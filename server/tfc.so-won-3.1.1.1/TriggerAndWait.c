// TriggerAndWait__11CBaseButton  @ 0008ccc8
void TriggerAndWait__11CBaseButton(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = UTIL_IsMasterTriggered__Fi(param_1[0x13d]);
  if (iVar1 != 0) {
    param_1[0x11d] = 0;
    if ((param_1[0x13e] == 0) && (iVar1 = *param_1, (*(byte *)(iVar1 + 0x1a0) & 0x20) == 0)) {
      *(float *)(iVar1 + 0x104) = *(float *)(iVar1 + 0x100) + (float)param_1[0x120];
      param_1[3] = -0x10000;
      param_1[4] = (int)ButtonReturn__11CBaseButton;
    }
    else if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
      param_1[5] = 0;
      param_1[6] = 0;
    }
    else {
      param_1[5] = -0x10000;
      param_1[6] = (int)ButtonTouch__11CBaseButtonP11CBaseEntity;
    }
    *(undefined4 *)(*param_1 + 0x130) = 0x3f800000;
    uVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x132,3,0);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar2);
  }
  return;
}


