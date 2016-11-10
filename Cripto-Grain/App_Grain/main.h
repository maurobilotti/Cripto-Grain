#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bpm-file.h"

void encriptar_imagen(char* dir, char *plaintext, bmpInfoHeader header);
void desencriptar_imagen(char* dir, char *ciphertext, bmpInfoHeader header);
void abrir_imagen(char* dir, bmpInfoHeader *header, char **body);