// GLR_StudioDrawShadow  @ 001445e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GLR_StudioDrawShadow(void)

{
  auxvert_t *paVar1;
  float fVar2;
  float fVar3;
  mstudiomodel_t *pmVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int local_34;
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
  iVar5 = psubmodel->nummesh;
  if (0 < iVar5) {
    local_30 = 0;
    local_34 = 0;
    pmVar4 = psubmodel;
    do {
                    /* Unresolved local var: short * ptricmds@[???] */
      fVar2 = lightspot[2] + 1.0;
      c_alias_polys = c_alias_polys + *(int *)(pstudiohdr->name + pmVar4->meshindex + local_30 + -8)
      ;
      pcVar7 = pstudiohdr->name +
               *(int *)(pstudiohdr->name + pmVar4->meshindex + local_30 + -8 + 4) + -8;
      iVar6 = (int)*(short *)pcVar7;
      if (iVar6 != 0) {
        do {
          pcVar7 = pcVar7 + 2;
          pcVar8 = pcVar7;
          if (iVar6 < 0) {
            iVar6 = -iVar6;
            (*qglBegin)(6);
            iVar5 = iVar6;
LAB_00144670:
            do {
              paVar1 = pauxverts + *(short *)pcVar8;
              fVar3 = paVar1->fv[2] - lightspot[2];
              local_28 = paVar1->fv[0] - shadevector[0] * fVar3;
              local_24 = paVar1->fv[1] - fVar3 * shadevector[1];
              local_20 = fVar2;
              (*qglVertex3fv)(&local_28);
              iVar6 = iVar6 + -1;
              pcVar8 = pcVar8 + 8;
            } while (iVar6 != 0);
            pcVar7 = pcVar7 + iVar5 * 8;
          }
          else {
            (*qglBegin)(5);
            iVar5 = iVar6;
            if (iVar6 != 0) goto LAB_00144670;
          }
          (*qglEnd)();
          iVar6 = (int)*(short *)pcVar7;
        } while (iVar6 != 0);
        iVar5 = psubmodel->nummesh;
        pmVar4 = psubmodel;
      }
      local_34 = local_34 + 1;
      local_30 = local_30 + 0x14;
    } while (local_34 < iVar5);
  }
  return;
}


