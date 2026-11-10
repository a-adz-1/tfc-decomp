// RampThink__15CAmbientGeneric  @ 000e0dac
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
  iVar7 = param_1[0x106];
  iVar5 = param_1[0x10a];
  local_c = 0;
  bVar9 = false;
  if (param_1[0xfa] == 0) {
    if ((((param_1[0xfb] == 0) && (param_1[0xfe] == 0)) && (param_1[0xff] == 0)) &&
       (param_1[0x100] == 0)) {
      return;
    }
    if ((param_1[0xfa] != 0) || (param_1[0xfb] != 0)) goto LAB_000e0e40;
LAB_000e0ee0:
    if ((param_1[0xfe] != 0) || (param_1[0xff] != 0)) {
      iVar6 = param_1[0x10d];
      if (param_1[0xfe] < 1) {
        if (0 < param_1[0xff]) {
          param_1[0x10d] = param_1[0x10d] - param_1[0xff];
        }
      }
      else {
        param_1[0x10d] = param_1[0x10d] + param_1[0xfe];
      }
      iVar5 = param_1[0x10d] >> 8;
      if (param_1[0xfc] < iVar5) {
        iVar5 = param_1[0xfc];
        param_1[0xfe] = 0;
      }
      if (iVar5 < param_1[0xfd]) {
        param_1[0xff] = 0;
        goto LAB_000e0f64;
      }
      if (100 < iVar5) {
        iVar5 = 100;
      }
      if (iVar5 < 1) {
        iVar5 = 1;
      }
      param_1[0x10a] = iVar5;
      if (iVar6 >> 8 != iVar5) {
        bVar9 = true;
      }
      local_c = local_c | 0x40;
    }
    iVar6 = iVar5;
    iVar8 = iVar7;
    if (param_1[0x100] != 0) {
      if (0x6fffffff < param_1[0x10e]) {
        param_1[0x10e] = 0;
      }
      iVar4 = param_1[0x101];
      iVar2 = iVar4 + param_1[0x10e];
      param_1[0x10e] = iVar2;
      iVar3 = iVar2 >> 8;
      if (iVar2 < 0) {
        param_1[0x10e] = 0;
        if (iVar4 < 0) {
          iVar4 = -iVar4;
        }
        param_1[0x101] = iVar4;
        iVar3 = 0;
      }
      else if (0xff < iVar3) {
        iVar3 = 0xff;
        param_1[0x10e] = 0xff00;
        local_18 = param_1[0x101];
        if (local_18 < 0) {
          local_18 = -local_18;
        }
        param_1[0x101] = -local_18;
      }
      iVar4 = param_1[0x100];
      if (iVar4 == 2) {
        param_1[0x10f] = iVar3;
      }
      else if (iVar4 < 3) {
        if (iVar4 != 1) {
          FUN_000e10cc();
          return;
        }
        if (iVar3 < 0x80) {
          param_1[0x10f] = 0xff;
        }
        else {
          param_1[0x10f] = 0;
        }
      }
      else {
        if (iVar4 != 3) {
          FUN_000e10cc();
          return;
        }
        if (iVar3 == 0xff) {
          iVar4 = (*DAT_001a7fa8)(0,0xff);
          param_1[0x10f] = iVar4;
        }
      }
      if (param_1[0x102] != 0) {
        iVar8 = iVar7 + ((param_1[0x10f] + -0x80) * param_1[0x102]) / 100;
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
      if (param_1[0x103] != 0) {
        iVar6 = iVar5 + ((param_1[0x10f] + -0x80) * param_1[0x103]) / 100;
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
    }
    if ((local_c != 0) && (bVar9)) {
      if (iVar8 == 100) {
        iVar8 = 0x65;
      }
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
                (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,iVar1,(float)iVar6 * 0.01,
                 param_1[0xf6],local_c,iVar8);
    }
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
  }
  else {
LAB_000e0e40:
    iVar6 = param_1[0x109];
    if (param_1[0xfa] < 1) {
      if (0 < param_1[0xfb]) {
        param_1[0x109] = param_1[0x109] - param_1[0xfb];
      }
    }
    else {
      param_1[0x109] = param_1[0x109] + param_1[0xfa];
    }
    iVar7 = param_1[0x109] >> 8;
    if (param_1[0xf8] < iVar7) {
      iVar7 = param_1[0xf8];
      param_1[0xfa] = 0;
    }
    if (param_1[0xf9] <= iVar7) {
      if (0xff < iVar7) {
        iVar7 = 0xff;
      }
      if (iVar7 < 1) {
        iVar7 = 1;
      }
      param_1[0x106] = iVar7;
      bVar9 = iVar6 >> 8 != iVar7;
      local_c = 0x80;
      goto LAB_000e0ee0;
    }
    param_1[0xfb] = 0;
LAB_000e0f64:
    UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii
              (*(undefined4 *)(*param_1 + 0x208),*param_1 + 8,iVar1,0,0,0x20,0);
  }
  return;
}


