// Netchan_AddBufferToList  @ 000878c0
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


// Netchan_AddFragbufToTail  @ 00087950
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


// Netchan_AllocFragbuf  @ 00087910
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


// Netchan_CanPacket  @ 00085ed0
qboolean Netchan_CanPacket(netchan_t *chan)

{
  if ((net_chokeloopback.value == 0.0) && ((chan->remote_address).type == NA_LOOPBACK)) {
    chan->cleartime = realtime;
    return true;
  }
  return (uint)(chan->cleartime < realtime);
}


// Netchan_CheckForCompletion  @ 00086ec0
void Netchan_CheckForCompletion(netchan_t *chan,int stream,int intotalbuffers)

{
  netadr_t a;
  char *src;
  int iVar1;
  fragbuf_t *pfVar2;
  uint uVar3;
  char local_bc [128];
  char local_3c [44];
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int id@[???]
                       Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: char[32] szCommand@[???] */
  pfVar2 = chan->incomingbufs[stream];
  if (pfVar2 != (fragbuf_t *)0x0) {
    uVar3 = 0;
    if (chan == &cls.netchan) {
      do {
        uVar3 = uVar3 + 1;
        if (*(ushort *)((int)&pfVar2->bufferid + 2) != uVar3) {
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
            Q_strncpy_s(local_bc,src,0x80);
                    /* Unresolved local var: char __r0@[???]
                       Unresolved local var: char __r1@[???]
                       Unresolved local var: char __r2@[???]
                       Unresolved local var: size_t __result@[???] */
            iVar1 = 0;
            while (((local_bc[0] != '\0' && (local_bc[0] != ';')) && (local_bc[0] != '\n'))) {
              iVar1 = iVar1 + 1;
              local_bc[0] = local_bc[iVar1];
            }
            local_bc[iVar1] = '\0';
            snprintf(local_3c,0x20,"listen %s\n",local_bc);
            Cbuf_AddText(local_3c);
            return;
          }
          Con_Printf(
                    "Netchan_CheckForCompletion:  Lost/dropped fragment would cause stall, retrying connection\n"
                    );
          Cbuf_AddText("retry\n");
        }
        pfVar2 = pfVar2->next;
      } while (pfVar2 != (fragbuf_s *)0x0);
    }
    else {
      do {
        pfVar2 = pfVar2->next;
        uVar3 = uVar3 + 1;
      } while (pfVar2 != (fragbuf_s *)0x0);
    }
    if (uVar3 == intotalbuffers) {
      chan->incomingready[stream] = true;
      return;
    }
  }
  return;
}


// Netchan_Clear  @ 00085c60
void Netchan_Clear(netchan_t *chan)

{
  void *p;
  
                    /* Unresolved local var: int i@[???] */
  Netchan_ClearFragments(chan);
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
  chan->reliable_fragment[1] = 0;
  chan->fragbufcount[1] = 0;
  chan->frag_startpos[1] = 0;
  chan->frag_length[1] = 0;
  chan->incomingready[1] = false;
  p = chan->tempbuffer;
  *(undefined4 *)&chan->cleartime = 0;
  *(undefined4 *)((int)&chan->cleartime + 4) = 0;
  chan->incomingready[0] = false;
  chan->reliable_fragid[1] = 0;
  if (p != (void *)0x0) {
    Mem_Free(p);
    chan->tempbuffer = (void *)0x0;
  }
  chan->tempbuffersize = 0;
  return;
}


// Netchan_ClearFragbufs  @ 00085b30
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


// Netchan_ClearFragments  @ 00085b70
void Netchan_ClearFragments(netchan_t *chan)

