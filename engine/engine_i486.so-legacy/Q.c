// Q_FileNameCmp  @ 0005f880
int Q_FileNameCmp(char *file1,char *file2)

{
  char cVar1;
  char cVar2;
  __int32_t *p_Var3;
  __int32_t **pp_Var4;
  char *pcVar5;
  char *pcVar6;
  
  pp_Var4 = __ctype_tolower_loc();
  p_Var3 = *pp_Var4;
LAB_0005f8a0:
  do {
    pcVar6 = file1 + 1;
    pcVar5 = file2 + 1;
    cVar1 = *file1;
    cVar2 = *file2;
    file2 = pcVar5;
    file1 = pcVar6;
    if (cVar1 == '/') {
      if (cVar2 == '\\') goto LAB_0005f8a0;
    }
    if (cVar2 == '/') {
      if (cVar1 == '\\') goto LAB_0005f8a0;
      if (p_Var3[cVar1] != p_Var3[0x2f]) {
        return -1;
      }
    }
    else {
                    /* Unresolved local var: int __res@[???] */
                    /* Unresolved local var: int __res@[???] */
      if (p_Var3[cVar1] != p_Var3[cVar2]) {
        return -1;
      }
    }
    if ((cVar1 == '\0') || (cVar2 == '\0')) {
      return 0;
    }
  } while( true );
}


// Q_IsDeprecatedW  @ 000d29c0
qboolean Q_IsDeprecatedW(wchar_t wch)

{
                    /* Unresolved local var: qboolean bIsDeprecated@[???] */
  if (wch < L'\x202a') {
    return 0;
  }
  if ((L'\x202e' < wch) && (5 < (uint)(wch + L'\xffffdf96'))) {
    return 0;
  }
  return 1;
}


// Q_IsMeanSpaceW  @ 000d2940
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


// Q_IsValidUChar32  @ 000d1070
bool Q_IsValidUChar32(uchar32 uVal)

{
  if (((0x7ff < uVal - 0xd800U) && ((uint)uVal < MSG_ReadString::string + 0x1860)) &&
     ((ushort)uVal < 0xfffe)) {
    return 0x1f < uVal - 0xfdd0U;
  }
  return false;
}


// Q_StripUnprintableAndSpace  @ 000d29f0
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

qboolean Q_StripUnprintableAndSpace(char *pch)

{
  bool bVar1;
  char *pOut;
  wchar_t *__ptr;
  uint uVar2;
  int iVar3;
  wchar_t *pwVar4;
  wchar_t wVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  bool bVar8;
  EStringConvertErrorPolicy in_stack_ffffffc8;
  uint local_20;
  
                    /* Unresolved local var: int cch@[???]
                       Unresolved local var: int cubDest@[???]
                       Unresolved local var: wchar_t * pwch@[???]
                       Unresolved local var: wchar_t * pwch_alloced@[???]
                       Unresolved local var: bool bStrippedAny@[???]
                       Unresolved local var: bool bStrippedWhitespace@[???]
                       Unresolved local var: int cwch@[???] */
  pOut = (char *)Q_strlen(pch);
  pwVar4 = (wchar_t *)((int)pOut * 4 + 4);
  __ptr = malloc((size_t)pwVar4);
                    /* Unresolved local var: wchar_t * pwchSource@[???]
                       Unresolved local var: wchar_t * pwchDest@[???] */
  uVar2 = anon_unknown.dwarf_f5b44::
          Q_UnicodeConvertT<char,_wchar_t,_true,_(*_Q_UTF8ToUChar32),_(*__anonymous_::Q_UChar32ToUTF32Len),_(*__anonymous_::Q_UChar32ToUTF32)>
                    (pch,(int)__ptr,pwVar4,4,in_stack_ffffffc8);
  wVar5 = *__ptr;
  pwVar4 = __ptr;
  pwVar6 = __ptr;
  if (wVar5 == L'\0') {
    bVar8 = false;
    local_20 = 0;
  }
  else {
    do {
                    /* Unresolved local var: qboolean bIsDeprecated@[???] */
      if ((L'\x1f' < wVar5) &&
         (((wVar5 < L'\x202a' || ((L'\x202e' < wVar5 && (5 < (uint)(wVar5 + L'\xffffdf96'))))) &&
          (wVar5 != L'\x85')))) {
        *pwVar6 = wVar5;
        pwVar6 = pwVar6 + 1;
      }
      pwVar4 = pwVar4 + 1;
      wVar5 = *pwVar4;
    } while (wVar5 != L'\0');
    bVar8 = pwVar4 != pwVar6;
    local_20 = (uint)bVar8;
  }
                    /* Unresolved local var: wchar_t * pwchEnd@[???] */
  pwVar7 = (wchar_t *)((int)__ptr + ((uVar2 & 0xfffffffc) - 4));
  pwVar4 = pwVar7 + -1;
  *pwVar6 = L'\0';
  bVar1 = false;
  pwVar6 = __ptr;
  if (pwVar4 < __ptr) goto joined_r0x000d2b34;
  bVar1 = false;
LAB_000d2ab0:
  wVar5 = pwVar7[-1];
  iVar3 = iswspace(wVar5);
  if (iVar3 == 0) {
                    /* Unresolved local var: qboolean bIsMean@[???] */
    if (L'\x2029' < wVar5) {
      if (wVar5 == L'\x2060') goto LAB_000d2af0;
      if (wVar5 < L'⁡') {
        if (wVar5 == L'\x202f') goto LAB_000d2af0;
        goto joined_r0x000d2b34;
      }
      if (wVar5 == L'\xfeff') goto LAB_000d2af0;
      if (wVar5 != L'￼') goto joined_r0x000d2b34;
      pwVar7[-1] = L'\0';
      goto joined_r0x000d2c36;
    }
    if ((wVar5 < L'\x2028') && (wVar5 != L'͏')) {
      if (wVar5 < L'͐') {
        if ((uint)(wVar5 + L'\xffffff80') < 0x21) goto LAB_000d2af0;
        goto joined_r0x000d2b34;
      }
      if (0xd < (uint)(wVar5 + L'\xffffe000')) goto joined_r0x000d2b34;
    }
  }
LAB_000d2af0:
  pwVar7[-1] = L'\0';
joined_r0x000d2c36:
  if (pwVar4 + -1 < __ptr) goto LAB_000d2c40;
  bVar1 = true;
  pwVar7 = pwVar4;
  pwVar4 = pwVar4 + -1;
  goto LAB_000d2ab0;
LAB_000d2c40:
  pwVar4 = pwVar4 + -1;
  bVar1 = true;
joined_r0x000d2b34:
  if (pwVar4 <= pwVar6) {
LAB_000d2b80:
    if ((bVar8) || (bVar1)) {
      anon_unknown.dwarf_f5b44::
      Q_UnicodeConvertT<wchar_t,_char,_true,_(*__anonymous_::Q_UTF32ToUChar32),_(*_Q_UChar32ToUTF8Len),_(*_Q_UChar32ToUTF8)>
                (pwVar6,(int)pch,pOut,4,in_stack_ffffffc8);
    }
    free(__ptr);
    return local_20;
  }
  wVar5 = *pwVar6;
  iVar3 = iswspace(wVar5);
  if (iVar3 == 0) {
                    /* Unresolved local var: qboolean bIsMean@[???] */
    if (L'\x2029' < wVar5) {
      if (wVar5 == L'\x2060') goto joined_r0x000d2c04;
      if (wVar5 < L'⁡') {
        if (wVar5 == L'\x202f') goto joined_r0x000d2c04;
        goto LAB_000d2b80;
      }
      if (wVar5 == L'\xfeff') goto joined_r0x000d2c04;
      if (wVar5 != L'￼') goto LAB_000d2b80;
      bVar1 = true;
      pwVar6 = pwVar6 + 1;
      goto joined_r0x000d2b34;
    }
    if ((wVar5 < L'\x2028') && (wVar5 != L'͏')) {
      if (L'͏' < wVar5) {
        if ((uint)(wVar5 + L'\xffffe000') < 0xe) goto joined_r0x000d2c04;
        goto LAB_000d2b80;
      }
      if (0x20 < (uint)(wVar5 + L'\xffffff80')) goto LAB_000d2b80;
    }
  }
joined_r0x000d2c04:
  bVar1 = true;
  pwVar6 = pwVar6 + 1;
  goto joined_r0x000d2b34;
}


