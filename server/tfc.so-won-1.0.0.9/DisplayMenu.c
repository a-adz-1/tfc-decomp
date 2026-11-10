// DisplayMenu__11CBasePlayerf  @ 000be830
void DisplayMenu__11CBasePlayerf(int param_1,float param_2)

{
  *(float *)(param_1 + 0x114) = param_2;
  if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 2.0) << 0xe) >> 8)) == 0x40) {
    Menu_Team__11CBasePlayer(param_1);
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_2 == 3.0) << 0xe) >> 8)) == 0x40) {
    Menu_Class__11CBasePlayer(param_1);
  }
  return;
}


