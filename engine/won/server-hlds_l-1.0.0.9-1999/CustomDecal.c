// CustomDecal_Init  @ 08054800
void CustomDecal_Init(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  Draw_CustomCacheWadInit(0x10,param_1,param_2,param_3);
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x14)) {
    do {
      Draw_CacheByIndex(param_1,iVar1,param_4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x14));
  }
  return;
}


