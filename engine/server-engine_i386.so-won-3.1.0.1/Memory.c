// Memory_Init  @ 0008e950
void Memory_Init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  hunk_base = param_1;
  hunk_size = param_2;
  hunk_low_used = 0;
  iVar2 = 0x20000;
  hunk_high_used = 0;
  Cache_Init();
  iVar1 = COM_CheckParm("-zone");
  if (iVar1 != 0) {
    if (iVar1 < com_argc + -1) {
      iVar2 = Q_atoi(*(undefined4 *)(com_argv + 4 + iVar1 * 4));
      iVar2 = iVar2 << 10;
    }
    else {
      Sys_Error("Memory_Init: you must specify a size in KB after -zone");
    }
  }
  mainzone = Hunk_AllocName(iVar2,&DAT_000ade17);
  Z_ClearZone(mainzone,iVar2);
  return;
}


