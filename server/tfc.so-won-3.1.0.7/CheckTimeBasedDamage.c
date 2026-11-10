// CheckTimeBasedDamage__11CBasePlayer  @ 000d8974
void CheckTimeBasedDamage__11CBasePlayer(int *param_1)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int *local_14;
  char local_d;
  
  local_d = '\0';
  fVar3 = (float)param_1[0x281] + (float)param_1[0x282];
  fVar2 = *gpGlobals;
  if ((byte)((fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
    param_1[0x27e] = 0;
  }
  else {
    param_1[0x27e] =
         (int)ROUND(((fVar3 - *gpGlobals) / (float)param_1[0x282]) * (float)param_1[0x280]);
  }
  if ((param_1[0x193] & 0xffc000U) != 0) {
    iVar4 = (int)ROUND(*gpGlobals - (float)param_1[0x209]);
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    if (2.0 <= (double)iVar4) {
      param_1[0x209] = (int)*gpGlobals;
      iVar4 = 0;
      local_14 = param_1 + 0x194;
      do {
        if ((0x8000 << ((byte)iVar4 & 0x1f) & param_1[0x193]) != 0) {
          switch(iVar4) {
          case 0:
          case 1:
          case 3:
          case 5:
          case 6:
          case 7:
            local_d = '\x02';
            break;
          case 2:
            (**(code **)(param_1[0x111] + 0x38))(param_1,*param_1,*param_1,0x40000000,0);
            local_d = '\x05';
            break;
          case 4:
            if ((1.0 <= *(float *)(*param_1 + 0x160)) && (*(int *)(*param_1 + 0x170) == 0)) {
              if (param_1[0x213] < param_1[0x212]) {
                iVar5 = param_1[0x212] - param_1[0x213];
                if (10 < iVar5) {
                  iVar5 = 10;
                }
                (**(code **)(param_1[0x111] + 0x3c))(param_1,(float)iVar5,0);
                param_1[0x213] = param_1[0x213] + iVar5;
              }
              local_d = '\x04';
            }
            break;
          default:
            local_d = '\0';
          }
          if ((char)*local_14 == '\0') {
            *(char *)local_14 = local_d;
          }
          else {
            if ((((iVar4 == 1) && (*(byte *)((int)param_1 + 0x651) < 2)) ||
                ((iVar4 == 2 && (*(byte *)((int)param_1 + 0x652) < 5)))) && (param_1[0x1b5] != 0)) {
              *(char *)local_14 = '\0';
              param_1[0x1b5] = param_1[0x1b5] + -1;
              SetSuitUpdate__11CBasePlayerPcii(param_1,&DAT_0014b440,0,0);
            }
            if (*(char *)((int)param_1 + iVar4 + 0x650) != '\0') {
              pcVar1 = (char *)((int)param_1 + iVar4 + 0x650);
              *pcVar1 = *pcVar1 + -1;
              if (*pcVar1 != '\0') goto LAB_000d8be6;
            }
            *(char *)local_14 = '\0';
            param_1[0x193] = param_1[0x193] & ~(0x8000 << ((byte)iVar4 & 0x1f));
          }
        }
LAB_000d8be6:
        local_14 = (int *)((int)local_14 + 1);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 8);
    }
  }
  return;
}


