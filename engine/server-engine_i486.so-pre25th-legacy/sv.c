// sv_cheats_hook_callback  @ 0009bc40
void sv_cheats_hook_callback(cvar_t *cvar)

{
  sizebuf_t *sb;
  qboolean qVar1;
  uint c;
  int iVar2;
  client_s *pcVar3;
  int iVar4;
  
  qVar1 = Host_IsServerActive();
  if (qVar1 != false) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???] */
    if (0 < svs.maxclients) {
      iVar4 = 0;
                    /* Unresolved local var: sizebuf_t * msg@[???] */
      iVar2 = svs.maxclients;
      pcVar3 = svs.clients;
      do {
        if ((pcVar3->fakeclient == false) &&
           (((pcVar3->active != false || (pcVar3->spawned != false)) || (pcVar3->connected != false)
            ))) {
          sb = &(pcVar3->netchan).message;
          MSG_WriteByte(sb,0x36);
          MSG_WriteString(sb,"");
          c = (uint)NAN(sv_cheats.value);
          if (sv_cheats.value != 0.0) {
            c = 1;
          }
          MSG_WriteByte(sb,c);
          iVar2 = svs.maxclients;
        }
        iVar4 = iVar4 + 1;
        pcVar3 = pcVar3 + 1;
      } while (iVar4 < iVar2);
    }
  }
  return;
}


