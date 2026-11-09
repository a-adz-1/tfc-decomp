// FontPlat_Bitmap::Create  @ 001d78e0
FontPlat_Bitmap * FontPlat_Bitmap::Create(char *name,FileImageStream *pStream,int id)

{
  uchar *puVar1;
  bool bVar2;
  FontPlat_Bitmap *pFVar3;
  size_t sVar4;
  char *pcVar5;
  _func_int_varargs *p_Var6;
  
                    /* Unresolved local var: FontPlat_Bitmap * pBitmap@[???] */
  pFVar3 = operator_new(0x418);
  (pFVar3->m_FontData).m_BitmapCharHeight = 0;
  (pFVar3->super_BaseFontPlat)._vptr_BaseFontPlat =
       (_func_int_varargs **)&PTR__FontPlat_Bitmap_002722f4;
  (pFVar3->m_FontData).m_BitmapCharWidth = 0;
  (pFVar3->m_FontData).m_pBitmap = (uchar *)0x0;
  pFVar3->m_pName = (char *)0x0;
  if (pFVar3 != (FontPlat_Bitmap *)0x0) {
    bVar2 = LoadVFontDataFrom32BitTGA(pStream,&pFVar3->m_FontData);
    if (bVar2) {
      sVar4 = strlen(name);
      pcVar5 = operator_new__(sVar4 + 1);
      pFVar3->m_pName = pcVar5;
      if (pcVar5 != (char *)0x0) {
        strcpy(pcVar5,name);
        pFVar3->_id = id;
        return pFVar3;
      }
      p_Var6 = (pFVar3->super_BaseFontPlat)._vptr_BaseFontPlat[1];
      if (p_Var6 != ~FontPlat_Bitmap) goto LAB_001d79e0;
      puVar1 = (pFVar3->m_FontData).m_pBitmap;
      (pFVar3->super_BaseFontPlat)._vptr_BaseFontPlat =
           (_func_int_varargs **)&PTR__FontPlat_Bitmap_002722f4;
    }
    else {
      p_Var6 = (pFVar3->super_BaseFontPlat)._vptr_BaseFontPlat[1];
      if (p_Var6 != ~FontPlat_Bitmap) {
LAB_001d79e0:
        (*p_Var6)(pFVar3);
        return (FontPlat_Bitmap *)0x0;
      }
      pcVar5 = pFVar3->m_pName;
      (pFVar3->super_BaseFontPlat)._vptr_BaseFontPlat =
           (_func_int_varargs **)&PTR__FontPlat_Bitmap_002722f4;
      if (pcVar5 != (char *)0x0) {
        operator_delete__(pcVar5);
      }
      puVar1 = (pFVar3->m_FontData).m_pBitmap;
    }
    if (puVar1 != (uchar *)0x0) {
      operator_delete__(puVar1);
    }
    operator_delete(pFVar3);
  }
  return (FontPlat_Bitmap *)0x0;
}


// FontPlat_Bitmap::DrawSetTextFont  @ 001d6a60
/* DWARF original prototype: void DrawSetTextFont(FontPlat_Bitmap * this, SurfacePlat * Plat) */

void __thiscall FontPlat_Bitmap::DrawSetTextFont(FontPlat_Bitmap *this,SurfacePlat *Plat)

{
  return;
}


// FontPlat_Bitmap::FontPlat_Bitmap  @ 001d78b0
/* DWARF original prototype: void FontPlat_Bitmap(FontPlat_Bitmap * this) */

void __thiscall FontPlat_Bitmap::FontPlat_Bitmap(FontPlat_Bitmap *this)

{
  (this->m_FontData).m_BitmapCharHeight = 0;
  (this->m_FontData).m_BitmapCharWidth = 0;
  (this->super_BaseFontPlat)._vptr_BaseFontPlat =
       (_func_int_varargs **)&PTR__FontPlat_Bitmap_002722f4;
  (this->m_FontData).m_pBitmap = (uchar *)0x0;
  this->m_pName = (char *)0x0;
  return;
}


// FontPlat_Bitmap::GetCharABCwide  @ 001d6a00
/* DWARF original prototype: void GetCharABCwide(FontPlat_Bitmap * this, int ch, int * a, int * b,
   int * c) */

void __thiscall FontPlat_Bitmap::GetCharABCwide(FontPlat_Bitmap *this,int ch,int *a,int *b,int *c)

{
  if (ch < 0) {
    ch = 0;
  }
  *c = 0;
  *a = 0;
  if (0xff < ch) {
    ch = 0xff;
  }
  *b = (this->m_FontData).m_CharWidths[ch] + 1;
  return;
}


// FontPlat_Bitmap::GetTall  @ 001d6a40
/* DWARF original prototype: int GetTall(FontPlat_Bitmap * this) */

int __thiscall FontPlat_Bitmap::GetTall(FontPlat_Bitmap *this)

{
  return (this->m_FontData).m_BitmapCharHeight;
}


// FontPlat_Bitmap::equals  @ 001d6bc0
/* DWARF original prototype: bool equals(FontPlat_Bitmap * this, char * name, int tall, int wide,
   float rotation, int weight, bool italic, bool underline, bool strikeout, bool symbol) */

