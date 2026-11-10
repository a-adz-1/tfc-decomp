// PrintState__17CBasePlayerWeapon  @ 00121d90
void PrintState__17CBasePlayerWeapon(int param_1)

{
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)*gpGlobals);
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)*(float *)(*(int *)(param_1 + 0x464) + 0x648));
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)*(float *)(param_1 + 0x478));
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)*(float *)(param_1 + 0x480));
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)(*(float *)(param_1 + 0x484) - *gpGlobals));
  COM_Log__FPcT0e("c:\\hlsv.log",&DAT_001547a6,*(undefined4 *)(param_1 + 0x4a4));
  COM_Log__FPcT0e("c:\\hlsv.log",&DAT_001547a6,*(undefined4 *)(param_1 + 0x4b0));
  return;
}


