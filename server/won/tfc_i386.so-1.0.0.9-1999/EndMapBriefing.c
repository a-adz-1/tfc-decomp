// EndMapBriefing__11CBasePlayer  @ 000e3d50
void EndMapBriefing__11CBasePlayer(int *param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  ResetMenu__11CBasePlayer(param_1);
  param_1[0x262] = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  UTIL_ScreenFade__FP7edict_sRC6Vectorffii
            (*(undefined4 *)(*param_1 + 0x1e8),&local_10,0x3f000000,0x3f000000,0,0);
  *(byte *)(param_1 + 0x202) = *(byte *)(param_1 + 0x202) & 0xf6;
  return;
}


