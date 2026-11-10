// UseSpecialSkill__11CBasePlayer  @ 000e32e8
void UseSpecialSkill__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  code *pcVar3;
  char *pcVar4;
  
  iVar2 = (**(code **)(param_1[0x111] + 0x8c))(param_1);
  if (iVar2 == 0) {
    return;
  }
  switch(*(undefined4 *)(*param_1 + 0x20c)) {
  case 1:
    TeamFortress_DisplayDetectionItems__11CBasePlayer(param_1);
    break;
  case 2:
    if (param_1[0x22d] == 0) {
      return;
    }
    iVar2 = strcmp((char *)(**(int **)param_1[0x22d] + *(int *)(gpGlobals + 0x98)),
                   "tf_weapon_sniperrifle");
    if (iVar2 != 0) {
      return;
    }
    iVar2 = param_1[0x22d];
    fVar1 = *(float *)(iVar2 + 0x47c);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      return;
    }
    pcVar3 = *(code **)(*(int *)(iVar2 + 0x444) + 0x174);
    goto LAB_000e33f4;
  case 3:
    if (param_1[0x22d] == 0) {
      return;
    }
    iVar2 = param_1[0x22d];
    pcVar3 = *(code **)(*(int *)(iVar2 + 0x444) + 0x178);
LAB_000e33f4:
    (*pcVar3)(iVar2);
    break;
  case 4:
    if ((param_1[0x22d] != 0) &&
       (fVar1 = *(float *)(param_1[0x22d] + 0x478),
       (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
      ExplodeOldPipebomb__11CBasePlayerii(param_1,1,0);
    }
    break;
  case 5:
    pcVar4 = (char *)FUN_0014bbb0;
    goto LAB_000e3446;
  case 6:
    pcVar4 = (char *)FUN_0014bbd4;
    goto LAB_000e3446;
  case 7:
    pcVar4 = "tf_weapon_flamethrower";
LAB_000e3446:
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