// Q_UChar32ToUTF16  @ 000d10f0
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


// Q_UChar32ToUTF16Len  @ 000d10e0
int Q_UChar32ToUTF16Len(uchar32 uVal)

{
  return (0xffff < uVal) + 1;
}


// Q_UChar32ToUTF8  @ 000d1140
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


// Q_UChar32ToUTF8Len  @ 000d10b0
int Q_UChar32ToUTF8Len(uchar32 uVal)

{
  int iVar1;
  
  iVar1 = 1;
  if ((0x7f < uVal) && (iVar1 = 2, 0x7ff < uVal)) {
    return (0xffff < uVal) + 3;
  }
  return iVar1;
}


// Q_UTF16ToUChar32  @ 000d11f0
int Q_UTF16ToUChar32(uchar16 *pUTF16,uchar32 *uValueOut,bool *bErrorOut)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)*pUTF16;
  uVar1 = uVar4 - 0xd800;
  if (((0x7ff < uVar1) && (uVar4 < 0xfffe)) && (0x1f < uVar4 - 0xfdd0)) {
    *uValueOut = uVar4;
    *bErrorOut = false;
    return 1;
  }
  if ((uVar1 < 0x400) && (pUTF16[1] - 0xdc00 < 0x400)) {
                    /* Unresolved local var: uchar32 uVal@[???] */
    pcVar2 = (char *)(pUTF16[1] + 0x2400 + uVar1 * 0x400);
    if (((pcVar2 + -0xd800 < (char *)0x800) ||
        ((MSG_ReadString::string + 0x185f < pcVar2 || (0xfffd < (ushort)pcVar2)))) ||
       (pcVar2 + -0xfdd0 < (char *)0x20)) {
      *uValueOut = 0x3f;
      *bErrorOut = true;
      return 2;
    }
    *uValueOut = (uchar32)pcVar2;
    iVar3 = 2;
    *bErrorOut = false;
  }
  else {
    *uValueOut = 0x3f;
    iVar3 = 1;
    *bErrorOut = true;
  }
  return iVar3;
}


// Q_UTF16ToUTF32  @ 000d16c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF16ToUTF32(uchar16 *pUTF16,uchar32 *pUTF32,int cubDestSizeInBytes,
                  EStringConvertErrorPolicy ePolicy)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uchar32 local_2c [3];
  bool local_1d [13];
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF32 == (uchar32 *)0x0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar1 = 1;
    if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
      if ((ePolicy & STRINGCONVERT_SKIP) != STRINGCONVERT_REPLACE) {
        for (; *pUTF16 != 0; pUTF16 = pUTF16 + iVar3) {
          local_1d[0] = false;
          iVar3 = Q_UTF16ToUChar32(pUTF16,local_2c,local_1d);
          iVar1 = iVar1 + (uint)(local_1d[0] == false);
        }
        goto LAB_000d175e;
      }
      iVar1 = 0;
      for (; *pUTF16 != 0; pUTF16 = pUTF16 + iVar3) {
        iVar1 = iVar1 + 1;
        local_1d[0] = false;
        iVar3 = Q_UTF16ToUChar32(pUTF16,local_2c,local_1d);
      }
    }
    else {
      if ((ePolicy & STRINGCONVERT_SKIP) != STRINGCONVERT_REPLACE) {
        for (; *pUTF16 != 0; pUTF16 = pUTF16 + iVar3) {
          local_1d[0] = false;
          iVar3 = Q_UTF16ToUChar32(pUTF16,local_2c,local_1d);
          iVar1 = iVar1 + (uint)(local_1d[0] == false);
        }
        goto LAB_000d175e;
      }
      iVar1 = 0;
      while (*pUTF16 != 0) {
        iVar1 = iVar1 + 1;
        local_1d[0] = false;
        iVar3 = Q_UTF16ToUChar32(pUTF16,local_2c,local_1d);
        pUTF16 = pUTF16 + iVar3;
        if (local_1d[0] != false) {
          _DAT_00000000 = 0;
          return 0;
        }
      }
    }
    iVar1 = iVar1 + 1;
    goto LAB_000d175e;
  }
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
  uVar2 = (uint)cubDestSizeInBytes >> 2;
  if (uVar2 == 0) {
    return 0;
  }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
  iVar3 = 0;
  if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
    if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
      while (*pUTF16 != 0) {
        local_1d[0] = false;
        iVar1 = Q_UTF16ToUChar32(pUTF16,local_2c,local_1d);
        pUTF16 = pUTF16 + iVar1;
        iVar1 = iVar3 + 1;
        if ((int)uVar2 <= iVar1) goto LAB_000d1758;
        pUTF32[iVar3] = local_2c[0];
        iVar3 = iVar1;
      }
LAB_000d17b7:
      iVar1 = iVar3 + 1;
    }
    else {
      iVar3 = 0;
      iVar1 = 1;
      while (iVar4 = iVar1, *pUTF16 != 0) {
        while( true ) {
          local_1d[0] = false;
          iVar1 = Q_UTF16ToUChar32(pUTF16,local_2c,local_1d);
          pUTF16 = pUTF16 + iVar1;
          iVar1 = iVar4;
          if ((int)uVar2 <= iVar4) goto LAB_000d1758;
          pUTF32[iVar3] = local_2c[0];
          if (local_1d[0] != false) break;
          iVar1 = iVar4 + 1;
          iVar3 = iVar4;
          iVar4 = iVar1;
          if (*pUTF16 == 0) goto LAB_000d1758;
        }
      }
    }
  }
  else {
    iVar1 = 1;
    if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
      if (*pUTF16 != 0) {
        iVar3 = 0;
        do {
          local_1d[0] = false;
          iVar1 = Q_UTF16ToUChar32(pUTF16,local_2c,local_1d);
          pUTF16 = pUTF16 + iVar1;
          iVar1 = iVar3 + 1;
          if ((int)uVar2 <= iVar1) goto LAB_000d1758;
          pUTF32[iVar3] = local_2c[0];
          if (local_1d[0] != false) {
            *pUTF32 = 0;
            return 0;
          }
          iVar3 = iVar1;
        } while (*pUTF16 != 0);
      }
      goto LAB_000d17b7;
    }
    while (iVar4 = iVar1, *pUTF16 != 0) {
      while( true ) {
        local_1d[0] = false;
        iVar1 = Q_UTF16ToUChar32(pUTF16,local_2c,local_1d);
        pUTF16 = pUTF16 + iVar1;
        iVar1 = iVar4;
        if ((int)uVar2 <= iVar4) goto LAB_000d1758;
        pUTF32[iVar3] = local_2c[0];
        if (local_1d[0] != false) break;
        iVar1 = iVar4 + 1;
        iVar3 = iVar4;
        iVar4 = iVar1;
        if (*pUTF16 == 0) goto LAB_000d1758;
      }
    }
  }
LAB_000d1758:
  pUTF32[iVar3] = 0;
LAB_000d175e:
  return iVar1 << 2;
}


// Q_UTF16ToUTF8  @ 000d12f0
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF16ToUTF8(uchar16 *pUTF16,char *pUTF8,int cubDestSizeInBytes,
                 EStringConvertErrorPolicy ePolicy)

