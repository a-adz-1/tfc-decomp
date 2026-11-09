// hudPhysInfo_ValueForKey  @ 00167330
char * hudPhysInfo_ValueForKey(char *key)

{
  char *pcVar1;
  
  (*g_engdstAddrs.PhysInfo_ValueForKey)(&key);
  pcVar1 = Info_ValueForKey(cls.physinfo,key);
  return pcVar1;
}


