// SZ_Alloc  @ 0010b110
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


// SZ_Clear  @ 0010b170
void SZ_Clear(sizebuf_t *buf)

{
  buf->cursize = 0;
  buf->flags = (ushort)*(undefined4 *)&buf->flags & 0xfffd;
  return;
}


// SZ_GetSpace  @ 0010b1b0
void * SZ_GetSpace(sizebuf_t *buf,int length)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
                    /* Unresolved local var: void * data@[???] */
  iVar2 = buf->cursize;
  iVar3 = buf->maxsize;
  iVar1 = iVar2 + length;
  if (iVar3 < iVar1) {
    if ((buf->flags & 1) == 0) {
      pcVar4 = buf->buffername;
      if (iVar3 == 0) {
        if (pcVar4 == (char *)0x0) {
          pcVar4 = "???";
        }
        Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar4);
        iVar3 = buf->maxsize;
      }
      else {
        if (pcVar4 == (char *)0x0) {
          pcVar4 = "???";
        }
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar4);
        iVar3 = buf->maxsize;
      }
    }
    if (iVar3 < length) {
      pcVar4 = buf->buffername;
      if ((buf->flags & 1) == 0) {
        if (pcVar4 == (char *)0x0) {
          pcVar4 = "???";
        }
        Sys_Error("SZ_GetSpace: %i is > full buffer size on %s",length,pcVar4);
      }
      else {
        if (pcVar4 == (char *)0x0) {
          pcVar4 = "???";
        }
        Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",length,pcVar4);
      }
    }
    pcVar4 = buf->buffername;
    if (pcVar4 == (char *)0x0) {
      pcVar4 = "???";
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar4);
    buf->cursize = length;
    buf->flags = (ushort)*(undefined4 *)&buf->flags | 2;
    return buf->data;
  }
  buf->cursize = iVar1;
  return buf->data + iVar2;
}


// SZ_HasSpace  @ 0010b190
qboolean SZ_HasSpace(sizebuf_t *buf,int length)

{
  return (uint)(length + buf->cursize <= buf->maxsize);
}


// SZ_Print  @ 0010c9a0
void SZ_Print(sizebuf_t *buf,char *data)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar7;
  void *pvVar8;
  uint uVar9;
  uint length;
  byte bVar10;
  int iVar6;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: byte * pData@[???] */
  bVar10 = 0;
                    /* Unresolved local var: int count@[???] */
  if ((data == (char *)0x0) || (*data == '\0')) {
    length = 1;
    iVar5 = 0;
  }
  else {
    iVar5 = 0;
    do {
      iVar6 = iVar5;
      iVar5 = iVar6 + 1;
    } while (data[iVar5] != '\0');
    length = iVar6 + 2;
  }
  if (buf->data[buf->cursize + -1] == '\0') {
    pvVar8 = SZ_GetSpace(buf,iVar5);
    pcVar7 = (char *)((int)pvVar8 + -1);
    bVar1 = (byte)buf->flags;
  }
  else {
    pcVar7 = SZ_GetSpace(buf,length);
    bVar1 = (byte)buf->flags;
  }
  if ((bVar1 & 2) == 0) {
    if (7 < length) {
      uVar9 = length;
      if (((uint)pcVar7 & 1) != 0) {
        cVar2 = *data;
        uVar9 = length - 1;
        data = data + 1;
        *pcVar7 = cVar2;
        pcVar7 = pcVar7 + 1;
      }
      if (((uint)pcVar7 & 2) != 0) {
        uVar3 = *(undefined2 *)data;
        uVar9 = uVar9 - 2;
        data = data + 2;
        *(undefined2 *)pcVar7 = uVar3;
        pcVar7 = pcVar7 + 2;
      }
      if (((uint)pcVar7 & 4) != 0) {
        uVar4 = *(undefined4 *)data;
        uVar9 = uVar9 - 4;
        data = data + 4;
        *(undefined4 *)pcVar7 = uVar4;
        pcVar7 = pcVar7 + 4;
      }
      length = uVar9 & 3;
      for (uVar9 = uVar9 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)data;
        data = data + (uint)bVar10 * -8 + 4;
        pcVar7 = pcVar7 + (uint)bVar10 * -8 + 4;
      }
    }
    iVar5 = 0;
    if ((length & 4) != 0) {
      iVar5 = 4;
      *(undefined4 *)pcVar7 = *(undefined4 *)data;
    }
    if ((length & 2) != 0) {
      *(undefined2 *)(pcVar7 + iVar5) = *(undefined2 *)(data + iVar5);
      iVar5 = iVar5 + 2;
    }
    if ((length & 1) != 0) {
      pcVar7[iVar5] = data[iVar5];
    }
  }
  return;
}


// SZ_Write  @ 0010c8a0
void SZ_Write(sizebuf_t *buf,void *data,int length)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  
                    /* Unresolved local var: byte * pData@[???] */
  bVar7 = 0;
  puVar4 = SZ_GetSpace(buf,length);
  if ((buf->flags & 2) == 0) {
    if (7 < (uint)length) {
      uVar6 = length;
      if (((uint)puVar4 & 1) != 0) {
        uVar1 = *(undefined1 *)data;
        uVar6 = length - 1;
        data = (void *)((int)data + 1);
        *(undefined1 *)puVar4 = uVar1;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      if (((uint)puVar4 & 2) != 0) {
        uVar2 = *(undefined2 *)data;
        uVar6 = uVar6 - 2;
        data = (void *)((int)data + 2);
        *(undefined2 *)puVar4 = uVar2;
        puVar4 = (undefined4 *)((int)puVar4 + 2);
      }
      if (((uint)puVar4 & 4) != 0) {
        uVar3 = *(undefined4 *)data;
        uVar6 = uVar6 - 4;
        data = (void *)((int)data + 4);
        *puVar4 = uVar3;
        puVar4 = puVar4 + 1;
      }
      length = uVar6 & 3;
      for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar4 = *(undefined4 *)data;
        data = (undefined4 *)((int)data + ((uint)bVar7 * -2 + 1) * 4);
        puVar4 = puVar4 + (uint)bVar7 * -2 + 1;
      }
    }
    iVar5 = 0;
    if ((length & 4U) != 0) {
      iVar5 = 4;
      *puVar4 = *(undefined4 *)data;
    }
    if ((length & 2U) != 0) {
      *(undefined2 *)((int)puVar4 + iVar5) = *(undefined2 *)((int)data + iVar5);
      iVar5 = iVar5 + 2;
    }
    if ((length & 1U) != 0) {
      *(undefined1 *)((int)puVar4 + iVar5) = *(undefined1 *)((int)data + iVar5);
      return;
    }
  }
  return;
}


