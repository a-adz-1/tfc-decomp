// BeamUpdateVars__10CLightning  @ 000ad340
void BeamUpdateVars__10CLightning(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uStack_10;
  int local_c;
  
  local_c = (*DAT_001754f8)(0,"targetname",param_1[0xf4] + *(int *)(gpGlobals + 0x98));
  iVar2 = (*DAT_001754f8)(0,"targetname",param_1[0xf5] + *(int *)(gpGlobals + 0x98));
  iVar3 = local_c;
  if ((local_c == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(undefined4 *)(iVar3 + 0xd8);
  }
  iVar4 = IsPointEntity__FP11CBaseEntity(uVar6);
  iVar3 = iVar2;
  if ((iVar2 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(undefined4 *)(iVar3 + 0xd8);
  }
  iVar5 = IsPointEntity__FP11CBaseEntity(uVar6);
  *(undefined4 *)(*param_1 + 0xf0) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  *(byte *)(*param_1 + 0x187) = *(byte *)(*param_1 + 0x187) | 0x20;
  *(int *)(*param_1 + 0x98) = param_1[0xfd];
  *(int *)(*param_1 + 0x94) = param_1[0xfc];
  uStack_10 = 2;
  iVar3 = iVar2;
  if (iVar4 == 0) {
    if (iVar5 != 0) {
      iVar5 = 0;
      iVar3 = local_c;
      local_c = iVar2;
      goto LAB_000ad461;
    }
  }
  else {
LAB_000ad461:
    uStack_10 = (uint)(iVar5 == 0);
  }
  *(uint *)(*param_1 + 0x128) = *(uint *)(*param_1 + 0x128) & 0xf0 | uStack_10;
  if ((uStack_10 < 2) || (uStack_10 == 3)) {
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(local_c + 0xe4);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(local_c + 0xe8);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(local_c + 0xec);
    if ((uStack_10 == 0) || (uStack_10 == 3)) {
      iVar2 = *param_1;
      *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(iVar3 + 0xe4);
      *(undefined4 *)(iVar2 + 0x54) = *(undefined4 *)(iVar3 + 0xe8);
      *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(iVar3 + 0xec);
      goto LAB_000ad50d;
    }
  }
  else {
    uVar6 = (*DAT_001755dc)(local_c);
    SetStartEntity__5CBeami(param_1,uVar6);
  }
  uVar6 = (*DAT_001755dc)(iVar3);
  SetEndEntity__5CBeami(param_1,uVar6);
LAB_000ad50d:
  RelinkBeam__5CBeam(param_1);
  *(float *)(*param_1 + 0x124) = (float)param_1[0xf7];
  *(int *)(*param_1 + 0xf4) = param_1[0xf8];
  *(float *)(*param_1 + 0x110) = (float)param_1[0xfe];
  *(float *)(*param_1 + 0x114) = (float)param_1[0xfa];
  iVar3 = *param_1;
  if (*(char *)(iVar3 + 0x180) < '\0') {
    bVar1 = (byte)*(undefined4 *)(iVar3 + 0x128) & 0xf | 0x40;
  }
  else {
    iVar3 = *param_1;
    if ((*(byte *)(iVar3 + 0x181) & 1) == 0) {
      return;
    }
    bVar1 = (byte)*(undefined4 *)(iVar3 + 0x128) & 0xf | 0x80;
  }
  *(uint *)(iVar3 + 0x128) = (uint)bVar1;
  return;
}


