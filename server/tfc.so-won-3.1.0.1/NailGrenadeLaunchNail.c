// NailGrenadeLaunchNail__14CTFNailGrenade  @ 000f0760
void NailGrenadeLaunchNail__14CTFNailGrenade(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  longdouble lVar3;
  longdouble lVar4;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined2 local_10;
  undefined2 uStack_e;
  float local_c;
  float local_8;
  float local_4;
  
  lVar3 = (longdouble)(*DAT_001a7fac)(0x41f00000,0x42200000);
  if (m_usNailGrenade_822 == 0) {
    m_usNailGrenade_822 = (*DAT_001a8028)(1,"events/explode/tf_nailgren.sc");
  }
  iVar2 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x198));
  iVar2 = iVar2 + -1;
  if ((iVar2 < 0) || ((int)gpGlobals[0x24] <= iVar2)) {
    iVar2 = 0;
  }
  _local_10 = CONCAT22(uStack_e,in_FPUControlWord);
  local_18 = (int)ROUND(*(float *)(*param_1 + 0x54) * 4.0);
  (*DAT_001a802c)(0,*(undefined4 *)(*param_1 + 0x208),m_usNailGrenade_822,0,&g_vecZero,&g_vecZero,
                  (float)lVar3,0,(short)iVar2 << 0xb | (ushort)local_18 & 0x7ff,0,0,0);
  iVar2 = 0;
  do {
    lVar4 = (longdouble)UTIL_AngleMod__Ff((float)lVar3 + *(float *)(*param_1 + 0x54));
    *(float *)(*param_1 + 0x54) = (float)lVar4;
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    iVar1 = *param_1;
    local_30 = *(float *)(iVar1 + 8) + gpGlobals[10] * 12.0;
    local_2c = *(float *)(iVar1 + 0xc) + gpGlobals[0xb] * 12.0;
    local_28 = *(float *)(iVar1 + 0x10) + gpGlobals[0xc] * 12.0;
    local_24 = *(undefined4 *)(iVar1 + 0x50);
    local_20 = *(undefined4 *)(iVar1 + 0x54);
    local_1c = *(undefined4 *)(iVar1 + 0x58);
    local_c = local_30;
    local_8 = local_2c;
    local_4 = local_28;
    CreateNailGrenNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3(&local_30,&local_24,param_1,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  *(int *)(*param_1 + 0x20c) = *(int *)(*param_1 + 0x20c) + 1;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  if (0x28 < *(int *)(*param_1 + 0x20c)) {
    param_1[3] = -0x10000;
    param_1[4] = (int)FinishedExplode__14CTFNailGrenade;
  }
  return;
}


