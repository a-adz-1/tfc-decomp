// TranqTouch__14CTFNailgunNailP11CBaseEntity  @ 001324d8
void TranqTouch__14CTFNailgunNailP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *piVar6;
  
  fVar1 = *(float *)(*param_2 + 0x16c);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) goto LAB_00132740;
  iVar2 = *(int *)(*param_1 + 0x198);
  if (iVar2 == 0) {
    iVar2 = (*DAT_0019f7b4)(0);
    if (iVar2 != 0) goto LAB_00132532;
    piVar6 = (int *)0x0;
  }
  else {
LAB_00132532:
    piVar6 = *(int **)(iVar2 + 0x7c);
  }
  iVar2 = (**(code **)(param_2[0x115] + 0x2c))(param_2);
  if (iVar2 == 2) {
    iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(piVar6,param_2);
    if (iVar2 != 0) {
      if (((int)ROUND(gpGlobals[7]) & 0x1eU) != 0) goto LAB_0013271e;
    }
    if ((short)param_2[0x21] < 0) {
      piVar3 = (int *)FindTimer__11CBaseEntityi(param_2,4);
      if (piVar3 != (int *)0x0) {
        *(float *)(*piVar3 + 0x104) = *gpGlobals + 15.0;
      }
    }
    else {
      ClientPrint__FP9entvars_siPCcN42(*param_2,1,"#Spy_tranq",0,0,0,0);
      *(byte *)((int)param_2 + 0x85) = *(byte *)((int)param_2 + 0x85) | 0x80;
      if (param_2[0x48] == 0) {
        pcVar4 = "SPECTATOR";
      }
      else {
        pcVar4 = (char *)GetTeamName__Fi(param_2[0x48]);
      }
      uVar5 = (*DAT_0019f8dc)(*(undefined4 *)(*param_2 + 0x208),pcVar4);
      uVar5 = (*DAT_0019f864)(*(undefined4 *)(*param_2 + 0x208),uVar5);
      if (piVar6[0x48] == 0) {
        pcVar4 = "SPECTATOR";
      }
      else {
        pcVar4 = (char *)GetTeamName__Fi(piVar6[0x48],
                                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
      }
      uVar5 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar6 + 0x208),pcVar4);
      uVar5 = (*DAT_0019f864)(*(undefined4 *)(*piVar6 + 0x208),uVar5);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%s><%s>\" triggered \"Spy_Tranq\" against \"%s<%i><%s><%s>\"\n",
                 *(int *)(*piVar6 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
      piVar3 = (int *)CreateTimer__11CBaseEntityi(param_2,4);
      *(float *)(*piVar3 + 0x104) = *gpGlobals + 15.0;
      piVar3[3] = -0x10000;
      piVar3[4] = (int)Timer_Tranquilisation__11CBaseEntity;
      piVar3[0x48] = piVar6[0x48];
      TeamFortress_SetSpeed__11CBasePlayer(param_2);
    }
  }
LAB_0013271e:
  (**(code **)(param_2[0x115] + 0x38))(param_2,*param_1,*piVar6,0x41a00000,0x800004);
LAB_00132740:
  SUB_Remove__11CBaseEntity(param_1);
  return;
}