{
  byte *pbVar1;
  uchar16 uVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  int local_18;
  bool local_11;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF8 == (char *)0x0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar5 = 0;
    if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
      if ((ePolicy & STRINGCONVERT_SKIP) != STRINGCONVERT_REPLACE) {
LAB_000d152f:
        do {
          if (*pUTF16 == 0) goto LAB_000d13f4;
          local_11 = false;
          iVar6 = Q_UTF16ToUChar32(pUTF16,&local_18,&local_11);
          pUTF16 = pUTF16 + iVar6;
          iVar6 = 1;
          if ((0x7f < local_18) && (iVar6 = 2, 0x7ff < local_18)) {
            iVar6 = (0xffff < local_18) + 3;
          }
          iVar5 = iVar5 + iVar6;
          if (local_11 != false) {
            if (local_18 < 0x80) {
              iVar6 = 1;
            }
            else {
              iVar6 = 2;
              if (0x7ff < local_18) {
                iVar5 = iVar5 - ((0xffff < local_18) + 3);
                goto LAB_000d152f;
              }
            }
            iVar5 = iVar5 - iVar6;
          }
        } while( true );
      }
      while (*pUTF16 != 0) {
        local_11 = false;
        iVar6 = Q_UTF16ToUChar32(pUTF16,&local_18,&local_11);
        pUTF16 = pUTF16 + iVar6;
        iVar6 = 1;
        if ((local_18 < 0x80) || (iVar6 = 2, local_18 < 0x800)) {
          iVar5 = iVar5 + iVar6;
        }
        else {
          iVar5 = iVar5 + (0xffff < local_18) + 3;
        }
      }
LAB_000d13f4:
      iVar5 = iVar5 + 1;
    }
    else {
      if ((ePolicy & STRINGCONVERT_SKIP) != STRINGCONVERT_REPLACE) {
LAB_000d1634:
        do {
          if (*pUTF16 == 0) goto LAB_000d13f4;
          local_11 = false;
          iVar6 = Q_UTF16ToUChar32(pUTF16,&local_18,&local_11);
          pUTF16 = pUTF16 + iVar6;
          iVar6 = 1;
          if ((0x7f < local_18) && (iVar6 = 2, 0x7ff < local_18)) {
            iVar6 = (0xffff < local_18) + 3;
          }
          iVar5 = iVar5 + iVar6;
          if (local_11 != false) {
            iVar6 = 1;
            if (0x7f < local_18) {
              if (local_18 < 0x800) {
                iVar5 = iVar5 + -2;
                goto LAB_000d1634;
              }
              iVar6 = (0xffff < local_18) + 3;
            }
            iVar5 = iVar5 - iVar6;
          }
        } while( true );
      }
      do {
        if (*pUTF16 == 0) goto LAB_000d13f4;
        local_11 = false;
        iVar6 = Q_UTF16ToUChar32(pUTF16,&local_18,&local_11);
        pUTF16 = pUTF16 + iVar6;
        iVar6 = 1;
        if ((0x7f < local_18) && (iVar6 = 2, 0x7ff < local_18)) {
          iVar6 = (0xffff < local_18) + 3;
        }
        iVar5 = iVar5 + iVar6;
      } while (local_11 == false);
      DAT_00000000 = 0;
      iVar5 = 0;
    }
  }
  else {
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
    iVar5 = 0;
    if (0 < cubDestSizeInBytes) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
      iVar5 = 0;
LAB_000d1330:
      uVar2 = *pUTF16;
      do {
        if (uVar2 == 0) {
LAB_000d13f0:
          pUTF8[iVar5] = '\0';
          goto LAB_000d13f4;
        }
        local_11 = false;
        iVar6 = Q_UTF16ToUChar32(pUTF16,&local_18,&local_11);
        pUTF16 = pUTF16 + iVar6;
        iVar6 = 1;
        if ((0x7f < local_18) && (iVar6 = 2, 0x7ff < local_18)) {
          iVar6 = (0xffff < local_18) + 3;
        }
        if (cubDestSizeInBytes <= iVar6 + iVar5) goto LAB_000d13f0;
        pbVar1 = (byte *)(pUTF8 + iVar5);
        bVar7 = (byte)local_18;
        if (local_18 < 0x80) {
          *pbVar1 = bVar7;
          iVar6 = 1;
        }
        else {
          bVar3 = (byte)(local_18 >> 6);
          if (local_18 < 0x800) {
            *pbVar1 = bVar3 | 0xc0;
            pbVar1[1] = bVar7 & 0x3f | 0x80;
            iVar6 = 2;
          }
          else {
            bVar4 = (byte)(local_18 >> 0xc);
            if (local_18 < 0x10000) {
              *pbVar1 = bVar4 | 0xe0;
              pbVar1[1] = bVar3 & 0x3f | 0x80;
              pbVar1[2] = bVar7 & 0x3f | 0x80;
              iVar6 = 3;
            }
            else {
              *pbVar1 = (byte)(local_18 >> 0x12) & 7 | 0xf0;
              pbVar1[1] = bVar4 & 0x3f | 0x80;
              pbVar1[2] = bVar3 & 0x3f | 0x80;
              pbVar1[3] = bVar7 & 0x3f | 0x80;
              iVar6 = 4;
            }
          }
        }
        iVar5 = iVar5 + iVar6;
        if (local_11 == false) goto LAB_000d1330;
        if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) goto LAB_000d1410;
        iVar6 = 1;
        if ((0x7f < local_18) && (iVar6 = 2, 0x7ff < local_18)) {
          iVar6 = (0xffff < local_18) + 3;
        }
        iVar5 = iVar5 - iVar6;
        uVar2 = *pUTF16;
      } while( true );
    }
  }
  return iVar5;
LAB_000d1410:
  if ((ePolicy & STRINGCONVERT_FAIL) != STRINGCONVERT_REPLACE) {
    *pUTF8 = '\0';
    return 0;
  }
  goto LAB_000d1330;
}


// Q_UTF32ToUTF16  @ 000d19e0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF32ToUTF16(uchar32 *pUTF32,uchar16 *pUTF16,int cubDestSizeInBytes,
                  EStringConvertErrorPolicy ePolicy)

