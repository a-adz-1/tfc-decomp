// Q_FileNameCmp  @ 0009e530
int Q_FileNameCmp(char *file1,char *file2)

{
  __int32_t **pp_Var1;
  char cVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  
  pcVar6 = file1 + 1;
  cVar3 = *file1;
  pcVar5 = file2 + 1;
  cVar2 = *file2;
  if (cVar3 == '/') goto LAB_0009e579;
LAB_0009e560:
  pcVar4 = pcVar5;
  pcVar5 = pcVar6;
  if ((cVar3 == '\\') && (cVar2 == '/')) goto LAB_0009e56a;
  pp_Var1 = __ctype_tolower_loc();
  if ((*pp_Var1)[cVar3] == (*pp_Var1)[cVar2]) {
    if (cVar3 == '\0') {
      return 0;
    }
    do {
      if (cVar2 == '\0') {
        return 0;
      }
LAB_0009e56a:
      do {
        pcVar6 = pcVar5 + 1;
        cVar3 = *pcVar5;
        pcVar5 = pcVar4 + 1;
        cVar2 = *pcVar4;
        if (cVar3 != '/') goto LAB_0009e560;
LAB_0009e579:
        pcVar4 = pcVar5;
        pcVar5 = pcVar6;
      } while (cVar2 == '\\');
                    /* Unresolved local var: int __res@[???] */
      pp_Var1 = __ctype_tolower_loc();
                    /* Unresolved local var: int __res@[???] */
    } while ((*pp_Var1)[cVar2] == (*pp_Var1)[0x2f]);
  }
  return -1;
}


// Q_IsDeprecatedW  @ 001c8a50
qboolean Q_IsDeprecatedW(wchar_t wch)

{
                    /* Unresolved local var: qboolean bIsDeprecated@[???] */
  if ((L'\x2029' < wch) && ((wch < L'\x202f' || ((uint)(wch + L'\xffffdf96') < 6)))) {
    return 1;
  }
  return 0;
}


// Q_IsMeanSpaceW  @ 001c89e0
qboolean Q_IsMeanSpaceW(wchar_t wch)

{
                    /* Unresolved local var: qboolean bIsMean@[???] */
  if (wch < L'\x202a') {
    if ((wch < L'\x2028') && (wch != L'͏')) {
      if (wch < L'͐') {
        if (0x20 < (uint)(wch + L'\xffffff80')) {
          return 0;
        }
      }
      else if (0xd < (uint)(wch + L'\xffffe000')) {
        return 0;
      }
    }
  }
  else if (wch != L'\x2060') {
    if (wch < L'⁡') {
      if (wch != L'\x202f') {
        return 0;
      }
    }
    else if ((wch != L'\xfeff') && (wch != L'￼')) {
      return 0;
    }
  }
  return 1;
}


// Q_IsValidUChar32  @ 001c6a40
bool Q_IsValidUChar32(uchar32 uVal)

{
  bool bVar1;
  bool bVar2;
  
  bVar1 = 0x7ff < uVal - 0xd800U;
  bVar2 = (uint)uVal < 0x110000 && bVar1;
  if (((uint)uVal < 0x110000 && bVar1) && (bVar2 = false, (ushort)uVal < 0xfffe)) {
    bVar2 = 0x1f < uVal - 0xfdd0U;
  }
  return bVar2;
}


// Q_StripUnprintableAndSpace  @ 001c8a80
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

qboolean Q_StripUnprintableAndSpace(char *pch)

{
  uint uVar1;
  byte bVar2;
  wchar_t *pwVar3;
  char *pOut;
  wchar_t *__ptr;
  byte *pbVar4;
  wchar_t *pwVar5;
  int iVar6;
  wchar_t *pwVar7;
  wchar_t wVar8;
  uint uVar9;
  int iVar10;
  wchar_t wVar11;
  char *pUTF8_;
  int iVar12;
  bool bVar13;
  uchar32 *in_stack_ffffffb8;
  uint local_34;
  bool local_21;
  uchar32 local_20 [4];
  
                    /* Unresolved local var: int cch@[???]
                       Unresolved local var: int cubDest@[???]
                       Unresolved local var: wchar_t * pwch@[???]
                       Unresolved local var: wchar_t * pwch_alloced@[???]
                       Unresolved local var: bool bStrippedAny@[???]
                       Unresolved local var: bool bStrippedWhitespace@[???]
                       Unresolved local var: int cwch@[???] */
  pOut = (char *)Q_strlen(pch);
  uVar9 = (int)pOut * 4 + 4;
  __ptr = malloc(uVar9);
                    /* Unresolved local var: int nOut@[???] */
  if (__ptr == (wchar_t *)0x0) {
    if (*pch == '\0') {
      uVar9 = 0xfffffffc;
    }
    else {
      iVar6 = 0;
      pUTF8_ = pch;
      do {
        iVar10 = iVar6;
        in_stack_ffffffb8 = local_20;
        local_21 = false;
        iVar6 = Q_UTF8ToUChar32(pUTF8_,in_stack_ffffffb8,&local_21);
        pUTF8_ = pUTF8_ + iVar6;
        iVar6 = iVar10 + 1;
      } while (*pUTF8_ != '\0');
      uVar9 = iVar10 * 4;
    }
  }
  else {
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
    uVar9 = uVar9 >> 2;
    if (uVar9 == 0) {
      uVar9 = 0xfffffff8;
    }
    else {
      if (*pch == '\0') {
        uVar9 = 0xfffffffc;
        iVar12 = 0;
      }
      else {
        pbVar4 = (byte *)pch;
        iVar6 = 0;
        do {
          wVar8 = (wchar_t)*pbVar4;
          if ((uint)wVar8 < 0x80) {
            iVar10 = 1;
          }
          else {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???]
                       Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
            if (((uint)(wVar8 + L'\xffffff40') < 0x38) && ((pbVar4[1] & 0xc0) == 0x80)) {
              wVar8 = wVar8 * 0x40 + -0x3080 + (uint)pbVar4[1];
              if ((wVar8 & 0x800U) == 0) {
                iVar10 = 2;
                wVar11 = L'\x80';
                goto LAB_001c8cc2;
              }
              if ((pbVar4[2] & 0xc0) == 0x80) {
                iVar10 = wVar8 * 0x40 + (uint)pbVar4[2];
                wVar8 = iVar10 + L'\xfffdff80';
                if ((wVar8 & 0x10000U) == 0) {
                  uVar1 = iVar10 - 0x2d880;
                  if ((((uVar1 < 0x400) && (pbVar4[3] == 0xed)) && ((byte)(pbVar4[4] + 0x50) < 0x10)
                      ) && ((pbVar4[5] & 0xc0) == 0x80)) {
                    wVar8 = pbVar4[5] + 0xff80 + (uint)(byte)(pbVar4[4] + 0x50) * 0x40 +
                            uVar1 * 0x400;
                    iVar10 = 6;
                  }
                  else {
                    iVar10 = 3;
                    wVar11 = L'ࠀ';
LAB_001c8cc2:
                    if ((uint)wVar8 < (uint)wVar11) goto LAB_001c8af7;
                  }
                  if (((0x7ff < (uint)(wVar8 + L'\xffff2800')) && ((uint)wVar8 < 0x110000)) &&
                     (((ushort)wVar8 < 0xfffe && (0x1f < (uint)(wVar8 + L'\xffff0230')))))
                  goto joined_r0x001c8b00;
                }
                else {
                  if ((pbVar4[3] & 0xc0) == 0x80) {
                    wVar11 = L'𐀀';
                    wVar8 = wVar8 * 0x40 + -0x400080 + (uint)pbVar4[3];
                    iVar10 = 4;
                    goto LAB_001c8cc2;
                  }
                  iVar10 = 3;
                }
              }
              else {
                iVar10 = 2;
              }
            }
            else {
              iVar10 = 1;
            }
LAB_001c8af7:
            wVar8 = L'?';
          }
joined_r0x001c8b00:
          if ((int)uVar9 <= iVar6 + 1) {
            iVar12 = iVar6 << 2;
            uVar9 = (iVar6 + 1) * 4 - 8;
            goto LAB_001c8b35;
          }
          iVar12 = iVar6 + 1;
          pbVar4 = pbVar4 + iVar10;
          bVar2 = *pbVar4;
          __ptr[iVar6] = wVar8;
          iVar6 = iVar12;
        } while (bVar2 != 0);
        iVar12 = iVar12 * 4;
        uVar9 = iVar12 - 4;
      }
LAB_001c8b35:
      *(undefined4 *)((int)__ptr + iVar12) = 0;
    }
  }
                    /* Unresolved local var: wchar_t * pwchSource@[???]
                       Unresolved local var: wchar_t * pwchDest@[???] */
  wVar8 = *__ptr;
  pwVar7 = __ptr;
  pwVar5 = __ptr;
  if (wVar8 == L'\0') {
    bVar13 = false;
    local_34 = 0;
  }
  else {
    do {
                    /* Unresolved local var: qboolean bIsDeprecated@[???] */
      if ((L'\x1f' < wVar8) &&
         (((wVar8 < L'\x202a' || ((L'\x202e' < wVar8 && (5 < (uint)(wVar8 + L'\xffffdf96'))))) &&
          (wVar8 != L'\x85')))) {
        *pwVar7 = wVar8;
        pwVar7 = pwVar7 + 1;
      }
      pwVar5 = pwVar5 + 1;
      wVar8 = *pwVar5;
    } while (wVar8 != L'\0');
    bVar13 = pwVar5 != pwVar7;
    local_34 = (uint)bVar13;
  }
                    /* Unresolved local var: wchar_t * pwchEnd@[???] */
  pwVar5 = (wchar_t *)(uVar9 + (int)__ptr);
  *pwVar7 = L'\0';
  pwVar7 = __ptr;
  if (CARRY4(uVar9,(uint)__ptr)) {
LAB_001c8c62:
    if (!bVar13) goto LAB_001c8c6d;
  }
  else {
    bVar2 = 0;
    do {
      while( true ) {
        wVar8 = *pwVar5;
        iVar6 = iswspace(wVar8);
        if (iVar6 == 0) break;
LAB_001c8d90:
        *pwVar5 = L'\0';
joined_r0x001c8d9e:
        bVar2 = 1;
        pwVar5 = pwVar5 + -1;
        if (pwVar5 < __ptr) goto LAB_001c8da6;
      }
                    /* Unresolved local var: qboolean bIsMean@[???] */
      if (L'\x2029' < wVar8) {
        if (wVar8 == L'\x2060') goto LAB_001c8d90;
        if (wVar8 < L'⁡') {
          if (wVar8 == L'\x202f') {
            *pwVar5 = L'\0';
            goto joined_r0x001c8d9e;
          }
        }
        else if ((wVar8 == L'\xfeff') || (wVar8 == L'￼')) goto LAB_001c8d90;
        goto LAB_001c8bf9;
      }
      if ((L'‧' < wVar8) || (wVar8 == L'͏')) goto LAB_001c8d90;
      if (wVar8 < L'͐') {
        if ((uint)(wVar8 + L'\xffffff80') < 0x21) goto LAB_001c8d90;
LAB_001c8bf9:
        pwVar3 = __ptr;
        if (__ptr < pwVar5) goto LAB_001c8c10;
        bVar13 = (bool)(bVar13 | bVar2);
        goto LAB_001c8c62;
      }
      if (0xd < (uint)(wVar8 + L'\xffffe000')) goto LAB_001c8bf9;
      *pwVar5 = L'\0';
      pwVar5 = pwVar5 + -1;
      bVar2 = 1;
    } while (__ptr <= pwVar5);
  }
  goto LAB_001c8da6;
