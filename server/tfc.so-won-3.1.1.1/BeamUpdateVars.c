// BeamUpdateVars__10CLightning  @ 000a11cc
void BeamUpdateVars__10CLightning(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  
  local_c = (*DAT_0019f6d8)(0,"targetname",param_1[0x117] + *(int *)(gpGlobals + 0x98));
  iVar2 = (*DAT_0019f6d8)(0,"targetname",param_1[0x118] + *(int *)(gpGlobals + 0x98));
  iVar3 = local_c;
  if ((local_c == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(undefined4 *)(iVar3 + 0x7c);
  }
  iVar4 = IsPointEntity__FP11CBaseEntity(uVar6);
  iVar3 = iVar2;
  if ((iVar2 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(undefined4 *)(iVar3 + 0x7c);
  }
  local_18 = IsPointEntity__FP11CBaseEntity(uVar6);
  *(undefined4 *)(*param_1 + 0x110) = 0;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  *(undefined4 *)(*param_1 + 0x148) = 0;
  local_14 = 2;
  *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 0x20;
  *(int *)(*param_1 + 0xb8) = param_1[0x120];
  *(int *)(*param_1 + 0xb4) = param_1[0x11f];
  local_10 = iVar2;
  if (iVar4 == 0) {
    if (local_18 != 0) {
      local_18 = 0;
      local_10 = local_c;
      local_c = iVar2;
      goto LAB_000a1311;
    }
  }
  else {
LAB_000a1311:
    local_14 = (uint)(local_18 == 0);
  }
  *(uint *)(*param_1 + 0x148) = *(uint *)(*param_1 + 0x148) & 0xf0 | local_14;
  if ((local_14 < 2) || (local_14 == 3)) {
    iVar3 = *param_1;
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(local_c + 0x88);
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(local_c + 0x8c);
    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(local_c + 0x90);
    if ((local_14 == 0) || (local_14 == 3)) {
      iVar3 = *param_1;
      *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(local_10 + 0x88);
      *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(local_10 + 0x8c);
      *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(local_10 + 0x90);
      goto LAB_000a145c;
    }
  }
  else {
    uVar5 = (*DAT_0019f7bc)(local_c);
    *(uint *)(*param_1 + 0x128) = (*(uint *)(*param_1 + 0x128) & 0xf000) << 0xc | uVar5 & 0xfff;
    uVar6 = (*DAT_0019f7c0)(uVar5);
    *(undefined4 *)(*param_1 + 0x198) = uVar6;
  }
  uVar5 = (*DAT_0019f7bc)(local_10);
  *(uint *)(*param_1 + 0x110) = (*(uint *)(*param_1 + 0x110) & 0xf000) << 0xc | uVar5 & 0xfff;
  uVar6 = (*DAT_0019f7c0)(uVar5);
  *(undefined4 *)(*param_1 + 0x194) = uVar6;
LAB_000a145c:
  RelinkBeam__5CBeam(param_1);
  *(float *)(*param_1 + 0x144) = (float)param_1[0x11a];
  *(int *)(*param_1 + 0x114) = param_1[0x11b];
  *(float *)(*param_1 + 0x130) = (float)param_1[0x121];
  *(float *)(*param_1 + 0x134) = (float)param_1[0x11d];
  iVar3 = *param_1;
  if (*(char *)(iVar3 + 0x1a0) < '\0') {
    bVar1 = (byte)*(undefined4 *)(iVar3 + 0x148) & 0xf | 0x40;
  }
  else {
    if ((*(byte *)(iVar3 + 0x1a1) & 1) == 0) {
      return;
    }
    bVar1 = (byte)*(undefined4 *)(iVar3 + 0x148) & 0xf | 0x80;
  }
  *(uint *)(iVar3 + 0x148) = (uint)bVar1;
  return;
}


