// StartTrapMode__7CEngine  @ 00099e78
void StartTrapMode__7CEngine(int param_1)

{
  if (*(char *)(param_1 + 0x28) == '\0') {
    *(undefined1 *)(param_1 + 0x29) = 0;
    *(undefined1 *)(param_1 + 0x28) = 1;
  }
  return;
}


