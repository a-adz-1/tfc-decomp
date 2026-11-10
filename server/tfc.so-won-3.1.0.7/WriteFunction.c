// WriteFunction__5CSavePCcPCii  @ 0011d57c
void WriteFunction__5CSavePCcPCii(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  
  pcVar2 = (char *)(*DAT_001c115c)(*param_3);
  if (pcVar2 == (char *)0x0) {
    (*DAT_001c1114)(4,"Invalid function pointer in entity!");
  }
  else {
    uVar3 = 0xffffffff;
    pcVar4 = pcVar2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    BufferField__5CSavePCciT1(param_1,param_2,~uVar3,pcVar2);
  }
  return;
}


