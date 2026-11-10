// GetTickCount__10EasySocket  @ 000d6ee8
int GetTickCount__10EasySocket(void)

{
  timeval local_10;
  
  gettimeofday(&local_10,(__timezone_ptr_t)0x0);
  return local_10.tv_usec / 1000 + local_10.tv_sec * 1000;
}


