// Net_BadConnection_f  @ 0808bf30
void Net_BadConnection_f(void)

{
  undefined4 uVar1;
  
  if (cls == 5) {
    uVar1 = va("fakelag 200\nfakeloss 10\nnetchokeloop 1\nr_netgraph 1\n");
    Cbuf_AddText(uVar1);
    Con_Printf("Simulating a poor connection\n");
    Cbuf_AddText("ping\n");
  }
  return;
}


// Net_Rate_f  @ 08065710
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Net_Rate_f(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  
  iVar2 = Cmd_Argc();
  if (iVar2 == 2) {
    uVar3 = Cmd_Argv();
    lVar4 = (longdouble)__strtod_internal(uVar3,0,0);
    fVar1 = (float)lVar4;
    if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      fVar1 = 9999.0;
    }
    if ((fVar1 < 500.0) ||
       ((byte)(10000.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 10000.0) << 0xe) >> 8)) == 1)) {
      Con_Printf("Rate:  Maximum %f, Minimum %f\n",10000,500);
    }
    else {
      _DAT_081b5304 = (double)fVar1;
      net_rate = fVar1;
    }
  }
  else {
    Con_Printf("Usage:  rate <num>\nTransmission rate (bytes/sec)\nCurrent:  %.5f\n",
               (double)net_rate);
  }
  return;
}