{
  ushort *puVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uchar32 *puVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF16 == (uchar16 *)0x0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    puVar5 = pUTF32 + 1;
    if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
      iVar4 = 0;
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
        for (; pcVar6 = (char *)puVar5[-1], pcVar6 != (char *)0x0; puVar5 = puVar5 + 1) {
          if (((pcVar6 + -0xd800 < (char *)0x800) || (MSG_ReadString::string + 0x185f < pcVar6)) ||
             ((0xfffd < (ushort)pcVar6 ||
              ((pcVar6 + -0xfdd0 < (char *)0x20 || ((int)pcVar6 < 0x10000)))))) {
            iVar4 = iVar4 + 1;
          }
          else {
            iVar4 = iVar4 + 2;
          }
        }
      }
      else {
        iVar4 = 0;
        for (; pcVar6 = (char *)puVar5[-1], pcVar6 != (char *)0x0; puVar5 = puVar5 + 1) {
          if (((((char *)0x7ff < pcVar6 + -0xd800) && (pcVar6 < MSG_ReadString::string + 0x1860)) &&
              ((ushort)pcVar6 < 0xfffe)) && ((char *)0x1f < pcVar6 + -0xfdd0)) {
            iVar8 = iVar4 + 2;
            iVar4 = iVar4 + 1;
            if (0xffff < (int)pcVar6) {
              iVar4 = iVar8;
            }
          }
        }
      }
    }
    else {
      iVar4 = 0;
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
        pcVar6 = (char *)*pUTF32;
        while (pcVar6 != (char *)0x0) {
          if (((pcVar6 + -0xd800 < (char *)0x800) || (MSG_ReadString::string + 0x185f < pcVar6)) ||
             ((0xfffd < (ushort)pcVar6 || (pcVar6 + -0xfdd0 < (char *)0x20)))) {
            _DAT_00000000 = 0;
            return 0;
          }
          iVar8 = iVar4 + 2;
          iVar4 = iVar4 + 1;
          if (0xffff < (int)pcVar6) {
            iVar4 = iVar8;
          }
          pcVar6 = (char *)*puVar5;
          puVar5 = puVar5 + 1;
        }
      }
      else {
        for (; pcVar6 = (char *)puVar5[-1], pcVar6 != (char *)0x0; puVar5 = puVar5 + 1) {
          if (((((char *)0x7ff < pcVar6 + -0xd800) && (pcVar6 < MSG_ReadString::string + 0x1860)) &&
              ((ushort)pcVar6 < 0xfffe)) && ((char *)0x1f < pcVar6 + -0xfdd0)) {
            iVar8 = iVar4 + 1;
            iVar4 = iVar4 + 2;
            if ((int)pcVar6 < 0x10000) {
              iVar4 = iVar8;
            }
          }
        }
      }
    }
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
    puVar5 = pUTF32 + 1;
    if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
      iVar4 = 0;
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
        for (; pcVar6 = (char *)puVar5[-1], pcVar6 != (char *)0x0; puVar5 = puVar5 + 1) {
          if (((pcVar6 + -0xd800 < (char *)0x800) || (MSG_ReadString::string + 0x185f < pcVar6)) ||
             ((0xfffd < (ushort)pcVar6 || (pcVar6 + -0xfdd0 < (char *)0x20)))) {
            pcVar6 = (char *)0x3f;
LAB_000d1b91:
            iVar8 = 1;
          }
          else {
            iVar8 = 2;
            if ((int)pcVar6 < 0x10000) goto LAB_000d1b91;
          }
          if ((int)uVar7 <= iVar8 + iVar4) break;
          puVar1 = pUTF16 + iVar4;
          if ((int)pcVar6 < 0x10000) {
            *puVar1 = (ushort)pcVar6;
            iVar8 = 1;
          }
          else {
            puVar1[1] = (ushort)(pcVar6 + -0x10000) & 0x3ff | 0xdc00;
            iVar8 = 2;
            *puVar1 = (ushort)((int)(pcVar6 + -0x10000) >> 10) | 0xd800;
          }
          iVar4 = iVar4 + iVar8;
        }
      }
      else {
        iVar4 = 0;
        for (; pcVar6 = (char *)puVar5[-1], pcVar6 != (char *)0x0; puVar5 = puVar5 + 1) {
          if ((((pcVar6 + -0xd800 < (char *)0x800) || (MSG_ReadString::string + 0x185f < pcVar6)) ||
              (0xfffd < (ushort)pcVar6)) || (pcVar6 + -0xfdd0 < (char *)0x20)) {
            pcVar6 = (char *)0x3f;
            bVar2 = true;
LAB_000d1ae2:
            iVar8 = iVar4 + 1;
          }
          else {
            bVar2 = false;
            if ((int)pcVar6 < 0x10000) goto LAB_000d1ae2;
            iVar8 = iVar4 + 2;
          }
          if ((int)uVar7 <= iVar8) break;
          puVar1 = pUTF16 + iVar4;
          if ((int)pcVar6 < 0x10000) {
            *puVar1 = (ushort)pcVar6;
            iVar8 = 1;
          }
          else {
            *puVar1 = (ushort)((int)(pcVar6 + -0x10000) >> 10) | 0xd800;
            iVar8 = 2;
            puVar1[1] = (ushort)(pcVar6 + -0x10000) & 0x3ff | 0xdc00;
          }
          iVar4 = iVar4 + iVar8;
          if (bVar2) {
            iVar4 = iVar4 - ((0xffff < (int)pcVar6) + 1);
          }
        }
      }
    }
    else {
      iVar4 = 0;
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
        while (pcVar6 = (char *)puVar5[-1], pcVar6 != (char *)0x0) {
          if (((pcVar6 + -0xd800 < (char *)0x800) || (MSG_ReadString::string + 0x185f < pcVar6)) ||
             ((0xfffd < (ushort)pcVar6 || (pcVar6 + -0xfdd0 < (char *)0x20)))) {
            pcVar6 = (char *)0x3f;
            bVar2 = true;
LAB_000d1e37:
            bVar3 = bVar2;
            iVar8 = 1;
          }
          else {
            bVar3 = false;
            bVar2 = false;
            if ((int)pcVar6 < 0x10000) goto LAB_000d1e37;
            iVar8 = 2;
          }
          if ((int)uVar7 <= iVar8 + iVar4) break;
          puVar1 = pUTF16 + iVar4;
          if ((int)pcVar6 < 0x10000) {
            *puVar1 = (ushort)pcVar6;
            iVar8 = 1;
          }
          else {
            *puVar1 = (ushort)((int)(pcVar6 + -0x10000) >> 10) | 0xd800;
            puVar1[1] = (ushort)(pcVar6 + -0x10000) & 0x3ff | 0xdc00;
            iVar8 = 2;
          }
          iVar4 = iVar4 + iVar8;
          puVar5 = puVar5 + 1;
          if (bVar3) {
            *pUTF16 = 0;
            return 0;
          }
        }
      }
      else {
        for (; pcVar6 = (char *)puVar5[-1], pcVar6 != (char *)0x0; puVar5 = puVar5 + 1) {
          if (((pcVar6 + -0xd800 < (char *)0x800) || (MSG_ReadString::string + 0x185f < pcVar6)) ||
             ((0xfffd < (ushort)pcVar6 || (pcVar6 + -0xfdd0 < (char *)0x20)))) {
            pcVar6 = (char *)0x3f;
            bVar2 = true;
LAB_000d1d5e:
            iVar8 = 1;
          }
          else {
            bVar2 = false;
            if ((int)pcVar6 < 0x10000) goto LAB_000d1d5e;
            iVar8 = 2;
          }
          if ((int)uVar7 <= iVar8 + iVar4) break;
          puVar1 = pUTF16 + iVar4;
          if ((int)pcVar6 < 0x10000) {
            *puVar1 = (ushort)pcVar6;
            iVar8 = 1;
          }
          else {
            *puVar1 = (ushort)((int)(pcVar6 + -0x10000) >> 10) | 0xd800;
            puVar1[1] = (ushort)(pcVar6 + -0x10000) & 0x3ff | 0xdc00;
            iVar8 = 2;
          }
          iVar4 = iVar4 + iVar8;
          if (bVar2) {
            iVar4 = iVar4 - ((0xffff < (int)pcVar6) + 1);
          }
        }
      }
    }
    pUTF16[iVar4] = 0;
  }
  return iVar4 * 2 + 2;
}


// Q_UTF32ToUTF8  @ 000d19c0
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF32ToUTF8(uchar32 *pUTF32,char *pUTF8,int cubDestSizeInBytes,
                 EStringConvertErrorPolicy ePolicy)

{
  int iVar1;
  
  iVar1 = anon_unknown.dwarf_f5b44::
          Q_UnicodeConvertT<wchar_t,_char,_true,_(*__anonymous_::Q_UTF32ToUChar32),_(*_Q_UChar32ToUTF8Len),_(*_Q_UChar32ToUTF8)>
                    (pUTF32,(int)pUTF8,(char *)cubDestSizeInBytes,ePolicy,
                     (EStringConvertErrorPolicy)pUTF8);
  return iVar1;
}


// Q_UTF8ToUChar32  @ 000d1f10
int Q_UTF8ToUChar32(char *pUTF8_,uchar32 *uValueOut,bool *bErrorOut)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
  pcVar2 = (char *)(uint)(byte)*pUTF8_;
  if (pcVar2 < (char *)0x80) {
    iVar1 = 1;
LAB_000d1f85:
    *uValueOut = (uchar32)pcVar2;
    *bErrorOut = false;
  }
  else {
    if (pcVar2 + -0xc0 < (char *)0x38) {
      iVar1 = 1;
      if (((byte)pUTF8_[1] & 0xc0) == 0x80) {
        pcVar2 = (char *)((int)pcVar2 * 0x40 + -0x3080 + (uint)(byte)pUTF8_[1]);
        if (((uint)pcVar2 & 0x800) == 0) {
          pcVar3 = (char *)0x80;
          iVar1 = 2;
        }
        else {
          iVar1 = 2;
          if (((byte)pUTF8_[2] & 0xc0) != 0x80) goto LAB_000d1f57;
          iVar1 = (uint)(byte)pUTF8_[2] + (int)pcVar2 * 0x40;
          pcVar2 = (char *)(iVar1 - 0x20080);
          if (((uint)pcVar2 & 0x10000) == 0) {
            uVar4 = iVar1 - 0x2d880;
            if ((((uVar4 < 0x400) && (pUTF8_[3] == -0x13)) && ((byte)(pUTF8_[4] + 0x50U) < 0x10)) &&
               ((pUTF8_[5] & 0xc0U) == 0x80)) {
              pcVar3 = "\x7fELF\x01\x01\x01";
              iVar1 = 6;
              pcVar2 = (char *)((byte)pUTF8_[5] + 0xff80 + (uint)(byte)(pUTF8_[4] + 0x50U) * 0x40 +
                               uVar4 * 0x400);
            }
            else {
              pcVar3 = (char *)0x800;
              iVar1 = 3;
            }
          }
          else {
            iVar1 = 3;
            if (((byte)pUTF8_[3] & 0xc0) != 0x80) goto LAB_000d1f57;
            iVar1 = 4;
            pcVar2 = (char *)((int)pcVar2 * 0x40 + -0x400080 + (uint)(byte)pUTF8_[3]);
            pcVar3 = "\x7fELF\x01\x01\x01";
          }
        }
        if (((pcVar3 <= pcVar2) && ((char *)0x7ff < pcVar2 + -0xd800)) &&
           ((pcVar2 < MSG_ReadString::string + 0x1860 &&
            (((ushort)pcVar2 < 0xfffe && ((char *)0x1f < pcVar2 + -0xfdd0)))))) goto LAB_000d1f85;
      }
    }
    else {
      iVar1 = 1;
    }
LAB_000d1f57:
    *uValueOut = 0x3f;
    *bErrorOut = true;
  }
  return iVar1;
}


