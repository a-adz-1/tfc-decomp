// ShowNodeConnections__6CGraphi  @ 000c5814
void ShowNodeConnections__6CGraphi(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  
  if ((*param_1 == 0) || (param_1[1] == 0)) {
    (*DAT_001c1114)(2,"Graph not ready!\n");
  }
  else if (param_2 < 0) {
    (*DAT_001c1114)(2,"Can\'t show connections for node %d\n",param_2);
  }
  else {
    iVar1 = param_1[3] + param_2 * 0x58;
    UTIL_ParticleEffect__FRC6VectorT0UlUl(iVar1,&g_vecZero,0xff,0x14);
    if (*(int *)(iVar1 + 0x20) < 1) {
      (*DAT_001c1114)(2,"**No Connections!\n");
    }
    for (iVar7 = 0; iVar7 < *(int *)(iVar1 + 0x20); iVar7 = iVar7 + 1) {
      iVar6 = param_2 * 0x58;
      puVar2 = (undefined4 *)
               (param_1[3] +
               *(int *)(param_1[4] + 4 + (iVar7 + *(int *)(param_1[3] + 0x24 + iVar6)) * 0x18) *
               0x58);
      uVar3 = *puVar2;
      uVar4 = puVar2[1];
      fVar5 = (float)puVar2[2];
      (*DAT_001c10d8)(0,0x17,0,0);
      (*DAT_001c10e0)(0x66);
      (*DAT_001c10f4)(*(undefined4 *)(param_1[3] + iVar6));
      (*DAT_001c10f4)(*(undefined4 *)(param_1[3] + 4 + iVar6));
      (*DAT_001c10f4)(*(float *)(param_1[3] + 8 + iVar6) + 8.0);
      (*DAT_001c10f4)(uVar3);
      (*DAT_001c10f4)(uVar4);
      (*DAT_001c10f4)(fVar5 + 8.0);
      (*DAT_001c10dc)();
    }
  }
  return;
}


