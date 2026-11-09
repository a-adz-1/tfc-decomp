// build_number  @ 0804c6f0
int build_number(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (b_24 == 0) {
    iVar3 = 0;
    iVar4 = 0;
    do {
      iVar1 = Q_strncasecmp(date,(&mon)[iVar3],3);
      if (iVar1 == 0) break;
      iVar4 = iVar4 + (char)(&mond)[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xb);
    iVar1 = __strtol_internal(date + 4,0,10,0);
    uVar2 = __strtol_internal(date + 7,0,10,0);
    b_24 = (int)ROUND((double)(int)(uVar2 - 0x76d) * 365.25) + iVar1 + -1 + iVar4;
    if (((uVar2 & 3) == 0) && (1 < iVar3)) {
      b_24 = b_24 + 1;
    }
    b_24 = b_24 + -0x88b3;
  }
  return b_24;
}


