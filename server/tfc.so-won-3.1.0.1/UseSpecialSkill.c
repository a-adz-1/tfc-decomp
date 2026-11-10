// UseSpecialSkill__11CBasePlayer  @ 000d7578
void UseSpecialSkill__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  code *pcVar3;
  char *pcVar4;
  
  iVar2 = (**(code **)(param_1[0xf5] + 0x88))(param_1);
  if (iVar2 == 0) {
    return;
  }
  switch(*(undefined4 *)(*param_1 + 0x20c)) {
  case 1:
    TeamFortress_DisplayDetectionItems__11CBasePlayer(param_1);
    break;
  case 2:
    if (param_1[0x211] == 0) {
      return;
    }
    iVar2 = strcmp((char *)(**(int **)param_1[0x211] + *(int *)(gpGlobals + 0x98)),
                   "tf_weapon_sniperrifle");
    if (iVar2 != 0) {
      return;
    }
    iVar2 = param_1[0x211];
    fVar1 = *(float *)(iVar2 + 0x40c);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      return;
    }
    pcVar3 = *(code **)(*(int *)(iVar2 + 0x3d4) + 0x16c);
    goto LAB_000d7684;
  case 3:
    if (param_1[0x211] == 0) {
      return;
    }
    iVar2 = param_1[0x211];
    pcVar3 = *(code **)(*(int *)(iVar2 + 0x3d4) + 0x170);
LAB_000d7684:
    (*pcVar3)(iVar2);
    break;
  case 4:
    if ((param_1[0x211] != 0) &&
       (fVar1 = *(float *)(param_1[0x211] + 0x408),
       (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
      ExplodeOldPipebomb__11CBasePlayerii(param_1,1,0);
    }
    break;
  case 5:
    pcVar4 = "tf_weapon_medikit";
    goto LAB_000d76d5_1;
  case 6:
    pcVar4 = "tf_weapon_ac";
    goto LAB_000d76d5_1;
  case 7:
    pcVar4 = "tf_weapon_flamethrower";
LAB_000d76d5_1:
    SelectItem__11CBasePlayerPCc(param_1,pcVar4);
    break;
  case 8:
    TeamFortress_SpyGoUndercover__11CBasePlayer(param_1);
    break;
  case 9:
    TeamFortress_EngineerBuild__11CBasePlayeri(param_1,0);
  }
  return;
}


