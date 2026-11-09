// MD5CRCHash__FPUcPcPUi  @ 08090d20
undefined4 MD5CRCHash__FPUcPcPUi(undefined4 param_1,char *param_2,undefined4 param_3)

{
  FILE *__stream;
  size_t __size;
  void *__ptr;
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  __stream = fopen(param_2,"rb");
  fseek(__stream,0,2);
  __size = ftell(__stream);
  fseek(__stream,0,0);
  __ptr = (void *)__builtin_vec_new(__size + 1);
  iVar1 = __size + 0x3ff;
  if (iVar1 < 0) {
    iVar1 = __size + 0x7fe;
  }
  puVar2 = (undefined4 *)__builtin_vec_new((iVar1 >> 10) * 4 + 4);
  fread(__ptr,__size,1,__stream);
  fclose(__stream);
  pvVar4 = __ptr;
  puVar5 = puVar2;
  if (0x3ff < (int)__size) {
    do {
      CRC32_Init(&local_8);
      CRC32_ProcessBuffer(&local_8,pvVar4,0x400);
      uVar3 = CRC32_Final(local_8);
      *puVar5 = uVar3;
      puVar5 = puVar5 + 1;
      pvVar4 = (void *)((int)pvVar4 + 0x400);
      __size = __size - 0x400;
    } while (0x3ff < (int)__size);
  }
  if (__size != 0) {
    CRC32_Init(&local_8);
    CRC32_ProcessBuffer(&local_8,pvVar4,__size);
    uVar3 = CRC32_Final(local_8);
    *puVar5 = uVar3;
  }
  if (__ptr != (void *)0x0) {
    __builtin_vec_delete(__ptr);
  }
  uVar3 = MD5_Hash_CachedFile(param_1,puVar2,iVar1 >> 10,1,param_3);
  if (puVar2 != (undefined4 *)0x0) {
    __builtin_vec_delete(puVar2);
  }
  return uVar3;
}