LAB_001c8c10:
  do {
    pwVar7 = pwVar3;
    wVar8 = *pwVar7;
    iVar6 = iswspace(wVar8);
    if (iVar6 == 0) {
                    /* Unresolved local var: qboolean bIsMean@[???] */
      if (wVar8 < L'\x202a') {
        if ((wVar8 < L'\x2028') && (wVar8 != L'͏')) {
          if (wVar8 < L'͐') {
            if (0x20 < (uint)(wVar8 + L'\xffffff80')) goto LAB_001c8c58;
          }
          else if (0xd < (uint)(wVar8 + L'\xffffe000')) goto LAB_001c8c58;
        }
      }
      else if (wVar8 != L'\x2060') {
        if (wVar8 < L'⁡') {
          if (wVar8 != L'\x202f') goto LAB_001c8c58;
        }
        else if ((wVar8 != L'\xfeff') && (wVar8 != L'￼')) {
LAB_001c8c58:
          bVar13 = (bool)(bVar13 | bVar2);
          goto LAB_001c8c62;
        }
      }
    }
    bVar2 = 1;
    pwVar3 = pwVar7 + 1;
  } while (pwVar7 + 1 < pwVar5);
  pwVar7 = pwVar7 + 1;
LAB_001c8da6:
  anon_unknown.dwarf_2ec073::
  Q_UnicodeConvertT<wchar_t,_char,_true,_(anonymous_namespace)::Q_UTF32ToUChar32,_Q_UChar32ToUTF8Len,_Q_UChar32ToUTF8>
            (pwVar7,(int)pch,pOut,4,(EStringConvertErrorPolicy)in_stack_ffffffb8);
LAB_001c8c6d:
  free(__ptr);
  return local_34;
}


// Q_UChar32ToUTF16  @ 001c6ac0
int Q_UChar32ToUTF16(uchar32 uVal,uchar16 *pUTF16Out)

{
  if (0xffff < uVal) {
    pUTF16Out[1] = (ushort)(uVal + -0x10000) & 0x3ff | 0xdc00;
    *pUTF16Out = (ushort)(uVal + -0x10000 >> 10) | 0xd800;
    return 2;
  }
  *pUTF16Out = (uchar16)uVal;
  return 1;
}


// Q_UChar32ToUTF16Len  @ 001c6ab0
int Q_UChar32ToUTF16Len(uchar32 uVal)

{
  return (0xffff < uVal) + 1;
}


// Q_UChar32ToUTF8  @ 001c6b10
int Q_UChar32ToUTF8(uchar32 uVal,char *pUTF8Out)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  
  bVar1 = (byte)uVal;
  if (uVal < 0x80) {
    *pUTF8Out = bVar1;
    return 1;
  }
  bVar2 = (byte)(uVal >> 6);
  if (uVal < 0x800) {
    pUTF8Out[1] = bVar1 & 0x3f | 0x80;
    *pUTF8Out = bVar2 | 0xc0;
    return 2;
  }
  bVar3 = (byte)(uVal >> 0xc);
  if (uVal < 0x10000) {
    *pUTF8Out = bVar3 | 0xe0;
    pUTF8Out[2] = bVar1 & 0x3f | 0x80;
    pUTF8Out[1] = bVar2 & 0x3f | 0x80;
    return 3;
  }
  *pUTF8Out = (byte)(uVal >> 0x12) & 7 | 0xf0;
  pUTF8Out[1] = bVar3 & 0x3f | 0x80;
  pUTF8Out[3] = bVar1 & 0x3f | 0x80;
  pUTF8Out[2] = bVar2 & 0x3f | 0x80;
  return 4;
}


// Q_UChar32ToUTF8Len  @ 001c6a80
int Q_UChar32ToUTF8Len(uchar32 uVal)

{
  int iVar1;
  
  iVar1 = 1;
  if ((0x7f < uVal) && (iVar1 = 2, 0x7ff < uVal)) {
    return (0xffff < uVal) + 3;
  }
  return iVar1;
}


// Q_UTF16ToUChar32  @ 001c6bc0
int Q_UTF16ToUChar32(uchar16 *pUTF16,uchar32 *uValueOut,bool *bErrorOut)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)*pUTF16;
  uVar1 = uVar3 - 0xd800;
  if ((uVar1 < 0x800) || (0xfffd < uVar3)) {
    if ((uVar1 < 0x400) && (pUTF16[1] - 0xdc00 < 0x400)) {
                    /* Unresolved local var: uchar32 uVal@[???] */
      iVar2 = pUTF16[1] + 0x2400 + uVar1 * 0x400;
      if ((ushort)iVar2 < 0xfffe) {
        *uValueOut = iVar2;
        *bErrorOut = false;
        return 2;
      }
      *uValueOut = 0x3f;
      *bErrorOut = true;
      return 2;
    }
  }
  else if (0x1f < uVar3 - 0xfdd0) {
    *uValueOut = uVar3;
    *bErrorOut = false;
    return 1;
  }
  *uValueOut = 0x3f;
  *bErrorOut = true;
  return 1;
}


// Q_UTF16ToUTF32  @ 001c7a80
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF16ToUTF32(uchar16 *pUTF16,uchar32 *pUTF32,int cubDestSizeInBytes,
                  EStringConvertErrorPolicy ePolicy)

{
  ushort *puVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF32 == (uchar32 *)0x0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
      iVar7 = 1;
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
        while (uVar8 = (uint)*pUTF16, uVar8 != 0) {
          if ((((uVar8 < 0xfffe) && (0x7ff < uVar8 - 0xd800)) || (0x3ff < uVar8 - 0xd800)) ||
             (0x3ff < pUTF16[1] - 0xdc00)) {
            pUTF16 = pUTF16 + 1;
            iVar7 = iVar7 + 1;
          }
          else {
            pUTF16 = pUTF16 + 2;
            iVar7 = iVar7 + 1;
          }
        }
      }
      else {
        while (uVar8 = (uint)*pUTF16, uVar8 != 0) {
          while ((uVar9 = uVar8 - 0xd800, 0x7ff < uVar9 && (uVar8 < 0xfffe))) {
            if (uVar8 - 0xfdd0 < 0x20) goto LAB_001c7dd0;
            pUTF16 = pUTF16 + 1;
            uVar8 = (uint)*pUTF16;
            iVar7 = iVar7 + 1;
            if (uVar8 == 0) goto LAB_001c7b37;
          }
          if ((uVar9 < 0x400) && (puVar1 = pUTF16 + 1, *puVar1 - 0xdc00 < 0x400)) {
            pUTF16 = pUTF16 + 2;
            iVar7 = iVar7 + (uint)((*puVar1 + 0x2400 + uVar9 * 0x400 & 0xffff) < 0xfffe);
          }
          else {
LAB_001c7dd0:
            pUTF16 = pUTF16 + 1;
          }
        }
      }
    }
    else if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
      iVar7 = 1;
      while (uVar8 = (uint)*pUTF16, uVar8 != 0) {
        uVar9 = uVar8 - 0xd800;
        if ((uVar9 < 0x800) || (0xfffd < uVar8)) {
          if (0x3ff < uVar9) {
            _DAT_00000000 = 0;
            return 0;
          }
          puVar1 = pUTF16 + 1;
          if (0x3ff < *puVar1 - 0xdc00) {
            _DAT_00000000 = 0;
            return 0;
          }
          pUTF16 = pUTF16 + 2;
          if (0xfffd < (ushort)(*puVar1 + 0x2400 + (short)uVar9 * 0x400)) {
            _DAT_00000000 = 0;
            return 0;
          }
        }
        else {
          if (uVar8 - 0xfdd0 < 0x20) {
            _DAT_00000000 = 0;
            return 0;
          }
          pUTF16 = pUTF16 + 1;
        }
        iVar7 = iVar7 + 1;
      }
    }
    else {
      iVar7 = 1;
      while (uVar8 = (uint)*pUTF16, uVar8 != 0) {
        while ((uVar9 = uVar8 - 0xd800, uVar8 < 0xfffe && (0x7ff < uVar9))) {
          if (uVar8 - 0xfdd0 < 0x20) goto LAB_001c7f75;
          pUTF16 = pUTF16 + 1;
          uVar8 = (uint)*pUTF16;
          iVar7 = iVar7 + 1;
          if (uVar8 == 0) goto LAB_001c7b37;
        }
        if ((uVar9 < 0x400) && (puVar1 = pUTF16 + 1, *puVar1 - 0xdc00 < 0x400)) {
          pUTF16 = pUTF16 + 2;
          iVar7 = iVar7 + (uint)((*puVar1 + 0x2400 + uVar9 * 0x400 & 0xffff) < 0xfffe);
        }
        else {
LAB_001c7f75:
          pUTF16 = pUTF16 + 1;
        }
      }
    }
    goto LAB_001c7b37;
  }
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
  uVar8 = (uint)cubDestSizeInBytes >> 2;
  if (uVar8 == 0) {
    return 0;
  }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
  iVar5 = 0;
  if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
    if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
      for (; uVar9 = (uint)*pUTF16, uVar9 != 0; pUTF16 = (uchar16 *)((int)pUTF16 + iVar4)) {
        uVar2 = uVar9 - 0xd800;
        if ((uVar2 < 0x800) || (0xfffd < uVar9)) {
          if ((0x3ff < uVar2) || (0x3ff < pUTF16[1] - 0xdc00)) {
            uVar9 = 0x3f;
            goto LAB_001c7b5d;
          }
                    /* Unresolved local var: uchar32 uVal@[???] */
          uVar9 = pUTF16[1] + 0x2400 + uVar2 * 0x400;
          if (0xfffd < (ushort)uVar9) {
            uVar9 = 0x3f;
          }
          iVar4 = 4;
        }
        else {
          if (uVar9 - 0xfdd0 < 0x20) {
            uVar9 = 0x3f;
          }
LAB_001c7b5d:
          iVar4 = 2;
        }
        iVar7 = iVar5 + 1;
        if ((int)uVar8 <= iVar5 + 1) goto LAB_001c7b30;
        pUTF32[iVar5] = uVar9;
        iVar5 = iVar5 + 1;
      }
