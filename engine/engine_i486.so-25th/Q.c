// Q_FileNameCmp  @ 0003a3f0
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
  if (cVar3 == '/') goto LAB_0003a439;
LAB_0003a420:
  pcVar4 = pcVar5;
  pcVar5 = pcVar6;
  if ((cVar3 == '\\') && (cVar2 == '/')) goto LAB_0003a42a;
  pp_Var1 = __ctype_tolower_loc();
  if ((*pp_Var1)[cVar3] == (*pp_Var1)[cVar2]) {
    if (cVar3 == '\0') {
      return 0;
    }
    do {
      if (cVar2 == '\0') {
        return 0;
      }
LAB_0003a42a:
      do {
        pcVar6 = pcVar5 + 1;
        cVar3 = *pcVar5;
        pcVar5 = pcVar4 + 1;
        cVar2 = *pcVar4;
        if (cVar3 != '/') goto LAB_0003a420;
LAB_0003a439:
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


// Q_IsDeprecatedW  @ 000c1f50
qboolean Q_IsDeprecatedW(wchar_t wch)

{
                    /* Unresolved local var: qboolean bIsDeprecated@[???] */
  if ((L'\x2029' < wch) && ((wch < L'\x202f' || ((uint)(wch + L'\xffffdf96') < 6)))) {
    return 1;
  }
  return 0;
}


// Q_IsMeanSpaceW  @ 000c1ee0
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


// Q_IsValidUChar32  @ 000bff40
bool Q_IsValidUChar32(uchar32 uVal)

{
  bool bVar1;
  bool bVar2;
  
  bVar1 = 0x7ff < uVal - 0xd800U;
  bVar2 = (uint)uVal < Netchan_OutOfBandPrint::string + 0xf20 && bVar1;
  if (((uint)uVal < Netchan_OutOfBandPrint::string + 0xf20 && bVar1) &&
     (bVar2 = false, (ushort)uVal < 0xfffe)) {
    bVar2 = 0x1f < uVal - 0xfdd0U;
  }
  return bVar2;
}


// Q_StripUnprintableAndSpace  @ 000c1f80
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
  char *pcVar8;
  wchar_t wVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  int iVar13;
  bool bVar14;
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
  uVar10 = (int)pOut * 4 + 4;
  __ptr = malloc(uVar10);
                    /* Unresolved local var: int nOut@[???] */
  if (__ptr == (wchar_t *)0x0) {
    if (*pch == '\0') {
      uVar10 = 0xfffffffc;
    }
    else {
      iVar6 = 0;
      pcVar8 = pch;
      do {
        iVar11 = iVar6;
        in_stack_ffffffb8 = local_20;
        local_21 = false;
        iVar6 = Q_UTF8ToUChar32(pcVar8,in_stack_ffffffb8,&local_21);
        pcVar8 = pcVar8 + iVar6;
        iVar6 = iVar11 + 1;
      } while (*pcVar8 != '\0');
      uVar10 = iVar11 * 4;
    }
  }
  else {
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
    uVar10 = uVar10 >> 2;
    if (uVar10 == 0) {
      uVar10 = 0xfffffff8;
    }
    else {
      if (*pch == '\0') {
        uVar10 = 0xfffffffc;
        iVar13 = 0;
      }
      else {
        pbVar4 = (byte *)pch;
        iVar6 = 0;
        do {
          pcVar8 = (char *)(uint)*pbVar4;
          if (pcVar8 < (char *)0x80) {
            iVar11 = 1;
          }
          else {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???]
                       Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
            if ((pcVar8 + -0xc0 < (char *)0x38) && ((pbVar4[1] & 0xc0) == 0x80)) {
              pcVar8 = (char *)((int)pcVar8 * 0x40 + -0x3080 + (uint)pbVar4[1]);
              if (((uint)pcVar8 & 0x800) == 0) {
                iVar11 = 2;
                pcVar12 = (char *)0x80;
                goto LAB_000c21c2;
              }
              if ((pbVar4[2] & 0xc0) == 0x80) {
                iVar11 = (int)pcVar8 * 0x40 + (uint)pbVar4[2];
                pcVar8 = (char *)(iVar11 - 0x20080);
                if (((uint)pcVar8 & 0x10000) == 0) {
                  uVar1 = iVar11 - 0x2d880;
                  if ((((uVar1 < 0x400) && (pbVar4[3] == 0xed)) && ((byte)(pbVar4[4] + 0x50) < 0x10)
                      ) && ((pbVar4[5] & 0xc0) == 0x80)) {
                    pcVar8 = (char *)(pbVar4[5] + 0xff80 + (uint)(byte)(pbVar4[4] + 0x50) * 0x40 +
                                     uVar1 * 0x400);
                    iVar11 = 6;
                  }
                  else {
                    iVar11 = 3;
                    pcVar12 = (char *)0x800;
LAB_000c21c2:
                    if (pcVar8 < pcVar12) goto LAB_000c1ff7;
                  }
                  if ((((char *)0x7ff < pcVar8 + -0xd800) &&
                      (pcVar8 < Netchan_OutOfBandPrint::string + 0xf20)) &&
                     (((ushort)pcVar8 < 0xfffe && ((char *)0x1f < pcVar8 + -0xfdd0))))
                  goto joined_r0x000c2000;
                }
                else {
                  if ((pbVar4[3] & 0xc0) == 0x80) {
                    pcVar12 = "\x7fELF\x01\x01\x01";
                    pcVar8 = (char *)((int)pcVar8 * 0x40 + -0x400080 + (uint)pbVar4[3]);
                    iVar11 = 4;
                    goto LAB_000c21c2;
                  }
                  iVar11 = 3;
                }
              }
              else {
                iVar11 = 2;
              }
            }
            else {
              iVar11 = 1;
            }
LAB_000c1ff7:
            pcVar8 = (char *)0x3f;
          }
joined_r0x000c2000:
          if ((int)uVar10 <= iVar6 + 1) {
            iVar13 = iVar6 << 2;
            uVar10 = (iVar6 + 1) * 4 - 8;
            goto LAB_000c2035;
          }
          iVar13 = iVar6 + 1;
          pbVar4 = pbVar4 + iVar11;
          bVar2 = *pbVar4;
          __ptr[iVar6] = (wchar_t)pcVar8;
          iVar6 = iVar13;
        } while (bVar2 != 0);
        iVar13 = iVar13 * 4;
        uVar10 = iVar13 - 4;
      }
LAB_000c2035:
      *(undefined4 *)((int)__ptr + iVar13) = 0;
    }
  }
                    /* Unresolved local var: wchar_t * pwchSource@[???]
                       Unresolved local var: wchar_t * pwchDest@[???] */
  wVar9 = *__ptr;
  pwVar7 = __ptr;
  pwVar5 = __ptr;
  if (wVar9 == L'\0') {
    bVar14 = false;
    local_34 = 0;
  }
  else {
    do {
                    /* Unresolved local var: qboolean bIsDeprecated@[???] */
      if ((L'\x1f' < wVar9) &&
         (((wVar9 < L'\x202a' || ((L'\x202e' < wVar9 && (5 < (uint)(wVar9 + L'\xffffdf96'))))) &&
          (wVar9 != L'\x85')))) {
        *pwVar7 = wVar9;
        pwVar7 = pwVar7 + 1;
      }
      pwVar5 = pwVar5 + 1;
      wVar9 = *pwVar5;
    } while (wVar9 != L'\0');
    bVar14 = pwVar5 != pwVar7;
    local_34 = (uint)bVar14;
  }
                    /* Unresolved local var: wchar_t * pwchEnd@[???] */
  pwVar5 = (wchar_t *)(uVar10 + (int)__ptr);
  *pwVar7 = L'\0';
  pwVar7 = __ptr;
  if (CARRY4(uVar10,(uint)__ptr)) {
LAB_000c2162:
    if (!bVar14) goto LAB_000c216d;
  }
  else {
    bVar2 = 0;
    do {
      while( true ) {
        wVar9 = *pwVar5;
        iVar6 = iswspace(wVar9);
        if (iVar6 == 0) break;
LAB_000c2290:
        *pwVar5 = L'\0';
joined_r0x000c229e:
        bVar2 = 1;
        pwVar5 = pwVar5 + -1;
        if (pwVar5 < __ptr) goto LAB_000c22a6;
      }
                    /* Unresolved local var: qboolean bIsMean@[???] */
      if (L'\x2029' < wVar9) {
        if (wVar9 == L'\x2060') goto LAB_000c2290;
        if (wVar9 < L'⁡') {
          if (wVar9 == L'\x202f') {
            *pwVar5 = L'\0';
            goto joined_r0x000c229e;
          }
        }
        else if ((wVar9 == L'\xfeff') || (wVar9 == L'￼')) goto LAB_000c2290;
        goto LAB_000c20f9;
      }
      if ((L'‧' < wVar9) || (wVar9 == L'͏')) goto LAB_000c2290;
      if (wVar9 < L'͐') {
        if ((uint)(wVar9 + L'\xffffff80') < 0x21) goto LAB_000c2290;
LAB_000c20f9:
        pwVar3 = __ptr;
        if (__ptr < pwVar5) goto LAB_000c2110;
        bVar14 = (bool)(bVar14 | bVar2);
        goto LAB_000c2162;
      }
      if (0xd < (uint)(wVar9 + L'\xffffe000')) goto LAB_000c20f9;
      *pwVar5 = L'\0';
      pwVar5 = pwVar5 + -1;
      bVar2 = 1;
    } while (__ptr <= pwVar5);
  }
  goto LAB_000c22a6;
LAB_000c2110:
  do {
    pwVar7 = pwVar3;
    wVar9 = *pwVar7;
    iVar6 = iswspace(wVar9);
    if (iVar6 == 0) {
                    /* Unresolved local var: qboolean bIsMean@[???] */
      if (wVar9 < L'\x202a') {
        if ((wVar9 < L'\x2028') && (wVar9 != L'͏')) {
          if (wVar9 < L'͐') {
            if (0x20 < (uint)(wVar9 + L'\xffffff80')) goto LAB_000c2158;
          }
          else if (0xd < (uint)(wVar9 + L'\xffffe000')) goto LAB_000c2158;
        }
      }
      else if (wVar9 != L'\x2060') {
        if (wVar9 < L'⁡') {
          if (wVar9 != L'\x202f') goto LAB_000c2158;
        }
        else if ((wVar9 != L'\xfeff') && (wVar9 != L'￼')) {
LAB_000c2158:
          bVar14 = (bool)(bVar14 | bVar2);
          goto LAB_000c2162;
        }
      }
    }
    bVar2 = 1;
    pwVar3 = pwVar7 + 1;
  } while (pwVar7 + 1 < pwVar5);
  pwVar7 = pwVar7 + 1;
LAB_000c22a6:
  anon_unknown.dwarf_159333::
  Q_UnicodeConvertT<wchar_t,_char,_true,_(anonymous_namespace)::Q_UTF32ToUChar32,_Q_UChar32ToUTF8Len,_Q_UChar32ToUTF8>
            (pwVar7,(int)pch,pOut,4,(EStringConvertErrorPolicy)in_stack_ffffffb8);
LAB_000c216d:
  free(__ptr);
  return local_34;
}


// Q_UChar32ToUTF16  @ 000bffc0
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


// Q_UChar32ToUTF16Len  @ 000bffb0
int Q_UChar32ToUTF16Len(uchar32 uVal)

{
  return (0xffff < uVal) + 1;
}


// Q_UChar32ToUTF8  @ 000c0010
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


// Q_UChar32ToUTF8Len  @ 000bff80
int Q_UChar32ToUTF8Len(uchar32 uVal)

{
  int iVar1;
  
  iVar1 = 1;
  if ((0x7f < uVal) && (iVar1 = 2, 0x7ff < uVal)) {
    return (0xffff < uVal) + 3;
  }
  return iVar1;
}


// Q_UTF16ToUChar32  @ 000c00c0
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


// Q_UTF16ToUTF32  @ 000c0f80
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
            if (uVar8 - 0xfdd0 < 0x20) goto LAB_000c12d0;
            pUTF16 = pUTF16 + 1;
            uVar8 = (uint)*pUTF16;
            iVar7 = iVar7 + 1;
            if (uVar8 == 0) goto LAB_000c1037;
          }
          if ((uVar9 < 0x400) && (puVar1 = pUTF16 + 1, *puVar1 - 0xdc00 < 0x400)) {
            pUTF16 = pUTF16 + 2;
            iVar7 = iVar7 + (uint)((*puVar1 + 0x2400 + uVar9 * 0x400 & 0xffff) < 0xfffe);
          }
          else {
LAB_000c12d0:
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
          if (uVar8 - 0xfdd0 < 0x20) goto LAB_000c1475;
          pUTF16 = pUTF16 + 1;
          uVar8 = (uint)*pUTF16;
          iVar7 = iVar7 + 1;
          if (uVar8 == 0) goto LAB_000c1037;
        }
        if ((uVar9 < 0x400) && (puVar1 = pUTF16 + 1, *puVar1 - 0xdc00 < 0x400)) {
          pUTF16 = pUTF16 + 2;
          iVar7 = iVar7 + (uint)((*puVar1 + 0x2400 + uVar9 * 0x400 & 0xffff) < 0xfffe);
        }
        else {
LAB_000c1475:
          pUTF16 = pUTF16 + 1;
        }
      }
    }
    goto LAB_000c1037;
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
            goto LAB_000c105d;
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
LAB_000c105d:
          iVar4 = 2;
        }
        iVar7 = iVar5 + 1;
        if ((int)uVar8 <= iVar5 + 1) goto LAB_000c1030;
        pUTF32[iVar5] = uVar9;
        iVar5 = iVar5 + 1;
      }
