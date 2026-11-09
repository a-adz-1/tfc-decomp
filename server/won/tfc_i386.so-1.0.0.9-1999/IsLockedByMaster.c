// IsLockedByMaster__11CBaseEntity  @ 0010e120
undefined4 IsLockedByMaster__11CBaseEntity(void)

{
  return 0;
}


// IsLockedByMaster__11CBaseToggle  @ 000f0d70
undefined4 IsLockedByMaster__11CBaseToggle(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x468) != 0) &&
     (iVar1 = UTIL_IsMasterTriggered__Fi(*(undefined4 *)(param_1 + 0x468)), iVar1 == 0)) {
    return 1;
  }
  return 0;
}


