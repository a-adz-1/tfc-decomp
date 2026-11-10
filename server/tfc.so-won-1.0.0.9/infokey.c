// infokey__FP11CBasePlayerPCc  @ 000be1f0
undefined1 * infokey__FP11CBasePlayerPCc(int *param_1,int param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    puVar1 = &DAT_001348e6;
  }
  else {
    uVar2 = (*DAT_00175668)(*(undefined4 *)(*param_1 + 0x1e8),param_2);
    puVar1 = (undefined1 *)(*DAT_0017566c)(uVar2);
  }
  return puVar1;
}


