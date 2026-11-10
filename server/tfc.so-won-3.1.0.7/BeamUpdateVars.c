// BeamUpdateVars__10CLightning  @ 000a23c4
void BeamUpdateVars__10CLightning(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_10;
  uint local_c;
  int local_8;
  
  local_8 = (*DAT_001c1058)(0,"targetname",param_1[0x113] + *(int *)(gpGlobals + 0x98));
  iVar2 = (*DAT_001c1058)(0,"targetname",param_1[0x114] + *(int *)(gpGlobals + 0x98));
  iVar3 = local_8;
  if ((local_8 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(iVar3 + 0x7c);
  }
  iVar4 = IsPointEntity__FP11CBaseEntity(uVar5);
  iVar3 = iVar2;
  if ((iVar2 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(iVar3 + 0x7c);
  }
  local_10 = IsPointEntity__FP11CBaseEntity(uVar5);
  *(undefined4 *)(*param_1 + 0x110) = 0;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  *(undefined4 *)(*param_1 + 0x148) = 0;
  *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 0x20;
  *(int *)(*param_1 + 0xb8) = param_1[0x11c];
  *(int *)(*param_1 + 0xb4) = param_1[0x11b];
  local_c = 2;
  iVar3 = iVar2;
  if (iVar4 == 0) {
    if (local_10 != 0) {
      local_10 = 0;
      iVar3 = local_8;
      local_8 = iVar2;
      goto LAB_000a250c;
    }
  }
  else {
LAB_000a250c:
    local_c = (uint)(local_10 == 0);
  }
  *(uint *)(*param_1 + 0x148) = *(uint *)(*param_1 + 0x148) & 0xf0 | local_c;
  if ((local_c < 2) || (local_c == 3)) {
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(local_8 + 0x88);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(local_8 + 0x8c);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(local_8 + 0x90);
    if ((local_c == 0) || (local_c == 3)) {
      iVar2 = *param_1;
      *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(iVar3 + 0x88);
      *(undefined4 *)(iVar2 + 0x54) = *(undefined4 *)(iVar3 + 0x8c);
      *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(iVar3 + 0x90);
      goto LAB_000a25d8;
    }
  }
  else {
    uVar5 = (*DAT_001c113c)(local_8);
    SetStartEntity__5CBeami(param_1,uVar5);
  }
  uVar5 = (*DAT_001c113c)(iVar3);
  SetEndEntity__5CBeami(param_1,uVar5);
LAB_000a25d8:
  RelinkBeam__5CBeam(param_1);
  *(float *)(*param_1 + 0x144) = (float)param_1[0x116];
  *(int *)(*param_1 + 0x114) = param_1[0x117];
  *(float *)(*param_1 + 0x130) = (float)param_1[0x11d];
  *(float *)(*param_1 + 0x134) = (float)param_1[0x119];
  iVar3 = *param_1;
  if (*(char *)(iVar3 + 0x1a0) < '\0') {
    bVar1 = (byte)*(undefined4 *)(iVar3 + 0x148) & 0xf | 0x40;
  }
  else {
    iVar3 = *param_1;
    if ((*(byte *)(iVar3 + 0x1a1) & 1) == 0) {
      return;
    }
    bVar1 = (byte)*(undefined4 *)(iVar3 + 0x148) & 0xf | 0x80;
  }
  *(uint *)(iVar3 + 0x148) = (uint)bVar1;
  return;
}


