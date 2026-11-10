// PrescheduleThink__12CBaseMonster  @ 000c304c
void PrescheduleThink__12CBaseMonster(void)

{
  return;
}


// PrescheduleThink__12CTalkMonster  @ 000f89a0
void PrescheduleThink__12CTalkMonster(int param_1)

{
  if ((*(uint *)(param_1 + 0x4f8) & 0x200000) == 0) {
    *(uint *)(param_1 + 0x4f8) = *(uint *)(param_1 + 0x4f8) | 0x20000000;
  }
  return;
}


