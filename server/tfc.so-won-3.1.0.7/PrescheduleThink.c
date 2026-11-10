// PrescheduleThink__12CBaseMonster  @ 000c2788
void PrescheduleThink__12CBaseMonster(void)

{
  return;
}


// PrescheduleThink__12CTalkMonster  @ 000f693c
void PrescheduleThink__12CTalkMonster(int param_1)

{
  if ((*(byte *)(param_1 + 0x4ea) & 0x20) == 0) {
    *(byte *)(param_1 + 0x4eb) = *(byte *)(param_1 + 0x4eb) | 0x20;
  }
  return;
}


