// ShowNodeConnections__6CGraphi  @ 000c5bbc
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
    (*DAT_0019f794)(2,"Graph not ready!\n");
  }
  else if (param_2 < 0) {
    (*DAT_0019f794)(2,"Can\'t show connections for node %d\n",param_2);
  }
  else {
    iVar1 = param_1[3] + param_2 * 0x58;
    UTIL_ParticleEffect__FRC6VectorT0UlUl(iVar1,&g_vecZero,0xff,0x14);
    iVar6 = *(int *)(iVar1 + 0x20);
    if (iVar6 < 1) {
      (*DAT_0019f794)(2,"**No Connections!\n");
      iVar6 = *(int *)(iVar1 + 0x20);
    }
    iVar7 = 0;
    if (0 < iVar6) {
      do {
        iVar6 = param_2 * 0x58;
        puVar2 = (undefined4 *)
                 (param_1[3] +
                 *(int *)(param_1[4] + 4 + (iVar7 + *(int *)(iVar6 + 0x24 + param_1[3])) * 0x18) *
                 0x58);
        uVar3 = *puVar2;
        uVar4 = puVar2[1];
        fVar5 = (float)puVar2[2];
        (*DAT_0019f758)(0,0x17,0,0);
        (*DAT_0019f760)(0x66);
        (*DAT_0019f774)(*(undefined4 *)(param_1[3] + iVar6));
        (*DAT_0019f774)(*(undefined4 *)(param_1[3] + 4 + iVar6));
        (*DAT_0019f774)(*(float *)(param_1[3] + 8 + iVar6) + 8.0);
        (*DAT_0019f774)(uVar3);
        (*DAT_0019f774)(uVar4);
        (*DAT_0019f774)(fVar5 + 8.0);
        (*DAT_0019f75c)();
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(iVar1 + 0x20));
    }
  }
  return;
}


