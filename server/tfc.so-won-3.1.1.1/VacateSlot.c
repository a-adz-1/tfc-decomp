// VacateSlot__13CSquadMonster  @ 000f55d8
void VacateSlot__13CSquadMonster(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x6d0) != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
    if (iVar1 != 0) {
      iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
      iVar1 = param_1;
      if (iVar2 != 0) {
        iVar1 = iVar2;
      }
      *(uint *)(iVar1 + 0x6c4) = *(uint *)(iVar1 + 0x6c4) & ~*(uint *)(param_1 + 0x6d0);
      *(undefined4 *)(param_1 + 0x6d0) = 0;
    }
  }
  return;
}


