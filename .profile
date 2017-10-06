sudo cp stlink/etc/udev/rules.d/49-stlinkv* /etc/udev/rules.d/
sudo udevadm control --reload-rules
sudo udevadm trigger

export LD_LIBRARY_PATH="$(pwd)/stlink/_install/usr/local/lib/"
export PATH=$PATH:"$(pwd)/gcc-arm-none-eabi/bin/"
export PATH=$PATH:"$(pwd)/stlink/_install/usr/local/bin/"
