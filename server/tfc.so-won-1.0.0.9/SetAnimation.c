// SetAnimation__11CBasePlayer11PLAYER_ANIM  @ 000d7f90
void SetAnimation__11CBasePlayer11PLAYER_ANIM(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  float local_4c;
  char acStack_44 [64];
  
  iVar2 = *param_1;
  local_4c = SQRT(*(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                  *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20));
  if ((*(byte *)(iVar2 + 0x185) & 0x10) != 0) {
    local_4c = 0.0;
    param_2 = 0;
  }
  switch(param_2) {
  case 0:
  case 1:
    if (((*(byte *)(*param_1 + 0x185) & 2) == 0) && (param_1[0x137] - 7U < 2)) {
      param_1[0x138] = param_1[0x137];
    }
    else if (*(int *)(*param_1 + 0x1a0) < 2) {
      param_1[0x138] = 3;
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(local_4c) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_4c == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x138] = 0x32;
    }
    else {
      param_1[0x138] = 6;
    }
    break;
  case 2:
    param_1[0x138] = 7;
    break;
  case 3:
    param_1[0x138] = 8;
    break;
  case 4:
    param_1[0x138] = 0x24;
    iVar2 = (**(code **)(param_1[0xf2] + 0x1e4))(param_1);
    param_1[0x138] = iVar2;
    break;
  case 5:
    iVar2 = param_1[0x137];
    if (iVar2 != 0x24) {
      if (iVar2 < 0x25) {
        if ((8 < iVar2) || (iVar2 < 6)) {
LAB_000d8140:
          param_1[0x138] = 0x1c;
          break;
        }
      }
      else if (iVar2 != 0x32) goto LAB_000d8140;
    }
    param_1[0x138] = param_1[0x137];
    break;
  case 6:
    uVar1 = (*DAT_00175628)(0,7);
    switch(uVar1) {
    case 0:
      param_1[0x138] = 0x24;
      break;
    case 1:
      param_1[0x138] = 0x25;
      break;
    case 2:
      param_1[0x138] = 0x26;
      break;
    case 3:
      param_1[0x138] = 0x27;
      break;
    case 4:
      param_1[0x138] = 0x42;
      break;
    case 5:
      param_1[0x138] = 0x43;
      break;
    case 6:
      param_1[0x138] = 0x44;
      break;
    default:
      param_1[0x138] = 0x45;
    }
    iVar2 = LookupActivity__14CBaseAnimatingi(param_1,param_1[0x138]);
    if (iVar2 == -1) {
      param_1[0x138] = 0x24;
    }
  }
  switch(param_1[0x138]) {
  case 3:
    if ((param_1[0x137] == 0x1c) && (param_1[0xf8] == 0)) {
      iVar3 = *(int *)(*param_1 + 0x108);
    }
    else {
      if ((param_1[0xb] == 2) && ((*(byte *)((int)param_1 + 0x89) & 8) != 0)) {
        iVar2 = 5;
        if ((*(byte *)(*param_1 + 0x185) & 0x40) != 0) {
          iVar2 = 6;
        }
      }
      else {
        iVar2 = 1;
        if ((*(byte *)(*param_1 + 0x185) & 0x40) != 0) {
          iVar2 = 2;
        }
      }
      if ((iVar2 == param_1[0x32d]) && (param_1[0x32e] != 0)) {
        iVar3 = param_1[0x32e];
      }
      else {
        sprintf(acStack_44,*(char **)(g_PlayerAnimationNames + iVar2 * 4),param_1 + 0x325);
        iVar3 = LookupSequence__14CBaseAnimatingPCc(param_1,acStack_44);
        param_1[0x32e] = iVar3;
        param_1[0x32d] = iVar2;
      }
      if (iVar3 == -1) {
        iVar3 = 0;
      }
      param_1[0x137] = 3;
    }
    break;
  default:
    if (param_1[0x137] == param_1[0x138]) {
      return;
    }
    param_1[0x137] = param_1[0x138];
    iVar2 = LookupActivity__14CBaseAnimatingi(param_1,param_1[0x138]);
    if (*(int *)(*param_1 + 0x108) == iVar2) {
      return;
    }
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    *(int *)(*param_1 + 0x108) = iVar2;
    goto LAB_000d8458;
  case 0x1c:
    iVar2 = 3;
    if ((*(byte *)(*param_1 + 0x185) & 0x40) != 0) {
      iVar2 = 4;
    }
    if ((iVar2 == param_1[0x32d]) && (param_1[0x32e] != 0)) {
      iVar3 = param_1[0x32e];
    }
    else {
      sprintf(acStack_44,*(char **)(g_PlayerAnimationNames + iVar2 * 4),param_1 + 0x325);
      iVar3 = LookupSequence__14CBaseAnimatingPCc(param_1,acStack_44);
      param_1[0x32d] = iVar2;
      param_1[0x32e] = iVar3;
    }
    if (iVar3 == -1) {
      iVar3 = 0;
    }
    if (((*(int *)(*param_1 + 0x108) != iVar3) || (param_1[0xf9] == 0)) &&
       (*(undefined4 *)(*param_1 + 0x110) = 0, param_1[0xf9] == 0)) {
      *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x20;
    }
    param_1[0x137] = param_1[0x138];
    *(int *)(*param_1 + 0x108) = iVar3;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  if ((*(byte *)(*param_1 + 0x185) & 0x40) == 0) {
    if ((byte)(220.0 < local_4c | (byte)((ushort)((ushort)NAN(local_4c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_4c == 220.0) << 0xe) >> 8)) == 1) {
      uVar1 = 4;
      goto LAB_000d8421;
    }
    if ((byte)(0.0 < local_4c | (byte)((ushort)((ushort)NAN(local_4c) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_4c == 0.0) << 0xe) >> 8)) == 1) {
      uVar1 = 3;
      goto LAB_000d8421;
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
LAB_000d8421:
    uVar1 = LookupActivity__14CBaseAnimatingi(param_1,uVar1);
  }
  *(undefined4 *)(*param_1 + 0x10c) = uVar1;
  if (*(int *)(*param_1 + 0x108) != iVar3) {
    *(int *)(*param_1 + 0x108) = iVar3;
LAB_000d8458:
    *(undefined4 *)(*param_1 + 0x110) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  return;
}


