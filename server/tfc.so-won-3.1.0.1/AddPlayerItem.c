// AddPlayerItem__11CBaseEntityP15CBasePlayerItem  @ 00100700
undefined4 AddPlayerItem__11CBaseEntityP15CBasePlayerItem(void)

{
  return 0;
}


// AddPlayerItem__11CBasePlayerP15CBasePlayerItem  @ 000d0ad0
undefined4 AddPlayerItem__11CBasePlayerP15CBasePlayerItem(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(param_2[0xf5] + 0x10c))(param_2);
  puVar1 = *(undefined4 **)(param_1 + 0x82c + iVar2 * 4);
  do {
    if (puVar1 == (undefined4 *)0x0) {
      iVar2 = (**(code **)(param_2[0xf5] + 0x104))(param_2,param_1);
      if (iVar2 == 0) {
LAB_000d0c4c:
        if (gEvilImpulse101 != 0) {
LAB_000d0c57:
          (**(code **)(param_2[0xf5] + 0x134))(param_2);
        }
        uVar3 = 0;
      }
      else {
        (**(code **)(*g_pGameRules + 0x80))(g_pGameRules,param_1,param_2);
        CheckRespawn__15CBasePlayerItem(param_2);
        iVar2 = (**(code **)(param_2[0xf5] + 0x10c))(param_2);
        param_2[0xfe] = *(undefined4 *)(param_1 + 0x82c + iVar2 * 4);
        iVar2 = (**(code **)(param_2[0xf5] + 0x10c))(param_2);
        *(undefined4 **)(param_1 + 0x82c + iVar2 * 4) = param_2;
        iVar2 = (**(code **)(*g_pGameRules + 0x18))(g_pGameRules,param_1,param_2);
        if (iVar2 != 0) {
          SwitchWeapon__11CBasePlayerP15CBasePlayerItem(param_1,param_2);
        }
        uVar3 = 1;
      }
      return uVar3;
    }
    iVar2 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*puVar1),
                   (char *)(*(int *)*param_2 + *(int *)(gpGlobals + 0x98)));
    if (iVar2 == 0) {
      iVar2 = (**(code **)(param_2[0xf5] + 0x108))(param_2,puVar1);
      if (iVar2 == 0) goto LAB_000d0c4c;
      (**(code **)(*g_pGameRules + 0x80))(g_pGameRules,param_1,param_2);
      CheckRespawn__15CBasePlayerItem(param_2);
      (**(code **)(puVar1[0xf5] + 0x124))(puVar1);
      if (*(int *)(param_1 + 0x844) != 0) {
        (**(code **)(*(int *)(*(int *)(param_1 + 0x844) + 0x3d4) + 0x124))
                  (*(int *)(param_1 + 0x844));
      }
      goto LAB_000d0c57;
    }
    puVar1 = (undefined4 *)puVar1[0xfe];
  } while( true );
}


