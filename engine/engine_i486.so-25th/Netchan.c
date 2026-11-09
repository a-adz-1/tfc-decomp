// Netchan_AddBufferToList  @ 00068180
void Netchan_AddBufferToList(fragbuf_t **pplist,fragbuf_t *pbuf)

{
  fragbuf_s *pfVar1;
  fragbuf_t *pfVar2;
  
                    /* Unresolved local var: fragbuf_t * pprev@[???]
                       Unresolved local var: fragbuf_t * n@[???]
                       Unresolved local var: int id1@[???]
                       Unresolved local var: int id2@[???] */
  pbuf->next = (fragbuf_s *)0x0;
  if (pplist != (fragbuf_t **)0x0) {
    pfVar1 = *pplist;
    if (*pplist == (fragbuf_t *)0x0) {
      *pplist = pbuf;
      return;
    }
    while (pfVar2 = pfVar1, pfVar1 = pfVar2->next, pfVar1 != (fragbuf_s *)0x0) {
      if (*(ushort *)((int)&pbuf->bufferid + 2) < *(ushort *)((int)&pfVar1->bufferid + 2)) {
        pbuf->next = pfVar1->next;
        pfVar2->next = pbuf;
        return;
      }
    }
    pfVar2->next = pbuf;
  }
  return;
}


// Netchan_AddFragbufToTail  @ 00068210
void Netchan_AddFragbufToTail(fragbufwaiting_t *wait,fragbuf_t *buf)

{
  fragbuf_s *pfVar1;
  fragbuf_t *pfVar2;
  
                    /* Unresolved local var: fragbuf_t * p@[???] */
  buf->next = (fragbuf_s *)0x0;
  wait->fragbufcount = wait->fragbufcount + 1;
  pfVar1 = wait->fragbufs;
  if (wait->fragbufs != (fragbuf_t *)0x0) {
    do {
      pfVar2 = pfVar1;
      pfVar1 = pfVar2->next;
    } while (pfVar1 != (fragbuf_s *)0x0);
    pfVar2->next = buf;
    return;
  }
  wait->fragbufs = buf;
  return;
}


// Netchan_AllocFragbuf  @ 000681d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

fragbuf_t * Netchan_AllocFragbuf(void)

{
  fragbuf_t *pfVar1;
  
                    /* Unresolved local var: fragbuf_t * buf@[DW_OP_reg0(EAX)] */
  pfVar1 = Mem_ZeroMalloc(0x6ac);
  pfVar1->bufferid = 0;
  (pfVar1->frag_message).cursize = 0;
  (pfVar1->frag_message).data = pfVar1->frag_message_buf;
  (pfVar1->frag_message).maxsize = 0x578;
  (pfVar1->frag_message).buffername = "Frag Buffer Alloc\'d";
  pfVar1->next = (fragbuf_s *)0x0;
  return pfVar1;
}


// Netchan_CanPacket  @ 00066c70
qboolean Netchan_CanPacket(netchan_t *chan)

{
  if ((net_chokeloopback.value == 0.0) && ((chan->remote_address).type == NA_LOOPBACK)) {
    chan->cleartime = realtime;
    return true;
  }
  return (uint)(chan->cleartime < realtime);
}


// Netchan_CheckForCompletion  @ 000670b0
void Netchan_CheckForCompletion(netchan_t *chan,int stream,int intotalbuffers)

{
  char cVar1;
  netadr_t a;
  char *src;
  int iVar2;
  fragbuf_t *pfVar3;
  uint uVar4;
  int in_GS_OFFSET;
  char local_b0 [32];
  char local_90 [128];
  int local_10;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int id@[???]
                       Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: char[32] szCommand@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  pfVar3 = chan->incomingbufs[stream];
  if (pfVar3 != (fragbuf_t *)0x0) {
    uVar4 = 0;
    do {
      while ((uVar4 = uVar4 + 1, *(ushort *)((int)&pfVar3->bufferid + 2) == uVar4 ||
             (chan != &cls.netchan))) {
        pfVar3 = pfVar3->next;
        if (pfVar3 == (fragbuf_s *)0x0) goto LAB_00067140;
      }
      if (cls.netchan.sock == NS_MULTICAST) {
                    /* Unresolved local var: char[128] buf@[???] */
        a.ip[0] = cls.netchan.remote_address.ip[0];
        a.ip[1] = cls.netchan.remote_address.ip[1];
        a.ip[2] = cls.netchan.remote_address.ip[2];
        a.ip[3] = cls.netchan.remote_address.ip[3];
        a.type = cls.netchan.remote_address.type;
        a.ipx[0] = cls.netchan.remote_address.ipx[0];
        a.ipx[1] = cls.netchan.remote_address.ipx[1];
        a.ipx[2] = cls.netchan.remote_address.ipx[2];
        a.ipx[3] = cls.netchan.remote_address.ipx[3];
        a.ipx[4] = cls.netchan.remote_address.ipx[4];
        a.ipx[5] = cls.netchan.remote_address.ipx[5];
        a.ipx[6] = cls.netchan.remote_address.ipx[6];
        a.ipx[7] = cls.netchan.remote_address.ipx[7];
        a.ipx[8] = cls.netchan.remote_address.ipx[8];
        a.ipx[9] = cls.netchan.remote_address.ipx[9];
        a.port = cls.netchan.remote_address.port;
        src = NET_AdrToString(a);
        Q_strncpy_s(local_90,src,0x80);
                    /* Unresolved local var: char __r0@[???]
                       Unresolved local var: char __r1@[???]
                       Unresolved local var: char __r2@[???]
                       Unresolved local var: size_t __result@[???] */
        iVar2 = 0;
        if (((local_90[0] == '\0') || (local_90[0] == '\n')) || (local_90[0] == ';'))
        goto LAB_000671fb;
        goto LAB_000671f2;
      }
      Con_Printf(
                "Netchan_CheckForCompletion:  Lost/dropped fragment would cause stall, retrying connection\n"
                );
      Cbuf_AddText("retry\n");
      pfVar3 = pfVar3->next;
    } while (pfVar3 != (fragbuf_s *)0x0);
LAB_00067140:
    if (uVar4 == intotalbuffers) {
      chan->incomingready[stream] = true;
    }
  }
  goto LAB_00067149;
  while (cVar1 != '\n') {
LAB_000671f2:
    iVar2 = iVar2 + 1;
    cVar1 = local_90[iVar2];
    if ((cVar1 == '\0') || (cVar1 == ';')) break;
  }
LAB_000671fb:
  local_90[iVar2] = '\0';
  __snprintf_chk(local_b0,0x20,1,0x20,"listen %s\n",local_90);
  Cbuf_AddText(local_b0);
LAB_00067149:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Netchan_Clear  @ 00066830
void Netchan_Clear(netchan_t *chan)

{
  fragbufwaiting_s *pfVar1;
  fragbuf_s *pfVar2;
  fragbufwaiting_t *p;
  fragbuf_t *pfVar3;
  fragbuf_t **ppfVar4;
  fragbuf_t **ppfVar5;
  
                    /* Unresolved local var: int i@[???] */
  ppfVar4 = chan->fragbufs;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: fragbufwaiting_t * next@[???] */
    p = (fragbufwaiting_t *)ppfVar4[-6];
    while (p != (fragbufwaiting_t *)0x0) {
                    /* Unresolved local var: fragbuf_t * buf@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
      pfVar1 = p->next;
      pfVar3 = p->fragbufs;
      while (pfVar3 != (fragbuf_t *)0x0) {
        pfVar2 = pfVar3->next;
        Mem_Free(pfVar3);
        pfVar3 = pfVar2;
      }
      p->fragbufs = (fragbuf_t *)0x0;
      Mem_Free(p);
      p = pfVar1;
    }
                    /* Unresolved local var: fragbuf_t * buf@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
    ppfVar4[-6] = (fragbuf_t *)0x0;
    if (ppfVar4 != (fragbuf_t **)0x0) {
      pfVar3 = *ppfVar4;
      while (pfVar3 != (fragbuf_t *)0x0) {
        pfVar2 = pfVar3->next;
        Mem_Free(pfVar3);
        pfVar3 = pfVar2;
      }
      *ppfVar4 = (fragbuf_t *)0x0;
    }
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
    SZ_Clear(&net_message);
    msg_readcount = 0;
    pfVar3 = ppfVar4[6];
    while (pfVar3 != (fragbuf_t *)0x0) {
      pfVar2 = pfVar3->next;
      Mem_Free(pfVar3);
      pfVar3 = pfVar2;
    }
    ppfVar4[6] = (fragbuf_t *)0x0;
    ppfVar5 = ppfVar4 + 1;
    ppfVar4[8] = (fragbuf_t *)0x0;
    ppfVar4 = ppfVar5;
  } while (ppfVar5 != (fragbuf_t **)chan->fragbufcount);
  if (chan->reliable_length != 0) {
    Con_DPrintf("Netchan_Clear() : reliable length not 0, reliable_sequence: %d, incoming_reliable_acknowledged: %d\n"
                ,chan->reliable_length,chan->incoming_reliable_acknowledged);
    chan->reliable_sequence = chan->reliable_sequence ^ 1;
    chan->reliable_length = 0;
  }
  chan->reliable_fragid[0] = 0;
  chan->reliable_fragment[0] = 0;
  chan->fragbufcount[0] = 0;
  chan->frag_startpos[0] = 0;
  chan->frag_length[0] = 0;
  chan->incomingready[0] = false;
  *(undefined4 *)&chan->cleartime = 0;
  *(undefined4 *)((int)&chan->cleartime + 4) = 0;
  chan->reliable_fragid[1] = 0;
  chan->reliable_fragment[1] = 0;
  chan->fragbufcount[1] = 0;
  chan->frag_startpos[1] = 0;
  chan->frag_length[1] = 0;
  chan->incomingready[1] = false;
  if (chan->tempbuffer != (void *)0x0) {
    Mem_Free(chan->tempbuffer);
    chan->tempbuffer = (void *)0x0;
  }
  chan->tempbuffersize = 0;
  return;
}


// Netchan_ClearFragbufs  @ 000666f0
void Netchan_ClearFragbufs(fragbuf_t **ppbuf)

{
  fragbuf_s *pfVar1;
  fragbuf_t *p;
  
                    /* Unresolved local var: fragbuf_t * buf@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
  if (ppbuf != (fragbuf_t **)0x0) {
    p = *ppbuf;
    while (p != (fragbuf_t *)0x0) {
      pfVar1 = p->next;
      Mem_Free(p);
      p = pfVar1;
    }
    *ppbuf = (fragbuf_t *)0x0;
  }
  return;
}


// Netchan_ClearFragments  @ 00066730
void Netchan_ClearFragments(netchan_t *chan)

{
  fragbufwaiting_s *pfVar1;
  fragbuf_s *pfVar2;
  fragbufwaiting_t *p;
  fragbuf_t *pfVar3;
  fragbuf_t **ppfVar4;
  fragbuf_t **ppfVar5;
  
                    /* Unresolved local var: int i@[???] */
  ppfVar4 = chan->fragbufs;
  do {
                    /* Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: fragbufwaiting_t * next@[???] */
    p = (fragbufwaiting_t *)ppfVar4[-6];
    while (p != (fragbufwaiting_t *)0x0) {
                    /* Unresolved local var: fragbuf_t * buf@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
      pfVar1 = p->next;
      pfVar3 = p->fragbufs;
      while (pfVar3 != (fragbuf_t *)0x0) {
        pfVar2 = pfVar3->next;
        Mem_Free(pfVar3);
        pfVar3 = pfVar2;
      }
      p->fragbufs = (fragbuf_t *)0x0;
      Mem_Free(p);
      p = pfVar1;
    }
                    /* Unresolved local var: fragbuf_t * buf@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
    ppfVar4[-6] = (fragbuf_t *)0x0;
    if (ppfVar4 != (fragbuf_t **)0x0) {
      pfVar3 = *ppfVar4;
      while (pfVar3 != (fragbuf_t *)0x0) {
        pfVar2 = pfVar3->next;
        Mem_Free(pfVar3);
        pfVar3 = pfVar2;
      }
      *ppfVar4 = (fragbuf_t *)0x0;
    }
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
    SZ_Clear(&net_message);
    msg_readcount = 0;
    pfVar3 = ppfVar4[6];
    while (pfVar3 != (fragbuf_t *)0x0) {
      pfVar2 = pfVar3->next;
      Mem_Free(pfVar3);
      pfVar3 = pfVar2;
    }
    ppfVar4[6] = (fragbuf_t *)0x0;
    ppfVar5 = ppfVar4 + 1;
    ppfVar4[8] = (fragbuf_t *)0x0;
    ppfVar4 = ppfVar5;
  } while ((fragbuf_t **)chan->fragbufcount != ppfVar5);
  return;
}


// Netchan_CompressPacket  @ 0006a6a0
undefined4 Netchan_CompressPacket(void)

{
  return 0;
}


// Netchan_CopyFileFragments  @ 00069d90
qboolean Netchan_CopyFileFragments(netchan_t *chan)

{
  fragbuf_s *pfVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  qboolean qVar6;
  void *p;
  FileHandle_t file;
  int count;
  fragbuf_t *pfVar7;
  byte *src;
  fragbuf_s *pfVar8;
  size_t size;
  int in_GS_OFFSET;
  bool bVar9;
  void *local_25c;
  size_t local_24c;
  char local_248 [31];
  undefined1 local_229;
  char local_228 [259];
  undefined1 local_125;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: char[260] filename@[???]
                       Unresolved local var: char[32] compressor@[???]
                       Unresolved local var: qboolean bCompressed@[???]
                       Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???]
                       Unresolved local var: int nsize@[???]
                       Unresolved local var: int uncompressedSize@[???]
                       Unresolved local var: uchar * buffer@[???]
                       Unresolved local var: int pos@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  qVar6 = false;
  if (chan->incomingready[1] == false) goto LAB_00069ee2;
  pfVar7 = chan->incomingbufs[1];
  if (pfVar7 == (fragbuf_t *)0x0) {
    Con_Printf("Netchan_CopyFileFragments:  Called with no fragments readied\n");
    chan->incomingready[1] = false;
    qVar6 = false;
    goto LAB_00069ee2;
  }
  SZ_Clear(&net_message);
  MSG_BeginReading();
  SZ_Write(&net_message,(pfVar7->frag_message).data,(pfVar7->frag_message).cursize);
  pcVar3 = MSG_ReadString();
  Q_strncpy(local_228,pcVar3,0x103);
  local_125 = 0;
  pcVar3 = MSG_ReadString();
  Q_strncpy(local_248,pcVar3,0x1f);
  local_229 = 0;
  iVar4 = strcasecmp(local_248,"bz2");
  local_24c = MSG_ReadLong();
  iVar5 = Q_strlen(local_228);
  if (iVar5 < 1) {
    Con_Printf("File fragment received with no filename\nFlushing input queue\n");
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
    SZ_Clear(&net_message);
    msg_readcount = 0;
    pfVar7 = chan->incomingbufs[1];
    while (pfVar7 != (fragbuf_t *)0x0) {
      pfVar8 = pfVar7->next;
      Mem_Free(pfVar7);
      pfVar7 = pfVar8;
    }
  }
  else {
    pcVar3 = Q_strstr(local_228,"..");
    if (pcVar3 == (char *)0x0) {
      if ((local_228[0] == '!') || (qVar6 = IsSafeFileToDownload(local_228), qVar6 != false)) {
        qVar6 = Host_IsServerActive();
        if ((qVar6 == false) || (local_228[0] == '!')) {
          Q_strncpy(chan->incomingfilename,local_228,0x103);
          chan->incomingfilename[0x103] = '\0';
          if ((local_228[0] == '!') || (iVar5 = FS_FileExists(local_228), iVar5 == 0)) {
            iVar5 = 0;
            do {
              iVar5 = iVar5 + (pfVar7->frag_message).cursize;
              bVar9 = chan->incomingbufs[1] == pfVar7;
              pfVar7 = pfVar7->next;
              if (bVar9) {
                iVar5 = iVar5 - msg_readcount;
              }
            } while (pfVar7 != (fragbuf_s *)0x0);
            p = Mem_ZeroMalloc(iVar5 + 1U);
            if (p == (void *)0x0) {
              Con_Printf("Buffer allocation failed on %i bytes\n",iVar5 + 1U);
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
              SZ_Clear(&net_message);
              msg_readcount = 0;
              pfVar7 = chan->incomingbufs[1];
              while (pfVar7 != (fragbuf_t *)0x0) {
                pfVar8 = pfVar7->next;
                Mem_Free(pfVar7);
                pfVar7 = pfVar8;
              }
              goto LAB_00069ed0;
            }
            pfVar7 = chan->incomingbufs[1];
            size = 0;
            pfVar8 = pfVar7;
            if (pfVar7 != (fragbuf_t *)0x0) {
              while( true ) {
                iVar2 = msg_readcount;
                pfVar1 = pfVar8->next;
                if (pfVar8 == pfVar7) {
                  count = (pfVar8->frag_message).cursize - msg_readcount;
                  (pfVar8->frag_message).cursize = count;
                  src = (pfVar8->frag_message).data + iVar2;
                }
                else {
                  count = (pfVar8->frag_message).cursize;
                  src = (pfVar8->frag_message).data;
                }
                Q_memcpy((void *)((int)p + size),src,count);
                size = size + (pfVar8->frag_message).cursize;
                Mem_Free(pfVar8);
                if (pfVar1 == (fragbuf_s *)0x0) break;
                pfVar7 = chan->incomingbufs[1];
                pfVar8 = pfVar1;
              }
            }
            local_25c = p;
            if (iVar4 == 0) {
                    /* Unresolved local var: uchar * uncompressedBuffer@[???] */
              local_25c = Mem_Malloc(local_24c);
              Con_DPrintf("Decompressing file %s (%d -> %d)\n",local_228,iVar5,local_24c);
              BZ2_bzBuffToBuffDecompress(local_25c,&local_24c,p,iVar5,1,0);
              Mem_Free(p);
              size = local_24c;
            }
            if (local_228[0] == '!') {
              if (chan->tempbuffer != (void *)0x0) {
                Con_DPrintf("Netchan_CopyFragments:  Freeing holdover tempbuffer\n");
                Mem_Free(chan->tempbuffer);
              }
              chan->tempbuffersize = size;
              chan->tempbuffer = local_25c;
            }
            else {
              strncpy(local_124,local_228,0x104);
              COM_FixSlashes(local_124);
              pcVar3 = strrchr(local_124,0x2f);
              if (pcVar3 != (char *)0x0) {
                *pcVar3 = '\0';
                FS_CreateDirHierarchy(local_124,"GAMEDOWNLOAD");
              }
              file = FS_OpenPathID(local_228,"wb","GAMEDOWNLOAD");
              if (file == (FileHandle_t)0x0) {
                Con_Printf("File open failed %s\n",local_228);
                SZ_Clear(&net_message);
                msg_readcount = 0;
                pfVar7 = chan->incomingbufs[1];
                while (pfVar7 != (fragbuf_t *)0x0) {
                  pfVar8 = pfVar7->next;
                  Mem_Free(pfVar7);
                  pfVar7 = pfVar8;
                }
                goto LAB_00069ed0;
              }
              Sys_Printf("COM_WriteFile: %s\n");
              FS_Write(local_25c,size,1,file);
              FS_Close(file);
              Mem_Free(local_25c);
            }
            SZ_Clear(&net_message);
            msg_readcount = 0;
          }
          else {
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
            Con_Printf("Can\'t download %s, already exists\n",local_228);
            SZ_Clear(&net_message);
            msg_readcount = 0;
            pfVar7 = chan->incomingbufs[1];
            while (pfVar7 != (fragbuf_t *)0x0) {
              pfVar8 = pfVar7->next;
              Mem_Free(pfVar7);
              pfVar7 = pfVar8;
            }
          }
          chan->incomingbufs[1] = (fragbuf_t *)0x0;
          qVar6 = true;
          chan->incomingready[1] = false;
          goto LAB_00069ee2;
        }
        Con_Printf("File fragment received with bad path, ignoring (2)\n");
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
        SZ_Clear(&net_message);
        msg_readcount = 0;
        pfVar7 = chan->incomingbufs[1];
        while (pfVar7 != (fragbuf_t *)0x0) {
          pfVar8 = pfVar7->next;
          Mem_Free(pfVar7);
          pfVar7 = pfVar8;
        }
      }
      else {
        Con_Printf("File fragment received with bad path, ignoring\n");
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
        SZ_Clear(&net_message);
        msg_readcount = 0;
        pfVar7 = chan->incomingbufs[1];
        while (pfVar7 != (fragbuf_t *)0x0) {
          pfVar8 = pfVar7->next;
          Mem_Free(pfVar7);
          pfVar7 = pfVar8;
        }
      }
    }
    else {
      Con_Printf("File fragment received with relative path, ignoring\n");
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
      SZ_Clear(&net_message);
      msg_readcount = 0;
      pfVar7 = chan->incomingbufs[1];
      while (pfVar7 != (fragbuf_t *)0x0) {
        pfVar8 = pfVar7->next;
        Mem_Free(pfVar7);
        pfVar7 = pfVar8;
      }
    }
  }
