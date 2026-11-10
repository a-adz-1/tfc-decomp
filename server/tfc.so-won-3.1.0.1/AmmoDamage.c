// AmmoDamage__FPCc  @ 000c7934
longdouble AmmoDamage__FPCc(code *param_1)

{
  int iVar1;
  code *pcVar2;
  code *pcVar3;
  bool bVar4;
  
  if (param_1 != (code *)0x0) {
    iVar1 = 4;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = FUN_0013a340;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001aa44c;
    }
    iVar1 = 4;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = (code *)&DAT_0013a344;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001aa450;
    }
    iVar1 = 0xb;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = (code *)"ARgrenades";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001aa458;
    }
    iVar1 = 9;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = (code *)"buckshot";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001aa45c;
    }
    iVar1 = 6;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = (code *)"bolts";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001aa464;
    }
    iVar1 = 8;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = (code *)"rockets";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001aa468;
    }
    iVar1 = 8;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = (code *)"uranium";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001aa46c;
    }
    iVar1 = 0xd;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = (code *)"Hand Grenade";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001aa47c;
    }
    iVar1 = 0xf;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = (code *)"Satchel Charge";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001aa480;
    }
    iVar1 = 10;
    bVar4 = true;
    pcVar2 = (code *)"Trip Mine";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *param_1 == *pcVar2;
      param_1 = param_1 + 1;
      pcVar2 = pcVar2 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001aa484;
    }
  }
  return (longdouble)0.0;
}


