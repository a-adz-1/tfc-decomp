// SetSuitUpdate__11CBasePlayerPcii  @ 000d88e4
void SetSuitUpdate__11CBasePlayerPcii(int *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int local_18;
  int local_c;
  
  local_c = -1;
  if ((*(int *)(*param_1 + 0x168) < 0) &&
     (iVar3 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules), iVar3 == 0)) {
    if (param_2 == 0) {
      iVar3 = 0;
      do {
        param_1[iVar3 + 0x1cd] = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
    }
    else {
      if (param_3 == 0) {
        local_18 = SENTENCEG_Lookup__FPCcPc(param_2,0);
        if (local_18 < 0) {
          return;
        }
      }
      else {
        local_18 = SENTENCEG_GetIndex__FPCc(param_2);
        local_18 = -local_18;
      }
      iVar3 = 0;
      do {
        if (local_18 == param_1[iVar3 + 0x1d2]) {
          fVar1 = *gpGlobals;
          fVar2 = (float)param_1[iVar3 + 0x1f2];
          if ((byte)((fVar1 < fVar2 |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
            return;
          }
          param_1[iVar3 + 0x1d2] = 0;
          param_1[iVar3 + 0x1f2] = 0;
          local_c = iVar3;
          break;
        }
        if (param_1[iVar3 + 0x1d2] == 0) {
          local_c = iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x20);
      if (param_4 != 0) {
        if (local_c < 0) {
          local_c = (*DAT_0019f808)(0,0x1f);
        }
        param_1[local_c + 0x1d2] = local_18;
        param_1[local_c + 0x1f2] = (int)(*gpGlobals + (float)param_4);
      }
      param_1[param_1[0x1d1] + 0x1cd] = local_18;
      param_1[0x1d1] = param_1[0x1d1] + 1;
      if (param_1[0x1d1] == 4) {
        param_1[0x1d1] = 0;
      }
      fVar1 = (float)param_1[0x1cc];
      fVar2 = *gpGlobals;
      if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 1) {
        if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
          param_1[0x1cc] = (int)(fVar2 + 0.1);
        }
        else {
          param_1[0x1cc] = (int)(fVar2 + 3.5);
        }
      }
    }
  }
  return;
}