LAB_001c7cc0:
      iVar7 = iVar5 + 1;
    }
    else {
      iVar4 = 1;
      while (uVar9 = (uint)*pUTF16, iVar7 = iVar4, uVar9 != 0) {
LAB_001c7ad7:
        iVar4 = iVar7;
        uVar2 = uVar9 - 0xd800;
        iVar7 = iVar4;
        if ((0x7ff < uVar2) && (uVar9 < 0xfffe)) {
          iVar6 = 2;
          if (uVar9 - 0xfdd0 < 0x20) goto LAB_001c7c30;
LAB_001c7b09:
          pUTF16 = (uchar16 *)((int)pUTF16 + iVar6);
          if ((int)uVar8 <= iVar4) break;
          pUTF32[iVar5] = uVar9;
          uVar9 = (uint)*pUTF16;
          iVar7 = iVar4 + 1;
          iVar5 = iVar4;
          if (uVar9 == 0) break;
          goto LAB_001c7ad7;
        }
        if ((uVar2 < 0x400) && (pUTF16[1] - 0xdc00 < 0x400)) {
          uVar9 = pUTF16[1] + 0x2400 + uVar2 * 0x400;
          iVar6 = 4;
          if (0xfffd < (ushort)uVar9) goto LAB_001c7c30;
          goto LAB_001c7b09;
        }
        iVar6 = 2;
LAB_001c7c30:
        pUTF16 = (uchar16 *)((int)pUTF16 + iVar6);
        if ((int)uVar8 <= iVar4) break;
        pUTF32[iVar5] = 0x3f;
      }
    }
  }
  else {
    if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
      uVar3 = *pUTF16;
      while (uVar9 = (uint)uVar3, uVar9 != 0) {
        uVar2 = uVar9 - 0xd800;
        if ((uVar2 < 0x800) || (0xfffd < uVar9)) {
          if ((0x3ff < uVar2) ||
             ((0x3ff < pUTF16[1] - 0xdc00 ||
              (uVar9 = pUTF16[1] + 0x2400 + uVar2 * 0x400, 0xfffd < (ushort)uVar9))))
          goto LAB_001c7ed8;
          iVar7 = 4;
        }
        else {
          if (uVar9 - 0xfdd0 < 0x20) {
LAB_001c7ed8:
            iVar7 = iVar5 + 1;
            if (iVar7 < (int)uVar8) {
              pUTF32[iVar5] = 0x3f;
              *pUTF32 = 0;
              return 0;
            }
            goto LAB_001c7b30;
          }
          iVar7 = 2;
        }
        pUTF16 = (uchar16 *)((int)pUTF16 + iVar7);
        iVar7 = iVar5 + 1;
        if ((int)uVar8 <= iVar7) goto LAB_001c7b30;
        pUTF32[iVar5] = uVar9;
        iVar5 = iVar7;
        uVar3 = *pUTF16;
      }
      goto LAB_001c7cc0;
    }
    iVar4 = 1;
    while (uVar9 = (uint)*pUTF16, iVar7 = iVar4, uVar9 != 0) {
LAB_001c7dfb:
      iVar4 = iVar7;
      uVar2 = uVar9 - 0xd800;
      iVar7 = iVar4;
      if ((0x7ff < uVar2) && (uVar9 < 0xfffe)) {
        iVar6 = 2;
        if (uVar9 - 0xfdd0 < 0x20) goto LAB_001c7e70;
LAB_001c7e21:
        pUTF16 = (uchar16 *)((int)pUTF16 + iVar6);
        if ((int)uVar8 <= iVar4) break;
        pUTF32[iVar5] = uVar9;
        uVar9 = (uint)*pUTF16;
        iVar7 = iVar4 + 1;
        iVar5 = iVar4;
        if (uVar9 == 0) break;
        goto LAB_001c7dfb;
      }
      if ((uVar2 < 0x400) && (pUTF16[1] - 0xdc00 < 0x400)) {
        uVar9 = pUTF16[1] + 0x2400 + uVar2 * 0x400;
        iVar6 = 4;
        if (0xfffd < (ushort)uVar9) goto LAB_001c7e70;
        goto LAB_001c7e21;
      }
      iVar6 = 2;
LAB_001c7e70:
      pUTF16 = (uchar16 *)((int)pUTF16 + iVar6);
      if ((int)uVar8 <= iVar4) break;
      pUTF32[iVar5] = 0x3f;
    }
  }
LAB_001c7b30:
  pUTF32[iVar5] = 0;
LAB_001c7b37:
  return iVar7 << 2;
}


// Q_UTF16ToUTF8  @ 001c7580
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF16ToUTF8(uchar16 *pUTF16,char *pUTF8,int cubDestSizeInBytes,
                 EStringConvertErrorPolicy ePolicy)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  byte bVar10;
  ushort *puVar11;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF8 == (char *)0x0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar9 = 0;
    if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
        while (uVar8 = (uint)*pUTF16, uVar8 != 0) {
          uVar1 = uVar8 - 0xd800;
          if ((uVar1 < 0x800) || (0xfffd < uVar8)) {
            if ((0x3ff < uVar1) || (puVar11 = pUTF16 + 1, 0x3ff < *puVar11 - 0xdc00))
            goto LAB_001c78f0;
            pUTF16 = pUTF16 + 2;
            uVar8 = *puVar11 + 0x2400 + uVar1 * 0x400;
            if ((ushort)uVar8 < 0xfffe) goto LAB_001c77d3;
LAB_001c78e1:
            iVar9 = iVar9 + 1;
          }
          else if (uVar8 - 0xfdd0 < 0x20) {
LAB_001c78f0:
            pUTF16 = pUTF16 + 1;
            iVar9 = iVar9 + 1;
          }
          else {
            pUTF16 = pUTF16 + 1;
            if (uVar8 < 0x80) goto LAB_001c78e1;
LAB_001c77d3:
            if ((int)uVar8 < 0x800) {
              iVar9 = iVar9 + 2;
            }
            else {
              iVar9 = iVar9 + (0xffff < (int)uVar8) + 3;
            }
          }
        }
      }
      else {
        while (uVar8 = (uint)*pUTF16, uVar8 != 0) {
          uVar1 = uVar8 - 0xd800;
          if ((uVar1 < 0x800) || (0xfffd < uVar8)) {
            if ((0x3ff < uVar1) || (puVar11 = pUTF16 + 1, 0x3ff < *puVar11 - 0xdc00))
            goto LAB_001c7900;
                    /* Unresolved local var: uchar32 uVal@[???] */
            pUTF16 = pUTF16 + 2;
            uVar8 = *puVar11 + 0x2400 + uVar1 * 0x400;
            if ((ushort)uVar8 < 0xfffe) {
LAB_001c786b:
              if ((int)uVar8 < 0x800) {
                iVar9 = iVar9 + 2;
              }
              else {
                iVar9 = iVar9 + (0xffff < (int)uVar8) + 3;
              }
            }
          }
          else if (uVar8 - 0xfdd0 < 0x20) {
LAB_001c7900:
            pUTF16 = pUTF16 + 1;
          }
          else {
            pUTF16 = pUTF16 + 1;
            if (0x7f < uVar8) goto LAB_001c786b;
            iVar9 = iVar9 + 1;
          }
        }
      }
    }
    else if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
LAB_001c791f:
      uVar8 = (uint)*pUTF16;
      if (uVar8 != 0) {
        uVar1 = uVar8 - 0xd800;
        if ((uVar1 < 0x800) || (0xfffd < uVar8)) {
          if (0x3ff < uVar1) {
            DAT_00000000 = 0;
            return 0;
          }
          if (0x3ff < pUTF16[1] - 0xdc00) {
            DAT_00000000 = 0;
            return 0;
          }
          uVar8 = pUTF16[1] + 0x2400 + uVar1 * 0x400;
          if (0xfffd < (ushort)uVar8) {
            DAT_00000000 = 0;
            return 0;
          }
          pUTF16 = pUTF16 + 2;
        }
        else {
          if (uVar8 - 0xfdd0 < 0x20) {
            DAT_00000000 = 0;
            return 0;
          }
          pUTF16 = pUTF16 + 1;
          if (uVar8 < 0x80) {
            iVar9 = iVar9 + 1;
            goto LAB_001c791f;
          }
        }
        if ((int)uVar8 < 0x800) {
          iVar9 = iVar9 + 2;
        }
        else {
          iVar9 = iVar9 + (0xffff < (int)uVar8) + 3;
        }
        goto LAB_001c791f;
      }
    }
    else {
      while (uVar8 = (uint)*pUTF16, uVar8 != 0) {
        uVar1 = uVar8 - 0xd800;
        if ((uVar1 < 0x800) || (0xfffd < uVar8)) {
          if ((0x3ff < uVar1) || (0x3ff < pUTF16[1] - 0xdc00)) goto LAB_001c7a47;
          uVar8 = pUTF16[1] + 0x2400 + uVar1 * 0x400;
          if ((ushort)uVar8 < 0xfffe) {
            pUTF16 = pUTF16 + 2;
            goto LAB_001c79a4;
          }
          pUTF16 = pUTF16 + 2;
        }
        else if (uVar8 - 0xfdd0 < 0x20) {
LAB_001c7a47:
          pUTF16 = pUTF16 + 1;
        }
        else {
          pUTF16 = pUTF16 + 1;
          if (uVar8 < 0x80) {
            iVar9 = iVar9 + 1;
          }
          else {
LAB_001c79a4:
            if ((int)uVar8 < 0x800) {
              iVar9 = iVar9 + 2;
            }
            else {
              iVar9 = iVar9 + (0xffff < (int)uVar8) + 3;
            }
          }
        }
      }
    }
    return iVar9 + 1;
  }
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
  if (cubDestSizeInBytes < 1) {
    return 0;
  }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
  iVar9 = 0;
LAB_001c75c0:
  uVar8 = (uint)*pUTF16;
  iVar4 = iVar9;
  puVar11 = pUTF16;
  if (uVar8 != 0) {
    do {
      uVar1 = uVar8 - 0xd800;
      if ((uVar1 < 0x800) || (0xfffd < uVar8)) {
        if ((0x3ff < uVar1) || (0x3ff < puVar11[1] - 0xdc00)) goto LAB_001c76a0;
                    /* Unresolved local var: uchar32 uVal@[???] */
        pUTF16 = puVar11 + 2;
        uVar8 = puVar11[1] + 0x2400 + uVar1 * 0x400;
        if ((ushort)uVar8 < 0xfffe) goto LAB_001c75f7;
        iVar9 = iVar4 + 1;
        if (cubDestSizeInBytes <= iVar9) goto LAB_001c762b;
        cVar7 = '?';
        bVar2 = true;
LAB_001c7680:
        pUTF8[iVar4] = cVar7;
        iVar9 = iVar4 + 1;
        if (((bVar2) && (iVar9 = iVar4, (ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE)) &&
           (iVar9 = iVar4 + 1, (ePolicy & STRINGCONVERT_FAIL) != STRINGCONVERT_REPLACE)) {
          *pUTF8 = '\0';
          return 0;
        }
        goto LAB_001c75c0;
      }
      if (uVar8 - 0xfdd0 < 0x20) {
LAB_001c76a0:
        uVar8 = 0x3f;
        bVar2 = true;
LAB_001c76ad:
        pUTF16 = puVar11 + 1;
        cVar7 = (char)uVar8;
        iVar9 = iVar4 + 1;
        if (iVar9 < cubDestSizeInBytes) goto LAB_001c7680;
        goto LAB_001c762b;
      }
      pUTF16 = puVar11 + 1;
      if (uVar8 < 0x80) {
        bVar2 = false;
        goto LAB_001c76ad;
      }
LAB_001c75f7:
      bVar6 = (byte)uVar8;
      bVar10 = (byte)((int)uVar8 >> 6);
      if (0x7ff < (int)uVar8) goto LAB_001c76e0;
      iVar9 = iVar4 + 2;
      if (cubDestSizeInBytes <= iVar9) break;
      pUTF8[iVar4] = bVar10 | 0xc0;
      (pUTF8 + iVar4)[1] = bVar6 & 0x3f | 0x80;
      uVar8 = (uint)*pUTF16;
      iVar4 = iVar9;
      puVar11 = pUTF16;
      if (uVar8 == 0) break;
    } while( true );
  }
  goto LAB_001c7628;
LAB_001c76e0:
  bVar3 = (byte)((int)uVar8 >> 0xc);
  if ((int)uVar8 < 0x10000) {
    if (iVar4 + 3 < cubDestSizeInBytes) {
      pbVar5 = (byte *)(pUTF8 + iVar4);
      *pbVar5 = bVar3 | 0xe0;
      pbVar5[1] = bVar10 & 0x3f | 0x80;
      pbVar5[2] = bVar6 & 0x3f | 0x80;
      iVar9 = iVar4 + 3;
      goto LAB_001c75c0;
    }
  }
  else if (iVar4 + 4 < cubDestSizeInBytes) {
    pbVar5 = (byte *)(pUTF8 + iVar4);
    *pbVar5 = (byte)((int)uVar8 >> 0x12) | 0xf0;
    pbVar5[1] = bVar3 & 0x3f | 0x80;
    pbVar5[2] = bVar10 & 0x3f | 0x80;
    pbVar5[3] = bVar6 & 0x3f | 0x80;
    iVar9 = iVar4 + 4;
    goto LAB_001c75c0;
  }
LAB_001c7628:
  iVar9 = iVar4 + 1;
LAB_001c762b:
  pUTF8[iVar4] = '\0';
  return iVar9;
}


