// PrototypeWriteDamage__Fv  @ 000e4900
void PrototypeWriteDamage__Fv(void)

{
  FILE *__stream;
  
  __stream = fopen("prototype.txt","a");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%6.2f : Damages %6.2f %6.2f %6.2f : Factors %6.2f %6.2f %6.2f %6.2f\n",
            (double)*gpGlobals,(double)gfPrototypeTotalDamage,(double)gfPrototypeExtraDamage,
            (double)gfPrototypeLessDamage,(double)(float)teamadvantage._4_4_,
            (double)(float)teamadvantage._8_4_,(double)(float)teamadvantage._12_4_,
            (double)(float)teamadvantage._16_4_);
    fclose(__stream);
  }
  return;
}


