/*
 * REFERENCE IMPLEMENTATION OF STREAM CIPHER GRAIN VERSION 1
 *
 * Filename: testvectors.c
 *
 * Author:
 * Martin Hell
 * Dept. of Information Technology
 * P.O. Box 118
 * SE-221 00 Lund, Sweden,
 * email: martin@it.lth.se
 *
 * Synopsis:
 *    Generates testvectors from the reference implementation of Grain Version 1.
 *
 */


#include <stdio.h>
#include <string.h>
#include "grain.h"

/*  GENERATE TEST VECTORS  */

void printData(u8 *key, u8 *IV, u8 *ks) {
	u32 i;
	printf("\n\nkey:        ");
	for (i=0;i<10;++i) printf("%02x",(int)key[i]);
	printf("\nIV :        ");
	for (i=0;i<8;++i) printf("%02x",(int)IV[i]);
	printf("\nkeystream:  ");
	for (i=0;i<10;++i) printf("%02x",(int)ks[i]);
}

void testvectors() {
	
	ECRYPT_ctx ctx;
	u8 key1[10] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		IV1[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	    ks[10];

	u8 key2[10] = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,0x12,0x34},
		IV2[8] = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef};

	ECRYPT_keysetup(&ctx,key1,80,64);
	ECRYPT_ivsetup(&ctx,IV1);
	ECRYPT_keystream_bytes(&ctx,ks,10);
	printData(key1,IV1,ks);

	ECRYPT_keysetup(&ctx,key2,80,64);
	ECRYPT_ivsetup(&ctx,IV2);
	ECRYPT_keystream_bytes(&ctx,ks,10);
	printData(key2,IV2,ks);

	printf("\n");

}

int main(int argc, char **argv) {	
	printf("---REFERENCE IMPLEMENTATION OF GRAIN---\n");
	testvectors();
	return 0;
}


