// CheckTimeBasedDamage__11CBasePlayer  @ 000cd2c4
void CheckTimeBasedDamage__11CBasePlayer(int *param_1)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int *piStack_14;
  char local_d;
  
  local_d = '\0';
  fVar3 = (float)param_1[0x264] + (float)param_1[0x265];
  fVar2 = *gpGlobals;
  if ((byte)((fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
    param_1[0x261] = 0;
  }
  else {
    param_1[0x261] =
         (int)ROUND(((fVar3 - *gpGlobals) / (float)param_1[0x265]) * (float)param_1[0x263]);
  }
  if ((param_1[0x177] & 0xffc000U) != 0) {
    iVar4 = (int)ROUND(*gpGlobals - (float)param_1[0x1ed]);
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    if (2.0 <= (double)iVar4) {
      param_1[0x1ed] = (int)*gpGlobals;
      iVar4 = 0;
      piStack_14 = param_1 + 0x178;
      do {
        if ((0x8000 << ((byte)iVar4 & 0x1f) & param_1[0x177]) != 0) {
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
            (**(code **)(param_1[0xf5] + 0x34))(param_1,*param_1,*param_1,0x40000000,0);
            local_d = '\x05';
            break;
          case 4:
            if ((1.0 <= *(float *)(*param_1 + 0x160)) && (*(int *)(*param_1 + 0x170) == 0)) {
              if (param_1[0x1f7] < param_1[0x1f6]) {
                iVar5 = param_1[0x1f6] - param_1[0x1f7];
                if (10 < iVar5) {
                  iVar5 = 10;
                }
                (**(code **)(param_1[0xf5] + 0x38))(param_1,(float)iVar5,0);
                param_1[0x1f7] = param_1[0x1f7] + iVar5;
              }
              local_d = '\x04';
            }
            break;
          default:
            local_d = '\0';
          }
          if ((char)*piStack_14 == '\0') {
            *(char *)piStack_14 = local_d;
          }
          else {
            if ((((iVar4 == 1) && (*(byte *)((int)param_1 + 0x5e1) < 2)) ||
                ((iVar4 == 2 && (*(byte *)((int)param_1 + 0x5e2) < 5)))) && (param_1[0x199] != 0)) {
              *(char *)piStack_14 = '\0';
              param_1[0x199] = param_1[0x199] + -1;
              SetSuitUpdate__11CBasePlayerPcii(param_1,&UNK_0013aae0,0,0);
            }
            if (*(char *)((int)param_1 + iVar4 + 0x5e0) != '\0') {
              pcVar1 = (char *)((int)param_1 + iVar4 + 0x5e0);
              *pcVar1 = *pcVar1 + -1;
              if (*pcVar1 != '\0') goto LAB_000cd536;
            }
            *(char *)piStack_14 = '\0';
            param_1[0x177] = param_1[0x177] & ~(0x8000 << ((byte)iVar4 & 0x1f));
          }
        }
LAB_000cd536:
        piStack_14 = (int *)((int)piStack_14 + 1);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 8);
    }
  }
  return;
}