// Q_UTF32ToUTF16  @ 001c8010
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF32ToUTF16(uchar32 *pUTF32,uchar16 *pUTF16,int cubDestSizeInBytes,
                  EStringConvertErrorPolicy ePolicy)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF16 == (uchar16 *)0x0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
      iVar5 = 0;
      if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
        while( true ) {
          uVar6 = *pUTF32;
          if (uVar6 == 0) break;
          if ((((uVar6 - 0xd800 < 0x800) || (0x10ffff < uVar6)) || (0xfffd < (ushort)uVar6)) ||
             ((uVar6 - 0xfdd0 < 0x20 || ((int)uVar6 < 0x10000)))) {
            iVar5 = iVar5 + 1;
            pUTF32 = pUTF32 + 1;
          }
          else {
            iVar5 = iVar5 + 2;
            pUTF32 = pUTF32 + 1;
          }
        }
      }
      else {
        iVar5 = 0;
        while (uVar6 = *pUTF32, uVar6 != 0) {
          while( true ) {
            if (((uVar6 - 0xd800 < 0x800) || (0x10ffff < uVar6)) ||
               ((0xfffd < (ushort)uVar6 || (uVar6 - 0xfdd0 < 0x20)))) {
              _DAT_00000000 = 0;
              return 0;
            }
            pUTF32 = pUTF32 + 1;
            if ((int)uVar6 < 0x10000) break;
            iVar5 = iVar5 + 2;
            uVar6 = *pUTF32;
            if (uVar6 == 0) goto LAB_001c8200;
          }
          iVar5 = iVar5 + 1;
        }
      }
    }
    else {
      iVar5 = 0;
      while( true ) {
        puVar7 = (uint *)(pUTF32 + 1);
        uVar6 = *pUTF32;
        if (uVar6 == 0) break;
        pUTF32 = (uchar32 *)puVar7;
        if ((((0x7ff < uVar6 - 0xd800) && (uVar6 < 0x110000)) && ((ushort)uVar6 < 0xfffe)) &&
           (0x1f < uVar6 - 0xfdd0)) {
          if ((int)uVar6 < 0x10000) {
            iVar5 = iVar5 + 1;
          }
          else {
            iVar5 = iVar5 + 2;
          }
        }
      }
    }
LAB_001c8200:
    iVar5 = iVar5 + 1;
  }
  else {
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
    uVar6 = (uint)cubDestSizeInBytes >> 1;
    if (uVar6 == 0) {
      return 0;
    }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
      puVar7 = (uint *)(pUTF32 + 1);
      iVar4 = 0;
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
        uVar3 = *pUTF32;
        while (uVar3 != 0) {
          if (((uVar3 - 0xd800 < 0x800) || (0x10ffff < uVar3)) ||
             ((0xfffd < (ushort)uVar3 || (uVar3 - 0xfdd0 < 0x20)))) {
            uVar3 = 0x3f;
LAB_001c80e8:
            iVar5 = iVar4 + 1;
            if ((int)uVar6 <= iVar5) goto LAB_001c8063;
            uVar2 = (ushort)uVar3;
          }
          else {
            if ((int)uVar3 < 0x10000) goto LAB_001c80e8;
            iVar5 = iVar4 + 2;
            if ((int)uVar6 <= iVar5) break;
            uVar2 = (ushort)((int)(uVar3 - 0x10000) >> 10) | 0xd800;
            (pUTF16 + iVar4)[1] = (ushort)(uVar3 - 0x10000) & 0x3ff | 0xdc00;
          }
          pUTF16[iVar4] = uVar2;
          uVar3 = *puVar7;
          iVar4 = iVar5;
          puVar7 = puVar7 + 1;
        }
      }
      else {
        for (; uVar3 = puVar7[-1], uVar3 != 0; puVar7 = puVar7 + 1) {
          if ((((uVar3 - 0xd800 < 0x800) || (0x10ffff < uVar3)) || (0xfffd < (ushort)uVar3)) ||
             (uVar3 - 0xfdd0 < 0x20)) {
            uVar3 = 0x3f;
            bVar1 = true;
LAB_001c817b:
            iVar5 = iVar4 + 1;
            if ((int)uVar6 <= iVar5) goto LAB_001c8063;
            pUTF16[iVar4] = (uchar16)uVar3;
            if (bVar1) {
              iVar5 = iVar4;
            }
          }
          else {
            if ((int)uVar3 < 0x10000) {
              bVar1 = false;
              goto LAB_001c817b;
            }
            if ((int)uVar6 <= iVar4 + 2) break;
            (pUTF16 + iVar4)[1] = (ushort)(uVar3 - 0x10000) & 0x3ff | 0xdc00;
            pUTF16[iVar4] = (ushort)((int)(uVar3 - 0x10000) >> 10) | 0xd800;
            iVar5 = iVar4 + 2;
          }
          iVar4 = iVar5;
        }
      }
    }
    else {
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
        iVar5 = 0;
        do {
          uVar3 = *pUTF32;
          iVar4 = iVar5;
          while( true ) {
            if (uVar3 == 0) goto LAB_001c8060;
            pUTF32 = pUTF32 + 1;
            if (((uVar3 - 0xd800 < 0x800) || (0x10ffff < uVar3)) ||
               ((0xfffd < (ushort)uVar3 || (uVar3 - 0xfdd0 < 0x20)))) {
              uVar3 = 0x3f;
              bVar1 = true;
              goto LAB_001c83a7;
            }
            if ((int)uVar3 < 0x10000) break;
            if ((int)uVar6 <= iVar4 + 2) goto LAB_001c8060;
            (pUTF16 + iVar4)[1] = (ushort)(uVar3 - 0x10000) & 0x3ff | 0xdc00;
            pUTF16[iVar4] = (ushort)((int)(uVar3 - 0x10000) >> 10) | 0xd800;
            uVar3 = *pUTF32;
            iVar4 = iVar4 + 2;
          }
          bVar1 = false;
LAB_001c83a7:
          iVar5 = iVar4 + 1;
          if ((int)uVar6 <= iVar5) goto LAB_001c8063;
          pUTF16[iVar4] = (uchar16)uVar3;
          if (bVar1) {
            *pUTF16 = 0;
            return 0;
          }
        } while( true );
      }
      iVar5 = 0;
      while( true ) {
        iVar4 = iVar5;
        puVar7 = (uint *)(pUTF32 + 1);
        uVar3 = *pUTF32;
        if (uVar3 == 0) break;
        pUTF32 = (uchar32 *)puVar7;
        if (((uVar3 - 0xd800 < 0x800) || (0x10ffff < uVar3)) ||
           ((0xfffd < (ushort)uVar3 || (uVar3 - 0xfdd0 < 0x20)))) {
          uVar3 = 0x3f;
          bVar1 = true;
LAB_001c82fb:
          iVar5 = iVar4 + 1;
          if ((int)uVar6 <= iVar5) goto LAB_001c8063;
          pUTF16[iVar4] = (uchar16)uVar3;
          if (bVar1) {
            iVar5 = iVar4;
          }
        }
        else {
          if ((int)uVar3 < 0x10000) {
            bVar1 = false;
            goto LAB_001c82fb;
          }
          if ((int)uVar6 <= iVar4 + 2) break;
          (pUTF16 + iVar4)[1] = (ushort)(uVar3 - 0x10000) & 0x3ff | 0xdc00;
          pUTF16[iVar4] = (ushort)((int)(uVar3 - 0x10000) >> 10) | 0xd800;
          iVar5 = iVar4 + 2;
        }
      }
    }
LAB_001c8060:
    iVar5 = iVar4 + 1;
LAB_001c8063:
    pUTF16[iVar4] = 0;
  }
  return iVar5 * 2;
}


// Q_UTF32ToUTF8  @ 001c7ff0
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF32ToUTF8(uchar32 *pUTF32,char *pUTF8,int cubDestSizeInBytes,
                 EStringConvertErrorPolicy ePolicy)

{
  int iVar1;
  
  iVar1 = anon_unknown.dwarf_2ec073::
          Q_UnicodeConvertT<wchar_t,_char,_true,_(anonymous_namespace)::Q_UTF32ToUChar32,_Q_UChar32ToUTF8Len,_Q_UChar32ToUTF8>
                    (pUTF32,(int)pUTF8,(char *)cubDestSizeInBytes,ePolicy,
                     (EStringConvertErrorPolicy)pUTF8);
  return iVar1;
}


// Q_UTF8ToUChar32  @ 001c8460
int Q_UTF8ToUChar32(char *pUTF8_,uchar32 *uValueOut,bool *bErrorOut)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
  uVar3 = (uint)(byte)*pUTF8_;
  if (uVar3 < 0x80) {
    iVar1 = 1;
    goto LAB_001c84d5;
  }
  if (0x37 < uVar3 - 0xc0) {
    iVar1 = 1;
    goto LAB_001c849a;
  }
  iVar1 = 1;
  if ((pUTF8_[1] & 0xc0U) != 0x80) goto LAB_001c849a;
  uVar3 = uVar3 * 0x40 + -0x3080 + (uint)(byte)pUTF8_[1];
  if ((uVar3 & 0x800) == 0) {
    uVar2 = 0x80;
    iVar1 = 2;
    goto LAB_001c856a;
  }
  iVar1 = 2;
  if ((pUTF8_[2] & 0xc0U) != 0x80) goto LAB_001c849a;
  iVar1 = (uint)(byte)pUTF8_[2] + uVar3 * 0x40;
  uVar3 = iVar1 - 0x20080;
  if ((uVar3 & 0x10000) == 0) {
    uVar2 = iVar1 - 0x2d880;
    if ((((0x3ff < uVar2) || (pUTF8_[3] != -0x13)) || (0xf < (byte)(pUTF8_[4] + 0x50U))) ||
       ((pUTF8_[5] & 0xc0U) != 0x80)) {
      uVar2 = 0x800;
      iVar1 = 3;
      goto LAB_001c856a;
    }
    iVar1 = 6;
    uVar3 = (uint)(byte)(pUTF8_[4] + 0x50U) * 0x40 + 0xff80 + (uint)(byte)pUTF8_[5] + uVar2 * 0x400;
  }
  else {
    iVar1 = 3;
    if ((pUTF8_[3] & 0xc0U) != 0x80) goto LAB_001c849a;
    uVar2 = 0x10000;
    uVar3 = uVar3 * 0x40 + -0x400080 + (uint)(byte)pUTF8_[3];
    iVar1 = 4;
LAB_001c856a:
    if (uVar3 < uVar2) goto LAB_001c849a;
  }
  if (((0x7ff < uVar3 - 0xd800) && (uVar3 < 0x110000)) &&
     (((ushort)uVar3 < 0xfffe && (0x1f < uVar3 - 0xfdd0)))) {
LAB_001c84d5:
    *uValueOut = uVar3;
    *bErrorOut = false;
    return iVar1;
  }