{
  fragbufwaiting_s *pfVar1;
  fragbuf_s *pfVar2;
  fragbufwaiting_t *p;
  fragbuf_t *pfVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  iVar4 = 0;
                    /* Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: fragbufwaiting_t * next@[???]
                       Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
  do {
    p = chan->waitlist[0];
    while (p != (fragbufwaiting_t *)0x0) {
      pfVar1 = p->next;
                    /* Unresolved local var: fragbuf_t * buf@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
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
    chan->waitlist[0] = (fragbufwaiting_t *)0x0;
                    /* Unresolved local var: fragbuf_t * buf@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
    pfVar3 = chan->fragbufs[0];
    while (pfVar3 != (fragbuf_t *)0x0) {
      pfVar2 = pfVar3->next;
      Mem_Free(pfVar3);
      pfVar3 = pfVar2;
    }
    chan->fragbufs[0] = (fragbuf_t *)0x0;
    SZ_Clear(&net_message);
    msg_readcount = 0;
    pfVar3 = chan->incomingbufs[0];
    while (pfVar3 != (fragbuf_t *)0x0) {
      pfVar2 = pfVar3->next;
      Mem_Free(pfVar3);
      pfVar3 = pfVar2;
    }
    iVar4 = iVar4 + 1;
    chan->incomingbufs[0] = (fragbuf_t *)0x0;
    chan->incomingready[0] = false;
    chan = (netchan_t *)&chan->remote_address;
  } while (iVar4 != 2);
  return;
}


// Netchan_CompressPacket  @ 00088d70
qboolean Netchan_CompressPacket(sizebuf_t *chan)

{
  return false;
}


// Netchan_CopyFileFragments  @ 00088480
qboolean Netchan_CopyFileFragments(netchan_t *chan)

{
  fragbuf_s *pfVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  qboolean qVar5;
  void *p;
  int count;
  FileHandle_t file;
  void *pInput;
  fragbuf_t *pfVar6;
  fragbuf_s *pfVar7;
  int iVar8;
  size_t size;
  bool bVar9;
  char local_24c [259];
  undefined1 local_149;
  char local_144 [260];
  char local_40 [31];
  undefined1 local_21;
  size_t local_20 [4];
  
                    /* Unresolved local var: char[260] filename@[???]
                       Unresolved local var: char[32] compressor@[???]
                       Unresolved local var: qboolean bCompressed@[???]
                       Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???]
                       Unresolved local var: int nsize@[???]
                       Unresolved local var: int uncompressedSize@[???]
                       Unresolved local var: uchar * buffer@[???]
                       Unresolved local var: int pos@[???] */
  if (chan->incomingready[1] == false) {
    return false;
  }
  pfVar6 = chan->incomingbufs[1];
  if (pfVar6 == (fragbuf_t *)0x0) {
    Con_Printf("Netchan_CopyFileFragments:  Called with no fragments readied\n");
    chan->incomingready[1] = false;
    return false;
  }
  SZ_Clear(&net_message);
  MSG_BeginReading();
  SZ_Write(&net_message,(pfVar6->frag_message).data,(pfVar6->frag_message).cursize);
  pcVar2 = MSG_ReadString();
  Q_strncpy(local_24c,pcVar2,0x103);
  local_149 = 0;
  pcVar2 = MSG_ReadString();
  Q_strncpy(local_40,pcVar2,0x1f);
  local_21 = 0;
  iVar3 = strcasecmp(local_40,"bz2");
  local_20[0] = MSG_ReadLong();
  iVar4 = Q_strlen(local_24c);
  if (iVar4 < 1) {
    Con_Printf("File fragment received with no filename\nFlushing input queue\n");
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
    SZ_Clear(&net_message);
    msg_readcount = 0;
    pfVar6 = chan->incomingbufs[1];
    while (pfVar6 != (fragbuf_t *)0x0) {
      pfVar7 = pfVar6->next;
      Mem_Free(pfVar6);
      pfVar6 = pfVar7;
    }
  }
  else {
    pcVar2 = Q_strstr(local_24c,"..");
    if (pcVar2 == (char *)0x0) {
      if ((local_24c[0] == '!') || (qVar5 = IsSafeFileToDownload(local_24c), qVar5 != false)) {
        if ((cls.state != ca_dedicated) || (local_24c[0] == '!')) {
          Q_strncpy(chan->incomingfilename,local_24c,0x103);
          chan->incomingfilename[0x103] = '\0';
          if ((local_24c[0] == '!') || (iVar4 = FS_FileExists(local_24c), iVar4 == 0)) {
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
            iVar4 = 0;
            do {
              iVar8 = (pfVar6->frag_message).cursize + iVar4;
              bVar9 = chan->incomingbufs[1] != pfVar6;
              pfVar6 = pfVar6->next;
              iVar4 = iVar8 - msg_readcount;
              if (bVar9) {
                iVar4 = iVar8;
              }
            } while (pfVar6 != (fragbuf_s *)0x0);
            p = Mem_ZeroMalloc(iVar4 + 1U);
            if (p == (void *)0x0) {
              Con_Printf("Buffer allocation failed on %i bytes\n",iVar4 + 1U);
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
              SZ_Clear(&net_message);
              msg_readcount = 0;
              pfVar6 = chan->incomingbufs[1];
              while (pfVar6 != (fragbuf_t *)0x0) {
                pfVar7 = pfVar6->next;
                Mem_Free(pfVar6);
                pfVar6 = pfVar7;
              }
              goto LAB_000885b0;
            }
            pfVar6 = chan->incomingbufs[1];
            size = 0;
            pfVar7 = pfVar6;
            if (pfVar6 != (fragbuf_t *)0x0) {
              while( true ) {
                iVar8 = msg_readcount;
                pfVar1 = pfVar7->next;
                if (pfVar7 == pfVar6) {
                  count = (pfVar7->frag_message).cursize - msg_readcount;
                  (pfVar7->frag_message).cursize = count;
                  Q_memcpy((void *)((int)p + size),(pfVar7->frag_message).data + iVar8,count);
                }
                else {
                  Q_memcpy((void *)((int)p + size),(pfVar7->frag_message).data,
                           (pfVar7->frag_message).cursize);
                }
                size = size + (pfVar7->frag_message).cursize;
                Mem_Free(pfVar7);
                if (pfVar1 == (fragbuf_s *)0x0) break;
                pfVar6 = chan->incomingbufs[1];
                pfVar7 = pfVar1;
              }
            }
            pInput = p;
            if (iVar3 == 0) {
                    /* Unresolved local var: uchar * uncompressedBuffer@[???] */
              pInput = Mem_Malloc(local_20[0]);
              Con_DPrintf("Decompressing file %s (%d -> %d)\n",local_24c,iVar4,local_20[0]);
              BZ2_bzBuffToBuffDecompress(pInput,local_20,p,iVar4,1,0);
              Mem_Free(p);
              size = local_20[0];
            }
            if (local_24c[0] == '!') {
              if (chan->tempbuffer != (void *)0x0) {
                Con_DPrintf("Netchan_CopyFragments:  Freeing holdover tempbuffer\n");
                Mem_Free(chan->tempbuffer);
              }
              chan->tempbuffer = pInput;
              chan->tempbuffersize = size;
            }
            else {
              strncpy(local_144,local_24c,0x104);
              COM_FixSlashes(local_144);
              pcVar2 = strrchr(local_144,0x2f);
              if (pcVar2 != (char *)0x0) {
                *pcVar2 = '\0';
                FS_CreateDirHierarchy(local_144,"GAMEDOWNLOAD");
              }
              file = FS_OpenPathID(local_24c,"wb","GAMEDOWNLOAD");
              if (file == (FileHandle_t)0x0) {
                Con_Printf("File open failed %s\n",local_24c);
                SZ_Clear(&net_message);
                msg_readcount = 0;
                pfVar6 = chan->incomingbufs[1];
                while (pfVar6 != (fragbuf_t *)0x0) {
                  pfVar7 = pfVar6->next;
                  Mem_Free(pfVar6);
                  pfVar6 = pfVar7;
                }
                goto LAB_000885b0;
              }
              Sys_Printf("COM_WriteFile: %s\n");
              FS_Write(pInput,size,1,file);
              FS_Close(file);
              Mem_Free(pInput);
            }
            SZ_Clear(&net_message);
            msg_readcount = 0;
          }
          else {
            Con_Printf("Can\'t download %s, already exists\n",local_24c);
            SZ_Clear(&net_message);
            msg_readcount = 0;
            pfVar6 = chan->incomingbufs[1];
            while (pfVar6 != (fragbuf_t *)0x0) {
              pfVar7 = pfVar6->next;
              Mem_Free(pfVar6);
              pfVar6 = pfVar7;
            }
          }
          chan->incomingbufs[1] = (fragbuf_t *)0x0;
          chan->incomingready[1] = false;
          return true;
        }
        Con_Printf("File fragment received with bad path, ignoring (2)\n");
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
        SZ_Clear(&net_message);
        msg_readcount = 0;
        pfVar6 = chan->incomingbufs[1];
        while (pfVar6 != (fragbuf_t *)0x0) {
          pfVar7 = pfVar6->next;
          Mem_Free(pfVar6);
          pfVar6 = pfVar7;
        }
      }
      else {
        Con_Printf("File fragment received with bad path, ignoring\n");
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
        SZ_Clear(&net_message);
        msg_readcount = 0;
        pfVar6 = chan->incomingbufs[1];
        while (pfVar6 != (fragbuf_t *)0x0) {
          pfVar7 = pfVar6->next;
          Mem_Free(pfVar6);
          pfVar6 = pfVar7;
        }
      }
    }
    else {
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
      Con_Printf("File fragment received with relative path, ignoring\n");
      SZ_Clear(&net_message);
      msg_readcount = 0;
      pfVar6 = chan->incomingbufs[1];
      while (pfVar6 != (fragbuf_t *)0x0) {
        pfVar7 = pfVar6->next;
        Mem_Free(pfVar6);
        pfVar6 = pfVar7;
      }
    }
  }
LAB_000885b0:
                    /* Unresolved local var: FileHandle_t handle@[???]
                       Unresolved local var: char[260] filedir@[???]
                       Unresolved local var: char * pszFileName@[???]
                       Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
  chan->incomingbufs[1] = (fragbuf_t *)0x0;
  chan->incomingready[1] = false;
  return false;
}


// Netchan_CopyNormalFragments  @ 00088250
qboolean Netchan_CopyNormalFragments(netchan_t *chan)

{
  undefined2 uVar1;
  fragbuf_s *pfVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  qboolean qVar8;
  fragbuf_t *p;
  byte bVar9;
  uint uStack_10030;
  byte bStack_10020;
  byte abStack_1001f [65535];
  uint local_20 [4];
  
                    /* Unresolved local var: qboolean bSuccess@[???]
                       Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: fragbuf_t * n@[???] */
  bVar9 = 0;
  qVar8 = false;
  if (chan->incomingready[0] != false) {
    p = chan->incomingbufs[0];
    if (p == (fragbuf_t *)0x0) {
      Con_Printf("Netchan_CopyNormalFragments:  Called with no fragments readied\n");
      chan->incomingready[0] = false;
    }
    else {
      qVar8 = true;
      SZ_Clear(&net_message);
      MSG_BeginReading();
LAB_000882ae:
      do {
        pfVar2 = p->next;
        if (qVar8 != false) {
          qVar8 = SZ_HasSpace(&net_message,(p->frag_message).cursize);
          if (qVar8 != false) {
            qVar8 = true;
            SZ_Write(&net_message,(p->frag_message).data,(p->frag_message).cursize);
            Mem_Free(p);
            p = pfVar2;
            if (pfVar2 == (fragbuf_s *)0x0) break;
            goto LAB_000882ae;
          }
          qVar8 = false;
          SZ_Clear(&net_message);
        }
        Mem_Free(p);
        p = pfVar2;
      } while (pfVar2 != (fragbuf_s *)0x0);
      if ((((*net_message.data == 'B') && (net_message.data[1] == 'Z')) &&
          (net_message.data[2] == '2')) && (net_message.data[3] == '\0')) {
                    /* Unresolved local var: uchar[65536] uncompressed@[???]
                       Unresolved local var: uint uncompressedSize@[???] */
        local_20[0] = 0x10000;
        pbVar4 = &bStack_10020;
        BZ2_bzBuffToBuffDecompress
                  (pbVar4,local_20,net_message.data + 4,net_message.cursize + -4,1,0);
        pbVar7 = net_message.data;
        uStack_10030 = local_20[0];
        if (7 < local_20[0]) {
          if (((uint)net_message.data & 1) != 0) {
            *net_message.data = bStack_10020;
            pbVar7 = pbVar7 + 1;
            pbVar4 = abStack_1001f;
            uStack_10030 = local_20[0] - 1;
          }
          if (((uint)pbVar7 & 2) != 0) {
            uVar1 = *(undefined2 *)pbVar4;
            pbVar4 = pbVar4 + 2;
            *(undefined2 *)pbVar7 = uVar1;
            pbVar7 = pbVar7 + 2;
            uStack_10030 = uStack_10030 - 2;
          }
          if (((uint)pbVar7 & 4) != 0) {
            uVar3 = *(undefined4 *)pbVar4;
            pbVar4 = pbVar4 + 4;
            *(undefined4 *)pbVar7 = uVar3;
            pbVar7 = pbVar7 + 4;
            uStack_10030 = uStack_10030 - 4;
          }
          for (uVar6 = uStack_10030 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined4 *)pbVar7 = *(undefined4 *)pbVar4;
            pbVar4 = pbVar4 + ((uint)bVar9 * -2 + 1) * 4;
            pbVar7 = pbVar7 + (uint)bVar9 * -8 + 4;
          }
          uStack_10030 = uStack_10030 & 3;
        }
        iVar5 = 0;
        if ((uStack_10030 & 4) != 0) {
          *(undefined4 *)pbVar7 = *(undefined4 *)pbVar4;
          iVar5 = 4;
        }
        if ((uStack_10030 & 2) != 0) {
          *(undefined2 *)(pbVar7 + iVar5) = *(undefined2 *)(pbVar4 + iVar5);
          iVar5 = iVar5 + 2;
        }
        if ((uStack_10030 & 1) != 0) {
          pbVar7[iVar5] = pbVar4[iVar5];
        }
        net_message.cursize = local_20[0];
      }
      chan->incomingbufs[0] = (fragbuf_t *)0x0;
      chan->incomingready[0] = false;
    }
  }
  return qVar8;
}


