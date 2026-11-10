// CreateGib__11CEnvShooter  @ 00099c00
int * CreateGib__11CEnvShooter(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  piVar3 = (int *)GetClassPtr__H1Z4CGib_PX01_PX01(0);
  Spawn__4CGibPCc(piVar3,*(int *)(*param_1 + 0xb8) + *(int *)(gpGlobals + 0x98));
  uVar4 = 0;
  if (1 < *(int *)(*param_1 + 0x114)) {
    uVar4 = (*DAT_001a7fa8)(0,*(int *)(*param_1 + 0x114) + -1);
  }
  *(undefined4 *)(*piVar3 + 0x114) = uVar4;
  piVar3[0xf6] = -1;
  piVar3[0xf8] = param_1[0xfa];
  *(undefined4 *)(*piVar3 + 0x148) = *(undefined4 *)(*param_1 + 0x148);
  *(undefined4 *)(*piVar3 + 0x14c) = *(undefined4 *)(*param_1 + 0x14c);
  iVar1 = *piVar3;
  iVar2 = *param_1;
  *(undefined4 *)(iVar1 + 0x150) = *(undefined4 *)(iVar2 + 0x150);
  *(undefined4 *)(iVar1 + 0x154) = *(undefined4 *)(iVar2 + 0x154);
  *(undefined4 *)(iVar1 + 0x158) = *(undefined4 *)(iVar2 + 0x158);
  *(undefined4 *)(*piVar3 + 0x15c) = *(undefined4 *)(*param_1 + 0x15c);
  *(undefined4 *)(*piVar3 + 0x144) = *(undefined4 *)(*param_1 + 0x144);
  *(undefined4 *)(*piVar3 + 0x110) = *(undefined4 *)(*param_1 + 0x110);
  return piVar3;
}


// CreateGib__11CGibShooter  @ 00099524
int * CreateGib__11CGibShooter(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  lVar3 = (longdouble)(*DAT_001a7f24)("violence_hgibs");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0.0) || NAN(lVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0.0 == lVar3) << 0xe) >> 8)) == 0x40) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)GetClassPtr__H1Z4CGib_PX01_PX01(0);
    Spawn__4CGibPCc(piVar1,"models/hgibs.mdl");
    piVar1[0xf6] = 0xf7;
    if (*(int *)(*param_1 + 0x114) < 2) {
      (*DAT_001a7f34)(2,"GibShooter Body is <= 1!\n");
    }
    uVar2 = (*DAT_001a7fa8)(1,*(int *)(*param_1 + 0x114) + -1);
    *(undefined4 *)(*piVar1 + 0x114) = uVar2;
  }
  return piVar1;
}


