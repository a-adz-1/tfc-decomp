// UseSpecialSkill__11CBasePlayer  @ 000e2a3c
void UseSpecialSkill__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = (**(code **)(param_1[0x115] + 0x8c))(param_1);
  if (iVar2 == 0) {
    return;
  }
  switch(*(undefined4 *)(*param_1 + 0x20c)) {
  case 1:
    TeamFortress_DisplayDetectionItems__11CBasePlayer(param_1);
    break;
  case 2:
    if (((undefined4 *)param_1[0x237] != (undefined4 *)0x0) &&
       (iVar2 = strcmp((char *)(**(int **)param_1[0x237] + *(int *)(gpGlobals + 0x98)),
                       "tf_weapon_sniperrifle"), iVar2 == 0)) {
      iVar2 = param_1[0x237];
      fVar1 = *(float *)(iVar2 + 0x48c);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
        (**(code **)(*(int *)(iVar2 + 0x454) + 0x174))(iVar2);
      }
    }
    break;
  case 3:
    iVar2 = param_1[0x237];
    if (iVar2 != 0) {
      (**(code **)(*(int *)(iVar2 + 0x454) + 0x178))(iVar2);
    }
    break;
  case 4:
    if ((param_1[0x237] != 0) &&
       (fVar1 = *(float *)(param_1[0x237] + 0x488),
       (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
      ExplodeOldPipebomb__11CBasePlayerii(param_1,1,0);
    }
    break;
  case 5:
    pcVar3 = (char *)FUN_00150e04;
    goto LAB_000e2b7a;
  case 6:
    pcVar3 = "tf_weapon_ac";
    goto LAB_000e2b7a;
  case 7:
    pcVar3 = "tf_weapon_flamethrower";
LAB_000e2b7a:
    SelectItem__11CBasePlayerPCc(param_1,pcVar3);
    break;
  case 8:
    TeamFortress_SpyGoUndercover__11CBasePlayer(param_1);
    break;
  case 9:
    TeamFortress_EngineerBuild__11CBasePlayeri(param_1,0);
  }
  return;
}


