// ClientPutInServer__FP7edict_s  @ 000a1ff0
void ClientPutInServer__FP7edict_s(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)GetClassPtr__H1Z11CBasePlayer_PX01_PX01(param_1 + 0xdc);
  SetCustomDecalFrames__11CBasePlayeri(piVar1,0xffffffff);
  piVar1[0xd] = 0;
  piVar1[0xb] = 0;
  uVar2 = (*DAT_00175668)(*(undefined4 *)(*piVar1 + 0x1e8));
  (**(code **)(*g_pGameRules + 0x6c))(g_pGameRules,piVar1,uVar2);
  if ((byte)(0.0 < (float)tfc_clanbattle._12_4_ |
             (byte)((ushort)((ushort)NAN((float)tfc_clanbattle._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)tfc_clanbattle._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    ConnectDuringBattle__11CBasePlayer(piVar1);
  }
  (**(code **)(piVar1[0xf2] + 8))(piVar1);
  piVar1[0x1f] = 0;
  iVar3 = 0;
  if (*(uint *)(gpGlobals + 0x90) < 0x80000000) {
    do {
      if ((&DAT_00175384)[iVar3 * 2] == param_1) {
        piVar1[0x83] = (&g_IpStorage)[iVar3 * 2];
        (&g_IpStorage)[iVar3 * 2] = 0;
        (&DAT_00175384)[iVar3 * 2] = 0;
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= *(int *)(gpGlobals + 0x90));
  }
  return;
}


