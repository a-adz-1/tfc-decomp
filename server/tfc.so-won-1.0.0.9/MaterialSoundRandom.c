// MaterialSoundRandom__10CBreakableP7edict_s9Materialsf  @ 000b2410
void MaterialSoundRandom__10CBreakableP7edict_s9Materialsf
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  iVar1 = MaterialSoundList__10CBreakable9MaterialsRi(param_2,&local_8);
  if (local_8 != 0) {
    iVar2 = (*DAT_00175628)(0,local_8 + -1);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (param_1,4,*(undefined4 *)(iVar1 + iVar2 * 4),param_3,0x3f800000,0,100);
  }
  return;
}


