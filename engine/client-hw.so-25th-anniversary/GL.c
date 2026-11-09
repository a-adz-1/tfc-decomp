// GL_BeginRendering  @ 00180e10
void GL_BeginRendering(int *x,int *y,int *width,int *height)

{
  int iVar1;
  ulonglong local_14;
  
                    /* Unresolved local var: cvar_t gl_clear@[???] */
  *y = 0;
  *x = 0;
  iVar1 = VideoMode_IsWindowed();
  if (iVar1 == 0) {
    VideoMode_GetCurrentVideoMode(width,height,(int *)0x0);
  }
  else {
    *width = window_rect.right - window_rect.left;
    *height = window_rect.bottom - window_rect.top;
  }
  vid.width = *width;
  vid.height = *height;
  local_14 = (ulonglong)vsync;
  vid.conwidth = vid.width;
  vid.conheight = vid.height;
  if (gl_vsync.value != (float)local_14) {
    SDL_GL_SetSwapInterval(0.0 < gl_vsync.value);
    local_14._0_4_ = (qboolean)(longlong)ROUND(gl_vsync.value);
    vsync = (qboolean)local_14;
  }
  if (s_BackBufferFBO.s_hBackBufferFBO != 0) {
    if (s_MSAAFBO.s_hBackBufferFBO == 0) {
      (*qglBindFramebufferEXT)(0x8ca9,s_BackBufferFBO.s_hBackBufferFBO);
    }
    else {
      (*qglBindFramebufferEXT)(0x8ca9,s_MSAAFBO.s_hBackBufferFBO);
    }
    glClearColor(0,0,0,0x3f800000);
    if (gl_clear.value == 0.0) {
      (*qglClear)(0x100);
    }
    else {
      glClear(0x4100);
    }
  }
  iVar1 = VideoMode_IsWindowed();
  if ((iVar1 != 0) && (bDoMSAAFBO != 0)) {
    glEnable(0x809d);
    GLimp_LogNewFrame();
    return;
  }
  GLimp_LogNewFrame();
  return;
}


// GL_Bind  @ 00159290
void GL_Bind(int texnum)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: int paletteIndex@[???] */
  uVar2 = texnum & 0xffff;
  if (uVar2 != currenttexture) {
    iVar1 = (texnum >> 0x10) + -1;
    currenttexture = uVar2;
    (*qglBindTexture)(0xde1,uVar2);
    if (((-1 < iVar1) && (iVar1 != g_currentpalette)) &&
       (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
      g_currentpalette = iVar1;
      (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(iVar1 * 0x308 + 0xdfa368));
    }
  }
  return;
}


// GL_BreakOnError  @ 0017b1e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_BreakOnError(void)

{
  return;
}


// GL_BuildLightmaps  @ 00192530
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_BuildLightmaps(void)

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
  int local_44;
  int local_38;
  int local_34;
  int local_30;
  int local_28;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: model_t * m@[???] */
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
  local_28 = 1;
LAB_0019266f:
  do {
    pmVar2 = cl.model_precache[local_28];
    if (pmVar2 == (model_s *)0x0) break;
    if ((pmVar2->name[0] != '*') && (pmVar2->numsurfaces != 0)) {
      pmVar5 = CL_GetModelByIndex(local_28);
      r_pcurrentvertbase = pmVar5->vertexes;
      currentmodel = pmVar5;
      if (0 < pmVar5->numsurfaces) {
        local_30 = 0;
        local_34 = 0;
LAB_001926d0:
                    /* Unresolved local var: msurface_t * surface@[???] */
        psurf = (msurface_t *)((int)pmVar5->surfaces->texturemins + local_30 + -0x14);
                    /* Unresolved local var: int smax@[???]
                       Unresolved local var: int tmax@[???]
                       Unresolved local var: byte * base@[???] */
        uVar7 = psurf->flags;
        if (((uVar7 & 0x14) == 0) && (((uVar7 & 0x20) == 0 || ((psurf->texinfo->flags & 1) == 0))))
        {
                    /* Unresolved local var: int smax@[???]
                       Unresolved local var: int tmax@[???]
                       Unresolved local var: byte * base@[???] */
          iVar14 = ((int)psurf->extents[0] >> 4) + 1;
          sVar1 = psurf->extents[1];
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int best@[???]
                       Unresolved local var: int best2@[???]
                       Unresolved local var: int texnum@[???] */
          local_38 = 0;
          do {
            if (0x80 - iVar14 < 1) {
              iVar15 = 0x80;
            }
            else {
              iVar13 = local_38 << 9;
              iVar15 = 0x80;
              iVar16 = 0;
              do {
                if (iVar14 < 1) {
                  iVar8 = 0;
                  local_44 = 0;
joined_r0x0019278d:
                  if (iVar14 == local_44) {
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
                      local_44 = iVar14;
                    } while ((iVar10 != iVar14) &&
                            (iVar6 = *(int *)((int)allocated[0] + iVar9 * 4 + 4 + iVar13),
                            iVar9 = iVar10, local_44 = iVar10, iVar6 < iVar15));
                    goto joined_r0x0019278d;
                  }
                }
                iVar16 = iVar16 + 1;
                iVar13 = iVar13 + 4;
              } while (iVar16 != 0x80 - iVar14);
            }
            iVar15 = iVar15 + ((int)sVar1 >> 4) + 1;
            if (iVar15 < 0x81) goto code_r0x001927af;
            local_38 = local_38 + 1;
            if (local_38 == 0x40) {
                    /* WARNING: Subroutine does not return */
              Sys_Error("AllocBlock: full");
            }
          } while( true );
        }
        goto LAB_00192822;
      }
    }
    local_28 = local_28 + 1;
  } while (local_28 != 0x200);
  goto LAB_00192865;
code_r0x001927af:
  iVar13 = 0;
  if (0 < iVar14) {
    do {
      iVar16 = psurf->light_s + iVar13;
      iVar13 = iVar13 + 1;
      allocated[local_38][iVar16] = iVar15;
    } while (iVar13 < iVar14);
  }
  iVar14 = lightmap_bytes;
  iVar15 = lightmap_bytes << 7;
  psurf->lightmaptexturenum = local_38;
  R_BuildLightMap(psurf,lightmaps +
                        iVar14 * local_38 * 0x4000 +
                        (psurf->light_t * 0x80 + psurf->light_s) * iVar14,iVar15);
  uVar7 = psurf->flags;
LAB_00192822:
  if (((uVar7 & 0x10) == 0) && (psurf->polys == (glpoly_t *)0x0)) {
    BuildSurfaceDisplayList(psurf);
  }
  local_34 = local_34 + 1;
  local_30 = local_30 + 0x6c;
  if (pmVar5->numsurfaces <= local_34) goto code_r0x00192852;
  goto LAB_001926d0;
code_r0x00192852:
  local_28 = local_28 + 1;
  if (local_28 == 0x200) goto LAB_00192865;
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


// GL_Config  @ 001805b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_Config(void)

{
  char *pcVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  char local_110 [255];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char[256] lowerCase@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Cbuf_InsertText("exec hw/opengl.cfg\n");
  Q_strncpy(local_110,gl_renderer,0xff);
  local_11 = 0;
  pcVar1 = Q_strstr(gl_vendor,"3Dfx");
  if (pcVar1 != (char *)0x0) {
    gGLHardwareType = 1;
    pcVar1 = Q_strstr(gl_renderer,"Voodoo(tm)");
    if (pcVar1 == (char *)0x0) {
      pcVar1 = Q_strstr(gl_renderer,"Voodoo^2");
      if (pcVar1 == (char *)0x0) {
        Cbuf_InsertText("exec hw/3Dfx.cfg\n");
      }
      else {
        Cbuf_InsertText("exec hw/3DfxVoodoo2.cfg\n");
      }
    }
    else {
      Cbuf_InsertText("exec hw/3DfxVoodoo1.cfg\n");
    }
    goto LAB_00180644;
  }
  pcVar1 = Q_strstr(gl_vendor,"NVIDIA");
  if (pcVar1 == (char *)0x0) {
    pcVar1 = Q_strstr(local_110,"riva tnt");
    if ((pcVar1 == (char *)0x0) &&
       (pcVar1 = Q_strstr(local_110,"velocity 4400"), pcVar1 == (char *)0x0)) {
      pcVar1 = Q_strstr(gl_vendor,"PCX2");
      if (pcVar1 == (char *)0x0) {
        pcVar1 = Q_strstr(gl_vendor,"PowerVR");
        if (pcVar1 == (char *)0x0) {
          pcVar1 = Q_strstr(gl_vendor,"V2200");
          if (pcVar1 == (char *)0x0) {
            pcVar1 = Q_strstr(gl_vendor,"3Dlabs");
            if (pcVar1 == (char *)0x0) {
              pcVar1 = Q_strstr(gl_vendor,"Matrox");
              if (pcVar1 == (char *)0x0) {
                pcVar1 = Q_strstr(gl_vendor,"ATI");
                if ((pcVar1 == (char *)0x0) ||
                   (((pcVar1 = Q_strstr(gl_renderer,"Rage"), pcVar1 == (char *)0x0 &&
                     (pcVar1 = Q_strstr(gl_renderer,"RAGE"), pcVar1 == (char *)0x0)) ||
                    (pcVar1 = Q_strstr(gl_renderer,"128"), pcVar1 == (char *)0x0)))) {
                  gGLHardwareType = 0;
                  pcVar1 = Q_strstr(gl_renderer,"Matrox");
                  if ((pcVar1 == (char *)0x0) ||
                     (pcVar1 = Q_strstr(gl_renderer,"G200"), pcVar1 == (char *)0x0)) {
                    pcVar1 = Q_strstr(gl_renderer,"ATI");
                    if (((pcVar1 == (char *)0x0) ||
                        ((pcVar1 = Q_strstr(gl_renderer,"Rage"), pcVar1 == (char *)0x0 &&
                         (pcVar1 = Q_strstr(gl_renderer,"RAGE"), pcVar1 == (char *)0x0)))) ||
                       (pcVar1 = Q_strstr(gl_renderer,"128"), pcVar1 == (char *)0x0)) {
                      pcVar1 = Q_strstr(gl_vendor,"NVIDIA");
                      if (pcVar1 != (char *)0x0) {
                        Cbuf_InsertText("exec hw/nvidiad3d.cfg\n");
                      }
                    }
                    else {
                      Cbuf_InsertText("exec hw/ATIRage128d3d.cfg\n");
                    }
                  }
                  else {
                    Cbuf_InsertText("exec hw/G200d3d.cfg\n");
                  }
                }
                else {
                  gGLHardwareType = 0;
                  Cbuf_InsertText("exec hw/ATIRage128.cfg\n");
                }
              }
              else {
                gGLHardwareType = 0;
                Cbuf_InsertText("exec hw/matrox.cfg\n");
              }
            }
            else {
              Cbuf_InsertText("exec hw/3Dlabs.cfg\n");
              gGLHardwareType = 6;
            }
          }
          else {
            Cbuf_InsertText("exec hw/V2200.cfg\n");
            gGLHardwareType = 5;
          }
        }
        else {
          Cbuf_InsertText("exec hw/PowerVRSG.cfg\n");
          gGLHardwareType = 4;
        }
      }
      else {
        Cbuf_InsertText("exec hw/PowerVRPCX2.cfg\n");
        gGLHardwareType = 3;
      }
      goto LAB_00180644;
    }
  }
  else {
    pcVar1 = Q_strstr(gl_renderer,"RIVA 128");
    if (pcVar1 != (char *)0x0) {
      gGLHardwareType = 2;
      Cbuf_InsertText("exec hw/riva128.cfg\n");
      goto LAB_00180644;
    }
    pcVar2 = Q_strstr(gl_renderer,"TNT");
    pcVar1 = gl_renderer;
    if (pcVar2 == (char *)0x0) {
      pcVar2 = strstr(gl_renderer,"Quadro");
      if ((pcVar2 != (char *)0x0) || (pcVar1 = strstr(pcVar1,"GeForce"), pcVar1 != (char *)0x0)) {
        gGLHardwareType = 0xb;
        Cbuf_InsertText("exec hw/geforce.cfg\n");
      }
      goto LAB_00180644;
    }
  }
  gGLHardwareType = 10;
  Cbuf_InsertText("exec hw/rivaTNT.cfg\n");
LAB_00180644:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// GL_CreateSurfaceLightmap  @ 00192370
void GL_CreateSurfaceLightmap(msurface_t *surf)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_30;
  int local_28;
  
                    /* Unresolved local var: int smax@[???]
                       Unresolved local var: int tmax@[???]
                       Unresolved local var: byte * base@[???] */
  if (((surf->flags & 0x14U) != 0) ||
     (((surf->flags & 0x20U) != 0 && ((surf->texinfo->flags & 1) != 0)))) {
    return;
  }
                    /* Unresolved local var: int smax@[???]
                       Unresolved local var: int tmax@[???]
                       Unresolved local var: byte * base@[???] */
  iVar1 = ((int)surf->extents[0] >> 4) + 1;
  sVar2 = surf->extents[1];
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int best@[???]
                       Unresolved local var: int best2@[???]
                       Unresolved local var: int texnum@[???] */
  local_28 = 0;
  do {
    iVar8 = 0x80;
    if (0 < 0x80 - iVar1) {
      iVar9 = 0;
      iVar7 = local_28 << 9;
      iVar8 = 0x80;
      do {
        if (iVar1 < 1) {
          iVar4 = 0;
          local_30 = 0;
joined_r0x001924d8:
          if (iVar1 == local_30) {
            surf->light_s = iVar9;
            surf->light_t = iVar4;
            iVar8 = iVar4;
          }
        }
        else {
          iVar3 = *(int *)((int)allocated[0] + iVar7);
          if (iVar3 < iVar8) {
            iVar4 = 0;
            iVar5 = 0;
            do {
              if (iVar4 < iVar3) {
                iVar4 = iVar3;
              }
              iVar6 = iVar5 + 1;
              local_30 = iVar1;
            } while ((iVar6 != iVar1) &&
                    (iVar3 = *(int *)((int)allocated[0] + iVar5 * 4 + 4 + iVar7), iVar5 = iVar6,
                    local_30 = iVar6, iVar3 < iVar8));
            goto joined_r0x001924d8;
          }
        }
        iVar9 = iVar9 + 1;
        iVar7 = iVar7 + 4;
      } while (iVar9 != 0x80 - iVar1);
    }
    iVar8 = iVar8 + ((int)sVar2 >> 4) + 1;
    if (iVar8 < 0x81) {
      iVar7 = 0;
      if (0 < iVar1) {
        do {
          iVar9 = surf->light_s + iVar7;
          iVar7 = iVar7 + 1;
          allocated[local_28][iVar9] = iVar8;
        } while (iVar7 < iVar1);
      }
      iVar1 = lightmap_bytes;
      iVar8 = lightmap_bytes << 7;
      surf->lightmaptexturenum = local_28;
      R_BuildLightMap(surf,lightmaps +
                           iVar1 * local_28 * 0x4000 +
                           (surf->light_t * 0x80 + surf->light_s) * iVar1,iVar8);
      return;
    }
    local_28 = local_28 + 1;
    if (local_28 == 0x40) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("AllocBlock: full");
    }
  } while( true );
}


// GL_DisableMultitexture  @ 00190970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_DisableMultitexture(void)

{
  if (mtexenabled == false) {
    return;
  }
  (*qglDisable)(0xde1);
  GL_SelectTexture(TEXTURE0_SGIS);
  mtexenabled = false;
  return;
}


// GL_DrawAliasFrame  @ 0017d1b0
void GL_DrawAliasFrame(aliashdr_t *paliashdr,int posenum)

{
  float fVar1;
  byte *pbVar2;
  byte *pbVar3;
  GLfloat *pGVar4;
  GLfloat GVar5;
  GLfloat GVar6;
  GLfloat *local_24;
  
                    /* Unresolved local var: float l@[???]
                       Unresolved local var: trivertx_t * verts@[???]
                       Unresolved local var: int * order@[???]
                       Unresolved local var: int count@[???] */
  local_24 = (GLfloat *)((int)paliashdr->scale + paliashdr->commands + -8);
  pbVar3 = (byte *)((int)paliashdr->scale +
                   paliashdr->posedata + posenum * paliashdr->poseverts * 4 + -8);
  GVar5 = *local_24;
  lastposenum = posenum;
  while (GVar5 != 0.0) {
    local_24 = local_24 + 1;
    pbVar2 = pbVar3;
    pGVar4 = local_24;
    if ((int)GVar5 < 0) {
      GVar5 = (GLfloat)-(int)GVar5;
      (*qglBegin)(6);
      GVar6 = GVar5;
    }
    else {
      (*qglBegin)(5);
      GVar6 = GVar5;
    }
    do {
      (*qglTexCoord2f)(*pGVar4,pGVar4[1]);
      fVar1 = shadedots[pbVar2[3]] * shadelight;
      (*qglColor3f)(fVar1,fVar1,fVar1);
      (*qglVertex3f)((float)*pbVar2,(float)pbVar2[1],(float)pbVar2[2]);
      GVar5 = (GLfloat)((int)GVar5 + -1);
      pbVar2 = pbVar2 + 4;
      pGVar4 = pGVar4 + 2;
    } while (GVar5 != 0.0);
    local_24 = local_24 + (int)GVar6 * 2;
    pbVar3 = pbVar3 + (int)GVar6 * 4;
    (*qglEnd)();
    GVar5 = *local_24;
  }
  return;
}


// GL_DrawAliasShadow  @ 0017d2e0
void GL_DrawAliasShadow(aliashdr_t *paliashdr,int posenum)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  int local_38;
  byte *local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: trivertx_t * verts@[???]
                       Unresolved local var: int * order@[???]
                       Unresolved local var: vec3_t point@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float lheight@[???]
                       Unresolved local var: int count@[???] */
  fVar1 = currententity->origin[2] - lightspot[2];
  local_34 = (byte *)((int)paliashdr->scale +
                     paliashdr->posedata + posenum * paliashdr->poseverts * 4 + -8);
  piVar3 = (int *)((int)paliashdr->scale + paliashdr->commands + -8);
  local_38 = *piVar3;
  if (local_38 != 0) {
    do {
      pbVar5 = local_34;
      if (local_38 < 0) {
        iVar4 = -local_38;
        (*qglBegin)(6);
        local_38 = iVar4;
      }
      else {
        (*qglBegin)(5);
        iVar4 = local_38;
      }
      do {
        fVar2 = (float)pbVar5[2] * paliashdr->scale[2] + paliashdr->scale_origin[2] + fVar1;
        local_28 = ((float)*pbVar5 * paliashdr->scale[0] + paliashdr->scale_origin[0]) -
                   shadevector[0] * fVar2;
        local_24 = ((float)pbVar5[1] * paliashdr->scale[1] + paliashdr->scale_origin[1]) -
                   fVar2 * shadevector[1];
        local_20 = 1.0 - fVar1;
        (*qglVertex3fv)(&local_28);
        iVar4 = iVar4 + -1;
        pbVar5 = pbVar5 + 4;
      } while (iVar4 != 0);
      piVar3 = piVar3 + local_38 * 2 + 1;
      local_34 = local_34 + local_38 * 4;
      (*qglEnd)();
      local_38 = *piVar3;
    } while (local_38 != 0);
  }
  return;
}


// GL_Dump_f  @ 001b9d30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_Dump_f(void)

{
  if (gl_vendor != (char *)0x0) {
    Con_Printf("GL Vendor: %s\n",gl_vendor);
  }
  if (gl_renderer != (char *)0x0) {
    Con_Printf("GL Renderer: %s\n",gl_renderer);
  }
  if (gl_version != (char *)0x0) {
    Con_Printf("GL Version: %s\n",gl_version);
  }
  if (gl_extensions != (char *)0x0) {
    Con_Printf("GL Extensions: %s\n",gl_extensions);
  }
  return;
}


// GL_EnableMultitexture  @ 001909b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_EnableMultitexture(void)

{
  if (gl_mtexable == 0) {
    return;
  }
  GL_SelectTexture(TEXTURE1_SGIS);
  (*qglEnable)(0xde1);
  mtexenabled = true;
  return;
}


// GL_EndRendering  @ 00180ff0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_EndRendering(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  int iVar9;
  int iVar10;
  GLint GVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  double dVar15;
  double dVar16;
  double local_64;
  int local_34;
  int local_30 [3];
  int local_24;
  
                    /* Unresolved local var: double dPreFlipTimeMs@[???]
                       Unresolved local var: double dFrameTimeMs@[???]
                       Unresolved local var: double dPostFlipTimeMs@[???] */
  if (s_BackBufferFBO.s_hBackBufferFBO != 0) {
                    /* Unresolved local var: int srcWide@[???]
                       Unresolved local var: int srcTall@[???]
                       Unresolved local var: int dstX1@[???]
                       Unresolved local var: int dstX2@[???]
                       Unresolved local var: int dstY1@[???]
                       Unresolved local var: int dstY2@[???]
                       Unresolved local var: float fSrcAspect@[???]
                       Unresolved local var: float fDstAspect@[???] */
    VideoMode_GetCurrentVideoMode(&local_34,local_30,(int *)0x0);
    if (s_MSAAFBO.s_hBackBufferFBO != 0) {
      (*qglBindFramebufferEXT)(0x8ca9,s_BackBufferFBO.s_hBackBufferFBO);
      (*qglBindFramebufferEXT)(0x8ca8,s_MSAAFBO.s_hBackBufferFBO);
      (*qglBlitFramebufferEXT)(0,0,local_34,local_30[0],0,0,local_34,local_30[0],0x4000,0x2601);
    }
    (*qglBindFramebufferEXT)(0x8ca9,0);
    (*qglBindFramebufferEXT)(0x8ca8,s_BackBufferFBO.s_hBackBufferFBO);
    glClearColor(0,0,0,0);
    glClear(0x4100);
    iVar10 = window_rect.right - window_rect.left;
    iVar14 = window_rect.bottom - window_rect.top;
    fVar5 = (float)local_34;
    fVar4 = (float)local_30[0];
    s_fYMouseAspectAdjustment = 1.0;
    s_fXMouseAspectAdjustment = 1.0;
    iVar9 = iVar10;
    GVar11 = iVar14;
    if (s_bEnforceAspect == 0) {
LAB_00181318:
      iVar12 = 0;
      iVar13 = 0;
    }
    else {
      fVar3 = fVar5 / fVar4;
      fVar2 = (float)iVar14;
      fVar1 = (float)iVar10 / fVar2;
      if (fVar1 <= fVar3) {
        if (fVar3 <= fVar1) goto LAB_00181318;
                    /* Unresolved local var: float fDesiredHeight@[???]
                       Unresolved local var: float fDiff@[???] */
        s_fYMouseAspectAdjustment = fVar3 / fVar1;
        iVar13 = 0;
        fVar1 = (fVar2 - (float)iVar10 * (1.0 / fVar3)) * 0.5;
        iVar12 = (int)(fVar1 + 0.0);
        GVar11 = (GLint)((float)iVar14 - fVar1);
      }
      else {
                    /* Unresolved local var: float fDesiredWidth@[???]
                       Unresolved local var: float fDiff@[???] */
        iVar12 = 0;
        fVar2 = ((float)iVar10 - fVar2 * fVar3) * 0.5;
        iVar13 = (int)(fVar2 + 0.0);
        s_fXMouseAspectAdjustment = fVar1 / fVar3;
        iVar9 = (int)((float)iVar10 - fVar2);
      }
    }
    if (s_bSupportsBlitTexturing == false) {
                    /* Unresolved local var: int GL_TEX_MODE@[???]
                       Unresolved local var: int nWindowWidth@[???]
                       Unresolved local var: int nWindowHeight@[???]
                       Unresolved local var: int nTextWidth@[???]
                       Unresolved local var: int nTextHeight@[???] */
      glDisable(0xbe2);
      glDisable(0xb50);
      glDisable(0xb71);
      glDisable(0xbc0);
      glDisable(0xb44);
      (*qglMatrixMode)(0x1701);
      (*qglPushMatrix)();
      glLoadIdentity();
      glOrtho(0,0,(double)iVar10,(double)iVar14,0,0,0,0xbff00000,0,0x3ff00000);
      (*qglMatrixMode)(0x1700);
      (*qglPushMatrix)();
      glLoadIdentity();
      (*qglViewport)(0,0,iVar10,iVar14);
      glTexParameteri(0x84f5,0x2800,0x2601);
      glTexParameteri(0x84f5,0x2801,0x2601);
      glTexParameteri(0x84f5,0x2802,0x812f);
      glTexParameteri(0x84f5,0x2803,0x812f);
      (*qglColor4f)(1.0,1.0,1.0,1.0);
      glEnable(0x84f5);
      glBindTexture(0x84f5,s_BackBufferFBO.s_hBackBufferTex);
      glBegin(7);
      glTexCoord2f(0,fVar4);
      glVertex3f((float)iVar13,(float)iVar12,0);
      glTexCoord2f(fVar5,fVar4);
      glVertex3f((float)iVar9,(float)iVar12,0);
      glTexCoord2f(fVar5,0);
      glVertex3f((float)iVar9,(float)GVar11,0);
      glTexCoord2f(0,0);
      glVertex3f((float)iVar13,(float)GVar11,0);
      glEnd();
      glBindTexture(0x84f5,0);
      (*qglMatrixMode)(0x1701);
      (*qglPopMatrix)();
      (*qglMatrixMode)(0x1700);
      (*qglPopMatrix)();
      glDisable(0x84f5);
    }
    else {
      (*qglBlitFramebufferEXT)(0,0,local_34,local_30[0],iVar13,iVar12,iVar9,GVar11,0x4000,0x2601);
    }
    (*qglBindFramebufferEXT)(0x8ca8,0);
  }
  dVar15 = Sys_FloatTime();
  dVar15 = dVar15 * 1000.0;
  if (dVar15 <= gGLLowLatencyPrevPostFlipTimeMs) {
    local_64 = 0.0;
  }
  else {
    local_64 = dVar15 - gGLLowLatencyPrevPostFlipTimeMs;
  }
  (*VID_FlipScreen)();
  dVar16 = Sys_FloatTime();
  dVar16 = dVar16 * 1000.0;
  if (gl_lowlatency.value <= 0.0) {
    gGLLowLatencyPrevPostFlipTimeMs = dVar16;
    return;
  }
                    /* Unresolved local var: double dVBlankIntervalMs@[???]
                       Unresolved local var: double dSlopMs@[???] */
  glFinish();
                    /* Unresolved local var: SDL_DisplayMode dm@[???] */
  iVar9 = SDL_GetCurrentDisplayMode(0,local_30);
  if ((iVar9 == 0) && (1 < local_24)) {
    dVar6 = (1.0 / (double)local_24) * 1000.0;
  }
  else {
    dVar6 = 16.666666666666668;
  }
  dVar15 = dVar16 - dVar15;
  dVar7 = dVar6 - local_64;
  if (dVar7 < 0.0) {
    if (dVar15 <= 0.0) goto LAB_00181224;
    dVar8 = 0.0;
  }
  else if (dVar15 <= dVar7) {
LAB_00181224:
    dVar8 = 0.0;
    if (0.0 <= dVar15) {
      dVar8 = dVar15;
    }
  }
  else {
    dVar8 = 0.0;
    if (0.0 <= dVar7) {
      dVar8 = dVar7;
    }
  }
  if (dVar8 <= (double)gl_lowlatency_maxslop_ms.value) {
    dVar15 = gGLLowLatencyThrottleMs;
    if (dVar8 < (double)gl_lowlatency_minslop_ms.value) {
      dVar15 = gGLLowLatencyThrottleMs - 1.0;
    }
  }
  else {
    dVar15 = gGLLowLatencyThrottleMs + 0.1;
  }
  dVar7 = dVar6 - (double)gl_lowlatency_minslop_ms.value;
  if (dVar7 < 0.0) {
    gGLLowLatencyThrottleMs = 0.0;
    if (0.0 < dVar15) goto LAB_00181110;
  }
  else if (dVar7 < dVar15) {
    gGLLowLatencyThrottleMs = 0.0;
    if (0.0 <= dVar7) {
      gGLLowLatencyThrottleMs = dVar7;
    }
    goto LAB_00181110;
  }
  gGLLowLatencyThrottleMs = 0.0;
  if (0.0 <= dVar15) {
    gGLLowLatencyThrottleMs = dVar15;
  }
LAB_00181110:
  if (0.0 < gl_lowlatency_debugoutput.value) {
    Con_Printf("gl_lowlatency: VBlank Interval: %.2f Frame Time: %.2f, Slop: %.2f Throttle:%.2f\n",
               SUB84(dVar6,0),(int)((ulonglong)dVar6 >> 0x20),SUB84(local_64,0),
               (int)((ulonglong)local_64 >> 0x20),SUB84(dVar8,0),(int)((ulonglong)dVar8 >> 0x20),
               gGLLowLatencyThrottleMs);
  }
  Sys_Sleep((int)gGLLowLatencyThrottleMs);
  gGLLowLatencyPrevPostFlipTimeMs = dVar16;
  return;
}


// GL_FindTexture  @ 0015b740
int GL_FindTexture(char *identifier)

{
  int iVar1;
  int iVar2;
  char *s2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: gltexture_t * glt@[???] */
  s2 = gltextures[0].identifier;
  iVar2 = 0;
  if (0 < numgltextures) {
    do {
      iVar1 = Q_strcmp(identifier,s2);
      if (iVar1 == 0) {
        return gltextures[iVar2].texnum;
      }
      iVar2 = iVar2 + 1;
      s2 = s2 + 0x54;
    } while (iVar2 < numgltextures);
  }
  return -1;
}


// GL_FreeGLTex  @ 0015f860
void GL_FreeGLTex(gltexture_t *glt)

{
  int iVar1;
  
                    /* Unresolved local var: int texnum@[???] */
  (*qglDeleteTextures)(1,(GLuint *)glt);
  iVar1 = (int)glt->paletteIndex;
  if (-1 < iVar1) {
    if (gGLPalette[iVar1].referenceCount < 2) {
      if (iVar1 < 0x15e) {
        gGLPalette[iVar1].tag = -1;
        gGLPalette[iVar1].referenceCount = 0;
      }
    }
    else {
      gGLPalette[iVar1].referenceCount = gGLPalette[iVar1].referenceCount + -1;
    }
  }
  Q_memset(glt,0,0x54);
  glt->servercount = -1;
  return;
}


// GL_GenTexture  @ 0015fde0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

GLint GL_GenTexture(void)

{
  GLuint local_10 [4];
  
                    /* Unresolved local var: GLuint tex@[???] */
  (*qglGenTextures)(1,local_10);
  return local_10[0];
}


// GL_Init  @ 00180a40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_Init(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10 [4];
  
                    /* Unresolved local var: int iShowExtensions@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int depth@[???] */
  gl_vendor = (char *)(*qglGetString)(0x1f00);
  if ((GLubyte *)gl_vendor != (GLubyte *)0x0) {
    Con_DPrintf("GL_VENDOR: %s\n",gl_vendor);
    gl_renderer = (char *)(*qglGetString)(0x1f01);
    Con_DPrintf("GL_RENDERER: %s\n",gl_renderer);
    gl_version = (char *)(*qglGetString)(0x1f02);
    Con_DPrintf("GL_VERSION: %s\n",gl_version);
    gl_extensions = (char *)(*qglGetString)(0x1f03);
    g_bSupportsNPOTTextures = false;
    iVar1 = COM_CheckParm("-glext");
    if (iVar1 != 0) {
      Con_DPrintf("GL_EXTENSIONS: %s\n",gl_extensions);
    }
    iVar1 = SDL_GL_GetAttribute(0,&local_20);
    if (iVar1 != 0) {
                    /* Unresolved local var: char * pErr@[???] */
      uVar3 = SDL_GetError();
      local_20 = 0;
      Con_DPrintf("Failed to get GL RED size (%s)\n",uVar3);
    }
    iVar1 = SDL_GL_GetAttribute(1,&local_1c);
    if (iVar1 != 0) {
                    /* Unresolved local var: char * pErr@[???] */
      uVar3 = SDL_GetError();
      local_1c = 0;
      Con_DPrintf("Failed to get GL GREEN size (%s)\n",uVar3);
    }
    iVar1 = SDL_GL_GetAttribute(2,&local_18);
    if (iVar1 != 0) {
                    /* Unresolved local var: char * pErr@[???] */
      uVar3 = SDL_GetError();
      local_18 = 0;
      Con_DPrintf("Failed to get GL BLUE size (%s)\n",uVar3);
    }
    iVar1 = SDL_GL_GetAttribute(3,&local_14);
    if (iVar1 != 0) {
                    /* Unresolved local var: char * pErr@[???] */
      uVar3 = SDL_GetError();
      local_14 = 0;
      Con_DPrintf("Failed to get GL ALPHA size (%s)\n",uVar3);
    }
    iVar1 = SDL_GL_GetAttribute(6,local_10);
    if (iVar1 != 0) {
                    /* Unresolved local var: char * pErr@[???] */
      uVar3 = SDL_GetError();
      local_10[0] = 0;
      Con_DPrintf("Failed to get GL DEPTH size (%s)\n",uVar3);
    }
    Con_DPrintf("GL_SIZES:  r:%d g:%d b:%d a:%d depth:%d\n",local_20,local_1c,local_18,local_14,
                local_10[0]);
    CheckTextureExtensions();
    CheckMultiTextureExtensions();
                    /* Unresolved local var: qboolean atismoothing@[???] */
    atismoothing = false;
    if (gl_extensions != (char *)0x0) {
      pcVar2 = Q_strstr(gl_extensions,"GL_ARB_texture_non_power_of_two");
      if (pcVar2 != (char *)0x0) {
        g_bSupportsNPOTTextures = true;
      }
    }
    (*qglClearColor)(1.0,0.0,0.0,0.0);
    (*qglCullFace)(0x404);
    (*qglEnable)(0xde1);
    (*qglEnable)(0xbc0);
    (*qglAlphaFunc)(0x205,0.0);
    (*qglPolygonMode)(0x408,0x1b02);
    (*qglShadeModel)(0x1d00);
    (*qglTexParameterf)(0xde1,0x2801,9728.0);
    (*qglTexParameterf)(0xde1,0x2800,9728.0);
    (*qglTexParameterf)(0xde1,0x2802,10497.0);
    (*qglTexParameterf)(0xde1,0x2803,10497.0);
    (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
    (*qglBlendFunc)(0x302,0x303);
    (*qglTexEnvf)(0x2300,0x2200,7681.0);
    GL_Config();
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Failed to query gl vendor string");
}


// GL_LoadFilterTexture  @ 00161840
void GL_LoadFilterTexture(float r,float g,float b,float brightness)

{
  undefined8 *__ptr;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  uint local_20 [4];
  
                    /* Unresolved local var: byte * data@[???]
                       Unresolved local var: int pixelIndex@[???] */
  iVar5 = gl_FilterTexture;
  if (gl_FilterTexture == 0) {
                    /* Unresolved local var: GLuint tex@[???] */
    (*qglGenTextures)(1,local_20);
    gl_FilterTexture = local_20[0];
    __ptr = malloc(0xc0);
    uVar3 = (int)(r * brightness * 255.0) & 0xff;
    uVar7 = (int)(g * brightness * 255.0) & 0xff;
    uVar1 = (uint)(brightness * b * 255.0);
    uVar6 = uVar1 & 0xff;
    uVar4 = (((uVar1 & 0xff) << 8 | uVar7) << 8 | uVar3) << 8 | uVar6;
                    /* Unresolved local var: int paletteIndex@[???] */
    uVar1 = ((uVar7 << 8 | uVar3) << 8 | uVar6) << 8 | uVar7;
    uVar2 = local_20[0] & 0xffff;
    uVar3 = ((uVar3 << 8 | uVar6) << 8 | uVar7) << 8 | uVar3;
    uVar11 = CONCAT44(uVar4,uVar1);
    bVar8 = uVar2 != currenttexture;
    uVar10 = CONCAT44(uVar3,uVar4);
    uVar9 = CONCAT44(uVar1,uVar3);
    __ptr[4] = uVar10;
    __ptr[5] = uVar11;
    __ptr[2] = uVar11;
    __ptr[3] = uVar9;
    *__ptr = uVar9;
    __ptr[1] = uVar10;
    __ptr[6] = uVar9;
    __ptr[7] = uVar10;
    __ptr[8] = uVar11;
    __ptr[9] = uVar9;
    __ptr[10] = uVar10;
    __ptr[0xb] = uVar11;
    __ptr[0xc] = uVar9;
    __ptr[0xd] = uVar10;
    __ptr[0xe] = uVar11;
    __ptr[0xf] = uVar9;
    __ptr[0x10] = uVar10;
    __ptr[0x11] = uVar11;
    __ptr[0x12] = uVar9;
    __ptr[0x13] = uVar10;
    __ptr[0x14] = uVar11;
    __ptr[0x15] = uVar9;
    __ptr[0x16] = uVar10;
    __ptr[0x17] = uVar11;
    if (bVar8) {
      iVar5 = ((int)local_20[0] >> 0x10) + -1;
      currenttexture = uVar2;
      (*qglBindTexture)(0xde1,uVar2);
      if (((-1 < iVar5) && (iVar5 != g_currentpalette)) &&
         (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
        g_currentpalette = iVar5;
        (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(iVar5 * 0x308 + 0xdfa368));
      }
    }
    (*qglTexImage2D)(0xde1,0,0x1907,8,8,0,0x1907,0x1401,__ptr);
    (*qglTexParameteri)(0xde1,0x2802,0x2901);
    (*qglTexParameteri)(0xde1,0x2803,0x2901);
    (*qglTexParameteri)(0xde1,0x2800,0x2601);
    (*qglTexParameteri)(0xde1,0x2801,0x2601);
    (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
  }
  else {
    __ptr = malloc(0xc0);
    uVar3 = (int)(r * brightness * 255.0) & 0xff;
    uVar4 = (int)(g * brightness * 255.0) & 0xff;
    uVar1 = (uint)(brightness * b * 255.0);
    uVar2 = uVar1 & 0xff;
    uVar7 = ((uVar3 << 8 | uVar2) << 8 | uVar4) << 8 | uVar3;
    uVar6 = (((uVar1 & 0xff) << 8 | uVar4) << 8 | uVar3) << 8 | uVar2;
                    /* Unresolved local var: int paletteIndex@[???] */
    uVar1 = iVar5 & 0xffff;
    uVar4 = ((uVar4 << 8 | uVar3) << 8 | uVar2) << 8 | uVar4;
    uVar10 = CONCAT44(uVar7,uVar6);
    bVar8 = uVar1 != currenttexture;
    uVar11 = CONCAT44(uVar6,uVar4);
    uVar9 = CONCAT44(uVar4,uVar7);
    __ptr[4] = uVar10;
    __ptr[5] = uVar11;
    __ptr[2] = uVar11;
    __ptr[3] = uVar9;
    *__ptr = uVar9;
    __ptr[1] = uVar10;
    __ptr[6] = uVar9;
    __ptr[7] = uVar10;
    __ptr[8] = uVar11;
    __ptr[9] = uVar9;
    __ptr[10] = uVar10;
    __ptr[0xb] = uVar11;
    __ptr[0xc] = uVar9;
    __ptr[0xd] = uVar10;
    __ptr[0xe] = uVar11;
    __ptr[0xf] = uVar9;
    __ptr[0x10] = uVar10;
    __ptr[0x11] = uVar11;
    __ptr[0x12] = uVar9;
    __ptr[0x13] = uVar10;
    __ptr[0x14] = uVar11;
    __ptr[0x15] = uVar9;
    __ptr[0x16] = uVar10;
    __ptr[0x17] = uVar11;
    if (bVar8) {
      iVar5 = (iVar5 >> 0x10) + -1;
      currenttexture = uVar1;
      (*qglBindTexture)(0xde1,uVar1);
      if (((-1 < iVar5) && (iVar5 != g_currentpalette)) &&
         (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
        g_currentpalette = iVar5;
        (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(iVar5 * 0x308 + 0xdfa368));
      }
    }
    (*qglTexSubImage2D)(0xde1,0,0,0,8,8,0x1907,0x1401,__ptr);
  }
  free(__ptr);
  return;
}


// GL_LoadPicTexture  @ 00160880
int GL_LoadPicTexture(qpic_t *pic,char *pszName)

{
  int iVar1;
  int in_stack_fffffff0;
  byte *in_stack_fffffff4;
  int in_stack_fffffff8;
  
                    /* Unresolved local var: byte * pPal@[???] */
  iVar1 = GL_LoadTexture2(pszName,pic->width,pic->height,(int)pic->data,
                          pic->data + pic->width * pic->height + 2,gl_filter_max,in_stack_fffffff0,
                          in_stack_fffffff4,in_stack_fffffff8);
  return iVar1;
}


// GL_LoadTexture  @ 00160820
int GL_LoadTexture(char *identifier,GL_TEXTURETYPE textureType,int width,int height,byte *data,
                  int mipmap,int iType,byte *pPal)

{
  int iVar1;
  
  iVar1 = GL_LoadTexture2(identifier,textureType,width,height,data,mipmap,iType,pPal,gl_filter_max);
  return iVar1;
}


// GL_LoadTexture2  @ 0015ca20
int __regparm3
GL_LoadTexture2(char *identifier,GL_TEXTURETYPE textureType,int width,int height,byte *data,
               qboolean mipmap,int iType,byte *pPal,int filter)

{
  undefined1 *puVar1;
  char cVar2;
  GL_TEXTURETYPE GVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  qboolean qVar10;
  uint uVar11;
  uint uVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  gltexture_t *pgVar15;
  gltexture_t *pgVar16;
  GL_TEXTURETYPE GVar17;
  int iVar18;
  int in_GS_OFFSET;
  GL_TEXTURETYPE filter_00;
  uint local_4058;
  uint local_4050;
  GL_TEXTURETYPE local_4028;
  uint local_4024;
  undefined1 local_4020 [16384];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: gltexture_t * glt@[???]
                       Unresolved local var: gltexture_t * slot@[???]
                       Unresolved local var: BOOL mustRescale@[???] */
  pgVar15 = (gltexture_t *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  V_CheckGamma();
  cVar2 = *identifier;
  while (cVar2 != '\0') {
    if (numgltextures < 1) goto LAB_0015cabf;
    iVar18 = 0;
    pgVar16 = gltextures;
    iVar6 = numgltextures;
    while( true ) {
      while ((short)(pgVar16->servercount & -0x8000) != 0) {
        if (pgVar15 == (gltexture_t *)0x0) {
          pgVar15 = pgVar16;
        }
        iVar18 = iVar18 + 1;
        pgVar16 = pgVar16 + 1;
        if (iVar6 <= iVar18) goto LAB_0015cabf;
      }
      iVar6 = Q_strcmp(identifier,pgVar16->identifier);
      if (iVar6 == 0) break;
      iVar18 = iVar18 + 1;
      pgVar16 = pgVar16 + 1;
      iVar6 = numgltextures;
      if (numgltextures <= iVar18) goto LAB_0015cabf;
    }
    if ((pgVar16->width == textureType) && (pgVar16->height == width)) {
      if (0 < pgVar16->servercount) {
        pgVar16->servercount = (short)gHostSpawnCount;
      }
      if (pgVar16->paletteIndex < 0) {
        uVar12 = pgVar16->texnum;
      }
      else {
        uVar12 = (pgVar16->paletteIndex + 1) * 0x10000 | pgVar16->texnum;
      }
      goto LAB_0015cca8;
    }
    identifier[3] = identifier[3] + '\x01';
    cVar2 = *identifier;
  }
  Con_DPrintf("NULL Texture\n");
LAB_0015cabf:
  if (pgVar15 == (gltexture_t *)0x0) {
    iVar6 = numgltextures + 1;
    pgVar15 = gltextures + numgltextures;
    numgltextures = iVar6;
    if (9999 < iVar6) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Texture Overflow: MAX_GLTEXTURES");
    }
  }
  if (pgVar15->texnum == 0) {
                    /* Unresolved local var: GLuint tex@[???] */
    (*qglGenTextures)(1,&local_4024);
    pgVar15->texnum = local_4024;
  }
  filter_00 = 0x3f;
  Q_strncpy(pgVar15->identifier,identifier,0x3f);
  pgVar15->identifier[0x3f] = '\0';
  pgVar15->mipmap = false;
  pgVar15->servercount = 0;
  pgVar15->width = textureType;
  pgVar15->paletteIndex = -1;
  pgVar15->height = width;
                    /* Unresolved local var: int paletteIndex@[???] */
  uVar12 = pgVar15->texnum & 0xffff;
  if (uVar12 != currenttexture) {
    iVar6 = (pgVar15->texnum >> 0x10) + -1;
    currenttexture = uVar12;
    (*qglBindTexture)(0xde1,uVar12);
    if (((-1 < iVar6) && (iVar6 != g_currentpalette)) &&
       (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
      filter_00 = 0x100;
      g_currentpalette = iVar6;
      (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(iVar6 * 0x308 + 0xdfa368));
    }
  }
  currenttexture = -1;
                    /* Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: int max_size@[???] */
  GVar3 = textureType;
  uVar12 = width;
  if ((((g_bSupportsNPOTTextures == false) &&
       ((ComputeScaledSize((int *)&local_4028,(int *)&local_4024,textureType,width),
        GVar17 = local_4028, GVar3 = local_4028, uVar12 = local_4024, textureType != local_4028 ||
        (GVar17 = textureType, width != local_4024)))) && ((int)GVar17 < 0x81)) &&
     ((int)local_4024 < 0x81)) {
                    /* Unresolved local var: byte * pTexture@[???]
                       Unresolved local var: byte[16384] scaled@[???] */
    if (fs_perf_warnings.value != 0.0) {
      filter_00 = textureType;
      Con_DPrintf("fs_perf_warnings: resampling non-power-of-2 texture %s (%dx%d)\n",identifier,
                  textureType,width);
      GVar17 = local_4028;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uint ufrac@[???]
                       Unresolved local var: uint vfrac@[???]
                       Unresolved local var: uint ufracstep@[???]
                       Unresolved local var: uint vfracstep@[???]
                       Unresolved local var: byte * src@[???]
                       Unresolved local var: byte * dest@[???] */
    uVar7 = (int)(textureType << 0x10) / (int)GVar17;
    uVar8 = (width << 0x10) / (int)local_4024;
    local_4050 = uVar8 >> 2;
    GVar3 = local_4028;
    uVar12 = local_4024;
    if (0 < (int)local_4024) {
      puVar14 = local_4020;
      local_4058 = 0;
      iVar6 = height;
      do {
        if (0 < (int)GVar17) {
          puVar1 = puVar14 + GVar17;
          uVar9 = uVar7 >> 2;
          puVar13 = puVar14;
          do {
            puVar14 = puVar13 + 1;
            uVar11 = uVar9 >> 0x10;
            uVar9 = uVar9 + uVar7;
            *puVar13 = *(undefined1 *)(iVar6 + uVar11);
            puVar13 = puVar14;
          } while (puVar14 != puVar1);
        }
        local_4058 = local_4058 + 1;
        local_4050 = local_4050 + uVar8;
        iVar6 = iVar6 + (local_4050 >> 0x10) * textureType;
        local_4050 = local_4050 & 0xffff;
      } while (local_4058 != local_4024);
    }
  }
  local_4024 = uVar12;
  local_4028 = GVar3;
  if (g_modfuncs.m_pfnTextureLoad != (PFN_TEXTURELOAD)0x0) {
    filter_00 = width;
    (*g_modfuncs.m_pfnTextureLoad)(identifier,textureType,width,(char *)height);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: qboolean noalpha@[???]
                       Unresolved local var: int p@[???]
                       Unresolved local var: byte * pb@[???] */
  uVar12 = textureType * width;
  if (uVar12 < 0x12c001) {
    if (data != (byte *)0x0) {
      pbVar4 = data;
      do {
        pbVar5 = pbVar4 + 1;
        *pbVar4 = texgammatable[*pbVar4];
        pbVar4 = pbVar5;
      } while (pbVar5 != data + 0x300);
      if (uVar12 == 0) {
        qVar10 = false;
      }
      else {
        qVar10 = true;
        iVar6 = 0;
        do {
          while (*(byte *)(height + iVar6) != 0xff) {
            GL_Upload16::trans[iVar6] =
                 *(uint *)(data + (uint)*(byte *)(height + iVar6) * 3) | 0xff000000;
            iVar6 = iVar6 + 1;
            if (uVar12 - iVar6 == 0) goto LAB_0015cc75;
          }
          GL_Upload16::trans[iVar6] = 0;
          iVar6 = iVar6 + 1;
          qVar10 = false;
        } while (uVar12 - iVar6 != 0);
LAB_0015cc75:
        qVar10 = qVar10 ^ true;
      }
      GL_Upload32(GL_Upload16::trans,textureType,width,qVar10,mipmap,filter_00);
    }
  }
  else {
    Con_Printf("Can\'t upload (%ix%i) texture, it\'s > 640*480 bytes\n",textureType,width);
  }
  if (pgVar15->paletteIndex < 0) {
    uVar12 = pgVar15->texnum;
  }
  else {
    uVar12 = (pgVar15->paletteIndex + 1) * 0x10000 | pgVar15->texnum;
  }
LAB_0015cca8:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}


// GL_LoadTexture2  @ 0015edf0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __regparm3
GL_LoadTexture2(char *identifier,GL_TEXTURETYPE textureType,int width,int height,byte *data,
               qboolean mipmap,int iType,byte *pPal,int filter)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 auVar3 [15];
  undefined1 auVar4 [14];
  undefined1 auVar5 [15];
  undefined1 auVar6 [15];
  undefined1 auVar7 [15];
  undefined1 auVar8 [14];
  undefined1 auVar9 [13];
  undefined1 auVar10 [13];
  undefined1 auVar11 [13];
  undefined1 auVar12 [15];
  undefined1 auVar13 [15];
  undefined1 auVar14 [16];
  undefined1 auVar15 [15];
  undefined1 auVar16 [15];
  undefined1 auVar17 [15];
  unkuint9 Var18;
  undefined1 auVar19 [11];
  undefined1 auVar20 [15];
  undefined1 auVar21 [14];
  undefined1 auVar22 [13];
  undefined1 auVar23 [15];
  uint6 uVar24;
  GL_TEXTURETYPE GVar25;
  int iVar26;
  byte *pbVar27;
  byte *pbVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  undefined1 (*pauVar33) [16];
  gltexture_t *pgVar34;
  gltexture_t *pgVar35;
  int iVar36;
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  GL_TEXTURETYPE local_24;
  uint local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: gltexture_t * glt@[???]
                       Unresolved local var: gltexture_t * slot@[???]
                       Unresolved local var: BOOL mustRescale@[???] */
  pgVar34 = (gltexture_t *)0x0;
  V_CheckGamma();
  cVar1 = *identifier;
  while (cVar1 != '\0') {
                    /* WARNING: Read-only address (ram,0x00267f60) is written */
    if (numgltextures < 1) goto LAB_0015ee5f;
    iVar36 = 0;
    pgVar35 = gltextures;
    iVar26 = numgltextures;
    while( true ) {
      while ((short)(pgVar35->servercount & -0x8000) != 0) {
        if (pgVar34 == (gltexture_t *)0x0) {
          pgVar34 = pgVar35;
        }
        iVar36 = iVar36 + 1;
        pgVar35 = pgVar35 + 1;
        if (iVar26 <= iVar36) goto LAB_0015ee5f;
      }
      iVar26 = Q_strcmp(identifier,pgVar35->identifier);
      if (iVar26 == 0) break;
      iVar36 = iVar36 + 1;
      pgVar35 = pgVar35 + 1;
      iVar26 = numgltextures;
      if (numgltextures <= iVar36) goto LAB_0015ee5f;
    }
    if ((pgVar35->width == textureType) && (pgVar35->height == width)) {
      if (0 < pgVar35->servercount) {
        pgVar35->servercount = (short)gHostSpawnCount;
      }
      if (-1 < pgVar35->paletteIndex) {
        return (pgVar35->paletteIndex + 1) * 0x10000 | pgVar35->texnum;
      }
      return pgVar35->texnum;
    }
    identifier[3] = identifier[3] + '\x01';
    cVar1 = *identifier;
  }
                    /* WARNING: Read-only address (ram,0x00267f60) is written */
  Con_DPrintf("NULL Texture\n");
LAB_0015ee5f:
  if (pgVar34 == (gltexture_t *)0x0) {
    iVar26 = numgltextures + 1;
    pgVar34 = gltextures + numgltextures;
    numgltextures = iVar26;
    if (9999 < iVar26) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Texture Overflow: MAX_GLTEXTURES");
    }
  }
  if (pgVar34->texnum == 0) {
                    /* Unresolved local var: GLuint tex@[???] */
    (*qglGenTextures)(1,local_20);
    pgVar34->texnum = local_20[0];
  }
  Q_strncpy(pgVar34->identifier,identifier,0x3f);
  pgVar34->identifier[0x3f] = '\0';
  pgVar34->mipmap = true;
  pgVar34->servercount = 0;
  pgVar34->width = textureType;
  pgVar34->paletteIndex = -1;
  pgVar34->height = width;
                    /* Unresolved local var: int paletteIndex@[???] */
  uVar32 = pgVar34->texnum & 0xffff;
  if (uVar32 != currenttexture) {
    iVar26 = (pgVar34->texnum >> 0x10) + -1;
    currenttexture = uVar32;
    (*qglBindTexture)(0xde1,uVar32);
    if (((-1 < iVar26) && (iVar26 != g_currentpalette)) &&
       (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
      g_currentpalette = iVar26;
      (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(iVar26 * 0x308 + 0xdfa368));
    }
  }
  currenttexture = -1;
                    /* Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: int max_size@[???] */
  GVar25 = textureType;
  uVar32 = width;
  if (g_bSupportsNPOTTextures == false) {
    ComputeScaledSize((int *)&local_24,(int *)local_20,textureType,width);
    GVar25 = local_24;
    uVar32 = local_20[0];
  }
  local_20[0] = uVar32;
  local_24 = GVar25;
  if (g_modfuncs.m_pfnTextureLoad != (PFN_TEXTURELOAD)0x0) {
    (*g_modfuncs.m_pfnTextureLoad)(identifier,textureType,width,(char *)height);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: qboolean noalpha@[???]
                       Unresolved local var: int p@[???]
                       Unresolved local var: byte * pb@[???] */
  uVar32 = textureType * width;
  if (uVar32 < 0x12c001) {
    if (data != (byte *)0x0) {
      pbVar27 = data;
      do {
        pbVar28 = pbVar27 + 1;
        *pbVar27 = texgammatable[*pbVar27];
        pbVar27 = pbVar28;
      } while (pbVar28 != data + 0x300);
      if (uVar32 == 0) {
        iVar26 = 0;
      }
      else {
        if ((data + 0x2fd < GL_Upload16::trans + uVar32 && GL_Upload16::trans < data + 0x301 ||
             GL_Upload16::trans < (uint *)(height + uVar32) &&
             (uint)height < GL_Upload16::trans + uVar32) || (uVar32 < 0x10)) {
          uVar31 = 0;
          do {
            GL_Upload16::trans[uVar31] =
                 *(uint *)(data + 0x2fd) & 0xffffff | (uint)*(byte *)(height + uVar31) << 0x18;
            uVar31 = uVar31 + 1;
          } while (uVar31 != uVar32);
        }
        else {
          uVar2 = *(undefined4 *)(data + 0x2fd);
          uVar30 = (uVar32 - 0x10 >> 4) + 1;
          auVar37._4_4_ = uVar2;
          auVar37._0_4_ = uVar2;
          auVar37._8_4_ = uVar2;
          auVar37._12_4_ = uVar2;
          auVar37 = auVar37 & _DAT_00267f60;
          iVar26 = uVar30 * 0x10;
          uVar31 = 0;
          pauVar33 = (undefined1 (*) [16])GL_Upload16::trans;
          do {
            uVar29 = uVar31 + 1;
            auVar39 = *(undefined1 (*) [16])(height + uVar31 * 0x10);
            auVar3[0xd] = 0;
            auVar3._0_13_ = auVar39._0_13_;
            auVar3[0xe] = auVar39[7];
            auVar5[0xc] = auVar39[6];
            auVar5._0_12_ = auVar39._0_12_;
            auVar5._13_2_ = auVar3._13_2_;
            auVar6[0xb] = 0;
            auVar6._0_11_ = auVar39._0_11_;
            auVar6._12_3_ = auVar5._12_3_;
            uVar31 = auVar6._11_4_;
            auVar7[10] = auVar39[5];
            auVar7._0_10_ = auVar39._0_10_;
            auVar7._11_4_ = uVar31;
            auVar12[9] = 0;
            auVar12._0_9_ = auVar39._0_9_;
            auVar12._10_5_ = auVar7._10_5_;
            auVar13[8] = auVar39[4];
            auVar13._0_8_ = auVar39._0_8_;
            auVar13._9_6_ = auVar12._9_6_;
            auVar17._7_8_ = 0;
            auVar17._0_7_ = auVar13._8_7_;
            Var18 = CONCAT81(SUB158(auVar17 << 0x40,7),auVar39[3]);
            auVar23._9_6_ = 0;
            auVar23._0_9_ = Var18;
            auVar19._1_10_ = SUB1510(auVar23 << 0x30,5);
            auVar19[0] = auVar39[2];
            auVar20._11_4_ = 0;
            auVar20._0_11_ = auVar19;
            auVar15[2] = auVar39[1];
            auVar15._0_2_ = auVar39._0_2_;
            auVar15._3_12_ = SUB1512(auVar20 << 0x20,3);
            auVar16._2_13_ = auVar15._2_13_;
            auVar16._0_2_ = auVar39._0_2_ & 0xff;
            auVar38._0_4_ = (uint)auVar13._8_2_ << 0x18;
            auVar38._4_4_ = (uint)auVar7._10_2_ << 0x18;
            auVar38._8_4_ = (uVar31 >> 8) << 0x18;
            auVar38._12_4_ = uVar31 & 0xff000000;
            uVar31 = CONCAT13(0,CONCAT12(auVar39[9],(ushort)auVar39[8]));
            auVar4._10_2_ = 0;
            auVar4._0_10_ = auVar16._0_10_;
            auVar4._12_2_ = (short)Var18;
            uVar24 = CONCAT42(auVar4._10_4_,auVar19._0_2_);
            auVar21._6_8_ = 0;
            auVar21._0_6_ = uVar24;
            auVar8._4_2_ = auVar15._2_2_;
            auVar8._0_4_ = auVar16._0_4_;
            auVar8._6_8_ = SUB148(auVar21 << 0x40,6);
            pauVar33[1] = auVar38 | auVar37;
            auVar40._0_4_ = auVar16._0_4_ << 0x18;
            auVar40._4_4_ = auVar8._4_4_ << 0x18;
            auVar40._8_4_ = (int)uVar24 << 0x18;
            auVar40._12_4_ = (auVar4._10_4_ >> 0x10) << 0x18;
            auVar9[0xc] = auVar39[0xb];
            auVar9._0_12_ = ZEXT112(auVar39[0xc]) << 0x40;
            auVar10._10_3_ = auVar9._10_3_;
            auVar10._0_10_ = (unkuint10)auVar39[10] << 0x40;
            auVar22._5_8_ = 0;
            auVar22._0_5_ = auVar10._8_5_;
            auVar11[4] = auVar39[9];
            auVar11._0_4_ = uVar31;
            auVar11[5] = 0;
            auVar11._6_7_ = SUB137(auVar22 << 0x40,6);
            auVar14._1_4_ = (uint)auVar39[0xd] << 0x18;
            auVar14[0] = auVar39[0xc];
            auVar14._5_4_ = (uint)auVar39[0xe] << 0x18;
            auVar14._9_4_ = (uint)auVar39[0xf] << 0x18;
            auVar14._13_3_ = 0;
            auVar39._0_4_ = uVar31 << 0x18;
            auVar39._4_4_ = auVar11._4_4_ << 0x18;
            auVar39._8_4_ = auVar10._8_4_ << 0x18;
            auVar39._12_4_ = (uint)(uint3)(auVar9._10_3_ >> 0x10) << 0x18;
            *pauVar33 = auVar40 | auVar37;
            pauVar33[3] = auVar14 << 0x18 | auVar37;
            pauVar33[2] = auVar39 | auVar37;
            uVar31 = uVar29;
            pauVar33 = pauVar33 + 4;
          } while (uVar29 < uVar30);
          if (uVar32 + uVar30 * -0x10 != 0) {
            iVar36 = iVar26 + 1;
            GL_Upload16::trans[uVar30 * 0x10] =
                 *(uint *)(data + 0x2fd) & 0xffffff | (uint)*(byte *)(height + iVar26) << 0x18;
            if (iVar36 < (int)uVar32) {
              GL_Upload16::trans[iVar36] =
                   *(uint *)(data + 0x2fd) & 0xffffff | (uint)*(byte *)(height + iVar36) << 0x18;
              iVar36 = iVar26 + 2;
              if (uVar32 - iVar36 != 0 && iVar36 <= (int)uVar32) {
                GL_Upload16::trans[iVar36] =
                     *(uint *)(data + 0x2fd) & 0xffffff | (uint)*(byte *)(height + iVar36) << 0x18;
                iVar36 = iVar26 + 3;
                if (uVar32 - iVar36 != 0 && iVar36 <= (int)uVar32) {
                  GL_Upload16::trans[iVar36] =
                       *(uint *)(data + 0x2fd) & 0xffffff | (uint)*(byte *)(height + iVar36) << 0x18
                  ;
                  iVar36 = iVar26 + 4;
                  if (uVar32 - iVar36 != 0 && iVar36 <= (int)uVar32) {
                    GL_Upload16::trans[iVar36] =
                         *(uint *)(data + 0x2fd) & 0xffffff |
                         (uint)*(byte *)(height + iVar36) << 0x18;
                    iVar36 = iVar26 + 5;
                    if (uVar32 - iVar36 != 0 && iVar36 <= (int)uVar32) {
                      GL_Upload16::trans[iVar36] =
                           *(uint *)(data + 0x2fd) & 0xffffff |
                           (uint)*(byte *)(height + iVar36) << 0x18;
                      iVar36 = iVar26 + 6;
                      if (uVar32 - iVar36 != 0 && iVar36 <= (int)uVar32) {
                        GL_Upload16::trans[iVar36] =
                             *(uint *)(data + 0x2fd) & 0xffffff |
                             (uint)*(byte *)(height + iVar36) << 0x18;
                        iVar36 = iVar26 + 7;
                        if (uVar32 - iVar36 != 0 && iVar36 <= (int)uVar32) {
                          GL_Upload16::trans[iVar36] =
                               *(uint *)(data + 0x2fd) & 0xffffff |
                               (uint)*(byte *)(height + iVar36) << 0x18;
                          iVar36 = iVar26 + 8;
                          if (uVar32 - iVar36 != 0 && iVar36 <= (int)uVar32) {
                            GL_Upload16::trans[iVar36] =
                                 *(uint *)(data + 0x2fd) & 0xffffff |
                                 (uint)*(byte *)(height + iVar36) << 0x18;
                            iVar36 = iVar26 + 9;
                            if (uVar32 - iVar36 != 0 && iVar36 <= (int)uVar32) {
                              GL_Upload16::trans[iVar36] =
                                   *(uint *)(data + 0x2fd) & 0xffffff |
                                   (uint)*(byte *)(height + iVar36) << 0x18;
                              iVar36 = iVar26 + 10;
                              if (uVar32 - iVar36 != 0 && iVar36 <= (int)uVar32) {
                                GL_Upload16::trans[iVar36] =
                                     *(uint *)(data + 0x2fd) & 0xffffff |
                                     (uint)*(byte *)(height + iVar36) << 0x18;
                                iVar36 = iVar26 + 0xb;
                                if (uVar32 - iVar36 != 0 && iVar36 <= (int)uVar32) {
                                  GL_Upload16::trans[iVar36] =
                                       *(uint *)(data + 0x2fd) & 0xffffff |
                                       (uint)*(byte *)(height + iVar36) << 0x18;
                                  iVar36 = iVar26 + 0xc;
                                  if (uVar32 - iVar36 != 0 && iVar36 <= (int)uVar32) {
                                    GL_Upload16::trans[iVar36] =
                                         *(uint *)(data + 0x2fd) & 0xffffff |
                                         (uint)*(byte *)(height + iVar36) << 0x18;
                                    iVar36 = iVar26 + 0xd;
                                    if (uVar32 - iVar36 != 0 && iVar36 <= (int)uVar32) {
                                      GL_Upload16::trans[iVar36] =
                                           *(uint *)(data + 0x2fd) & 0xffffff |
                                           (uint)*(byte *)(height + iVar36) << 0x18;
                                      iVar26 = iVar26 + 0xe;
                                      if (uVar32 - iVar26 != 0 && iVar26 <= (int)uVar32) {
                                        GL_Upload16::trans[iVar26] =
                                             *(uint *)(data + 0x2fd) & 0xffffff |
                                             (uint)*(byte *)(height + iVar26) << 0x18;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        iVar26 = 3;
      }
      GL_Upload32(GL_Upload16::trans,textureType,width,true,iVar26,mipmap);
    }
  }
  else {
    Con_Printf("Can\'t upload (%ix%i) texture, it\'s > 640*480 bytes\n",textureType,width);
  }
  if (-1 < pgVar34->paletteIndex) {
                    /* WARNING: Read-only address (ram,0x00267f60) is written */
    return (pgVar34->paletteIndex + 1) * 0x10000 | pgVar34->texnum;
  }
  return pgVar34->texnum;
}


// GL_LoadTexture2  @ 0015fe00
int GL_LoadTexture2(char *identifier,GL_TEXTURETYPE textureType,int width,int height,byte *data,
                   qboolean mipmap,int iType,byte *pPal,int filter)

{
  char cVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  gltexture_t *pgVar13;
  gltexture_t *pgVar14;
  int iVar15;
  byte *pbVar16;
  int iVar17;
  int in_GS_OFFSET;
  uint local_4354;
  uint local_4350;
  int local_4328;
  uint local_4324;
  byte local_4320 [768];
  byte local_4020 [16384];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: gltexture_t * glt@[???]
                       Unresolved local var: gltexture_t * slot@[???]
                       Unresolved local var: BOOL mustRescale@[???] */
  pgVar13 = (gltexture_t *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  V_CheckGamma();
  cVar1 = *identifier;
  while (cVar1 != '\0') {
    if (numgltextures < 1) goto LAB_0015fe97;
    pgVar14 = gltextures;
    iVar15 = 0;
    iVar6 = numgltextures;
    while( true ) {
      while ((short)(pgVar14->servercount & -0x8000) != 0) {
        if (pgVar13 == (gltexture_t *)0x0) {
          pgVar13 = pgVar14;
        }
        iVar15 = iVar15 + 1;
        pgVar14 = pgVar14 + 1;
        if (iVar6 <= iVar15) goto LAB_0015fe97;
      }
      iVar6 = Q_strcmp(identifier,pgVar14->identifier);
      if (iVar6 == 0) break;
      iVar15 = iVar15 + 1;
      pgVar14 = pgVar14 + 1;
      iVar6 = numgltextures;
      if (numgltextures <= iVar15) goto LAB_0015fe97;
    }
    if ((pgVar14->width == width) && (pgVar14->height == height)) {
      if (0 < pgVar14->servercount) {
        pgVar14->servercount = (short)gHostSpawnCount;
      }
      if (pgVar14->paletteIndex < 0) {
        uVar10 = pgVar14->texnum;
      }
      else {
        uVar10 = (pgVar14->paletteIndex + 1) * 0x10000 | pgVar14->texnum;
      }
      goto LAB_00160061;
    }
    identifier[3] = identifier[3] + '\x01';
    cVar1 = *identifier;
  }
  Con_DPrintf("NULL Texture\n");
LAB_0015fe97:
  if (pgVar13 == (gltexture_t *)0x0) {
    iVar6 = numgltextures + 1;
    pgVar13 = gltextures + numgltextures;
    numgltextures = iVar6;
    if (9999 < iVar6) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Texture Overflow: MAX_GLTEXTURES");
    }
  }
  if (pgVar13->texnum == 0) {
                    /* Unresolved local var: GLuint tex@[???] */
    (*qglGenTextures)(1,&local_4324);
    pgVar13->texnum = local_4324;
  }
  Q_strncpy(pgVar13->identifier,identifier,0x3f);
  sVar2 = (short)gHostSpawnCount;
  pgVar13->identifier[0x3f] = '\0';
  pgVar13->paletteIndex = -1;
  pgVar13->width = width;
  pgVar13->height = height;
  pgVar13->mipmap = mipmap;
  sVar3 = 0;
  if (textureType == GLT_WORLD) {
    sVar3 = sVar2;
  }
  pgVar13->servercount = sVar3;
                    /* Unresolved local var: int paletteIndex@[???] */
  uVar10 = pgVar13->texnum & 0xffff;
  if (uVar10 != currenttexture) {
    iVar6 = (pgVar13->texnum >> 0x10) + -1;
    currenttexture = uVar10;
    (*qglBindTexture)(0xde1,uVar10);
    if (((-1 < iVar6) && (iVar6 != g_currentpalette)) &&
       (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
      g_currentpalette = iVar6;
      (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(iVar6 * 0x308 + 0xdfa368));
    }
  }
  currenttexture = -1;
                    /* Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: int max_size@[???] */
  if (g_bSupportsNPOTTextures == false) {
    ComputeScaledSize(&local_4328,(int *)&local_4324,width,height);
    iVar6 = local_4328;
    if ((width == local_4328) && (iVar6 = width, height == local_4324)) goto LAB_0015ffb0;
    if ((mipmap != false) || ((0x80 < iVar6 || (0x80 < (int)local_4324)))) goto LAB_0015ffd0;
    if (fs_perf_warnings.value != 0.0) {
      Con_DPrintf("fs_perf_warnings: resampling non-power-of-2 texture %s (%dx%d)\n",identifier,
                  width,height);
      iVar6 = local_4328;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uint ufrac@[???]
                       Unresolved local var: uint vfrac@[???]
                       Unresolved local var: uint ufracstep@[???]
                       Unresolved local var: uint vfracstep@[???]
                       Unresolved local var: byte * src@[???]
                       Unresolved local var: byte * dest@[???] */
    uVar10 = (width << 0x10) / iVar6;
    uVar9 = (height << 0x10) / (int)local_4324;
    local_4350 = uVar9 >> 2;
    if ((int)local_4324 < 1) {
      pbVar5 = local_4020;
    }
    else {
      local_4354 = 0;
      pbVar11 = local_4020;
      pbVar16 = data;
      do {
        if (0 < iVar6) {
          pbVar5 = pbVar11 + iVar6;
          uVar4 = uVar10 >> 2;
          pbVar12 = pbVar11;
          do {
            pbVar11 = pbVar12 + 1;
            uVar8 = uVar4 >> 0x10;
            uVar4 = uVar4 + uVar10;
            *pbVar12 = pbVar16[uVar8];
            pbVar12 = pbVar11;
          } while (pbVar11 != pbVar5);
        }
        local_4354 = local_4354 + 1;
        local_4350 = local_4350 + uVar9;
        pbVar16 = pbVar16 + (local_4350 >> 0x10) * width;
        local_4350 = local_4350 & 0xffff;
        pbVar5 = local_4020;
      } while (local_4354 != local_4324);
    }
  }
  else {
    local_4328 = width;
    local_4324 = height;
LAB_0015ffb0:
    pbVar5 = data;
    if (mipmap != false) goto LAB_0015ffd0;
  }
  if (((qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0) &&
      (gl_palette_tex.value != 0.0)) && (iType == 0)) {
    iVar6 = 0;
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int tag@[???]
                       Unresolved local var: int limit@[???]
                       Unresolved local var: byte[768] gammaPal@[???] */
      local_4320[iVar6] = texgammatable[pPal[iVar6]];
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0x300);
                    /* Unresolved local var: int tag@[???]
                       Unresolved local var: int i@[???] */
    uVar9 = (uint)local_4320[0];
    iVar6 = 1;
    uVar10 = uVar9;
    pbVar11 = local_4320 + 1;
    do {
      iVar6 = iVar6 + 2;
      uVar9 = uVar9 + *pbVar11 ^ uVar10;
      uVar10 = (uint)pbVar11[1];
      uVar9 = uVar9 + uVar10 ^ (uint)*pbVar11;
      pbVar11 = pbVar11 + 2;
    } while (iVar6 != 0x2ff);
    pbVar11 = local_4320 + 0x2ff;
    do {
      pbVar12 = pbVar11 + 1;
      uVar9 = uVar9 + *pbVar11 ^ (uint)pbVar11[-1];
      pbVar11 = pbVar12;
    } while (local_4020 != pbVar12);
    iVar15 = 0;
    iVar17 = (uVar9 ^ (int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f);
    iVar6 = 0;
    do {
      if (*(int *)(gGLPalette[0].colors + iVar6 + -8) < 0) {
        Q_memcpy(gGLPalette[iVar15].colors,local_4320,0x300);
        gGLPalette[iVar15].referenceCount = 1;
        gGLPalette[iVar15].tag = iVar17;
LAB_00160355:
        pgVar13->paletteIndex = (short)iVar15;
        (*qglTexImage2D)(0xde1,0,0x80e5,local_4328,local_4324,0,0x1900,0x1401,pbVar5);
        (*qglTexParameterf)(0xde1,0x2801,(float)filter);
        (*qglTexParameterf)(0xde1,0x2800,(float)filter);
        (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
        iVar6 = (int)pgVar13->paletteIndex;
        if (-1 < iVar6) goto LAB_00160059;
        uVar10 = pgVar13->texnum;
        goto LAB_00160061;
      }
                    /* Unresolved local var: int i@[???] */
      if (*(int *)(gGLPalette[0].colors + iVar6 + -8) == iVar17) {
        iVar7 = 0;
                    /* Unresolved local var: int i@[???] */
        while (local_4320[iVar7] == *(byte *)(iVar6 + 0xdfa368 + iVar7)) {
          iVar7 = iVar7 + 1;
          if (iVar7 == 0x300) {
            gGLPalette[iVar15].referenceCount = gGLPalette[iVar15].referenceCount + 1;
            goto LAB_00160355;
          }
        }
      }
      iVar15 = iVar15 + 1;
      iVar6 = iVar6 + 0x308;
    } while (iVar15 != 0x158);
    pgVar13->paletteIndex = -1;
  }
LAB_0015ffd0:
  if (g_modfuncs.m_pfnTextureLoad != (PFN_TEXTURELOAD)0x0) {
    (*g_modfuncs.m_pfnTextureLoad)(identifier,width,height,(char *)data);
  }
  if ((textureType == GLT_SPRITE) && (iType == 4)) {
    GL_Upload32((uint *)data,width,height,mipmap,4,filter);
    sVar2 = pgVar13->paletteIndex;
  }
  else {
    GL_Upload16(data,width,height,mipmap,iType,pPal,filter);
    sVar2 = pgVar13->paletteIndex;
  }
  iVar6 = (int)sVar2;
  if (iVar6 < 0) {
    uVar10 = pgVar13->texnum;
  }
  else {
LAB_00160059:
    uVar10 = (iVar6 + 1) * 0x10000 | pgVar13->texnum;
  }
LAB_00160061:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}


// GL_MakeAliasModelDisplayLists  @ 001831d0
void GL_MakeAliasModelDisplayLists(model_t *m,aliashdr_t *hdr)

{
  int *piVar1;
  aliashdr_t *paVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  FileHandle_t pvVar7;
  void *dest;
  trivertx_t *ptVar8;
  trivertx_t *ptVar9;
  uint *puVar10;
  uint *puVar11;
  int iVar12;
  int in_GS_OFFSET;
  uint local_154 [15];
  char acStack_115 [261];
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int * cmds@[???]
                       Unresolved local var: trivertx_t * verts@[???]
                       Unresolved local var: char[64] cache@[???]
                       Unresolved local var: char[260] fullpath@[???]
                       Unresolved local var: FileHandle_t f@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  aliasmodel = m;
  paliashdr = hdr;
  Q_strcpy((char *)local_154,"glquake/");
  iVar3 = Q_strlen("glquake/");
  iVar4 = Q_strlen("progs/");
  COM_StripExtension(m->name + iVar4,(char *)(iVar3 + (int)local_154));
  puVar11 = local_154;
  do {
    puVar10 = puVar11;
    uVar5 = *puVar10 + 0xfefefeff & ~*puVar10;
    uVar6 = uVar5 & 0x80808080;
    puVar11 = puVar10 + 1;
  } while (uVar6 == 0);
  if ((uVar5 & 0x8080) == 0) {
    puVar11 = (uint *)((int)puVar10 + 6);
    uVar6 = uVar6 >> 0x10;
  }
  __strncat_chk(local_154,&DAT_0026c9b2,
                acStack_115 + -(int)((int)puVar11 + (-3 - (uint)CARRY1((byte)uVar6,(byte)uVar6))),
                0x40);
  pvVar7 = FS_Open((char *)local_154,"rb");
  if (pvVar7 == (FileHandle_t)0x0) {
    Con_Printf("meshing %s...\n",m);
    BuildTris();
    snprintf(acStack_115 + 1,0x104,"%s",local_154);
    pvVar7 = FS_Open(acStack_115 + 1,"wb");
    if (pvVar7 != (FileHandle_t)0x0) {
      FS_Write(&numcommands,4,1,pvVar7);
      FS_Write(&numorder,4,1,pvVar7);
      FS_Write(commands,numcommands << 2,1,pvVar7);
      FS_Write(vertexorder,numorder << 2,1,pvVar7);
      FS_Close(pvVar7);
    }
  }
  else {
    FS_Read(&numcommands,4,1,pvVar7);
    if (0x8000 < (uint)(numcommands * 4)) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("GL_MakeAliasModelDisplayLists: num commands (%d) too large",numcommands);
    }
    FS_Read(&numorder,4,1,pvVar7);
    if (0x8000 < (uint)(numorder * 4)) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("GL_MakeAliasModelDisplayLists: num orders (%d) too large",numorder);
    }
    FS_Read(commands,numcommands << 2,1,pvVar7);
    FS_Read(vertexorder,numorder << 2,1,pvVar7);
    FS_Close(pvVar7);
  }
  paliashdr->poseverts = numorder;
  dest = Hunk_Alloc(numcommands << 2);
  iVar3 = numcommands;
  paliashdr->commands = (int)dest - (int)paliashdr;
  Q_memcpy(dest,commands,iVar3 * 4);
  ptVar8 = Hunk_Alloc(paliashdr->numposes * paliashdr->poseverts * 4);
  paVar2 = paliashdr;
  paliashdr->posedata = (int)ptVar8 - (int)paliashdr;
  iVar3 = paVar2->numposes;
  if (0 < iVar3) {
    iVar12 = 0;
    iVar4 = numorder;
    do {
      if (0 < iVar4) {
        iVar3 = 0;
        ptVar9 = ptVar8;
        do {
          piVar1 = vertexorder + iVar3;
          ptVar8 = ptVar9 + 1;
          iVar3 = iVar3 + 1;
          *ptVar9 = poseverts[iVar12][*piVar1];
          ptVar9 = ptVar8;
        } while (iVar3 < numorder);
        iVar3 = paliashdr->numposes;
        iVar4 = numorder;
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < iVar3);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// GL_MipMap  @ 0015d050
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GL_MipMap(byte *in,int width,int height)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  short sVar18;
  short sVar19;
  short sVar20;
  short sVar21;
  short sVar22;
  short sVar23;
  short sVar24;
  short sVar25;
  short sVar26;
  short sVar27;
  short sVar28;
  short sVar29;
  short sVar30;
  short sVar31;
  short sVar32;
  short sVar33;
  short sVar34;
  short sVar35;
  short sVar36;
  short sVar37;
  short sVar38;
  short sVar39;
  short sVar40;
  short sVar41;
  short sVar42;
  short sVar43;
  short sVar44;
  short sVar45;
  short sVar46;
  short sVar47;
  short sVar48;
  short sVar49;
  short sVar50;
  short sVar51;
  short sVar52;
  short sVar53;
  short sVar54;
  short sVar55;
  short sVar56;
  short sVar57;
  short sVar58;
  short sVar59;
  short sVar60;
  short sVar61;
  byte bVar62;
  byte bVar78;
  byte bVar86;
  byte bVar94;
  byte bVar98;
  byte bVar106;
  byte bVar114;
  byte bVar122;
  byte bVar135;
  byte bVar138;
  byte bVar140;
  byte bVar143;
  char cVar145;
  char cVar146;
  char cVar149;
  char cVar152;
  char cVar155;
  char cVar162;
  char cVar166;
  char cVar173;
  char cVar180;
  char cVar187;
  char cVar194;
  char cVar201;
  char cVar207;
  byte bVar214;
  byte bVar229;
  byte bVar230;
  byte bVar231;
  byte bVar247;
  byte bVar248;
  byte bVar249;
  byte bVar251;
  undefined1 auVar252 [15];
  undefined1 auVar253 [15];
  undefined1 auVar254 [15];
  undefined1 auVar255 [15];
  undefined1 auVar256 [14];
  undefined1 auVar257 [14];
  undefined1 auVar258 [14];
  undefined1 auVar259 [15];
  undefined1 auVar260 [15];
  undefined1 auVar261 [15];
  undefined1 auVar262 [14];
  undefined1 auVar263 [14];
  undefined1 auVar264 [14];
  undefined1 auVar265 [14];
  undefined1 auVar266 [15];
  undefined1 auVar267 [15];
  undefined1 auVar268 [15];
  undefined1 auVar269 [14];
  undefined1 auVar270 [14];
  undefined1 auVar271 [14];
  undefined1 auVar272 [14];
  undefined1 auVar273 [15];
  undefined1 auVar274 [15];
  undefined1 auVar275 [15];
  undefined1 auVar276 [14];
  undefined1 auVar277 [14];
  undefined1 auVar278 [14];
  undefined1 auVar279 [14];
  undefined1 auVar280 [14];
  undefined1 auVar281 [15];
  undefined1 auVar282 [15];
  undefined1 auVar283 [15];
  undefined1 auVar284 [15];
  undefined1 auVar285 [15];
  undefined1 auVar286 [15];
  undefined1 auVar287 [15];
  undefined1 auVar288 [15];
  undefined1 auVar289 [15];
  undefined1 auVar290 [15];
  undefined1 auVar291 [15];
  undefined1 auVar292 [15];
  undefined1 auVar293 [15];
  undefined1 auVar294 [15];
  undefined1 auVar295 [15];
  undefined1 auVar296 [15];
  uint uVar297;
  uint uVar298;
  uint uVar299;
  uint uVar300;
  undefined1 auVar301 [14];
  undefined1 auVar302 [14];
  undefined1 auVar303 [14];
  undefined1 auVar304 [14];
  undefined1 auVar305 [13];
  undefined1 auVar306 [13];
  undefined1 auVar307 [13];
  undefined1 auVar308 [13];
  undefined1 auVar309 [13];
  undefined1 auVar310 [13];
  undefined1 auVar311 [15];
  undefined1 auVar312 [14];
  undefined1 auVar313 [14];
  undefined1 auVar314 [14];
  undefined1 auVar315 [14];
  undefined1 auVar316 [14];
  undefined1 auVar317 [14];
  undefined1 auVar318 [14];
  undefined1 auVar319 [14];
  undefined1 auVar320 [15];
  undefined1 auVar321 [14];
  undefined1 auVar322 [14];
  undefined1 auVar323 [14];
  undefined1 auVar324 [14];
  undefined1 auVar325 [14];
  undefined1 auVar326 [14];
  undefined1 auVar327 [14];
  undefined1 auVar328 [14];
  undefined1 auVar329 [15];
  undefined1 auVar330 [14];
  undefined1 auVar331 [14];
  undefined1 auVar332 [14];
  undefined1 auVar333 [14];
  undefined1 auVar334 [14];
  undefined1 auVar335 [14];
  undefined1 auVar336 [14];
  undefined1 auVar337 [14];
  undefined1 auVar338 [15];
  undefined1 auVar339 [15];
  undefined1 auVar340 [15];
  undefined1 auVar341 [15];
  undefined1 auVar342 [15];
  undefined1 auVar343 [15];
  undefined1 auVar344 [15];
  undefined1 auVar345 [15];
  undefined1 auVar346 [15];
  undefined1 auVar347 [15];
  undefined1 auVar348 [15];
  undefined1 auVar349 [15];
  undefined1 auVar350 [15];
  undefined1 auVar351 [15];
  undefined1 auVar352 [15];
  undefined1 auVar353 [15];
  undefined1 auVar354 [15];
  undefined1 auVar355 [15];
  undefined1 auVar356 [15];
  undefined1 auVar357 [15];
  undefined1 auVar358 [15];
  undefined1 auVar359 [15];
  undefined1 auVar360 [15];
  undefined1 auVar361 [15];
  undefined1 auVar362 [15];
  undefined1 auVar363 [15];
  undefined1 auVar364 [15];
  undefined1 auVar365 [15];
  undefined1 auVar366 [15];
  undefined1 auVar367 [15];
  undefined1 auVar368 [15];
  undefined1 auVar369 [15];
  unkbyte10 Var370;
  undefined1 auVar371 [12];
  undefined1 auVar372 [14];
  undefined1 auVar373 [12];
  undefined1 auVar374 [14];
  undefined1 auVar375 [12];
  undefined1 auVar376 [14];
  undefined1 auVar377 [12];
  undefined1 auVar378 [14];
  undefined1 auVar379 [12];
  undefined1 auVar380 [14];
  undefined1 auVar381 [12];
  undefined1 auVar382 [14];
  undefined1 auVar383 [12];
  undefined1 auVar384 [14];
  undefined1 auVar385 [12];
  undefined1 auVar386 [14];
  undefined1 auVar387 [16];
  undefined1 auVar388 [12];
  undefined1 auVar389 [14];
  undefined1 auVar390 [15];
  unkuint9 Var391;
  undefined1 auVar392 [11];
  undefined1 auVar393 [13];
  undefined1 auVar394 [15];
  unkuint9 Var395;
  undefined1 auVar396 [11];
  undefined1 auVar397 [13];
  undefined5 uVar398;
  undefined5 uVar399;
  undefined1 auVar400 [15];
  unkuint9 Var401;
  undefined1 auVar402 [11];
  undefined1 auVar403 [13];
  undefined1 auVar404 [15];
  unkuint9 Var405;
  undefined1 auVar406 [11];
  undefined1 auVar407 [13];
  undefined1 auVar408 [14];
  undefined1 auVar409 [14];
  undefined1 auVar410 [14];
  undefined1 auVar411 [14];
  undefined1 auVar412 [16];
  undefined1 auVar413 [16];
  undefined1 auVar414 [16];
  undefined1 auVar415 [13];
  undefined1 auVar416 [13];
  undefined1 auVar417 [16];
  undefined1 auVar418 [15];
  undefined1 auVar419 [11];
  undefined1 auVar420 [13];
  undefined1 auVar421 [15];
  undefined1 auVar422 [11];
  undefined1 auVar423 [15];
  undefined1 auVar424 [11];
  undefined1 auVar425 [15];
  undefined1 auVar426 [11];
  undefined1 auVar427 [14];
  undefined1 auVar428 [14];
  undefined1 auVar429 [14];
  undefined1 auVar430 [14];
  undefined1 auVar431 [16];
  undefined1 auVar432 [16];
  undefined1 auVar433 [15];
  undefined1 auVar434 [11];
  undefined1 auVar435 [13];
  undefined1 auVar436 [15];
  undefined1 auVar437 [11];
  undefined1 auVar438 [15];
  undefined1 auVar439 [11];
  undefined1 auVar440 [15];
  undefined1 auVar441 [11];
  undefined1 auVar442 [14];
  undefined1 auVar443 [14];
  undefined1 auVar444 [14];
  undefined1 auVar445 [14];
  undefined1 auVar446 [16];
  undefined1 auVar447 [16];
  undefined1 auVar448 [15];
  undefined1 auVar449 [11];
  undefined1 auVar450 [15];
  undefined1 auVar451 [11];
  undefined1 auVar452 [15];
  undefined1 auVar453 [11];
  undefined1 auVar454 [15];
  undefined1 auVar455 [11];
  undefined1 auVar456 [13];
  undefined1 auVar457 [14];
  undefined1 auVar458 [14];
  undefined1 auVar459 [14];
  undefined1 auVar460 [14];
  undefined1 auVar461 [16];
  undefined1 auVar462 [16];
  undefined1 auVar463 [16];
  undefined3 uVar464;
  undefined3 uVar465;
  undefined1 auVar466 [15];
  undefined1 auVar467 [15];
  undefined1 auVar468 [15];
  undefined1 auVar469 [15];
  undefined1 auVar470 [15];
  undefined1 auVar471 [15];
  undefined1 auVar472 [15];
  undefined1 auVar473 [15];
  undefined1 auVar474 [15];
  undefined1 auVar475 [15];
  undefined1 auVar476 [15];
  undefined1 auVar477 [15];
  undefined1 auVar478 [15];
  undefined1 auVar479 [15];
  undefined1 auVar480 [15];
  undefined1 auVar481 [15];
  undefined1 auVar482 [15];
  undefined1 auVar483 [15];
  undefined1 auVar484 [15];
  undefined1 auVar485 [15];
  undefined1 auVar486 [15];
  undefined1 auVar487 [15];
  undefined1 auVar488 [15];
  undefined1 auVar489 [15];
  undefined1 auVar490 [15];
  undefined1 auVar491 [15];
  undefined1 auVar492 [15];
  undefined1 auVar493 [15];
  undefined1 auVar494 [15];
  undefined1 auVar495 [15];
  undefined1 auVar496 [15];
  undefined1 auVar497 [15];
  undefined1 auVar498 [12];
  undefined8 uVar499;
  undefined1 auVar500 [12];
  undefined8 uVar501;
  undefined1 auVar502 [12];
  undefined1 auVar503 [12];
  undefined1 auVar504 [13];
  undefined1 auVar505 [13];
  undefined1 auVar506 [13];
  undefined1 auVar507 [13];
  undefined1 auVar508 [13];
  undefined1 auVar509 [13];
  undefined1 auVar510 [13];
  undefined1 auVar511 [13];
  undefined1 auVar512 [13];
  undefined1 auVar513 [13];
  undefined1 auVar514 [13];
  undefined1 auVar515 [13];
  undefined1 auVar516 [13];
  undefined1 auVar517 [13];
  undefined1 auVar518 [13];
  undefined1 auVar519 [13];
  undefined1 auVar520 [13];
  undefined1 auVar521 [13];
  undefined1 auVar522 [13];
  undefined1 auVar523 [13];
  undefined1 auVar524 [13];
  undefined1 auVar525 [13];
  undefined1 auVar526 [13];
  undefined1 auVar527 [13];
  undefined1 auVar528 [13];
  undefined1 auVar529 [13];
  undefined1 auVar530 [13];
  undefined1 auVar531 [13];
  undefined1 auVar532 [14];
  undefined1 auVar533 [14];
  undefined1 auVar534 [14];
  undefined1 auVar535 [14];
  uint6 uVar536;
  uint6 uVar537;
  uint6 uVar538;
  uint6 uVar539;
  undefined1 auVar540 [13];
  undefined1 auVar541 [13];
  undefined1 auVar542 [13];
  undefined1 auVar543 [13];
  undefined1 auVar544 [13];
  undefined1 auVar545 [13];
  undefined1 auVar546 [13];
  undefined1 auVar547 [13];
  undefined1 auVar548 [13];
  undefined3 uVar549;
  undefined3 uVar550;
  undefined3 uVar551;
  undefined5 uVar552;
  undefined5 uVar553;
  undefined5 uVar554;
  undefined1 auVar555 [12];
  undefined1 auVar556 [12];
  undefined1 auVar557 [12];
  undefined1 auVar558 [12];
  undefined1 auVar559 [12];
  undefined1 auVar560 [12];
  undefined1 auVar561 [12];
  undefined1 auVar562 [12];
  undefined1 auVar563 [12];
  undefined1 auVar564 [12];
  undefined1 auVar565 [12];
  undefined1 auVar566 [12];
  undefined1 auVar567 [14];
  undefined1 auVar568 [14];
  undefined1 auVar569 [14];
  undefined1 auVar570 [14];
  undefined1 auVar571 [14];
  undefined1 auVar572 [14];
  undefined1 auVar573 [14];
  undefined1 auVar574 [14];
  undefined1 auVar575 [14];
  undefined1 auVar576 [14];
  undefined1 auVar577 [14];
  undefined1 auVar578 [14];
  undefined1 auVar579 [12];
  undefined1 auVar580 [12];
  undefined1 auVar581 [12];
  undefined1 auVar582 [12];
  undefined1 *puVar583;
  uint uVar584;
  undefined1 (*pauVar585) [16];
  undefined1 (*pauVar586) [16];
  undefined1 (*pauVar587) [16];
  uint uVar588;
  undefined1 (*pauVar589) [16];
  undefined1 (*pauVar590) [16];
  undefined1 (*pauVar591) [16];
  undefined4 uVar592;
  uint uVar641;
  undefined1 auVar605 [16];
  undefined1 auVar607 [16];
  undefined4 uVar593;
  undefined4 uVar594;
  uint uVar595;
  undefined1 auVar610 [16];
  undefined1 auVar612 [16];
  undefined1 auVar616 [16];
  undefined1 auVar619 [16];
  uint uVar642;
  undefined1 auVar620 [16];
  undefined1 auVar622 [16];
  undefined1 auVar626 [16];
  undefined1 auVar629 [16];
  uint uVar643;
  undefined1 auVar630 [16];
  undefined1 auVar632 [16];
  undefined1 auVar636 [16];
  undefined1 auVar639 [16];
  ushort uVar644;
  undefined4 uVar645;
  undefined8 uVar649;
  undefined1 auVar652 [12];
  ushort uVar683;
  ushort uVar684;
  ushort uVar685;
  ushort uVar686;
  ushort uVar689;
  ushort uVar690;
  ushort uVar692;
  undefined1 auVar656 [16];
  undefined1 auVar658 [16];
  undefined1 auVar659 [16];
  uint uVar646;
  undefined1 auVar660 [16];
  undefined1 auVar661 [16];
  ushort uVar691;
  undefined1 auVar663 [16];
  int iVar687;
  uint uVar688;
  undefined1 auVar664 [16];
  undefined1 auVar666 [16];
  undefined1 auVar670 [16];
  undefined1 auVar673 [16];
  undefined1 auVar674 [16];
  undefined1 auVar676 [16];
  undefined1 auVar677 [16];
  undefined1 auVar679 [16];
  undefined1 auVar680 [16];
  undefined1 auVar682 [16];
  ushort uVar693;
  ushort uVar694;
  ushort uVar695;
  ushort uVar696;
  ushort uVar716;
  undefined4 uVar697;
  ushort uVar717;
  undefined4 uVar698;
  uint uVar699;
  int iVar700;
  short sVar718;
  ushort uVar719;
  undefined2 uVar723;
  int iVar724;
  ushort uVar725;
  ushort uVar727;
  undefined2 uVar731;
  ushort uVar733;
  undefined1 auVar705 [12];
  ushort uVar720;
  ushort uVar721;
  ushort uVar722;
  ushort uVar726;
  ushort uVar728;
  ushort uVar729;
  ushort uVar730;
  ushort uVar734;
  undefined1 auVar707 [12];
  int iVar732;
  ushort uVar735;
  ushort uVar736;
  ushort uVar737;
  ushort uVar738;
  ushort uVar739;
  ushort uVar740;
  ushort uVar741;
  ushort uVar742;
  ushort uVar743;
  ushort uVar746;
  ushort uVar747;
  uint uVar744;
  ushort uVar748;
  ushort uVar749;
  ushort uVar750;
  ushort uVar751;
  ushort uVar752;
  ushort uVar753;
  ushort uVar754;
  ushort uVar755;
  ushort uVar756;
  ushort uVar757;
  ushort uVar758;
  ushort uVar759;
  ushort uVar760;
  ushort uVar761;
  ushort uVar762;
  ushort uVar763;
  ushort uVar764;
  ushort uVar765;
  undefined1 auVar745 [16];
  short sVar777;
  short sVar778;
  short sVar779;
  undefined6 uVar766;
  undefined8 uVar767;
  ushort uVar780;
  ushort uVar781;
  undefined1 auVar774 [16];
  undefined1 auVar776 [16];
  ushort uVar782;
  ushort uVar783;
  ushort uVar788;
  ushort uVar789;
  ushort uVar790;
  ushort uVar791;
  ushort uVar792;
  ushort uVar793;
  ushort uVar794;
  ushort uVar795;
  ushort uVar796;
  ushort uVar798;
  ushort uVar799;
  ushort uVar800;
  ushort uVar802;
  ushort uVar803;
  undefined1 auVar784 [16];
  undefined1 auVar785 [16];
  undefined1 auVar786 [16];
  ushort uVar797;
  ushort uVar801;
  ushort uVar804;
  undefined1 auVar787 [16];
  ushort uVar805;
  ushort uVar806;
  undefined6 uVar807;
  undefined1 auVar809 [12];
  ushort uVar819;
  ushort uVar823;
  undefined1 auVar811 [12];
  ushort uVar820;
  ushort uVar821;
  ushort uVar822;
  ushort uVar824;
  ushort uVar825;
  ushort uVar826;
  ushort uVar827;
  undefined1 auVar815 [16];
  ushort uVar828;
  int local_168;
  short local_15c;
  short sStack_15a;
  short sStack_158;
  short sStack_156;
  short sStack_154;
  short sStack_152;
  short sStack_150;
  short sStack_14e;
  undefined1 local_13c [16];
  undefined1 local_12c [16];
  undefined1 local_10c [16];
  undefined1 local_fc [16];
  char cStack_97;
  undefined1 uStack_96;
  char cStack_95;
  undefined1 uStack_94;
  char cStack_93;
  undefined1 uStack_92;
  char cStack_91;
  undefined1 uStack_90;
  char cStack_8f;
  undefined1 uStack_8e;
  char cStack_8d;
  char cStack_87;
  undefined1 uStack_86;
  char cStack_85;
  undefined1 uStack_84;
  char cStack_83;
  undefined1 uStack_82;
  char cStack_81;
  undefined1 uStack_80;
  char cStack_7f;
  undefined1 uStack_7e;
  char cStack_7d;
  byte bVar63;
  byte bVar64;
  byte bVar65;
  byte bVar66;
  byte bVar67;
  byte bVar68;
  byte bVar69;
  byte bVar70;
  byte bVar71;
  byte bVar72;
  byte bVar73;
  byte bVar74;
  byte bVar75;
  byte bVar76;
  byte bVar77;
  char cVar79;
  char cVar80;
  char cVar81;
  char cVar82;
  char cVar83;
  char cVar84;
  char cVar85;
  char cVar87;
  char cVar88;
  char cVar89;
  char cVar90;
  char cVar91;
  char cVar92;
  char cVar93;
  char cVar95;
  char cVar96;
  char cVar97;
  char cVar99;
  char cVar100;
  char cVar101;
  char cVar102;
  char cVar103;
  char cVar104;
  char cVar105;
  char cVar107;
  char cVar108;
  char cVar109;
  char cVar110;
  char cVar111;
  char cVar112;
  char cVar113;
  char cVar115;
  char cVar116;
  char cVar117;
  char cVar118;
  char cVar119;
  char cVar120;
  char cVar121;
  byte bVar123;
  byte bVar124;
  byte bVar125;
  byte bVar126;
  byte bVar127;
  byte bVar128;
  byte bVar129;
  byte bVar130;
  byte bVar131;
  byte bVar132;
  byte bVar133;
  byte bVar134;
  byte bVar136;
  byte bVar137;
  byte bVar139;
  byte bVar141;
  byte bVar142;
  byte bVar144;
  char cVar147;
  char cVar148;
  char cVar150;
  char cVar151;
  char cVar153;
  char cVar154;
  char cVar156;
  char cVar157;
  char cVar158;
  char cVar159;
  char cVar160;
  char cVar161;
  char cVar163;
  char cVar164;
  char cVar165;
  char cVar167;
  char cVar168;
  char cVar169;
  char cVar170;
  char cVar171;
  char cVar172;
  char cVar174;
  char cVar175;
  char cVar176;
  char cVar177;
  char cVar178;
  char cVar179;
  char cVar181;
  char cVar182;
  char cVar183;
  char cVar184;
  char cVar185;
  char cVar186;
  char cVar188;
  char cVar189;
  char cVar190;
  char cVar191;
  char cVar192;
  char cVar193;
  char cVar195;
  char cVar196;
  char cVar197;
  char cVar198;
  char cVar199;
  char cVar200;
  char cVar202;
  char cVar203;
  char cVar204;
  char cVar205;
  char cVar206;
  char cVar208;
  char cVar209;
  char cVar210;
  char cVar211;
  char cVar212;
  char cVar213;
  byte bVar215;
  byte bVar216;
  byte bVar217;
  byte bVar218;
  byte bVar219;
  byte bVar220;
  byte bVar221;
  byte bVar222;
  byte bVar223;
  byte bVar224;
  byte bVar225;
  byte bVar226;
  byte bVar227;
  byte bVar228;
  byte bVar232;
  byte bVar233;
  byte bVar234;
  byte bVar235;
  byte bVar236;
  byte bVar237;
  byte bVar238;
  byte bVar239;
  byte bVar240;
  byte bVar241;
  byte bVar242;
  byte bVar243;
  byte bVar244;
  byte bVar245;
  byte bVar246;
  byte bVar250;
  undefined6 uVar596;
  undefined8 uVar597;
  undefined8 uVar598;
  undefined1 auVar599 [12];
  undefined1 auVar600 [12];
  undefined1 auVar601 [12];
  undefined1 auVar613 [16];
  undefined1 auVar614 [16];
  undefined1 auVar617 [16];
  undefined1 auVar623 [16];
  undefined1 auVar624 [16];
  undefined1 auVar627 [16];
  undefined1 auVar633 [16];
  undefined1 auVar634 [16];
  undefined1 auVar637 [16];
  undefined1 auVar602 [14];
  undefined1 auVar603 [14];
  undefined1 auVar604 [14];
  undefined1 auVar615 [16];
  undefined1 auVar618 [16];
  undefined1 auVar625 [16];
  undefined1 auVar628 [16];
  undefined1 auVar635 [16];
  undefined1 auVar638 [16];
  undefined1 auVar606 [16];
  undefined1 auVar608 [16];
  undefined1 auVar609 [16];
  undefined1 auVar611 [16];
  undefined1 auVar621 [16];
  undefined1 auVar631 [16];
  undefined2 uVar640;
  undefined6 uVar647;
  undefined8 uVar648;
  undefined1 auVar650 [12];
  undefined1 auVar651 [12];
  undefined1 auVar667 [16];
  undefined1 auVar668 [16];
  undefined1 auVar671 [16];
  undefined1 auVar653 [14];
  undefined1 auVar654 [14];
  undefined1 auVar655 [14];
  undefined1 auVar669 [16];
  undefined1 auVar672 [16];
  undefined1 auVar675 [16];
  undefined1 auVar678 [16];
  undefined1 auVar681 [16];
  undefined1 auVar657 [16];
  undefined1 auVar662 [16];
  undefined1 auVar665 [16];
  undefined6 uVar701;
  undefined8 uVar702;
  undefined8 uVar703;
  undefined1 auVar704 [12];
  undefined1 auVar706 [12];
  undefined1 auVar708 [14];
  undefined1 auVar709 [14];
  undefined1 auVar710 [14];
  undefined1 auVar711 [14];
  undefined1 auVar712 [16];
  undefined1 auVar713 [16];
  undefined1 auVar714 [16];
  undefined1 auVar715 [16];
  undefined1 auVar768 [12];
  undefined1 auVar769 [12];
  undefined1 auVar770 [14];
  undefined1 auVar771 [14];
  undefined1 auVar775 [16];
  undefined1 auVar772 [16];
  undefined1 auVar773 [16];
  undefined8 uVar808;
  undefined1 auVar810 [12];
  undefined1 auVar812 [14];
  undefined1 auVar813 [14];
  undefined1 auVar814 [14];
  undefined1 auVar816 [16];
  undefined1 auVar817 [16];
  undefined1 auVar818 [16];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: byte * out@[???] */
  iVar2 = width * 4;
  if (0 < height >> 1) {
    uVar584 = iVar2 - 1U >> 3;
    iVar3 = uVar584 * 8 + 8;
    uVar1 = (uVar584 - 0xf >> 4) + 1;
    local_168 = 0;
    pauVar590 = (undefined1 (*) [16])in;
    do {
      pauVar589 = (undefined1 (*) [16])in;
      pauVar591 = pauVar590;
      if (0 < iVar2) {
        pauVar587 = (undefined1 (*) [16])(*(undefined1 (*) [16])in + iVar2);
        pauVar591 = (undefined1 (*) [16])(*pauVar590 + uVar584 * 4 + 4);
        pauVar589 = (undefined1 (*) [16])(*(undefined1 (*) [16])in + iVar3);
        if ((pauVar590 < (undefined1 (*) [16])(*(undefined1 (*) [16])in + iVar3 + iVar2) &&
             pauVar587 < pauVar591 || pauVar590 < pauVar589 && in < pauVar591) ||
           (uVar584 + 1 < 0x10)) {
          pauVar585 = (undefined1 (*) [16])in;
          do {
            puVar583 = *pauVar587;
            (*pauVar590)[0] =
                 (char)((int)((uint)(byte)(*pauVar587)[4] +
                             (uint)(byte)(*pauVar585)[0] + (uint)(byte)(*pauVar585)[4] +
                             (uint)(byte)(*pauVar587)[0]) >> 2);
            (*pauVar590)[1] =
                 (char)((int)((uint)(byte)(*pauVar587)[5] +
                             (uint)(byte)(*pauVar585)[1] + (uint)(byte)(*pauVar585)[5] +
                             (uint)(byte)(*pauVar587)[1]) >> 2);
            (*pauVar590)[2] =
                 (char)((int)((uint)(byte)(*pauVar587)[6] +
                             (uint)(byte)(*pauVar585)[2] + (uint)(byte)(*pauVar585)[6] +
                             (uint)(byte)(*pauVar587)[2]) >> 2);
            (*pauVar590)[3] =
                 (char)((int)((uint)(byte)(*pauVar587)[7] +
                             (uint)(byte)(*pauVar585)[3] + (uint)(byte)(*pauVar585)[7] +
                             (uint)(byte)(*pauVar587)[3]) >> 2);
            pauVar587 = (undefined1 (*) [16])(puVar583 + 8);
            pauVar585 = (undefined1 (*) [16])(*pauVar585 + 8);
            pauVar590 = (undefined1 (*) [16])(*pauVar590 + 4);
          } while ((undefined1 (*) [16])(*(undefined1 (*) [16])in + iVar2 + 8 + uVar584 * 8) !=
                   (undefined1 (*) [16])(puVar583 + 8));
        }
        else {
          if (iVar2 - 1U < 0x78) {
            iVar687 = 0;
          }
          else {
            uVar588 = 0;
            pauVar585 = (undefined1 (*) [16])in;
            pauVar586 = pauVar590;
            do {
              auVar658 = *pauVar585;
              auVar607 = pauVar585[1];
              auVar371 = *(undefined1 (*) [12])pauVar585[5];
              uVar593 = *(undefined4 *)(pauVar585[5] + 0xc);
              auVar605 = _DAT_00267f50 & auVar607;
              auVar373 = *(undefined1 (*) [12])pauVar585[7];
              uVar594 = *(undefined4 *)(pauVar585[7] + 0xc);
              uVar693 = auVar607._0_2_ >> 8;
              uVar716 = auVar607._2_2_ >> 8;
              uVar719 = auVar607._4_2_ >> 8;
              uVar725 = auVar607._6_2_ >> 8;
              uVar727 = auVar607._8_2_ >> 8;
              uVar733 = auVar607._10_2_ >> 8;
              uVar735 = auVar607._12_2_ >> 8;
              uVar739 = auVar607._14_2_ >> 8;
              auVar815 = _DAT_00267f50 & auVar658;
              uVar740 = auVar658._0_2_ >> 8;
              uVar746 = auVar658._2_2_ >> 8;
              uVar748 = auVar658._4_2_ >> 8;
              uVar752 = auVar658._6_2_ >> 8;
              uVar754 = auVar658._8_2_ >> 8;
              uVar758 = auVar658._10_2_ >> 8;
              uVar760 = auVar658._12_2_ >> 8;
              uVar764 = auVar658._14_2_ >> 8;
              auVar656 = pauVar585[2];
              auVar375 = *(undefined1 (*) [12])pauVar585[3];
              uVar645 = *(undefined4 *)(pauVar585[3] + 0xc);
              auVar377 = *(undefined1 (*) [12])pauVar585[4];
              uVar698 = *(undefined4 *)(pauVar585[4] + 0xc);
              sVar718 = auVar815._0_2_;
              bVar62 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[0] - (0xff < sVar718);
              sVar718 = auVar815._2_2_;
              bVar63 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[2] - (0xff < sVar718);
              sVar718 = auVar815._4_2_;
              bVar64 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[4] - (0xff < sVar718);
              sVar718 = auVar815._6_2_;
              bVar65 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[6] - (0xff < sVar718);
              sVar718 = auVar815._8_2_;
              bVar66 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[8] - (0xff < sVar718);
              sVar718 = auVar815._10_2_;
              bVar67 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[10] - (0xff < sVar718);
              sVar718 = auVar815._12_2_;
              bVar68 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[0xc] - (0xff < sVar718);
              sVar718 = auVar815._14_2_;
              bVar69 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[0xe] - (0xff < sVar718);
              sVar718 = auVar605._0_2_;
              bVar70 = (0 < sVar718) * (sVar718 < 0x100) * auVar605[0] - (0xff < sVar718);
              sVar718 = auVar605._2_2_;
              bVar71 = (0 < sVar718) * (sVar718 < 0x100) * auVar605[2] - (0xff < sVar718);
              sVar718 = auVar605._4_2_;
              bVar72 = (0 < sVar718) * (sVar718 < 0x100) * auVar605[4] - (0xff < sVar718);
              sVar718 = auVar605._6_2_;
              bVar73 = (0 < sVar718) * (sVar718 < 0x100) * auVar605[6] - (0xff < sVar718);
              sVar718 = auVar605._8_2_;
              bVar74 = (0 < sVar718) * (sVar718 < 0x100) * auVar605[8] - (0xff < sVar718);
              sVar718 = auVar605._10_2_;
              bVar75 = (0 < sVar718) * (sVar718 < 0x100) * auVar605[10] - (0xff < sVar718);
              sVar718 = auVar605._12_2_;
              bVar76 = (0 < sVar718) * (sVar718 < 0x100) * auVar605[0xc] - (0xff < sVar718);
              sVar718 = auVar605._14_2_;
              bVar77 = (0 < sVar718) * (sVar718 < 0x100) * auVar605[0xe] - (0xff < sVar718);
              bVar78 = (uVar746 != 0) * (uVar746 < 0x100) * auVar658[3] - (0xff < uVar746);
              cVar79 = (uVar752 != 0) * (uVar752 < 0x100) * auVar658[7] - (0xff < uVar752);
              cVar80 = (uVar758 != 0) * (uVar758 < 0x100) * auVar658[0xb] - (0xff < uVar758);
              cVar81 = (uVar764 != 0) * (uVar764 < 0x100) * auVar658[0xf] - (0xff < uVar764);
              cVar82 = (uVar716 != 0) * (uVar716 < 0x100) * auVar607[3] - (0xff < uVar716);
              cVar83 = (uVar725 != 0) * (uVar725 < 0x100) * auVar607[7] - (0xff < uVar725);
              cVar84 = (uVar733 != 0) * (uVar733 < 0x100) * auVar607[0xb] - (0xff < uVar733);
              cVar85 = (uVar739 != 0) * (uVar739 < 0x100) * auVar607[0xf] - (0xff < uVar739);
              auVar815 = _DAT_00267f50 & auVar656;
              auVar605 = _DAT_00267f50 & pauVar585[3];
              uVar644 = auVar656._0_2_ >> 8;
              uVar683 = auVar656._2_2_ >> 8;
              uVar684 = auVar656._4_2_ >> 8;
              uVar685 = auVar656._6_2_ >> 8;
              uVar686 = auVar656._8_2_ >> 8;
              uVar689 = auVar656._10_2_ >> 8;
              uVar690 = auVar656._12_2_ >> 8;
              uVar692 = auVar656._14_2_ >> 8;
              sVar718 = auVar815._0_2_;
              sVar777 = auVar815._2_2_;
              bVar86 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[2] - (0xff < sVar777);
              sVar777 = auVar815._4_2_;
              sVar778 = auVar815._6_2_;
              cVar87 = (0 < sVar778) * (sVar778 < 0x100) * auVar815[6] - (0xff < sVar778);
              uVar697 = CONCAT13(cVar87,CONCAT12((0 < sVar777) * (sVar777 < 0x100) * auVar815[4] -
                                                 (0xff < sVar777),
                                                 CONCAT11(bVar86,(0 < sVar718) * (sVar718 < 0x100) *
                                                                 auVar815[0] - (0xff < sVar718))));
              sVar718 = auVar815._8_2_;
              sVar777 = auVar815._10_2_;
              cVar88 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[10] - (0xff < sVar777);
              uVar701 = CONCAT15(cVar88,CONCAT14((0 < sVar718) * (sVar718 < 0x100) * auVar815[8] -
                                                 (0xff < sVar718),uVar697));
              sVar718 = auVar815._12_2_;
              sVar777 = auVar815._14_2_;
              cVar89 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[0xe] - (0xff < sVar777);
              uVar702 = CONCAT17(cVar89,CONCAT16((0 < sVar718) * (sVar718 < 0x100) * auVar815[0xc] -
                                                 (0xff < sVar718),uVar701));
              sVar718 = auVar605._0_2_;
              sVar777 = auVar605._2_2_;
              cVar90 = (0 < sVar777) * (sVar777 < 0x100) * auVar605[2] - (0xff < sVar777);
              auVar704._0_10_ =
                   CONCAT19(cVar90,CONCAT18((0 < sVar718) * (sVar718 < 0x100) * auVar605[0] -
                                            (0xff < sVar718),uVar702));
              sVar718 = auVar605._4_2_;
              auVar704[10] = (0 < sVar718) * (sVar718 < 0x100) * auVar605[4] - (0xff < sVar718);
              sVar718 = auVar605._6_2_;
              cVar91 = (0 < sVar718) * (sVar718 < 0x100) * auVar605[6] - (0xff < sVar718);
              auVar704[0xb] = cVar91;
              sVar718 = auVar605._8_2_;
              auVar708[0xc] = (0 < sVar718) * (sVar718 < 0x100) * auVar605[8] - (0xff < sVar718);
              auVar708._0_12_ = auVar704;
              sVar718 = auVar605._10_2_;
              cVar92 = (0 < sVar718) * (sVar718 < 0x100) * auVar605[10] - (0xff < sVar718);
              auVar708[0xd] = cVar92;
              sVar718 = auVar605._12_2_;
              auVar712[0xe] = (0 < sVar718) * (sVar718 < 0x100) * auVar605[0xc] - (0xff < sVar718);
              auVar712._0_14_ = auVar708;
              sVar718 = auVar605._14_2_;
              cVar93 = (0 < sVar718) * (sVar718 < 0x100) * auVar605[0xe] - (0xff < sVar718);
              auVar712[0xf] = cVar93;
              uVar716 = auVar375._0_2_ >> 8;
              uVar725 = auVar375._2_2_ >> 8;
              uVar733 = auVar375._4_2_ >> 8;
              uVar739 = auVar375._6_2_ >> 8;
              uVar746 = auVar375._8_2_ >> 8;
              uVar752 = auVar375._10_2_ >> 8;
              uVar758 = (ushort)uVar645 >> 8;
              uVar764 = (ushort)((uint)uVar645 >> 0x18);
              bVar94 = (uVar683 != 0) * (uVar683 < 0x100) * auVar656[3] - (0xff < uVar683);
              local_13c[3] = (uVar685 != 0) * (uVar685 < 0x100) * auVar656[7] - (0xff < uVar685);
              cVar95 = (uVar689 != 0) * (uVar689 < 0x100) * auVar656[0xb] - (0xff < uVar689);
              local_13c[7] = (uVar692 != 0) * (uVar692 < 0x100) * auVar656[0xf] - (0xff < uVar692);
              cVar96 = (uVar725 != 0) * (uVar725 < 0x100) * auVar375[3] - (0xff < uVar725);
              local_13c[0xb] = (uVar739 != 0) * (uVar739 < 0x100) * auVar375[7] - (0xff < uVar739);
              cVar97 = (uVar752 != 0) * (uVar752 < 0x100) * auVar375[0xb] - (0xff < uVar752);
              local_13c[0xf] =
                   (uVar764 != 0) * (uVar764 < 0x100) * (char)((uint)uVar645 >> 0x18) -
                   (0xff < uVar764);
              auVar815 = _DAT_00267f50 & pauVar585[5];
              auVar605 = _DAT_00267f50 & pauVar585[4];
              uVar741 = auVar371._0_2_ >> 8;
              uVar747 = auVar371._2_2_ >> 8;
              uVar749 = auVar371._4_2_ >> 8;
              uVar753 = auVar371._6_2_ >> 8;
              uVar755 = auVar371._8_2_ >> 8;
              uVar759 = auVar371._10_2_ >> 8;
              uVar761 = (ushort)uVar593 >> 8;
              uVar765 = (ushort)((uint)uVar593 >> 0x18);
              sVar718 = auVar605._0_2_;
              sVar777 = auVar605._2_2_;
              bVar98 = (0 < sVar777) * (sVar777 < 0x100) * auVar605[2] - (0xff < sVar777);
              sVar777 = auVar605._4_2_;
              sVar778 = auVar605._6_2_;
              cVar99 = (0 < sVar778) * (sVar778 < 0x100) * auVar605[6] - (0xff < sVar778);
              uVar592 = CONCAT13(cVar99,CONCAT12((0 < sVar777) * (sVar777 < 0x100) * auVar605[4] -
                                                 (0xff < sVar777),
                                                 CONCAT11(bVar98,(0 < sVar718) * (sVar718 < 0x100) *
                                                                 auVar605[0] - (0xff < sVar718))));
              sVar718 = auVar605._8_2_;
              sVar777 = auVar605._10_2_;
              cVar100 = (0 < sVar777) * (sVar777 < 0x100) * auVar605[10] - (0xff < sVar777);
              uVar596 = CONCAT15(cVar100,CONCAT14((0 < sVar718) * (sVar718 < 0x100) * auVar605[8] -
                                                  (0xff < sVar718),uVar592));
              sVar718 = auVar605._12_2_;
              sVar777 = auVar605._14_2_;
              cVar101 = (0 < sVar777) * (sVar777 < 0x100) * auVar605[0xe] - (0xff < sVar777);
              uVar597 = CONCAT17(cVar101,CONCAT16((0 < sVar718) * (sVar718 < 0x100) * auVar605[0xc]
                                                  - (0xff < sVar718),uVar596));
              sVar718 = auVar815._0_2_;
              sVar777 = auVar815._2_2_;
              cVar102 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[2] - (0xff < sVar777);
              auVar599._0_10_ =
                   CONCAT19(cVar102,CONCAT18((0 < sVar718) * (sVar718 < 0x100) * auVar815[0] -
                                             (0xff < sVar718),uVar597));
              sVar718 = auVar815._4_2_;
              auVar599[10] = (0 < sVar718) * (sVar718 < 0x100) * auVar815[4] - (0xff < sVar718);
              sVar718 = auVar815._6_2_;
              cVar103 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[6] - (0xff < sVar718);
              auVar599[0xb] = cVar103;
              sVar718 = auVar815._8_2_;
              auVar602[0xc] = (0 < sVar718) * (sVar718 < 0x100) * auVar815[8] - (0xff < sVar718);
              auVar602._0_12_ = auVar599;
              sVar718 = auVar815._10_2_;
              cVar104 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[10] - (0xff < sVar718);
              auVar602[0xd] = cVar104;
              sVar718 = auVar815._12_2_;
              auVar606[0xe] = (0 < sVar718) * (sVar718 < 0x100) * auVar815[0xc] - (0xff < sVar718);
              auVar606._0_14_ = auVar602;
              sVar718 = auVar815._14_2_;
              cVar105 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[0xe] - (0xff < sVar718);
              auVar606[0xf] = cVar105;
              uVar725 = auVar377._0_2_ >> 8;
              uVar739 = auVar377._2_2_ >> 8;
              uVar752 = auVar377._4_2_ >> 8;
              uVar764 = auVar377._6_2_ >> 8;
              uVar683 = auVar377._8_2_ >> 8;
              uVar685 = auVar377._10_2_ >> 8;
              uVar689 = (ushort)uVar698 >> 8;
              uVar692 = (ushort)((uint)uVar698 >> 0x18);
              auVar605 = pauVar585[6];
              local_13c[1] = bVar94;
              local_13c[0] = (uVar644 != 0) * (uVar644 < 0x100) * auVar656[1] - (0xff < uVar644);
              local_13c[2] = (uVar684 != 0) * (uVar684 < 0x100) * auVar656[5] - (0xff < uVar684);
              local_13c[4] = (uVar686 != 0) * (uVar686 < 0x100) * auVar656[9] - (0xff < uVar686);
              local_13c[5] = cVar95;
              local_13c[6] = (uVar690 != 0) * (uVar690 < 0x100) * auVar656[0xd] - (0xff < uVar690);
              local_13c[8] = (uVar716 != 0) * (uVar716 < 0x100) * auVar375[1] - (0xff < uVar716);
              local_13c[9] = cVar96;
              local_13c[10] = (uVar733 != 0) * (uVar733 < 0x100) * auVar375[5] - (0xff < uVar733);
              local_13c[0xc] = (uVar746 != 0) * (uVar746 < 0x100) * auVar375[9] - (0xff < uVar746);
              local_13c[0xd] = cVar97;
              local_13c[0xe] =
                   (uVar758 != 0) * (uVar758 < 0x100) * (char)((uint)uVar645 >> 8) -
                   (0xff < uVar758);
              local_12c[1] = (uVar739 != 0) * (uVar739 < 0x100) * auVar377[3] - (0xff < uVar739);
              local_12c[3] = (uVar764 != 0) * (uVar764 < 0x100) * auVar377[7] - (0xff < uVar764);
              local_12c[5] = (uVar685 != 0) * (uVar685 < 0x100) * auVar377[0xb] - (0xff < uVar685);
              local_12c[7] = (uVar692 != 0) * (uVar692 < 0x100) * (char)((uint)uVar698 >> 0x18) -
                             (0xff < uVar692);
              local_12c[9] = (uVar747 != 0) * (uVar747 < 0x100) * auVar371[3] - (0xff < uVar747);
              local_12c[0xb] = (uVar753 != 0) * (uVar753 < 0x100) * auVar371[7] - (0xff < uVar753);
              local_12c[0xd] = (uVar759 != 0) * (uVar759 < 0x100) * auVar371[0xb] - (0xff < uVar759)
              ;
              local_12c[0xf] =
                   (uVar765 != 0) * (uVar765 < 0x100) * (char)((uint)uVar593 >> 0x18) -
                   (0xff < uVar765);
              auVar656 = _DAT_00267f50 & auVar605;
              uVar716 = auVar605._0_2_ >> 8;
              uVar733 = auVar605._2_2_ >> 8;
              uVar739 = auVar605._4_2_ >> 8;
              uVar746 = auVar605._6_2_ >> 8;
              uVar758 = auVar605._8_2_ >> 8;
              uVar764 = auVar605._10_2_ >> 8;
              uVar644 = auVar605._12_2_ >> 8;
              uVar684 = auVar605._14_2_ >> 8;
              auVar815 = _DAT_00267f50 & pauVar585[7];
              uVar685 = auVar373._0_2_ >> 8;
              uVar686 = auVar373._2_2_ >> 8;
              uVar690 = auVar373._4_2_ >> 8;
              uVar692 = auVar373._6_2_ >> 8;
              uVar747 = auVar373._8_2_ >> 8;
              uVar753 = auVar373._10_2_ >> 8;
              uVar759 = (ushort)uVar594 >> 8;
              uVar765 = (ushort)((uint)uVar594 >> 0x18);
              sVar718 = auVar656._0_2_;
              sVar777 = auVar656._2_2_;
              bVar106 = (0 < sVar777) * (sVar777 < 0x100) * auVar656[2] - (0xff < sVar777);
              sVar777 = auVar656._4_2_;
              sVar778 = auVar656._6_2_;
              cVar107 = (0 < sVar778) * (sVar778 < 0x100) * auVar656[6] - (0xff < sVar778);
              uVar645 = CONCAT13(cVar107,CONCAT12((0 < sVar777) * (sVar777 < 0x100) * auVar656[4] -
                                                  (0xff < sVar777),
                                                  CONCAT11(bVar106,(0 < sVar718) * (sVar718 < 0x100)
                                                                   * auVar656[0] - (0xff < sVar718))
                                                 ));
              sVar718 = auVar656._8_2_;
              sVar777 = auVar656._10_2_;
              cVar108 = (0 < sVar777) * (sVar777 < 0x100) * auVar656[10] - (0xff < sVar777);
              uVar647 = CONCAT15(cVar108,CONCAT14((0 < sVar718) * (sVar718 < 0x100) * auVar656[8] -
                                                  (0xff < sVar718),uVar645));
              sVar718 = auVar656._12_2_;
              sVar777 = auVar656._14_2_;
              cVar109 = (0 < sVar777) * (sVar777 < 0x100) * auVar656[0xe] - (0xff < sVar777);
              uVar648 = CONCAT17(cVar109,CONCAT16((0 < sVar718) * (sVar718 < 0x100) * auVar656[0xc]
                                                  - (0xff < sVar718),uVar647));
              sVar718 = auVar815._0_2_;
              sVar777 = auVar815._2_2_;
              cVar110 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[2] - (0xff < sVar777);
              auVar650._0_10_ =
                   CONCAT19(cVar110,CONCAT18((0 < sVar718) * (sVar718 < 0x100) * auVar815[0] -
                                             (0xff < sVar718),uVar648));
              sVar718 = auVar815._4_2_;
              auVar650[10] = (0 < sVar718) * (sVar718 < 0x100) * auVar815[4] - (0xff < sVar718);
              sVar718 = auVar815._6_2_;
              cVar111 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[6] - (0xff < sVar718);
              auVar650[0xb] = cVar111;
              sVar718 = auVar815._8_2_;
              auVar653[0xc] = (0 < sVar718) * (sVar718 < 0x100) * auVar815[8] - (0xff < sVar718);
              auVar653._0_12_ = auVar650;
              sVar718 = auVar815._10_2_;
              cVar112 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[10] - (0xff < sVar718);
              auVar653[0xd] = cVar112;
              sVar718 = auVar815._12_2_;
              auVar657[0xe] = (0 < sVar718) * (sVar718 < 0x100) * auVar815[0xc] - (0xff < sVar718);
              auVar657._0_14_ = auVar653;
              sVar718 = auVar815._14_2_;
              cVar113 = (0 < sVar718) * (sVar718 < 0x100) * auVar815[0xe] - (0xff < sVar718);
              auVar657[0xf] = cVar113;
              local_12c[0] = (uVar725 != 0) * (uVar725 < 0x100) * auVar377[1] - (0xff < uVar725);
              local_12c[2] = (uVar752 != 0) * (uVar752 < 0x100) * auVar377[5] - (0xff < uVar752);
              local_12c[4] = (uVar683 != 0) * (uVar683 < 0x100) * auVar377[9] - (0xff < uVar683);
              local_12c[6] = (uVar689 != 0) * (uVar689 < 0x100) * (char)((uint)uVar698 >> 8) -
                             (0xff < uVar689);
              local_12c[8] = (uVar741 != 0) * (uVar741 < 0x100) * auVar371[1] - (0xff < uVar741);
              local_12c[10] = (uVar749 != 0) * (uVar749 < 0x100) * auVar371[5] - (0xff < uVar749);
              local_12c[0xc] = (uVar755 != 0) * (uVar755 < 0x100) * auVar371[9] - (0xff < uVar755);
              local_12c[0xe] =
                   (uVar761 != 0) * (uVar761 < 0x100) * (char)((uint)uVar593 >> 8) -
                   (0xff < uVar761);
              bVar114 = (uVar733 != 0) * (uVar733 < 0x100) * auVar605[3] - (0xff < uVar733);
              cVar115 = (uVar746 != 0) * (uVar746 < 0x100) * auVar605[7] - (0xff < uVar746);
              uVar698 = CONCAT13(cVar115,CONCAT12((uVar739 != 0) * (uVar739 < 0x100) * auVar605[5] -
                                                  (0xff < uVar739),
                                                  CONCAT11(bVar114,(uVar716 != 0) *
                                                                   (uVar716 < 0x100) * auVar605[1] -
                                                                   (0xff < uVar716))));
              cVar116 = (uVar764 != 0) * (uVar764 < 0x100) * auVar605[0xb] - (0xff < uVar764);
              uVar766 = CONCAT15(cVar116,CONCAT14((uVar758 != 0) * (uVar758 < 0x100) * auVar605[9] -
                                                  (0xff < uVar758),uVar698));
              cVar117 = (uVar684 != 0) * (uVar684 < 0x100) * auVar605[0xf] - (0xff < uVar684);
              uVar598 = CONCAT17(cVar117,CONCAT16((uVar644 != 0) * (uVar644 < 0x100) * auVar605[0xd]
                                                  - (0xff < uVar644),uVar766));
              cVar118 = (uVar686 != 0) * (uVar686 < 0x100) * auVar373[3] - (0xff < uVar686);
              auVar768._0_10_ =
                   CONCAT19(cVar118,CONCAT18((uVar685 != 0) * (uVar685 < 0x100) * auVar373[1] -
                                             (0xff < uVar685),uVar598));
              auVar768[10] = (uVar690 != 0) * (uVar690 < 0x100) * auVar373[5] - (0xff < uVar690);
              cVar119 = (uVar692 != 0) * (uVar692 < 0x100) * auVar373[7] - (0xff < uVar692);
              auVar768[0xb] = cVar119;
              auVar770[0xc] = (uVar747 != 0) * (uVar747 < 0x100) * auVar373[9] - (0xff < uVar747);
              auVar770._0_12_ = auVar768;
              cVar120 = (uVar753 != 0) * (uVar753 < 0x100) * auVar373[0xb] - (0xff < uVar753);
              auVar770[0xd] = cVar120;
              auVar772[0xe] =
                   (uVar759 != 0) * (uVar759 < 0x100) * (char)((uint)uVar594 >> 8) -
                   (0xff < uVar759);
              auVar772._0_14_ = auVar770;
              cVar121 = (uVar765 != 0) * (uVar765 < 0x100) * (char)((uint)uVar594 >> 0x18) -
                        (0xff < uVar765);
              auVar772[0xf] = cVar121;
              auVar656 = _DAT_00267f50 & auVar712;
              uVar741 = (ushort)bVar86;
              uVar716 = (ushort)((uint)uVar697 >> 0x18);
              uVar747 = (ushort)((uint6)uVar701 >> 0x28);
              uVar725 = (ushort)((ulonglong)uVar702 >> 0x38);
              uVar749 = (ushort)((unkuint10)auVar704._0_10_ >> 0x48);
              uVar733 = auVar704._10_2_ >> 8;
              uVar753 = auVar708._12_2_ >> 8;
              uVar739 = auVar712._14_2_ >> 8;
              local_10c[1] = (bVar64 != 0) * (bVar64 < 0x100) * bVar64 - (0xff < bVar64);
              local_10c[3] = (bVar68 != 0) * (bVar68 < 0x100) * bVar68 - (0xff < bVar68);
              local_10c[5] = (bVar72 != 0) * (bVar72 < 0x100) * bVar72 - (0xff < bVar72);
              local_10c[7] = (bVar76 != 0) * (bVar76 < 0x100) * bVar76 - (0xff < bVar76);
              sVar718 = auVar656._0_2_;
              sVar777 = auVar656._2_2_;
              local_10c[9] = (0 < sVar777) * (sVar777 < 0x100) * auVar656[2] - (0xff < sVar777);
              sVar777 = auVar656._4_2_;
              sVar778 = auVar656._6_2_;
              local_10c[0xb] = (0 < sVar778) * (sVar778 < 0x100) * auVar656[6] - (0xff < sVar778);
              sVar778 = auVar656._8_2_;
              sVar779 = auVar656._10_2_;
              local_10c[0xd] = (0 < sVar779) * (sVar779 < 0x100) * auVar656[10] - (0xff < sVar779);
              sVar779 = auVar656._12_2_;
              sVar4 = auVar656._14_2_;
              local_10c[0xf] = (0 < sVar4) * (sVar4 < 0x100) * auVar656[0xe] - (0xff < sVar4);
              local_10c[0] = (bVar62 != 0) * (bVar62 < 0x100) * bVar62 - (0xff < bVar62);
              local_10c[2] = (bVar66 != 0) * (bVar66 < 0x100) * bVar66 - (0xff < bVar66);
              local_10c[4] = (bVar70 != 0) * (bVar70 < 0x100) * bVar70 - (0xff < bVar70);
              local_10c[6] = (bVar74 != 0) * (bVar74 < 0x100) * bVar74 - (0xff < bVar74);
              local_10c[8] = (0 < sVar718) * (sVar718 < 0x100) * auVar656[0] - (0xff < sVar718);
              local_10c[10] = (0 < sVar777) * (sVar777 < 0x100) * auVar656[4] - (0xff < sVar777);
              local_10c[0xc] = (0 < sVar778) * (sVar778 < 0x100) * auVar656[8] - (0xff < sVar778);
              local_10c[0xe] = (0 < sVar779) * (sVar779 < 0x100) * auVar656[0xc] - (0xff < sVar779);
              uVar755 = (ushort)bVar63;
              uVar746 = (ushort)bVar65;
              uVar759 = (ushort)bVar67;
              uVar752 = (ushort)bVar69;
              uVar761 = (ushort)bVar71;
              uVar758 = (ushort)bVar73;
              uVar765 = (ushort)bVar75;
              uVar764 = (ushort)bVar77;
              local_fc[1] = (uVar746 != 0) * (uVar746 < 0x100) * bVar65 - (0xff < uVar746);
              local_fc[3] = (uVar752 != 0) * (uVar752 < 0x100) * bVar69 - (0xff < uVar752);
              local_fc[5] = (uVar758 != 0) * (uVar758 < 0x100) * bVar73 - (0xff < uVar758);
              local_fc[7] = (uVar764 != 0) * (uVar764 < 0x100) * bVar77 - (0xff < uVar764);
              local_fc[9] = (uVar716 != 0) * (uVar716 < 0x100) * cVar87 - (0xff < uVar716);
              local_fc[0xb] = (uVar725 != 0) * (uVar725 < 0x100) * cVar89 - (0xff < uVar725);
              local_fc[0xd] = (uVar733 != 0) * (uVar733 < 0x100) * cVar91 - (0xff < uVar733);
              local_fc[0xf] = (uVar739 != 0) * (uVar739 < 0x100) * cVar93 - (0xff < uVar739);
              auVar605 = _DAT_00267f50 & auVar606;
              uVar716 = (ushort)bVar98;
              uVar725 = (ushort)((uint)uVar592 >> 0x18);
              uVar733 = (ushort)((uint6)uVar596 >> 0x28);
              uVar739 = (ushort)((ulonglong)uVar597 >> 0x38);
              uVar746 = (ushort)((unkuint10)auVar599._0_10_ >> 0x48);
              uVar752 = auVar599._10_2_ >> 8;
              uVar758 = auVar602._12_2_ >> 8;
              uVar764 = auVar606._14_2_ >> 8;
              auVar656 = _DAT_00267f50 & auVar657;
              uVar644 = (ushort)bVar106;
              uVar683 = (ushort)((uint)uVar645 >> 0x18);
              uVar684 = (ushort)((uint6)uVar647 >> 0x28);
              uVar685 = (ushort)((ulonglong)uVar648 >> 0x38);
              uVar686 = (ushort)((unkuint10)auVar650._0_10_ >> 0x48);
              uVar689 = auVar650._10_2_ >> 8;
              uVar690 = auVar653._12_2_ >> 8;
              uVar692 = auVar657._14_2_ >> 8;
              local_fc[0] = (uVar755 != 0) * (uVar755 < 0x100) * bVar63 - (0xff < uVar755);
              local_fc[2] = (uVar759 != 0) * (uVar759 < 0x100) * bVar67 - (0xff < uVar759);
              local_fc[4] = (uVar761 != 0) * (uVar761 < 0x100) * bVar71 - (0xff < uVar761);
              local_fc[6] = (uVar765 != 0) * (uVar765 < 0x100) * bVar75 - (0xff < uVar765);
              local_fc[8] = (uVar741 != 0) * (uVar741 < 0x100) * bVar86 - (0xff < uVar741);
              local_fc[10] = (uVar747 != 0) * (uVar747 < 0x100) * cVar88 - (0xff < uVar747);
              local_fc[0xc] = (uVar749 != 0) * (uVar749 < 0x100) * cVar90 - (0xff < uVar749);
              local_fc[0xe] = (uVar753 != 0) * (uVar753 < 0x100) * cVar92 - (0xff < uVar753);
              uVar593 = CONCAT13(cVar79,CONCAT12((uVar748 != 0) * (uVar748 < 0x100) * auVar658[5] -
                                                 (0xff < uVar748),
                                                 CONCAT11(bVar78,(uVar740 != 0) * (uVar740 < 0x100)
                                                                 * auVar658[1] - (0xff < uVar740))))
              ;
              uVar596 = CONCAT15(cVar80,CONCAT14((uVar754 != 0) * (uVar754 < 0x100) * auVar658[9] -
                                                 (0xff < uVar754),uVar593));
              uVar597 = CONCAT17(cVar81,CONCAT16((uVar760 != 0) * (uVar760 < 0x100) * auVar658[0xd]
                                                 - (0xff < uVar760),uVar596));
              Var370 = CONCAT19(cVar82,CONCAT18((uVar693 != 0) * (uVar693 < 0x100) * auVar607[1] -
                                                (0xff < uVar693),uVar597));
              auVar371[10] = (uVar719 != 0) * (uVar719 < 0x100) * auVar607[5] - (0xff < uVar719);
              auVar371._0_10_ = Var370;
              auVar371[0xb] = cVar83;
              auVar372[0xc] = (uVar727 != 0) * (uVar727 < 0x100) * auVar607[9] - (0xff < uVar727);
              auVar372._0_12_ = auVar371;
              auVar372[0xd] = cVar84;
              auVar658[0xe] = (uVar735 != 0) * (uVar735 < 0x100) * auVar607[0xd] - (0xff < uVar735);
              auVar658._0_14_ = auVar372;
              auVar658[0xf] = cVar85;
              sVar718 = auVar605._0_2_;
              sVar777 = auVar605._2_2_;
              bVar70 = (0 < sVar777) * (sVar777 < 0x100) * auVar605[2] - (0xff < sVar777);
              sVar777 = auVar605._4_2_;
              sVar778 = auVar605._6_2_;
              cVar87 = (0 < sVar778) * (sVar778 < 0x100) * auVar605[6] - (0xff < sVar778);
              uVar645 = CONCAT13(cVar87,CONCAT12((0 < sVar777) * (sVar777 < 0x100) * auVar605[4] -
                                                 (0xff < sVar777),
                                                 CONCAT11(bVar70,(0 < sVar718) * (sVar718 < 0x100) *
                                                                 auVar605[0] - (0xff < sVar718))));
              sVar718 = auVar605._8_2_;
              sVar777 = auVar605._10_2_;
              cVar93 = (0 < sVar777) * (sVar777 < 0x100) * auVar605[10] - (0xff < sVar777);
              uVar701 = CONCAT15(cVar93,CONCAT14((0 < sVar718) * (sVar718 < 0x100) * auVar605[8] -
                                                 (0xff < sVar718),uVar645));
              sVar718 = auVar605._12_2_;
              sVar777 = auVar605._14_2_;
              cVar92 = (0 < sVar777) * (sVar777 < 0x100) * auVar605[0xe] - (0xff < sVar777);
              uVar702 = CONCAT17(cVar92,CONCAT16((0 < sVar718) * (sVar718 < 0x100) * auVar605[0xc] -
                                                 (0xff < sVar718),uVar701));
              sVar718 = auVar656._0_2_;
              sVar777 = auVar656._2_2_;
              cVar91 = (0 < sVar777) * (sVar777 < 0x100) * auVar656[2] - (0xff < sVar777);
              auVar809._0_10_ =
                   CONCAT19(cVar91,CONCAT18((0 < sVar718) * (sVar718 < 0x100) * auVar656[0] -
                                            (0xff < sVar718),uVar702));
              sVar718 = auVar656._4_2_;
              auVar809[10] = (0 < sVar718) * (sVar718 < 0x100) * auVar656[4] - (0xff < sVar718);
              sVar718 = auVar656._6_2_;
              cVar90 = (0 < sVar718) * (sVar718 < 0x100) * auVar656[6] - (0xff < sVar718);
              auVar809[0xb] = cVar90;
              sVar718 = auVar656._8_2_;
              auVar812[0xc] = (0 < sVar718) * (sVar718 < 0x100) * auVar656[8] - (0xff < sVar718);
              auVar812._0_12_ = auVar809;
              sVar718 = auVar656._10_2_;
              cVar89 = (0 < sVar718) * (sVar718 < 0x100) * auVar656[10] - (0xff < sVar718);
              auVar812[0xd] = cVar89;
              sVar718 = auVar656._12_2_;
              auVar816[0xe] = (0 < sVar718) * (sVar718 < 0x100) * auVar656[0xc] - (0xff < sVar718);
              auVar816._0_14_ = auVar812;
              sVar718 = auVar656._14_2_;
              cVar88 = (0 < sVar718) * (sVar718 < 0x100) * auVar656[0xe] - (0xff < sVar718);
              auVar816[0xf] = cVar88;
              auVar656 = _DAT_00267f50 & auVar658;
              bVar65 = (uVar716 != 0) * (uVar716 < 0x100) * bVar98 - (0xff < uVar716);
              bVar62 = (uVar725 != 0) * (uVar725 < 0x100) * cVar99 - (0xff < uVar725);
              bVar63 = (uVar733 != 0) * (uVar733 < 0x100) * cVar100 - (0xff < uVar733);
              bVar64 = (uVar739 != 0) * (uVar739 < 0x100) * cVar101 - (0xff < uVar739);
              bVar66 = (uVar746 != 0) * (uVar746 < 0x100) * cVar102 - (0xff < uVar746);
              bVar67 = (uVar752 != 0) * (uVar752 < 0x100) * cVar103 - (0xff < uVar752);
              bVar68 = (uVar758 != 0) * (uVar758 < 0x100) * cVar104 - (0xff < uVar758);
              bVar86 = (uVar764 != 0) * (uVar764 < 0x100) * cVar105 - (0xff < uVar764);
              bVar69 = (uVar644 != 0) * (uVar644 < 0x100) * bVar106 - (0xff < uVar644);
              bVar71 = (uVar683 != 0) * (uVar683 < 0x100) * cVar107 - (0xff < uVar683);
              bVar72 = (uVar684 != 0) * (uVar684 < 0x100) * cVar108 - (0xff < uVar684);
              bVar73 = (uVar685 != 0) * (uVar685 < 0x100) * cVar109 - (0xff < uVar685);
              bVar77 = (uVar686 != 0) * (uVar686 < 0x100) * cVar110 - (0xff < uVar686);
              bVar74 = (uVar689 != 0) * (uVar689 < 0x100) * cVar111 - (0xff < uVar689);
              bVar75 = (uVar690 != 0) * (uVar690 < 0x100) * cVar112 - (0xff < uVar690);
              bVar76 = (uVar692 != 0) * (uVar692 < 0x100) * cVar113 - (0xff < uVar692);
              auVar607 = _DAT_00267f50 & local_13c;
              uVar716 = (ushort)bVar94;
              uVar725 = SUB42(local_13c._0_4_,2) >> 8;
              uVar733 = SUB62(local_13c._0_6_,4) >> 8;
              uVar739 = SUB82(local_13c._0_8_,6) >> 8;
              uVar746 = SUB102(local_13c._0_10_,8) >> 8;
              uVar752 = local_13c._10_2_ >> 8;
              uVar758 = local_13c._12_2_ >> 8;
              uVar764 = local_13c._14_2_ >> 8;
              uVar644 = (ushort)bVar78;
              uVar683 = (ushort)((uint)uVar593 >> 0x18);
              uVar684 = (ushort)((uint6)uVar596 >> 0x28);
              uVar685 = (ushort)((ulonglong)uVar597 >> 0x38);
              uVar686 = (ushort)((unkuint10)Var370 >> 0x48);
              uVar689 = auVar371._10_2_ >> 8;
              uVar690 = auVar372._12_2_ >> 8;
              uVar692 = auVar658._14_2_ >> 8;
              sVar718 = auVar656._0_2_;
              sVar777 = auVar656._2_2_;
              bVar98 = (0 < sVar777) * (sVar777 < 0x100) * auVar656[2] - (0xff < sVar777);
              sVar777 = auVar656._4_2_;
              sVar778 = auVar656._6_2_;
              cVar105 = (0 < sVar778) * (sVar778 < 0x100) * auVar656[6] - (0xff < sVar778);
              uVar594 = CONCAT13(cVar105,CONCAT12((0 < sVar777) * (sVar777 < 0x100) * auVar656[4] -
                                                  (0xff < sVar777),
                                                  CONCAT11(bVar98,(0 < sVar718) * (sVar718 < 0x100)
                                                                  * auVar656[0] - (0xff < sVar718)))
                                );
              sVar718 = auVar656._8_2_;
              sVar777 = auVar656._10_2_;
              cVar104 = (0 < sVar777) * (sVar777 < 0x100) * auVar656[10] - (0xff < sVar777);
              uVar647 = CONCAT15(cVar104,CONCAT14((0 < sVar718) * (sVar718 < 0x100) * auVar656[8] -
                                                  (0xff < sVar718),uVar594));
              sVar718 = auVar656._12_2_;
              sVar777 = auVar656._14_2_;
              cVar103 = (0 < sVar777) * (sVar777 < 0x100) * auVar656[0xe] - (0xff < sVar777);
              uVar648 = CONCAT17(cVar103,CONCAT16((0 < sVar718) * (sVar718 < 0x100) * auVar656[0xc]
                                                  - (0xff < sVar718),uVar647));
              sVar718 = auVar607._0_2_;
              sVar777 = auVar607._2_2_;
              cVar99 = (0 < sVar777) * (sVar777 < 0x100) * auVar607[2] - (0xff < sVar777);
              auVar705._0_10_ =
                   CONCAT19(cVar99,CONCAT18((0 < sVar718) * (sVar718 < 0x100) * auVar607[0] -
                                            (0xff < sVar718),uVar648));
              sVar718 = auVar607._4_2_;
              auVar705[10] = (0 < sVar718) * (sVar718 < 0x100) * auVar607[4] - (0xff < sVar718);
              sVar718 = auVar607._6_2_;
              cVar102 = (0 < sVar718) * (sVar718 < 0x100) * auVar607[6] - (0xff < sVar718);
              auVar705[0xb] = cVar102;
              sVar718 = auVar607._8_2_;
              auVar709[0xc] = (0 < sVar718) * (sVar718 < 0x100) * auVar607[8] - (0xff < sVar718);
              auVar709._0_12_ = auVar705;
              sVar718 = auVar607._10_2_;
              cVar101 = (0 < sVar718) * (sVar718 < 0x100) * auVar607[10] - (0xff < sVar718);
              auVar709[0xd] = cVar101;
              sVar718 = auVar607._12_2_;
              auVar713[0xe] = (0 < sVar718) * (sVar718 < 0x100) * auVar607[0xc] - (0xff < sVar718);
              auVar713._0_14_ = auVar709;
              sVar718 = auVar607._14_2_;
              cVar100 = (0 < sVar718) * (sVar718 < 0x100) * auVar607[0xe] - (0xff < sVar718);
              auVar713[0xf] = cVar100;
              local_13c[1] = (uVar683 != 0) * (uVar683 < 0x100) * cVar79 - (0xff < uVar683);
              cVar107 = (uVar685 != 0) * (uVar685 < 0x100) * cVar81 - (0xff < uVar685);
              local_13c[5] = (uVar689 != 0) * (uVar689 < 0x100) * cVar83 - (0xff < uVar689);
              cVar108 = (uVar692 != 0) * (uVar692 < 0x100) * cVar85 - (0xff < uVar692);
              cVar109 = (uVar725 != 0) * (uVar725 < 0x100) * local_13c[3] - (0xff < uVar725);
              cVar110 = (uVar739 != 0) * (uVar739 < 0x100) * local_13c[7] - (0xff < uVar739);
              local_13c[0xd] =
                   (uVar752 != 0) * (uVar752 < 0x100) * local_13c[0xb] - (0xff < uVar752);
              local_13c[0xf] =
                   (uVar764 != 0) * (uVar764 < 0x100) * local_13c[0xf] - (0xff < uVar764);
              auVar607 = _DAT_00267f50 & local_12c;
              local_13c[0] = (uVar644 != 0) * (uVar644 < 0x100) * bVar78 - (0xff < uVar644);
              local_13c[2] = (uVar684 != 0) * (uVar684 < 0x100) * cVar80 - (0xff < uVar684);
              local_13c[3] = cVar107;
              local_13c[4] = (uVar686 != 0) * (uVar686 < 0x100) * cVar82 - (0xff < uVar686);
              local_13c[6] = (uVar690 != 0) * (uVar690 < 0x100) * cVar84 - (0xff < uVar690);
              local_13c[7] = cVar108;
              local_13c[8] = (uVar716 != 0) * (uVar716 < 0x100) * bVar94 - (0xff < uVar716);
              local_13c[9] = cVar109;
              local_13c[10] = (uVar733 != 0) * (uVar733 < 0x100) * cVar95 - (0xff < uVar733);
              local_13c[0xb] = cVar110;
              local_13c[0xc] = (uVar746 != 0) * (uVar746 < 0x100) * cVar96 - (0xff < uVar746);
              local_13c[0xe] = (uVar758 != 0) * (uVar758 < 0x100) * cVar97 - (0xff < uVar758);
              auVar658 = _DAT_00267f50 & auVar772;
              uVar644 = (ushort)bVar114;
              uVar683 = (ushort)((uint)uVar698 >> 0x18);
              uVar684 = (ushort)((uint6)uVar766 >> 0x28);
              uVar685 = (ushort)((ulonglong)uVar598 >> 0x38);
              uVar686 = (ushort)((unkuint10)auVar768._0_10_ >> 0x48);
              uVar689 = auVar768._10_2_ >> 8;
              uVar690 = auVar770._12_2_ >> 8;
              uVar692 = auVar772._14_2_ >> 8;
              sVar718 = auVar607._0_2_;
              sVar777 = auVar607._2_2_;
              bVar78 = (0 < sVar777) * (sVar777 < 0x100) * auVar607[2] - (0xff < sVar777);
              sVar777 = auVar607._4_2_;
              sVar778 = auVar607._6_2_;
              cVar81 = (0 < sVar778) * (sVar778 < 0x100) * auVar607[6] - (0xff < sVar778);
              uVar593 = CONCAT13(cVar81,CONCAT12((0 < sVar777) * (sVar777 < 0x100) * auVar607[4] -
                                                 (0xff < sVar777),
                                                 CONCAT11(bVar78,(0 < sVar718) * (sVar718 < 0x100) *
                                                                 auVar607[0] - (0xff < sVar718))));
              sVar718 = auVar607._8_2_;
              sVar777 = auVar607._10_2_;
              cVar80 = (0 < sVar777) * (sVar777 < 0x100) * auVar607[10] - (0xff < sVar777);
              uVar596 = CONCAT15(cVar80,CONCAT14((0 < sVar718) * (sVar718 < 0x100) * auVar607[8] -
                                                 (0xff < sVar718),uVar593));
              sVar718 = auVar607._12_2_;
              sVar777 = auVar607._14_2_;
              cVar79 = (0 < sVar777) * (sVar777 < 0x100) * auVar607[0xe] - (0xff < sVar777);
              uVar597 = CONCAT17(cVar79,CONCAT16((0 < sVar718) * (sVar718 < 0x100) * auVar607[0xc] -
                                                 (0xff < sVar718),uVar596));
              sVar718 = auVar658._0_2_;
              sVar777 = auVar658._2_2_;
              cVar82 = (0 < sVar777) * (sVar777 < 0x100) * auVar658[2] - (0xff < sVar777);
              auVar600._0_10_ =
                   CONCAT19(cVar82,CONCAT18((0 < sVar718) * (sVar718 < 0x100) * auVar658[0] -
                                            (0xff < sVar718),uVar597));
              sVar718 = auVar658._4_2_;
              auVar600[10] = (0 < sVar718) * (sVar718 < 0x100) * auVar658[4] - (0xff < sVar718);
              sVar718 = auVar658._6_2_;
              cVar95 = (0 < sVar718) * (sVar718 < 0x100) * auVar658[6] - (0xff < sVar718);
              auVar600[0xb] = cVar95;
              sVar718 = auVar658._8_2_;
              auVar603[0xc] = (0 < sVar718) * (sVar718 < 0x100) * auVar658[8] - (0xff < sVar718);
              auVar603._0_12_ = auVar600;
              sVar718 = auVar658._10_2_;
              cVar96 = (0 < sVar718) * (sVar718 < 0x100) * auVar658[10] - (0xff < sVar718);
              auVar603[0xd] = cVar96;
              sVar718 = auVar658._12_2_;
              auVar608[0xe] = (0 < sVar718) * (sVar718 < 0x100) * auVar658[0xc] - (0xff < sVar718);
              auVar608._0_14_ = auVar603;
              sVar718 = auVar658._14_2_;
              cVar97 = (0 < sVar718) * (sVar718 < 0x100) * auVar658[0xe] - (0xff < sVar718);
              auVar608[0xf] = cVar97;
              uVar716 = (ushort)local_12c[1];
              uVar725 = SUB42(local_12c._0_4_,2) >> 8;
              uVar733 = SUB62(local_12c._0_6_,4) >> 8;
              uVar739 = SUB82(local_12c._0_8_,6) >> 8;
              uVar746 = SUB102(local_12c._0_10_,8) >> 8;
              uVar752 = local_12c._10_2_ >> 8;
              uVar758 = local_12c._12_2_ >> 8;
              uVar764 = local_12c._14_2_ >> 8;
              uVar588 = uVar588 + 1;
              bVar122 = (uVar716 != 0) * (uVar716 < 0x100) * local_12c[1] - (0xff < uVar716);
              bVar123 = (uVar725 != 0) * (uVar725 < 0x100) * local_12c[3] - (0xff < uVar725);
              bVar124 = (uVar733 != 0) * (uVar733 < 0x100) * local_12c[5] - (0xff < uVar733);
              bVar125 = (uVar739 != 0) * (uVar739 < 0x100) * local_12c[7] - (0xff < uVar739);
              bVar126 = (uVar746 != 0) * (uVar746 < 0x100) * local_12c[9] - (0xff < uVar746);
              bVar127 = (uVar752 != 0) * (uVar752 < 0x100) * local_12c[0xb] - (0xff < uVar752);
              bVar128 = (uVar758 != 0) * (uVar758 < 0x100) * local_12c[0xd] - (0xff < uVar758);
              bVar129 = (uVar764 != 0) * (uVar764 < 0x100) * local_12c[0xf] - (0xff < uVar764);
              bVar130 = (uVar644 != 0) * (uVar644 < 0x100) * bVar114 - (0xff < uVar644);
              bVar131 = (uVar683 != 0) * (uVar683 < 0x100) * cVar115 - (0xff < uVar683);
              bVar132 = (uVar684 != 0) * (uVar684 < 0x100) * cVar116 - (0xff < uVar684);
              bVar133 = (uVar685 != 0) * (uVar685 < 0x100) * cVar117 - (0xff < uVar685);
              bVar134 = (uVar686 != 0) * (uVar686 < 0x100) * cVar118 - (0xff < uVar686);
              bVar114 = (uVar689 != 0) * (uVar689 < 0x100) * cVar119 - (0xff < uVar689);
              bVar106 = (uVar690 != 0) * (uVar690 < 0x100) * cVar120 - (0xff < uVar690);
              bVar94 = (uVar692 != 0) * (uVar692 < 0x100) * cVar121 - (0xff < uVar692);
              auVar659 = _DAT_00267f50 & auVar816;
              uVar733 = (ushort)bVar70;
              uVar739 = (ushort)((uint)uVar645 >> 0x18);
              uVar746 = (ushort)((uint6)uVar701 >> 0x28);
              uVar752 = (ushort)((ulonglong)uVar702 >> 0x38);
              uVar758 = (ushort)((unkuint10)auVar809._0_10_ >> 0x48);
              uVar823 = auVar809._10_2_ >> 8;
              uVar825 = auVar812._12_2_ >> 8;
              uVar828 = auVar816._14_2_ >> 8;
              auVar607 = _DAT_00267f50 & local_10c;
              sVar718 = auVar607._0_2_;
              sVar777 = auVar607._2_2_;
              sVar778 = auVar607._4_2_;
              sVar779 = auVar607._6_2_;
              sVar4 = auVar607._8_2_;
              sVar11 = auVar607._10_2_;
              sVar12 = auVar607._12_2_;
              sVar5 = auVar607._14_2_;
              cVar83 = (0 < sVar5) * (sVar5 < 0x100) * auVar607[0xe] - (0xff < sVar5);
              sVar5 = auVar659._0_2_;
              bVar135 = (0 < sVar5) * (sVar5 < 0x100) * auVar659[0] - (0xff < sVar5);
              uVar716 = CONCAT11(bVar135,cVar83);
              sVar5 = auVar659._2_2_;
              cVar111 = (0 < sVar5) * (sVar5 < 0x100) * auVar659[2] - (0xff < sVar5);
              uVar464 = CONCAT12(cVar111,uVar716);
              sVar5 = auVar659._4_2_;
              bVar136 = (0 < sVar5) * (sVar5 < 0x100) * auVar659[4] - (0xff < sVar5);
              uVar297 = CONCAT13(bVar136,uVar464);
              sVar5 = auVar659._6_2_;
              cVar112 = (0 < sVar5) * (sVar5 < 0x100) * auVar659[6] - (0xff < sVar5);
              uVar398 = CONCAT14(cVar112,uVar297);
              sVar5 = auVar659._8_2_;
              bVar137 = (0 < sVar5) * (sVar5 < 0x100) * auVar659[8] - (0xff < sVar5);
              auVar532[5] = bVar137;
              auVar532._0_5_ = uVar398;
              sVar50 = auVar659._10_2_;
              sVar54 = auVar659._12_2_;
              sVar58 = auVar659._14_2_;
              uVar764 = (ushort)local_10c[1];
              uVar644 = SUB42(local_10c._0_4_,2) >> 8;
              uVar683 = SUB62(local_10c._0_6_,4) >> 8;
              uVar684 = SUB82(local_10c._0_8_,6) >> 8;
              uVar685 = SUB102(local_10c._0_10_,8) >> 8;
              uVar686 = local_10c._10_2_ >> 8;
              uVar692 = local_10c._12_2_ >> 8;
              uVar725 = local_10c._14_2_ >> 8;
              auVar784 = _DAT_00267f50 & auVar713;
              cVar84 = (uVar725 != 0) * (uVar725 < 0x100) * local_10c[0xf] - (0xff < uVar725);
              bVar70 = (uVar733 != 0) * (uVar733 < 0x100) * bVar70 - (0xff < uVar733);
              uVar725 = CONCAT11(bVar70,cVar84);
              cVar113 = (uVar739 != 0) * (uVar739 < 0x100) * cVar87 - (0xff < uVar739);
              uVar465 = CONCAT12(cVar113,uVar725);
              bVar138 = (uVar746 != 0) * (uVar746 < 0x100) * cVar93 - (0xff < uVar746);
              uVar298 = CONCAT13(bVar138,uVar465);
              cVar87 = (uVar752 != 0) * (uVar752 < 0x100) * cVar92 - (0xff < uVar752);
              uVar399 = CONCAT14(cVar87,uVar298);
              bVar139 = (uVar758 != 0) * (uVar758 < 0x100) * cVar91 - (0xff < uVar758);
              auVar533[5] = bVar139;
              auVar533._0_5_ = uVar399;
              uVar694 = (ushort)bVar98;
              uVar717 = (ushort)((uint)uVar594 >> 0x18);
              uVar720 = (ushort)((uint6)uVar647 >> 0x28);
              uVar726 = (ushort)((ulonglong)uVar648 >> 0x38);
              uVar728 = (ushort)((unkuint10)auVar705._0_10_ >> 0x48);
              uVar734 = auVar705._10_2_ >> 8;
              uVar736 = auVar709._12_2_ >> 8;
              uVar693 = auVar713._14_2_ >> 8;
              auVar785 = _DAT_00267f50 & auVar608;
              uVar733 = (ushort)bVar78;
              uVar739 = (ushort)((uint)uVar593 >> 0x18);
              uVar746 = (ushort)((uint6)uVar596 >> 0x28);
              uVar752 = (ushort)((ulonglong)uVar597 >> 0x38);
              uVar758 = (ushort)((unkuint10)auVar600._0_10_ >> 0x48);
              uVar689 = auVar600._10_2_ >> 8;
              uVar690 = auVar603._12_2_ >> 8;
              uVar741 = auVar608._14_2_ >> 8;
              sVar5 = auVar784._0_2_;
              sVar8 = auVar784._2_2_;
              sVar14 = auVar784._4_2_;
              sVar21 = auVar784._6_2_;
              sVar28 = auVar784._8_2_;
              sVar35 = auVar784._10_2_;
              sVar42 = auVar784._12_2_;
              sVar6 = auVar784._14_2_;
              cVar93 = (0 < sVar6) * (sVar6 < 0x100) * auVar784[0xe] - (0xff < sVar6);
              sVar6 = auVar785._0_2_;
              bVar140 = (0 < sVar6) * (sVar6 < 0x100) * auVar785[0] - (0xff < sVar6);
              sVar6 = auVar785._2_2_;
              cVar92 = (0 < sVar6) * (sVar6 < 0x100) * auVar785[2] - (0xff < sVar6);
              sVar6 = auVar785._4_2_;
              bVar141 = (0 < sVar6) * (sVar6 < 0x100) * auVar785[4] - (0xff < sVar6);
              sVar6 = auVar785._6_2_;
              cVar91 = (0 < sVar6) * (sVar6 < 0x100) * auVar785[6] - (0xff < sVar6);
              sVar6 = auVar785._8_2_;
              bVar142 = (0 < sVar6) * (sVar6 < 0x100) * auVar785[8] - (0xff < sVar6);
              sVar51 = auVar785._10_2_;
              sVar55 = auVar785._12_2_;
              sVar59 = auVar785._14_2_;
              cVar100 = (uVar693 != 0) * (uVar693 < 0x100) * cVar100 - (0xff < uVar693);
              bVar78 = (uVar733 != 0) * (uVar733 < 0x100) * bVar78 - (0xff < uVar733);
              cVar119 = (uVar739 != 0) * (uVar739 < 0x100) * cVar81 - (0xff < uVar739);
              bVar143 = (uVar746 != 0) * (uVar746 < 0x100) * cVar80 - (0xff < uVar746);
              cVar121 = (uVar752 != 0) * (uVar752 < 0x100) * cVar79 - (0xff < uVar752);
              bVar144 = (uVar758 != 0) * (uVar758 < 0x100) * cVar82 - (0xff < uVar758);
              uVar739 = CONCAT11(bVar140,cVar93);
              uVar549 = CONCAT12(cVar92,uVar739);
              uVar595 = CONCAT13(bVar141,uVar549);
              uVar552 = CONCAT14(cVar91,uVar595);
              auVar567[5] = bVar142;
              auVar567._0_5_ = uVar552;
              uVar752 = CONCAT11(bVar78,cVar100);
              uVar550 = CONCAT12(cVar119,uVar752);
              uVar642 = CONCAT13(bVar143,uVar550);
              uVar553 = CONCAT14(cVar121,uVar642);
              auVar568[5] = bVar144;
              auVar568._0_5_ = uVar553;
              auVar786 = _DAT_00267f50 & local_fc;
              sVar6 = auVar786._0_2_;
              sVar9 = auVar786._2_2_;
              sVar15 = auVar786._4_2_;
              sVar22 = auVar786._6_2_;
              sVar29 = auVar786._8_2_;
              sVar36 = auVar786._10_2_;
              sVar43 = auVar786._12_2_;
              sVar7 = auVar786._14_2_;
              cVar120 = (0 < sVar7) * (sVar7 < 0x100) * auVar786[0xe] - (0xff < sVar7);
              bVar65 = (bVar65 != 0) * (bVar65 < 0x100) * bVar65 - (0xff < bVar65);
              cVar117 = (bVar63 != 0) * (bVar63 < 0x100) * bVar63 - (0xff < bVar63);
              bVar66 = (bVar66 != 0) * (bVar66 < 0x100) * bVar66 - (0xff < bVar66);
              cVar118 = (bVar68 != 0) * (bVar68 < 0x100) * bVar68 - (0xff < bVar68);
              bVar69 = (bVar69 != 0) * (bVar69 < 0x100) * bVar69 - (0xff < bVar69);
              uVar782 = (ushort)local_fc[1];
              uVar788 = SUB42(local_fc._0_4_,2) >> 8;
              uVar790 = SUB62(local_fc._0_6_,4) >> 8;
              uVar792 = SUB82(local_fc._0_8_,6) >> 8;
              uVar794 = SUB102(local_fc._0_10_,8) >> 8;
              uVar796 = local_fc._10_2_ >> 8;
              uVar800 = local_fc._12_2_ >> 8;
              uVar727 = local_fc._14_2_ >> 8;
              uVar758 = CONCAT11(bVar65,cVar120);
              uVar551 = CONCAT12(cVar117,uVar758);
              uVar643 = CONCAT13(bVar66,uVar551);
              uVar554 = CONCAT14(cVar118,uVar643);
              auVar571[5] = bVar69;
              auVar571._0_5_ = uVar554;
              pauVar585 = pauVar585 + 8;
              uVar733 = (ushort)bVar62;
              uVar746 = (ushort)bVar64;
              uVar693 = (ushort)bVar67;
              uVar719 = (ushort)bVar86;
              uVar747 = (ushort)bVar71;
              uVar797 = (ushort)bVar73;
              uVar801 = (ushort)bVar74;
              uVar804 = (ushort)bVar76;
              cVar116 = (uVar727 != 0) * (uVar727 < 0x100) * local_fc[0xf] - (0xff < uVar727);
              bVar68 = (uVar733 != 0) * (uVar733 < 0x100) * bVar62 - (0xff < uVar733);
              cVar115 = (uVar746 != 0) * (uVar746 < 0x100) * bVar64 - (0xff < uVar746);
              bVar67 = (uVar693 != 0) * (uVar693 < 0x100) * bVar67 - (0xff < uVar693);
              cVar145 = (uVar719 != 0) * (uVar719 < 0x100) * bVar86 - (0xff < uVar719);
              bVar71 = (uVar747 != 0) * (uVar747 < 0x100) * bVar71 - (0xff < uVar747);
              auVar787 = _DAT_00267f50 & local_13c;
              sVar7 = auVar787._0_2_;
              sVar10 = auVar787._2_2_;
              sVar16 = auVar787._4_2_;
              sVar23 = auVar787._6_2_;
              sVar30 = auVar787._8_2_;
              sVar37 = auVar787._10_2_;
              sVar44 = auVar787._12_2_;
              sVar13 = auVar787._14_2_;
              cVar146 = (0 < sVar13) * (sVar13 < 0x100) * auVar787[0xe] - (0xff < sVar13);
              bVar64 = (bVar122 != 0) * (bVar122 < 0x100) * bVar122 - (0xff < bVar122);
              cVar147 = (bVar124 != 0) * (bVar124 < 0x100) * bVar124 - (0xff < bVar124);
              bVar63 = (bVar126 != 0) * (bVar126 < 0x100) * bVar126 - (0xff < bVar126);
              cVar148 = (bVar128 != 0) * (bVar128 < 0x100) * bVar128 - (0xff < bVar128);
              bVar62 = (bVar130 != 0) * (bVar130 < 0x100) * bVar130 - (0xff < bVar130);
              uVar783 = (ushort)local_13c[1];
              uVar789 = SUB42(local_13c._0_4_,2) >> 8;
              uVar791 = SUB62(local_13c._0_6_,4) >> 8;
              uVar793 = SUB82(local_13c._0_8_,6) >> 8;
              uVar795 = SUB102(local_13c._0_10_,8) >> 8;
              uVar798 = local_13c._10_2_ >> 8;
              uVar802 = local_13c._12_2_ >> 8;
              uVar727 = local_13c._14_2_ >> 8;
              auVar658 = pauVar587[1];
              uVar733 = (ushort)bVar123;
              uVar746 = (ushort)(((uint)bVar125 << 0x18) >> 0x18);
              uVar693 = (ushort)(((uint6)bVar127 << 0x28) >> 0x28);
              uVar719 = (ushort)(((ulonglong)bVar129 << 0x38) >> 0x38);
              uVar747 = (ushort)((uint3)((uint3)bVar131 << 0x10) >> 0x10);
              uVar799 = (ushort)(((uint5)bVar133 << 0x20) >> 0x20);
              uVar803 = (ushort)(((uint7)bVar114 << 0x30) >> 0x30);
              uVar805 = (ushort)((uint3)((uint3)bVar94 << 0x10) >> 0x10);
              cVar149 = (uVar727 != 0) * (uVar727 < 0x100) * local_13c[0xf] - (0xff < uVar727);
              bVar86 = (uVar733 != 0) * (uVar733 < 0x100) * bVar123 - (0xff < uVar733);
              cVar150 = (uVar746 != 0) * (uVar746 < 0x100) * bVar125 - (0xff < uVar746);
              bVar130 = (uVar693 != 0) * (uVar693 < 0x100) * bVar127 - (0xff < uVar693);
              cVar151 = (uVar719 != 0) * (uVar719 < 0x100) * bVar129 - (0xff < uVar719);
              bVar131 = (uVar747 != 0) * (uVar747 < 0x100) * bVar131 - (0xff < uVar747);
              uVar744 = CONCAT13(0,CONCAT12(cVar111,(ushort)bVar135));
              auVar532._6_8_ = 0;
              auVar252[0xe] = cVar83;
              auVar252._0_14_ = auVar532 << 0x38;
              auVar498._4_8_ = 0;
              auVar498._0_4_ = uVar297;
              auVar284._12_3_ =
                   (int3)(CONCAT26(auVar252._13_2_,
                                   CONCAT15((0 < sVar12) * (sVar12 < 0x100) * auVar607[0xc] -
                                            (0xff < sVar12),uVar398)) >> 0x28);
              auVar284._0_12_ = auVar498 << 0x38;
              uVar297 = auVar284._11_4_;
              uVar499 = CONCAT44(uVar297,CONCAT13((0 < sVar11) * (sVar11 < 0x100) * auVar607[10] -
                                                  (0xff < sVar11),uVar464));
              auVar338._10_5_ = (int5)((ulonglong)uVar499 >> 0x18);
              auVar338._0_10_ = (unkuint10)uVar716 << 0x38;
              uVar648 = CONCAT62(auVar338._9_6_,
                                 CONCAT11((0 < sVar4) * (sVar4 < 0x100) * auVar607[8] -
                                          (0xff < sVar4),cVar83));
              auVar390._7_8_ = 0;
              auVar390._0_7_ = (uint7)((ulonglong)uVar648 >> 8);
              Var391 = CONCAT81(SUB158(auVar390 << 0x40,7),
                                (0 < sVar779) * (sVar779 < 0x100) * auVar607[6] - (0xff < sVar779));
              auVar466._9_6_ = 0;
              auVar466._0_9_ = Var391;
              auVar392._1_10_ = SUB1510(auVar466 << 0x30,5);
              auVar392[0] = (0 < sVar778) * (sVar778 < 0x100) * auVar607[4] - (0xff < sVar778);
              auVar467._11_4_ = 0;
              auVar467._0_11_ = auVar392;
              auVar393._1_12_ = SUB1512(auVar467 << 0x20,3);
              auVar393[0] = (0 < sVar777) * (sVar777 < 0x100) * auVar607[2] - (0xff < sVar777);
              uVar716 = CONCAT11(0,(0 < sVar718) * (sVar718 < 0x100) * auVar607[0] -
                                   (0xff < sVar718));
              auVar354._2_13_ = auVar393;
              auVar354._0_2_ = uVar716;
              uVar646 = CONCAT13(0,CONCAT12(cVar113,(ushort)bVar70));
              auVar533._6_8_ = 0;
              auVar253[0xe] = cVar84;
              auVar253._0_14_ = auVar533 << 0x38;
              auVar500._4_8_ = 0;
              auVar500._0_4_ = uVar298;
              auVar285._12_3_ =
                   (int3)(CONCAT26(auVar253._13_2_,
                                   CONCAT15((uVar692 != 0) * (uVar692 < 0x100) * local_10c[0xd] -
                                            (0xff < uVar692),uVar399)) >> 0x28);
              auVar285._0_12_ = auVar500 << 0x38;
              uVar298 = auVar285._11_4_;
              uVar501 = CONCAT44(uVar298,CONCAT13((uVar686 != 0) * (uVar686 < 0x100) *
                                                  local_10c[0xb] - (0xff < uVar686),uVar465));
              auVar339._10_5_ = (int5)((ulonglong)uVar501 >> 0x18);
              auVar339._0_10_ = (unkuint10)uVar725 << 0x38;
              uVar702 = CONCAT62(auVar339._9_6_,
                                 CONCAT11((uVar685 != 0) * (uVar685 < 0x100) * local_10c[9] -
                                          (0xff < uVar685),cVar84));
              auVar394._7_8_ = 0;
              auVar394._0_7_ = (uint7)((ulonglong)uVar702 >> 8);
              Var395 = CONCAT81(SUB158(auVar394 << 0x40,7),
                                (uVar684 != 0) * (uVar684 < 0x100) * local_10c[7] - (0xff < uVar684)
                               );
              auVar468._9_6_ = 0;
              auVar468._0_9_ = Var395;
              auVar396._1_10_ = SUB1510(auVar468 << 0x30,5);
              auVar396[0] = (uVar683 != 0) * (uVar683 < 0x100) * local_10c[5] - (0xff < uVar683);
              auVar469._11_4_ = 0;
              auVar469._0_11_ = auVar396;
              auVar397._1_12_ = SUB1512(auVar469 << 0x20,3);
              auVar397[0] = (uVar644 != 0) * (uVar644 < 0x100) * local_10c[3] - (0xff < uVar644);
              auVar355[1] = 0;
              auVar355[0] = (uVar764 != 0) * (uVar764 < 0x100) * local_10c[1] - (0xff < uVar764);
              auVar355._2_13_ = auVar397;
              auVar607 = pauVar587[4];
              auVar656 = *pauVar587;
              uVar593 = *(undefined4 *)(pauVar587[5] + 4);
              uVar398 = *(undefined5 *)pauVar587[5];
              uVar594 = *(undefined4 *)(pauVar587[5] + 8);
              uVar645 = *(undefined4 *)(pauVar587[5] + 0xc);
              cStack_97 = (char)((uint)uVar593 >> 8);
              uStack_96 = (undefined1)((uint)uVar593 >> 0x10);
              cStack_95 = (char)((uint)uVar593 >> 0x18);
              uStack_94 = (undefined1)uVar594;
              cStack_93 = (char)((uint)uVar594 >> 8);
              uStack_92 = (undefined1)((uint)uVar594 >> 0x10);
              cStack_91 = (char)((uint)uVar594 >> 0x18);
              uStack_90 = (undefined1)uVar645;
              cStack_8f = (char)((uint)uVar645 >> 8);
              uStack_8e = (undefined1)((uint)uVar645 >> 0x10);
              cStack_8d = (char)((uint)uVar645 >> 0x18);
              uVar593 = *(undefined4 *)(pauVar587[7] + 4);
              uVar399 = *(undefined5 *)pauVar587[7];
              uVar594 = *(undefined4 *)(pauVar587[7] + 8);
              uVar645 = *(undefined4 *)(pauVar587[7] + 0xc);
              cStack_87 = (char)((uint)uVar593 >> 8);
              uStack_86 = (undefined1)((uint)uVar593 >> 0x10);
              cStack_85 = (char)((uint)uVar593 >> 0x18);
              uStack_84 = (undefined1)uVar594;
              cStack_83 = (char)((uint)uVar594 >> 8);
              uStack_82 = (undefined1)((uint)uVar594 >> 0x10);
              cStack_81 = (char)((uint)uVar594 >> 0x18);
              uStack_80 = (undefined1)uVar645;
              cStack_7f = (char)((uint)uVar645 >> 8);
              uStack_7e = (undefined1)((uint)uVar645 >> 0x10);
              cStack_7d = (char)((uint)uVar645 >> 0x18);
              auVar815 = _DAT_00267f50 & auVar656;
              uVar742 = auVar656._0_2_ >> 8;
              uVar644 = auVar656._2_2_ >> 8;
              uVar750 = auVar656._4_2_ >> 8;
              uVar683 = auVar656._6_2_ >> 8;
              uVar756 = auVar656._8_2_ >> 8;
              uVar684 = auVar656._10_2_ >> 8;
              uVar762 = auVar656._12_2_ >> 8;
              uVar685 = auVar656._14_2_ >> 8;
              auVar660 = _DAT_00267f50 & auVar658;
              uVar695 = auVar658._0_2_ >> 8;
              uVar725 = auVar658._2_2_ >> 8;
              uVar721 = auVar658._4_2_ >> 8;
              uVar733 = auVar658._6_2_ >> 8;
              uVar729 = auVar658._8_2_ >> 8;
              uVar746 = auVar658._10_2_ >> 8;
              uVar737 = auVar658._12_2_ >> 8;
              uVar764 = auVar658._14_2_ >> 8;
              auVar605 = pauVar587[3];
              sVar718 = auVar815._0_2_;
              sVar777 = auVar815._2_2_;
              bVar128 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[2] - (0xff < sVar777);
              sVar777 = auVar815._4_2_;
              sVar778 = auVar815._6_2_;
              cVar81 = (0 < sVar778) * (sVar778 < 0x100) * auVar815[6] - (0xff < sVar778);
              uVar697 = CONCAT13(cVar81,CONCAT12((0 < sVar777) * (sVar777 < 0x100) * auVar815[4] -
                                                 (0xff < sVar777),
                                                 CONCAT11(bVar128,(0 < sVar718) * (sVar718 < 0x100)
                                                                  * auVar815[0] - (0xff < sVar718)))
                                );
              sVar718 = auVar815._8_2_;
              sVar777 = auVar815._10_2_;
              cVar152 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[10] - (0xff < sVar777);
              uVar807 = CONCAT15(cVar152,CONCAT14((0 < sVar718) * (sVar718 < 0x100) * auVar815[8] -
                                                  (0xff < sVar718),uVar697));
              sVar718 = auVar815._12_2_;
              sVar777 = auVar815._14_2_;
              cVar82 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[0xe] - (0xff < sVar777);
              uVar808 = CONCAT17(cVar82,CONCAT16((0 < sVar718) * (sVar718 < 0x100) * auVar815[0xc] -
                                                 (0xff < sVar718),uVar807));
              sVar718 = auVar660._0_2_;
              sVar777 = auVar660._2_2_;
              cVar153 = (0 < sVar777) * (sVar777 < 0x100) * auVar660[2] - (0xff < sVar777);
              auVar810._0_10_ =
                   CONCAT19(cVar153,CONCAT18((0 < sVar718) * (sVar718 < 0x100) * auVar660[0] -
                                             (0xff < sVar718),uVar808));
              sVar718 = auVar660._4_2_;
              auVar810[10] = (0 < sVar718) * (sVar718 < 0x100) * auVar660[4] - (0xff < sVar718);
              sVar718 = auVar660._6_2_;
              cVar80 = (0 < sVar718) * (sVar718 < 0x100) * auVar660[6] - (0xff < sVar718);
              auVar810[0xb] = cVar80;
              sVar718 = auVar660._8_2_;
              auVar813[0xc] = (0 < sVar718) * (sVar718 < 0x100) * auVar660[8] - (0xff < sVar718);
              auVar813._0_12_ = auVar810;
              sVar718 = auVar660._10_2_;
              cVar154 = (0 < sVar718) * (sVar718 < 0x100) * auVar660[10] - (0xff < sVar718);
              auVar813[0xd] = cVar154;
              sVar718 = auVar660._12_2_;
              auVar817[0xe] = (0 < sVar718) * (sVar718 < 0x100) * auVar660[0xc] - (0xff < sVar718);
              auVar817._0_14_ = auVar813;
              sVar718 = auVar660._14_2_;
              cVar79 = (0 < sVar718) * (sVar718 < 0x100) * auVar660[0xe] - (0xff < sVar718);
              auVar817[0xf] = cVar79;
              auVar371 = *(undefined1 (*) [12])pauVar587[2];
              uVar593 = *(undefined4 *)(pauVar587[2] + 0xc);
              bVar127 = (uVar644 != 0) * (uVar644 < 0x100) * auVar656[3] - (0xff < uVar644);
              cVar155 = (uVar683 != 0) * (uVar683 < 0x100) * auVar656[7] - (0xff < uVar683);
              cVar156 = (uVar684 != 0) * (uVar684 < 0x100) * auVar656[0xb] - (0xff < uVar684);
              cVar157 = (uVar685 != 0) * (uVar685 < 0x100) * auVar656[0xf] - (0xff < uVar685);
              cVar158 = (uVar725 != 0) * (uVar725 < 0x100) * auVar658[3] - (0xff < uVar725);
              cVar159 = (uVar733 != 0) * (uVar733 < 0x100) * auVar658[7] - (0xff < uVar733);
              cVar160 = (uVar746 != 0) * (uVar746 < 0x100) * auVar658[0xb] - (0xff < uVar746);
              cVar161 = (uVar764 != 0) * (uVar764 < 0x100) * auVar658[0xf] - (0xff < uVar764);
              auVar815 = _DAT_00267f50 & pauVar587[2];
              auVar660 = _DAT_00267f50 & auVar605;
              uVar747 = auVar371._0_2_ >> 8;
              uVar685 = auVar371._2_2_ >> 8;
              uVar753 = auVar371._4_2_ >> 8;
              uVar686 = auVar371._6_2_ >> 8;
              uVar755 = auVar371._8_2_ >> 8;
              uVar693 = auVar371._10_2_ >> 8;
              uVar765 = (ushort)uVar593 >> 8;
              uVar719 = (ushort)((uint)uVar593 >> 0x18);
              uVar725 = auVar605._0_2_ >> 8;
              uVar733 = auVar605._2_2_ >> 8;
              uVar764 = auVar605._4_2_ >> 8;
              uVar746 = auVar605._6_2_ >> 8;
              uVar684 = auVar605._8_2_ >> 8;
              uVar644 = auVar605._10_2_ >> 8;
              uVar692 = auVar605._12_2_ >> 8;
              uVar683 = auVar605._14_2_ >> 8;
              sVar718 = auVar815._0_2_;
              sVar777 = auVar815._2_2_;
              bVar126 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[2] - (0xff < sVar777);
              sVar777 = auVar815._4_2_;
              sVar778 = auVar815._6_2_;
              cVar83 = (0 < sVar778) * (sVar778 < 0x100) * auVar815[6] - (0xff < sVar778);
              uVar698 = CONCAT13(cVar83,CONCAT12((0 < sVar777) * (sVar777 < 0x100) * auVar815[4] -
                                                 (0xff < sVar777),
                                                 CONCAT11(bVar126,(0 < sVar718) * (sVar718 < 0x100)
                                                                  * auVar815[0] - (0xff < sVar718)))
                                );
              sVar718 = auVar815._8_2_;
              sVar777 = auVar815._10_2_;
              cVar162 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[10] - (0xff < sVar777);
              uVar701 = CONCAT15(cVar162,CONCAT14((0 < sVar718) * (sVar718 < 0x100) * auVar815[8] -
                                                  (0xff < sVar718),uVar698));
              sVar718 = auVar815._12_2_;
              sVar777 = auVar815._14_2_;
              cVar163 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[0xe] - (0xff < sVar777);
              uVar703 = CONCAT17(cVar163,CONCAT16((0 < sVar718) * (sVar718 < 0x100) * auVar815[0xc]
                                                  - (0xff < sVar718),uVar701));
              sVar718 = auVar660._0_2_;
              sVar777 = auVar660._2_2_;
              cVar164 = (0 < sVar777) * (sVar777 < 0x100) * auVar660[2] - (0xff < sVar777);
              auVar706._0_10_ =
                   CONCAT19(cVar164,CONCAT18((0 < sVar718) * (sVar718 < 0x100) * auVar660[0] -
                                             (0xff < sVar718),uVar703));
              sVar718 = auVar660._4_2_;
              auVar706[10] = (0 < sVar718) * (sVar718 < 0x100) * auVar660[4] - (0xff < sVar718);
              sVar718 = auVar660._6_2_;
              cVar85 = (0 < sVar718) * (sVar718 < 0x100) * auVar660[6] - (0xff < sVar718);
              auVar706[0xb] = cVar85;
              sVar718 = auVar660._8_2_;
              auVar710[0xc] = (0 < sVar718) * (sVar718 < 0x100) * auVar660[8] - (0xff < sVar718);
              auVar710._0_12_ = auVar706;
              sVar718 = auVar660._10_2_;
              cVar165 = (0 < sVar718) * (sVar718 < 0x100) * auVar660[10] - (0xff < sVar718);
              auVar710[0xd] = cVar165;
              sVar718 = auVar660._12_2_;
              auVar714[0xe] = (0 < sVar718) * (sVar718 < 0x100) * auVar660[0xc] - (0xff < sVar718);
              auVar714._0_14_ = auVar710;
              sVar718 = auVar660._14_2_;
              cVar84 = (0 < sVar718) * (sVar718 < 0x100) * auVar660[0xe] - (0xff < sVar718);
              auVar714[0xf] = cVar84;
              bVar125 = (uVar685 != 0) * (uVar685 < 0x100) * auVar371[3] - (0xff < uVar685);
              cVar166 = (uVar686 != 0) * (uVar686 < 0x100) * auVar371[7] - (0xff < uVar686);
              cVar167 = (uVar693 != 0) * (uVar693 < 0x100) * auVar371[0xb] - (0xff < uVar693);
              cVar168 = (uVar719 != 0) * (uVar719 < 0x100) * (char)((uint)uVar593 >> 0x18) -
                        (0xff < uVar719);
              cVar169 = (uVar733 != 0) * (uVar733 < 0x100) * auVar605[3] - (0xff < uVar733);
              cVar170 = (uVar746 != 0) * (uVar746 < 0x100) * auVar605[7] - (0xff < uVar746);
              cVar171 = (uVar644 != 0) * (uVar644 < 0x100) * auVar605[0xb] - (0xff < uVar644);
              cVar172 = (uVar683 != 0) * (uVar683 < 0x100) * auVar605[0xf] - (0xff < uVar683);
              auVar660 = _DAT_00267f50 & auVar607;
              uVar597 = CONCAT17(cStack_95,CONCAT16(uStack_96,CONCAT15(cStack_97,uVar398)));
              Var370 = CONCAT19(cStack_93,CONCAT18(uStack_94,uVar597));
              auVar379[10] = uStack_92;
              auVar379._0_10_ = Var370;
              auVar379[0xb] = cStack_91;
              auVar380[0xc] = uStack_90;
              auVar380._0_12_ = auVar379;
              auVar380[0xd] = cStack_8f;
              auVar815[0xe] = uStack_8e;
              auVar815._0_14_ = auVar380;
              auVar815[0xf] = cStack_8d;
              auVar661 = _DAT_00267f50 & auVar815;
              uVar743 = (ushort)uVar398 >> 8;
              uVar685 = (ushort)((uint5)uVar398 >> 0x10) >> 8;
              uVar751 = (ushort)(CONCAT15(cStack_97,uVar398) >> 0x28);
              uVar686 = (ushort)((ulonglong)uVar597 >> 0x38);
              uVar757 = (ushort)((unkuint10)Var370 >> 0x48);
              uVar693 = auVar379._10_2_ >> 8;
              uVar763 = auVar380._12_2_ >> 8;
              uVar719 = auVar815._14_2_ >> 8;
              sVar718 = auVar660._0_2_;
              sVar777 = auVar660._2_2_;
              bVar70 = (0 < sVar777) * (sVar777 < 0x100) * auVar660[2] - (0xff < sVar777);
              sVar777 = auVar660._4_2_;
              sVar778 = auVar660._6_2_;
              cVar173 = (0 < sVar778) * (sVar778 < 0x100) * auVar660[6] - (0xff < sVar778);
              uVar594 = CONCAT13(cVar173,CONCAT12((0 < sVar777) * (sVar777 < 0x100) * auVar660[4] -
                                                  (0xff < sVar777),
                                                  CONCAT11(bVar70,(0 < sVar718) * (sVar718 < 0x100)
                                                                  * auVar660[0] - (0xff < sVar718)))
                                );
              sVar718 = auVar660._8_2_;
              sVar777 = auVar660._10_2_;
              cVar174 = (0 < sVar777) * (sVar777 < 0x100) * auVar660[10] - (0xff < sVar777);
              uVar596 = CONCAT15(cVar174,CONCAT14((0 < sVar718) * (sVar718 < 0x100) * auVar660[8] -
                                                  (0xff < sVar718),uVar594));
              sVar718 = auVar660._12_2_;
              sVar777 = auVar660._14_2_;
              cVar175 = (0 < sVar777) * (sVar777 < 0x100) * auVar660[0xe] - (0xff < sVar777);
              uVar598 = CONCAT17(cVar175,CONCAT16((0 < sVar718) * (sVar718 < 0x100) * auVar660[0xc]
                                                  - (0xff < sVar718),uVar596));
              sVar718 = auVar661._0_2_;
              sVar777 = auVar661._2_2_;
              cVar176 = (0 < sVar777) * (sVar777 < 0x100) * auVar661[2] - (0xff < sVar777);
              auVar601._0_10_ =
                   CONCAT19(cVar176,CONCAT18((0 < sVar718) * (sVar718 < 0x100) * auVar661[0] -
                                             (0xff < sVar718),uVar598));
              sVar718 = auVar661._4_2_;
              auVar601[10] = (0 < sVar718) * (sVar718 < 0x100) * auVar661[4] - (0xff < sVar718);
              sVar718 = auVar661._6_2_;
              cVar177 = (0 < sVar718) * (sVar718 < 0x100) * auVar661[6] - (0xff < sVar718);
              auVar601[0xb] = cVar177;
              sVar718 = auVar661._8_2_;
              auVar604[0xc] = (0 < sVar718) * (sVar718 < 0x100) * auVar661[8] - (0xff < sVar718);
              auVar604._0_12_ = auVar601;
              sVar718 = auVar661._10_2_;
              cVar178 = (0 < sVar718) * (sVar718 < 0x100) * auVar661[10] - (0xff < sVar718);
              auVar604[0xd] = cVar178;
              sVar718 = auVar661._12_2_;
              auVar609[0xe] = (0 < sVar718) * (sVar718 < 0x100) * auVar661[0xc] - (0xff < sVar718);
              auVar609._0_14_ = auVar604;
              sVar718 = auVar661._14_2_;
              cVar179 = (0 < sVar718) * (sVar718 < 0x100) * auVar661[0xe] - (0xff < sVar718);
              auVar609[0xf] = cVar179;
              uVar727 = auVar607._0_2_ >> 8;
              uVar733 = auVar607._2_2_ >> 8;
              uVar740 = auVar607._4_2_ >> 8;
              uVar746 = auVar607._6_2_ >> 8;
              uVar759 = auVar607._8_2_ >> 8;
              uVar644 = auVar607._10_2_ >> 8;
              uVar691 = auVar607._12_2_ >> 8;
              uVar683 = auVar607._14_2_ >> 8;
              auVar815 = pauVar587[6];
              bVar124 = (uVar733 != 0) * (uVar733 < 0x100) * auVar607[3] - (0xff < uVar733);
              cVar180 = (uVar746 != 0) * (uVar746 < 0x100) * auVar607[7] - (0xff < uVar746);
              cVar181 = (uVar644 != 0) * (uVar644 < 0x100) * auVar607[0xb] - (0xff < uVar644);
              cVar182 = (uVar683 != 0) * (uVar683 < 0x100) * auVar607[0xf] - (0xff < uVar683);
              cVar183 = (uVar685 != 0) * (uVar685 < 0x100) * (char)((uint5)uVar398 >> 0x18) -
                        (0xff < uVar685);
              cVar184 = (uVar686 != 0) * (uVar686 < 0x100) * cStack_95 - (0xff < uVar686);
              cVar185 = (uVar693 != 0) * (uVar693 < 0x100) * cStack_91 - (0xff < uVar693);
              cVar186 = (uVar719 != 0) * (uVar719 < 0x100) * cStack_8d - (0xff < uVar719);
              auVar660 = _DAT_00267f50 & auVar815;
              uVar597 = CONCAT17(cStack_85,CONCAT16(uStack_86,CONCAT15(cStack_87,uVar399)));
              Var370 = CONCAT19(cStack_83,CONCAT18(uStack_84,uVar597));
              auVar383[10] = uStack_82;
              auVar383._0_10_ = Var370;
              auVar383[0xb] = cStack_81;
              auVar384[0xc] = uStack_80;
              auVar384._0_12_ = auVar383;
              auVar384[0xd] = cStack_7f;
              auVar661[0xe] = uStack_7e;
              auVar661._0_14_ = auVar384;
              auVar661[0xf] = cStack_7d;
              uVar749 = auVar815._0_2_ >> 8;
              uVar735 = auVar815._2_2_ >> 8;
              uVar748 = auVar815._4_2_ >> 8;
              uVar754 = auVar815._6_2_ >> 8;
              uVar760 = auVar815._8_2_ >> 8;
              uVar761 = auVar815._10_2_ >> 8;
              uVar780 = auVar815._12_2_ >> 8;
              uVar781 = auVar815._14_2_ >> 8;
              auVar745 = _DAT_00267f50 & auVar661;
              sVar718 = auVar660._0_2_;
              sVar777 = auVar660._2_2_;
              bVar123 = (0 < sVar777) * (sVar777 < 0x100) * auVar660[2] - (0xff < sVar777);
              sVar777 = auVar660._4_2_;
              sVar778 = auVar660._6_2_;
              cVar187 = (0 < sVar778) * (sVar778 < 0x100) * auVar660[6] - (0xff < sVar778);
              uVar645 = CONCAT13(cVar187,CONCAT12((0 < sVar777) * (sVar777 < 0x100) * auVar660[4] -
                                                  (0xff < sVar777),
                                                  CONCAT11(bVar123,(0 < sVar718) * (sVar718 < 0x100)
                                                                   * auVar660[0] - (0xff < sVar718))
                                                 ));
              sVar718 = auVar660._8_2_;
              sVar777 = auVar660._10_2_;
              cVar188 = (0 < sVar777) * (sVar777 < 0x100) * auVar660[10] - (0xff < sVar777);
              uVar647 = CONCAT15(cVar188,CONCAT14((0 < sVar718) * (sVar718 < 0x100) * auVar660[8] -
                                                  (0xff < sVar718),uVar645));
              sVar718 = auVar660._12_2_;
              sVar777 = auVar660._14_2_;
              cVar189 = (0 < sVar777) * (sVar777 < 0x100) * auVar660[0xe] - (0xff < sVar777);
              uVar649 = CONCAT17(cVar189,CONCAT16((0 < sVar718) * (sVar718 < 0x100) * auVar660[0xc]
                                                  - (0xff < sVar718),uVar647));
              sVar718 = auVar745._0_2_;
              sVar777 = auVar745._2_2_;
              cVar190 = (0 < sVar777) * (sVar777 < 0x100) * auVar745[2] - (0xff < sVar777);
              auVar651._0_10_ =
                   CONCAT19(cVar190,CONCAT18((0 < sVar718) * (sVar718 < 0x100) * auVar745[0] -
                                             (0xff < sVar718),uVar649));
              sVar718 = auVar745._4_2_;
              auVar651[10] = (0 < sVar718) * (sVar718 < 0x100) * auVar745[4] - (0xff < sVar718);
              sVar718 = auVar745._6_2_;
              cVar191 = (0 < sVar718) * (sVar718 < 0x100) * auVar745[6] - (0xff < sVar718);
              auVar651[0xb] = cVar191;
              sVar718 = auVar745._8_2_;
              auVar654[0xc] = (0 < sVar718) * (sVar718 < 0x100) * auVar745[8] - (0xff < sVar718);
              auVar654._0_12_ = auVar651;
              sVar718 = auVar745._10_2_;
              cVar192 = (0 < sVar718) * (sVar718 < 0x100) * auVar745[10] - (0xff < sVar718);
              auVar654[0xd] = cVar192;
              sVar718 = auVar745._12_2_;
              auVar662[0xe] = (0 < sVar718) * (sVar718 < 0x100) * auVar745[0xc] - (0xff < sVar718);
              auVar662._0_14_ = auVar654;
              sVar718 = auVar745._14_2_;
              cVar193 = (0 < sVar718) * (sVar718 < 0x100) * auVar745[0xe] - (0xff < sVar718);
              auVar662[0xf] = cVar193;
              uVar733 = (ushort)uVar399 >> 8;
              uVar746 = (ushort)((uint5)uVar399 >> 0x10) >> 8;
              uVar644 = (ushort)(CONCAT15(cStack_87,uVar399) >> 0x28);
              uVar683 = (ushort)((ulonglong)uVar597 >> 0x38);
              uVar685 = (ushort)((unkuint10)Var370 >> 0x48);
              uVar686 = auVar383._10_2_ >> 8;
              uVar693 = auVar384._12_2_ >> 8;
              uVar719 = auVar661._14_2_ >> 8;
              bVar122 = (uVar735 != 0) * (uVar735 < 0x100) * auVar815[3] - (0xff < uVar735);
              cVar194 = (uVar754 != 0) * (uVar754 < 0x100) * auVar815[7] - (0xff < uVar754);
              uVar592 = CONCAT13(cVar194,CONCAT12((uVar748 != 0) * (uVar748 < 0x100) * auVar815[5] -
                                                  (0xff < uVar748),
                                                  CONCAT11(bVar122,(uVar749 != 0) *
                                                                   (uVar749 < 0x100) * auVar815[1] -
                                                                   (0xff < uVar749))));
              cVar195 = (uVar761 != 0) * (uVar761 < 0x100) * auVar815[0xb] - (0xff < uVar761);
              uVar766 = CONCAT15(cVar195,CONCAT14((uVar760 != 0) * (uVar760 < 0x100) * auVar815[9] -
                                                  (0xff < uVar760),uVar592));
              cVar196 = (uVar781 != 0) * (uVar781 < 0x100) * auVar815[0xf] - (0xff < uVar781);
              uVar767 = CONCAT17(cVar196,CONCAT16((uVar780 != 0) * (uVar780 < 0x100) * auVar815[0xd]
                                                  - (0xff < uVar780),uVar766));
              cVar197 = (uVar746 != 0) * (uVar746 < 0x100) * (char)((uint5)uVar399 >> 0x18) -
                        (0xff < uVar746);
              auVar769._0_10_ =
                   CONCAT19(cVar197,CONCAT18((uVar733 != 0) * (uVar733 < 0x100) *
                                             (char)((uint5)uVar399 >> 8) - (0xff < uVar733),uVar767)
                           );
              auVar769[10] = (uVar644 != 0) * (uVar644 < 0x100) * cStack_87 - (0xff < uVar644);
              cVar198 = (uVar683 != 0) * (uVar683 < 0x100) * cStack_85 - (0xff < uVar683);
              auVar769[0xb] = cVar198;
              auVar771[0xc] = (uVar685 != 0) * (uVar685 < 0x100) * cStack_83 - (0xff < uVar685);
              auVar771._0_12_ = auVar769;
              cVar199 = (uVar686 != 0) * (uVar686 < 0x100) * cStack_81 - (0xff < uVar686);
              auVar771[0xd] = cVar199;
              auVar773[0xe] = (uVar693 != 0) * (uVar693 < 0x100) * cStack_7f - (0xff < uVar693);
              auVar773._0_14_ = auVar771;
              cVar200 = (uVar719 != 0) * (uVar719 < 0x100) * cStack_7d - (0xff < uVar719);
              auVar773[0xf] = cVar200;
              auVar661 = _DAT_00267f50 & auVar817;
              auVar745 = _DAT_00267f50 & auVar714;
              uVar806 = (ushort)bVar128;
              uVar685 = (ushort)((uint)uVar697 >> 0x18);
              uVar819 = (ushort)((uint6)uVar807 >> 0x28);
              uVar686 = (ushort)((ulonglong)uVar808 >> 0x38);
              uVar821 = (ushort)((unkuint10)auVar810._0_10_ >> 0x48);
              uVar693 = auVar810._10_2_ >> 8;
              uVar826 = auVar813._12_2_ >> 8;
              uVar719 = auVar817._14_2_ >> 8;
              uVar696 = (ushort)bVar126;
              uVar733 = (ushort)((uint)uVar698 >> 0x18);
              uVar722 = (ushort)((uint6)uVar701 >> 0x28);
              uVar746 = (ushort)((ulonglong)uVar703 >> 0x38);
              uVar730 = (ushort)((unkuint10)auVar706._0_10_ >> 0x48);
              uVar644 = auVar706._10_2_ >> 8;
              uVar738 = auVar710._12_2_ >> 8;
              uVar683 = auVar714._14_2_ >> 8;
              bVar129 = (uVar685 != 0) * (uVar685 < 0x100) * cVar81 - (0xff < uVar685);
              cVar201 = (uVar686 != 0) * (uVar686 < 0x100) * cVar82 - (0xff < uVar686);
              cVar202 = (uVar693 != 0) * (uVar693 < 0x100) * cVar80 - (0xff < uVar693);
              cVar203 = (uVar719 != 0) * (uVar719 < 0x100) * cVar79 - (0xff < uVar719);
              cVar204 = (uVar733 != 0) * (uVar733 < 0x100) * cVar83 - (0xff < uVar733);
              cVar163 = (uVar746 != 0) * (uVar746 < 0x100) * cVar163 - (0xff < uVar746);
              cVar205 = (uVar644 != 0) * (uVar644 < 0x100) * cVar85 - (0xff < uVar644);
              cVar206 = (uVar683 != 0) * (uVar683 < 0x100) * cVar84 - (0xff < uVar683);
              auVar815 = _DAT_00267f50 & auVar609;
              uVar733 = (ushort)bVar70;
              uVar746 = (ushort)((uint)uVar594 >> 0x18);
              uVar644 = (ushort)((uint6)uVar596 >> 0x28);
              uVar683 = (ushort)((ulonglong)uVar598 >> 0x38);
              uVar685 = (ushort)((unkuint10)auVar601._0_10_ >> 0x48);
              uVar686 = auVar601._10_2_ >> 8;
              uVar693 = auVar604._12_2_ >> 8;
              uVar719 = auVar609._14_2_ >> 8;
              auVar660 = _DAT_00267f50 & auVar662;
              uVar749 = (ushort)bVar123;
              uVar735 = (ushort)((uint)uVar645 >> 0x18);
              uVar748 = (ushort)((uint6)uVar647 >> 0x28);
              uVar754 = (ushort)((ulonglong)uVar649 >> 0x38);
              uVar760 = (ushort)((unkuint10)auVar651._0_10_ >> 0x48);
              uVar761 = auVar651._10_2_ >> 8;
              uVar780 = auVar654._12_2_ >> 8;
              uVar781 = auVar662._14_2_ >> 8;
              sVar718 = auVar815._0_2_;
              sVar777 = auVar815._2_2_;
              bVar135 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[2] - (0xff < sVar777);
              sVar777 = auVar815._4_2_;
              sVar778 = auVar815._6_2_;
              cVar207 = (0 < sVar778) * (sVar778 < 0x100) * auVar815[6] - (0xff < sVar778);
              uVar645 = CONCAT13(cVar207,CONCAT12((0 < sVar777) * (sVar777 < 0x100) * auVar815[4] -
                                                  (0xff < sVar777),
                                                  CONCAT11(bVar135,(0 < sVar718) * (sVar718 < 0x100)
                                                                   * auVar815[0] - (0xff < sVar718))
                                                 ));
              sVar718 = auVar815._8_2_;
              sVar777 = auVar815._10_2_;
              cVar208 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[10] - (0xff < sVar777);
              uVar701 = CONCAT15(cVar208,CONCAT14((0 < sVar718) * (sVar718 < 0x100) * auVar815[8] -
                                                  (0xff < sVar718),uVar645));
              sVar718 = auVar815._12_2_;
              sVar777 = auVar815._14_2_;
              cVar209 = (0 < sVar777) * (sVar777 < 0x100) * auVar815[0xe] - (0xff < sVar777);
              uVar649 = CONCAT17(cVar209,CONCAT16((0 < sVar718) * (sVar718 < 0x100) * auVar815[0xc]
                                                  - (0xff < sVar718),uVar701));
              sVar718 = auVar660._0_2_;
              sVar777 = auVar660._2_2_;
              cVar210 = (0 < sVar777) * (sVar777 < 0x100) * auVar660[2] - (0xff < sVar777);
              auVar707._0_10_ =
                   CONCAT19(cVar210,CONCAT18((0 < sVar718) * (sVar718 < 0x100) * auVar660[0] -
                                             (0xff < sVar718),uVar649));
              sVar718 = auVar660._4_2_;
              auVar707[10] = (0 < sVar718) * (sVar718 < 0x100) * auVar660[4] - (0xff < sVar718);
              sVar718 = auVar660._6_2_;
              cVar211 = (0 < sVar718) * (sVar718 < 0x100) * auVar660[6] - (0xff < sVar718);
              auVar707[0xb] = cVar211;
              sVar718 = auVar660._8_2_;
              auVar711[0xc] = (0 < sVar718) * (sVar718 < 0x100) * auVar660[8] - (0xff < sVar718);
              auVar711._0_12_ = auVar707;
              sVar718 = auVar660._10_2_;
              cVar212 = (0 < sVar718) * (sVar718 < 0x100) * auVar660[10] - (0xff < sVar718);
              auVar711[0xd] = cVar212;
              sVar718 = auVar660._12_2_;
              auVar715[0xe] = (0 < sVar718) * (sVar718 < 0x100) * auVar660[0xc] - (0xff < sVar718);
              auVar715._0_14_ = auVar711;
              sVar718 = auVar660._14_2_;
              cVar213 = (0 < sVar718) * (sVar718 < 0x100) * auVar660[0xe] - (0xff < sVar718);
              auVar715[0xf] = cVar213;
              bVar214 = (uVar733 != 0) * (uVar733 < 0x100) * bVar70 - (0xff < uVar733);
              bVar215 = (uVar746 != 0) * (uVar746 < 0x100) * cVar173 - (0xff < uVar746);
              bVar216 = (uVar644 != 0) * (uVar644 < 0x100) * cVar174 - (0xff < uVar644);
              bVar217 = (uVar683 != 0) * (uVar683 < 0x100) * cVar175 - (0xff < uVar683);
              bVar218 = (uVar685 != 0) * (uVar685 < 0x100) * cVar176 - (0xff < uVar685);
              bVar219 = (uVar686 != 0) * (uVar686 < 0x100) * cVar177 - (0xff < uVar686);
              bVar220 = (uVar693 != 0) * (uVar693 < 0x100) * cVar178 - (0xff < uVar693);
              bVar221 = (uVar719 != 0) * (uVar719 < 0x100) * cVar179 - (0xff < uVar719);
              bVar222 = (uVar749 != 0) * (uVar749 < 0x100) * bVar123 - (0xff < uVar749);
              bVar223 = (uVar735 != 0) * (uVar735 < 0x100) * cVar187 - (0xff < uVar735);
              bVar224 = (uVar748 != 0) * (uVar748 < 0x100) * cVar188 - (0xff < uVar748);
              bVar225 = (uVar754 != 0) * (uVar754 < 0x100) * cVar189 - (0xff < uVar754);
              bVar226 = (uVar760 != 0) * (uVar760 < 0x100) * cVar190 - (0xff < uVar760);
              bVar227 = (uVar761 != 0) * (uVar761 < 0x100) * cVar191 - (0xff < uVar761);
              bVar228 = (uVar780 != 0) * (uVar780 < 0x100) * cVar192 - (0xff < uVar780);
              bVar123 = (uVar781 != 0) * (uVar781 < 0x100) * cVar193 - (0xff < uVar781);
              uVar594 = CONCAT13(cVar155,CONCAT12((uVar750 != 0) * (uVar750 < 0x100) * auVar656[5] -
                                                  (0xff < uVar750),
                                                  CONCAT11(bVar127,(uVar742 != 0) *
                                                                   (uVar742 < 0x100) * auVar656[1] -
                                                                   (0xff < uVar742))));
              uVar596 = CONCAT15(cVar156,CONCAT14((uVar756 != 0) * (uVar756 < 0x100) * auVar656[9] -
                                                  (0xff < uVar756),uVar594));
              uVar597 = CONCAT17(cVar157,CONCAT16((uVar762 != 0) * (uVar762 < 0x100) * auVar656[0xd]
                                                  - (0xff < uVar762),uVar596));
              Var370 = CONCAT19(cVar158,CONCAT18((uVar695 != 0) * (uVar695 < 0x100) * auVar658[1] -
                                                 (0xff < uVar695),uVar597));
              auVar373[10] = (uVar721 != 0) * (uVar721 < 0x100) * auVar658[5] - (0xff < uVar721);
              auVar373._0_10_ = Var370;
              auVar373[0xb] = cVar159;
              auVar374[0xc] = (uVar729 != 0) * (uVar729 < 0x100) * auVar658[9] - (0xff < uVar729);
              auVar374._0_12_ = auVar373;
              auVar374[0xd] = cVar160;
              auVar656[0xe] = (uVar737 != 0) * (uVar737 < 0x100) * auVar658[0xd] - (0xff < uVar737);
              auVar656._0_14_ = auVar374;
              auVar656[0xf] = cVar161;
              auVar658 = _DAT_00267f50 & auVar656;
              uVar746 = (ushort)bVar127;
              uVar733 = (ushort)((uint)uVar594 >> 0x18);
              uVar686 = (ushort)((uint6)uVar596 >> 0x28);
              uVar644 = (ushort)((ulonglong)uVar597 >> 0x38);
              uVar749 = (ushort)((unkuint10)Var370 >> 0x48);
              uVar685 = auVar373._10_2_ >> 8;
              uVar760 = auVar374._12_2_ >> 8;
              uVar693 = auVar656._14_2_ >> 8;
              local_15c = auVar745._0_2_;
              sStack_15a = auVar745._2_2_;
              sStack_158 = auVar745._4_2_;
              sStack_156 = auVar745._6_2_;
              sStack_154 = auVar745._8_2_;
              sStack_152 = auVar745._10_2_;
              sStack_150 = auVar745._12_2_;
              sStack_14e = auVar745._14_2_;
              sVar718 = auVar661._0_2_;
              sVar777 = auVar661._2_2_;
              bVar70 = (0 < sVar777) * (sVar777 < 0x100) * auVar661[2] - (0xff < sVar777);
              sVar777 = auVar661._4_2_;
              sVar778 = auVar661._6_2_;
              cVar80 = (0 < sVar778) * (sVar778 < 0x100) * auVar661[6] - (0xff < sVar778);
              sVar778 = auVar661._8_2_;
              sVar779 = auVar661._10_2_;
              cVar79 = (0 < sVar779) * (sVar779 < 0x100) * auVar661[10] - (0xff < sVar779);
              sVar779 = auVar661._12_2_;
              sVar4 = auVar661._14_2_;
              cVar84 = (0 < sVar4) * (sVar4 < 0x100) * auVar661[0xe] - (0xff < sVar4);
              cVar83 = (0 < sStack_15a) * (sStack_15a < 0x100) * auVar745[2] - (0xff < sStack_15a);
              cVar85 = (0 < sStack_156) * (sStack_156 < 0x100) * auVar745[6] - (0xff < sStack_156);
              cVar82 = (0 < sStack_152) * (sStack_152 < 0x100) * auVar745[10] - (0xff < sStack_152);
              cVar81 = (0 < sStack_14e) * (sStack_14e < 0x100) * auVar745[0xe] - (0xff < sStack_14e)
              ;
              uVar594 = CONCAT13(cVar166,CONCAT12((uVar753 != 0) * (uVar753 < 0x100) * auVar371[5] -
                                                  (0xff < uVar753),
                                                  CONCAT11(bVar125,(uVar747 != 0) *
                                                                   (uVar747 < 0x100) * auVar371[1] -
                                                                   (0xff < uVar747))));
              uVar596 = CONCAT15(cVar167,CONCAT14((uVar755 != 0) * (uVar755 < 0x100) * auVar371[9] -
                                                  (0xff < uVar755),uVar594));
              uVar597 = CONCAT17(cVar168,CONCAT16((uVar765 != 0) * (uVar765 < 0x100) *
                                                  (char)((uint)uVar593 >> 8) - (0xff < uVar765),
                                                  uVar596));
              Var370 = CONCAT19(cVar169,CONCAT18((uVar725 != 0) * (uVar725 < 0x100) * auVar605[1] -
                                                 (0xff < uVar725),uVar597));
              auVar375[10] = (uVar764 != 0) * (uVar764 < 0x100) * auVar605[5] - (0xff < uVar764);
              auVar375._0_10_ = Var370;
              auVar375[0xb] = cVar170;
              auVar376[0xc] = (uVar684 != 0) * (uVar684 < 0x100) * auVar605[9] - (0xff < uVar684);
              auVar376._0_12_ = auVar375;
              auVar376[0xd] = cVar171;
              auVar605[0xe] = (uVar692 != 0) * (uVar692 < 0x100) * auVar605[0xd] - (0xff < uVar692);
              auVar605._0_14_ = auVar376;
              auVar605[0xf] = cVar172;
              uVar764 = (ushort)bVar125;
              uVar725 = (ushort)((uint)uVar594 >> 0x18);
              uVar692 = (ushort)((uint6)uVar596 >> 0x28);
              uVar683 = (ushort)((ulonglong)uVar597 >> 0x38);
              uVar735 = (ushort)((unkuint10)Var370 >> 0x48);
              uVar684 = auVar375._10_2_ >> 8;
              uVar761 = auVar376._12_2_ >> 8;
              uVar719 = auVar605._14_2_ >> 8;
              auVar605 = _DAT_00267f50 & auVar605;
              uVar593 = CONCAT13(cVar180,CONCAT12((uVar740 != 0) * (uVar740 < 0x100) * auVar607[5] -
                                                  (0xff < uVar740),
                                                  CONCAT11(bVar124,(uVar727 != 0) *
                                                                   (uVar727 < 0x100) * auVar607[1] -
                                                                   (0xff < uVar727))));
              uVar596 = CONCAT15(cVar181,CONCAT14((uVar759 != 0) * (uVar759 < 0x100) * auVar607[9] -
                                                  (0xff < uVar759),uVar593));
              uVar597 = CONCAT17(cVar182,CONCAT16((uVar691 != 0) * (uVar691 < 0x100) * auVar607[0xd]
                                                  - (0xff < uVar691),uVar596));
              Var370 = CONCAT19(cVar183,CONCAT18((uVar743 != 0) * (uVar743 < 0x100) *
                                                 (char)((uint5)uVar398 >> 8) - (0xff < uVar743),
                                                 uVar597));
              auVar381[10] = (uVar751 != 0) * (uVar751 < 0x100) * cStack_97 - (0xff < uVar751);
              auVar381._0_10_ = Var370;
              auVar381[0xb] = cVar184;
              auVar382[0xc] = (uVar757 != 0) * (uVar757 < 0x100) * cStack_93 - (0xff < uVar757);
              auVar382._0_12_ = auVar381;
              auVar382[0xd] = cVar185;
              auVar660[0xe] = (uVar763 != 0) * (uVar763 < 0x100) * cStack_8f - (0xff < uVar763);
              auVar660._0_14_ = auVar382;
              auVar660[0xf] = cVar186;
              sVar4 = auVar658._0_2_;
              sVar11 = auVar658._2_2_;
              bVar229 = (0 < sVar11) * (sVar11 < 0x100) * auVar658[2] - (0xff < sVar11);
              sVar11 = auVar658._4_2_;
              sVar12 = auVar658._6_2_;
              cVar173 = (0 < sVar12) * (sVar12 < 0x100) * auVar658[6] - (0xff < sVar12);
              uVar698 = CONCAT13(cVar173,CONCAT12((0 < sVar11) * (sVar11 < 0x100) * auVar658[4] -
                                                  (0xff < sVar11),
                                                  CONCAT11(bVar229,(0 < sVar4) * (sVar4 < 0x100) *
                                                                   auVar658[0] - (0xff < sVar4))));
              sVar4 = auVar658._8_2_;
              sVar11 = auVar658._10_2_;
              cVar174 = (0 < sVar11) * (sVar11 < 0x100) * auVar658[10] - (0xff < sVar11);
              uVar807 = CONCAT15(cVar174,CONCAT14((0 < sVar4) * (sVar4 < 0x100) * auVar658[8] -
                                                  (0xff < sVar4),uVar698));
              sVar4 = auVar658._12_2_;
              sVar11 = auVar658._14_2_;
              cVar175 = (0 < sVar11) * (sVar11 < 0x100) * auVar658[0xe] - (0xff < sVar11);
              uVar703 = CONCAT17(cVar175,CONCAT16((0 < sVar4) * (sVar4 < 0x100) * auVar658[0xc] -
                                                  (0xff < sVar4),uVar807));
              sVar4 = auVar605._0_2_;
              sVar11 = auVar605._2_2_;
              cVar176 = (0 < sVar11) * (sVar11 < 0x100) * auVar605[2] - (0xff < sVar11);
              auVar811._0_10_ =
                   CONCAT19(cVar176,CONCAT18((0 < sVar4) * (sVar4 < 0x100) * auVar605[0] -
                                             (0xff < sVar4),uVar703));
              sVar4 = auVar605._4_2_;
              auVar811[10] = (0 < sVar4) * (sVar4 < 0x100) * auVar605[4] - (0xff < sVar4);
              sVar4 = auVar605._6_2_;
              cVar177 = (0 < sVar4) * (sVar4 < 0x100) * auVar605[6] - (0xff < sVar4);
              auVar811[0xb] = cVar177;
              sVar4 = auVar605._8_2_;
              auVar814[0xc] = (0 < sVar4) * (sVar4 < 0x100) * auVar605[8] - (0xff < sVar4);
              auVar814._0_12_ = auVar811;
              sVar4 = auVar605._10_2_;
              cVar178 = (0 < sVar4) * (sVar4 < 0x100) * auVar605[10] - (0xff < sVar4);
              auVar814[0xd] = cVar178;
              sVar4 = auVar605._12_2_;
              auVar818[0xe] = (0 < sVar4) * (sVar4 < 0x100) * auVar605[0xc] - (0xff < sVar4);
              auVar818._0_14_ = auVar814;
              sVar4 = auVar605._14_2_;
              cVar179 = (0 < sVar4) * (sVar4 < 0x100) * auVar605[0xe] - (0xff < sVar4);
              auVar818[0xf] = cVar179;
              bVar230 = (uVar733 != 0) * (uVar733 < 0x100) * cVar155 - (0xff < uVar733);
              cVar188 = (uVar644 != 0) * (uVar644 < 0x100) * cVar157 - (0xff < uVar644);
              cVar187 = (uVar685 != 0) * (uVar685 < 0x100) * cVar159 - (0xff < uVar685);
              cVar161 = (uVar693 != 0) * (uVar693 < 0x100) * cVar161 - (0xff < uVar693);
              cVar166 = (uVar725 != 0) * (uVar725 < 0x100) * cVar166 - (0xff < uVar725);
              cVar159 = (uVar683 != 0) * (uVar683 < 0x100) * cVar168 - (0xff < uVar683);
              cVar157 = (uVar684 != 0) * (uVar684 < 0x100) * cVar170 - (0xff < uVar684);
              cVar155 = (uVar719 != 0) * (uVar719 < 0x100) * cVar172 - (0xff < uVar719);
              auVar607 = _DAT_00267f50 & auVar660;
              auVar658 = _DAT_00267f50 & auVar773;
              uVar747 = (ushort)bVar122;
              uVar727 = (ushort)((uint)uVar592 >> 0x18);
              uVar753 = (ushort)((uint6)uVar766 >> 0x28);
              uVar740 = (ushort)((ulonglong)uVar767 >> 0x38);
              uVar748 = (ushort)((unkuint10)auVar769._0_10_ >> 0x48);
              uVar754 = auVar769._10_2_ >> 8;
              uVar755 = auVar771._12_2_ >> 8;
              uVar759 = auVar773._14_2_ >> 8;
              uVar725 = (ushort)bVar124;
              uVar733 = (ushort)((uint)uVar593 >> 0x18);
              uVar644 = (ushort)((uint6)uVar596 >> 0x28);
              uVar683 = (ushort)((ulonglong)uVar597 >> 0x38);
              uVar684 = (ushort)((unkuint10)Var370 >> 0x48);
              uVar685 = auVar381._10_2_ >> 8;
              uVar693 = auVar382._12_2_ >> 8;
              uVar719 = auVar660._14_2_ >> 8;
              uVar593 = CONCAT13(cVar80,CONCAT12((0 < sVar777) * (sVar777 < 0x100) * auVar661[4] -
                                                 (0xff < sVar777),
                                                 CONCAT11(bVar70,(0 < sVar718) * (sVar718 < 0x100) *
                                                                 auVar661[0] - (0xff < sVar718))));
              uVar596 = CONCAT15(cVar79,CONCAT14((0 < sVar778) * (sVar778 < 0x100) * auVar661[8] -
                                                 (0xff < sVar778),uVar593));
              uVar597 = CONCAT17(cVar84,CONCAT16((0 < sVar779) * (sVar779 < 0x100) * auVar661[0xc] -
                                                 (0xff < sVar779),uVar596));
              Var370 = CONCAT19(cVar83,CONCAT18((0 < local_15c) * (local_15c < 0x100) * auVar745[0]
                                                - (0xff < local_15c),uVar597));
              auVar385[10] = (0 < sStack_158) * (sStack_158 < 0x100) * auVar745[4] -
                             (0xff < sStack_158);
              auVar385._0_10_ = Var370;
              auVar385[0xb] = cVar85;
              auVar386[0xc] =
                   (0 < sStack_154) * (sStack_154 < 0x100) * auVar745[8] - (0xff < sStack_154);
              auVar386._0_12_ = auVar385;
              auVar386[0xd] = cVar82;
              auVar745[0xe] =
                   (0 < sStack_150) * (sStack_150 < 0x100) * auVar745[0xc] - (0xff < sStack_150);
              auVar745._0_14_ = auVar386;
              auVar745[0xf] = cVar81;
              sVar718 = auVar607._0_2_;
              bVar231 = (0 < sVar718) * (sVar718 < 0x100) * auVar607[0] - (0xff < sVar718);
              sVar718 = auVar607._2_2_;
              bVar232 = (0 < sVar718) * (sVar718 < 0x100) * auVar607[2] - (0xff < sVar718);
              sVar718 = auVar607._4_2_;
              bVar233 = (0 < sVar718) * (sVar718 < 0x100) * auVar607[4] - (0xff < sVar718);
              sVar718 = auVar607._6_2_;
              bVar234 = (0 < sVar718) * (sVar718 < 0x100) * auVar607[6] - (0xff < sVar718);
              sVar718 = auVar607._8_2_;
              bVar235 = (0 < sVar718) * (sVar718 < 0x100) * auVar607[8] - (0xff < sVar718);
              sVar718 = auVar607._10_2_;
              bVar236 = (0 < sVar718) * (sVar718 < 0x100) * auVar607[10] - (0xff < sVar718);
              sVar718 = auVar607._12_2_;
              bVar237 = (0 < sVar718) * (sVar718 < 0x100) * auVar607[0xc] - (0xff < sVar718);
              sVar718 = auVar607._14_2_;
              bVar238 = (0 < sVar718) * (sVar718 < 0x100) * auVar607[0xe] - (0xff < sVar718);
              sVar718 = auVar658._0_2_;
              bVar239 = (0 < sVar718) * (sVar718 < 0x100) * auVar658[0] - (0xff < sVar718);
              sVar718 = auVar658._2_2_;
              bVar240 = (0 < sVar718) * (sVar718 < 0x100) * auVar658[2] - (0xff < sVar718);
              sVar718 = auVar658._4_2_;
              bVar241 = (0 < sVar718) * (sVar718 < 0x100) * auVar658[4] - (0xff < sVar718);
              sVar718 = auVar658._6_2_;
              bVar242 = (0 < sVar718) * (sVar718 < 0x100) * auVar658[6] - (0xff < sVar718);
              sVar718 = auVar658._8_2_;
              bVar243 = (0 < sVar718) * (sVar718 < 0x100) * auVar658[8] - (0xff < sVar718);
              sVar718 = auVar658._10_2_;
              bVar244 = (0 < sVar718) * (sVar718 < 0x100) * auVar658[10] - (0xff < sVar718);
              sVar718 = auVar658._12_2_;
              bVar245 = (0 < sVar718) * (sVar718 < 0x100) * auVar658[0xc] - (0xff < sVar718);
              sVar718 = auVar658._14_2_;
              bVar246 = (0 < sVar718) * (sVar718 < 0x100) * auVar658[0xe] - (0xff < sVar718);
              bVar247 = (uVar733 != 0) * (uVar733 < 0x100) * cVar180 - (0xff < uVar733);
              cVar182 = (uVar683 != 0) * (uVar683 < 0x100) * cVar182 - (0xff < uVar683);
              uVar594 = CONCAT13(cVar182,CONCAT12((uVar644 != 0) * (uVar644 < 0x100) * cVar181 -
                                                  (0xff < uVar644),
                                                  CONCAT11(bVar247,(uVar725 != 0) *
                                                                   (uVar725 < 0x100) * bVar124 -
                                                                   (0xff < uVar725))));
              cVar184 = (uVar685 != 0) * (uVar685 < 0x100) * cVar184 - (0xff < uVar685);
              uVar647 = CONCAT15(cVar184,CONCAT14((uVar684 != 0) * (uVar684 < 0x100) * cVar183 -
                                                  (0xff < uVar684),uVar594));
              cVar186 = (uVar719 != 0) * (uVar719 < 0x100) * cVar186 - (0xff < uVar719);
              uVar598 = CONCAT17(cVar186,CONCAT16((uVar693 != 0) * (uVar693 < 0x100) * cVar185 -
                                                  (0xff < uVar693),uVar647));
              cVar180 = (uVar727 != 0) * (uVar727 < 0x100) * cVar194 - (0xff < uVar727);
              auVar652._0_10_ =
                   CONCAT19(cVar180,CONCAT18((uVar747 != 0) * (uVar747 < 0x100) * bVar122 -
                                             (0xff < uVar747),uVar598));
              auVar652[10] = (uVar753 != 0) * (uVar753 < 0x100) * cVar195 - (0xff < uVar753);
              cVar168 = (uVar740 != 0) * (uVar740 < 0x100) * cVar196 - (0xff < uVar740);
              auVar652[0xb] = cVar168;
              auVar655[0xc] = (uVar748 != 0) * (uVar748 < 0x100) * cVar197 - (0xff < uVar748);
              auVar655._0_12_ = auVar652;
              cVar172 = (uVar754 != 0) * (uVar754 < 0x100) * cVar198 - (0xff < uVar754);
              auVar655[0xd] = cVar172;
              auVar663[0xe] = (uVar755 != 0) * (uVar755 < 0x100) * cVar199 - (0xff < uVar755);
              auVar663._0_14_ = auVar655;
              cVar170 = (uVar759 != 0) * (uVar759 < 0x100) * cVar200 - (0xff < uVar759);
              auVar663[0xf] = cVar170;
              auVar658 = _DAT_00267f50 & auVar745;
              auVar656 = _DAT_00267f50 & auVar715;
              uVar683 = (ushort)bVar135;
              uVar685 = (ushort)((uint)uVar645 >> 0x18);
              uVar719 = (ushort)((uint6)uVar701 >> 0x28);
              uVar727 = (ushort)((ulonglong)uVar649 >> 0x38);
              uVar740 = (ushort)((unkuint10)auVar707._0_10_ >> 0x48);
              uVar695 = auVar707._10_2_ >> 8;
              uVar721 = auVar711._12_2_ >> 8;
              uVar729 = auVar715._14_2_ >> 8;
              sVar718 = auVar658._0_2_;
              sVar4 = auVar658._2_2_;
              sVar17 = auVar658._4_2_;
              sVar24 = auVar658._6_2_;
              sVar31 = auVar658._8_2_;
              sVar38 = auVar658._10_2_;
              sVar45 = auVar658._12_2_;
              sVar777 = auVar658._14_2_;
              cVar185 = (0 < sVar777) * (sVar777 < 0x100) * auVar658[0xe] - (0xff < sVar777);
              sVar777 = auVar656._0_2_;
              bVar124 = (0 < sVar777) * (sVar777 < 0x100) * auVar656[0] - (0xff < sVar777);
              uVar725 = CONCAT11(bVar124,cVar185);
              sVar777 = auVar656._2_2_;
              cVar181 = (0 < sVar777) * (sVar777 < 0x100) * auVar656[2] - (0xff < sVar777);
              uVar464 = CONCAT12(cVar181,uVar725);
              sVar777 = auVar656._4_2_;
              bVar122 = (0 < sVar777) * (sVar777 < 0x100) * auVar656[4] - (0xff < sVar777);
              uVar299 = CONCAT13(bVar122,uVar464);
              sVar777 = auVar656._6_2_;
              cVar183 = (0 < sVar777) * (sVar777 < 0x100) * auVar656[6] - (0xff < sVar777);
              uVar398 = CONCAT14(cVar183,uVar299);
              sVar777 = auVar656._8_2_;
              bVar248 = (0 < sVar777) * (sVar777 < 0x100) * auVar656[8] - (0xff < sVar777);
              auVar534[5] = bVar248;
              auVar534._0_5_ = uVar398;
              sVar52 = auVar656._10_2_;
              sVar56 = auVar656._12_2_;
              sVar60 = auVar656._14_2_;
              uVar644 = (ushort)bVar70;
              uVar684 = (ushort)((uint)uVar593 >> 0x18);
              uVar693 = (ushort)((uint6)uVar596 >> 0x28);
              uVar747 = (ushort)((ulonglong)uVar597 >> 0x38);
              uVar753 = (ushort)((unkuint10)Var370 >> 0x48);
              uVar748 = auVar385._10_2_ >> 8;
              uVar759 = auVar386._12_2_ >> 8;
              uVar733 = auVar745._14_2_ >> 8;
              pauVar587 = pauVar587 + 8;
              cVar81 = (uVar733 != 0) * (uVar733 < 0x100) * cVar81 - (0xff < uVar733);
              bVar135 = (uVar683 != 0) * (uVar683 < 0x100) * bVar135 - (0xff < uVar683);
              uVar733 = CONCAT11(bVar135,cVar81);
              cVar189 = (uVar685 != 0) * (uVar685 < 0x100) * cVar207 - (0xff < uVar685);
              uVar465 = CONCAT12(cVar189,uVar733);
              bVar249 = (uVar719 != 0) * (uVar719 < 0x100) * cVar208 - (0xff < uVar719);
              uVar300 = CONCAT13(bVar249,uVar465);
              cVar190 = (uVar727 != 0) * (uVar727 < 0x100) * cVar209 - (0xff < uVar727);
              uVar399 = CONCAT14(cVar190,uVar300);
              bVar250 = (uVar740 != 0) * (uVar740 < 0x100) * cVar210 - (0xff < uVar740);
              auVar535[5] = bVar250;
              auVar535._0_5_ = uVar399;
              auVar605 = _DAT_00267f50 & auVar818;
              uVar757 = (ushort)bVar229;
              uVar762 = (ushort)((uint)uVar698 >> 0x18);
              uVar763 = (ushort)((uint6)uVar807 >> 0x28);
              uVar820 = (ushort)((ulonglong)uVar703 >> 0x38);
              uVar822 = (ushort)((unkuint10)auVar811._0_10_ >> 0x48);
              uVar824 = auVar811._10_2_ >> 8;
              uVar827 = auVar814._12_2_ >> 8;
              uVar755 = auVar818._14_2_ >> 8;
              sVar777 = auVar605._0_2_;
              sVar11 = auVar605._2_2_;
              sVar18 = auVar605._4_2_;
              sVar25 = auVar605._6_2_;
              sVar32 = auVar605._8_2_;
              sVar39 = auVar605._10_2_;
              sVar46 = auVar605._12_2_;
              sVar778 = auVar605._14_2_;
              cVar191 = (0 < sVar778) * (sVar778 < 0x100) * auVar605[0xe] - (0xff < sVar778);
              bVar251 = (bVar231 != 0) * (bVar231 < 0x100) * bVar231 - (0xff < bVar231);
              cVar193 = (bVar233 != 0) * (bVar233 < 0x100) * bVar233 - (0xff < bVar233);
              bVar231 = (bVar235 != 0) * (bVar235 < 0x100) * bVar235 - (0xff < bVar235);
              cVar192 = (bVar237 != 0) * (bVar237 < 0x100) * bVar237 - (0xff < bVar237);
              bVar239 = (bVar239 != 0) * (bVar239 < 0x100) * bVar239 - (0xff < bVar239);
              uVar683 = (ushort)bVar232;
              uVar685 = (ushort)(((uint)bVar234 << 0x18) >> 0x18);
              uVar719 = (ushort)(((uint6)bVar236 << 0x28) >> 0x28);
              uVar727 = (ushort)(((ulonglong)bVar238 << 0x38) >> 0x38);
              uVar740 = (ushort)((uint3)((uint3)bVar240 << 0x10) >> 0x10);
              uVar754 = (ushort)(((uint5)bVar242 << 0x20) >> 0x20);
              uVar765 = (ushort)(((uint7)bVar244 << 0x30) >> 0x30);
              uVar780 = (ushort)((uint3)((uint3)bVar246 << 0x10) >> 0x10);
              uVar593 = CONCAT13(cVar201,CONCAT12((uVar819 != 0) * (uVar819 < 0x100) * cVar152 -
                                                  (0xff < uVar819),
                                                  CONCAT11(bVar129,(uVar806 != 0) *
                                                                   (uVar806 < 0x100) * bVar128 -
                                                                   (0xff < uVar806))));
              uVar596 = CONCAT15(cVar202,CONCAT14((uVar821 != 0) * (uVar821 < 0x100) * cVar153 -
                                                  (0xff < uVar821),uVar593));
              uVar597 = CONCAT17(cVar203,CONCAT16((uVar826 != 0) * (uVar826 < 0x100) * cVar154 -
                                                  (0xff < uVar826),uVar596));
              Var370 = CONCAT19(cVar204,CONCAT18((uVar696 != 0) * (uVar696 < 0x100) * bVar126 -
                                                 (0xff < uVar696),uVar597));
              auVar388[10] = (uVar722 != 0) * (uVar722 < 0x100) * cVar162 - (0xff < uVar722);
              auVar388._0_10_ = Var370;
              auVar388[0xb] = cVar163;
              auVar389[0xc] = (uVar730 != 0) * (uVar730 < 0x100) * cVar164 - (0xff < uVar730);
              auVar389._0_12_ = auVar388;
              auVar389[0xd] = cVar205;
              auVar387[0xe] = (uVar738 != 0) * (uVar738 < 0x100) * cVar165 - (0xff < uVar738);
              auVar387._0_14_ = auVar389;
              auVar387[0xf] = cVar206;
              cVar154 = (uVar755 != 0) * (uVar755 < 0x100) * cVar179 - (0xff < uVar755);
              bVar128 = (uVar683 != 0) * (uVar683 < 0x100) * bVar232 - (0xff < uVar683);
              cVar153 = (uVar685 != 0) * (uVar685 < 0x100) * bVar234 - (0xff < uVar685);
              bVar126 = (uVar719 != 0) * (uVar719 < 0x100) * bVar236 - (0xff < uVar719);
              cVar152 = (uVar727 != 0) * (uVar727 < 0x100) * bVar238 - (0xff < uVar727);
              bVar234 = (uVar740 != 0) * (uVar740 < 0x100) * bVar240 - (0xff < uVar740);
              auVar815 = _DAT_00267f50 & auVar387;
              uVar696 = (ushort)bVar129;
              uVar722 = (ushort)((uint)uVar593 >> 0x18);
              uVar730 = (ushort)((uint6)uVar596 >> 0x28);
              uVar737 = (ushort)((ulonglong)uVar597 >> 0x38);
              uVar738 = (ushort)((unkuint10)Var370 >> 0x48);
              uVar742 = auVar388._10_2_ >> 8;
              uVar743 = auVar389._12_2_ >> 8;
              uVar750 = auVar387._14_2_ >> 8;
              sVar778 = auVar815._0_2_;
              sVar12 = auVar815._2_2_;
              sVar19 = auVar815._4_2_;
              sVar26 = auVar815._6_2_;
              sVar33 = auVar815._8_2_;
              sVar40 = auVar815._10_2_;
              sVar47 = auVar815._12_2_;
              sVar779 = auVar815._14_2_;
              cVar165 = (0 < sVar779) * (sVar779 < 0x100) * auVar815[0xe] - (0xff < sVar779);
              bVar214 = (bVar214 != 0) * (bVar214 < 0x100) * bVar214 - (0xff < bVar214);
              cVar164 = (bVar216 != 0) * (bVar216 < 0x100) * bVar216 - (0xff < bVar216);
              bVar218 = (bVar218 != 0) * (bVar218 < 0x100) * bVar218 - (0xff < bVar218);
              cVar162 = (bVar220 != 0) * (bVar220 < 0x100) * bVar220 - (0xff < bVar220);
              bVar220 = (bVar222 != 0) * (bVar222 < 0x100) * bVar222 - (0xff < bVar222);
              uVar683 = (ushort)bVar215;
              uVar685 = (ushort)bVar217;
              uVar719 = (ushort)bVar219;
              uVar727 = (ushort)bVar221;
              uVar740 = (ushort)bVar223;
              uVar755 = (ushort)bVar225;
              uVar691 = (ushort)bVar227;
              uVar781 = (ushort)bVar123;
              cVar179 = (uVar750 != 0) * (uVar750 < 0x100) * cVar206 - (0xff < uVar750);
              bVar216 = (uVar683 != 0) * (uVar683 < 0x100) * bVar215 - (0xff < uVar683);
              cVar198 = (uVar685 != 0) * (uVar685 < 0x100) * bVar217 - (0xff < uVar685);
              bVar219 = (uVar719 != 0) * (uVar719 < 0x100) * bVar219 - (0xff < uVar719);
              cVar200 = (uVar727 != 0) * (uVar727 < 0x100) * bVar221 - (0xff < uVar727);
              bVar223 = (uVar740 != 0) * (uVar740 < 0x100) * bVar223 - (0xff < uVar740);
              uVar593 = CONCAT13(cVar188,CONCAT12((uVar686 != 0) * (uVar686 < 0x100) * cVar156 -
                                                  (0xff < uVar686),
                                                  CONCAT11(bVar230,(uVar746 != 0) *
                                                                   (uVar746 < 0x100) * bVar127 -
                                                                   (0xff < uVar746))));
              uVar596 = CONCAT15(cVar187,CONCAT14((uVar749 != 0) * (uVar749 < 0x100) * cVar158 -
                                                  (0xff < uVar749),uVar593));
              uVar597 = CONCAT17(cVar161,CONCAT16((uVar760 != 0) * (uVar760 < 0x100) * cVar160 -
                                                  (0xff < uVar760),uVar596));
              Var370 = CONCAT19(cVar166,CONCAT18((uVar764 != 0) * (uVar764 < 0x100) * bVar125 -
                                                 (0xff < uVar764),uVar597));
              auVar377[10] = (uVar692 != 0) * (uVar692 < 0x100) * cVar167 - (0xff < uVar692);
              auVar377._0_10_ = Var370;
              auVar377[0xb] = cVar159;
              auVar378[0xc] = (uVar735 != 0) * (uVar735 < 0x100) * cVar169 - (0xff < uVar735);
              auVar378._0_12_ = auVar377;
              auVar378[0xd] = cVar157;
              auVar607[0xe] = (uVar761 != 0) * (uVar761 < 0x100) * cVar171 - (0xff < uVar761);
              auVar607._0_14_ = auVar378;
              auVar607[0xf] = cVar155;
              auVar660 = _DAT_00267f50 & auVar607;
              uVar764 = (ushort)bVar230;
              uVar685 = (ushort)((uint)uVar593 >> 0x18);
              uVar692 = (ushort)((uint6)uVar596 >> 0x28);
              uVar727 = (ushort)((ulonglong)uVar597 >> 0x38);
              uVar749 = (ushort)((unkuint10)Var370 >> 0x48);
              uVar740 = auVar377._10_2_ >> 8;
              uVar761 = auVar378._12_2_ >> 8;
              uVar751 = auVar607._14_2_ >> 8;
              uVar746 = (ushort)bVar247;
              uVar683 = (ushort)((uint)uVar594 >> 0x18);
              uVar686 = (ushort)((uint6)uVar647 >> 0x28);
              uVar719 = (ushort)((ulonglong)uVar598 >> 0x38);
              uVar735 = (ushort)((unkuint10)auVar652._0_10_ >> 0x48);
              uVar760 = auVar652._10_2_ >> 8;
              uVar750 = auVar655._12_2_ >> 8;
              uVar756 = auVar663._14_2_ >> 8;
              auVar663 = _DAT_00267f50 & auVar663;
              sVar779 = auVar660._0_2_;
              sVar13 = auVar660._2_2_;
              sVar20 = auVar660._4_2_;
              sVar27 = auVar660._6_2_;
              sVar34 = auVar660._8_2_;
              sVar41 = auVar660._10_2_;
              sVar48 = auVar660._12_2_;
              sVar49 = auVar660._14_2_;
              cVar156 = (0 < sVar49) * (sVar49 < 0x100) * auVar660[0xe] - (0xff < sVar49);
              sVar49 = auVar663._0_2_;
              bVar127 = (0 < sVar49) * (sVar49 < 0x100) * auVar663[0] - (0xff < sVar49);
              sVar49 = auVar663._2_2_;
              cVar158 = (0 < sVar49) * (sVar49 < 0x100) * auVar663[2] - (0xff < sVar49);
              sVar49 = auVar663._4_2_;
              bVar125 = (0 < sVar49) * (sVar49 < 0x100) * auVar663[4] - (0xff < sVar49);
              sVar49 = auVar663._6_2_;
              cVar160 = (0 < sVar49) * (sVar49 < 0x100) * auVar663[6] - (0xff < sVar49);
              sVar49 = auVar663._8_2_;
              bVar221 = (0 < sVar49) * (sVar49 < 0x100) * auVar663[8] - (0xff < sVar49);
              sVar53 = auVar663._10_2_;
              sVar57 = auVar663._12_2_;
              sVar61 = auVar663._14_2_;
              cVar169 = (uVar751 != 0) * (uVar751 < 0x100) * cVar155 - (0xff < uVar751);
              bVar217 = (uVar746 != 0) * (uVar746 < 0x100) * bVar247 - (0xff < uVar746);
              cVar155 = (uVar683 != 0) * (uVar683 < 0x100) * cVar182 - (0xff < uVar683);
              bVar215 = (uVar686 != 0) * (uVar686 < 0x100) * cVar184 - (0xff < uVar686);
              cVar171 = (uVar719 != 0) * (uVar719 < 0x100) * cVar186 - (0xff < uVar719);
              bVar222 = (uVar735 != 0) * (uVar735 < 0x100) * cVar180 - (0xff < uVar735);
              uVar641 = CONCAT13(0,CONCAT12(cVar181,(ushort)bVar124));
              auVar534._6_8_ = 0;
              auVar254[0xe] = cVar185;
              auVar254._0_14_ = auVar534 << 0x38;
              auVar502._4_8_ = 0;
              auVar502._0_4_ = uVar299;
              auVar286._12_3_ =
                   (int3)(CONCAT26(auVar254._13_2_,
                                   CONCAT15((0 < sVar45) * (sVar45 < 0x100) * auVar658[0xc] -
                                            (0xff < sVar45),uVar398)) >> 0x28);
              auVar286._0_12_ = auVar502 << 0x38;
              uVar299 = auVar286._11_4_;
              uVar649 = CONCAT44(uVar299,CONCAT13((0 < sVar38) * (sVar38 < 0x100) * auVar658[10] -
                                                  (0xff < sVar38),uVar464));
              auVar340._10_5_ = (int5)((ulonglong)uVar649 >> 0x18);
              auVar340._0_10_ = (unkuint10)uVar725 << 0x38;
              uVar597 = CONCAT62(auVar340._9_6_,
                                 CONCAT11((0 < sVar31) * (sVar31 < 0x100) * auVar658[8] -
                                          (0xff < sVar31),cVar185));
              auVar400._7_8_ = 0;
              auVar400._0_7_ = (uint7)((ulonglong)uVar597 >> 8);
              Var401 = CONCAT81(SUB158(auVar400 << 0x40,7),
                                (0 < sVar24) * (sVar24 < 0x100) * auVar658[6] - (0xff < sVar24));
              auVar470._9_6_ = 0;
              auVar470._0_9_ = Var401;
              auVar402._1_10_ = SUB1510(auVar470 << 0x30,5);
              auVar402[0] = (0 < sVar17) * (sVar17 < 0x100) * auVar658[4] - (0xff < sVar17);
              auVar471._11_4_ = 0;
              auVar471._0_11_ = auVar402;
              auVar403._1_12_ = SUB1512(auVar471 << 0x20,3);
              auVar403[0] = (0 < sVar4) * (sVar4 < 0x100) * auVar658[2] - (0xff < sVar4);
              uVar725 = CONCAT11(0,(0 < sVar718) * (sVar718 < 0x100) * auVar658[0] -
                                   (0xff < sVar718));
              auVar356._2_13_ = auVar403;
              auVar356._0_2_ = uVar725;
              auVar535._6_8_ = 0;
              auVar255[0xe] = cVar81;
              auVar255._0_14_ = auVar535 << 0x38;
              auVar503._4_8_ = 0;
              auVar503._0_4_ = uVar300;
              auVar287._12_3_ =
                   (int3)(CONCAT26(auVar255._13_2_,
                                   CONCAT15((uVar759 != 0) * (uVar759 < 0x100) * cVar82 -
                                            (0xff < uVar759),uVar399)) >> 0x28);
              auVar287._0_12_ = auVar503 << 0x38;
              uVar300 = auVar287._11_4_;
              uVar703 = CONCAT44(uVar300,CONCAT13((uVar748 != 0) * (uVar748 < 0x100) * cVar85 -
                                                  (0xff < uVar748),uVar465));
              auVar341._10_5_ = (int5)((ulonglong)uVar703 >> 0x18);
              auVar341._0_10_ = (unkuint10)uVar733 << 0x38;
              uVar598 = CONCAT62(auVar341._9_6_,
                                 CONCAT11((uVar753 != 0) * (uVar753 < 0x100) * cVar83 -
                                          (0xff < uVar753),cVar81));
              auVar404._7_8_ = 0;
              auVar404._0_7_ = (uint7)((ulonglong)uVar598 >> 8);
              Var405 = CONCAT81(SUB158(auVar404 << 0x40,7),
                                (uVar747 != 0) * (uVar747 < 0x100) * cVar84 - (0xff < uVar747));
              auVar472._9_6_ = 0;
              auVar472._0_9_ = Var405;
              auVar406._1_10_ = SUB1510(auVar472 << 0x30,5);
              auVar406[0] = (uVar693 != 0) * (uVar693 < 0x100) * cVar79 - (0xff < uVar693);
              auVar473._11_4_ = 0;
              auVar473._0_11_ = auVar406;
              auVar407._1_12_ = SUB1512(auVar473 << 0x20,3);
              auVar407[0] = (uVar684 != 0) * (uVar684 < 0x100) * cVar80 - (0xff < uVar684);
              auVar357[1] = 0;
              auVar357[0] = (uVar644 != 0) * (uVar644 < 0x100) * bVar70 - (0xff < uVar644);
              auVar357._2_13_ = auVar407;
              uVar699 = CONCAT13(0,CONCAT12(cVar189,(ushort)bVar135));
              auVar280._10_2_ = 0;
              auVar280._0_10_ = auVar354._0_10_;
              auVar280._12_2_ = (short)Var391;
              uVar536 = CONCAT42(auVar280._10_4_,auVar392._0_2_);
              auVar408._6_8_ = 0;
              auVar408._0_6_ = uVar536;
              auVar256._10_2_ = 0;
              auVar256._0_10_ = auVar355._0_10_;
              auVar256._12_2_ = (short)Var395;
              uVar537 = CONCAT42(auVar256._10_4_,auVar396._0_2_);
              auVar409._6_8_ = 0;
              auVar409._0_6_ = uVar537;
              auVar301._4_2_ = auVar397._0_2_;
              auVar301._0_4_ = auVar355._0_4_;
              auVar301._6_8_ = SUB148(auVar409 << 0x40,6);
              auVar257._10_2_ = 0;
              auVar257._0_10_ = auVar356._0_10_;
              auVar257._12_2_ = (short)Var401;
              uVar538 = CONCAT42(auVar257._10_4_,auVar402._0_2_);
              auVar410._6_8_ = 0;
              auVar410._0_6_ = uVar538;
              auVar258._10_2_ = 0;
              auVar258._0_10_ = auVar357._0_10_;
              auVar258._12_2_ = (short)Var405;
              uVar539 = CONCAT42(auVar258._10_4_,auVar406._0_2_);
              auVar411._6_8_ = 0;
              auVar411._0_6_ = uVar539;
              auVar302._4_2_ = auVar407._0_2_;
              auVar302._0_4_ = auVar357._0_4_;
              auVar302._6_8_ = SUB148(auVar411 << 0x40,6);
              iVar687 = (int)uVar539 + (int)uVar537 + (int)uVar536 + (int)uVar538;
              local_13c._8_2_ = (undefined2)((ulonglong)uVar702 >> 8);
              local_13c._10_2_ = (undefined2)((ulonglong)uVar501 >> 0x18);
              iVar700 = (uint)(ushort)local_13c._8_2_ + (uint)(ushort)((ulonglong)uVar648 >> 8) +
                        (uint)(ushort)((ulonglong)uVar597 >> 8) +
                        (uint)(ushort)((ulonglong)uVar598 >> 8);
              iVar724 = (uint)(ushort)local_13c._10_2_ + (uint)(ushort)((ulonglong)uVar499 >> 0x18)
                        + (uint)(ushort)((ulonglong)uVar649 >> 0x18) +
                        (uint)(ushort)((ulonglong)uVar703 >> 0x18);
              iVar732 = (uVar298 >> 8 & 0xffff) + (uVar297 >> 8 & 0xffff) + (uVar299 >> 8 & 0xffff)
                        + (uVar300 >> 8 & 0xffff);
              uVar688 = iVar687 >> 2;
              auVar664._0_10_ = (unkuint10)uVar688 << 0x40;
              auVar665._0_14_ = ZEXT414(uVar688) << 0x40;
              auVar665._14_2_ = (short)(iVar724 >> 0x12);
              auVar664._12_4_ = auVar665._12_4_;
              uVar723 = (undefined2)(iVar724 >> 2);
              auVar664._10_2_ = uVar723;
              uVar640 = (undefined2)
                        (auVar302._4_4_ +
                         auVar301._4_4_ + (int)CONCAT82(SUB148(auVar408 << 0x40,6),auVar393._0_2_) +
                         (int)CONCAT82(SUB148(auVar410 << 0x40,6),auVar403._0_2_) >> 2);
              auVar413._4_6_ = auVar664._10_6_;
              auVar413._2_2_ = uVar640;
              sVar718 = (short)(iVar700 >> 0x12);
              auVar413._0_2_ = sVar718;
              auVar413._10_6_ = 0;
              auVar673._0_2_ =
                   (undefined2)
                   ((int)((auVar357._0_4_ & 0xffff) +
                         (auVar355._0_4_ & 0xffff) + (uint)uVar716 + (uint)uVar725) >> 2);
              auVar412._12_4_ = 0;
              auVar412._0_12_ = SUB1612(auVar413 << 0x30,4);
              uVar731 = (undefined2)(iVar732 >> 2);
              auVar669._0_12_ = SUB1612(auVar412 << 0x20,0);
              auVar669._12_2_ = sVar718;
              auVar669._14_2_ = (short)(iVar732 >> 0x12);
              auVar668._12_4_ = auVar669._12_4_;
              auVar668._0_10_ = SUB1610(auVar412 << 0x20,0);
              auVar668._10_2_ = (short)(iVar687 >> 0x12);
              auVar667._10_6_ = auVar668._10_6_;
              auVar667._0_10_ = (unkuint10)0 << 0x40;
              auVar414._2_8_ = auVar667._8_8_;
              auVar414._0_2_ = uVar731;
              auVar414._10_6_ = 0;
              auVar666._12_4_ = 0;
              auVar666._0_12_ = SUB1612(auVar414 << 0x30,4);
              auVar666 = auVar666 << 0x20;
              auVar672._0_12_ = auVar666._0_12_;
              auVar672._12_2_ = uVar731;
              auVar672._14_2_ =
                   (short)((int)((uVar298 >> 0x18) + (uVar297 >> 0x18) + (uVar299 >> 0x18) +
                                (uVar300 >> 0x18)) >> 2);
              auVar671._12_4_ = auVar672._12_4_;
              auVar671._0_10_ = auVar666._0_10_;
              auVar671._10_2_ = uVar723;
              auVar670._10_6_ = auVar671._10_6_;
              auVar670._0_8_ = auVar666._0_8_;
              auVar670._8_2_ = (short)(iVar700 >> 2);
              auVar673._8_8_ = auVar670._8_8_;
              auVar673._6_2_ =
                   (short)((int)((auVar258._10_4_ >> 0x10) +
                                (auVar256._10_4_ >> 0x10) + (auVar280._10_4_ >> 0x10) +
                                (auVar257._10_4_ >> 0x10)) >> 2);
              auVar673._4_2_ = (short)uVar688;
              auVar673._2_2_ = uVar640;
              auVar504[0xc] = cVar87;
              auVar504._0_12_ = ZEXT112(bVar139) << 0x40;
              auVar505._10_3_ = auVar504._10_3_;
              auVar505._0_10_ = (unkuint10)bVar138 << 0x40;
              auVar303[4] = cVar113;
              auVar303._0_4_ = uVar646;
              auVar303[5] = 0;
              auVar303._6_8_ = SUB148(ZEXT514(auVar505._8_5_) << 0x40,6);
              auVar506[0xc] = cVar112;
              auVar506._0_12_ = ZEXT112(bVar137) << 0x40;
              auVar507._10_3_ = auVar506._10_3_;
              auVar507._0_10_ = (unkuint10)bVar136 << 0x40;
              auVar304[4] = cVar111;
              auVar304._0_4_ = uVar744;
              auVar304[5] = 0;
              auVar304._6_8_ = SUB148(ZEXT514(auVar507._8_5_) << 0x40,6);
              auVar305[0xc] = cVar183;
              auVar305._0_12_ = ZEXT112(bVar248) << 0x40;
              auVar306._10_3_ = auVar305._10_3_;
              auVar306._0_10_ = (unkuint10)bVar122 << 0x40;
              auVar415._5_8_ = 0;
              auVar415._0_5_ = auVar306._8_5_;
              auVar307[4] = cVar181;
              auVar307._0_4_ = uVar641;
              auVar307[5] = 0;
              auVar307._6_7_ = SUB137(auVar415 << 0x40,6);
              auVar308[0xc] = cVar190;
              auVar308._0_12_ = ZEXT112(bVar250) << 0x40;
              auVar309._10_3_ = auVar308._10_3_;
              auVar309._0_10_ = (unkuint10)bVar249 << 0x40;
              auVar416._5_8_ = 0;
              auVar416._0_5_ = auVar309._8_5_;
              auVar310[4] = cVar189;
              auVar310._0_4_ = uVar699;
              auVar310[5] = 0;
              auVar310._6_7_ = SUB137(auVar416 << 0x40,6);
              iVar687 = auVar505._8_4_ + auVar507._8_4_ + auVar306._8_4_ + auVar309._8_4_;
              auVar673 = auVar673 & _DAT_00267f50;
              auVar776._0_2_ =
                   (undefined2)
                   ((int)((uVar646 & 0xffff) + (uVar744 & 0xffff) + (uVar641 & 0xffff) +
                         (uVar699 & 0xffff)) >> 2);
              uVar640 = (undefined2)
                        ((int)((uint)(byte)((0 < sVar56) * (sVar56 < 0x100) * auVar656[0xc] -
                                           (0xff < sVar56)) +
                               (uint)(byte)((0 < sVar54) * (sVar54 < 0x100) * auVar659[0xc] -
                                           (0xff < sVar54)) +
                               (uint)(byte)((uVar825 != 0) * (uVar825 < 0x100) * cVar89 -
                                           (0xff < uVar825)) +
                              (uint)(byte)((uVar721 != 0) * (uVar721 < 0x100) * cVar212 -
                                          (0xff < uVar721))) >> 2);
              auVar579._10_2_ = (short)(iVar687 >> 0x12);
              auVar579._0_10_ = (unkuint10)0 << 0x40;
              auVar417._12_4_ = 0;
              auVar417._0_12_ = SUB1612(ZEXT616(CONCAT42(auVar579._8_4_,uVar640)) << 0x30,4);
              auVar775._0_12_ = SUB1612(auVar417 << 0x20,0);
              auVar775._12_2_ = uVar640;
              auVar775._14_2_ =
                   (short)((int)((uint)(byte)((0 < sVar60) * (sVar60 < 0x100) * auVar656[0xe] -
                                             (0xff < sVar60)) +
                                 (uint)(byte)((0 < sVar58) * (sVar58 < 0x100) * auVar659[0xe] -
                                             (0xff < sVar58)) +
                                 (uint)(byte)((uVar828 != 0) * (uVar828 < 0x100) * cVar88 -
                                             (0xff < uVar828)) +
                                (uint)(byte)((uVar729 != 0) * (uVar729 < 0x100) * cVar213 -
                                            (0xff < uVar729))) >> 2);
              auVar774._12_4_ = auVar775._12_4_;
              auVar774._0_10_ = SUB1610(auVar417 << 0x20,0);
              auVar774._10_2_ =
                   (short)((int)((uint)(byte)((0 < sVar52) * (sVar52 < 0x100) * auVar656[10] -
                                             (0xff < sVar52)) +
                                 (uint)(byte)((0 < sVar50) * (sVar50 < 0x100) * auVar659[10] -
                                             (0xff < sVar50)) +
                                 (uint)(byte)((uVar823 != 0) * (uVar823 < 0x100) * cVar90 -
                                             (0xff < uVar823)) +
                                (uint)(byte)((uVar695 != 0) * (uVar695 < 0x100) * cVar211 -
                                            (0xff < uVar695))) >> 2);
              auVar776._10_6_ = auVar774._10_6_;
              auVar776._8_2_ =
                   (short)((int)((uint)bVar248 + (uint)bVar137 + (uint)bVar139 + (uint)bVar250) >> 2
                          );
              auVar776._6_2_ =
                   (short)((int)((uint)(uint3)(auVar504._10_3_ >> 0x10) +
                                 (uint)(uint3)(auVar506._10_3_ >> 0x10) +
                                 (uint)(uint3)(auVar305._10_3_ >> 0x10) +
                                (uint)(uint3)(auVar308._10_3_ >> 0x10)) >> 2);
              auVar776._4_2_ = (short)(iVar687 >> 2);
              auVar776._2_2_ =
                   (short)(auVar303._4_4_ + auVar304._4_4_ + auVar307._4_4_ + auVar310._4_4_ >> 2);
              auVar776 = auVar776 & _DAT_00267f50;
              uVar716 = auVar673._0_2_;
              uVar746 = auVar673._2_2_;
              sVar718 = auVar673._4_2_;
              sVar4 = auVar673._6_2_;
              sVar17 = auVar673._8_2_;
              sVar24 = auVar673._10_2_;
              sVar31 = auVar673._12_2_;
              sVar38 = auVar673._14_2_;
              uVar644 = auVar776._0_2_;
              uVar686 = auVar776._2_2_;
              sVar45 = auVar776._4_2_;
              uVar693 = auVar776._6_2_;
              sVar49 = auVar776._8_2_;
              sVar50 = auVar776._10_2_;
              sVar52 = auVar776._12_2_;
              sVar54 = auVar776._14_2_;
              uVar688 = CONCAT13(0,CONCAT12(cVar92,(ushort)bVar140));
              auVar567._6_8_ = 0;
              auVar281[0xe] = cVar93;
              auVar281._0_14_ = auVar567 << 0x38;
              auVar555._4_8_ = 0;
              auVar555._0_4_ = uVar595;
              auVar311._12_3_ =
                   (int3)(CONCAT26(auVar281._13_2_,
                                   CONCAT15((0 < sVar42) * (sVar42 < 0x100) * auVar784[0xc] -
                                            (0xff < sVar42),uVar552)) >> 0x28);
              auVar311._0_12_ = auVar555 << 0x38;
              uVar300 = auVar311._11_4_;
              uVar499 = CONCAT44(uVar300,CONCAT13((0 < sVar35) * (sVar35 < 0x100) * auVar784[10] -
                                                  (0xff < sVar35),uVar549));
              auVar351._10_5_ = (int5)((ulonglong)uVar499 >> 0x18);
              auVar351._0_10_ = (unkuint10)uVar739 << 0x38;
              uVar597 = CONCAT62(auVar351._9_6_,
                                 CONCAT11((0 < sVar28) * (sVar28 < 0x100) * auVar784[8] -
                                          (0xff < sVar28),cVar93));
              auVar418._7_8_ = 0;
              auVar418._0_7_ = (uint7)((ulonglong)uVar597 >> 8);
              Var391 = CONCAT81(SUB158(auVar418 << 0x40,7),
                                (0 < sVar21) * (sVar21 < 0x100) * auVar784[6] - (0xff < sVar21));
              auVar474._9_6_ = 0;
              auVar474._0_9_ = Var391;
              auVar419._1_10_ = SUB1510(auVar474 << 0x30,5);
              auVar419[0] = (0 < sVar14) * (sVar14 < 0x100) * auVar784[4] - (0xff < sVar14);
              auVar475._11_4_ = 0;
              auVar475._0_11_ = auVar419;
              auVar420._1_12_ = SUB1512(auVar475 << 0x20,3);
              auVar420[0] = (0 < sVar8) * (sVar8 < 0x100) * auVar784[2] - (0xff < sVar8);
              auVar367[1] = 0;
              auVar367[0] = (0 < sVar5) * (sVar5 < 0x100) * auVar784[0] - (0xff < sVar5);
              auVar367._2_13_ = auVar420;
              uVar595 = CONCAT13(0,CONCAT12(cVar119,(ushort)bVar78));
              auVar568._6_8_ = 0;
              auVar259[0xe] = cVar100;
              auVar259._0_14_ = auVar568 << 0x38;
              auVar556._4_8_ = 0;
              auVar556._0_4_ = uVar642;
              auVar288._12_3_ =
                   (int3)(CONCAT26(auVar259._13_2_,
                                   CONCAT15((uVar736 != 0) * (uVar736 < 0x100) * cVar101 -
                                            (0xff < uVar736),uVar553)) >> 0x28);
              auVar288._0_12_ = auVar556 << 0x38;
              uVar297 = auVar288._11_4_;
              uVar501 = CONCAT44(uVar297,CONCAT13((uVar734 != 0) * (uVar734 < 0x100) * cVar102 -
                                                  (0xff < uVar734),uVar550));
              auVar342._10_5_ = (int5)((ulonglong)uVar501 >> 0x18);
              auVar342._0_10_ = (unkuint10)uVar752 << 0x38;
              uVar648 = CONCAT62(auVar342._9_6_,
                                 CONCAT11((uVar728 != 0) * (uVar728 < 0x100) * cVar99 -
                                          (0xff < uVar728),cVar100));
              auVar421._7_8_ = 0;
              auVar421._0_7_ = (uint7)((ulonglong)uVar648 >> 8);
              Var395 = CONCAT81(SUB158(auVar421 << 0x40,7),
                                (uVar726 != 0) * (uVar726 < 0x100) * cVar103 - (0xff < uVar726));
              auVar476._9_6_ = 0;
              auVar476._0_9_ = Var395;
              auVar422._1_10_ = SUB1510(auVar476 << 0x30,5);
              auVar422[0] = (uVar720 != 0) * (uVar720 < 0x100) * cVar104 - (0xff < uVar720);
              auVar477._11_4_ = 0;
              auVar477._0_11_ = auVar422;
              auVar540._1_12_ = SUB1512(auVar477 << 0x20,3);
              auVar540[0] = (uVar717 != 0) * (uVar717 < 0x100) * cVar105 - (0xff < uVar717);
              auVar358[1] = 0;
              auVar358[0] = (uVar694 != 0) * (uVar694 < 0x100) * bVar98 - (0xff < uVar694);
              auVar358._2_13_ = auVar540;
              uVar725 = CONCAT11(bVar251,cVar191);
              uVar464 = CONCAT12(cVar193,uVar725);
              uVar298 = CONCAT13(bVar231,uVar464);
              uVar398 = CONCAT14(cVar192,uVar298);
              auVar569[5] = bVar239;
              auVar569._0_5_ = uVar398;
              auVar569._6_8_ = 0;
              auVar260[0xe] = cVar191;
              auVar260._0_14_ = auVar569 << 0x38;
              auVar557._4_8_ = 0;
              auVar557._0_4_ = uVar298;
              auVar289._12_3_ =
                   (int3)(CONCAT26(auVar260._13_2_,
                                   CONCAT15((0 < sVar46) * (sVar46 < 0x100) * auVar605[0xc] -
                                            (0xff < sVar46),uVar398)) >> 0x28);
              auVar289._0_12_ = auVar557 << 0x38;
              uVar298 = auVar289._11_4_;
              uVar649 = CONCAT44(uVar298,CONCAT13((0 < sVar39) * (sVar39 < 0x100) * auVar605[10] -
                                                  (0xff < sVar39),uVar464));
              auVar343._10_5_ = (int5)((ulonglong)uVar649 >> 0x18);
              auVar343._0_10_ = (unkuint10)uVar725 << 0x38;
              uVar702 = CONCAT62(auVar343._9_6_,
                                 CONCAT11((0 < sVar32) * (sVar32 < 0x100) * auVar605[8] -
                                          (0xff < sVar32),cVar191));
              auVar423._7_8_ = 0;
              auVar423._0_7_ = (uint7)((ulonglong)uVar702 >> 8);
              Var401 = CONCAT81(SUB158(auVar423 << 0x40,7),
                                (0 < sVar25) * (sVar25 < 0x100) * auVar605[6] - (0xff < sVar25));
              auVar478._9_6_ = 0;
              auVar478._0_9_ = Var401;
              auVar424._1_10_ = SUB1510(auVar478 << 0x30,5);
              auVar424[0] = (0 < sVar18) * (sVar18 < 0x100) * auVar605[4] - (0xff < sVar18);
              auVar479._11_4_ = 0;
              auVar479._0_11_ = auVar424;
              auVar541._1_12_ = SUB1512(auVar479 << 0x20,3);
              auVar541[0] = (0 < sVar11) * (sVar11 < 0x100) * auVar605[2] - (0xff < sVar11);
              auVar359[1] = 0;
              auVar359[0] = (0 < sVar777) * (sVar777 < 0x100) * auVar605[0] - (0xff < sVar777);
              auVar359._2_13_ = auVar541;
              uVar725 = CONCAT11(bVar128,cVar154);
              uVar464 = CONCAT12(cVar153,uVar725);
              uVar299 = CONCAT13(bVar126,uVar464);
              uVar398 = CONCAT14(cVar152,uVar299);
              auVar570[5] = bVar234;
              auVar570._0_5_ = uVar398;
              uVar646 = CONCAT13(0,CONCAT12(cVar193,(ushort)bVar251));
              uVar642 = CONCAT13(0,CONCAT12(cVar153,(ushort)bVar128));
              auVar570._6_8_ = 0;
              auVar261[0xe] = cVar154;
              auVar261._0_14_ = auVar570 << 0x38;
              auVar558._4_8_ = 0;
              auVar558._0_4_ = uVar299;
              auVar290._12_3_ =
                   (int3)(CONCAT26(auVar261._13_2_,
                                   CONCAT15((uVar827 != 0) * (uVar827 < 0x100) * cVar178 -
                                            (0xff < uVar827),uVar398)) >> 0x28);
              auVar290._0_12_ = auVar558 << 0x38;
              uVar299 = auVar290._11_4_;
              uVar703 = CONCAT44(uVar299,CONCAT13((uVar824 != 0) * (uVar824 < 0x100) * cVar177 -
                                                  (0xff < uVar824),uVar464));
              auVar344._10_5_ = (int5)((ulonglong)uVar703 >> 0x18);
              auVar344._0_10_ = (unkuint10)uVar725 << 0x38;
              uVar598 = CONCAT62(auVar344._9_6_,
                                 CONCAT11((uVar822 != 0) * (uVar822 < 0x100) * cVar176 -
                                          (0xff < uVar822),cVar154));
              auVar425._7_8_ = 0;
              auVar425._0_7_ = (uint7)((ulonglong)uVar598 >> 8);
              Var405 = CONCAT81(SUB158(auVar425 << 0x40,7),
                                (uVar820 != 0) * (uVar820 < 0x100) * cVar175 - (0xff < uVar820));
              auVar480._9_6_ = 0;
              auVar480._0_9_ = Var405;
              auVar426._1_10_ = SUB1510(auVar480 << 0x30,5);
              auVar426[0] = (uVar763 != 0) * (uVar763 < 0x100) * cVar174 - (0xff < uVar763);
              auVar481._11_4_ = 0;
              auVar481._0_11_ = auVar426;
              auVar542._1_12_ = SUB1512(auVar481 << 0x20,3);
              auVar542[0] = (uVar762 != 0) * (uVar762 < 0x100) * cVar173 - (0xff < uVar762);
              auVar360[1] = 0;
              auVar360[0] = (uVar757 != 0) * (uVar757 < 0x100) * bVar229 - (0xff < uVar757);
              auVar360._2_13_ = auVar542;
              auVar262._10_2_ = 0;
              auVar262._0_10_ = auVar367._0_10_;
              auVar262._12_2_ = (short)Var391;
              uVar536 = CONCAT42(auVar262._10_4_,auVar419._0_2_);
              auVar427._6_8_ = 0;
              auVar427._0_6_ = uVar536;
              auVar312._4_2_ = auVar420._0_2_;
              auVar312._0_4_ = auVar367._0_4_;
              auVar312._6_8_ = SUB148(auVar427 << 0x40,6);
              auVar263._10_2_ = 0;
              auVar263._0_10_ = auVar358._0_10_;
              auVar263._12_2_ = (short)Var395;
              uVar537 = CONCAT42(auVar263._10_4_,auVar422._0_2_);
              auVar428._6_8_ = 0;
              auVar428._0_6_ = uVar537;
              auVar313._4_2_ = auVar540._0_2_;
              auVar313._0_4_ = auVar358._0_4_;
              auVar313._6_8_ = SUB148(auVar428 << 0x40,6);
              auVar264._10_2_ = 0;
              auVar264._0_10_ = auVar359._0_10_;
              auVar264._12_2_ = (short)Var401;
              uVar538 = CONCAT42(auVar264._10_4_,auVar424._0_2_);
              auVar429._6_8_ = 0;
              auVar429._0_6_ = uVar538;
              auVar314._4_2_ = auVar541._0_2_;
              auVar314._0_4_ = auVar359._0_4_;
              auVar314._6_8_ = SUB148(auVar429 << 0x40,6);
              auVar265._10_2_ = 0;
              auVar265._0_10_ = auVar360._0_10_;
              auVar265._12_2_ = (short)Var405;
              uVar539 = CONCAT42(auVar265._10_4_,auVar426._0_2_);
              auVar430._6_8_ = 0;
              auVar430._0_6_ = uVar539;
              auVar315._4_2_ = auVar542._0_2_;
              auVar315._0_4_ = auVar360._0_4_;
              auVar315._6_8_ = SUB148(auVar430 << 0x40,6);
              iVar700 = (uint)(ushort)((ulonglong)uVar597 >> 8) +
                        (uint)(ushort)((ulonglong)uVar648 >> 8) +
                        (uint)(ushort)((ulonglong)uVar702 >> 8) +
                        (uint)(ushort)((ulonglong)uVar598 >> 8);
              iVar724 = (uint)(ushort)((ulonglong)uVar499 >> 0x18) +
                        (uint)(ushort)((ulonglong)uVar501 >> 0x18) +
                        (uint)(ushort)((ulonglong)uVar649 >> 0x18) +
                        (uint)(ushort)((ulonglong)uVar703 >> 0x18);
              iVar732 = (uVar300 >> 8 & 0xffff) + (uVar297 >> 8 & 0xffff) + (uVar298 >> 8 & 0xffff)
                        + (uVar299 >> 8 & 0xffff);
              iVar687 = (int)uVar539 + (int)uVar537 + (int)uVar536 + (int)uVar538;
              uVar641 = iVar687 >> 2;
              auVar610._0_10_ = (unkuint10)uVar641 << 0x40;
              auVar611._0_14_ = ZEXT414(uVar641) << 0x40;
              auVar611._14_2_ = (short)(iVar724 >> 0x12);
              auVar610._12_4_ = auVar611._12_4_;
              uVar723 = (undefined2)(iVar724 >> 2);
              auVar610._10_2_ = uVar723;
              uVar640 = (undefined2)
                        (auVar315._4_4_ + auVar313._4_4_ + auVar312._4_4_ + auVar314._4_4_ >> 2);
              auVar784._4_6_ = auVar610._10_6_;
              auVar784._2_2_ = uVar640;
              sVar777 = (short)(iVar700 >> 0x12);
              auVar784._0_2_ = sVar777;
              auVar784._10_6_ = 0;
              auVar619._0_2_ =
                   (undefined2)
                   ((int)((auVar360._0_4_ & 0xffff) +
                         (auVar358._0_4_ & 0xffff) + (auVar367._0_4_ & 0xffff) +
                         (auVar359._0_4_ & 0xffff)) >> 2);
              auVar659._12_4_ = 0;
              auVar659._0_12_ = SUB1612(auVar784 << 0x30,4);
              uVar731 = (undefined2)(iVar732 >> 2);
              auVar615._0_12_ = SUB1612(auVar659 << 0x20,0);
              auVar615._12_2_ = sVar777;
              auVar615._14_2_ = (short)(iVar732 >> 0x12);
              auVar614._12_4_ = auVar615._12_4_;
              auVar614._0_10_ = SUB1610(auVar659 << 0x20,0);
              auVar614._10_2_ = (short)(iVar687 >> 0x12);
              auVar613._10_6_ = auVar614._10_6_;
              auVar613._0_10_ = (unkuint10)0 << 0x40;
              auVar431._2_8_ = auVar613._8_8_;
              auVar431._0_2_ = uVar731;
              auVar431._10_6_ = 0;
              auVar612._12_4_ = 0;
              auVar612._0_12_ = SUB1612(auVar431 << 0x30,4);
              auVar612 = auVar612 << 0x20;
              auVar618._0_12_ = auVar612._0_12_;
              auVar618._12_2_ = uVar731;
              auVar618._14_2_ =
                   (short)((int)((uVar300 >> 0x18) + (uVar297 >> 0x18) + (uVar298 >> 0x18) +
                                (uVar299 >> 0x18)) >> 2);
              auVar617._12_4_ = auVar618._12_4_;
              auVar617._0_10_ = auVar612._0_10_;
              auVar617._10_2_ = uVar723;
              auVar616._10_6_ = auVar617._10_6_;
              auVar616._0_8_ = auVar612._0_8_;
              auVar616._8_2_ = (short)(iVar700 >> 2);
              auVar619._8_8_ = auVar616._8_8_;
              auVar619._6_2_ =
                   (short)((int)((auVar265._10_4_ >> 0x10) +
                                (auVar263._10_4_ >> 0x10) + (auVar262._10_4_ >> 0x10) +
                                (auVar264._10_4_ >> 0x10)) >> 2);
              auVar619._4_2_ = (short)uVar641;
              auVar619._2_2_ = uVar640;
              auVar508[0xc] = cVar91;
              auVar508._0_12_ = ZEXT112(bVar142) << 0x40;
              auVar509._10_3_ = auVar508._10_3_;
              auVar509._0_10_ = (unkuint10)bVar141 << 0x40;
              auVar316[4] = cVar92;
              auVar316._0_4_ = uVar688;
              auVar316[5] = 0;
              auVar316._6_8_ = SUB148(ZEXT514(auVar509._8_5_) << 0x40,6);
              auVar510[0xc] = cVar121;
              auVar510._0_12_ = ZEXT112(bVar144) << 0x40;
              auVar511._10_3_ = auVar510._10_3_;
              auVar511._0_10_ = (unkuint10)bVar143 << 0x40;
              auVar317[4] = cVar119;
              auVar317._0_4_ = uVar595;
              auVar317[5] = 0;
              auVar317._6_8_ = SUB148(ZEXT514(auVar511._8_5_) << 0x40,6);
              auVar512[0xc] = cVar192;
              auVar512._0_12_ = ZEXT112(bVar239) << 0x40;
              auVar513._10_3_ = auVar512._10_3_;
              auVar513._0_10_ = (unkuint10)bVar231 << 0x40;
              auVar318[4] = cVar193;
              auVar318._0_4_ = uVar646;
              auVar318[5] = 0;
              auVar318._6_8_ = SUB148(ZEXT514(auVar513._8_5_) << 0x40,6);
              auVar514[0xc] = cVar152;
              auVar514._0_12_ = ZEXT112(bVar234) << 0x40;
              auVar515._10_3_ = auVar514._10_3_;
              auVar515._0_10_ = (unkuint10)bVar126 << 0x40;
              auVar319[4] = cVar153;
              auVar319._0_4_ = uVar642;
              auVar319[5] = 0;
              auVar319._6_8_ = SUB148(ZEXT514(auVar515._8_5_) << 0x40,6);
              iVar687 = auVar515._8_4_ + auVar511._8_4_ + auVar509._8_4_ + auVar513._8_4_;
              auVar619 = auVar619 & _DAT_00267f50;
              uVar640 = (undefined2)
                        ((int)((uint)(byte)((bVar243 != 0) * (bVar243 < 0x100) * bVar243 -
                                           (0xff < bVar243)) +
                               (uint)(byte)((0 < sVar55) * (sVar55 < 0x100) * auVar785[0xc] -
                                           (0xff < sVar55)) +
                               (uint)(byte)((uVar690 != 0) * (uVar690 < 0x100) * cVar96 -
                                           (0xff < uVar690)) +
                              (uint)(byte)((uVar765 != 0) * (uVar765 < 0x100) * bVar244 -
                                          (0xff < uVar765))) >> 2);
              auVar676._0_2_ =
                   (undefined2)
                   ((int)((uVar642 & 0xffff) +
                         (uVar595 & 0xffff) + (uVar688 & 0xffff) + (uVar646 & 0xffff)) >> 2);
              auVar580._10_2_ = (short)(iVar687 >> 0x12);
              auVar580._0_10_ = (unkuint10)0 << 0x40;
              auVar432._12_4_ = 0;
              auVar432._0_12_ = SUB1612(ZEXT616(CONCAT42(auVar580._8_4_,uVar640)) << 0x30,4);
              auVar675._0_12_ = SUB1612(auVar432 << 0x20,0);
              auVar675._12_2_ = uVar640;
              auVar675._14_2_ =
                   (short)((int)((uint)(byte)((bVar245 != 0) * (bVar245 < 0x100) * bVar245 -
                                             (0xff < bVar245)) +
                                 (uint)(byte)((0 < sVar59) * (sVar59 < 0x100) * auVar785[0xe] -
                                             (0xff < sVar59)) +
                                 (uint)(byte)((uVar741 != 0) * (uVar741 < 0x100) * cVar97 -
                                             (0xff < uVar741)) +
                                (uint)(byte)((uVar780 != 0) * (uVar780 < 0x100) * bVar246 -
                                            (0xff < uVar780))) >> 2);
              auVar674._12_4_ = auVar675._12_4_;
              auVar674._0_10_ = SUB1610(auVar432 << 0x20,0);
              auVar674._10_2_ =
                   (short)((int)((uint)(byte)((bVar241 != 0) * (bVar241 < 0x100) * bVar241 -
                                             (0xff < bVar241)) +
                                 (uint)(byte)((0 < sVar51) * (sVar51 < 0x100) * auVar785[10] -
                                             (0xff < sVar51)) +
                                 (uint)(byte)((uVar689 != 0) * (uVar689 < 0x100) * cVar95 -
                                             (0xff < uVar689)) +
                                (uint)(byte)((uVar754 != 0) * (uVar754 < 0x100) * bVar242 -
                                            (0xff < uVar754))) >> 2);
              auVar676._10_6_ = auVar674._10_6_;
              auVar676._8_2_ =
                   (short)((int)((uint)bVar239 + (uint)bVar142 + (uint)bVar144 + (uint)bVar234) >> 2
                          );
              auVar676._6_2_ =
                   (short)((int)((uint)(uint3)(auVar514._10_3_ >> 0x10) +
                                (uint)(uint3)(auVar510._10_3_ >> 0x10) +
                                (uint)(uint3)(auVar508._10_3_ >> 0x10) +
                                (uint)(uint3)(auVar512._10_3_ >> 0x10)) >> 2);
              auVar676._4_2_ = (short)(iVar687 >> 2);
              auVar676._2_2_ =
                   (short)(auVar319._4_4_ + auVar317._4_4_ + auVar316._4_4_ + auVar318._4_4_ >> 2);
              auVar676 = auVar676 & _DAT_00267f50;
              uVar646 = CONCAT13(0,CONCAT12(cVar117,(ushort)bVar65));
              uVar725 = auVar619._0_2_;
              uVar752 = auVar619._2_2_;
              sVar777 = auVar619._4_2_;
              sVar5 = auVar619._6_2_;
              sVar8 = auVar619._8_2_;
              sVar11 = auVar619._10_2_;
              sVar14 = auVar619._12_2_;
              sVar18 = auVar619._14_2_;
              uVar683 = auVar676._0_2_;
              uVar689 = auVar676._2_2_;
              sVar21 = auVar676._4_2_;
              uVar741 = auVar676._6_2_;
              sVar25 = auVar676._8_2_;
              sVar28 = auVar676._10_2_;
              sVar32 = auVar676._12_2_;
              sVar35 = auVar676._14_2_;
              auVar571._6_8_ = 0;
              auVar282[0xe] = cVar120;
              auVar282._0_14_ = auVar571 << 0x38;
              auVar559._4_8_ = 0;
              auVar559._0_4_ = uVar643;
              auVar320._12_3_ =
                   (int3)(CONCAT26(auVar282._13_2_,
                                   CONCAT15((0 < sVar43) * (sVar43 < 0x100) * auVar786[0xc] -
                                            (0xff < sVar43),uVar554)) >> 0x28);
              auVar320._0_12_ = auVar559 << 0x38;
              uVar300 = auVar320._11_4_;
              uVar499 = CONCAT44(uVar300,CONCAT13((0 < sVar36) * (sVar36 < 0x100) * auVar786[10] -
                                                  (0xff < sVar36),uVar551));
              auVar352._10_5_ = (int5)((ulonglong)uVar499 >> 0x18);
              auVar352._0_10_ = (unkuint10)uVar758 << 0x38;
              uVar597 = CONCAT62(auVar352._9_6_,
                                 CONCAT11((0 < sVar29) * (sVar29 < 0x100) * auVar786[8] -
                                          (0xff < sVar29),cVar120));
              auVar433._7_8_ = 0;
              auVar433._0_7_ = (uint7)((ulonglong)uVar597 >> 8);
              Var391 = CONCAT81(SUB158(auVar433 << 0x40,7),
                                (0 < sVar22) * (sVar22 < 0x100) * auVar786[6] - (0xff < sVar22));
              auVar482._9_6_ = 0;
              auVar482._0_9_ = Var391;
              auVar434._1_10_ = SUB1510(auVar482 << 0x30,5);
              auVar434[0] = (0 < sVar15) * (sVar15 < 0x100) * auVar786[4] - (0xff < sVar15);
              auVar483._11_4_ = 0;
              auVar483._0_11_ = auVar434;
              auVar435._1_12_ = SUB1512(auVar483 << 0x20,3);
              auVar435[0] = (0 < sVar9) * (sVar9 < 0x100) * auVar786[2] - (0xff < sVar9);
              auVar368[1] = 0;
              auVar368[0] = (0 < sVar6) * (sVar6 < 0x100) * auVar786[0] - (0xff < sVar6);
              auVar368._2_13_ = auVar435;
              uVar733 = CONCAT11(bVar68,cVar116);
              uVar464 = CONCAT12(cVar115,uVar733);
              uVar297 = CONCAT13(bVar67,uVar464);
              uVar398 = CONCAT14(cVar145,uVar297);
              auVar572[5] = bVar71;
              auVar572._0_5_ = uVar398;
              uVar739 = CONCAT11(bVar214,cVar165);
              uVar465 = CONCAT12(cVar164,uVar739);
              uVar298 = CONCAT13(bVar218,uVar465);
              uVar399 = CONCAT14(cVar162,uVar298);
              auVar573[5] = bVar220;
              auVar573._0_5_ = uVar399;
              auVar572._6_8_ = 0;
              auVar266[0xe] = cVar116;
              auVar266._0_14_ = auVar572 << 0x38;
              auVar560._4_8_ = 0;
              auVar560._0_4_ = uVar297;
              auVar291._12_3_ =
                   (int3)(CONCAT26(auVar266._13_2_,
                                   CONCAT15((uVar800 != 0) * (uVar800 < 0x100) * local_fc[0xd] -
                                            (0xff < uVar800),uVar398)) >> 0x28);
              auVar291._0_12_ = auVar560 << 0x38;
              uVar297 = auVar291._11_4_;
              uVar501 = CONCAT44(uVar297,CONCAT13((uVar796 != 0) * (uVar796 < 0x100) * local_fc[0xb]
                                                  - (0xff < uVar796),uVar464));
              auVar345._10_5_ = (int5)((ulonglong)uVar501 >> 0x18);
              auVar345._0_10_ = (unkuint10)uVar733 << 0x38;
              uVar648 = CONCAT62(auVar345._9_6_,
                                 CONCAT11((uVar794 != 0) * (uVar794 < 0x100) * local_fc[9] -
                                          (0xff < uVar794),cVar116));
              auVar436._7_8_ = 0;
              auVar436._0_7_ = (uint7)((ulonglong)uVar648 >> 8);
              Var395 = CONCAT81(SUB158(auVar436 << 0x40,7),
                                (uVar792 != 0) * (uVar792 < 0x100) * local_fc[7] - (0xff < uVar792))
              ;
              auVar484._9_6_ = 0;
              auVar484._0_9_ = Var395;
              auVar437._1_10_ = SUB1510(auVar484 << 0x30,5);
              auVar437[0] = (uVar790 != 0) * (uVar790 < 0x100) * local_fc[5] - (0xff < uVar790);
              auVar485._11_4_ = 0;
              auVar485._0_11_ = auVar437;
              auVar543._1_12_ = SUB1512(auVar485 << 0x20,3);
              auVar543[0] = (uVar788 != 0) * (uVar788 < 0x100) * local_fc[3] - (0xff < uVar788);
              auVar361[1] = 0;
              auVar361[0] = (uVar782 != 0) * (uVar782 < 0x100) * local_fc[1] - (0xff < uVar782);
              auVar361._2_13_ = auVar543;
              uVar641 = CONCAT13(0,CONCAT12(cVar115,(ushort)bVar68));
              auVar573._6_8_ = 0;
              auVar267[0xe] = cVar165;
              auVar267._0_14_ = auVar573 << 0x38;
              auVar561._4_8_ = 0;
              auVar561._0_4_ = uVar298;
              auVar292._12_3_ =
                   (int3)(CONCAT26(auVar267._13_2_,
                                   CONCAT15((0 < sVar47) * (sVar47 < 0x100) * auVar815[0xc] -
                                            (0xff < sVar47),uVar399)) >> 0x28);
              auVar292._0_12_ = auVar561 << 0x38;
              uVar298 = auVar292._11_4_;
              uVar649 = CONCAT44(uVar298,CONCAT13((0 < sVar40) * (sVar40 < 0x100) * auVar815[10] -
                                                  (0xff < sVar40),uVar465));
              auVar346._10_5_ = (int5)((ulonglong)uVar649 >> 0x18);
              auVar346._0_10_ = (unkuint10)uVar739 << 0x38;
              uVar702 = CONCAT62(auVar346._9_6_,
                                 CONCAT11((0 < sVar33) * (sVar33 < 0x100) * auVar815[8] -
                                          (0xff < sVar33),cVar165));
              auVar438._7_8_ = 0;
              auVar438._0_7_ = (uint7)((ulonglong)uVar702 >> 8);
              Var401 = CONCAT81(SUB158(auVar438 << 0x40,7),
                                (0 < sVar26) * (sVar26 < 0x100) * auVar815[6] - (0xff < sVar26));
              auVar486._9_6_ = 0;
              auVar486._0_9_ = Var401;
              auVar439._1_10_ = SUB1510(auVar486 << 0x30,5);
              auVar439[0] = (0 < sVar19) * (sVar19 < 0x100) * auVar815[4] - (0xff < sVar19);
              auVar487._11_4_ = 0;
              auVar487._0_11_ = auVar439;
              auVar544._1_12_ = SUB1512(auVar487 << 0x20,3);
              auVar544[0] = (0 < sVar12) * (sVar12 < 0x100) * auVar815[2] - (0xff < sVar12);
              auVar362[1] = 0;
              auVar362[0] = (0 < sVar778) * (sVar778 < 0x100) * auVar815[0] - (0xff < sVar778);
              auVar362._2_13_ = auVar544;
              uVar733 = CONCAT11(bVar216,cVar179);
              uVar464 = CONCAT12(cVar198,uVar733);
              uVar299 = CONCAT13(bVar219,uVar464);
              uVar398 = CONCAT14(cVar200,uVar299);
              auVar574[5] = bVar223;
              auVar574._0_5_ = uVar398;
              uVar643 = CONCAT13(0,CONCAT12(cVar164,(ushort)bVar214));
              uVar595 = CONCAT13(0,CONCAT12(cVar198,(ushort)bVar216));
              auVar574._6_8_ = 0;
              auVar268[0xe] = cVar179;
              auVar268._0_14_ = auVar574 << 0x38;
              auVar562._4_8_ = 0;
              auVar562._0_4_ = uVar299;
              auVar293._12_3_ =
                   (int3)(CONCAT26(auVar268._13_2_,
                                   CONCAT15((uVar743 != 0) * (uVar743 < 0x100) * cVar205 -
                                            (0xff < uVar743),uVar398)) >> 0x28);
              auVar293._0_12_ = auVar562 << 0x38;
              uVar299 = auVar293._11_4_;
              uVar703 = CONCAT44(uVar299,CONCAT13((uVar742 != 0) * (uVar742 < 0x100) * cVar163 -
                                                  (0xff < uVar742),uVar464));
              auVar347._10_5_ = (int5)((ulonglong)uVar703 >> 0x18);
              auVar347._0_10_ = (unkuint10)uVar733 << 0x38;
              uVar598 = CONCAT62(auVar347._9_6_,
                                 CONCAT11((uVar738 != 0) * (uVar738 < 0x100) * cVar204 -
                                          (0xff < uVar738),cVar179));
              auVar440._7_8_ = 0;
              auVar440._0_7_ = (uint7)((ulonglong)uVar598 >> 8);
              Var405 = CONCAT81(SUB158(auVar440 << 0x40,7),
                                (uVar737 != 0) * (uVar737 < 0x100) * cVar203 - (0xff < uVar737));
              auVar488._9_6_ = 0;
              auVar488._0_9_ = Var405;
              auVar441._1_10_ = SUB1510(auVar488 << 0x30,5);
              auVar441[0] = (uVar730 != 0) * (uVar730 < 0x100) * cVar202 - (0xff < uVar730);
              auVar489._11_4_ = 0;
              auVar489._0_11_ = auVar441;
              auVar545._1_12_ = SUB1512(auVar489 << 0x20,3);
              auVar545[0] = (uVar722 != 0) * (uVar722 < 0x100) * cVar201 - (0xff < uVar722);
              auVar363[1] = 0;
              auVar363[0] = (uVar696 != 0) * (uVar696 < 0x100) * bVar129 - (0xff < uVar696);
              auVar363._2_13_ = auVar545;
              auVar269._10_2_ = 0;
              auVar269._0_10_ = auVar368._0_10_;
              auVar269._12_2_ = (short)Var391;
              uVar536 = CONCAT42(auVar269._10_4_,auVar434._0_2_);
              auVar442._6_8_ = 0;
              auVar442._0_6_ = uVar536;
              auVar321._4_2_ = auVar435._0_2_;
              auVar321._0_4_ = auVar368._0_4_;
              auVar321._6_8_ = SUB148(auVar442 << 0x40,6);
              auVar270._10_2_ = 0;
              auVar270._0_10_ = auVar361._0_10_;
              auVar270._12_2_ = (short)Var395;
              uVar537 = CONCAT42(auVar270._10_4_,auVar437._0_2_);
              auVar443._6_8_ = 0;
              auVar443._0_6_ = uVar537;
              auVar322._4_2_ = auVar543._0_2_;
              auVar322._0_4_ = auVar361._0_4_;
              auVar322._6_8_ = SUB148(auVar443 << 0x40,6);
              auVar271._10_2_ = 0;
              auVar271._0_10_ = auVar362._0_10_;
              auVar271._12_2_ = (short)Var401;
              uVar538 = CONCAT42(auVar271._10_4_,auVar439._0_2_);
              auVar444._6_8_ = 0;
              auVar444._0_6_ = uVar538;
              auVar323._4_2_ = auVar544._0_2_;
              auVar323._0_4_ = auVar362._0_4_;
              auVar323._6_8_ = SUB148(auVar444 << 0x40,6);
              auVar272._10_2_ = 0;
              auVar272._0_10_ = auVar363._0_10_;
              auVar272._12_2_ = (short)Var405;
              uVar539 = CONCAT42(auVar272._10_4_,auVar441._0_2_);
              auVar445._6_8_ = 0;
              auVar445._0_6_ = uVar539;
              auVar324._4_2_ = auVar545._0_2_;
              auVar324._0_4_ = auVar363._0_4_;
              auVar324._6_8_ = SUB148(auVar445 << 0x40,6);
              iVar700 = (uint)(ushort)((ulonglong)uVar597 >> 8) +
                        (uint)(ushort)((ulonglong)uVar648 >> 8) +
                        (uint)(ushort)((ulonglong)uVar702 >> 8) +
                        (uint)(ushort)((ulonglong)uVar598 >> 8);
              iVar724 = (uint)(ushort)((ulonglong)uVar499 >> 0x18) +
                        (uint)(ushort)((ulonglong)uVar501 >> 0x18) +
                        (uint)(ushort)((ulonglong)uVar649 >> 0x18) +
                        (uint)(ushort)((ulonglong)uVar703 >> 0x18);
              iVar732 = (uVar300 >> 8 & 0xffff) + (uVar297 >> 8 & 0xffff) + (uVar298 >> 8 & 0xffff)
                        + (uVar299 >> 8 & 0xffff);
              iVar687 = (int)uVar539 + (int)uVar537 + (int)uVar536 + (int)uVar538;
              uVar642 = iVar687 >> 2;
              auVar620._0_10_ = (unkuint10)uVar642 << 0x40;
              uVar731 = (undefined2)(iVar732 >> 2);
              auVar621._0_14_ = ZEXT414(uVar642) << 0x40;
              auVar621._14_2_ = (short)(iVar724 >> 0x12);
              auVar620._12_4_ = auVar621._12_4_;
              uVar723 = (undefined2)(iVar724 >> 2);
              auVar620._10_2_ = uVar723;
              uVar640 = (undefined2)
                        (auVar324._4_4_ + auVar322._4_4_ + auVar321._4_4_ + auVar323._4_4_ >> 2);
              auVar786._4_6_ = auVar620._10_6_;
              auVar786._2_2_ = uVar640;
              sVar778 = (short)(iVar700 >> 0x12);
              auVar786._0_2_ = sVar778;
              auVar786._10_6_ = 0;
              auVar629._0_2_ =
                   (undefined2)
                   ((int)((auVar363._0_4_ & 0xffff) +
                         (auVar361._0_4_ & 0xffff) + (auVar368._0_4_ & 0xffff) +
                         (auVar362._0_4_ & 0xffff)) >> 2);
              auVar785._12_4_ = 0;
              auVar785._0_12_ = SUB1612(auVar786 << 0x30,4);
              auVar516[0xc] = cVar145;
              auVar516._0_12_ = ZEXT112(bVar71) << 0x40;
              auVar517._10_3_ = auVar516._10_3_;
              auVar517._0_10_ = (unkuint10)bVar67 << 0x40;
              auVar325[4] = cVar115;
              auVar325._0_4_ = uVar641;
              auVar325[5] = 0;
              auVar325._6_8_ = SUB148(ZEXT514(auVar517._8_5_) << 0x40,6);
              auVar625._0_12_ = SUB1612(auVar785 << 0x20,0);
              auVar625._12_2_ = sVar778;
              auVar625._14_2_ = (short)(iVar732 >> 0x12);
              auVar624._12_4_ = auVar625._12_4_;
              auVar624._0_10_ = SUB1610(auVar785 << 0x20,0);
              auVar624._10_2_ = (short)(iVar687 >> 0x12);
              auVar623._10_6_ = auVar624._10_6_;
              auVar623._0_10_ = (unkuint10)0 << 0x40;
              auVar446._2_8_ = auVar623._8_8_;
              auVar446._0_2_ = uVar731;
              auVar446._10_6_ = 0;
              auVar622._12_4_ = 0;
              auVar622._0_12_ = SUB1612(auVar446 << 0x30,4);
              auVar622 = auVar622 << 0x20;
              auVar628._0_12_ = auVar622._0_12_;
              auVar628._12_2_ = uVar731;
              auVar628._14_2_ =
                   (short)((int)((uVar300 >> 0x18) + (uVar297 >> 0x18) + (uVar298 >> 0x18) +
                                (uVar299 >> 0x18)) >> 2);
              auVar627._12_4_ = auVar628._12_4_;
              auVar627._0_10_ = auVar622._0_10_;
              auVar627._10_2_ = uVar723;
              auVar626._10_6_ = auVar627._10_6_;
              auVar626._0_8_ = auVar622._0_8_;
              auVar626._8_2_ = (short)(iVar700 >> 2);
              auVar629._8_8_ = auVar626._8_8_;
              auVar629._6_2_ =
                   (short)((int)((auVar272._10_4_ >> 0x10) +
                                (auVar270._10_4_ >> 0x10) + (auVar269._10_4_ >> 0x10) +
                                (auVar271._10_4_ >> 0x10)) >> 2);
              auVar629._4_2_ = (short)uVar642;
              auVar629._2_2_ = uVar640;
              auVar518[0xc] = cVar118;
              auVar518._0_12_ = ZEXT112(bVar69) << 0x40;
              auVar519._10_3_ = auVar518._10_3_;
              auVar519._0_10_ = (unkuint10)bVar66 << 0x40;
              auVar326[4] = cVar117;
              auVar326._0_4_ = uVar646;
              auVar326[5] = 0;
              auVar326._6_8_ = SUB148(ZEXT514(auVar519._8_5_) << 0x40,6);
              auVar520[0xc] = cVar162;
              auVar520._0_12_ = ZEXT112(bVar220) << 0x40;
              auVar521._10_3_ = auVar520._10_3_;
              auVar521._0_10_ = (unkuint10)bVar218 << 0x40;
              auVar327[4] = cVar164;
              auVar327._0_4_ = uVar643;
              auVar327[5] = 0;
              auVar327._6_8_ = SUB148(ZEXT514(auVar521._8_5_) << 0x40,6);
              auVar522[0xc] = cVar200;
              auVar522._0_12_ = ZEXT112(bVar223) << 0x40;
              auVar523._10_3_ = auVar522._10_3_;
              auVar523._0_10_ = (unkuint10)bVar219 << 0x40;
              auVar328[4] = cVar198;
              auVar328._0_4_ = uVar595;
              auVar328[5] = 0;
              auVar328._6_8_ = SUB148(ZEXT514(auVar523._8_5_) << 0x40,6);
              iVar687 = auVar523._8_4_ + auVar517._8_4_ + auVar519._8_4_ + auVar521._8_4_;
              auVar629 = auVar629 & _DAT_00267f50;
              uVar733 = CONCAT11(bVar64,cVar146);
              uVar464 = CONCAT12(cVar147,uVar733);
              uVar297 = CONCAT13(bVar63,uVar464);
              uVar398 = CONCAT14(cVar148,uVar297);
              auVar575[5] = bVar62;
              auVar575._0_5_ = uVar398;
              uVar640 = (undefined2)
                        ((int)((uint)(byte)((uVar691 != 0) * (uVar691 < 0x100) * bVar227 -
                                           (0xff < uVar691)) +
                              (uint)(byte)((bVar77 != 0) * (bVar77 < 0x100) * bVar77 -
                                          (0xff < bVar77)) +
                              (uint)(byte)((uVar801 != 0) * (uVar801 < 0x100) * bVar74 -
                                          (0xff < uVar801)) +
                              (uint)(byte)((bVar226 != 0) * (bVar226 < 0x100) * bVar226 -
                                          (0xff < bVar226))) >> 2);
              auVar679._0_2_ =
                   (undefined2)
                   ((int)((uVar595 & 0xffff) +
                         (uVar641 & 0xffff) + (uVar646 & 0xffff) + (uVar643 & 0xffff)) >> 2);
              uVar739 = CONCAT11(bVar86,cVar149);
              uVar465 = CONCAT12(cVar150,uVar739);
              uVar298 = CONCAT13(bVar130,uVar465);
              uVar399 = CONCAT14(cVar151,uVar298);
              auVar576[5] = bVar131;
              auVar576._0_5_ = uVar399;
              auVar581._10_2_ = (short)(iVar687 >> 0x12);
              auVar581._0_10_ = (unkuint10)0 << 0x40;
              auVar447._12_4_ = 0;
              auVar447._0_12_ = SUB1612(ZEXT616(CONCAT42(auVar581._8_4_,uVar640)) << 0x30,4);
              auVar678._0_12_ = SUB1612(auVar447 << 0x20,0);
              auVar678._12_2_ = uVar640;
              auVar678._14_2_ =
                   (short)((int)((uint)(byte)((uVar781 != 0) * (uVar781 < 0x100) * bVar123 -
                                             (0xff < uVar781)) +
                                (uint)(byte)((bVar75 != 0) * (bVar75 < 0x100) * bVar75 -
                                            (0xff < bVar75)) +
                                (uint)(byte)((uVar804 != 0) * (uVar804 < 0x100) * bVar76 -
                                            (0xff < uVar804)) +
                                (uint)(byte)((bVar228 != 0) * (bVar228 < 0x100) * bVar228 -
                                            (0xff < bVar228))) >> 2);
              auVar677._12_4_ = auVar678._12_4_;
              auVar677._0_10_ = SUB1610(auVar447 << 0x20,0);
              auVar677._10_2_ =
                   (short)((int)((uint)(byte)((uVar755 != 0) * (uVar755 < 0x100) * bVar225 -
                                             (0xff < uVar755)) +
                                (uint)(byte)((bVar72 != 0) * (bVar72 < 0x100) * bVar72 -
                                            (0xff < bVar72)) +
                                (uint)(byte)((uVar797 != 0) * (uVar797 < 0x100) * bVar73 -
                                            (0xff < uVar797)) +
                                (uint)(byte)((bVar224 != 0) * (bVar224 < 0x100) * bVar224 -
                                            (0xff < bVar224))) >> 2);
              auVar679._10_6_ = auVar677._10_6_;
              auVar679._8_2_ =
                   (short)((int)((uint)bVar223 + (uint)bVar69 + (uint)bVar71 + (uint)bVar220) >> 2);
              auVar679._6_2_ =
                   (short)((int)((uint)(uint3)(auVar522._10_3_ >> 0x10) +
                                (uint)(uint3)(auVar516._10_3_ >> 0x10) +
                                (uint)(uint3)(auVar518._10_3_ >> 0x10) +
                                (uint)(uint3)(auVar520._10_3_ >> 0x10)) >> 2);
              auVar679._4_2_ = (short)(iVar687 >> 2);
              auVar679._2_2_ =
                   (short)(auVar328._4_4_ + auVar325._4_4_ + auVar326._4_4_ + auVar327._4_4_ >> 2);
              auVar679 = auVar679 & _DAT_00267f50;
              auVar575._6_8_ = 0;
              auVar273[0xe] = cVar146;
              auVar273._0_14_ = auVar575 << 0x38;
              auVar563._4_8_ = 0;
              auVar563._0_4_ = uVar297;
              auVar294._12_3_ =
                   (int3)(CONCAT26(auVar273._13_2_,
                                   CONCAT15((0 < sVar44) * (sVar44 < 0x100) * auVar787[0xc] -
                                            (0xff < sVar44),uVar398)) >> 0x28);
              auVar294._0_12_ = auVar563 << 0x38;
              uVar297 = auVar294._11_4_;
              uVar499 = CONCAT44(uVar297,CONCAT13((0 < sVar37) * (sVar37 < 0x100) * auVar787[10] -
                                                  (0xff < sVar37),uVar464));
              auVar348._10_5_ = (int5)((ulonglong)uVar499 >> 0x18);
              auVar348._0_10_ = (unkuint10)uVar733 << 0x38;
              uVar597 = CONCAT62(auVar348._9_6_,
                                 CONCAT11((0 < sVar30) * (sVar30 < 0x100) * auVar787[8] -
                                          (0xff < sVar30),cVar146));
              auVar448._7_8_ = 0;
              auVar448._0_7_ = (uint7)((ulonglong)uVar597 >> 8);
              Var391 = CONCAT81(SUB158(auVar448 << 0x40,7),
                                (0 < sVar23) * (sVar23 < 0x100) * auVar787[6] - (0xff < sVar23));
              auVar490._9_6_ = 0;
              auVar490._0_9_ = Var391;
              auVar449._1_10_ = SUB1510(auVar490 << 0x30,5);
              auVar449[0] = (0 < sVar16) * (sVar16 < 0x100) * auVar787[4] - (0xff < sVar16);
              auVar491._11_4_ = 0;
              auVar491._0_11_ = auVar449;
              auVar546._1_12_ = SUB1512(auVar491 << 0x20,3);
              auVar546[0] = (0 < sVar10) * (sVar10 < 0x100) * auVar787[2] - (0xff < sVar10);
              auVar364[1] = 0;
              auVar364[0] = (0 < sVar7) * (sVar7 < 0x100) * auVar787[0] - (0xff < sVar7);
              auVar364._2_13_ = auVar546;
              uVar733 = auVar629._0_2_;
              uVar758 = auVar629._2_2_;
              sVar778 = auVar629._4_2_;
              sVar6 = auVar629._6_2_;
              sVar9 = auVar629._8_2_;
              sVar12 = auVar629._10_2_;
              sVar15 = auVar629._12_2_;
              sVar19 = auVar629._14_2_;
              uVar684 = auVar679._0_2_;
              uVar690 = auVar679._2_2_;
              sVar22 = auVar679._4_2_;
              uVar719 = auVar679._6_2_;
              sVar26 = auVar679._8_2_;
              sVar29 = auVar679._10_2_;
              sVar33 = auVar679._12_2_;
              sVar36 = auVar679._14_2_;
              uVar646 = CONCAT13(0,CONCAT12(cVar147,(ushort)bVar64));
              auVar576._6_8_ = 0;
              auVar274[0xe] = cVar149;
              auVar274._0_14_ = auVar576 << 0x38;
              auVar564._4_8_ = 0;
              auVar564._0_4_ = uVar298;
              auVar295._12_3_ =
                   (int3)(CONCAT26(auVar274._13_2_,
                                   CONCAT15((uVar802 != 0) * (uVar802 < 0x100) * local_13c[0xd] -
                                            (0xff < uVar802),uVar399)) >> 0x28);
              auVar295._0_12_ = auVar564 << 0x38;
              uVar298 = auVar295._11_4_;
              uVar501 = CONCAT44(uVar298,CONCAT13((uVar798 != 0) * (uVar798 < 0x100) * cVar110 -
                                                  (0xff < uVar798),uVar465));
              auVar349._10_5_ = (int5)((ulonglong)uVar501 >> 0x18);
              auVar349._0_10_ = (unkuint10)uVar739 << 0x38;
              uVar648 = CONCAT62(auVar349._9_6_,
                                 CONCAT11((uVar795 != 0) * (uVar795 < 0x100) * cVar109 -
                                          (0xff < uVar795),cVar149));
              auVar450._7_8_ = 0;
              auVar450._0_7_ = (uint7)((ulonglong)uVar648 >> 8);
              Var395 = CONCAT81(SUB158(auVar450 << 0x40,7),
                                (uVar793 != 0) * (uVar793 < 0x100) * cVar108 - (0xff < uVar793));
              auVar492._9_6_ = 0;
              auVar492._0_9_ = Var395;
              auVar451._1_10_ = SUB1510(auVar492 << 0x30,5);
              auVar451[0] = (uVar791 != 0) * (uVar791 < 0x100) * local_13c[5] - (0xff < uVar791);
              auVar493._11_4_ = 0;
              auVar493._0_11_ = auVar451;
              auVar547._1_12_ = SUB1512(auVar493 << 0x20,3);
              auVar547[0] = (uVar789 != 0) * (uVar789 < 0x100) * cVar107 - (0xff < uVar789);
              auVar365[1] = 0;
              auVar365[0] = (uVar783 != 0) * (uVar783 < 0x100) * local_13c[1] - (0xff < uVar783);
              auVar365._2_13_ = auVar547;
              uVar595 = CONCAT13(0,CONCAT12(cVar150,(ushort)bVar86));
              uVar739 = CONCAT11(bVar127,cVar156);
              uVar464 = CONCAT12(cVar158,uVar739);
              uVar299 = CONCAT13(bVar125,uVar464);
              uVar398 = CONCAT14(cVar160,uVar299);
              auVar577[5] = bVar221;
              auVar577._0_5_ = uVar398;
              uVar641 = CONCAT13(0,CONCAT12(cVar158,(ushort)bVar127));
              auVar577._6_8_ = 0;
              auVar275[0xe] = cVar156;
              auVar275._0_14_ = auVar577 << 0x38;
              auVar565._4_8_ = 0;
              auVar565._0_4_ = uVar299;
              auVar296._12_3_ =
                   (int3)(CONCAT26(auVar275._13_2_,
                                   CONCAT15((0 < sVar48) * (sVar48 < 0x100) * auVar660[0xc] -
                                            (0xff < sVar48),uVar398)) >> 0x28);
              auVar296._0_12_ = auVar565 << 0x38;
              uVar299 = auVar296._11_4_;
              uVar649 = CONCAT44(uVar299,CONCAT13((0 < sVar41) * (sVar41 < 0x100) * auVar660[10] -
                                                  (0xff < sVar41),uVar464));
              auVar350._10_5_ = (int5)((ulonglong)uVar649 >> 0x18);
              auVar350._0_10_ = (unkuint10)uVar739 << 0x38;
              uVar702 = CONCAT62(auVar350._9_6_,
                                 CONCAT11((0 < sVar34) * (sVar34 < 0x100) * auVar660[8] -
                                          (0xff < sVar34),cVar156));
              auVar452._7_8_ = 0;
              auVar452._0_7_ = (uint7)((ulonglong)uVar702 >> 8);
              Var401 = CONCAT81(SUB158(auVar452 << 0x40,7),
                                (0 < sVar27) * (sVar27 < 0x100) * auVar660[6] - (0xff < sVar27));
              auVar494._9_6_ = 0;
              auVar494._0_9_ = Var401;
              auVar453._1_10_ = SUB1510(auVar494 << 0x30,5);
              auVar453[0] = (0 < sVar20) * (sVar20 < 0x100) * auVar660[4] - (0xff < sVar20);
              auVar495._11_4_ = 0;
              auVar495._0_11_ = auVar453;
              auVar548._1_12_ = SUB1512(auVar495 << 0x20,3);
              auVar548[0] = (0 < sVar13) * (sVar13 < 0x100) * auVar660[2] - (0xff < sVar13);
              auVar366[1] = 0;
              auVar366[0] = (0 < sVar779) * (sVar779 < 0x100) * auVar660[0] - (0xff < sVar779);
              auVar366._2_13_ = auVar548;
              uVar739 = CONCAT11(bVar217,cVar169);
              uVar464 = CONCAT12(cVar155,uVar739);
              uVar300 = CONCAT13(bVar215,uVar464);
              uVar398 = CONCAT14(cVar171,uVar300);
              auVar578[5] = bVar222;
              auVar578._0_5_ = uVar398;
              uVar642 = CONCAT13(0,CONCAT12(cVar155,(ushort)bVar217));
              auVar578._6_8_ = 0;
              auVar283[0xe] = cVar169;
              auVar283._0_14_ = auVar578 << 0x38;
              auVar566._4_8_ = 0;
              auVar566._0_4_ = uVar300;
              auVar329._12_3_ =
                   (int3)(CONCAT26(auVar283._13_2_,
                                   CONCAT15((uVar761 != 0) * (uVar761 < 0x100) * cVar157 -
                                            (0xff < uVar761),uVar398)) >> 0x28);
              auVar329._0_12_ = auVar566 << 0x38;
              uVar300 = auVar329._11_4_;
              uVar703 = CONCAT44(uVar300,CONCAT13((uVar740 != 0) * (uVar740 < 0x100) * cVar159 -
                                                  (0xff < uVar740),uVar464));
              auVar353._10_5_ = (int5)((ulonglong)uVar703 >> 0x18);
              auVar353._0_10_ = (unkuint10)uVar739 << 0x38;
              uVar598 = CONCAT62(auVar353._9_6_,
                                 CONCAT11((uVar749 != 0) * (uVar749 < 0x100) * cVar166 -
                                          (0xff < uVar749),cVar169));
              auVar454._7_8_ = 0;
              auVar454._0_7_ = (uint7)((ulonglong)uVar598 >> 8);
              Var405 = CONCAT81(SUB158(auVar454 << 0x40,7),
                                (uVar727 != 0) * (uVar727 < 0x100) * cVar161 - (0xff < uVar727));
              auVar496._9_6_ = 0;
              auVar496._0_9_ = Var405;
              auVar455._1_10_ = SUB1510(auVar496 << 0x30,5);
              auVar455[0] = (uVar692 != 0) * (uVar692 < 0x100) * cVar187 - (0xff < uVar692);
              auVar497._11_4_ = 0;
              auVar497._0_11_ = auVar455;
              auVar456._1_12_ = SUB1512(auVar497 << 0x20,3);
              auVar456[0] = (uVar685 != 0) * (uVar685 < 0x100) * cVar188 - (0xff < uVar685);
              auVar369[1] = 0;
              auVar369[0] = (uVar764 != 0) * (uVar764 < 0x100) * bVar230 - (0xff < uVar764);
              auVar369._2_13_ = auVar456;
              auVar276._10_2_ = 0;
              auVar276._0_10_ = auVar364._0_10_;
              auVar276._12_2_ = (short)Var391;
              uVar536 = CONCAT42(auVar276._10_4_,auVar449._0_2_);
              auVar457._6_8_ = 0;
              auVar457._0_6_ = uVar536;
              auVar330._4_2_ = auVar546._0_2_;
              auVar330._0_4_ = auVar364._0_4_;
              auVar330._6_8_ = SUB148(auVar457 << 0x40,6);
              auVar277._10_2_ = 0;
              auVar277._0_10_ = auVar365._0_10_;
              auVar277._12_2_ = (short)Var395;
              uVar537 = CONCAT42(auVar277._10_4_,auVar451._0_2_);
              auVar458._6_8_ = 0;
              auVar458._0_6_ = uVar537;
              auVar331._4_2_ = auVar547._0_2_;
              auVar331._0_4_ = auVar365._0_4_;
              auVar331._6_8_ = SUB148(auVar458 << 0x40,6);
              auVar278._10_2_ = 0;
              auVar278._0_10_ = auVar366._0_10_;
              auVar278._12_2_ = (short)Var401;
              uVar538 = CONCAT42(auVar278._10_4_,auVar453._0_2_);
              auVar459._6_8_ = 0;
              auVar459._0_6_ = uVar538;
              auVar332._4_2_ = auVar548._0_2_;
              auVar332._0_4_ = auVar366._0_4_;
              auVar332._6_8_ = SUB148(auVar459 << 0x40,6);
              auVar279._10_2_ = 0;
              auVar279._0_10_ = auVar369._0_10_;
              auVar279._12_2_ = (short)Var405;
              uVar539 = CONCAT42(auVar279._10_4_,auVar455._0_2_);
              auVar460._6_8_ = 0;
              auVar460._0_6_ = uVar539;
              auVar333._4_2_ = auVar456._0_2_;
              auVar333._0_4_ = auVar369._0_4_;
              auVar333._6_8_ = SUB148(auVar460 << 0x40,6);
              iVar700 = (uint)(ushort)((ulonglong)uVar597 >> 8) +
                        (uint)(ushort)((ulonglong)uVar648 >> 8) +
                        (uint)(ushort)((ulonglong)uVar702 >> 8) +
                        (uint)(ushort)((ulonglong)uVar598 >> 8);
              iVar724 = (uint)(ushort)((ulonglong)uVar499 >> 0x18) +
                        (uint)(ushort)((ulonglong)uVar501 >> 0x18) +
                        (uint)(ushort)((ulonglong)uVar649 >> 0x18) +
                        (uint)(ushort)((ulonglong)uVar703 >> 0x18);
              iVar732 = (uVar297 >> 8 & 0xffff) + (uVar298 >> 8 & 0xffff) + (uVar299 >> 8 & 0xffff)
                        + (uVar300 >> 8 & 0xffff);
              iVar687 = (int)uVar539 + (int)uVar537 + (int)uVar536 + (int)uVar538;
              uVar643 = iVar687 >> 2;
              auVar630._0_10_ = (unkuint10)uVar643 << 0x40;
              auVar631._0_14_ = ZEXT414(uVar643) << 0x40;
              auVar631._14_2_ = (short)(iVar724 >> 0x12);
              auVar630._12_4_ = auVar631._12_4_;
              uVar723 = (undefined2)(iVar724 >> 2);
              auVar630._10_2_ = uVar723;
              uVar640 = (undefined2)
                        (auVar333._4_4_ + auVar331._4_4_ + auVar330._4_4_ + auVar332._4_4_ >> 2);
              auVar461._4_6_ = auVar630._10_6_;
              auVar461._2_2_ = uVar640;
              sVar779 = (short)(iVar700 >> 0x12);
              auVar461._0_2_ = sVar779;
              auVar461._10_6_ = 0;
              auVar639._0_2_ =
                   (undefined2)
                   ((int)((auVar369._0_4_ & 0xffff) +
                         (auVar365._0_4_ & 0xffff) + (auVar364._0_4_ & 0xffff) +
                         (auVar366._0_4_ & 0xffff)) >> 2);
              auVar787._12_4_ = 0;
              auVar787._0_12_ = SUB1612(auVar461 << 0x30,4);
              uVar731 = (undefined2)(iVar732 >> 2);
              auVar635._0_12_ = SUB1612(auVar787 << 0x20,0);
              auVar635._12_2_ = sVar779;
              auVar635._14_2_ = (short)(iVar732 >> 0x12);
              auVar634._12_4_ = auVar635._12_4_;
              auVar634._0_10_ = SUB1610(auVar787 << 0x20,0);
              auVar634._10_2_ = (short)(iVar687 >> 0x12);
              auVar633._10_6_ = auVar634._10_6_;
              auVar633._0_10_ = (unkuint10)0 << 0x40;
              auVar462._2_8_ = auVar633._8_8_;
              auVar462._0_2_ = uVar731;
              auVar462._10_6_ = 0;
              auVar632._12_4_ = 0;
              auVar632._0_12_ = SUB1612(auVar462 << 0x30,4);
              auVar632 = auVar632 << 0x20;
              auVar638._0_12_ = auVar632._0_12_;
              auVar638._12_2_ = uVar731;
              auVar638._14_2_ =
                   (short)((int)((uVar297 >> 0x18) + (uVar298 >> 0x18) + (uVar299 >> 0x18) +
                                (uVar300 >> 0x18)) >> 2);
              auVar637._12_4_ = auVar638._12_4_;
              auVar637._0_10_ = auVar632._0_10_;
              auVar637._10_2_ = uVar723;
              auVar636._10_6_ = auVar637._10_6_;
              auVar636._0_8_ = auVar632._0_8_;
              auVar636._8_2_ = (short)(iVar700 >> 2);
              auVar639._8_8_ = auVar636._8_8_;
              auVar639._6_2_ =
                   (short)((int)((auVar279._10_4_ >> 0x10) +
                                (auVar277._10_4_ >> 0x10) + (auVar276._10_4_ >> 0x10) +
                                (auVar278._10_4_ >> 0x10)) >> 2);
              auVar639._4_2_ = (short)uVar643;
              auVar639._2_2_ = uVar640;
              auVar524[0xc] = cVar148;
              auVar524._0_12_ = ZEXT112(bVar62) << 0x40;
              auVar525._10_3_ = auVar524._10_3_;
              auVar525._0_10_ = (unkuint10)bVar63 << 0x40;
              auVar334[4] = cVar147;
              auVar334._0_4_ = uVar646;
              auVar334[5] = 0;
              auVar334._6_8_ = SUB148(ZEXT514(auVar525._8_5_) << 0x40,6);
              auVar526[0xc] = cVar151;
              auVar526._0_12_ = ZEXT112(bVar131) << 0x40;
              auVar527._10_3_ = auVar526._10_3_;
              auVar527._0_10_ = (unkuint10)bVar130 << 0x40;
              auVar335[4] = cVar150;
              auVar335._0_4_ = uVar595;
              auVar335[5] = 0;
              auVar335._6_8_ = SUB148(ZEXT514(auVar527._8_5_) << 0x40,6);
              auVar528[0xc] = cVar160;
              auVar528._0_12_ = ZEXT112(bVar221) << 0x40;
              auVar529._10_3_ = auVar528._10_3_;
              auVar529._0_10_ = (unkuint10)bVar125 << 0x40;
              auVar336[4] = cVar158;
              auVar336._0_4_ = uVar641;
              auVar336[5] = 0;
              auVar336._6_8_ = SUB148(ZEXT514(auVar529._8_5_) << 0x40,6);
              auVar530[0xc] = cVar171;
              auVar530._0_12_ = ZEXT112(bVar222) << 0x40;
              auVar531._10_3_ = auVar530._10_3_;
              auVar531._0_10_ = (unkuint10)bVar215 << 0x40;
              auVar337[4] = cVar155;
              auVar337._0_4_ = uVar642;
              auVar337[5] = 0;
              auVar337._6_8_ = SUB148(ZEXT514(auVar531._8_5_) << 0x40,6);
              iVar687 = auVar531._8_4_ + auVar527._8_4_ + auVar525._8_4_ + auVar529._8_4_;
              auVar639 = auVar639 & _DAT_00267f50;
              uVar640 = (undefined2)
                        ((int)((uint)(byte)((uVar750 != 0) * (uVar750 < 0x100) * cVar172 -
                                           (0xff < uVar750)) +
                              (uint)(byte)((bVar134 != 0) * (bVar134 < 0x100) * bVar134 -
                                          (0xff < bVar134)) +
                              (uint)(byte)((uVar803 != 0) * (uVar803 < 0x100) * bVar114 -
                                          (0xff < uVar803)) +
                              (uint)(byte)((0 < sVar57) * (sVar57 < 0x100) * auVar663[0xc] -
                                          (0xff < sVar57))) >> 2);
              auVar682._0_2_ =
                   (undefined2)
                   ((int)((uVar642 & 0xffff) +
                         (uVar595 & 0xffff) + (uVar646 & 0xffff) + (uVar641 & 0xffff)) >> 2);
              auVar582._10_2_ = (short)(iVar687 >> 0x12);
              auVar582._0_10_ = (unkuint10)0 << 0x40;
              auVar463._12_4_ = 0;
              auVar463._0_12_ = SUB1612(ZEXT616(CONCAT42(auVar582._8_4_,uVar640)) << 0x30,4);
              auVar681._0_12_ = SUB1612(auVar463 << 0x20,0);
              auVar681._12_2_ = uVar640;
              auVar681._14_2_ =
                   (short)((int)((uint)(byte)((uVar756 != 0) * (uVar756 < 0x100) * cVar170 -
                                             (0xff < uVar756)) +
                                (uint)(byte)((bVar106 != 0) * (bVar106 < 0x100) * bVar106 -
                                            (0xff < bVar106)) +
                                (uint)(byte)((uVar805 != 0) * (uVar805 < 0x100) * bVar94 -
                                            (0xff < uVar805)) +
                                (uint)(byte)((0 < sVar61) * (sVar61 < 0x100) * auVar663[0xe] -
                                            (0xff < sVar61))) >> 2);
              auVar680._12_4_ = auVar681._12_4_;
              auVar680._0_10_ = SUB1610(auVar463 << 0x20,0);
              auVar680._10_2_ =
                   (short)((int)((uint)(byte)((uVar760 != 0) * (uVar760 < 0x100) * cVar168 -
                                             (0xff < uVar760)) +
                                (uint)(byte)((bVar132 != 0) * (bVar132 < 0x100) * bVar132 -
                                            (0xff < bVar132)) +
                                (uint)(byte)((uVar799 != 0) * (uVar799 < 0x100) * bVar133 -
                                            (0xff < uVar799)) +
                                (uint)(byte)((0 < sVar53) * (sVar53 < 0x100) * auVar663[10] -
                                            (0xff < sVar53))) >> 2);
              auVar682._10_6_ = auVar680._10_6_;
              auVar682._8_2_ =
                   (short)((int)((uint)bVar222 + (uint)bVar62 + (uint)bVar131 + (uint)bVar221) >> 2)
              ;
              auVar682._6_2_ =
                   (short)((int)((uint)(uint3)(auVar530._10_3_ >> 0x10) +
                                (uint)(uint3)(auVar526._10_3_ >> 0x10) +
                                (uint)(uint3)(auVar524._10_3_ >> 0x10) +
                                (uint)(uint3)(auVar528._10_3_ >> 0x10)) >> 2);
              auVar682._4_2_ = (short)(iVar687 >> 2);
              auVar682._2_2_ =
                   (short)(auVar337._4_4_ + auVar335._4_4_ + auVar334._4_4_ + auVar336._4_4_ >> 2);
              auVar682 = auVar682 & _DAT_00267f50;
              uVar739 = auVar639._0_2_;
              uVar764 = auVar639._2_2_;
              sVar779 = auVar639._4_2_;
              sVar7 = auVar639._6_2_;
              sVar10 = auVar639._8_2_;
              sVar13 = auVar639._10_2_;
              sVar16 = auVar639._12_2_;
              sVar20 = auVar639._14_2_;
              uVar685 = auVar682._0_2_;
              uVar692 = auVar682._2_2_;
              sVar23 = auVar682._4_2_;
              uVar747 = auVar682._6_2_;
              sVar27 = auVar682._8_2_;
              sVar30 = auVar682._10_2_;
              sVar34 = auVar682._12_2_;
              sVar37 = auVar682._14_2_;
              pauVar586[1][0] = (0 < sVar17) * (sVar17 < 0x100) * auVar673[8] - (0xff < sVar17);
              pauVar586[1][1] = (0 < sVar8) * (sVar8 < 0x100) * auVar619[8] - (0xff < sVar8);
              pauVar586[1][2] = (0 < sVar9) * (sVar9 < 0x100) * auVar629[8] - (0xff < sVar9);
              pauVar586[1][3] = (0 < sVar10) * (sVar10 < 0x100) * auVar639[8] - (0xff < sVar10);
              pauVar586[1][4] = (0 < sVar24) * (sVar24 < 0x100) * auVar673[10] - (0xff < sVar24);
              pauVar586[1][5] = (0 < sVar11) * (sVar11 < 0x100) * auVar619[10] - (0xff < sVar11);
              pauVar586[1][6] = (0 < sVar12) * (sVar12 < 0x100) * auVar629[10] - (0xff < sVar12);
              pauVar586[1][7] = (0 < sVar13) * (sVar13 < 0x100) * auVar639[10] - (0xff < sVar13);
              pauVar586[1][8] = (0 < sVar31) * (sVar31 < 0x100) * auVar673[0xc] - (0xff < sVar31);
              pauVar586[1][9] = (0 < sVar14) * (sVar14 < 0x100) * auVar619[0xc] - (0xff < sVar14);
              pauVar586[1][10] = (0 < sVar15) * (sVar15 < 0x100) * auVar629[0xc] - (0xff < sVar15);
              pauVar586[1][0xb] = (0 < sVar16) * (sVar16 < 0x100) * auVar639[0xc] - (0xff < sVar16);
              pauVar586[1][0xc] = (0 < sVar38) * (sVar38 < 0x100) * auVar673[0xe] - (0xff < sVar38);
              pauVar586[1][0xd] = (0 < sVar18) * (sVar18 < 0x100) * auVar619[0xe] - (0xff < sVar18);
              pauVar586[1][0xe] = (0 < sVar19) * (sVar19 < 0x100) * auVar629[0xe] - (0xff < sVar19);
              pauVar586[1][0xf] = (0 < sVar20) * (sVar20 < 0x100) * auVar639[0xe] - (0xff < sVar20);
              (*pauVar586)[0] = (uVar716 != 0) * (uVar716 < 0x100) * auVar673[0] - (0xff < uVar716);
              (*pauVar586)[1] = (uVar725 != 0) * (uVar725 < 0x100) * auVar619[0] - (0xff < uVar725);
              (*pauVar586)[2] = (uVar733 != 0) * (uVar733 < 0x100) * auVar629[0] - (0xff < uVar733);
              (*pauVar586)[3] = (uVar739 != 0) * (uVar739 < 0x100) * auVar639[0] - (0xff < uVar739);
              (*pauVar586)[4] = (uVar746 != 0) * (uVar746 < 0x100) * auVar673[2] - (0xff < uVar746);
              (*pauVar586)[5] = (uVar752 != 0) * (uVar752 < 0x100) * auVar619[2] - (0xff < uVar752);
              (*pauVar586)[6] = (uVar758 != 0) * (uVar758 < 0x100) * auVar629[2] - (0xff < uVar758);
              (*pauVar586)[7] = (uVar764 != 0) * (uVar764 < 0x100) * auVar639[2] - (0xff < uVar764);
              (*pauVar586)[8] = (0 < sVar718) * (sVar718 < 0x100) * auVar673[4] - (0xff < sVar718);
              (*pauVar586)[9] = (0 < sVar777) * (sVar777 < 0x100) * auVar619[4] - (0xff < sVar777);
              (*pauVar586)[10] = (0 < sVar778) * (sVar778 < 0x100) * auVar629[4] - (0xff < sVar778);
              (*pauVar586)[0xb] = (0 < sVar779) * (sVar779 < 0x100) * auVar639[4] - (0xff < sVar779)
              ;
              (*pauVar586)[0xc] = (0 < sVar4) * (sVar4 < 0x100) * auVar673[6] - (0xff < sVar4);
              (*pauVar586)[0xd] = (0 < sVar5) * (sVar5 < 0x100) * auVar619[6] - (0xff < sVar5);
              (*pauVar586)[0xe] = (0 < sVar6) * (sVar6 < 0x100) * auVar629[6] - (0xff < sVar6);
              (*pauVar586)[0xf] = (0 < sVar7) * (sVar7 < 0x100) * auVar639[6] - (0xff < sVar7);
              pauVar586[2][0] = (uVar644 != 0) * (uVar644 < 0x100) * auVar776[0] - (0xff < uVar644);
              pauVar586[2][1] = (uVar683 != 0) * (uVar683 < 0x100) * auVar676[0] - (0xff < uVar683);
              pauVar586[2][2] = (uVar684 != 0) * (uVar684 < 0x100) * auVar679[0] - (0xff < uVar684);
              pauVar586[2][3] = (uVar685 != 0) * (uVar685 < 0x100) * auVar682[0] - (0xff < uVar685);
              pauVar586[2][4] = (uVar686 != 0) * (uVar686 < 0x100) * auVar776[2] - (0xff < uVar686);
              pauVar586[2][5] = (uVar689 != 0) * (uVar689 < 0x100) * auVar676[2] - (0xff < uVar689);
              pauVar586[2][6] = (uVar690 != 0) * (uVar690 < 0x100) * auVar679[2] - (0xff < uVar690);
              pauVar586[2][7] = (uVar692 != 0) * (uVar692 < 0x100) * auVar682[2] - (0xff < uVar692);
              pauVar586[2][8] = (0 < sVar45) * (sVar45 < 0x100) * auVar776[4] - (0xff < sVar45);
              pauVar586[2][9] = (0 < sVar21) * (sVar21 < 0x100) * auVar676[4] - (0xff < sVar21);
              pauVar586[2][10] = (0 < sVar22) * (sVar22 < 0x100) * auVar679[4] - (0xff < sVar22);
              pauVar586[2][0xb] = (0 < sVar23) * (sVar23 < 0x100) * auVar682[4] - (0xff < sVar23);
              pauVar586[2][0xc] =
                   (uVar693 != 0) * (uVar693 < 0x100) * auVar776[6] - (0xff < uVar693);
              pauVar586[2][0xd] =
                   (uVar741 != 0) * (uVar741 < 0x100) * auVar676[6] - (0xff < uVar741);
              pauVar586[2][0xe] =
                   (uVar719 != 0) * (uVar719 < 0x100) * auVar679[6] - (0xff < uVar719);
              pauVar586[2][0xf] =
                   (uVar747 != 0) * (uVar747 < 0x100) * auVar682[6] - (0xff < uVar747);
              pauVar586[3][0] = (0 < sVar49) * (sVar49 < 0x100) * auVar776[8] - (0xff < sVar49);
              pauVar586[3][1] = (0 < sVar25) * (sVar25 < 0x100) * auVar676[8] - (0xff < sVar25);
              pauVar586[3][2] = (0 < sVar26) * (sVar26 < 0x100) * auVar679[8] - (0xff < sVar26);
              pauVar586[3][3] = (0 < sVar27) * (sVar27 < 0x100) * auVar682[8] - (0xff < sVar27);
              pauVar586[3][4] = (0 < sVar50) * (sVar50 < 0x100) * auVar776[10] - (0xff < sVar50);
              pauVar586[3][5] = (0 < sVar28) * (sVar28 < 0x100) * auVar676[10] - (0xff < sVar28);
              pauVar586[3][6] = (0 < sVar29) * (sVar29 < 0x100) * auVar679[10] - (0xff < sVar29);
              pauVar586[3][7] = (0 < sVar30) * (sVar30 < 0x100) * auVar682[10] - (0xff < sVar30);
              pauVar586[3][8] = (0 < sVar52) * (sVar52 < 0x100) * auVar776[0xc] - (0xff < sVar52);
              pauVar586[3][9] = (0 < sVar32) * (sVar32 < 0x100) * auVar676[0xc] - (0xff < sVar32);
              pauVar586[3][10] = (0 < sVar33) * (sVar33 < 0x100) * auVar679[0xc] - (0xff < sVar33);
              pauVar586[3][0xb] = (0 < sVar34) * (sVar34 < 0x100) * auVar682[0xc] - (0xff < sVar34);
              pauVar586[3][0xc] = (0 < sVar54) * (sVar54 < 0x100) * auVar776[0xe] - (0xff < sVar54);
              pauVar586[3][0xd] = (0 < sVar35) * (sVar35 < 0x100) * auVar676[0xe] - (0xff < sVar35);
              pauVar586[3][0xe] = (0 < sVar36) * (sVar36 < 0x100) * auVar679[0xe] - (0xff < sVar36);
              pauVar586[3][0xf] = (0 < sVar37) * (sVar37 < 0x100) * auVar682[0xe] - (0xff < sVar37);
              pauVar586 = pauVar586 + 4;
            } while (uVar588 < uVar1);
            in = (byte *)((int)in + uVar1 * 8 * 0x10);
            pauVar590 = pauVar590 + uVar1 * 4;
            if (uVar584 + 1 == uVar1 * 0x10) goto LAB_0015e047;
            pauVar587 = (undefined1 (*) [16])(*(undefined1 (*) [16])in + iVar2);
            iVar687 = uVar1 * 0x80;
          }
          pauVar585 = (undefined1 (*) [16])in;
          do {
            puVar583 = *pauVar585;
            (*pauVar590)[0] =
                 (char)((int)((uint)(byte)(*pauVar585)[4] + (uint)(byte)(*pauVar585)[0] +
                              (uint)(byte)(*pauVar587)[0] + (uint)(byte)(*pauVar587)[4]) >> 2);
            (*pauVar590)[1] =
                 (char)((int)((uint)(byte)(*pauVar585)[5] + (uint)(byte)(*pauVar585)[1] +
                              (uint)(byte)(*pauVar587)[1] + (uint)(byte)(*pauVar587)[5]) >> 2);
            (*pauVar590)[2] =
                 (char)((int)((uint)(byte)(*pauVar585)[6] + (uint)(byte)(*pauVar585)[2] +
                              (uint)(byte)(*pauVar587)[2] + (uint)(byte)(*pauVar587)[6]) >> 2);
            (*pauVar590)[3] =
                 (char)((int)((uint)(byte)(*pauVar585)[7] + (uint)(byte)(*pauVar585)[3] +
                              (uint)(byte)(*pauVar587)[3] + (uint)(byte)(*pauVar587)[7]) >> 2);
            pauVar585 = (undefined1 (*) [16])(puVar583 + 8);
            pauVar587 = (undefined1 (*) [16])(*pauVar587 + 8);
            pauVar590 = (undefined1 (*) [16])(*pauVar590 + 4);
          } while ((int)((int)(puVar583 + 8) + (iVar687 - (int)in)) < iVar2);
        }
      }
LAB_0015e047:
      local_168 = local_168 + 1;
      in = *pauVar589 + iVar2;
      pauVar590 = pauVar591;
    } while (height >> 1 != local_168);
  }
  return;
}


// GL_PaletteAdd  @ 0015fbe0
short GL_PaletteAdd(byte *pPal,qboolean isSky)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  short sVar7;
  int iVar8;
  int in_GS_OFFSET;
  byte local_310 [768];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if (qglColorTableEXT == (_func_void_int_int_int_int_int_void_ptr *)0x0) {
LAB_0015fd30:
    sVar7 = -1;
  }
  else {
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int tag@[???]
                       Unresolved local var: int limit@[???]
                       Unresolved local var: byte[768] gammaPal@[???] */
      local_310[iVar1] = texgammatable[pPal[iVar1]];
      iVar1 = iVar1 + 1;
    } while (iVar1 != 0x300);
                    /* Unresolved local var: int tag@[???]
                       Unresolved local var: int i@[???] */
    uVar2 = (uint)local_310[0];
    iVar1 = 1;
    uVar3 = uVar2;
    pbVar5 = local_310 + 1;
    do {
      iVar1 = iVar1 + 2;
      uVar2 = uVar2 + *pbVar5 ^ uVar3;
      uVar3 = (uint)pbVar5[1];
      uVar2 = uVar2 + uVar3 ^ (uint)*pbVar5;
      pbVar5 = pbVar5 + 2;
    } while (iVar1 != 0x2ff);
    pbVar5 = local_310 + 0x2ff;
    do {
      pbVar6 = pbVar5 + 1;
      uVar2 = uVar2 + *pbVar5 ^ (uint)pbVar5[-1];
      pbVar5 = pbVar6;
    } while (pbVar6 != (byte *)&local_10);
    iVar8 = (uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f);
    uVar2 = ~-(uint)(isSky == false) & 0x158;
    iVar1 = gGLPalette[uVar2].tag;
    iVar4 = uVar2 * 0x308;
    uVar3 = uVar2;
    if (-1 < iVar1) {
      do {
                    /* Unresolved local var: int i@[???] */
        if (iVar1 == iVar8) {
          iVar1 = 0;
                    /* Unresolved local var: int i@[???] */
          while (local_310[iVar1] == *(byte *)(iVar4 + 0xdfa368 + iVar1)) {
            iVar1 = iVar1 + 1;
            if (iVar1 == 0x300) {
              gGLPalette[uVar3].referenceCount = gGLPalette[uVar3].referenceCount + 1;
              sVar7 = (short)uVar3;
              goto LAB_0015fd16;
            }
          }
        }
        uVar3 = uVar3 + 1;
        if ((int)((-(uint)(isSky == false) & 0xfffffffa) + 0x15e) <= (int)uVar3) goto LAB_0015fd30;
        iVar1 = *(int *)(gGLPalette[1].colors + iVar4 + -8);
        iVar4 = iVar4 + 0x308;
      } while (-1 < iVar1);
      uVar2 = (uint)(short)uVar3;
    }
    Q_memcpy(gGLPalette[uVar3].colors,local_310,0x300);
    sVar7 = (short)uVar2;
    gGLPalette[uVar3].tag = iVar8;
    gGLPalette[uVar3].referenceCount = 1;
  }
LAB_0015fd16:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return sVar7;
}


// GL_PaletteClear  @ 0015faa0
void GL_PaletteClear(int index)

{
  if ((uint)index < 0x15e) {
    gGLPalette[index].tag = -1;
    gGLPalette[index].referenceCount = 0;
  }
  return;
}


// GL_PaletteClearSky  @ 0015fb70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_PaletteClearSky(void)

{
                    /* Unresolved local var: int i@[???] */
  gGLPalette[0x158].tag = -1;
  gGLPalette[0x159].referenceCount = 0;
  gGLPalette[0x15a].tag = -1;
  gGLPalette[0x15a].referenceCount = 0;
  gGLPalette[0x15b].tag = -1;
  gGLPalette[0x15b].referenceCount = 0;
  gGLPalette[0x158].referenceCount = 0;
  gGLPalette[0x159].tag = -1;
  gGLPalette[0x15c].tag = -1;
  gGLPalette[0x15c].referenceCount = 0;
  gGLPalette[0x15d].tag = -1;
  gGLPalette[0x15d].referenceCount = 0;
  return;
}


// GL_PaletteEqual  @ 0015fb30
int GL_PaletteEqual(byte *pPal1,int tag1,byte *pPal2,int tag2)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = 0;
  if (tag1 != tag2) {
    return iVar1;
  }
  do {
    if (pPal1[iVar1] != pPal2[iVar1]) {
      return 0;
    }
                    /* Unresolved local var: int i@[???] */
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x300);
  return 1;
}


// GL_PaletteInit  @ 0015fa70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_PaletteInit(void)

{
  GL_PALETTE *pGVar1;
  GL_PALETTE *pGVar2;
  
                    /* Unresolved local var: int i@[???] */
  pGVar1 = gGLPalette;
  do {
    pGVar1->tag = -1;
    pGVar2 = pGVar1 + 1;
    pGVar1->referenceCount = 0;
    pGVar1 = pGVar2;
  } while (pGVar2 != (GL_PALETTE *)&DAT_00e3c850);
  return;
}


// GL_PaletteSelect  @ 0015fd80
void GL_PaletteSelect(int paletteIndex)

{
  if ((g_currentpalette != paletteIndex) &&
     (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
    g_currentpalette = paletteIndex;
    (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(paletteIndex * 0x308 + 0xdfa368))
    ;
  }
  return;
}


// GL_PaletteTag  @ 0015fad0
int GL_PaletteTag(byte *pPal)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  
                    /* Unresolved local var: int tag@[???]
                       Unresolved local var: int i@[???] */
  iVar1 = 1;
  uVar4 = (uint)*pPal;
  uVar5 = uVar4;
  do {
    pbVar2 = pPal + iVar1;
    uVar4 = uVar4 + *pbVar2 ^ uVar5;
    uVar5 = (uint)pPal[iVar1 + 1];
    iVar1 = iVar1 + 2;
    uVar4 = uVar4 + uVar5 ^ (uint)*pbVar2;
  } while (iVar1 != 0x2ff);
  pbVar2 = pPal + 0x2ff;
  do {
    pbVar3 = pbVar2 + 1;
    uVar4 = uVar4 + *pbVar2 ^ (uint)pbVar2[-1];
    pbVar2 = pbVar3;
  } while (pbVar3 != pPal + 0x300);
  return (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
}


// GL_ResampleAlphaTexture  @ 0015bb40
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GL_ResampleAlphaTexture(byte *in,int inwidth,int inheight,byte *out,int outwidth,int outheight)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  uint uVar18;
  byte *pbVar19;
  byte *pbVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  byte *pbVar25;
  uint uVar26;
  byte *pbVar27;
  int iVar28;
  int in_GS_OFFSET;
  undefined1 auVar29 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar34 [16];
  int iVar35;
  int iVar42;
  ushort uVar43;
  int iVar44;
  int iVar45;
  undefined1 auVar36 [16];
  undefined1 auVar38 [16];
  int iVar46;
  undefined1 auVar39 [16];
  undefined1 auVar41 [16];
  int iVar49;
  int iVar50;
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  int iVar51;
  int iVar52;
  int iVar53;
  int iVar54;
  int iVar55;
  byte *local_850;
  int local_84c;
  int local_834;
  byte local_82c [1024];
  byte local_42c [1036];
  int local_20;
  undefined1 auVar30 [16];
  undefined1 auVar33 [16];
  undefined1 auVar37 [16];
  undefined1 auVar40 [16];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: byte * inrow@[???]
                       Unresolved local var: byte * inrow2@[???]
                       Unresolved local var: uint frac@[???]
                       Unresolved local var: uint fracstep@[???]
                       Unresolved local var: byte[1024] p1@[???]
                       Unresolved local var: byte[1024] p2@[???]
                       Unresolved local var: byte * pix1@[???]
                       Unresolved local var: byte * pix2@[???]
                       Unresolved local var: byte * pix3@[???]
                       Unresolved local var: byte * pix4@[???] */
  local_850 = out;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar18 = (inwidth << 0x10) / outwidth;
  uVar26 = uVar18 >> 2;
  if (outwidth < 1) goto LAB_0015c100;
  uVar1 = (outwidth - 0x10U >> 4) + 1;
  iVar28 = uVar1 * 0x10;
  if (outwidth - 1U < 0xf) {
    local_84c = 0;
    uVar24 = uVar26;
LAB_0015bcb5:
    local_82c[local_84c] = (byte)(uVar24 >> 0x10);
    if (local_84c + 1 < outwidth) {
      iVar21 = uVar18 + uVar24 + uVar18;
      local_82c[local_84c + 1] = (byte)(uVar18 + uVar24 >> 0x10);
      if (local_84c + 2 < outwidth) {
        iVar22 = iVar21 + uVar18;
        local_82c[local_84c + 2] = (byte)((uint)iVar21 >> 0x10);
        if (local_84c + 3 < outwidth) {
          iVar21 = iVar22 + uVar18;
          local_82c[local_84c + 3] = (byte)((uint)iVar22 >> 0x10);
          if (local_84c + 4 < outwidth) {
            iVar22 = iVar21 + uVar18;
            local_82c[local_84c + 4] = (byte)((uint)iVar21 >> 0x10);
            if (local_84c + 5 < outwidth) {
              iVar21 = iVar22 + uVar18;
              local_82c[local_84c + 5] = (byte)((uint)iVar22 >> 0x10);
              if (local_84c + 6 < outwidth) {
                iVar22 = iVar21 + uVar18;
                local_82c[local_84c + 6] = (byte)((uint)iVar21 >> 0x10);
                if (local_84c + 7 < outwidth) {
                  iVar21 = iVar22 + uVar18;
                  local_82c[local_84c + 7] = (byte)((uint)iVar22 >> 0x10);
                  if (local_84c + 8 < outwidth) {
                    iVar22 = iVar21 + uVar18;
                    local_82c[local_84c + 8] = (byte)((uint)iVar21 >> 0x10);
                    if (local_84c + 9 < outwidth) {
                      iVar21 = iVar22 + uVar18;
                      local_82c[local_84c + 9] = (byte)((uint)iVar22 >> 0x10);
                      if (local_84c + 10 < outwidth) {
                        iVar22 = iVar21 + uVar18;
                        local_82c[local_84c + 10] = (byte)((uint)iVar21 >> 0x10);
                        if (local_84c + 0xb < outwidth) {
                          iVar21 = iVar22 + uVar18;
                          local_82c[local_84c + 0xb] = (byte)((uint)iVar22 >> 0x10);
                          if (local_84c + 0xc < outwidth) {
                            iVar22 = iVar21 + uVar18;
                            local_82c[local_84c + 0xc] = (byte)((uint)iVar21 >> 0x10);
                            if (local_84c + 0xd < outwidth) {
                              local_82c[local_84c + 0xd] = (byte)((uint)iVar22 >> 0x10);
                              if (local_84c + 0xe < outwidth) {
                                local_82c[local_84c + 0xe] = (byte)(iVar22 + uVar18 >> 0x10);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    iVar21 = uVar26 * 3;
    if (0xe < outwidth - 1U) goto LAB_0015be71;
    iVar28 = 0;
  }
  else {
    iVar21 = uVar18 + uVar18 + uVar26;
    auVar47._12_4_ = uVar18 + iVar21;
    auVar47._8_4_ = iVar21;
    iVar22 = uVar18 * 0x10;
    auVar47._4_4_ = uVar18 + uVar26;
    auVar47._0_4_ = uVar26;
    iVar21 = uVar18 * 4;
    uVar24 = 0;
    do {
      iVar35 = iVar21 + auVar47._0_4_;
      iVar46 = auVar47._4_4_;
      iVar42 = iVar21 + iVar46;
      iVar49 = auVar47._8_4_;
      iVar44 = iVar21 + iVar49;
      iVar50 = auVar47._12_4_;
      iVar45 = iVar21 + iVar50;
      iVar51 = iVar35 + iVar21;
      iVar52 = iVar42 + iVar21;
      iVar53 = iVar44 + iVar21;
      iVar54 = iVar45 + iVar21;
      uVar23 = uVar24 + 1;
      uVar43 = (ushort)((uint)iVar44 >> 0x10);
      auVar31._0_2_ = auVar47._2_2_;
      auVar30._0_12_ = ZEXT212(uVar43) << 0x30;
      auVar30._12_2_ = uVar43;
      auVar30._14_2_ = (short)((uint)iVar45 >> 0x10);
      auVar29._12_4_ = auVar30._12_4_;
      auVar29._0_10_ = (unkuint10)uVar43 << 0x30;
      auVar29._10_2_ = (short)((uint)iVar42 >> 0x10);
      auVar31._8_8_ =
           (undefined8)
           (CONCAT64(auVar29._10_6_,CONCAT22((short)((uint)iVar35 >> 0x10),uVar43)) >> 0x10);
      auVar31._6_2_ = auVar47._14_2_;
      auVar31._4_2_ = auVar47._10_2_;
      auVar31._2_2_ = auVar47._6_2_;
      iVar35 = uVar24 * 0x10;
      auVar31 = auVar31 & _DAT_00267f50;
      auVar47._0_4_ = auVar47._0_4_ + iVar22;
      auVar47._4_4_ = iVar46 + iVar22;
      auVar47._8_4_ = iVar49 + iVar22;
      auVar47._12_4_ = iVar50 + iVar22;
      auVar38._0_2_ = (undefined2)((uint)iVar51 >> 0x10);
      uVar43 = (ushort)((uint)(iVar53 + iVar21) >> 0x10);
      auVar37._0_12_ = ZEXT212(uVar43) << 0x30;
      auVar37._12_2_ = uVar43;
      auVar37._14_2_ = (short)((uint)(iVar54 + iVar21) >> 0x10);
      auVar36._12_4_ = auVar37._12_4_;
      auVar36._0_10_ = (unkuint10)uVar43 << 0x30;
      auVar36._10_2_ = (short)((uint)(iVar52 + iVar21) >> 0x10);
      auVar38._8_8_ =
           (undefined8)
           (CONCAT64(auVar36._10_6_,CONCAT22((short)((uint)(iVar51 + iVar21) >> 0x10),uVar43)) >>
           0x10);
      auVar38._6_2_ = (short)((uint)iVar54 >> 0x10);
      auVar38._4_2_ = (short)((uint)iVar53 >> 0x10);
      auVar38._2_2_ = (short)((uint)iVar52 >> 0x10);
      auVar38 = auVar38 & _DAT_00267f50;
      sVar2 = auVar31._0_2_;
      sVar3 = auVar31._2_2_;
      sVar4 = auVar31._4_2_;
      sVar5 = auVar31._6_2_;
      sVar6 = auVar31._8_2_;
      sVar7 = auVar31._10_2_;
      sVar8 = auVar31._12_2_;
      sVar9 = auVar31._14_2_;
      sVar10 = auVar38._0_2_;
      sVar11 = auVar38._2_2_;
      sVar12 = auVar38._4_2_;
      sVar13 = auVar38._6_2_;
      sVar14 = auVar38._8_2_;
      sVar15 = auVar38._10_2_;
      sVar16 = auVar38._12_2_;
      sVar17 = auVar38._14_2_;
      local_82c[iVar35] = (0 < sVar2) * (sVar2 < 0x100) * auVar31[0] - (0xff < sVar2);
      local_82c[iVar35 + 1] = (0 < sVar3) * (sVar3 < 0x100) * auVar31[2] - (0xff < sVar3);
      local_82c[iVar35 + 2] = (0 < sVar4) * (sVar4 < 0x100) * auVar31[4] - (0xff < sVar4);
      local_82c[iVar35 + 3] = (0 < sVar5) * (sVar5 < 0x100) * auVar31[6] - (0xff < sVar5);
      local_82c[iVar35 + 4] = (0 < sVar6) * (sVar6 < 0x100) * auVar31[8] - (0xff < sVar6);
      local_82c[iVar35 + 5] = (0 < sVar7) * (sVar7 < 0x100) * auVar31[10] - (0xff < sVar7);
      local_82c[iVar35 + 6] = (0 < sVar8) * (sVar8 < 0x100) * auVar31[0xc] - (0xff < sVar8);
      local_82c[iVar35 + 7] = (0 < sVar9) * (sVar9 < 0x100) * auVar31[0xe] - (0xff < sVar9);
      local_82c[iVar35 + 8] = (0 < sVar10) * (sVar10 < 0x100) * auVar38[0] - (0xff < sVar10);
      local_82c[iVar35 + 9] = (0 < sVar11) * (sVar11 < 0x100) * auVar38[2] - (0xff < sVar11);
      local_82c[iVar35 + 10] = (0 < sVar12) * (sVar12 < 0x100) * auVar38[4] - (0xff < sVar12);
      local_82c[iVar35 + 0xb] = (0 < sVar13) * (sVar13 < 0x100) * auVar38[6] - (0xff < sVar13);
      local_82c[iVar35 + 0xc] = (0 < sVar14) * (sVar14 < 0x100) * auVar38[8] - (0xff < sVar14);
      local_82c[iVar35 + 0xd] = (0 < sVar15) * (sVar15 < 0x100) * auVar38[10] - (0xff < sVar15);
      local_82c[iVar35 + 0xe] = (0 < sVar16) * (sVar16 < 0x100) * auVar38[0xc] - (0xff < sVar16);
      local_82c[iVar35 + 0xf] = (0 < sVar17) * (sVar17 < 0x100) * auVar38[0xe] - (0xff < sVar17);
      uVar24 = uVar23;
    } while (uVar23 < uVar1);
    uVar24 = uVar18 * iVar28 + uVar26;
    local_84c = iVar28;
    if (iVar28 != outwidth) goto LAB_0015bcb5;
LAB_0015be71:
    iVar21 = uVar26 * 3;
    iVar22 = uVar18 + uVar18 + iVar21;
    auVar48._4_4_ = uVar18 + iVar21;
    auVar48._0_4_ = iVar21;
    auVar48._12_4_ = uVar18 + iVar22;
    auVar48._8_4_ = iVar22;
    iVar35 = uVar18 * 0x10;
    iVar22 = uVar18 * 4;
    uVar26 = 0;
    do {
      iVar42 = iVar22 + auVar48._0_4_;
      iVar49 = auVar48._4_4_;
      iVar44 = iVar22 + iVar49;
      iVar50 = auVar48._8_4_;
      iVar45 = iVar22 + iVar50;
      iVar51 = auVar48._12_4_;
      iVar46 = iVar22 + iVar51;
      iVar52 = iVar42 + iVar22;
      iVar53 = iVar44 + iVar22;
      iVar54 = iVar45 + iVar22;
      iVar55 = iVar46 + iVar22;
      uVar24 = uVar26 + 1;
      uVar43 = (ushort)((uint)iVar45 >> 0x10);
      auVar34._0_2_ = auVar48._2_2_;
      auVar33._0_12_ = ZEXT212(uVar43) << 0x30;
      auVar33._12_2_ = uVar43;
      auVar33._14_2_ = (short)((uint)iVar46 >> 0x10);
      auVar32._12_4_ = auVar33._12_4_;
      auVar32._0_10_ = (unkuint10)uVar43 << 0x30;
      auVar32._10_2_ = (short)((uint)iVar44 >> 0x10);
      auVar34._8_8_ =
           (undefined8)
           (CONCAT64(auVar32._10_6_,CONCAT22((short)((uint)iVar42 >> 0x10),uVar43)) >> 0x10);
      auVar34._6_2_ = auVar48._14_2_;
      auVar34._4_2_ = auVar48._10_2_;
      auVar34._2_2_ = auVar48._6_2_;
      iVar42 = uVar26 * 0x10;
      auVar34 = auVar34 & _DAT_00267f50;
      uVar43 = (ushort)((uint)(iVar54 + iVar22) >> 0x10);
      auVar41._0_2_ = (undefined2)((uint)iVar52 >> 0x10);
      auVar48._0_4_ = auVar48._0_4_ + iVar35;
      auVar48._4_4_ = iVar49 + iVar35;
      auVar48._8_4_ = iVar50 + iVar35;
      auVar48._12_4_ = iVar51 + iVar35;
      auVar40._0_12_ = ZEXT212(uVar43) << 0x30;
      auVar40._12_2_ = uVar43;
      auVar40._14_2_ = (short)((uint)(iVar55 + iVar22) >> 0x10);
      auVar39._12_4_ = auVar40._12_4_;
      auVar39._0_10_ = (unkuint10)uVar43 << 0x30;
      auVar39._10_2_ = (short)((uint)(iVar53 + iVar22) >> 0x10);
      auVar41._8_8_ =
           (undefined8)
           (CONCAT64(auVar39._10_6_,CONCAT22((short)((uint)(iVar52 + iVar22) >> 0x10),uVar43)) >>
           0x10);
      auVar41._6_2_ = (short)((uint)iVar55 >> 0x10);
      auVar41._4_2_ = (short)((uint)iVar54 >> 0x10);
      auVar41._2_2_ = (short)((uint)iVar53 >> 0x10);
      auVar41 = auVar41 & _DAT_00267f50;
      sVar2 = auVar34._0_2_;
      sVar3 = auVar34._2_2_;
      sVar4 = auVar34._4_2_;
      sVar5 = auVar34._6_2_;
      sVar6 = auVar34._8_2_;
      sVar7 = auVar34._10_2_;
      sVar8 = auVar34._12_2_;
      sVar9 = auVar34._14_2_;
      sVar10 = auVar41._0_2_;
      sVar11 = auVar41._2_2_;
      sVar12 = auVar41._4_2_;
      sVar13 = auVar41._6_2_;
      sVar14 = auVar41._8_2_;
      sVar15 = auVar41._10_2_;
      sVar16 = auVar41._12_2_;
      sVar17 = auVar41._14_2_;
      local_42c[iVar42] = (0 < sVar2) * (sVar2 < 0x100) * auVar34[0] - (0xff < sVar2);
      local_42c[iVar42 + 1] = (0 < sVar3) * (sVar3 < 0x100) * auVar34[2] - (0xff < sVar3);
      local_42c[iVar42 + 2] = (0 < sVar4) * (sVar4 < 0x100) * auVar34[4] - (0xff < sVar4);
      local_42c[iVar42 + 3] = (0 < sVar5) * (sVar5 < 0x100) * auVar34[6] - (0xff < sVar5);
      local_42c[iVar42 + 4] = (0 < sVar6) * (sVar6 < 0x100) * auVar34[8] - (0xff < sVar6);
      local_42c[iVar42 + 5] = (0 < sVar7) * (sVar7 < 0x100) * auVar34[10] - (0xff < sVar7);
      local_42c[iVar42 + 6] = (0 < sVar8) * (sVar8 < 0x100) * auVar34[0xc] - (0xff < sVar8);
      local_42c[iVar42 + 7] = (0 < sVar9) * (sVar9 < 0x100) * auVar34[0xe] - (0xff < sVar9);
      local_42c[iVar42 + 8] = (0 < sVar10) * (sVar10 < 0x100) * auVar41[0] - (0xff < sVar10);
      local_42c[iVar42 + 9] = (0 < sVar11) * (sVar11 < 0x100) * auVar41[2] - (0xff < sVar11);
      local_42c[iVar42 + 10] = (0 < sVar12) * (sVar12 < 0x100) * auVar41[4] - (0xff < sVar12);
      local_42c[iVar42 + 0xb] = (0 < sVar13) * (sVar13 < 0x100) * auVar41[6] - (0xff < sVar13);
      local_42c[iVar42 + 0xc] = (0 < sVar14) * (sVar14 < 0x100) * auVar41[8] - (0xff < sVar14);
      local_42c[iVar42 + 0xd] = (0 < sVar15) * (sVar15 < 0x100) * auVar41[10] - (0xff < sVar15);
      local_42c[iVar42 + 0xe] = (0 < sVar16) * (sVar16 < 0x100) * auVar41[0xc] - (0xff < sVar16);
      local_42c[iVar42 + 0xf] = (0 < sVar17) * (sVar17 < 0x100) * auVar41[0xe] - (0xff < sVar17);
      uVar26 = uVar24;
    } while (uVar24 < uVar1);
    iVar21 = iVar21 + uVar18 * iVar28;
    if (iVar28 == outwidth) goto LAB_0015c100;
  }
  local_42c[iVar28] = (byte)((uint)iVar21 >> 0x10);
  if (iVar28 + 1 < outwidth) {
    iVar22 = iVar21 + uVar18 + uVar18;
    local_42c[iVar28 + 1] = (byte)(iVar21 + uVar18 >> 0x10);
    if (iVar28 + 2 < outwidth) {
      iVar21 = iVar22 + uVar18;
      local_42c[iVar28 + 2] = (byte)((uint)iVar22 >> 0x10);
      if (iVar28 + 3 < outwidth) {
        iVar22 = iVar21 + uVar18;
        local_42c[iVar28 + 3] = (byte)((uint)iVar21 >> 0x10);
        if (iVar28 + 4 < outwidth) {
          iVar21 = iVar22 + uVar18;
          local_42c[iVar28 + 4] = (byte)((uint)iVar22 >> 0x10);
          if (iVar28 + 5 < outwidth) {
            iVar22 = iVar21 + uVar18;
            local_42c[iVar28 + 5] = (byte)((uint)iVar21 >> 0x10);
            if (iVar28 + 6 < outwidth) {
              iVar21 = iVar22 + uVar18;
              local_42c[iVar28 + 6] = (byte)((uint)iVar22 >> 0x10);
              if (iVar28 + 7 < outwidth) {
                iVar22 = iVar21 + uVar18;
                local_42c[iVar28 + 7] = (byte)((uint)iVar21 >> 0x10);
                if (iVar28 + 8 < outwidth) {
                  iVar21 = iVar22 + uVar18;
                  local_42c[iVar28 + 8] = (byte)((uint)iVar22 >> 0x10);
                  if (iVar28 + 9 < outwidth) {
                    iVar22 = iVar21 + uVar18;
                    local_42c[iVar28 + 9] = (byte)((uint)iVar21 >> 0x10);
                    if (iVar28 + 10 < outwidth) {
                      iVar21 = iVar22 + uVar18;
                      local_42c[iVar28 + 10] = (byte)((uint)iVar22 >> 0x10);
                      if (iVar28 + 0xb < outwidth) {
                        iVar22 = iVar21 + uVar18;
                        local_42c[iVar28 + 0xb] = (byte)((uint)iVar21 >> 0x10);
                        if (iVar28 + 0xc < outwidth) {
                          iVar21 = iVar22 + uVar18;
                          local_42c[iVar28 + 0xc] = (byte)((uint)iVar22 >> 0x10);
                          if (iVar28 + 0xd < outwidth) {
                            local_42c[iVar28 + 0xd] = (byte)((uint)iVar21 >> 0x10);
                            if (iVar28 + 0xe < outwidth) {
                              local_42c[iVar28 + 0xe] = (byte)(uVar18 + iVar21 >> 0x10);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0015c100:
  if (0 < outheight) {
    local_834 = 0;
    do {
      iVar28 = (int)((((float)local_834 + 0.25) * (float)inheight) / (float)outheight) * inwidth;
      iVar21 = (int)((((float)local_834 + 0.75) * (float)inheight) / (float)outheight) * inwidth;
      if (0 < outwidth) {
        iVar22 = 0;
        do {
          pbVar25 = in + (uint)local_82c[iVar22] + iVar28;
          pbVar19 = in + (uint)local_82c[iVar22] + iVar21;
          pbVar20 = in + (uint)local_42c[iVar22] + iVar28;
          pbVar27 = in + (uint)local_42c[iVar22] + iVar21;
          local_850[iVar22] =
               (byte)((int)((uint)*pbVar27 + (uint)*pbVar25 + (uint)*pbVar20 + (uint)*pbVar19) >> 2)
          ;
          local_850[iVar22 + 1] =
               (byte)((int)((uint)pbVar27[1] +
                           (uint)pbVar25[1] + (uint)pbVar20[1] + (uint)pbVar19[1]) >> 2);
          local_850[iVar22 + 2] =
               (byte)((int)((uint)pbVar27[2] +
                           (uint)pbVar25[2] + (uint)pbVar20[2] + (uint)pbVar19[2]) >> 2);
          local_850[iVar22 + 3] =
               (byte)((int)((uint)pbVar25[3] + (uint)pbVar20[3] + (uint)pbVar19[3] +
                           (uint)pbVar27[3]) >> 2);
          iVar22 = iVar22 + 1;
        } while (outwidth != iVar22);
      }
      local_834 = local_834 + 1;
      local_850 = local_850 + outwidth;
    } while (outheight != local_834);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// GL_ResampleTexture  @ 0015b7a0
void GL_ResampleTexture(uint *in,int inwidth,int inheight,uint *out,int outwidth,int outheight)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int local_2024;
  int local_201c [1024];
  int local_101c [1027];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uint * inrow@[???]
                       Unresolved local var: uint * inrow2@[???]
                       Unresolved local var: uint frac@[???]
                       Unresolved local var: uint fracstep@[???]
                       Unresolved local var: uint[1024] p1@[???]
                       Unresolved local var: uint[1024] p2@[???]
                       Unresolved local var: byte * pix1@[???]
                       Unresolved local var: byte * pix2@[???]
                       Unresolved local var: byte * pix3@[???]
                       Unresolved local var: byte * pix4@[???] */
  uVar3 = (inwidth << 0x10) / outwidth;
  uVar9 = uVar3 >> 2;
  if (outwidth < 1) goto LAB_0015b97a;
  uVar1 = (outwidth - 4U >> 2) + 1;
  iVar4 = uVar1 * 4;
  if (outwidth - 1U < 3) {
    iVar5 = 0;
    uVar16 = uVar9;
LAB_0015b86b:
    local_201c[iVar5] = (uVar16 >> 0x10) << 2;
    if (iVar5 + 1 < outwidth) {
      local_201c[iVar5 + 1] = (uVar16 + uVar3 >> 0x10) << 2;
      if (iVar5 + 2 < outwidth) {
        local_201c[iVar5 + 2] = (uVar16 + uVar3 + uVar3 >> 0x10) << 2;
      }
    }
    uVar16 = uVar9 * 3;
    if (2 < outwidth - 1U) goto LAB_0015b8bd;
    iVar4 = 0;
  }
  else {
    uVar16 = uVar3 + uVar9;
    uVar17 = uVar3 + uVar16;
    uVar18 = uVar3 + uVar17;
    iVar5 = uVar3 * 4;
    uVar10 = 0;
    uVar15 = uVar9;
    do {
      uVar13 = uVar10 + 1;
      uVar19 = uVar15 >> 0x10;
      uVar20 = uVar16 >> 0x10;
      uVar21 = uVar17 >> 0x10;
      uVar22 = uVar18 >> 0x10;
      uVar15 = uVar15 + iVar5;
      uVar16 = uVar16 + iVar5;
      uVar17 = uVar17 + iVar5;
      uVar18 = uVar18 + iVar5;
      local_201c[uVar10 * 4] = uVar19 << 2;
      local_201c[uVar10 * 4 + 1] = uVar20 << 2;
      local_201c[uVar10 * 4 + 2] = uVar21 << 2;
      local_201c[uVar10 * 4 + 3] = uVar22 << 2;
      uVar10 = uVar13;
    } while (uVar13 < uVar1);
    iVar5 = iVar4;
    uVar16 = uVar3 * iVar4 + uVar9;
    if (iVar4 - outwidth != 0) goto LAB_0015b86b;
LAB_0015b8bd:
    uVar16 = uVar9 * 3;
    uVar9 = uVar3 + uVar16;
    uVar17 = uVar3 + uVar9;
    iVar5 = uVar3 * 4;
    uVar18 = uVar3 + uVar17;
    uVar10 = 0;
    uVar15 = uVar16;
    do {
      uVar13 = uVar10 + 1;
      uVar19 = uVar15 >> 0x10;
      uVar20 = uVar9 >> 0x10;
      uVar21 = uVar17 >> 0x10;
      uVar22 = uVar18 >> 0x10;
      uVar15 = uVar15 + iVar5;
      uVar9 = uVar9 + iVar5;
      uVar17 = uVar17 + iVar5;
      uVar18 = uVar18 + iVar5;
      local_101c[uVar10 * 4] = uVar19 << 2;
      local_101c[uVar10 * 4 + 1] = uVar20 << 2;
      local_101c[uVar10 * 4 + 2] = uVar21 << 2;
      local_101c[uVar10 * 4 + 3] = uVar22 << 2;
      uVar10 = uVar13;
    } while (uVar13 < uVar1);
    uVar16 = uVar16 + uVar3 * iVar4;
    if (iVar4 - outwidth == 0) goto LAB_0015b97a;
  }
  local_101c[iVar4] = (uVar16 >> 0x10) << 2;
  if (iVar4 + 1 < outwidth) {
    local_101c[iVar4 + 1] = (uVar16 + uVar3 >> 0x10) << 2;
    if (iVar4 + 2 < outwidth) {
      local_101c[iVar4 + 2] = (uVar16 + uVar3 + uVar3 >> 0x10) << 2;
    }
  }
LAB_0015b97a:
  if (0 < outheight) {
    local_2024 = 0;
    do {
      iVar4 = (int)((((float)local_2024 + 0.25) * (float)inheight) / (float)outheight) * inwidth;
      iVar5 = (int)((((float)local_2024 + 0.75) * (float)inheight) / (float)outheight) * inwidth;
      if (0 < outwidth) {
        iVar14 = 0;
        puVar12 = out;
        do {
          pbVar6 = (byte *)((int)in + local_201c[iVar14] + iVar4 * 4);
          pbVar8 = (byte *)((int)in + local_201c[iVar14] + iVar5 * 4);
          piVar2 = local_101c + iVar14;
          iVar14 = iVar14 + 1;
          pbVar11 = (byte *)((int)in + *piVar2 + iVar4 * 4);
          pbVar7 = (byte *)((int)in + *piVar2 + iVar5 * 4);
          *(char *)puVar12 =
               (char)((int)((uint)*pbVar7 + (uint)*pbVar6 + (uint)*pbVar11 + (uint)*pbVar8) >> 2);
          *(char *)((int)puVar12 + 1) =
               (char)((int)((uint)pbVar7[1] + (uint)pbVar6[1] + (uint)pbVar11[1] + (uint)pbVar8[1])
                     >> 2);
          *(char *)((int)puVar12 + 2) =
               (char)((int)((uint)pbVar7[2] + (uint)pbVar6[2] + (uint)pbVar11[2] + (uint)pbVar8[2])
                     >> 2);
          *(char *)((int)puVar12 + 3) =
               (char)((int)((uint)pbVar6[3] + (uint)pbVar11[3] + (uint)pbVar8[3] + (uint)pbVar7[3])
                     >> 2);
          puVar12 = puVar12 + 1;
        } while (outwidth != iVar14);
      }
      local_2024 = local_2024 + 1;
      out = out + outwidth;
    } while (outheight != local_2024);
  }
  return;
}


// GL_ResampleTexturePoint  @ 0015cfa0
void GL_ResampleTexturePoint(byte *in,int inwidth,int inheight,byte *out,int outwidth,int outheight)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  int local_20;
  uint local_1c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uint ufrac@[???]
                       Unresolved local var: uint vfrac@[???]
                       Unresolved local var: uint ufracstep@[???]
                       Unresolved local var: uint vfracstep@[???]
                       Unresolved local var: byte * src@[???]
                       Unresolved local var: byte * dest@[???] */
  uVar2 = (inwidth << 0x10) / outwidth;
  local_20 = 0;
  uVar3 = (inheight << 0x10) / outheight;
  local_1c = uVar3 >> 2;
  if (0 < outheight) {
    do {
      if (0 < outwidth) {
        pbVar1 = out + outwidth;
        uVar4 = uVar2 >> 2;
        pbVar5 = out;
        do {
          out = pbVar5 + 1;
          uVar6 = uVar4 >> 0x10;
          uVar4 = uVar4 + uVar2;
          *pbVar5 = in[uVar6];
          pbVar5 = out;
        } while (out != pbVar1);
      }
      local_20 = local_20 + 1;
      local_1c = local_1c + uVar3;
      in = in + (local_1c >> 0x10) * inwidth;
      local_1c = local_1c & 0xffff;
    } while (outheight != local_20);
  }
  return;
}


// GL_SelectTexture  @ 00159320
void GL_SelectTexture(GLenum target)

{
  GLenum GVar1;
  int iVar2;
  
  if (gl_mtexable != 0) {
    (*qglSelectTextureSGIS)(target);
    iVar2 = TEXTURE0_SGIS;
    GVar1 = oldtarget;
    if (target != oldtarget) {
      oldtarget = target;
      cnttextures[GVar1 - TEXTURE0_SGIS] = currenttexture;
      currenttexture = cnttextures[target - iVar2];
      return;
    }
  }
  return;
}


// GL_SetMode  @ 00181990
/* WARNING: Type propagation algorithm not settling */

int GL_SetMode(HWND mainwindow,HDC *pmaindc,HGLRC *pbaseRC,int fD3D,char *pszDriver,char *pszCmdLine
              )

{
  int iVar1;
  char *pcVar2;
  GLenum GVar3;
  long lVar4;
  GLsizei local_3c;
  GLsizei local_38 [3];
  GLsizei local_2c;
  long local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
                    /* Unresolved local var: int iVidCmd@[???] */
  gfMiniDriver = 0;
  *pbaseRC = (HGLRC)0x0;
  *pmaindc = (HDC)0x0;
  iVar1 = COM_CheckParm("-stretchaspect");
  s_bEnforceAspect = (int)(iVar1 == 0);
  iVar1 = COM_CheckParm("-nomsaa");
  if (iVar1 != 0) {
    bDoMSAAFBO = 0;
  }
  iVar1 = COM_CheckParm("-nofbo");
  if (iVar1 != 0) {
    bDoScaledFBO = 0;
  }
  QGL_Init(pszDriver,pszCmdLine);
  gl_extensions = (char *)(*qglGetString)(0x1f03);
  s_bSupportsBlitTexturing = false;
  if (((GLubyte *)gl_extensions != (GLubyte *)0x0) &&
     (pcVar2 = Q_strstr(gl_extensions,"GL_EXT_framebuffer_multisample_blit_scaled"),
     pcVar2 != (char *)0x0)) {
    s_bSupportsBlitTexturing = true;
  }
  iVar1 = COM_CheckParm("-directblit");
  if (iVar1 != 0) {
    s_bSupportsBlitTexturing = true;
  }
  iVar1 = COM_CheckParm("-nodirectblit");
  if (iVar1 != 0) {
    s_bSupportsBlitTexturing = false;
  }
  if (((qglGenFramebuffersEXT == (_func_void_GLsizei_GLuint_ptr *)0x0) ||
      (qglBindFramebufferEXT == (_func_void_GLenum_GLuint *)0x0)) ||
     (qglBlitFramebufferEXT ==
      (_func_void_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLbitfield_GLenum *)0x0)) {
    bDoScaledFBO = 0;
  }
  if (((gl_extensions != (char *)0x0) &&
      (pcVar2 = Q_strstr(gl_extensions,"GL_ARB_texture_rectangle"), pcVar2 == (char *)0x0)) &&
     (pcVar2 = Q_strstr(gl_extensions,"GL_NV_texture_rectangle"), pcVar2 == (char *)0x0)) {
    bDoScaledFBO = 0;
  }
  iVar1 = VideoMode_IsWindowed();
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
  s_MSAAFBO.s_hBackBufferFBO = 0;
  if (iVar1 != 0) {
    s_MSAAFBO.s_hBackBufferFBO = 0;
    return 1;
  }
  s_MSAAFBO.s_hBackBufferCB = 0;
  s_MSAAFBO.s_hBackBufferDB = 0;
  s_MSAAFBO.s_hBackBufferTex = 0;
  s_BackBufferFBO.s_hBackBufferFBO = 0;
  s_BackBufferFBO.s_hBackBufferCB = 0;
  s_BackBufferFBO.s_hBackBufferDB = 0;
  s_BackBufferFBO.s_hBackBufferTex = 0;
  VideoMode_GetCurrentVideoMode(&local_3c,local_38,(int *)0x0);
  if (((qglRenderbufferStorageMultisampleEXT ==
        (_func_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei *)0x0) || (bDoMSAAFBO < 1)) ||
     ((gl_extensions == (char *)0x0 ||
      (pcVar2 = Q_strstr(gl_extensions,"GL_EXT_framebuffer_multisample"), pcVar2 == (char *)0x0))))
  {
    Con_DPrintf("MSAA backbuffer rendering disabled.\n");
LAB_00181d43:
    s_MSAAFBO.s_hBackBufferFBO = 0;
    if (bDoScaledFBO < 1) goto LAB_00181ef0;
  }
  else {
    (*qglGenFramebuffersEXT)(1,&s_MSAAFBO.s_hBackBufferFBO);
    (*qglBindFramebufferEXT)(0x8d40,s_MSAAFBO.s_hBackBufferFBO);
    (*qglGenRenderbuffersEXT)(1,(GLuint *)0xf8da0c);
    (*qglBindRenderbufferEXT)(0x8d41,s_MSAAFBO.s_hBackBufferCB);
    (*qglRenderbufferStorageMultisampleEXT)(0x8d41,4,0x8058,local_3c,local_38[0]);
    (*qglFramebufferRenderbufferEXT)(0x8d40,0x8ce0,0x8d41,s_MSAAFBO.s_hBackBufferCB);
    (*qglGenRenderbuffersEXT)(1,(GLuint *)0xf8da10);
    (*qglBindRenderbufferEXT)(0x8d41,s_MSAAFBO.s_hBackBufferDB);
    (*qglRenderbufferStorageMultisampleEXT)(0x8d41,4,0x81a6,local_3c,local_38[0]);
    (*qglFramebufferRenderbufferEXT)(0x8d40,0x8d00,0x8d41,s_MSAAFBO.s_hBackBufferDB);
    GVar3 = (*qglCheckFramebufferStatusEXT)(0x8d40);
    if (GVar3 != 0x8cd5) {
      if (s_MSAAFBO.s_hBackBufferFBO != 0) {
        (*qglDeleteFramebuffersEXT)(1,&s_MSAAFBO.s_hBackBufferFBO);
      }
      s_MSAAFBO.s_hBackBufferFBO = 0;
      if (s_MSAAFBO.s_hBackBufferCB != 0) {
        (*qglDeleteRenderbuffersEXT)(1,(GLuint *)0xf8da0c);
      }
      s_MSAAFBO.s_hBackBufferCB = 0;
      if (s_MSAAFBO.s_hBackBufferDB != 0) {
        (*qglDeleteRenderbuffersEXT)(1,(GLuint *)0xf8da10);
      }
      s_MSAAFBO.s_hBackBufferDB = 0;
      if (s_MSAAFBO.s_hBackBufferTex != 0) {
        (*qglDeleteTextures)(1,(GLuint *)0xf8da14);
      }
      s_MSAAFBO.s_hBackBufferTex = 0;
      Con_DPrintf("Error initializing MSAA frame buffer\n");
      goto LAB_00181d43;
    }
    if (bDoScaledFBO < 1) goto LAB_00181ef0;
    if (s_MSAAFBO.s_hBackBufferFBO != 0) {
      glEnable(0x809d);
    }
  }
                    /* Unresolved local var: int GL_TEX_MODE@[???] */
  glEnable(0x84f5);
  (*qglGenFramebuffersEXT)(1,&s_BackBufferFBO.s_hBackBufferFBO);
  (*qglBindFramebufferEXT)(0x8d40,s_BackBufferFBO.s_hBackBufferFBO);
  if (s_MSAAFBO.s_hBackBufferFBO == 0) {
    (*qglGenRenderbuffersEXT)(1,(GLuint *)0xf8da9c);
    (*qglBindRenderbufferEXT)(0x8d41,s_BackBufferFBO.s_hBackBufferDB);
    (*qglRenderbufferStorageEXT)(0x8d41,0x81a6,local_3c,local_38[0]);
    (*qglFramebufferRenderbufferEXT)(0x8d40,0x8d00,0x8d41,s_BackBufferFBO.s_hBackBufferDB);
  }
  glGenTextures(1,0xf8daa0);
  glBindTexture(0x84f5,s_BackBufferFBO.s_hBackBufferTex);
  glTexParameteri(0x84f5,0x2800,0x2601);
  glTexParameteri(0x84f5,0x2801,0x2601);
  glTexParameteri(0x84f5,0x2802,0x812f);
  glTexParameteri(0x84f5,0x2803,0x812f);
  glTexEnvi(0x2300,0x2200,0x1e01);
  glTexImage2D(0x84f5,0,0x1908,local_3c,local_38[0],0,0x1908,0x1401,0);
  (*qglFramebufferTexture2DEXT)(0x8d40,0x8ce0,0x84f5,s_BackBufferFBO.s_hBackBufferTex,0);
  glBindTexture(0x84f5,0);
  glDisable(0x84f5);
LAB_00181ef0:
  if ((bDoScaledFBO == 0) || (GVar3 = (*qglCheckFramebufferStatusEXT)(0x8d40), GVar3 != 0x8cd5)) {
                    /* Unresolved local var: int iFreq@[???]
                       Unresolved local var: int refresh@[???]
                       Unresolved local var: SDL_DisplayMode requestedMode@[???]
                       Unresolved local var: SDL_DisplayMode mode@[???] */
    FreeFBOObjects();
    iVar1 = COM_CheckParm("-freq");
    if (iVar1 == 0) {
      lVar4 = 0;
    }
    else {
      lVar4 = strtol(com_argv[iVar1 + 1],(char **)0x0,10);
      Con_DPrintf("Setting refresh rate to %dHz\n",lVar4);
    }
    local_38[2] = local_3c;
    local_2c = local_38[0];
    local_38[1] = 0;
    local_28 = lVar4;
    iVar1 = SDL_GetClosestDisplayMode(0,local_38 + 1,&local_20);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Error initializing Main frame buffer\n");
    }
    Con_DPrintf("Setting closest display mode: width:%d height:%d freq:%d format:%u\n",local_1c,
                local_18,local_14,local_20);
    if (bDoScaledFBO == 0) {
      Con_DPrintf("FBO backbuffer rendering disabled.\n",local_1c,local_18,local_14,local_20);
    }
    else {
      Con_DPrintf("FBO backbuffer rendering disabled due to create error.\n",local_1c,local_18,
                  local_14,local_20);
    }
    SDL_SetWindowDisplayMode(mainwindow,&local_20);
    bNeedsFullScreenModeSwitch = 1;
    VideoMode_RestoreVideo();
  }
  if (bDoScaledFBO < 1) {
    return 1;
  }
  (*qglBindFramebufferEXT)(0x8d40,0);
  return 1;
}


// GL_Shutdown  @ 001821d0
void GL_Shutdown(HWND hwnd,HDC hdc,HGLRC hglrc)

{
  if (s_MSAAFBO.s_hBackBufferFBO != 0) {
    (*qglDeleteFramebuffersEXT)(1,&s_MSAAFBO.s_hBackBufferFBO);
  }
  s_MSAAFBO.s_hBackBufferFBO = 0;
  if (s_MSAAFBO.s_hBackBufferCB != 0) {
    (*qglDeleteRenderbuffersEXT)(1,(GLuint *)0xf8da0c);
  }
  s_MSAAFBO.s_hBackBufferCB = 0;
  if (s_MSAAFBO.s_hBackBufferDB != 0) {
    (*qglDeleteRenderbuffersEXT)(1,(GLuint *)0xf8da10);
  }
  s_MSAAFBO.s_hBackBufferDB = 0;
  if (s_MSAAFBO.s_hBackBufferTex != 0) {
    (*qglDeleteTextures)(1,(GLuint *)0xf8da14);
  }
  s_MSAAFBO.s_hBackBufferTex = 0;
  if (s_BackBufferFBO.s_hBackBufferFBO != 0) {
    (*qglDeleteFramebuffersEXT)(1,&s_BackBufferFBO.s_hBackBufferFBO);
  }
  s_BackBufferFBO.s_hBackBufferFBO = 0;
  if (s_BackBufferFBO.s_hBackBufferCB != 0) {
    (*qglDeleteRenderbuffersEXT)(1,(GLuint *)0xf8da98);
  }
  s_BackBufferFBO.s_hBackBufferCB = 0;
  if (s_BackBufferFBO.s_hBackBufferDB != 0) {
    (*qglDeleteRenderbuffersEXT)(1,(GLuint *)0xf8da9c);
  }
  s_BackBufferFBO.s_hBackBufferDB = 0;
  if (s_BackBufferFBO.s_hBackBufferTex != 0) {
    (*qglDeleteTextures)(1,(GLuint *)0xf8daa0);
  }
  s_BackBufferFBO.s_hBackBufferTex = 0;
  return;
}


// GL_SubdivideSurface  @ 0018bd90
void GL_SubdivideSurface(msurface_t *fa)

{
  vec_t vVar1;
  uint numverts;
  int iVar2;
  vec_t *pvVar3;
  vec_t *pvVar4;
  int iVar5;
  mvertex_t *pmVar6;
  float *local_320;
  float local_31c [195];
  
                    /* Unresolved local var: vec_t[64][3] verts@[???]
                       Unresolved local var: int numverts@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int lindex@[???]
                       Unresolved local var: float * vec@[???] */
  numverts = fa->numedges;
  warpface = fa;
  if (0x40 < numverts) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Too many edges in model %s\n",loadmodel);
  }
  if (numverts != 0) {
    iVar5 = fa->firstedge << 2;
    pvVar4 = local_31c;
    do {
      iVar2 = *(int *)((int)loadmodel->surfedges + iVar5);
      if (iVar2 < 1) {
        pmVar6 = loadmodel->vertexes + loadmodel->edges[-iVar2].v[1];
        vVar1 = pmVar6->position[0];
      }
      else {
        pmVar6 = loadmodel->vertexes + loadmodel->edges[iVar2].v[0];
        vVar1 = pmVar6->position[0];
      }
      *pvVar4 = vVar1;
      pvVar3 = pvVar4 + 3;
      iVar5 = iVar5 + 4;
      pvVar4[1] = pmVar6->position[1];
      pvVar4[2] = pmVar6->position[2];
      pvVar4 = pvVar3;
    } while (local_31c + numverts * 3 != pvVar3);
  }
  local_320 = local_31c;
  SubdividePolygon(numverts,local_320);
  return;
}


// GL_Texels_f  @ 00158f20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_Texels_f(void)

{
  Con_Printf("Current uploaded texels: %i\n",texels);
  return;
}


// GL_UnloadTexture  @ 0015f9b0
void GL_UnloadTexture(char *identifier)

{
  int iVar1;
  gltexture_t *dest;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: gltexture_t * glt@[???] */
  if (0 < numgltextures) {
    dest = gltextures;
    iVar2 = 0;
    do {
      iVar1 = Q_strcmp(identifier,dest->identifier);
      if (iVar1 == 0) {
        if ((short)(dest->servercount & -0x8000) != 0) {
          return;
        }
                    /* Unresolved local var: int texnum@[???] */
        (*qglDeleteTextures)(1,(GLuint *)dest);
        iVar2 = (int)dest->paletteIndex;
        if (-1 < iVar2) {
          if (gGLPalette[iVar2].referenceCount < 2) {
            if (iVar2 < 0x15e) {
              gGLPalette[iVar2].tag = -1;
              gGLPalette[iVar2].referenceCount = 0;
            }
          }
          else {
            gGLPalette[iVar2].referenceCount = gGLPalette[iVar2].referenceCount + -1;
          }
        }
        Q_memset(dest,0,0x54);
        dest->servercount = -1;
        return;
      }
      iVar2 = iVar2 + 1;
      dest = dest + 1;
    } while (iVar2 < numgltextures);
  }
  return;
}


// GL_UnloadTextures  @ 0015f8f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_UnloadTextures(void)

{
  int iVar1;
  gltexture_t *dest;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: gltexture_t * glt@[???] */
  if (0 < numgltextures) {
    iVar2 = 0;
    dest = gltextures;
    iVar1 = numgltextures;
    do {
      if ((0 < dest->servercount) && (dest->servercount != gHostSpawnCount)) {
        (*qglDeleteTextures)(1,(GLuint *)dest);
        iVar1 = (int)dest->paletteIndex;
        if (-1 < iVar1) {
          if (gGLPalette[iVar1].referenceCount < 2) {
            if (iVar1 < 0x15e) {
              gGLPalette[iVar1].tag = -1;
              gGLPalette[iVar1].referenceCount = 0;
            }
          }
          else {
                    /* Unresolved local var: int texnum@[???] */
            gGLPalette[iVar1].referenceCount = gGLPalette[iVar1].referenceCount + -1;
          }
        }
        Q_memset(dest,0,0x54);
        iVar1 = numgltextures;
        dest->servercount = -1;
      }
      iVar2 = iVar2 + 1;
      dest = dest + 1;
    } while (iVar2 < iVar1);
  }
  return;
}


// GL_Upload16  @ 0015f550
void GL_Upload16(byte *data,int width,int height,qboolean mipmap,int iType,byte *pPal,int filter)

{
  bool bVar1;
  byte bVar2;
  uint count;
  byte *pbVar3;
  uint *puVar4;
  uint *puVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  byte *pbVar9;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: qboolean noalpha@[???]
                       Unresolved local var: int p@[???]
                       Unresolved local var: byte * pb@[???] */
  count = width * height;
  if (0x12c000 < count) {
    Con_Printf("Can\'t upload (%ix%i) texture, it\'s > 640*480 bytes\n");
    return;
  }
  if (iType == 2) {
    Q_memcpy(GL_Upload16::trans,data,count);
    goto LAB_0015f687;
  }
  if (pPal == (byte *)0x0) {
    return;
  }
  pbVar9 = pPal;
  do {
    pbVar3 = pbVar9 + 1;
    *pbVar9 = texgammatable[*pbVar9];
    pbVar9 = pbVar3;
  } while (pbVar3 != pPal + 0x300);
  if ((iType - 3U < 2) || (iType == 1)) {
    if (count != 0) {
      if (iType == 3) {
        uVar8 = 0;
        do {
          GL_Upload16::trans[uVar8] = (uint)data[uVar8] << 0x18 | *(uint *)(pPal + 0x2fd) & 0xffffff
          ;
          uVar8 = uVar8 + 1;
        } while (count != uVar8);
        goto LAB_0015f687;
      }
      if (iType == 4) {
        uVar8 = 0;
        do {
          GL_Upload16::trans[uVar8] =
               (uint)data[uVar8] << 0x18 | *(uint *)(pPal + (uint)data[uVar8] * 3) & 0xffffff;
          uVar8 = uVar8 + 1;
        } while (count != uVar8);
        goto LAB_0015f687;
      }
      bVar1 = true;
      uVar8 = 0;
      do {
        while (data[uVar8] == 0xff) {
          bVar1 = false;
          GL_Upload16::trans[uVar8] = 0;
          uVar8 = uVar8 + 1;
          if (count == uVar8) goto LAB_0015f71c;
        }
        GL_Upload16::trans[uVar8] = *(uint *)(pPal + (uint)data[uVar8] * 3) | 0xff000000;
        uVar8 = uVar8 + 1;
      } while (count != uVar8);
LAB_0015f71c:
      if (!bVar1) goto LAB_0015f687;
    }
  }
  else {
    if (iType != 0) {
      Con_Printf("Upload16:Bogus texture type!/n");
      goto LAB_0015f687;
    }
    if ((count & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("GL_Upload16: s&3");
    }
    if (gl_dither.value == 0.0) {
      if (count != 0) {
        puVar4 = GL_Upload16::trans;
        do {
          puVar5 = puVar4 + 4;
          *puVar4 = *(uint *)(pPal + (uint)*data * 3) | 0xff000000;
          puVar4[1] = *(uint *)(pPal + (uint)data[1] * 3) | 0xff000000;
          puVar4[2] = *(uint *)(pPal + (uint)data[2] * 3) | 0xff000000;
          puVar4[3] = *(uint *)(pPal + (uint)data[3] * 3) | 0xff000000;
          puVar4 = puVar5;
          data = data + 4;
        } while ((uint *)((int)GL_Upload16::trans + (count * 4 - 4 & 0xfffffff0) + 0x10) != puVar5);
      }
    }
    else if (count != 0) {
      uVar8 = 0;
      do {
                    /* Unresolved local var: byte r@[???]
                       Unresolved local var: byte g@[???]
                       Unresolved local var: byte b@[???]
                       Unresolved local var: byte * ppix@[???] */
        pbVar9 = pPal + (uint)data[uVar8] * 3;
        bVar7 = *pbVar9 >> 6 | *pbVar9;
        *pbVar9 = bVar7;
        bVar6 = pbVar9[1] >> 6 | pbVar9[1];
        pbVar9[1] = bVar6;
        bVar2 = pbVar9[2] | pbVar9[2] >> 6;
        pbVar9[2] = bVar2;
        GL_Upload16::trans[uVar8] = (uint)bVar2 << 0x10 | bVar7 | 0xff000000 | (uint)bVar6 << 8;
        uVar8 = uVar8 + 1;
      } while (count != uVar8);
    }
  }
  iType = 0;
LAB_0015f687:
  GL_Upload32(GL_Upload16::trans,width,height,mipmap,iType,filter);
  return;
}


// GL_Upload32  @ 0015c2d0
void __regparm3 GL_Upload32(uint *data,int width,int height,qboolean mipmap,int iType,int filter)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  GLenum GVar11;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_40;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int iComponent@[???]
                       Unresolved local var: int iFormat@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: qboolean f4444@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int bpp@[???] */
  VideoMode_GetCurrentVideoMode(&local_28,&local_24,local_20);
  iVar1 = giTotalTextures;
  uVar5 = width * height;
  giTotalTexBytes = uVar5 + giTotalTexBytes;
  if (mipmap == 2) {
LAB_0015c347:
                    /* Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: int max_size@[???] */
    giTotalTextures = iVar1 + 1;
  }
  else {
    giTotalTextures = giTotalTextures + 1;
    giTotalTexBytes = giTotalTexBytes + width * 2 * height;
    if ((gl_spriteblend.value == 0.0) ||
       (((1 < mipmap - 3 && (mipmap != true)) || ((int)uVar5 < 1)))) goto LAB_0015c347;
    uVar7 = 0;
    puVar10 = data;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int acount@[???]
                       Unresolved local var: int u@[???]
                       Unresolved local var: int v@[???]
                       Unresolved local var: byte * pixel@[???] */
    do {
      while (*puVar10 != 0) {
        uVar7 = uVar7 + 1;
        puVar10 = puVar10 + 1;
        if (uVar5 == uVar7) goto joined_r0x0015c34f;
      }
      iVar6 = (int)uVar7 / width;
      iVar8 = (int)uVar7 % width;
      iVar1 = iVar8 + -1;
      iVar2 = iVar6 + -1;
      if ((iVar1 < width) && (-1 < iVar1)) {
        if (((iVar2 < 0) || (height <= iVar2)) ||
           (puVar4 = data + iVar2 * width + iVar1, *(byte *)((int)puVar4 + 3) == 0)) {
          local_48 = 1;
          uVar9 = 0;
          local_4c = 0;
          local_50 = 0;
          local_54 = 0;
        }
        else {
          local_4c = (uint)(byte)*puVar4;
          local_50 = (uint)*(byte *)((int)puVar4 + 1);
          local_54 = (uint)*(byte *)((int)puVar4 + 2);
          local_48 = 2;
          uVar9 = 1;
        }
        if (((iVar6 < height) && (-1 < iVar6)) &&
           (puVar4 = data + width * iVar6 + iVar1, *(byte *)((int)puVar4 + 3) != 0)) {
          local_4c = local_4c + (byte)*puVar4;
          local_50 = local_50 + *(byte *)((int)puVar4 + 1);
          local_54 = local_54 + *(byte *)((int)puVar4 + 2);
          uVar9 = local_48;
        }
        iVar3 = iVar6 + 1;
        if (((-1 < iVar3) && (iVar3 < height)) &&
           (puVar4 = data + iVar1 + width * iVar3, *(byte *)((int)puVar4 + 3) != 0)) {
          uVar9 = uVar9 + 1;
          local_4c = local_4c + (byte)*puVar4;
          local_50 = local_50 + *(byte *)((int)puVar4 + 1);
          local_54 = local_54 + *(byte *)((int)puVar4 + 2);
        }
      }
      else {
        uVar9 = 0;
        local_50 = 0;
        local_4c = 0;
        local_54 = 0;
      }
      local_48 = iVar6 + 1;
      if ((-1 < iVar8) && (iVar8 < width)) {
        if ((-1 < iVar2) &&
           ((iVar2 < height &&
            (puVar4 = data + iVar2 * width + iVar8, *(byte *)((int)puVar4 + 3) != 0)))) {
          uVar9 = uVar9 + 1;
          local_4c = local_4c + (byte)*puVar4;
          local_50 = local_50 + *(byte *)((int)puVar4 + 1);
          local_54 = local_54 + *(byte *)((int)puVar4 + 2);
        }
        if (((-1 < iVar6) && (iVar6 < height)) &&
           (puVar4 = data + width * iVar6 + iVar8, *(byte *)((int)puVar4 + 3) != 0)) {
          uVar9 = uVar9 + 1;
          local_4c = local_4c + (byte)*puVar4;
          local_50 = local_50 + *(byte *)((int)puVar4 + 1);
          local_54 = local_54 + *(byte *)((int)puVar4 + 2);
        }
        if (((-1 < (int)local_48) && ((int)local_48 < height)) &&
           (puVar4 = data + width * local_48 + iVar8, *(byte *)((int)puVar4 + 3) != 0)) {
          uVar9 = uVar9 + 1;
          local_4c = local_4c + (byte)*puVar4;
          local_50 = local_50 + *(byte *)((int)puVar4 + 1);
          local_54 = local_54 + *(byte *)((int)puVar4 + 2);
        }
      }
      iVar8 = iVar8 + 1;
      if ((iVar8 < 0) || (width <= iVar8)) {
LAB_0015c610:
        if (uVar9 == 0) {
          uVar9 = 1;
        }
      }
      else {
        if ((-1 < iVar2) &&
           ((iVar2 < height &&
            (puVar4 = data + iVar2 * width + iVar8, *(byte *)((int)puVar4 + 3) != 0)))) {
          uVar9 = uVar9 + 1;
          local_4c = local_4c + (byte)*puVar4;
          local_50 = local_50 + *(byte *)((int)puVar4 + 1);
          local_54 = local_54 + *(byte *)((int)puVar4 + 2);
        }
        if (((-1 < iVar6) && (iVar6 < height)) &&
           (puVar4 = data + iVar6 * width + iVar8, *(byte *)((int)puVar4 + 3) != 0)) {
          uVar9 = uVar9 + 1;
          local_4c = local_4c + (byte)*puVar4;
          local_50 = local_50 + *(byte *)((int)puVar4 + 1);
          local_54 = local_54 + *(byte *)((int)puVar4 + 2);
        }
        if ((((int)local_48 < 0) || (height <= (int)local_48)) ||
           (puVar4 = data + iVar8 + width * local_48, *(byte *)((int)puVar4 + 3) == 0))
        goto LAB_0015c610;
        uVar9 = uVar9 + 1;
        local_4c = local_4c + (byte)*puVar4;
        local_50 = local_50 + *(byte *)((int)puVar4 + 1);
        local_54 = local_54 + *(byte *)((int)puVar4 + 2);
      }
      uVar7 = uVar7 + 1;
      *(undefined1 *)((int)puVar10 + 3) = 0;
      *(char *)puVar10 = (char)(local_4c / uVar9);
      *(char *)((int)puVar10 + 1) = (char)(local_50 / uVar9);
      *(char *)((int)puVar10 + 2) = (char)(local_54 / uVar9);
      puVar10 = puVar10 + 1;
    } while (uVar5 != uVar7);
  }
joined_r0x0015c34f:
  iVar1 = width;
  iVar2 = height;
  if (g_bSupportsNPOTTextures == false) {
    ComputeScaledSize(&local_30,&local_2c,width,height);
    uVar5 = local_2c * local_30;
    iVar1 = local_30;
    iVar2 = local_2c;
  }
  local_2c = iVar2;
  local_30 = iVar1;
  if (0x80000 < uVar5) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("GL_LoadTexture: too big");
  }
  switch(mipmap) {
  case false:
    local_40 = 0x8058;
    if (local_20[0] == 0x10) {
      local_40 = 0x8051;
    }
    if (width != local_30) goto LAB_0015c70d;
    goto LAB_0015c856;
  case true:
  case 3:
    local_40 = (uint)(local_20[0] != 0x10) * 2 + 0x8056;
    break;
  case 2:
    if ((width == local_30) && (height == local_2c)) {
      GVar11 = 0x1909;
      local_40 = 0x8040;
      goto LAB_0015c76e;
    }
    GVar11 = 0x1909;
    local_40 = 0x8040;
    goto LAB_0015c6c6;
  case 4:
    local_40 = (local_20[0] != 0x10) + 0x8057;
    if (width == local_30) goto LAB_0015c856;
    goto LAB_0015c70d;
  }
  if (width == local_30) {
LAB_0015c856:
    if (height == local_2c) {
      GVar11 = 0x1908;
      goto LAB_0015c76e;
    }
  }
  if (mipmap == 2) {
    GVar11 = 0x1908;
LAB_0015c6c6:
    GL_ResampleAlphaTexture((byte *)data,width,height,(byte *)GL_Upload32::scaled,local_30,local_2c)
    ;
  }
  else {
LAB_0015c70d:
    GVar11 = 0x1908;
    GL_ResampleTexture(data,width,height,GL_Upload32::scaled,local_30,local_2c);
  }
  texels = texels + local_30 * local_2c;
  data = GL_Upload32::scaled;
  width = local_30;
  height = local_2c;
LAB_0015c76e:
  (*qglTexImage2D)(0xde1,0,local_40,width,height,0,GVar11,0x1401,data);
  (*qglTexParameterf)(0xde1,0x2801,(float)iType);
  (*qglTexParameterf)(0xde1,0x2800,(float)iType);
  (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
  return;
}


// GL_Upload32  @ 0015e450
void GL_Upload32(uint *data,int width,int height,qboolean mipmap,int iType,int filter)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  GLenum GVar9;
  uint uVar10;
  int iVar11;
  int unaff_EDI;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int iComponent@[???]
                       Unresolved local var: int iFormat@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: qboolean f4444@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int bpp@[???] */
  VideoMode_GetCurrentVideoMode(&local_28,&local_24,local_20);
  iVar11 = giTotalTextures;
  uVar4 = height * width;
  giTotalTexBytes = uVar4 + giTotalTexBytes;
  if (iType == 2) {
LAB_0015e4cf:
                    /* Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: int max_size@[???] */
    giTotalTextures = iVar11 + 1;
  }
  else {
    giTotalTextures = giTotalTextures + 1;
    giTotalTexBytes = giTotalTexBytes + width * 2 * height;
    if ((gl_spriteblend.value == 0.0) || (((1 < iType - 3U && (iType != 1)) || ((int)uVar4 < 1))))
    goto LAB_0015e4cf;
    uVar6 = 0;
    puVar8 = data;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int acount@[???]
                       Unresolved local var: int u@[???]
                       Unresolved local var: int v@[???]
                       Unresolved local var: byte * pixel@[???] */
    do {
      while (*puVar8 != 0) {
        uVar6 = uVar6 + 1;
        puVar8 = puVar8 + 1;
        if (uVar4 == uVar6) goto joined_r0x0015e4d6;
      }
      iVar5 = (int)uVar6 / width;
      iVar7 = (int)uVar6 % width;
      iVar11 = iVar7 + -1;
      iVar1 = iVar5 + -1;
      if ((iVar11 < width) && (-1 < iVar11)) {
        if (((iVar1 < 0) || (height <= iVar1)) ||
           (puVar3 = data + iVar1 * width + iVar11, *(byte *)((int)puVar3 + 3) == 0)) {
          local_48 = 1;
          uVar10 = 0;
          local_4c = 0;
          local_50 = 0;
          local_54 = 0;
        }
        else {
          local_4c = (uint)(byte)*puVar3;
          local_50 = (uint)*(byte *)((int)puVar3 + 1);
          local_54 = (uint)*(byte *)((int)puVar3 + 2);
          local_48 = 2;
          uVar10 = 1;
        }
        if (((iVar5 < height) && (-1 < iVar5)) &&
           (puVar3 = data + width * iVar5 + iVar11, *(byte *)((int)puVar3 + 3) != 0)) {
          local_4c = local_4c + (byte)*puVar3;
          local_50 = local_50 + *(byte *)((int)puVar3 + 1);
          local_54 = local_54 + *(byte *)((int)puVar3 + 2);
          uVar10 = local_48;
        }
        iVar2 = iVar5 + 1;
        if (((-1 < iVar2) && (iVar2 < height)) &&
           (puVar3 = data + iVar11 + width * iVar2, *(byte *)((int)puVar3 + 3) != 0)) {
          uVar10 = uVar10 + 1;
          local_4c = local_4c + (byte)*puVar3;
          local_50 = local_50 + *(byte *)((int)puVar3 + 1);
          local_54 = local_54 + *(byte *)((int)puVar3 + 2);
        }
      }
      else {
        uVar10 = 0;
        local_50 = 0;
        local_4c = 0;
        local_54 = 0;
      }
      local_48 = iVar5 + 1;
      if ((-1 < iVar7) && (iVar7 < width)) {
        if ((-1 < iVar1) &&
           ((iVar1 < height &&
            (puVar3 = data + iVar1 * width + iVar7, *(byte *)((int)puVar3 + 3) != 0)))) {
          uVar10 = uVar10 + 1;
          local_4c = local_4c + (byte)*puVar3;
          local_50 = local_50 + *(byte *)((int)puVar3 + 1);
          local_54 = local_54 + *(byte *)((int)puVar3 + 2);
        }
        if (((-1 < iVar5) && (iVar5 < height)) &&
           (puVar3 = data + width * iVar5 + iVar7, *(byte *)((int)puVar3 + 3) != 0)) {
          uVar10 = uVar10 + 1;
          local_4c = local_4c + (byte)*puVar3;
          local_50 = local_50 + *(byte *)((int)puVar3 + 1);
          local_54 = local_54 + *(byte *)((int)puVar3 + 2);
        }
        if (((-1 < (int)local_48) && ((int)local_48 < height)) &&
           (puVar3 = data + width * local_48 + iVar7, *(byte *)((int)puVar3 + 3) != 0)) {
          uVar10 = uVar10 + 1;
          local_4c = local_4c + (byte)*puVar3;
          local_50 = local_50 + *(byte *)((int)puVar3 + 1);
          local_54 = local_54 + *(byte *)((int)puVar3 + 2);
        }
      }
      iVar7 = iVar7 + 1;
      if ((iVar7 < 0) || (width <= iVar7)) {
LAB_0015e810:
        if (uVar10 == 0) {
          uVar10 = 1;
        }
      }
      else {
        if ((-1 < iVar1) &&
           ((iVar1 < height &&
            (puVar3 = data + iVar1 * width + iVar7, *(byte *)((int)puVar3 + 3) != 0)))) {
          uVar10 = uVar10 + 1;
          local_4c = local_4c + (byte)*puVar3;
          local_50 = local_50 + *(byte *)((int)puVar3 + 1);
          local_54 = local_54 + *(byte *)((int)puVar3 + 2);
        }
        if (((-1 < iVar5) && (iVar5 < height)) &&
           (puVar3 = data + iVar5 * width + iVar7, *(byte *)((int)puVar3 + 3) != 0)) {
          uVar10 = uVar10 + 1;
          local_4c = local_4c + (byte)*puVar3;
          local_50 = local_50 + *(byte *)((int)puVar3 + 1);
          local_54 = local_54 + *(byte *)((int)puVar3 + 2);
        }
        if ((((int)local_48 < 0) || (height <= (int)local_48)) ||
           (puVar3 = data + iVar7 + width * local_48, *(byte *)((int)puVar3 + 3) == 0))
        goto LAB_0015e810;
        uVar10 = uVar10 + 1;
        local_4c = local_4c + (byte)*puVar3;
        local_50 = local_50 + *(byte *)((int)puVar3 + 1);
        local_54 = local_54 + *(byte *)((int)puVar3 + 2);
      }
      uVar6 = uVar6 + 1;
      *(undefined1 *)((int)puVar8 + 3) = 0;
      *(char *)puVar8 = (char)(local_4c / uVar10);
      *(char *)((int)puVar8 + 1) = (char)(local_50 / uVar10);
      *(char *)((int)puVar8 + 2) = (char)(local_54 / uVar10);
      puVar8 = puVar8 + 1;
    } while (uVar4 != uVar6);
  }
joined_r0x0015e4d6:
  iVar11 = width;
  iVar1 = height;
  uVar6 = uVar4;
  if (g_bSupportsNPOTTextures == false) {
    ComputeScaledSize(&local_30,&local_2c,width,height);
    iVar11 = local_30;
    iVar1 = local_2c;
    uVar6 = local_2c * local_30;
  }
  local_2c = iVar1;
  local_30 = iVar11;
  if (0x80000 < uVar6) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("GL_LoadTexture: too big");
  }
  switch(iType) {
  case 0:
    unaff_EDI = 0x8058;
    if (local_20[0] == 0x10) {
      unaff_EDI = 0x8051;
    }
    if (width != local_30) goto LAB_0015e911;
    goto LAB_0015ea6c;
  case 1:
  case 3:
    unaff_EDI = (uint)(local_20[0] != 0x10) * 2 + 0x8056;
    break;
  case 2:
    if ((width != local_30) || (height != local_2c)) {
      GVar9 = 0x1909;
      unaff_EDI = 0x8040;
      goto LAB_0015e8c2;
    }
    GVar9 = 0x1909;
    unaff_EDI = 0x8040;
    goto LAB_0015ea7a;
  case 4:
    unaff_EDI = (local_20[0] != 0x10) + 0x8057;
    if (width == local_30) goto LAB_0015ea6c;
    goto LAB_0015e911;
  }
  if (width == local_30) {
LAB_0015ea6c:
    GVar9 = 0x1908;
    if (height != local_2c) goto LAB_0015ea2e;
LAB_0015ea7a:
                    /* Unresolved local var: int iNum@[???] */
    if (mipmap == false) {
      (*qglTexImage2D)(0xde1,0,unaff_EDI,width,height,0,GVar9,0x1401,data);
      goto LAB_0015e9a2;
    }
    uVar6 = uVar4 * 4;
    if (iType == 2) {
      uVar6 = uVar4;
    }
    Q_memcpy(GL_Upload32::scaled,data,uVar6);
    texels = texels + local_2c * local_30;
    (*qglTexImage2D)(0xde1,0,unaff_EDI,local_30,local_2c,0,GVar9,0x1401,GL_Upload32::scaled);
  }
  else {
LAB_0015ea2e:
    if (iType == 2) {
      GVar9 = 0x1908;
LAB_0015e8c2:
      GL_ResampleAlphaTexture
                ((byte *)data,width,height,(byte *)GL_Upload32::scaled,local_30,local_2c);
    }
    else {
LAB_0015e911:
      GVar9 = 0x1908;
      GL_ResampleTexture(data,width,height,GL_Upload32::scaled,local_30,local_2c);
    }
    texels = texels + local_30 * local_2c;
    (*qglTexImage2D)(0xde1,0,unaff_EDI,local_30,local_2c,0,GVar9,0x1401,GL_Upload32::scaled);
    if (mipmap == false) {
LAB_0015e9a2:
      (*qglTexParameterf)(0xde1,0x2801,(float)filter);
      (*qglTexParameterf)(0xde1,0x2800,(float)filter);
      goto LAB_0015e9e5;
    }
  }
                    /* Unresolved local var: int miplevel@[???] */
  iVar11 = 0;
  while ((1 < local_30 || (1 < local_2c))) {
    GL_MipMap((byte *)GL_Upload32::scaled,local_30,local_2c);
    local_30 = local_30 >> 1;
    local_2c = local_2c >> 1;
    if (local_30 < 1) {
      local_30 = 1;
    }
    if (local_2c < 1) {
      local_2c = 1;
    }
    iVar11 = iVar11 + 1;
    texels = texels + local_30 * local_2c;
    (*qglTexImage2D)(0xde1,iVar11,unaff_EDI,local_30,local_2c,0,GVar9,0x1401,GL_Upload32::scaled);
  }
  (*qglTexParameterf)(0xde1,0x2801,(float)gl_filter_min);
  (*qglTexParameterf)(0xde1,0x2800,(float)gl_filter_max);
LAB_0015e9e5:
  (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
  return;
}