// Netchan_CreateFileFragments  @ 00087d00
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
  fragbufwaiting_s *pfVar8;
  fragbuf_s *pfVar9;
  char *pcVar10;
  void *pOutput;
  void *pInput;
  FileHandle_t file;
  fragbuf_t *pfVar11;
  fragbufwaiting_t *pfVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int local_140;
  int local_138;
  uint local_134;
  char local_124 [260];
  uint local_20 [4];
  
                    /* Unresolved local var: fragbuf_t * buf@[DW_OP_reg0(EAX)]
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
  uVar4 = (*chan->pfnNetchan_Blocksize)(chan->connection_status);
  snprintf(local_124,0x104,"%s.ztmp",filename);
  iVar5 = FS_GetFileTime(local_124);
  iVar6 = FS_GetFileTime(filename);
  if ((iVar5 < iVar6) || (pvVar7 = FS_Open(local_124,"rb"), pvVar7 == (FileHandle_t)0x0)) {
    pvVar7 = FS_Open(filename,"rb");
    if (pvVar7 == (FileHandle_t)0x0) goto LAB_000880a4;
    local_134 = FS_Size(pvVar7);
    if (sv_filetransfermaxsize.value < (float)(int)local_134) goto LAB_00088049;
    uVar13 = local_134;
    if (sv_filetransfercompression.value == 0.0) {
      local_138 = 0;
    }
    else {
                    /* Unresolved local var: uchar * uncompressed@[???]
                       Unresolved local var: uchar * compressed@[???]
                       Unresolved local var: int compressedSize@[???] */
      pOutput = Mem_Malloc(local_134);
      pInput = Mem_Malloc(local_134);
      local_20[0] = local_134;
      FS_Read(pOutput,local_134,1,pvVar7);
      iVar14 = BZ2_bzBuffToBuffCompress(pInput,local_20,pOutput,local_134,9,0,0x1e);
      if ((iVar14 == 0) && (file = FS_Open(local_124,"wb"), file != (FileHandle_t)0x0)) {
        Con_DPrintf("Creating compressed version of file %s (%d -> %d)\n",filename,local_134,
                    local_20[0]);
        FS_Write(pInput,local_20[0],1,file);
        FS_Close(file);
        local_138 = 1;
        uVar13 = local_20[0];
      }
      else {
                    /* Unresolved local var: FileHandle_t destFile@[???] */
        local_138 = 0;
      }
      Mem_Free(pOutput);
      Mem_Free(pInput);
    }
    FS_Close(pvVar7);
  }
  else {
    uVar13 = FS_Size(pvVar7);
    FS_Close(pvVar7);
    pvVar7 = FS_Open(filename,"rb");
    if (pvVar7 == (FileHandle_t)0x0) {
LAB_000880a4:
      Con_Printf("Warning:  Unable to open %s for transfer\n",filename);
      return 0;
    }
    local_134 = FS_Size(pvVar7);
    if (sv_filetransfermaxsize.value < (float)(int)local_134) {
LAB_00088049:
      FS_Close(pvVar7);
      pcVar10 = NET_AdrToString(chan->remote_address);
      Con_Printf("Warning:  File %s is too big to transfer from host %s\n",filename,pcVar10);
      return 0;
    }
    FS_Close(pvVar7);
    local_138 = 1;
  }
  pfVar8 = Mem_ZeroMalloc(0xc);
  if (0 < (int)uVar13) {
    bVar3 = true;
    iVar14 = 1;
    local_140 = 0;
    while( true ) {
                    /* Unresolved local var: fragbuf_t * buf@[???] */
      uVar15 = uVar4;
      if ((int)uVar13 <= (int)uVar4) {
        uVar15 = uVar13;
      }
      pfVar9 = Mem_ZeroMalloc(0x6ac);
      (pfVar9->frag_message).data = pfVar9->frag_message_buf;
      buf = &pfVar9->frag_message;
      pfVar9->bufferid = iVar14;
      iVar14 = iVar14 + 1;
      (pfVar9->frag_message).cursize = 0;
      (pfVar9->frag_message).maxsize = 0x578;
      (pfVar9->frag_message).buffername = "Frag Buffer Alloc\'d";
      pfVar9->next = (fragbuf_s *)0x0;
      SZ_Clear(buf);
      if (bVar3) {
        MSG_WriteString(buf,filename);
        if (local_138 == 0) {
          MSG_WriteString(buf,"uncompressed");
        }
        else {
          MSG_WriteString(buf,"bz2");
        }
        MSG_WriteLong(buf,local_134);
        uVar15 = uVar15 - (pfVar9->frag_message).cursize;
      }
      uVar13 = uVar13 - uVar15;
      pfVar9->isfile = 1;
      pfVar9->size = uVar15;
      pfVar9->foffset = local_140;
      pfVar9->iscompressed = local_138;
      Q_strncpy(pfVar9->filename,filename,0x103);
      local_140 = local_140 + uVar15;
      pfVar9->filename[0x103] = '\0';
                    /* Unresolved local var: fragbuf_t * p@[???] */
      pfVar9->next = (fragbuf_s *)0x0;
      pfVar8->fragbufcount = pfVar8->fragbufcount + 1;
      pfVar1 = pfVar8->fragbufs;
      if (pfVar8->fragbufs == (fragbuf_t *)0x0) {
        pfVar8->fragbufs = pfVar9;
      }
      else {
        do {
          pfVar11 = pfVar1;
          pfVar1 = pfVar11->next;
        } while (pfVar1 != (fragbuf_s *)0x0);
        pfVar11->next = pfVar9;
      }
      if ((int)uVar13 < 1) break;
      bVar3 = false;
    }
  }
  pfVar2 = chan->waitlist[1];
  if (chan->waitlist[1] == (fragbufwaiting_t *)0x0) {
    chan->waitlist[1] = pfVar8;
    return 1;
  }
  do {
    pfVar12 = pfVar2;
    pfVar2 = pfVar12->next;
  } while (pfVar2 != (fragbufwaiting_s *)0x0);
  pfVar12->next = pfVar8;
  return 1;
}


// Netchan_CreateFileFragmentsFromBuffer  @ 00087a20
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
  fragbufwaiting_s *pfVar6;
  fragbuf_s *pfVar7;
  uchar *buf_00;
  fragbuf_t *pfVar8;
  fragbufwaiting_t *pfVar9;
  int iSize;
  int iVar10;
  int iVar11;
  int local_3c;
  uchar *local_34;
  int local_2c [7];
  
                    /* Unresolved local var: fragbuf_t * buf@[DW_OP_reg0(EAX)]
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
  local_2c[0] = uncompressed_size;
  if (uncompressed_size != 0) {
    local_34 = Mem_Malloc(uncompressed_size);
    iVar4 = BZ2_bzBuffToBuffCompress(local_34,local_2c,uncompressed_pbuf,uncompressed_size,9,0,0x1e)
    ;
    if (iVar4 == 0) {
      Con_DPrintf("Compressed %s for transmission (%d -> %d)\n",filename,uncompressed_size,
                  local_2c[0]);
    }
    else {
      Mem_Free(local_34);
      local_34 = uncompressed_pbuf;
      local_2c[0] = uncompressed_size;
    }
    iVar5 = (*chan->pfnNetchan_Blocksize)(chan->connection_status);
    pfVar6 = Mem_ZeroMalloc(0xc);
    if (0 < local_2c[0]) {
      bVar3 = true;
      local_3c = 1;
      iVar11 = 0;
      iVar10 = local_2c[0];
      while( true ) {
                    /* Unresolved local var: fragbuf_t * buf@[???] */
        iSize = iVar5;
        if (iVar10 <= iVar5) {
          iSize = iVar10;
        }
        pfVar7 = Mem_ZeroMalloc(0x6ac);
        (pfVar7->frag_message).data = pfVar7->frag_message_buf;
        (pfVar7->frag_message).cursize = 0;
        (pfVar7->frag_message).maxsize = 0x578;
        (pfVar7->frag_message).buffername = "Frag Buffer Alloc\'d";
        pfVar7->bufferid = local_3c;
        local_3c = local_3c + 1;
        pfVar7->next = (fragbuf_s *)0x0;
        buf = &pfVar7->frag_message;
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
          iSize = iSize - (pfVar7->frag_message).cursize;
        }
        iVar10 = iVar10 - iSize;
        pfVar7->isbuffer = 1;
        pfVar7->isfile = 1;
        pfVar7->foffset = iVar11;
        pfVar7->size = iSize;
        buf_00 = local_34 + iVar11;
        iVar11 = iVar11 + iSize;
        MSG_WriteBuf(buf,iSize,buf_00);
                    /* Unresolved local var: fragbuf_t * p@[???] */
        pfVar7->next = (fragbuf_s *)0x0;
        pfVar6->fragbufcount = pfVar6->fragbufcount + 1;
        pfVar1 = pfVar6->fragbufs;
        if (pfVar6->fragbufs == (fragbuf_t *)0x0) {
          pfVar6->fragbufs = pfVar7;
        }
        else {
          do {
            pfVar8 = pfVar1;
            pfVar1 = pfVar8->next;
          } while (pfVar1 != (fragbuf_s *)0x0);
          pfVar8->next = pfVar7;
        }
        if (iVar10 < 1) break;
        bVar3 = false;
      }
    }
    pfVar2 = chan->waitlist[1];
    if (chan->waitlist[1] != (fragbufwaiting_t *)0x0) {
      do {
        pfVar9 = pfVar2;
        pfVar2 = pfVar9->next;
      } while (pfVar2 != (fragbufwaiting_s *)0x0);
      pfVar9->next = pfVar6;
      return;
    }
    chan->waitlist[1] = pfVar6;
  }
  return;
}


// Netchan_CreateFragments  @ 000879b0
void Netchan_CreateFragments(qboolean server,netchan_t *chan,sizebuf_t *msg)

{
  if (0 < (chan->message).cursize) {
    Netchan_CreateFragments_(server,chan,&chan->message);
    (chan->message).cursize = 0;
  }
                    /* Unresolved local var: fragbuf_t * buf@[???]
                       Unresolved local var: int chunksize@[???]
                       Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: int send@[???]
                       Unresolved local var: int remaining@[???]
                       Unresolved local var: int pos@[???]
                       Unresolved local var: int bufferid@[???]
                       Unresolved local var: fragbufwaiting_t * p@[???] */
  if (msg->cursize != 0) {
    Netchan_CreateFragments_(server,chan,msg);
    return;
  }
  return;
}


// Netchan_CreateFragments_  @ 000856c0
/* WARNING: Removing unreachable block (ram,0x0008592f) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __regparm3 Netchan_CreateFragments_(qboolean server,netchan_t *chan,sizebuf_t *msg)

{
  undefined2 uVar1;
  fragbuf_s *pfVar2;
  fragbufwaiting_s *pfVar3;
  byte *pbVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  fragbufwaiting_s *pfVar8;
  fragbuf_s *pfVar9;
  uint uVar10;
  fragbuf_t *pfVar11;
  uint uVar12;
  byte *pbVar13;
  fragbufwaiting_t *pfVar14;
  int iVar15;
  int length;
  undefined4 *puVar16;
  byte bVar17;
  int iStack_1003c;
  undefined1 auStack_10020 [65536];
  uint local_20 [4];
  
                    /* Unresolved local var: fragbuf_t * buf@[DW_OP_reg0(EAX)]
                       Unresolved local var: int chunksize@[???]
                       Unresolved local var: int send@[???]
                       Unresolved local var: int remaining@[???]
                       Unresolved local var: int pos@[???]
                       Unresolved local var: int bufferid@[???]
                       Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: fragbufwaiting_t * p@[???] */
  bVar17 = 0;
  pbVar13 = msg->data;
  if ((((*pbVar13 == 'B') && (pbVar13[1] == 'Z')) && (pbVar13[2] == '2')) && (pbVar13[3] == '\0'))
  goto LAB_0008572e;
                    /* Unresolved local var: uchar[65536] compressed@[???]
                       Unresolved local var: char[4] hdr@[???]
                       Unresolved local var: uint compressedSize@[???] */
  puVar16 = (undefined4 *)auStack_10020;
  local_20[0] = msg->cursize - 4;
  iVar6 = BZ2_bzBuffToBuffCompress(puVar16,local_20,pbVar13,msg->cursize,9,0,0x1e);
  if (iVar6 != 0) goto LAB_0008572e;
  Con_DPrintf("Compressing split packet (%d -> %d bytes)\n",msg->cursize,local_20[0]);
  builtin_memcpy(msg->data,"BZ2",4);
  pbVar4 = msg->data;
  pbVar13 = pbVar4 + 4;
  if (local_20[0] < 8) {
    uVar10 = local_20[0];
    if ((local_20[0] & 4) == 0) goto LAB_000858c0;
    *(undefined4 *)pbVar13 = auStack_10020._0_4_;
    iVar6 = 4;
  }
  else {
    uVar12 = local_20[0];
    if (((uint)pbVar13 & 1) != 0) {
      pbVar13 = pbVar4 + 5;
      uVar12 = local_20[0] - 1;
      puVar16 = (undefined4 *)(auStack_10020 + 1);
      pbVar4[4] = auStack_10020[0];
    }
    if (((uint)pbVar13 & 2) != 0) {
      uVar1 = *(undefined2 *)puVar16;
      uVar12 = uVar12 - 2;
      puVar16 = (undefined4 *)((int)puVar16 + 2);
      *(undefined2 *)pbVar13 = uVar1;
      pbVar13 = pbVar13 + 2;
    }
    if (((uint)pbVar13 & 4) != 0) {
      uVar5 = *puVar16;
      uVar12 = uVar12 - 4;
      puVar16 = puVar16 + 1;
      *(undefined4 *)pbVar13 = uVar5;
      pbVar13 = pbVar13 + 4;
    }
    uVar10 = uVar12 & 3;
    for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
      *(undefined4 *)pbVar13 = *puVar16;
      puVar16 = puVar16 + (uint)bVar17 * -2 + 1;
      pbVar13 = pbVar13 + (uint)bVar17 * -8 + 4;
    }
