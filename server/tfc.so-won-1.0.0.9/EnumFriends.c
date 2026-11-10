// EnumFriends__12CTalkMonsterP11CBaseEntityii  @ 000f1bb0
int * EnumFriends__12CTalkMonsterP11CBaseEntityii
                (int *param_1,int *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 auStack_3c [16];
  float fStack_2c;
  
  iVar2 = (**(code **)(param_1[0xf2] + 0x21c))(param_1,param_3);
  uVar1 = *(undefined4 *)(_12CTalkMonster_m_szFriends + iVar2 * 4);
  do {
    do {
      param_2 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(param_2,uVar1);
      if (param_2 == (int *)0x0) {
        return (int *)0x0;
      }
    } while ((param_2 == param_1) ||
            (iVar2 = (**(code **)(param_2[0xf2] + 0x88))(param_2), iVar2 == 0));
    if (param_4 == 0) {
      fStack_2c = 1.0;
    }
    else {
      uStack_48 = *(undefined4 *)(*param_2 + 8);
      uStack_44 = *(undefined4 *)(*param_2 + 0xc);
      uStack_40 = *(undefined4 *)(*param_2 + 0xb8);
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (*param_1 + 8,&uStack_48,1,*(undefined4 *)(*param_1 + 0x1e8),auStack_3c);
    }
  } while ((byte)((byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) != 0x40);
  return param_2;
}


