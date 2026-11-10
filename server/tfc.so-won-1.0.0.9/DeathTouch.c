// DeathTouch__14CTelefragDeathP11CBaseEntity  @ 00113190
void DeathTouch__14CTelefragDeathP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  longdouble lVar4;
  
  if (*(int *)(*param_2 + 0x1e8) == *(int *)(*param_1 + 0x178)) {
    return;
  }
  iVar2 = *(int *)(*param_1 + 0x178);
  if ((iVar2 == 0) && (iVar2 = (*DAT_001755d4)(0), iVar2 == 0)) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(iVar2 + 0xd8);
  }
  iVar2 = (**(code **)(param_2[0xf2] + 0x28))(param_2);
  if ((iVar2 == 2) && (*gpGlobals < (float)param_2[0xe8])) {
    *(int *)*param_1 = (int)"teledeath2" - (int)gpGlobals[0x26];
    (**(code **)(piVar3[0xf2] + 0x34))(piVar3,*param_1,*param_1,0x459c4000,0x2000);
    return;
  }
  fVar1 = *(float *)(*param_2 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    iVar2 = (**(code **)(param_2[0xf2] + 0x28))(param_2);
    if (iVar2 == 2) {
      lVar4 = (longdouble)(*DAT_0017562c)(0,0x40a00000);
      param_2[0x19b] = (int)(float)((longdouble)5.0 + (longdouble)*gpGlobals + lVar4);
    }
    (**(code **)(param_2[0xf2] + 0x34))(param_2,*param_1,*param_1,0x459c4000,0x2000);
  }
  iVar2 = strcmp((char *)(*(int *)*param_2 + (int)gpGlobals[0x26]),"detpack");
  if (iVar2 == 0) {
    UTIL_ClientPrintAll__FiPCcN41
              (1,"#Detpack_telefragged",*(int *)(*piVar3 + 0x1b0) + (int)gpGlobals[0x26],
               *(int *)(*param_2 + 0x1b0) + (int)gpGlobals[0x26],0,0);
    dremove__FP11CBaseEntity(param_2);
  }
  return;
}


