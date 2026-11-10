// CheckTimeBasedDamage__11CBasePlayer  @ 000d8418
void CheckTimeBasedDamage__11CBasePlayer(int *param_1)

{
  char cVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined1 local_11;
  
  local_11 = 0;
  fVar2 = (float)param_1[0x28b] + (float)param_1[0x28c];
  if (fVar2 <= *gpGlobals) {
    param_1[0x288] = 0;
  }
  else {
    param_1[0x288] =
         (int)ROUND(((fVar2 - *gpGlobals) / (float)param_1[0x28c]) * (float)param_1[0x28a]);
  }
  if ((param_1[0x197] & 0xffc000U) != 0) {
    iVar4 = (int)ROUND(*gpGlobals - (float)param_1[0x213]);
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    if (2.0 <= (double)iVar4) {
      iVar4 = 0;
      param_1[0x213] = (int)*gpGlobals;
      do {
        if ((param_1[0x197] & 0x8000 << ((byte)iVar4 & 0x1f)) != 0) {
          switch(iVar4) {
          case 0:
          case 1:
          case 3:
          case 5:
          case 6:
          case 7:
            local_11 = 2;
            break;
          case 2:
            (**(code **)(param_1[0x115] + 0x38))(param_1,*param_1,*param_1,0x40000000,0);
            local_11 = 5;
            break;
          case 4:
            if ((1.0 <= *(float *)(*param_1 + 0x160)) && (*(int *)(*param_1 + 0x170) == 0)) {
              if (param_1[0x21d] < param_1[0x21c]) {
                iVar3 = param_1[0x21c] - param_1[0x21d];
                if (10 < iVar3) {
                  iVar3 = 10;
                }
                (**(code **)(param_1[0x115] + 0x3c))(param_1,(float)iVar3,0);
                param_1[0x21d] = param_1[0x21d] + iVar3;
              }
              local_11 = 4;
            }
            break;
          default:
            local_11 = 0;
          }
          if (*(char *)((int)param_1 + iVar4 + 0x660) == '\0') {
            *(undefined1 *)((int)param_1 + iVar4 + 0x660) = local_11;
          }
          else {
            if ((((iVar4 == 1) && (*(byte *)((int)param_1 + 0x661) < 2)) ||
                ((iVar4 == 2 && (*(byte *)((int)param_1 + 0x662) < 5)))) && (param_1[0x1be] != 0)) {
              *(undefined1 *)((int)param_1 + iVar4 + 0x660) = 0;
              param_1[0x1be] = param_1[0x1be] + -1;
              SetSuitUpdate__11CBasePlayerPcii(param_1,FUN_00150748,0,0);
            }
            cVar1 = *(char *)((int)param_1 + iVar4 + 0x660);
            if ((cVar1 == '\0') ||
               (*(char *)((int)param_1 + iVar4 + 0x660) = cVar1 + -1, cVar1 == '\x01')) {
              *(undefined1 *)((int)param_1 + iVar4 + 0x660) = 0;
              param_1[0x197] = param_1[0x197] & ~(0x8000 << ((byte)iVar4 & 0x1f));
            }
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 8);
    }
  }
  return;
}


