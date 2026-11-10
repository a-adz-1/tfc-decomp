// MaterialSoundPrecache__10CBreakable9Materials  @ 000a994c
void MaterialSoundPrecache__10CBreakable9Materials(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int local_8;
  
  ppuVar2 = (undefined **)0x0;
  switch(param_1) {
  case 0:
  case 6:
  case 7:
    ppuVar2 = &_10CBreakable_pSoundsGlass;
    local_8 = 3;
    break;
  case 1:
    ppuVar2 = &_10CBreakable_pSoundsWood;
    local_8 = 3;
    break;
  case 2:
    ppuVar2 = &_10CBreakable_pSoundsMetal;
    local_8 = 3;
    break;
  case 3:
    ppuVar2 = &_10CBreakable_pSoundsFlesh;
    local_8 = 6;
    break;
  case 4:
  case 8:
    ppuVar2 = &_10CBreakable_pSoundsConcrete;
    local_8 = 3;
    break;
  default:
    local_8 = 0;
  }
  if (local_8 != 0) {
    iVar1 = 0;
    do {
      (*DAT_0019f6a4)(ppuVar2[iVar1]);
      iVar1 = iVar1 + 1;
    } while (iVar1 < local_8);
  }
  return;
}


