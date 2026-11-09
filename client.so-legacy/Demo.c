// Demo_ReadBuffer  @ 0008d050
void Demo_ReadBuffer(int size,uchar *buffer)

{
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: int i@[???] */
  if (*(int *)buffer != 0) {
    if (*(int *)buffer != 1) {
                    /* WARNING: Could not recover jumptable at 0x0008d0c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*gEngfuncs.Con_DPrintf)("Unknown demo buffer type, skipping.\n");
      return;
    }
    g_demozoom = *(float *)(buffer + 4);
    return;
  }
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


// Demo_WriteBuffer  @ 0008cf80
/* WARNING: Removing unreachable block (ram,0x0008d038) */

void Demo_WriteBuffer(int type,int size,uchar *buffer)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uchar *puVar4;
  int local_800c;
  uchar local_8008 [32764];
  
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: uchar[32768] buf@[???] */
  puVar4 = local_8008;
  local_800c = type;
  uVar1 = size;
  if (7 < (uint)size) {
    uVar1 = size & 3;
    for (uVar3 = (uint)size >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)puVar4 = *(undefined4 *)buffer;
      buffer = buffer + 4;
      puVar4 = puVar4 + 4;
    }
  }
  iVar2 = 0;
  if ((uVar1 & 4) != 0) {
    *(undefined4 *)puVar4 = *(undefined4 *)buffer;
    iVar2 = 4;
  }
  if ((uVar1 & 2) != 0) {
    *(undefined2 *)(puVar4 + iVar2) = *(undefined2 *)(buffer + iVar2);
    iVar2 = iVar2 + 2;
  }
  if ((uVar1 & 1) != 0) {
    puVar4[iVar2] = buffer[iVar2];
  }
  (*(gEngfuncs.pDemoAPI)->WriteBuffer)(size + 4,(uchar *)&local_800c);
  return;
}


