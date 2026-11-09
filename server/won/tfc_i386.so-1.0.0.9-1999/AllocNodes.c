// AllocNodes__6CGraph  @ 000c9650
bool AllocNodes__6CGraph(void)

{
  bool bVar1;
  
  DAT_001758cc = calloc(0x58,0x400);
  bVar1 = DAT_001758cc == (void *)0x0;
  if (bVar1) {
    (*DAT_001755b4)(2,"**ERROR**\nCouldn\'t malloc %d nodes!\n",DAT_001758d8);
  }
  return !bVar1;
}


