// HACK_GetPlayerUniqueID  @ 000b4a20
bool HACK_GetPlayerUniqueID(int iPlayer,char *playerID)

{
  qboolean qVar1;
  
  qVar1 = (*gEngfuncs.GetPlayerUniqueID)(iPlayer,playerID);
  return qVar1 != 0;
}