LAB_000c11c0:
      iVar7 = iVar5 + 1;
    }
    else {
      iVar4 = 1;
      while (uVar9 = (uint)*pUTF16, iVar7 = iVar4, uVar9 != 0) {
LAB_000c0fd7:
        iVar4 = iVar7;
        uVar2 = uVar9 - 0xd800;
        iVar7 = iVar4;
        if ((0x7ff < uVar2) && (uVar9 < 0xfffe)) {
          iVar6 = 2;
          if (uVar9 - 0xfdd0 < 0x20) goto LAB_000c1130;
LAB_000c1009:
          pUTF16 = (uchar16 *)((int)pUTF16 + iVar6);
          if ((int)uVar8 <= iVar4) break;
          pUTF32[iVar5] = uVar9;
          uVar9 = (uint)*pUTF16;
          iVar7 = iVar4 + 1;
          iVar5 = iVar4;
          if (uVar9 == 0) break;
          goto LAB_000c0fd7;
        }
        if ((uVar2 < 0x400) && (pUTF16[1] - 0xdc00 < 0x400)) {
          uVar9 = pUTF16[1] + 0x2400 + uVar2 * 0x400;
          iVar6 = 4;
          if (0xfffd < (ushort)uVar9) goto LAB_000c1130;
          goto LAB_000c1009;
        }
        iVar6 = 2;
LAB_000c1130:
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
          goto LAB_000c13d8;
          iVar7 = 4;
        }
        else {
          if (uVar9 - 0xfdd0 < 0x20) {
LAB_000c13d8:
            iVar7 = iVar5 + 1;
            if (iVar7 < (int)uVar8) {
              pUTF32[iVar5] = 0x3f;
              *pUTF32 = 0;
              return 0;
            }
            goto LAB_000c1030;
          }
          iVar7 = 2;
        }
        pUTF16 = (uchar16 *)((int)pUTF16 + iVar7);
        iVar7 = iVar5 + 1;
        if ((int)uVar8 <= iVar7) goto LAB_000c1030;
        pUTF32[iVar5] = uVar9;
        iVar5 = iVar7;
        uVar3 = *pUTF16;
      }
      goto LAB_000c11c0;
    }
    iVar4 = 1;
    while (uVar9 = (uint)*pUTF16, iVar7 = iVar4, uVar9 != 0) {
LAB_000c12fb:
      iVar4 = iVar7;
      uVar2 = uVar9 - 0xd800;
      iVar7 = iVar4;
      if ((0x7ff < uVar2) && (uVar9 < 0xfffe)) {
        iVar6 = 2;
        if (uVar9 - 0xfdd0 < 0x20) goto LAB_000c1370;
LAB_000c1321:
        pUTF16 = (uchar16 *)((int)pUTF16 + iVar6);
        if ((int)uVar8 <= iVar4) break;
        pUTF32[iVar5] = uVar9;
        uVar9 = (uint)*pUTF16;
        iVar7 = iVar4 + 1;
        iVar5 = iVar4;
        if (uVar9 == 0) break;
        goto LAB_000c12fb;
      }
      if ((uVar2 < 0x400) && (pUTF16[1] - 0xdc00 < 0x400)) {
        uVar9 = pUTF16[1] + 0x2400 + uVar2 * 0x400;
        iVar6 = 4;
        if (0xfffd < (ushort)uVar9) goto LAB_000c1370;
        goto LAB_000c1321;
      }
      iVar6 = 2;
LAB_000c1370:
      pUTF16 = (uchar16 *)((int)pUTF16 + iVar6);
      if ((int)uVar8 <= iVar4) break;
      pUTF32[iVar5] = 0x3f;
    }
  }
