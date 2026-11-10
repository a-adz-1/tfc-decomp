// FollowerUse__12CTalkMonsterP11CBaseEntityT18USE_TYPEf  @ 000f834c
void FollowerUse__12CTalkMonsterP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  code *pcVar6;
  bool bVar7;
  longdouble lVar8;
  char *pcVar9;
  
  fVar2 = *gpGlobals;
  fVar3 = (float)param_1[0x1bc];
  if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) {
    return;
  }
  if (param_3 == (int *)0x0) {
    return;
  }
  if ((*(byte *)(*param_3 + 0x1a4) & 8) == 0) {
    return;
  }
  if ((*(byte *)(*param_1 + 0x1a1) & 1) != 0) {
    (**(code **)(param_1[0x115] + 0x21c))(param_1);
    return;
  }
  if (((param_1[0x15d] != 6) || (iVar4 = CanInterrupt__12CCineMonster(param_1[0x1a6]), iVar4 != 0))
     && (iVar4 = (**(code **)(param_1[0x115] + 0x8c))(param_1), iVar4 != 0)) {
    bVar7 = false;
    piVar1 = param_1 + 0x141;
    iVar4 = __opP11CBaseEntity__7EHANDLE(piVar1);
    if (iVar4 != 0) {
      piVar5 = (int *)__rf__7EHANDLE(piVar1);
      bVar7 = (*(byte *)(*piVar5 + 0x1a4) & 8) != 0;
    }
    if (!bVar7) {
      LimitFollowers__12CTalkMonsterP11CBaseEntityi(param_1,param_3,1);
      if ((*(byte *)(param_1 + 399) & 1) == 0) {
        if (param_1[0x1a6] != 0) {
          CancelScript__12CCineMonster(param_1[0x1a6]);
        }
        iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13f);
        if (iVar4 != 0) {
          param_1[0x15e] = 3;
        }
        __as__7EHANDLEP11CBaseEntity(piVar1,param_3);
        iVar4 = param_1[0x115];
        lVar8 = (longdouble)(*DAT_0019f80c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
        (**(code **)(iVar4 + 0x188))(param_1,param_1[0x1ae],(float)lVar8);
        param_1[0x1c1] = param_1[0x141];
        param_1[0x1c2] = param_1[0x142];
        *(byte *)((int)param_1 + 0x4fb) = *(byte *)((int)param_1 + 0x4fb) & 0xef;
        ClearSchedule__12CBaseMonster(param_1);
        *(byte *)(param_1 + 0x1a7) = *(byte *)(param_1 + 0x1a7) | 8;
        return;
      }
      pcVar9 = "I\'m not following you, you evil person!\n";
      param_1 = (int *)0x1;
      pcVar6 = DAT_0019f794;
      goto LAB_000f852f;
    }
  }
  pcVar9 = (char *)0x1;
  pcVar6 = *(code **)(param_1[0x115] + 0x218);
LAB_000f852f:
  (*pcVar6)(param_1,pcVar9);
  return;
}


