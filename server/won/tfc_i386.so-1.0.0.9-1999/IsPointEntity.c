// IsPointEntity__FP11CBaseEntity  @ 000ac450
undefined4 IsPointEntity__FP11CBaseEntity(int *param_1)

{
  int iVar1;
  
  if ((((*(int *)(*param_1 + 0x94) != 0) &&
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


