// CanPlayerHearPlayer__15TFGameMgrHelperP11CBasePlayerT1  @ 00142f44
undefined1
CanPlayerHearPlayer__15TFGameMgrHelperP11CBasePlayerT1(undefined4 param_1,int param_2,int param_3)

{
  undefined1 local_5;
  
  local_5 = 0;
  if ((*(int *)(param_2 + 0x120) == *(int *)(param_3 + 0x120)) ||
     (((int)(&teamallies)[*(int *)(param_2 + 0x120)] >>
       ((char)*(int *)(param_3 + 0x120) - 1U & 0x1f) & 1U) != 0)) {
    local_5 = 1;
  }
  return local_5;
}


