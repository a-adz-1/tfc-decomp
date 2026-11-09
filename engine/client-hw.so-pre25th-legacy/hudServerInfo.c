// hudServerInfo_ValueForKey  @ 001be140
char * hudServerInfo_ValueForKey(char *key)

{
  char *pcVar1;
  
  (*g_engdstAddrs.ServerInfo_ValueForKey)(&key);
  pcVar1 = Info_ValueForKey(cl.serverinfo,key);
  return pcVar1;
}


