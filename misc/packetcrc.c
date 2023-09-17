#include <stdio.h>
int main(int argc,char **argv)
{
	unsigned src, crc;
	while(scanf("%x",&src))
	{
		crc = 0;
		while(src)
		{
			crc += src & 0xffff;
			src = src >> 16;
		}
		crc = (crc >> 16) + (crc & 0xffff);
		crc += crc >> 16;
		crc = ~crc & 0xffff;
		printf("%04x\n",crc);
		crc = crc >> 8 | (crc & 0xff) << 8;
		printf("%04x\n",crc);
	}
	return 0;
}