LAB_001c849a:
  *uValueOut = 0x3f;
  *bErrorOut = true;
  return iVar1;
}


// Q_UTF8ToUTF16  @ 001c6c90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF8ToUTF16(char *pUTF8,uchar16 *pUTF16,int cubDestSizeInBytes,
                 EStringConvertErrorPolicy ePolicy)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF16 == (uchar16 *)0x0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar5 = 0;
LAB_001c6f20:
    bVar1 = *pUTF8;
    do {
      if (bVar1 == 0) goto LAB_001c6d5a;
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
      if (bVar1 < 0x80) {
        pUTF8 = pUTF8 + 1;
LAB_001c6f79:
        iVar5 = iVar5 + 1;
        goto LAB_001c6f20;
      }
      if (bVar1 - 0xc0 < 0x38) {
        iVar3 = 1;
        if ((pUTF8[1] & 0xc0U) == 0x80) {
          uVar4 = (uint)bVar1 * 0x40 + -0x3080 + (uint)(byte)pUTF8[1];
          if ((uVar4 & 0x800) == 0) {
            iVar3 = 2;
            uVar7 = 0x80;
            goto LAB_001c7012;
          }
          iVar3 = 2;
          if ((pUTF8[2] & 0xc0U) == 0x80) {
            iVar3 = uVar4 * 0x40 + (uint)(byte)pUTF8[2];
            uVar4 = iVar3 - 0x20080;
            if ((uVar4 & 0x10000) == 0) {
              uVar7 = iVar3 - 0x2d880;
              if ((((0x3ff < uVar7) || (pUTF8[3] != 0xed)) || (0xf < (byte)(pUTF8[4] + 0x50U))) ||
                 ((pUTF8[5] & 0xc0U) != 0x80)) {
                iVar3 = 3;
                uVar7 = 0x800;
                goto LAB_001c7012;
              }
              uVar4 = (uint)(byte)(pUTF8[4] + 0x50U) * 0x40 + 0xff80 + (uint)(byte)pUTF8[5] +
                      uVar7 * 0x400;
              iVar3 = 6;
LAB_001c701a:
              if (((0x7ff < uVar4 - 0xd800) && (uVar4 < 0x110000)) &&
                 (((ushort)uVar4 < 0xfffe && (0x1f < uVar4 - 0xfdd0)))) {
                pUTF8 = pUTF8 + iVar3;
                if (uVar4 < 0x10000) goto LAB_001c6f79;
                iVar5 = iVar5 + 2;
                goto LAB_001c6f20;
              }
            }
            else {
              iVar3 = 3;
              if ((pUTF8[3] & 0xc0U) == 0x80) {
                iVar3 = 4;
                uVar4 = uVar4 * 0x40 + -0x400080 + (uint)(byte)pUTF8[3];
                uVar7 = 0x10000;
LAB_001c7012:
                if (uVar7 <= uVar4) goto LAB_001c701a;
              }
            }
          }
        }
      }
      else {
        iVar3 = 1;
      }
      pUTF8 = pUTF8 + iVar3;
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) goto code_r0x001c6f54;
      bVar1 = *pUTF8;
    } while( true );
  }
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
  uVar4 = (uint)cubDestSizeInBytes >> 1;
  if (uVar4 == 0) {
    return 0;
  }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
  iVar3 = 0;
LAB_001c6cd0:
  bVar1 = *pUTF8;
  iVar5 = iVar3;
  do {
    if (bVar1 == 0) goto LAB_001c6d53;
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
    uVar7 = (uint)(byte)*pUTF8;
    if (uVar7 < 0x80) {
      pUTF8 = pUTF8 + 1;
      bVar2 = false;
    }
    else {
      if (uVar7 - 0xc0 < 0x38) {
        iVar3 = 1;
        if ((pUTF8[1] & 0xc0U) == 0x80) {
          uVar7 = uVar7 * 0x40 + -0x3080 + (uint)(byte)pUTF8[1];
          if ((uVar7 & 0x800) == 0) {
            iVar3 = 2;
            uVar6 = 0x80;
LAB_001c6ea2:
            if (uVar6 <= uVar7) {
LAB_001c6e10:
              if ((((0x7ff < uVar7 - 0xd800) && (uVar7 < 0x110000)) && ((ushort)uVar7 < 0xfffe)) &&
                 (0x1f < uVar7 - 0xfdd0)) {
                pUTF8 = pUTF8 + iVar3;
                if (uVar7 < 0x10000) {
                  bVar2 = false;
                  goto LAB_001c6d10;
                }
                iVar3 = iVar5 + 2;
                if ((int)uVar4 <= iVar3) goto LAB_001c6d53;
                (pUTF16 + iVar5)[1] = (ushort)(uVar7 - 0x10000) & 0x3ff | 0xdc00;
                pUTF16[iVar5] = (ushort)((int)(uVar7 - 0x10000) >> 10) | 0xd800;
                goto LAB_001c6cd0;
              }
            }
          }
          else {
            iVar3 = 2;
            if ((pUTF8[2] & 0xc0U) == 0x80) {
              iVar3 = uVar7 * 0x40 + (uint)(byte)pUTF8[2];
              uVar7 = iVar3 - 0x20080;
              if ((uVar7 & 0x10000) == 0) {
                uVar6 = iVar3 - 0x2d880;
                if (((uVar6 < 0x400) && (pUTF8[3] == 0xed)) &&
                   (((byte)(pUTF8[4] + 0x50U) < 0x10 && ((pUTF8[5] & 0xc0U) == 0x80)))) {
                  uVar7 = (uint)(byte)(pUTF8[4] + 0x50U) * 0x40 + 0xff80 + (uint)(byte)pUTF8[5] +
                          uVar6 * 0x400;
                  iVar3 = 6;
                }
                else {
                  iVar3 = 3;
                  if (uVar7 < 0x800) goto LAB_001c6d07;
                }
                goto LAB_001c6e10;
              }
              iVar3 = 3;
              if ((pUTF8[3] & 0xc0U) == 0x80) {
                iVar3 = 4;
                uVar7 = uVar7 * 0x40 + -0x400080 + (uint)(byte)pUTF8[3];
                uVar6 = 0x10000;
                goto LAB_001c6ea2;
              }
            }
          }
        }
      }
      else {
        iVar3 = 1;
      }
LAB_001c6d07:
      pUTF8 = pUTF8 + iVar3;
      uVar7 = 0x3f;
      bVar2 = true;
    }
LAB_001c6d10:
    iVar3 = iVar5 + 1;
    if ((int)uVar4 <= iVar3) {
LAB_001c6d53:
      pUTF16[iVar5] = 0;
LAB_001c6d5a:
      return (iVar5 + 1) * 2;
    }
    pUTF16[iVar5] = (uchar16)uVar7;
    if (!bVar2) goto LAB_001c6cd0;
    if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) goto LAB_001c6d70;
    iVar5 = iVar3 - ((0xffff < (int)uVar7) + 1);
    bVar1 = *pUTF8;
  } while( true );
code_r0x001c6f54:
  iVar5 = iVar5 + 1;
  if ((ePolicy & STRINGCONVERT_FAIL) != STRINGCONVERT_REPLACE) {
    _DAT_00000000 = 0;
    return 0;
  }
  goto LAB_001c6f20;
LAB_001c6d70:
  if ((ePolicy & STRINGCONVERT_FAIL) != STRINGCONVERT_REPLACE) {
    *pUTF16 = 0;
    return 0;
  }
  goto LAB_001c6cd0;
}


// Q_UTF8ToUTF32  @ 001c7130
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF8ToUTF32(char *pUTF8,uchar32 *pUTF32,int cubDestSizeInBytes,
                 EStringConvertErrorPolicy ePolicy)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF32 == (uchar32 *)0x0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar8 = 1;
LAB_001c7370:
    bVar1 = *pUTF8;
    if (bVar1 != 0) {
      while (0x7f < bVar1) {
        if (bVar1 - 0xc0 < 0x38) {
          iVar4 = 1;
          if ((pUTF8[1] & 0xc0U) == 0x80) {
            uVar2 = (uint)bVar1 * 0x40 + -0x3080 + (uint)(byte)pUTF8[1];
            if ((uVar2 & 0x800) == 0) {
              iVar4 = 2;
              uVar3 = 0x80;
              goto LAB_001c7452;
            }
            iVar4 = 2;
            if ((pUTF8[2] & 0xc0U) == 0x80) {
              iVar4 = uVar2 * 0x40 + (uint)(byte)pUTF8[2];
              uVar2 = iVar4 - 0x20080;
              if ((uVar2 & 0x10000) == 0) {
                uVar3 = iVar4 - 0x2d880;
                if (((uVar3 < 0x400) && (pUTF8[3] == 0xed)) &&
                   (((byte)(pUTF8[4] + 0x50U) < 0x10 && ((pUTF8[5] & 0xc0U) == 0x80)))) {
                  iVar4 = 6;
                  uVar2 = (uint)(byte)(pUTF8[4] + 0x50U) * 0x40 + 0xff80 + (uint)(byte)pUTF8[5] +
                          uVar3 * 0x400;
                }
                else {
                  iVar4 = 3;
                  uVar3 = 0x800;
LAB_001c7452:
                  if (uVar2 < uVar3) goto LAB_001c73a0;
                }
                if ((((0x7ff < uVar2 - 0xd800) && (uVar2 < 0x110000)) && ((ushort)uVar2 < 0xfffe))
                   && (0x1f < uVar2 - 0xfdd0)) goto LAB_001c73c7;
              }
              else {
                iVar4 = 3;
                if ((pUTF8[3] & 0xc0U) == 0x80) {
                  iVar4 = 4;
                  uVar2 = uVar2 * 0x40 + -0x400080 + (uint)(byte)pUTF8[3];
                  uVar3 = 0x10000;
                  goto LAB_001c7452;
                }
              }
            }
          }
        }
        else {
          iVar4 = 1;
        }
LAB_001c73a0:
        pUTF8 = pUTF8 + iVar4;
        if ((ePolicy & STRINGCONVERT_SKIP) != STRINGCONVERT_REPLACE) goto LAB_001c7370;
        if ((ePolicy & STRINGCONVERT_FAIL) != STRINGCONVERT_REPLACE) {
          _DAT_00000000 = 0;
          return 0;
        }
        bVar1 = *pUTF8;
        iVar8 = iVar8 + 1;
        if (bVar1 == 0) goto LAB_001c71fb;
      }
      iVar4 = 1;
LAB_001c73c7:
      pUTF8 = pUTF8 + iVar4;
      iVar8 = iVar8 + 1;
      goto LAB_001c7370;
    }
  }
  else {
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
    uVar2 = (uint)cubDestSizeInBytes >> 2;
    if (uVar2 == 0) {
      return 0;
    }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar4 = 0;
    iVar8 = 1;
LAB_001c7180:
    iVar7 = iVar8;
    if (*pUTF8 != 0) {
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
      while (uVar3 = (uint)(byte)*pUTF8, iVar8 = iVar7, 0x7f < uVar3) {
        if (uVar3 - 0xc0 < 0x38) {
          iVar6 = 1;
          if ((pUTF8[1] & 0xc0U) == 0x80) {
            uVar3 = uVar3 * 0x40 + -0x3080 + (uint)(byte)pUTF8[1];
            if ((uVar3 & 0x800) == 0) {
              iVar6 = 2;
              uVar5 = 0x80;
LAB_001c72fa:
              if (uVar5 <= uVar3) {
LAB_001c72b0:
                if (((0x7ff < uVar3 - 0xd800) && (uVar3 < 0x110000)) &&
                   (((ushort)uVar3 < 0xfffe && (0x1f < uVar3 - 0xfdd0)))) goto LAB_001c7215;
              }
            }
            else {
              iVar6 = 2;
              if ((pUTF8[2] & 0xc0U) == 0x80) {
                iVar6 = (uint)(byte)pUTF8[2] + uVar3 * 0x40;
                uVar3 = iVar6 - 0x20080;
                if ((uVar3 & 0x10000) == 0) {
                  uVar5 = iVar6 - 0x2d880;
                  if ((((uVar5 < 0x400) && (pUTF8[3] == 0xed)) && ((byte)(pUTF8[4] + 0x50U) < 0x10))
                     && ((pUTF8[5] & 0xc0U) == 0x80)) {
                    iVar6 = 6;
                    uVar3 = (byte)pUTF8[5] + 0xff80 + (uint)(byte)(pUTF8[4] + 0x50U) * 0x40 +
                            uVar5 * 0x400;
                  }
                  else {
                    iVar6 = 3;
                    if (uVar3 < 0x800) goto LAB_001c71b7;
                    iVar6 = 3;
                  }
                  goto LAB_001c72b0;
                }
                iVar6 = 3;
                if ((pUTF8[3] & 0xc0U) == 0x80) {
                  iVar6 = 4;
                  uVar3 = uVar3 * 0x40 + -0x400080 + (uint)(byte)pUTF8[3];
                  uVar5 = 0x10000;
                  goto LAB_001c72fa;
                }
              }
            }
          }
        }
        else {
          iVar6 = 1;
        }
LAB_001c71b7:
        pUTF8 = pUTF8 + iVar6;
        if ((int)uVar2 <= iVar7) goto LAB_001c71f0;
        pUTF32[iVar4] = 0x3f;
        if ((ePolicy & STRINGCONVERT_SKIP) != STRINGCONVERT_REPLACE) goto LAB_001c7180;
        if ((ePolicy & STRINGCONVERT_FAIL) != STRINGCONVERT_REPLACE) {
          *pUTF32 = 0;
          return 0;
        }
        iVar8 = iVar7 + 1;
        iVar4 = iVar7;
        iVar7 = iVar8;
        if (*pUTF8 == 0) goto LAB_001c71f0;
      }
      iVar6 = 1;
LAB_001c7215:
      pUTF8 = pUTF8 + iVar6;
      if ((int)uVar2 <= iVar7) goto LAB_001c71f0;
      pUTF32[iVar4] = uVar3;
      iVar8 = iVar7 + 1;
      iVar4 = iVar7;
      goto LAB_001c7180;
    }
LAB_001c71f0:
    pUTF32[iVar4] = 0;
  }
