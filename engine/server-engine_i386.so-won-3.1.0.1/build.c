// build_number  @ 0004720c
void build_number(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if (b_24 == 0) {
    iVar1 = Q_strncasecmp(date,mon,3);
    iVar4 = 0;
    if (iVar1 != 0) {
      iVar5 = (int)mond;
      iVar1 = Q_strncasecmp(date,PTR_DAT_000b1fa4,3);
      iVar4 = 1;
      if (iVar1 != 0) {
        iVar5 = iVar5 + DAT_000b1fd1;
        iVar1 = Q_strncasecmp(date,PTR_DAT_000b1fa8,3);
        iVar4 = 2;
        if (iVar1 != 0) {
          iVar5 = iVar5 + DAT_000b1fd2;
          iVar1 = 3;
          do {
            iVar2 = Q_strncasecmp(date,(&mon)[iVar1],3);
            iVar4 = iVar1;
            if (iVar2 == 0) break;
            iVar5 = iVar5 + (&mond)[iVar1];
            iVar4 = iVar1 + 1;
            iVar2 = Q_strncasecmp(date,(&mon)[iVar4],3);
            if (iVar2 == 0) break;
            iVar5 = iVar5 + (&DAT_000b1fd1)[iVar1];
            iVar4 = iVar1 + 2;
            iVar2 = Q_strncasecmp(date,(&mon)[iVar4],3);
            if (iVar2 == 0) break;
            iVar5 = iVar5 + (&DAT_000b1fd2)[iVar1];
            iVar4 = iVar1 + 3;
            iVar2 = Q_strncasecmp(date,(&mon)[iVar4],3);
            if (iVar2 == 0) break;
            iVar5 = iVar5 + (char)(&DAT_000b1fd3)[iVar1];
            iVar4 = iVar1 + 4;
            iVar1 = iVar4;
          } while (iVar4 < 0xb);
        }
      }
    }
    iVar1 = __strtol_internal(date + 4,0,10,0);
    uVar3 = __strtol_internal(date + 7,0,10,0);
    b_24 = (int)ROUND((double)(int)(uVar3 - 0x76d) * 365.25) + iVar1 + -1 + iVar5;
    if (((uVar3 & 3) == 0) && (1 < iVar4)) {
      b_24 = b_24 + 1;
    }
    b_24 = b_24 + -0x88b3;
  }
  return;
}


