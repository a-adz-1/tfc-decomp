// CM_CalcPAS  @ 0009cd50
void CM_CalcPAS(model_t *pModel)

{
  size_t size;
  byte *pbVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  byte *pbVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  byte *pbVar15;
  byte *pbVar16;
  uint *dest;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  byte *pbVar23;
  int iVar24;
  size_t sVar25;
  byte *pbVar26;
  uint uVar27;
  int iVar28;
  uint uVar29;
  size_t local_80;
  int local_78;
  int local_6c;
  byte *local_60;
  size_t local_30;
  int local_2c;
  int local_28;
  
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
  gPVS = (byte *)0x0;
  gPAS = (byte *)0x0;
  size = pModel->numleafs + 1;
  iVar14 = pModel->numleafs + 7 >> 3;
  gPVSRowBytes = iVar14 + 3U & 0xfffffffc;
  uVar29 = (int)(iVar14 + 3U) >> 2;
  pbVar15 = Mem_Calloc(gPVSRowBytes,size);
  gPVS = pbVar15;
  if ((int)size < 1) {
    gPAS = Mem_Calloc(gPVSRowBytes,size);
    local_28 = 0;
    local_2c = 0;
  }
  else {
    local_28 = 0;
    local_80 = 0;
    do {
      pbVar23 = pModel->leafs[local_80].compressed_vis;
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: byte * out@[???] */
      pbVar16 = pbVar15;
      if (pbVar23 == (byte *)0x0) {
        Q_memcpy(pbVar15,mod_novis,iVar14);
      }
      else {
        do {
          while (*pbVar23 != '\0') {
            *pbVar16 = *pbVar23;
            pbVar23 = pbVar23 + 1;
            pbVar16 = pbVar16 + 1;
LAB_0009ce44:
            if (pbVar15 + iVar14 <= pbVar16) goto LAB_0009ce9a;
          }
          pbVar1 = pbVar23 + 1;
          uVar21 = (uint)*pbVar1;
          pbVar23 = pbVar23 + 2;
          if (*pbVar1 == 0) goto LAB_0009ce44;
          pbVar26 = pbVar16;
          uVar17 = uVar21;
          if (7 < uVar21) {
            if (((uint)pbVar16 & 1) != 0) {
              *pbVar16 = '\0';
              pbVar26 = pbVar16 + 1;
              uVar17 = uVar21 - 1;
            }
            if (((uint)pbVar26 & 2) != 0) {
              pbVar26[0] = '\0';
              pbVar26[1] = '\0';
              uVar17 = uVar17 - 2;
              pbVar26 = pbVar26 + 2;
            }
            if (7 < uVar17) {
              uVar27 = 0;
              do {
                pbVar6 = pbVar26 + uVar27;
                pbVar6[0] = '\0';
                pbVar6[1] = '\0';
                pbVar6[2] = '\0';
                pbVar6[3] = '\0';
                pbVar6 = pbVar26 + uVar27 + 4;
                pbVar6[0] = '\0';
                pbVar6[1] = '\0';
                pbVar6[2] = '\0';
                pbVar6[3] = '\0';
                uVar27 = uVar27 + 8;
              } while (uVar27 < (uVar17 & 0xfffffff8));
              pbVar26 = pbVar26 + uVar27;
            }
          }
          if ((uVar17 & 4) != 0) {
            pbVar26[0] = '\0';
            pbVar26[1] = '\0';
            pbVar26[2] = '\0';
            pbVar26[3] = '\0';
            pbVar26 = pbVar26 + 4;
          }
          if ((uVar17 & 2) != 0) {
            pbVar26[0] = '\0';
            pbVar26[1] = '\0';
            pbVar26 = pbVar26 + 2;
          }
          if ((uVar17 & 1) != 0) {
            *pbVar26 = '\0';
          }
          pbVar16 = pbVar16 + uVar21;
        } while (pbVar16 < pbVar15 + iVar14);
      }
LAB_0009ce9a:
      if (local_80 != 0) {
        sVar25 = 0;
        do {
          iVar18 = (int)sVar25 >> 3;
          bVar7 = (byte)sVar25;
          sVar25 = sVar25 + 1;
          local_28 = local_28 + ((int)(uint)pbVar15[iVar18] >> (bVar7 & 7) & 1U);
        } while (sVar25 != size);
      }
      local_80 = local_80 + 1;
      pbVar15 = pbVar15 + gPVSRowBytes;
    } while (local_80 != size);
    dest = Mem_Calloc(gPVSRowBytes,size);
    local_2c = 0;
    local_60 = gPVS;
    local_80 = gPVSRowBytes;
    local_30 = 0;
    gPAS = (byte *)dest;
    do {
      Q_memcpy(dest,local_60,local_80);
      pbVar15 = gPVS;
      iVar14 = gPVSRowBytes;
      local_80 = gPVSRowBytes;
      if (0 < gPVSRowBytes) {
        uVar21 = -(((uint)dest & 0xf) >> 2) & 3;
        if (uVar29 < uVar21) {
          uVar21 = uVar29;
        }
        uVar17 = ((uVar29 - uVar21) - 4 >> 2) + 1;
        iVar18 = uVar17 * 4;
        iVar19 = uVar21 * 4;
        local_78 = 0;
        do {
          bVar7 = local_60[local_78];
          if (bVar7 != 0) {
            iVar28 = local_78 * 8 + 1;
            iVar22 = 0;
            iVar24 = iVar14 * iVar28;
            do {
              if ((((((int)(uint)bVar7 >> ((byte)iVar22 & 0x1f) & 1U) != 0) && (iVar28 < (int)size))
                  && (0 < iVar28)) && (0 < (int)uVar29)) {
                puVar2 = (uint *)(pbVar15 + iVar24);
                if ((dest < pbVar15 + iVar24 + 0x10 && puVar2 < dest + 4) || (uVar29 < 9)) {
                  uVar27 = 0;
                  do {
                    dest[uVar27] = dest[uVar27] | puVar2[uVar27];
                    uVar27 = uVar27 + 1;
                  } while (uVar29 != uVar27);
                }
                else {
                  if (uVar21 == 0) {
                    local_6c = 0;
                  }
                  else {
                    *dest = *dest | *puVar2;
                    if (uVar21 == 1) {
                      local_6c = 1;
                    }
                    else {
                      dest[1] = dest[1] | *(uint *)(pbVar15 + iVar24 + 4);
                      if (uVar21 == 3) {
                        dest[2] = dest[2] | *(uint *)(pbVar15 + iVar24 + 8);
                        local_6c = 3;
                      }
                      else {
                        local_6c = 2;
                      }
                    }
                  }
                  if (2 < (uVar29 - 1) - uVar21) {
                    uVar27 = 0;
                    iVar20 = 0;
                    do {
                      uVar27 = uVar27 + 1;
                      puVar3 = (uint *)(pbVar15 + iVar20 + iVar19 + iVar24);
                      uVar8 = puVar3[1];
                      uVar9 = puVar3[2];
                      uVar10 = puVar3[3];
                      puVar4 = (uint *)((int)dest + iVar20 + iVar19);
                      uVar11 = puVar4[1];
                      uVar12 = puVar4[2];
                      uVar13 = puVar4[3];
                      puVar5 = (uint *)((int)dest + iVar20 + iVar19);
                      *puVar5 = *puVar3 | *puVar4;
                      puVar5[1] = uVar8 | uVar11;
                      puVar5[2] = uVar9 | uVar12;
                      puVar5[3] = uVar10 | uVar13;
                      iVar20 = iVar20 + 0x10;
                    } while (uVar27 < uVar17);
                    local_6c = local_6c + iVar18;
                    if (iVar18 == uVar29 - uVar21) goto LAB_0009d120;
                  }
                  dest[local_6c] = dest[local_6c] | *(uint *)(pbVar15 + iVar24 + local_6c * 4);
                  if ((local_6c + 1 < (int)uVar29) &&
                     (dest[local_6c + 1] =
                           dest[local_6c + 1] | *(uint *)(pbVar15 + iVar24 + local_6c * 4 + 4),
                     local_6c + 2 < (int)uVar29)) {
                    dest[local_6c + 2] = dest[local_6c + 2] | puVar2[local_6c + 2];
                  }
                }
              }
LAB_0009d120:
              iVar22 = iVar22 + 1;
              iVar28 = iVar28 + 1;
              iVar24 = iVar24 + iVar14;
            } while (iVar22 != 8);
          }
          local_78 = local_78 + 1;
        } while (local_78 != iVar14);
      }
      if (local_30 != 0) {
        sVar25 = 0;
        do {
          iVar18 = (int)sVar25 >> 3;
          bVar7 = (byte)sVar25;
          sVar25 = sVar25 + 1;
          local_2c = local_2c + ((int)(uint)*(byte *)((int)dest + iVar18) >> (bVar7 & 7) & 1U);
        } while (sVar25 != size);
      }
      local_30 = local_30 + 1;
      local_60 = local_60 + iVar14;
      dest = dest + uVar29;
    } while (local_30 != size);
  }
  Con_DPrintf("Average leaves visible / audible / total: %i / %i / %i\n",local_28 / (int)size,
              local_2c / (int)size,size);
  return;
}


