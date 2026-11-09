// CM_CalcPAS  @ 00108500
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
  byte *pbVar10;
  int iVar11;
  int iVar12;
  byte *pbVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  byte *pbVar18;
  byte *pbVar19;
  uint uVar20;
  int local_54;
  int local_48;
  byte *local_44;
  int local_40;
  byte *local_3c;
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
                       Unresolved local var: byte * scan@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int vcount@[???] */
  Con_DPrintf("Building PAS...\n");
  if (gPAS != (byte *)0x0) {
    Mem_Free(gPAS);
  }
  if (gPVS != (byte *)0x0) {
    Mem_Free(gPVS);
  }
  gPAS = (byte *)0x0;
  gPVS = (byte *)0x0;
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
                       Unresolved local var: byte * out@[???] */
    local_3c = (byte *)0x0;
    local_24 = 0;
    local_40 = 0;
    local_44 = gPVS;
    do {
      pbVar18 = *(byte **)(pModel->leafs->ambient_sound_level + (int)local_3c + -0x14);
      if (pbVar18 == (byte *)0x0) {
        Q_memcpy(local_44,mod_novis,iVar9);
      }
      else {
        pbVar19 = local_44;
        do {
          while (*pbVar18 != '\0') {
            *pbVar19 = *pbVar18;
            pbVar18 = pbVar18 + 1;
            pbVar19 = pbVar19 + 1;
LAB_001085e4:
            if (local_44 + iVar9 <= pbVar19) goto LAB_00108698;
          }
          uVar16 = (uint)pbVar18[1];
          pbVar18 = pbVar18 + 2;
          if (uVar16 == 0) goto LAB_001085e4;
          uVar20 = -(int)pbVar19 & 0xfU;
          if (uVar16 < (-(int)pbVar19 & 0xfU)) {
            uVar20 = uVar16;
          }
          pbVar10 = pbVar19;
          uVar17 = uVar16;
          if (uVar20 == 0) {
LAB_00108630:
            uVar14 = uVar16 - uVar20 >> 4;
            if (uVar14 != 0) {
              pbVar13 = pbVar19 + uVar20;
              uVar15 = 0;
              do {
                uVar15 = uVar15 + 1;
                pbVar13[0] = '\0';
                pbVar13[1] = '\0';
                pbVar13[2] = '\0';
                pbVar13[3] = '\0';
                pbVar13[4] = '\0';
                pbVar13[5] = '\0';
                pbVar13[6] = '\0';
                pbVar13[7] = '\0';
                pbVar13[8] = '\0';
                pbVar13[9] = '\0';
                pbVar13[10] = '\0';
                pbVar13[0xb] = '\0';
                pbVar13[0xc] = '\0';
                pbVar13[0xd] = '\0';
                pbVar13[0xe] = '\0';
                pbVar13[0xf] = '\0';
                pbVar13 = pbVar13 + 0x10;
              } while (uVar15 < uVar14);
              pbVar10 = pbVar10 + uVar14 * 0x10;
              uVar17 = uVar17 + uVar14 * -0x10;
              if (uVar16 - uVar20 == uVar14 * 0x10) goto LAB_00108688;
            }
            pbVar13 = pbVar10 + uVar17;
            do {
              *pbVar10 = '\0';
              pbVar10 = pbVar10 + 1;
            } while (pbVar10 != pbVar13);
          }
          else {
            uVar14 = 0;
            do {
              uVar14 = uVar14 + 1;
              uVar17 = uVar17 - 1;
              *pbVar10 = '\0';
              pbVar10 = pbVar10 + 1;
            } while (uVar14 < uVar20);
            if (uVar16 != uVar20) goto LAB_00108630;
          }
LAB_00108688:
          pbVar19 = pbVar19 + uVar16;
        } while (pbVar19 < local_44 + iVar9);
      }
LAB_00108698:
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
      local_3c = (byte *)((int)local_3c + 0x3c);
    } while (local_40 < (int)size);
    pbVar18 = Mem_Calloc(gPVSRowBytes,size);
    uVar16 = (int)(iVar9 + 3U) >> 2;
    uVar20 = uVar16 >> 2;
    local_28 = 0;
    local_2c = 0;
    local_3c = gPVS;
    iVar9 = gPVSRowBytes;
    gPAS = pbVar18;
    do {
      Q_memcpy(pbVar18,local_3c,iVar9);
      iVar9 = gPVSRowBytes;
      pbVar19 = gPVS;
      if (0 < gPVSRowBytes) {
        local_48 = 0;
        do {
          bVar4 = local_3c[local_48];
          if (bVar4 != 0) {
            iVar11 = 0;
            local_54 = local_48 * 8 + 1;
            pbVar10 = pbVar19 + iVar9 * local_54;
            do {
              if ((((((int)(uint)bVar4 >> ((byte)iVar11 & 0x1f) & 1U) != 0) && (0 < local_54)) &&
                  (local_54 < (int)size)) && (0 < (int)uVar16)) {
                if ((uVar20 == 0) ||
                   (pbVar10 <= pbVar18 + 0x10 && pbVar18 <= pbVar10 + 0x10 || uVar16 < 7)) {
                  uVar17 = 0;
                }
                else {
                  iVar12 = 0;
                  uVar17 = 0;
                  do {
                    uVar17 = uVar17 + 1;
                    puVar1 = (uint *)(pbVar10 + iVar12);
                    uVar14 = puVar1[1];
                    uVar15 = puVar1[2];
                    uVar5 = puVar1[3];
                    puVar2 = (uint *)(pbVar18 + iVar12);
                    uVar6 = puVar2[1];
                    uVar7 = puVar2[2];
                    uVar8 = puVar2[3];
                    puVar3 = (uint *)(pbVar18 + iVar12);
                    *puVar3 = *puVar2 | *puVar1;
                    puVar3[1] = uVar6 | uVar14;
                    puVar3[2] = uVar7 | uVar15;
                    puVar3[3] = uVar8 | uVar5;
                    iVar12 = iVar12 + 0x10;
                  } while (uVar17 < uVar20);
                  uVar17 = uVar20 * 4;
                  if (uVar20 * 4 == uVar16) goto LAB_0010886b;
                }
                do {
                  *(uint *)(pbVar18 + uVar17 * 4) =
                       *(uint *)(pbVar18 + uVar17 * 4) | *(uint *)(pbVar10 + uVar17 * 4);
                  uVar17 = uVar17 + 1;
                } while ((int)uVar17 < (int)uVar16);
              }
LAB_0010886b:
              iVar11 = iVar11 + 1;
              local_54 = local_54 + 1;
              pbVar10 = pbVar10 + iVar9;
            } while (iVar11 != 8);
          }
          local_48 = local_48 + 1;
        } while (local_48 != iVar9);
      }
      if (local_2c != 0) {
        iVar11 = 0;
        do {
          if (((int)(uint)pbVar18[iVar11 >> 3] >> ((byte)iVar11 & 7) & 1U) != 0) {
            local_28 = local_28 + 1;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < (int)size);
      }
      local_2c = local_2c + 1;
      pbVar18 = pbVar18 + uVar16 * 4;
      local_3c = local_3c + iVar9;
    } while (local_2c < (int)size);
  }
  Con_DPrintf("Average leaves visible / audible / total: %i / %i / %i\n",local_24 / (int)size,
              local_28 / (int)size,size);
  return;
}


