// TranqTouch__14CTFNailgunNailP11CBaseEntity  @ 0012e520
void TranqTouch__14CTFNailgunNailP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *piVar6;
  
  fVar1 = *(float *)(*param_2 + 0x16c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) goto LAB_0012e79a;
  iVar2 = *(int *)(*param_1 + 0x198);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001c1134)(0);
    if (iVar2 != 0) goto LAB_0012e57f;
    piVar6 = (int *)0x0;
  }
  else {
LAB_0012e57f:
    piVar6 = *(int **)(iVar2 + 0x7c);
  }
  iVar2 = (**(code **)(param_2[0x111] + 0x2c))(param_2);
  if (iVar2 == 2) {
    iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(piVar6,param_2);
    if (iVar2 != 0) {
      if (((int)ROUND(gpGlobals[7]) & 0x1eU) != 0) goto LAB_0012e77a;
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
      uVar5 = (*DAT_001c11f4)(*(undefined4 *)(*param_2 + 0x208),pcVar4);
      uVar5 = (*DAT_001c11e4)(*(undefined4 *)(*param_2 + 0x208),uVar5);
      if (piVar6[0x48] == 0) {
        pcVar4 = "SPECTATOR";
      }
      else {
        pcVar4 = (char *)GetTeamName__Fi(piVar6[0x48],
                                         *(int *)(*param_2 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
      }
      uVar5 = (*DAT_001c11f4)(*(undefined4 *)(*piVar6 + 0x208),pcVar4);
      uVar5 = (*DAT_001c11e4)(*(undefined4 *)(*piVar6 + 0x208),uVar5);
      UTIL_LogPrintf__FPce
                ("\"%s<%i><%u><%s>\" triggered \"Spy_Tranq\" against \"%s<%i><%u><%s>\"\n",
                 *(int *)(*piVar6 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
      piVar3 = (int *)CreateTimer__11CBaseEntityi(param_2,4);
      *(float *)(*piVar3 + 0x104) = *gpGlobals + 15.0;
      piVar3[3] = -0x10000;
      piVar3[4] = (int)Timer_Tranquilisation__11CBaseEntity;
      piVar3[0x48] = piVar6[0x48];
      TeamFortress_SetSpeed__11CBasePlayer(param_2);
    }
  }
LAB_0012e77a:
  (**(code **)(param_2[0x111] + 0x38))(param_2,*param_1,*piVar6,0x41a00000,0x800004);
LAB_0012e79a:
  SUB_Remove__11CBaseEntity(param_1);
  return;
}


