// SetAnimation__11CBasePlayer11PLAYER_ANIM  @ 000d5ab4
void SetAnimation__11CBasePlayer11PLAYER_ANIM(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  float local_48;
  char local_40 [64];
  
  iVar2 = *param_1;
  local_48 = SQRT(*(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                  *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
  if ((*(byte *)(iVar2 + 0x1a5) & 0x10) != 0) {
    local_48 = 0.0;
    param_2 = 0;
  }
  switch(param_2) {
  case 0:
  case 1:
    if (((*(byte *)(*param_1 + 0x1a5) & 2) == 0) && (param_1[0x156] - 7U < 2)) {
      param_1[0x157] = param_1[0x156];
    }
    else if (*(int *)(*param_1 + 0x1c0) < 2) {
      param_1[0x157] = 3;
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(local_48) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_48 == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x157] = 0x32;
    }
    else {
      param_1[0x157] = 6;
    }
    break;
  case 2:
    param_1[0x157] = 7;
    break;
  case 3:
    param_1[0x157] = 8;
    break;
  case 4:
    param_1[0x157] = 0x24;
    iVar2 = (**(code **)(param_1[0x111] + 0x1ec))(param_1);
    param_1[0x157] = iVar2;
    break;
  case 5:
    iVar2 = param_1[0x156];
    if (iVar2 != 0x24) {
      if (iVar2 < 0x25) {
        if ((8 < iVar2) || (iVar2 < 6)) {
LAB_000d5c74:
          param_1[0x157] = 0x1c;
          break;
        }
      }
      else if (iVar2 != 0x32) goto LAB_000d5c74;
    }
    param_1[0x157] = param_1[0x156];
    break;
  case 6:
    uVar1 = (*DAT_001c1188)(0,7);
    switch(uVar1) {
    case 0:
      param_1[0x157] = 0x24;
      break;
    case 1:
      param_1[0x157] = 0x25;
      break;
    case 2:
      param_1[0x157] = 0x26;
      break;
    case 3:
      param_1[0x157] = 0x27;
      break;
    case 4:
      param_1[0x157] = 0x42;
      break;
    case 5:
      param_1[0x157] = 0x43;
      break;
    case 6:
      param_1[0x157] = 0x44;
      break;
    default:
      param_1[0x157] = 0x45;
    }
    iVar2 = LookupActivity__14CBaseAnimatingi(param_1,param_1[0x157]);
    if (iVar2 == -1) {
      param_1[0x157] = 0x24;
    }
  }
  switch(param_1[0x157]) {
  case 3:
    if ((param_1[0x156] == 0x1c) && (param_1[0x117] == 0)) {
      iVar3 = *(int *)(*param_1 + 0x128);
    }
    else {
      if ((*(int *)(*param_1 + 0x20c) == 2) && ((*(byte *)((int)param_1 + 0x85) & 8) != 0)) {
        iVar2 = 5;
        if ((*(byte *)(*param_1 + 0x1a5) & 0x40) != 0) {
          iVar2 = 6;
        }
      }
      else {
        iVar2 = 1;
        if ((*(byte *)(*param_1 + 0x1a5) & 0x40) != 0) {
          iVar2 = 2;
        }
      }
      if ((iVar2 == param_1[0x350]) && (param_1[0x351] != 0)) {
        iVar3 = param_1[0x351];
      }
      else {
        sprintf(local_40,*(char **)(g_PlayerAnimationNames + iVar2 * 4),param_1 + 0x348);
        iVar3 = LookupSequence__14CBaseAnimatingPCc(param_1,local_40);
        param_1[0x351] = iVar3;
        param_1[0x350] = iVar2;
      }
      if (iVar3 == -1) {
        iVar3 = 0;
      }
      param_1[0x156] = 3;
    }
    break;
  default:
    if (param_1[0x156] == param_1[0x157]) {
      return;
    }
    param_1[0x156] = param_1[0x157];
    iVar2 = LookupActivity__14CBaseAnimatingi(param_1,param_1[0x157]);
    if (*(int *)(*param_1 + 0x128) == iVar2) {
      return;
    }
    *(undefined4 *)(*param_1 + 300) = 0;
    *(int *)(*param_1 + 0x128) = iVar2;
    goto LAB_000d601e;
  case 0x1c:
    iVar2 = 3;
    if ((*(byte *)(*param_1 + 0x1a5) & 0x40) != 0) {
      iVar2 = 4;
    }
    if ((iVar2 == param_1[0x350]) && (param_1[0x351] != 0)) {
      iVar3 = param_1[0x351];
    }
    else {
      sprintf(local_40,*(char **)(g_PlayerAnimationNames + iVar2 * 4),param_1 + 0x348);
      iVar3 = LookupSequence__14CBaseAnimatingPCc(param_1,local_40);
      param_1[0x350] = iVar2;
      param_1[0x351] = iVar3;
    }
    if (iVar3 == -1) {
      iVar3 = 0;
    }
    if (((*(int *)(*param_1 + 0x128) != iVar3) || (param_1[0x118] == 0)) &&
       (*(undefined4 *)(*param_1 + 0x130) = 0, param_1[0x118] == 0)) {
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
    }
    param_1[0x156] = param_1[0x157];
    *(int *)(*param_1 + 0x128) = iVar3;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  if ((*(byte *)(*param_1 + 0x1a5) & 0x40) == 0) {
    if (220.0 < local_48) {
      uVar1 = 4;
      goto LAB_000d5feb;
    }
    if (0.0 < local_48) {
      uVar1 = 3;
      goto LAB_000d5feb;
    }
    uVar1 = LookupSequence__14CBaseAnimatingPCc(param_1,"deep_idle");
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN(local_48) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_48 == 0.0) << 0xe) >> 8)) == 0x40) {
      uVar1 = 0x12;
    }
    else {
      uVar1 = 0x11;
    }
LAB_000d5feb:
    uVar1 = LookupActivity__14CBaseAnimatingi(param_1,uVar1);
  }
  *(undefined4 *)(*param_1 + 300) = uVar1;
  if (*(int *)(*param_1 + 0x128) != iVar3) {
    *(int *)(*param_1 + 0x128) = iVar3;
LAB_000d601e:
    *(undefined4 *)(*param_1 + 0x130) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  return;
}


