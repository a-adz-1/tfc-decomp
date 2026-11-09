// CreateGib__11CEnvShooter  @ 000aed70
int * CreateGib__11CEnvShooter(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  piVar3 = (int *)GetClassPtr__H1Z4CGib_PX01_PX01(0);
  Spawn__4CGibPCc(piVar3,*(int *)(*param_1 + 0x98) + *(int *)(gpGlobals + 0x98));
  uVar4 = 0;
  if (1 < *(int *)(*param_1 + 0xf4)) {
    uVar4 = (*DAT_00175628)(0,*(int *)(*param_1 + 0xf4) + -1);
  }
  *(undefined4 *)(*piVar3 + 0xf4) = uVar4;
  piVar3[0xf3] = -1;
  piVar3[0xf5] = param_1[0xf7];
  *(undefined4 *)(*piVar3 + 0x128) = *(undefined4 *)(*param_1 + 0x128);
  *(undefined4 *)(*piVar3 + 300) = *(undefined4 *)(*param_1 + 300);
  iVar1 = *piVar3;
  iVar2 = *param_1;
  *(undefined4 *)(iVar1 + 0x130) = *(undefined4 *)(iVar2 + 0x130);
  *(undefined4 *)(iVar1 + 0x134) = *(undefined4 *)(iVar2 + 0x134);
  *(undefined4 *)(iVar1 + 0x138) = *(undefined4 *)(iVar2 + 0x138);
  *(undefined4 *)(*piVar3 + 0x13c) = *(undefined4 *)(*param_1 + 0x13c);
  *(undefined4 *)(*piVar3 + 0x124) = *(undefined4 *)(*param_1 + 0x124);
  *(undefined4 *)(*piVar3 + 0xf0) = *(undefined4 *)(*param_1 + 0xf0);
  return piVar3;
}


// CreateGib__11CGibShooter  @ 000ae7d0
int * CreateGib__11CGibShooter(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  lVar3 = (longdouble)(*DAT_001755a4)("violence_hgibs");
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar3) << 0xe) >> 8)) == 0x40) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)GetClassPtr__H1Z4CGib_PX01_PX01(0);
    Spawn__4CGibPCc(piVar1,"models/hgibs.mdl");
    piVar1[0xf3] = 0xf7;
    if (*(int *)(*param_1 + 0xf4) < 2) {
      (*DAT_001755b4)(2,"GibShooter Body is <= 1!\n");
    }
    uVar2 = (*DAT_00175628)(1,*(int *)(*param_1 + 0xf4) + -1);
    *(undefined4 *)(*piVar1 + 0xf4) = uVar2;
  }
  return piVar1;
}


