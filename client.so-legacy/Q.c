// Q_log2  @ 000d8f20
int Q_log2(int val)

{
  int iVar1;
  
                    /* Unresolved local var: int answer@[???] */
  iVar1 = 0;
  while (val = val >> 1, val != 0) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


