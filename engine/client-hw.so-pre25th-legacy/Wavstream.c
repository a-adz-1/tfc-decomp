// Wavstream_Close  @ 001fdd90
void Wavstream_Close(int i)

{
  if (wavstreams[i].hFile != (FileHandle_t)0x0) {
    FS_Close(wavstreams[i].hFile);
  }
  Q_memset(wavstreams + i,0,0x28);
  wavstreams[i].hFile = (FileHandle_t)0x0;
  return;
}


// Wavstream_GetNextChunk  @ 001fdde0
void Wavstream_GetNextChunk(channel_t *ch,sfx_t *s)

{
  int *piVar1;
  int iVar2;
  byte *data;
  int iVar3;
  uint uVar4;
  int local_10;
  
                    /* Unresolved local var: byte * data@[???]
                       Unresolved local var: sfxcache_t * sc@[???]
                       Unresolved local var: int cbread@[???]
                       Unresolved local var: int i@[???] */
  piVar1 = Cache_Check(&s->cache);
  uVar4 = (uint)ch[-0x4d847].origin >> 6;
  iVar2 = wavstreams[uVar4].csamplesplayed + wavstreams[uVar4].info.dataofs;
  wavstreams[uVar4].lastposloaded = iVar2;
  data = COM_LoadFileLimit((char *)0x0,iVar2,0x8000,&local_10,&wavstreams[uVar4].hFile);
  iVar3 = wavstreams[uVar4].info.samples - wavstreams[uVar4].csamplesplayed;
  wavstreams[uVar4].csamplesinmem = local_10;
  iVar2 = local_10;
  if (iVar3 < local_10) {
    wavstreams[uVar4].csamplesinmem = iVar3;
    iVar2 = iVar3;
  }
  *piVar1 = iVar2;
  ResampleSfx(s,piVar1[2],piVar1[3],data,local_10);
  return;
}


// Wavstream_Init  @ 001fdd40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean Wavstream_Init(void)

{
  int iVar1;
  int iVar2;
  FileHandle_t *ppvVar3;
  
                    /* Unresolved local var: int i@[???] */
  ppvVar3 = &wavstreams[0].hFile;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    Q_memset(wavstreams + iVar1,0,0x28);
    *ppvVar3 = (FileHandle_t)0x0;
    ppvVar3 = ppvVar3 + 10;
    iVar1 = iVar2;
  } while (iVar2 != 0x80);
  return true;
}