// CM_DecompressPVS  @ 0009cbc0
void CM_DecompressPVS(byte *in,byte *decompressed,int byteCount)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: byte * out@[???] */
  pbVar2 = decompressed + byteCount;
  if (in != (byte *)0x0) {
    do {
      if (*in == '\0') {
        pbVar1 = in + 1;
        uVar4 = (uint)*pbVar1;
        in = in + 2;
        if (*pbVar1 != 0) {
          pbVar5 = decompressed;
          uVar6 = uVar4;
          if (7 < uVar4) {
            if (((uint)decompressed & 1) != 0) {
              *decompressed = '\0';
              pbVar5 = decompressed + 1;
              uVar6 = uVar4 - 1;
            }
            if (((uint)pbVar5 & 2) != 0) {
              pbVar5[0] = '\0';
              pbVar5[1] = '\0';
              uVar6 = uVar6 - 2;
              pbVar5 = pbVar5 + 2;
            }
            if (7 < uVar6) {
              uVar7 = 0;
              do {
                pbVar3 = pbVar5 + uVar7;
                pbVar3[0] = '\0';
                pbVar3[1] = '\0';
                pbVar3[2] = '\0';
                pbVar3[3] = '\0';
                pbVar3 = pbVar5 + uVar7 + 4;
                pbVar3[0] = '\0';
                pbVar3[1] = '\0';
                pbVar3[2] = '\0';
                pbVar3[3] = '\0';
                uVar7 = uVar7 + 8;
              } while (uVar7 < (uVar6 & 0xfffffff8));
              pbVar5 = pbVar5 + uVar7;
            }
          }
          if ((uVar6 & 4) != 0) {
            pbVar5[0] = '\0';
            pbVar5[1] = '\0';
            pbVar5[2] = '\0';
            pbVar5[3] = '\0';
            pbVar5 = pbVar5 + 4;
          }
          if ((uVar6 & 2) != 0) {
            pbVar5[0] = '\0';
            pbVar5[1] = '\0';
            pbVar5 = pbVar5 + 2;
          }
          if ((uVar6 & 1) != 0) {
            *pbVar5 = '\0';
          }
          decompressed = decompressed + uVar4;
        }
      }
      else {
        *decompressed = *in;
        in = in + 1;
        decompressed = decompressed + 1;
      }
    } while (decompressed < pbVar2);
    return;
  }
  Q_memcpy(decompressed,mod_novis,byteCount);
  return;
}


