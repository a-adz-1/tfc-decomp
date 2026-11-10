// ValveAuth_Init  @ 0006ca28
void ValveAuth_Init(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStackY_2b4 [2];
  char local_278 [256];
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  int local_168;
  char local_164 [64];
  undefined4 local_124 [5];
  int local_110;
  int local_10c;
  char local_108 [259];
  undefined1 local_5;
  
  local_16c = 0;
  if (((bInitialized_119 == 0) && (1 < DAT_00524288)) &&
     ((byte)((byte)((ushort)((ushort)NAN((float)sv_lan._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)sv_lan._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)) {
    bInitialized_119 = 1;
    strcpy(local_108,"valvecomm.lst");
    local_178 = COM_CheckParm();
    if ((local_178 != 0) && (local_178 < com_argc + -1)) {
      Q_strncpy();
      local_5 = 0;
    }
    local_110 = COM_LoadFile();
    local_10c = local_110;
    if (local_110 == 0) {
      Con_Printf();
    }
    else {
LAB_0006cb6c:
      local_110 = COM_Parse();
      iVar1 = Q_strlen();
      if (0 < iVar1) {
        local_170 = 1;
        iVar1 = Q_stricmp();
        if (iVar1 == 0) {
          local_174 = 0x6982;
          local_170 = 0;
        }
        local_110 = COM_Parse();
        iVar1 = Q_strlen();
        if ((iVar1 < 1) || (iVar1 = Q_stricmp(), iVar1 != 0)) goto LAB_0006ce70;
        while( true ) {
          local_110 = COM_Parse();
          iVar1 = Q_strlen();
          if ((iVar1 < 1) || (iVar1 = Q_stricmp(), iVar1 == 0)) break;
          snprintf(local_278,0x100,"%s");
          local_110 = COM_Parse();
          iVar1 = Q_strlen();
          if ((iVar1 < 1) || (iVar1 = Q_stricmp(), iVar1 != 0)) break;
          local_110 = COM_Parse();
          iVar1 = Q_strlen();
          if (iVar1 < 1) break;
          local_168 = Q_atoi();
          if (local_168 == 0) {
            local_168 = local_174;
          }
          auStackY_2b4[1] = 0x6cde1;
          snprintf(local_164,0x40,"%s:%i");
          iVar1 = NET_StringToAdr();
          if (iVar1 == 0) {
            local_170 = 1;
          }
          if (local_170 == 0) {
            puVar2 = local_124;
            puVar3 = auStackY_2b4;
            for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar3 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar3 = puVar3 + 1;
            }
            NET_AdrToString();
            Con_Printf();
            Auth_AddServer();
            local_16c = local_16c + 1;
          }
        }
        goto LAB_0006cb6c;
      }
LAB_0006ce70:
      if (local_16c == 0) {
        Con_Printf();
      }
      Mem_Free();
    }
  }
  return;
}


