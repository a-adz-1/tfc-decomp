// PlayStepSound__11CBasePlayerif  @ 000d9ea0
void PlayStepSound__11CBasePlayerif(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*g_pGameRules + 0xd8))(g_pGameRules,param_1,param_3);
  if (iVar1 != 0) {
    iVar1 = (*DAT_00175628)(0,1);
    iVar1 = iVar1 + param_1[0x1ec] * 2;
    param_1[0x1ec] = (uint)(param_1[0x1ec] == 0);
    switch(param_2) {
    default:
      if (iVar1 == 1) {
        FUN_000da509(param_3,0x3f4ccccd,0,100);
        return;
      }
      if (iVar1 < 2) {
        if (iVar1 == 0) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      else {
        if (iVar1 == 2) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
        if (iVar1 == 3) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      break;
    case 1:
      if (iVar1 == 1) {
        FUN_000da509(param_3,0x3f4ccccd,0,100);
        return;
      }
      if (iVar1 < 2) {
        if (iVar1 == 0) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      else {
        if (iVar1 == 2) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
        if (iVar1 == 3) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      break;
    case 2:
      if (iVar1 == 1) {
        FUN_000da509(param_3,0x3f4ccccd,0,100);
        return;
      }
      if (iVar1 < 2) {
        if (iVar1 == 0) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      else {
        if (iVar1 == 2) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
        if (iVar1 == 3) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      break;
    case 3:
      if (iVar1 == 1) {
        FUN_000da509(param_3,0x3f4ccccd,0,100);
        return;
      }
      if (iVar1 < 2) {
        if (iVar1 == 0) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      else {
        if (iVar1 == 2) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
        if (iVar1 == 3) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      break;
    case 4:
      if (iVar1 == 1) {
        FUN_000da509(param_3,0x3f4ccccd,0,100);
        return;
      }
      if (iVar1 < 2) {
        if (iVar1 == 0) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      else {
        if (iVar1 == 2) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
        if (iVar1 == 3) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      break;
    case 5:
      iVar2 = (*DAT_00175628)(0,4);
      if (iVar2 == 0) {
        iVar1 = 4;
      }
      switch(iVar1) {
      case 0:
        FUN_000da509(param_3,0x3f4ccccd,0,100);
        return;
      case 1:
        FUN_000da509(param_3,0x3f4ccccd,0,100);
        return;
      case 2:
        FUN_000da509(param_3,0x3f4ccccd,0,100);
        return;
      case 3:
        FUN_000da509(param_3,0x3f4ccccd,0,100);
        return;
      case 4:
        FUN_000da509(param_3,0x3f4ccccd,0,100);
        return;
      }
      break;
    case 6:
      if (iVar1 == 1) {
        FUN_000da509(param_3,0x3f4ccccd,0,100);
        return;
      }
      if (iVar1 < 2) {
        if (iVar1 == 0) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      else {
        if (iVar1 == 2) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
        if (iVar1 == 3) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      break;
    case 7:
      if (iSkipStep_766 == 0) {
        iSkipStep_766 = 1;
      }
      else {
        iSkipStep_766 = iSkipStep_766 + 1;
        if (iSkipStep_766 == 4) {
          iSkipStep_766 = 0;
        }
        if (iVar1 == 1) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
        if (iVar1 < 2) {
          if (iVar1 == 0) {
            FUN_000da509(param_3,0x3f4ccccd,0,100);
            return;
          }
        }
        else {
          if (iVar1 == 2) {
            FUN_000da509(param_3,0x3f4ccccd,0,100);
            return;
          }
          if (iVar1 == 3) {
            FUN_000da509(param_3,0x3f4ccccd,0,100);
            return;
          }
        }
      }
      break;
    case 8:
      if (iVar1 == 1) {
        FUN_000da509(param_3,0x3f4ccccd,0,100);
        return;
      }
      if (iVar1 < 2) {
        if (iVar1 == 0) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
      }
      else {
        if (iVar1 == 2) {
          FUN_000da509(param_3,0x3f4ccccd,0,100);
          return;
        }
        if (iVar1 == 3) {
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(*param_1 + 0x1e8),4,"player/pl_ladder4.wav",param_3,0x3f4ccccd,
                     0,100);
        }
      }
    }
  }
  return;
}


