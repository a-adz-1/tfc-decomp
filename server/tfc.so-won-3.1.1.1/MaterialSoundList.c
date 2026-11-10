// MaterialSoundList__10CBreakable9MaterialsRi  @ 000a9a30
undefined ** MaterialSoundList__10CBreakable9MaterialsRi(undefined4 param_1,undefined4 *param_2)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)0x0;
  switch(param_1) {
  case 0:
  case 6:
  case 7:
    ppuVar1 = &_10CBreakable_pSoundsGlass;
    *param_2 = 3;
    break;
  case 1:
    ppuVar1 = &_10CBreakable_pSoundsWood;
    *param_2 = 3;
    break;
  case 2:
    ppuVar1 = &_10CBreakable_pSoundsMetal;
    *param_2 = 3;
    break;
  case 3:
    ppuVar1 = &_10CBreakable_pSoundsFlesh;
    *param_2 = 6;
    break;
  case 4:
  case 8:
    ppuVar1 = &_10CBreakable_pSoundsConcrete;
    *param_2 = 3;
    break;
  default:
    *param_2 = 0;
  }
  return ppuVar1;
}


