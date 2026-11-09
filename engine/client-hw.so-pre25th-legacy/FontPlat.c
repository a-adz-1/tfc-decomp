// FontPlat_Bitmap::Create  @ 00221ad0
FontPlat_Bitmap * FontPlat_Bitmap::Create(char *name,FileImageStream *pStream,int id)

{
  bool bVar1;
  FontPlat_Bitmap *pFVar2;
  size_t sVar3;
  char *__dest;
  
                    /* Unresolved local var: FontPlat_Bitmap * pBitmap@[???] */
  pFVar2 = operator_new(0x418);
  (pFVar2->super_BaseFontPlat)._vptr_BaseFontPlat =
       (_func_int_varargs **)&PTR__FontPlat_Bitmap_00296da8;
  (pFVar2->m_FontData).m_BitmapCharHeight = 0;
  (pFVar2->m_FontData).m_BitmapCharWidth = 0;
  (pFVar2->m_FontData).m_pBitmap = (uchar *)0x0;
  pFVar2->m_pName = (char *)0x0;
  bVar1 = LoadVFontDataFrom32BitTGA(pStream,&pFVar2->m_FontData);
  if (bVar1) {
    sVar3 = strlen(name);
    __dest = operator_new__(sVar3 + 1);
    pFVar2->m_pName = __dest;
    if (__dest != (char *)0x0) {
      strcpy(__dest,name);
      pFVar2->_id = id;
      return pFVar2;
    }
  }
  (*(pFVar2->super_BaseFontPlat)._vptr_BaseFontPlat[1])(pFVar2);
  return (FontPlat_Bitmap *)0x0;
}


// FontPlat_Bitmap::DrawSetTextFont  @ 00220e60
/* DWARF original prototype: void DrawSetTextFont(FontPlat_Bitmap * this, SurfacePlat * Plat) */

void __thiscall FontPlat_Bitmap::DrawSetTextFont(FontPlat_Bitmap *this,SurfacePlat *Plat)

{
  return;
}


// FontPlat_Bitmap::FontPlat_Bitmap  @ 00221aa0
/* DWARF original prototype: void FontPlat_Bitmap(FontPlat_Bitmap * this) */

void __thiscall FontPlat_Bitmap::FontPlat_Bitmap(FontPlat_Bitmap *this)

{
  (this->m_FontData).m_BitmapCharHeight = 0;
  (this->m_FontData).m_BitmapCharWidth = 0;
  (this->super_BaseFontPlat)._vptr_BaseFontPlat =
       (_func_int_varargs **)&PTR__FontPlat_Bitmap_00296da8;
  (this->m_FontData).m_pBitmap = (uchar *)0x0;
  this->m_pName = (char *)0x0;
  return;
}


// FontPlat_Bitmap::GetCharABCwide  @ 00220e00
/* DWARF original prototype: void GetCharABCwide(FontPlat_Bitmap * this, int ch, int * a, int * b,
   int * c) */

void __thiscall FontPlat_Bitmap::GetCharABCwide(FontPlat_Bitmap *this,int ch,int *a,int *b,int *c)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (-1 < ch) {
    iVar1 = ch;
  }
  *c = 0;
  *a = 0;
  iVar2 = 0xff;
  if (iVar1 < 0x100) {
    iVar2 = iVar1;
  }
  *b = (this->m_FontData).m_CharWidths[iVar2] + 1;
  return;
}


// FontPlat_Bitmap::GetTall  @ 00220e40
/* DWARF original prototype: int GetTall(FontPlat_Bitmap * this) */

int __thiscall FontPlat_Bitmap::GetTall(FontPlat_Bitmap *this)

{
  return (this->m_FontData).m_BitmapCharHeight;
}


// FontPlat_Bitmap::equals  @ 00220ed0
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


// FontPlat_Bitmap::getCharRGBA  @ 00220cc0
/* DWARF original prototype: void getCharRGBA(FontPlat_Bitmap * this, int ch, int rgbaX, int rgbaY,
   int rgbaWide, int rgbaTall, uchar * rgba) */