LAB_000c1030:
  pUTF32[iVar5] = 0;
LAB_000c1037:
  return iVar7 << 2;
}


// Q_UTF16ToUTF8  @ 000c0a80
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
            goto LAB_000c0df0;
            pUTF16 = pUTF16 + 2;
            uVar8 = *puVar11 + 0x2400 + uVar1 * 0x400;
            if ((ushort)uVar8 < 0xfffe) goto LAB_000c0cd3;
LAB_000c0de1:
            iVar9 = iVar9 + 1;
          }
          else if (uVar8 - 0xfdd0 < 0x20) {
LAB_000c0df0:
            pUTF16 = pUTF16 + 1;
            iVar9 = iVar9 + 1;
          }
          else {
            pUTF16 = pUTF16 + 1;
            if (uVar8 < 0x80) goto LAB_000c0de1;
LAB_000c0cd3:
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
            goto LAB_000c0e00;
                    /* Unresolved local var: uchar32 uVal@[???] */
            pUTF16 = pUTF16 + 2;
            uVar8 = *puVar11 + 0x2400 + uVar1 * 0x400;
            if ((ushort)uVar8 < 0xfffe) {
LAB_000c0d6b:
              if ((int)uVar8 < 0x800) {
                iVar9 = iVar9 + 2;
              }
              else {
                iVar9 = iVar9 + (0xffff < (int)uVar8) + 3;
              }
            }
          }
          else if (uVar8 - 0xfdd0 < 0x20) {
LAB_000c0e00:
            pUTF16 = pUTF16 + 1;
          }
          else {
            pUTF16 = pUTF16 + 1;
            if (0x7f < uVar8) goto LAB_000c0d6b;
            iVar9 = iVar9 + 1;
          }
        }
      }
    }
    else if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