LAB_00069ed0:
                    /* Unresolved local var: FileHandle_t handle@[???]
                       Unresolved local var: char[260] filedir@[???]
                       Unresolved local var: char * pszFileName@[???]
                       Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
  chan->incomingbufs[1] = (fragbuf_t *)0x0;
  chan->incomingready[1] = false;
  qVar6 = false;
LAB_00069ee2:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Netchan_CopyNormalFragments  @ 00069ba0
qboolean Netchan_CopyNormalFragments(netchan_t *chan)

{
  int iVar1;
  undefined2 uVar2;
  fragbuf_s *pfVar3;
  undefined4 uVar4;
  uint uVar5;
  qboolean qVar6;
  fragbuf_t *p;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  int in_GS_OFFSET;
  byte bVar10;
  uint uStack_10024;
  byte bStack_10020;
  byte abStack_1001f [65551];
  
                    /* Unresolved local var: qboolean bSuccess@[???]
                       Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
  bVar10 = 0;
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  qVar6 = false;
  if (chan->incomingready[0] != false) {
    p = chan->incomingbufs[0];
    if (p == (fragbuf_t *)0x0) {
      Con_Printf("Netchan_CopyNormalFragments:  Called with no fragments readied\n");
      chan->incomingready[0] = false;
      qVar6 = false;
    }
    else {
      qVar6 = true;
      SZ_Clear(&net_message);
      MSG_BeginReading();
LAB_00069c06:
      do {
        pfVar3 = p->next;
        if (qVar6 != false) {
          qVar6 = SZ_HasSpace(&net_message,(p->frag_message).cursize);
          if (qVar6 != false) {
            qVar6 = true;
            SZ_Write(&net_message,(p->frag_message).data,(p->frag_message).cursize);
            Mem_Free(p);
            p = pfVar3;
            if (pfVar3 == (fragbuf_s *)0x0) break;
            goto LAB_00069c06;
          }
          qVar6 = false;
          SZ_Clear(&net_message);
        }
        Mem_Free(p);
        p = pfVar3;
      } while (pfVar3 != (fragbuf_s *)0x0);
      if ((((*net_message.data == 'B') && (net_message.data[1] == 'Z')) &&
          (net_message.data[2] == '2')) && (net_message.data[3] == '\0')) {
                    /* Unresolved local var: uchar[65536] uncompressed@[???]
                       Unresolved local var: uint uncompressedSize@[???] */
        uStack_10024 = 0x10000;
        pbVar7 = &bStack_10020;
        BZ2_bzBuffToBuffDecompress
                  (pbVar7,&uStack_10024,net_message.data + 4,net_message.cursize + -4,1,0);
        uVar5 = uStack_10024;
        pbVar8 = net_message.data;
        if (7 < uStack_10024) {
          if (((uint)net_message.data & 1) != 0) {
            pbVar8 = net_message.data + 1;
            uVar5 = uStack_10024 - 1;
            pbVar7 = abStack_1001f;
            *net_message.data = bStack_10020;
          }
          pbVar9 = pbVar8;
          if (((uint)pbVar8 & 2) != 0) {
            uVar2 = *(undefined2 *)pbVar7;
            pbVar9 = pbVar8 + 2;
            pbVar7 = pbVar7 + 2;
            uVar5 = uVar5 - 2;
            *(undefined2 *)pbVar8 = uVar2;
          }
          pbVar8 = pbVar9;
          if (((uint)pbVar9 & 4) != 0) {
            uVar4 = *(undefined4 *)pbVar7;
            pbVar8 = pbVar9 + 4;
            pbVar7 = pbVar7 + 4;
            uVar5 = uVar5 - 4;
            *(undefined4 *)pbVar9 = uVar4;
          }
        }
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pbVar8 = *pbVar7;
          pbVar7 = pbVar7 + (uint)bVar10 * -2 + 1;
          pbVar8 = pbVar8 + (uint)bVar10 * -2 + 1;
        }
        net_message.cursize = uStack_10024;
      }
      chan->incomingbufs[0] = (fragbuf_t *)0x0;
      chan->incomingready[0] = false;
    }
  }
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Netchan_CreateFileFragments  @ 000695f0
int Netchan_CreateFileFragments(qboolean server,netchan_t *chan,char *filename)