// Q_UTF8ToUTF16  @ 000d23c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF8ToUTF16(char *pUTF8,uchar16 *pUTF16,int cubDestSizeInBytes,
                 EStringConvertErrorPolicy ePolicy)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_18;
  bool local_11;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF16 == (uchar16 *)0x0) {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar4 = 0;
    if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
        for (; *pUTF8 != '\0'; pUTF8 = pUTF8 + iVar2) {
          local_11 = false;
          iVar2 = Q_UTF8ToUChar32(pUTF8,&local_18,&local_11);
          iVar4 = iVar4 + 1 + (uint)(0xffff < local_18);
        }
      }
      else {
        while (*pUTF8 != '\0') {
          while( true ) {
            local_11 = false;
            iVar2 = Q_UTF8ToUChar32(pUTF8,&local_18,&local_11);
            pUTF8 = pUTF8 + iVar2;
            iVar4 = iVar4 + 1 + (uint)(0xffff < local_18);
            if (local_11 == false) break;
            iVar4 = iVar4 - ((0xffff < local_18) + 1);
            if (*pUTF8 == '\0') goto LAB_000d24b6;
          }
        }
      }
    }
    else if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
      while (*pUTF8 != '\0') {
        local_11 = false;
        iVar2 = Q_UTF8ToUChar32(pUTF8,&local_18,&local_11);
        pUTF8 = pUTF8 + iVar2;
        iVar4 = iVar4 + 1 + (uint)(0xffff < local_18);
        if (local_11 != false) {
          _DAT_00000000 = 0;
          return 0;
        }
      }
    }
    else {
      while (*pUTF8 != '\0') {
        while( true ) {
          local_11 = false;
          iVar2 = Q_UTF8ToUChar32(pUTF8,&local_18,&local_11);
          pUTF8 = pUTF8 + iVar2;
          iVar4 = (0xffff < local_18) + 1 + iVar4;
          if (local_11 == false) break;
          iVar4 = iVar4 - ((0xffff < local_18) + 1);
          if (*pUTF8 == '\0') goto LAB_000d24b6;
        }
      }
    }
  }
  else {
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???] */
    uVar3 = (uint)cubDestSizeInBytes >> 1;
    if (uVar3 == 0) {
      return 0;
    }
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    iVar4 = 0;
    if ((ePolicy & STRINGCONVERT_FAIL) == STRINGCONVERT_REPLACE) {
      if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
        iVar4 = 0;
        while (*pUTF8 != '\0') {
          local_11 = false;
          iVar2 = Q_UTF8ToUChar32(pUTF8,&local_18,&local_11);
          pUTF8 = pUTF8 + iVar2;
          if ((int)uVar3 <= (int)(iVar4 + 1 + (uint)(0xffff < local_18))) break;
          puVar1 = pUTF16 + iVar4;
          if (local_18 < 0x10000) {
            *puVar1 = (ushort)local_18;
            iVar4 = iVar4 + 1;
          }
          else {
            *puVar1 = (ushort)(local_18 + -0x10000 >> 10) | 0xd800;
            puVar1[1] = (ushort)(local_18 + -0x10000) & 0x3ff | 0xdc00;
            iVar4 = iVar4 + 2;
          }
        }
      }
      else {
        iVar4 = 0;
        while (*pUTF8 != '\0') {
          while( true ) {
            local_11 = false;
            iVar2 = Q_UTF8ToUChar32(pUTF8,&local_18,&local_11);
            pUTF8 = pUTF8 + iVar2;
            if ((int)uVar3 <= (int)((0xffff < local_18) + 1 + iVar4)) goto LAB_000d24b0;
            puVar1 = pUTF16 + iVar4;
            if (local_18 < 0x10000) {
              *puVar1 = (ushort)local_18;
              iVar2 = 1;
            }
            else {
              *puVar1 = (ushort)(local_18 + -0x10000 >> 10) | 0xd800;
              iVar2 = 2;
              puVar1[1] = (ushort)(local_18 + -0x10000) & 0x3ff | 0xdc00;
            }
            iVar4 = iVar4 + iVar2;
            if (local_11 == false) break;
            iVar4 = iVar4 - ((0xffff < local_18) + 1);
            if (*pUTF8 == '\0') goto LAB_000d24b0;
          }
        }
      }
    }
    else if ((ePolicy & STRINGCONVERT_SKIP) == STRINGCONVERT_REPLACE) {
      iVar4 = 0;
      while (*pUTF8 != '\0') {
        local_11 = false;
        iVar2 = Q_UTF8ToUChar32(pUTF8,&local_18,&local_11);
        pUTF8 = pUTF8 + iVar2;
        if ((int)uVar3 <= (int)(iVar4 + 1 + (uint)(0xffff < local_18))) break;
        puVar1 = pUTF16 + iVar4;
        if (local_18 < 0x10000) {
          *puVar1 = (ushort)local_18;
          iVar2 = 1;
        }
        else {
          *puVar1 = (ushort)(local_18 + -0x10000 >> 10) | 0xd800;
          puVar1[1] = (ushort)(local_18 + -0x10000) & 0x3ff | 0xdc00;
          iVar2 = 2;
        }
        iVar4 = iVar4 + iVar2;
        if (local_11 != false) {
          *pUTF16 = 0;
          return 0;
        }
      }
    }
    else {
      while (*pUTF8 != '\0') {
        while( true ) {
          local_11 = false;
          iVar2 = Q_UTF8ToUChar32(pUTF8,&local_18,&local_11);
          pUTF8 = pUTF8 + iVar2;
          if ((int)uVar3 <= (int)((0xffff < local_18) + 1 + iVar4)) goto LAB_000d24b0;
          puVar1 = pUTF16 + iVar4;
          if (local_18 < 0x10000) {
            *puVar1 = (ushort)local_18;
            iVar2 = 1;
          }
          else {
            *puVar1 = (ushort)(local_18 + -0x10000 >> 10) | 0xd800;
            puVar1[1] = (ushort)(local_18 + -0x10000) & 0x3ff | 0xdc00;
            iVar2 = 2;
          }
          iVar4 = iVar4 + iVar2;
          if (local_11 == false) break;
          iVar4 = iVar4 - ((0xffff < local_18) + 1);
          if (*pUTF8 == '\0') goto LAB_000d24b0;
        }
      }
    }
LAB_000d24b0:
    pUTF16[iVar4] = 0;
  }
LAB_000d24b6:
  return iVar4 * 2 + 2;
}


// Q_UTF8ToUTF32  @ 000d23a0
/* WARNING: Enum "EStringConvertErrorPolicy": Some values do not have unique names */

int Q_UTF8ToUTF32(char *pUTF8,uchar32 *pUTF32,int cubDestSizeInBytes,
                 EStringConvertErrorPolicy ePolicy)

