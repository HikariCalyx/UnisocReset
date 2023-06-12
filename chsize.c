#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    FILE* fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", filename);
        return 1;
    }

    int end_pos = -1;
    fseek(fp, 0L, SEEK_END);
    end_pos = ftell(fp);

    char buf[1];
    while (end_pos >= 0) {
        fseek(fp, end_pos, SEEK_SET);
        fread(buf, 1, 1, fp);
        if (buf[0] != '\x00') {
            break;
        }
        end_pos--;
    }

    if (end_pos < 0) {
        fclose(fp);
        remove(filename);
        return 0;
    }

#ifdef _WIN32
    if (_chsize(fileno(fp), end_pos + 1) != 0) {
        printf("Failed to truncate file: %s\n", filename);
        fclose(fp);
        return 1;
    }
#else
    if (ftruncate(fileno(fp), end_pos + 1) != 0) {
        printf("Failed to truncate file: %s\n", filename);
        fclose(fp);
        return 1;
    }
#endif

    fclose(fp);
    return 0;
}
