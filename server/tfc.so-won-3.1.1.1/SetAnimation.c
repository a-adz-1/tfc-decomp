// SetAnimation__11CBasePlayer11PLAYER_ANIM  @ 000d5620
void SetAnimation__11CBasePlayer11PLAYER_ANIM(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_50;
  float local_4c;
  char local_44 [64];
  
  iVar2 = *param_1;
  local_4c = SQRT(*(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                  *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
  if ((*(byte *)(iVar2 + 0x1a5) & 0x10) != 0) {
    local_4c = 0.0;
    param_2 = 0;
  }
  switch(param_2) {
  case 0:
  case 1:
    if (((*(byte *)(*param_1 + 0x1a5) & 2) == 0) && (iVar2 = param_1[0x15a], iVar2 - 7U < 2))
    goto LAB_000d57f7;
    if (*(int *)(*param_1 + 0x1c0) < 2) {
      param_1[0x15b] = 3;
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(local_4c) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_4c == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x15b] = 0x32;
    }
    else {
      param_1[0x15b] = 6;
    }
    break;
  case 2:
    param_1[0x15b] = 7;
    break;
  case 3:
    param_1[0x15b] = 8;
    break;
  case 4:
    param_1[0x15b] = 0x24;
    iVar2 = (**(code **)(param_1[0x115] + 0x1ec))(param_1);
    param_1[0x15b] = iVar2;
    break;
  case 5:
    iVar2 = param_1[0x15a];
    if (iVar2 != 0x24) {
      if (iVar2 < 0x25) {
        if ((8 < iVar2) || (iVar2 < 6)) {
LAB_000d57cd:
          param_1[0x15b] = 0x1c;
          break;
        }
      }
      else if (iVar2 != 0x32) goto LAB_000d57cd;
    }
LAB_000d57f7:
    param_1[0x15b] = iVar2;
    break;
  case 6:
    uVar1 = (*DAT_0019f808)(0,7);
    switch(uVar1) {
    case 0:
      param_1[0x15b] = 0x24;
      break;
    case 1:
      param_1[0x15b] = 0x25;
      break;
    case 2:
      param_1[0x15b] = 0x26;
      break;
    case 3:
      param_1[0x15b] = 0x27;
      break;
    case 4:
      param_1[0x15b] = 0x42;
      break;
    case 5:
      param_1[0x15b] = 0x43;
      break;
    case 6:
      param_1[0x15b] = 0x44;
      break;
    default:
      param_1[0x15b] = 0x45;
    }
    iVar2 = LookupActivity__14CBaseAnimatingi(param_1,param_1[0x15b]);
    if (iVar2 == -1) {
      param_1[0x15b] = 0x24;
    }
  }
  iVar2 = param_1[0x15b];
  switch(iVar2) {
  case 3:
    if ((param_1[0x15a] == 0x1c) && (param_1[0x11b] == 0)) {
      iVar2 = *param_1;
      iVar3 = *(int *)(iVar2 + 0x128);
    }
    else {
      iVar2 = *param_1;
      if ((*(int *)(iVar2 + 0x20c) == 2) && ((*(byte *)((int)param_1 + 0x85) & 8) != 0)) {
        local_50 = 5;
        if ((*(byte *)(iVar2 + 0x1a5) & 0x40) != 0) {
          local_50 = 6;
        }
      }
      else {
        local_50 = 1;
        if ((*(byte *)(iVar2 + 0x1a5) & 0x40) != 0) {
          local_50 = 2;
        }
      }
      if ((local_50 != param_1[0x35a]) || (iVar3 = param_1[0x35b], iVar3 == 0)) {
        sprintf(local_44,*(char **)(g_PlayerAnimationNames + local_50 * 4),param_1 + 0x352);
        iVar3 = LookupSequence__14CBaseAnimatingPCc(param_1,local_44);
        param_1[0x35b] = iVar3;
        param_1[0x35a] = local_50;
      }
      if (iVar3 == -1) {
        iVar3 = 0;
      }
      param_1[0x15a] = 3;
      iVar2 = *param_1;
    }
    break;
  default:
    if (param_1[0x15a] == iVar2) {
      return;
    }
    param_1[0x15a] = iVar2;
    iVar2 = LookupActivity__14CBaseAnimatingi(param_1,iVar2);
    if (*(int *)(*param_1 + 0x128) == iVar2) {
      return;
    }
    *(undefined4 *)(*param_1 + 300) = 0;
    *(int *)(*param_1 + 0x128) = iVar2;
    goto LAB_000d5b72;
  case 0x1c:
    iVar2 = *param_1;
    local_50 = 3;
    if ((*(byte *)(iVar2 + 0x1a5) & 0x40) != 0) {
      local_50 = 4;
    }
    if ((local_50 != param_1[0x35a]) || (iVar3 = param_1[0x35b], iVar3 == 0)) {
      sprintf(local_44,*(char **)(g_PlayerAnimationNames + local_50 * 4),param_1 + 0x352);
      iVar3 = LookupSequence__14CBaseAnimatingPCc(param_1,local_44);
      param_1[0x35a] = local_50;
      param_1[0x35b] = iVar3;
      iVar2 = *param_1;
    }
    if (iVar3 == -1) {
      iVar3 = 0;
    }
    if (((*(int *)(iVar2 + 0x128) != iVar3) || (param_1[0x11c] == 0)) &&
       (*(undefined4 *)(iVar2 + 0x130) = 0, param_1[0x11c] == 0)) {
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
    }
    param_1[0x15a] = param_1[0x15b];
    *(int *)(*param_1 + 0x128) = iVar3;
    ResetSequenceInfo__14CBaseAnimating(param_1);
    iVar2 = *param_1;
  }
  if ((*(byte *)(iVar2 + 0x1a5) & 0x40) == 0) {
    if (220.0 < local_4c) {
      uVar1 = 4;
      goto LAB_000d5b3e;
    }
    if (0.0 < local_4c) {
      uVar1 = 3;
      goto LAB_000d5b3e;
    }
    uVar1 = LookupSequence__14CBaseAnimatingPCc(param_1,"deep_idle");
  }
  else {
    if ((byte)((byte)((ushort)((ushort)NAN(local_4c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_4c == 0.0) << 0xe) >> 8)) == 0x40) {
      uVar1 = 0x12;
    }
    else {
      uVar1 = 0x11;
    }
LAB_000d5b3e:
    uVar1 = LookupActivity__14CBaseAnimatingi(param_1,uVar1);
  }
  *(undefined4 *)(*param_1 + 300) = uVar1;
  if (*(int *)(*param_1 + 0x128) != iVar3) {
    *(int *)(*param_1 + 0x128) = iVar3;
LAB_000d5b72:
    *(undefined4 *)(*param_1 + 0x130) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  return;
}


