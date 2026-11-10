// Animate__13CCyclerSpritef  @ 000bbd30
void Animate__13CCyclerSpritef(int *param_1,float param_2)

{
  float fVar1;
  longdouble lVar2;
  
  *(float *)(*param_1 + 0x110) = param_2 + *(float *)(*param_1 + 0x110);
  fVar1 = (float)param_1[0xf5];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    lVar2 = (longdouble)*(float *)(*param_1 + 0x110);
    do {
      lVar2 = lVar2 - (longdouble)(unkint10)(lVar2 / (longdouble)(float)param_1[0xf5]) *
                      (longdouble)(float)param_1[0xf5];
    } while (NAN(fVar1) != 0);
    *(float *)(*param_1 + 0x110) = (float)lVar2;
  }
  return;
}


// Animate__5CGlowf  @ 000adec0
void Animate__5CGlowf(int *param_1,float param_2)

{
  float fVar1;
  longdouble lVar2;
  
  fVar1 = (float)param_1[0xf4];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    lVar2 = (longdouble)param_2 + (longdouble)*(float *)(*param_1 + 0x110);
    do {
      lVar2 = lVar2 - (longdouble)(unkint10)(lVar2 / (longdouble)(float)param_1[0xf4]) *
                      (longdouble)(float)param_1[0xf4];
    } while (NAN(fVar1) != 0);
    *(float *)(*param_1 + 0x110) = (float)lVar2;
  }
  return;
}


// Animate__7CSpritef  @ 000ae390
void Animate__7CSpritef(int *param_1,float param_2)

{
  float fVar1;
  longdouble lVar2;
  
  *(float *)(*param_1 + 0x110) = param_2 + *(float *)(*param_1 + 0x110);
  if ((float)param_1[0xf4] < *(float *)(*param_1 + 0x110)) {
    if ((*(byte *)(*param_1 + 0x180) & 2) == 0) {
      fVar1 = (float)param_1[0xf4];
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        lVar2 = (longdouble)*(float *)(*param_1 + 0x110);
        do {
          lVar2 = lVar2 - (longdouble)(unkint10)(lVar2 / (longdouble)(float)param_1[0xf4]) *
                          (longdouble)(float)param_1[0xf4];
        } while (NAN(fVar1) != 0);
        *(float *)(*param_1 + 0x110) = (float)lVar2;
      }
    }
    else {
      TurnOff__7CSprite(param_1);
    }
  }
  return;
}


