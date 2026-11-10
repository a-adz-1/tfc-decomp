// NailTouch__14CTFNailgunNailP11CBaseEntity  @ 001006c0
void NailTouch__14CTFNailgunNailP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x51);
  if (iVar3 == 0) {
    if ((*(int *)(*param_1 + 0x198) == 0) ||
       (iVar2 = *(int *)(*param_1 + 0x198), iVar3 = iVar2 + 0x80, iVar2 == 0)) {
      iVar3 = 0;
    }
  }
  else {
    piVar4 = (int *)__rf__7EHANDLE(param_1 + 0x51);
    iVar3 = *piVar4;
  }
  if (param_2 != (int *)0x0) {
    fVar1 = *(float *)(*param_2 + 0x16c);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      iVar3 = (**(code **)(param_2[0x111] + 0x38))
                        (param_2,*param_1,iVar3,*(undefined4 *)(*param_1 + 0x1e0),4);
      if (iVar3 != 0) {
        iVar3 = *param_1;
        uStack_c = *(undefined4 *)(iVar3 + 8);
        uStack_8 = *(undefined4 *)(iVar3 + 0xc);
        uStack_4 = *(undefined4 *)(iVar3 + 0x10);
        uVar5 = (**(code **)(param_2[0x111] + 0x44))(param_2,*(undefined4 *)(iVar3 + 0x1e0));
        SpawnBlood__FG6Vectorif(&uStack_c,uVar5);
      }
    }
  }
  if (*(int *)(*param_2 + 0xb4) != *(int *)(*param_1 + 0xb4)) {
    SUB_Remove__11CBaseEntity(param_1);
  }
  return;
}


