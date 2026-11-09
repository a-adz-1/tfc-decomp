// BEGIN_READ  @ 000cb2a0
void BEGIN_READ(void *buf,int size)

{
  giBadRead = 0;
  giRead = 0;
  giSize = size;
  gpBuf = buf;
  return;
}


