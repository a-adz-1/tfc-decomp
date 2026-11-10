// MaterialSoundRandom__10CBreakableP7edict_s9Materialsf  @ 000a9850
void MaterialSoundRandom__10CBreakableP7edict_s9Materialsf
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined **ppuVar2;
  int local_8;
  
  ppuVar2 = (undefined **)0x0;
  switch(param_2) {
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
    iVar1 = (*DAT_0019f808)(0,local_8 + -1);
    EMIT_SOUND_DYN__FP7edict_siPCcffii(param_1,4,ppuVar2[iVar1],param_3,0x3f800000,0,100);
  }
  return;
}