bool __thiscall
FontPlat_Bitmap::equals
          (FontPlat_Bitmap *this,char *name,int tall,int wide,float rotation,int weight,bool italic,
          bool underline,bool strikeout,bool symbol)

{
  int iVar1;
  
  iVar1 = strcasecmp(name,this->m_pName);
  return iVar1 == 0;
}


// FontPlat_Bitmap::getCharRGBA  @ 001d68c0
/* DWARF original prototype: void getCharRGBA(FontPlat_Bitmap * this, int ch, int rgbaX, int rgbaY,
   int rgbaWide, int rgbaTall, uchar * rgba) */

void __thiscall
FontPlat_Bitmap::getCharRGBA
          (FontPlat_Bitmap *this,int ch,int rgbaX,int rgbaY,int rgbaWide,int rgbaTall,uchar *rgba)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_20;
  int local_1c;
  int local_18;
  
                    /* Unresolved local var: uchar * pSrcPos@[???]
                       Unresolved local var: uchar * pOutPos@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int outX@[???]
                       Unresolved local var: int outY@[???] */
  local_18 = 0x100;
  if ((ch < 0x100) && (local_18 = 0, -1 < ch)) {
    local_18 = ch;
  }
  iVar6 = (this->m_FontData).m_BitmapCharHeight;
  if (0 < iVar6) {
    iVar7 = (this->m_FontData).m_BitmapCharWidth;
    local_20 = 0;
    local_1c = (rgbaWide * rgbaY + rgbaX) * 4;
    do {
      iVar5 = iVar7 * 0x100;
      iVar2 = local_18 * iVar7;
      puVar1 = (this->m_FontData).m_pBitmap;
      if (0 < iVar7) {
        iVar3 = 0;
        iVar6 = local_1c;
        do {
          while ((rgbaWide <= rgbaX + iVar3 || (rgbaTall <= rgbaY + local_20))) {
LAB_001d6989:
            iVar3 = iVar3 + 1;
            iVar6 = iVar6 + 4;
            if (iVar7 <= iVar3) goto LAB_001d69cd;
          }
          puVar4 = rgba + iVar6;
          if (puVar1[iVar3 + iVar2 + iVar5 * local_20] != '\0') {
            puVar4[3] = 0xff;
            puVar4[2] = 0xff;
            puVar4[1] = 0xff;
            *puVar4 = 0xff;
            iVar7 = (this->m_FontData).m_BitmapCharWidth;
            goto LAB_001d6989;
          }
          iVar3 = iVar3 + 1;
          iVar6 = iVar6 + 4;
          puVar4[3] = '\0';
          puVar4[2] = '\0';
          puVar4[1] = '\0';
          *puVar4 = '\0';
          iVar7 = (this->m_FontData).m_BitmapCharWidth;
        } while (iVar3 < iVar7);
LAB_001d69cd:
        iVar6 = (this->m_FontData).m_BitmapCharHeight;
      }
      local_20 = local_20 + 1;
      local_1c = local_1c + rgbaWide * 4;
    } while (local_20 < iVar6);
  }
  return;
}


// FontPlat_Bitmap::getId  @ 001d6a50
/* DWARF original prototype: int getId(FontPlat_Bitmap * this) */

int __thiscall FontPlat_Bitmap::getId(FontPlat_Bitmap *this)

{
  return this->_id;
}


// FontPlat_Bitmap::~FontPlat_Bitmap  @ 001d6b70
/* DWARF original prototype: void ~FontPlat_Bitmap(FontPlat_Bitmap * this, int __in_chrg) */

void __thiscall FontPlat_Bitmap::~FontPlat_Bitmap(FontPlat_Bitmap *this,int __in_chrg)

{
  char *pcVar1;
  uchar *puVar2;
  
  pcVar1 = this->m_pName;
  (this->super_BaseFontPlat)._vptr_BaseFontPlat =
       (_func_int_varargs **)&PTR__FontPlat_Bitmap_002722f4;
  if (pcVar1 != (char *)0x0) {
    operator_delete__(pcVar1);
  }
  puVar2 = (this->m_FontData).m_pBitmap;
  if (puVar2 != (uchar *)0x0) {
    operator_delete__(puVar2);
    return;
  }
  return;
}


// FontPlat_Bitmap::~FontPlat_Bitmap  @ 001d6d10
/* DWARF original prototype: void ~FontPlat_Bitmap(FontPlat_Bitmap * this, int __in_chrg) */

void __thiscall FontPlat_Bitmap::~FontPlat_Bitmap(FontPlat_Bitmap *this,int __in_chrg)

{
  char *pcVar1;
  uchar *puVar2;
  
  pcVar1 = this->m_pName;
  (this->super_BaseFontPlat)._vptr_BaseFontPlat =
       (_func_int_varargs **)&PTR__FontPlat_Bitmap_002722f4;
  if (pcVar1 != (char *)0x0) {
    operator_delete__(pcVar1);
  }
  puVar2 = (this->m_FontData).m_pBitmap;
  if (puVar2 != (uchar *)0x0) {
    operator_delete__(puVar2);
  }
  operator_delete(this);
  return;
}


