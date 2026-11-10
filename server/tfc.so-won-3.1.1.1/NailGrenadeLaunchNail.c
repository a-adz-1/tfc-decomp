// NailGrenadeLaunchNail__14CTFNailGrenade  @ 000ff7dc
void NailGrenadeLaunchNail__14CTFNailGrenade(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  longdouble lVar3;
  longdouble lVar4;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int local_1c;
  undefined2 local_14;
  undefined2 uStack_12;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  lVar3 = (longdouble)(*DAT_0019f80c)(0x41f00000,0x42200000);
  if (m_usNailGrenade_826 == 0) {
    m_usNailGrenade_826 = (*DAT_0019f888)(1,"events/explode/tf_nailgren.sc");
  }
  iVar2 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x198));
  iVar2 = iVar2 + -1;
  if ((iVar2 < 0) || ((int)gpGlobals[0x24] <= iVar2)) {
    iVar2 = 0;
  }
  _local_14 = CONCAT22(uStack_12,in_FPUControlWord);
  local_1c = (int)ROUND(*(float *)(*param_1 + 0x54) * 4.0);
  (*DAT_0019f88c)(0,*(undefined4 *)(*param_1 + 0x208),m_usNailGrenade_826,0,&g_vecZero,&g_vecZero,
                  (float)lVar3,0,(short)iVar2 << 0xb | (ushort)local_1c & 0x7ff,0,0,0);
  iVar2 = 0;
  do {
    lVar4 = (longdouble)UTIL_AngleMod__Ff((float)lVar3 + *(float *)(*param_1 + 0x54));
    *(float *)(*param_1 + 0x54) = (float)lVar4;
    UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
    iVar1 = *param_1;
    fStack_34 = gpGlobals[10] * 12.0 + *(float *)(iVar1 + 8);
    fStack_30 = gpGlobals[0xb] * 12.0 + *(float *)(iVar1 + 0xc);
    fStack_2c = gpGlobals[0xc] * 12.0 + *(float *)(iVar1 + 0x10);
    uStack_28 = *(undefined4 *)(iVar1 + 0x50);
    uStack_24 = *(undefined4 *)(iVar1 + 0x54);
    uStack_20 = *(undefined4 *)(iVar1 + 0x58);
    fStack_10 = fStack_34;
    fStack_c = fStack_30;
    fStack_8 = fStack_2c;
    CreateNailGrenNail__14CTFNailgunNailG6VectorT1P11CBaseEntityT3(&fStack_34,&uStack_28,param_1,0);
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


