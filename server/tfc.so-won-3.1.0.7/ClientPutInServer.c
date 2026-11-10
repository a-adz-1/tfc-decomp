// ClientPutInServer__FP7edict_s  @ 0008fb9c
void ClientPutInServer__FP7edict_s(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  piVar1 = (int *)GetClassPtr__H1Z11CBasePlayer_PX01_PX01(param_1 + 0x80);
  SetCustomDecalFrames__11CBasePlayeri(piVar1,0xffffffff);
  piVar1[0xc] = 0;
  *(undefined4 *)(*piVar1 + 0x20c) = 0;
  uVar2 = (*DAT_001c11c8)(*(undefined4 *)(*piVar1 + 0x208));
  (**(code **)(*g_pGameRules + 0x6c))(g_pGameRules,piVar1,uVar2);
  if ((byte)(0.0 < (float)tfc_clanbattle._12_4_ |
             (byte)((ushort)((ushort)NAN((float)tfc_clanbattle._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    ConnectDuringBattle__11CBasePlayer(piVar1);
  }
  (**(code **)(piVar1[0x111] + 0xc))(piVar1);
  *(byte *)(*piVar1 + 0x118) = *(byte *)(*piVar1 + 0x118) | 0x20;
  piVar1[0x1e] = 0;
  iVar4 = 0;
  if (*(uint *)(gpGlobals + 0x90) < 0x80000000) {
    piVar3 = &DAT_001c0904;
    do {
      if (*piVar3 == param_1) {
        piVar1[0x83] = (&g_IpStorage)[iVar4 * 2];
        (&g_IpStorage)[iVar4 * 2] = 0;
        *piVar3 = 0;
        return;
      }
      piVar3 = piVar3 + 2;
      iVar4 = iVar4 + 1;
    } while (iVar4 <= *(int *)(gpGlobals + 0x90));
  }
  return;
}


