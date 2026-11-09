// CHudBenchmark::Bench_ScoreForValue  @ 000924d0
/* DWARF original prototype: int Bench_ScoreForValue(CHudBenchmark * this, int stage, float raw) */

int __thiscall CHudBenchmark::Bench_ScoreForValue(CHudBenchmark *this,int stage,float raw)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int score@[???]
                       Unresolved local var: int power_play@[DW_OP_reg1(ECX)] */
  if (stage == 2) {
    iVar1 = (int)(this->m_fAvgFrameRate * 100.0) / 0x48;
    iVar2 = 100;
    if (iVar1 < 0x65) {
      iVar2 = iVar1;
    }
    iVar1 = 0;
    if (-1 < iVar2) {
      iVar1 = iVar2;
    }
    iVar1 = (int)((double)iVar1 * 0.6);
    if (g_isPowerPlay != 0) {
      return (int)((float)iVar1 + 40.0);
    }
  }
  else if (stage == 3) {
    iVar2 = (int)((this->m_fAvgScore * 100.0) / 40.0);
    iVar1 = 0;
    if (-1 < iVar2) {
      iVar1 = iVar2;
    }
    if (100 < iVar1) {
      iVar1 = 100;
    }
    iVar1 = (int)((double)(100 - iVar1) * 0.6);
    if (g_isPowerPlay != 0) {
      return (int)((float)iVar1 + 40.0);
    }
  }
  else {
    if (stage == 1) {
      iVar2 = (int)(this->m_StoredLatency * 100.0);
      iVar1 = 0;
      if (-1 < iVar2) {
        iVar1 = iVar2;
      }
      if (100 < iVar1) {
        iVar1 = 100;
      }
      return 100 - iVar1;
    }
    iVar1 = 100;
  }
  return iVar1;
}


