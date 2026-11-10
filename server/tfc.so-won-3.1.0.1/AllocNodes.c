// AllocNodes__6CGraph  @ 000b86b4
bool AllocNodes__6CGraph(void)

{
  bool bVar1;
  
  DAT_001a82ac = calloc(0x58,0x400);
  bVar1 = DAT_001a82ac != (void *)0x0;
  if (!bVar1) {
    (*DAT_001a7f34)(2,"**ERROR**\nCouldn\'t malloc %d nodes!\n",DAT_001a82b8);
  }
  return bVar1;
}


