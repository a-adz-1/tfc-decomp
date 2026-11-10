// infokey__FP11CBasePlayerPCc  @ 000ac754
undefined1 * infokey__FP11CBasePlayerPCc(int *param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    puVar2 = &DAT_00136f46;
  }
  else {
    uVar1 = (*DAT_001a7fe8)(*(undefined4 *)(*param_1 + 0x208),param_2);
    puVar2 = (undefined1 *)(*DAT_001a7fec)(uVar1);
  }
  return puVar2;
}


