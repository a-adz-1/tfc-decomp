// CAM_Think  @ 2701c090
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CAM_Think(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  longlong lVar6;
  float local_28;
  float local_18;
  float local_14;
  float fStack_c;
  float fStack_8;
  
                    /* 0x1c090  418  CAM_Think */
  lVar6 = __ftol();
  if ((int)lVar6 == 1) {
    FUN_2701c730();
  }
  else if ((int)lVar6 == 2) {
    FUN_2701c7a0();
  }
  if (DAT_27089e38 != 0) {
    local_18 = *(float *)(DAT_27089e0c + 0xc);
    local_14 = *(float *)(DAT_27089d9c + 0xc);
    local_28 = *(float *)(DAT_27089da8 + 0xc);
    if ((DAT_27089d84 != 0) && (GetCursorPos((LPPOINT)&DAT_27089db0), DAT_27089dfc == 0)) {
      iVar3 = (*DAT_2707c948)();
      if (iVar3 < DAT_27089db0) {
        if (local_14 < *(float *)(DAT_27089db8 + 0xc)) {
          iVar3 = (*DAT_2707c948)();
          local_14 = (float)((DAT_27089db0 - iVar3) / 2) * 0.5 + local_14;
        }
        if (*(float *)(DAT_27089db8 + 0xc) < local_14) {
          local_14 = *(float *)(DAT_27089db8 + 0xc);
        }
      }
      else {
        iVar3 = (*DAT_2707c948)();
        if (DAT_27089db0 < iVar3) {
          if (*(float *)(DAT_27089d78 + 0xc) < local_14) {
            iVar3 = (*DAT_2707c948)();
            local_14 = local_14 - (float)((iVar3 - DAT_27089db0) / 2) * 0.5;
          }
          if (local_14 < *(float *)(DAT_27089d78 + 0xc)) {
            local_14 = *(float *)(DAT_27089d78 + 0xc);
          }
        }
      }
      iVar3 = (*DAT_2707c94c)();
      if (iVar3 < DAT_27089db4) {
        if (local_18 < *(float *)(DAT_27089dcc + 0xc)) {
          iVar3 = (*DAT_2707c94c)();
          local_18 = (float)((DAT_27089db4 - iVar3) / 2) * 0.5 + local_18;
        }
        if (*(float *)(DAT_27089dcc + 0xc) < local_18) {
          local_18 = *(float *)(DAT_27089dcc + 0xc);
        }
      }
      else {
        iVar3 = (*DAT_2707c94c)();
        if (DAT_27089db4 < iVar3) {
          if (*(float *)(DAT_27089da4 + 0xc) < local_18) {
            iVar3 = (*DAT_2707c94c)();
            local_18 = local_18 - (float)((iVar3 - DAT_27089db4) / 2) * 0.5;
          }
          if (local_18 < *(float *)(DAT_27089da4 + 0xc)) {
            local_18 = *(float *)(DAT_27089da4 + 0xc);
          }
        }
      }
      fVar5 = FUN_27018b80(0x2707bf70);
      if (fVar5 == (float10)0.0) {
        _DAT_27089d8c = DAT_27089db0;
        _DAT_27089d88 = DAT_27089db4;
      }
      else {
        lVar6 = __ftol();
        _DAT_27089d8c = (int)lVar6;
        lVar6 = __ftol();
        _DAT_27089d88 = (int)lVar6;
      }
      iVar3 = (*DAT_2707c94c)();
      iVar4 = (*DAT_2707c948)();
      SetCursorPos(iVar4,iVar3);
    }
    fVar5 = FUN_2701d2f0(0x27089de0);
    if (fVar5 == (float10)0.0) {
      fVar5 = FUN_2701d2f0(0x27089e18);
      if (fVar5 != (float10)0.0) {
        local_18 = local_18 - 2.5;
      }
    }
    else {
      local_18 = local_18 + 2.5;
    }
    fVar5 = FUN_2701d2f0(0x27089d90);
    if (fVar5 == (float10)0.0) {
      fVar5 = FUN_2701d2f0(0x27089df0);
      if (fVar5 != (float10)0.0) {
        local_14 = local_14 + 2.5;
      }
    }
    else {
      local_14 = local_14 - 2.5;
    }
    fVar5 = FUN_2701d2f0(0x27089e28);
    if (fVar5 == (float10)0.0) {
      fVar5 = FUN_2701d2f0(0x27089dd0);
      if (fVar5 != (float10)0.0) {
        local_28 = local_28 + 1.0;
      }
    }
    else {
      local_28 = local_28 - 1.0;
      if (local_28 < 30.0) {
        local_18 = 0.0;
        local_14 = 0.0;
        local_28 = 30.0;
      }
    }
    if (DAT_27089dfc != 0) {
      iVar3 = (*DAT_2707c94c)();
      if (iVar3 < DAT_27089db4) {
        if (local_28 < *(float *)(DAT_27089da0 + 0xc)) {
          iVar3 = (*DAT_2707c94c)();
          local_28 = (float)((DAT_27089db4 - iVar3) / 2) + local_28;
        }
        if (*(float *)(DAT_27089da0 + 0xc) < local_28) {
          local_28 = *(float *)(DAT_27089da0 + 0xc);
        }
      }
      else {
        iVar3 = (*DAT_2707c94c)();
        if (DAT_27089db4 < iVar3) {
          if (*(float *)(DAT_27089e34 + 0xc) < local_28) {
            iVar3 = (*DAT_2707c94c)();
            local_28 = local_28 - (float)((iVar3 - DAT_27089db4) / 2);
          }
          if (local_28 < *(float *)(DAT_27089e34 + 0xc)) {
            local_28 = *(float *)(DAT_27089e34 + 0xc);
          }
        }
      }
      FUN_27018b80(0x2707bf70);
      lVar6 = __ftol();
      _DAT_27089d8c = (int)lVar6;
      FUN_27018b80(0x2707bf70);
      lVar6 = __ftol();
      _DAT_27089d88 = (int)lVar6;
      iVar3 = (*DAT_2707c94c)();
      iVar4 = (*DAT_2707c948)();
      SetCursorPos(iVar4,iVar3);
    }
    *(float *)(DAT_27089e0c + 0xc) = local_18;
    *(float *)(DAT_27089d9c + 0xc) = local_14;
    *(float *)(DAT_27089da8 + 0xc) = local_28;
    fVar2 = DAT_27089dc4;
    fVar1 = DAT_27089dc0;
    local_14 = DAT_27089dc4;
    (*DAT_2707c950)(&fStack_c);
    if (*(float *)(DAT_27089d80 + 0xc) == 0.0) {
      if (fVar2 - fStack_8 != *(float *)(DAT_27089d9c + 0xc)) {
        fVar5 = FUN_2701bfb0(fVar2,fStack_8 + *(float *)(DAT_27089d9c + 0xc));
        local_14 = (float)fVar5;
      }
      fVar5 = (float10)fVar1;
      if (fVar5 - (float10)fStack_c != (float10)*(float *)(DAT_27089e0c + 0xc)) {
        fVar5 = FUN_2701bfb0(fVar1,fStack_c + *(float *)(DAT_27089e0c + 0xc));
      }
    }
    else {
      local_14 = fStack_8 + *(float *)(DAT_27089d9c + 0xc);
      fVar5 = (float10)fStack_c + (float10)*(float *)(DAT_27089e0c + 0xc);
    }
    DAT_27089dc0 = (float)fVar5;
    DAT_27089dc4 = local_14;
    DAT_27089dc8 = local_28;
  }
  return;
}


