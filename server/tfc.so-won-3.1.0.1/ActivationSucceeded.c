// ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0  @ 000fc70c
undefined4 ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  
  fVar1 = *gpGlobals;
  if (((byte)((cb_prematch_time < fVar1 |
               (byte)((ushort)((ushort)(NAN(cb_prematch_time) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(cb_prematch_time == fVar1) << 0xe) >> 8)) - 1) < 0x40) ||
     (iVar2 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x28))(param_1), iVar2 == 0x81)) {
    iVar2 = ShouldActivate__FP11CBaseEntityT0(param_1,param_2);
    if (iVar2 != 0) {
      return 1;
    }
    if ((*(int *)(param_1 + 0x230) != 0) &&
       (iVar2 = Findgoal__Fi(*(undefined4 *)(param_1 + 0x230)), iVar2 != 0)) {
      ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0(iVar2,param_2,param_1);
    }
  }
  return 0;
}


