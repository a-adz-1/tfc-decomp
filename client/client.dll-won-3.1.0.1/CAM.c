// CAM_Think  @ 2701c290
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
  
                    /* 0x1c290  418  CAM_Think */
  lVar6 = __ftol();
  if ((int)lVar6 == 1) {
    FUN_2701c930();
  }
  else if ((int)lVar6 == 2) {
    FUN_2701c9a0();
  }
  if (DAT_2707cf58 != 0) {
    local_18 = *(float *)(DAT_2707cf2c + 0xc);
    local_14 = *(float *)(DAT_2707cebc + 0xc);
    local_28 = *(float *)(DAT_2707cec8 + 0xc);
    if ((DAT_2707cea4 != 0) && (GetCursorPos((LPPOINT)&DAT_2707ced0), DAT_2707cf1c == 0)) {
      iVar3 = (*DAT_27073b20)();
      if (iVar3 < DAT_2707ced0) {
        if (local_14 < *(float *)(DAT_2707ced8 + 0xc)) {
          iVar3 = (*DAT_27073b20)();
          local_14 = (float)((DAT_2707ced0 - iVar3) / 2) * 0.5 + local_14;
        }
        if (*(float *)(DAT_2707ced8 + 0xc) < local_14) {
          local_14 = *(float *)(DAT_2707ced8 + 0xc);
        }
      }
      else {
        iVar3 = (*DAT_27073b20)();
        if (DAT_2707ced0 < iVar3) {
          if (*(float *)(DAT_2707ce98 + 0xc) < local_14) {
            iVar3 = (*DAT_27073b20)();
            local_14 = local_14 - (float)((iVar3 - DAT_2707ced0) / 2) * 0.5;
          }
          if (local_14 < *(float *)(DAT_2707ce98 + 0xc)) {
            local_14 = *(float *)(DAT_2707ce98 + 0xc);
          }
        }
      }
      iVar3 = (*DAT_27073b24)();
      if (iVar3 < DAT_2707ced4) {
        if (local_18 < *(float *)(DAT_2707ceec + 0xc)) {
          iVar3 = (*DAT_27073b24)();
          local_18 = (float)((DAT_2707ced4 - iVar3) / 2) * 0.5 + local_18;
        }
        if (*(float *)(DAT_2707ceec + 0xc) < local_18) {
          local_18 = *(float *)(DAT_2707ceec + 0xc);
        }
      }
      else {
        iVar3 = (*DAT_27073b24)();
        if (DAT_2707ced4 < iVar3) {
          if (*(float *)(DAT_2707cec4 + 0xc) < local_18) {
            iVar3 = (*DAT_27073b24)();
            local_18 = local_18 - (float)((iVar3 - DAT_2707ced4) / 2) * 0.5;
          }
          if (local_18 < *(float *)(DAT_2707cec4 + 0xc)) {
            local_18 = *(float *)(DAT_2707cec4 + 0xc);
          }
        }
      }
      fVar5 = FUN_27018cc0(0x27073150);
      if (fVar5 == (float10)0.0) {
        _DAT_2707ceac = DAT_2707ced0;
        _DAT_2707cea8 = DAT_2707ced4;
      }
      else {
        lVar6 = __ftol();
        _DAT_2707ceac = (int)lVar6;
        lVar6 = __ftol();
        _DAT_2707cea8 = (int)lVar6;
      }
      iVar3 = (*DAT_27073b24)();
      iVar4 = (*DAT_27073b20)();
      SetCursorPos(iVar4,iVar3);
    }
    fVar5 = FUN_2701d4f0(0x2707cf00);
    if (fVar5 == (float10)0.0) {
      fVar5 = FUN_2701d4f0(0x2707cf38);
      if (fVar5 != (float10)0.0) {
        local_18 = local_18 - 2.5;
      }
    }
    else {
      local_18 = local_18 + 2.5;
    }
    fVar5 = FUN_2701d4f0(0x2707ceb0);
    if (fVar5 == (float10)0.0) {
      fVar5 = FUN_2701d4f0(0x2707cf10);
      if (fVar5 != (float10)0.0) {
        local_14 = local_14 + 2.5;
      }
    }
    else {
      local_14 = local_14 - 2.5;
    }
    fVar5 = FUN_2701d4f0(0x2707cf48);
    if (fVar5 == (float10)0.0) {
      fVar5 = FUN_2701d4f0(0x2707cef0);
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
    if (DAT_2707cf1c != 0) {
      iVar3 = (*DAT_27073b24)();
      if (iVar3 < DAT_2707ced4) {
        if (local_28 < *(float *)(DAT_2707cec0 + 0xc)) {
          iVar3 = (*DAT_27073b24)();
          local_28 = (float)((DAT_2707ced4 - iVar3) / 2) + local_28;
        }
        if (*(float *)(DAT_2707cec0 + 0xc) < local_28) {
          local_28 = *(float *)(DAT_2707cec0 + 0xc);
        }
      }
      else {
        iVar3 = (*DAT_27073b24)();
        if (DAT_2707ced4 < iVar3) {
          if (*(float *)(DAT_2707cf54 + 0xc) < local_28) {
            iVar3 = (*DAT_27073b24)();
            local_28 = local_28 - (float)((iVar3 - DAT_2707ced4) / 2);
          }
          if (local_28 < *(float *)(DAT_2707cf54 + 0xc)) {
            local_28 = *(float *)(DAT_2707cf54 + 0xc);
          }
        }
      }
      FUN_27018cc0(0x27073150);
      lVar6 = __ftol();
      _DAT_2707ceac = (int)lVar6;
      FUN_27018cc0(0x27073150);
      lVar6 = __ftol();
      _DAT_2707cea8 = (int)lVar6;
      iVar3 = (*DAT_27073b24)();
      iVar4 = (*DAT_27073b20)();
      SetCursorPos(iVar4,iVar3);
    }
    *(float *)(DAT_2707cf2c + 0xc) = local_18;
    *(float *)(DAT_2707cebc + 0xc) = local_14;
    *(float *)(DAT_2707cec8 + 0xc) = local_28;
    fVar2 = DAT_2707cee4;
    fVar1 = DAT_2707cee0;
    local_14 = DAT_2707cee4;
    (*DAT_27073b28)(&fStack_c);
    if (*(float *)(DAT_2707cea0 + 0xc) == 0.0) {
      if (fVar2 - fStack_8 != *(float *)(DAT_2707cebc + 0xc)) {
        fVar5 = FUN_2701c1b0(fVar2,fStack_8 + *(float *)(DAT_2707cebc + 0xc));
        local_14 = (float)fVar5;
      }
      fVar5 = (float10)fVar1;
      if (fVar5 - (float10)fStack_c != (float10)*(float *)(DAT_2707cf2c + 0xc)) {
        fVar5 = FUN_2701c1b0(fVar1,fStack_c + *(float *)(DAT_2707cf2c + 0xc));
      }
    }
    else {
      local_14 = fStack_8 + *(float *)(DAT_2707cebc + 0xc);
      fVar5 = (float10)fStack_c + (float10)*(float *)(DAT_2707cf2c + 0xc);
    }
    DAT_2707cee0 = (float)fVar5;
    DAT_2707cee4 = local_14;
    DAT_2707cee8 = local_28;
  }
  return;
}


