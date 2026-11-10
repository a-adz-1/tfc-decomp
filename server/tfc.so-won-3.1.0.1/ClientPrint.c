// ClientPrint__FP9entvars_siPCcN42  @ 0010ad04
void ClientPrint__FP9entvars_siPCcN42
               (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
               int param_6,int param_7)

{
  (*DAT_001a7ef8)(1,gmsgTextMsg,0,*(undefined4 *)(param_1 + 0x208));
  (*DAT_001a7f00)(param_2);
  (*DAT_001a7f18)(param_3);
  if (param_4 != 0) {
    (*DAT_001a7f18)(param_4);
  }
  if (param_5 != 0) {
    (*DAT_001a7f18)(param_5);
  }
  if (param_6 != 0) {
    (*DAT_001a7f18)(param_6);
  }
  if (param_7 != 0) {
    (*DAT_001a7f18)(param_7);
  }
  (*DAT_001a7efc)();
  return;
}


