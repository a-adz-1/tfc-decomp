// ButtonBackHome__11CBaseButton  @ 0008b5cc
void ButtonBackHome__11CBaseButton(int *param_1)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int local_c;
  
  iVar4 = *param_1;
  param_1[0x11d] = 1;
  if ((*(byte *)(iVar4 + 0x1a0) & 0x20) != 0) {
    uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x132,3,0);
    SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf(param_1,uVar3);
    iVar4 = *param_1;
  }
  if (*(int *)(iVar4 + 0x1c8) != 0) {
    local_c = 0;
LAB_0008b6c1:
    local_c = (*DAT_0019f6d8)(local_c,"targetname",*(int *)(*param_1 + 0x1c8) + (int)gpGlobals[0x26]
                             );
    bVar2 = false;
    if (local_c == 0) {
LAB_0008b716:
      bVar2 = true;
    }
    else {
      iVar4 = (*DAT_0019f7b8)(local_c);
      if (iVar4 == 0) goto LAB_0008b716;
    }
    if (!bVar2) {
      piVar5 = (int *)(local_c + 0x80);
      if (local_c == 0) {
        piVar5 = (int *)0x0;
      }
      iVar4 = strcmp((char *)(*piVar5 + (int)gpGlobals[0x26]),"multisource");
      if (iVar4 == 0) {
        iVar4 = local_c;
        if (local_c == 0) {
          iVar4 = (*DAT_0019f7b4)(0);
          if (iVar4 != 0) goto LAB_0008b688;
          iVar4 = 0;
        }
        else {
LAB_0008b688:
          iVar4 = *(int *)(iVar4 + 0x7c);
        }
        if (iVar4 != 0) {
          iVar1 = *(int *)(iVar4 + 0x454);
          uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x132,param_1,3,0);
          (**(code **)(iVar1 + 0xb8))(iVar4,uVar3);
        }
      }
      goto LAB_0008b6c1;
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


