// U_Random__Fv  @ 0011961c
uint U_Random__Fv(void)

{
  glSeed = glSeed * 0x10dcd + *(int *)(seed_table + (glSeed * 0x10dcd & 0xff) * 4) + 1;
  return glSeed & 0xfffffff;
}


// U_Srand__FUi  @ 00119678
void U_Srand__FUi(byte param_1)

{
  glSeed = *(undefined4 *)(seed_table + (uint)param_1 * 4);
  return;
}


