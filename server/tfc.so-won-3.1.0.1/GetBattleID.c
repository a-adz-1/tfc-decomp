// GetBattleID__FP7edict_s  @ 000eb570
undefined4 GetBattleID__FP7edict_s(undefined4 param_1)

{
  undefined4 uVar1;
  char *__s;
  undefined4 local_4;
  
  local_4 = 0;
  uVar1 = (*DAT_001a7fe8)(param_1);
  __s = (char *)(*DAT_001a7fec)(uVar1,"tf_id");
  if ((__s != (char *)0x0) && (*__s != '\0')) {
    sscanf(__s,"%d",&local_4);
  }
  return local_4;
}


