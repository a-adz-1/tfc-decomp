// IsPointEntity__FP11CBaseEntity  @ 00096a10
undefined4 IsPointEntity__FP11CBaseEntity(int *param_1)

{
  int iVar1;
  
  if ((((*(int *)(*param_1 + 0xb4) != 0) &&
       (iVar1 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"info_target"),
       iVar1 != 0)) &&
      (iVar1 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"info_landmark"),
      iVar1 != 0)) &&
     (iVar1 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),"path_corner"),
     iVar1 != 0)) {
    return 0;
  }
  return 1;
}


