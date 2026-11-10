// VacateSlot__13CSquadMonster  @ 000e5760
void VacateSlot__13CSquadMonster(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x650) != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x61c);
    if (iVar1 != 0) {
      iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x61c);
      iVar1 = param_1;
      if (iVar2 != 0) {
        iVar1 = iVar2;
      }
      *(uint *)(iVar1 + 0x644) = *(uint *)(iVar1 + 0x644) & ~*(uint *)(param_1 + 0x650);
      *(undefined4 *)(param_1 + 0x650) = 0;
    }
  }
  return;
}


