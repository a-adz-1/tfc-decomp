// WriteDest_Parm  @ 00136e10
sizebuf_t * WriteDest_Parm(int dest)

{
  sizebuf_t *psVar1;
  int iVar2;
  
  switch(dest) {
  case 0:
    return &sv.datagram;
  case 1:
  case 8:
    iVar2 = NUM_FOR_EDICT((edict_t *)gMsgEntity);
    if ((iVar2 < 1) || (svs.maxclients < iVar2)) {
      Host_Error("WriteDest_Parm: not a client");
    }
    if (dest != 1) {
      return &svs.clients[iVar2 + -1].datagram;
    }
    psVar1 = &svs.clients[iVar2 + -1].netchan.message;
    break;
  case 2:
    return &sv.reliable_datagram;
  case 3:
    return &sv.signon;
  case 4:
  case 5:
    return &sv.multicast;
  default:
    Host_Error("WriteDest_Parm: bad destination=%d",dest);
    psVar1 = (sizebuf_t *)0x0;
    break;
  case 9:
    return &sv.spectator;
  }
  return psVar1;
}


