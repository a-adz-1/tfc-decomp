// NailTouch__14CTFNailgunNailP11CBaseEntity  @ 00100260
void NailTouch__14CTFNailgunNailP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined1 auStack_48 [20];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_18;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x51);
  if (iVar2 == 0) {
    if ((*(int *)(*param_1 + 0x178) == 0) || (iVar2 = *(int *)(*param_1 + 0x178), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 + 0xdc;
    }
  }
  else {
    piVar3 = (int *)__rf__7EHANDLE(param_1 + 0x51);
    iVar2 = *piVar3;
  }
  if ((param_2 != (int *)0x0) &&
     (fVar1 = *(float *)(*param_2 + 0x14c),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    iVar2 = (**(code **)(param_2[0xf2] + 0x34))
                      (param_2,*param_1,iVar2,*(undefined4 *)(*param_1 + 0x1c0),4);
    if (iVar2 != 0) {
      iVar2 = *param_1;
      uStack_10 = *(undefined4 *)(iVar2 + 8);
      uStack_c = *(undefined4 *)(iVar2 + 0xc);
      uStack_8 = *(undefined4 *)(iVar2 + 0x10);
      uVar4 = (**(code **)(param_2[0xf2] + 0x40))(param_2,*(undefined4 *)(iVar2 + 0x1c0));
      SpawnBlood__FG6Vectorif(&uStack_10,uVar4);
    }
  }
  iVar2 = *param_2;
  if (*(int *)(iVar2 + 0x94) != *(int *)(*param_1 + 0x94)) {
    if ((*(int *)(iVar2 + 0xec) == 4) || (*(int *)(iVar2 + 0xe8) == 0xd)) {
      iVar2 = *param_1;
      uStack_34 = *(undefined4 *)(iVar2 + 8);
      uStack_30 = *(undefined4 *)(iVar2 + 0xc);
      uStack_2c = *(undefined4 *)(iVar2 + 0x10);
      uStack_18 = *(undefined4 *)(*param_2 + 0x1e8);
      uVar4 = (*DAT_00175628)(0,4);
      UTIL_GunshotDecalTrace__FP11TraceResulti(auStack_48,uVar4);
    }
    SUB_Remove__11CBaseEntity(param_1);
  }
  return;
}