LAB_001c71fb:
  return iVar8 * 4;
}


// Q_UnicodeAdvance  @ 001c88f0
char * Q_UnicodeAdvance(char *pUTF8,int nChars)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  if (0 < nChars) {
    do {
      bVar2 = *pUTF8;
      if (bVar2 == 0) {
        return (char *)(byte *)pUTF8;
      }
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
      iVar4 = 1;
      if (((0x7f < bVar2) && (bVar2 - 0xc0 < 0x38)) && ((pUTF8[1] & 0xc0U) == 0x80)) {
        iVar4 = 2;
        uVar1 = (uint)bVar2 * 0x40 + -0x3080 + (uint)(byte)pUTF8[1];
        if (((uVar1 & 0x800) != 0) && ((pUTF8[2] & 0xc0U) == 0x80)) {
          iVar3 = (uint)(byte)pUTF8[2] + uVar1 * 0x40;
          if ((iVar3 - 0x20080U & 0x10000) == 0) {
            iVar4 = 3;
            if (((iVar3 - 0x2d880U < 0x400) && (pUTF8[3] == 0xed)) &&
               (((byte)(pUTF8[4] + 0x50U) < 0x10 && ((pUTF8[5] & 0xc0U) == 0x80)))) {
              iVar4 = 6;
            }
          }
          else {
            iVar4 = ((pUTF8[3] & 0xc0U) == 0x80) + 3;
          }
        }
      }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bError@[???] */
      pUTF8 = pUTF8 + iVar4;
      nChars = nChars + -1;
    } while (nChars != 0);
  }
  return pUTF8;
}


// Q_UnicodeLength  @ 001c87e0
int Q_UnicodeLength(char *pUTF8)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int nChars@[???] */
  iVar5 = 0;
  bVar2 = *pUTF8;
  while (bVar2 != 0) {
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
    iVar4 = 1;
    if (((0x7f < bVar2) && (bVar2 - 0xc0 < 0x38)) && ((pUTF8[1] & 0xc0U) == 0x80)) {
      iVar4 = 2;
      uVar1 = (uint)bVar2 * 0x40 + -0x3080 + (uint)(byte)pUTF8[1];
      if ((uVar1 & 0x800) != 0) {
        iVar4 = 2;
        if ((pUTF8[2] & 0xc0U) == 0x80) {
          iVar3 = (uint)(byte)pUTF8[2] + uVar1 * 0x40;
          if ((iVar3 - 0x20080U & 0x10000) == 0) {
            iVar4 = 3;
            if (((iVar3 - 0x2d880U < 0x400) && (pUTF8[3] == 0xed)) &&
               (((byte)(pUTF8[4] + 0x50U) < 0x10 && ((pUTF8[5] & 0xc0U) == 0x80)))) {
              iVar4 = 6;
            }
          }
          else {
            iVar4 = ((pUTF8[3] & 0xc0U) == 0x80) + 3;
          }
        }
      }
    }
                    /* Unresolved local var: bool bError@[???]
                       Unresolved local var: uchar32 uVal@[???] */
    pUTF8 = pUTF8 + iVar4;
    iVar5 = iVar5 + 1;
    bVar2 = *pUTF8;
  }
  return iVar5;
}


// Q_UnicodeRepair  @ 001c9170
int Q_UnicodeRepair(char *pUTF8)

{
  byte *pbVar1;
  bool bVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  char *pUTF8_;
  int iVar9;
  uint local_28;
  bool local_15;
  int local_14;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF8 != (char *)0x0) {
    iVar3 = 0;
    pbVar5 = (byte *)pUTF8;
LAB_001c9190:
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
    if (*pbVar5 != 0) {
      do {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???]
                       Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
        bVar4 = *pbVar5;
        uVar8 = (uint)bVar4;
        if (uVar8 < 0x80) {
          pbVar5 = pbVar5 + 1;
          bVar2 = false;
        }
        else {
          if (uVar8 - 0xc0 < 0x38) {
            iVar9 = 1;
            if ((pbVar5[1] & 0xc0) == 0x80) {
              local_28 = uVar8 * 0x40 + -0x3080 + (uint)pbVar5[1];
              if ((local_28 & 0x800) == 0) {
                iVar9 = 2;
                uVar8 = 0x80;
LAB_001c92aa:
                if (local_28 < uVar8) {
LAB_001c9280:
                  pbVar5 = pbVar5 + iVar9;
                  if (0xfffd < iVar3) break;
                  pUTF8[iVar3] = '?';
                  goto LAB_001c9190;
                }
LAB_001c92b0:
                if (((0x7ff < local_28 - 0xd800) && (local_28 < 0x110000)) &&
                   (((ushort)local_28 < 0xfffe && (0x1f < local_28 - 0xfdd0))))
                goto code_r0x001c92ed;
              }
              else {
                iVar9 = 2;
                if ((pbVar5[2] & 0xc0) == 0x80) {
                  iVar9 = local_28 * 0x40 + (uint)pbVar5[2];
                  local_28 = iVar9 - 0x20080;
                  if ((local_28 & 0x10000) == 0) {
                    uVar8 = iVar9 - 0x2d880;
                    if ((((uVar8 < 0x400) && (pbVar5[3] == 0xed)) &&
                        ((byte)(pbVar5[4] + 0x50) < 0x10)) && ((pbVar5[5] & 0xc0) == 0x80)) {
                      local_28 = uVar8 * 0x400 +
                                 (uint)(byte)(pbVar5[4] + 0x50) * 0x40 + 0xff80 + (uint)pbVar5[5];
                      iVar9 = 6;
                    }
                    else {
                      iVar9 = 3;
                      if (local_28 < 0x800) goto LAB_001c9280;
                    }
                    goto LAB_001c92b0;
                  }
                  iVar9 = 3;
                  if ((pbVar5[3] & 0xc0) == 0x80) {
                    local_28 = local_28 * 0x40 + -0x400080 + (uint)pbVar5[3];
                    uVar8 = 0x10000;
                    iVar9 = 4;
                    goto LAB_001c92aa;
                  }
                }
              }
            }
          }
          else {
            iVar9 = 1;
          }
          pbVar5 = pbVar5 + iVar9;
          bVar4 = 0x3f;
          bVar2 = true;
        }
        if (0xfffd < iVar3) break;
        pUTF8[iVar3] = bVar4;
        iVar3 = iVar3 + (uint)!bVar2;
        if (*pbVar5 == 0) break;
      } while( true );
    }
    goto LAB_001c91e0;
  }
  if (DAT_00000000 == '\0') {
    return 1;
  }
  pUTF8_ = (char *)0x0;
  iVar3 = 0;
  do {
    while( true ) {
      local_15 = false;
      iVar9 = Q_UTF8ToUChar32(pUTF8_,&local_14,&local_15);
      pUTF8_ = pUTF8_ + iVar9;
      if (local_14 < 0x80) break;
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
      if (local_14 < 0x800) {
        iVar9 = iVar3 + 2;
        goto joined_r0x001c9477;
      }
      if (local_14 < 0x10000) {
        iVar9 = iVar3 + 3;
        goto joined_r0x001c9477;
      }
      iVar9 = iVar3 + 4;
      if (local_15 == false) goto LAB_001c9421;
LAB_001c9455:
      iVar9 = iVar3;
      if (*pUTF8_ == '\0') goto LAB_001c945a;
    }
    iVar9 = iVar3 + 1;
joined_r0x001c9477:
    if (local_15 != false) goto LAB_001c9455;
LAB_001c9421:
    iVar3 = iVar9;
  } while (*pUTF8_ != '\0');
LAB_001c945a:
  return iVar9 + 1;
code_r0x001c92ed:
  pbVar5 = pbVar5 + iVar9;
  bVar4 = (byte)local_28;
  bVar6 = (byte)((int)local_28 >> 6);
  if ((int)local_28 < 0x800) {
    if (0xfffc < iVar3) {
LAB_001c91e0:
      pUTF8[iVar3] = '\0';
      return iVar3 + 1;
    }
    pbVar1 = (byte *)(pUTF8 + iVar3);
    *pbVar1 = bVar6 | 0xc0;
    iVar3 = iVar3 + 2;
    pbVar1[1] = bVar4 & 0x3f | 0x80;
  }
  else {
    bVar7 = (byte)((int)local_28 >> 0xc);
    if ((int)local_28 < 0x10000) {
      if (0xfffb < iVar3) goto LAB_001c91e0;
      pbVar1 = (byte *)(pUTF8 + iVar3);
      *pbVar1 = bVar7 | 0xe0;
      iVar3 = iVar3 + 3;
      pbVar1[1] = bVar6 & 0x3f | 0x80;
      pbVar1[2] = bVar4 & 0x3f | 0x80;
    }
    else {
      if (0xfffa < iVar3) goto LAB_001c91e0;
      pbVar1 = (byte *)(pUTF8 + iVar3);
      *pbVar1 = (byte)((int)local_28 >> 0x12) | 0xf0;
      iVar3 = iVar3 + 4;
      pbVar1[1] = bVar7 & 0x3f | 0x80;
      pbVar1[2] = bVar6 & 0x3f | 0x80;
      pbVar1[3] = bVar4 & 0x3f | 0x80;
    }
  }
  goto LAB_001c9190;
}


