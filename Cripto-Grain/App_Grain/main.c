#include "main.h"
#include "ecrypt-sync.h"
#include "bpm-file.h"

void encriptar_imagen(char* dir, char *plaintext, bmpInfoHeader header) {

	ECRYPT_ctx ctx;
	u8 key[16] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0 },
		IV[12] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x12, 0x34, 0x56, 0x78 };

	u32 msglen = header.imgsize;
	char* ciphertext = malloc(sizeof(msglen + 1));
	ECRYPT_init();
	ECRYPT_keysetup(&ctx, key, 128, 96);
	ECRYPT_ivsetup(&ctx, IV);
	ECRYPT_encrypt_bytes(&ctx, plaintext, ciphertext, msglen);
	SaveBMP(dir, ciphertext, msglen);
}

void desencriptar_imagen(char* dir, char *ciphertext, bmpInfoHeader header) {

	ECRYPT_ctx ctx;
	u8 key[16] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0 },
		IV[12] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x12, 0x34, 0x56, 0x78 };
	u32 msglen = header.imgsize;
	char *plaintext = malloc(sizeof(msglen));
	ECRYPT_init();
	ECRYPT_keysetup(&ctx, key, 128, 96);
	ECRYPT_ivsetup(&ctx, IV);
	ECRYPT_decrypt_bytes(&ctx, ciphertext, plaintext, msglen);
	SaveBMP(dir, plaintext, msglen);
	return;
}

void abrir_imagen(char* dir, bmpInfoHeader *header, char **body) {
	*body = LoadBMP(dir, header);
	return;
}
