// AllocNodes__6CGraph  @ 000c3994
bool AllocNodes__6CGraph(void)

{
  bool bVar1;
  
  DAT_001c148c = calloc(0x58,0x400);
  bVar1 = DAT_001c148c != (void *)0x0;
  if (!bVar1) {
    (*DAT_001c1114)(2,"**ERROR**\nCouldn\'t malloc %d nodes!\n",DAT_001c1498);
  }
  return bVar1;
}


