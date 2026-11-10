// AllocNodes__6CGraph  @ 000cb8dc
bool AllocNodes__6CGraph(void)

{
  bool bVar1;
  
  DAT_0019fb2c = calloc(0x58,0x400);
  bVar1 = DAT_0019fb2c != (void *)0x0;
  if (!bVar1) {
    (*DAT_0019f794)(2,"**ERROR**\nCouldn\'t malloc %d nodes!\n",DAT_0019fb38);
  }
  return bVar1;
}


