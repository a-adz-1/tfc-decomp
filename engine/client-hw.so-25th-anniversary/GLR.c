// GLR_StudioDrawShadow  @ 000e0de0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GLR_StudioDrawShadow(void)

{
  auxvert_t *paVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  mstudiomodel_t *pmVar5;
  char *pcVar6;
  int iVar7;
  char *local_34;
  int local_30;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: vec3_t point@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: auxvert_t * av@[???]
                       Unresolved local var: mstudiomesh_t * pmesh@[???] */
  local_30 = 0;
  iVar4 = psubmodel->nummesh;
  if (0 < iVar4) {
    pmVar5 = psubmodel;
    do {
                    /* Unresolved local var: short * ptricmds@[???] */
      fVar2 = lightspot[2] + 1.0;
      c_alias_polys =
           c_alias_polys + *(int *)(pstudiohdr->name + pmVar5->meshindex + local_30 * 0x14 + -8);
      local_34 = pstudiohdr->name +
                 *(int *)(pstudiohdr->name + pmVar5->meshindex + local_30 * 0x14 + -8 + 4) + -8;
      iVar7 = (int)*(short *)local_34;
      if (iVar7 != 0) {
        do {
          local_34 = local_34 + 2;
          pcVar6 = local_34;
          if (iVar7 < 0) {
            iVar7 = -iVar7;
            (*qglBegin)(6);
            iVar4 = iVar7;
LAB_000e0e80:
            do {
              paVar1 = pauxverts + *(short *)pcVar6;
              fVar3 = paVar1->fv[2] - lightspot[2];
              local_28 = paVar1->fv[0] - shadevector[0] * fVar3;
              local_24 = paVar1->fv[1] - fVar3 * shadevector[1];
              local_20 = fVar2;
              (*qglVertex3fv)(&local_28);
              iVar7 = iVar7 + -1;
              pcVar6 = pcVar6 + 8;
            } while (iVar7 != 0);
            local_34 = local_34 + iVar4 * 8;
          }
          else {
            (*qglBegin)(5);
            iVar4 = iVar7;
            if (iVar7 != 0) goto LAB_000e0e80;
          }
          (*qglEnd)();
          iVar7 = (int)*(short *)local_34;
        } while (iVar7 != 0);
        iVar4 = psubmodel->nummesh;
        pmVar5 = psubmodel;
      }
      local_30 = local_30 + 1;
    } while (local_30 < iVar4);
  }
  return;
}


