// FieldUse__16CFuncMortarFieldP11CBaseEntityT18USE_TYPEf  @ 000c3890
void FieldUse__16CFuncMortarFieldP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  float fStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined1 auStack_54 [20];
  undefined1 auStack_40 [36];
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float local_10;
  float local_c;
  float local_8;
  
  lVar4 = (longdouble)
          (*DAT_0019f80c)(*(undefined4 *)(*param_1 + 0xdc),*(undefined4 *)(*param_1 + 0xe8));
  local_10 = (float)lVar4;
  lVar4 = (longdouble)
          (*DAT_0019f80c)(*(undefined4 *)(*param_1 + 0xe0),*(undefined4 *)(*param_1 + 0xec));
  local_c = (float)lVar4;
  local_8 = *(float *)(*param_1 + 0xf0);
  iVar3 = param_1[0x143];
  if (iVar3 == 1) {
    if (param_2 != (int *)0x0) {
      local_10 = *(float *)(*param_2 + 8);
      local_c = *(float *)(*param_2 + 0xc);
    }
  }
  else if ((1 < iVar3) && (iVar3 == 2)) {
    if ((param_1[0x13e] != 0) &&
       (piVar2 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc
                                  (0,param_1[0x13e] + (int)gpGlobals[0x26]), piVar2 != (int *)0x0))
    {
      local_10 = *(float *)(*piVar2 + 0xac) * *(float *)(*param_1 + 0xf4) +
                 *(float *)(*param_1 + 0xdc);
    }
    if ((param_1[0x13f] != 0) &&
       (piVar2 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc
                                  (0,param_1[0x13f] + (int)gpGlobals[0x26]), piVar2 != (int *)0x0))
    {
      local_c = *(float *)(*piVar2 + 0xac) * *(float *)(*param_1 + 0xf8) +
                *(float *)(*param_1 + 0xe0);
    }
  }
  uVar1 = (*DAT_0019f808)(0x5f,0x7c);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),2,"weapons/mortar.wav",0x3f800000,0,0,uVar1);
  fStack_7c = 2.5;
  iVar3 = 0;
  if (0 < param_1[0x142]) {
    do {
      fStack_1c = local_10;
      fStack_18 = local_c;
      fStack_14 = local_8;
      lVar4 = (longdouble)(*DAT_0019f80c)(-(float)param_1[0x140],param_1[0x140]);
      fStack_1c = (float)(lVar4 + (longdouble)fStack_1c);
      lVar5 = (longdouble)(*DAT_0019f80c)(-(float)param_1[0x140],param_1[0x140]);
      lVar4 = (longdouble)fStack_18;
      fStack_58 = fStack_14 + -4096.0;
      uStack_78 = 0;
      uStack_74 = 0;
      uStack_70 = 0xbf800000;
      uStack_6c = 0;
      uStack_68 = 0;
      uStack_64 = 0xc5800000;
      fStack_60 = fStack_1c;
      fStack_18 = (float)(lVar5 + lVar4);
      fStack_5c = (float)(lVar5 + lVar4);
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&fStack_1c,&fStack_60,1,*(undefined4 *)(*param_1 + 0x208),auStack_54);
      uVar1 = 0;
      if (param_2 != (int *)0x0) {
        uVar1 = *(undefined4 *)(*param_2 + 0x208);
      }
      uStack_78 = 0;
      uStack_74 = 0;
      uStack_70 = 0;
      piVar2 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                                ("monster_mortar",auStack_40,&uStack_78,uVar1);
      *(float *)(*piVar2 + 0x104) = fStack_7c + *gpGlobals;
      lVar4 = (longdouble)(*DAT_0019f80c)(0x3e4ccccd,0x3f000000);
      fStack_7c = (float)(lVar4 + (longdouble)fStack_7c);
      if (iVar3 == 0) {
        InsertSound__9CSoundEntiRC6Vectorif(0x20,auStack_40,400,0x3e99999a);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[0x142]);
  }
  return;
}


