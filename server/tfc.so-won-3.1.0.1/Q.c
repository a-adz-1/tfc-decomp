// Q_log2  @ 0011f5f4
void Q_log2(int param_1)

{
  do {
    param_1 = param_1 >> 1;
  } while (param_1 != 0);
  return;
}


