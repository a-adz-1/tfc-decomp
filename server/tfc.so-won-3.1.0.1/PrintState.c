// PrintState__17CBasePlayerWeapon  @ 00112240
void PrintState__17CBasePlayerWeapon(int param_1)

{
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)*gpGlobals);
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)*(float *)(*(int *)(param_1 + 0x3f4) + 0x5d8));
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)*(float *)(param_1 + 0x408));
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)*(float *)(param_1 + 0x410));
  COM_Log__FPcT0e("c:\\hlsv.log","%.4f ",(double)(*(float *)(param_1 + 0x414) - *gpGlobals));
  COM_Log__FPcT0e("c:\\hlsv.log",&DAT_001432e6,*(undefined4 *)(param_1 + 0x434));
  COM_Log__FPcT0e("c:\\hlsv.log",&DAT_001432e6,*(undefined4 *)(param_1 + 0x440));
  return;
}