LAB_000858c0:
    iVar6 = 0;
  }
  if ((uVar10 & 2) != 0) {
    *(undefined2 *)(pbVar13 + iVar6) = *(undefined2 *)((int)puVar16 + iVar6);
    iVar6 = iVar6 + 2;
  }
  if ((uVar10 & 1) != 0) {
    pbVar13[iVar6] = *(byte *)((int)puVar16 + iVar6);
  }
  msg->cursize = local_20[0] + 4;
LAB_0008572e:
  iVar7 = (*chan->pfnNetchan_Blocksize)(chan->connection_status);
  pfVar8 = Mem_ZeroMalloc(0xc);
  iVar6 = msg->cursize;
  if (0 < iVar6) {
    iVar15 = 0;
    iStack_1003c = 1;
    do {
                    /* Unresolved local var: fragbuf_t * buf@[???] */
      length = iVar7;
      if (iVar6 <= iVar7) {
        length = iVar6;
      }
      pfVar9 = Mem_ZeroMalloc(0x6ac);
      iVar6 = iVar6 - length;
      (pfVar9->frag_message).data = pfVar9->frag_message_buf;
      (pfVar9->frag_message).cursize = 0;
      (pfVar9->frag_message).maxsize = 0x578;
      (pfVar9->frag_message).buffername = "Frag Buffer Alloc\'d";
      pfVar9->bufferid = iStack_1003c;
      iStack_1003c = iStack_1003c + 1;
      pfVar9->next = (fragbuf_s *)0x0;
      SZ_Clear(&pfVar9->frag_message);
      pbVar13 = msg->data + iVar15;
      iVar15 = iVar15 + length;
      SZ_Write(&pfVar9->frag_message,pbVar13,length);
                    /* Unresolved local var: fragbuf_t * p@[???] */
      pfVar9->next = (fragbuf_s *)0x0;
      pfVar8->fragbufcount = pfVar8->fragbufcount + 1;
      pfVar2 = pfVar8->fragbufs;
      if (pfVar8->fragbufs == (fragbuf_t *)0x0) {
        pfVar8->fragbufs = pfVar9;
      }
      else {
        do {
          pfVar11 = pfVar2;
          pfVar2 = pfVar11->next;
        } while (pfVar2 != (fragbuf_s *)0x0);
        pfVar11->next = pfVar9;
      }
    } while (0 < iVar6);
  }
  pfVar3 = chan->waitlist[0];
  if (chan->waitlist[0] == (fragbufwaiting_t *)0x0) {
    chan->waitlist[0] = pfVar8;
  }
  else {
    do {
      pfVar14 = pfVar3;
      pfVar3 = pfVar14->next;
    } while (pfVar3 != (fragbufwaiting_s *)0x0);
    pfVar14->next = pfVar8;
  }
  return;
}


// Netchan_CreateFragments_  @ 00087980
void Netchan_CreateFragments_(qboolean server,netchan_t *chan,sizebuf_t *msg)

{
                    /* Unresolved local var: fragbuf_t * buf@[???]
                       Unresolved local var: int chunksize@[???]
                       Unresolved local var: int send@[???]
                       Unresolved local var: int remaining@[???]
                       Unresolved local var: int pos@[???]
                       Unresolved local var: int bufferid@[???]
                       Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: fragbufwaiting_t * p@[???] */
  if (msg->cursize != 0) {
    Netchan_CreateFragments_(server,chan,msg);
    return;
  }
  return;
}


// Netchan_DecompressPacket  @ 00088d80
qboolean Netchan_DecompressPacket(sizebuf_t *chan)

{
  return false;
}


// Netchan_FindBufferById  @ 00086e00
fragbuf_t * Netchan_FindBufferById(fragbuf_t **pplist,int id,qboolean allocate)

{
  fragbuf_s *pfVar1;
  fragbuf_t *pfVar2;
  fragbuf_t *pfVar3;
  
                    /* Unresolved local var: fragbuf_t * list@[???]
                       Unresolved local var: fragbuf_t * pnewbuf@[DW_OP_reg0(EAX)] */
  for (pfVar2 = *pplist; pfVar2 != (fragbuf_t *)0x0; pfVar2 = pfVar2->next) {
    if (pfVar2->bufferid == id) {
      return pfVar2;
    }
  }
  pfVar2 = (fragbuf_t *)0x0;
  if (allocate != false) {
    pfVar2 = Mem_ZeroMalloc(0x6ac);
    pfVar2->bufferid = id;
                    /* Unresolved local var: fragbuf_t * pprev@[???]
                       Unresolved local var: fragbuf_t * n@[???]
                       Unresolved local var: int id1@[???]
                       Unresolved local var: int id2@[DW_OP_reg3(EBX)] */
    (pfVar2->frag_message).cursize = 0;
    (pfVar2->frag_message).data = pfVar2->frag_message_buf;
    (pfVar2->frag_message).maxsize = 0x578;
    (pfVar2->frag_message).buffername = "Frag Buffer";
    (pfVar2->frag_message).flags = 1;
    pfVar2->next = (fragbuf_s *)0x0;
    pfVar1 = *pplist;
    if (*pplist != (fragbuf_t *)0x0) {
      do {
        pfVar3 = pfVar1;
        pfVar1 = pfVar3->next;
        if (pfVar1 == (fragbuf_s *)0x0) {
          pfVar3->next = pfVar2;
          return pfVar2;
        }
      } while ((uint)*(ushort *)((int)&pfVar1->bufferid + 2) <= (uint)id >> 0x10);
      pfVar2->next = pfVar1->next;
      pfVar3->next = pfVar2;
      return pfVar2;
    }
    *pplist = pfVar2;
  }
  return pfVar2;
}


// Netchan_FlushIncoming  @ 000881f0
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


// Netchan_FragSend  @ 00087820
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


// Netchan_IncomingReady  @ 00088b30
qboolean Netchan_IncomingReady(netchan_t *chan)

{
  qboolean qVar1;
  
                    /* Unresolved local var: int i@[???] */
  qVar1 = true;
  if (chan->incomingready[0] == false) {
    qVar1 = (qboolean)(chan->incomingready[1] != false);
  }
  return qVar1;
}


// Netchan_Init  @ 00088d10
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


// Netchan_IsReceiving  @ 00088b00
qboolean Netchan_IsReceiving(netchan_t *chan)

{
  qboolean qVar1;
  
                    /* Unresolved local var: int i@[???] */
  qVar1 = true;
  if (chan->incomingbufs[0] == (fragbuf_t *)0x0) {
    qVar1 = (qboolean)(chan->incomingbufs[1] != (fragbuf_t *)0x0);
  }
  return qVar1;
}


// Netchan_IsSending  @ 00088ad0
qboolean Netchan_IsSending(netchan_t *chan)

{
  qboolean qVar1;
  
                    /* Unresolved local var: int i@[???] */
  qVar1 = true;
  if (chan->fragbufs[0] == (fragbuf_t *)0x0) {
    qVar1 = (qboolean)(chan->fragbufs[1] != (fragbuf_t *)0x0);
  }
  return qVar1;
}


// Netchan_OutOfBand  @ 000855e0
void __regparm1 Netchan_OutOfBand(netsrc_t sock,netadr_t adr,int length,byte *data)

{
  byte local_fe5 [4037];
  sizebuf_t local_20;
  
                    /* Unresolved local var: sizebuf_t send@[???]
                       Unresolved local var: byte[4037] send_buf@[???] */
  local_20.data = local_fe5;
  local_20.buffername = "Netchan_OutOfBand";
  local_20.flags = 1;
  local_20.maxsize = 0xfc5;
  local_20.cursize = 0;
  MSG_WriteLong(&local_20,-1);
  SZ_Write(&local_20,Netchan_OutOfBandPrint::string,length);
  if (cls.demoplayback == false) {
    NET_SendPacket(sock,local_20.cursize,local_20.data,adr);
  }
  return;
}


// Netchan_OutOfBand  @ 000859d0
void Netchan_OutOfBand(netsrc_t sock,netadr_t adr,int length,byte *data)

{
  byte local_fe5 [4037];
  sizebuf_t local_20;
  
                    /* Unresolved local var: sizebuf_t send@[???]
                       Unresolved local var: byte[4037] send_buf@[???] */
  local_20.buffername = "Netchan_OutOfBand";
  local_20.data = local_fe5;
  local_20.maxsize = 0xfc5;
  local_20.cursize = 0;
  local_20.flags = 1;
  MSG_WriteLong(&local_20,-1);
  SZ_Write(&local_20,data,length);
  if (cls.demoplayback == false) {
    NET_SendPacket(sock,local_20.cursize,local_20.data,adr);
  }
  return;
}


// Netchan_OutOfBandPrint  @ 00085ac0
void Netchan_OutOfBandPrint(netsrc_t sock,netadr_t adr,char *format,...)

{
  int iVar1;
  byte *in_stack_ffffffec;
  
                    /* Unresolved local var: va_list argptr@[???] */
  vsnprintf(Netchan_OutOfBandPrint::string,0x2000,format,&stack0x00000020);
  iVar1 = Q_strlen(Netchan_OutOfBandPrint::string);
  Netchan_OutOfBand(sock,adr,iVar1 + 1,in_stack_ffffffec);
  return;
}


// Netchan_Process  @ 00087090
/* WARNING: Variable defined which should be unmapped: pbuf */

qboolean Netchan_Process(netchan_t *chan)

