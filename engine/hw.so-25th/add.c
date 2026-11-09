// add_pair_to_block  @ 001df7e0
void add_pair_to_block(void)

{
  uint uVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  
  uVar1 = *(uint *)(in_EAX + 0x34);
  iVar2 = *(int *)(in_EAX + 0x38);
  if (0 < iVar2) {
    uVar4 = *(uint *)(in_EAX + 0x260);
    iVar3 = 0;
    do {
      uVar4 = *(uint *)(BZ2_crc32Table + (uVar4 >> 0x18 ^ uVar1 & 0xff) * 4) ^ uVar4 << 8;
      iVar3 = iVar3 + 1;
    } while (iVar3 != iVar2);
    *(uint *)(in_EAX + 0x260) = uVar4;
  }
  *(undefined1 *)(in_EAX + 0x58 + uVar1) = 1;
  uVar5 = (undefined1)uVar1;
  if (iVar2 == 2) {
    *(undefined1 *)(*(int *)(in_EAX + 0x24) + *(int *)(in_EAX + 0x44)) = uVar5;
  }
  else {
    if (iVar2 != 3) {
      if (iVar2 != 1) {
        *(undefined1 *)(in_EAX + 0x54 + iVar2) = 1;
        *(undefined1 *)(*(int *)(in_EAX + 0x24) + *(int *)(in_EAX + 0x44)) = uVar5;
        iVar2 = *(int *)(in_EAX + 0x44);
        *(int *)(in_EAX + 0x44) = iVar2 + 1;
        *(undefined1 *)(*(int *)(in_EAX + 0x24) + 1 + iVar2) = uVar5;
        iVar2 = *(int *)(in_EAX + 0x44);
        *(int *)(in_EAX + 0x44) = iVar2 + 1;
        *(undefined1 *)(*(int *)(in_EAX + 0x24) + 1 + iVar2) = uVar5;
        iVar2 = *(int *)(in_EAX + 0x44);
        *(int *)(in_EAX + 0x44) = iVar2 + 1;
        *(undefined1 *)(*(int *)(in_EAX + 0x24) + 1 + iVar2) = uVar5;
        iVar2 = *(int *)(in_EAX + 0x44);
        *(int *)(in_EAX + 0x44) = iVar2 + 1;
        *(char *)(*(int *)(in_EAX + 0x24) + 1 + iVar2) = (char)*(undefined4 *)(in_EAX + 0x38) + -4;
        *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x44) + 1;
        return;
      }
      *(undefined1 *)(*(int *)(in_EAX + 0x24) + *(int *)(in_EAX + 0x44)) = uVar5;
      *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x44) + 1;
      return;
    }
    *(undefined1 *)(*(int *)(in_EAX + 0x24) + *(int *)(in_EAX + 0x44)) = uVar5;
    iVar2 = *(int *)(in_EAX + 0x44);
    *(int *)(in_EAX + 0x44) = iVar2 + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x24) + 1 + iVar2) = uVar5;
  }
  iVar2 = *(int *)(in_EAX + 0x44);
  *(int *)(in_EAX + 0x44) = iVar2 + 1;
  *(undefined1 *)(*(int *)(in_EAX + 0x24) + 1 + iVar2) = uVar5;
  *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x44) + 1;
  return;
}


