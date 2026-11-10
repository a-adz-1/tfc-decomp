// Spy_DisguiseExternalWeaponModel__11CBasePlayer  @ 000e4f58
void Spy_DisguiseExternalWeaponModel__11CBasePlayer(int *param_1)

{
  if ((((*(int *)(*param_1 + 0x20c) == 8) && (param_1[0x19] != 0)) && (param_1[0x76] != 0)) &&
     ((param_1[0x76] != 8 && (param_1[0x76] < 10)))) {
    *(int *)(*param_1 + 0xc0) =
         *(int *)(SpyFakeWeaponArray + param_1[0x76] * 8) - *(int *)(gpGlobals + 0x98);
    strcpy((char *)(param_1 + 0x32b),*(char **)(SpyFakeWeaponArray + param_1[0x76] * 8 + 4));
    param_1[0x333] = 0;
  }
  return;
}


// Spy_RemoveDisguise__11CBasePlayer  @ 000e4e3c
void Spy_RemoveDisguise__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  
  if (*(int *)(*param_1 + 0x20c) == 8) {
    if ((param_1[0x75] != 0) || (param_1[0x76] != 0)) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Disguise_Lost",0,0,0,0);
    }
    param_1[0x75] = 0;
    param_1[0x76] = 0;
    param_1[99] = (int)(*gpGlobals + 10.0);
    param_1[0x19] = 0;
    TeamFortress_SetSkin__11CBasePlayer(param_1);
    TeamFortress_SpyCalcName__11CBasePlayer(param_1);
    Spy_ResetExternalWeaponModel__11CBasePlayer(param_1);
    fVar1 = (float)param_1[0x44];
    if ((((byte)(12.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 12.0) << 0xe) >> 8)) == 0x40) ||
        ((byte)(13.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 13.0) << 0xe) >> 8)) == 0x40)) ||
       ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 14.0) << 0xe) >> 8)) == 0x40)) {
      ResetMenu__11CBasePlayer(param_1);
    }
    iVar2 = FindTimer__11CBaseEntityi(param_1,0xd);
    if (iVar2 != 0) {
      ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Disguise_stop",0,0,0,0);
      UTIL_Remove__FP11CBaseEntity(iVar2);
    }
  }
  return;
}


// Spy_ResetExternalWeaponModel__11CBasePlayer  @ 000e5000
void Spy_ResetExternalWeaponModel__11CBasePlayer(int *param_1)

{
  *(int *)(*param_1 + 0xc0) = param_1[0x33d] - *(int *)(gpGlobals + 0x98);
  strcpy((char *)(param_1 + 0x32b),(char *)(param_1 + 0x335));
  param_1[0x333] = 0;
  return;
}


