// ShutUpFriends__12CTalkMonster  @ 000f74dc
void ShutUpFriends__12CTalkMonster(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c [16];
  float local_2c;
  
  piVar3 = (int *)0x0;
  local_4c = 0;
  do {
    iVar2 = (**(code **)(param_1[0x115] + 0x224))(param_1,local_4c);
    uVar1 = *(undefined4 *)(_12CTalkMonster_m_szFriends + iVar2 * 4);
    do {
      do {
        piVar3 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar3,uVar1);
        if (piVar3 == (int *)0x0) {
          piVar3 = (int *)0x0;
          goto LAB_000f75e3;
        }
      } while ((piVar3 == param_1) ||
              (iVar2 = (**(code **)(piVar3[0x115] + 0x8c))(piVar3), iVar2 == 0));
      local_48 = *(undefined4 *)(*piVar3 + 8);
      local_44 = *(undefined4 *)(*piVar3 + 0xc);
      local_40 = *(undefined4 *)(*piVar3 + 0xd8);
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (*param_1 + 8,&local_48,1,*(undefined4 *)(*param_1 + 0x208),local_3c);
    } while ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40);
LAB_000f75e3:
    if (piVar3 == (int *)0x0) {
      local_4c = local_4c + 1;
      if (2 < local_4c) {
        return;
      }
    }
    else {
      iVar2 = (**(code **)(piVar3[0x115] + 0x50))(piVar3);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar2 + 0x454) + 400))(iVar2);
      }
    }
  } while( true );
}