// CM_DecompressPVS  @ 00108370
void CM_DecompressPVS(byte *in,byte *decompressed,int byteCount)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  undefined1 (*pauVar4) [16];
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: byte * out@[???] */
  if (in == (byte *)0x0) {
    Q_memcpy(decompressed,mod_novis,byteCount);
    return;
  }
  pbVar1 = decompressed + byteCount;
  do {
    if (*in == '\0') {
      uVar7 = (uint)in[1];
      in = in + 2;
      if (uVar7 != 0) {
        uVar3 = -(int)decompressed & 0xfU;
        if (uVar7 < (-(int)decompressed & 0xfU)) {
          uVar3 = uVar7;
        }
        pbVar2 = decompressed;
        uVar8 = uVar7;
        if (uVar3 == 0) {
LAB_001083ef:
          uVar5 = uVar7 - uVar3 >> 4;
          if (uVar5 != 0) {
            pauVar4 = (undefined1 (*) [16])(decompressed + uVar3);
            uVar6 = 0;
            do {
              uVar6 = uVar6 + 1;
              *pauVar4 = (undefined1  [16])0x0;
              pauVar4 = pauVar4 + 1;
            } while (uVar6 < uVar5);
            pbVar2 = pbVar2 + uVar5 * 0x10;
            uVar8 = uVar8 + uVar5 * -0x10;
            if (uVar7 - uVar3 == uVar5 * 0x10) goto LAB_00108448;
          }
          pbVar9 = pbVar2 + uVar8;
          do {
            *pbVar2 = '\0';
            pbVar2 = pbVar2 + 1;
          } while (pbVar2 != pbVar9);
        }
        else {
          uVar5 = 0;
          do {
            uVar5 = uVar5 + 1;
            uVar8 = uVar8 - 1;
            *pbVar2 = '\0';
            pbVar2 = pbVar2 + 1;
          } while (uVar5 < uVar3);
          if (uVar7 != uVar3) goto LAB_001083ef;
        }
LAB_00108448:
        decompressed = decompressed + uVar7;
      }
    }
    else {
      *decompressed = *in;
      in = in + 1;
      decompressed = decompressed + 1;
    }
    if (pbVar1 <= decompressed) {
      return;
    }
  } while( true );
}


// CM_FreePAS  @ 001084c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CM_FreePAS(void)

