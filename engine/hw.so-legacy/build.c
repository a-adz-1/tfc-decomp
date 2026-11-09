// build_number  @ 00104e80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int build_number(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  
                    /* Unresolved local var: int m@[???]
                       Unresolved local var: int d@[???]
                       Unresolved local var: int y@[???] */
  if (build_number::b != 0) {
    return build_number::b;
  }
  iVar2 = Q_strncasecmp(date,mon[0],3);
  if (iVar2 == 0) {
    iVar2 = 0;
    uVar5 = 0;
  }
  else {
    iVar2 = (int)mond[0];
    iVar3 = Q_strncasecmp(date,mon[1],3);
    if (iVar3 == 0) {
      uVar5 = 1;
    }
    else {
      iVar2 = iVar2 + mond[1];
      iVar3 = Q_strncasecmp(date,mon[2],3);
      if (iVar3 == 0) {
        uVar5 = 2;
      }
      else {
        iVar2 = iVar2 + mond[2];
        iVar3 = Q_strncasecmp(date,mon[3],3);
        if (iVar3 == 0) {
          uVar5 = 3;
        }
        else {
          iVar2 = iVar2 + mond[3];
          iVar3 = Q_strncasecmp(date,mon[4],3);
          if (iVar3 == 0) {
            uVar5 = 4;
          }
          else {
            iVar2 = iVar2 + mond[4];
            iVar3 = Q_strncasecmp(date,mon[5],3);
            if (iVar3 == 0) {
              uVar5 = 5;
            }
            else {
              iVar2 = iVar2 + mond[5];
              iVar3 = Q_strncasecmp(date,mon[6],3);
              if (iVar3 == 0) {
                uVar5 = 6;
              }
              else {
                iVar2 = iVar2 + mond[6];
                iVar3 = Q_strncasecmp(date,mon[7],3);
                if (iVar3 == 0) {
                  uVar5 = 7;
                }
                else {
                  iVar2 = iVar2 + mond[7];
                  iVar3 = Q_strncasecmp(date,mon[8],3);
                  if (iVar3 == 0) {
                    uVar5 = 8;
                  }
                  else {
                    iVar2 = iVar2 + mond[8];
                    iVar3 = Q_strncasecmp(date,mon[9],3);
                    if (iVar3 == 0) {
                      uVar5 = 9;
                    }
                    else {
                      iVar2 = iVar2 + mond[9];
                      iVar3 = Q_strncasecmp(date,mon[10],3);
                      if (iVar3 != 0) {
                        bVar1 = true;
                        iVar2 = iVar2 + mond[10];
                        goto LAB_001050a2;
                      }
                      uVar5 = 10;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  bVar1 = 1 < uVar5;
LAB_001050a2:
  lVar4 = strtol(date + 4,(char **)0x0,10);
  uVar5 = strtol(date + 7,(char **)0x0,10);
  iVar2 = iVar2 + -1 + lVar4 + (int)((float)(int)(uVar5 - 0x76d) * 365.25);
  if ((uVar5 & 3) == 0) {
    iVar2 = (iVar2 + 1) - (uint)!bVar1;
  }
  build_number::b = iVar2 + -0x88b3;
  return iVar2 + -0x88b3;
}


