// SZ_Alloc  @ 0003d5e0
void SZ_Alloc(char *name,sizebuf_t *buf,int startsize)

{
  byte *pbVar1;
  
  if (startsize < 0x100) {
    startsize = 0x100;
  }
  buf->buffername = name;
  pbVar1 = Hunk_AllocName(startsize,name);
  buf->maxsize = startsize;
  buf->cursize = 0;
  buf->flags = 0;
  buf->data = pbVar1;
  return;
}


// SZ_Clear  @ 0003d640
void SZ_Clear(sizebuf_t *buf)

{
  buf->cursize = 0;
  buf->flags = (ushort)*(undefined4 *)&buf->flags & 0xfffd;
  return;
}


// SZ_GetSpace  @ 0003d680
void * SZ_GetSpace(sizebuf_t *buf,int length)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: void * data@[???] */
  iVar3 = buf->cursize;
  iVar1 = buf->maxsize;
  iVar4 = iVar3 + length;
  if (iVar3 + length <= iVar1) goto LAB_0003d721;
  if ((buf->flags & 1) == 0) {
    pcVar2 = buf->buffername;
    if (pcVar2 == (char *)0x0) {
      pcVar2 = "???";
    }
    if (iVar1 == 0) {
      Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar2);
    }
    else {
      Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar2);
    }
    if (buf->maxsize < length) {
      if ((buf->flags & 1) != 0) goto LAB_0003d734;
      pcVar2 = buf->buffername;
      if (pcVar2 == (char *)0x0) {
        pcVar2 = "???";
      }
      Sys_Error("SZ_GetSpace: %i is > full buffer size on %s",length,pcVar2);
    }
  }
  else if (iVar1 < length) {
LAB_0003d734:
    pcVar2 = buf->buffername;
    if (pcVar2 == (char *)0x0) {
      pcVar2 = "???";
    }
    Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",length,pcVar2);
  }
  pcVar2 = buf->buffername;
  if (pcVar2 == (char *)0x0) {
    pcVar2 = "???";
  }
  Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar2);
  buf->flags = (ushort)*(undefined4 *)&buf->flags | 2;
  iVar3 = 0;
  iVar4 = length;
LAB_0003d721:
  buf->cursize = iVar4;
  return buf->data + iVar3;
}


// SZ_HasSpace  @ 0003d660
qboolean SZ_HasSpace(sizebuf_t *buf,int length)

{
  return (uint)(buf->cursize + length <= buf->maxsize);
}


// SZ_Print  @ 0003fbe0
void SZ_Print(sizebuf_t *buf,char *data)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  char *pcVar4;
  void *pvVar5;
  int iVar6;
  uint length;
  int iVar7;
  char *pcVar8;
  byte bVar9;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: byte * pData@[???] */
  bVar9 = 0;
                    /* Unresolved local var: int count@[???] */
  if ((data == (char *)0x0) || (*data == '\0')) {
    length = 1;
    iVar7 = 0;
  }
  else {
    iVar7 = 0;
    do {
      iVar6 = iVar7;
      iVar7 = iVar6 + 1;
    } while (data[iVar7] != '\0');
    length = iVar6 + 2;
  }
  if (buf->data[buf->cursize + -1] == '\0') {
    pvVar5 = SZ_GetSpace(buf,iVar7);
    pcVar4 = (char *)((int)pvVar5 + -1);
    bVar1 = (byte)buf->flags;
  }
  else {
    pcVar4 = SZ_GetSpace(buf,length);
    bVar1 = (byte)buf->flags;
  }
  if ((bVar1 & 2) == 0) {
    if (7 < length) {
      pcVar8 = pcVar4;
      if (((uint)pcVar4 & 1) != 0) {
        cVar2 = *data;
        pcVar8 = pcVar4 + 1;
        data = data + 1;
        length = length - 1;
        *pcVar4 = cVar2;
      }
      pcVar4 = pcVar8;
      if (((uint)pcVar8 & 2) != 0) {
        uVar3 = *(undefined2 *)data;
        pcVar4 = pcVar8 + 2;
        data = data + 2;
        length = length - 2;
        *(undefined2 *)pcVar8 = uVar3;
      }
      if (((uint)pcVar4 & 4) != 0) {
        *(undefined4 *)pcVar4 = *(undefined4 *)data;
        pcVar8 = data + 4;
        pcVar4 = pcVar4 + 4;
        for (iVar7 = length - 4; iVar7 != 0; iVar7 = iVar7 + -1) {
          *pcVar4 = *pcVar8;
          pcVar8 = pcVar8 + (uint)bVar9 * -2 + 1;
          pcVar4 = pcVar4 + (uint)bVar9 * -2 + 1;
        }
        return;
      }
    }
    for (; length != 0; length = length - 1) {
      *pcVar4 = *data;
      data = data + (uint)bVar9 * -2 + 1;
      pcVar4 = pcVar4 + (uint)bVar9 * -2 + 1;
    }
  }
  return;
}


