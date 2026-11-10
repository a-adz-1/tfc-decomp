// FIdleSpeak__12CTalkMonster  @ 000f7c30
undefined4 FIdleSpeak__12CTalkMonster(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  longdouble lVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int local_c;
  int local_8;
  
  iVar4 = FOkToSpeak__12CTalkMonster(param_1);
  if (iVar4 == 0) {
    return 0;
  }
  if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
    local_8 = param_1[0x1ac];
    local_c = param_1[0x1ab];
    uVar10 = 0x404ccccd;
    uVar9 = 0x40333333;
  }
  else {
    local_8 = param_1[0x1b4];
    local_c = param_1[0x1b5];
    uVar10 = 0x40a66666;
    uVar9 = 0x4099999a;
  }
  lVar8 = (longdouble)(*DAT_0019f80c)(uVar9,uVar10);
  fVar1 = (float)lVar8;
  (*DAT_0019f808)(0,3);
  piVar6 = param_1 + 0x141;
  piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(piVar6);
  if (((piVar5 != (int *)0x0) && ((*(byte *)(*piVar5 + 0x1a4) & 8) != 0)) &&
     (iVar4 = (**(code **)(piVar5[0x115] + 0x8c))(piVar5), iVar4 != 0)) {
    param_1[0x1c1] = param_1[0x141];
    param_1[0x1c2] = param_1[0x142];
    if ((*(byte *)(param_1 + 0x1a7) & 4) == 0) {
      piVar5 = (int *)__rf__7EHANDLE(piVar6);
      iVar4 = *piVar5;
      piVar5 = (int *)__rf__7EHANDLE(piVar6);
      fVar3 = *(float *)(*piVar5 + 0x1b0) * 0.125;
      fVar2 = *(float *)(iVar4 + 0x160);
      if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 1) {
        (**(code **)(param_1[0x115] + 0x188))(param_1,param_1[0x1b8],fVar1,0x3f800000,0x40000000);
        *(byte *)(param_1 + 0x1a7) = *(byte *)(param_1 + 0x1a7) | 4;
        return 1;
      }
    }
    if ((*(byte *)(param_1 + 0x1a7) & 2) == 0) {
      piVar5 = (int *)__rf__7EHANDLE(piVar6);
      iVar4 = *piVar5;
      piVar5 = (int *)__rf__7EHANDLE(piVar6);
      fVar3 = *(float *)(*piVar5 + 0x1b0) * 0.25;
      fVar2 = *(float *)(iVar4 + 0x160);
      if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 1) {
        (**(code **)(param_1[0x115] + 0x188))(param_1,param_1[0x1b7],fVar1,0x3f800000,0x40000000);
        *(byte *)(param_1 + 0x1a7) = *(byte *)(param_1 + 0x1a7) | 2;
        return 1;
      }
    }
    if (((*(byte *)(param_1 + 0x1a7) ^ 1) & 1) != 0) {
      piVar5 = (int *)__rf__7EHANDLE(piVar6);
      iVar4 = *piVar5;
      piVar6 = (int *)__rf__7EHANDLE(piVar6);
      fVar3 = *(float *)(*piVar6 + 0x1b0) * 0.5;
      fVar2 = *(float *)(iVar4 + 0x160);
      if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 1) {
        (**(code **)(param_1[0x115] + 0x188))(param_1,param_1[0x1b6],fVar1,0x3f800000,0x40000000);
        *(byte *)(param_1 + 0x1a7) = *(byte *)(param_1 + 0x1a7) | 1;
        return 1;
      }
    }
  }
  iVar4 = FindNearestFriend__12CTalkMonsteri(param_1,0);
  if (((iVar4 == 0) || (iVar7 = (**(code **)(*(int *)(iVar4 + 0x454) + 0x6c))(iVar4), iVar7 != 0))
     || (iVar7 = (*DAT_0019f808)(0,99), 0x4a < iVar7)) {
    iVar4 = (*DAT_0019f808)(0,1);
    if ((iVar4 == 0) || (iVar4 = FindNearestFriend__12CTalkMonsteri(param_1,1), iVar4 == 0)) {
      Talk__12CTalkMonsterf(param_1,0);
      _12CTalkMonster_g_talkWaitTime = 0;
      return 0;
    }
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x1c1,iVar4);
    (**(code **)(param_1[0x115] + 0x188))(param_1,local_8,fVar1,0x3f800000,0x40000000);
  }
  else {
    (**(code **)(param_1[0x115] + 0x188))(param_1,local_c,fVar1,0x3f800000,0x40000000);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x1c1,iVar4);
    (**(code **)(*(int *)(iVar4 + 0x454) + 0x220))(iVar4,param_1);
    *(int *)(iVar4 + 0x700) = param_1[0x1c0];
  }
  param_1[0x1a8] = param_1[0x1a8] + 1;
  return 1;
}


