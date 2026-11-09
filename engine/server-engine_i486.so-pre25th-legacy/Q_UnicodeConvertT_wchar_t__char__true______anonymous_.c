// anon_unknown.dwarf_f5b44::Q_UnicodeConvertT<wchar_t,_char,_true,_(*_{anonymous}::Q_UTF32ToUChar32),_(*_Q_UChar32ToUTF8Len),_(*_Q_UChar32ToUTF8)>  @ 000d0ce0
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */
/* DWARF original name: Q_UnicodeConvertT<wchar_t, char, true, (* {anonymous}::Q_UTF32ToUChar32), (*
   Q_UChar32ToUTF8Len), (* Q_UChar32ToUTF8)> */

int __regparm3
anon_unknown.dwarf_f5b44::
Q_UnicodeConvertT<wchar_t,_char,_true,_(*__anonymous_::Q_UTF32ToUChar32),_(*_Q_UChar32ToUTF8Len),_(*_Q_UChar32ToUTF8)>
          (wchar_t *pIn,int nInChars,char *pOut,int nOutBytes,EStringConvertErrorPolicy ePolicy)

{
  byte *pbVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  char *pcVar7;
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
          pcVar7 = (char *)*pIn;
          if (pcVar7 == (char *)0x0) break;
          if (((pcVar7 + -0xd800 < (char *)0x800) || (MSG_ReadString::string + 0x185f < pcVar7)) ||
             ((0xfffd < (ushort)pcVar7 || (pcVar7 + -0xfdd0 < (char *)0x20)))) {
            iVar8 = iVar8 + 1;
            pIn = pIn + 1;
          }
          else {
            if ((int)pcVar7 < 0x80) {
              iVar5 = 1;
            }
            else {
              iVar5 = 2;
              if (0x7ff < (int)pcVar7) {
                iVar5 = (0xffff < (int)pcVar7) + 3;
              }
            }
            iVar8 = iVar8 + iVar5;
            pIn = pIn + 1;
          }
        }
      }
      else {
        iVar8 = 0;
        while (pcVar7 = (char *)*pIn, pcVar7 != (char *)0x0) {
          if ((((pcVar7 + -0xd800 < (char *)0x800) || (MSG_ReadString::string + 0x185f < pcVar7)) ||
              (0xfffd < (ushort)pcVar7)) || (pcVar7 + -0xfdd0 < (char *)0x20)) {
            DAT_00000000 = 0;
            return 0;
          }
          pIn = pIn + 1;
          if ((int)pcVar7 < 0x80) {
            iVar8 = iVar8 + 1;
          }
          else if ((int)pcVar7 < 0x800) {
            iVar8 = iVar8 + 2;
          }
          else {
            iVar8 = iVar8 + (0xffff < (int)pcVar7) + 3;
          }
        }
      }
    }
    else {
      iVar8 = 0;
      while( true ) {
        pwVar9 = pIn + 1;
        pcVar7 = (char *)*pIn;
        if (pcVar7 == (char *)0x0) break;
        pIn = pwVar9;
        if ((((char *)0x7ff < pcVar7 + -0xd800) && (pcVar7 < MSG_ReadString::string + 0x1860)) &&
           (((ushort)pcVar7 < 0xfffe && ((char *)0x1f < pcVar7 + -0xfdd0)))) {
          if ((int)pcVar7 < 0x80) {
            iVar5 = 1;
          }
          else {
            iVar5 = 2;
            if (0x7ff < (int)pcVar7) {
              iVar5 = (0xffff < (int)pcVar7) + 3;
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
    pcVar7 = (char *)*pIn;
    iVar8 = 0;
    if (pcVar7 != (char *)0x0) {
      iVar8 = 0;
      do {
        pIn = pIn + 1;
        if ((((pcVar7 + -0xd800 < (char *)0x800) || (MSG_ReadString::string + 0x185f < pcVar7)) ||
            (0xfffd < (ushort)pcVar7)) || (pcVar7 + -0xfdd0 < (char *)0x20)) {
          pcVar7 = (char *)0x3f;
          bVar2 = true;
          iVar5 = 1;
        }
        else if ((int)pcVar7 < 0x80) {
          bVar2 = false;
          iVar5 = 1;
        }
        else {
          iVar5 = 2;
          if (0x7ff < (int)pcVar7) {
            iVar5 = (0xffff < (int)pcVar7) + 3;
          }
          bVar2 = false;
        }
        if ((int)pOut <= iVar5 + iVar8) break;
        pbVar1 = (byte *)(nInChars + iVar8);
        bVar6 = (byte)pcVar7;
        if ((int)pcVar7 < 0x80) {
          *pbVar1 = bVar6;
          iVar5 = 1;
        }
        else {
          bVar3 = (byte)((int)pcVar7 >> 6);
          if ((int)pcVar7 < 0x800) {
            *pbVar1 = bVar3 | 0xc0;
            pbVar1[1] = bVar6 & 0x3f | 0x80;
            iVar5 = 2;
          }
          else {
            bVar4 = (byte)((int)pcVar7 >> 0xc);
            if ((int)pcVar7 < 0x10000) {
              *pbVar1 = bVar4 | 0xe0;
              pbVar1[1] = bVar3 & 0x3f | 0x80;
              pbVar1[2] = bVar6 & 0x3f | 0x80;
              iVar5 = 3;
            }
            else {
              *pbVar1 = (byte)((int)pcVar7 >> 0x12) | 0xf0;
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
            if ((0x7f < (int)pcVar7) && (iVar5 = 2, 0x7ff < (int)pcVar7)) {
              iVar5 = (0xffff < (int)pcVar7) + 3;
            }
            iVar8 = iVar8 - iVar5;
          }
        }
        pcVar7 = (char *)*pIn;
      } while (pcVar7 != (char *)0x0);
    }
    *(undefined1 *)(nInChars + iVar8) = 0;
  }
  return iVar8 + 1;
}


