// SetSuitUpdate__11CBasePlayerPcii  @ 000db4a0
void SetSuitUpdate__11CBasePlayerPcii(int *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = -1;
  if ((*(int *)(*param_1 + 0x148) < 0) &&
     (iVar3 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules), iVar3 == 0)) {
    if (param_2 == 0) {
      iVar5 = 0;
      do {
        param_1[iVar5 + 0x1a2] = 0;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 4);
    }
    else {
      if (param_3 == 0) {
        iVar3 = SENTENCEG_Lookup__FPCcPc(param_2,0);
        if (iVar3 < 0) {
          return;
        }
      }
      else {
        iVar3 = SENTENCEG_GetIndex__FPCc(param_2);
        iVar3 = -iVar3;
      }
      iVar4 = 0;
      do {
        if (iVar3 == param_1[iVar4 + 0x1a7]) {
          fVar1 = (float)param_1[iVar4 + 0x1c7];
          fVar2 = *gpGlobals;
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            return;
          }
          param_1[iVar4 + 0x1a7] = 0;
          param_1[iVar4 + 0x1c7] = 0;
          iVar5 = iVar4;
          break;
        }
        if (param_1[iVar4 + 0x1a7] == 0) {
          iVar5 = iVar4;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x20);
      if (param_4 != 0) {
        if (iVar5 < 0) {
          iVar5 = (*DAT_00175628)(0,0x1f);
        }
        param_1[iVar5 + 0x1a7] = iVar3;
        param_1[iVar5 + 0x1c7] = (int)((float)param_4 + *gpGlobals);
      }
      param_1[param_1[0x1a6] + 0x1a2] = iVar3;
      param_1[0x1a6] = param_1[0x1a6] + 1;
      if (param_1[0x1a6] == 4) {
        param_1[0x1a6] = 0;
      }
      fVar1 = (float)param_1[0x1a1];
      fVar2 = *gpGlobals;
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
          fVar1 = *gpGlobals + 0.1;
        }
        else {
          fVar1 = *gpGlobals + 3.5;
        }
        param_1[0x1a1] = (int)fVar1;
      }
    }
  }
  return;
}


