#!/bin/bash
nasm -f elf64 malware.s -o malware.o # convert nasm to object file
ld malware.o -o malware.bin # link object file into executable binary
