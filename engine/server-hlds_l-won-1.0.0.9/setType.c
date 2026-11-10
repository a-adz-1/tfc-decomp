// setType__10EasySocketQ210EasySocket10SocketType  @ 0808e0e0
void setType__10EasySocketQ210EasySocket10SocketType(int param_1,int param_2)

{
  if (*(int *)(param_1 + 4) != param_2) {
    close__10EasySocket(param_1);
  }
  *(int *)(param_1 + 4) = param_2;
  return;
}


