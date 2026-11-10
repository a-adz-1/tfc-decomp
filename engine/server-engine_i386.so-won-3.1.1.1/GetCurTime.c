// GetCurTime__19CPerformanceCounter  @ 000d8c94
longdouble GetCurTime__19CPerformanceCounter(void)

{
  longdouble lVar1;
  timeval local_c;
  
  gettimeofday(&local_c,(__timezone_ptr_t)0x0);
  if (secbase_45 == 0) {
    secbase_45 = local_c.tv_sec;
    lVar1 = (longdouble)local_c.tv_usec / (longdouble)1000000.0;
  }
  else {
    lVar1 = (longdouble)local_c.tv_usec / (longdouble)1000000.0 +
            (longdouble)(local_c.tv_sec - secbase_45);
  }
  return lVar1;
}


// GetCurTime__7CEngine  @ 00099e1c
longdouble GetCurTime__7CEngine(int param_1)

{
  return (longdouble)*(double *)(param_1 + 0x10);
}


