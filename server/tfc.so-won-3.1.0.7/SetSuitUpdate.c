// SetSuitUpdate__11CBasePlayerPcii  @ 000d8e54
void SetSuitUpdate__11CBasePlayerPcii(int *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *local_18;
  int local_10;
  int local_8;
  
  iVar5 = -1;
  if ((*(int *)(*param_1 + 0x168) < 0) &&
     (iVar2 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules), iVar2 == 0)) {
    if (param_2 == 0) {
      param_1[0x1c6] = 0;
      param_1[0x1c5] = 0;
      param_1[0x1c4] = 0;
      param_1[0x1c3] = 0;
    }
    else {
      if (param_3 == 0) {
        local_8 = SENTENCEG_Lookup__FPCcPc(param_2,0);
        if (local_8 < 0) {
          return;
        }
      }
      else {
        local_8 = SENTENCEG_GetIndex__FPCc(param_2);
        local_8 = -local_8;
      }
      iVar2 = 0;
      local_10 = 0;
      local_18 = param_1 + 0x1c8;
      do {
        if (local_8 == *local_18) {
          if (*gpGlobals <= *(float *)((int)param_1 + local_10 + 0x7a0)) {
            return;
          }
          *local_18 = 0;
          *(undefined4 *)((int)param_1 + local_10 + 0x7a0) = 0;
          iVar5 = iVar2;
          break;
        }
        if (*local_18 == 0) {
          iVar5 = iVar2;
        }
        iVar4 = local_10 + 4;
        iVar3 = iVar2 + 1;
        if (local_8 == local_18[1]) {
          if (*gpGlobals <= *(float *)((int)param_1 + local_10 + 0x7a4)) {
            return;
          }
          local_18[1] = 0;
LAB_000d905b:
          *(undefined4 *)((int)param_1 + iVar4 + 0x7a0) = 0;
          iVar5 = iVar3;
          break;
        }
        if (local_18[1] == 0) {
          iVar5 = iVar3;
        }
        iVar4 = local_10 + 8;
        iVar3 = iVar2 + 2;
        if (local_8 == local_18[2]) {
          if (*gpGlobals <= *(float *)((int)param_1 + local_10 + 0x7a8)) {
            return;
          }
          local_18[2] = 0;
          goto LAB_000d905b;
        }
        if (local_18[2] == 0) {
          iVar5 = iVar3;
        }
        iVar4 = local_10 + 0xc;
        iVar3 = iVar2 + 3;
        if (local_8 == local_18[3]) {
          if (*gpGlobals <= *(float *)((int)param_1 + local_10 + 0x7ac)) {
            return;
          }
          local_18[3] = 0;
          goto LAB_000d905b;
        }
        if (local_18[3] == 0) {
          iVar5 = iVar3;
        }
        local_18 = local_18 + 4;
        local_10 = local_10 + 0x10;
        iVar2 = iVar2 + 4;
      } while (iVar2 < 0x20);
      if (param_4 != 0) {
        if (iVar5 < 0) {
          iVar5 = (*DAT_001c1188)(0,0x1f);
        }
        param_1[iVar5 + 0x1c8] = local_8;
        param_1[iVar5 + 0x1e8] = (int)((float)param_4 + *gpGlobals);
      }
      param_1[param_1[0x1c7] + 0x1c3] = local_8;
      param_1[0x1c7] = param_1[0x1c7] + 1;
      if (param_1[0x1c7] == 4) {
        param_1[0x1c7] = 0;
      }
      fVar1 = (float)param_1[0x1c2];
      if (fVar1 <= *gpGlobals) {
        if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
          fVar1 = *gpGlobals + 0.1;
        }
        else {
          fVar1 = *gpGlobals + 3.5;
        }
        param_1[0x1c2] = (int)fVar1;
      }
    }
  }
  return;
}