{
  sizebuf_t *buf;
  fragbuf_s *pfVar1;
  fragbufwaiting_s *pfVar2;
  bool bVar3;
  uint uVar4;
  int32 iVar5;
  int32 iVar6;
  FileHandle_t pvVar7;
  char *pcVar8;
  fragbufwaiting_s *p;
  fragbuf_s *pfVar9;
  void *pOutput;
  void *pInput;
  int iVar10;
  FileHandle_t file;
  fragbuf_t *pfVar11;
  fragbufwaiting_t *pfVar12;
  uint uVar13;
  uint uVar14;
  int in_GS_OFFSET;
  int local_148;
  int local_13c;
  uint local_134;
  uint local_128;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: fragbuf_t * buf@[DW_OP_reg7(EDI)]
                       Unresolved local var: int chunksize@[???]
                       Unresolved local var: int send@[???]
                       Unresolved local var: int remaining@[???]
                       Unresolved local var: int pos@[???]
                       Unresolved local var: int bufferid@[???]
                       Unresolved local var: FileHandle_t hfile@[???]
                       Unresolved local var: int filesize@[???]
                       Unresolved local var: int uncompressed_size@[???]
                       Unresolved local var: qboolean bCompressed@[???]
                       Unresolved local var: qboolean firstfragment@[???]
                       Unresolved local var: char[260] compressedfilename@[???]
                       Unresolved local var: int compressedFileTime@[???]
                       Unresolved local var: int fileTime@[???]
                       Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: fragbufwaiting_t * p@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar4 = (*chan->pfnNetchan_Blocksize)(chan->connection_status);
  __snprintf_chk(local_124,0x104,1,0x104,"%s.ztmp",filename);
  iVar5 = FS_GetFileTime(local_124);
  iVar6 = FS_GetFileTime(filename);
  if ((iVar5 < iVar6) || (pvVar7 = FS_Open(local_124,"rb"), pvVar7 == (FileHandle_t)0x0)) {
    pvVar7 = FS_Open(filename,"rb");
    if (pvVar7 == (FileHandle_t)0x0) goto LAB_00069a05;
    local_134 = FS_Size(pvVar7);
    if (sv_filetransfermaxsize.value < (float)(int)local_134) goto LAB_000696eb;
    uVar14 = local_134;
    if (sv_filetransfercompression.value == 0.0) {
      local_13c = 0;
    }
    else {
                    /* Unresolved local var: uchar * uncompressed@[???]
                       Unresolved local var: uchar * compressed@[???]
                       Unresolved local var: int compressedSize@[???] */
      pOutput = Mem_Malloc(local_134);
      pInput = Mem_Malloc(local_134);
      local_128 = local_134;
      FS_Read(pOutput,local_134,1,pvVar7);
      iVar10 = BZ2_bzBuffToBuffCompress(pInput,&local_128,pOutput,local_134,9,0,0x1e);
                    /* Unresolved local var: FileHandle_t destFile@[???] */
      if ((iVar10 == 0) && (file = FS_Open(local_124,"wb"), file != (FileHandle_t)0x0)) {
        Con_DPrintf("Creating compressed version of file %s (%d -> %d)\n",filename,local_134,
                    local_128);
        FS_Write(pInput,local_128,1,file);
        FS_Close(file);
        local_13c = 1;
        uVar14 = local_128;
      }
      else {
        local_13c = 0;
      }
      Mem_Free(pOutput);
      Mem_Free(pInput);
    }
    FS_Close(pvVar7);
  }
  else {
    uVar14 = FS_Size(pvVar7);
    FS_Close(pvVar7);
    pvVar7 = FS_Open(filename,"rb");
    if (pvVar7 == (FileHandle_t)0x0) {
LAB_00069a05:
      Con_Printf("Warning:  Unable to open %s for transfer\n",filename);
      iVar10 = 0;
      goto LAB_00069738;
    }
    local_134 = FS_Size(pvVar7);
    if (sv_filetransfermaxsize.value < (float)(int)local_134) {
LAB_000696eb:
      FS_Close(pvVar7);
      pcVar8 = NET_AdrToString(chan->remote_address);
      Con_Printf("Warning:  File %s is too big to transfer from host %s\n",filename,pcVar8);
      iVar10 = 0;
      goto LAB_00069738;
    }
    FS_Close(pvVar7);
    local_13c = 1;
  }
  p = Mem_ZeroMalloc(0xc);
  if (0 < (int)uVar14) {
    bVar3 = true;
    local_148 = 0;
    iVar10 = 1;
    while( true ) {
                    /* Unresolved local var: fragbuf_t * buf@[???] */
      uVar13 = uVar4;
      if ((int)uVar14 <= (int)uVar4) {
        uVar13 = uVar14;
      }
      pfVar9 = Mem_ZeroMalloc(0x6ac);
      pfVar9->bufferid = 0;
      (pfVar9->frag_message).cursize = 0;
      (pfVar9->frag_message).data = pfVar9->frag_message_buf;
      (pfVar9->frag_message).maxsize = 0x578;
      (pfVar9->frag_message).buffername = "Frag Buffer Alloc\'d";
      pfVar9->next = (fragbuf_s *)0x0;
      if (pfVar9 == (fragbuf_s *)0x0) {
        Con_Printf("Couldn\'t allocate fragbuf_t\n");
        Mem_Free(p);
        if (server == false) {
          CL_Disconnect_f();
          iVar10 = 0;
        }
        else {
          SV_DropClient(host_client,false,"Malloc problem");
          iVar10 = 0;
        }
        goto LAB_00069738;
      }
      pfVar9->bufferid = iVar10;
      buf = &pfVar9->frag_message;
      SZ_Clear(buf);
      if (bVar3) {
        MSG_WriteString(buf,filename);
        if (local_13c == 0) {
          MSG_WriteString(buf,"uncompressed");
        }
        else {
          MSG_WriteString(buf,"bz2");
        }
        MSG_WriteLong(buf,local_134);
        uVar13 = uVar13 - (pfVar9->frag_message).cursize;
      }
      pfVar9->isfile = 1;
      uVar14 = uVar14 - uVar13;
      pfVar9->size = uVar13;
      pfVar9->iscompressed = local_13c;
      pfVar9->foffset = local_148;
      Q_strncpy(pfVar9->filename,filename,0x103);
      pfVar9->filename[0x103] = '\0';
                    /* Unresolved local var: fragbuf_t * p@[???] */
      pfVar9->next = (fragbuf_s *)0x0;
      local_148 = local_148 + uVar13;
      p->fragbufcount = p->fragbufcount + 1;
      pfVar1 = p->fragbufs;
      if (p->fragbufs == (fragbuf_t *)0x0) {
        p->fragbufs = pfVar9;
      }
      else {
        do {
          pfVar11 = pfVar1;
          pfVar1 = pfVar11->next;
        } while (pfVar1 != (fragbuf_s *)0x0);
        pfVar11->next = pfVar9;
      }
      if ((int)uVar14 < 1) break;
      bVar3 = false;
      iVar10 = iVar10 + 1;
    }
  }
  pfVar2 = chan->waitlist[1];
  if (chan->waitlist[1] == (fragbufwaiting_t *)0x0) {
    chan->waitlist[1] = p;
    iVar10 = 1;
  }
  else {
    do {
      pfVar12 = pfVar2;
      pfVar2 = pfVar12->next;
    } while (pfVar2 != (fragbufwaiting_s *)0x0);
    pfVar12->next = p;
    iVar10 = 1;
  }
LAB_00069738:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar10;
}


// Netchan_CreateFileFragmentsFromBuffer  @ 000692d0
void Netchan_CreateFileFragmentsFromBuffer
               (qboolean server,netchan_t *chan,char *filename,uchar *uncompressed_pbuf,
               int uncompressed_size)

{
  sizebuf_t *buf;
  fragbuf_s *pfVar1;
  fragbufwaiting_s *pfVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  fragbufwaiting_s *p;
  fragbuf_s *pfVar6;
  fragbuf_t *pfVar7;
  int iVar8;
  fragbufwaiting_t *pfVar9;
  int iSize;
  int iVar10;
  int local_48;
  uchar *local_38;
  int local_20 [4];
  
                    /* Unresolved local var: fragbuf_t * buf@[DW_OP_reg7(EDI)]
                       Unresolved local var: int chunksize@[???]
                       Unresolved local var: int send@[???]
                       Unresolved local var: int remaining@[???]
                       Unresolved local var: int pos@[???]
                       Unresolved local var: int bufferid@[???]
                       Unresolved local var: int filesize@[???]
                       Unresolved local var: qboolean firstfragment@[???]
                       Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: fragbufwaiting_t * p@[???]
                       Unresolved local var: uchar * pbuf@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: qboolean bCompressed@[???] */
  local_20[0] = uncompressed_size;
  if (uncompressed_size != 0) {
    local_38 = Mem_Malloc(uncompressed_size);
    iVar4 = BZ2_bzBuffToBuffCompress(local_38,local_20,uncompressed_pbuf,uncompressed_size,9,0,0x1e)
    ;
    if (iVar4 == 0) {
      Con_DPrintf("Compressed %s for transmission (%d -> %d)\n",filename,uncompressed_size,
                  local_20[0]);
    }
    else {
      Mem_Free(local_38);
      local_20[0] = uncompressed_size;
      local_38 = uncompressed_pbuf;
    }
    iVar5 = (*chan->pfnNetchan_Blocksize)(chan->connection_status);
    p = Mem_ZeroMalloc(0xc);
    if (0 < local_20[0]) {
      bVar3 = true;
      local_48 = 0;
      iVar8 = 1;
      iVar10 = local_20[0];
      while( true ) {
                    /* Unresolved local var: fragbuf_t * buf@[???] */
        iSize = iVar5;
        if (iVar10 <= iVar5) {
          iSize = iVar10;
        }
        pfVar6 = Mem_ZeroMalloc(0x6ac);
        pfVar6->bufferid = 0;
        (pfVar6->frag_message).cursize = 0;
        (pfVar6->frag_message).data = pfVar6->frag_message_buf;
        (pfVar6->frag_message).maxsize = 0x578;
        (pfVar6->frag_message).buffername = "Frag Buffer Alloc\'d";
        pfVar6->next = (fragbuf_s *)0x0;
        if (pfVar6 == (fragbuf_s *)0x0) {
          Con_Printf("Couldn\'t allocate fragbuf_t\n");
          Mem_Free(p);
          if (server != false) {
            SV_DropClient(host_client,false,"Malloc problem");
            return;
          }
          CL_Disconnect_f();
          return;
        }
        pfVar6->bufferid = iVar8;
        buf = &pfVar6->frag_message;
        SZ_Clear(buf);
        if (bVar3) {
          MSG_WriteString(buf,filename);
          if (iVar4 == 0) {
            MSG_WriteString(buf,"bz2");
          }
          else {
            MSG_WriteString(buf,"uncompressed");
          }
          MSG_WriteLong(buf,uncompressed_size);
          iSize = iSize - (pfVar6->frag_message).cursize;
        }
        pfVar6->isbuffer = 1;
        iVar10 = iVar10 - iSize;
        pfVar6->isfile = 1;
        pfVar6->size = iSize;
        pfVar6->foffset = local_48;
        MSG_WriteBuf(buf,iSize,local_38 + local_48);
                    /* Unresolved local var: fragbuf_t * p@[???] */
        pfVar6->next = (fragbuf_s *)0x0;
        local_48 = local_48 + iSize;
        p->fragbufcount = p->fragbufcount + 1;
        pfVar1 = p->fragbufs;
        if (p->fragbufs == (fragbuf_t *)0x0) {
          p->fragbufs = pfVar6;
        }
        else {
          do {
            pfVar7 = pfVar1;
            pfVar1 = pfVar7->next;
          } while (pfVar1 != (fragbuf_s *)0x0);
          pfVar7->next = pfVar6;
        }
        if (iVar10 < 1) break;
        bVar3 = false;
        iVar8 = iVar8 + 1;
      }
    }
    pfVar2 = chan->waitlist[1];
    if (chan->waitlist[1] != (fragbufwaiting_t *)0x0) {
      do {
        pfVar9 = pfVar2;
        pfVar2 = pfVar9->next;
      } while (pfVar2 != (fragbufwaiting_s *)0x0);
      pfVar9->next = p;
      return;
    }
    chan->waitlist[1] = p;
  }
  return;
}


// Netchan_CreateFragments  @ 00069270
void Netchan_CreateFragments(qboolean server,netchan_t *chan,sizebuf_t *msg)

{
  if (0 < (chan->message).cursize) {
    Netchan_CreateFragments_(server,chan,&chan->message);
    (chan->message).cursize = 0;
  }
  Netchan_CreateFragments_(server,chan,msg);
  return;
}


// Netchan_CreateFragments_  @ 00068250
void Netchan_CreateFragments_(qboolean server,netchan_t *chan,sizebuf_t *msg)

