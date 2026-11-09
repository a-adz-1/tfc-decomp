// GasThePlace__13CTFGasGrenade  @ 000fe870
void GasThePlace__13CTFGasGrenade(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  iVar2 = *(int *)(*param_1 + 0x178);
  if ((iVar2 == 0) && (iVar2 = (*DAT_001755d4)(0), iVar2 == 0)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(iVar2 + 0xd8);
  }
  piVar5 = (int *)0x0;
  if (((*(byte *)(param_1 + 0x18b) ^ 1) & 1) != 0) {
    (*DAT_00175578)(4,0x17,*param_1 + 8,0);
    (*DAT_00175580)(0x7a);
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_00175588)(0xf0);
    (*DAT_00175580)(0xc3);
    (*DAT_00175580)(0x14);
    (*DAT_0017557c)();
  }
  while (piVar5 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                   (piVar5,*param_1 + 8,param_1[0x18a]), piVar5 != (int *)0x0) {
    if (piVar5[0xb] != 0) {
      if (*(int *)(*param_1 + 0x178) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(*param_1 + 0x178) + 0xdc;
      }
      (**(code **)(piVar5[0xf2] + 0x34))(piVar5,*param_1,iVar2,0x41200000,0x84001000);
      iVar2 = (**(code **)(piVar5[0xf2] + 0x9c))(piVar5);
      if ((iVar2 != 0) &&
         (((iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar5), iVar2 == 0 ||
           (piVar5 == piVar4)) || (((int)ROUND(gpGlobals[7]) & 0x1eU) == 0)))) {
        if ((*(byte *)((int)piVar5 + 0x89) & 0x40) == 0) {
          *(byte *)((int)piVar5 + 0x89) = *(byte *)((int)piVar5 + 0x89) | 0x40;
          piVar3 = (int *)CreateTimer__11CBaseEntityi(piVar5,3);
          *(float *)(*piVar3 + 0xe4) = *gpGlobals + 0.3;
          piVar3[3] = -0x10000;
          piVar3[4] = (int)Timer_Hallucination__11CBaseEntity;
          *(undefined4 *)(*piVar3 + 0x178) = *(undefined4 *)(*piVar5 + 0x1e8);
          *(undefined4 *)(*piVar3 + 0x140) = 0x43160000;
          piVar3[0x48] = piVar5[0x48];
        }
        else {
          piVar3 = (int *)FindTimer__11CBaseEntityi(piVar5,3);
          if (piVar3 != (int *)0x0) {
            bVar1 = false;
            if ((*piVar3 == 0) ||
               (iVar2 = (*DAT_001755d8)(*(undefined4 *)(*piVar3 + 0x1e8)), iVar2 == 0)) {
              bVar1 = true;
            }
            if (!bVar1) {
              *(float *)(*piVar3 + 0x140) = *(float *)(*piVar3 + 0x140) + 25.0;
              if (*(float *)(*piVar3 + 0x140) < 150.0) {
                *(undefined4 *)(*piVar3 + 0x140) = 0x43160000;
              }
              *(float *)(*piVar3 + 0xe4) = *gpGlobals + 0.3;
            }
          }
        }
      }
    }
  }
  piVar4 = param_1 + 0x18b;
  *piVar4 = *piVar4 + -1;
  if (*piVar4 == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  else {
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.75;
  }
  return;
}


