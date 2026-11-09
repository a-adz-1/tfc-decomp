// Snd_AcquireBuffer  @ 001cca00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Snd_AcquireBuffer(void)

{
  snd_buffer_count = snd_buffer_count + 1;
  if (snd_buffer_count != 1) {
    return;
  }
  S_Startup();
  return;
}


// Snd_ReleaseBuffer  @ 001cc9e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Snd_ReleaseBuffer(void)

{
  snd_buffer_count = snd_buffer_count + -1;
  if (snd_buffer_count != 0) {
    return;
  }
  S_ClearBuffer();
  S_Shutdown();
  return;
}


// Snd_WriteLinearBlastStereo16  @ 001a9c10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Snd_WriteLinearBlastStereo16(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int val@[???] */
  if (0 < snd_linear_count) {
    iVar3 = 2;
    iVar4 = 0;
    iVar5 = 0;
    do {
      iVar2 = snd_p[iVar4] * snd_vol >> 8;
      if (iVar2 < 0x8000) {
        if (iVar2 < -0x8000) {
          *(undefined2 *)((int)snd_out + iVar5) = 0x8000;
        }
        else {
          *(short *)((int)snd_out + iVar5) = (short)((uint)(snd_p[iVar4] * snd_vol) >> 8);
        }
      }
      else {
        *(undefined2 *)((int)snd_out + iVar5) = 0x7fff;
      }
      iVar2 = *(int *)((int)snd_p + iVar3 * 2) * snd_vol;
      iVar1 = iVar2 >> 8;
      if (iVar1 < 0x8000) {
        if (iVar1 < -0x8000) {
          *(undefined2 *)((int)snd_out + iVar3) = 0x8000;
        }
        else {
          *(short *)((int)snd_out + iVar3) = (short)((uint)iVar2 >> 8);
        }
      }
      else {
        *(undefined2 *)((int)snd_out + iVar3) = 0x7fff;
      }
      iVar4 = iVar4 + 2;
      iVar3 = iVar3 + 4;
      iVar5 = iVar5 + 4;
    } while (iVar4 < snd_linear_count);
  }
  return;
}


