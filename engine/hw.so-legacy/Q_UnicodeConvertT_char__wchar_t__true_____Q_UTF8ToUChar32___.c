// anon_unknown.dwarf_22c827::Q_UnicodeConvertT<char,_wchar_t,_true,_(*_Q_UTF8ToUChar32),_(*_{anonymous}::Q_UChar32ToUTF32Len),_(*_{anonymous}::Q_UChar32ToUTF32)>  @ 00217130
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */
/* DWARF original name: Q_UnicodeConvertT<char, wchar_t, true, (* Q_UTF8ToUChar32), (*
   {anonymous}::Q_UChar32ToUTF32Len), (* {anonymous}::Q_UChar32ToUTF32)> */

int __regparm3
anon_unknown.dwarf_22c827::
Q_UnicodeConvertT<char,_wchar_t,_true,_(*_Q_UTF8ToUChar32),_(*__anonymous_::Q_UChar32ToUTF32Len),_(*__anonymous_::Q_UChar32ToUTF32)>
          (char *pIn,int nInChars,wchar_t *pOut,int nOutBytes,EStringConvertErrorPolicy ePolicy)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uchar32 local_2c [3];
  bool local_1d [13];
  
                    /* Unresolved local var: int nOut@[???] */
  if (nInChars == 0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar2 = 1;
    if ((nOutBytes & 2U) == 0) {
      if ((nOutBytes & 1U) != 0) {
        for (; *pIn != '\0'; pIn = pIn + iVar4) {
          local_1d[0] = false;
          iVar4 = Q_UTF8ToUChar32(pIn,local_2c,local_1d);
          iVar2 = iVar2 + (uint)(local_1d[0] == false);
        }
        goto LAB_002171bb;
      }
      iVar2 = 0;
      for (; *pIn != '\0'; pIn = pIn + iVar4) {
        iVar2 = iVar2 + 1;
        local_1d[0] = false;
        iVar4 = Q_UTF8ToUChar32(pIn,local_2c,local_1d);
      }
    }
    else {
      if ((nOutBytes & 1U) != 0) {
        for (; *pIn != '\0'; pIn = pIn + iVar4) {
          local_1d[0] = false;
          iVar4 = Q_UTF8ToUChar32(pIn,local_2c,local_1d);
          iVar2 = iVar2 + (uint)(local_1d[0] == false);
        }
        goto LAB_002171bb;
      }
      iVar2 = 0;
      while (*pIn != '\0') {
        iVar2 = iVar2 + 1;
        local_1d[0] = false;
        iVar4 = Q_UTF8ToUChar32(pIn,local_2c,local_1d);
        pIn = pIn + iVar4;
        if (local_1d[0] != false) {
          _DAT_00000000 = 0;
          return 0;
        }
      }
    }
    iVar2 = iVar2 + 1;
  }
  else {
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
    uVar1 = (uint)pOut >> 2;
    if (uVar1 == 0) {
      return 0;
    }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar4 = 0;
    if ((nOutBytes & 2U) == 0) {
      iVar2 = 1;
      if ((nOutBytes & 1U) == 0) {
        while (*pIn != '\0') {
          local_1d[0] = false;
          iVar2 = Q_UTF8ToUChar32(pIn,local_2c,local_1d);
          pIn = pIn + iVar2;
          iVar2 = iVar4 + 1;
          if ((int)uVar1 <= iVar2) goto LAB_002171b4;
          *(uchar32 *)(nInChars + -4 + iVar2 * 4) = local_2c[0];
          iVar4 = iVar2;
        }
        iVar2 = iVar4 + 1;
      }
      else {
        while (*pIn != '\0') {
          while( true ) {
            iVar3 = iVar2;
            local_1d[0] = false;
            iVar2 = Q_UTF8ToUChar32(pIn,local_2c,local_1d);
            pIn = pIn + iVar2;
            iVar2 = iVar3;
            if ((int)uVar1 <= iVar3) goto LAB_002171b4;
            *(uchar32 *)(nInChars + iVar4 * 4) = local_2c[0];
            if (local_1d[0] != false) break;
            iVar2 = iVar3 + 1;
            iVar4 = iVar3;
            if (*pIn == '\0') goto LAB_002171b4;
          }
        }
      }
    }
    else {
      iVar2 = 1;
      if ((nOutBytes & 1U) == 0) {
        if (*pIn != '\0') {
          iVar4 = 0;
          do {
            local_1d[0] = false;
            iVar2 = Q_UTF8ToUChar32(pIn,local_2c,local_1d);
            pIn = pIn + iVar2;
            iVar2 = iVar4 + 1;
            if ((int)uVar1 <= iVar2) goto LAB_002171b4;
            *(uchar32 *)(nInChars + -4 + iVar2 * 4) = local_2c[0];
            if (local_1d[0] != false) {
              *(undefined4 *)nInChars = 0;
              return 0;
            }
            iVar4 = iVar2;
          } while (*pIn != '\0');
        }
        iVar2 = iVar4 + 1;
      }
      else {
        while (*pIn != '\0') {
          while( true ) {
            iVar3 = iVar2;
            local_1d[0] = false;
            iVar2 = Q_UTF8ToUChar32(pIn,local_2c,local_1d);
            pIn = pIn + iVar2;
            iVar2 = iVar3;
            if ((int)uVar1 <= iVar3) goto LAB_002171b4;
            *(uchar32 *)(nInChars + iVar4 * 4) = local_2c[0];
            if (local_1d[0] != false) break;
            iVar2 = iVar3 + 1;
            iVar4 = iVar3;
            if (*pIn == '\0') goto LAB_002171b4;
          }
        }
      }
    }
LAB_002171b4:
    *(undefined4 *)(nInChars + iVar4 * 4) = 0;
  }
LAB_002171bb:
  return iVar2 << 2;
}


