// SquadRecruit__13CSquadMonsterii  @ 000ef7f0
int SquadRecruit__13CSquadMonsterii(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [16];
  float local_2c;
  
  iVar2 = (**(code **)(param_1[0xf2] + 0x28))(param_1);
  iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x184);
  if ((iVar3 == 0) && (1 < param_3)) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x184,param_1);
    local_58 = 1;
    iVar3 = 0;
    if (*(int *)(*param_1 + 0x1b0) == 0) {
      while (iVar3 = UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                               (iVar3,*param_1 + 8,(float)param_2), iVar3 != 0) {
        piVar4 = (int *)(**(code **)(*(int *)(iVar3 + 0x3c8) + 0x50))(iVar3);
        if (((((piVar4 != (int *)0x0) && (piVar4 != param_1)) &&
             (iVar5 = (**(code **)(piVar4[0xf2] + 0x88))(piVar4), iVar5 != 0)) &&
            (((piVar4[0x183] == 0 &&
              (iVar5 = __opP11CBaseEntity__7EHANDLE(piVar4 + 0x184), iVar5 == 0)) &&
             ((iVar5 = (**(code **)(piVar4[0xf2] + 0x28))(piVar4), iVar5 == iVar2 &&
              ((iVar2 != 7 ||
               (iVar5 = strcmp((char *)(*(int *)*param_1 + *(int *)(gpGlobals + 0x98)),
                               (char *)(*(int *)(gpGlobals + 0x98) + *(int *)*piVar4)), iVar5 == 0))
              )))))) && (iVar5 = *piVar4, *(int *)(iVar5 + 0x1b0) == 0)) {
          iVar1 = *param_1;
          local_48 = *(float *)(iVar5 + 8) + *(float *)(iVar1 + 0x154);
          local_44 = *(float *)(iVar5 + 0xc) + *(float *)(iVar1 + 0x158);
          local_40 = *(float *)(iVar5 + 0x10) + *(float *)(iVar1 + 0x15c);
          local_54 = *(float *)(iVar1 + 8) + *(float *)(iVar1 + 0x154);
          local_50 = *(float *)(*param_1 + 0xc) + *(float *)(iVar1 + 0x158);
          local_4c = *(float *)(*param_1 + 0x10) + *(float *)(iVar1 + 0x15c);
          UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                    (&local_54,&local_48,1,*(undefined4 *)(*piVar4 + 0x1e8),local_3c);
          if ((byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                    (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) {
            iVar5 = SquadAdd__13CSquadMonsterP13CSquadMonster(param_1,piVar4);
            if (iVar5 == 0) break;
            local_58 = local_58 + 1;
          }
        }
      }
    }
    else {
      for (iVar3 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                             (0,"netname",*(int *)(gpGlobals + 0x98) + *(int *)(*param_1 + 0x1b0));
          iVar3 != 0;
          iVar3 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                            (iVar3,"netname",*(int *)(*param_1 + 0x1b0) + *(int *)(gpGlobals + 0x98)
                            )) {
        piVar4 = (int *)(**(code **)(*(int *)(iVar3 + 0x3c8) + 0x50))(iVar3);
        if ((((piVar4 != (int *)0x0) &&
             (iVar5 = __opP11CBaseEntity__7EHANDLE(piVar4 + 0x184), iVar5 == 0)) &&
            (iVar5 = (**(code **)(piVar4[0xf2] + 0x28))(piVar4), iVar5 == iVar2)) &&
           (piVar4 != param_1)) {
          iVar5 = SquadAdd__13CSquadMonsterP13CSquadMonster(param_1,piVar4);
          if (iVar5 == 0) break;
          local_58 = local_58 + 1;
        }
      }
    }
    if (local_58 == 1) {
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x184,0);
    }
  }
  else {
    local_58 = 0;
  }
  return local_58;
}


