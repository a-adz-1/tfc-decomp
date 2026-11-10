// PrototypeWriteDamage__Fv  @ 000d89d0
void PrototypeWriteDamage__Fv(void)

{
  FILE *__stream;
  
  __stream = fopen("prototype.txt","a");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%6.2f : Damages %6.2f %6.2f %6.2f : Factors %6.2f %6.2f %6.2f %6.2f\n",
            (double)*gpGlobals,(double)gfPrototypeTotalDamage,(double)gfPrototypeExtraDamage,
            (double)gfPrototypeLessDamage,(double)DAT_001b4a74,(double)DAT_001b4a78,
            (double)DAT_001b4a7c,(double)DAT_001b4a80);
    fclose(__stream);
  }
  return;
}


