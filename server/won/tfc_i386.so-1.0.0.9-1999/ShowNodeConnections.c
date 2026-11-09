// ShowNodeConnections__6CGraphi  @ 000cb0b0
void ShowNodeConnections__6CGraphi(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  int iVar6;
  
  if ((*param_1 == 0) || (param_1[1] == 0)) {
    (*DAT_001755b4)(2,"Graph not ready!\n");
  }
  else if (param_2 < 0) {
    (*DAT_001755b4)(2,"Can\'t show connections for node %d\n",param_2);
  }
  else {
    iVar1 = param_1[3] + param_2 * 0x58;
    UTIL_ParticleEffect__FRC6VectorT0UlUl(iVar1,&g_vecZero,0xff,0x14);
    if (*(int *)(iVar1 + 0x20) < 1) {
      (*DAT_001755b4)(2,"**No Connections!\n");
    }
    if (0 < *(int *)(iVar1 + 0x20)) {
      param_2 = param_2 * 0x58;
      iVar6 = 0;
      do {
        puVar2 = (undefined4 *)
                 (param_1[3] +
                 *(int *)(param_1[4] + 4 + (iVar6 + *(int *)(param_1[3] + 0x24 + param_2)) * 0x18) *
                 0x58);
        uVar3 = *puVar2;
        uVar4 = puVar2[1];
        fVar5 = (float)puVar2[2];
        (*DAT_00175578)(0,0x17,0,0);
        (*DAT_00175580)(0x66);
        (*DAT_00175594)(*(undefined4 *)(param_1[3] + param_2));
        (*DAT_00175594)(*(undefined4 *)(param_1[3] + 4 + param_2));
        (*DAT_00175594)(*(float *)(param_1[3] + 8 + param_2) + 8.0);
        (*DAT_00175594)(uVar3);
        (*DAT_00175594)(uVar4);
        (*DAT_00175594)(fVar5 + 8.0);
        (*DAT_0017557c)();
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(iVar1 + 0x20));
    }
  }
  return;
}