LAB_000c0e1f:
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
            goto LAB_000c0e1f;
          }
        }
        if ((int)uVar8 < 0x800) {
          iVar9 = iVar9 + 2;
        }
        else {
          iVar9 = iVar9 + (0xffff < (int)uVar8) + 3;
        }
        goto LAB_000c0e1f;
      }
    }
    else {
      while (uVar8 = (uint)*pUTF16, uVar8 != 0) {
        uVar1 = uVar8 - 0xd800;
        if ((uVar1 < 0x800) || (0xfffd < uVar8)) {
          if ((0x3ff < uVar1) || (0x3ff < pUTF16[1] - 0xdc00)) goto LAB_000c0f47;
          uVar8 = pUTF16[1] + 0x2400 + uVar1 * 0x400;
          if ((ushort)uVar8 < 0xfffe) {
            pUTF16 = pUTF16 + 2;
            goto LAB_000c0ea4;
          }
          pUTF16 = pUTF16 + 2;
        }
        else if (uVar8 - 0xfdd0 < 0x20) {
LAB_000c0f47:
          pUTF16 = pUTF16 + 1;
        }
        else {
          pUTF16 = pUTF16 + 1;
          if (uVar8 < 0x80) {
            iVar9 = iVar9 + 1;
          }
          else {
LAB_000c0ea4:
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
LAB_000c0ac0:
  uVar8 = (uint)*pUTF16;
  iVar4 = iVar9;
  puVar11 = pUTF16;
  if (uVar8 != 0) {
    do {
      uVar1 = uVar8 - 0xd800;
      if ((uVar1 < 0x800) || (0xfffd < uVar8)) {
        if ((0x3ff < uVar1) || (0x3ff < puVar11[1] - 0xdc00)) goto LAB_000c0ba0;
                    /* Unresolved local var: uchar32 uVal@[???] */
        pUTF16 = puVar11 + 2;
        uVar8 = puVar11[1] + 0x2400 + uVar1 * 0x400;
        if ((ushort)uVar8 < 0xfffe) goto LAB_000c0af7;
        iVar9 = iVar4 + 1;
        if (cubDestSizeInBytes <= iVar9) goto LAB_000c0b2b;
        cVar7 = '?';
        bVar2 = true;
LAB_000c0b80:
        pUTF8[iVar4] = cVar7;
        iVar9 = iVar4 + 1;
        if (((bVar2) && (iVar9 = iVar4, (ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE)) &&
           (iVar9 = iVar4 + 1, (ePolicy & STRINGCONVERT_FAIL) != STRINGCONVERT_REPLACE)) {
          *pUTF8 = '\0';
          return 0;
        }
        goto LAB_000c0ac0;
      }
      if (uVar8 - 0xfdd0 < 0x20) {
LAB_000c0ba0:
        uVar8 = 0x3f;
        bVar2 = true;
LAB_000c0bad:
        pUTF16 = puVar11 + 1;
        cVar7 = (char)uVar8;
        iVar9 = iVar4 + 1;
        if (iVar9 < cubDestSizeInBytes) goto LAB_000c0b80;
        goto LAB_000c0b2b;
      }
      pUTF16 = puVar11 + 1;
      if (uVar8 < 0x80) {
        bVar2 = false;
        goto LAB_000c0bad;
      }
LAB_000c0af7:
      bVar6 = (byte)uVar8;
      bVar10 = (byte)((int)uVar8 >> 6);
      if (0x7ff < (int)uVar8) goto LAB_000c0be0;
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
  goto LAB_000c0b28;
LAB_000c0be0:
  bVar3 = (byte)((int)uVar8 >> 0xc);
  if ((int)uVar8 < 0x10000) {
    if (iVar4 + 3 < cubDestSizeInBytes) {
      pbVar5 = (byte *)(pUTF8 + iVar4);
      *pbVar5 = bVar3 | 0xe0;
      pbVar5[1] = bVar10 & 0x3f | 0x80;
      pbVar5[2] = bVar6 & 0x3f | 0x80;
      iVar9 = iVar4 + 3;
      goto LAB_000c0ac0;
    }
  }
  else if (iVar4 + 4 < cubDestSizeInBytes) {
    pbVar5 = (byte *)(pUTF8 + iVar4);
    *pbVar5 = (byte)((int)uVar8 >> 0x12) | 0xf0;
    pbVar5[1] = bVar3 & 0x3f | 0x80;
    pbVar5[2] = bVar10 & 0x3f | 0x80;
    pbVar5[3] = bVar6 & 0x3f | 0x80;
    iVar9 = iVar4 + 4;
    goto LAB_000c0ac0;
  }
LAB_000c0b28:
  iVar9 = iVar4 + 1;
LAB_000c0b2b:
  pUTF8[iVar4] = '\0';
  return iVar9;
}


// Q_UTF32ToUTF16  @ 000c1510
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF32ToUTF16(uchar32 *pUTF32,uchar16 *pUTF16,int cubDestSizeInBytes,
                  EStringConvertErrorPolicy ePolicy)

{
  bool bVar1;
  uint *puVar2;
  ushort uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uchar32 *puVar8;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF16 == (uchar16 *)0x0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
      iVar6 = 0;
      if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
        while( true ) {
          pcVar4 = (char *)*pUTF32;
          if (pcVar4 == (char *)0x0) break;
          if ((((pcVar4 + -0xd800 < (char *)0x800) ||
               (Netchan_OutOfBandPrint::string + 0xf1f < pcVar4)) || (0xfffd < (ushort)pcVar4)) ||
             ((pcVar4 + -0xfdd0 < (char *)0x20 || ((int)pcVar4 < 0x10000)))) {
            iVar6 = iVar6 + 1;
            pUTF32 = pUTF32 + 1;
          }
          else {
            iVar6 = iVar6 + 2;
            pUTF32 = pUTF32 + 1;
          }
        }
      }
      else {
        iVar6 = 0;
        while (pcVar4 = (char *)*pUTF32, pcVar4 != (char *)0x0) {
          while( true ) {
            if (((pcVar4 + -0xd800 < (char *)0x800) ||
                (Netchan_OutOfBandPrint::string + 0xf1f < pcVar4)) ||
               ((0xfffd < (ushort)pcVar4 || (pcVar4 + -0xfdd0 < (char *)0x20)))) {
              _DAT_00000000 = 0;
              return 0;
            }
            pUTF32 = pUTF32 + 1;
            if ((int)pcVar4 < 0x10000) break;
            iVar6 = iVar6 + 2;
            pcVar4 = (char *)*pUTF32;
            if (pcVar4 == (char *)0x0) goto LAB_000c1700;
          }
          iVar6 = iVar6 + 1;
        }
      }
    }
    else {
      iVar6 = 0;
      while( true ) {
        puVar2 = (uint *)(pUTF32 + 1);
        pcVar4 = (char *)*pUTF32;
        if (pcVar4 == (char *)0x0) break;
        pUTF32 = (uchar32 *)puVar2;
        if (((((char *)0x7ff < pcVar4 + -0xd800) &&
             (pcVar4 < Netchan_OutOfBandPrint::string + 0xf20)) && ((ushort)pcVar4 < 0xfffe)) &&
           ((char *)0x1f < pcVar4 + -0xfdd0)) {
          if ((int)pcVar4 < 0x10000) {
            iVar6 = iVar6 + 1;
          }
          else {
            iVar6 = iVar6 + 2;
          }
        }
      }
    }
LAB_000c1700:
    iVar6 = iVar6 + 1;
  }
  else {
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
    uVar7 = (uint)cubDestSizeInBytes >> 1;
    if (uVar7 == 0) {
      return 0;
    }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
      puVar8 = pUTF32 + 1;
      iVar5 = 0;
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
        pcVar4 = (char *)*pUTF32;
        while (pcVar4 != (char *)0x0) {
          if (((pcVar4 + -0xd800 < (char *)0x800) ||
              (Netchan_OutOfBandPrint::string + 0xf1f < pcVar4)) ||
             ((0xfffd < (ushort)pcVar4 || (pcVar4 + -0xfdd0 < (char *)0x20)))) {
            pcVar4 = (char *)0x3f;
LAB_000c15e8:
            iVar6 = iVar5 + 1;
            if ((int)uVar7 <= iVar6) goto LAB_000c1563;
            uVar3 = (ushort)pcVar4;
          }
          else {
            if ((int)pcVar4 < 0x10000) goto LAB_000c15e8;
            iVar6 = iVar5 + 2;
            if ((int)uVar7 <= iVar6) break;
            uVar3 = (ushort)((int)(pcVar4 + -0x10000) >> 10) | 0xd800;
            (pUTF16 + iVar5)[1] = (ushort)(pcVar4 + -0x10000) & 0x3ff | 0xdc00;
          }
          pUTF16[iVar5] = uVar3;
          pcVar4 = (char *)*puVar8;
          iVar5 = iVar6;
          puVar8 = puVar8 + 1;
        }
      }
      else {
        for (; pcVar4 = (char *)puVar8[-1], pcVar4 != (char *)0x0; puVar8 = puVar8 + 1) {
          if ((((pcVar4 + -0xd800 < (char *)0x800) ||
               (Netchan_OutOfBandPrint::string + 0xf1f < pcVar4)) || (0xfffd < (ushort)pcVar4)) ||
             (pcVar4 + -0xfdd0 < (char *)0x20)) {
            pcVar4 = (char *)0x3f;
            bVar1 = true;
LAB_000c167b:
            iVar6 = iVar5 + 1;
            if ((int)uVar7 <= iVar6) goto LAB_000c1563;
            pUTF16[iVar5] = (uchar16)pcVar4;
            if (bVar1) {
              iVar6 = iVar5;
            }
          }
          else {
            if ((int)pcVar4 < 0x10000) {
              bVar1 = false;
              goto LAB_000c167b;
            }
            if ((int)uVar7 <= iVar5 + 2) break;
            (pUTF16 + iVar5)[1] = (ushort)(pcVar4 + -0x10000) & 0x3ff | 0xdc00;
            pUTF16[iVar5] = (ushort)((int)(pcVar4 + -0x10000) >> 10) | 0xd800;
            iVar6 = iVar5 + 2;
          }
          iVar5 = iVar6;
        }
      }
    }
    else {
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
        iVar6 = 0;
        do {
          pcVar4 = (char *)*pUTF32;
          iVar5 = iVar6;
          while( true ) {
            if (pcVar4 == (char *)0x0) goto LAB_000c1560;
            pUTF32 = pUTF32 + 1;
            if (((pcVar4 + -0xd800 < (char *)0x800) ||
                (Netchan_OutOfBandPrint::string + 0xf20 <= pcVar4)) ||
               ((0xfffd < (ushort)pcVar4 || (pcVar4 + -0xfdd0 < &DAT_00000020)))) {
              pcVar4 = (char *)0x3f;
              bVar1 = true;
              goto LAB_000c18a7;
            }
            if ((int)pcVar4 < 0x10000) break;
            if ((int)uVar7 <= iVar5 + 2) goto LAB_000c1560;
            (pUTF16 + iVar5)[1] = (ushort)(pcVar4 + -0x10000) & 0x3ff | 0xdc00;
            pUTF16[iVar5] = (ushort)((int)(pcVar4 + -0x10000) >> 10) | 0xd800;
            pcVar4 = (char *)*pUTF32;
            iVar5 = iVar5 + 2;
          }
          bVar1 = false;
LAB_000c18a7:
          iVar6 = iVar5 + 1;
          if ((int)uVar7 <= iVar6) goto LAB_000c1563;
          pUTF16[iVar5] = (uchar16)pcVar4;
          if (bVar1) {
            *pUTF16 = 0;
            return 0;
          }
        } while( true );
      }
      iVar6 = 0;
      while( true ) {
        iVar5 = iVar6;
        puVar2 = (uint *)(pUTF32 + 1);
        pcVar4 = (char *)*pUTF32;
        if (pcVar4 == (char *)0x0) break;
        pUTF32 = (uchar32 *)puVar2;
        if (((pcVar4 + -0xd800 < (char *)0x800) || (Netchan_OutOfBandPrint::string + 0xf1f < pcVar4)
            ) || ((0xfffd < (ushort)pcVar4 || (pcVar4 + -0xfdd0 < (char *)0x20)))) {
          pcVar4 = (char *)0x3f;
          bVar1 = true;
LAB_000c17fb:
          iVar6 = iVar5 + 1;
          if ((int)uVar7 <= iVar6) goto LAB_000c1563;
          pUTF16[iVar5] = (uchar16)pcVar4;
          if (bVar1) {
            iVar6 = iVar5;
          }
        }
        else {
          if ((int)pcVar4 < 0x10000) {
            bVar1 = false;
            goto LAB_000c17fb;
          }
          if ((int)uVar7 <= iVar5 + 2) break;
          (pUTF16 + iVar5)[1] = (ushort)(pcVar4 + -0x10000) & 0x3ff | 0xdc00;
          pUTF16[iVar5] = (ushort)((int)(pcVar4 + -0x10000) >> 10) | 0xd800;
          iVar6 = iVar5 + 2;
        }
      }
    }
LAB_000c1560:
    iVar6 = iVar5 + 1;
LAB_000c1563:
    pUTF16[iVar5] = 0;
  }
  return iVar6 * 2;
}


