// EnumFriends__12CTalkMonsterP11CBaseEntityii  @ 000e86bc
int * EnumFriends__12CTalkMonsterP11CBaseEntityii
                (int *param_1,int *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [16];
  float local_28;
  
  iVar2 = (**(code **)(param_1[0xf5] + 0x21c))(param_1,param_3);
  uVar1 = *(undefined4 *)(_12CTalkMonster_m_szFriends + iVar2 * 4);
  do {
    do {
      param_2 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(param_2,uVar1);
      if (param_2 == (int *)0x0) {
        return (int *)0x0;
      }
    } while ((param_2 == param_1) ||
            (iVar2 = (**(code **)(param_2[0xf5] + 0x88))(param_2), iVar2 == 0));
    if (param_4 == 0) {
      local_28 = 1.0;
    }
    else {
      local_44 = *(undefined4 *)(*param_2 + 8);
      local_40 = *(undefined4 *)(*param_2 + 0xc);
      local_3c = *(undefined4 *)(*param_2 + 0xd8);
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (*param_1 + 8,&local_44,1,*(undefined4 *)(*param_1 + 0x208),local_38);
    }
  } while ((byte)((byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
                 (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) != 0x40);
  return param_2;
}


