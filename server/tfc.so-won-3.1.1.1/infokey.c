// infokey__FP11CBasePlayerPCc  @ 000bad64
undefined1 * infokey__FP11CBasePlayerPCc(int *param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    puVar2 = &DAT_0014cd26;
  }
  else {
    uVar1 = (*DAT_0019f848)(*(undefined4 *)(*param_1 + 0x208),param_2);
    puVar2 = (undefined1 *)(*DAT_0019f84c)(uVar1);
  }
  return puVar2;
}