{
  byte *pbVar1;
  byte *pbVar2;
  fragbuf_s *pfVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  netadr_t a;
  double dVar6;
  uint uVar7;
  uint uVar8;
  qboolean qVar9;
  int iVar10;
  char *pcVar11;
  undefined4 uVar12;
  int iVar13;
  fragbuf_t *pfVar14;
  byte *pbVar15;
  fragbuf_t *pfVar16;
  uint uVar17;
  byte *pbVar18;
  uint uVar19;
  bool bVar20;
  uint local_74;
  int local_6c;
  uint local_5c [4];
  int local_4c [4];
  uint local_3c [4];
  uint local_2c [7];
  fragbuf_t *pbuf;
  
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
  local_4c[1] = 0;
  local_3c[0] = 0;
  local_3c[1] = 0;
  local_2c[0] = 0;
  local_2c[1] = 0;
  local_5c[0] = 0;
  local_5c[1] = 0;
  local_4c[0] = 0;
  if (((cls.demoplayback == false) && (cls.passive == false)) &&
     (a.ip = net_from.ip, a.type = net_from.type, a.ipx._0_4_ = net_from.ipx._0_4_,
     a.ipx._4_4_ = net_from.ipx._4_4_, a._16_4_ = net_from._16_4_,
     qVar9 = NET_CompareAdr(a,chan->remote_address), qVar9 == false)) {
    return false;
  }
  chan->last_received = (float)realtime;
  MSG_BeginReading();
  uVar7 = MSG_ReadLong();
  uVar8 = MSG_ReadLong();
  if ((uVar8 & 0x40000000) == 0) {
    if (g_modfuncs.m_pfnProcessIncomingNet == (PFN_PROCESSINCOMINGNET)0x0) goto LAB_00087137;
  }
  else if (g_modfuncs.m_pfnProcessIncomingNet == (PFN_PROCESSINCOMINGNET)0x0) {
    return false;
  }
  qVar9 = (*g_modfuncs.m_pfnProcessIncomingNet)(chan,&net_message);
  if (qVar9 == false) {
    return false;
  }
LAB_00087137:
  COM_UnMunge2(net_message.data + 8,net_message.cursize + -8,uVar7 & 0xff);
  bVar20 = (uVar7 & 0x40000000) != 0;
  if (bVar20) {
    iVar10 = MSG_ReadByte();
    if (iVar10 != 0) {
      local_4c[0] = 1;
      local_5c[0] = MSG_ReadLong();
      local_3c[0] = MSG_ReadShort();
      local_2c[0] = MSG_ReadShort();
    }
    iVar10 = MSG_ReadByte();
    if (iVar10 != 0) {
      local_4c[1] = 1;
      local_5c[1] = MSG_ReadLong();
      local_3c[1] = MSG_ReadShort();
      local_2c[1] = MSG_ReadShort();
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int buffer@[???]
                       Unresolved local var: int count@[???] */
    if (local_4c[0] != 0) {
      if (0x61a8ffff < local_5c[0]) {
        return false;
      }
      if (25000 < (ushort)local_5c[0]) {
        return false;
      }
      if (0x800 < local_2c[0]) {
        return false;
      }
      if (0x4000 < local_3c[0]) {
        return false;
      }
    }
    if (local_4c[1] != 0) {
      if (0x61a8ffff < local_5c[1]) {
        return false;
      }
      if (25000 < (ushort)local_5c[1]) {
        return false;
      }
      if (0x800 < local_2c[1]) {
        return false;
      }
      if (0x4000 < local_3c[1]) {
        return false;
      }
    }
  }
  uVar19 = uVar7 & 0x3fffffff;
  if ((net_showpackets.value == 0.0) || (net_showpackets.value == 3.0)) {
    uVar17 = chan->incoming_sequence;
  }
  else {
                    /* Unresolved local var: char c@[???]
                       Unresolved local var: int mask@[???] */
    if (chan == &cls.netchan) {
      uVar12 = 99;
      dVar6 = cl.time;
    }
    else {
      uVar12 = 0x73;
      dVar6 = sv.time;
    }
    Con_Printf(" %c <-- sz=%i seq=%i ack=%i rel=%i tm=%f\n",uVar12,net_message.cursize,uVar19,
               uVar8 & 0x3fffffff,-((int)uVar7 >> 0x1f),SUB84((double)(float)dVar6,0),
               (int)((ulonglong)(double)(float)dVar6 >> 0x20));
    uVar17 = chan->incoming_sequence;
  }
  if (uVar17 < uVar19) {
    iVar10 = ~uVar17 + uVar19;
    net_drop = iVar10;
    if ((0 < iVar10) && (net_showdrop.value != 0.0)) {
      pcVar11 = NET_AdrToString(chan->remote_address);
      Con_Printf("%s:Dropped %i packets at %i\n",pcVar11,iVar10,uVar19);
    }
    if ((chan->reliable_sequence == uVar8 >> 0x1f) &&
       (chan->last_reliable_sequence <= chan->incoming_acknowledged + 1)) {
      chan->reliable_length = 0;
    }
    chan->incoming_sequence = uVar19;
    chan->incoming_acknowledged = uVar8 & 0x3fffffff;
    chan->incoming_reliable_acknowledged = uVar8 >> 0x1f;
    if (-((int)uVar7 >> 0x1f) != 0) {
      chan->incoming_reliable_sequence = chan->incoming_reliable_sequence ^ 1;
    }
    dVar6 = realtime;
    uVar7 = chan->flow[1].current;
    uVar8 = uVar7 & 0x1f;
    chan->flow[1].stats[uVar8].size = net_message.cursize + 0x1c;
    chan->flow[1].stats[uVar8].time = dVar6;
    chan->flow[1].current = uVar7 + 1;
    Netchan_UpdateFlow(chan);
    qVar9 = true;
    if (bVar20) {
      iVar10 = 0;
      local_6c = 1;
      do {
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: uchar * src@[???]
                       Unresolved local var: uchar * dst@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int inbufferid@[???]
                       Unresolved local var: int intotalbuffers@[???] */
        if (local_4c[iVar10] == 0) {
LAB_000873f6:
          if (local_6c == 2) {
            return (uint)(0x10 < net_message.cursize);
          }
        }
        else {
          uVar7 = local_5c[iVar10];
          if (uVar7 == 0) {
            local_74 = local_2c[iVar10];
            uVar8 = local_3c[iVar10];
          }
          else {
            for (pfVar14 = chan->incomingbufs[iVar10]; pfVar14 != (fragbuf_t *)0x0;
                pfVar14 = pfVar14->next) {
              if (uVar7 == pfVar14->bufferid) goto LAB_000876e8;
            }
            pfVar14 = Mem_ZeroMalloc(0x6ac);
            pfVar14->bufferid = uVar7;
            (pfVar14->frag_message).cursize = 0;
            (pfVar14->frag_message).data = pfVar14->frag_message_buf;
            (pfVar14->frag_message).maxsize = 0x578;
            (pfVar14->frag_message).buffername = "Frag Buffer";
            (pfVar14->frag_message).flags = 1;
            pfVar14->next = (fragbuf_s *)0x0;
            pfVar3 = chan->incomingbufs[iVar10];
            if (chan->incomingbufs[iVar10] == (fragbuf_t *)0x0) {
              chan->incomingbufs[iVar10] = pfVar14;
            }
            else {
              do {
                pfVar16 = pfVar3;
                pfVar3 = pfVar16->next;
                if (pfVar3 == (fragbuf_s *)0x0) {
                  pfVar16->next = pfVar14;
                  goto LAB_000876e8;
                }
              } while ((uint)*(ushort *)((int)&pfVar3->bufferid + 2) <= uVar7 >> 0x10);
              pfVar14->next = pfVar3->next;
              pfVar16->next = pfVar14;
            }
LAB_000876e8:
                    /* Unresolved local var: int nbytes@[???] */
            local_74 = local_2c[iVar10];
            SZ_Clear(&pfVar14->frag_message);
            uVar8 = local_3c[iVar10];
            SZ_Write(&pfVar14->frag_message,net_message.data + msg_readcount + uVar8,local_74);
            if (((pfVar14->frag_message).flags & 2) != 0) {
              if (chan == &cls.netchan) {
                return false;
              }
              (chan->message).flags = (ushort)*(undefined4 *)&(chan->message).flags | 2;
              return false;
            }
            Netchan_CheckForCompletion(chan,iVar10,uVar7 & 0xffff);
          }
          iVar13 = net_message.cursize - local_74;
          uVar7 = (iVar13 - uVar8) - msg_readcount;
          if (0 < (int)uVar7) {
            uVar19 = uVar7 >> 4;
            pbVar15 = net_message.data + msg_readcount + uVar8;
            pbVar18 = net_message.data + local_74 + msg_readcount + uVar8;
            uVar8 = uVar19 * 0x10;
            if ((uVar19 == 0) ||
               (pbVar18 <= pbVar15 + 0x10 && pbVar15 <= pbVar18 + 0x10 || uVar7 < 0x10)) {
              uVar8 = 0;
LAB_0008758e:
              iVar13 = -uVar8;
              do {
                pbVar15[uVar8 + iVar13] = pbVar18[uVar8 + iVar13];
                uVar8 = uVar8 + 1;
              } while ((int)uVar8 < (int)uVar7);
            }
            else {
                    /* Unresolved local var: fragbuf_t * list@[???]
                       Unresolved local var: fragbuf_t * pnewbuf@[???]
                       Unresolved local var: fragbuf_t * pprev@[???]
                       Unresolved local var: fragbuf_t * n@[???]
                       Unresolved local var: int id1@[???]
                       Unresolved local var: int id2@[???] */
              iVar13 = 0;
              uVar17 = 0;
              do {
                uVar17 = uVar17 + 1;
                pbVar1 = pbVar18 + iVar13;
                uVar12 = *(undefined4 *)(pbVar1 + 4);
                uVar4 = *(undefined4 *)(pbVar1 + 8);
                uVar5 = *(undefined4 *)(pbVar1 + 0xc);
                pbVar2 = pbVar15 + iVar13;
                *(undefined4 *)pbVar2 = *(undefined4 *)pbVar1;
                *(undefined4 *)(pbVar2 + 4) = uVar12;
                *(undefined4 *)(pbVar2 + 8) = uVar4;
                *(undefined4 *)(pbVar2 + 0xc) = uVar5;
                iVar13 = iVar13 + 0x10;
              } while (uVar17 < uVar19);
              pbVar18 = pbVar18 + uVar8;
              pbVar15 = pbVar15 + uVar8;
              if (uVar7 != uVar8) goto LAB_0008758e;
            }
            iVar13 = net_message.cursize - local_74;
          }
          net_message.cursize = iVar13;
          if (iVar10 != 0) goto LAB_000873f6;
          local_3c[1] = local_3c[1] - local_74;
        }
        iVar10 = iVar10 + 1;
        local_6c = local_6c + 1;
      } while( true );
    }
  }
  else {
    if (net_showdrop.value == 0.0) {
      net_from.ipx[8] = net_from.ipx[8];
      net_from.ipx[9] = net_from.ipx[9];
      net_from.port = net_from.port;
      net_from.ipx[4] = net_from.ipx[4];
      net_from.ipx[5] = net_from.ipx[5];
      net_from.ipx[6] = net_from.ipx[6];
      net_from.ipx[7] = net_from.ipx[7];
      net_from.ipx[0] = net_from.ipx[0];
      net_from.ipx[1] = net_from.ipx[1];
      net_from.ipx[2] = net_from.ipx[2];
      net_from.ipx[3] = net_from.ipx[3];
      net_from.ip[0] = net_from.ip[0];
      net_from.ip[1] = net_from.ip[1];
      net_from.ip[2] = net_from.ip[2];
      net_from.ip[3] = net_from.ip[3];
      return false;
    }
    if (uVar19 == uVar17) {
      pcVar11 = NET_AdrToString(chan->remote_address);
      Con_Printf("%s:duplicate packet %i at %i\n",pcVar11,uVar19,uVar19);
      qVar9 = false;
    }
    else {
      pcVar11 = NET_AdrToString(chan->remote_address);
      Con_Printf("%s:out of order packet %i at %i\n",pcVar11,uVar19,uVar17);
      qVar9 = false;
    }
  }
  return qVar9;
}


// Netchan_Setup  @ 00085d50
void Netchan_Setup(netsrc_t socketnumber,netchan_t *chan,netadr_t adr,int player_slot,
                  void *connection_status,_func_qboolean_void_ptr *pfnNetchan_Blocksize)

{
  void *p;
  float fVar1;
  
                    /* Unresolved local var: int i@[???] */
  Netchan_ClearFragments(chan);
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
  chan->reliable_fragid[1] = 0;
  chan->reliable_fragment[1] = 0;
  chan->fragbufcount[1] = 0;
  chan->frag_startpos[1] = 0;
  chan->frag_length[1] = 0;
  chan->incomingready[1] = false;
  p = chan->tempbuffer;
  *(undefined4 *)&chan->cleartime = 0;
  *(undefined4 *)((int)&chan->cleartime + 4) = 0;
  chan->frag_length[0] = 0;
  chan->incomingready[0] = false;
  if (p != (void *)0x0) {
    Mem_Free(p);
    chan->tempbuffer = (void *)0x0;
  }
  chan->tempbuffersize = 0;
  Q_memset(chan,0,0x2414);
  chan->player_slot = player_slot + 1;
  chan->sock = socketnumber;
  (chan->remote_address).type = adr.type;
  fVar1 = (float)realtime;
  *&(chan->remote_address).ip = adr.ip;
  *(undefined4 *)(chan->remote_address).ipx = adr.ipx._0_4_;
  *(undefined4 *)((chan->remote_address).ipx + 4) = adr.ipx._4_4_;
  *(undefined4 *)((chan->remote_address).ipx + 8) = adr._16_4_;
  (chan->message).data = chan->message_buf;
  chan->last_received = fVar1;
  chan->connect_time = fVar1;
  (chan->message).flags = 1;
  chan->connection_status = connection_status;
  (chan->message).maxsize = 0xf96;
  (chan->message).buffername = "netchan->message";
  *(undefined4 *)&chan->rate = 0;
  *(undefined4 *)((int)&chan->rate + 4) = 0x40dd4c00;
  chan->outgoing_sequence = 1;
  chan->pfnNetchan_Blocksize = (_func_int_void_ptr *)pfnNetchan_Blocksize;
  return;
}


// Netchan_Transmit  @ 00086460
void Netchan_Transmit(netchan_t *chan,int length,byte *data)

{
  int *piVar1;
  fragbuf_t *p;
  fragbuf_s *pfVar2;
  fragbufwaiting_t *pfVar3;
  bool bVar4;
  double dVar5;
  double dVar6;
  bool bVar7;
  short sVar8;
  int iVar9;
  char *pcVar10;
  FileHandle_t file;
  uint uVar11;
  int iVar12;
  fragbuf_t *pfVar13;
  undefined4 uVar14;
  uint c;
  uint uVar15;
  int iVar16;
  netchan_t *pnVar17;
  bool bVar18;
  uint local_1130;
  uint local_112c;
  byte local_1115 [4037];
  char local_150 [260];
  sizebuf_t local_4c;
  int aiStack_30 [8];
  
                    /* Unresolved local var: sizebuf_t send@[???]
                       Unresolved local var: byte[4037] send_buf@[???]
                       Unresolved local var: qboolean send_reliable@[???]
                       Unresolved local var: qboolean send_reliable_fragment@[???]
                       Unresolved local var: qboolean send_resending@[???]
                       Unresolved local var: int max_send_size@[???]
                       Unresolved local var: uint w1@[???]
                       Unresolved local var: uint w2@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float fRate@[???] */
  local_4c.data = local_1115;
  local_4c.buffername = "Netchan_Transmit";
  local_4c.maxsize = 0xfc5;
  local_4c.cursize = 0;
  local_4c.flags = 0;
  if (((chan->message).flags & 2) != 0) {
    pcVar10 = NET_AdrToString(chan->remote_address);
    Con_Printf("%s:Outgoing message overflow\n",pcVar10);
    return;
  }
  uVar15 = 0;
  if (chan->last_reliable_sequence < chan->incoming_acknowledged) {
    iVar16 = chan->reliable_length;
    uVar15 = (uint)(chan->incoming_reliable_acknowledged != chan->reliable_sequence);
  }
  else {
    iVar16 = chan->reliable_length;
  }
  local_112c = uVar15;
  if (iVar16 == 0) {
                    /* Unresolved local var: qboolean send_frag@[???]
                       Unresolved local var: fragbuf_t * pbuf@[???]
                       Unresolved local var: int[2] send_from_frag@[???]
                       Unresolved local var: int send_from_regular@[???]
                       Unresolved local var: fragbufwaiting_t * wait@[???]
                       Unresolved local var: int i@[???] */
    aiStack_30[1] = 0;
    aiStack_30[2] = 0;
    if ((chan->fragbufs[0] == (fragbuf_t *)0x0) &&
       (pfVar3 = chan->waitlist[0], pfVar3 != (fragbufwaiting_t *)0x0)) {
      chan->waitlist[0] = pfVar3->next;
      pfVar3->next = (fragbufwaiting_s *)0x0;
      chan->fragbufs[0] = pfVar3->fragbufs;
      chan->fragbufcount[0] = pfVar3->fragbufcount;
      Mem_Free(pfVar3);
    }
    if ((chan->fragbufs[1] == (fragbuf_t *)0x0) &&
       (pfVar3 = chan->waitlist[1], pfVar3 != (fragbufwaiting_t *)0x0)) {
      chan->waitlist[1] = pfVar3->next;
      pfVar3->next = (fragbufwaiting_s *)0x0;
      chan->fragbufs[1] = pfVar3->fragbufs;
      chan->fragbufcount[1] = pfVar3->fragbufcount;
      Mem_Free(pfVar3);
    }
    iVar12 = aiStack_30[1];
    iVar16 = (chan->message).cursize;
    bVar18 = chan->fragbufs[0] != (fragbuf_t *)0x0;
    if (bVar18) {
      aiStack_30[1] = 1;
    }
    if (chan->fragbufs[1] != (fragbuf_t *)0x0) {
      aiStack_30[2] = 1;
    }
    if (iVar16 != 0) {
      if (aiStack_30[1] == 0) {
        bVar4 = true;
        bVar7 = true;
        goto LAB_000866d1;
      }
      if (0x4b0 < iVar16) {
        Netchan_CreateFragments_((uint)(chan != &cls.netchan),chan,&chan->message);
        bVar4 = false;
        bVar7 = false;
        (chan->message).cursize = 0;
        goto LAB_000866d1;
      }
    }
    bVar4 = false;
    bVar7 = false;
LAB_000866d1:
    chan->frag_startpos[0] = 0;
    chan->reliable_fragid[0] = 0;
    chan->frag_startpos[1] = 0;
    chan->reliable_fragid[1] = 0;
    chan->reliable_fragment[0] = 0;
    chan->frag_length[0] = 0;
    chan->reliable_fragment[1] = 0;
    chan->frag_length[1] = 0;
    if (((aiStack_30[2] != 0) || (bVar4)) || (bVar18 || iVar12 != 0)) {
      chan->reliable_sequence = chan->reliable_sequence ^ 1;
      if (bVar7) {
        Q_memcpy(chan->reliable_buf,chan->message_buf,(chan->message).cursize);
        iVar16 = (chan->message).cursize;
        (chan->message).cursize = 0;
        local_112c = 1;
        chan->reliable_length = iVar16;
        sVar8 = (short)iVar16;
        chan->frag_startpos[0] = sVar8;
        chan->frag_startpos[1] = sVar8;
        local_1130 = 0x80000000;
      }
      else {
        local_1130 = 0x80000000;
        local_112c = 1;
      }
    }
    else {
      local_1130 = uVar15 << 0x1f;
    }
    iVar16 = 1;
    pnVar17 = chan;
    do {
                    /* Unresolved local var: int fragment_size@[???]
                       Unresolved local var: int host_framecount@[???] */
      p = pnVar17->fragbufs[0];
      if (p == (fragbuf_t *)0x0) {
LAB_00086b18:
        if (iVar16 == 2) goto LAB_000864dc;
      }
      else {
        iVar12 = (p->frag_message).cursize;
        if ((p->isfile != 0) && (p->isbuffer == 0)) {
          iVar12 = p->size;
        }
        if ((aiStack_30[iVar16] == 0) || (iVar9 = chan->reliable_length, 0x4af < iVar12 + iVar9))
        goto LAB_00086b18;
        pnVar17->reliable_fragid[0] = (uint)(ushort)pnVar17->fragbufcount[0] | p->bufferid << 0x10;
        if ((p->isfile != 0) && (p->isbuffer == 0)) {
                    /* Unresolved local var: FileHandle_t hfile@[???] */
          if (p->iscompressed == 0) {
            file = FS_Open(p->filename,"rb");
          }
          else {
                    /* Unresolved local var: char[260] compressedfilename@[???] */
            snprintf(local_150,0x104,"%s.ztmp",p->filename);
            file = FS_Open(local_150,"rb");
          }
          FS_Seek(file,p->foffset,FILESYSTEM_SEEK_HEAD);
          FS_Read((p->frag_message).data + (p->frag_message).cursize,p->size,1,file);
          piVar1 = &(p->frag_message).cursize;
          *piVar1 = *piVar1 + p->size;
          FS_Close(file);
          iVar9 = chan->reliable_length;
        }
        Q_memcpy(chan->reliable_buf + iVar9,(p->frag_message).data,(p->frag_message).cursize);
        chan->reliable_length = chan->reliable_length + (p->frag_message).cursize;
        chan->frag_startpos[iVar16 + 1] = (short)(p->frag_message).cursize;
                    /* Unresolved local var: fragbuf_t * search@[???] */
        pfVar2 = pnVar17->fragbufs[0];
        if (p == pnVar17->fragbufs[0]) {
          pnVar17->fragbufs[0] = p->next;
          Mem_Free(p);
        }
        else {
          do {
            pfVar13 = pfVar2;
            pfVar2 = pfVar13->next;
            if (pfVar2 == (fragbuf_s *)0x0) {
              Con_Printf("Netchan_UnlinkFragment:  Couldn\'t find fragment\n");
              goto LAB_0008682e;
            }
          } while (p != pfVar2);
          pfVar13->next = p->next;
          Mem_Free(p);
        }
LAB_0008682e:
        pnVar17->reliable_fragment[0] = 1;
        if (iVar16 != 1) goto LAB_00086b18;
        chan->frag_startpos[1] = chan->frag_startpos[1] + chan->frag_length[0];
      }
      pnVar17 = (netchan_t *)&pnVar17->remote_address;
      iVar16 = iVar16 + 1;
    } while( true );
  }
  local_1130 = uVar15 << 0x1f;
LAB_000864dc:
  uVar11 = chan->outgoing_sequence;
  c = chan->incoming_reliable_sequence << 0x1f | chan->incoming_sequence;
  if (((chan->reliable_fragment[0] == 0) && (chan->reliable_fragment[1] == 0)) || (local_112c == 0))
  {
    chan->outgoing_sequence = uVar11 + 1;
    MSG_WriteLong(&local_4c,local_1130 | uVar11);
    MSG_WriteLong(&local_4c,c);
    if (local_112c == 0) goto LAB_00086537;
  }
  else {
    chan->outgoing_sequence = uVar11 + 1;
    MSG_WriteLong(&local_4c,local_1130 | uVar11 | 0x40000000);
    MSG_WriteLong(&local_4c,c);
    if (chan->reliable_fragment[0] == 0) {
      MSG_WriteByte(&local_4c,0);
      iVar16 = chan->reliable_fragment[1];
    }
    else {
      MSG_WriteByte(&local_4c,1);
      MSG_WriteLong(&local_4c,chan->reliable_fragid[0]);
      MSG_WriteShort(&local_4c,(int)chan->frag_startpos[0]);
      MSG_WriteShort(&local_4c,(int)chan->frag_length[0]);
      iVar16 = chan->reliable_fragment[1];
    }
    if (iVar16 == 0) {
      MSG_WriteByte(&local_4c,0);
    }
    else {
      MSG_WriteByte(&local_4c,1);
      MSG_WriteLong(&local_4c,chan->reliable_fragid[1]);
      MSG_WriteShort(&local_4c,(int)chan->frag_startpos[1]);
      MSG_WriteShort(&local_4c,(int)chan->frag_length[1]);
    }
  }
  SZ_Write(&local_4c,chan->reliable_buf,chan->reliable_length);
  chan->last_reliable_sequence = chan->outgoing_sequence + -1;
LAB_00086537:
  iVar16 = 0x578;
  if (uVar15 == 0) {
    iVar16 = local_4c.maxsize;
  }
  if (iVar16 - local_4c.cursize < length) {
    Con_DPrintf("Netchan_Transmit:  Unreliable would overfow, ignoring\n");
  }
  else {
    SZ_Write(&local_4c,data,length);
  }
  iVar16 = local_4c.cursize;
  if (local_4c.cursize < 0x10) {
    do {
                    /* Unresolved local var: int i@[???] */
      iVar16 = iVar16 + 1;
      MSG_WriteByte(&local_4c,1);
    } while (iVar16 != 0x10);
  }
  dVar6 = realtime;
  uVar15 = chan->flow[0].current;
  uVar11 = uVar15 & 0x1f;
  chan->flow[0].stats[uVar11].size = local_4c.cursize + 0x1c;
  chan->flow[0].stats[uVar11].time = dVar6;
  chan->flow[0].current = uVar15 + 1;
  Netchan_UpdateFlow(chan);
  if (cls.demoplayback == false) {
    COM_Munge2(local_4c.data + 8,local_4c.cursize + -8,chan->outgoing_sequence - 1U & 0xff);
    if (g_modfuncs.m_pfnProcessOutgoingNet != (PFN_PROCESSOUTGOINGNET)0x0) {
      (*g_modfuncs.m_pfnProcessOutgoingNet)(chan,&local_4c);
    }
    NET_SendPacket(chan->sock,local_4c.cursize,local_4c.data,chan->remote_address);
  }
  if (((sv.active == false) || (sv_lan.value == 0.0)) || ((double)sv_lan_rate.value <= 1000.0)) {
    dVar6 = (double)(1.0 / (float)chan->rate);
  }
  else {
    dVar6 = 1.0 / (double)sv_lan_rate.value;
  }
  dVar5 = realtime;
  if (realtime <= chan->cleartime) {
    dVar5 = chan->cleartime;
  }
  chan->cleartime = dVar5 + (double)(local_4c.cursize + 0x1c) * dVar6;
  if ((net_showpackets.value != 0.0) && (net_showpackets.value != 2.0)) {
                    /* Unresolved local var: char c@[???]
                       Unresolved local var: int mask@[???] */
    if (chan == &cls.netchan) {
      uVar14 = 99;
      dVar6 = cl.time;
    }
    else {
      uVar14 = 0x73;
      dVar6 = sv.time;
    }
    Con_Printf(" %c --> sz=%i seq=%i ack=%i rel=%i tm=%f\n",uVar14,local_4c.cursize,
               chan->outgoing_sequence + -1,chan->incoming_sequence,local_112c,
               SUB84((double)(float)dVar6,0),(int)((ulonglong)(double)(float)dVar6 >> 0x20));
  }
  return;
}


// Netchan_UnlinkFragment  @ 00085970
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


// Netchan_UpdateFlow  @ 00085f20
void Netchan_UpdateFlow(netchan_t *chan)

{
  flowstats_t *pfVar1;
  flowstats_t *pfVar2;
  flowstats_t *pfVar3;
  flowstats_t *pfVar4;
  flowstats_t *pfVar5;
  flowstats_t *pfVar6;
  flowstats_t *pfVar7;
  flowstats_t *pfVar8;
  flowstats_t *pfVar9;
  flowstats_t *pfVar10;
  flowstats_t *pfVar11;
  flowstats_t *pfVar12;
  flowstats_t *pfVar13;
  flowstats_t *pfVar14;
  flowstats_t *pfVar15;
  float fVar16;
  int iVar17;
  float fVar18;
  double dVar19;
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
  dVar19 = realtime;
  if (chan != (netchan_t *)0x0) {
    if (realtime - chan->flow[0].nextcompute < 0.1) {
      lVar21 = (longdouble)0;
      iVar20 = 0;
    }
    else {
      iVar17 = chan->flow[0].current;
      pfVar1 = chan->flow[0].stats + (iVar17 - 2U & 0x1f);
      chan->flow[0].nextcompute = realtime + 0.1;
      pfVar2 = chan->flow[0].stats + (iVar17 - 3U & 0x1f);
      lVar21 = (longdouble)pfVar1->time;
      pfVar3 = chan->flow[0].stats + (iVar17 - 4U & 0x1f);
      lVar35 = (longdouble)0;
      lVar22 = (longdouble)pfVar2->time;
      lVar23 = (longdouble)pfVar3->time;
      pfVar4 = chan->flow[0].stats + (iVar17 - 5U & 0x1f);
      lVar24 = (longdouble)pfVar4->time;
      pfVar5 = chan->flow[0].stats + (iVar17 - 6U & 0x1f);
      lVar25 = (longdouble)pfVar5->time;
      pfVar6 = chan->flow[0].stats + (iVar17 - 7U & 0x1f);
      lVar26 = (longdouble)pfVar6->time;
      pfVar7 = chan->flow[0].stats + (iVar17 - 8U & 0x1f);
      lVar27 = (longdouble)pfVar7->time;
      pfVar8 = chan->flow[0].stats + (iVar17 - 9U & 0x1f);
      lVar28 = (longdouble)pfVar8->time;
      pfVar9 = chan->flow[0].stats + (iVar17 - 10U & 0x1f);
      lVar29 = (longdouble)pfVar9->time;
      pfVar10 = chan->flow[0].stats + (iVar17 - 0xbU & 0x1f);
      lVar30 = (longdouble)pfVar10->time;
      pfVar11 = chan->flow[0].stats + (iVar17 - 0xcU & 0x1f);
      lVar31 = (longdouble)pfVar11->time;
      pfVar12 = chan->flow[0].stats + (iVar17 - 0xdU & 0x1f);
      lVar32 = (longdouble)pfVar12->time;
      pfVar13 = chan->flow[0].stats + (iVar17 - 0xeU & 0x1f);
      lVar33 = (longdouble)pfVar13->time;
      pfVar14 = chan->flow[0].stats + (iVar17 - 0xfU & 0x1f);
      lVar34 = (longdouble)pfVar14->time;
      pfVar15 = chan->flow[0].stats + (iVar17 - 0x10U & 0x1f);
      iVar20 = pfVar1->size + pfVar2->size + pfVar3->size + pfVar4->size + pfVar5->size +
               pfVar6->size + pfVar7->size + pfVar8->size + pfVar9->size + pfVar10->size +
               pfVar11->size + pfVar12->size + pfVar13->size + pfVar14->size + pfVar15->size;
      lVar21 = (longdouble)
               (float)((lVar34 - (longdouble)pfVar15->time) +
                      (longdouble)
                      (float)((lVar33 - lVar34) +
                             (longdouble)
                             (float)((lVar32 - lVar33) +
                                    (longdouble)
                                    (float)((lVar31 - lVar32) +
                                           (longdouble)
                                           (float)((lVar30 - lVar31) +
                                                  (longdouble)
                                                  (float)((lVar29 - lVar30) +
                                                         (longdouble)
                                                         (float)((lVar28 - lVar29) +
                                                                (longdouble)
                                                                (float)((lVar27 - lVar28) +
                                                                       (longdouble)
                                                                       (float)((lVar26 - lVar27) +
                                                                              (longdouble)
                                                                              (float)((lVar25 - 
                                                  lVar26) + (longdouble)
                                                            (float)((lVar24 - lVar25) +
                                                                   (longdouble)
                                                                   (float)((lVar23 - lVar24) +
                                                                          (longdouble)
                                                                          (float)((lVar22 - lVar23)
                                                                                 + (longdouble)
                                                                                   (float)((lVar21 -
                                                                                           lVar22) +
                                                                                          (
                                                  longdouble)
                                                  (float)(((longdouble)
                                                           chan->flow[0].stats[iVar17 - 1U & 0x1f].
                                                           time - lVar21) + lVar35)))))))))))))));
      if (lVar21 == lVar35) {
        chan->flow[0].kbytespersec = (float)lVar35;
      }
      else {
        lVar35 = ((longdouble)iVar20 / lVar21) * (longdouble)0.0009765625;
        chan->flow[0].kbytespersec = (float)lVar35;
        lVar35 = (longdouble)0.33333333333333337 * lVar35;
      }
      chan->flow[0].avgkbytespersec =
           (float)((longdouble)0.6666666666666666 * (longdouble)chan->flow[0].avgkbytespersec +
                  lVar35);
    }
    if (0.1 <= dVar19 - chan->flow[1].nextcompute) {
      iVar17 = chan->flow[1].current;
      chan->flow[1].nextcompute = dVar19 + 0.1;
      pfVar1 = chan->flow[1].stats + (iVar17 - 2U & 0x1f);
      lVar35 = (longdouble)pfVar1->time;
      pfVar2 = chan->flow[1].stats + (iVar17 - 3U & 0x1f);
      lVar22 = (longdouble)pfVar2->time;
      pfVar3 = chan->flow[1].stats + (iVar17 - 4U & 0x1f);
      lVar23 = (longdouble)pfVar3->time;
      pfVar4 = chan->flow[1].stats + (iVar17 - 5U & 0x1f);
      lVar24 = (longdouble)pfVar4->time;
      pfVar5 = chan->flow[1].stats + (iVar17 - 6U & 0x1f);
      lVar25 = (longdouble)pfVar5->time;
      pfVar6 = chan->flow[1].stats + (iVar17 - 7U & 0x1f);
      lVar26 = (longdouble)pfVar6->time;
      pfVar7 = chan->flow[1].stats + (iVar17 - 8U & 0x1f);
      lVar27 = (longdouble)pfVar7->time;
      pfVar8 = chan->flow[1].stats + (iVar17 - 9U & 0x1f);
      lVar28 = (longdouble)pfVar8->time;
      pfVar9 = chan->flow[1].stats + (iVar17 - 10U & 0x1f);
      lVar29 = (longdouble)pfVar9->time;
      pfVar10 = chan->flow[1].stats + (iVar17 - 0xbU & 0x1f);
      lVar30 = (longdouble)pfVar10->time;
      pfVar11 = chan->flow[1].stats + (iVar17 - 0xcU & 0x1f);
      lVar31 = (longdouble)pfVar11->time;
      pfVar12 = chan->flow[1].stats + (iVar17 - 0xdU & 0x1f);
      lVar32 = (longdouble)pfVar12->time;
      pfVar13 = chan->flow[1].stats + (iVar17 - 0xeU & 0x1f);
      lVar33 = (longdouble)pfVar13->time;
      pfVar14 = chan->flow[1].stats + (iVar17 - 0xfU & 0x1f);
      lVar34 = (longdouble)pfVar14->time;
      pfVar15 = chan->flow[1].stats + (iVar17 - 0x10U & 0x1f);
      fVar16 = (float)((lVar34 - (longdouble)pfVar15->time) +
                      (longdouble)
                      (float)((lVar33 - lVar34) +
                             (longdouble)
                             (float)((lVar32 - lVar33) +
                                    (longdouble)
                                    (float)((lVar31 - lVar32) +
                                           (longdouble)
                                           (float)((lVar30 - lVar31) +
                                                  (longdouble)
                                                  (float)((lVar29 - lVar30) +
                                                         (longdouble)
                                                         (float)((lVar28 - lVar29) +
                                                                (longdouble)
                                                                (float)((lVar27 - lVar28) +
                                                                       (longdouble)
                                                                       (float)((lVar26 - lVar27) +
                                                                              (longdouble)
                                                                              (float)((lVar25 - 
                                                  lVar26) + (longdouble)
                                                            (float)((lVar24 - lVar25) +
                                                                   (longdouble)
                                                                   (float)((lVar23 - lVar24) +
                                                                          (longdouble)
                                                                          (float)((lVar22 - lVar23)
                                                                                 + (longdouble)
                                                                                   (float)((lVar35 -
                                                                                           lVar22) +
                                                                                          (
                                                  longdouble)
                                                  (float)(((longdouble)
                                                           chan->flow[1].stats[iVar17 - 1U & 0x1f].
                                                           time - lVar35) + lVar21)))))))))))))));
      fVar18 = 0.0;
      if (fVar16 == 0.0) {
        chan->flow[1].kbytespersec = 0.0;
      }
      else {
        fVar18 = ((float)(iVar20 + pfVar1->size + pfVar2->size + pfVar3->size + pfVar4->size +
                          pfVar5->size + pfVar6->size + pfVar7->size + pfVar8->size + pfVar9->size +
                          pfVar10->size + pfVar11->size + pfVar12->size + pfVar13->size +
                          pfVar14->size + pfVar15->size) / fVar16) * 0.0009765625;
        chan->flow[1].kbytespersec = fVar18;
        fVar18 = fVar18 * 0.33333334;
      }
      chan->flow[1].avgkbytespersec = chan->flow[1].avgkbytespersec * 0.6666667 + fVar18;
    }
  }
  return;
}


// Netchan_UpdateProgress  @ 00088b60
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
  fragbuf_t *pfVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  netchan_t *pnVar13;
  byte local_41c [1036];
  
                    /* Unresolved local var: fragbuf_t * p@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int total@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float bestpercent@[???] */
  scr_downloading.value = -1.0;
  gDownloadFile[0] = '\0';
  if ((net_drawslider.value != 1.0) && (chan->incomingbufs[1] == (fragbuf_t *)0x0)) {
    gDownloadFile[0] = '\0';
    scr_downloading.value = -1.0;
    return;
  }
  pfVar9 = chan->incomingbufs[1];
  iVar12 = 0;
  iVar11 = 0;
  fVar5 = 0.0;
  if (pfVar9 == (fragbuf_t *)0x0) goto LAB_00088c93;
  while( true ) {
    uVar3 = (ushort)pfVar9->bufferid;
    pfVar6 = pfVar9;
    do {
      pfVar6 = pfVar6->next;
      iVar11 = iVar11 + 1;
    } while (pfVar6 != (fragbuf_s *)0x0);
    fVar4 = fVar5;
                    /* Unresolved local var: float percent@[???] */
    if ((uVar3 != 0) && (fVar4 = ((float)iVar11 * 100.0) / (float)uVar3, fVar4 <= fVar5)) {
      fVar4 = fVar5;
    }
    if (iVar12 == 0) break;
    while( true ) {
      pnVar13 = chan;
      if (iVar12 == -1) {
        scr_downloading.value = fVar4;
        return;
      }
LAB_00088c81:
      chan = (netchan_t *)&pnVar13[-1].flow[1].avgkbytespersec;
      iVar12 = iVar12 + -1;
      pfVar9 = pnVar13->incomingbufs[0];
      fVar5 = fVar4;
      if (pfVar9 != (fragbuf_t *)0x0) break;
LAB_00088c93:
      fVar4 = fVar5;
                    /* Unresolved local var: float percent@[???] */
      if (((chan->fragbufs[1] != (fragbuf_t *)0x0) && (chan->fragbufcount[1] != 0)) &&
         (fVar4 = ((float)chan->fragbufs[1]->bufferid * 100.0) / (float)chan->fragbufcount[1],
         fVar4 <= fVar5)) {
        fVar4 = fVar5;
      }
    }
  }
                    /* Unresolved local var: char[1024] sz@[???]
                       Unresolved local var: char * in@[???]
                       Unresolved local var: char * out@[???]
                       Unresolved local var: int len@[???] */
  pbVar10 = (pfVar9->frag_message).data;
  pbVar8 = local_41c;
  pbVar1 = pbVar10 + 0x81;
  do {
    bVar2 = *pbVar10;
    if (bVar2 == '\0') break;
    pbVar10 = pbVar10 + 1;
    *pbVar8 = bVar2;
    pbVar8 = pbVar8 + 1;
  } while (pbVar10 != pbVar1);
  *pbVar8 = '\0';
  iVar7 = Q_strlen((char *)local_41c);
  pnVar13 = chan;
  if (iVar7 < 1) goto LAB_00088c81;
  if ((local_41c[0] == '!') && (iVar7 = Q_strncmp((char *)local_41c,"!ModuleC.dll",0xb), iVar7 != 0)
     ) goto LAB_00088c81;
  Q_strncpy(gDownloadFile,(char *)local_41c,0xff);
  gDownloadFile[0xff] = '\0';
  goto LAB_00088c81;
}


// Netchan_Validate  @ 00087010
qboolean Netchan_Validate(netchan_t *chan,qboolean *frag_message,uint *fragid,int *frag_offset,
                         int *frag_length)

{
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int buffer@[???]
                       Unresolved local var: int count@[???] */
  if ((*frag_message == false) ||
     ((((*fragid < 0x61a90000 && ((ushort)*fragid < 0x61a9)) && ((uint)*frag_length < 0x801)) &&
      ((uint)*frag_offset < 0x4001)))) {
    if (frag_message[1] == false) {
      return true;
    }
    if (((fragid[1] < 0x61a90000) && ((ushort)fragid[1] < 0x61a9)) && ((uint)frag_length[1] < 0x801)
       ) {
      return (uint)((uint)frag_offset[1] < 0x4001);
    }
  }
  return false;
}


