// Animate__13CCyclerSpritef  @ 000b4cbc
void Animate__13CCyclerSpritef(int *param_1,float param_2)

{
  longdouble lVar1;
  
  *(float *)(*param_1 + 0x130) = param_2 + *(float *)(*param_1 + 0x130);
  if (0.0 < (float)param_1[0x114]) {
    lVar1 = (longdouble)*(float *)(*param_1 + 0x130);
    do {
      lVar1 = lVar1 - (longdouble)(unkint10)(lVar1 / (longdouble)(float)param_1[0x114]) *
                      (longdouble)(float)param_1[0x114];
    } while (NAN((float)param_1[0x114]));
    *(float *)(*param_1 + 0x130) = (float)lVar1;
  }
  return;
}


// Animate__5CGlowf  @ 000a3048
void Animate__5CGlowf(int *param_1,float param_2)

{
  longdouble lVar1;
  
  if (0.0 < (float)param_1[0x113]) {
    lVar1 = (longdouble)param_2 + (longdouble)*(float *)(*param_1 + 0x130);
    do {
      lVar1 = lVar1 - (longdouble)(unkint10)(lVar1 / (longdouble)(float)param_1[0x113]) *
                      (longdouble)(float)param_1[0x113];
    } while (NAN((float)param_1[0x113]));
    *(float *)(*param_1 + 0x130) = (float)lVar1;
  }
  return;
}


// Animate__7CSpritef  @ 000a35d8
void Animate__7CSpritef(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  
  *(float *)(*param_1 + 0x130) = param_2 + *(float *)(*param_1 + 0x130);
  fVar1 = *(float *)(*param_1 + 0x130);
  fVar2 = (float)param_1[0x113];
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
    if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
      if (0.0 < (float)param_1[0x113]) {
        lVar3 = (longdouble)*(float *)(*param_1 + 0x130);
        do {
          lVar3 = lVar3 - (longdouble)(unkint10)(lVar3 / (longdouble)(float)param_1[0x113]) *
                          (longdouble)(float)param_1[0x113];
        } while (NAN((float)param_1[0x113]));
        *(float *)(*param_1 + 0x130) = (float)lVar3;
      }
    }
    else {
      TurnOff__7CSprite(param_1);
    }
  }
  return;
}


