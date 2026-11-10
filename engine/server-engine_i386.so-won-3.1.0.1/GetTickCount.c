// GetTickCount__10EasySocket  @ 0009ddf0
int GetTickCount__10EasySocket(void)

{
  timeval local_c;
  
  gettimeofday(&local_c,(__timezone_ptr_t)0x0);
  return local_c.tv_usec / 1000 + local_c.tv_sec * 1000;
}


