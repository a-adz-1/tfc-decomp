// HashChoosePrimes__6CGraphi  @ 000c8acc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HashChoosePrimes__6CGraphi(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_34;
  int local_10;
  int local_c;
  
  iVar4 = param_2 / 2;
  if (_DAT_00165b7c < param_2 / 2) {
    iVar4 = _DAT_00165b7c;
  }
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0xf;
  }
  local_c = 1;
  iVar5 = 0;
  param_1 = param_1 + 0x207c;
  do {
    local_34 = 0;
    iVar2 = Primes;
    iVar3 = Primes;
    while (iVar3 != 0) {
      if ((((local_34 == 0) || (local_10 = iVar2, param_2 % (&Primes)[local_34] != 0)) &&
          (local_10 = (&Primes)[local_34], iVar2 <= local_c)) && (local_c <= local_10)) {
        if (local_10 - local_c < local_c - iVar2) {
          *(int *)(param_1 + iVar5 * 4) = local_10;
          iVar5 = iVar5 + 1;
        }
        else {
          *(int *)(param_1 + iVar5 * 4) = iVar2;
          iVar5 = iVar5 + 1;
        }
        break;
      }
      local_34 = local_34 + 1;
      iVar2 = local_10;
      iVar3 = (&Primes)[local_34];
    }
    local_c = local_c + (iVar4 >> 4);
    if (0xf < iVar5) {
      iVar4 = 0;
      do {
        *(int *)(param_1 + iVar4 * 4) = param_2 - *(int *)(param_1 + iVar4 * 4);
        iVar4 = iVar4 + 2;
      } while (iVar4 < 0x10);
      iVar4 = 0;
      do {
        iVar5 = (*DAT_0019f808)(0,0xf - iVar4);
        iVar3 = (0xf - iVar4) * 4;
        iVar4 = iVar4 + 1;
        uVar1 = *(undefined4 *)(iVar5 * 4 + param_1);
        *(undefined4 *)(iVar5 * 4 + param_1) = *(undefined4 *)(iVar3 + param_1);
        *(undefined4 *)(iVar3 + param_1) = uVar1;
      } while (iVar4 < 0xf);
      return;
    }
  } while( true );
}


