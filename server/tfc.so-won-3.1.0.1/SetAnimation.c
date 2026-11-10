// SetAnimation__11CBasePlayer11PLAYER_ANIM  @ 000ca44c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetAnimation__11CBasePlayer11PLAYER_ANIM(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  float local_48;
  char acStack_40 [64];
  
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
    if (((*(byte *)(*param_1 + 0x1a5) & 2) == 0) && (param_1[0x13a] - 7U < 2)) {
      param_1[0x13b] = param_1[0x13a];
    }
    else if (*(int *)(*param_1 + 0x1c0) < 2) {
      param_1[0x13b] = 3;
    }
    else if ((byte)((byte)((ushort)((ushort)NAN(local_48) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_48 == 0.0) << 0xe) >> 8)) == 0x40) {
      param_1[0x13b] = 0x32;
    }
    else {
      param_1[0x13b] = 6;
    }
    break;
  case 2:
    param_1[0x13b] = 7;
    break;
  case 3:
    param_1[0x13b] = 8;
    break;
  case 4:
    param_1[0x13b] = 0x24;
    iVar2 = (**(code **)(param_1[0xf5] + 0x1e4))(param_1);
    param_1[0x13b] = iVar2;
    break;
  case 5:
    iVar2 = param_1[0x13a];
    if (iVar2 != 0x24) {
      if (iVar2 < 0x25) {
        if ((8 < iVar2) || (iVar2 < 6)) {
LAB_000ca60c:
          param_1[0x13b] = 0x1c;
          break;
        }
      }
      else if (iVar2 != 0x32) goto LAB_000ca60c;
    }
    param_1[0x13b] = param_1[0x13a];
    break;
  case 6:
    uVar1 = (*DAT_001a7fa8)(0,7);
    switch(uVar1) {
    case 0:
      param_1[0x13b] = 0x24;
      break;
    case 1:
      param_1[0x13b] = 0x25;
      break;
    case 2:
      param_1[0x13b] = 0x26;
      break;
    case 3:
      param_1[0x13b] = 0x27;
      break;
    case 4:
      param_1[0x13b] = 0x42;
      break;
    case 5:
      param_1[0x13b] = 0x43;
      break;
    case 6:
      param_1[0x13b] = 0x44;
      break;
    default:
      param_1[0x13b] = 0x45;
    }
    iVar2 = LookupActivity__14CBaseAnimatingi(param_1,param_1[0x13b]);
    if (iVar2 == -1) {
      param_1[0x13b] = 0x24;
    }
  }
  switch(param_1[0x13b]) {
  case 3:
    if ((param_1[0x13a] == 0x1c) && (param_1[0xfb] == 0)) {
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
      if ((iVar2 == param_1[0x333]) && (param_1[0x334] != 0)) {
        iVar3 = param_1[0x334];
      }
      else {
        sprintf(acStack_40,*(char **)(g_PlayerAnimationNames + iVar2 * 4),param_1 + 0x32b);
        iVar3 = LookupSequence__14CBaseAnimatingPCc(param_1,acStack_40);
        param_1[0x334] = iVar3;
        param_1[0x333] = iVar2;
      }
      if (iVar3 == -1) {
        iVar3 = 0;
      }
      param_1[0x13a] = 3;
    }
    break;
  default:
    if (param_1[0x13a] == param_1[0x13b]) {
      return;
    }
    param_1[0x13a] = param_1[0x13b];
    iVar2 = LookupActivity__14CBaseAnimatingi(param_1,param_1[0x13b]);
    if (*(int *)(*param_1 + 0x128) == iVar2) {
      return;
    }
    *(undefined4 *)(*param_1 + 300) = 0;
    *(int *)(*param_1 + 0x128) = iVar2;
    goto LAB_000ca9b6;
  case 0x1c:
    iVar2 = 3;
    if ((*(byte *)(*param_1 + 0x1a5) & 0x40) != 0) {
      iVar2 = 4;
    }
    if ((iVar2 == param_1[0x333]) && (param_1[0x334] != 0)) {
      iVar3 = param_1[0x334];
    }
    else {
      sprintf(acStack_40,*(char **)(g_PlayerAnimationNames + iVar2 * 4),param_1 + 0x32b);
      iVar3 = LookupSequence__14CBaseAnimatingPCc(param_1,acStack_40);
      param_1[0x333] = iVar2;
      param_1[0x334] = iVar3;
    }
    if (iVar3 == -1) {
      iVar3 = 0;
    }
    if (((*(int *)(*param_1 + 0x128) != iVar3) || (param_1[0xfc] == 0)) &&
       (*(undefined4 *)(*param_1 + 0x130) = 0, param_1[0xfc] == 0)) {
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
    }
    param_1[0x13a] = param_1[0x13b];
    *(int *)(*param_1 + 0x128) = iVar3;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  if ((*(byte *)(*param_1 + 0x1a5) & 0x40) == 0) {
    if (_FUN_0013a664 < local_48) {
      uVar1 = 4;
      goto code_r0x000ca983;
    }
    if (0.0 < local_48) {
      uVar1 = 3;
      goto code_r0x000ca983;
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
code_r0x000ca983:
    uVar1 = LookupActivity__14CBaseAnimatingi(param_1,uVar1);
  }
  *(undefined4 *)(*param_1 + 300) = uVar1;
  if (*(int *)(*param_1 + 0x128) != iVar3) {
    *(int *)(*param_1 + 0x128) = iVar3;
LAB_000ca9b6:
    *(undefined4 *)(*param_1 + 0x130) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  return;
}


