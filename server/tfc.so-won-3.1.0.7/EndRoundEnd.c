// EndRoundEnd__11CBaseEntity  @ 0010ee28
void EndRoundEnd__11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  cease_fire = 0;
  piVar3 = (int *)0x0;
  while( true ) {
    piVar3 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar3,"player");
    if (piVar3 == (int *)0x0) break;
    bVar1 = false;
    if (*(int *)(*piVar3 + 0x208) == 0) {
LAB_0010ee82:
      bVar1 = true;
    }
    else {
      iVar2 = (*DAT_001c1138)(*(int *)(*piVar3 + 0x208));
      if (iVar2 == 0) goto LAB_0010ee82;
    }
    if (bVar1) break;
    if (*piVar3 != 0) {
      if (*(int *)(*piVar3 + 0x244) == 0) {
        *(undefined4 *)(*piVar3 + 0x250) = 0;
        piVar3[0x223] = 0;
        *(byte *)((int)piVar3 + 0x86) = *(byte *)((int)piVar3 + 0x86) & 0xfe;
      }
      TeamFortress_SetSpeed__11CBasePlayer(piVar3);
    }
  }
  *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 0x40;
  no_cease_fire_text = 0;
  return;
}


