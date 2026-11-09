// anon_unknown.dwarf_2ec073::Q_UnicodeConvertT<wchar_t,_char,_true,_(anonymous_namespace)::Q_UTF32ToUChar32,_Q_UChar32ToUTF8Len,_Q_UChar32ToUTF8>  @ 001c66e0
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */
/* DWARF original name: Q_UnicodeConvertT<wchar_t, char, true, (anonymous
   namespace)::Q_UTF32ToUChar32, Q_UChar32ToUTF8Len, Q_UChar32ToUTF8> */

int __regparm3
anon_unknown.dwarf_2ec073::
Q_UnicodeConvertT<wchar_t,_char,_true,_(anonymous_namespace)::Q_UTF32ToUChar32,_Q_UChar32ToUTF8Len,_Q_UChar32ToUTF8>
          (wchar_t *pIn,int nInChars,char *pOut,int nOutBytes,EStringConvertErrorPolicy ePolicy)

{
  int iVar1;
  bool bVar2;
  byte *pbVar3;
  wchar_t *pwVar4;
  byte bVar5;
  wchar_t wVar6;
  int iVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  int local_18;
  
                    /* Unresolved local var: int nOut@[???] */
  if (nInChars == 0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    pwVar4 = pIn + 1;
    iVar7 = 0;
    if ((nOutBytes & 1U) == 0) {
      if ((nOutBytes & 2U) == 0) {
        for (; wVar6 = pwVar4[-1], wVar6 != L'\0'; pwVar4 = pwVar4 + 1) {
          if ((((uint)(wVar6 + L'\xffff2800') < 0x800) || (0x10ffff < (uint)wVar6)) ||
             ((0xfffd < (ushort)wVar6 || ((uint)(wVar6 + L'\xffff0230') < 0x20)))) {
            iVar7 = iVar7 + 1;
          }
          else {
            if (wVar6 < L'\x80') {
              iVar10 = 1;
            }
            else {
              iVar10 = 2;
              if (L'߿' < wVar6) {
                iVar10 = (L'\xffff' < wVar6) + 3;
              }
            }
            iVar7 = iVar7 + iVar10;
          }
        }
      }
      else {
        iVar7 = 0;
        while (wVar6 = *pIn, wVar6 != L'\0') {
          if ((((uint)(wVar6 + L'\xffff2800') < 0x800) || (0x10ffff < (uint)wVar6)) ||
             ((0xfffd < (ushort)wVar6 || ((uint)(wVar6 + L'\xffff0230') < 0x20)))) {
            DAT_00000000 = 0;
            return 0;
          }
          pIn = pIn + 1;
          if (wVar6 < L'\x80') {
            iVar7 = iVar7 + 1;
          }
          else if (wVar6 < L'ࠀ') {
            iVar7 = iVar7 + 2;
          }
          else {
            iVar7 = iVar7 + (L'\xffff' < wVar6) + 3;
          }
        }
      }
    }
    else {
      for (; wVar6 = pwVar4[-1], wVar6 != L'\0'; pwVar4 = pwVar4 + 1) {
        if ((((0x7ff < (uint)(wVar6 + L'\xffff2800')) && ((uint)wVar6 < 0x110000)) &&
            ((ushort)wVar6 < 0xfffe)) && (0x1f < (uint)(wVar6 + L'\xffff0230'))) {
          if (wVar6 < L'\x80') {
            iVar10 = 1;
          }
          else {
            iVar10 = 2;
            if (L'߿' < wVar6) {
              iVar10 = (L'\xffff' < wVar6) + 3;
            }
          }
          iVar7 = iVar7 + iVar10;
        }
      }
    }
    return iVar7 + 1;
  }
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
  if ((int)pOut < 1) {
    return 0;
  }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
  iVar7 = 0;
LAB_001c676b:
  iVar10 = iVar7;
  pwVar4 = pIn + 1;
  wVar6 = *pIn;
  if (wVar6 == L'\0') {
LAB_001c6795:
    local_18 = iVar10 + 1;
    *(undefined1 *)(nInChars + iVar10) = 0;
    return local_18;
  }
  pIn = pwVar4;
  if (((((uint)(wVar6 + L'\xffff2800') < 0x800) || (0x10ffff < (uint)wVar6)) ||
      (0xfffd < (ushort)wVar6)) || ((uint)(wVar6 + L'\xffff0230') < 0x20)) {
    wVar6 = L'?';
    bVar2 = true;
  }
  else {
    if (L'\x7f' < wVar6) {
      bVar5 = (byte)wVar6;
      bVar8 = (byte)(wVar6 >> 6);
      if (wVar6 < L'ࠀ') {
        if (iVar10 + 2 < (int)pOut) {
          *(byte *)(iVar10 + nInChars) = bVar8 | 0xc0;
          ((byte *)(iVar10 + nInChars))[1] = bVar5 & 0x3f | 0x80;
          iVar7 = iVar10 + 2;
          goto LAB_001c676b;
        }
      }
      else {
        bVar9 = (byte)(wVar6 >> 0xc);
        if (wVar6 < L'𐀀') {
          if ((int)pOut <= iVar10 + 3) goto LAB_001c6795;
          pbVar3 = (byte *)(iVar10 + nInChars);
          *pbVar3 = bVar9 | 0xe0;
          pbVar3[1] = bVar8 & 0x3f | 0x80;
          pbVar3[2] = bVar5 & 0x3f | 0x80;
          iVar7 = iVar10 + 3;
          goto LAB_001c676b;
        }
        if (iVar10 + 4 < (int)pOut) {
          pbVar3 = (byte *)(iVar10 + nInChars);
          *pbVar3 = (byte)(wVar6 >> 0x12) | 0xf0;
          pbVar3[1] = bVar9 & 0x3f | 0x80;
          pbVar3[2] = bVar8 & 0x3f | 0x80;
          pbVar3[3] = bVar5 & 0x3f | 0x80;
          iVar7 = iVar10 + 4;
          goto LAB_001c676b;
        }
      }
      goto LAB_001c6795;
    }
    bVar2 = false;
  }
  iVar1 = iVar10 + 1;
  if ((int)pOut <= iVar1) goto LAB_001c6795;
  *(char *)(nInChars + iVar10) = (char)wVar6;
  iVar7 = iVar1;
  if (((bVar2) && (iVar7 = iVar10, (nOutBytes & 1U) == 0)) && (iVar7 = iVar1, (nOutBytes & 2U) != 0)
     ) {
    *(undefined1 *)nInChars = 0;
    return 0;
  }
  goto LAB_001c676b;
}


