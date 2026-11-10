// Burn__16CTFNapalmGrenade  @ 001006a8
void Burn__16CTFNapalmGrenade(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  local_8 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = local_8;
  if ((float)param_1[0x1b3] <= *gpGlobals) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"ambience/fire1.wav",0x3f800000,0x3f4ccccd,0,100)
    ;
    iVar1 = *param_1;
    local_14 = *(undefined4 *)(iVar1 + 8);
    local_10 = *(undefined4 *)(iVar1 + 0xc);
    local_c = *(undefined4 *)(iVar1 + 0x10);
    iVar2 = *(int *)(iVar1 + 0x198) + 0x80;
    if (*(int *)(iVar1 + 0x198) == 0) {
      iVar2 = 0;
    }
    RadiusDamage__FG6VectorP9entvars_sT1ffii
              (&local_14,iVar1,iVar2,*(undefined4 *)(iVar1 + 0x1e0),param_1[0x1af],0,
               param_1[0x1b1] | 0x3000000);
    if (*(int *)(*param_1 + 0x198) == 0) {
      (*DAT_0019f7b4)(0);
    }
    iVar2 = param_1[0x1b0];
    param_1[0x1b0] = iVar2 + -1;
    if (iVar2 == 1 || iVar2 + -1 < 0) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    else {
      local_8 = (float)param_1[0x1b3] + 1.0;
      param_1[0x1b3] = (int)local_8;
    }
  }
  if ((float)param_1[0x1b2] <= *gpGlobals) {
    if (m_usBurn_861 == 0) {
      m_usBurn_861 = (*DAT_0019f888)(1,"events/explode/tf_burn.sc");
    }
    (*DAT_0019f88c)(0,*(undefined4 *)(*param_1 + 0x208),m_usBurn_861,0,*param_1 + 8,&g_vecZero,0,0,0
                    ,0,0,0);
    param_1[0x1b2] = (int)((float)param_1[0x1b2] + 0.5);
  }
  return;
}