{
  int iVar1;
  
  iVar1 = anon_unknown.dwarf_f5b44::
          Q_UnicodeConvertT<char,_wchar_t,_true,_(*_Q_UTF8ToUChar32),_(*__anonymous_::Q_UChar32ToUTF32Len),_(*__anonymous_::Q_UChar32ToUTF32)>
                    (pUTF8,(int)pUTF32,(wchar_t *)cubDestSizeInBytes,ePolicy,
                     (EStringConvertErrorPolicy)pUTF32);
  return iVar1;
}


// Q_UnicodeAdvance  @ 000d28e0
char * Q_UnicodeAdvance(char *pUTF8,int nChars)

{
  int iVar1;
  uchar32 local_18;
  bool local_11;
  
  if ((0 < nChars) && (*pUTF8 != '\0')) {
    do {
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bError@[???] */
      iVar1 = Q_UTF8ToUChar32(pUTF8,&local_18,&local_11);
      pUTF8 = pUTF8 + iVar1;
      nChars = nChars + -1;
      if (nChars == 0) {
        return pUTF8;
      }
    } while (*pUTF8 != '\0');
  }
  return pUTF8;
}


// Q_UnicodeLength  @ 000d2890
int Q_UnicodeLength(char *pUTF8)

{
  int iVar1;
  int iVar2;
  uchar32 local_18;
  bool local_11;
  
                    /* Unresolved local var: int nChars@[???] */
  iVar2 = 0;
  if (*pUTF8 != '\0') {
    iVar2 = 0;
    do {
                    /* Unresolved local var: bool bError@[???]
                       Unresolved local var: uchar32 uVal@[???] */
      iVar2 = iVar2 + 1;
      iVar1 = Q_UTF8ToUChar32(pUTF8,&local_18,&local_11);
      pUTF8 = pUTF8 + iVar1;
    } while (*pUTF8 != '\0');
  }
  return iVar2;
}


// Q_UnicodeRepair  @ 000d2ce0
int Q_UnicodeRepair(char *pUTF8)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  char *pcVar7;
  int local_18;
  bool local_11;
  
                    /* Unresolved local var: int nOut@[???] */
  if (pUTF8 == (char *)0x0) {
    iVar6 = 0;
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    pcVar7 = (char *)0x0;
    while (*pcVar7 != '\0') {
      local_11 = false;
      iVar4 = Q_UTF8ToUChar32(pcVar7,&local_18,&local_11);
      pcVar7 = pcVar7 + iVar4;
      iVar4 = 1;
      if ((0x7f < local_18) && (iVar4 = 2, 0x7ff < local_18)) {
        iVar4 = (0xffff < local_18) + 3;
      }
      iVar6 = iVar6 + iVar4;
      if (local_11 != false) {
        iVar4 = 1;
        if ((local_18 < 0x80) || (iVar4 = 2, local_18 < 0x800)) {
          iVar6 = iVar6 - iVar4;
        }
        else {
          iVar6 = iVar6 - ((0xffff < local_18) + 3);
        }
      }
    }
  }
  else {
    iVar6 = 0;
                    /* Unresolved local var: int nOutElems@[???]
                       Unresolved local var: int nMaxOut@[???]
                       Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: bool bErr@[???] */
    pcVar7 = pUTF8;
    while (*pcVar7 != '\0') {
      while( true ) {
        local_11 = false;
        iVar4 = Q_UTF8ToUChar32(pcVar7,&local_18,&local_11);
        pcVar7 = pcVar7 + iVar4;
        iVar4 = 1;
        if ((0x7f < local_18) && (iVar4 = 2, 0x7ff < local_18)) {
          iVar4 = (0xffff < local_18) + 3;
        }
        if (0xfffe < iVar4 + iVar6) goto LAB_000d2db0;
        pbVar1 = (byte *)(pUTF8 + iVar6);
        bVar5 = (byte)local_18;
        if (local_18 < 0x80) {
          *pbVar1 = bVar5;
          iVar4 = 1;
        }
        else {
          bVar2 = (byte)(local_18 >> 6);
          if (local_18 < 0x800) {
            *pbVar1 = bVar2 | 0xc0;
            pbVar1[1] = bVar5 & 0x3f | 0x80;
            iVar4 = 2;
          }
          else {
            bVar3 = (byte)(local_18 >> 0xc);
            if (local_18 < 0x10000) {
              *pbVar1 = bVar3 | 0xe0;
              pbVar1[1] = bVar2 & 0x3f | 0x80;
              pbVar1[2] = bVar5 & 0x3f | 0x80;
              iVar4 = 3;
            }
            else {
              *pbVar1 = (byte)(local_18 >> 0x12) & 7 | 0xf0;
              pbVar1[1] = bVar3 & 0x3f | 0x80;
              pbVar1[2] = bVar2 & 0x3f | 0x80;
              pbVar1[3] = bVar5 & 0x3f | 0x80;
              iVar4 = 4;
            }
          }
        }
        iVar6 = iVar6 + iVar4;
        if (local_11 == false) break;
        iVar4 = 1;
        if ((0x7f < local_18) && (iVar4 = 2, 0x7ff < local_18)) {
          iVar4 = (0xffff < local_18) + 3;
        }
        iVar6 = iVar6 - iVar4;
        if (*pcVar7 == '\0') goto LAB_000d2db0;
      }
    }
LAB_000d2db0:
    pUTF8[iVar6] = '\0';
  }
  return iVar6 + 1;
}


// Q_UnicodeValidate  @ 000d2820
qboolean Q_UnicodeValidate(char *pUTF8)

{
  qboolean qVar1;
  int iVar2;
  uchar32 local_14;
  bool local_d;
  
                    /* Unresolved local var: bool bError@[???] */
  qVar1 = 1;
  local_d = false;
  if (*pUTF8 != '\0') {
    while( true ) {
      iVar2 = Q_UTF8ToUChar32(pUTF8,&local_14,&local_d);
                    /* Unresolved local var: uchar32 uVal@[???]
                       Unresolved local var: int nCharSize@[???] */
      if ((local_d != false) || (iVar2 == 6)) break;
      pUTF8 = pUTF8 + iVar2;
      if (*pUTF8 == '\0') {
        return 1;
      }
    }
    qVar1 = 0;
  }
  return qVar1;
}


// Q_atof  @ 0005f680
float Q_atof(char *str)

{
  char cVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  
                    /* Unresolved local var: double val@[???]
                       Unresolved local var: int sign@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int decimal@[DW_OP_reg6(ESI)]
                       Unresolved local var: int total@[???] */
  cVar1 = *str;
  if (cVar1 == '-') {
    cVar1 = str[1];
    str = str + 1;
    fVar3 = -1.0;
    iVar5 = -1;
  }
  else {
    iVar5 = 1;
    fVar3 = 1.0;
  }
  if (cVar1 == '0') {
    if ((str[1] == 'X') || (str[1] == 'x')) {
      fVar2 = 0.0;
      pcVar7 = str + 2;
      while( true ) {
        while( true ) {
          cVar1 = *pcVar7;
          while( true ) {
            iVar5 = (int)cVar1;
            pcVar7 = pcVar7 + 1;
            if (9 < iVar5 - 0x30U) break;
            cVar1 = *pcVar7;
            fVar2 = ((float)iVar5 + fVar2 * 16.0) - 48.0;
          }
          if (5 < iVar5 - 0x61U) break;
          fVar2 = (((float)iVar5 + fVar2 * 16.0) - 97.0) + 10.0;
        }
        if (5 < iVar5 - 0x41U) break;
        fVar2 = (((float)iVar5 + fVar2 * 16.0) - 65.0) + 10.0;
      }
      return fVar2 * fVar3;
    }
  }
  else if (cVar1 == '\'') {
    return (float)(str[1] * iVar5);
  }
  fVar2 = 0.0;
  iVar6 = 0;
  iVar5 = -1;
  do {
    do {
      iVar8 = iVar5;
      cVar1 = *str;
      str = str + 1;
      iVar4 = (int)cVar1;
      iVar5 = iVar6;
    } while (cVar1 == 0x2c);
    do {
      iVar5 = iVar6;
      if (iVar4 == 0x2e) break;
      if (9 < iVar4 - 0x30U) {
        if ((iVar8 != -1) && (iVar8 < iVar6)) {
          do {
            iVar6 = iVar6 + -1;
            fVar2 = fVar2 / 10.0;
          } while (iVar6 != iVar8);
        }
        return fVar2 * fVar3;
      }
      iVar6 = iVar6 + 1;
      cVar1 = *str;
      str = str + 1;
      fVar2 = ((float)iVar4 + fVar2 * 10.0) - 48.0;
      iVar4 = (int)cVar1;
      iVar5 = iVar6;
    } while (cVar1 != 0x2c);
  } while( true );
}


