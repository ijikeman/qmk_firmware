sudo avrdude -v -patmega32u4 \
-c avrisp \
-P /dev/cu.usbmodem1411 \
-b 57600 \
-C /Users/testuser/Library/Arduino15/packages/SparkFun/hardware/avr/1.1.5/avrdude.conf \
-D -U flash:w:/Users/testuser/Downloads/megaUSB_DFU_Bootloaders/ATMega32U4-usbdevice_dfu-1_0_0.hex:i
