// Snd_AcquireBuffer  @ 10079450
void Snd_AcquireBuffer(void)

{
                    /* 0x79450  56  Snd_AcquireBuffer */
  if (DAT_1055a85c != 0) {
    FUN_1002d3e0();
    return;
  }
  if ((DAT_104c06c8 != 0) && (DAT_100d7f54 = DAT_100d7f54 + 1, DAT_100d7f54 == 1)) {
    FUN_1002d3e0();
    return;
  }
  return;
}


// Snd_ReleaseBuffer  @ 10079420
void Snd_ReleaseBuffer(void)

{
                    /* 0x79420  57  Snd_ReleaseBuffer */
  if (DAT_1055a85c != 0) {
    FUN_1002d9b0();
    return;
  }
  if ((DAT_104c06c8 != 0) && (DAT_100d7f54 = DAT_100d7f54 + -1, DAT_100d7f54 == 0)) {
    S_ClearBuffer();
    FUN_1002d9b0();
    return;
  }
  return;
}


