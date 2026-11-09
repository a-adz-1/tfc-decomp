// anon_unknown.dwarf_22c827::Q_UnicodeConvertT<wchar_t,_char,_true,_(*_{anonymous}::Q_UTF32ToUChar32),_(*_Q_UChar32ToUTF8Len),_(*_Q_UChar32ToUTF8)>  @ 00215d60
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */
/* DWARF original name: Q_UnicodeConvertT<wchar_t, char, true, (* {anonymous}::Q_UTF32ToUChar32), (*
   Q_UChar32ToUTF8Len), (* Q_UChar32ToUTF8)> */

int __regparm3
anon_unknown.dwarf_22c827::
Q_UnicodeConvertT<wchar_t,_char,_true,_(*__anonymous_::Q_UTF32ToUChar32),_(*_Q_UChar32ToUTF8Len),_(*_Q_UChar32ToUTF8)>
          (wchar_t *pIn,int nInChars,char *pOut,int nOutBytes,EStringConvertErrorPolicy ePolicy)

{
  byte *pbVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  wchar_t wVar7;
  int iVar8;
  wchar_t *pwVar9;
  
                    /* Unresolved local var: int nOut@[???] */
  if (nInChars == 0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    if ((nOutBytes & 1U) == 0) {
      if ((nOutBytes & 2U) == 0) {
        iVar8 = 0;
        while( true ) {
          wVar7 = *pIn;
          if (wVar7 == L'\0') break;
          if ((((uint)(wVar7 + L'\xffff2800') < 0x800) || (0x10ffff < (uint)wVar7)) ||
             ((0xfffd < (ushort)wVar7 || ((uint)(wVar7 + L'\xffff0230') < 0x20)))) {
            iVar8 = iVar8 + 1;
            pIn = pIn + 1;
          }
          else {
            if (wVar7 < L'\x80') {
              iVar5 = 1;
            }
            else {
              iVar5 = 2;
              if (L'߿' < wVar7) {
                iVar5 = (L'\xffff' < wVar7) + 3;
              }
            }
            iVar8 = iVar8 + iVar5;
            pIn = pIn + 1;
          }
        }
      }
      else {
        iVar8 = 0;
        while (wVar7 = *pIn, wVar7 != L'\0') {
          if (((((uint)(wVar7 + L'\xffff2800') < 0x800) || (0x10ffff < (uint)wVar7)) ||
              (0xfffd < (ushort)wVar7)) || ((uint)(wVar7 + L'\xffff0230') < 0x20)) {
            DAT_00000000 = 0;
            return 0;
          }
          pIn = pIn + 1;
          if (wVar7 < L'\x80') {
            iVar8 = iVar8 + 1;
          }
          else if (wVar7 < L'ࠀ') {
            iVar8 = iVar8 + 2;
          }
          else {
            iVar8 = iVar8 + (L'\xffff' < wVar7) + 3;
          }
        }
      }
    }
    else {
      iVar8 = 0;
      while( true ) {
        pwVar9 = pIn + 1;
        wVar7 = *pIn;
        if (wVar7 == L'\0') break;
        pIn = pwVar9;
        if (((0x7ff < (uint)(wVar7 + L'\xffff2800')) && ((uint)wVar7 < 0x110000)) &&
           (((ushort)wVar7 < 0xfffe && (0x1f < (uint)(wVar7 + L'\xffff0230'))))) {
          if (wVar7 < L'\x80') {
            iVar5 = 1;
          }
          else {
            iVar5 = 2;
            if (L'߿' < wVar7) {
              iVar5 = (L'\xffff' < wVar7) + 3;
            }
          }
          iVar8 = iVar8 + iVar5;
        }
      }
    }
  }
  else {
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
    if ((int)pOut < 1) {
      return 0;
    }
    wVar7 = *pIn;
    iVar8 = 0;
    if (wVar7 != L'\0') {
      iVar8 = 0;
      do {
        pIn = pIn + 1;
        if (((((uint)(wVar7 + L'\xffff2800') < 0x800) || (0x10ffff < (uint)wVar7)) ||
            (0xfffd < (ushort)wVar7)) || ((uint)(wVar7 + L'\xffff0230') < 0x20)) {
          wVar7 = L'?';
          bVar2 = true;
          iVar5 = 1;
        }
        else if (wVar7 < L'\x80') {
          bVar2 = false;
          iVar5 = 1;
        }
        else {
          iVar5 = 2;
          if (L'߿' < wVar7) {
            iVar5 = (L'\xffff' < wVar7) + 3;
          }
          bVar2 = false;
        }
        if ((int)pOut <= iVar5 + iVar8) break;
        pbVar1 = (byte *)(nInChars + iVar8);
        bVar6 = (byte)wVar7;
        if (wVar7 < L'\x80') {
          *pbVar1 = bVar6;
          iVar5 = 1;
        }
        else {
          bVar3 = (byte)(wVar7 >> 6);
          if (wVar7 < L'ࠀ') {
            *pbVar1 = bVar3 | 0xc0;
            pbVar1[1] = bVar6 & 0x3f | 0x80;
            iVar5 = 2;
          }
          else {
            bVar4 = (byte)(wVar7 >> 0xc);
            if (wVar7 < L'𐀀') {
              *pbVar1 = bVar4 | 0xe0;
              pbVar1[1] = bVar3 & 0x3f | 0x80;
              pbVar1[2] = bVar6 & 0x3f | 0x80;
              iVar5 = 3;
            }
            else {
              *pbVar1 = (byte)(wVar7 >> 0x12) | 0xf0;
              pbVar1[1] = bVar4 & 0x3f | 0x80;
              pbVar1[2] = bVar3 & 0x3f | 0x80;
              pbVar1[3] = bVar6 & 0x3f | 0x80;
              iVar5 = 4;
            }
          }
        }
        iVar8 = iVar8 + iVar5;
        if (bVar2) {
          if ((nOutBytes & 1U) == 0) {
            if ((nOutBytes & 2U) != 0) {
              *(undefined1 *)nInChars = 0;
              return 0;
            }
          }
          else {
            iVar5 = 1;
            if ((L'\x7f' < wVar7) && (iVar5 = 2, L'߿' < wVar7)) {
              iVar5 = (L'\xffff' < wVar7) + 3;
            }
            iVar8 = iVar8 - iVar5;
          }
        }
        wVar7 = *pIn;
      } while (wVar7 != L'\0');
    }
    *(undefined1 *)(nInChars + iVar8) = 0;
  }
  return iVar8 + 1;
}


