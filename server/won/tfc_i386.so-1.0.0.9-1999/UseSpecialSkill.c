// UseSpecialSkill__11CBasePlayer  @ 000e3170
void UseSpecialSkill__11CBasePlayer(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  char *pcVar4;
  
  switch(*(undefined4 *)(param_1 + 0x2c)) {
  case 1:
    TeamFortress_DisplayDetectionItems__11CBasePlayer(param_1);
    switchD_000e3184::default();
    return;
  case 2:
    if ((*(int *)(param_1 + 0x830) != 0) &&
       (iVar3 = strcmp((char *)(*(int *)**(undefined4 **)(param_1 + 0x830) + (int)gpGlobals[0x26]),
                       "tf_weapon_sniperrifle"), iVar3 == 0)) {
      iVar3 = *(int *)(param_1 + 0x830);
      fVar1 = *(float *)(iVar3 + 0x400);
      fVar2 = *gpGlobals;
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x168))(iVar3);
        switchD_000e3184::default();
        return;
      }
    }
    break;
  case 3:
    if (*(int *)(param_1 + 0x830) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0x830) + 0x3c8) + 0x16c))(*(int *)(param_1 + 0x830));
      switchD_000e3184::default();
      return;
    }
    break;
  case 4:
    if (*(int *)(param_1 + 0x830) != 0) {
      fVar1 = *(float *)(*(int *)(param_1 + 0x830) + 0x3fc);
      fVar2 = *gpGlobals;
      if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
        ExplodeOldPipebomb__11CBasePlayeri(param_1,1);
        switchD_000e3184::default();
        return;
      }
    }
    break;
  case 5:
    pcVar4 = "tf_weapon_medikit";
    goto LAB_000e32a5;
  case 6:
    pcVar4 = "tf_weapon_ac";
    goto LAB_000e32a5;
  case 7:
    pcVar4 = "tf_weapon_flamethrower";
LAB_000e32a5:
    SelectItem__11CBasePlayerPCc(param_1,pcVar4);
    switchD_000e3184::default();
    return;
  case 8:
    TeamFortress_SpyGoUndercover__11CBasePlayer(param_1);
    switchD_000e3184::default();
    return;
  case 9:
    TeamFortress_EngineerBuild__11CBasePlayer(param_1);
  }
  return;
}


