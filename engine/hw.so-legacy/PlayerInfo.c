// PlayerInfo_SetValueForKey  @ 001be1a0
void PlayerInfo_SetValueForKey(char *key,char *value)

{
  char *__s1;
  int iVar1;
  char *pcVar2;
  
  pcVar2 = value;
                    /* Unresolved local var: size_t __s1_len@[???]
                       Unresolved local var: size_t __s2_len@[???] */
  __s1 = Info_ValueForKey(cls.userinfo,key);
  iVar1 = strcmp(__s1,pcVar2);
  if (iVar1 != 0) {
    (*g_engdstAddrs.PlayerInfo_SetValueForKey)(&key,&value);
    Info_SetValueForStarKey(cls.userinfo,key,value,0x100);
    if (ca_connecting < cls.state) {
      MSG_WriteByte(&cls.netchan.message,3);
      pcVar2 = va("setinfo \"%s\" \"%s\"\n",key,value);
      SZ_Print(&cls.netchan.message,pcVar2);
      return;
    }
  }
  return;
}


// PlayerInfo_ValueForKey  @ 001be0e0
char * PlayerInfo_ValueForKey(int playerNum,char *key)

{
  char *pcVar1;
  
  (*g_engdstAddrs.PlayerInfo_ValueForKey)(&playerNum,&key);
  pcVar1 = (char *)0x0;
  if (((playerNum <= cl.maxclients) && (0 < playerNum)) &&
     (*(char *)((int)cl.viewent.ph + playerNum * 0x250 + 0x690) != '\0')) {
    pcVar1 = Info_ValueForKey((char *)((int)cl.viewent.ph + playerNum * 0x250 + 0x590),key);
  }
  return pcVar1;
}


