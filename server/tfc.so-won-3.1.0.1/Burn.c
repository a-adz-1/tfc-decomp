// Burn__16CTFNapalmGrenade  @ 000f17e0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Burn__16CTFNapalmGrenade(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  local_4 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = local_4;
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x193];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"ambience/fire1.wav",0x3f800000,0x3f4ccccd,0,100)
    ;
    iVar3 = *param_1;
    local_10 = *(undefined4 *)(iVar3 + 8);
    local_c = *(undefined4 *)(iVar3 + 0xc);
    local_8 = *(undefined4 *)(iVar3 + 0x10);
    iVar4 = *(int *)(iVar3 + 0x198) + 0x80;
    if (*(int *)(iVar3 + 0x198) == 0) {
      iVar4 = 0;
    }
    RadiusDamage__FG6VectorP9entvars_sT1ffii
              (&local_10,*param_1,iVar4,*(undefined4 *)(iVar3 + 0x1e0),param_1[399],0,
               param_1[0x191] | 0x3000000);
    if (*(int *)(*param_1 + 0x198) == 0) {
      (*DAT_001a7f54)(0);
    }
    param_1[400] = param_1[400] + -1;
    if (param_1[400] < 1) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    else {
      local_4 = (float)_FUN_0013e808 + (float)param_1[0x193];
      param_1[0x193] = (int)local_4;
    }
  }
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x192];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    if (m_usBurn_857 == 0) {
      m_usBurn_857 = (*DAT_001a8028)(1,"events/explode/tf_burn.sc");
    }
    (*DAT_001a802c)(0,*(undefined4 *)(*param_1 + 0x208),m_usBurn_857,0,*param_1 + 8,&g_vecZero,0,0,0
                    ,0,0,0);
    param_1[0x192] = (int)((float)param_1[0x192] + 0.5);
  }
  return;
}


