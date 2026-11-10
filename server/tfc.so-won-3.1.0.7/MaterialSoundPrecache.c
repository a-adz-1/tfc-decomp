// MaterialSoundPrecache__10CBreakable9Materials  @ 000a8558
void MaterialSoundPrecache__10CBreakable9Materials(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int local_4;
  
  local_4 = 0;
  puVar1 = (undefined4 *)MaterialSoundList__10CBreakable9MaterialsRi(param_1,&local_4);
  if (0 < local_4) {
    iVar2 = 0;
    do {
      (*DAT_001c1024)(*puVar1);
      puVar1 = puVar1 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_4);
  }
  return;
}


