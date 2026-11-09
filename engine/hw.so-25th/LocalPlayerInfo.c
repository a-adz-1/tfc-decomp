// LocalPlayerInfo_ValueForKey  @ 00167400
char * LocalPlayerInfo_ValueForKey(char *key)

{
  char *pcVar1;
  
  (*g_engdstAddrs.LocalPlayerInfo_ValueForKey)(&key);
  pcVar1 = Info_ValueForKey(cls.userinfo,key);
  return pcVar1;
}


