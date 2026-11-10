// RampThink__15CAmbientGeneric  @ 000ed7d8
void RampThink__15CAmbientGeneric(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  int local_18;
  uint local_c;
  
  iVar1 = *(int *)(*param_1 + 0x1d4) + (int)gpGlobals[0x26];
  iVar7 = param_1[0x122];
  iVar5 = param_1[0x126];
  local_c = 0;
  bVar9 = false;
  if (param_1[0x116] == 0) {
    if ((((param_1[0x117] == 0) && (param_1[0x11a] == 0)) && (param_1[0x11b] == 0)) &&
       (param_1[0x11c] == 0)) {
      return;
    }
    if ((param_1[0x116] != 0) || (param_1[0x117] != 0)) goto LAB_000ed86c;
  }
  else {
LAB_000ed86c:
    iVar6 = param_1[0x125];
    if (param_1[0x116] < 1) {
      if (0 < param_1[0x117]) {
        param_1[0x125] = param_1[0x125] - param_1[0x117];
      }
    }
    else {
      param_1[0x125] = param_1[0x125] + param_1[0x116];
    }
    iVar7 = param_1[0x125] >> 8;
    if (param_1[0x114] < iVar7) {
      iVar7 = param_1[0x114];
      param_1[0x116] = 0;
    }
    if (iVar7 < param_1[0x115]) {
      param_1[0x117] = 0;
      goto LAB_000ed990;
    }
    if (0xff < iVar7) {
      iVar7 = 0xff;
    }
    if (iVar7 < 1) {
      iVar7 = 1;
    }
    param_1[0x122] = iVar7;
    bVar9 = iVar6 >> 8 != iVar7;
    local_c = 0x80;
  }
  if ((param_1[0x11a] != 0) || (param_1[0x11b] != 0)) {
    iVar6 = param_1[0x129];
    if (param_1[0x11a] < 1) {
      if (0 < param_1[0x11b]) {
        param_1[0x129] = param_1[0x129] - param_1[0x11b];
      }
    }
    else {
      param_1[0x129] = param_1[0x129] + param_1[0x11a];
    }
    iVar5 = param_1[0x129] >> 8;
    if (param_1[0x118] < iVar5) {
      iVar5 = param_1[0x118];
      param_1[0x11a] = 0;
    }
    if (iVar5 < param_1[0x119]) {
      param_1[0x11b] = 0;
LAB_000ed990:
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
                (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,iVar1,0,0,0x20,0);
      return;
    }
    if (100 < iVar5) {
      iVar5 = 100;
    }
    if (iVar5 < 1) {
      iVar5 = 1;
    }
    param_1[0x126] = iVar5;
    if (iVar6 >> 8 != iVar5) {
      bVar9 = true;
    }
    local_c = local_c | 0x40;
  }
  iVar6 = iVar5;
  iVar8 = iVar7;
  if (param_1[0x11c] == 0) goto LAB_000edbaa;
  if (0x6fffffff < param_1[0x12a]) {
    param_1[0x12a] = 0;
  }
  iVar4 = param_1[0x11d];
  iVar2 = iVar4 + param_1[0x12a];
  param_1[0x12a] = iVar2;
  iVar3 = iVar2 >> 8;
  if (iVar2 < 0) {
    param_1[0x12a] = 0;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    param_1[0x11d] = iVar4;
    iVar3 = 0;
  }
  else if (0xff < iVar3) {
    iVar3 = 0xff;
    param_1[0x12a] = 0xff00;
    local_18 = param_1[0x11d];
    if (local_18 < 0) {
      local_18 = -local_18;
    }
    param_1[0x11d] = -local_18;
  }
  iVar4 = param_1[0x11c];
  if (iVar4 == 2) {
LAB_000edaf8:
    param_1[299] = iVar3;
  }
  else if (iVar4 < 3) {
    if (iVar4 != 1) goto LAB_000edaf8;
    if (iVar3 < 0x80) {
      param_1[299] = 0xff;
    }
    else {
      param_1[299] = 0;
    }
  }
  else {
    if (iVar4 != 3) goto LAB_000edaf8;
    if (iVar3 == 0xff) {
      iVar4 = (*DAT_001c1188)(0,0xff);
      param_1[299] = iVar4;
    }
  }
  if (param_1[0x11e] != 0) {
    iVar8 = iVar7 + ((param_1[299] + -0x80) * param_1[0x11e]) / 100;
    if (0xff < iVar8) {
      iVar8 = 0xff;
    }
    if (iVar8 < 1) {
      iVar8 = 1;
    }
    if (iVar7 != iVar8) {
      bVar9 = true;
    }
    local_c = local_c | 0x80;
  }
  if (param_1[0x11f] != 0) {
    iVar6 = iVar5 + ((param_1[299] + -0x80) * param_1[0x11f]) / 100;
    if (100 < iVar6) {
      iVar6 = 100;
    }
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if (iVar5 != iVar6) {
      bVar9 = true;
    }
    local_c = local_c | 0x40;
  }
LAB_000edbaa:
  if ((local_c != 0) && (bVar9)) {
    if (iVar8 == 100) {
      iVar8 = 0x65;
    }
    UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
              (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,iVar1,(float)iVar6 * 0.01,
               param_1[0x112],local_c,iVar8);
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
  return;
}


