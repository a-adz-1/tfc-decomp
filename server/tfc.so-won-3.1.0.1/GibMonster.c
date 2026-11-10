// GibMonster__11CBaseTurret  @ 00109a80
void GibMonster__11CBaseTurret(void)

{
  return;
}


// GibMonster__12CBaseMonster  @ 0008cf8c
void GibMonster__12CBaseMonster(int *param_1)

{
  float fVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  char cVar5;
  longdouble lVar6;
  longdouble lVar7;
  
  bVar2 = false;
  bVar3 = false;
  if (usGibs_622 == 0) {
    usGibs_622 = (*DAT_001a8028)(1,"events/misc/gibs.sc");
  }
  iVar4 = (**(code **)(param_1[0xf5] + 0x1ec))(param_1);
  if (iVar4 == 0) {
    iVar4 = (**(code **)(param_1[0xf5] + 0x1f0))(param_1);
    if (iVar4 == 0) goto LAB_0008d116;
    lVar6 = (longdouble)(*DAT_001a7f24)("violence_agibs");
    lVar7 = (longdouble)0.0;
    if ((byte)(lVar7 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) != 0x40) {
      SpawnRandomGibs__4CGibP9entvars_sii(*param_1,4,0);
    }
  }
  else {
    lVar6 = (longdouble)(*DAT_001a7f24)("violence_hgibs");
    lVar7 = (longdouble)0.0;
    if ((byte)(lVar7 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) != 0x40) {
      if (*(float *)(*param_1 + 0x160) <= -50.0) {
        fVar1 = *(float *)(*param_1 + 0x160);
        cVar5 = ((byte)(-200.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == -200.0) << 0xe) >> 8)) == 1) * '\x02';
      }
      else {
        cVar5 = '\x01';
      }
      bVar3 = true;
      if (usGibs_622 != 0) {
        (*DAT_001a802c)(0,0,usGibs_622,0,*param_1 + 8,&g_vecAttackDir,0,0,cVar5,0,0,0);
      }
    }
  }
  bVar2 = true;
LAB_0008d116:
  if ((*(byte *)(*param_1 + 0x1a4) & 8) == 0) {
    if (bVar2) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_Remove__11CBaseEntity;
      *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
    }
    else {
      (**(code **)(param_1[0xf5] + 500))(param_1);
    }
  }
  if (!bVar3) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"common/bodysplat.wav",0x3f800000,0x3f4ccccd,0,
               100);
  }
  return;
}


