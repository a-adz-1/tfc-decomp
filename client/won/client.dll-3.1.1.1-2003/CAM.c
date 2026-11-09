// CAM_Think  @ 270254a0
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
  
                    /* 0x254a0  471  CAM_Think */
  lVar6 = __ftol();
  if ((int)lVar6 == 1) {
    FUN_27025b40();
  }
  else if ((int)lVar6 == 2) {
    FUN_27025bb0();
  }
  if (DAT_270b5750 != 0) {
    local_18 = *(float *)(DAT_270b572c + 0xc);
    local_14 = *(float *)(DAT_270b56d8 + 0xc);
    local_28 = *(float *)(DAT_270b56e4 + 0xc);
    if ((DAT_270b56c0 != 0) && (GetCursorPos((LPPOINT)&DAT_270b56e8), DAT_270b5728 == 0)) {
      iVar3 = (*DAT_270a8248)();
      if (iVar3 < DAT_270b56e8) {
        if (local_14 < *(float *)(DAT_270b56f0 + 0xc)) {
          iVar3 = (*DAT_270a8248)();
          local_14 = (float)((DAT_270b56e8 - iVar3) / 2) * 0.5 + local_14;
        }
        if (*(float *)(DAT_270b56f0 + 0xc) < local_14) {
          local_14 = *(float *)(DAT_270b56f0 + 0xc);
        }
      }
      else {
        iVar3 = (*DAT_270a8248)();
        if (DAT_270b56e8 < iVar3) {
          if (*(float *)(DAT_270b56b4 + 0xc) < local_14) {
            iVar3 = (*DAT_270a8248)();
            local_14 = local_14 - (float)((iVar3 - DAT_270b56e8) / 2) * 0.5;
          }
          if (local_14 < *(float *)(DAT_270b56b4 + 0xc)) {
            local_14 = *(float *)(DAT_270b56b4 + 0xc);
          }
        }
      }
      iVar3 = (*DAT_270a824c)();
      if (iVar3 < DAT_270b56ec) {
        if (local_18 < *(float *)(DAT_270b5700 + 0xc)) {
          iVar3 = (*DAT_270a824c)();
          local_18 = (float)((DAT_270b56ec - iVar3) / 2) * 0.5 + local_18;
        }
        if (*(float *)(DAT_270b5700 + 0xc) < local_18) {
          local_18 = *(float *)(DAT_270b5700 + 0xc);
        }
      }
      else {
        iVar3 = (*DAT_270a824c)();
        if (DAT_270b56ec < iVar3) {
          if (*(float *)(DAT_270b56e0 + 0xc) < local_18) {
            iVar3 = (*DAT_270a824c)();
            local_18 = local_18 - (float)((iVar3 - DAT_270b56ec) / 2) * 0.5;
          }
          if (local_18 < *(float *)(DAT_270b56e0 + 0xc)) {
            local_18 = *(float *)(DAT_270b56e0 + 0xc);
          }
        }
      }
      fVar5 = FUN_270220d0(0x270a65e8);
      if (fVar5 == (float10)0.0) {
        _DAT_270b56c8 = DAT_270b56e8;
        _DAT_270b56c4 = DAT_270b56ec;
      }
      else {
        lVar6 = __ftol();
        _DAT_270b56c8 = (int)lVar6;
        lVar6 = __ftol();
        _DAT_270b56c4 = (int)lVar6;
      }
      iVar3 = (*DAT_270a824c)();
      iVar4 = (*DAT_270a8248)();
      SetCursorPos(iVar4,iVar3);
    }
    fVar5 = FUN_270267c0(0x270b5710);
    if (fVar5 == (float10)0.0) {
      fVar5 = FUN_270267c0(0x270b5734);
      if (fVar5 != (float10)0.0) {
        local_18 = local_18 - 2.5;
      }
    }
    else {
      local_18 = local_18 + 2.5;
    }
    fVar5 = FUN_270267c0(0x270b56cc);
    if (fVar5 == (float10)0.0) {
      fVar5 = FUN_270267c0(0x270b571c);
      if (fVar5 != (float10)0.0) {
        local_14 = local_14 + 2.5;
      }
    }
    else {
      local_14 = local_14 - 2.5;
    }
    fVar5 = FUN_270267c0(0x270b5740);
    if (fVar5 == (float10)0.0) {
      fVar5 = FUN_270267c0(0x270b5704);
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
    if (DAT_270b5728 != 0) {
      iVar3 = (*DAT_270a824c)();
      if (iVar3 < DAT_270b56ec) {
        if (local_28 < *(float *)(DAT_270b56dc + 0xc)) {
          iVar3 = (*DAT_270a824c)();
          local_28 = (float)((DAT_270b56ec - iVar3) / 2) + local_28;
        }
        if (*(float *)(DAT_270b56dc + 0xc) < local_28) {
          local_28 = *(float *)(DAT_270b56dc + 0xc);
        }
      }
      else {
        iVar3 = (*DAT_270a824c)();
        if (DAT_270b56ec < iVar3) {
          if (*(float *)(DAT_270b574c + 0xc) < local_28) {
            iVar3 = (*DAT_270a824c)();
            local_28 = local_28 - (float)((iVar3 - DAT_270b56ec) / 2);
          }
          if (local_28 < *(float *)(DAT_270b574c + 0xc)) {
            local_28 = *(float *)(DAT_270b574c + 0xc);
          }
        }
      }
      FUN_270220d0(0x270a65e8);
      lVar6 = __ftol();
      _DAT_270b56c8 = (int)lVar6;
      FUN_270220d0(0x270a65e8);
      lVar6 = __ftol();
      _DAT_270b56c4 = (int)lVar6;
      iVar3 = (*DAT_270a824c)();
      iVar4 = (*DAT_270a8248)();
      SetCursorPos(iVar4,iVar3);
    }
    *(float *)(DAT_270b572c + 0xc) = local_18;
    *(float *)(DAT_270b56d8 + 0xc) = local_14;
    *(float *)(DAT_270b56e4 + 0xc) = local_28;
    fVar2 = DAT_270b56f8;
    fVar1 = DAT_270b56f4;
    local_14 = DAT_270b56f8;
    (*DAT_270a8250)(&fStack_c);
    if (*(float *)(DAT_270b56bc + 0xc) == 0.0) {
      if (fVar2 - fStack_8 != *(float *)(DAT_270b56d8 + 0xc)) {
        fVar5 = FUN_270253c0(fVar2,fStack_8 + *(float *)(DAT_270b56d8 + 0xc));
        local_14 = (float)fVar5;
      }
      fVar5 = (float10)fVar1;
      if (fVar5 - (float10)fStack_c != (float10)*(float *)(DAT_270b572c + 0xc)) {
        fVar5 = FUN_270253c0(fVar1,fStack_c + *(float *)(DAT_270b572c + 0xc));
      }
    }
    else {
      local_14 = fStack_8 + *(float *)(DAT_270b56d8 + 0xc);
      fVar5 = (float10)fStack_c + (float10)*(float *)(DAT_270b572c + 0xc);
    }
    DAT_270b56f4 = (float)fVar5;
    DAT_270b56f8 = local_14;
    DAT_270b56fc = local_28;
  }
  return;
}


