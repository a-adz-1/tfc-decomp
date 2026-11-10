// CanPlaySentence__12CBaseMonsteri  @ 000c31bc
void CanPlaySentence__12CBaseMonsteri(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x454) + 0x8c))(param_1);
  return;
}


// CanPlaySentence__12CTalkMonsteri  @ 000f8dc8
void CanPlaySentence__12CTalkMonsteri(int param_1,int param_2)

{
  if (param_2 == 0) {
    FOkToSpeak__12CTalkMonster(param_1);
  }
  else {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x8c))(param_1);
  }
  return;
}


