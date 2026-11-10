// HashChoosePrimes__6CGraphi  @ 000c9310
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HashChoosePrimes__6CGraphi(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_c;
  int local_8;
  
  iVar4 = param_2 / 2;
  if (_DAT_00160a5c < param_2 / 2) {
    iVar4 = _DAT_00160a5c;
  }
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0xf;
  }
  iVar5 = 1;
  local_8 = 0;
  do {
    local_c = 0;
    if (Primes != 0) {
      piVar2 = (int *)(param_1 + 0x207c + local_8 * 4);
      iVar6 = 0;
      iVar7 = Primes;
      do {
        if ((((local_c == 0) || (iVar8 = iVar7, param_2 % *(int *)((int)&Primes + iVar6) != 0)) &&
            (iVar8 = *(int *)((int)&Primes + iVar6), iVar7 <= iVar5)) && (iVar5 <= iVar8)) {
          if (iVar8 - iVar5 < iVar5 - iVar7) {
            *piVar2 = iVar8;
            local_8 = local_8 + 1;
          }
          else {
            *piVar2 = iVar7;
            local_8 = local_8 + 1;
          }
          break;
        }
        local_c = local_c + 1;
        piVar1 = (int *)((int)&DAT_001607a4 + iVar6);
        iVar6 = iVar6 + 4;
        iVar7 = iVar8;
      } while (*piVar1 != 0);
    }
    iVar5 = iVar5 + (iVar4 >> 4);
    if (0xf < local_8) {
      *(int *)(param_1 + 0x207c) = param_2 - *(int *)(param_1 + 0x207c);
      *(int *)(param_1 + 0x2084) = param_2 - *(int *)(param_1 + 0x2084);
      *(int *)(param_1 + 0x208c) = param_2 - *(int *)(param_1 + 0x208c);
      *(int *)(param_1 + 0x2094) = param_2 - *(int *)(param_1 + 0x2094);
      *(int *)(param_1 + 0x209c) = param_2 - *(int *)(param_1 + 0x209c);
      *(int *)(param_1 + 0x20a4) = param_2 - *(int *)(param_1 + 0x20a4);
      *(int *)(param_1 + 0x20ac) = param_2 - *(int *)(param_1 + 0x20ac);
      *(int *)(param_1 + 0x20b4) = param_2 - *(int *)(param_1 + 0x20b4);
      local_8 = 0;
      param_1 = param_1 + 0x207c;
      do {
        iVar4 = (*DAT_001c1188)(0,0xf - local_8);
        uVar3 = *(undefined4 *)(iVar4 * 4 + param_1);
        iVar5 = (0xf - local_8) * 4;
        *(undefined4 *)(iVar4 * 4 + param_1) = *(undefined4 *)(iVar5 + param_1);
        *(undefined4 *)(iVar5 + param_1) = uVar3;
        iVar5 = 0xf - (local_8 + 1);
        iVar4 = (*DAT_001c1188)(0,iVar5);
        uVar3 = *(undefined4 *)(iVar4 * 4 + param_1);
        iVar5 = iVar5 * 4;
        *(undefined4 *)(iVar4 * 4 + param_1) = *(undefined4 *)(iVar5 + param_1);
        *(undefined4 *)(iVar5 + param_1) = uVar3;
        iVar5 = 0xf - (local_8 + 2);
        iVar4 = (*DAT_001c1188)(0,iVar5);
        uVar3 = *(undefined4 *)(iVar4 * 4 + param_1);
        iVar5 = iVar5 * 4;
        *(undefined4 *)(iVar4 * 4 + param_1) = *(undefined4 *)(iVar5 + param_1);
        *(undefined4 *)(iVar5 + param_1) = uVar3;
        iVar5 = 0xf - (local_8 + 3);
        iVar4 = (*DAT_001c1188)(0,iVar5);
        uVar3 = *(undefined4 *)(iVar4 * 4 + param_1);
        iVar5 = iVar5 * 4;
        *(undefined4 *)(iVar4 * 4 + param_1) = *(undefined4 *)(iVar5 + param_1);
        *(undefined4 *)(iVar5 + param_1) = uVar3;
        iVar5 = 0xf - (local_8 + 4);
        iVar4 = (*DAT_001c1188)(0,iVar5);
        uVar3 = *(undefined4 *)(iVar4 * 4 + param_1);
        iVar5 = iVar5 * 4;
        *(undefined4 *)(iVar4 * 4 + param_1) = *(undefined4 *)(iVar5 + param_1);
        *(undefined4 *)(iVar5 + param_1) = uVar3;
        local_8 = local_8 + 5;
      } while (local_8 < 0xf);
      return;
    }
  } while( true );
}


