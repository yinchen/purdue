#include "bmp_header.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


unsigned int lendianReadInt(unsigned char b[]) {
	unsigned int i;
	i = (b[3]<<24) | (b[2]<<16) | (b[1]<<8) | b[0]; // big endian
   	return i;
}
unsigned short int lendianReadShort(unsigned char b[]) {
	unsigned short int i;
	i = ((b[1]<<8) | b[0]); // big endian
   	return i;
}

unsigned int lendianWriteInt(unsigned char b[]) {
	unsigned int i;
	i = (b[3]<<24) | (b[2]<<16) | (b[1]<<8) | b[0]; // big endian
   	return i;
}

unsigned short int lendianWriteShort(unsigned char b[]) {
	unsigned short int i;
  	i = (b[1]<<8) | (b[0]); // little endian
   	return i;
}

