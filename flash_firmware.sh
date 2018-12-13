#!/bin/bash

# Copyright (c) 2018 Tim Perkins

set -o errexit
set -o nounset
set -o pipefail

MELODY96_FIRMWARE="build/melody96_tprk77.hex"
DEBUG_FLAG="" # "--debug 10"

if ! command -v dfu-programmer &>/dev/null; then
    echo "Missing dfu-programmer! On Ubuntu, try:"
    echo "sudo apt install dfu-programmer"
    exit 1
fi

sudo dfu-programmer atmega32u4 erase ${DEBUG_FLAG}
sudo dfu-programmer atmega32u4 flash ${DEBUG_FLAG} "${MELODY96_FIRMWARE}"
sudo dfu-programmer atmega32u4 reset ${DEBUG_FLAG}

exit 0
