// MaterialSoundPrecache__10CBreakable9Materials  @ 000b23c0
void MaterialSoundPrecache__10CBreakable9Materials(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  iVar1 = MaterialSoundList__10CBreakable9MaterialsRi(param_1,&local_8);
  iVar2 = 0;
  if (0 < local_8) {
    do {
      (*DAT_001754c4)(*(undefined4 *)(iVar1 + iVar2 * 4));
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_8);
  }
  return;
}


