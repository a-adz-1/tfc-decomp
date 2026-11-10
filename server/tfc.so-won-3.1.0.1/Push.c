// Push__6CStacki  @ 000bd298
void Push__6CStacki(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 400) < 100) {
    *(undefined4 *)(*(int *)(param_1 + 400) * 4 + param_1) = param_2;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 1;
  }
  else {
    printf("Error!\n");
  }
  return;
}


