// CM_CalcPAS  @ 0005e240
void CM_CalcPAS(model_t *pModel)

{
  size_t size;
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uchar *puVar10;
  int iVar11;
  int iVar12;
  uchar *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uchar *puVar18;
  uchar *puVar19;
  uint uVar20;
  int local_54;
  int local_48;
  uchar *local_44;
  int local_40;
  uchar *local_3c;
  int local_2c;
  int local_28;
  int local_24;
  
                    /* Unresolved local var: int rowwords@[???]
                       Unresolved local var: int actualRowBytes@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: int l@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: int bitbyte@[???]
                       Unresolved local var: uint * dest@[???]
                       Unresolved local var: uint * src@[???]
                       Unresolved local var: uchar * scan@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int vcount@[???] */
  Con_DPrintf("Building PAS...\n");
  if (gPAS != (uchar *)0x0) {
    Mem_Free(gPAS);
  }
  if (gPVS != (uchar *)0x0) {
    Mem_Free(gPVS);
  }
  gPAS = (uchar *)0x0;
  gPVS = (uchar *)0x0;
  size = pModel->numleafs + 1;
  iVar9 = pModel->numleafs + 7 >> 3;
  gPVSRowBytes = iVar9 + 3U & 0xfffffffc;
  gPVS = Mem_Calloc(gPVSRowBytes,size);
  if ((int)size < 1) {
    gPAS = Mem_Calloc(gPVSRowBytes,size);
    local_24 = 0;
    local_28 = 0;
  }
  else {
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: uchar * out@[???] */
    local_3c = (uchar *)0x0;
    local_24 = 0;
    local_40 = 0;
    local_44 = gPVS;
    do {
      puVar18 = *(uchar **)((int)pModel->leafs->minmaxs + (int)local_3c + 0x10);
      if (puVar18 == (uchar *)0x0) {
        Q_memcpy(local_44,mod_novis,iVar9);
      }
      else {
        puVar19 = local_44;
        do {
          while (*puVar18 != '\0') {
            *puVar19 = *puVar18;
            puVar18 = puVar18 + 1;
            puVar19 = puVar19 + 1;
LAB_0005e324:
            if (local_44 + iVar9 <= puVar19) goto LAB_0005e3d8;
          }
          uVar16 = (uint)puVar18[1];
          puVar18 = puVar18 + 2;
          if (uVar16 == 0) goto LAB_0005e324;
          uVar20 = -(int)puVar19 & 0xfU;
          if (uVar16 < (-(int)puVar19 & 0xfU)) {
            uVar20 = uVar16;
          }
          puVar10 = puVar19;
          uVar17 = uVar16;
          if (uVar20 == 0) {
LAB_0005e370:
            uVar14 = uVar16 - uVar20 >> 4;
            if (uVar14 != 0) {
              puVar13 = puVar19 + uVar20;
              uVar15 = 0;
              do {
                uVar15 = uVar15 + 1;
                puVar13[0] = '\0';
                puVar13[1] = '\0';
                puVar13[2] = '\0';
                puVar13[3] = '\0';
                puVar13[4] = '\0';
                puVar13[5] = '\0';
                puVar13[6] = '\0';
                puVar13[7] = '\0';
                puVar13[8] = '\0';
                puVar13[9] = '\0';
                puVar13[10] = '\0';
                puVar13[0xb] = '\0';
                puVar13[0xc] = '\0';
                puVar13[0xd] = '\0';
                puVar13[0xe] = '\0';
                puVar13[0xf] = '\0';
                puVar13 = puVar13 + 0x10;
              } while (uVar15 < uVar14);
              puVar10 = puVar10 + uVar14 * 0x10;
              uVar17 = uVar17 + uVar14 * -0x10;
              if (uVar16 - uVar20 == uVar14 * 0x10) goto LAB_0005e3c8;
            }
            puVar13 = puVar10 + uVar17;
            do {
              *puVar10 = '\0';
              puVar10 = puVar10 + 1;
            } while (puVar10 != puVar13);
          }
          else {
            uVar14 = 0;
            do {
              uVar14 = uVar14 + 1;
              uVar17 = uVar17 - 1;
              *puVar10 = '\0';
              puVar10 = puVar10 + 1;
            } while (uVar14 < uVar20);
            if (uVar16 != uVar20) goto LAB_0005e370;
          }
LAB_0005e3c8:
          puVar19 = puVar19 + uVar16;
        } while (puVar19 < local_44 + iVar9);
      }
LAB_0005e3d8:
      if (local_40 != 0) {
        iVar11 = 0;
        do {
          if (((int)(uint)local_44[iVar11 >> 3] >> ((byte)iVar11 & 7) & 1U) != 0) {
            local_24 = local_24 + 1;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < (int)size);
      }
      local_40 = local_40 + 1;
      local_44 = local_44 + gPVSRowBytes;
      local_3c = (uchar *)((int)local_3c + 0x30);
    } while (local_40 < (int)size);
    puVar18 = Mem_Calloc(gPVSRowBytes,size);
    uVar16 = (int)(iVar9 + 3U) >> 2;
    uVar20 = uVar16 >> 2;
    local_28 = 0;
    local_2c = 0;
    local_3c = gPVS;
    iVar9 = gPVSRowBytes;
    gPAS = puVar18;
    do {
      Q_memcpy(puVar18,local_3c,iVar9);
      iVar9 = gPVSRowBytes;
      puVar19 = gPVS;
      if (0 < gPVSRowBytes) {
        local_48 = 0;
        do {
          bVar4 = local_3c[local_48];
          if (bVar4 != 0) {
            iVar11 = 0;
            local_54 = local_48 * 8 + 1;
            puVar10 = puVar19 + iVar9 * local_54;
            do {
              if ((((((int)(uint)bVar4 >> ((byte)iVar11 & 0x1f) & 1U) != 0) && (0 < local_54)) &&
                  (local_54 < (int)size)) && (0 < (int)uVar16)) {
                if ((uVar20 == 0) ||
                   (puVar10 <= puVar18 + 0x10 && puVar18 <= puVar10 + 0x10 || uVar16 < 7)) {
                  uVar17 = 0;
                }
                else {
                  iVar12 = 0;
                  uVar17 = 0;
                  do {
                    uVar17 = uVar17 + 1;
                    puVar1 = (uint *)(puVar10 + iVar12);
                    uVar14 = puVar1[1];
                    uVar15 = puVar1[2];
                    uVar5 = puVar1[3];
                    puVar2 = (uint *)(puVar18 + iVar12);
                    uVar6 = puVar2[1];
                    uVar7 = puVar2[2];
                    uVar8 = puVar2[3];
                    puVar3 = (uint *)(puVar18 + iVar12);
                    *puVar3 = *puVar2 | *puVar1;
                    puVar3[1] = uVar6 | uVar14;
                    puVar3[2] = uVar7 | uVar15;
                    puVar3[3] = uVar8 | uVar5;
                    iVar12 = iVar12 + 0x10;
                  } while (uVar17 < uVar20);
                  uVar17 = uVar20 * 4;
                  if (uVar20 * 4 == uVar16) goto LAB_0005e5ab;
                }
                do {
                  *(uint *)(puVar18 + uVar17 * 4) =
                       *(uint *)(puVar18 + uVar17 * 4) | *(uint *)(puVar10 + uVar17 * 4);
                  uVar17 = uVar17 + 1;
                } while ((int)uVar17 < (int)uVar16);
              }
LAB_0005e5ab:
              iVar11 = iVar11 + 1;
              local_54 = local_54 + 1;
              puVar10 = puVar10 + iVar9;
            } while (iVar11 != 8);
          }
          local_48 = local_48 + 1;
        } while (local_48 != iVar9);
      }
      if (local_2c != 0) {
        iVar11 = 0;
        do {
          if (((int)(uint)puVar18[iVar11 >> 3] >> ((byte)iVar11 & 7) & 1U) != 0) {
            local_28 = local_28 + 1;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < (int)size);
      }
      local_2c = local_2c + 1;
      puVar18 = puVar18 + uVar16 * 4;
      local_3c = local_3c + iVar9;
    } while (local_2c < (int)size);
  }
  Con_DPrintf("Average leaves visible / audible / total: %i / %i / %i\n",local_24 / (int)size,
              local_28 / (int)size,size);
  return;
}


// CM_DecompressPVS  @ 0005e0b0
void CM_DecompressPVS(uchar *in,uchar *decompressed,int byteCount)

{
  uchar *puVar1;
  uchar *puVar2;
  uint uVar3;
  undefined1 (*pauVar4) [16];
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uchar *puVar9;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: uchar * out@[???] */
  if (in == (uchar *)0x0) {
    Q_memcpy(decompressed,mod_novis,byteCount);
    return;
  }
  puVar1 = decompressed + byteCount;
  do {
    if (*in == '\0') {
      uVar7 = (uint)in[1];
      in = in + 2;
      if (uVar7 != 0) {
        uVar3 = -(int)decompressed & 0xfU;
        if (uVar7 < (-(int)decompressed & 0xfU)) {
          uVar3 = uVar7;
        }
        puVar2 = decompressed;
        uVar8 = uVar7;
        if (uVar3 == 0) {
LAB_0005e12f:
          uVar5 = uVar7 - uVar3 >> 4;
          if (uVar5 != 0) {
            pauVar4 = (undefined1 (*) [16])(decompressed + uVar3);
            uVar6 = 0;
            do {
              uVar6 = uVar6 + 1;
              *pauVar4 = (undefined1  [16])0x0;
              pauVar4 = pauVar4 + 1;
            } while (uVar6 < uVar5);
            puVar2 = puVar2 + uVar5 * 0x10;
            uVar8 = uVar8 + uVar5 * -0x10;
            if (uVar7 - uVar3 == uVar5 * 0x10) goto LAB_0005e188;
          }
          puVar9 = puVar2 + uVar8;
          do {
            *puVar2 = '\0';
            puVar2 = puVar2 + 1;
          } while (puVar2 != puVar9);
        }
        else {
          uVar5 = 0;
          do {
            uVar5 = uVar5 + 1;
            uVar8 = uVar8 - 1;
            *puVar2 = '\0';
            puVar2 = puVar2 + 1;
          } while (uVar5 < uVar3);
          if (uVar7 != uVar3) goto LAB_0005e12f;
        }
LAB_0005e188:
        decompressed = decompressed + uVar7;
      }
    }
    else {
      *decompressed = *in;
      in = in + 1;
      decompressed = decompressed + 1;
    }
    if (puVar1 <= decompressed) {
      return;
    }
  } while( true );
}


// CM_FreePAS  @ 0005e200
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CM_FreePAS(void)

{
  if (gPAS != (uchar *)0x0) {
    Mem_Free(gPAS);
  }
  if (gPVS != (uchar *)0x0) {
    Mem_Free(gPVS);
  }
  gPAS = (uchar *)0x0;
  gPVS = (uchar *)0x0;
  return;
}


// CM_HeadnodeVisible  @ 0005e6d0
qboolean CM_HeadnodeVisible(mnode_t *node,uchar *visbits,int *first_visible_leafnum)

{
  mnode_s *pmVar1;
  mnode_s *pmVar2;
  mnode_s *pmVar3;
  mnode_s *pmVar4;
  mnode_s *pmVar5;
  mnode_s *pmVar6;
  mnode_s *pmVar7;
  mnode_s *pmVar8;
  qboolean qVar9;
  int iVar10;
  
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
  if (node != (mnode_t *)0x0) {
    iVar10 = node->contents;
    while (iVar10 != -2) {
      if (iVar10 < 0) {
        iVar10 = ((int)node - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
        if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) == 0) {
          return false;
        }
LAB_0005e93b:
        if (first_visible_leafnum != (int *)0x0) {
          *first_visible_leafnum = iVar10;
          return true;
        }
        return true;
      }
      pmVar1 = node->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
      while( true ) {
        if ((pmVar1 == (mnode_s *)0x0) || (pmVar1->contents == -2)) goto LAB_0005e8db;
        if (pmVar1->contents < 0) break;
        pmVar2 = pmVar1->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
        while( true ) {
          if ((pmVar2 == (mnode_s *)0x0) || (pmVar2->contents == -2)) goto LAB_0005e8c8;
          if (pmVar2->contents < 0) break;
          pmVar3 = pmVar2->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
          while( true ) {
            if ((pmVar3 == (mnode_s *)0x0) || (pmVar3->contents == -2)) goto LAB_0005e8b5;
            if (pmVar3->contents < 0) break;
            pmVar4 = pmVar3->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
            while( true ) {
              if ((pmVar4 == (mnode_s *)0x0) || (pmVar4->contents == -2)) goto LAB_0005e8a2;
              if (pmVar4->contents < 0) break;
              pmVar5 = pmVar4->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
              while( true ) {
                if ((pmVar5 == (mnode_s *)0x0) || (pmVar5->contents == -2)) goto LAB_0005e88f;
                if (pmVar5->contents < 0) break;
                pmVar6 = pmVar5->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
joined_r0x0005e7cb:
                if ((pmVar6 == (mnode_s *)0x0) || (pmVar6->contents == -2)) goto LAB_0005e87c;
                if (-1 < pmVar6->contents) {
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
                  for (pmVar7 = pmVar6->children[0];
                      (pmVar7 != (mnode_s *)0x0 && (pmVar7->contents != -2));
                      pmVar7 = pmVar7->children[1]) {
                    if (pmVar7->contents < 0) {
                      iVar10 = ((int)pmVar7 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
                      if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0)
                      goto LAB_0005e987;
                      pmVar6 = pmVar6->children[1];
                      goto joined_r0x0005e7cb;
                    }
                    pmVar8 = pmVar7->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
                    if ((pmVar8 != (mnode_s *)0x0) && (iVar10 = pmVar8->contents, iVar10 != -2)) {
                      while (-1 < iVar10) {
                        qVar9 = CM_HeadnodeVisible(pmVar8->children[0],visbits,first_visible_leafnum
                                                  );
                        if (qVar9 != false) {
                          return true;
                        }
                        pmVar8 = pmVar8->children[1];
                        if ((pmVar8 == (mnode_s *)0x0) || (iVar10 = pmVar8->contents, iVar10 == -2))
                        goto LAB_0005e866;
                      }
                      iVar10 = ((int)pmVar8 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
                      if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0)
                      goto LAB_0005e987;
                    }
LAB_0005e866:
                  }
                  pmVar6 = pmVar6->children[1];
                  goto joined_r0x0005e7cb;
                }
                iVar10 = ((int)pmVar6 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
                if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) {
                  if (first_visible_leafnum == (int *)0x0) {
                    return true;
                  }
                  *first_visible_leafnum = iVar10;
                  return true;
                }
LAB_0005e87c:
                pmVar5 = pmVar5->children[1];
              }
              iVar10 = ((int)pmVar5 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
              if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) {
LAB_0005e987:
                if (first_visible_leafnum == (int *)0x0) {
                  return true;
                }
                *first_visible_leafnum = iVar10;
                return true;
              }
LAB_0005e88f:
              pmVar4 = pmVar4->children[1];
            }
            iVar10 = ((int)pmVar4 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
            if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0)
            goto LAB_0005eb00;
LAB_0005e8a2:
            pmVar3 = pmVar3->children[1];
          }
          iVar10 = ((int)pmVar3 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
          if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) {
LAB_0005eb00:
            if (first_visible_leafnum != (int *)0x0) {
              *first_visible_leafnum = iVar10;
            }
            return true;
          }
LAB_0005e8b5:
          pmVar2 = pmVar2->children[1];
        }
        iVar10 = ((int)pmVar2 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
        if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) goto LAB_0005e93b;
LAB_0005e8c8:
        pmVar1 = pmVar1->children[1];
      }
      iVar10 = ((int)pmVar1 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
      if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) goto LAB_0005e93b;
LAB_0005e8db:
      node = node->children[1];
      if (node == (mnode_s *)0x0) {
        return false;
      }
      iVar10 = node->contents;
    }
  }
  return false;
}


// CM_LeafPAS  @ 0005e1e0
uchar * CM_LeafPAS(int leafnum)

{
  uchar *puVar1;
  
  puVar1 = mod_novis;
  if (gPAS != (uchar *)0x0) {
    puVar1 = gPAS + leafnum * gPVSRowBytes;
  }
  return puVar1;
}


// CM_LeafPVS  @ 0005e1c0
uchar * CM_LeafPVS(int leafnum)

{
  uchar *puVar1;
  
  puVar1 = mod_novis;
  if (gPVS != (uchar *)0x0) {
    puVar1 = gPVS + leafnum * gPVSRowBytes;
  }
  return puVar1;
}