// SZ_Write  @ 0003fa30
void SZ_Write(sizebuf_t *buf,void *data,int length)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  
                    /* Unresolved local var: byte * pData@[???] */
                    /* Unresolved local var: void * data@[???] */
  iVar3 = buf->cursize;
  iVar4 = buf->maxsize;
  iVar6 = length + iVar3;
  if (iVar6 <= iVar4) {
    buf->cursize = iVar6;
    if ((buf->flags & 2) != 0) {
      return;
    }
    pbVar7 = buf->data + iVar3;
    if (7 < (uint)length) {
      pbVar8 = pbVar7;
      if (((uint)pbVar7 & 1) != 0) {
        bVar1 = *(byte *)data;
        pbVar8 = pbVar7 + 1;
        data = (void *)((int)data + 1);
        length = length + -1;
        *pbVar7 = bVar1;
      }
      pbVar7 = pbVar8;
      if (((uint)pbVar8 & 2) != 0) {
        uVar2 = *(undefined2 *)data;
        pbVar7 = pbVar8 + 2;
        data = (void *)((int)data + 2);
        length = length + -2;
        *(undefined2 *)pbVar8 = uVar2;
      }
      if (((uint)pbVar7 & 4) != 0) {
        *(undefined4 *)pbVar7 = *(undefined4 *)data;
        pbVar8 = (byte *)((int)data + 4);
        pbVar7 = pbVar7 + 4;
        for (iVar6 = length + -4; iVar6 != 0; iVar6 = iVar6 + -1) {
          *pbVar7 = *pbVar8;
          pbVar8 = pbVar8 + 1;
          pbVar7 = pbVar7 + 1;
        }
        return;
      }
    }
    for (; length != 0; length = length + -1) {
      *pbVar7 = *(byte *)data;
      data = (byte *)((int)data + 1);
      pbVar7 = pbVar7 + 1;
    }
    return;
  }
  if ((buf->flags & 1) == 0) {
    pcVar5 = buf->buffername;
    if (iVar4 == 0) {
      if (pcVar5 == (char *)0x0) {
        pcVar5 = "???";
      }
      Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar5);
    }
    else {
      if (pcVar5 == (char *)0x0) {
        pcVar5 = "???";
      }
      Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar5);
    }
    if (length <= buf->maxsize) goto LAB_0003fab1;
    if ((buf->flags & 1) == 0) {
      pcVar5 = buf->buffername;
      if (pcVar5 == (char *)0x0) {
        pcVar5 = "???";
      }
      Sys_Error("SZ_GetSpace: %i is > full buffer size on %s",length,pcVar5);
      goto LAB_0003fab1;
    }
  }
  else if (length <= iVar4) goto LAB_0003fab1;
  pcVar5 = buf->buffername;
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "???";
  }
  Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",length,pcVar5);
LAB_0003fab1:
  pcVar5 = buf->buffername;
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "???";
  }
  Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar5);
  buf->cursize = length;
  buf->flags = (ushort)*(undefined4 *)&buf->flags | 2;
  return;
}


