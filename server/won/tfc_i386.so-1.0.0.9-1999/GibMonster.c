// GibMonster__11CBaseTurret  @ 00116640
void GibMonster__11CBaseTurret(void)

{
  return;
}


// GibMonster__12CBaseMonster  @ 000a4700
void GibMonster__12CBaseMonster(int *param_1)

{
  longdouble lVar1;
  bool bVar2;
  int iVar3;
  longdouble lVar4;
  
  bVar2 = false;
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),1,"common/bodysplat.wav",0x3f800000,0x3f4ccccd,0,100)
  ;
  iVar3 = (**(code **)(param_1[0xf2] + 0x1ec))(param_1);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(param_1[0xf2] + 0x1f0))(param_1);
    if (iVar3 == 0) goto LAB_000a47c7;
    lVar4 = (longdouble)(*DAT_001755a4)("violence_agibs");
    lVar1 = (longdouble)0;
    if ((byte)(lVar1 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar1 == lVar4) << 0xe) >> 8)) != 0x40) {
      SpawnRandomGibs__4CGibP9entvars_tii(*param_1,4,0);
    }
  }
  else {
    lVar4 = (longdouble)(*DAT_001755a4)("violence_hgibs");
    lVar1 = (longdouble)0;
    if ((byte)(lVar1 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar1 == lVar4) << 0xe) >> 8)) != 0x40) {
      SpawnHeadGib__4CGibP9entvars_t(*param_1);
      SpawnRandomGibs__4CGibP9entvars_tii(*param_1,4,1);
    }
  }
  bVar2 = true;
LAB_000a47c7:
  if ((*(byte *)(*param_1 + 0x184) & 8) == 0) {
    if (bVar2) {
      param_1[3] = -0x10000;
      param_1[4] = (int)SUB_Remove__11CBaseEntity;
      *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
    }
    else {
      (**(code **)(param_1[0xf2] + 500))(param_1);
    }
  }
  return;
}


