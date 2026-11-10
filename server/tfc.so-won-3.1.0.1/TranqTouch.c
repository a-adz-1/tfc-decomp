// TranqTouch__14CTFNailgunNailP11CBaseEntity  @ 0011df40
void TranqTouch__14CTFNailgunNailP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  fVar1 = *(float *)(*param_2 + 0x16c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) goto LAB_0011e0c6;
  iVar2 = *(int *)(*param_1 + 0x198);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001a7f54)(0);
    if (iVar2 != 0) goto LAB_0011df9f;
    puVar4 = (undefined4 *)0x0;
  }
  else {
LAB_0011df9f:
    puVar4 = *(undefined4 **)(iVar2 + 0x7c);
  }
  iVar2 = (**(code **)(param_2[0xf5] + 0x28))(param_2);
  if (iVar2 == 2) {
    iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(puVar4,param_2);
    if (iVar2 != 0) {
      if (((int)ROUND(gpGlobals[7]) & 0x1eU) != 0) goto LAB_0011e0a6;
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
      piVar3 = (int *)CreateTimer__11CBaseEntityi(param_2,4);
      *(float *)(*piVar3 + 0x104) = *gpGlobals + 15.0;
      piVar3[3] = -0x10000;
      piVar3[4] = (int)Timer_Tranquilisation__11CBaseEntity;
      piVar3[0x48] = puVar4[0x48];
      TeamFortress_SetSpeed__11CBasePlayer(param_2);
    }
  }
LAB_0011e0a6:
  (**(code **)(param_2[0xf5] + 0x34))(param_2,*param_1,*puVar4,0x41a00000,0x800004);
LAB_0011e0c6:
  SUB_Remove__11CBaseEntity(param_1);
  return;
}


