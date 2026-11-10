// GetBattleID__FP7edict_s  @ 000f84d8
undefined4 GetBattleID__FP7edict_s(undefined4 param_1)

{
  undefined4 uVar1;
  char *__s;
  undefined4 local_4;
  
  local_4 = 0;
  uVar1 = (*DAT_001c11c8)(param_1);
  __s = (char *)(*DAT_001c11cc)(uVar1,"tf_id");
  if ((__s != (char *)0x0) && (*__s != '\0')) {
    sscanf(__s,"%d",&local_4);
  }
  return local_4;
}


