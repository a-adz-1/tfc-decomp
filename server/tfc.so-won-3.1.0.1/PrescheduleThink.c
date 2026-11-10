// PrescheduleThink__12CBaseMonster  @ 000b7528
void PrescheduleThink__12CBaseMonster(void)

{
  return;
}


// PrescheduleThink__12CTalkMonster  @ 000e9c60
void PrescheduleThink__12CTalkMonster(int param_1)

{
  if ((*(byte *)(param_1 + 0x47a) & 0x20) == 0) {
    *(byte *)(param_1 + 0x47b) = *(byte *)(param_1 + 0x47b) | 0x20;
  }
  return;
}


