// vgui_LoadTGA  @ 000cd740
BitmapTGA * vgui_LoadTGA(char *pFilename)

{
  BitmapTGA *this;
  InputStream local_1c;
  byte *local_18;
  int local_14 [4];
  
                    /* Unresolved local var: MemoryInputStream stream@[???]
                       Unresolved local var: BitmapTGA * pRet@[???] */
  local_18 = (byte *)0x0;
  local_14[1] = 0;
  local_14[0] = 0;
  local_1c._vptr_InputStream = (_func_int_varargs **)&PTR_seekStart_000ee9c8;
  this = (BitmapTGA *)0x0;
  local_18 = (*gEngfuncs.COM_LoadFile)(pFilename,5,local_14);
  if (local_18 != (byte *)0x0) {
    local_14[1] = 0;
    this = operator_new(0x30);
    vgui::BitmapTGA::BitmapTGA(this,&local_1c,true);
    (*gEngfuncs.COM_FreeFile)(local_18);
  }
  return this;
}


// vgui_LoadTGANoInvertAlpha  @ 000cd7d0
BitmapTGA * vgui_LoadTGANoInvertAlpha(char *pFilename)

{
  BitmapTGA *this;
  InputStream local_1c;
  byte *local_18;
  int local_14 [4];
  
                    /* Unresolved local var: MemoryInputStream stream@[???]
                       Unresolved local var: BitmapTGA * pRet@[???] */
  local_14[0] = 0;
  local_14[1] = 0;
  this = (BitmapTGA *)0x0;
  local_1c._vptr_InputStream = (_func_int_varargs **)&PTR_seekStart_000ee9c8;
  local_18 = (byte *)0x0;
  local_18 = (*gEngfuncs.COM_LoadFile)(pFilename,5,local_14);
  if (local_18 != (byte *)0x0) {
    local_14[1] = 0;
    this = operator_new(0x30);
    vgui::BitmapTGA::BitmapTGA(this,&local_1c,false);
    (*gEngfuncs.COM_FreeFile)(local_18);
  }
  return this;
}