// Q_UTF32ToUTF8  @ 000c14f0
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF32ToUTF8(uchar32 *pUTF32,char *pUTF8,int cubDestSizeInBytes,
                 EStringConvertErrorPolicy ePolicy)

{
  int iVar1;
  
  iVar1 = anon_unknown.dwarf_159333::
          Q_UnicodeConvertT<wchar_t,_char,_true,_(anonymous_namespace)::Q_UTF32ToUChar32,_Q_UChar32ToUTF8Len,_Q_UChar32ToUTF8>
                    (pUTF32,(int)pUTF8,(char *)cubDestSizeInBytes,ePolicy,
                     (EStringConvertErrorPolicy)pUTF8);
  return iVar1;
}


// Q_UTF8ToUChar32  @ 000c1960
int Q_UTF8ToUChar32(char *pUTF8_,uchar32 *uValueOut,bool *bErrorOut)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
  pcVar4 = (char *)(uint)(byte)*pUTF8_;
  if (pcVar4 < (char *)0x80) {
    iVar2 = 1;
    goto LAB_000c19d5;
  }
  if ((char *)0x37 < pcVar4 + -0xc0) {
    iVar2 = 1;
    goto LAB_000c199a;
  }
  iVar2 = 1;
  if ((pUTF8_[1] & 0xc0U) != 0x80) goto LAB_000c199a;
  pcVar4 = (char *)((int)pcVar4 * 0x40 + -0x3080 + (uint)(byte)pUTF8_[1]);
  if (((uint)pcVar4 & 0x800) == 0) {
    pcVar3 = (char *)0x80;
    iVar2 = 2;
    goto LAB_000c1a6a;
  }
  iVar2 = 2;
  if ((pUTF8_[2] & 0xc0U) != 0x80) goto LAB_000c199a;
  iVar2 = (uint)(byte)pUTF8_[2] + (int)pcVar4 * 0x40;
  pcVar4 = (char *)(iVar2 - 0x20080);
  if (((uint)pcVar4 & 0x10000) == 0) {
    uVar1 = iVar2 - 0x2d880;
    if ((((0x3ff < uVar1) || (pUTF8_[3] != -0x13)) || (0xf < (byte)(pUTF8_[4] + 0x50U))) ||
       ((pUTF8_[5] & 0xc0U) != 0x80)) {
      pcVar3 = (char *)0x800;
      iVar2 = 3;
      goto LAB_000c1a6a;
    }
    iVar2 = 6;
    pcVar4 = (char *)((uint)(byte)(pUTF8_[4] + 0x50U) * 0x40 + 0xff80 + (uint)(byte)pUTF8_[5] +
                     uVar1 * 0x400);
  }
  else {
    iVar2 = 3;
    if ((pUTF8_[3] & 0xc0U) != 0x80) goto LAB_000c199a;
    pcVar3 = "\x7fELF\x01\x01\x01";
    pcVar4 = (char *)((int)pcVar4 * 0x40 + -0x400080 + (uint)(byte)pUTF8_[3]);
    iVar2 = 4;
LAB_000c1a6a:
    if (pcVar4 < pcVar3) goto LAB_000c199a;
  }
  if ((((char *)0x7ff < pcVar4 + -0xd800) && (pcVar4 < Netchan_OutOfBandPrint::string + 0xf20)) &&
     (((ushort)pcVar4 < 0xfffe && ((char *)0x1f < pcVar4 + -0xfdd0)))) {
LAB_000c19d5:
    *uValueOut = (uchar32)pcVar4;
    *bErrorOut = false;
    return iVar2;
  }
LAB_000c199a:
  *uValueOut = 0x3f;
  *bErrorOut = true;
  return iVar2;
}


// Q_UTF8ToUTF16  @ 000c0190
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF8ToUTF16(char *pUTF8,uchar16 *pUTF16,int cubDestSizeInBytes,
                 EStringConvertErrorPolicy ePolicy)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF16 == (uchar16 *)0x0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar6 = 0;
LAB_000c0420:
    bVar1 = *pUTF8;
    do {
      if (bVar1 == 0) goto LAB_000c025a;
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
      if (bVar1 < 0x80) {
        pUTF8 = pUTF8 + 1;
LAB_000c0479:
        iVar6 = iVar6 + 1;
        goto LAB_000c0420;
      }
      if (bVar1 - 0xc0 < 0x38) {
        iVar3 = 1;
        if ((pUTF8[1] & 0xc0U) == 0x80) {
          pcVar8 = (char *)((uint)bVar1 * 0x40 + -0x3080 + (uint)(byte)pUTF8[1]);
          if (((uint)pcVar8 & 0x800) == 0) {
            iVar3 = 2;
            pcVar4 = (char *)0x80;
            goto LAB_000c0512;
          }
          iVar3 = 2;
          if ((pUTF8[2] & 0xc0U) == 0x80) {
            iVar3 = (int)pcVar8 * 0x40 + (uint)(byte)pUTF8[2];
            pcVar8 = (char *)(iVar3 - 0x20080);
            if (((uint)pcVar8 & 0x10000) == 0) {
              uVar5 = iVar3 - 0x2d880;
              if ((((0x3ff < uVar5) || (pUTF8[3] != 0xed)) || (0xf < (byte)(pUTF8[4] + 0x50U))) ||
                 ((pUTF8[5] & 0xc0U) != 0x80)) {
                iVar3 = 3;
                pcVar4 = (char *)0x800;
                goto LAB_000c0512;
              }
              pcVar8 = (char *)((uint)(byte)(pUTF8[4] + 0x50U) * 0x40 + 0xff80 +
                                (uint)(byte)pUTF8[5] + uVar5 * 0x400);
              iVar3 = 6;
LAB_000c051a:
              if ((((char *)0x7ff < pcVar8 + -0xd800) &&
                  (pcVar8 < Netchan_OutOfBandPrint::string + 0xf20)) &&
                 (((ushort)pcVar8 < 0xfffe && ((char *)0x1f < pcVar8 + -0xfdd0)))) {
                pUTF8 = pUTF8 + iVar3;
                if (pcVar8 < "\x7fELF\x01\x01\x01") goto LAB_000c0479;
                iVar6 = iVar6 + 2;
                goto LAB_000c0420;
              }
            }
            else {
              iVar3 = 3;
              if ((pUTF8[3] & 0xc0U) == 0x80) {
                iVar3 = 4;
                pcVar8 = (char *)((int)pcVar8 * 0x40 + -0x400080 + (uint)(byte)pUTF8[3]);
                pcVar4 = "\x7fELF\x01\x01\x01";
LAB_000c0512:
                if (pcVar4 <= pcVar8) goto LAB_000c051a;
              }
            }
          }
        }
      }
      else {
        iVar3 = 1;
      }
      pUTF8 = pUTF8 + iVar3;
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) goto code_r0x000c0454;
      bVar1 = *pUTF8;
    } while( true );
  }
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
  uVar5 = (uint)cubDestSizeInBytes >> 1;
  if (uVar5 == 0) {
    return 0;
  }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
  iVar3 = 0;
