// Wavstream_Close  @ 001ac290
void Wavstream_Close(int i)

{
  if (wavstreams[i].hFile != (FileHandle_t)0x0) {
    FS_Close(wavstreams[i].hFile);
  }
  Q_memset(wavstreams + i,0,0x28);
  wavstreams[i].hFile = (FileHandle_t)0x0;
  return;
}


// Wavstream_GetNextChunk  @ 001ac2e0
void Wavstream_GetNextChunk(channel_t *ch,sfx_t *s)

{
  int *piVar1;
  int iVar2;
  byte *data;
  int iVar3;
  uint uVar4;
  int local_20 [4];
  
                    /* Unresolved local var: byte * data@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int cbread@[???]
                       Unresolved local var: int i@[???] */
  piVar1 = Cache_Check(&s->cache);
  uVar4 = (uint)(ch + -0x4f242) >> 6;
  iVar2 = wavstreams[uVar4].info.dataofs + wavstreams[uVar4].csamplesplayed;
  wavstreams[uVar4].lastposloaded = iVar2;
  data = COM_LoadFileLimit((char *)0x0,iVar2,0x8000,local_20,&wavstreams[uVar4].hFile);
  iVar3 = wavstreams[uVar4].info.samples - wavstreams[uVar4].csamplesplayed;
  wavstreams[uVar4].csamplesinmem = local_20[0];
  iVar2 = local_20[0];
  if (iVar3 < local_20[0]) {
    wavstreams[uVar4].csamplesinmem = iVar3;
    iVar2 = iVar3;
  }
  *piVar1 = iVar2;
  ResampleSfx(s,piVar1[2],piVar1[3],data,local_20[0]);
  return;
}


// Wavstream_Init  @ 001ac240
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Wavstream_Init(void)

{
  wavstream_t *dest;
  wavstream_t *pwVar1;
  
                    /* Unresolved local var: int i@[???] */
  dest = wavstreams;
  do {
    pwVar1 = dest + 1;
    Q_memset(dest,0,0x28);
    dest->hFile = (FileHandle_t)0x0;
    dest = pwVar1;
  } while (pwVar1 != (wavstream_t *)&known_sfx);
  return true;
}


