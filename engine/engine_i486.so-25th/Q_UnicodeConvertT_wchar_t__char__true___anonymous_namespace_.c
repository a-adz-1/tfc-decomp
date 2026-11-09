// anon_unknown.dwarf_159333::Q_UnicodeConvertT<wchar_t,_char,_true,_(anonymous_namespace)::Q_UTF32ToUChar32,_Q_UChar32ToUTF8Len,_Q_UChar32ToUTF8>  @ 000bfbe0
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */
/* DWARF original name: Q_UnicodeConvertT<wchar_t, char, true, (anonymous
   namespace)::Q_UTF32ToUChar32, Q_UChar32ToUTF8Len, Q_UChar32ToUTF8> */

int __regparm3
anon_unknown.dwarf_159333::
Q_UnicodeConvertT<wchar_t,_char,_true,_(anonymous_namespace)::Q_UTF32ToUChar32,_Q_UChar32ToUTF8Len,_Q_UChar32ToUTF8>
          (wchar_t *pIn,int nInChars,char *pOut,int nOutBytes,EStringConvertErrorPolicy ePolicy)

{
  int iVar1;
  bool bVar2;
  byte *pbVar3;
  wchar_t *pwVar4;
  byte bVar5;
  char *pcVar6;
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
        for (; pcVar6 = (char *)pwVar4[-1], pcVar6 != (char *)0x0; pwVar4 = pwVar4 + 1) {
          if (((pcVar6 + -0xd800 < (char *)0x800) ||
              (Netchan_OutOfBandPrint::string + 0xf1f < pcVar6)) ||
             ((0xfffd < (ushort)pcVar6 || (pcVar6 + -0xfdd0 < (char *)0x20)))) {
            iVar7 = iVar7 + 1;
          }
          else {
            if ((int)pcVar6 < 0x80) {
              iVar10 = 1;
            }
            else {
              iVar10 = 2;
              if (0x7ff < (int)pcVar6) {
                iVar10 = (0xffff < (int)pcVar6) + 3;
              }
            }
            iVar7 = iVar7 + iVar10;
          }
        }
      }
      else {
        iVar7 = 0;
        while (pcVar6 = (char *)*pIn, pcVar6 != (char *)0x0) {
          if (((pcVar6 + -0xd800 < (char *)0x800) ||
              (Netchan_OutOfBandPrint::string + 0xf1f < pcVar6)) ||
             ((0xfffd < (ushort)pcVar6 || (pcVar6 + -0xfdd0 < (char *)0x20)))) {
            DAT_00000000 = 0;
            return 0;
          }
          pIn = pIn + 1;
          if ((int)pcVar6 < 0x80) {
            iVar7 = iVar7 + 1;
          }
          else if ((int)pcVar6 < 0x800) {
            iVar7 = iVar7 + 2;
          }
          else {
            iVar7 = iVar7 + (0xffff < (int)pcVar6) + 3;
          }
        }
      }
    }
    else {
      for (; pcVar6 = (char *)pwVar4[-1], pcVar6 != (char *)0x0; pwVar4 = pwVar4 + 1) {
        if (((((char *)0x7ff < pcVar6 + -0xd800) &&
             (pcVar6 < Netchan_OutOfBandPrint::string + 0xf20)) && ((ushort)pcVar6 < 0xfffe)) &&
           ((char *)0x1f < pcVar6 + -0xfdd0)) {
          if ((int)pcVar6 < 0x80) {
            iVar10 = 1;
          }
          else {
            iVar10 = 2;
            if (0x7ff < (int)pcVar6) {
              iVar10 = (0xffff < (int)pcVar6) + 3;
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
LAB_000bfc6b:
  iVar10 = iVar7;
  pwVar4 = pIn + 1;
  pcVar6 = (char *)*pIn;
  if (pcVar6 == (char *)0x0) {
LAB_000bfc95:
    local_18 = iVar10 + 1;
    *(undefined1 *)(nInChars + iVar10) = 0;
    return local_18;
  }
  pIn = pwVar4;
  if ((((pcVar6 + -0xd800 < (char *)0x800) || (Netchan_OutOfBandPrint::string + 0xf1f < pcVar6)) ||
      (0xfffd < (ushort)pcVar6)) || (pcVar6 + -0xfdd0 < (char *)0x20)) {
    pcVar6 = (char *)0x3f;
    bVar2 = true;
  }
  else {
    if (0x7f < (int)pcVar6) {
      bVar5 = (byte)pcVar6;
      bVar8 = (byte)((int)pcVar6 >> 6);
      if ((int)pcVar6 < 0x800) {
        if (iVar10 + 2 < (int)pOut) {
          *(byte *)(iVar10 + nInChars) = bVar8 | 0xc0;
          ((byte *)(iVar10 + nInChars))[1] = bVar5 & 0x3f | 0x80;
          iVar7 = iVar10 + 2;
          goto LAB_000bfc6b;
        }
      }
      else {
        bVar9 = (byte)((int)pcVar6 >> 0xc);
        if ((int)pcVar6 < 0x10000) {
          if ((int)pOut <= iVar10 + 3) goto LAB_000bfc95;
          pbVar3 = (byte *)(iVar10 + nInChars);
          *pbVar3 = bVar9 | 0xe0;
          pbVar3[1] = bVar8 & 0x3f | 0x80;
          pbVar3[2] = bVar5 & 0x3f | 0x80;
          iVar7 = iVar10 + 3;
          goto LAB_000bfc6b;
        }
        if (iVar10 + 4 < (int)pOut) {
          pbVar3 = (byte *)(iVar10 + nInChars);
          *pbVar3 = (byte)((int)pcVar6 >> 0x12) | 0xf0;
          pbVar3[1] = bVar9 & 0x3f | 0x80;
          pbVar3[2] = bVar8 & 0x3f | 0x80;
          pbVar3[3] = bVar5 & 0x3f | 0x80;
          iVar7 = iVar10 + 4;
          goto LAB_000bfc6b;
        }
      }
      goto LAB_000bfc95;
    }
    bVar2 = false;
  }
  iVar1 = iVar10 + 1;
  if ((int)pOut <= iVar1) goto LAB_000bfc95;
  *(char *)(nInChars + iVar10) = (char)pcVar6;
  iVar7 = iVar1;
  if (((bVar2) && (iVar7 = iVar10, (nOutBytes & 1U) == 0)) && (iVar7 = iVar1, (nOutBytes & 2U) != 0)
     ) {
    *(undefined1 *)nInChars = 0;
    return 0;
  }
  goto LAB_000bfc6b;
}


