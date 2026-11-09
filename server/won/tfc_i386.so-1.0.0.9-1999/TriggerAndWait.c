// TriggerAndWait__11CBaseButton  @ 0009ecb0
void TriggerAndWait__11CBaseButton(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = UTIL_IsMasterTriggered__Fi(param_1[0x11a]);
  if (iVar1 != 0) {
    param_1[0xfa] = 0;
    if ((param_1[0x11b] == 0) && ((*(byte *)(*param_1 + 0x180) & 0x20) == 0)) {
      *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + (float)param_1[0xfd];
      param_1[3] = -0x10000;
      param_1[4] = (int)ButtonReturn__11CBaseButton;
    }
    else if ((*(byte *)(*param_1 + 0x181) & 1) == 0) {
      param_1[5] = 0;
      param_1[6] = 0;
    }
    else {
      param_1[5] = -0x10000;
      param_1[6] = (int)ButtonTouch__11CBaseButtonP11CBaseEntity;
    }
    *(undefined4 *)(*param_1 + 0x110) = 0x3f800000;
    uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x10f,3,0);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar2);
  }
  return;
}


