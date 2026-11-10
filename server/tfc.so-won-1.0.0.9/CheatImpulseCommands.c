// CheatImpulseCommands__11CBasePlayeri  @ 000ddcb0
void CheatImpulseCommands__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
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
      Create__11CBaseEntityPcRC6VectorT2P7edict_s("node_viewer_fly",*param_1 + 8,*param_1 + 0x50,0);
    }
    else if (param_2 < 0xc4) {
      if (param_2 == 0x68) {
        DumpGlobals__12CGlobalState(&gGlobalState);
      }
      else if (param_2 == 0x6b) {
        iVar1 = (*DAT_001755e0)(0);
        iVar2 = *param_1;
        local_80 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x154);
        local_7c = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x158);
        local_78 = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x15c);
        local_8c = local_80 + *(float *)(gpGlobals + 0x28) * 1024.0;
        local_88 = local_7c + *(float *)(gpGlobals + 0x2c) * 1024.0;
        local_84 = local_78 + *(float *)(gpGlobals + 0x30) * 1024.0;
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (&local_80,&local_8c,1,*(undefined4 *)(iVar2 + 0x1e8),local_74);
        if (local_44 != 0) {
          iVar1 = local_44;
        }
        iVar2 = (*DAT_00175550)(iVar1,&local_80,&local_8c);
        if (iVar2 != 0) {
          (*DAT_001755b4)(1,"Texture: %s\n",iVar2);
        }
      }
    }
    else if (param_2 == 0xc5) {
      Create__11CBaseEntityPcRC6VectorT2P7edict_s
                ("node_viewer_human",*param_1 + 8,*param_1 + 0x50,0);
    }
    else if (param_2 < 0xc5) {
      Create__11CBaseEntityPcRC6VectorT2P7edict_s
                ("node_viewer_large",*param_1 + 8,*param_1 + 0x50,0);
    }
    else if (param_2 == 199) {
      uVar3 = FindNearestNode__6CGraphRC6Vectori(&WorldGraph,*param_1 + 8,7);
      (*DAT_001755b4)(1,&DAT_0013a3cd,uVar3);
      uVar3 = FindNearestNode__6CGraphRC6Vectori(&WorldGraph,*param_1 + 8,7);
      ShowNodeConnections__6CGraphi(&WorldGraph,uVar3);
    }
  }
  return;
}


