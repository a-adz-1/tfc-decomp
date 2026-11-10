// PrototypeWriteDamage__Fv  @ 000e3e54
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PrototypeWriteDamage__Fv(void)

{
  FILE *__stream;
  
  __stream = fopen("prototype.txt","a");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%6.2f : Damages %6.2f %6.2f %6.2f : Factors %6.2f %6.2f %6.2f %6.2f\n",
            (double)*gpGlobals,(double)gfPrototypeTotalDamage,(double)gfPrototypeExtraDamage,
            (double)gfPrototypeLessDamage,(double)DAT_001ac4c8,(double)_DAT_001ac4cc,
            (double)_DAT_001ac4d0,(double)_DAT_001ac4d4);
    fclose(__stream);
  }
  return;
}


