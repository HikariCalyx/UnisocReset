spd_dump exec_addr 0x3f88 fdl fdl1-dl.bin 0x5500 fdl uboot-mod.bin 0x9efffe00 exec read_part teecfg 0 1M teecfg.bin read_part trustos 0 6M tos.bin read_part sml 0 1M sml.bin erase_part splloader reset

chsize teecfg.bin

chsize tos.bin

chsize sml.bin
TIMEOUT /T 10 /NOBREAK
spd_dump exec_addr 0x3f28 fdl fdl1-boot.bin 0x5500 fdl uboot-mod.bin 0x9efffe00 fdl teecfg.bin 0x9401fe00 fdl tos.bin 0x9403fe00 fdl sml.bin 0x93fffe00 exec
TIMEOUT /T 10 /NOBREAK
spd_dump exec_addr 0x3f28 fdl fdl1-dl.bin 0x5500 fdl uboot-mod.bin 0x9efffe00 exec erase_part uboot_log write_part splloader spl.bin timeout 100000 write_part userdata userdata.bin reset
