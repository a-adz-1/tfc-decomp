// Cbuf_AddText  @ 0004747c
void Cbuf_AddText(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Q_strlen(param_1);
  if (iVar1 + cmd_text._12_4_ < (int)cmd_text._8_4_) {
    uVar2 = Q_strlen(param_1);
    SZ_Write(cmd_text,param_1,uVar2);
  }
  else {
    Con_Printf("Cbuf_AddText: overflow\n");
  }
  return;
}


// Cbuf_Execute  @ 000475f4
void Cbuf_Execute(void)

{
  char cVar1;
  undefined4 uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  undefined1 local_404 [1024];
  
  if (cmd_text._12_4_ != 0) {
    do {
      uVar2 = cmd_text._4_4_;
      bVar7 = false;
      bVar3 = false;
      iVar5 = 0;
      if (0 < (int)cmd_text._12_4_) {
        uVar4 = cmd_text._12_4_ & 3;
        iVar6 = iVar5;
        if (uVar4 == 0) goto LAB_000476c8;
        if (1 < uVar4) {
          if (2 < uVar4) {
            cVar1 = *(char *)cmd_text._4_4_;
            bVar7 = cVar1 == '\"';
            if (((!bVar7) && (cVar1 == ';')) || (cVar1 == '\n')) goto LAB_00047750;
            iVar5 = 1;
          }
          cVar1 = *(char *)(iVar5 + cmd_text._4_4_);
          if (cVar1 == '\"') {
            bVar7 = (bool)(bVar7 ^ 1);
          }
          if (((bVar7 == false) && (cVar1 == ';')) || (cVar1 == '\n')) goto LAB_00047750;
          iVar5 = iVar5 + 1;
          bVar3 = bVar7;
        }
        cVar1 = *(char *)(iVar5 + cmd_text._4_4_);
        if (cVar1 == '\"') {
          bVar3 = bVar3 + 1;
        }
        if (((bVar3 != 0) || (cVar1 != ';')) && (cVar1 != '\n')) {
          while (iVar6 = iVar5 + 1, iVar5 = iVar6, iVar6 < (int)cmd_text._12_4_) {
LAB_000476c8:
            cVar1 = *(char *)(iVar6 + cmd_text._4_4_);
            if (cVar1 == '\"') {
              bVar3 = bVar3 + 1;
            }
            iVar5 = iVar6;
            if (((bVar3 == 0) && (cVar1 == ';')) || (cVar1 == '\n')) break;
            iVar5 = iVar6 + 1;
            cVar1 = *(char *)(iVar5 + cmd_text._4_4_);
            if (cVar1 == '\"') {
              bVar3 = bVar3 + 1;
            }
            if (((bVar3 == 0) && (cVar1 == ';')) || (cVar1 == '\n')) break;
            iVar5 = iVar6 + 2;
            cVar1 = *(char *)(iVar5 + cmd_text._4_4_);
            if (cVar1 == '\"') {
              bVar3 = bVar3 + 1;
            }
            if (((bVar3 == 0) && (cVar1 == ';')) || (cVar1 == '\n')) break;
            iVar5 = iVar6 + 3;
            cVar1 = *(char *)(iVar5 + cmd_text._4_4_);
            if (cVar1 == '\"') {
              bVar3 = bVar3 + 1;
            }
            if (((bVar3 == 0) && (cVar1 == ';')) || (cVar1 == '\n')) break;
          }
        }
      }
LAB_00047750:
      Q_memcpy(local_404,cmd_text._4_4_,iVar5);
      local_404[iVar5] = 0;
      if (iVar5 == cmd_text._12_4_) {
        cmd_text._12_4_ = 0;
      }
      else {
        cmd_text._12_4_ = cmd_text._12_4_ - (iVar5 + 1);
        Q_memcpy(uVar2,uVar2 + iVar5 + 1,cmd_text._12_4_);
      }
      Cmd_ExecuteString(local_404,1);
      if (cmd_wait != 0) {
        cmd_wait = 0;
        return;
      }
    } while (cmd_text._12_4_ != 0);
  }
  return;
}


// Cbuf_Init  @ 00047454
void Cbuf_Init(void)

{
  SZ_Alloc(cmd_text,0x2000);
  return;
}


// Cbuf_InsertText  @ 000474d8
void Cbuf_InsertText(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = cmd_text._12_4_;
  if (cmd_text._12_4_ == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = Z_Malloc(cmd_text._12_4_);
    Q_memcpy(uVar2,cmd_text._4_4_,uVar1);
    SZ_Clear(cmd_text);
  }
  Cbuf_AddText(param_1);
  if (uVar1 != 0) {
    SZ_Write(cmd_text,uVar2,uVar1);
    Z_Free(uVar2);
  }
  return;
}


// Cbuf_InsertTextLines  @ 00047554
void Cbuf_InsertTextLines(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_8;
  
  uVar1 = cmd_text._12_4_;
  if (cmd_text._12_4_ == 0) {
    local_8 = 0;
  }
  else {
    local_8 = Z_Malloc(cmd_text._12_4_);
    Q_memcpy(local_8,cmd_text._4_4_,uVar1);
    SZ_Clear(cmd_text);
  }
  Cbuf_AddText(&DAT_000a4018);
  Cbuf_AddText(param_1);
  Cbuf_AddText(&DAT_000a4018);
  if (uVar1 != 0) {
    SZ_Write(cmd_text,local_8,uVar1);
    Z_Free(local_8);
  }
  return;
}


