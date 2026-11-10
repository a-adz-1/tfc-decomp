// NailGrenadeLaunchNail__14CTFNailGrenade  @ 000fd510
void NailGrenadeLaunchNail__14CTFNailGrenade(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  longdouble lVar4;
  char *pcVar5;
  undefined4 local_34;
  float local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  float local_c;
  undefined4 local_8;
  
  local_10 = g_vecZero;
  local_c = DAT_00175484;
  local_8 = DAT_00175488;
  iVar3 = 0;
  do {
    lVar4 = (longdouble)(*DAT_0017562c)(0x40000000,0x40400000);
    lVar4 = (longdouble)
            UTIL_AngleMod__Ff((float)((longdouble)local_c + (longdouble)*(float *)(*param_1 + 0x54)
                                     + (longdouble)5.0 * lVar4));
    local_c = (float)lVar4;
    UTIL_MakeVectors__FRC6Vector(&local_10);
    local_28 = gpGlobals[10] * 12.0;
    local_24 = gpGlobals[0xb] * 12.0;
    local_20 = gpGlobals[0xc] * 12.0;
    iVar1 = *param_1;
    local_1c = *(float *)(iVar1 + 8) + local_28;
    local_18 = *(float *)(iVar1 + 0xc) + local_24;
    local_14 = *(float *)(iVar1 + 0x10) + local_20;
    local_34 = local_10;
    local_30 = local_c;
    local_2c = local_8;
    iVar1 = *(int *)(iVar1 + 0x178);
    if (iVar1 == 0) {
      iVar1 = (*DAT_001755d4)(0,0);
      if (iVar1 != 0) goto LAB_000fd5ef;
      uVar2 = 0;
    }
    else {
LAB_000fd5ef:
      uVar2 = *(undefined4 *)(iVar1 + 0xd8);
    }
    CreateNailGrenNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3(&local_1c,&local_34,uVar2);
    iVar1 = (*DAT_00175628)(0,5);
    if (iVar1 == 0) {
      iVar1 = (*DAT_00175628)(0,1);
      if (iVar1 == 0) {
        iVar1 = (*DAT_00175628)(0,0xf);
        pcVar5 = "weapons/airgun_1.wav";
      }
      else {
        iVar1 = (*DAT_00175628)(0,0xf);
        pcVar5 = "weapons/spike2.wav";
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),1,pcVar5,0x3f800000,0x3f4ccccd,0,iVar1 + 0x5e);
    }
    iVar3 = iVar3 + 1;
    if (3 < iVar3) {
      *(float *)(*param_1 + 0x54) = local_c;
      param_1[0xb] = param_1[0xb] + 1;
      *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
      if (0x28 < param_1[0xb]) {
        param_1[3] = -0x10000;
        param_1[4] = (int)FinishedExplode__14CTFNailGrenade;
      }
      return;
    }
  } while( true );
}


