#!/bin/sh

# execute this script as root to install packages

if [ $(id -u) != 0 ]; then
  echo "This script must be executed as root!"
  exit 1
fi

#cd /usr/bin && rm python && ln -s python3 python

apt update
echo "----------------"
apt upgrade
echo "----------------"
apt install cmake build-essential
echo "----------------"
pip3 install rpi_ws281x
echo "----------------"
pip3 install mpu6050-raspberrypi
echo "----------------"
apt install -y libqt5gui5 python3-dev python3-pyqt5

# reboot