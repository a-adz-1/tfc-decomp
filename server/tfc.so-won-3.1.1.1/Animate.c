// Animate__13CCyclerSpritef  @ 000b40c4
void Animate__13CCyclerSpritef(int *param_1,float param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  
  *(float *)(*param_1 + 0x130) = *(float *)(*param_1 + 0x130) + param_2;
  lVar1 = (longdouble)(float)param_1[0x118];
  if ((longdouble)0 < lVar1) {
    lVar2 = (longdouble)*(float *)(*param_1 + 0x130);
    do {
      lVar2 = lVar2 - (longdouble)(unkint10)(lVar2 / lVar1) * lVar1;
    } while (NAN((longdouble)0) || NAN(lVar1));
    *(float *)(*param_1 + 0x130) = (float)lVar2;
  }
  return;
}


// Animate__5CGlowf  @ 000a4968
void Animate__5CGlowf(int *param_1,float param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  lVar1 = (longdouble)0;
  lVar2 = (longdouble)(float)param_1[0x117];
  if (0x3f < (byte)((lVar2 < lVar1 | (byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar2 == lVar1) << 0xe) >> 8)) - 1)) {
    lVar3 = (longdouble)*(float *)(*param_1 + 0x130) + (longdouble)param_2;
    do {
      lVar3 = lVar3 - (longdouble)(unkint10)(lVar3 / lVar2) * lVar2;
    } while ((NAN(lVar2) || NAN(lVar1)) != 0);
    *(float *)(*param_1 + 0x130) = (float)lVar3;
  }
  return;
}


// Animate__7CSpritef  @ 000a4454
void Animate__7CSpritef(int *param_1,float param_2)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  *(float *)(*param_1 + 0x130) = *(float *)(*param_1 + 0x130) + param_2;
  iVar1 = *param_1;
  lVar2 = (longdouble)(float)param_1[0x117];
  lVar3 = (longdouble)*(float *)(iVar1 + 0x130);
  if (0x3f < (byte)((lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) - 1)) {
    if ((*(byte *)(iVar1 + 0x1a0) & 2) == 0) {
      if ((longdouble)0 < lVar2) {
        do {
          lVar3 = lVar3 - (longdouble)(unkint10)(lVar3 / lVar2) * lVar2;
        } while (NAN((longdouble)0) || NAN(lVar2));
        *(float *)(iVar1 + 0x130) = (float)lVar3;
      }
    }
    else {
      TurnOff__7CSprite(param_1);
    }
  }
  return;
}


