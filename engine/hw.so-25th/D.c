// D_FillRect  @ 0017b1f0
void D_FillRect(vrect_t *r,uchar *color)

{
  (*qglDisable)(0xde1);
  (*qglEnable)(0xbe2);
  (*qglTexEnvf)(0x2300,0x2200,8448.0);
  (*qglBlendFunc)(0x302,0x303);
  (*qglEnable)(0xbc0);
  (*qglColor4f)((float)*color / 255.0,(float)color[1] / 255.0,(float)color[2] / 255.0,1.0);
  (*qglDisable)(0xb71);
  (*qglBegin)(7);
  (*qglVertex2f)((float)r->x,(float)r->y);
  (*qglVertex2f)((float)(r->width + r->x),(float)r->y);
  (*qglVertex2f)((float)(r->width + r->x),(float)(r->height + r->y));
  (*qglVertex2f)((float)r->x,(float)(r->height + r->y));
  (*qglEnd)();
  (*qglDisable)(0xbc0);
  (*qglEnable)(0xb71);
  (*qglColor3f)(1.0,1.0,1.0);
  (*qglEnable)(0xde1);
                    /* WARNING: Could not recover jumptable at 0x0017b39c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglDisable)(0xbe2);
  return;
}


// D_FlushCaches  @ 001bae70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void D_FlushCaches(void)

{
  short sVar1;
  model_s *pmVar2;
  qboolean qVar3;
  GLint GVar4;
  model_t *pmVar5;
  msurface_t *psurf;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iStack_44;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_28;
  
  qVar3 = R_UseLegacyRender();
  if (((((((qVar3 == 0) && (qglCreateShader != (_func_GLuint_GLenum *)0x0)) &&
         (qglDeleteShader != (_func_void_GLuint *)0x0)) &&
        ((qglShaderSource != (_func_void_GLuint_GLsizei_GLchar_ptr_ptr_GLint_ptr *)0x0 &&
         (qglGetProgramiv != (_func_void_GLuint_GLenum_GLint_ptr *)0x0)))) &&
       ((qglGetProgramInfoLog != (_func_void_GLuint_GLsizei_GLsizei_ptr_GLchar_ptr *)0x0 &&
        ((qglAttachShader != (_func_void_GLuint_GLuint *)0x0 &&
         (qglLinkProgram != (_func_void_GLuint *)0x0)))))) &&
      (qglCreateProgram != (_func_GLuint *)0x0)) &&
     ((qglDeleteProgram != (_func_void_GLuint *)0x0 && (qglUseProgram != (_func_void_GLuint *)0x0)))
     ) {
    R_LoadShaders();
  }
  if (g_bHasShaderFunctions == false) {
    wasUsingShaders = false;
  }
  else {
    wasUsingShaders = false;
    if ((gl_use_shaders.value != 0.0) &&
       (wasUsingShaders = (qboolean)NAN(sv_allow_shaders.value), sv_allow_shaders.value != 0.0)) {
      wasUsingShaders = true;
    }
  }
  Q_memset(allocated,0,0x8000);
  r_framecount = 1;
  if (lightmap_textures[0] == 0) {
    piVar11 = lightmap_textures;
    do {
      GVar4 = GL_GenTexture();
      piVar12 = piVar11 + 1;
      *piVar11 = GVar4;
      piVar11 = piVar12;
    } while ((int (*) [20])piVar12 != R_TextureAnimation::rtable);
  }
  gl_lightmap_format = 0x1908;
  lightmap_bytes = 4;
  lightmap_used = 0x1908;
  iStack_28 = 1;
LAB_0019266f:
  do {
    pmVar2 = cl.model_precache[iStack_28];
    if (pmVar2 == (model_s *)0x0) break;
    if ((pmVar2->name[0] != '*') && (pmVar2->numsurfaces != 0)) {
      pmVar5 = CL_GetModelByIndex(iStack_28);
      r_pcurrentvertbase = pmVar5->vertexes;
      currentmodel = pmVar5;
      if (0 < pmVar5->numsurfaces) {
        iStack_30 = 0;
        iStack_34 = 0;
LAB_001926d0:
        psurf = (msurface_t *)((int)pmVar5->surfaces->texturemins + iStack_30 + -0x14);
        uVar7 = psurf->flags;
        if (((uVar7 & 0x14) == 0) && (((uVar7 & 0x20) == 0 || ((psurf->texinfo->flags & 1) == 0))))
        {
          iVar14 = ((int)psurf->extents[0] >> 4) + 1;
          sVar1 = psurf->extents[1];
          iStack_38 = 0;
          do {
            if (0x80 - iVar14 < 1) {
              iVar15 = 0x80;
            }
            else {
              iVar13 = iStack_38 << 9;
              iVar15 = 0x80;
              iVar16 = 0;
              do {
                if (iVar14 < 1) {
                  iVar8 = 0;
                  iStack_44 = 0;
joined_r0x0019278d:
                  if (iVar14 == iStack_44) {
                    psurf->light_s = iVar16;
                    psurf->light_t = iVar8;
                    iVar15 = iVar8;
                  }
                }
                else {
                  iVar6 = *(int *)((int)allocated[0] + iVar13);
                  if (iVar6 < iVar15) {
                    iVar8 = 0;
                    iVar9 = 0;
                    do {
                      if (iVar8 < iVar6) {
                        iVar8 = iVar6;
                      }
                      iVar10 = iVar9 + 1;
                      iStack_44 = iVar14;
                    } while ((iVar10 != iVar14) &&
                            (iVar6 = *(int *)((int)allocated[0] + iVar9 * 4 + 4 + iVar13),
                            iVar9 = iVar10, iStack_44 = iVar10, iVar6 < iVar15));
                    goto joined_r0x0019278d;
                  }
                }
                iVar16 = iVar16 + 1;
                iVar13 = iVar13 + 4;
              } while (iVar16 != 0x80 - iVar14);
            }
            iVar15 = iVar15 + ((int)sVar1 >> 4) + 1;
            if (iVar15 < 0x81) goto code_r0x001927af;
            iStack_38 = iStack_38 + 1;
            if (iStack_38 == 0x40) {
                    /* WARNING: Subroutine does not return */
              Sys_Error("AllocBlock: full");
            }
          } while( true );
        }
        goto LAB_00192822;
      }
    }
    iStack_28 = iStack_28 + 1;
  } while (iStack_28 != 0x200);
  goto LAB_00192865;
