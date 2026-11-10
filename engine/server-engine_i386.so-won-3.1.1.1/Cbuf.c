// Cbuf_AddText  @ 0005390c
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


// Cbuf_AddText__13EngineWrapperPc  @ 00097a8c
void Cbuf_AddText__13EngineWrapperPc(undefined4 param_1,undefined4 param_2)

{
  Cbuf_AddText(param_2);
  return;
}


// Cbuf_Execute  @ 00053bbc
void Cbuf_Execute(void)

{
  bool bVar1;
  int local_414;
  undefined1 local_40c [1024];
  int local_c;
  int local_8;
  
  do {
    if (cmd_text._16_4_ == 0) {
      return;
    }
    local_c = cmd_text._8_4_;
    bVar1 = false;
    for (local_8 = 0; local_8 < (int)cmd_text._16_4_; local_8 = local_8 + 1) {
      if (*(char *)(cmd_text._8_4_ + local_8) == '\"') {
        bVar1 = (bool)(bVar1 ^ 1);
      }
      if (((!bVar1) && (*(char *)(cmd_text._8_4_ + local_8) == ';')) ||
         (*(char *)(cmd_text._8_4_ + local_8) == '\n')) break;
    }
    if (local_8 < 0x400) {
      local_414 = local_8;
    }
    else {
      local_414 = 0x3ff;
    }
    Q_memcpy(local_40c,cmd_text._8_4_,local_414);
    local_40c[local_414] = 0;
    if (local_8 == cmd_text._16_4_) {
      cmd_text._16_4_ = 0;
    }
    else {
      local_8 = local_8 + 1;
      cmd_text._16_4_ = cmd_text._16_4_ - local_8;
      Q_memcpy(local_c,local_c + local_8,cmd_text._16_4_);
    }
    Cmd_ExecuteString(local_40c,1);
    if (cmd_wait != 0) {
      cmd_wait = 0;
      return;
    }
  } while( true );
}


// Cbuf_Init  @ 000538d0
void Cbuf_Init(void)

{
  SZ_Alloc("cmd_text",cmd_text,0x4000);
  return;
}


// Cbuf_InsertText  @ 00053998
void Cbuf_InsertText(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_8;
  
  uVar1 = cmd_text._16_4_;
  iVar2 = Q_strlen(param_1);
  if (uVar1 + iVar2 < (int)cmd_text._12_4_) {
    if (uVar1 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = Z_Malloc(uVar1);
      Q_memcpy(local_8,cmd_text._8_4_,uVar1);
      SZ_Clear(cmd_text);
    }
    Cbuf_AddText(param_1);
    if (uVar1 != 0) {
      SZ_Write(cmd_text,local_8,uVar1);
      Z_Free(local_8);
    }
  }
  else {
    Con_Printf("Cbuf_InsertText: overflow\n");
  }
  return;
}


// Cbuf_InsertTextLines  @ 00053a94
void Cbuf_InsertTextLines(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_8;
  
  uVar1 = cmd_text._16_4_;
  iVar2 = Q_strlen(param_1);
  if (uVar1 + iVar2 + 2 < (int)cmd_text._12_4_) {
    if (uVar1 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = Z_Malloc(uVar1);
      Q_memcpy(local_8,cmd_text._8_4_,uVar1);
      SZ_Clear(cmd_text);
    }
    Cbuf_AddText(&DAT_000df7e0);
    Cbuf_AddText(param_1);
    Cbuf_AddText(&DAT_000df7e0);
    if (uVar1 != 0) {
      SZ_Write(cmd_text,local_8,uVar1);
      Z_Free(local_8);
    }
  }
  else {
    Con_Printf("Cbuf_InsertTextLines: overflow\n");
  }
  return;
}


