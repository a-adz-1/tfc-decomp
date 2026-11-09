// build_number  @ 00035e80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int build_number(void)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int m@[???]
                       Unresolved local var: int d@[???]
                       Unresolved local var: int y@[???] */
  if (build_number::b == 0) {
    iVar6 = 0;
    iVar7 = 0;
    do {
      iVar3 = Q_strncasecmp(date,mon[iVar6],3);
      if (iVar3 == 0) {
        bVar2 = 1 < iVar6;
        goto LAB_00035eda;
      }
      pcVar1 = mond + iVar6;
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + *pcVar1;
    } while (iVar6 != 0xb);
    bVar2 = true;
LAB_00035eda:
    lVar4 = strtol(date + 4,(char **)0x0,10);
    uVar5 = strtol(date + 7,(char **)0x0,10);
    iVar6 = (int)((float)(int)(uVar5 - 0x76d) * 365.25) + iVar7 + -1 + lVar4;
    if ((uVar5 & 3) == 0) {
      iVar6 = (iVar6 + 1) - (uint)!bVar2;
    }
    build_number::b = iVar6 + -0x88b3;
  }
  return build_number::b;
}


