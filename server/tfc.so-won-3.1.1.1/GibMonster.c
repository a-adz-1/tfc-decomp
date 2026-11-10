// GibMonster__11CBaseTurret  @ 0011d560
void GibMonster__11CBaseTurret(void)

{
  return;
}


// GibMonster__12CBaseMonster  @ 000955fc
void GibMonster__12CBaseMonster(int *param_1)

{
  float fVar1;
  longdouble lVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  char cVar6;
  longdouble lVar7;
  
  bVar3 = false;
  bVar4 = false;
  if (usGibs_646 == 0) {
    usGibs_646 = (*DAT_0019f888)(1,"events/misc/gibs.sc");
  }
  iVar5 = (**(code **)(param_1[0x115] + 500))(param_1);
  if (iVar5 == 0) {
    iVar5 = (**(code **)(param_1[0x115] + 0x1f8))(param_1);
    if (iVar5 == 0) goto LAB_00095774;
    lVar7 = (longdouble)(*DAT_0019f784)("violence_agibs");
    lVar2 = (longdouble)0;
    if ((byte)(lVar2 < lVar7 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar7)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar2 == lVar7) << 0xe) >> 8)) != 0x40) {
      SpawnRandomGibs__4CGibP9entvars_sii(*param_1,4,0);
    }
  }
  else {
    lVar7 = (longdouble)(*DAT_0019f784)("violence_hgibs");
    lVar2 = (longdouble)0;
    if ((byte)(lVar2 < lVar7 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar7)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar2 == lVar7) << 0xe) >> 8)) != 0x40) {
      fVar1 = *(float *)(*param_1 + 0x160);
      if ((byte)((fVar1 < -50.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == -50.0) << 0xe) >> 8)) - 1) < 0x40) {
        cVar6 = ((byte)(-200.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == -200.0) << 0xe) >> 8)) == 1) * '\x02';
      }
      else {
        cVar6 = '\x01';
      }
      bVar4 = true;
      if (usGibs_646 != 0) {
        (*DAT_0019f88c)(0,0,usGibs_646,0,*param_1 + 8,&g_vecAttackDir,0,0,cVar6,0,0,0);
      }
    }
  }
  bVar3 = true;
LAB_00095774:
  if ((*(byte *)(*param_1 + 0x1a4) & 8) == 0) {
    if (bVar3) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_Remove__11CBaseEntity;
      *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
    }
    else {
      (**(code **)(param_1[0x115] + 0x1fc))(param_1);
    }
  }
  if (!bVar4) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"common/bodysplat.wav",0x3f800000,0x3f4ccccd,0,
               100);
  }
  return;
}


