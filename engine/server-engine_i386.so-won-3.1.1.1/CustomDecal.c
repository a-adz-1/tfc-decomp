// CustomDecal_Init  @ 00060a2c
int CustomDecal_Init(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int local_8;
  
  iVar1 = Draw_CustomCacheWadInit(0x10,param_1,param_2,param_3);
  if (iVar1 != 0) {
    Draw_CacheWadHandler(param_1,Draw_MiptexTexture,0x18);
    for (local_8 = 0; local_8 < *(int *)(param_1 + 0x14); local_8 = local_8 + 1) {
      Draw_CacheByIndex(param_1,local_8,param_4);
    }
  }
  return iVar1;
}


// CustomDecal_Validate  @ 00060980
uint CustomDecal_Validate(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  iVar1 = Mem_ZeroMalloc(0x2c);
  if (iVar1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = CustomDecal_Init(iVar1,param_1,param_2,0);
    if (local_8 != 0) {
      iVar2 = Draw_CustomCacheGet(iVar1,param_1,param_2,0);
      local_8 = (uint)(iVar2 != 0);
    }
    Draw_FreeWad(iVar1);
    Mem_Free(iVar1);
  }
  return local_8;
}


