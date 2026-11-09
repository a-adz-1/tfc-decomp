// Cbuf_AddFilteredText  @ 00105e80
void Cbuf_AddFilteredText(char *text)

{
  int iVar1;
  
                    /* Unresolved local var: int l@[???] */
  iVar1 = Q_strlen(text);
  if (iVar1 + filteredcmd_text.cursize < filteredcmd_text.maxsize) {
                    /* Unresolved local var: int l@[???] */
    iVar1 = Q_strlen(text);
    SZ_Write(&filteredcmd_text,text,iVar1);
    return;
  }
  Con_Printf("Cbuf_AddTextToBuffer: overflow\n");
  return;
}


// Cbuf_AddText  @ 00105e20
void Cbuf_AddText(char *text)

{
  int iVar1;
  
                    /* Unresolved local var: int l@[???] */
  iVar1 = Q_strlen(text);
  if (iVar1 + cmd_text.cursize < cmd_text.maxsize) {
                    /* Unresolved local var: int l@[???] */
    iVar1 = Q_strlen(text);
    SZ_Write(&cmd_text,text,iVar1);
    return;
  }
  Con_Printf("Cbuf_AddTextToBuffer: overflow\n");
  return;
}


// Cbuf_Execute  @ 00107b50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cbuf_Execute(void)

{
  Cbuf_ExecuteCommandsFromBuffer(&cmd_text,true,-1);
  Cbuf_ExecuteCommandsFromBuffer(&filteredcmd_text,false,1);
  return;
}


// Cbuf_ExecuteCommandsFromBuffer  @ 00107a10
void Cbuf_ExecuteCommandsFromBuffer(sizebuf_t *buf,qboolean bIsPrivileged,int nCmdsToExecute)

{
  byte bVar1;
  byte *src;
  bool bVar2;
  int iVar3;
  qboolean bIsPrivileged_00;
  int iVar4;
  int iVar5;
  int local_420;
  char local_41c [1036];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * text@[???]
                       Unresolved local var: char[1024] line@[???]
                       Unresolved local var: int quotes@[???]
                       Unresolved local var: int amount@[???]
                       Unresolved local var: int nCmds@[???] */
  if (buf != (sizebuf_t *)0x0) {
    local_420 = 0;
    do {
      iVar4 = buf->cursize;
      if (iVar4 == 0) {
        return;
      }
      src = buf->data;
      if (iVar4 < 1) {
        iVar4 = 0;
        iVar5 = 0;
      }
      else {
        bVar2 = false;
        iVar5 = 0;
        do {
          bVar1 = src[iVar5];
          bVar2 = (bool)(bVar2 ^ bVar1 == '\"');
          if (((!bVar2) && (bVar1 == ';')) || (bVar1 == '\n')) break;
          iVar5 = iVar5 + 1;
        } while (iVar5 != iVar4);
        iVar4 = 0x3ff;
        if (iVar5 < 0x400) {
          iVar4 = iVar5;
        }
      }
      Q_memcpy(local_41c,src,iVar4);
      iVar3 = buf->cursize;
      local_41c[iVar4] = '\0';
      if (iVar3 == iVar5) {
        buf->cursize = 0;
      }
      else {
        iVar3 = iVar3 - (iVar5 + 1);
        buf->cursize = iVar3;
        Q_memcpy(src,src + iVar5 + 1,iVar3);
      }
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmdalias_t * a@[???] */
      cmd_source = src_command;
      Cmd_TokenizeString(local_41c);
      (*g_engdstAddrs.Cmd_Argc)();
      if (cmd_argc != 0) {
        Cmd_ExecuteStringWithPrivilegeCheck(local_41c,bIsPrivileged,bIsPrivileged_00);
      }
    } while ((cmd_wait == false) &&
            ((local_420 = local_420 + 1, local_420 < nCmdsToExecute || (nCmdsToExecute < 1))));
    cmd_wait = false;
  }
  return;
}


// Cbuf_Init  @ 00105dd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cbuf_Init(void)

{
  SZ_Alloc("cmd_text",&cmd_text,0x4000);
  SZ_Alloc("filteredcmd_text",&filteredcmd_text,0x4000);
  return;
}


// Cbuf_InsertText  @ 00105ee0
void Cbuf_InsertText(char *text)

{
  Cbuf_InsertTextToBuffer(text,&cmd_text,false);
  return;
}


// Cbuf_InsertTextLines  @ 00105ef0
void Cbuf_InsertTextLines(char *text)

{
  Cbuf_InsertTextToBuffer(text,&cmd_text,true);
  return;
}


// Cbuf_InsertTextToBuffer  @ 00105620
void __regparm3 Cbuf_InsertTextToBuffer(char *text,sizebuf_t *buf,qboolean bAddNewlines)

{
  int size;
  int iVar1;
  void *local_20;
  
                    /* Unresolved local var: char * temp@[???]
                       Unresolved local var: int currLen@[???]
                       Unresolved local var: int addLen@[???] */
  size = buf->cursize;
  iVar1 = Q_strlen(text);
  if (bAddNewlines != false) {
    iVar1 = iVar1 + 2;
  }
  if (iVar1 + size < buf->maxsize) {
    local_20 = (void *)0x0;
    if (size != 0) {
      local_20 = Z_Malloc(size);
      Q_memcpy(local_20,buf->data,size);
      SZ_Clear(buf);
    }
    if (bAddNewlines != false) {
                    /* Unresolved local var: int l@[???] */
      iVar1 = Q_strlen("\n");
      if (iVar1 + buf->cursize < buf->maxsize) {
                    /* Unresolved local var: int l@[???] */
        iVar1 = Q_strlen("\n");
        SZ_Write(buf,"\n",iVar1);
      }
      else {
        Con_Printf("Cbuf_AddTextToBuffer: overflow\n");
      }
    }
                    /* Unresolved local var: int l@[???] */
    iVar1 = Q_strlen(text);
    if (iVar1 + buf->cursize < buf->maxsize) {
                    /* Unresolved local var: int l@[???] */
      iVar1 = Q_strlen(text);
      SZ_Write(buf,text,iVar1);
    }
    else {
      Con_Printf("Cbuf_AddTextToBuffer: overflow\n");
    }
    if (bAddNewlines != false) {
                    /* Unresolved local var: int l@[???] */
      iVar1 = Q_strlen("\n");
      if (iVar1 + buf->cursize < buf->maxsize) {
                    /* Unresolved local var: int l@[???] */
        iVar1 = Q_strlen("\n");
        SZ_Write(buf,"\n",iVar1);
      }
      else {
        Con_Printf("Cbuf_AddTextToBuffer: overflow\n");
      }
    }
    if (size != 0) {
      SZ_Write(buf,local_20,size);
      Z_Free(local_20);
    }
  }
  else {
    Con_Printf("Cbuf_InsertText: overflow\n");
  }
  return;
}


// Cbuf_ReplaceSemiColons  @ 002057a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cbuf_ReplaceSemiColons(void)

{
  char cVar1;
  char *pcVar2;
  
                    /* Unresolved local var: char * temp@[???] */
  if (chat_buffer[0] != '\0') {
    pcVar2 = chat_buffer;
    cVar1 = chat_buffer[0];
    do {
      if (cVar1 == ';') {
        *pcVar2 = ',';
      }
      if (pcVar2 == (char *)0xffffffff) {
        return;
      }
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar2;
    } while (cVar1 != '\0');
  }
  return;
}


