// CreateSpot__10CLaserSpot  @ 000f4a8c
undefined4 * CreateSpot__10CLaserSpot(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)GetClassPtr__H1Z10CLaserSpot_PX01_PX01(0);
  (**(code **)(puVar1[0xf5] + 8))(puVar1);
  *(int *)*puVar1 = (int)"laser_spot" - *(int *)(gpGlobals + 0x98);
  return puVar1;
}


