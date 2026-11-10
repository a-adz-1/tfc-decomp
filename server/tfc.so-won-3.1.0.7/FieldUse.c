// FieldUse__16CFuncMortarFieldP11CBaseEntityT18USE_TYPEf  @ 000c3104
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FieldUse__16CFuncMortarFieldP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  longdouble lVar4;
  float local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined1 local_50 [20];
  undefined1 local_3c [36];
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  lVar4 = (longdouble)
          (*DAT_001c118c)(*(undefined4 *)(*param_1 + 0xdc),*(undefined4 *)(*param_1 + 0xe8));
  local_c = (float)lVar4;
  lVar4 = (longdouble)
          (*DAT_001c118c)(*(undefined4 *)(*param_1 + 0xe0),*(undefined4 *)(*param_1 + 0xec));
  local_8 = (float)lVar4;
  local_4 = *(float *)(*param_1 + 0xf0);
  iVar3 = param_1[0x13f];
  if (iVar3 == 1) {
    if (param_2 != (int *)0x0) {
      local_c = *(float *)(*param_2 + 8);
      local_8 = *(float *)(*param_2 + 0xc);
    }
  }
  else if ((1 < iVar3) && (iVar3 == 2)) {
    if ((param_1[0x13a] != 0) &&
       (piVar2 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc
                                  (0,param_1[0x13a] + (int)gpGlobals[0x26]), piVar2 != (int *)0x0))
    {
      local_c = *(float *)(*piVar2 + 0xac) * *(float *)(*param_1 + 0xf4) +
                *(float *)(*param_1 + 0xdc);
    }
    if ((param_1[0x13b] != 0) &&
       (piVar2 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc
                                  (0,param_1[0x13b] + (int)gpGlobals[0x26]), piVar2 != (int *)0x0))
    {
      local_8 = *(float *)(*piVar2 + 0xac) * *(float *)(*param_1 + 0xf8) +
                *(float *)(*param_1 + 0xe0);
    }
  }
  uVar1 = (*DAT_001c1188)(0x5f,0x7c);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),2,"weapons/mortar.wav",0x3f800000,0,0,uVar1);
  local_78 = 2.5;
  iVar3 = 0;
  if (0 < param_1[0x13e]) {
    do {
      local_18 = local_c;
      local_14 = local_8;
      local_10 = local_4;
      lVar4 = (longdouble)(*DAT_001c118c)(-(float)param_1[0x13c],param_1[0x13c]);
      local_18 = (float)(lVar4 + (longdouble)local_18);
      lVar4 = (longdouble)(*DAT_001c118c)(-(float)param_1[0x13c],param_1[0x13c]);
      local_14 = (float)(lVar4 + (longdouble)local_14);
      local_74 = 0;
      local_70 = 0;
      local_6c = 0xbf800000;
      local_64 = 0;
      local_60 = 0xc5800000;
      local_68 = 0;
      local_58 = local_14 + 0.0;
      local_54 = local_10 + -4096.0;
      local_5c = local_18;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_18,&local_5c,1,*(undefined4 *)(*param_1 + 0x208),local_50);
      uVar1 = 0;
      if (param_2 != (int *)0x0) {
        uVar1 = *(undefined4 *)(*param_2 + 0x208);
      }
      local_74 = 0;
      local_70 = 0;
      local_6c = 0;
      piVar2 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                                ("monster_mortar",local_3c,&local_74,uVar1);
      *(float *)(*piVar2 + 0x104) = local_78 + *gpGlobals;
      lVar4 = (longdouble)(*DAT_001c118c)(0x3e4ccccd,0x3f000000);
      local_78 = (float)(lVar4 + (longdouble)local_78);
      if (iVar3 == 0) {
        InsertSound__9CSoundEntiRC6Vectorif(0x20,local_3c,400,0x3e99999a);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[0x13e]);
  }
  return;
}


