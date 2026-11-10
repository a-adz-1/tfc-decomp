// RailgunNailTouch__14CTFNailgunNailP11CBaseEntity  @ 000f3088
void RailgunNailTouch__14CTFNailgunNailP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar1 = *(float *)(*param_2 + 0x16c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) goto LAB_000f3177;
  iVar2 = *(int *)(*param_1 + 0x198);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001a7f54)(0);
    if (iVar2 != 0) goto LAB_000f30e7;
    puVar4 = (undefined4 *)0x0;
  }
  else {
LAB_000f30e7:
    puVar4 = *(undefined4 **)(iVar2 + 0x7c);
  }
  if (*(int *)(*param_1 + 400) == 0) {
    (*DAT_001a7f54)(0);
  }
  iVar2 = (**(code **)(param_2[0xf5] + 0x34))(param_2,*param_1,*puVar4,0x41c80000,0x400);
  if (iVar2 != 0) {
    iVar2 = *param_1;
    local_c = *(undefined4 *)(iVar2 + 8);
    local_8 = *(undefined4 *)(iVar2 + 0xc);
    local_4 = *(undefined4 *)(iVar2 + 0x10);
    uVar3 = (**(code **)(param_2[0xf5] + 0x40))(param_2,*(undefined4 *)(iVar2 + 0x1e0));
    SpawnBlood__FG6Vectorif(&local_c,uVar3);
  }
LAB_000f3177:
  SUB_Remove__11CBaseEntity(param_1);
  return;
}


