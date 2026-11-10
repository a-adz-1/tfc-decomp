// GasThePlace__13CTFGasGrenade  @ 00100984
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
  int iStack_48;
  int *local_18;
  
  iVar4 = *(int *)(*param_1 + 0x198);
  if ((iVar4 == 0) && (iVar4 = (*DAT_0019f7b4)(0), iVar4 == 0)) {
    local_18 = (int *)0x0;
  }
  else {
    local_18 = *(int **)(iVar4 + 0x7c);
  }
  piVar8 = (int *)0x0;
  if (((*(byte *)(param_1 + 0x1b0) ^ 1) & 1) != 0) {
    if ((short)param_1[0x1ad] == 0) {
      uVar3 = (*DAT_0019f888)(1,"events/explode/tf_gas.sc");
      *(undefined2 *)(param_1 + 0x1ad) = uVar3;
    }
    (*DAT_0019f88c)(0,0,(short)param_1[0x1ad],0,*param_1 + 8,&g_vecZero,0,0,0,0,0,0);
  }
  while (piVar8 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                   (piVar8,*param_1 + 8,param_1[0x1af]), piVar8 != (int *)0x0) {
    if (*(int *)(*piVar8 + 0x20c) != 0) {
      iVar4 = *(int *)(*param_1 + 0x198);
      iStack_48 = iVar4 + 0x80;
      if (iVar4 == 0) {
        iStack_48 = 0;
      }
      (**(code **)(piVar8[0x115] + 0x38))(piVar8,*param_1,iStack_48,0x41200000,0x84001000);
      iVar4 = (**(code **)(piVar8[0x115] + 0xa0))(piVar8);
      if ((iVar4 != 0) &&
         (((iVar4 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar8), iVar4 == 0 ||
           (piVar8 == local_18)) || (((int)ROUND(gpGlobals[7]) & 0x1eU) == 0)))) {
        if ((piVar8[0x21] & 0x4000U) == 0) {
          piVar8[0x21] = piVar8[0x21] | 0x4000;
          piVar5 = (int *)CreateTimer__11CBaseEntityi(piVar8,3);
          *(float *)(*piVar5 + 0x104) = *gpGlobals + 0.3;
          piVar5[3] = -0x10000;
          piVar5[4] = (int)Timer_Hallucination__11CBaseEntity;
          *(undefined4 *)(*piVar5 + 0x198) = *(undefined4 *)(*piVar8 + 0x208);
          *(undefined4 *)(*piVar5 + 0x160) = 0x43160000;
          piVar5[0x48] = piVar8[0x48];
          iVar4 = *(int *)(*param_1 + 0x198);
          if ((iVar4 == 0) && (iVar4 = (*DAT_0019f7b4)(0), iVar4 == 0)) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = *(int **)(iVar4 + 0x7c);
          }
          if (piVar8[0x48] == 0) {
            pcVar6 = "SPECTATOR";
          }
          else {
            pcVar6 = (char *)GetTeamName__Fi(piVar8[0x48]);
          }
          uVar7 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar8 + 0x208),pcVar6);
          uVar7 = (*DAT_0019f864)(*(undefined4 *)(*piVar8 + 0x208),uVar7);
          if (piVar5[0x48] == 0) {
            pcVar6 = "SPECTATOR";
          }
          else {
            pcVar6 = (char *)GetTeamName__Fi(piVar5[0x48],
                                             *(int *)(*piVar8 + 0x1d0) + (int)gpGlobals[0x26],uVar7)
            ;
          }
          uVar7 = (*DAT_0019f8dc)(*(undefined4 *)(*param_1 + 0x198),pcVar6);
          uVar7 = (*DAT_0019f864)(*(undefined4 *)(*param_1 + 0x198),uVar7);
          UTIL_LogPrintf__FPce
                    ("\"%s<%i><%s><%s>\" triggered \"Hallucination_Grenade\" against \"%s<%i><%s><%s>\"\n"
                     ,*(int *)(*piVar5 + 0x1d0) + (int)gpGlobals[0x26],uVar7);
        }
        else {
          piVar5 = (int *)FindTimer__11CBaseEntityi(piVar8,3);
          if (piVar5 != (int *)0x0) {
            bVar2 = false;
            if ((*piVar5 == 0) ||
               (iVar4 = (*DAT_0019f7b8)(*(undefined4 *)(*piVar5 + 0x208)), iVar4 == 0)) {
              bVar2 = true;
            }
            if (!bVar2) {
              *(float *)(*piVar5 + 0x160) = *(float *)(*piVar5 + 0x160) + 25.0;
              iVar4 = *piVar5;
              fVar1 = *(float *)(iVar4 + 0x160);
              if (0x3f < (byte)((150.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                                (byte)((ushort)((ushort)(fVar1 == 150.0) << 0xe) >> 8)) - 1)) {
                *(undefined4 *)(iVar4 + 0x160) = 0x43160000;
                iVar4 = *piVar5;
              }
              *(float *)(iVar4 + 0x104) = *gpGlobals + 0.3;
            }
          }
        }
      }
    }
  }
  iVar4 = param_1[0x1b0];
  param_1[0x1b0] = iVar4 + -1;
  if (iVar4 == 1) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.75;
  }
  return;
}


