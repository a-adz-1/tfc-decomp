// VID_UpdateVID  @ 100841f0
void VID_UpdateVID(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_1055a060;
                    /* 0x841f0  60  VID_UpdateVID */
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// VID_UpdateWindowVars  @ 100841b0
void VID_UpdateWindowVars(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x841b0  61  VID_UpdateWindowVars */
  DAT_1055a010 = *param_1;
  DAT_1055a014 = param_1[1];
  DAT_1055a018 = param_1[2];
  DAT_1055a01c = param_1[3];
  DAT_1055a024 = param_2;
  DAT_1055a028 = param_3;
  return;
}