code_r0x001927af:
  iVar13 = 0;
  if (0 < iVar14) {
    do {
      iVar16 = psurf->light_s + iVar13;
      iVar13 = iVar13 + 1;
      allocated[iStack_38][iVar16] = iVar15;
    } while (iVar13 < iVar14);
  }
  iVar14 = lightmap_bytes;
  iVar15 = lightmap_bytes << 7;
  psurf->lightmaptexturenum = iStack_38;
  R_BuildLightMap(psurf,lightmaps +
                        iVar14 * iStack_38 * 0x4000 +
                        (psurf->light_t * 0x80 + psurf->light_s) * iVar14,iVar15);
  uVar7 = psurf->flags;
LAB_00192822:
  if (((uVar7 & 0x10) == 0) && (psurf->polys == (glpoly_t *)0x0)) {
    BuildSurfaceDisplayList(psurf);
  }
  iStack_34 = iStack_34 + 1;
  iStack_30 = iStack_30 + 0x6c;
  if (pmVar5->numsurfaces <= iStack_34) goto code_r0x00192852;
  goto LAB_001926d0;
code_r0x00192852:
  iStack_28 = iStack_28 + 1;
  if (iStack_28 == 0x200) goto LAB_00192865;
  goto LAB_0019266f;
LAB_00192865:
  if (gl_texsort == false) {
    GL_SelectTexture(TEXTURE1_SGIS);
  }
  iVar14 = 0;
  do {
    if (allocated[0][iVar14 * 0x20] == 0) break;
    *(undefined4 *)((int)lightmap_modified + iVar14) = 0;
    GL_Bind(*(int *)((int)lightmap_textures + iVar14));
    (*qglTexParameterf)(0xde1,0x2801,9729.0);
    (*qglTexParameterf)(0xde1,0x2800,9729.0);
    (*qglPixelStorei)(0xcf5,4);
    iVar15 = iVar14 * 0x1000;
    iVar14 = iVar14 + 4;
    (*qglTexImage2D)(0xde1,0,lightmap_used,0x80,0x80,0,gl_lightmap_format,0x1401,
                     lightmaps + iVar15 * lightmap_bytes);
  } while (iVar14 != 0x100);
  if (gl_texsort == false) {
    GL_SelectTexture(TEXTURE0_SGIS);
  }
  return;
}


// D_SetFadeColor  @ 0018be90
void D_SetFadeColor(int r,int g,int b,int fog)

{
  cshift_water.destcolor[1] = g;
  cshift_water.destcolor[0] = r;
  gWaterColor.r = r;
  gWaterColor.g = g;
  gWaterColor.b = b;
  cshift_water.percent = fog;
  cshift_water.destcolor[2] = b;
  return;
}


