// StrikeUse__10CLightningP11CBaseEntityT18USE_TYPEf  @ 000a0ec8
void StrikeUse__10CLightningP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0x112]);
  if (iVar1 != 0) {
    if (param_1[0x112] == 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)StrikeThink__10CLightning;
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
    }
    else {
      param_1[0x112] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
    }
    if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
      param_1[7] = 0;
      param_1[8] = 0;
    }
  }
  return;
}


