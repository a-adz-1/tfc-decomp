// sv_cheats_hook_callback  @ 00080910
void sv_cheats_hook_callback(cvar_t *cvar)

{
  qboolean qVar1;
  uint c;
  int iVar2;
  sizebuf_t *sb;
  int iVar3;
  
  qVar1 = Host_IsServerActive();
  if (qVar1 != false) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???] */
    if (0 < svs.maxclients) {
      sb = &((svs.clients)->netchan).message;
                    /* Unresolved local var: sizebuf_t * msg@[???] */
      iVar3 = 0;
      iVar2 = svs.maxclients;
      do {
        if ((sb[0x291].cursize == 0) &&
           (((*(int *)&sb[-6].flags != 0 || (sb[-6].data != (byte *)0x0)) || (sb[-6].cursize != 0)))
           ) {
          MSG_WriteByte(sb,0x36);
          MSG_WriteString(sb,"");
          c = (uint)NAN(sv_cheats.value);
          if (sv_cheats.value != 0.0) {
            c = 1;
          }
          MSG_WriteByte(sb,c);
          iVar2 = svs.maxclients;
        }
        iVar3 = iVar3 + 1;
        sb = (sizebuf_t *)&sb[0x51e].cursize;
      } while (iVar3 < iVar2);
    }
  }
  return;
}


