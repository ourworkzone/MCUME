#!/bin/bash
. ${IDF_PATH}/add_path.sh
esptool.py --chip esp32 --port "/dev/cu.SLAB_USBtoUART" --baud $((230400*4)) write_flash -fs 4MB 0x390000 ../esp5200/build/esp5200.bin