LAB_000c01d0:
  bVar1 = *pUTF8;
  iVar6 = iVar3;
  do {
    if (bVar1 == 0) goto LAB_000c0253;
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
    pcVar8 = (char *)(uint)(byte)*pUTF8;
    if (pcVar8 < (char *)0x80) {
      pUTF8 = pUTF8 + 1;
      bVar2 = false;
    }
    else {
      if (pcVar8 + -0xc0 < (char *)0x38) {
        iVar3 = 1;
        if ((pUTF8[1] & 0xc0U) == 0x80) {
          pcVar8 = (char *)((int)pcVar8 * 0x40 + -0x3080 + (uint)(byte)pUTF8[1]);
          if (((uint)pcVar8 & 0x800) == 0) {
            iVar3 = 2;
            pcVar4 = (char *)0x80;
LAB_000c03a2:
            if (pcVar4 <= pcVar8) {
LAB_000c0310:
              if (((((char *)0x7ff < pcVar8 + -0xd800) &&
                   (pcVar8 < Netchan_OutOfBandPrint::string + 0xf20)) && ((ushort)pcVar8 < 0xfffe))
                 && ((char *)0x1f < pcVar8 + -0xfdd0)) {
                pUTF8 = pUTF8 + iVar3;
                if (pcVar8 < "\x7fELF\x01\x01\x01") {
                  bVar2 = false;
                  goto LAB_000c0210;
                }
                iVar3 = iVar6 + 2;
                if ((int)uVar5 <= iVar3) goto LAB_000c0253;
                (pUTF16 + iVar6)[1] = (ushort)(pcVar8 + -0x10000) & 0x3ff | 0xdc00;
                pUTF16[iVar6] = (ushort)((int)(pcVar8 + -0x10000) >> 10) | 0xd800;
                goto LAB_000c01d0;
              }
            }
          }
          else {
            iVar3 = 2;
            if ((pUTF8[2] & 0xc0U) == 0x80) {
              iVar3 = (int)pcVar8 * 0x40 + (uint)(byte)pUTF8[2];
              pcVar8 = (char *)(iVar3 - 0x20080);
              if (((uint)pcVar8 & 0x10000) == 0) {
                uVar7 = iVar3 - 0x2d880;
                if (((uVar7 < 0x400) && (pUTF8[3] == 0xed)) &&
                   (((byte)(pUTF8[4] + 0x50U) < 0x10 && ((pUTF8[5] & 0xc0U) == 0x80)))) {
                  pcVar8 = (char *)((uint)(byte)(pUTF8[4] + 0x50U) * 0x40 + 0xff80 +
                                    (uint)(byte)pUTF8[5] + uVar7 * 0x400);
                  iVar3 = 6;
                }
                else {
                  iVar3 = 3;
                  if (pcVar8 < (char *)0x800) goto LAB_000c0207;
                }
                goto LAB_000c0310;
              }
              iVar3 = 3;
              if ((pUTF8[3] & 0xc0U) == 0x80) {
                iVar3 = 4;
                pcVar8 = (char *)((int)pcVar8 * 0x40 + -0x400080 + (uint)(byte)pUTF8[3]);
                pcVar4 = "\x7fELF\x01\x01\x01";
                goto LAB_000c03a2;
              }
            }
          }
        }
      }
      else {
        iVar3 = 1;
      }
LAB_000c0207:
      pUTF8 = pUTF8 + iVar3;
      pcVar8 = (char *)0x3f;
      bVar2 = true;
    }
LAB_000c0210:
    iVar3 = iVar6 + 1;
    if ((int)uVar5 <= iVar3) {
LAB_000c0253:
      pUTF16[iVar6] = 0;
LAB_000c025a:
      return (iVar6 + 1) * 2;
    }
    pUTF16[iVar6] = (uchar16)pcVar8;
    if (!bVar2) goto LAB_000c01d0;
    if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) goto LAB_000c0270;
    iVar6 = iVar3 - ((0xffff < (int)pcVar8) + 1);
    bVar1 = *pUTF8;
  } while( true );
code_r0x000c0454:
  iVar6 = iVar6 + 1;
  if ((ePolicy & STRINGCONVERT_FAIL) != STRINGCONVERT_REPLACE) {
    _DAT_00000000 = 0;
    return 0;
  }
  goto LAB_000c0420;
LAB_000c0270:
  if ((ePolicy & STRINGCONVERT_FAIL) != STRINGCONVERT_REPLACE) {
    *pUTF16 = 0;
    return 0;
  }
  goto LAB_000c01d0;
}


// Q_UTF8ToUTF32  @ 000c0630
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF8ToUTF32(char *pUTF8,uchar32 *pUTF32,int cubDestSizeInBytes,
                 EStringConvertErrorPolicy ePolicy)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF32 == (uchar32 *)0x0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar9 = 1;
