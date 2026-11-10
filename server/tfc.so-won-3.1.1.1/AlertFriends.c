// AlertFriends__12CTalkMonster  @ 000f73c0
void AlertFriends__12CTalkMonster(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c [16];
  float local_2c;
  
  piVar4 = (int *)0x0;
  local_4c = 0;
  do {
    iVar3 = (**(code **)(param_1[0x115] + 0x224))(param_1,local_4c);
    uVar1 = *(undefined4 *)(_12CTalkMonster_m_szFriends + iVar3 * 4);
    do {
      do {
        do {
          piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,uVar1);
          if (piVar4 == (int *)0x0) {
            piVar4 = (int *)0x0;
            goto LAB_000f74bb;
          }
        } while (piVar4 == param_1);
        iVar3 = (**(code **)(piVar4[0x115] + 0x8c))(piVar4);
      } while (iVar3 == 0);
      local_48 = *(undefined4 *)(*piVar4 + 8);
      local_44 = *(undefined4 *)(*piVar4 + 0xc);
      local_40 = *(undefined4 *)(*piVar4 + 0xd8);
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (*param_1 + 8,&local_48,1,*(undefined4 *)(*param_1 + 0x208),local_3c);
    } while ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40);
LAB_000f74bb:
    if (piVar4 == (int *)0x0) {
      local_4c = local_4c + 1;
      if (2 < local_4c) {
        return;
      }
    }
    else {
      iVar3 = (**(code **)(piVar4[0x115] + 0x50))(piVar4);
      iVar2 = (**(code **)(*(int *)(iVar3 + 0x454) + 0x8c))(iVar3);
      if (iVar2 != 0) {
        *(byte *)(iVar3 + 0x63c) = *(byte *)(iVar3 + 0x63c) | 1;
      }
    }
  } while( true );
}


