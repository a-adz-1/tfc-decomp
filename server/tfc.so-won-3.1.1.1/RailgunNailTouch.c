// RailgunNailTouch__14CTFNailgunNailP11CBaseEntity  @ 00103054
void RailgunNailTouch__14CTFNailgunNailP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  fVar1 = *(float *)(*param_2 + 0x16c);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) goto LAB_00103149;
  iVar2 = *(int *)(*param_1 + 0x198);
  if (iVar2 == 0) {
    iVar2 = (*DAT_0019f7b4)(0);
    if (iVar2 != 0) goto LAB_001030ae;
    puVar4 = (undefined4 *)0x0;
  }
  else {
LAB_001030ae:
    puVar4 = *(undefined4 **)(iVar2 + 0x7c);
  }
  if (*(int *)(*param_1 + 400) == 0) {
    (*DAT_0019f7b4)(0);
  }
  iVar2 = (**(code **)(param_2[0x115] + 0x38))(param_2,*param_1,*puVar4,0x41c80000,0x400);
  if (iVar2 != 0) {
    iVar2 = *param_1;
    uStack_10 = *(undefined4 *)(iVar2 + 8);
    uStack_c = *(undefined4 *)(iVar2 + 0xc);
    uStack_8 = *(undefined4 *)(iVar2 + 0x10);
    uVar3 = (**(code **)(param_2[0x115] + 0x44))(param_2,*(undefined4 *)(iVar2 + 0x1e0));
    SpawnBlood__FG6Vectorif(&uStack_10,uVar3);
  }
LAB_00103149:
  SUB_Remove__11CBaseEntity(param_1);
  return;
}


