// CheckTimeBasedDamage__11CBasePlayer  @ 000db0a0
void CheckTimeBasedDamage__11CBasePlayer(undefined4 *param_1)

{
  char *pcVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  
  if ((float)param_1[0x25d] + (float)param_1[0x25e] <= *gpGlobals) {
    param_1[0x25a] = 0;
  }
  else {
    param_1[0x25a] =
         (int)ROUND(((((float)param_1[0x25d] + (float)param_1[0x25e]) - *gpGlobals) /
                    (float)param_1[0x25e]) * (float)(int)param_1[0x25c]);
  }
  if ((param_1[0x174] & 0xffc000) != 0) {
    iVar3 = (int)ROUND(*gpGlobals - (float)param_1[0x1e8]);
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if (2.0 <= (double)iVar3) {
      param_1[0x1e8] = *gpGlobals;
      iVar3 = 0;
      do {
        if ((0x8000 << ((byte)iVar3 & 0x1f) & param_1[0x174]) != 0) {
          switch(iVar3) {
          case 0:
          case 1:
          case 3:
          case 5:
          case 6:
          case 7:
            uVar2 = 2;
            break;
          case 2:
            (**(code **)(param_1[0xf2] + 0x34))(param_1,*param_1,*param_1,0x40000000,0);
            uVar2 = 5;
            break;
          case 4:
            if ((int)param_1[0x1f2] < (int)param_1[0x1f1]) {
              iVar4 = param_1[0x1f1] - param_1[0x1f2];
              if (10 < iVar4) {
                iVar4 = 10;
              }
              (**(code **)(param_1[0xf2] + 0x38))(param_1,(float)iVar4,0);
              param_1[0x1f2] = param_1[0x1f2] + iVar4;
            }
            uVar2 = 4;
            break;
          default:
            uVar2 = 0;
          }
          if (*(char *)(iVar3 + 0x5d4 + (int)param_1) == '\0') {
            *(undefined1 *)(iVar3 + 0x5d4 + (int)param_1) = uVar2;
          }
          else {
            if ((((iVar3 == 1) && (*(byte *)((int)param_1 + 0x5d5) < 2)) ||
                ((iVar3 == 2 && (*(byte *)((int)param_1 + 0x5d6) < 5)))) && (param_1[0x195] != 0)) {
              *(undefined1 *)(iVar3 + 0x5d4 + (int)param_1) = 0;
              param_1[0x195] = param_1[0x195] + -1;
              SetSuitUpdate__11CBasePlayerPcii(param_1,"!HEV_HEAL4",0,0);
            }
            if (*(char *)((int)param_1 + iVar3 + 0x5d4) != '\0') {
              pcVar1 = (char *)((int)param_1 + iVar3 + 0x5d4);
              *pcVar1 = *pcVar1 + -1;
              if (*pcVar1 != '\0') goto LAB_000db287;
            }
            *(undefined1 *)(iVar3 + 0x5d4 + (int)param_1) = 0;
            param_1[0x174] = param_1[0x174] & ~(0x8000 << ((byte)iVar3 & 0x1f));
          }
        }
LAB_000db287:
        iVar3 = iVar3 + 1;
      } while (iVar3 < 8);
    }
  }
  return;
}