LAB_000c0870:
    bVar2 = *pUTF8;
    if (bVar2 != 0) {
      while (0x7f < bVar2) {
        if (bVar2 - 0xc0 < 0x38) {
          iVar5 = 1;
          if ((pUTF8[1] & 0xc0U) == 0x80) {
            pcVar4 = (char *)((uint)bVar2 * 0x40 + -0x3080 + (uint)(byte)pUTF8[1]);
            if (((uint)pcVar4 & 0x800) == 0) {
              iVar5 = 2;
              pcVar6 = (char *)0x80;
              goto LAB_000c0952;
            }
            iVar5 = 2;
            if ((pUTF8[2] & 0xc0U) == 0x80) {
              iVar5 = (int)pcVar4 * 0x40 + (uint)(byte)pUTF8[2];
              pcVar4 = (char *)(iVar5 - 0x20080);
              if (((uint)pcVar4 & 0x10000) == 0) {
                uVar3 = iVar5 - 0x2d880;
                if (((uVar3 < 0x400) && (pUTF8[3] == 0xed)) &&
                   (((byte)(pUTF8[4] + 0x50U) < 0x10 && ((pUTF8[5] & 0xc0U) == 0x80)))) {
                  iVar5 = 6;
                  pcVar4 = (char *)((uint)(byte)(pUTF8[4] + 0x50U) * 0x40 + 0xff80 +
                                    (uint)(byte)pUTF8[5] + uVar3 * 0x400);
                }
                else {
                  iVar5 = 3;
                  pcVar6 = (char *)0x800;
LAB_000c0952:
                  if (pcVar4 < pcVar6) goto LAB_000c08a0;
                }
                if (((((char *)0x7ff < pcVar4 + -0xd800) &&
                     (pcVar4 < Netchan_OutOfBandPrint::string + 0xf20)) && ((ushort)pcVar4 < 0xfffe)
                    ) && ((char *)0x1f < pcVar4 + -0xfdd0)) goto LAB_000c08c7;
              }
              else {
                iVar5 = 3;
                if ((pUTF8[3] & 0xc0U) == 0x80) {
                  iVar5 = 4;
                  pcVar4 = (char *)((int)pcVar4 * 0x40 + -0x400080 + (uint)(byte)pUTF8[3]);
                  pcVar6 = "\x7fELF\x01\x01\x01";
                  goto LAB_000c0952;
                }
              }
            }
          }
        }
        else {
          iVar5 = 1;
        }
LAB_000c08a0:
        pUTF8 = pUTF8 + iVar5;
        if ((ePolicy & STRINGCONVERT_SKIP) != STRINGCONVERT_REPLACE) goto LAB_000c0870;
        if ((ePolicy & STRINGCONVERT_FAIL) != STRINGCONVERT_REPLACE) {
          _DAT_00000000 = 0;
          return 0;
        }
        bVar2 = *pUTF8;
        iVar9 = iVar9 + 1;
        if (bVar2 == 0) goto LAB_000c06fb;
      }
      iVar5 = 1;
LAB_000c08c7:
      pUTF8 = pUTF8 + iVar5;
      iVar9 = iVar9 + 1;
      goto LAB_000c0870;
    }
  }
  else {
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
    uVar3 = (uint)cubDestSizeInBytes >> 2;
    if (uVar3 == 0) {
      return 0;
    }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar5 = 0;
    iVar9 = 1;
LAB_000c0680:
    iVar8 = iVar9;
    if (*pUTF8 != 0) {
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
      while (pcVar4 = (char *)(uint)(byte)*pUTF8, iVar9 = iVar8, (char *)0x7f < pcVar4) {
        if (pcVar4 + -0xc0 < (char *)0x38) {
          iVar7 = 1;
          if ((pUTF8[1] & 0xc0U) == 0x80) {
            pcVar4 = (char *)((int)pcVar4 * 0x40 + -0x3080 + (uint)(byte)pUTF8[1]);
            if (((uint)pcVar4 & 0x800) == 0) {
              iVar7 = 2;
              pcVar6 = (char *)0x80;
LAB_000c07fa:
              if (pcVar6 <= pcVar4) {
LAB_000c07b0:
                if ((((char *)0x7ff < pcVar4 + -0xd800) &&
                    (pcVar4 < Netchan_OutOfBandPrint::string + 0xf20)) &&
                   (((ushort)pcVar4 < 0xfffe && ((char *)0x1f < pcVar4 + -0xfdd0))))
                goto LAB_000c0715;
              }
            }
            else {
              iVar7 = 2;
              if ((pUTF8[2] & 0xc0U) == 0x80) {
                iVar7 = (uint)(byte)pUTF8[2] + (int)pcVar4 * 0x40;
                pcVar4 = (char *)(iVar7 - 0x20080);
                if (((uint)pcVar4 & 0x10000) == 0) {
                  uVar1 = iVar7 - 0x2d880;
                  if ((((uVar1 < 0x400) && (pUTF8[3] == 0xed)) && ((byte)(pUTF8[4] + 0x50U) < 0x10))
                     && ((pUTF8[5] & 0xc0U) == 0x80)) {
                    iVar7 = 6;
                    pcVar4 = (char *)((byte)pUTF8[5] + 0xff80 +
                                      (uint)(byte)(pUTF8[4] + 0x50U) * 0x40 + uVar1 * 0x400);
                  }
                  else {
                    iVar7 = 3;
                    if (pcVar4 < (char *)0x800) goto LAB_000c06b7;
                    iVar7 = 3;
                  }
                  goto LAB_000c07b0;
                }
                iVar7 = 3;
                if ((pUTF8[3] & 0xc0U) == 0x80) {
                  iVar7 = 4;
                  pcVar4 = (char *)((int)pcVar4 * 0x40 + -0x400080 + (uint)(byte)pUTF8[3]);
                  pcVar6 = "\x7fELF\x01\x01\x01";
                  goto LAB_000c07fa;
                }
              }
            }
          }
        }
        else {
          iVar7 = 1;
        }
LAB_000c06b7:
        pUTF8 = pUTF8 + iVar7;
        if ((int)uVar3 <= iVar8) goto LAB_000c06f0;
        pUTF32[iVar5] = 0x3f;
        if ((ePolicy & STRINGCONVERT_SKIP) != STRINGCONVERT_REPLACE) goto LAB_000c0680;
        if ((ePolicy & STRINGCONVERT_FAIL) != STRINGCONVERT_REPLACE) {
          *pUTF32 = 0;
          return 0;
        }
        iVar9 = iVar8 + 1;
        iVar5 = iVar8;
        iVar8 = iVar9;
        if (*pUTF8 == 0) goto LAB_000c06f0;
      }
      iVar7 = 1;
LAB_000c0715:
      pUTF8 = pUTF8 + iVar7;
      if ((int)uVar3 <= iVar8) goto LAB_000c06f0;
      pUTF32[iVar5] = (uchar32)pcVar4;
      iVar9 = iVar8 + 1;
      iVar5 = iVar8;
      goto LAB_000c0680;
    }
LAB_000c06f0:
    pUTF32[iVar5] = 0;
  }
LAB_000c06fb:
  return iVar9 * 4;
}


// Q_UnicodeAdvance  @ 000c1df0
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


// Q_UnicodeLength  @ 000c1ce0
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


// Q_UnicodeRepair  @ 000c2670
int Q_UnicodeRepair(char *pUTF8)

{
  byte *pbVar1;
  bool bVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;
  byte bVar6;
  byte bVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  char *local_28;
  bool local_15;
  int local_14;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF8 != (char *)0x0) {
    iVar3 = 0;
    pbVar5 = (byte *)pUTF8;
LAB_000c2690:
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
        uVar9 = (uint)bVar4;
        if (uVar9 < 0x80) {
          pbVar5 = pbVar5 + 1;
          bVar2 = false;
        }
        else {
          if (uVar9 - 0xc0 < 0x38) {
            iVar10 = 1;
            if ((pbVar5[1] & 0xc0) == 0x80) {
              local_28 = (char *)(uVar9 * 0x40 + -0x3080 + (uint)pbVar5[1]);
              if (((uint)local_28 & 0x800) == 0) {
                iVar10 = 2;
                pcVar8 = (char *)0x80;
LAB_000c27aa:
                if (local_28 < pcVar8) {
LAB_000c2780:
                  pbVar5 = pbVar5 + iVar10;
                  if (0xfffd < iVar3) break;
                  pUTF8[iVar3] = '?';
                  goto LAB_000c2690;
                }
LAB_000c27b0:
                if ((((char *)0x7ff < local_28 + -0xd800) &&
                    (local_28 < Netchan_OutOfBandPrint::string + 0xf20)) &&
                   (((ushort)local_28 < 0xfffe && ((char *)0x1f < local_28 + -0xfdd0))))
                goto code_r0x000c27ed;
              }
              else {
                iVar10 = 2;
                if ((pbVar5[2] & 0xc0) == 0x80) {
                  iVar10 = (int)local_28 * 0x40 + (uint)pbVar5[2];
                  local_28 = (char *)(iVar10 - 0x20080);
                  if (((uint)local_28 & 0x10000) == 0) {
                    uVar9 = iVar10 - 0x2d880;
                    if ((((uVar9 < 0x400) && (pbVar5[3] == 0xed)) &&
                        ((byte)(pbVar5[4] + 0x50) < 0x10)) && ((pbVar5[5] & 0xc0) == 0x80)) {
                      local_28 = (char *)(uVar9 * 0x400 +
                                         (uint)(byte)(pbVar5[4] + 0x50) * 0x40 + 0xff80 +
                                         (uint)pbVar5[5]);
                      iVar10 = 6;
                    }
                    else {
                      iVar10 = 3;
                      if (local_28 < (char *)0x800) goto LAB_000c2780;
                    }
                    goto LAB_000c27b0;
                  }
                  iVar10 = 3;
                  if ((pbVar5[3] & 0xc0) == 0x80) {
                    local_28 = (char *)((int)local_28 * 0x40 + -0x400080 + (uint)pbVar5[3]);
                    pcVar8 = "\x7fELF\x01\x01\x01";
                    iVar10 = 4;
                    goto LAB_000c27aa;
                  }
                }
              }
            }
          }
          else {
            iVar10 = 1;
          }
          pbVar5 = pbVar5 + iVar10;
          bVar4 = 0x3f;
          bVar2 = true;
        }
        if (0xfffd < iVar3) break;
        pUTF8[iVar3] = bVar4;
        iVar3 = iVar3 + (uint)!bVar2;
        if (*pbVar5 == 0) break;
      } while( true );
    }
    goto LAB_000c26e0;
  }
  if (DAT_00000000 == '\0') {
    return 1;
  }
  pcVar8 = (char *)0x0;
  iVar3 = 0;
  do {
    while( true ) {
      local_15 = false;
      iVar10 = Q_UTF8ToUChar32(pcVar8,&local_14,&local_15);
      pcVar8 = pcVar8 + iVar10;
      if (local_14 < 0x80) break;
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
      if (local_14 < 0x800) {
        iVar10 = iVar3 + 2;
        goto joined_r0x000c2977;
      }
      if (local_14 < 0x10000) {
        iVar10 = iVar3 + 3;
        goto joined_r0x000c2977;
      }
      iVar10 = iVar3 + 4;
      if (local_15 == false) goto LAB_000c2921;
LAB_000c2955:
      iVar10 = iVar3;
      if (*pcVar8 == '\0') goto LAB_000c295a;
    }
    iVar10 = iVar3 + 1;
joined_r0x000c2977:
    if (local_15 != false) goto LAB_000c2955;
LAB_000c2921:
    iVar3 = iVar10;
  } while (*pcVar8 != '\0');
