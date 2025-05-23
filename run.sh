#!/bin/bash

# WARNING!
# WARNING!
# WARNING!
# RUNNING THIS SHELLSCRIPT WILL CRASH YOUR COMPUTER

mkdir cyberProject
cd cyberProject
# copy dummy.c into a file
# copy malicious.txt into a file
gcc -fno-stack-protector -z execstack dummy.c -o dummy.exe
sudo su
echo 0 > /proc/sys/kernel/randomize_va_space
exit
python2 "print 'malicious.txt'" | ./dummy.exe
