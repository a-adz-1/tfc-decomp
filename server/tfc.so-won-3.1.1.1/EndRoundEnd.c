// EndRoundEnd__11CBaseEntity  @ 0011174c
void EndRoundEnd__11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *local_8;
  
  cease_fire = 0;
  local_8 = (int *)0x0;
  while( true ) {
    local_8 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(local_8,"player");
    if (local_8 == (int *)0x0) break;
    bVar1 = false;
    if (*(int *)(*local_8 + 0x208) == 0) {
LAB_0011179c:
      bVar1 = true;
    }
    else {
      iVar2 = (*DAT_0019f7b8)(*(int *)(*local_8 + 0x208));
      if (iVar2 == 0) goto LAB_0011179c;
    }
    if (bVar1) break;
    iVar2 = *local_8;
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x244) == 0) {
        *(undefined4 *)(iVar2 + 0x250) = 0;
        local_8[0x22d] = 0;
        *(byte *)((int)local_8 + 0x86) = *(byte *)((int)local_8 + 0x86) & 0xfe;
      }
      TeamFortress_SetSpeed__11CBasePlayer(local_8);
    }
  }
  *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 0x40;
  no_cease_fire_text = 0;
  return;
}


