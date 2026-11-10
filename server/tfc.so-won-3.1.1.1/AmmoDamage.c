// AmmoDamage__FPCc  @ 000d3374
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longdouble AmmoDamage__FPCc(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  if (param_1 != (char *)0x0) {
    iVar1 = 4;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = "9mm";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001a1ccc;
    }
    iVar1 = 4;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = "357";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001a1cd0;
    }
    iVar1 = 0xb;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = "ARgrenades";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001a1cd8;
    }
    iVar1 = 9;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = "buckshot";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001a1cdc;
    }
    iVar1 = 6;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = "bolts";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)_DAT_001a1ce4;
    }
    iVar1 = 8;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = "rockets";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001a1ce8;
    }
    iVar1 = 8;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = "uranium";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)_DAT_001a1cec;
    }
    iVar1 = 0xd;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = "Hand Grenade";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001a1cfc;
    }
    iVar1 = 0xf;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = "Satchel Charge";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001a1d00;
    }
    iVar1 = 10;
    bVar4 = true;
    pcVar2 = "Trip Mine";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *param_1 == *pcVar2;
      param_1 = param_1 + 1;
      pcVar2 = pcVar2 + 1;
    } while (bVar4);
    if (bVar4) {
      return (longdouble)DAT_001a1d04;
    }
  }
  return (longdouble)0;
}


