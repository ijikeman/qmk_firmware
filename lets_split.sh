TTY=`ls /dev/|egrep cu.usbmodem14`
if [ "$TTY" != "" ]; then
  echo $TTY;
  sudo avrdude -v -patmega32u4 -c avr109 -P /dev/$TTY -b 57600 -D -U flash:w:/Users/fsvuser/git/qmk_firmware/lets_split_rev2_ijikeman.hex:i -C /Users/fsvuser/Library/Arduino15/packages/SparkFun/hardware/avr/1.1.5/avrdude.conf
fi
