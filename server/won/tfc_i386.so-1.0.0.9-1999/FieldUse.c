// FieldUse__16CFuncMortarFieldP11CBaseEntityT18USE_TYPEf  @ 000c8fb0
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FieldUse__16CFuncMortarFieldP11CBaseEntityT18USE_TYPEf(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  longdouble lVar4;
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined1 local_54 [20];
  undefined1 local_40 [36];
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  lVar4 = (longdouble)
          (*DAT_0017562c)(*(undefined4 *)(*param_1 + 0xbc),*(undefined4 *)(*param_1 + 200));
  local_10 = (float)lVar4;
  lVar4 = (longdouble)
          (*DAT_0017562c)(*(undefined4 *)(*param_1 + 0xc0),*(undefined4 *)(*param_1 + 0xcc));
  local_c = (float)lVar4;
  local_8 = *(float *)(*param_1 + 0xd0);
  iVar3 = param_1[0x120];
  if (iVar3 == 1) {
    if (param_2 != (int *)0x0) {
      local_10 = *(float *)(*param_2 + 8);
      local_c = *(float *)(*param_2 + 0xc);
    }
  }
  else if ((1 < iVar3) && (iVar3 == 2)) {
    if ((param_1[0x11b] != 0) &&
       (piVar2 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc
                                  (0,(int)gpGlobals[0x26] + param_1[0x11b]), piVar2 != (int *)0x0))
    {
      local_10 = *(float *)(*piVar2 + 0x8c) * *(float *)(*param_1 + 0xd4) +
                 *(float *)(*param_1 + 0xbc);
    }
    if ((param_1[0x11c] != 0) &&
       (piVar2 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc
                                  (0,(int)gpGlobals[0x26] + param_1[0x11c]), piVar2 != (int *)0x0))
    {
      local_c = *(float *)(*piVar2 + 0x8c) * *(float *)(*param_1 + 0xd8) +
                *(float *)(*param_1 + 0xc0);
    }
  }
  uVar1 = (*DAT_00175628)(0x5f,0x7c);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),2,"weapons/mortar.wav",0x3f800000,0,0,uVar1);
  local_7c = 2.5;
  iVar3 = 0;
  if (0 < param_1[0x11f]) {
    do {
      local_1c = local_10;
      local_18 = local_c;
      local_14 = local_8;
      lVar4 = (longdouble)(*DAT_0017562c)(-(float)param_1[0x11d],param_1[0x11d]);
      local_1c = (float)(lVar4 + (longdouble)local_1c);
      lVar4 = (longdouble)(*DAT_0017562c)(-(float)param_1[0x11d],param_1[0x11d]);
      local_18 = (float)(lVar4 + (longdouble)local_18);
      local_78 = 0;
      local_74 = 0;
      local_70 = 0xbf800000;
      local_68 = 0;
      local_64 = 0xc5800000;
      local_6c = 0;
      local_60 = local_1c + 0.0;
      local_5c = local_18 + 0.0;
      local_58 = local_14 + -4096.0;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (&local_1c,&local_60,1,*(undefined4 *)(*param_1 + 0x1e8),local_54);
      uVar1 = 0;
      if (param_2 != (int *)0x0) {
        uVar1 = *(undefined4 *)(*param_2 + 0x1e8);
      }
      local_78 = 0;
      local_74 = 0;
      local_70 = 0;
      piVar2 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                                ("monster_mortar",local_40,&local_78,uVar1);
      *(float *)(*piVar2 + 0xe4) = local_7c + *gpGlobals;
      lVar4 = (longdouble)(*DAT_0017562c)(0x3e4ccccd,0x3f000000);
      local_7c = (float)(lVar4 + (longdouble)local_7c);
      if (iVar3 == 0) {
        InsertSound__9CSoundEntiRC6Vectorif(0x20,local_40,400,0x3e99999a);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[0x11f]);
  }
  return;
}