{
  undefined2 uVar1;
  int iVar2;
  fragbuf_s *pfVar3;
  fragbufwaiting_s *pfVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  fragbufwaiting_s *p;
  fragbuf_s *pfVar9;
  fragbuf_t *pfVar10;
  fragbufwaiting_t *pfVar11;
  uint uVar12;
  byte *pbVar13;
  int length;
  byte *pbVar14;
  byte *pbVar15;
  int in_GS_OFFSET;
  byte bVar16;
  int iStack_10044;
  uint uStack_10024;
  byte bStack_10020;
  byte abStack_1001f [65551];
  
                    /* Unresolved local var: fragbuf_t * buf@[DW_OP_reg3(EBX)]
                       Unresolved local var: int chunksize@[???]
                       Unresolved local var: int send@[???]
                       Unresolved local var: int remaining@[???]
                       Unresolved local var: int pos@[???]
                       Unresolved local var: int bufferid@[???]
                       Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: fragbufwaiting_t * p@[???] */
  bVar16 = 0;
  iVar2 = *(int *)(in_GS_OFFSET + 0x14);
  iVar7 = msg->cursize;
  if (iVar7 != 0) {
    pbVar14 = msg->data;
    if ((((*pbVar14 != 'B') || (pbVar14[1] != 'Z')) || (pbVar14[2] != '2')) || (pbVar14[3] != '\0'))
    {
                    /* Unresolved local var: uchar[65536] compressed@[???]
                       Unresolved local var: char[4] hdr@[???]
                       Unresolved local var: uint compressedSize@[???] */
      uStack_10024 = iVar7 - 4;
      pbVar13 = &bStack_10020;
      iVar7 = BZ2_bzBuffToBuffCompress(pbVar13,&uStack_10024,pbVar14,iVar7,9,0,0x1e);
      if (iVar7 == 0) {
        Con_DPrintf("Compressing split packet (%d -> %d bytes)\n",msg->cursize,uStack_10024);
        builtin_memcpy(msg->data,"BZ2",4);
        pbVar15 = msg->data;
        pbVar14 = pbVar15 + 4;
        uVar12 = uStack_10024;
        if (7 < uStack_10024) {
          if (((uint)pbVar14 & 1) != 0) {
            pbVar14 = pbVar15 + 5;
            pbVar13 = abStack_1001f;
            pbVar15[4] = bStack_10020;
            uVar12 = uStack_10024 - 1;
          }
          pbVar15 = pbVar14;
          if (((uint)pbVar14 & 2) != 0) {
            uVar1 = *(undefined2 *)pbVar13;
            pbVar15 = pbVar14 + 2;
            pbVar13 = pbVar13 + 2;
            uVar12 = uVar12 - 2;
            *(undefined2 *)pbVar14 = uVar1;
          }
          pbVar14 = pbVar15;
          if (((uint)pbVar15 & 4) != 0) {
            uVar5 = *(undefined4 *)pbVar13;
            pbVar14 = pbVar15 + 4;
            pbVar13 = pbVar13 + 4;
            uVar12 = uVar12 - 4;
            *(undefined4 *)pbVar15 = uVar5;
          }
        }
        for (; uVar12 != 0; uVar12 = uVar12 - 1) {
          *pbVar14 = *pbVar13;
          pbVar13 = pbVar13 + (uint)bVar16 * -2 + 1;
          pbVar14 = pbVar14 + (uint)bVar16 * -2 + 1;
        }
        msg->cursize = uStack_10024 + 4;
      }
    }
    iVar8 = (*chan->pfnNetchan_Blocksize)(chan->connection_status);
    p = Mem_ZeroMalloc(0xc);
    iStack_10044 = 0;
    iVar7 = msg->cursize;
    iVar6 = 1;
    while (0 < iVar7) {
                    /* Unresolved local var: fragbuf_t * buf@[???] */
      length = iVar8;
      if (iVar7 < iVar8) {
        length = iVar7;
      }
      pfVar9 = Mem_ZeroMalloc(0x6ac);
      iVar7 = iVar7 - length;
      pfVar9->bufferid = 0;
      (pfVar9->frag_message).cursize = 0;
      (pfVar9->frag_message).data = pfVar9->frag_message_buf;
      (pfVar9->frag_message).maxsize = 0x578;
      (pfVar9->frag_message).buffername = "Frag Buffer Alloc\'d";
      pfVar9->next = (fragbuf_s *)0x0;
      if (pfVar9 == (fragbuf_s *)0x0) {
        Con_Printf("Couldn\'t allocate fragbuf_t\n");
        Mem_Free(p);
        if (server == false) {
          CL_Disconnect_f();
        }
        else {
          SV_DropClient(host_client,false,"Malloc problem");
        }
        goto LAB_00068402;
      }
      pfVar9->bufferid = iVar6;
      SZ_Clear(&pfVar9->frag_message);
      SZ_Write(&pfVar9->frag_message,msg->data + iStack_10044,length);
                    /* Unresolved local var: fragbuf_t * p@[???] */
      pfVar9->next = (fragbuf_s *)0x0;
      iStack_10044 = iStack_10044 + length;
      p->fragbufcount = p->fragbufcount + 1;
      pfVar3 = p->fragbufs;
      if (p->fragbufs == (fragbuf_t *)0x0) {
        p->fragbufs = pfVar9;
        iVar6 = iVar6 + 1;
      }
      else {
        do {
          pfVar10 = pfVar3;
          pfVar3 = pfVar10->next;
        } while (pfVar3 != (fragbuf_s *)0x0);
        pfVar10->next = pfVar9;
        iVar6 = iVar6 + 1;
      }
    }
    pfVar4 = chan->waitlist[0];
    if (chan->waitlist[0] == (fragbufwaiting_t *)0x0) {
      chan->waitlist[0] = p;
    }
    else {
      do {
        pfVar11 = pfVar4;
        pfVar4 = pfVar11->next;
      } while (pfVar4 != (fragbufwaiting_s *)0x0);
      pfVar11->next = p;
    }
  }
LAB_00068402:
  if (iVar2 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Netchan_DecompressPacket  @ 0006a6b0
qboolean Netchan_DecompressPacket(sizebuf_t *chan)

{
  return false;
}


// Netchan_FindBufferById  @ 00066ff0
fragbuf_t * Netchan_FindBufferById(fragbuf_t **pplist,int id,qboolean allocate)

{
  int iVar1;
  fragbuf_s *pfVar2;
  fragbuf_t *pfVar3;
  fragbuf_t *pfVar4;
  
                    /* Unresolved local var: fragbuf_t * list@[???]
                       Unresolved local var: fragbuf_t * pnewbuf@[???] */
  pfVar3 = *pplist;
  if (pfVar3 == (fragbuf_t *)0x0) {
LAB_0006701b:
    if (allocate == false) {
      return (fragbuf_t *)0x0;
    }
                    /* Unresolved local var: fragbuf_t * list@[???]
                       Unresolved local var: fragbuf_t * pnewbuf@[???] */
    pfVar3 = Mem_ZeroMalloc(0x6ac);
                    /* Unresolved local var: fragbuf_t * pprev@[???]
                       Unresolved local var: fragbuf_t * n@[???]
                       Unresolved local var: int id1@[???]
                       Unresolved local var: int id2@[???] */
    pfVar3->bufferid = id;
    (pfVar3->frag_message).cursize = 0;
    (pfVar3->frag_message).data = pfVar3->frag_message_buf;
    (pfVar3->frag_message).maxsize = 0x578;
    (pfVar3->frag_message).buffername = "Frag Buffer";
    (pfVar3->frag_message).flags = 1;
    pfVar3->next = (fragbuf_s *)0x0;
    if (pplist != (fragbuf_t **)0x0) {
      pfVar2 = *pplist;
      if (*pplist == (fragbuf_t *)0x0) {
        *pplist = pfVar3;
      }
      else {
        while (pfVar4 = pfVar2, pfVar2 = pfVar4->next, pfVar2 != (fragbuf_s *)0x0) {
          if ((uint)id >> 0x10 < (uint)*(ushort *)((int)&pfVar2->bufferid + 2)) {
            pfVar3->next = pfVar2->next;
            pfVar4->next = pfVar3;
            return pfVar3;
          }
        }
        pfVar4->next = pfVar3;
      }
    }
  }
  else {
    iVar1 = pfVar3->bufferid;
    while (id != iVar1) {
      pfVar3 = pfVar3->next;
      if (pfVar3 == (fragbuf_s *)0x0) goto LAB_0006701b;
      iVar1 = pfVar3->bufferid;
    }
  }
  return pfVar3;
}


// Netchan_FlushIncoming  @ 00069b40
void Netchan_FlushIncoming(netchan_t *chan,int stream)

{
  fragbuf_s *pfVar1;
  fragbuf_t *p;
  
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
  SZ_Clear(&net_message);
  msg_readcount = 0;
  p = chan->incomingbufs[stream];
  while (p != (fragbuf_t *)0x0) {
    pfVar1 = p->next;
    Mem_Free(p);
    p = pfVar1;
  }
  chan->incomingbufs[stream] = (fragbuf_t *)0x0;
  chan->incomingready[stream] = false;
  return;
}


// Netchan_FragSend  @ 000680e0
void Netchan_FragSend(netchan_t *chan)

{
  fragbufwaiting_t *pfVar1;
  
                    /* Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: int i@[???] */
  if (chan != (netchan_t *)0x0) {
    if ((chan->fragbufs[0] == (fragbuf_t *)0x0) &&
       (pfVar1 = chan->waitlist[0], pfVar1 != (fragbufwaiting_t *)0x0)) {
      chan->waitlist[0] = pfVar1->next;
      pfVar1->next = (fragbufwaiting_s *)0x0;
      chan->fragbufs[0] = pfVar1->fragbufs;
      chan->fragbufcount[0] = pfVar1->fragbufcount;
      Mem_Free(pfVar1);
    }
    if ((chan->fragbufs[1] == (fragbuf_t *)0x0) &&
       (pfVar1 = chan->waitlist[1], pfVar1 != (fragbufwaiting_t *)0x0)) {
      chan->waitlist[1] = pfVar1->next;
      pfVar1->next = (fragbufwaiting_s *)0x0;
      chan->fragbufs[1] = pfVar1->fragbufs;
      chan->fragbufcount[1] = pfVar1->fragbufcount;
      Mem_Free(pfVar1);
      return;
    }
  }
  return;
}


// Netchan_IncomingReady  @ 0006a430
qboolean Netchan_IncomingReady(netchan_t *chan)

{
                    /* Unresolved local var: int i@[???] */
  if (chan->incomingready[0] == false) {
    return (uint)(chan->incomingready[1] != false);
  }
  return true;
}


// Netchan_Init  @ 0006a640
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Netchan_Init(void)

{
  Cvar_RegisterVariable(&net_log);
  Cvar_RegisterVariable(&net_showpackets);
  Cvar_RegisterVariable(&net_showdrop);
  Cvar_RegisterVariable(&net_chokeloopback);
  Cvar_RegisterVariable(&net_drawslider);
  Cvar_RegisterVariable(&sv_filetransfercompression);
  Cvar_RegisterVariable(&sv_filetransfermaxsize);
  return;
}


// Netchan_IsReceiving  @ 0006a400
qboolean Netchan_IsReceiving(netchan_t *chan)

{
                    /* Unresolved local var: int i@[???] */
  if (chan->incomingbufs[0] == (fragbuf_t *)0x0) {
    return (uint)(chan->incomingbufs[1] != (fragbuf_t *)0x0);
  }
  return true;
}


// Netchan_IsSending  @ 0006a3d0
qboolean Netchan_IsSending(netchan_t *chan)

{
                    /* Unresolved local var: int i@[???] */
  if (chan->fragbufs[0] == (fragbuf_t *)0x0) {
    return (uint)(chan->fragbufs[1] != (fragbuf_t *)0x0);
  }
  return true;
}


// Netchan_OutOfBand  @ 00066570
void Netchan_OutOfBand(netsrc_t sock,netadr_t adr,int length,byte *data)

{
  int in_GS_OFFSET;
  sizebuf_t local_17bc;
  byte local_17a5 [6037];
  int local_10;
  
                    /* Unresolved local var: sizebuf_t send@[???]
                       Unresolved local var: byte[6037] send_buf@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_17bc.buffername = "Netchan_OutOfBand";
  local_17bc.data = local_17a5;
  local_17bc.maxsize = 0x1795;
  local_17bc.cursize = 0;
  local_17bc.flags = 1;
  MSG_WriteLong(&local_17bc,-1);
  SZ_Write(&local_17bc,data,length);
  if (cls.demoplayback == false) {
    NET_SendPacket(sock,local_17bc.cursize,local_17bc.data,adr);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Netchan_OutOfBandPrint  @ 00066660
void Netchan_OutOfBandPrint(netsrc_t sock,netadr_t adr,char *format,...)

{
  int iVar1;
  
                    /* Unresolved local var: va_list argptr@[???] */
  __vsnprintf_chk(Netchan_OutOfBandPrint::string,0x2000,1,0x2000,format,&stack0x00000020);
  iVar1 = Q_strlen(Netchan_OutOfBandPrint::string);
  Netchan_OutOfBand(sock,adr,iVar1 + 1,(byte *)Netchan_OutOfBandPrint::string);
  return;
}


// Netchan_Process  @ 000672e0
/* WARNING: Type propagation algorithm not settling */

qboolean Netchan_Process(netchan_t *chan)

{
  float fVar1;
  float fVar2;
  fragbuf_s *pfVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  netadr_t a;
  double dVar7;
  uint uVar8;
  uint uVar9;
  qboolean qVar10;
  uint seq;
  int iVar11;
  undefined4 uVar12;
  char *pcVar13;
  byte *pbVar14;
  fragbuf_t *pfVar15;
  int iVar16;
  byte *pbVar17;
  byte *pbVar18;
  fragbuf_t *pfVar19;
  uint uVar20;
  double *pdVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  int iVar37;
  longdouble lVar38;
  longdouble lVar39;
  longdouble lVar40;
  longdouble lVar41;
  longdouble lVar42;
  longdouble lVar43;
  longdouble lVar44;
  longdouble lVar45;
  longdouble lVar46;
  longdouble lVar47;
  longdouble lVar48;
  longdouble lVar49;
  longdouble lVar50;
  longdouble lVar51;
  longdouble lVar52;
  uint local_64;
  uint local_60;
  int local_5c;
  fragbuf_t **local_54;
  byte *local_4c;
  float local_40;
  uint local_3c [11];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uint sequence@[???]
                       Unresolved local var: uint sequence_ack@[???]
                       Unresolved local var: uint reliable_ack@[???]
                       Unresolved local var: uint reliable_message@[???]
                       Unresolved local var: uint[2] fragid@[???]
                       Unresolved local var: qboolean[2] frag_message@[???]
                       Unresolved local var: int[2] frag_offset@[???]
                       Unresolved local var: int[2] frag_length@[???]
                       Unresolved local var: qboolean message_contains_fragments@[???] */
  local_3c[3] = 0;
  local_3c[4] = 0;
  local_3c[5] = 0;
  local_3c[6] = 0;
  local_3c[7] = 0;
  local_3c[0] = 0;
  local_3c[1] = 0;
  local_3c[2] = 0;
  if (((cls.demoplayback == false) && (cls.passive == false)) &&
     (a.ip = net_from.ip, a.type = net_from.type, a.ipx._0_4_ = net_from.ipx._0_4_,
     a.ipx._4_4_ = net_from.ipx._4_4_, a._16_4_ = net_from._16_4_,
     qVar10 = NET_CompareAdr(a,chan->remote_address), qVar10 == false)) {
    return false;
  }
  chan->last_received = (float)realtime;
  MSG_BeginReading();
  uVar8 = MSG_ReadLong();
  uVar9 = MSG_ReadLong();
  if ((uVar9 & 0x40000000) == 0) {
    if (g_modfuncs.m_pfnProcessIncomingNet == (PFN_PROCESSINCOMINGNET)0x0) goto LAB_00067380;
  }
  else if (g_modfuncs.m_pfnProcessIncomingNet == (PFN_PROCESSINCOMINGNET)0x0) {
    return false;
  }
  qVar10 = (*g_modfuncs.m_pfnProcessIncomingNet)(chan,&net_message);
  if (qVar10 == false) {
    return false;
  }
LAB_00067380:
  seq = uVar8 & 0xff;
  COM_UnMunge2(net_message.data + 8,net_message.cursize + -8,seq);
  if ((uVar8 & 0x40000000) != 0) {
    iVar22 = 0;
    do {
      iVar11 = MSG_ReadByte();
      if (iVar11 != 0) {
        local_3c[iVar22 + 2] = 1;
        uVar20 = MSG_ReadLong();
        local_3c[iVar22] = uVar20;
        uVar20 = MSG_ReadShort();
        local_3c[iVar22 + 4] = uVar20;
        uVar20 = MSG_ReadShort();
        local_3c[iVar22 + 6] = uVar20;
      }
      iVar22 = iVar22 + 1;
    } while (iVar22 != 2);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int buffer@[???]
                       Unresolved local var: int count@[???] */
    if (local_3c[2] != 0) {
      if (0x61a8ffff < local_3c[0]) {
        return false;
      }
      if (25000 < (local_3c[0] & 0xffff)) {
        return false;
      }
      if (0x800 < local_3c[6]) {
        return false;
      }
      if (0x4000 < local_3c[4]) {
        return false;
      }
    }
    if (local_3c[3] != 0) {
      if (25000 < (local_3c[1] & 0xffff)) {
        return false;
      }
      if (0x61a8ffff < local_3c[1]) {
        return false;
      }
      if (0x800 < local_3c[7]) {
        return false;
      }
      if (0x4000 < local_3c[5]) {
        return false;
      }
    }
  }
  uVar20 = uVar8 & 0x3fffffff;
  if ((net_showpackets.value != 3.0) && (net_showpackets.value != 0.0)) {
                    /* Unresolved local var: char c@[???]
                       Unresolved local var: int mask@[???] */
    if (chan == &cls.netchan) {
      uVar12 = 99;
      dVar7 = cl.time;
    }
    else {
      uVar12 = 0x73;
      dVar7 = sv.time;
    }
    local_40 = (float)dVar7;
    seq = net_message.cursize;
    Con_Printf(" %c <-- sz=%i seq=%i ack=%i rel=%i tm=%f\n",uVar12,net_message.cursize,uVar20,
               uVar9 & 0x3fffffff,-((int)uVar8 >> 0x1f),SUB84((double)local_40,0),
               (int)((ulonglong)(double)local_40 >> 0x20));
  }
  uVar23 = chan->incoming_sequence;
  if (uVar20 <= uVar23) {
    if (net_showdrop.value == 0.0) {
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: uchar * src@[???]
                       Unresolved local var: uchar * dst@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: fragbuf_t * pbuf@[???]
                       Unresolved local var: int inbufferid@[???]
                       Unresolved local var: int intotalbuffers@[???]
                       Unresolved local var: int nbytes@[???] */
      return false;
    }
    if (uVar20 != uVar23) {
      pcVar13 = NET_AdrToString(chan->remote_address);
      Con_Printf("%s:out of order packet %i at %i\n",pcVar13,uVar20,uVar23);
      return false;
    }
    pcVar13 = NET_AdrToString(chan->remote_address);
    Con_Printf("%s:duplicate packet %i at %i\n",pcVar13,uVar20,uVar20);
    return false;
  }
  uVar23 = ~uVar23 + uVar20;
  net_drop = uVar23;
  if ((0 < (int)uVar23) && (net_showdrop.value != 0.0)) {
    pcVar13 = NET_AdrToString(chan->remote_address);
    Con_Printf("%s:Dropped %i packets at %i\n",pcVar13,uVar23,uVar20);
    seq = uVar23;
  }
  if ((uVar9 >> 0x1f == chan->reliable_sequence) &&
     (chan->last_reliable_sequence <= chan->incoming_acknowledged + 1)) {
    chan->reliable_length = 0;
  }
  chan->incoming_sequence = uVar20;
  chan->incoming_acknowledged = uVar9 & 0x3fffffff;
  chan->incoming_reliable_acknowledged = uVar9 >> 0x1f;
  if (-((int)uVar8 >> 0x1f) != 0) {
    chan->incoming_reliable_sequence = chan->incoming_reliable_sequence ^ 1;
  }
  dVar7 = realtime;
  uVar9 = chan->flow[1].current;
  uVar20 = uVar9 & 0x1f;
                    /* Unresolved local var: int flow@[???]
                       Unresolved local var: int start@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int bytes@[???]
                       Unresolved local var: float faccumulatedtime@[???]
                       Unresolved local var: flow_t * pflow@[???]
                       Unresolved local var: flowstats_t * pstat@[???]
                       Unresolved local var: flowstats_t * pprev@[???] */
  chan->flow[1].stats[uVar20].size = net_message.cursize + 0x1c;
  chan->flow[1].stats[uVar20].time = dVar7;
  chan->flow[1].current = uVar9 + 1;
  if (chan != (netchan_t *)0x0) {
    pdVar21 = &chan->flow[0].nextcompute;
    iVar22 = 0;
    lVar52 = (longdouble)0;
    iVar11 = 0;
    do {
      if (0.1 <= dVar7 - *pdVar21) {
        iVar16 = *(int *)((int)pdVar21 + -4);
        uVar9 = iVar16 - 2U & 0x1f;
        *pdVar21 = dVar7 + 0.1;
        lVar38 = (longdouble)chan->flow[iVar11].stats[uVar9].time;
        uVar23 = iVar16 - 3U & 0x1f;
        lVar39 = (longdouble)chan->flow[iVar11].stats[uVar23].time;
        uVar25 = iVar16 - 4U & 0x1f;
        lVar40 = (longdouble)chan->flow[iVar11].stats[uVar25].time;
        uVar26 = iVar16 - 5U & 0x1f;
        lVar41 = (longdouble)chan->flow[iVar11].stats[uVar26].time;
        uVar27 = iVar16 - 6U & 0x1f;
        lVar42 = (longdouble)chan->flow[iVar11].stats[uVar27].time;
        uVar28 = iVar16 - 7U & 0x1f;
        lVar43 = (longdouble)chan->flow[iVar11].stats[uVar28].time;
        uVar29 = iVar16 - 8U & 0x1f;
        lVar44 = (longdouble)chan->flow[iVar11].stats[uVar29].time;
        uVar30 = iVar16 - 9U & 0x1f;
        lVar45 = (longdouble)chan->flow[iVar11].stats[uVar30].time;
        uVar31 = iVar16 - 10U & 0x1f;
        lVar46 = (longdouble)chan->flow[iVar11].stats[uVar31].time;
        uVar32 = iVar16 - 0xbU & 0x1f;
        lVar47 = (longdouble)chan->flow[iVar11].stats[uVar32].time;
        uVar33 = iVar16 - 0xcU & 0x1f;
        lVar48 = (longdouble)chan->flow[iVar11].stats[uVar33].time;
        uVar34 = iVar16 - 0xdU & 0x1f;
        lVar49 = (longdouble)chan->flow[iVar11].stats[uVar34].time;
        uVar35 = iVar16 - 0xeU & 0x1f;
        lVar50 = (longdouble)chan->flow[iVar11].stats[uVar35].time;
        uVar36 = iVar16 - 0xfU & 0x1f;
        uVar20 = iVar16 - 0x10U & 0x1f;
        lVar51 = (longdouble)chan->flow[iVar11].stats[uVar36].time;
        iVar22 = iVar22 + chan->flow[iVar11].stats[uVar9].size +
                 chan->flow[iVar11].stats[uVar23].size + chan->flow[iVar11].stats[uVar25].size +
                 chan->flow[iVar11].stats[uVar26].size + chan->flow[iVar11].stats[uVar27].size +
                 chan->flow[iVar11].stats[uVar28].size + chan->flow[iVar11].stats[uVar29].size +
                 chan->flow[iVar11].stats[uVar30].size + chan->flow[iVar11].stats[uVar31].size +
                 chan->flow[iVar11].stats[uVar32].size + chan->flow[iVar11].stats[uVar33].size +
                 chan->flow[iVar11].stats[uVar34].size + chan->flow[iVar11].stats[uVar35].size +
                 chan->flow[iVar11].stats[uVar36].size + chan->flow[iVar11].stats[uVar20].size;
        local_40 = (float)((longdouble)
                           (float)((longdouble)
                                   (float)((longdouble)
                                           (float)((longdouble)
                                                   (float)((longdouble)
                                                           (float)((longdouble)
                                                                   (float)((longdouble)
                                                                           (float)((longdouble)
                                                                                   (float)((
                                                  longdouble)
                                                  (float)((longdouble)
                                                          (float)((longdouble)
                                                                  (float)((longdouble)
                                                                          (float)((longdouble)
                                                                                  (float)((
                                                  longdouble)
                                                  (float)(((longdouble)
                                                           chan->flow[iVar11].stats
                                                           [iVar16 - 1U & 0x1f].time - lVar38) +
                                                         lVar52) + (lVar38 - lVar39)) +
                                                  (lVar39 - lVar40)) + (lVar40 - lVar41)) +
                                                  (lVar41 - lVar42)) + (lVar42 - lVar43)) +
                                                  (lVar43 - lVar44)) + (lVar44 - lVar45)) +
                                                  (lVar45 - lVar46)) + (lVar46 - lVar47)) +
                                                  (lVar47 - lVar48)) + (lVar48 - lVar49)) +
                                          (lVar49 - lVar50)) + (lVar50 - lVar51)) +
                          (lVar51 - (longdouble)chan->flow[iVar11].stats[uVar20].time));
        lVar52 = (longdouble)local_40;
        lVar38 = (longdouble)0;
        if (lVar52 == lVar38) {
          *(float *)(pdVar21 + 1) = 0.0;
        }
        else {
          lVar38 = ((longdouble)iVar22 / lVar52) * (longdouble)0.0009765625;
          *(float *)(pdVar21 + 1) = (float)lVar38;
          lVar38 = (longdouble)0.33333333333333337 * lVar38;
        }
        *(float *)((int)pdVar21 + 0xc) =
             (float)((longdouble)0.6666666666666666 * (longdouble)*(float *)((int)pdVar21 + 0xc) +
                    lVar38);
      }
      iVar11 = iVar11 + 1;
      pdVar21 = (double *)((int)pdVar21 + 0x194);
    } while (iVar11 != 2);
  }
  if ((uVar8 & 0x40000000) == 0) {
    return true;
  }
  iVar22 = 1;
  local_54 = chan->incomingbufs;
  local_5c = 0;
  if (local_3c[2] == 0) goto LAB_00067ca8;
  do {
    fVar1 = (&local_40)[iVar22];
    if (fVar1 == 0.0) {
      local_60 = local_3c[iVar22 + 5];
      uVar8 = local_3c[iVar22 + 3];
    }
    else {
                    /* Unresolved local var: fragbuf_t * list@[???]
                       Unresolved local var: fragbuf_t * pnewbuf@[???] */
      pfVar15 = *local_54;
      if (pfVar15 == (fragbuf_t *)0x0) {
LAB_00067e27:
                    /* Unresolved local var: fragbuf_t * list@[???]
                       Unresolved local var: fragbuf_t * pnewbuf@[???] */
        pfVar15 = Mem_ZeroMalloc(0x6ac);
                    /* Unresolved local var: fragbuf_t * pprev@[???]
                       Unresolved local var: fragbuf_t * n@[???]
                       Unresolved local var: int id1@[???]
                       Unresolved local var: int id2@[???] */
        pfVar15->bufferid = (int)fVar1;
        (pfVar15->frag_message).cursize = 0;
        (pfVar15->frag_message).data = pfVar15->frag_message_buf;
        (pfVar15->frag_message).maxsize = 0x578;
        (pfVar15->frag_message).buffername = "Frag Buffer";
        (pfVar15->frag_message).flags = 1;
        pfVar15->next = (fragbuf_s *)0x0;
        if (local_54 != (fragbuf_t **)0x0) {
          pfVar3 = *local_54;
          if (*local_54 == (fragbuf_t *)0x0) {
            *local_54 = pfVar15;
          }
          else {
            do {
              pfVar19 = pfVar3;
              pfVar3 = pfVar19->next;
              if (pfVar3 == (fragbuf_s *)0x0) {
                pfVar19->next = pfVar15;
                goto LAB_00067e8e;
              }
            } while ((uint)*(ushort *)((int)&pfVar3->bufferid + 2) <= (uint)fVar1 >> 0x10);
            pfVar15->next = pfVar3->next;
            pfVar19->next = pfVar15;
          }
        }
LAB_00067e8e:
        if (pfVar15 != (fragbuf_t *)0x0) goto LAB_00067eb0;
        Con_Printf("Netchan_Process:  Couldn\'t allocate or find buffer %i\n",(uint)fVar1 >> 0x10,
                   seq);
        local_60 = local_3c[iVar22 + 5];
        uVar8 = local_3c[iVar22 + 3];
      }
      else {
        fVar2 = (float)pfVar15->bufferid;
        while (fVar2 != fVar1) {
          pfVar15 = pfVar15->next;
          if (pfVar15 == (fragbuf_s *)0x0) goto LAB_00067e27;
          fVar2 = (float)pfVar15->bufferid;
        }
LAB_00067eb0:
        local_60 = local_3c[iVar22 + 5];
        SZ_Clear(&pfVar15->frag_message);
        uVar8 = local_3c[iVar22 + 3];
        SZ_Write(&pfVar15->frag_message,net_message.data + msg_readcount + uVar8,local_60);
        if (((pfVar15->frag_message).flags & 2) != 0) {
          if (chan == &cls.netchan) {
            return false;
          }
          (chan->message).flags = (ushort)*(undefined4 *)&(chan->message).flags | 2;
          return false;
        }
      }
      seq = (uint)fVar1 & 0xffff;
      Netchan_CheckForCompletion(chan,local_5c,seq);
    }
    pbVar18 = net_message.data;
    iVar11 = msg_readcount + uVar8;
    iVar16 = local_60 + iVar11;
    pbVar17 = net_message.data + iVar11;
    pbVar14 = net_message.data + iVar16;
    iVar37 = net_message.cursize - local_60;
    uVar8 = (iVar37 - uVar8) - msg_readcount;
    if (0 < (int)uVar8) {
      if ((iVar11 < iVar16 + 0x10 && iVar16 < iVar11 + 0x10) || (uVar8 < 0x17)) {
        uVar9 = 0;
        do {
          pbVar17[uVar9] = pbVar14[uVar9];
          uVar9 = uVar9 + 1;
        } while (uVar8 != uVar9);
      }
      else {
        uVar9 = -(int)pbVar14 & 0xfU;
        if (uVar8 < (-(int)pbVar14 & 0xfU)) {
          uVar9 = uVar8;
        }
        if (uVar9 == 0) {
          iVar37 = 0;
        }
        else {
          *pbVar17 = *pbVar14;
          if (uVar9 == 1) {
            iVar37 = 1;
            pbVar14 = pbVar14 + 1;
            pbVar17 = pbVar17 + 1;
          }
          else {
            pbVar17[1] = pbVar14[1];
            if (uVar9 == 2) {
              iVar37 = 2;
              pbVar14 = pbVar14 + 2;
              pbVar17 = pbVar17 + 2;
            }
            else {
              pbVar17[2] = pbVar14[2];
              if (uVar9 == 3) {
                iVar37 = 3;
                pbVar14 = pbVar14 + 3;
                pbVar17 = pbVar17 + 3;
              }
              else {
                pbVar17[3] = pbVar14[3];
                if (uVar9 == 4) {
                  iVar37 = 4;
                  pbVar14 = pbVar14 + 4;
                  pbVar17 = pbVar17 + 4;
                }
                else {
                  pbVar17[4] = pbVar14[4];
                  if (uVar9 == 5) {
                    iVar37 = 5;
                    pbVar14 = pbVar14 + 5;
                    pbVar17 = pbVar17 + 5;
                  }
                  else {
                    pbVar17[5] = pbVar14[5];
                    if (uVar9 == 6) {
                      iVar37 = 6;
                      pbVar14 = pbVar14 + 6;
                      pbVar17 = pbVar17 + 6;
                    }
                    else {
                      pbVar17[6] = pbVar14[6];
                      if (uVar9 == 7) {
                        iVar37 = 7;
                        pbVar14 = pbVar14 + 7;
                        pbVar17 = pbVar17 + 7;
                      }
                      else {
                        pbVar17[7] = pbVar14[7];
                        if (uVar9 == 8) {
                          iVar37 = 8;
                          pbVar14 = pbVar14 + 8;
                          pbVar17 = pbVar17 + 8;
                        }
                        else {
                          pbVar17[8] = pbVar14[8];
                          if (uVar9 == 9) {
                            iVar37 = 9;
                            pbVar14 = pbVar14 + 9;
                            pbVar17 = pbVar17 + 9;
                          }
                          else {
                            pbVar17[9] = pbVar14[9];
                            if (uVar9 == 10) {
                              iVar37 = 10;
                              pbVar14 = pbVar14 + 10;
                              pbVar17 = pbVar17 + 10;
                            }
                            else {
                              pbVar17[10] = pbVar14[10];
                              if (uVar9 == 0xb) {
                                iVar37 = 0xb;
                                pbVar14 = pbVar14 + 0xb;
                                pbVar17 = pbVar17 + 0xb;
                              }
                              else {
                                pbVar17[0xb] = pbVar14[0xb];
                                if (uVar9 == 0xc) {
                                  iVar37 = 0xc;
                                  pbVar14 = pbVar14 + 0xc;
                                  pbVar17 = pbVar17 + 0xc;
                                }
                                else {
                                  pbVar17[0xc] = pbVar14[0xc];
                                  if (uVar9 == 0xd) {
                                    iVar37 = 0xd;
                                    pbVar14 = pbVar14 + 0xd;
                                    pbVar17 = pbVar17 + 0xd;
                                  }
                                  else {
                                    pbVar17[0xd] = pbVar14[0xd];
                                    if (uVar9 == 0xf) {
                                      pbVar17[0xe] = pbVar14[0xe];
                                      iVar37 = 0xf;
                                      pbVar14 = pbVar14 + 0xf;
                                      pbVar17 = pbVar17 + 0xf;
                                    }
                                    else {
                                      iVar37 = 0xe;
                                      pbVar14 = pbVar14 + 0xe;
                                      pbVar17 = pbVar17 + 0xe;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        uVar20 = ((uVar8 - uVar9) - 0x10 >> 4) + 1;
        iVar24 = uVar20 * 0x10;
        if (0xe < (uVar8 - 1) - uVar9) {
          local_4c = pbVar18 + iVar11 + uVar9;
          local_64 = 0;
          pbVar18 = pbVar18 + uVar9 + iVar16;
          do {
            uVar12 = *(undefined4 *)pbVar18;
            uVar4 = *(undefined4 *)(pbVar18 + 4);
            uVar5 = *(undefined4 *)(pbVar18 + 8);
            uVar6 = *(undefined4 *)(pbVar18 + 0xc);
            pbVar18 = pbVar18 + 0x10;
            local_64 = local_64 + 1;
            *(undefined4 *)local_4c = uVar12;
            *(undefined4 *)(local_4c + 4) = uVar4;
            *(undefined4 *)(local_4c + 8) = uVar5;
            *(undefined4 *)(local_4c + 0xc) = uVar6;
            local_4c = local_4c + 0x10;
          } while (local_64 < uVar20);
          iVar37 = iVar37 + iVar24;
          pbVar17 = pbVar17 + iVar24;
          pbVar14 = pbVar14 + iVar24;
          if (iVar24 == uVar8 - uVar9) goto LAB_00067c6d;
        }
        *pbVar17 = *pbVar14;
        if ((((((iVar37 + 1 < (int)uVar8) && (pbVar17[1] = pbVar14[1], iVar37 + 2 < (int)uVar8)) &&
              (pbVar17[2] = pbVar14[2], iVar37 + 3 < (int)uVar8)) &&
             ((pbVar17[3] = pbVar14[3], iVar37 + 4 < (int)uVar8 &&
              (pbVar17[4] = pbVar14[4], iVar37 + 5 < (int)uVar8)))) &&
            ((pbVar17[5] = pbVar14[5], iVar37 + 6 < (int)uVar8 &&
             ((pbVar17[6] = pbVar14[6], iVar37 + 7 < (int)uVar8 &&
              (pbVar17[7] = pbVar14[7], iVar37 + 8 < (int)uVar8)))))) &&
           ((pbVar17[8] = pbVar14[8], iVar37 + 9 < (int)uVar8 &&
            ((((pbVar17[9] = pbVar14[9], iVar37 + 10 < (int)uVar8 &&
               (pbVar17[10] = pbVar14[10], iVar37 + 0xb < (int)uVar8)) &&
              (pbVar17[0xb] = pbVar14[0xb], iVar37 + 0xc < (int)uVar8)) &&
             ((pbVar17[0xc] = pbVar14[0xc], iVar37 + 0xd < (int)uVar8 &&
              (pbVar17[0xd] = pbVar14[0xd], iVar37 + 0xe < (int)uVar8)))))))) {
          pbVar17[0xe] = pbVar14[0xe];
        }
      }
LAB_00067c6d:
      iVar37 = net_message.cursize - local_60;
    }
    net_message.cursize = iVar37;
    if (local_5c != 0) goto LAB_00067ca8;
    local_3c[5] = local_3c[5] - local_60;
    local_5c = iVar22;
    while( true ) {
      iVar22 = local_5c + 1;
      local_54 = local_54 + 1;
      if (local_3c[local_5c + 2] != 0) break;
LAB_00067ca8:
      local_5c = iVar22;
      if (iVar22 == 2) {
        return (uint)(0x10 < net_message.cursize);
      }
    }
  } while( true );
}


// Netchan_Setup  @ 00066a10
void Netchan_Setup(netsrc_t socketnumber,netchan_t *chan,netadr_t adr,int player_slot,
                  void *connection_status,_func_qboolean_void_ptr *pfnNetchan_Blocksize)

{
  fragbufwaiting_s *pfVar1;
  fragbuf_s *pfVar2;
  void *p;
  float fVar3;
  fragbufwaiting_t *p_00;
  fragbuf_t *pfVar4;
  fragbuf_t **ppfVar5;
  fragbuf_t **ppfVar6;
  
  ppfVar5 = chan->fragbufs;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: fragbufwaiting_t * next@[???] */
    p_00 = (fragbufwaiting_t *)ppfVar5[-6];
    while (p_00 != (fragbufwaiting_t *)0x0) {
                    /* Unresolved local var: fragbuf_t * buf@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
      pfVar1 = p_00->next;
      pfVar4 = p_00->fragbufs;
      while (pfVar4 != (fragbuf_t *)0x0) {
        pfVar2 = pfVar4->next;
        Mem_Free(pfVar4);
        pfVar4 = pfVar2;
      }
      p_00->fragbufs = (fragbuf_t *)0x0;
      Mem_Free(p_00);
      p_00 = pfVar1;
    }
                    /* Unresolved local var: fragbuf_t * buf@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
    ppfVar5[-6] = (fragbuf_t *)0x0;
    if (ppfVar5 != (fragbuf_t **)0x0) {
      pfVar4 = *ppfVar5;
      while (pfVar4 != (fragbuf_t *)0x0) {
        pfVar2 = pfVar4->next;
        Mem_Free(pfVar4);
        pfVar4 = pfVar2;
      }
      *ppfVar5 = (fragbuf_t *)0x0;
    }
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
    SZ_Clear(&net_message);
    msg_readcount = 0;
    pfVar4 = ppfVar5[6];
    while (pfVar4 != (fragbuf_t *)0x0) {
      pfVar2 = pfVar4->next;
      Mem_Free(pfVar4);
      pfVar4 = pfVar2;
    }
    ppfVar5[6] = (fragbuf_t *)0x0;
    ppfVar6 = ppfVar5 + 1;
    ppfVar5[8] = (fragbuf_t *)0x0;
    ppfVar5 = ppfVar6;
  } while ((fragbuf_t **)chan->fragbufcount != ppfVar6);
  if (chan->reliable_length != 0) {
    Con_DPrintf("Netchan_Clear() : reliable length not 0, reliable_sequence: %d, incoming_reliable_acknowledged: %d\n"
                ,chan->reliable_length,chan->incoming_reliable_acknowledged);
    chan->reliable_sequence = chan->reliable_sequence ^ 1;
    chan->reliable_length = 0;
  }
  chan->fragbufcount[0] = 0;
  chan->frag_startpos[0] = 0;
  chan->frag_length[0] = 0;
  chan->incomingready[0] = false;
  chan->reliable_fragid[1] = 0;
  chan->reliable_fragment[1] = 0;
  p = chan->tempbuffer;
  chan->reliable_fragid[0] = 0;
  *(undefined4 *)&chan->cleartime = 0;
  *(undefined4 *)((int)&chan->cleartime + 4) = 0;
  chan->reliable_fragment[0] = 0;
  chan->fragbufcount[1] = 0;
  chan->frag_startpos[1] = 0;
  chan->frag_length[1] = 0;
  chan->incomingready[1] = false;
  if (p != (void *)0x0) {
    Mem_Free(p);
    chan->tempbuffer = (void *)0x0;
  }
  chan->tempbuffersize = 0;
  Q_memset(chan,0,0x33b4);
  chan->player_slot = player_slot + 1;
  chan->sock = socketnumber;
  (chan->remote_address).type = adr.type;
  fVar3 = (float)realtime;
  *&(chan->remote_address).ip = adr.ip;
  *(undefined4 *)(chan->remote_address).ipx = adr.ipx._0_4_;
  *(undefined4 *)((chan->remote_address).ipx + 4) = adr.ipx._4_4_;
  *(undefined4 *)((chan->remote_address).ipx + 8) = adr._16_4_;
  (chan->message).data = chan->message_buf;
  chan->last_received = fVar3;
  chan->connect_time = fVar3;
  (chan->message).flags = 1;
  chan->connection_status = connection_status;
  (chan->message).maxsize = 0x1766;
  (chan->message).buffername = "netchan->message";
  *(undefined4 *)&chan->rate = 0;
  *(undefined4 *)((int)&chan->rate + 4) = 0x40dd4c00;
  chan->outgoing_sequence = 1;
  chan->pfnNetchan_Blocksize = (_func_int_void_ptr *)pfnNetchan_Blocksize;
  return;
}


// Netchan_Transmit  @ 00068540
void Netchan_Transmit(netchan_t *chan,int length,byte *data)

{
  fragbuf_t *p;
  fragbuf_s *pfVar1;
  fragbufwaiting_t *pfVar2;
  double dVar3;
  double dVar4;
  bool bVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  FileHandle_t file;
  uint uVar10;
  undefined4 uVar11;
  fragbuf_t *pfVar12;
  qboolean server;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  int iVar27;
  uint uVar28;
  double *pdVar29;
  fragbuf_t **ppfVar30;
  short *psVar31;
  int in_GS_OFFSET;
  bool bVar32;
  longdouble lVar33;
  longdouble lVar34;
  longdouble lVar35;
  longdouble lVar36;
  longdouble lVar37;
  longdouble lVar38;
  longdouble lVar39;
  longdouble lVar40;
  longdouble lVar41;
  longdouble lVar42;
  longdouble lVar43;
  longdouble lVar44;
  longdouble lVar45;
  longdouble lVar46;
  longdouble lVar47;
  uint local_18f4;
  int local_18f0;
  uint local_18ec;
  int aiStack_18dc [3];
  sizebuf_t local_18d0;
  char local_18b9 [260];
  byte local_17b5 [6037];
  int local_20;
  
                    /* Unresolved local var: sizebuf_t send@[???]
                       Unresolved local var: byte[6037] send_buf@[???]
                       Unresolved local var: qboolean send_reliable@[???]
                       Unresolved local var: qboolean send_reliable_fragment@[???]
                       Unresolved local var: qboolean send_resending@[???]
                       Unresolved local var: int max_send_size@[???]
                       Unresolved local var: uint w1@[???]
                       Unresolved local var: uint w2@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float fRate@[???] */
  local_18d0.flags = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_18d0.buffername = "Netchan_Transmit";
  local_18d0.data = local_17b5;
  local_18d0.maxsize = 0x1795;
  local_18d0.cursize = 0;
  if (((chan->message).flags & 2) != 0) {
    pcVar9 = NET_AdrToString(chan->remote_address);
    Con_Printf("%s:Outgoing message overflow\n",pcVar9);
    goto LAB_00068a72;
  }
  uVar14 = 0;
  if (chan->last_reliable_sequence < chan->incoming_acknowledged) {
    iVar7 = chan->reliable_length;
    uVar14 = (uint)(chan->incoming_reliable_acknowledged != chan->reliable_sequence);
  }
  else {
    iVar7 = chan->reliable_length;
  }
  local_18ec = uVar14;
  if (iVar7 == 0) {
                    /* Unresolved local var: qboolean send_frag@[???]
                       Unresolved local var: fragbuf_t * pbuf@[???]
                       Unresolved local var: int[2] send_from_frag@[???]
                       Unresolved local var: int send_from_regular@[???] */
    aiStack_18dc[1] = 0;
                    /* Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: int i@[???] */
    aiStack_18dc[2] = 0;
    if (chan != (netchan_t *)0x0) {
      if ((chan->fragbufs[0] == (fragbuf_t *)0x0) &&
         (pfVar2 = chan->waitlist[0], pfVar2 != (fragbufwaiting_t *)0x0)) {
        chan->waitlist[0] = pfVar2->next;
        pfVar2->next = (fragbufwaiting_s *)0x0;
        chan->fragbufs[0] = pfVar2->fragbufs;
        chan->fragbufcount[0] = pfVar2->fragbufcount;
        Mem_Free(pfVar2);
      }
      if ((chan->fragbufs[1] == (fragbuf_t *)0x0) &&
         (pfVar2 = chan->waitlist[1], pfVar2 != (fragbufwaiting_t *)0x0)) {
        chan->waitlist[1] = pfVar2->next;
        pfVar2->next = (fragbufwaiting_s *)0x0;
        chan->fragbufs[1] = pfVar2->fragbufs;
        chan->fragbufcount[1] = pfVar2->fragbufcount;
        Mem_Free(pfVar2);
      }
    }
    iVar7 = (chan->message).cursize;
    bVar32 = chan->fragbufs[0] != (fragbuf_t *)0x0;
    if (bVar32) {
      aiStack_18dc[1] = 1;
    }
    if (chan->fragbufs[1] == (fragbuf_t *)0x0) {
      if ((iVar7 != 0) && (bVar5 = false, bVar32)) goto LAB_00068f3d;
      chan->frag_startpos[0] = 0;
      chan->reliable_fragment[0] = 0;
      chan->reliable_fragid[0] = 0;
      chan->frag_length[0] = 0;
      chan->frag_startpos[1] = 0;
      chan->reliable_fragment[1] = 0;
      chan->reliable_fragid[1] = 0;
      chan->frag_length[1] = 0;
      if ((iVar7 != 0) || (bVar32)) goto LAB_00068b8e;
    }
    else {
      aiStack_18dc[2] = 1;
      if ((iVar7 == 0) || (!bVar32)) {
        chan->reliable_fragid[0] = 0;
        chan->frag_length[0] = 0;
        chan->frag_startpos[1] = 0;
        chan->reliable_fragment[1] = 0;
        chan->reliable_fragid[1] = 0;
        chan->frag_startpos[0] = 0;
        chan->reliable_fragment[0] = 0;
        chan->frag_length[1] = 0;
LAB_00068b8e:
        chan->reliable_sequence = chan->reliable_sequence ^ 1;
        if (iVar7 == 0) {
          local_18f4 = 0x80000000;
          local_18ec = 1;
        }
        else {
          Q_memcpy(chan->reliable_buf,chan->message_buf,iVar7);
          iVar7 = (chan->message).cursize;
          (chan->message).cursize = 0;
          local_18ec = 1;
          chan->reliable_length = iVar7;
          sVar6 = (short)iVar7;
          chan->frag_startpos[0] = sVar6;
          chan->frag_startpos[1] = sVar6;
          local_18f4 = 0x80000000;
        }
        goto LAB_00068be4;
      }
      bVar5 = true;
LAB_00068f3d:
      if (0x4b0 < iVar7) {
        server = (qboolean)(chan != &cls.netchan);
        Netchan_CreateFragments_(server,chan,&chan->message);
        (chan->message).cursize = 0;
        Netchan_CreateFragments_(server,chan,&chan->message);
        (chan->message).cursize = 0;
      }
      chan->frag_startpos[0] = 0;
      chan->reliable_fragment[0] = 0;
      chan->reliable_fragid[0] = 0;
      chan->frag_length[0] = 0;
      chan->frag_startpos[1] = 0;
      chan->reliable_fragment[1] = 0;
      chan->reliable_fragid[1] = 0;
      chan->frag_length[1] = 0;
      if ((bVar5) || (bVar32)) {
        chan->reliable_sequence = chan->reliable_sequence ^ 1;
        local_18f4 = 0x80000000;
        local_18ec = 1;
        goto LAB_00068be4;
      }
    }
    local_18f4 = uVar14 << 0x1f;
LAB_00068be4:
    ppfVar30 = chan->fragbufs;
    iVar7 = 1;
    do {
                    /* Unresolved local var: int fragment_size@[???]
                       Unresolved local var: int host_framecount@[???] */
      p = *ppfVar30;
      if (p == (fragbuf_t *)0x0) {
LAB_00068f18:
        if (iVar7 == 2) goto LAB_000685ca;
      }
      else {
        iVar27 = (p->frag_message).cursize;
        if ((p->isfile != 0) && (p->isbuffer == 0)) {
          iVar27 = p->size;
        }
        if ((aiStack_18dc[iVar7] == 0) || (iVar8 = chan->reliable_length, 0x4af < iVar27 + iVar8))
        goto LAB_00068f18;
        ppfVar30[-2] = (fragbuf_t *)((uint)(ushort)ppfVar30[2] | p->bufferid << 0x10);
        if ((p->isfile != 0) && (p->isbuffer == 0)) {
                    /* Unresolved local var: FileHandle_t hfile@[???] */
          if (p->iscompressed == 0) {
            file = FS_Open(p->filename,"rb");
          }
          else {
                    /* Unresolved local var: char[260] compressedfilename@[???] */
            __snprintf_chk(local_18b9,0x104,1,0x104,"%s.ztmp",p->filename);
            file = FS_Open(local_18b9,"rb");
          }
          FS_Seek(file,p->foffset,FILESYSTEM_SEEK_HEAD);
          FS_Read((p->frag_message).data + (p->frag_message).cursize,p->size,1,file);
          piVar13 = &(p->frag_message).cursize;
          *piVar13 = *piVar13 + p->size;
          FS_Close(file);
          iVar8 = chan->reliable_length;
        }
        Q_memcpy(chan->reliable_buf + iVar8,(p->frag_message).data,(p->frag_message).cursize);
        chan->reliable_length = chan->reliable_length + (p->frag_message).cursize;
                    /* Unresolved local var: fragbuf_t * search@[???] */
        chan->frag_startpos[iVar7 + 1] = (short)(p->frag_message).cursize;
        if (ppfVar30 == (fragbuf_t **)0x0) {
          Con_Printf("Netchan_UnlinkFragment:  Asked to unlink fragment from empty list, ignored\n")
          ;
        }
        else {
          pfVar1 = *ppfVar30;
          if (*ppfVar30 == p) {
            *ppfVar30 = p->next;
            Mem_Free(p);
          }
          else {
            do {
              pfVar12 = pfVar1;
              pfVar1 = pfVar12->next;
              if (pfVar1 == (fragbuf_s *)0x0) {
                Con_Printf("Netchan_UnlinkFragment:  Couldn\'t find fragment\n");
                goto LAB_00068cce;
              }
            } while (p != pfVar1);
            pfVar12->next = p->next;
            Mem_Free(p);
          }
        }
LAB_00068cce:
        ppfVar30[-4] = (fragbuf_t *)0x1;
        if (iVar7 != 1) goto LAB_00068f18;
        chan->frag_startpos[1] = chan->frag_startpos[1] + chan->frag_length[0];
      }
      ppfVar30 = ppfVar30 + 1;
      iVar7 = iVar7 + 1;
    } while( true );
  }
  local_18f4 = uVar14 << 0x1f;
LAB_000685ca:
  uVar10 = chan->outgoing_sequence;
  uVar28 = chan->incoming_reliable_sequence << 0x1f | chan->incoming_sequence;
  if (((chan->reliable_fragment[0] == 0) && (chan->reliable_fragment[1] == 0)) || (local_18ec == 0))
  {
    chan->outgoing_sequence = uVar10 + 1;
    MSG_WriteLong(&local_18d0,local_18f4 | uVar10);
    MSG_WriteLong(&local_18d0,uVar28);
    if (local_18ec != 0) goto LAB_00068dc7;
  }
  else {
    chan->outgoing_sequence = uVar10 + 1;
    MSG_WriteLong(&local_18d0,local_18f4 | uVar10 | 0x40000000);
    psVar31 = chan->frag_startpos;
    MSG_WriteLong(&local_18d0,uVar28);
    piVar13 = chan->reliable_fragment;
    do {
      if (*piVar13 == 0) {
        MSG_WriteByte(&local_18d0,0);
      }
      else {
        MSG_WriteByte(&local_18d0,1);
        MSG_WriteLong(&local_18d0,piVar13[2]);
        MSG_WriteShort(&local_18d0,(int)*psVar31);
        MSG_WriteShort(&local_18d0,(int)psVar31[2]);
      }
      piVar13 = piVar13 + 1;
      psVar31 = psVar31 + 1;
    } while ((uint *)piVar13 != chan->reliable_fragid);
LAB_00068dc7:
    SZ_Write(&local_18d0,chan->reliable_buf,chan->reliable_length);
    chan->last_reliable_sequence = chan->outgoing_sequence + -1;
  }
  iVar7 = 0x578;
  if (uVar14 == 0) {
    iVar7 = local_18d0.maxsize;
  }
  if (iVar7 - local_18d0.cursize < length) {
    Con_DPrintf("Netchan_Transmit:  Unreliable would overfow, ignoring\n");
  }
  else {
    SZ_Write(&local_18d0,data,length);
  }
                    /* Unresolved local var: int i@[???] */
  iVar7 = local_18d0.cursize;
  if (local_18d0.cursize < 0x10) {
    do {
      iVar7 = iVar7 + 1;
      MSG_WriteByte(&local_18d0,1);
    } while (iVar7 != 0x10);
  }
  dVar3 = realtime;
  uVar14 = chan->flow[0].current;
  uVar10 = uVar14 & 0x1f;
  local_18f0 = local_18d0.cursize + 0x1c;
                    /* Unresolved local var: int flow@[???]
                       Unresolved local var: int start@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int bytes@[???]
                       Unresolved local var: float faccumulatedtime@[???]
                       Unresolved local var: flow_t * pflow@[???]
                       Unresolved local var: flowstats_t * pstat@[???]
                       Unresolved local var: flowstats_t * pprev@[???] */
  chan->flow[0].stats[uVar10].size = local_18f0;
  chan->flow[0].stats[uVar10].time = dVar3;
  chan->flow[0].current = uVar14 + 1;
  if (chan != (netchan_t *)0x0) {
    iVar7 = 0;
    pdVar29 = &chan->flow[0].nextcompute;
    iVar27 = 0;
    lVar47 = (longdouble)0;
    do {
      if (0.1 <= dVar3 - *pdVar29) {
        iVar8 = *(int *)((int)pdVar29 + -4);
        uVar14 = iVar8 - 2U & 0x1f;
        *pdVar29 = dVar3 + 0.1;
        lVar33 = (longdouble)chan->flow[iVar27].stats[uVar14].time;
        uVar28 = iVar8 - 3U & 0x1f;
        lVar34 = (longdouble)chan->flow[iVar27].stats[uVar28].time;
        uVar15 = iVar8 - 4U & 0x1f;
        lVar35 = (longdouble)chan->flow[iVar27].stats[uVar15].time;
        uVar16 = iVar8 - 5U & 0x1f;
        lVar36 = (longdouble)chan->flow[iVar27].stats[uVar16].time;
        uVar17 = iVar8 - 6U & 0x1f;
        lVar37 = (longdouble)chan->flow[iVar27].stats[uVar17].time;
        uVar18 = iVar8 - 7U & 0x1f;
        lVar38 = (longdouble)chan->flow[iVar27].stats[uVar18].time;
        uVar19 = iVar8 - 8U & 0x1f;
        lVar39 = (longdouble)chan->flow[iVar27].stats[uVar19].time;
        uVar20 = iVar8 - 9U & 0x1f;
        lVar40 = (longdouble)chan->flow[iVar27].stats[uVar20].time;
        uVar21 = iVar8 - 10U & 0x1f;
        lVar41 = (longdouble)chan->flow[iVar27].stats[uVar21].time;
        uVar22 = iVar8 - 0xbU & 0x1f;
        lVar42 = (longdouble)chan->flow[iVar27].stats[uVar22].time;
        uVar23 = iVar8 - 0xcU & 0x1f;
        lVar43 = (longdouble)chan->flow[iVar27].stats[uVar23].time;
        uVar24 = iVar8 - 0xdU & 0x1f;
        lVar44 = (longdouble)chan->flow[iVar27].stats[uVar24].time;
        uVar25 = iVar8 - 0xeU & 0x1f;
        lVar45 = (longdouble)chan->flow[iVar27].stats[uVar25].time;
        uVar26 = iVar8 - 0xfU & 0x1f;
        uVar10 = iVar8 - 0x10U & 0x1f;
        lVar46 = (longdouble)chan->flow[iVar27].stats[uVar26].time;
        iVar7 = iVar7 + chan->flow[iVar27].stats[uVar14].size +
                chan->flow[iVar27].stats[uVar28].size + chan->flow[iVar27].stats[uVar15].size +
                chan->flow[iVar27].stats[uVar16].size + chan->flow[iVar27].stats[uVar17].size +
                chan->flow[iVar27].stats[uVar18].size + chan->flow[iVar27].stats[uVar19].size +
                chan->flow[iVar27].stats[uVar20].size + chan->flow[iVar27].stats[uVar21].size +
                chan->flow[iVar27].stats[uVar22].size + chan->flow[iVar27].stats[uVar23].size +
                chan->flow[iVar27].stats[uVar24].size + chan->flow[iVar27].stats[uVar25].size +
                chan->flow[iVar27].stats[uVar26].size + chan->flow[iVar27].stats[uVar10].size;
        lVar47 = (longdouble)
                 (float)((longdouble)
                         (float)((longdouble)
                                 (float)((longdouble)
                                         (float)((longdouble)
                                                 (float)((longdouble)
                                                         (float)((longdouble)
                                                                 (float)((longdouble)
                                                                         (float)((longdouble)
                                                                                 (float)((longdouble
                                                                                         )(float)((
                                                  longdouble)
                                                  (float)((longdouble)
                                                          (float)((longdouble)
                                                                  (float)((longdouble)
                                                                          (float)((longdouble)
                                                                                  (float)(((
                                                  longdouble)
                                                  chan->flow[iVar27].stats[iVar8 - 1U & 0x1f].time -
                                                  lVar33) + lVar47) + (lVar33 - lVar34)) +
                                                  (lVar34 - lVar35)) + (lVar35 - lVar36)) +
                                                  (lVar36 - lVar37)) + (lVar37 - lVar38)) +
                                                  (lVar38 - lVar39)) + (lVar39 - lVar40)) +
                                                  (lVar40 - lVar41)) + (lVar41 - lVar42)) +
                                                  (lVar42 - lVar43)) + (lVar43 - lVar44)) +
                                        (lVar44 - lVar45)) + (lVar45 - lVar46)) +
                        (lVar46 - (longdouble)chan->flow[iVar27].stats[uVar10].time));
        lVar33 = (longdouble)0;
        if (lVar47 == lVar33) {
          *(float *)(pdVar29 + 1) = 0.0;
        }
        else {
          lVar33 = ((longdouble)iVar7 / lVar47) * (longdouble)0.0009765625;
          *(float *)(pdVar29 + 1) = (float)lVar33;
          lVar33 = (longdouble)0.33333333333333337 * lVar33;
        }
        *(float *)((int)pdVar29 + 0xc) =
             (float)((longdouble)0.6666666666666666 * (longdouble)*(float *)((int)pdVar29 + 0xc) +
                    lVar33);
      }
      iVar27 = iVar27 + 1;
      pdVar29 = (double *)((int)pdVar29 + 0x194);
    } while (iVar27 != 2);
  }
  if (cls.demoplayback == false) {
    COM_Munge2(local_18d0.data + 8,local_18d0.cursize + -8,chan->outgoing_sequence - 1U & 0xff);
    if (g_modfuncs.m_pfnProcessOutgoingNet != (PFN_PROCESSOUTGOINGNET)0x0) {
      (*g_modfuncs.m_pfnProcessOutgoingNet)(chan,&local_18d0);
    }
    NET_SendPacket(chan->sock,local_18d0.cursize,local_18d0.data,chan->remote_address);
    local_18f0 = local_18d0.cursize + 0x1c;
    dVar3 = realtime;
  }
  if (((sv.active == false) || (sv_lan.value == 0.0)) || ((double)sv_lan_rate.value <= 1000.0)) {
    dVar4 = (double)(1.0 / (float)chan->rate);
  }
  else {
    dVar4 = 1.0 / (double)sv_lan_rate.value;
  }
  if (dVar3 <= chan->cleartime) {
    dVar3 = chan->cleartime;
  }
  chan->cleartime = (double)local_18f0 * dVar4 + dVar3;
  if ((net_showpackets.value != 0.0) && (net_showpackets.value != 2.0)) {
                    /* Unresolved local var: char c@[???]
                       Unresolved local var: int mask@[???] */
    if (chan == &cls.netchan) {
      uVar11 = 99;
      dVar3 = cl.time;
    }
    else {
      uVar11 = 0x73;
      dVar3 = sv.time;
    }
    Con_Printf(" %c --> sz=%i seq=%i ack=%i rel=%i tm=%f\n",uVar11,local_18d0.cursize,
               chan->outgoing_sequence + -1,chan->incoming_sequence,local_18ec,
               SUB84((double)(float)dVar3,0),(int)((ulonglong)(double)(float)dVar3 >> 0x20));
  }
LAB_00068a72:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Netchan_UnlinkFragment  @ 00066510
void Netchan_UnlinkFragment(fragbuf_t *buf,fragbuf_t **list)

{
  fragbuf_t *p;
  fragbuf_t *pfVar1;
  
                    /* Unresolved local var: fragbuf_t * search@[???] */
  if (list == (fragbuf_t **)0x0) {
    Con_Printf("Netchan_UnlinkFragment:  Asked to unlink fragment from empty list, ignored\n");
    return;
  }
  p = *list;
  if (p != buf) {
    do {
      pfVar1 = p;
      p = pfVar1->next;
      if (p == (fragbuf_s *)0x0) {
        Con_Printf("Netchan_UnlinkFragment:  Couldn\'t find fragment\n");
        return;
      }
    } while (buf != p);
    pfVar1->next = buf->next;
    Mem_Free(buf);
    return;
  }
  *list = p->next;
  Mem_Free(p);
  return;
}


// Netchan_UpdateFlow  @ 00066cc0
void Netchan_UpdateFlow(netchan_t *chan)

{
  int iVar1;
  double dVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  double *pdVar19;
  int iVar20;
  longdouble lVar21;
  longdouble lVar22;
  longdouble lVar23;
  longdouble lVar24;
  longdouble lVar25;
  longdouble lVar26;
  longdouble lVar27;
  longdouble lVar28;
  longdouble lVar29;
  longdouble lVar30;
  longdouble lVar31;
  longdouble lVar32;
  longdouble lVar33;
  longdouble lVar34;
  longdouble lVar35;
  
                    /* Unresolved local var: int flow@[???]
                       Unresolved local var: int start@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int bytes@[???]
                       Unresolved local var: float faccumulatedtime@[???]
                       Unresolved local var: flow_t * pflow@[???]
                       Unresolved local var: flowstats_t * pstat@[???]
                       Unresolved local var: flowstats_t * pprev@[???] */
  dVar2 = realtime;
  if (chan != (netchan_t *)0x0) {
    pdVar19 = &chan->flow[0].nextcompute;
    iVar3 = 0;
    lVar35 = (longdouble)0;
    iVar20 = 0;
    do {
      if (0.1 <= dVar2 - *pdVar19) {
        iVar1 = *(int *)((int)pdVar19 + -4);
        uVar5 = iVar1 - 2U & 0x1f;
        *pdVar19 = dVar2 + 0.1;
        lVar21 = (longdouble)chan->flow[iVar20].stats[uVar5].time;
        uVar6 = iVar1 - 3U & 0x1f;
        lVar22 = (longdouble)chan->flow[iVar20].stats[uVar6].time;
        uVar7 = iVar1 - 4U & 0x1f;
        lVar23 = (longdouble)chan->flow[iVar20].stats[uVar7].time;
        uVar8 = iVar1 - 5U & 0x1f;
        lVar24 = (longdouble)chan->flow[iVar20].stats[uVar8].time;
        uVar9 = iVar1 - 6U & 0x1f;
        lVar25 = (longdouble)chan->flow[iVar20].stats[uVar9].time;
        uVar10 = iVar1 - 7U & 0x1f;
        lVar26 = (longdouble)chan->flow[iVar20].stats[uVar10].time;
        uVar11 = iVar1 - 8U & 0x1f;
        lVar27 = (longdouble)chan->flow[iVar20].stats[uVar11].time;
        uVar12 = iVar1 - 9U & 0x1f;
        lVar28 = (longdouble)chan->flow[iVar20].stats[uVar12].time;
        uVar13 = iVar1 - 10U & 0x1f;
        lVar29 = (longdouble)chan->flow[iVar20].stats[uVar13].time;
        uVar14 = iVar1 - 0xbU & 0x1f;
        lVar30 = (longdouble)chan->flow[iVar20].stats[uVar14].time;
        uVar15 = iVar1 - 0xcU & 0x1f;
        lVar31 = (longdouble)chan->flow[iVar20].stats[uVar15].time;
        uVar16 = iVar1 - 0xdU & 0x1f;
        lVar32 = (longdouble)chan->flow[iVar20].stats[uVar16].time;
        uVar17 = iVar1 - 0xeU & 0x1f;
        lVar33 = (longdouble)chan->flow[iVar20].stats[uVar17].time;
        uVar18 = iVar1 - 0xfU & 0x1f;
        uVar4 = iVar1 - 0x10U & 0x1f;
        lVar34 = (longdouble)chan->flow[iVar20].stats[uVar18].time;
        iVar3 = iVar3 + chan->flow[iVar20].stats[uVar5].size + chan->flow[iVar20].stats[uVar6].size
                + chan->flow[iVar20].stats[uVar7].size + chan->flow[iVar20].stats[uVar8].size +
                chan->flow[iVar20].stats[uVar9].size + chan->flow[iVar20].stats[uVar10].size +
                chan->flow[iVar20].stats[uVar11].size + chan->flow[iVar20].stats[uVar12].size +
                chan->flow[iVar20].stats[uVar13].size + chan->flow[iVar20].stats[uVar14].size +
                chan->flow[iVar20].stats[uVar15].size + chan->flow[iVar20].stats[uVar16].size +
                chan->flow[iVar20].stats[uVar17].size + chan->flow[iVar20].stats[uVar18].size +
                chan->flow[iVar20].stats[uVar4].size;
        lVar35 = (longdouble)
                 (float)((longdouble)
                         (float)((longdouble)
                                 (float)((longdouble)
                                         (float)((longdouble)
                                                 (float)((longdouble)
                                                         (float)((longdouble)
                                                                 (float)((longdouble)
                                                                         (float)((longdouble)
                                                                                 (float)((longdouble
                                                                                         )(float)((
                                                  longdouble)
                                                  (float)((longdouble)
                                                          (float)((longdouble)
                                                                  (float)((longdouble)
                                                                          (float)((longdouble)
                                                                                  (float)(((
                                                  longdouble)
                                                  chan->flow[iVar20].stats[iVar1 - 1U & 0x1f].time -
                                                  lVar21) + lVar35) + (lVar21 - lVar22)) +
                                                  (lVar22 - lVar23)) + (lVar23 - lVar24)) +
                                                  (lVar24 - lVar25)) + (lVar25 - lVar26)) +
                                                  (lVar26 - lVar27)) + (lVar27 - lVar28)) +
                                                  (lVar28 - lVar29)) + (lVar29 - lVar30)) +
                                                  (lVar30 - lVar31)) + (lVar31 - lVar32)) +
                                        (lVar32 - lVar33)) + (lVar33 - lVar34)) +
                        (lVar34 - (longdouble)chan->flow[iVar20].stats[uVar4].time));
        lVar21 = (longdouble)0;
        if (lVar35 == lVar21) {
          *(float *)(pdVar19 + 1) = 0.0;
        }
        else {
          lVar21 = ((longdouble)iVar3 / lVar35) * (longdouble)0.0009765625;
          *(float *)(pdVar19 + 1) = (float)lVar21;
          lVar21 = (longdouble)0.33333333333333337 * lVar21;
        }
        *(float *)((int)pdVar19 + 0xc) =
             (float)((longdouble)0.6666666666666666 * (longdouble)*(float *)((int)pdVar19 + 0xc) +
                    lVar21);
      }
      iVar20 = iVar20 + 1;
      pdVar19 = (double *)((int)pdVar19 + 0x194);
    } while (iVar20 != 2);
  }
  return;
}


// Netchan_UpdateProgress  @ 0006a460
void Netchan_UpdateProgress(netchan_t *chan)

{
  byte *pbVar1;
  byte bVar2;
  ushort uVar3;
  float fVar4;
  float fVar5;
  fragbuf_s *pfVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  fragbuf_t *pfVar10;
  byte *pbVar11;
  int iVar12;
  fragbuf_t **ppfVar13;
  int iVar14;
  int in_GS_OFFSET;
  byte local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int total@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float bestpercent@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  scr_downloading.value = -1.0;
  gDownloadFile[0] = '\0';
  if ((net_drawslider.value != 1.0) &&
     (fVar4 = scr_downloading.value, chan->incomingbufs[1] == (fragbuf_t *)0x0)) {
LAB_0006a514:
    scr_downloading.value = fVar4;
    if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  ppfVar13 = chan->incomingbufs + 1;
  pfVar10 = *ppfVar13;
  iVar14 = 0;
  iVar12 = 0;
  fVar5 = 0.0;
  if (pfVar10 == (fragbuf_t *)0x0) goto LAB_0006a5ce;
  while( true ) {
    uVar3 = (ushort)pfVar10->bufferid;
    pfVar6 = pfVar10;
    do {
      pfVar6 = pfVar6->next;
      iVar12 = iVar12 + 1;
    } while (pfVar6 != (fragbuf_s *)0x0);
    fVar4 = fVar5;
                    /* Unresolved local var: float percent@[???] */
    if ((uVar3 != 0) && (fVar4 = ((float)iVar12 * 100.0) / (float)uVar3, fVar4 <= fVar5)) {
      fVar4 = fVar5;
    }
    if (iVar14 == 0) break;
    while( true ) {
      if (iVar14 == -1) goto LAB_0006a514;
LAB_0006a5c0:
      ppfVar13 = ppfVar13 + -1;
      pfVar10 = *ppfVar13;
      iVar14 = iVar14 + -1;
      fVar5 = fVar4;
      if (pfVar10 != (fragbuf_t *)0x0) break;
LAB_0006a5ce:
      fVar4 = fVar5;
                    /* Unresolved local var: float percent@[???] */
      if (((ppfVar13[-6] != (fragbuf_t *)0x0) && (ppfVar13[-4] != (fragbuf_t *)0x0)) &&
         (fVar4 = ((float)ppfVar13[-6]->bufferid * 100.0) / (float)(int)ppfVar13[-4], fVar4 <= fVar5
         )) {
        fVar4 = fVar5;
      }
    }
  }
                    /* Unresolved local var: char[1024] sz@[???]
                       Unresolved local var: char * in@[???]
                       Unresolved local var: char * out@[???]
                       Unresolved local var: int len@[???] */
  pbVar11 = (pfVar10->frag_message).data;
  pbVar1 = pbVar11 + 0x81;
  pbVar9 = local_420;
  do {
    bVar2 = *pbVar11;
    pbVar8 = pbVar9;
    if (bVar2 == '\0') break;
    pbVar11 = pbVar11 + 1;
    pbVar8 = pbVar9 + 1;
    *pbVar9 = bVar2;
    pbVar9 = pbVar8;
  } while (pbVar1 != pbVar11);
  *pbVar8 = '\0';
  iVar7 = Q_strlen((char *)local_420);
  if (iVar7 < 1) goto LAB_0006a5c0;
  if ((local_420[0] == '!') && (iVar7 = Q_strncmp((char *)local_420,"!ModuleC.dll",0xb), iVar7 != 0)
     ) goto LAB_0006a5c0;
  Q_strncpy(gDownloadFile,(char *)local_420,0xff);
  gDownloadFile[0xff] = '\0';
  goto LAB_0006a5c0;
}


// Netchan_Validate  @ 00067250
qboolean Netchan_Validate(netchan_t *chan,qboolean *frag_message,uint *fragid,int *frag_offset,
                         int *frag_length)

{
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int buffer@[???]
                       Unresolved local var: int count@[???] */
  if ((*frag_message == false) ||
     ((((*fragid < 0x61a90000 && ((*fragid & 0xffff) < 0x61a9)) && ((uint)*frag_length < 0x801)) &&
      ((uint)*frag_offset < 0x4001)))) {
    if (frag_message[1] == false) {
      return true;
    }
    if ((((fragid[1] & 0xffff) < 0x61a9) && (fragid[1] < 0x61a90000)) &&
       ((uint)frag_length[1] < 0x801)) {
      return (uint)((uint)frag_offset[1] < 0x4001);
    }
  }
  return false;
}


