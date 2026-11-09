// LocalPlayerInfo_ValueForKey  @ 001be0b0
char * LocalPlayerInfo_ValueForKey(char *key)

{
  char *pcVar1;
  
  (*g_engdstAddrs.LocalPlayerInfo_ValueForKey)(&key);
  pcVar1 = Info_ValueForKey(cls.userinfo,key);
  return pcVar1;
}


