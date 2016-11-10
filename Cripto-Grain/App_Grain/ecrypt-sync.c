/* ecrypt-sync.c */

/* *** Please do not edit this file. *** */

#include "ecrypt-sync.h"

#ifdef ECRYPT_USES_DEFAULT_ALL_IN_ONE

/*
 * Default implementation of all-in-one encryption/decryption of
 * (short) packets.
 */

void ECRYPT_encrypt_packet(
  ECRYPT_ctx* ctx,
  const u8* iv,
  const u8* plaintext,
  u8* ciphertext,
  u32 msglen)
{
  ECRYPT_ivsetup(ctx, iv);
  ECRYPT_encrypt_bytes(ctx, plaintext, ciphertext, msglen);
}

void ECRYPT_decrypt_packet(
  ECRYPT_ctx* ctx,
  const u8* iv,
  const u8* ciphertext,
  u8* plaintext,
  u32 msglen)
{
  ECRYPT_ivsetup(ctx, iv);
  ECRYPT_decrypt_bytes(ctx, ciphertext, plaintext, msglen);
}

#endif