// FIdleSpeak__12CTalkMonster  @ 000f5f10
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
  int local_8;
  int local_4;
  
  iVar4 = FOkToSpeak__12CTalkMonster(param_1);
  if (iVar4 == 0) {
    return 0;
  }
  if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
    local_4 = param_1[0x1a8];
    local_8 = param_1[0x1a7];
    uVar10 = 0x404ccccd;
    uVar9 = 0x40333333;
  }
  else {
    local_4 = param_1[0x1b0];
    local_8 = param_1[0x1b1];
    uVar10 = 0x40a66666;
    uVar9 = 0x4099999a;
  }
  lVar8 = (longdouble)(*DAT_001c118c)(uVar9,uVar10);
  fVar1 = (float)lVar8;
  GetVoicePitch__12CTalkMonster(param_1);
  piVar6 = param_1 + 0x13d;
  piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(piVar6);
  if (((piVar5 != (int *)0x0) && ((*(byte *)(*piVar5 + 0x1a4) & 8) != 0)) &&
     (iVar4 = (**(code **)(piVar5[0x111] + 0x8c))(piVar5), iVar4 != 0)) {
    param_1[0x1bd] = param_1[0x13d];
    param_1[0x1be] = param_1[0x13e];
    if ((*(byte *)(param_1 + 0x1a3) & 4) == 0) {
      piVar5 = (int *)__rf__7EHANDLE(piVar6);
      iVar4 = *piVar5;
      piVar6 = (int *)__rf__7EHANDLE(piVar6);
      fVar3 = *(float *)(*piVar6 + 0x1b0) * 0.125;
      fVar2 = *(float *)(iVar4 + 0x160);
      if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 1) {
        (**(code **)(param_1[0x111] + 0x188))(param_1,param_1[0x1b4],fVar1,0x3f800000,0x40000000);
        *(byte *)(param_1 + 0x1a3) = *(byte *)(param_1 + 0x1a3) | 4;
        return 1;
      }
    }
    if ((*(byte *)(param_1 + 0x1a3) & 2) == 0) {
      piVar6 = (int *)__rf__7EHANDLE(param_1 + 0x13d);
      iVar4 = *piVar6;
      piVar6 = (int *)__rf__7EHANDLE(param_1 + 0x13d);
      fVar3 = *(float *)(*piVar6 + 0x1b0) * 0.25;
      fVar2 = *(float *)(iVar4 + 0x160);
      if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 1) {
        (**(code **)(param_1[0x111] + 0x188))(param_1,param_1[0x1b3],fVar1,0x3f800000,0x40000000);
        *(byte *)(param_1 + 0x1a3) = *(byte *)(param_1 + 0x1a3) | 2;
        return 1;
      }
    }
    if (((*(byte *)(param_1 + 0x1a3) ^ 1) & 1) != 0) {
      piVar6 = (int *)__rf__7EHANDLE(param_1 + 0x13d);
      iVar4 = *piVar6;
      piVar6 = (int *)__rf__7EHANDLE(param_1 + 0x13d);
      fVar3 = *(float *)(*piVar6 + 0x1b0) * 0.5;
      fVar2 = *(float *)(iVar4 + 0x160);
      if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 1) {
        (**(code **)(param_1[0x111] + 0x188))(param_1,param_1[0x1b2],fVar1,0x3f800000,0x40000000);
        *(byte *)(param_1 + 0x1a3) = *(byte *)(param_1 + 0x1a3) | 1;
        return 1;
      }
    }
  }
  iVar4 = FindNearestFriend__12CTalkMonsteri(param_1,0);
  if (((iVar4 != 0) && (iVar7 = (**(code **)(*(int *)(iVar4 + 0x444) + 0x6c))(iVar4), iVar7 == 0))
     && (iVar7 = (*DAT_001c1188)(0,99), iVar7 < 0x4b)) {
    (**(code **)(param_1[0x111] + 0x188))(param_1,local_8,fVar1,0x3f800000,0x40000000);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x1bd,iVar4);
    (**(code **)(*(int *)(iVar4 + 0x444) + 0x220))(iVar4,param_1);
    *(int *)(iVar4 + 0x6f0) = param_1[0x1bc];
    param_1[0x1a4] = param_1[0x1a4] + 1;
    return 1;
  }
  iVar4 = (*DAT_001c1188)(0,1);
  if ((iVar4 != 0) && (iVar4 = FindNearestFriend__12CTalkMonsteri(param_1,1), iVar4 != 0)) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x1bd,iVar4);
    (**(code **)(param_1[0x111] + 0x188))(param_1,local_4,fVar1,0x3f800000,0x40000000);
    param_1[0x1a4] = param_1[0x1a4] + 1;
    return 1;
  }
  Talk__12CTalkMonsterf(param_1,0);
  _12CTalkMonster_g_talkWaitTime = 0;
  return 0;
}


