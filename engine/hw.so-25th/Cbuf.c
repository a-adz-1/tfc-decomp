// Cbuf_AddFilteredText  @ 0009add0
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


// Cbuf_AddText  @ 0009ad70
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


// Cbuf_Execute  @ 0009c380
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cbuf_Execute(void)

{
  Cbuf_ExecuteCommandsFromBuffer(&cmd_text,true,-1);
  Cbuf_ExecuteCommandsFromBuffer(&filteredcmd_text,false,1);
  return;
}


// Cbuf_ExecuteCommandsFromBuffer  @ 0009c210
void Cbuf_ExecuteCommandsFromBuffer(sizebuf_t *buf,qboolean bIsPrivileged,int nCmdsToExecute)

{
  byte bVar1;
  byte *src;
  int iVar2;
  byte bVar3;
  size_t __n;
  qboolean bIsPrivileged_00;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  int local_430;
  char local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * text@[???]
                       Unresolved local var: char[1024] line@[???]
                       Unresolved local var: int quotes@[???]
                       Unresolved local var: int amount@[???]
                       Unresolved local var: int nCmds@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (buf != (sizebuf_t *)0x0) {
    local_430 = 0;
    do {
      iVar5 = buf->cursize;
      if (iVar5 == 0) goto LAB_0009c335;
      src = buf->data;
      if (iVar5 < 1) {
        iVar5 = 0;
        iVar4 = 0;
      }
      else {
        bVar3 = 0;
        iVar4 = 0;
        do {
          while (bVar1 = src[iVar4], bVar1 != '\"') {
            if (((((bool)(bVar3 ^ 1)) && (bVar1 == ';')) || (bVar1 == '\n')) ||
               (iVar4 = iVar4 + 1, iVar5 == iVar4)) goto LAB_0009c290;
          }
          iVar4 = iVar4 + 1;
          bVar3 = bVar3 ^ 1;
        } while (iVar5 != iVar4);
LAB_0009c290:
        iVar5 = 0x3ff;
        if (iVar4 < 0x400) {
          iVar5 = iVar4;
        }
      }
      Q_memcpy(local_420,src,iVar5);
      iVar2 = buf->cursize;
      local_420[iVar5] = '\0';
      if (iVar2 == iVar4) {
        buf->cursize = 0;
      }
      else {
        __n = iVar2 - (iVar4 + 1);
        buf->cursize = __n;
        memmove(src,src + iVar4 + 1,__n);
      }
                    /* Unresolved local var: cmd_function_t * cmd@[???]
                       Unresolved local var: cmdalias_t * a@[???] */
      cmd_source = src_command;
      Cmd_TokenizeString(local_420);
      (*g_engdstAddrs.Cmd_Argc)();
      if (cmd_argc != 0) {
        Cmd_ExecuteStringWithPrivilegeCheck(local_420,bIsPrivileged,bIsPrivileged_00);
      }
      local_430 = local_430 + 1;
    } while ((cmd_wait == false) && ((nCmdsToExecute < 1 || (local_430 < nCmdsToExecute))));
    cmd_wait = false;
  }
LAB_0009c335:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Cbuf_Init  @ 0009ad20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cbuf_Init(void)

{
  SZ_Alloc("cmd_text",&cmd_text,0x4000);
  SZ_Alloc("filteredcmd_text",&filteredcmd_text,0x4000);
  return;
}


// Cbuf_InsertText  @ 0009ae30
void Cbuf_InsertText(char *text)

{
  int size;
  int iVar1;
  void *dest;
  
  size = cmd_text.cursize;
                    /* Unresolved local var: char * temp@[???]
                       Unresolved local var: int currLen@[???]
                       Unresolved local var: int addLen@[???] */
  iVar1 = Q_strlen(text);
  if (cmd_text.maxsize <= iVar1 + size) {
    Con_Printf("Cbuf_InsertText: overflow\n");
    return;
  }
  dest = (void *)0x0;
  if (size != 0) {
    dest = Z_Malloc(size);
    Q_memcpy(dest,cmd_text.data,size);
    SZ_Clear(&cmd_text);
  }
                    /* Unresolved local var: int l@[???] */
  iVar1 = Q_strlen(text);
  if (iVar1 + cmd_text.cursize < cmd_text.maxsize) {
                    /* Unresolved local var: int l@[???] */
    iVar1 = Q_strlen(text);
    SZ_Write(&cmd_text,text,iVar1);
  }
  else {
    Con_Printf("Cbuf_AddTextToBuffer: overflow\n");
  }
  if (size == 0) {
    return;
  }
  SZ_Write(&cmd_text,dest,size);
  Z_Free(dest);
  return;
}


// Cbuf_InsertTextLines  @ 0009af50
void Cbuf_InsertTextLines(char *text)

{
  int size;
  int iVar1;
  void *dest;
  
  size = cmd_text.cursize;
                    /* Unresolved local var: char * temp@[???]
                       Unresolved local var: int currLen@[???]
                       Unresolved local var: int addLen@[???] */
  iVar1 = Q_strlen(text);
  if (cmd_text.maxsize <= size + 2 + iVar1) {
    Con_Printf("Cbuf_InsertText: overflow\n");
    return;
  }
  dest = (void *)0x0;
  if (size != 0) {
    dest = Z_Malloc(size);
    Q_memcpy(dest,cmd_text.data,size);
    SZ_Clear(&cmd_text);
  }
                    /* Unresolved local var: int l@[???] */
  iVar1 = Q_strlen("\n");
  if (iVar1 + cmd_text.cursize < cmd_text.maxsize) {
                    /* Unresolved local var: int l@[???] */
    iVar1 = Q_strlen("\n");
    SZ_Write(&cmd_text,"\n",iVar1);
  }
  else {
    Con_Printf("Cbuf_AddTextToBuffer: overflow\n");
  }
                    /* Unresolved local var: int l@[???] */
  iVar1 = Q_strlen(text);
  if (iVar1 + cmd_text.cursize < cmd_text.maxsize) {
                    /* Unresolved local var: int l@[???] */
    iVar1 = Q_strlen(text);
    SZ_Write(&cmd_text,text,iVar1);
  }
  else {
    Con_Printf("Cbuf_AddTextToBuffer: overflow\n");
  }
                    /* Unresolved local var: int l@[???] */
  iVar1 = Q_strlen("\n");
  if (iVar1 + cmd_text.cursize < cmd_text.maxsize) {
                    /* Unresolved local var: int l@[???] */
    iVar1 = Q_strlen("\n");
    SZ_Write(&cmd_text,"\n",iVar1);
  }
  else {
    Con_Printf("Cbuf_AddTextToBuffer: overflow\n");
  }
  if (size == 0) {
    return;
  }
  SZ_Write(&cmd_text,dest,size);
  Z_Free(dest);
  return;
}


// Cbuf_InsertTextToBuffer  @ 0009a550
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


// Cbuf_ReplaceSemiColons  @ 001b5850
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Cbuf_ReplaceSemiColons(void)

{
  char *pcVar1;
  
                    /* Unresolved local var: char * temp@[???] */
  pcVar1 = chat_buffer;
  do {
    while( true ) {
      if (*pcVar1 == '\0') {
        return;
      }
      if (*pcVar1 == ';') break;
      pcVar1 = pcVar1 + 1;
      if (pcVar1 == (char *)0x0) {
        return;
      }
    }
    *pcVar1 = ',';
    pcVar1 = pcVar1 + 1;
  } while (pcVar1 != (char *)0x0);
  return;
}


