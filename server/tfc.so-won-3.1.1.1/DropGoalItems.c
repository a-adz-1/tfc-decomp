// DropGoalItems__11CBasePlayer  @ 000e27e8
void DropGoalItems__11CBasePlayer(int *param_1)

{
  int *piVar1;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float local_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [16];
  float fStack_2c;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x74);
  GetGunPosition__12CBaseMonster(&local_48,param_1);
  fStack_54 = *(float *)(gpGlobals + 0x28) * 32.0 + local_48;
  fStack_50 = *(float *)(gpGlobals + 0x2c) * 32.0 + fStack_44;
  fStack_4c = *(float *)(gpGlobals + 0x30) * 32.0 + fStack_40;
  UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
            (&local_48,&fStack_54,0,1,*(undefined4 *)(*param_1 + 0x208),auStack_3c);
  if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40) {
    piVar1 = (int *)0x0;
    while (piVar1 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar1,"item_tfgoal"),
          piVar1 != (int *)0x0) {
      if ((*(int *)(*piVar1 + 0x198) == *(int *)(*param_1 + 0x208)) &&
         ((*(byte *)((int)piVar1 + 0x229) & 0x10) != 0)) {
        tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar1,param_1,2);
      }
    }
  }
  else {
    ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Dropitems_noroom",0,0,0,0);
  }
  return;
}


