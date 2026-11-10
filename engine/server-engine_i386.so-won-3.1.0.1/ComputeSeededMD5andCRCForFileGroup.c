// ComputeSeededMD5andCRCForFileGroup__11AuthRequestPUcPcPUi  @ 0009c348
undefined4
ComputeSeededMD5andCRCForFileGroup__11AuthRequestPUcPcPUi
          (undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  char cVar1;
  FILE *pFVar2;
  long lVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  size_t __size;
  uint uVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *__src;
  void *pvVar10;
  int local_420;
  undefined4 *local_418;
  int local_414;
  undefined4 local_408;
  char local_404 [1024];
  
  local_420 = 0;
  local_414 = local_420;
  pcVar9 = param_3;
  while ((pcVar9 != (char *)0x0 && (cVar1 = *pcVar9, cVar1 != '\0'))) {
    __src = pcVar9;
    if (cVar1 == ';') {
      pcVar9 = pcVar9 + 1;
      cVar1 = *pcVar9;
      __src = pcVar9;
    }
    while ((cVar1 != '\0' && (*pcVar9 != ';'))) {
      pcVar9 = pcVar9 + 1;
      cVar1 = *pcVar9;
    }
    strncpy(local_404,__src,(int)pcVar9 - (int)__src);
    local_404[(int)pcVar9 - (int)__src] = '\0';
    pFVar2 = fopen(local_404,"rb");
    fseek(pFVar2,0,2);
    lVar3 = ftell(pFVar2);
    fseek(pFVar2,0,0);
    fclose(pFVar2);
    local_414 = local_414 + lVar3;
  }
  pvVar4 = (void *)__builtin_vec_new(local_414 + 1);
  iVar5 = local_414 + 0x3ff;
  if (iVar5 < 0) {
    iVar5 = local_414 + 0x7fe;
  }
  puVar6 = (undefined4 *)__builtin_vec_new((iVar5 >> 10) * 4 + 4);
  pvVar10 = pvVar4;
  while ((param_3 != (char *)0x0 && (cVar1 = *param_3, cVar1 != '\0'))) {
    pcVar9 = param_3;
    if (cVar1 == ';') {
      param_3 = param_3 + 1;
      cVar1 = *param_3;
      pcVar9 = param_3;
    }
    while ((cVar1 != '\0' && (*param_3 != ';'))) {
      param_3 = param_3 + 1;
      cVar1 = *param_3;
    }
    strncpy(local_404,pcVar9,(int)param_3 - (int)pcVar9);
    local_404[(int)param_3 - (int)pcVar9] = '\0';
    pFVar2 = fopen(local_404,"rb");
    fseek(pFVar2,0,2);
    __size = ftell(pFVar2);
    fseek(pFVar2,0,0);
    fread(pvVar10,__size,1,pFVar2);
    fclose(pFVar2);
    pvVar10 = (void *)((int)pvVar10 + __size);
  }
  pvVar10 = pvVar4;
  local_418 = puVar6;
  if (local_414 < 0x400) goto LAB_0009c72e;
  uVar7 = 0x3ffU - local_414 & 0xfff;
  if (uVar7 != 0) {
    if (uVar7 < 0xc00) {
      if (uVar7 < 0x800) {
        if (uVar7 < 0x400) goto LAB_0009c64c;
        CRC32_Init__FPUl(&local_408);
        CRC32_ProcessBuffer__FPUlPvi(&local_408,pvVar4,0x400);
        uVar8 = CRC32_Final__FUl(local_408);
        *puVar6 = uVar8;
        local_418 = puVar6 + 1;
        pvVar10 = (void *)((int)pvVar4 + 0x400);
        local_414 = local_414 + -0x400;
      }
      CRC32_Init__FPUl(&local_408);
      CRC32_ProcessBuffer__FPUlPvi(&local_408,pvVar10,0x400);
      uVar8 = CRC32_Final__FUl(local_408);
      pvVar10 = (void *)((int)pvVar10 + 0x400);
      *local_418 = uVar8;
      local_418 = local_418 + 1;
      local_414 = local_414 + -0x400;
    }
    CRC32_Init__FPUl(&local_408);
    CRC32_ProcessBuffer__FPUlPvi(&local_408,pvVar10,0x400);
    uVar8 = CRC32_Final__FUl(local_408);
    pvVar10 = (void *)((int)pvVar10 + 0x400);
    *local_418 = uVar8;
    local_418 = local_418 + 1;
    local_414 = local_414 + -0x400;
    if (local_414 < 0x400) goto LAB_0009c72e;
  }
LAB_0009c64c:
  do {
    CRC32_Init__FPUl(&local_408);
    CRC32_ProcessBuffer__FPUlPvi(&local_408,pvVar10,0x400);
    uVar8 = CRC32_Final__FUl(local_408);
    *local_418 = uVar8;
    CRC32_Init__FPUl(&local_408);
    CRC32_ProcessBuffer__FPUlPvi(&local_408,(int)pvVar10 + 0x400,0x400);
    uVar8 = CRC32_Final__FUl(local_408);
    local_418[1] = uVar8;
    CRC32_Init__FPUl(&local_408);
    CRC32_ProcessBuffer__FPUlPvi(&local_408,(int)pvVar10 + 0x800,0x400);
    uVar8 = CRC32_Final__FUl(local_408);
    local_418[2] = uVar8;
    CRC32_Init__FPUl(&local_408);
    CRC32_ProcessBuffer__FPUlPvi(&local_408,(int)pvVar10 + 0xc00,0x400);
    uVar8 = CRC32_Final__FUl(local_408);
    pvVar10 = (void *)((int)pvVar10 + 0x1000);
    local_418[3] = uVar8;
    local_418 = local_418 + 4;
    local_414 = local_414 + -0x1000;
  } while (0x3ff < local_414);
LAB_0009c72e:
  if (local_414 != 0) {
    CRC32_Init__FPUl(&local_408);
    CRC32_ProcessBuffer__FPUlPvi(&local_408,pvVar10,local_414);
    uVar8 = CRC32_Final__FUl(local_408);
    *local_418 = uVar8;
  }
  if (pvVar4 != (void *)0x0) {
    __builtin_vec_delete(pvVar4);
  }
  uVar8 = MD5_Hash_CachedFile__FPUcT0iiPUi(param_2,puVar6,iVar5 >> 10,1,param_4);
  if (puVar6 != (undefined4 *)0x0) {
    __builtin_vec_delete(puVar6);
  }
  return uVar8;
}


