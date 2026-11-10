// DeathTouch__14CTelefragDeathP11CBaseEntity  @ 00105f44
void DeathTouch__14CTelefragDeathP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  longdouble lVar5;
  
  if (*(int *)(*param_2 + 0x208) == *(int *)(*param_1 + 0x198)) {
    return;
  }
  iVar3 = *(int *)(*param_1 + 0x198);
  if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(iVar3 + 0x7c);
  }
  iVar3 = (**(code **)(param_2[0xf5] + 0x28))(param_2);
  if (iVar3 == 2) {
    fVar1 = (float)param_2[0xeb];
    fVar2 = *gpGlobals;
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      *(int *)*param_1 = (int)"teledeath2" - (int)gpGlobals[0x26];
      (**(code **)(piVar4[0xf5] + 0x34))(piVar4,*param_1,*param_1,0x459c4000,0x2000);
      return;
    }
  }
  fVar1 = *(float *)(*param_2 + 0x16c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar3 = (**(code **)(param_2[0xf5] + 0x28))(param_2);
    if (iVar3 == 2) {
      lVar5 = (longdouble)(*DAT_001a7fac)(0,0x40a00000);
      param_2[0x19f] = (int)(float)((longdouble)5.0 + (longdouble)*gpGlobals + lVar5);
    }
    (**(code **)(param_2[0xf5] + 0x34))(param_2,*param_1,*param_1,0x459c4000,0x2000);
  }
  iVar3 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"detpack");
  if (iVar3 == 0) {
    UTIL_ClientPrintAll__FiPCcN41
              (1,"#Detpack_telefragged",*(int *)(*piVar4 + 0x1d0) + (int)gpGlobals[0x26],
               *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
    dremove__FP11CBaseEntity(param_2);
  }
  return;
}


