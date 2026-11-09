// Ghidra decompilation of functions from cl_dll/demo.cpp
// 2 functions, ordered by original source line

// Demo_WriteBuffer  @ 00069720  (line 38)

void Demo_WriteBuffer(int type,int size,uchar *buffer)

{
  int in_GS_OFFSET;
  int local_8010;
  undefined1 local_800c [32764];
  int local_10;
  
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: uchar[32768] buf@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_8010 = type;
  __memcpy_chk(local_800c,buffer,size,0x7ffc);
  (*(gEngfuncs.pDemoAPI)->WriteBuffer)(size + 4,(uchar *)&local_8010);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Demo_ReadBuffer  @ 000697c0  (line 58)

void Demo_ReadBuffer(int size,uchar *buffer)

{
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: int i@[???] */
  if (*(int *)buffer == 0) {
    g_demosniper = *(int *)(buffer + 4);
    if (*(int *)(buffer + 4) != 0) {
      g_demosniperdamage = *(int *)(buffer + 8);
      g_demosniperangles[0] = *(float *)(buffer + 0xc);
      g_demosniperangles[1] = *(float *)(buffer + 0x10);
      g_demosniperangles[2] = *(float *)(buffer + 0x14);
      g_demosniperorg[0] = *(float *)(buffer + 0x18);
      g_demosniperorg[1] = *(float *)(buffer + 0x1c);
      g_demosniperorg[2] = *(float *)(buffer + 0x20);
      return;
    }
    return;
  }
  if (*(int *)buffer == 1) {
    g_demozoom = *(float *)(buffer + 4);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000697e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.Con_DPrintf)("Unknown demo buffer type, skipping.\n");
  return;
}