LAB_000c295a:
  return iVar10 + 1;
code_r0x000c27ed:
  pbVar5 = pbVar5 + iVar10;
  bVar4 = (byte)local_28;
  bVar6 = (byte)((int)local_28 >> 6);
  if ((int)local_28 < 0x800) {
    if (0xfffc < iVar3) {
LAB_000c26e0:
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
      if (0xfffb < iVar3) goto LAB_000c26e0;
      pbVar1 = (byte *)(pUTF8 + iVar3);
      *pbVar1 = bVar7 | 0xe0;
      iVar3 = iVar3 + 3;
      pbVar1[1] = bVar6 & 0x3f | 0x80;
      pbVar1[2] = bVar4 & 0x3f | 0x80;
    }
    else {
      if (0xfffa < iVar3) goto LAB_000c26e0;
      pbVar1 = (byte *)(pUTF8 + iVar3);
      *pbVar1 = (byte)((int)local_28 >> 0x12) | 0xf0;
      iVar3 = iVar3 + 4;
      pbVar1[1] = bVar7 & 0x3f | 0x80;
      pbVar1[2] = bVar6 & 0x3f | 0x80;
      pbVar1[3] = bVar4 & 0x3f | 0x80;
    }
  }
  goto LAB_000c2690;
}


// Q_UnicodeValidate  @ 000c1b10
qboolean Q_UnicodeValidate(char *pUTF8)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  
                    /* Unresolved local var: bool bError@[???] */
  bVar2 = *pUTF8;
  do {
    while( true ) {
      if (bVar2 == 0) {
        return 1;
      }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: int nCharSize@[DW_OP_reg1(ECX)]
                       Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
      if (0x7f < bVar2) break;
      pUTF8 = pUTF8 + 1;
      bVar2 = *pUTF8;
    }
    if (0x37 < bVar2 - 0xc0) {
      return 0;
    }
    if ((pUTF8[1] & 0xc0U) != 0x80) {
      return 0;
    }
    pcVar6 = (char *)((uint)bVar2 * 0x40 + -0x3080 + (uint)(byte)pUTF8[1]);
    if (((uint)pcVar6 & 0x800) == 0) {
      iVar3 = 2;
      pcVar5 = (char *)0x80;
      iVar4 = 2;
LAB_000c1c5f:
      if (pcVar6 < pcVar5) {
        return 0;
      }
    }
    else {
      if ((pUTF8[2] & 0xc0U) != 0x80) {
        return 0;
      }
      iVar3 = (uint)(byte)pUTF8[2] + (int)pcVar6 * 0x40;
      pcVar6 = (char *)(iVar3 - 0x20080);
      if (((uint)pcVar6 & 0x10000) != 0) {
        if ((pUTF8[3] & 0xc0U) != 0x80) {
          return 0;
        }
        pcVar5 = "\x7fELF\x01\x01\x01";
        pcVar6 = (char *)((int)pcVar6 * 0x40 + -0x400080 + (uint)(byte)pUTF8[3]);
        iVar4 = 4;
        iVar3 = 4;
        goto LAB_000c1c5f;
      }
      uVar1 = iVar3 - 0x2d880;
      if ((((uVar1 < 0x400) && (pUTF8[3] == 0xed)) && ((byte)(pUTF8[4] + 0x50U) < 0x10)) &&
         ((pUTF8[5] & 0xc0U) == 0x80)) {
        iVar4 = 6;
        pcVar6 = (char *)((uint)(byte)(pUTF8[4] + 0x50U) * 0x40 + 0xff80 + (uint)(byte)pUTF8[5] +
                         uVar1 * 0x400);
        iVar3 = 6;
      }
      else {
        iVar3 = 3;
        iVar4 = 3;
        if (pcVar6 < (char *)0x800) {
          return 0;
        }
      }
    }
    if (((pcVar6 + -0xd800 < (char *)0x800) || (Netchan_OutOfBandPrint::string + 0xf1f < pcVar6)) ||
       ((0xfffd < (ushort)pcVar6 || ((pcVar6 + -0xfdd0 < (char *)0x20 || (iVar4 == 6)))))) {
      return 0;
    }
    pUTF8 = pUTF8 + iVar3;
    bVar2 = *pUTF8;
  } while( true );
}


// Q_atof  @ 0003a1e0
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


// Q_atoi  @ 0003a0e0
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


// Q_log2  @ 00060d00
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


// Q_memcmp  @ 00039d80
int Q_memcmp(void *m1,void *m2,int count)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: int byteLoops@[???]
                       Unresolved local var: int numLoops@[???]
                       Unresolved local var: int i@[???] */
  if (count >> 2 < 1) {
LAB_00039db5:
    uVar2 = count & 3;
    if (uVar2 != 0) {
      if (*(char *)m1 != *(char *)m2) goto LAB_00039df0;
      if (uVar2 != 1) {
        if (*(char *)((int)m1 + 1) != *(char *)((int)m2 + 1)) goto LAB_00039df0;
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
        if (count >> 2 == iVar1) goto LAB_00039db5;
      } while (*(int *)((int)m1 + iVar1 * 4) == *(int *)((int)m2 + iVar1 * 4));
    }
LAB_00039df0:
    iVar1 = -1;
  }
  return iVar1;
}


// Q_memcpy  @ 00039cf0
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


// Q_memset  @ 00039c60
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


// Q_ntohs  @ 000af350
ushort Q_ntohs(ushort param_1)

{
  return param_1 >> 8 | param_1 << 8;
}


// Q_strcasecmp  @ 0003a030
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


// Q_strcat  @ 00039f00
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


// Q_strcmp  @ 00039f60
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


// Q_strcpy  @ 00039e00
void Q_strcpy(char *dest,char *src)

{
  for (; ((dest != (char *)0x0 && (src != (char *)0x0)) && (*src != '\0')); src = src + 1) {
    *dest = *src;
    dest = dest + 1;
  }
  *dest = '\0';
  return;
}


// Q_stricmp  @ 0003a070
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


// Q_striprefix  @ 0003a5b0
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


// Q_stristr  @ 00081920
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


// Q_strlen  @ 00039e80
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


// Q_strlwr  @ 0003a3b0
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


// Q_strncasecmp  @ 0003a000
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


// Q_strncmp  @ 00039fa0
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


// Q_strncpy  @ 00039e30
void Q_strncpy(char *dest,char *src,int count)

{
  strncpy(dest,src,count);
  return;
}


// Q_strncpy_s  @ 00039e40
void Q_strncpy_s(char *dest,char *src,int count)

{
  strncpy(dest,src,count);
  dest[count + -1] = '\0';
  return;
}


// Q_strnicmp  @ 0003a0b0
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


// Q_strrchr  @ 00039eb0
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


// Q_strstr  @ 0003a4a0
char * Q_strstr(char *s1,char *search)

{
  char *pcVar1;
  
  pcVar1 = strstr(s1,search);
  return pcVar1;
}


// Q_strtoull  @ 0003a4b0
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
  if (cVar2 != ' ') goto LAB_0003a4e0;
  do {
    do {
      local_18 = local_18 + 1;
      cVar2 = *local_18;
    } while (cVar2 == ' ');
LAB_0003a4e0:
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
    goto LAB_0003a538;
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
LAB_0003a538:
  return CONCAT44(iVar6,uVar4);
}