{
  if (gPAS != (byte *)0x0) {
    Mem_Free(gPAS);
  }
  if (gPVS != (byte *)0x0) {
    Mem_Free(gPVS);
  }
  gPAS = (byte *)0x0;
  gPVS = (byte *)0x0;
  return;
}


// CM_HeadnodeVisible  @ 00108990
qboolean CM_HeadnodeVisible(mnode_t *node,byte *visbits,int *first_visible_leafnum)

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
        iVar10 = ((int)node - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
        if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) == 0) {
          return false;
        }
LAB_00108bfb:
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
        if ((pmVar1 == (mnode_s *)0x0) || (pmVar1->contents == -2)) goto LAB_00108b9b;
        if (pmVar1->contents < 0) break;
        pmVar2 = pmVar1->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
        while( true ) {
          if ((pmVar2 == (mnode_s *)0x0) || (pmVar2->contents == -2)) goto LAB_00108b88;
          if (pmVar2->contents < 0) break;
          pmVar3 = pmVar2->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
          while( true ) {
            if ((pmVar3 == (mnode_s *)0x0) || (pmVar3->contents == -2)) goto LAB_00108b75;
            if (pmVar3->contents < 0) break;
            pmVar4 = pmVar3->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
            while( true ) {
              if ((pmVar4 == (mnode_s *)0x0) || (pmVar4->contents == -2)) goto LAB_00108b62;
              if (pmVar4->contents < 0) break;
              pmVar5 = pmVar4->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
              while( true ) {
                if ((pmVar5 == (mnode_s *)0x0) || (pmVar5->contents == -2)) goto LAB_00108b4f;
                if (pmVar5->contents < 0) break;
                pmVar6 = pmVar5->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
joined_r0x00108a8b:
                if ((pmVar6 == (mnode_s *)0x0) || (pmVar6->contents == -2)) goto LAB_00108b3c;
                if (-1 < pmVar6->contents) {
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
                  for (pmVar7 = pmVar6->children[0];
                      (pmVar7 != (mnode_s *)0x0 && (pmVar7->contents != -2));
                      pmVar7 = pmVar7->children[1]) {
                    if (pmVar7->contents < 0) {
                      iVar10 = ((int)pmVar7 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
                      if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0)
                      goto LAB_00108c47;
                      pmVar6 = pmVar6->children[1];
                      goto joined_r0x00108a8b;
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
                        goto LAB_00108b26;
                      }
                      iVar10 = ((int)pmVar8 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
                      if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0)
                      goto LAB_00108c47;
                    }
LAB_00108b26:
                  }
                  pmVar6 = pmVar6->children[1];
                  goto joined_r0x00108a8b;
                }
                iVar10 = ((int)pmVar6 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
                if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) {
                  if (first_visible_leafnum == (int *)0x0) {
                    return true;
                  }
                  *first_visible_leafnum = iVar10;
                  return true;
                }
LAB_00108b3c:
                pmVar5 = pmVar5->children[1];
              }
              iVar10 = ((int)pmVar5 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
              if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) {
LAB_00108c47:
                if (first_visible_leafnum == (int *)0x0) {
                  return true;
                }
                *first_visible_leafnum = iVar10;
                return true;
              }
LAB_00108b4f:
              pmVar4 = pmVar4->children[1];
            }
            iVar10 = ((int)pmVar4 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
            if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0)
            goto LAB_00108dc0;
LAB_00108b62:
            pmVar3 = pmVar3->children[1];
          }
          iVar10 = ((int)pmVar3 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
          if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) {
LAB_00108dc0:
            if (first_visible_leafnum != (int *)0x0) {
              *first_visible_leafnum = iVar10;
            }
            return true;
          }
LAB_00108b75:
          pmVar2 = pmVar2->children[1];
        }
        iVar10 = ((int)pmVar2 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
        if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) goto LAB_00108bfb;
LAB_00108b88:
        pmVar1 = pmVar1->children[1];
      }
      iVar10 = ((int)pmVar1 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
      if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) goto LAB_00108bfb;
LAB_00108b9b:
      node = node->children[1];
      if (node == (mnode_s *)0x0) {
        return false;
      }
      iVar10 = node->contents;
    }
  }
  return false;
}


// CM_LeafPAS  @ 001084a0
byte * CM_LeafPAS(int leafnum)

{
  byte *pbVar1;
  
  pbVar1 = mod_novis;
  if (gPAS != (byte *)0x0) {
    pbVar1 = gPAS + leafnum * gPVSRowBytes;
  }
  return pbVar1;
}


// CM_LeafPVS  @ 00108480
byte * CM_LeafPVS(int leafnum)

{
  byte *pbVar1;
  
  pbVar1 = mod_novis;
  if (gPVS != (byte *)0x0) {
    pbVar1 = gPVS + leafnum * gPVSRowBytes;
  }
  return pbVar1;
}


