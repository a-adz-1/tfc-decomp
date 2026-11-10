// PrescheduleThink__12CBaseMonster  @ 000c86c0
void PrescheduleThink__12CBaseMonster(void)

{
  return;
}


// PrescheduleThink__12CTalkMonster  @ 000f2ed0
void PrescheduleThink__12CTalkMonster(int param_1)

{
  if ((*(byte *)(param_1 + 0x46e) & 0x20) == 0) {
    *(byte *)(param_1 + 0x46f) = *(byte *)(param_1 + 0x46f) | 0x20;
  }
  return;
}


