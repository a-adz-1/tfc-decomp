// ChangeClass__11CBasePlayeri  @ 000d4270
void ChangeClass__11CBasePlayeri(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  ushort in_FPUControlWord;
  longdouble lVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  ushort local_8;
  undefined2 uStack_6;
  ushort local_4;
  
  iVar2 = TeamFortress_TeamIsCivilian__Ff((float)param_1[0x48]);
  if ((iVar2 == 0) || (param_2 == 0xb)) {
    if (*(int *)(*param_1 + 0x20c) != 0) {
      iVar2 = CantChange__11CBasePlayeri(param_1,param_2);
      if (iVar2 != 0) {
        return;
      }
      param_1[0xb] = param_2;
      uVar3 = UTIL_VarArgs__FPce(&DAT_0013b0e8,*(undefined4 *)(sClassNames + param_2 * 4),0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_changeclass",uVar3);
      uVar3 = (*DAT_001a8004)(*(undefined4 *)(*param_1 + 0x208),
                              *(undefined4 *)(sClassNames + param_2 * 4));
      UTIL_LogPrintf__FPce
                ("\"%s<%i>\" changed class to \"%s\"\n",
                 *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],uVar3);
      param_1[99] = (int)(*gpGlobals + 10.0);
      ResetMenu__11CBasePlayer(param_1);
      return;
    }
    fVar1 = gpGlobals[7];
    if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
       (param_1[0x48] == 0)) {
      if ((*gpGlobals <= 30.0) ||
         ((byte)((float)tfc_autoteam._12_4_ < 0.0 |
                 (byte)((ushort)((ushort)NAN((float)tfc_autoteam._12_4_) << 10) >> 8) |
                (byte)((ushort)((ushort)((float)tfc_autoteam._12_4_ == 0.0) << 0xe) >> 8)) == 0x40))
      {
        pcVar4 = "#Game_mustteam";
        goto LAB_000d4413;
      }
      iVar2 = TeamFortress_TeamPutPlayerInTeam__11CBasePlayer(param_1);
      if (iVar2 == 0) {
        return;
      }
    }
    if (param_1[0x49] != 0) {
      iVar2 = CantChange__11CBasePlayeri(param_1,param_2);
      if (iVar2 != 0) {
        Menu_Class__11CBasePlayer(param_1);
        return;
      }
      ResetMenu__11CBasePlayer(param_1);
      param_1[0x1f9] = 1;
      param_1[0x208] = -1;
      param_1[0x262] = -1;
      *(undefined1 *)(param_1 + 0x30b) = 10;
      *(undefined1 *)(param_1 + 0x2eb) = 10;
      *(int *)(*param_1 + 0x20c) = param_2;
      param_1[0xb] = 0;
      if (*(int *)(*param_1 + 0x20c) == 10) {
        ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Game_random",0,0,0,0);
        *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) | 8;
        do {
          do {
            lVar5 = (longdouble)(*DAT_001a7fac)(0,0x41100000);
            local_4 = in_FPUControlWord & 0xf3ff | 0x400;
            _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
            local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
            *(int *)(*param_1 + 0x20c) = (int)ROUND((longdouble)1.0 + ROUND(lVar5));
            iVar2 = IsLegalClass__11CBasePlayeri(param_1,*(undefined4 *)(*param_1 + 0x20c));
          } while (iVar2 == 0);
          iVar2 = ClassIsRestricted__Ffi((float)param_1[0x48],*(undefined4 *)(*param_1 + 0x20c));
        } while (iVar2 != 0);
      }
      uVar3 = (*DAT_001a8004)(*(undefined4 *)(*param_1 + 0x208),
                              *(undefined4 *)(sClassNames + param_2 * 4));
      UTIL_LogPrintf__FPce
                ("\"%s<%i>\" changed class to \"%s\"\n",
                 *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26],uVar3);
      if ((*(int *)(*param_1 + 0x244) != 0) || (*(int *)(*param_1 + 0x248) != 0)) {
        (*DAT_001a7ef8)(2,gmsgSpectator,0,0);
        uVar3 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208));
        (*DAT_001a7f00)(uVar3);
        (*DAT_001a7f00)(0);
        (*DAT_001a7efc)();
        iVar2 = *param_1;
        *(undefined4 *)(iVar2 + 0x248) = 0;
        *(undefined4 *)(iVar2 + 0x244) = 0;
      }
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x33f,0);
      *(byte *)(*param_1 + 0x16b) = *(byte *)(*param_1 + 0x16b) | 0x80;
      param_1[0x207] = 0;
      TeamFortress_SetEquipment__11CBasePlayer(param_1);
      TeamFortress_SetHealth__11CBasePlayer(param_1);
      TeamFortress_SetSpeed__11CBasePlayer(param_1);
      TeamFortress_SetSkin__11CBasePlayer(param_1);
      *(undefined4 *)(*param_1 + 0x16c) = 0x40000000;
      *(undefined4 *)(*param_1 + 0x10c) = 3;
      *(undefined4 *)(*param_1 + 0x108) = 3;
      *(undefined4 *)(*param_1 + 0x1a4) = 0x208;
      *(undefined4 *)(*param_1 + 0x1c0) = 0;
      *(float *)(*param_1 + 0x1fc) = *gpGlobals + 12.0;
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
      iVar2 = *param_1;
      uStack_14 = 0x41e00000;
      uStack_1c = 0;
      uStack_18 = 0;
      *(undefined4 *)(iVar2 + 0x174) = 0;
      *(undefined4 *)(iVar2 + 0x178) = 0;
      *(undefined4 *)(iVar2 + 0x17c) = 0x41e00000;
      *(undefined4 *)(*param_1 + 0x170) = 0;
      param_1[0x196] = 0;
      uVar3 = LookupActivity__14CBaseAnimatingi(param_1,1);
      *(undefined4 *)(*param_1 + 0x128) = uVar3;
      iVar2 = *param_1;
      if ((*(byte *)(iVar2 + 0x1a5) & 0x40) == 0) {
        uStack_24 = 0x41800000;
        uStack_20 = 0x42100000;
        puVar7 = &uStack_28;
        uStack_18 = 0xc1800000;
        uStack_14 = 0xc2100000;
        puVar6 = &uStack_1c;
        iVar2 = *param_1;
      }
      else {
        uStack_18 = 0x41800000;
        uStack_14 = 0x41900000;
        puVar7 = &uStack_1c;
        uStack_24 = 0xc1800000;
        uStack_20 = 0xc1900000;
        puVar6 = &uStack_28;
      }
      uStack_28 = uStack_24;
      uStack_1c = uStack_18;
      UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar2,puVar6,puVar7);
      TeamFortress_ExecClassScript__11CBasePlayer(param_1);
      (**(code **)(*g_pGameRules + 0x60))(g_pGameRules,param_1);
      return;
    }
    pcVar4 = "#Game_nolives";
  }
  else {
    pcVar4 = "#Game_nochangeclass";
  }
LAB_000d4413:
  ClientPrint__FP9entvars_siPCcN42(*param_1,1,pcVar4,0,0,0,0);
  return;
}


