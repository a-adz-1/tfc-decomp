// DeathTouch__14CTelefragDeathP11CBaseEntity  @ 001155f4
void DeathTouch__14CTelefragDeathP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *piVar6;
  longdouble lVar7;
  
  if (*(int *)(*param_2 + 0x208) == *(int *)(*param_1 + 0x198)) {
    return;
  }
  iVar3 = *(int *)(*param_1 + 0x198);
  if ((iVar3 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = *(int **)(iVar3 + 0x7c);
  }
  iVar3 = (**(code **)(param_2[0x111] + 0x2c))(param_2);
  if (iVar3 == 2) {
    fVar1 = (float)param_2[0x107];
    fVar2 = *gpGlobals;
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      *(int *)*param_1 = (int)"teledeath2" - (int)gpGlobals[0x26];
      (**(code **)(piVar6[0x111] + 0x38))(piVar6,*param_1,*param_1,0x459c4000,0x2000);
      return;
    }
  }
  fVar1 = *(float *)(*param_2 + 0x16c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar3 = (**(code **)(param_2[0x111] + 0x2c))(param_2);
    if (iVar3 == 2) {
      lVar7 = (longdouble)(*DAT_001c118c)(0,0x40a00000);
      param_2[0x1bb] = (int)(float)((longdouble)5.0 + (longdouble)*gpGlobals + lVar7);
    }
    (**(code **)(param_2[0x111] + 0x38))(param_2,*param_1,*param_1,0x459c4000,0x2000);
  }
  iVar3 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"detpack");
  if (iVar3 == 0) {
    UTIL_ClientPrintAll__FiPCcN41
              (1,"#Detpack_telefragged",*(int *)(*piVar6 + 0x1d0) + (int)gpGlobals[0x26],
               *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
    if (piVar6[0x48] == 0) {
      pcVar4 = "SPECTATOR";
    }
    else {
      pcVar4 = (char *)GetTeamName__Fi(piVar6[0x48]);
    }
    uVar5 = (*DAT_001c11f4)(*(undefined4 *)(*piVar6 + 0x208),pcVar4);
    uVar5 = (*DAT_001c11e4)(*(undefined4 *)(*piVar6 + 0x208),uVar5);
    if (param_2[0x48] == 0) {
      pcVar4 = "SPECTATOR";
    }
    else {
      pcVar4 = (char *)GetTeamName__Fi(param_2[0x48],
                                       *(int *)(*piVar6 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
    }
    uVar5 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar4);
    uVar5 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar5);
    UTIL_LogPrintf__FPce
              ("\"%s<%i><%u><%s>\" triggered \"Detpack_Telefragged\" against \"%s<%i><%u><%s>\"\n",
               *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
    dremove__FP11CBaseEntity(param_2);
  }
  return;
}


