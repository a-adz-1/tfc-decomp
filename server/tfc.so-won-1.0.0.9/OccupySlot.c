// OccupySlot__13CSquadMonsteri  @ 000ef2e0
undefined4 OccupySlot__13CSquadMonsteri(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    iVar1 = SquadEnemySplit__13CSquadMonster(param_1);
    if (iVar1 == 0) {
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x610);
      iVar1 = param_1;
      if (iVar3 != 0) {
        iVar1 = iVar3;
      }
      if (param_2 != *(uint *)(iVar1 + 0x638)) {
        iVar3 = 0;
        do {
          uVar4 = 1 << ((byte)iVar3 & 0x1f);
          if (((param_2 & uVar4) != 0) && ((*(uint *)(iVar1 + 0x638) & uVar4) == 0)) {
            *(uint *)(iVar1 + 0x638) = *(uint *)(iVar1 + 0x638) | uVar4;
            *(uint *)(param_1 + 0x644) = uVar4;
            return 1;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0xb);
      }
      uVar2 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x644) = 0x400;
      uVar2 = 1;
    }
  }
  return uVar2;
}


