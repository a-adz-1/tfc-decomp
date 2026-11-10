// GasThePlace__13CTFGasGrenade  @ 000ff160
void GasThePlace__13CTFGasGrenade(int *param_1)

{
  float fVar1;
  bool bVar2;
  undefined2 uVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  
  iVar4 = *(int *)(*param_1 + 0x198);
  if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = *(int **)(iVar4 + 0x7c);
  }
  piVar9 = (int *)0x0;
  if (((*(byte *)(param_1 + 0x1ac) ^ 1) & 1) != 0) {
    if ((short)param_1[0x1a9] == 0) {
      uVar3 = (*DAT_001c1208)(1,"events/explode/tf_gas.sc");
      *(undefined2 *)(param_1 + 0x1a9) = uVar3;
    }
    (*DAT_001c120c)(0,0,(short)param_1[0x1a9],0,*param_1 + 8,&g_vecZero,0,0,0,0,0,0);
  }
  while (piVar9 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                   (piVar9,*param_1 + 8,param_1[0x1ab]), piVar9 != (int *)0x0) {
    if (*(int *)(*piVar9 + 0x20c) != 0) {
      iVar4 = *(int *)(*param_1 + 0x198) + 0x80;
      if (*(int *)(*param_1 + 0x198) == 0) {
        iVar4 = 0;
      }
      (**(code **)(piVar9[0x111] + 0x38))(piVar9,*param_1,iVar4,0x41200000,0x84001000);
      iVar4 = (**(code **)(piVar9[0x111] + 0xa0))(piVar9);
      if ((iVar4 != 0) &&
         (((iVar4 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar9), iVar4 == 0 ||
           (piVar9 == piVar8)) || (((int)ROUND(gpGlobals[7]) & 0x1eU) == 0)))) {
        if ((*(byte *)((int)piVar9 + 0x85) & 0x40) == 0) {
          *(byte *)((int)piVar9 + 0x85) = *(byte *)((int)piVar9 + 0x85) | 0x40;
          piVar5 = (int *)CreateTimer__11CBaseEntityi(piVar9,3);
          *(float *)(*piVar5 + 0x104) = *gpGlobals + 0.3;
          piVar5[3] = -0x10000;
          piVar5[4] = (int)Timer_Hallucination__11CBaseEntity;
          *(undefined4 *)(*piVar5 + 0x198) = *(undefined4 *)(*piVar9 + 0x208);
          *(undefined4 *)(*piVar5 + 0x160) = 0x43160000;
          piVar5[0x48] = piVar9[0x48];
          iVar4 = *(int *)(*param_1 + 0x198);
          if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = *(int **)(iVar4 + 0x7c);
          }
          if (piVar9[0x48] == 0) {
            pcVar6 = "SPECTATOR";
          }
          else {
            pcVar6 = (char *)GetTeamName__Fi(piVar9[0x48]);
          }
          uVar7 = (*DAT_001c11f4)(*(undefined4 *)(*piVar9 + 0x208),pcVar6);
          uVar7 = (*DAT_001c11e4)(*(undefined4 *)(*piVar9 + 0x208),uVar7);
          if (piVar5[0x48] == 0) {
            pcVar6 = "SPECTATOR";
          }
          else {
            pcVar6 = (char *)GetTeamName__Fi(piVar5[0x48],
                                             *(int *)(*piVar9 + 0x1d0) + (int)gpGlobals[0x26],uVar7)
            ;
          }
          uVar7 = (*DAT_001c11f4)(*(undefined4 *)(*param_1 + 0x198),pcVar6);
          uVar7 = (*DAT_001c11e4)(*(undefined4 *)(*param_1 + 0x198),uVar7);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%u><%s>\" triggered \"Hallucination_Grenade\" against \"%s<%i><%u><%s>\"\n"
                     ,*(int *)(*piVar5 + 0x1d0) + (int)gpGlobals[0x26],uVar7);
        }
        else {
          piVar5 = (int *)FindTimer__11CBaseEntityi(piVar9,3);
          if (piVar5 != (int *)0x0) {
            bVar2 = false;
            if ((*piVar5 == 0) ||
               (iVar4 = (*DAT_001c1138)(*(undefined4 *)(*piVar5 + 0x208)), iVar4 == 0)) {
              bVar2 = true;
            }
            if (!bVar2) {
              *(float *)(*piVar5 + 0x160) = *(float *)(*piVar5 + 0x160) + 25.0;
              fVar1 = *(float *)(*piVar5 + 0x160);
              if (0x3f < (byte)((150.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                                (byte)((ushort)((ushort)(fVar1 == 150.0) << 0xe) >> 8)) - 1)) {
                *(undefined4 *)(*piVar5 + 0x160) = 0x43160000;
              }
              *(float *)(*piVar5 + 0x104) = *gpGlobals + 0.3;
            }
          }
        }
      }
    }
  }
  piVar8 = param_1 + 0x1ac;
  *piVar8 = *piVar8 + -1;
  if (*piVar8 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.75;
  }
  return;
}


