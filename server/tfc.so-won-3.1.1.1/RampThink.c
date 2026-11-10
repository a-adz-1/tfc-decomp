// RampThink__15CAmbientGeneric  @ 000ef4d0
void RampThink__15CAmbientGeneric(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  int local_20;
  uint local_14;
  int local_10;
  
  local_14 = 0;
  bVar8 = false;
  iVar2 = *(int *)(*param_1 + 0x1d4) + (int)gpGlobals[0x26];
  iVar7 = param_1[0x126];
  local_10 = param_1[0x12a];
  iVar1 = param_1[0x11a];
  if (iVar1 == 0) {
    if ((((param_1[0x11b] == 0) && (param_1[0x11e] == 0)) && (param_1[0x11f] == 0)) &&
       (param_1[0x120] == 0)) {
      return;
    }
    if (param_1[0x11b] != 0) goto LAB_000ef564;
  }
  else {
LAB_000ef564:
    iVar3 = param_1[0x129];
    iVar4 = iVar3 >> 8;
    if (iVar1 < 1) {
      if (0 < param_1[0x11b]) {
        iVar1 = -param_1[0x11b];
        goto LAB_000ef58a;
      }
    }
    else {
LAB_000ef58a:
      iVar3 = iVar1 + iVar3;
      param_1[0x129] = iVar3;
    }
    iVar7 = iVar3 >> 8;
    if (param_1[0x118] < iVar3 >> 8) {
      param_1[0x11a] = 0;
      iVar7 = param_1[0x118];
    }
    if (iVar7 < param_1[0x119]) {
      param_1[0x11b] = 0;
      goto LAB_000ef669;
    }
    if (0xff < iVar7) {
      iVar7 = 0xff;
    }
    if (iVar7 < 1) {
      iVar7 = 1;
    }
    param_1[0x126] = iVar7;
    bVar8 = iVar4 != iVar7;
    local_14 = 0x80;
  }
  iVar1 = param_1[0x11e];
  if ((iVar1 != 0) || (param_1[0x11f] != 0)) {
    local_20 = param_1[0x12d];
    iVar3 = local_20 >> 8;
    if (iVar1 < 1) {
      if (0 < param_1[0x11f]) {
        iVar1 = -param_1[0x11f];
        goto LAB_000ef62b;
      }
    }
    else {
LAB_000ef62b:
      local_20 = local_20 + iVar1;
      param_1[0x12d] = local_20;
    }
    local_10 = local_20 >> 8;
    if (param_1[0x11c] < local_20 >> 8) {
      param_1[0x11e] = 0;
      local_10 = param_1[0x11c];
    }
    if (local_10 < param_1[0x11d]) {
      param_1[0x11f] = 0;
LAB_000ef669:
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
                (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,iVar2,0,0,0x20,0);
      return;
    }
    if (100 < local_10) {
      local_10 = 100;
    }
    if (local_10 < 1) {
      local_10 = 1;
    }
    param_1[0x12a] = local_10;
    if (iVar3 != local_10) {
      bVar8 = true;
    }
    local_14 = local_14 | 0x40;
  }
  iVar1 = local_10;
  iVar3 = iVar7;
  if (param_1[0x120] == 0) goto LAB_000ef85b;
  iVar4 = param_1[0x12e];
  if (0x6fffffff < iVar4) {
    param_1[0x12e] = 0;
    iVar4 = 0;
  }
  iVar6 = param_1[0x121];
  iVar4 = iVar6 + iVar4;
  param_1[0x12e] = iVar4;
  iVar5 = iVar4 >> 8;
  if (iVar4 < 0) {
    param_1[0x12e] = 0;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    param_1[0x121] = iVar6;
    iVar5 = 0;
  }
  else if (0xff < iVar5) {
    iVar5 = 0xff;
    param_1[0x12e] = 0xff00;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    param_1[0x121] = -iVar6;
  }
  iVar4 = param_1[0x120];
  if (iVar4 == 2) {
LAB_000ef7a8:
    param_1[0x12f] = iVar5;
  }
  else if (iVar4 < 3) {
    if (iVar4 != 1) goto LAB_000ef7a8;
    if (iVar5 < 0x80) {
      param_1[0x12f] = 0xff;
    }
    else {
      param_1[0x12f] = 0;
    }
  }
  else {
    if (iVar4 != 3) goto LAB_000ef7a8;
    if (iVar5 == 0xff) {
      iVar4 = (*DAT_0019f808)(0,0xff);
      param_1[0x12f] = iVar4;
    }
  }
  if (param_1[0x122] != 0) {
    iVar3 = iVar7 + (param_1[0x122] * (param_1[0x12f] + -0x80)) / 100;
    if (0xff < iVar3) {
      iVar3 = 0xff;
    }
    if (iVar3 < 1) {
      iVar3 = 1;
    }
    if (iVar7 != iVar3) {
      bVar8 = true;
    }
    local_14 = local_14 | 0x80;
  }
  if (param_1[0x123] != 0) {
    local_10 = local_10 + (param_1[0x123] * (param_1[0x12f] + -0x80)) / 100;
    if (100 < local_10) {
      local_10 = 100;
    }
    if (local_10 < 0) {
      local_10 = 0;
    }
    if (iVar1 != local_10) {
      bVar8 = true;
    }
    local_14 = local_14 | 0x40;
  }
LAB_000ef85b:
  if ((local_14 != 0) && (bVar8)) {
    if (iVar3 == 100) {
      iVar3 = 0x65;
    }
    UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
              (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,iVar2,(float)local_10 * 0.01,
               param_1[0x116],local_14,iVar3);
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
  return;
}


