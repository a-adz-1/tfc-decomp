// HashChoosePrimes__6CGraphi  @ 000ce170
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HashChoosePrimes__6CGraphi(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_10;
  
  iVar2 = param_2 / 2;
  if (_DAT_0015271c < param_2 / 2) {
    iVar2 = _DAT_0015271c;
  }
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xf;
  }
  iVar6 = 1;
  iVar5 = 0;
  do {
    local_10 = 0;
    if (Primes != 0) {
      iVar3 = Primes;
      do {
        if ((((local_10 == 0) || (iVar4 = iVar3, param_2 % (&Primes)[local_10] != 0)) &&
            (iVar4 = (&Primes)[local_10], iVar3 <= iVar6)) && (iVar6 <= iVar4)) {
          if (iVar4 - iVar6 < iVar6 - iVar3) {
            *(int *)(param_1 + 0x207c + iVar5 * 4) = iVar4;
            iVar5 = iVar5 + 1;
          }
          else {
            *(int *)(param_1 + 0x207c + iVar5 * 4) = iVar3;
            iVar5 = iVar5 + 1;
          }
          break;
        }
        local_10 = local_10 + 1;
        iVar3 = iVar4;
      } while ((&Primes)[local_10] != 0);
    }
    iVar6 = iVar6 + (iVar2 >> 4);
    if (0xf < iVar5) {
      iVar2 = 0;
      do {
        *(int *)(param_1 + 0x207c + iVar2 * 4) = param_2 - *(int *)(param_1 + 0x207c + iVar2 * 4);
        iVar2 = iVar2 + 2;
      } while (iVar2 < 0x10);
      iVar2 = 0;
      param_1 = param_1 + 0x207c;
      do {
        iVar5 = (*DAT_00175628)(0,0xf - iVar2);
        uVar1 = *(undefined4 *)(iVar5 * 4 + param_1);
        iVar6 = (0xf - iVar2) * 4;
        *(undefined4 *)(iVar5 * 4 + param_1) = *(undefined4 *)(iVar6 + param_1);
        *(undefined4 *)(iVar6 + param_1) = uVar1;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0xf);
      return;
    }
  } while( true );
}


