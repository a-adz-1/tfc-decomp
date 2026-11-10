// ButtonBackHome__11CBaseButton  @ 0008c3a4
void ButtonBackHome__11CBaseButton(int *param_1)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  param_1[0x119] = 1;
  if ((*(byte *)(*param_1 + 0x1a0) & 0x20) != 0) {
    uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x12e,3,0);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar3);
  }
  if (*(int *)(*param_1 + 0x1c8) != 0) {
    iVar5 = 0;
LAB_0008c40c:
    iVar5 = (*DAT_001c1058)(iVar5,"targetname",*(int *)(*param_1 + 0x1c8) + (int)gpGlobals[0x26]);
    bVar2 = false;
    if (iVar5 == 0) {
LAB_0008c45b:
      bVar2 = true;
    }
    else {
      iVar4 = (*DAT_001c1138)(iVar5);
      if (iVar4 == 0) goto LAB_0008c45b;
    }
    if (!bVar2) {
      piVar6 = (int *)(iVar5 + 0x80);
      if (iVar5 == 0) {
        piVar6 = (int *)0x0;
      }
      iVar4 = strcmp((char *)(*piVar6 + (int)gpGlobals[0x26]),"multisource");
      if (iVar4 == 0) {
        iVar4 = iVar5;
        if (iVar5 == 0) {
          iVar4 = (*DAT_001c1134)(0);
          if (iVar4 != 0) goto LAB_0008c4b9;
          iVar4 = 0;
        }
        else {
LAB_0008c4b9:
          iVar4 = *(int *)(iVar4 + 0x7c);
        }
        if (iVar4 != 0) {
          iVar1 = *(int *)(iVar4 + 0x444);
          uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x12e,param_1,3,0);
          (**(code **)(iVar1 + 0xb8))(iVar4,uVar3);
        }
      }
      goto LAB_0008c40c;
    }
  }
  if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
    param_1[5] = 0;
    param_1[6] = 0;
  }
  else {
    param_1[5] = -0x10000;
    param_1[6] = (int)ButtonTouch__11CBaseButtonP11CBaseEntity;
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 0x40) != 0) {
    param_1[3] = -0x10000;
    param_1[4] = (int)ButtonSpark__11CBaseButton;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.5;
  }
  return;
}


