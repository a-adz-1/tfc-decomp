// legacy_Mod_ForName  @ 00139da0
model_s * legacy_Mod_ForName(char *model,int crash)

{
  model_t *pmVar1;
  
  pmVar1 = Mod_ForName(model,crash,false);
  return pmVar1;
}


