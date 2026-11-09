// MD5_Hash_File  @ 00111dd0
BOOL MD5_Hash_File(uchar *digest,char *pszFileName,BOOL bUsefopen,BOOL bSeed,uint *seed)

{
  FileHandle_t file;
  uint size;
  int iVar1;
  uint len;
  uchar local_474 [1024];
  MD5Context_t local_74;
  
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: byte[1024] chunk@[???]
                       Unresolved local var: int nBytesRead@[???]
                       Unresolved local var: MD5Context_t ctx@[???]
                       Unresolved local var: int nSize@[???] */
  file = FS_OpenPathID(pszFileName,"rb","GAMECONFIG");
  if ((file == (FileHandle_t)0x0) && (file = FS_Open(pszFileName,"rb"), file == (FileHandle_t)0x0))
  {
    return 0;
  }
  size = FS_Size(file);
  if ((int)size < 1) {
LAB_00111f30:
    FS_Close(file);
    return 0;
  }
  Q_memset(&local_74,0,0x58);
  local_74.buf[0] = 0x67452301;
  local_74.bits[0] = 0;
  local_74.bits[1] = 0;
  local_74.buf[3] = 0x10325476;
  local_74.buf[1] = 0xefcdab89;
  local_74.buf[2] = 0x98badcfe;
  if (bSeed != 0) {
    MD5Update(&local_74,(uchar *)seed,0x10);
  }
  do {
    if ((int)size < 0x401) {
      len = FS_Read(local_474,size,1,file);
    }
    else {
      len = FS_Read(local_474,0x400,1,file);
    }
    if (0 < (int)len) {
      size = size - len;
      MD5Update(&local_74,local_474,len);
    }
    iVar1 = FS_EndOfFile(file);
    if (iVar1 != 0) break;
    iVar1 = FS_IsOk(file);
    if (iVar1 == 0) goto LAB_00111f30;
  } while (0 < (int)size);
  FS_Close(file);
  MD5Final(digest,&local_74);
  return 1;
}


// MD5_Print  @ 00111f90
char * MD5_Print(uchar *hash)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  char local_16 [14];
  
                    /* Unresolved local var: uchar c@[???]
                       Unresolved local var: char[10] szChunk@[???]
                       Unresolved local var: int i@[???] */
  Q_memset(MD5_Print::szReturn,0,0x40);
  snprintf(local_16,10,"%02x",(uint)*hash);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[1]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[2]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[3]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[4]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[5]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[6]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[7]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[8]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[9]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[10]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[0xb]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[0xc]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[0xd]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[0xe]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  snprintf(local_16,10,"%02x",(uint)hash[0xf]);
  puVar4 = (uint *)MD5_Print::szReturn;
  do {
    puVar3 = puVar4;
    uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
    uVar2 = uVar1 & 0x80808080;
    puVar4 = puVar3 + 1;
  } while (uVar2 == 0);
  if ((uVar1 & 0x8080) == 0) {
    puVar4 = (uint *)((int)puVar3 + 6);
    uVar2 = uVar2 >> 0x10;
  }
  strncat(MD5_Print::szReturn,local_16,
          (size_t)(MD5_Print::szReturn +
                  (0x3f - ((int)puVar4 + (-3 - (uint)CARRY1((byte)uVar2,(byte)uVar2))))));
  return MD5_Print::szReturn;
}


