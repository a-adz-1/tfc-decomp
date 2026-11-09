// AddPlayerItem__11CBaseEntityP15CBasePlayerItem  @ 0010e4c0
undefined4 AddPlayerItem__11CBaseEntityP15CBasePlayerItem(void)

{
  return 0;
}


// AddPlayerItem__11CBasePlayerP15CBasePlayerItem  @ 000ddee0
undefined4 AddPlayerItem__11CBasePlayerP15CBasePlayerItem(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(param_2[0xf2] + 0x10c))(param_2);
  puVar1 = *(undefined4 **)(param_1 + 0x818 + iVar2 * 4);
  do {
    if (puVar1 == (undefined4 *)0x0) {
      iVar2 = (**(code **)(param_2[0xf2] + 0x104))(param_2,param_1);
      if (iVar2 == 0) {
LAB_000de050:
        if (gEvilImpulse101 != 0) {
LAB_000de059:
          (**(code **)(param_2[0xf2] + 0x134))(param_2);
        }
        uVar3 = 0;
      }
      else {
        (**(code **)(*g_pGameRules + 0x80))(g_pGameRules,param_1,param_2);
        CheckRespawn__15CBasePlayerItem(param_2);
        iVar2 = (**(code **)(param_2[0xf2] + 0x10c))(param_2);
        param_2[0xfb] = *(undefined4 *)(param_1 + 0x818 + iVar2 * 4);
        iVar2 = (**(code **)(param_2[0xf2] + 0x10c))(param_2);
        *(undefined4 **)(param_1 + 0x818 + iVar2 * 4) = param_2;
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
      iVar2 = (**(code **)(param_2[0xf2] + 0x108))(param_2,puVar1);
      if (iVar2 == 0) goto LAB_000de050;
      (**(code **)(*g_pGameRules + 0x80))(g_pGameRules,param_1,param_2);
      CheckRespawn__15CBasePlayerItem(param_2);
      (**(code **)(puVar1[0xf2] + 0x124))(puVar1);
      if (*(int *)(param_1 + 0x830) != 0) {
        (**(code **)(*(int *)(*(int *)(param_1 + 0x830) + 0x3c8) + 0x124))
                  (*(int *)(param_1 + 0x830));
      }
      goto LAB_000de059;
    }
    puVar1 = (undefined4 *)puVar1[0xfb];
  } while( true );
}


