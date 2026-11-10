// ComputeSeededMD5andCRCForFileGroup__11AuthRequestPUcPcPUi  @ 000d5170
undefined4
ComputeSeededMD5andCRCForFileGroup__11AuthRequestPUcPcPUi
          (undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  long lVar1;
  FILE *pFVar2;
  size_t __size;
  undefined4 uVar3;
  void *local_444;
  int local_440;
  char *local_434;
  char *local_430;
  char local_42c [1024];
  undefined4 *local_2c;
  undefined4 local_28;
  undefined4 *local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  void *local_14;
  void *local_10;
  undefined4 local_c;
  int local_8;
  
  local_440 = 0;
  local_430 = param_3;
  while ((local_430 != (char *)0x0 && (*local_430 != '\0'))) {
    if (*local_430 == ';') {
      local_430 = local_430 + 1;
    }
    for (local_434 = local_430; (*local_434 != '\0' && (*local_434 != ';'));
        local_434 = local_434 + 1) {
    }
    strncpy(local_42c,local_430,(int)local_434 - (int)local_430);
    local_434[(int)(local_42c + -(int)local_430)] = '\0';
    local_430 = local_434;
    pFVar2 = fopen(local_42c,"rb");
    fseek(pFVar2,0,2);
    lVar1 = ftell(pFVar2);
    fseek(pFVar2,0,0);
    fclose(pFVar2);
    local_440 = local_440 + lVar1;
  }
  local_10 = (void *)__builtin_vec_new(local_440 + 1);
  local_18 = local_440 + 0x3ff;
  if (local_18 < 0) {
    local_18 = local_440 + 0x7fe;
  }
  local_18 = local_18 >> 10;
  local_2c = (undefined4 *)__builtin_vec_new((local_18 + 1) * 4);
  local_444 = local_10;
  local_430 = param_3;
  while ((local_430 != (char *)0x0 && (*local_430 != '\0'))) {
    if (*local_430 == ';') {
      local_430 = local_430 + 1;
    }
    for (local_434 = local_430; (*local_434 != '\0' && (*local_434 != ';'));
        local_434 = local_434 + 1) {
    }
    strncpy(local_42c,local_430,(int)local_434 - (int)local_430);
    local_434[(int)(local_42c + -(int)local_430)] = '\0';
    local_430 = local_434;
    pFVar2 = fopen(local_42c,"rb");
    fseek(pFVar2,0,2);
    __size = ftell(pFVar2);
    fseek(pFVar2,0,0);
    fread(local_444,__size,1,pFVar2);
    fclose(pFVar2);
    local_444 = (void *)((int)local_444 + __size);
  }
  local_20 = 0;
  local_24 = local_2c;
  local_14 = local_10;
  for (local_1c = local_440; 0x3ff < local_1c; local_1c = local_1c + -0x400) {
    CRC32_Init__FPUl(&local_28);
    CRC32_ProcessBuffer__FPUlPvi(&local_28,local_14,0x400);
    uVar3 = CRC32_Final__FUl(local_28);
    *local_24 = uVar3;
    local_24 = local_24 + 1;
    local_14 = (void *)((int)local_14 + 0x400);
  }
  if (local_1c != 0) {
    CRC32_Init__FPUl(&local_28);
    CRC32_ProcessBuffer__FPUlPvi(&local_28,local_14,local_1c);
    uVar3 = CRC32_Final__FUl(local_28);
    *local_24 = uVar3;
    local_24 = local_24 + 1;
    local_14 = (void *)((int)local_14 + local_1c);
  }
  local_8 = local_18;
  if (local_10 != (void *)0x0) {
    __builtin_vec_delete(local_10);
  }
  local_c = MD5_Hash_CachedFile__FPUcT0iiPUi(param_2,local_2c,local_8,1,param_4);
  if (local_2c != (undefined4 *)0x0) {
    __builtin_vec_delete(local_2c);
  }
  return local_c;
}


