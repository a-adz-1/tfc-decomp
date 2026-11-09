// Burn__16CTFNapalmGrenade  @ 000fe2e0
void Burn__16CTFNapalmGrenade(int *param_1)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  pfVar2 = gpGlobals;
  local_8 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0xe4) = local_8;
  if ((float)param_1[0x18e] <= *pfVar2) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),1,"ambience/fire1.wav",0x3f800000,0x3f4ccccd,0,100)
    ;
    iVar1 = *param_1;
    local_14 = *(undefined4 *)(iVar1 + 8);
    local_10 = *(undefined4 *)(iVar1 + 0xc);
    local_c = *(undefined4 *)(iVar1 + 0x10);
    if (*(int *)(iVar1 + 0x178) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar1 + 0x178) + 0xdc;
    }
    RadiusDamage__FG6VectorP9entvars_tT1ffii
              (&local_14,*param_1,iVar3,*(undefined4 *)(iVar1 + 0x1c0),param_1[0x18a],0,
               param_1[0x18c] | 0x3000000);
    if (*(int *)(*param_1 + 0x178) == 0) {
      (*DAT_001755d4)(0);
    }
    param_1[0x18b] = param_1[0x18b] + -1;
    if (param_1[0x18b] < 1) {
      UTIL_Remove__FP11CBaseEntity(param_1);
    }
    else {
      local_8 = (float)param_1[0x18e] + 1.0;
      param_1[0x18e] = (int)local_8;
    }
  }
  if ((float)param_1[0x18d] <= *gpGlobals) {
    (*DAT_00175578)(4,0x17,*param_1 + 8,0);
    (*DAT_00175580)(0x7b);
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_00175594)(*(float *)(*param_1 + 0x10) + 16.0);
    (*DAT_00175588)(100);
    (*DAT_00175588)((int)g_sModelIndexPlayerFlame);
    (*DAT_00175580)(0xc);
    (*DAT_00175580)(0x12);
    (*DAT_00175580)(8);
    (*DAT_0017557c)();
    param_1[0x18d] = (int)((float)param_1[0x18d] + 0.5);
  }
  return;
}


