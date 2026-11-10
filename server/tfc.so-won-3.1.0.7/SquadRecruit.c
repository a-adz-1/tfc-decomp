// SquadRecruit__13CSquadMonsterii  @ 000f2908
int SquadRecruit__13CSquadMonsterii(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  undefined1 auStack_38 [16];
  float fStack_28;
  
  iVar2 = (**(code **)(param_1[0x111] + 0x2c))(param_1);
  iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1a3);
  if ((iVar3 == 0) && (1 < param_3)) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x1a3,param_1);
    local_54 = 1;
    iVar3 = 0;
    if (*(int *)(*param_1 + 0x1d0) == 0) {
      while (iVar3 = UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                               (iVar3,*param_1 + 8,(float)param_2), iVar3 != 0) {
        piVar4 = (int *)(**(code **)(*(int *)(iVar3 + 0x444) + 0x54))(iVar3);
        if (((((piVar4 != (int *)0x0) && (piVar4 != param_1)) &&
             (iVar5 = (**(code **)(piVar4[0x111] + 0x8c))(piVar4), iVar5 != 0)) &&
            (((piVar4[0x1a2] == 0 &&
              (iVar5 = __opP11CBaseEntity__7EHANDLE(piVar4 + 0x1a3), iVar5 == 0)) &&
             ((iVar5 = (**(code **)(piVar4[0x111] + 0x2c))(piVar4), iVar5 == iVar2 &&
              ((iVar2 != 7 ||
               (iVar5 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),
                               (char *)(*(int *)(gpGlobals + 0x98) + *(int *)*piVar4)), iVar5 == 0))
              )))))) && (iVar5 = *piVar4, *(int *)(iVar5 + 0x1d0) == 0)) {
          iVar1 = *param_1;
          fStack_44 = *(float *)(iVar5 + 8) + *(float *)(iVar1 + 0x174);
          fStack_40 = *(float *)(iVar5 + 0xc) + *(float *)(iVar1 + 0x178);
          fStack_3c = *(float *)(iVar5 + 0x10) + *(float *)(iVar1 + 0x17c);
          fStack_50 = *(float *)(iVar1 + 8) + *(float *)(iVar1 + 0x174);
          fStack_4c = *(float *)(*param_1 + 0xc) + *(float *)(iVar1 + 0x178);
          fStack_48 = *(float *)(*param_1 + 0x10) + *(float *)(iVar1 + 0x17c);
          UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                    (&fStack_50,&fStack_44,1,*(undefined4 *)(*piVar4 + 0x208),auStack_38);
          if ((byte)((byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) == 0x40) {
            iVar5 = SquadAdd__13CSquadMonsterP13CSquadMonster(param_1,piVar4);
            if (iVar5 == 0) break;
            local_54 = local_54 + 1;
          }
        }
      }
    }
    else {
      for (iVar3 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                             (0,"netname",*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98));
          iVar3 != 0;
          iVar3 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                            (iVar3,"netname",*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98)
                            )) {
        piVar4 = (int *)(**(code **)(*(int *)(iVar3 + 0x444) + 0x54))(iVar3);
        if ((((piVar4 != (int *)0x0) &&
             (iVar5 = __opP11CBaseEntity__7EHANDLE(piVar4 + 0x1a3), iVar5 == 0)) &&
            (iVar5 = (**(code **)(piVar4[0x111] + 0x2c))(piVar4), iVar5 == iVar2)) &&
           (piVar4 != param_1)) {
          iVar5 = SquadAdd__13CSquadMonsterP13CSquadMonster(param_1,piVar4);
          if (iVar5 == 0) break;
          local_54 = local_54 + 1;
        }
      }
    }
    if (local_54 == 1) {
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x1a3,0);
    }
  }
  else {
    local_54 = 0;
  }
  return local_54;
}


