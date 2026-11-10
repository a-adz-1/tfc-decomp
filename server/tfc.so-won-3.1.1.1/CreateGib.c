// CreateGib__11CEnvShooter  @ 000a3da8
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
    uVar4 = (*DAT_0019f808)(0,*(int *)(*param_1 + 0x114) + -1);
  }
  *(undefined4 *)(*piVar3 + 0x114) = uVar4;
  piVar3[0x116] = -1;
  piVar3[0x118] = param_1[0x11a];
  *(undefined4 *)(*piVar3 + 0x148) = *(undefined4 *)(*param_1 + 0x148);
  *(undefined4 *)(*piVar3 + 0x14c) = *(undefined4 *)(*param_1 + 0x14c);
  iVar1 = *param_1;
  iVar2 = *piVar3;
  *(undefined4 *)(iVar2 + 0x150) = *(undefined4 *)(iVar1 + 0x150);
  *(undefined4 *)(iVar2 + 0x154) = *(undefined4 *)(iVar1 + 0x154);
  *(undefined4 *)(iVar2 + 0x158) = *(undefined4 *)(iVar1 + 0x158);
  *(undefined4 *)(*piVar3 + 0x15c) = *(undefined4 *)(*param_1 + 0x15c);
  *(undefined4 *)(*piVar3 + 0x144) = *(undefined4 *)(*param_1 + 0x144);
  *(undefined4 *)(*piVar3 + 0x110) = *(undefined4 *)(*param_1 + 0x110);
  return piVar3;
}


// CreateGib__11CGibShooter  @ 000a3f8c
int * CreateGib__11CGibShooter(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  longdouble lVar4;
  
  lVar4 = (longdouble)(*DAT_0019f784)("violence_hgibs");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar4) << 0xe) >> 8)) == 0x40) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)GetClassPtr__H1Z4CGib_PX01_PX01(0);
    Spawn__4CGibPCc(piVar1,"models/hgibs.mdl");
    piVar1[0x116] = 0xf7;
    iVar3 = *param_1;
    if (*(int *)(iVar3 + 0x114) < 2) {
      (*DAT_0019f794)(2,"GibShooter Body is <= 1!\n");
      iVar3 = *param_1;
    }
    uVar2 = (*DAT_0019f808)(1,*(int *)(iVar3 + 0x114) + -1);
    *(undefined4 *)(*piVar1 + 0x114) = uVar2;
  }
  return piVar1;
}


