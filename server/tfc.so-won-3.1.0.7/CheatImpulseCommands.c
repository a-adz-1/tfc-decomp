// CheatImpulseCommands__11CBasePlayeri  @ 000dbf54
void CheatImpulseCommands__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  undefined1 auStack_70 [48];
  int iStack_40;
  
  if ((byte)(0.0 < g_flWeaponCheat | (byte)((ushort)((ushort)NAN(g_flWeaponCheat) << 10) >> 8) |
            (byte)((ushort)((ushort)(g_flWeaponCheat == 0.0) << 0xe) >> 8)) != 0x40) {
    if (param_2 == 0xc3) {
      iVar2 = *param_1 + 0x50;
      iVar1 = *param_1 + 8;
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
        iVar1 = (*DAT_001c1140)(0);
        iVar2 = *param_1;
        fStack_7c = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x174);
        fStack_78 = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x178);
        fStack_74 = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x17c);
        fStack_88 = fStack_7c + *(float *)(gpGlobals + 0x28) * 1024.0;
        fStack_84 = fStack_78 + *(float *)(gpGlobals + 0x2c) * 1024.0;
        fStack_80 = fStack_74 + *(float *)(gpGlobals + 0x30) * 1024.0;
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (&fStack_7c,&fStack_88,1,*(undefined4 *)(iVar2 + 0x208),auStack_70);
        if (iStack_40 != 0) {
          iVar1 = iStack_40;
        }
        iVar2 = (*DAT_001c10b0)(iVar1,&fStack_7c,&fStack_88);
        if (iVar2 == 0) {
          return;
        }
        (*DAT_001c1114)(1,"Texture: %s\n",iVar2);
        return;
      }
      if (param_2 == 0xc5) {
        iVar2 = *param_1 + 0x50;
        iVar1 = *param_1 + 8;
        pcVar3 = "node_viewer_human";
      }
      else {
        if (0xc4 < param_2) {
          if (param_2 != 199) {
            return;
          }
          uVar4 = FindNearestNode__6CGraphRC6Vectori(&WorldGraph,*param_1 + 8,7);
          (*DAT_001c1114)(1,&UNK_0014b841,uVar4);
          uVar4 = FindNearestNode__6CGraphRC6Vectori(&WorldGraph,*param_1 + 8,7);
          ShowNodeConnections__6CGraphi(&WorldGraph,uVar4);
          return;
        }
        iVar2 = *param_1 + 0x50;
        iVar1 = *param_1 + 8;
        pcVar3 = "node_viewer_large";
      }
    }
    Create__11CBaseEntityPcRC6VectorT2P7edict_s(pcVar3,iVar1,iVar2,0);
  }
  return;
}


