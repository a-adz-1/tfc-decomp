// FIdleSpeak__12CTalkMonster  @ 000f2620
undefined4 FIdleSpeak__12CTalkMonster(int *param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  longdouble lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int local_c;
  int local_8;
  
  iVar2 = FOkToSpeak__12CTalkMonster(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if ((*(byte *)(*param_1 + 0x181) & 1) == 0) {
    local_8 = param_1[0x189];
    local_c = param_1[0x188];
    uVar8 = 0x404ccccd;
    uVar7 = 0x40333333;
  }
  else {
    local_8 = param_1[0x191];
    local_c = param_1[0x192];
    uVar8 = 0x40a66666;
    uVar7 = 0x4099999a;
  }
  lVar6 = (longdouble)(*DAT_0017562c)(uVar7,uVar8);
  fVar1 = (float)lVar6;
  GetVoicePitch__12CTalkMonster(param_1);
  piVar4 = param_1 + 0x11e;
  piVar3 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4);
  if (((piVar3 != (int *)0x0) && ((*(byte *)(*piVar3 + 0x184) & 8) != 0)) &&
     (iVar2 = (**(code **)(piVar3[0xf2] + 0x88))(piVar3), iVar2 != 0)) {
    param_1[0x19e] = param_1[0x11e];
    param_1[0x19f] = param_1[0x11f];
    if ((*(byte *)(param_1 + 0x184) & 4) == 0) {
      piVar3 = (int *)__rf__7EHANDLE(piVar4);
      iVar2 = *piVar3;
      piVar4 = (int *)__rf__7EHANDLE(piVar4);
      if (*(float *)(iVar2 + 0x140) <= *(float *)(*piVar4 + 400) * 0.125) {
        (**(code **)(param_1[0xf2] + 0x180))(param_1,param_1[0x195],fVar1,0x3f800000,0x40000000);
        *(byte *)(param_1 + 0x184) = *(byte *)(param_1 + 0x184) | 4;
        return 1;
      }
    }
    if ((*(byte *)(param_1 + 0x184) & 2) == 0) {
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x11e);
      iVar2 = *piVar4;
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x11e);
      if (*(float *)(iVar2 + 0x140) <= *(float *)(*piVar4 + 400) * 0.25) {
        (**(code **)(param_1[0xf2] + 0x180))(param_1,param_1[0x194],fVar1,0x3f800000,0x40000000);
        *(byte *)(param_1 + 0x184) = *(byte *)(param_1 + 0x184) | 2;
        return 1;
      }
    }
    if (((*(byte *)(param_1 + 0x184) ^ 1) & 1) != 0) {
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x11e);
      iVar2 = *piVar4;
      piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x11e);
      if (*(float *)(iVar2 + 0x140) <= *(float *)(*piVar4 + 400) * 0.5) {
        (**(code **)(param_1[0xf2] + 0x180))(param_1,param_1[0x193],fVar1,0x3f800000,0x40000000);
        *(byte *)(param_1 + 0x184) = *(byte *)(param_1 + 0x184) | 1;
        return 1;
      }
    }
  }
  iVar2 = FindNearestFriend__12CTalkMonsteri(param_1,0);
  if (((iVar2 == 0) || (iVar5 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x68))(iVar2), iVar5 != 0))
     || (iVar5 = (*DAT_00175628)(0,99), 0x4a < iVar5)) {
    iVar2 = (*DAT_00175628)(0,1);
    if ((iVar2 == 0) || (iVar2 = FindNearestFriend__12CTalkMonsteri(param_1,1), iVar2 == 0)) {
      Talk__12CTalkMonsterf(param_1,0);
      _12CTalkMonster_g_talkWaitTime = 0;
      return 0;
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x19e,iVar2);
    (**(code **)(param_1[0xf2] + 0x180))(param_1,local_8,fVar1,0x3f800000,0x40000000);
  }
  else {
    (**(code **)(param_1[0xf2] + 0x180))(param_1,local_c,fVar1,0x3f800000,0x40000000);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x19e,iVar2);
    (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x218))(iVar2,param_1);
    *(int *)(iVar2 + 0x674) = param_1[0x19d];
  }
  param_1[0x185] = param_1[0x185] + 1;
  return 1;
}


