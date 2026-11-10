// CleanupOnPlayerDisconnection__11CBasePlayer  @ 000d6a00
void CleanupOnPlayerDisconnection__11CBasePlayer(int *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *local_8;
  
  TeamFortress_RemoveTimers__11CBasePlayer(param_1);
  if ((param_1[0x21] & 1U) != 0) {
    param_1[0x20] = 1;
    param_1[0x21] = param_1[0x21] & 0xfffffffe;
  }
  TeamFortress_RemoveLiveGrenades__11CBasePlayer(param_1);
  TeamFortress_RemoveRockets__11CBasePlayer(param_1);
  TeamFortress_RemoveDetpacks__11CBasePlayer(param_1);
  param_1[0x36a] = 1;
  param_1[0x36b] = 1;
  Engineer_RemoveBuildings__11CBasePlayer(param_1);
  for (piVar2 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"detpack");
      piVar2 != (int *)0x0;
      piVar2 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar2,"detpack")) {
    if (((byte)((byte)((ushort)((ushort)NAN((float)piVar2[0x42]) << 10) >> 8) |
               (byte)((ushort)((ushort)((float)piVar2[0x42] == 1.0) << 0xe) >> 8)) == 0x40) &&
       (*(int *)(*piVar2 + 400) == *(int *)(*param_1 + 0x208))) {
      piVar2[0x42] = 0;
    }
    if (*(int *)(*piVar2 + 0x198) == *(int *)(*param_1 + 0x208)) {
      if ((byte)((byte)((ushort)((ushort)NAN((float)piVar2[0x42]) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)piVar2[0x42] == 1.0) << 0xe) >> 8)) == 0x40) {
        iVar3 = *(int *)(*piVar2 + 400);
        bVar1 = false;
        if ((iVar3 == 0) || (iVar3 = (*DAT_0019f7b8)(iVar3), iVar3 == 0)) {
          bVar1 = true;
        }
        if (!bVar1) {
          iVar3 = *(int *)(*piVar2 + 400);
          if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
            iVar3 = 0;
          }
          else {
            iVar3 = *(int *)(iVar3 + 0x7c);
          }
          *(byte *)(iVar3 + 0x86) = *(byte *)(iVar3 + 0x86) & 0xfe;
          TeamFortress_SetSpeed__11CBasePlayer(iVar3);
          uVar4 = FindTimer__11CBaseEntityi(iVar3,10);
          UTIL_Remove__FP11CBaseEntity(uVar4);
        }
      }
      piVar2[3] = -0x10000;
      piVar2[4] = (int)SUB_Remove__11CBaseEntity;
      *(undefined4 *)(*piVar2 + 0x104) = *gpGlobals;
    }
  }
  local_8 = (int *)0x0;
  while( true ) {
    local_8 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(local_8,"player");
    if (local_8 == (int *)0x0) {
      return;
    }
    bVar1 = false;
    if ((*(int *)(*local_8 + 0x208) == 0) ||
       (iVar3 = (*DAT_0019f7b8)(*(int *)(*local_8 + 0x208)), iVar3 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    if ((*local_8 != 0) && (local_8 != param_1)) {
      if ((*(int *)(*local_8 + 0x20c) == 8) &&
         (piVar2 = (int *)__opP11CBaseEntity__7EHANDLE(local_8 + 0x77), piVar2 == param_1)) {
        TeamFortress_SpyCalcName__11CBasePlayer(local_8);
      }
      piVar2 = (int *)__opP11CBaseEntity__7EHANDLE(local_8 + 0x1a7);
      if (piVar2 == param_1) {
        uVar4 = *(undefined4 *)(*local_8 + 0x244);
        *(undefined4 *)(*local_8 + 0x244) = 0;
        __as__7EHANDLEP11CBaseEntity(local_8 + 0x1a7,0);
        Observer_SetMode__11CBasePlayeri(local_8,uVar4);
      }
    }
  }
  return;
}


