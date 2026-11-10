// DeathTouch__14CTelefragDeathP11CBaseEntity  @ 00117a60
void DeathTouch__14CTelefragDeathP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  longdouble lVar7;
  
  iVar2 = *(int *)(*param_1 + 0x198);
  if (*(int *)(*param_2 + 0x208) != iVar2) {
    if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = *(int **)(iVar2 + 0x7c);
    }
    iVar2 = (**(code **)(param_2[0x115] + 0x2c))(param_2);
    if ((iVar2 != 2) || ((float)param_2[0x10b] <= *gpGlobals)) {
      piVar5 = (int *)*param_2;
      fVar1 = (float)piVar5[0x5b];
      if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
        iVar2 = (**(code **)(param_2[0x115] + 0x2c))(param_2);
        if (iVar2 == 2) {
          lVar7 = (longdouble)(*DAT_0019f80c)(0,0x40a00000);
          param_2[0x1c4] = (int)(float)((longdouble)5.0 + (longdouble)*gpGlobals + lVar7);
        }
        (**(code **)(param_2[0x115] + 0x38))(param_2,*param_1,*param_1,0x459c4000,0x2000);
        piVar5 = (int *)*param_2;
      }
      iVar2 = strcmp((char *)(*piVar5 + (int)gpGlobals[0x26]),"detpack");
      if (iVar2 == 0) {
        UTIL_ClientPrintAll__FiPCcN41
                  (1,"#Detpack_telefragged",*(int *)(*piVar6 + 0x1d0) + (int)gpGlobals[0x26],
                   *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],0,0);
        if (piVar6[0x48] == 0) {
          pcVar3 = "SPECTATOR";
        }
        else {
          pcVar3 = (char *)GetTeamName__Fi(piVar6[0x48]);
        }
        uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar6 + 0x208),pcVar3);
        uVar4 = (*DAT_0019f864)(*(undefined4 *)(*piVar6 + 0x208),uVar4);
        if (param_2[0x48] == 0) {
          pcVar3 = "SPECTATOR";
        }
        else {
          pcVar3 = (char *)GetTeamName__Fi(param_2[0x48],
                                           *(int *)(*piVar6 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
        }
        uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar3);
        uVar4 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar4);
        UTIL_LogPrintf__FPce
                  ("\"%s<%i><%s><%s>\" triggered \"Detpack_Telefragged\" against \"%s<%i><%s><%s>\"\n"
                   ,*(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
        dremove__FP11CBaseEntity(param_2);
      }
    }
    else {
      *(int *)*param_1 = (int)"teledeath2" - (int)gpGlobals[0x26];
      (**(code **)(piVar6[0x115] + 0x38))(piVar6,*param_1,*param_1,0x459c4000,0x2000);
    }
    return;
  }
  return;
}