// Q_atoi  @ 0005f5a0
int Q_atoi(char *str)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int val@[???]
                       Unresolved local var: int sign@[???]
                       Unresolved local var: int c@[???] */
  iVar5 = 1;
  cVar1 = *str;
  if (cVar1 == '-') {
    cVar1 = str[1];
    str = str + 1;
    iVar5 = -1;
  }
  if (cVar1 == '0') {
    if ((str[1] == 'X') || (str[1] == 'x')) {
      pcVar3 = str + 2;
      iVar2 = 0;
      while( true ) {
        while( true ) {
          cVar1 = *pcVar3;
          while( true ) {
            iVar4 = (int)cVar1;
            pcVar3 = pcVar3 + 1;
            if (9 < iVar4 - 0x30U) break;
            iVar2 = iVar4 + -0x30 + iVar2 * 0x10;
            cVar1 = *pcVar3;
          }
          if (5 < iVar4 - 0x61U) break;
          iVar2 = iVar4 + -0x57 + iVar2 * 0x10;
        }
        if (5 < iVar4 - 0x41U) break;
        iVar2 = iVar4 + -0x37 + iVar2 * 0x10;
      }
      return iVar5 * iVar2;
    }
  }
  else if (cVar1 == '\'') {
    return str[1] * iVar5;
  }
  iVar4 = (int)cVar1;
  iVar2 = 0;
  if (iVar4 - 0x30U < 10) {
    iVar2 = 0;
    do {
      str = str + 1;
      iVar2 = iVar4 + -0x30 + iVar2 * 10;
      iVar4 = (int)*str;
    } while (iVar4 - 0x30U < 10);
    iVar2 = iVar2 * iVar5;
  }
  return iVar2;
}


// Q_log2  @ 00080720
int Q_log2(int val)

{
  int iVar1;
  
                    /* Unresolved local var: int answer@[???] */
  iVar1 = 0;
  while (val = val >> 1, val != 0) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


// Q_memcmp  @ 0005f230
int Q_memcmp(void *m1,void *m2,int count)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: int byteLoops@[???]
                       Unresolved local var: int numLoops@[???]
                       Unresolved local var: int i@[???] */
  if (0 < count >> 2) {
    if (*(int *)m1 != *(int *)m2) {
      return -1;
    }
    iVar1 = 0;
    while (iVar1 = iVar1 + 1, iVar1 != count >> 2) {
      if (*(int *)((int)m1 + iVar1 * 4) != *(int *)((int)m2 + iVar1 * 4)) {
        return -1;
      }
    }
  }
  iVar1 = 0;
  if (((count & 3U) != 0) && (iVar1 = -1, *(char *)m1 == *(char *)m2)) {
    uVar2 = 0;
    do {
      uVar2 = uVar2 + 1;
      if (uVar2 == (count & 3U)) {
        return 0;
      }
    } while (*(char *)((int)m1 + uVar2) == *(char *)((int)m2 + uVar2));
    return -1;
  }
  return iVar1;
}


// Q_memcpy  @ 0005f190
void Q_memcpy(void *dest,void *src,int count)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  if (7 < (uint)count) {
    uVar4 = count;
    if (((uint)dest & 1) != 0) {
      uVar1 = *(undefined1 *)src;
      uVar4 = count - 1;
      src = (void *)((int)src + 1);
      *(undefined1 *)dest = uVar1;
      dest = (void *)((int)dest + 1);
    }
    if (((uint)dest & 2) != 0) {
      uVar2 = *(undefined2 *)src;
      uVar4 = uVar4 - 2;
      src = (void *)((int)src + 2);
      *(undefined2 *)dest = uVar2;
      dest = (void *)((int)dest + 2);
    }
    if (((uint)dest & 4) != 0) {
      uVar3 = *(undefined4 *)src;
      uVar4 = uVar4 - 4;
      src = (void *)((int)src + 4);
      *(undefined4 *)dest = uVar3;
      dest = (void *)((int)dest + 4);
    }
    count = uVar4 & 3;
    for (uVar4 = uVar4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)dest = *(undefined4 *)src;
      src = (undefined4 *)((int)src + 4);
      dest = (undefined4 *)((int)dest + 4);
    }
  }
  iVar5 = 0;
  if ((count & 4U) != 0) {
    *(undefined4 *)dest = *(undefined4 *)src;
    iVar5 = 4;
  }
  if ((count & 2U) != 0) {
    *(undefined2 *)((int)dest + iVar5) = *(undefined2 *)((int)src + iVar5);
    iVar5 = iVar5 + 2;
  }
  if ((count & 1U) != 0) {
    *(undefined1 *)((int)dest + iVar5) = *(undefined1 *)((int)src + iVar5);
  }
  return;
}


// Q_memset  @ 0005f100
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


// Q_ntohs  @ 000c41a0
ushort Q_ntohs(ushort netshort)

{
                    /* Unresolved local var: ushort __v@[DW_OP_reg0(EAX)]
                       Unresolved local var: ushort __x@[???] */
  return netshort >> 8 | netshort << 8;
}


// Q_strcasecmp  @ 0005f4f0
int Q_strcasecmp(char *s1,char *s2)

