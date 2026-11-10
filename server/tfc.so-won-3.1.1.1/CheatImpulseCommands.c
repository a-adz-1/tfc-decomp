// CheatImpulseCommands__11CBasePlayeri  @ 000db028
void CheatImpulseCommands__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int local_9c;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  undefined1 local_74 [48];
  int local_44;
  
  if ((byte)(0.0 < g_flWeaponCheat | (byte)((ushort)((ushort)NAN(g_flWeaponCheat) << 10) >> 8) |
            (byte)((ushort)((ushort)(g_flWeaponCheat == 0.0) << 0xe) >> 8)) != 0x40) {
    if (param_2 == 0xc3) {
      iVar1 = *param_1 + 0x50;
      iVar2 = *param_1 + 8;
      pcVar3 = "node_viewer_fly";
    }
    else {
      if (param_2 < 0xc4) {
        if (param_2 == 0x68) {
          DumpGlobals__12CGlobalState(&gGlobalState);
          return;
        }
        if (param_2 != 0x6b) {
          return;
        }
        local_9c = (*DAT_0019f7c0)(0);
        iVar1 = *param_1;
        local_80 = *(float *)(iVar1 + 8) + *(float *)(iVar1 + 0x174);
        local_7c = *(float *)(iVar1 + 0xc) + *(float *)(iVar1 + 0x178);
        local_78 = *(float *)(iVar1 + 0x10) + *(float *)(iVar1 + 0x17c);
        local_8c = local_80 + *(float *)(gpGlobals + 0x28) * 1024.0;
        local_88 = local_7c + *(float *)(gpGlobals + 0x2c) * 1024.0;
        local_84 = local_78 + *(float *)(gpGlobals + 0x30) * 1024.0;
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (&local_80,&local_8c,1,*(undefined4 *)(iVar1 + 0x208),local_74);
        if (local_44 != 0) {
          local_9c = local_44;
        }
        iVar1 = (*DAT_0019f730)(local_9c,&local_80,&local_8c);
        if (iVar1 == 0) {
          return;
        }
        (*DAT_0019f794)(1,"Texture: %s\n",iVar1);
        return;
      }
      if (param_2 == 0xc5) {
        iVar1 = *param_1 + 0x50;
        iVar2 = *param_1 + 8;
        pcVar3 = "node_viewer_human";
      }
      else {
        if (0xc4 < param_2) {
          if (param_2 != 199) {
            return;
          }
          uVar4 = FindNearestNode__6CGraphRC6Vectori(&WorldGraph,*param_1 + 8,7);
          (*DAT_0019f794)(1,&UNK_00150afd,uVar4);
          uVar4 = FindNearestNode__6CGraphRC6Vectori(&WorldGraph,*param_1 + 8,7);
          ShowNodeConnections__6CGraphi(&WorldGraph,uVar4);
          return;
        }
        iVar1 = *param_1 + 0x50;
        iVar2 = *param_1 + 8;
        pcVar3 = "node_viewer_large";
      }
    }
    Create__11CBaseEntityPcRC6VectorT2P7edict_s(pcVar3,iVar2,iVar1,0);
  }
  return;
}


