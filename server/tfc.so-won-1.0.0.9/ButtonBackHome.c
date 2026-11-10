// ButtonBackHome__11CBaseButton  @ 0009ee50
void ButtonBackHome__11CBaseButton(int *param_1)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  param_1[0xfa] = 1;
  if ((*(byte *)(*param_1 + 0x180) & 0x20) != 0) {
    uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x10f,3,0);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar3);
  }
  if (*(int *)(*param_1 + 0x1a8) != 0) {
    iVar6 = 0;
LAB_0009eea8:
    iVar6 = (*DAT_001754f8)(iVar6,"targetname",*(int *)(*param_1 + 0x1a8) + (int)gpGlobals[0x26]);
    bVar2 = false;
    if (iVar6 == 0) {
LAB_0009eee7:
      bVar2 = true;
    }
    else {
      iVar4 = (*DAT_001755d8)(iVar6);
      if (iVar4 == 0) goto LAB_0009eee7;
    }
    if (!bVar2) {
      if (iVar6 == 0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)(iVar6 + 0xdc);
      }
      iVar4 = strcmp((char *)(*piVar5 + (int)gpGlobals[0x26]),"multisource");
      if (iVar4 == 0) {
        iVar4 = iVar6;
        if (iVar6 == 0) {
          iVar4 = (*DAT_001755d4)(0);
          if (iVar4 != 0) goto LAB_0009ef3c;
          iVar4 = 0;
        }
        else {
LAB_0009ef3c:
          iVar4 = *(int *)(iVar4 + 0xd8);
        }
        if (iVar4 != 0) {
          iVar1 = *(int *)(iVar4 + 0x3c8);
          uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x10f,param_1,3,0);
          (**(code **)(iVar1 + 0xb0))(iVar4,uVar3);
        }
      }
      goto LAB_0009eea8;
    }
  }
  if ((*(byte *)(*param_1 + 0x181) & 1) == 0) {
    param_1[5] = 0;
    param_1[6] = 0;
  }
  else {
    param_1[5] = -0x10000;
    param_1[6] = (int)ButtonTouch__11CBaseButtonP11CBaseEntity;
  }
  if ((*(byte *)(*param_1 + 0x180) & 0x40) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)ButtonSpark__11CBaseButton;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.5;
  }
  return;
}


