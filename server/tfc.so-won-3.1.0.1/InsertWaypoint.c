// InsertWaypoint__12CBaseMonsterG6Vectori  @ 000b1354
void InsertWaypoint__12CBaseMonsterG6Vectori(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x58c) * 0x10;
  uVar1 = *(uint *)(iVar2 + param_1 + 0x514);
  *(undefined4 *)(param_1 + 0x578) = *(undefined4 *)(param_1 + 0x568);
  *(undefined4 *)(param_1 + 0x57c) = *(undefined4 *)(param_1 + 0x56c);
  *(undefined4 *)(param_1 + 0x580) = *(undefined4 *)(param_1 + 0x570);
  *(undefined4 *)(param_1 + 0x584) = *(undefined4 *)(param_1 + 0x574);
  *(undefined4 *)(param_1 + 0x568) = *(undefined4 *)(param_1 + 0x558);
  *(undefined4 *)(param_1 + 0x56c) = *(undefined4 *)(param_1 + 0x55c);
  *(undefined4 *)(param_1 + 0x570) = *(undefined4 *)(param_1 + 0x560);
  *(undefined4 *)(param_1 + 0x574) = *(undefined4 *)(param_1 + 0x564);
  *(undefined4 *)(param_1 + 0x558) = *(undefined4 *)(param_1 + 0x548);
  *(undefined4 *)(param_1 + 0x55c) = *(undefined4 *)(param_1 + 0x54c);
  *(undefined4 *)(param_1 + 0x560) = *(undefined4 *)(param_1 + 0x550);
  *(undefined4 *)(param_1 + 0x564) = *(undefined4 *)(param_1 + 0x554);
  *(undefined4 *)(param_1 + 0x548) = *(undefined4 *)(param_1 + 0x538);
  *(undefined4 *)(param_1 + 0x54c) = *(undefined4 *)(param_1 + 0x53c);
  *(undefined4 *)(param_1 + 0x550) = *(undefined4 *)(param_1 + 0x540);
  *(undefined4 *)(param_1 + 0x554) = *(undefined4 *)(param_1 + 0x544);
  *(undefined4 *)(param_1 + 0x538) = *(undefined4 *)(param_1 + 0x528);
  *(undefined4 *)(param_1 + 0x53c) = *(undefined4 *)(param_1 + 0x52c);
  *(undefined4 *)(param_1 + 0x540) = *(undefined4 *)(param_1 + 0x530);
  *(undefined4 *)(param_1 + 0x544) = *(undefined4 *)(param_1 + 0x534);
  *(undefined4 *)(param_1 + 0x528) = *(undefined4 *)(param_1 + 0x518);
  *(undefined4 *)(param_1 + 0x52c) = *(undefined4 *)(param_1 + 0x51c);
  *(undefined4 *)(param_1 + 0x530) = *(undefined4 *)(param_1 + 0x520);
  *(undefined4 *)(param_1 + 0x534) = *(undefined4 *)(param_1 + 0x524);
  *(undefined4 *)(param_1 + 0x518) = *(undefined4 *)(param_1 + 0x508);
  *(undefined4 *)(param_1 + 0x51c) = *(undefined4 *)(param_1 + 0x50c);
  *(undefined4 *)(param_1 + 0x520) = *(undefined4 *)(param_1 + 0x510);
  *(undefined4 *)(param_1 + 0x524) = *(undefined4 *)(param_1 + 0x514);
  iVar2 = iVar2 + param_1;
  *(undefined4 *)(iVar2 + 0x508) = *param_2;
  *(undefined4 *)(iVar2 + 0x50c) = param_2[1];
  *(undefined4 *)(iVar2 + 0x510) = param_2[2];
  *(uint *)(*(int *)(param_1 + 0x58c) * 0x10 + param_1 + 0x514) = param_3 | uVar1 & 0xfffffe7f;
  return;
}


