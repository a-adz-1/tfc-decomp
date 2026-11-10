// PrintState__17CBasePlayerWeapon  @ 00124cc0
void PrintState__17CBasePlayerWeapon(int param_1)

{
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)*gpGlobals);
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)*(float *)(*(int *)(param_1 + 0x474) + 0x658));
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)*(float *)(param_1 + 0x488));
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)*(float *)(param_1 + 0x490));
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)(*(float *)(param_1 + 0x494) - *gpGlobals));
  COM_Log__FPcT0e("c:\\hlsv.log",&DAT_00159802,*(undefined4 *)(param_1 + 0x4b4));
  COM_Log__FPcT0e("c:\\hlsv.log",&DAT_00159802,*(undefined4 *)(param_1 + 0x4c0));
  return;
}


