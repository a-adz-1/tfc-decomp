// ExplodeTouch__8CGrenadeP11CBaseEntity  @ 000b9490
void ExplodeTouch__8CGrenadeP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [56];
  
  *(undefined4 *)(*param_1 + 0x170) = *(undefined4 *)(*param_2 + 0x1e8);
  iVar1 = *param_1;
  fStack_64 = SQRT(*(float *)(iVar1 + 0x28) * *(float *)(iVar1 + 0x28) +
                   *(float *)(iVar1 + 0x24) * *(float *)(iVar1 + 0x24) +
                   *(float *)(*param_1 + 0x20) * *(float *)(*param_1 + 0x20));
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_64) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_64 == 0.0) << 0xe) >> 8)) == 0x40) {
    fStack_6c = 0.0;
    fStack_68 = 0.0;
    fStack_64 = 1.0;
  }
  else {
    fStack_64 = 1.0 / fStack_64;
    fStack_6c = fStack_64 * *(float *)(iVar1 + 0x20);
    fStack_68 = fStack_64 * *(float *)(iVar1 + 0x24);
    fStack_64 = fStack_64 * *(float *)(iVar1 + 0x28);
  }
  iVar1 = *param_1;
  fStack_48 = *(float *)(iVar1 + 8) - fStack_6c * 32.0;
  fStack_44 = *(float *)(iVar1 + 0xc) - fStack_68 * 32.0;
  fStack_40 = *(float *)(iVar1 + 0x10) - fStack_64 * 32.0;
  fStack_4c = SQRT(*(float *)(iVar1 + 0x28) * *(float *)(iVar1 + 0x28) +
                   *(float *)(iVar1 + 0x24) * *(float *)(iVar1 + 0x24) +
                   *(float *)(iVar1 + 0x20) * *(float *)(iVar1 + 0x20));
  if ((byte)((byte)((ushort)((ushort)NAN(fStack_4c) << 10) >> 8) |
            (byte)((ushort)((ushort)(fStack_4c == 0.0) << 0xe) >> 8)) == 0x40) {
    fStack_58 = 0.0;
    fStack_54 = 0.0;
    fStack_50 = 1.0;
  }
  else {
    fStack_50 = 1.0 / fStack_4c;
    fStack_58 = fStack_50 * *(float *)(iVar1 + 0x20);
    fStack_54 = fStack_50 * *(float *)(iVar1 + 0x24);
    fStack_50 = fStack_50 * *(float *)(iVar1 + 0x28);
  }
  fStack_64 = fStack_58 * 64.0;
  fStack_60 = fStack_54 * 64.0;
  fStack_5c = fStack_50 * 64.0;
  fStack_70 = fStack_48 + fStack_64;
  fStack_6c = fStack_44 + fStack_60;
  fStack_68 = fStack_40 + fStack_5c;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&fStack_48,&fStack_70,1,*(undefined4 *)(*param_1 + 0x1e8),auStack_3c);
  if ((*(int *)(*param_1 + 0x178) != 0) && (iVar1 = *(int *)(*param_1 + 0x178) + 0xdc, iVar1 != 0))
  {
    (**(code **)(param_2[0xf2] + 0x34))
              (param_2,*param_1,iVar1,*(undefined4 *)(*param_1 + 0x1c0),0x40);
  }
  (**(code **)(param_1[0xf2] + 0x218))(param_1,auStack_3c,0x40);
  return;
}