{
  int iVar1;
  
                    /* Unresolved local var: int c1@[???]
                       Unresolved local var: int c2@[???] */
  if (s1 == (char *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = 1;
    if (s2 != (char *)0x0) {
      iVar1 = strncasecmp(s1,s2,99999);
    }
  }
  return iVar1;
}


// Q_strcat  @ 0005f3b0
void Q_strcat(char *dest,char *src)

{
  char cVar1;
  
                    /* Unresolved local var: int count@[???] */
  if (dest != (char *)0x0) {
    cVar1 = *dest;
    while (cVar1 != '\0') {
      dest = dest + 1;
      cVar1 = *dest;
    }
    if ((dest != (char *)0x0) && (src != (char *)0x0)) {
      while (*src != '\0') {
        *dest = *src;
        dest = dest + 1;
        src = src + 1;
        if ((src == (char *)0x0) || (dest == (char *)0x0)) break;
      }
    }
  }
  *dest = '\0';
  return;
}


// Q_strcmp  @ 0005f400
int Q_strcmp(char *s1,char *s2)

{
  int iVar1;
  int iVar2;
  
  if ((s2 != (char *)0x0) && (s1 != (char *)0x0)) {
    if (*s1 != *s2) {
      return -1;
    }
    if (*s1 == '\0') {
      return 0;
    }
    iVar2 = 0;
    while (iVar1 = iVar2 + 1, s1[iVar1] == s2[iVar2 + 1]) {
      iVar2 = iVar2 + 1;
      if (s1[iVar1] == '\0') {
        return 0;
      }
    }
  }
  return -1;
}


// Q_strcpy  @ 0005f2b0
void Q_strcpy(char *dest,char *src)

{
  for (; ((src != (char *)0x0 && (dest != (char *)0x0)) && (*src != '\0')); src = src + 1) {
    *dest = *src;
    dest = dest + 1;
  }
  *dest = '\0';
  return;
}


// Q_stricmp  @ 0005f530
int Q_stricmp(char *s1,char *s2)

{
  int iVar1;
  
                    /* Unresolved local var: int c1@[???]
                       Unresolved local var: int c2@[???] */
  if (s1 == (char *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = 1;
    if (s2 != (char *)0x0) {
      iVar1 = strncasecmp(s1,s2,99999);
    }
  }
  return iVar1;
}


// Q_striprefix  @ 0005fa70
qboolean Q_striprefix(char *str,char *prefix)

{
  char cVar1;
  __int32_t **pp_Var2;
  char cVar3;
  char cVar4;
  
  if ((prefix == (char *)0x0) || (str == (char *)0x0)) {
    return false;
  }
  cVar4 = *str;
  if (cVar4 == '\0') {
LAB_0005fad4:
    cVar1 = *prefix;
  }
  else {
    cVar3 = *prefix;
    cVar1 = '\0';
    if (cVar3 != '\0') {
      pp_Var2 = __ctype_tolower_loc();
      do {
                    /* Unresolved local var: int __res@[???] */
                    /* Unresolved local var: int __res@[???] */
        if ((*pp_Var2)[cVar4] != (*pp_Var2)[cVar3]) goto LAB_0005fad4;
        cVar4 = str[1];
        if (cVar4 == '\0') {
          cVar1 = prefix[1];
          goto LAB_0005fad7;
        }
        cVar3 = prefix[1];
        str = str + 1;
        prefix = prefix + 1;
      } while (cVar3 != '\0');
      cVar1 = '\0';
    }
  }
LAB_0005fad7:
  return (uint)(cVar1 == '\0');
}


// Q_stristr  @ 0009c1f0
char * Q_stristr(char *pStr,char *pSearch)

{
  __int32_t *p_Var1;
  byte *pbVar2;
  __int32_t **pp_Var3;
  byte *pbVar4;
  byte bVar5;
  byte *pbVar6;
  
                    /* Unresolved local var: char * pLetter@[???] */
  if ((pSearch != (char *)0x0) && (pStr != (char *)0x0)) {
    bVar5 = *pStr;
    if (bVar5 == 0) {
      return (char *)0x0;
    }
    pp_Var3 = __ctype_tolower_loc();
    p_Var1 = *pp_Var3;
    do {
                    /* Unresolved local var: int __res@[???] */
      while (pbVar2 = (byte *)pStr, pStr = (char *)(pbVar2 + 1),
            p_Var1[bVar5] == p_Var1[(byte)*pSearch]) {
                    /* Unresolved local var: char * pMatch@[???]
                       Unresolved local var: char * pTest@[???] */
        if (pSearch[1] == 0) {
          return (char *)pbVar2;
        }
        bVar5 = *pStr;
        if (bVar5 == 0) {
          return (char *)0x0;
        }
                    /* Unresolved local var: int __res@[???] */
                    /* Unresolved local var: int __res@[???] */
        if (p_Var1[bVar5] == p_Var1[(byte)pSearch[1]]) {
          pbVar6 = (byte *)(pSearch + 1);
          pbVar4 = (byte *)pStr;
          do {
            pbVar6 = pbVar6 + 1;
            pbVar4 = pbVar4 + 1;
            if (*pbVar6 == 0) {
              return (char *)pbVar2;
            }
            if (*pbVar4 == 0) {
              return (char *)0x0;
            }
          } while (p_Var1[*pbVar4] == p_Var1[*pbVar6]);
        }
      }
      bVar5 = *pStr;
    } while (bVar5 != 0);
  }
  return (char *)0x0;
}


// Q_strlen  @ 0005f330
int Q_strlen(char *str)

{
  char cVar1;
  int iVar2;
  
                    /* Unresolved local var: int count@[???] */
  iVar2 = 0;
  if (str != (char *)0x0) {
    cVar1 = *str;
    while (cVar1 != '\0') {
      iVar2 = iVar2 + 1;
      cVar1 = str[iVar2];
    }
  }
  return iVar2;
}


// Q_strlwr  @ 0005f840
char * Q_strlwr(char *src)

{
  __int32_t **pp_Var1;
  char cVar2;
  
                    /* Unresolved local var: char * p@[???] */
  cVar2 = *src;
  if (cVar2 != '\0') {
    pp_Var1 = __ctype_tolower_loc();
    do {
                    /* Unresolved local var: int __res@[???] */
      *src = (char)(*pp_Var1)[cVar2];
      src = src + 1;
      cVar2 = *src;
    } while (cVar2 != '\0');
  }
  return src;
}


// Q_strncasecmp  @ 0005f4c0
int Q_strncasecmp(char *s1,char *s2,int n)

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


// Q_strncmp  @ 0005f460
int Q_strncmp(char *s1,char *s2,int count)

{
  int iVar1;
  int iVar2;
  
  if ((s2 == (char *)0x0) || (s1 == (char *)0x0)) {
    return -1;
  }
  iVar2 = 0;
  if (count != 0) {
    iVar2 = -1;
    if ((*s1 == *s2) && (iVar2 = 0, *s1 != '\0')) {
      iVar2 = 0;
      do {
        if (iVar2 == count + -1) break;
        iVar1 = iVar2 + 1;
        if (s1[iVar1] != s2[iVar2 + 1]) {
          return -1;
        }
        iVar2 = iVar2 + 1;
      } while (s1[iVar1] != '\0');
      iVar2 = 0;
    }
  }
  return iVar2;
}


// Q_strncpy  @ 0005f2e0
void Q_strncpy(char *dest,char *src,int count)

{
  strncpy(dest,src,count);
  return;
}


// Q_strncpy_s  @ 0005f2f0
void Q_strncpy_s(char *dest,char *src,int count)

{
  strncpy(dest,src,count);
  dest[count + -1] = '\0';
  return;
}


// Q_strnicmp  @ 0005f570
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


// Q_strrchr  @ 0005f350
char * Q_strrchr(char *s,char c)

{
  char *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: int len@[DW_OP_reg1(ECX)] */
                    /* Unresolved local var: int count@[???] */
  if (s == (char *)0x0) {
    pcVar1 = (char *)0x0;
    iVar2 = 0;
  }
  else if (*s == '\0') {
    iVar2 = 0;
    pcVar1 = s;
  }
  else {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      pcVar1 = s + iVar2;
    } while (s[iVar2] != '\0');
  }
  do {
    if (iVar2 == 0) {
      return (char *)0x0;
    }
    pcVar1 = pcVar1 + -1;
    iVar2 = iVar2 + -1;
  } while (*pcVar1 != c);
  return pcVar1;
}


// Q_strstr  @ 0005f910
char * Q_strstr(char *s1,char *search)

{
  char *pcVar1;
  
  pcVar1 = strstr(s1,search);
  return pcVar1;
}


// Q_strtoull  @ 0005f920
uint64 Q_strtoull(char *str)

{
  ulonglong uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_10;
  
                    /* Unresolved local var: uint64 iResult@[???]
                       Unresolved local var: int isNegative@[???] */
  cVar5 = *str;
  while ((cVar5 == '\t' || (cVar5 == ' '))) {
    str = str + 1;
    cVar5 = *str;
  }
  if (cVar5 == '+') {
    cVar5 = str[1];
    bVar2 = false;
    str = str + 1;
  }
  else {
    bVar2 = false;
    if (cVar5 == '-') {
      cVar5 = str[1];
      bVar2 = true;
      str = str + 1;
    }
  }
  local_10 = 0;
  local_14 = 0;
  if ((byte)(cVar5 - 0x30U) < 10) {
    if (!bVar2) {
      local_1c = 0;
      local_18 = 0;
      do {
        uVar1 = (ulonglong)local_1c;
        uVar3 = (uint)(uVar1 * 10);
        uVar4 = (int)cVar5 - 0x30;
        local_1c = uVar4 + uVar3;
        local_18 = ((int)uVar4 >> 0x1f) + (int)(uVar1 * 10 >> 0x20) + local_18 * 10 +
                   (uint)CARRY4(uVar4,uVar3);
        str = str + 1;
        cVar5 = *str;
      } while ((byte)(cVar5 - 0x30U) < 10);
      return CONCAT44(local_18,local_1c);
    }
    local_14 = 0;
    local_10 = 0;
    do {
      uVar1 = (ulonglong)local_14;
      uVar3 = (uint)(uVar1 * 10);
      uVar4 = (int)cVar5 - 0x30;
      local_14 = uVar3 - uVar4;
      local_10 = (((int)(uVar1 * 10 >> 0x20) + local_10 * 10) - ((int)uVar4 >> 0x1f)) -
                 (uint)(uVar3 < uVar4);
      str = str + 1;
      cVar5 = *str;
    } while ((byte)(cVar5 - 0x30U) < 10);
  }
  return CONCAT44(local_10,local_14);
}


