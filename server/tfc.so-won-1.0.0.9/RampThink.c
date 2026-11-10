// RampThink__15CAmbientGeneric  @ 000eb310
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
  int local_44;
  uint local_14;
  
  iVar1 = *(int *)(*param_1 + 0x1b4) + (int)gpGlobals[0x26];
  iVar4 = param_1[0x103];
  iVar6 = param_1[0x107];
  local_14 = 0;
  bVar8 = false;
  if (param_1[0xf7] == 0) {
    if ((((param_1[0xf8] == 0) && (param_1[0xfb] == 0)) && (param_1[0xfc] == 0)) &&
       (param_1[0xfd] == 0)) {
      return;
    }
    if ((param_1[0xf7] != 0) || (param_1[0xf8] != 0)) goto LAB_000eb394;
  }
  else {
LAB_000eb394:
    iVar5 = param_1[0x106];
    if (param_1[0xf7] < 1) {
      if (0 < param_1[0xf8]) {
        param_1[0x106] = param_1[0x106] - param_1[0xf8];
      }
    }
    else {
      param_1[0x106] = param_1[0x106] + param_1[0xf7];
    }
    iVar4 = param_1[0x106] >> 8;
    if (param_1[0xf5] < iVar4) {
      iVar4 = param_1[0xf5];
      param_1[0xf7] = 0;
    }
    if (iVar4 < param_1[0xf6]) {
      param_1[0xf8] = 0;
      goto LAB_000eb4b8;
    }
    if (0xff < iVar4) {
      iVar4 = 0xff;
    }
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    param_1[0x103] = iVar4;
    bVar8 = iVar5 >> 8 != iVar4;
    local_14 = 0x80;
  }
  if ((param_1[0xfb] != 0) || (param_1[0xfc] != 0)) {
    iVar5 = param_1[0x10a];
    if (param_1[0xfb] < 1) {
      if (0 < param_1[0xfc]) {
        param_1[0x10a] = param_1[0x10a] - param_1[0xfc];
      }
    }
    else {
      param_1[0x10a] = param_1[0x10a] + param_1[0xfb];
    }
    iVar6 = param_1[0x10a] >> 8;
    if (param_1[0xf9] < iVar6) {
      iVar6 = param_1[0xf9];
      param_1[0xfb] = 0;
    }
    if (iVar6 < param_1[0xfa]) {
      param_1[0xfc] = 0;
LAB_000eb4b8:
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),*param_1 + 8,iVar1,0,0,0x20,0);
      return;
    }
    if (100 < iVar6) {
      iVar6 = 100;
    }
    if (iVar6 < 1) {
      iVar6 = 1;
    }
    param_1[0x107] = iVar6;
    if (iVar5 >> 8 != iVar6) {
      bVar8 = true;
    }
    local_14 = local_14 | 0x40;
  }
  iVar5 = iVar4;
  iVar7 = iVar6;
  if (param_1[0xfd] == 0) goto LAB_000eb6f1;
  if (0x6fffffff < param_1[0x10b]) {
    param_1[0x10b] = 0;
  }
  iVar3 = param_1[0xfe];
  iVar2 = param_1[0x10b] + iVar3;
  param_1[0x10b] = iVar2;
  local_44 = iVar2 >> 8;
  if (iVar2 < 0) {
    param_1[0x10b] = 0;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    param_1[0xfe] = iVar3;
    local_44 = 0;
  }
  else if (0xff < local_44) {
    local_44 = 0xff;
    param_1[0x10b] = 0xff00;
    iVar3 = param_1[0xfe];
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    param_1[0xfe] = -iVar3;
  }
  iVar3 = param_1[0xfd];
  if (iVar3 == 2) {
LAB_000eb640:
    param_1[0x10c] = local_44;
  }
  else if (iVar3 < 3) {
    if (iVar3 != 1) goto LAB_000eb640;
    if (local_44 < 0x80) {
      param_1[0x10c] = 0xff;
    }
    else {
      param_1[0x10c] = 0;
    }
  }
  else {
    if (iVar3 != 3) goto LAB_000eb640;
    if (local_44 == 0xff) {
      iVar3 = (*DAT_00175628)(0,0xff);
      param_1[0x10c] = iVar3;
    }
  }
  if (param_1[0xff] != 0) {
    iVar5 = iVar4 + ((param_1[0x10c] + -0x80) * param_1[0xff]) / 100;
    if (0xff < iVar5) {
      iVar5 = 0xff;
    }
    if (iVar5 < 1) {
      iVar5 = 1;
    }
    if (iVar4 != iVar5) {
      bVar8 = true;
    }
    local_14 = local_14 | 0x80;
  }
  if (param_1[0x100] != 0) {
    iVar7 = iVar6 + ((param_1[0x10c] + -0x80) * param_1[0x100]) / 100;
    if (100 < iVar7) {
      iVar7 = 100;
    }
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    if (iVar6 != iVar7) {
      bVar8 = true;
    }
    local_14 = local_14 | 0x40;
  }
LAB_000eb6f1:
  if ((local_14 != 0) && (bVar8)) {
    if (iVar5 == 100) {
      iVar5 = 0x65;
    }
    UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),*param_1 + 8,iVar1,(float)iVar7 * 0.01,
               param_1[0xf3],local_14,iVar5);
  }
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.2;
  return;
}


