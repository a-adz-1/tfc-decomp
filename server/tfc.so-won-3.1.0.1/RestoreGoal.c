// RestoreGoal__FP11CBaseEntity  @ 000fb374
void RestoreGoal__FP11CBaseEntity(int *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  if (param_1[0x86] == 3) {
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x93]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x93] == 0.0) << 0xe) >> 8)) == 0x40) {
      if (((*(byte *)((int)param_1 + 0x221) & 0x20) == 0) ||
         (iVar2 = strcmp((char *)(*(int *)*param_1 + (int)gpGlobals[0x26]),"item_tfgoal"),
         iVar2 != 0)) {
        *(undefined4 *)(*param_1 + 0x10c) = 1;
      }
      else {
        *(undefined4 *)(*param_1 + 0x10c) = 2;
      }
    }
    else {
      *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0x93];
    }
    param_1[0x86] = 2;
    if (*(char *)(*(int *)(*param_1 + 0xb8) + (int)gpGlobals[0x26]) != '*') {
      pbVar1 = (byte *)(*param_1 + 0x118);
      *pbVar1 = *pbVar1 & 0x7f;
    }
    return;
  }
  return;
}


