// NailTouch__14CTFNailgunNailP11CBaseEntity  @ 00102f48
void NailTouch__14CTFNailgunNailP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x51);
  if (iVar2 == 0) {
    iVar2 = 0;
    if (*(int *)(*param_1 + 0x198) != 0) {
      iVar2 = *(int *)(*param_1 + 0x198) + 0x80;
    }
  }
  else {
    piVar3 = (int *)__rf__7EHANDLE(param_1 + 0x51);
    iVar2 = *piVar3;
  }
  if ((param_2 != (int *)0x0) &&
     (fVar1 = *(float *)(*param_2 + 0x16c),
     (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    iVar2 = (**(code **)(param_2[0x115] + 0x38))
                      (param_2,*param_1,iVar2,*(undefined4 *)(*param_1 + 0x1e0),4);
    if (iVar2 != 0) {
      iVar2 = *param_1;
      local_10 = *(undefined4 *)(iVar2 + 8);
      local_c = *(undefined4 *)(iVar2 + 0xc);
      local_8 = *(undefined4 *)(iVar2 + 0x10);
      uVar4 = (**(code **)(param_2[0x115] + 0x44))(param_2,*(undefined4 *)(iVar2 + 0x1e0));
      SpawnBlood__FG6Vectorif(&local_10,uVar4);
    }
  }
  if (*(int *)(*param_2 + 0xb4) != *(int *)(*param_1 + 0xb4)) {
    SUB_Remove__11CBaseEntity(param_1);
  }
  return;
}


