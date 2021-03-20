#!/usr/bin/bash
# Compile and "deploy" a new custom kernel from source on Ubuntu Linux

# Change this if you'd like. It has no relation
# to the suffix set in the kernel config.
SUFFIX="-ppp"

# This causes the script to exit if an error occurs
set -e

# Compile the kernel
make -j4

# Compile and install modules
make -j4 modules_install

# Install kernel image
#cp arch/x86_64/boot/bzImage /boot/vmlinuz-linux$SUFFIX
#make -j4 modules_install install
make -j4 install

# Update the bootloader
sudo update-grub
