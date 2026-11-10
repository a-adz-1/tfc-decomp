// GasThePlace__13CTFGasGrenade  @ 000f1cd8
void GasThePlace__13CTFGasGrenade(int *param_1)

{
  float fVar1;
  bool bVar2;
  undefined2 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  iVar4 = *(int *)(*param_1 + 0x198);
  if ((iVar4 == 0) && (iVar4 = (*DAT_001a7f54)(0), iVar4 == 0)) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = *(int **)(iVar4 + 0x7c);
  }
  piVar7 = (int *)0x0;
  if (((*(byte *)(param_1 + 400) ^ 1) & 1) != 0) {
    if ((short)param_1[0x18d] == 0) {
      uVar3 = (*DAT_001a8028)(1,"events/explode/tf_gas.sc");
      *(undefined2 *)(param_1 + 0x18d) = uVar3;
    }
    (*DAT_001a802c)(0,0,(short)param_1[0x18d],0,*param_1 + 8,&g_vecZero,0,0,0,0,0,0);
  }
  while (piVar7 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                   (piVar7,*param_1 + 8,param_1[399]), piVar7 != (int *)0x0) {
    if (*(int *)(*piVar7 + 0x20c) != 0) {
      iVar4 = *(int *)(*param_1 + 0x198) + 0x80;
      if (*(int *)(*param_1 + 0x198) == 0) {
        iVar4 = 0;
      }
      (**(code **)(piVar7[0xf5] + 0x34))(piVar7,*param_1,iVar4,0x41200000,0x84001000);
      iVar4 = (**(code **)(piVar7[0xf5] + 0x9c))(piVar7);
      if ((iVar4 != 0) &&
         (((iVar4 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar7), iVar4 == 0 ||
           (piVar7 == piVar6)) || (((int)ROUND(gpGlobals[7]) & 0x1eU) == 0)))) {
        if ((*(byte *)((int)piVar7 + 0x85) & 0x40) == 0) {
          *(byte *)((int)piVar7 + 0x85) = *(byte *)((int)piVar7 + 0x85) | 0x40;
          piVar5 = (int *)CreateTimer__11CBaseEntityi(piVar7,3);
          *(float *)(*piVar5 + 0x104) = *gpGlobals + 0.3;
          piVar5[3] = -0x10000;
          piVar5[4] = (int)Timer_Hallucination__11CBaseEntity;
          *(undefined4 *)(*piVar5 + 0x198) = *(undefined4 *)(*piVar7 + 0x208);
          *(undefined4 *)(*piVar5 + 0x160) = 0x43160000;
          piVar5[0x48] = piVar7[0x48];
        }
        else {
          piVar5 = (int *)FindTimer__11CBaseEntityi(piVar7,3);
          if (piVar5 != (int *)0x0) {
            bVar2 = false;
            if ((*piVar5 == 0) ||
               (iVar4 = (*DAT_001a7f58)(*(undefined4 *)(*piVar5 + 0x208)), iVar4 == 0)) {
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
  piVar6 = param_1 + 400;
  *piVar6 = *piVar6 + -1;
  if (*piVar6 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.75;
  }
  return;
}