// Q_UnicodeValidate  @ 001c8610
qboolean Q_UnicodeValidate(char *pUTF8)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
                    /* Unresolved local var: bool bError@[???] */
  bVar1 = *pUTF8;
  do {
    while( true ) {
      if (bVar1 == 0) {
        return 1;
      }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: int nCharSize@[DW_OP_reg1(ECX)]
                       Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
      if (0x7f < bVar1) break;
      pUTF8 = pUTF8 + 1;
      bVar1 = *pUTF8;
    }
    if (0x37 < bVar1 - 0xc0) {
      return 0;
    }
    if ((pUTF8[1] & 0xc0U) != 0x80) {
      return 0;
    }
    uVar5 = (uint)bVar1 * 0x40 + -0x3080 + (uint)(byte)pUTF8[1];
    if ((uVar5 & 0x800) == 0) {
      iVar2 = 2;
      uVar4 = 0x80;
      iVar3 = 2;
LAB_001c875f:
      if (uVar5 < uVar4) {
        return 0;
      }
    }
    else {
      if ((pUTF8[2] & 0xc0U) != 0x80) {
        return 0;
      }
      iVar2 = (uint)(byte)pUTF8[2] + uVar5 * 0x40;
      uVar5 = iVar2 - 0x20080;
      if ((uVar5 & 0x10000) != 0) {
        if ((pUTF8[3] & 0xc0U) != 0x80) {
          return 0;
        }
        uVar4 = 0x10000;
        uVar5 = uVar5 * 0x40 + -0x400080 + (uint)(byte)pUTF8[3];
        iVar3 = 4;
        iVar2 = 4;
        goto LAB_001c875f;
      }
      uVar4 = iVar2 - 0x2d880;
      if ((((uVar4 < 0x400) && (pUTF8[3] == 0xed)) && ((byte)(pUTF8[4] + 0x50U) < 0x10)) &&
         ((pUTF8[5] & 0xc0U) == 0x80)) {
        iVar3 = 6;
        uVar5 = (uint)(byte)(pUTF8[4] + 0x50U) * 0x40 + 0xff80 + (uint)(byte)pUTF8[5] +
                uVar4 * 0x400;
        iVar2 = 6;
      }
      else {
        iVar2 = 3;
        iVar3 = 3;
        if (uVar5 < 0x800) {
          return 0;
        }
      }
    }
    if (((uVar5 - 0xd800 < 0x800) || (0x10ffff < uVar5)) ||
       ((0xfffd < (ushort)uVar5 || ((uVar5 - 0xfdd0 < 0x20 || (iVar3 == 6)))))) {
      return 0;
    }
    pUTF8 = pUTF8 + iVar2;
    bVar1 = *pUTF8;
  } while( true );
}


// Q_atof  @ 0009e320
float Q_atof(char *str)

{
  char cVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  
                    /* Unresolved local var: double val@[???]
                       Unresolved local var: int sign@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int decimal@[???]
                       Unresolved local var: int total@[???] */
  cVar1 = *str;
  if (cVar1 == '-') {
    cVar1 = str[1];
    str = str + 1;
    fVar4 = -1.0;
    iVar6 = -1;
  }
  else {
    iVar6 = 1;
    fVar4 = 1.0;
  }
  if (cVar1 == '0') {
    if ((str[1] & 0xdfU) == 0x58) {
      fVar3 = 0.0;
      pbVar8 = (byte *)(str + 2);
      while( true ) {
        while( true ) {
          bVar2 = *pbVar8;
          while( true ) {
            iVar6 = (int)(char)bVar2;
            pbVar8 = pbVar8 + 1;
            if (9 < iVar6 - 0x30U) break;
            sVar5 = (short)(char)bVar2;
            bVar2 = *pbVar8;
            fVar3 = ((float)sVar5 + fVar3 * 16.0) - 48.0;
          }
          if (5 < iVar6 - 0x61U) break;
          fVar3 = (((float)(short)(char)bVar2 + fVar3 * 16.0) - 97.0) + 10.0;
        }
        if (5 < iVar6 - 0x41U) break;
        fVar3 = (((float)(short)(char)bVar2 + fVar3 * 16.0) - 65.0) + 10.0;
      }
      return fVar3 * fVar4;
    }
  }
  else if (cVar1 == '\'') {
    return (float)(str[1] * iVar6);
  }
  fVar3 = 0.0;
  iVar7 = 0;
  iVar6 = -1;
  do {
    do {
      iVar9 = iVar6;
      bVar2 = *str;
      pbVar8 = (byte *)(str + 1);
      str = str + 1;
      iVar6 = iVar7;
    } while ((bVar2 & 0xfd) == 0x2c);
    do {
      sVar5 = (short)(char)bVar2;
      if (9 < (int)(char)bVar2 - 0x30U) {
        if ((iVar9 != -1) && (iVar9 < iVar7)) {
          do {
            iVar7 = iVar7 + -1;
            fVar3 = fVar3 / 10.0;
          } while (iVar9 != iVar7);
        }
        return fVar3 * fVar4;
      }
      str = (char *)(pbVar8 + 1);
      bVar2 = *pbVar8;
      iVar7 = iVar7 + 1;
      fVar3 = ((float)sVar5 + fVar3 * 10.0) - 48.0;
      pbVar8 = (byte *)str;
      iVar6 = iVar7;
    } while ((bVar2 & 0xfd) != 0x2c);
  } while( true );
}


// Q_atoi  @ 0009e220
int Q_atoi(char *str)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
                    /* Unresolved local var: int val@[???]
                       Unresolved local var: int sign@[???]
                       Unresolved local var: int c@[???] */
  iVar5 = 1;
  cVar1 = *str;
  if (cVar1 == '-') {
    cVar1 = str[1];
    iVar5 = -1;
    str = str + 1;
  }
  iVar3 = (int)cVar1;
  if (cVar1 == '0') {
    if ((str[1] & 0xdfU) == 0x58) {
      pcVar4 = str + 2;
      iVar3 = 0;
      while( true ) {
        while( true ) {
          cVar1 = *pcVar4;
          while( true ) {
            iVar2 = (int)cVar1;
            pcVar4 = pcVar4 + 1;
            if (9 < iVar2 - 0x30U) break;
            iVar3 = iVar2 + -0x30 + iVar3 * 0x10;
            cVar1 = *pcVar4;
          }
          if (5 < iVar2 - 0x61U) break;
          iVar3 = iVar2 + -0x57 + iVar3 * 0x10;
        }
        if (5 < iVar2 - 0x41U) break;
        iVar3 = iVar2 + -0x37 + iVar3 * 0x10;
      }
      return iVar3 * iVar5;
    }
    iVar3 = 0x30;
  }
  else {
    if (cVar1 == '\'') {
      return str[1] * iVar5;
    }
    if (9 < iVar3 - 0x30U) {
      return 0;
    }
  }
  iVar2 = 0;
  do {
    str = str + 1;
    iVar2 = iVar3 + -0x30 + iVar2 * 10;
    iVar3 = (int)*str;
  } while (iVar3 - 0x30U < 10);
  return iVar2 * iVar5;
}


// Q_log2  @ 000c5f40
int Q_log2(int val)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int answer@[???] */
  iVar1 = 0;
  iVar2 = val >> 1;
  if (iVar2 == 0) {
    return iVar1;
  }
  do {
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 >> 1;
  } while (iVar2 != 0);
  return iVar1;
}


// Q_memcmp  @ 0009dec0
int Q_memcmp(void *m1,void *m2,int count)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: int byteLoops@[???]
                       Unresolved local var: int numLoops@[???]
                       Unresolved local var: int i@[???] */
  if (count >> 2 < 1) {
LAB_0009def5:
    uVar2 = count & 3;
    if (uVar2 != 0) {
      if (*(char *)m1 != *(char *)m2) goto LAB_0009df30;
      if (uVar2 != 1) {
        if (*(char *)((int)m1 + 1) != *(char *)((int)m2 + 1)) goto LAB_0009df30;
        if (uVar2 == 3) {
          return -(uint)(*(char *)((int)m1 + 2) != *(char *)((int)m2 + 2));
        }
      }
    }
    iVar1 = 0;
  }
  else {
    if (*(int *)m1 == *(int *)m2) {
      iVar1 = 0;
      do {
        iVar1 = iVar1 + 1;
        if (count >> 2 == iVar1) goto LAB_0009def5;
      } while (*(int *)((int)m1 + iVar1 * 4) == *(int *)((int)m2 + iVar1 * 4));
    }
LAB_0009df30:
    iVar1 = -1;
  }
  return iVar1;
}


// Q_memcpy  @ 0009de30
void Q_memcpy(void *dest,void *src,int count)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (7 < (uint)count) {
    puVar4 = dest;
    if (((uint)dest & 1) != 0) {
      uVar1 = *(undefined1 *)src;
      puVar4 = (undefined4 *)((int)dest + 1);
      src = (void *)((int)src + 1);
      count = count + -1;
      *(undefined1 *)dest = uVar1;
    }
    puVar5 = puVar4;
    if (((uint)puVar4 & 2) != 0) {
      uVar2 = *(undefined2 *)src;
      puVar5 = (undefined4 *)((int)puVar4 + 2);
      src = (void *)((int)src + 2);
      count = count + -2;
      *(undefined2 *)puVar4 = uVar2;
    }
    dest = puVar5;
    if (((uint)puVar5 & 4) != 0) {
      uVar3 = *(undefined4 *)src;
      dest = puVar5 + 1;
      src = (void *)((int)src + 4);
      count = count + -4;
      *puVar5 = uVar3;
    }
  }
  for (; count != 0; count = count + -1) {
    *(undefined1 *)dest = *(undefined1 *)src;
    src = (undefined4 *)((int)src + 1);
    dest = (undefined4 *)((int)dest + 1);
  }
  return;
}


// Q_memset  @ 0009dda0
void Q_memset(void *dest,int fill,int count)

{
  uint uVar1;
  int iVar2;
  
  if (7 < (uint)count) {
    iVar2 = (fill & 0xffU) * 0x1010101;
    uVar1 = count;
    if (((uint)dest & 1) != 0) {
      *(char *)dest = (char)iVar2;
      uVar1 = count - 1;
      dest = (void *)((int)dest + 1);
    }
    if (((uint)dest & 2) != 0) {
      *(short *)dest = (short)iVar2;
      uVar1 = uVar1 - 2;
      dest = (void *)((int)dest + 2);
    }
    if (((uint)dest & 4) != 0) {
      *(int *)dest = iVar2;
      uVar1 = uVar1 - 4;
      dest = (void *)((int)dest + 4);
    }
    count = uVar1 & 3;
    for (uVar1 = uVar1 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(int *)dest = iVar2;
      dest = (int *)((int)dest + 4);
    }
  }
  if ((count & 7U) != 0) {
    uVar1 = 0;
    do {
      *(char *)((int)dest + uVar1) = (char)fill;
      uVar1 = uVar1 + 1;
    } while (uVar1 < (count & 7U));
  }
  return;
}


