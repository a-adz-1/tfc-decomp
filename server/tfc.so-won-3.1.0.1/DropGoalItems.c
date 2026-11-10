// DropGoalItems__11CBasePlayer  @ 000d72d8
void DropGoalItems__11CBasePlayer(int *param_1)

{
  int *piVar1;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [16];
  float local_2c;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
  GetGunPosition__12CBaseMonster(&local_44,param_1);
  local_54 = local_48 + *(float *)(gpGlobals + 0x28) * 32.0;
  local_50 = local_44 + *(float *)(gpGlobals + 0x2c) * 32.0;
  local_4c = local_40 + *(float *)(gpGlobals + 0x30) * 32.0;
  UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
            (&local_44,&local_54,0,1,*(undefined4 *)(*param_1 + 0x208),local_3c);
  if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40) {
    piVar1 = (int *)0x0;
    while (piVar1 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar1,"item_tfgoal"),
          piVar1 != (int *)0x0) {
      if ((*(int *)(*piVar1 + 0x198) == *(int *)(*param_1 + 0x208)) &&
         ((*(byte *)((int)piVar1 + 0x221) & 0x10) != 0)) {
        tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar1,param_1,2);
      }
    }
  }
  else {
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Dropitems_noroom",0,0,0,0);
  }
  return;
}


