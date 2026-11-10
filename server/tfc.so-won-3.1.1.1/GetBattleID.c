// GetBattleID__FP7edict_s  @ 000fb448
undefined4 GetBattleID__FP7edict_s(undefined4 param_1)

{
  undefined4 uVar1;
  char *__s;
  undefined4 local_8;
  
  local_8 = 0;
  uVar1 = (*DAT_0019f848)(param_1);
  __s = (char *)(*DAT_0019f84c)(uVar1,"tf_id");
  if ((__s != (char *)0x0) && (*__s != '\0')) {
    sscanf(__s,"%d",&local_8);
  }
  return local_8;
}


