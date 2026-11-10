// ClientPutInServer__FP7edict_s  @ 0008f454
void ClientPutInServer__FP7edict_s(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)GetClassPtr__H1Z11CBasePlayer_PX01_PX01(param_1 + 0x80);
  SetCustomDecalFrames__11CBasePlayeri(piVar1,0xffffffff);
  piVar1[0xc] = 0;
  *(undefined4 *)(*piVar1 + 0x20c) = 0;
  uVar2 = (*DAT_0019f848)(*(undefined4 *)(*piVar1 + 0x208));
  (**(code **)(*g_pGameRules + 0x6c))(g_pGameRules,piVar1,uVar2);
  if ((byte)((float)tfc_clanbattle._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)tfc_clanbattle._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    ConnectDuringBattle__11CBasePlayer(piVar1);
  }
  (**(code **)(piVar1[0x115] + 0xc))(piVar1);
  *(byte *)(*piVar1 + 0x118) = *(byte *)(*piVar1 + 0x118) | 0x20;
  piVar1[0x1e] = 0;
  iVar3 = 0;
  if (*(uint *)(gpGlobals + 0x90) < 0x80000000) {
    do {
      if ((&DAT_0019ef84)[iVar3 * 2] == param_1) {
        piVar1[0x83] = (&g_IpStorage)[iVar3 * 2];
        (&g_IpStorage)[iVar3 * 2] = 0;
        (&DAT_0019ef84)[iVar3 * 2] = 0;
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= *(int *)(gpGlobals + 0x90));
  }
  return;
}