// Q_ntohs  @ 0011a710
ushort Q_ntohs(ushort param_1)

{
  return param_1 >> 8 | param_1 << 8;
}


// Q_strcasecmp  @ 0009e170
int Q_strcasecmp(char *param_1,char *param_2)

{
  int iVar1;
  
  if (param_1 == (char *)0x0) {
    iVar1 = -1;
  }
  else {
    if (param_2 == (char *)0x0) {
      return 1;
    }
    iVar1 = strncasecmp(param_1,param_2,99999);
  }
  return iVar1;
}


// Q_strcat  @ 0009e040
void Q_strcat(char *dest,char *src)

{
  char cVar1;
  char *pcVar2;
  
                    /* Unresolved local var: int count@[???] */
  if (dest != (char *)0x0) {
    cVar1 = *dest;
    while (cVar1 != '\0') {
      dest = dest + 1;
      cVar1 = *dest;
    }
    if ((src != (char *)0x0) && (pcVar2 = dest, dest != (char *)0x0)) {
      while (cVar1 = *src, dest = pcVar2, cVar1 != '\0') {
        dest = pcVar2 + 1;
        src = src + 1;
        *pcVar2 = cVar1;
        if ((dest == (char *)0x0) || (pcVar2 = dest, src == (char *)0x0)) break;
      }
    }
  }
  *dest = '\0';
  return;
}


// Q_strcmp  @ 0009e0a0
int Q_strcmp(char *s1,char *s2)

{
  if ((s1 != (char *)0x0) && (s2 != (char *)0x0)) {
    for (; *s1 == *s2; s1 = s1 + 1) {
      if (*s1 == '\0') {
        return 0;
      }
      s2 = s2 + 1;
    }
  }
  return -1;
}


// Q_strcpy  @ 0009df40
void Q_strcpy(char *dest,char *src)

{
  for (; ((dest != (char *)0x0 && (src != (char *)0x0)) && (*src != '\0')); src = src + 1) {
    *dest = *src;
    dest = dest + 1;
  }
  *dest = '\0';
  return;
}


// Q_stricmp  @ 0009e1b0
int Q_stricmp(char *s1,char *s2)

{
  int iVar1;
  
                    /* Unresolved local var: int c1@[???]
                       Unresolved local var: int c2@[???] */
  if (s1 == (char *)0x0) {
    iVar1 = -1;
  }
  else {
    if (s2 == (char *)0x0) {
      return 1;
    }
    iVar1 = strncasecmp(s1,s2,99999);
  }
  return iVar1;
}


// Q_striprefix  @ 0009e6f0
qboolean Q_striprefix(char *str,char *prefix)

{
  char cVar1;
  __int32_t **pp_Var2;
  char cVar3;
  
  if ((str == (char *)0x0) || (prefix == (char *)0x0)) {
    return false;
  }
  cVar1 = *str;
  cVar3 = *prefix;
  if ((cVar1 != '\0') && (cVar3 != '\0')) {
    pp_Var2 = __ctype_tolower_loc();
                    /* Unresolved local var: int __res@[???] */
    while ((*pp_Var2)[cVar1] == (*pp_Var2)[cVar3]) {
      str = str + 1;
      cVar1 = *str;
      cVar3 = prefix[1];
      if ((cVar1 == '\0') || (prefix = prefix + 1, cVar3 == '\0')) break;
    }
  }
  return (uint)(cVar3 == '\0');
}


// Q_stristr  @ 000ec990
char * Q_stristr(char *pStr,char *pSearch)

{
  byte bVar1;
  __int32_t *p_Var2;
  int iVar3;
  int iVar4;
  __int32_t **pp_Var5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  
                    /* Unresolved local var: char * pLetter@[???] */
  if (((pStr == (char *)0x0) || (pSearch == (char *)0x0)) || (bVar1 = *pStr, bVar1 == 0)) {
    return (char *)0x0;
  }
  pp_Var5 = __ctype_tolower_loc();
  pbVar8 = (byte *)(pStr + 1);
  p_Var2 = *pp_Var5;
  iVar6 = p_Var2[bVar1];
  do {
    if (p_Var2[(byte)*pSearch] == iVar6) {
                    /* Unresolved local var: char * pMatch@[???]
                       Unresolved local var: char * pTest@[???] */
      if (pSearch[1] == 0) {
        return (char *)(byte *)pStr;
      }
      if (*pbVar8 == 0) {
        return (char *)0x0;
      }
                    /* Unresolved local var: int __res@[???] */
      iVar6 = p_Var2[*pbVar8];
      if (iVar6 == p_Var2[(byte)pSearch[1]]) {
        iVar7 = 0;
        do {
          iVar4 = iVar7 + 2;
          if (pSearch[iVar4] == 0) {
            return (char *)(byte *)pStr;
          }
          iVar3 = iVar7 + 2;
          if (pStr[iVar3] == 0) {
            return (char *)0x0;
          }
          iVar7 = iVar7 + 1;
        } while (p_Var2[(byte)pStr[iVar3]] == p_Var2[(byte)pSearch[iVar4]]);
      }
    }
    else {
      if (*pbVar8 == 0) {
        return (char *)0x0;
      }
      iVar6 = p_Var2[*pbVar8];
    }
    pbVar8 = pbVar8 + 1;
    pStr = (char *)(pbVar8 + -1);
  } while( true );
}


// Q_strlen  @ 0009dfc0
int Q_strlen(char *str)

{
  int iVar1;
  
                    /* Unresolved local var: int count@[???] */
  iVar1 = 0;
  if (str == (char *)0x0) {
    return iVar1;
  }
  if (*str != '\0') {
    do {
      iVar1 = iVar1 + 1;
    } while (str[iVar1] != '\0');
    return iVar1;
  }
  return iVar1;
}


// Q_strlwr  @ 0009e4f0
char * Q_strlwr(char *src)

{
  char cVar1;
  __int32_t **pp_Var2;
  char *pcVar3;
  
                    /* Unresolved local var: char * p@[???] */
  cVar1 = *src;
  if (cVar1 != '\0') {
    pp_Var2 = __ctype_tolower_loc();
    pcVar3 = src;
    do {
                    /* Unresolved local var: int __res@[???] */
      src = pcVar3 + 1;
      *pcVar3 = (char)(*pp_Var2)[cVar1];
      cVar1 = *src;
      pcVar3 = src;
    } while (cVar1 != '\0');
  }
  return src;
}


// Q_strncasecmp  @ 0009e140
int Q_strncasecmp(char *param_1,char *param_2,size_t param_3)

{
  int iVar1;
  
  if (param_1 == (char *)0x0) {
    return -1;
  }
  if (param_2 != (char *)0x0) {
    iVar1 = strncasecmp(param_1,param_2,param_3);
    return iVar1;
  }
  return 1;
}


// Q_strncmp  @ 0009e0e0
int Q_strncmp(char *s1,char *s2,int count)

{
  int iVar1;
  int iVar2;
  
  if ((s1 == (char *)0x0) || (s2 == (char *)0x0)) {
    return -1;
  }
  if (count != 0) {
    if (*s1 != *s2) {
      return -1;
    }
    if (*s1 != '\0') {
      iVar2 = 0;
      do {
        if (iVar2 == count + -1) {
          return 0;
        }
        iVar1 = iVar2 + 1;
        if (s1[iVar1] != s2[iVar2 + 1]) {
          return -1;
        }
        iVar2 = iVar2 + 1;
      } while (s1[iVar1] != '\0');
    }
  }
  return 0;
}


// Q_strncpy  @ 0009df70
void Q_strncpy(char *dest,char *src,int count)

{
  strncpy(dest,src,count);
  return;
}


// Q_strncpy_s  @ 0009df80
void Q_strncpy_s(char *dest,char *src,int count)

{
  strncpy(dest,src,count);
  dest[count + -1] = '\0';
  return;
}


// Q_strnicmp  @ 0009e1f0
int Q_strnicmp(char *s1,char *s2,int n)

{
  int iVar1;
  
                    /* Unresolved local var: int c1@[???]
                       Unresolved local var: int c2@[???] */
  if (s1 == (char *)0x0) {
    return -1;
  }
  if (s2 != (char *)0x0) {
    iVar1 = strncasecmp(s1,s2,n);
    return iVar1;
  }
  return 1;
}


// Q_strrchr  @ 0009dff0
char * Q_strrchr(char *s,char c)

{
  char *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: int len@[???] */
                    /* Unresolved local var: int count@[???] */
  if ((s == (char *)0x0) || (*s == '\0')) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    do {
      s = s + 1;
      iVar2 = iVar2 + 1;
    } while (*s != '\0');
  }
  pcVar1 = s + -iVar2;
  do {
    if (s == pcVar1) {
      return (char *)0x0;
    }
    s = s + -1;
  } while (*s != c);
  return s;
}


// Q_strstr  @ 0009e5e0
char * Q_strstr(char *s1,char *search)

{
  char *pcVar1;
  
  pcVar1 = strstr(s1,search);
  return pcVar1;
}


// Q_strtoull  @ 0009e5f0
uint64 Q_strtoull(char *str)

{
  uint uVar1;
  char cVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *local_18;
  
                    /* Unresolved local var: uint64 iResult@[???]
                       Unresolved local var: int isNegative@[???] */
  local_18 = str;
  cVar2 = *str;
  if (cVar2 != ' ') goto LAB_0009e620;
  do {
    do {
      local_18 = local_18 + 1;
      cVar2 = *local_18;
    } while (cVar2 == ' ');
LAB_0009e620:
  } while (cVar2 == '\t');
  if (cVar2 == '+') {
    cVar2 = local_18[1];
    local_18 = local_18 + 1;
  }
  else if (cVar2 == '-') {
    iVar6 = 0;
    cVar2 = local_18[1];
    local_18 = local_18 + 1;
    uVar4 = 0;
    if ((byte)(cVar2 - 0x30U) < 10) {
      do {
        uVar3 = (ulonglong)uVar4;
        uVar5 = (uint)(uVar3 * 10);
        uVar1 = (int)cVar2 - 0x30;
        uVar4 = uVar5 - uVar1;
        iVar6 = (((int)(uVar3 * 10 >> 0x20) + iVar6 * 10) - ((int)uVar1 >> 0x1f)) -
                (uint)(uVar5 < uVar1);
        local_18 = local_18 + 1;
        cVar2 = *local_18;
      } while ((byte)(cVar2 - 0x30U) < 10);
      return CONCAT44(iVar6,uVar4);
    }
    goto LAB_0009e678;
  }
  iVar6 = 0;
  uVar4 = 0;
  while ((byte)(cVar2 - 0x30U) < 10) {
    uVar3 = (ulonglong)uVar4;
    uVar5 = (uint)(uVar3 * 10);
    uVar1 = (int)cVar2 - 0x30;
    uVar4 = uVar5 + uVar1;
    iVar6 = (int)(uVar3 * 10 >> 0x20) + iVar6 * 10 + ((int)uVar1 >> 0x1f) +
            (uint)CARRY4(uVar5,uVar1);
    local_18 = local_18 + 1;
    cVar2 = *local_18;
  }
LAB_0009e678:
  return CONCAT44(iVar6,uVar4);
}


