// VacateSlot__13CSquadMonster  @ 000ef3b0
void VacateSlot__13CSquadMonster(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x644) != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
    if (iVar1 != 0) {
      iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
      iVar1 = param_1;
      if (iVar2 != 0) {
        iVar1 = iVar2;
      }
      *(uint *)(iVar1 + 0x638) = *(uint *)(iVar1 + 0x638) & ~*(uint *)(param_1 + 0x644);
      *(undefined4 *)(param_1 + 0x644) = 0;
    }
  }
  return;
}


