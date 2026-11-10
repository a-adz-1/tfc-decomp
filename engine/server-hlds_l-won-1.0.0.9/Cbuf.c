// Cbuf_AddText  @ 0804c810
void Cbuf_AddText(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Q_strlen(param_1);
  if (iVar1 + cmd_text._16_4_ < (int)cmd_text._12_4_) {
    uVar2 = Q_strlen(param_1);
    SZ_Write(cmd_text,param_1,uVar2);
  }
  else {
    Con_Printf("Cbuf_AddText: overflow\n");
  }
  return;
}


// Cbuf_Execute  @ 0804c960
void Cbuf_Execute(void)

{
  undefined4 uVar1;
  bool bVar2;
  size_t __n;
  undefined1 local_404 [1024];
  
  if (cmd_text._16_4_ != 0) {
    do {
      uVar1 = cmd_text._8_4_;
      bVar2 = false;
      __n = 0;
      if (0 < (int)cmd_text._16_4_) {
        do {
          if (*(char *)(__n + cmd_text._8_4_) == '\"') {
            bVar2 = (bool)(bVar2 ^ 1);
          }
        } while ((((bVar2) || (*(char *)(__n + cmd_text._8_4_) != ';')) &&
                 (*(char *)(__n + cmd_text._8_4_) != '\n')) &&
                (__n = __n + 1, (int)__n < (int)cmd_text._16_4_));
      }
      memcpy(local_404,(void *)cmd_text._8_4_,__n);
      local_404[__n] = 0;
      if (__n == cmd_text._16_4_) {
        cmd_text._16_4_ = 0;
      }
      else {
        cmd_text._16_4_ = cmd_text._16_4_ - (__n + 1);
        Q_memcpy(uVar1,__n + 1 + uVar1,cmd_text._16_4_);
      }
      Cmd_ExecuteString(local_404,1);
      if (cmd_wait != 0) {
        cmd_wait = 0;
        return;
      }
    } while (cmd_text._16_4_ != 0);
  }
  return;
}


// Cbuf_Init  @ 0804c7f0
void Cbuf_Init(void)

{
  SZ_Alloc(cmd_text,0x2000);
  return;
}


// Cbuf_InsertText  @ 0804c860
void Cbuf_InsertText(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = cmd_text._16_4_;
  if (cmd_text._16_4_ == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = Z_Malloc(cmd_text._16_4_);
    Q_memcpy(uVar2,cmd_text._8_4_,uVar1);
    SZ_Clear(cmd_text);
  }
  Cbuf_AddText(param_1);
  if (uVar1 != 0) {
    SZ_Write(cmd_text,uVar2,uVar1);
    Z_Free(uVar2);
  }
  return;
}


// Cbuf_InsertTextLines  @ 0804c8d0
void Cbuf_InsertTextLines(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = cmd_text._16_4_;
  if (cmd_text._16_4_ == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = Z_Malloc(cmd_text._16_4_);
    Q_memcpy(uVar2,cmd_text._8_4_,uVar1);
    SZ_Clear(cmd_text);
  }
  Cbuf_AddText(&DAT_0809e718);
  Cbuf_AddText(param_1);
  Cbuf_AddText(&DAT_0809e718);
  if (uVar1 != 0) {
    SZ_Write(cmd_text,uVar2,uVar1);
    Z_Free(uVar2);
  }
  return;
}