// CM_FreePAS  @ 0009cd10
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


// CM_HeadnodeVisible  @ 0009d330
/* WARNING: Type propagation algorithm not settling */

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
        if (first_visible_leafnum == (int *)0x0) {
          return true;
        }
        *first_visible_leafnum = iVar10;
        return true;
      }
      pmVar1 = node->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
      while( true ) {
        if ((pmVar1 == (mnode_s *)0x0) || (pmVar1->contents == -2)) goto LAB_0009d52a;
        if (pmVar1->contents < 0) break;
        pmVar2 = pmVar1->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
        while( true ) {
          if ((pmVar2 == (mnode_s *)0x0) || (pmVar2->contents == -2)) goto LAB_0009d517;
          if (pmVar2->contents < 0) break;
          pmVar3 = pmVar2->children[0];
                    /* Unresolved local var: int leafnum@[DW_OP_reg0(EAX)]
                       Unresolved local var: mleaf_t * leaf@[???] */
          while( true ) {
            if ((pmVar3 == (mnode_s *)0x0) || (pmVar3->contents == -2)) goto LAB_0009d504;
            if (pmVar3->contents < 0) break;
            pmVar4 = pmVar3->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
joined_r0x0009d3eb:
            if ((pmVar4 != (mnode_s *)0x0) && (pmVar4->contents != -2)) {
              if (-1 < pmVar4->contents) {
                pmVar5 = pmVar4->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
joined_r0x0009d411:
                if ((pmVar5 == (mnode_s *)0x0) || (pmVar5->contents == -2)) {
                  pmVar4 = pmVar4->children[1];
                }
                else {
                  if (-1 < pmVar5->contents) {
                    pmVar6 = pmVar5->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
joined_r0x0009d437:
                    do {
                      if ((pmVar6 == (mnode_s *)0x0) || (pmVar6->contents == -2)) goto LAB_0009d4cb;
                      if (pmVar6->contents < 0) {
                        iVar10 = ((int)pmVar6 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1
                        ;
                        if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0)
                        goto LAB_0009d5d0;
                        pmVar5 = pmVar5->children[1];
                        goto joined_r0x0009d411;
                      }
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
                      for (pmVar7 = pmVar6->children[0];
                          (pmVar7 != (mnode_s *)0x0 && (pmVar7->contents != -2));
                          pmVar7 = pmVar7->children[1]) {
                        if (pmVar7->contents < 0) {
                          iVar10 = ((int)pmVar7 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 +
                                   -1;
                          if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0)
                          goto LAB_0009d5d0;
                          pmVar6 = pmVar6->children[1];
                          goto joined_r0x0009d437;
                        }
                        pmVar8 = pmVar7->children[0];
                    /* Unresolved local var: int leafnum@[???]
                       Unresolved local var: mleaf_t * leaf@[???] */
                        while( true ) {
                          if ((pmVar8 == (mnode_s *)0x0) || (pmVar8->contents == -2))
                          goto LAB_0009d4b1;
                          if (pmVar8->contents < 0) break;
                          qVar9 = CM_HeadnodeVisible(pmVar8->children[0],visbits,
                                                     first_visible_leafnum);
                          if (qVar9 != false) {
                            return true;
                          }
                          pmVar8 = pmVar8->children[1];
                        }
                        iVar10 = ((int)pmVar8 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1
                        ;
                        if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0)
                        goto LAB_0009d5d0;
LAB_0009d4b1:
                      }
                      pmVar6 = pmVar6->children[1];
                    } while( true );
                  }
                  iVar10 = ((int)pmVar5 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
                  if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0)
                  goto LAB_0009d5d0;
                  pmVar4 = pmVar4->children[1];
                }
                goto joined_r0x0009d3eb;
              }
              iVar10 = ((int)pmVar4 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
              if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0)
              goto LAB_0009d5d0;
            }
            pmVar3 = pmVar3->children[1];
          }
          iVar10 = ((int)pmVar3 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
          if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) goto LAB_0009d5d0;
LAB_0009d504:
          pmVar2 = pmVar2->children[1];
        }
        iVar10 = ((int)pmVar2 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
        if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) goto LAB_0009d5d0;
LAB_0009d517:
        pmVar1 = pmVar1->children[1];
      }
      iVar10 = ((int)pmVar1 - (int)(sv.worldmodel)->leafs >> 2) * -0x11111111 + -1;
      if (((int)(uint)visbits[iVar10 >> 3] >> ((byte)iVar10 & 7) & 1U) != 0) {
LAB_0009d5d0:
        if (first_visible_leafnum == (int *)0x0) {
          return true;
        }
        *first_visible_leafnum = iVar10;
        return true;
      }
LAB_0009d52a:
      node = node->children[1];
      if (node == (mnode_s *)0x0) {
        return false;
      }
      iVar10 = node->contents;
    }
  }
  return false;
LAB_0009d4cb:
  pmVar5 = pmVar5->children[1];
  goto joined_r0x0009d411;
}


// CM_LeafPAS  @ 0009cce0
byte * CM_LeafPAS(int leafnum)

{
  if (gPAS != (byte *)0x0) {
    return gPAS + leafnum * gPVSRowBytes;
  }
  return mod_novis;
}


// CM_LeafPVS  @ 0009ccb0
byte * CM_LeafPVS(int leafnum)

{
  if (gPVS != (byte *)0x0) {
    return gPVS + leafnum * gPVSRowBytes;
  }
  return mod_novis;
}


