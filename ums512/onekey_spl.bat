spd_dump exec_addr 0x3f48 fdl fdl1-dl.bin 0x5500 fdl uboot-mod.bin 0x9efffe00 exec write_part uboot uboot-mod.bin erase_part splloader reset
TIMEOUT /T 10 /NOBREAK
spd_dump exec_addr 0x3ee8 fdl spl-custom.bin 0x5500
TIMEOUT /T 10 /NOBREAK
spd_dump exec_addr 0x3f48 fdl fdl1-dl.bin 0x5500 fdl uboot-mod.bin 0x9efffe00 exec write_part uboot uboot.bin write_part splloader spl.bin timeout 100000 write_part userdata userdata.bin reset
