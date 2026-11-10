// Push__6CStacki  @ 000cb4f8
void Push__6CStacki(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 400) < 100) {
    *(undefined4 *)(param_1 + *(int *)(param_1 + 400) * 4) = param_2;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 1;
  }
  else {
    printf("Error!\n");
  }
  return;
}


