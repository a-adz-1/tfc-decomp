// TrapMouse_Event__7CEngineib  @ 00099e40
void TrapMouse_Event__7CEngineib(int param_1,int param_2,char param_3)

{
  if (((*(char *)(param_1 + 0x28) != '\0') && (param_2 != 0)) && (param_3 == '\0')) {
    *(undefined1 *)(param_1 + 0x28) = 0;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(int *)(param_1 + 0x30) = param_2;
  }
  return;
}


