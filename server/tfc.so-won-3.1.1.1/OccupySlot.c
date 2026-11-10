// OccupySlot__13CSquadMonsteri  @ 000f563c
undefined4 OccupySlot__13CSquadMonsteri(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
  if (iVar2 == 0) {
    uVar3 = 1;
  }
  else {
    iVar2 = SquadEnemySplit__13CSquadMonster(param_1);
    if (iVar2 == 0) {
      iVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x69c);
      iVar2 = param_1;
      if (iVar4 != 0) {
        iVar2 = iVar4;
      }
      uVar1 = *(uint *)(iVar2 + 0x6c4);
      if (param_2 != uVar1) {
        iVar4 = 0;
        do {
          uVar5 = 1 << ((byte)iVar4 & 0x1f);
          if (((param_2 & uVar5) != 0) && ((uVar1 & uVar5) == 0)) {
            *(uint *)(iVar2 + 0x6c4) = uVar1 | uVar5;
            *(uint *)(param_1 + 0x6d0) = uVar5;
            return 1;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0xb);
      }
      uVar3 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x6d0) = 0x400;
      uVar3 = 1;
    }
  }
  return uVar3;
}


