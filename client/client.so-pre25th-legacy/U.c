// U_Random  @ 0008bfd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint U_Random(void)

{
  glSeed = glSeed * 0x10dcd + 1 + seed_table[glSeed * 0x10dcd & 0xff];
  return glSeed & 0xfffffff;
}


// U_Srand  @ 0008c000
void U_Srand(uint seed)

{
  glSeed = seed_table[seed & 0xff];
  return;
}


