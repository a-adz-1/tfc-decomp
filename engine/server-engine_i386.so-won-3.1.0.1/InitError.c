// InitError__11AuthRequest  @ 00098c08
void InitError__11AuthRequest(int param_1)

{
  sprintf((char *)(param_1 + 0x8204),"No Error");
  *(undefined4 *)(param_1 + 0x8200) = 0;
  *(undefined4 *)(param_1 + 0x81f8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x81fc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x81f4) = 0;
  return;
}


