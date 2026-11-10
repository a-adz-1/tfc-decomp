// ChangeClass__11CBasePlayeri  @ 000e0480
void ChangeClass__11CBasePlayeri(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  ushort in_FPUControlWord;
  longdouble lVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  ushort uStack_c;
  undefined2 uStack_a;
  ushort uStack_8;
  
  iVar2 = TeamFortress_TeamIsCivilian__Ff((float)param_1[0x48]);
  if ((iVar2 == 0) || (param_2 == 0xb)) {
    if (param_1[0xb] != 0) {
      iVar2 = CantChange__11CBasePlayeri(param_1,param_2);
      if (iVar2 != 0) {
        return;
      }
      param_1[0xc] = param_2;
      uVar3 = UTIL_VarArgs__FPce(&DAT_0013a55e,*(undefined4 *)(sClassNames + param_2 * 4),0,0,0);
      ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Game_changeclass",uVar3);
      param_1[99] = (int)(*gpGlobals + 10.0);
      return;
    }
    fVar1 = gpGlobals[7];
    if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
       (param_1[0x48] == 0)) {
      fVar1 = *gpGlobals;
      if (((byte)(30.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 30.0) << 0xe) >> 8)) != 1) ||
         ((byte)((float)tfc_autoteam._12_4_ < 0.0 |
                 (byte)((ushort)((ushort)NAN((float)tfc_autoteam._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)tfc_autoteam._12_4_ == 0.0) << 0xe) >> 8)) == 0x40))
      {
        pcVar5 = "#Game_mustteam";
        goto LAB_000e05b6;
      }
      iVar2 = TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(param_1);
      if (iVar2 == 0) {
        return;
      }
    }
    if (param_1[0x49] != 0) {
      iVar2 = CantChange__11CBasePlayeri(param_1,param_2);
      if (iVar2 != 0) {
        return;
      }
      ResetMenu__11CBasePlayer(param_1);
      param_1[500] = 1;
      param_1[0x203] = -1;
      param_1[0x25b] = -1;
      *(undefined1 *)(param_1 + 0x305) = 10;
      *(undefined1 *)(param_1 + 0x2e5) = 10;
      param_1[0xb] = param_2;
      param_1[0xc] = 0;
      if (param_2 == 10) {
        ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Game_random",0,0,0,0);
        *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 8;
        do {
          do {
            lVar4 = (longdouble)(*DAT_0017562c)(0,0x41100000);
            uStack_8 = in_FPUControlWord & 0xf3ff | 0x400;
            _uStack_c = CONCAT22(uStack_a,in_FPUControlWord);
            uStack_14 = CONCAT22(uStack_a,CONCAT11(0xc,(char)in_FPUControlWord));
            param_1[0xb] = (int)ROUND((longdouble)1 + ROUND(lVar4));
            iVar2 = IsLegalClass__11CBasePlayeri(param_1,(int)ROUND((longdouble)1 + ROUND(lVar4)));
          } while (iVar2 == 0);
          iVar2 = ClassIsRestricted__Ffi((float)param_1[0x48],param_1[0xb]);
        } while (iVar2 != 0);
      }
      uVar3 = UTIL_VarArgs__FPce(&DAT_0013a55e,*(undefined4 *)(sClassNames + param_2 * 4),0);
      teamsprint__FiP11CBaseEntityiPCcN33
                (param_1[0x48],param_1,1,"#Game_playingas",
                 *(int *)(*param_1 + 0x1b0) + (int)gpGlobals[0x26],uVar3);
      TeamFortress_PrintClassName__11CBasePlayeri(param_1,param_1[0xb]);
      TeamFortress_SetEquipment__11CBasePlayer(param_1);
      TeamFortress_SetHealth__11CBasePlayer(param_1);
      TeamFortress_SetSpeed__11CBasePlayer(param_1);
      TeamFortress_SetSkin__11CBasePlayer(param_1);
      *(undefined4 *)(*param_1 + 0x14c) = 0x40000000;
      *(undefined4 *)(*param_1 + 0xec) = 3;
      *(undefined4 *)(*param_1 + 0xe8) = 3;
      *(undefined4 *)(*param_1 + 0x184) = 0x208;
      *(undefined4 *)(*param_1 + 0x1a0) = 0;
      *(float *)(*param_1 + 0x1dc) = *gpGlobals + 12.0;
      *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) & 0x7f;
      iVar2 = *param_1;
      uStack_20 = 0;
      uStack_1c = 0;
      uStack_18 = 0x41e00000;
      *(undefined4 *)(iVar2 + 0x154) = 0;
      *(undefined4 *)(iVar2 + 0x158) = 0;
      *(undefined4 *)(iVar2 + 0x15c) = 0x41e00000;
      *(undefined4 *)(*param_1 + 0x150) = 0;
      param_1[0x192] = 0;
      uVar3 = LookupActivity__14CBaseAnimatingi(param_1,1);
      *(undefined4 *)(*param_1 + 0x108) = uVar3;
      iVar2 = *param_1;
      if ((*(byte *)(iVar2 + 0x185) & 0x40) == 0) {
        uStack_2c = 0x41800000;
        uStack_28 = 0x41800000;
        uStack_24 = 0x42100000;
        puVar7 = &uStack_2c;
        uStack_20 = 0xc1800000;
        uStack_1c = 0xc1800000;
        uStack_18 = 0xc2100000;
        puVar6 = &uStack_20;
        iVar2 = *param_1;
      }
      else {
        uStack_20 = 0x41800000;
        uStack_1c = 0x41800000;
        uStack_18 = 0x41900000;
        puVar7 = &uStack_20;
        uStack_2c = 0xc1800000;
        uStack_28 = 0xc1800000;
        uStack_24 = 0xc1900000;
        puVar6 = &uStack_2c;
      }
      UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar2,puVar6,puVar7);
      TeamFortress_ExecClassScript__11CBasePlayer(param_1);
      (**(code **)(*g_pGameRules + 0x60))(g_pGameRules,param_1);
      return;
    }
    pcVar5 = "#Game_nolives";
  }
  else {
    pcVar5 = "#Game_nochangeclass";
  }
LAB_000e05b6:
  ClientPrint__FP9entvars_tiPCcN42(*param_1,1,pcVar5,0,0,0,0);
  return;
}


