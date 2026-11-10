// Memory_Init  @ 000c2698
void Memory_Init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int local_c;
  
  local_c = 0x200000;
  hunk_base = param_1;
  hunk_size = param_2;
  hunk_low_used = 0;
  hunk_high_used = 0;
  Cache_Init();
  iVar1 = COM_CheckParm("-zone");
  if (iVar1 != 0) {
    if (iVar1 < com_argc + -1) {
      local_c = Q_atoi(*(undefined4 *)(iVar1 * 4 + com_argv + 4));
      local_c = local_c << 10;
    }
    else {
      Sys_Error("Memory_Init: you must specify a size in KB after -zone");
    }
  }
  mainzone = Hunk_AllocName(local_c,&DAT_000ed2d7);
  Z_ClearZone(mainzone,local_c);
  return;
}


