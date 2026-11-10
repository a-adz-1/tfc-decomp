// disconnect__10EasySocket  @ 000d6cec
void disconnect__10EasySocket(int *param_1)

{
  sockaddr local_18;
  int local_8;
  
  param_1[6] = 0;
  if (param_1[1] == 1) {
    close__10EasySocket(param_1);
  }
  else {
    memset(&local_18,0,0x10);
    local_8 = connect(*param_1,&local_18,0x10);
    if (local_8 != 0) {
      close__10EasySocket(param_1);
    }
  }
  return;
}


