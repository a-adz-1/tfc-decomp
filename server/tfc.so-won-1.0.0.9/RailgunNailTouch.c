// RailgunNailTouch__14CTFNailgunNailP11CBaseEntity  @ 001010c0
void RailgunNailTouch__14CTFNailgunNailP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 auStack_48 [20];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  fVar1 = *(float *)(*param_2 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    if ((*(int *)(*param_2 + 0xec) == 4) || (*(int *)(*param_2 + 0xe8) == 0xd)) {
      iVar2 = *param_1;
      uStack_34 = *(undefined4 *)(iVar2 + 8);
      uStack_30 = *(undefined4 *)(iVar2 + 0xc);
      uStack_2c = *(undefined4 *)(iVar2 + 0x10);
      uStack_18 = *(undefined4 *)(*param_2 + 0x1e8);
      uVar3 = (*DAT_00175628)(0,4);
      UTIL_GunshotDecalTrace__FP11TraceResulti(auStack_48,uVar3);
    }
    goto LAB_001011eb;
  }
  iVar2 = *(int *)(*param_1 + 0x178);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001755d4)(0);
    if (iVar2 != 0) goto LAB_00101107;
    puVar4 = (undefined4 *)0x0;
  }
  else {
LAB_00101107:
    puVar4 = *(undefined4 **)(iVar2 + 0xd8);
  }
  if (*(int *)(*param_1 + 0x170) == 0) {
    (*DAT_001755d4)(0);
  }
  iVar2 = (**(code **)(param_2[0xf2] + 0x34))(param_2,*param_1,*puVar4,0x41c80000,0x400);
  if (iVar2 != 0) {
    iVar2 = *param_1;
    uStack_10 = *(undefined4 *)(iVar2 + 8);
    uStack_c = *(undefined4 *)(iVar2 + 0xc);
    uStack_8 = *(undefined4 *)(iVar2 + 0x10);
    uVar3 = (**(code **)(param_2[0xf2] + 0x40))(param_2,*(undefined4 *)(iVar2 + 0x1c0));
    SpawnBlood__FG6Vectorif(&uStack_10,uVar3);
  }
LAB_001011eb:
  SUB_Remove__11CBaseEntity(param_1);
  return;
}