void __thiscall
FontPlat_Bitmap::getCharRGBA
          (FontPlat_Bitmap *this,int ch,int rgbaX,int rgbaY,int rgbaWide,int rgbaTall,uchar *rgba)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  int iVar6;
  int local_20;
  uchar *local_1c;
  int local_18;
  
                    /* Unresolved local var: uchar * pSrcPos@[???]
                       Unresolved local var: uchar * pOutPos@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int outX@[???]
                       Unresolved local var: int outY@[???] */
  local_18 = 0x100;
  if ((ch < 0x100) && (local_18 = ch, ch < 0)) {
    local_18 = 0;
  }
  iVar2 = (this->m_FontData).m_BitmapCharHeight;
  if (0 < iVar2) {
    iVar6 = (this->m_FontData).m_BitmapCharWidth;
    local_1c = rgba + (rgbaY * rgbaWide + rgbaX) * 4 + 3;
    local_20 = 0;
    do {
      puVar1 = (this->m_FontData).m_pBitmap;
      if (0 < iVar6) {
        iVar4 = iVar6 * 0x100;
        iVar2 = local_18 * iVar6;
        iVar3 = 0;
        puVar5 = local_1c;
        do {
          while ((rgbaWide <= iVar3 + rgbaX || (rgbaTall <= local_20 + rgbaY))) {
LAB_00220d9d:
            iVar3 = iVar3 + 1;
            puVar5 = puVar5 + 4;
            if (iVar6 <= iVar3) goto LAB_00220dd9;
          }
          if (puVar1[iVar3 + iVar2 + iVar4 * local_20] != '\0') {
            *puVar5 = 0xff;
            puVar5[-1] = 0xff;
            puVar5[-2] = 0xff;
            puVar5[-3] = 0xff;
            iVar6 = (this->m_FontData).m_BitmapCharWidth;
            goto LAB_00220d9d;
          }
          *puVar5 = '\0';
          iVar3 = iVar3 + 1;
          puVar5[-1] = '\0';
          puVar5[-2] = '\0';
          puVar5[-3] = '\0';
          puVar5 = puVar5 + 4;
          iVar6 = (this->m_FontData).m_BitmapCharWidth;
        } while (iVar3 < iVar6);
LAB_00220dd9:
        iVar2 = (this->m_FontData).m_BitmapCharHeight;
      }
      local_20 = local_20 + 1;
      local_1c = local_1c + rgbaWide * 4;
    } while (local_20 < iVar2);
  }
  return;
}


// FontPlat_Bitmap::getId  @ 00220e50
/* DWARF original prototype: int getId(FontPlat_Bitmap * this) */

int __thiscall FontPlat_Bitmap::getId(FontPlat_Bitmap *this)

{
  return this->_id;
}


// FontPlat_Bitmap::~FontPlat_Bitmap  @ 00221050
/* DWARF original prototype: void ~FontPlat_Bitmap(FontPlat_Bitmap * this, int __in_chrg) */

void __thiscall FontPlat_Bitmap::~FontPlat_Bitmap(FontPlat_Bitmap *this,int __in_chrg)

{
  char *pcVar1;
  uchar *puVar2;
  
  pcVar1 = this->m_pName;
  (this->super_BaseFontPlat)._vptr_BaseFontPlat =
       (_func_int_varargs **)&PTR__FontPlat_Bitmap_00296da8;
  if (pcVar1 != (char *)0x0) {
    operator_delete__(pcVar1);
  }
  puVar2 = (this->m_FontData).m_pBitmap;
  if (puVar2 != (uchar *)0x0) {
    operator_delete__(puVar2);
  }
  (this->super_BaseFontPlat)._vptr_BaseFontPlat = (_func_int_varargs **)&PTR__BaseFontPlat_00296e28;
  return;
}


// FontPlat_Bitmap::~FontPlat_Bitmap  @ 00221120
/* DWARF original prototype: void ~FontPlat_Bitmap(FontPlat_Bitmap * this, int __in_chrg) */

void __thiscall FontPlat_Bitmap::~FontPlat_Bitmap(FontPlat_Bitmap *this,int __in_chrg)

{
  char *pcVar1;
  uchar *puVar2;
  
  pcVar1 = this->m_pName;
  (this->super_BaseFontPlat)._vptr_BaseFontPlat =
       (_func_int_varargs **)&PTR__FontPlat_Bitmap_00296da8;
  if (pcVar1 != (char *)0x0) {
    operator_delete__(pcVar1);
  }
  puVar2 = (this->m_FontData).m_pBitmap;
  if (puVar2 != (uchar *)0x0) {
    operator_delete__(puVar2);
  }
  (this->super_BaseFontPlat)._vptr_BaseFontPlat = (_func_int_varargs **)&PTR__BaseFontPlat_00296e28;
  operator_delete(this);
  return;
}


