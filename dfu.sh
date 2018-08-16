#sudo avrdude -v -patmega32u4 -c avrisp -P /dev/cu.usbmodem1411 -b 57600 -D -U flash:w:/Users/testuser/Downloads/megaUSB_DFU_Bootloaders/ATMega32U4-usbdevice_dfu-1_0_0.hex:i -C /Users/testuser/Library/Arduino15/packages/SparkFun/hardware/avr/1.1.5/avrdude.conf
#sudo avrdude -v -p atmega32u4 -c avrisp -P /dev/cu.usbmodem1411 -b 57600 -D -C /Users/testuser/Library/Arduino15/packages/SparkFun/hardware/avr/1.1.5/avrdude.conf -e \
#-U efuse:w:0xC3:m -U hfuse:w:0xD9:m -U lfuse:w:0xFF:m \
#-U flash:w:/Users/testuser/git/qmk_firmware/util/bootloader_atmega32u4_1_0_0.hex:i
#-U lock:w:0xEF:m \
#-U flash:w:/Users/testuser/Downloads/megaUSB_DFU_Bootloaders/ATMega32U4-usbdevice_dfu-1_0_0.hex:i
sudo /Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude -C/Users/testuser/Library/Arduino15/packages/SparkFun/hardware/avr/1.1.5/avrdude.conf \
-v -patmega32u4 \
-c stk500v1 \
-P/dev/cu.usbmodem1421 \
-b19200 \
-e -Ulock:w:0x3F:m -Uefuse:w:0xCB:m -Uhfuse:w:0xD8:m -Ulfuse:w:0xFF:m

sudo /Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude -C/Users/testuser/Library/Arduino15/packages/SparkFun/hardware/avr/1.1.5/avrdude.conf \
-v -patmega32u4 \
-cstk500v1 \
-P/dev/cu.usbmodem1421 \
-b19200 \
-Ulock:w:0x2F:m \
-Uflash:w:/Users/testuser/git/Arduino/hardware/arduino/avr/bootloaders/caterina/Caterina-Micro.hex:i
#-Uflash:w:/Users/testuser/Library/Arduino15/packages/SparkFun/hardware/avr/1.1.5/bootloaders/caterina/Caterina-promicro16.hex:i
#-Uflash:w:/Users/testuser/Downloads/megaUSB_DFU_Bootloaders/ATMega32U4-usbdevice_dfu-1_0_0.hex:i
#-U flash:w:/Users/testuser/git/qmk_firmware/util/bootloader_atmega32u4_1_0_0.hex:i
#-U flash:w:/Users/testuser/git/qmk_firmware/split_maxipad_rev1_ijikeman.hex:i
