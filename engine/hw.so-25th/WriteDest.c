// WriteDest_Parm  @ 000d3020
sizebuf_t * WriteDest_Parm(int dest)

{
  sizebuf_t *psVar1;
  int iVar2;
  
                    /* Unresolved local var: int entnum@[???] */
  switch(dest) {
  case 0:
    psVar1 = &sv.datagram;
    break;
  case 1:
  case 8:
                    /* Unresolved local var: int entnum@[???] */
    iVar2 = NUM_FOR_EDICT(gMsgEntity);
    if ((iVar2 < 1) || (svs.maxclients < iVar2)) {
                    /* WARNING: Subroutine does not return */
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
                    /* WARNING: Subroutine does not return */
    Host_Error("WriteDest_Parm: bad destination=%d",dest);
  case 9:
    return &sv.spectator;
  }
  return psVar1;
}


