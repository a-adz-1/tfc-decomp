// MD5_Hash_File  @ 00044ef0
BOOL MD5_Hash_File(uchar *digest,char *pszFileName,BOOL bUsefopen,BOOL bSeed,uint *seed)

{
  uchar *in;
  FileHandle_t file;
  uint uVar1;
  int iVar2;
  uint len;
  BOOL BVar3;
  int in_GS_OFFSET;
  MD5Context_t local_478;
  uchar local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: byte[1024] chunk@[???]
                       Unresolved local var: int nBytesRead@[???]
                       Unresolved local var: MD5Context_t ctx@[???]
                       Unresolved local var: int nSize@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  file = FS_OpenPathID(pszFileName,"rb","GAMECONFIG");
  if ((file == (FileHandle_t)0x0) && (file = FS_Open(pszFileName,"rb"), file == (FileHandle_t)0x0))
  {
    BVar3 = 0;
  }
  else {
    uVar1 = FS_Size(file);
    if ((int)uVar1 < 1) {
      FS_Close(file);
      BVar3 = 0;
    }
    else {
      Q_memset(&local_478,0,0x58);
      local_478.buf[1] = 0xefcdab89;
      local_478.buf[2] = 0x98badcfe;
      local_478.buf[3] = 0x10325476;
      local_478.bits[0] = 0;
      local_478.bits[1] = 0;
      local_478.buf[0] = 0x67452301;
      if (bSeed != 0) {
        MD5Update(&local_478,(uchar *)seed,0x10);
      }
      do {
        if ((int)uVar1 < 0x401) {
          len = FS_Read(local_420,uVar1,1,file);
        }
        else {
          len = FS_Read(local_420,0x400,1,file);
        }
        if (0 < (int)len) {
          uVar1 = uVar1 - len;
          MD5Update(&local_478,local_420,len);
        }
        iVar2 = FS_EndOfFile(file);
        if (iVar2 != 0) break;
        iVar2 = FS_IsOk(file);
        if (iVar2 == 0) {
          FS_Close(file);
          BVar3 = 0;
          goto LAB_000450c9;
        }
      } while (0 < (int)uVar1);
      FS_Close(file);
                    /* Unresolved local var: uint count@[???]
                       Unresolved local var: uchar * p@[???] */
      in = local_478.in;
      uVar1 = local_478.bits[0] >> 3 & 0x3f;
      local_478.in[uVar1] = 0x80;
      if (0x3f - uVar1 < 8) {
        Q_memset(local_478.in + uVar1 + 1,0,0x3f - uVar1);
        MD5Transform(local_478.buf,(uint *)in);
        Q_memset(in,0,0x38);
      }
      else {
        Q_memset(local_478.in + uVar1 + 1,0,0x37 - uVar1);
      }
      local_478.in[0x38] = (undefined1)local_478.bits[0];
      local_478.in[0x39] = local_478.bits[0]._1_1_;
      local_478.in[0x3a] = local_478.bits[0]._2_1_;
      local_478.in[0x3b] = local_478.bits[0]._3_1_;
      local_478.in[0x3c] = (undefined1)local_478.bits[1];
      local_478.in[0x3d] = local_478.bits[1]._1_1_;
      local_478.in[0x3e] = local_478.bits[1]._2_1_;
      local_478.in[0x3f] = local_478.bits[1]._3_1_;
      MD5Transform(local_478.buf,(uint *)in);
      Q_memcpy(digest,&local_478,0x10);
      Q_memset(&local_478,0,4);
      BVar3 = 1;
    }
  }
LAB_000450c9:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return BVar3;
}


// MD5_Print  @ 000451a0
char * MD5_Print(uchar *hash)

{
  uchar *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  int in_GS_OFFSET;
  undefined1 local_2a [10];
  int local_20;
  
                    /* Unresolved local var: uchar c@[???]
                       Unresolved local var: char[10] szChunk@[???]
                       Unresolved local var: int i@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(MD5_Print::szReturn,0,0x40);
  puVar1 = hash + 0x10;
  do {
    __snprintf_chk(local_2a,10,1,10,&DAT_000d0f1f,*hash);
    puVar5 = (uint *)MD5_Print::szReturn;
    do {
      puVar4 = puVar5;
      uVar2 = *puVar4 + 0xfefefeff & ~*puVar4;
      uVar3 = uVar2 & 0x80808080;
      puVar5 = puVar4 + 1;
    } while (uVar3 == 0);
    if ((uVar2 & 0x8080) == 0) {
      puVar5 = (uint *)((int)puVar4 + 6);
      uVar3 = uVar3 >> 0x10;
    }
    hash = hash + 1;
    __strncat_chk(MD5_Print::szReturn,local_2a,
                  0x3f - ((int)puVar5 + (-0x10aea3 - (uint)CARRY1((byte)uVar3,(byte)uVar3))),0x40);
  } while (hash != puVar1);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return MD5_Print::szReturn;
}


