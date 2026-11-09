// StrikeUse__10CLightningP11CBaseEntityT18USE_TYPEf  @ 000ac3b0
void StrikeUse__10CLightningP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = ShouldToggle__11CBaseEntity8USE_TYPEi(param_1,param_4,param_1[0xf3]);
  if (iVar1 != 0) {
    if (param_1[0xf3] == 0) {
      param_1[3] = -0x10000;
      param_1[4] = (int)StrikeThink__10CLightning;
      *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
    }
    else {
      param_1[0xf3] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
    }
    if ((*(byte *)(*param_1 + 0x180) & 2) == 0) {
      param_1[7] = 0;
      param_1[8] = 0;
    }
  }
  return;
}


