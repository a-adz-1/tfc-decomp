// IsLockedByMaster__11CBaseEntity  @ 00112ba4
undefined4 IsLockedByMaster__11CBaseEntity(void)

{
  return 0;
}


// IsLockedByMaster__11CBaseToggle  @ 000f64bc
undefined4 IsLockedByMaster__11CBaseToggle(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x4f4) != 0) &&
     (iVar1 = UTIL_IsMasterTriggered__Fi(*(int *)(param_1 + 0x4f4)), iVar1 == 0)) {
    return 1;
  }
  return 0;
}


