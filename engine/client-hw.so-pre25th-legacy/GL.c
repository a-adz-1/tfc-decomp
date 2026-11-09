// GL_BeginRendering  @ 001d6b90
void GL_BeginRendering(int *x,int *y,int *width,int *height)

{
  int iVar1;
  qboolean local_24;
  
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
  vid.conwidth = vid.width;
  vid.conheight = vid.height;
  if (gl_vsync.value != (float)vsync) {
    SDL_GL_SetSwapInterval(0.0 < gl_vsync.value);
    local_24 = (qboolean)(longlong)ROUND(gl_vsync.value);
    vsync = local_24;
  }
  if (s_BackBufferFBO.s_hBackBufferFBO != 0) {
    if (s_MSAAFBO.s_hBackBufferFBO == 0) {
      (*qglBindFramebufferEXT)(0x8ca9,s_BackBufferFBO.s_hBackBufferFBO);
    }
    else {
      (*qglBindFramebufferEXT)(0x8ca9,s_MSAAFBO.s_hBackBufferFBO);
    }
    glClearColor(0,0,0,0x3f800000);
    if (gl_clear.value != 0.0) {
      glClear(0x4100);
      GLimp_LogNewFrame();
      return;
    }
    (*qglClear)(0x100);
  }
  GLimp_LogNewFrame();
  return;
}


// GL_Bind  @ 001b1090
void GL_Bind(int texnum)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: int paletteIndex@[???] */
  uVar2 = texnum & 0xffff;
  if (currenttexture != uVar2) {
    iVar1 = (texnum >> 0x10) + -1;
    currenttexture = uVar2;
    (*qglBindTexture)(0xde1,uVar2);
    if (((-1 < iVar1) && (iVar1 != g_currentpalette)) &&
       (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
      g_currentpalette = iVar1;
      (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(iVar1 * 0x308 + 0xe0c1a8));
    }
  }
  return;
}


// GL_BreakOnError  @ 001d13b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_BreakOnError(void)

{
  return;
}


// GL_BuildLightmaps  @ 001e4ea0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_BuildLightmaps(void)

{
  model_s *pmVar1;
  GLint GVar2;
  model_t *pmVar3;
  msurface_t *fa;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: model_t * m@[???] */
  Q_memset(allocated,0,0x8000);
  r_framecount = 1;
  if (lightmap_textures[0] == 0) {
    iVar4 = 0;
    do {
      GVar2 = GL_GenTexture();
      lightmap_textures[iVar4] = GVar2;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x40);
  }
  iVar4 = 1;
  gl_lightmap_format = 0x1908;
  lightmap_bytes = 4;
  lightmap_used = 0x1908;
  do {
    pmVar1 = cl.model_precache[iVar4];
    if (pmVar1 == (model_s *)0x0) break;
    if ((pmVar1->name[0] != '*') && (pmVar1->numsurfaces != 0)) {
      pmVar3 = CL_GetModelByIndex(iVar4);
      r_pcurrentvertbase = pmVar3->vertexes;
      currentmodel = pmVar3;
      if (0 < pmVar3->numsurfaces) {
        iVar6 = 0;
        iVar5 = 0;
        do {
          GL_CreateSurfaceLightmap
                    ((msurface_t *)((int)pmVar3->surfaces->texturemins + iVar6 + -0x14));
          fa = (msurface_t *)((int)pmVar3->surfaces->texturemins + iVar6 + -0x14);
          if ((fa->flags & 0x10) == 0) {
            BuildSurfaceDisplayList(fa);
          }
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0x5c;
        } while (iVar5 < pmVar3->numsurfaces);
      }
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x200);
  if (gl_texsort == false) {
    GL_SelectTexture(TEXTURE1_SGIS);
  }
  iVar4 = 0;
  do {
    if (allocated[iVar4][0] == 0) break;
    lightmap_modified[iVar4] = false;
    GL_Bind(lightmap_textures[iVar4]);
    (*qglTexParameterf)(0xde1,0x2801,9729.0);
    (*qglTexParameterf)(0xde1,0x2800,9729.0);
    (*qglPixelStorei)(0xcf5,4);
    iVar5 = iVar4 * 0x4000;
    iVar4 = iVar4 + 1;
    (*qglTexImage2D)(0xde1,0,lightmap_used,0x80,0x80,0,gl_lightmap_format,0x1401,
                     lightmaps + iVar5 * lightmap_bytes);
  } while (iVar4 != 0x40);
  if (gl_texsort == false) {
    GL_SelectTexture(TEXTURE0_SGIS);
  }
  return;
}


// GL_Config  @ 001d6360
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_Config(void)

{
  char *pcVar1;
  char *pcVar2;
  char local_10c [255];
  undefined1 local_d;
  
                    /* Unresolved local var: char[256] lowerCase@[???] */
  Cbuf_InsertText("exec hw/opengl.cfg\n");
  Q_strncpy(local_10c,gl_renderer,0xff);
  local_d = 0;
  pcVar1 = Q_strstr(gl_vendor,"3Dfx");
  if (pcVar1 != (char *)0x0) {
    gGLHardwareType = 1;
    pcVar1 = Q_strstr(gl_renderer,"Voodoo(tm)");
    if (pcVar1 != (char *)0x0) {
      Cbuf_InsertText("exec hw/3DfxVoodoo1.cfg\n");
      return;
    }
    pcVar1 = Q_strstr(gl_renderer,"Voodoo^2");
    if (pcVar1 == (char *)0x0) {
      Cbuf_InsertText("exec hw/3Dfx.cfg\n");
      return;
    }
    Cbuf_InsertText("exec hw/3DfxVoodoo2.cfg\n");
    return;
  }
  pcVar1 = Q_strstr(gl_vendor,"NVIDIA");
  if (pcVar1 == (char *)0x0) {
    pcVar1 = Q_strstr(local_10c,"riva tnt");
    if ((pcVar1 == (char *)0x0) &&
       (pcVar1 = Q_strstr(local_10c,"velocity 4400"), pcVar1 == (char *)0x0)) {
      pcVar1 = Q_strstr(gl_vendor,"PCX2");
      if (pcVar1 != (char *)0x0) {
        Cbuf_InsertText("exec hw/PowerVRPCX2.cfg\n");
        gGLHardwareType = 3;
        return;
      }
      pcVar1 = Q_strstr(gl_vendor,"PowerVR");
      if (pcVar1 != (char *)0x0) {
        Cbuf_InsertText("exec hw/PowerVRSG.cfg\n");
        gGLHardwareType = 4;
        return;
      }
      pcVar1 = Q_strstr(gl_vendor,"V2200");
      if (pcVar1 != (char *)0x0) {
        Cbuf_InsertText("exec hw/V2200.cfg\n");
        gGLHardwareType = 5;
        return;
      }
      pcVar1 = Q_strstr(gl_vendor,"3Dlabs");
      if (pcVar1 != (char *)0x0) {
        Cbuf_InsertText("exec hw/3Dlabs.cfg\n");
        gGLHardwareType = 6;
        return;
      }
      pcVar1 = Q_strstr(gl_vendor,"Matrox");
      if (pcVar1 != (char *)0x0) {
        gGLHardwareType = 0;
        Cbuf_InsertText("exec hw/matrox.cfg\n");
        return;
      }
      pcVar1 = Q_strstr(gl_vendor,"ATI");
      if ((pcVar1 != (char *)0x0) &&
         (((pcVar1 = Q_strstr(gl_renderer,"Rage"), pcVar1 != (char *)0x0 ||
           (pcVar1 = Q_strstr(gl_renderer,"RAGE"), pcVar1 != (char *)0x0)) &&
          (pcVar1 = Q_strstr(gl_renderer,"128"), pcVar1 != (char *)0x0)))) {
        gGLHardwareType = 0;
        Cbuf_InsertText("exec hw/ATIRage128.cfg\n");
        return;
      }
      gGLHardwareType = 0;
      pcVar1 = Q_strstr(gl_renderer,"Matrox");
      if ((pcVar1 != (char *)0x0) && (pcVar1 = Q_strstr(gl_renderer,"G200"), pcVar1 != (char *)0x0))
      {
        Cbuf_InsertText("exec hw/G200d3d.cfg\n");
        return;
      }
      pcVar1 = Q_strstr(gl_renderer,"ATI");
      if ((pcVar1 != (char *)0x0) &&
         (((pcVar1 = Q_strstr(gl_renderer,"Rage"), pcVar1 != (char *)0x0 ||
           (pcVar1 = Q_strstr(gl_renderer,"RAGE"), pcVar1 != (char *)0x0)) &&
          (pcVar1 = Q_strstr(gl_renderer,"128"), pcVar1 != (char *)0x0)))) {
        Cbuf_InsertText("exec hw/ATIRage128d3d.cfg\n");
        return;
      }
      pcVar1 = Q_strstr(gl_vendor,"NVIDIA");
      if (pcVar1 == (char *)0x0) {
        return;
      }
      Cbuf_InsertText("exec hw/nvidiad3d.cfg\n");
      return;
    }
  }
  else {
    pcVar1 = Q_strstr(gl_renderer,"RIVA 128");
    if (pcVar1 != (char *)0x0) {
      gGLHardwareType = 2;
      Cbuf_InsertText("exec hw/riva128.cfg\n");
      return;
    }
    pcVar2 = Q_strstr(gl_renderer,"TNT");
    pcVar1 = gl_renderer;
    if (pcVar2 == (char *)0x0) {
      pcVar2 = strstr(gl_renderer,"Quadro");
      if ((pcVar2 == (char *)0x0) && (pcVar1 = strstr(pcVar1,"GeForce"), pcVar1 == (char *)0x0)) {
        return;
      }
      gGLHardwareType = 0xb;
      Cbuf_InsertText("exec hw/geforce.cfg\n");
      return;
    }
  }
  gGLHardwareType = 10;
  Cbuf_InsertText("exec hw/rivaTNT.cfg\n");
  return;
}


// GL_CreateSurfaceLightmap  @ 001e4cf0
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
  int iVar10;
  int local_2c;
  
                    /* Unresolved local var: int smax@[???]
                       Unresolved local var: int tmax@[???]
                       Unresolved local var: uchar * base@[???] */
  if (((surf->flags & 0x14U) == 0) &&
     (((surf->flags & 0x20U) == 0 || ((surf->texinfo->flags & 1) == 0)))) {
    sVar2 = surf->extents[1];
    iVar3 = (int)surf->extents[0] >> 4;
    iVar1 = iVar3 + 1;
    iVar3 = 0x7f - iVar3;
    local_2c = 0;
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int best@[???]
                       Unresolved local var: int best2@[???]
                       Unresolved local var: int texnum@[???] */
      iVar10 = 0x80;
      if (0 < iVar3) {
        iVar9 = 0;
        iVar8 = local_2c << 9;
        do {
          if (iVar1 < 1) {
            iVar6 = 0;
            iVar5 = 0;
LAB_001e4da5:
            if (iVar1 == iVar5) {
              surf->light_s = iVar9;
              surf->light_t = iVar6;
              iVar10 = iVar6;
            }
          }
          else {
            iVar7 = *(int *)((int)allocated[0] + iVar8);
            if (iVar7 < iVar10) {
              iVar6 = 0;
              iVar4 = 0;
              do {
                if (iVar6 < iVar7) {
                  iVar6 = iVar7;
                }
                iVar5 = iVar4 + 1;
              } while ((iVar5 != iVar1) &&
                      (iVar7 = *(int *)((int)allocated[0] + iVar4 * 4 + 4 + iVar8), iVar4 = iVar5,
                      iVar7 < iVar10));
              goto LAB_001e4da5;
            }
          }
          iVar9 = iVar9 + 1;
          iVar8 = iVar8 + 4;
        } while (iVar9 != iVar3);
      }
      iVar10 = iVar10 + ((int)sVar2 >> 4) + 1;
      if (iVar10 < 0x81) {
        iVar3 = 0;
        if (0 < iVar1) {
          do {
            iVar8 = surf->light_s + iVar3;
            iVar3 = iVar3 + 1;
            allocated[local_2c][iVar8] = iVar10;
          } while (iVar3 < iVar1);
        }
        goto LAB_001e4df2;
      }
      local_2c = local_2c + 1;
    } while (local_2c != 0x40);
    Sys_Error("AllocBlock: full");
    local_2c = 0;
LAB_001e4df2:
    surf->lightmaptexturenum = local_2c;
    R_BuildLightMap(surf,lightmaps +
                         (surf->light_t * 0x80 + surf->light_s) * lightmap_bytes +
                         local_2c * lightmap_bytes * 0x4000,lightmap_bytes << 7);
  }
  return;
}


// GL_DisableMultitexture  @ 001e3560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_DisableMultitexture(void)

{
  if (mtexenabled != false) {
    (*qglDisable)(0xde1);
    GL_SelectTexture(TEXTURE0_SGIS);
    mtexenabled = false;
  }
  return;
}


// GL_DrawAliasFrame  @ 001d31f0
void GL_DrawAliasFrame(aliashdr_t *paliashdr,int posenum)

{
  float fVar1;
  byte *pbVar2;
  GLfloat GVar3;
  GLfloat *pGVar4;
  GLfloat GVar5;
  GLfloat *local_28;
  byte *local_24;
  
                    /* Unresolved local var: float l@[???]
                       Unresolved local var: trivertx_t * verts@[???]
                       Unresolved local var: int * order@[???]
                       Unresolved local var: int count@[???] */
  lastposenum = posenum;
  local_28 = (GLfloat *)((int)paliashdr->scale + paliashdr->commands + -8);
  GVar5 = *local_28;
  if (GVar5 != 0.0) {
    local_24 = (byte *)((int)paliashdr->scale +
                       posenum * paliashdr->poseverts * 4 + paliashdr->posedata + -8);
    do {
      local_28 = local_28 + 1;
      pbVar2 = local_24;
      pGVar4 = local_28;
      if ((int)GVar5 < 0) {
        GVar5 = (GLfloat)-(int)GVar5;
        (*qglBegin)(6);
        GVar3 = GVar5;
      }
      else {
        (*qglBegin)(5);
        GVar3 = GVar5;
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
      local_28 = local_28 + (int)GVar3 * 2;
      local_24 = local_24 + (int)GVar3 * 4;
      (*qglEnd)();
      GVar5 = *local_28;
    } while (GVar5 != 0.0);
  }
  return;
}


// GL_DrawAliasShadow  @ 001d3320
void GL_DrawAliasShadow(aliashdr_t *paliashdr,int posenum)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  byte *pbVar4;
  int iVar5;
  int local_3c;
  byte *local_38;
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
  piVar3 = (int *)((int)paliashdr->scale + paliashdr->commands + -8);
  local_3c = *piVar3;
  if (local_3c != 0) {
    local_38 = (byte *)((int)paliashdr->scale +
                       paliashdr->poseverts * posenum * 4 + paliashdr->posedata + -8);
    do {
      pbVar4 = local_38;
      if (local_3c < 0) {
        iVar5 = -local_3c;
        (*qglBegin)(6);
        local_3c = iVar5;
      }
      else {
        (*qglBegin)(5);
        iVar5 = local_3c;
      }
      do {
        fVar2 = (float)pbVar4[2] * paliashdr->scale[2] + paliashdr->scale_origin[2] + fVar1;
        local_28 = ((float)*pbVar4 * paliashdr->scale[0] + paliashdr->scale_origin[0]) -
                   shadevector[0] * fVar2;
        local_24 = ((float)pbVar4[1] * paliashdr->scale[1] + paliashdr->scale_origin[1]) -
                   fVar2 * shadevector[1];
        local_20 = 1.0 - fVar1;
        (*qglVertex3fv)(&local_28);
        iVar5 = iVar5 + -1;
        pbVar4 = pbVar4 + 4;
      } while (iVar5 != 0);
      piVar3 = piVar3 + local_3c * 2 + 1;
      local_38 = local_38 + local_3c * 4;
      (*qglEnd)();
      local_3c = *piVar3;
    } while (local_3c != 0);
  }
  return;
}


// GL_Dump_f  @ 00209ab0
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


// GL_EnableMultitexture  @ 001e35a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_EnableMultitexture(void)

{
  if (gl_mtexable != 0) {
    GL_SelectTexture(TEXTURE1_SGIS);
    (*qglEnable)(0xde1);
    mtexenabled = true;
  }
  return;
}


// GL_EndRendering  @ 001d6d40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_EndRendering(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_24;
  int local_20 [4];
  
  if (s_BackBufferFBO.s_hBackBufferFBO == 0) goto LAB_001d6d6b;
                    /* Unresolved local var: int srcWide@[???]
                       Unresolved local var: int srcTall@[???]
                       Unresolved local var: int dstX1@[???]
                       Unresolved local var: int dstX2@[???]
                       Unresolved local var: int dstY1@[???]
                       Unresolved local var: int dstY2@[???]
                       Unresolved local var: float fSrcAspect@[???]
                       Unresolved local var: float fDstAspect@[???] */
  VideoMode_GetCurrentVideoMode(&local_24,local_20,(int *)0x0);
  if (s_MSAAFBO.s_hBackBufferFBO != 0) {
    (*qglBindFramebufferEXT)(0x8ca9,s_BackBufferFBO.s_hBackBufferFBO);
    (*qglBindFramebufferEXT)(0x8ca8,s_MSAAFBO.s_hBackBufferFBO);
    (*qglBlitFramebufferEXT)(0,0,local_24,local_20[0],0,0,local_24,local_20[0],0x4000,0x2601);
  }
  (*qglBindFramebufferEXT)(0x8ca9,0);
  (*qglBindFramebufferEXT)(0x8ca8,s_BackBufferFBO.s_hBackBufferFBO);
  glClearColor(0,0,0);
  glClear(0x4100);
  iVar8 = window_rect.right - window_rect.left;
  iVar9 = window_rect.bottom - window_rect.top;
  s_fYMouseAspectAdjustment = 1.0;
  s_fXMouseAspectAdjustment = 1.0;
  iVar5 = iVar8;
  iVar4 = iVar9;
  if (s_bEnforceAspect == 0) {
LAB_001d6f1a:
    iVar6 = 0;
    iVar7 = 0;
  }
  else {
    fVar3 = (float)local_24 / (float)local_20[0];
    fVar2 = (float)iVar9;
    fVar1 = (float)iVar8 / fVar2;
    if (fVar1 <= fVar3) {
      if (fVar3 <= fVar1) goto LAB_001d6f1a;
                    /* Unresolved local var: float fDesiredHeight@[???]
                       Unresolved local var: float fDiff@[???] */
      s_fYMouseAspectAdjustment = fVar3 / fVar1;
      iVar7 = 0;
      fVar1 = (fVar2 - (float)iVar8 * (1.0 / fVar3)) * 0.5;
      iVar6 = (int)(fVar1 + 0.0);
      iVar4 = (int)((float)iVar9 - fVar1);
    }
    else {
                    /* Unresolved local var: float fDesiredWidth@[???]
                       Unresolved local var: float fDiff@[???] */
      iVar6 = 0;
      fVar2 = ((float)iVar8 - fVar2 * fVar3) * 0.5;
      iVar7 = (int)(fVar2 + 0.0);
      s_fXMouseAspectAdjustment = fVar1 / fVar3;
      iVar5 = (int)((float)iVar8 - fVar2);
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
    glOrtho(0,0,(double)iVar8,(double)iVar9,0,0,0,0xbff00000,0,0x3ff00000);
    (*qglMatrixMode)(0x1700);
    (*qglPushMatrix)();
    glLoadIdentity();
    (*qglViewport)(0,0,iVar8,iVar9);
    glTexParameteri(0x84f5,0x2800,0x2601);
    glTexParameteri(0x84f5,0x2801,0x2601);
    glTexParameteri(0x84f5,0x2802,0x812f);
    glTexParameteri(0x84f5,0x2803,0x812f);
    (*qglColor4f)(1.0,1.0,1.0,1.0);
    glEnable(0x84f5);
    glBindTexture(0x84f5,s_BackBufferFBO.s_hBackBufferTex);
    glBegin(7);
    glTexCoord2f(0,(float)local_20[0]);
    glVertex3f((float)iVar7,(float)iVar6,0);
    glTexCoord2f((float)local_24,(float)local_20[0]);
    glVertex3f((float)iVar5,(float)iVar6,0);
    glTexCoord2f((float)local_24,0);
    glVertex3f((float)iVar5,(float)iVar4,0);
    glTexCoord2f(0,0);
    glVertex3f((float)iVar7,(float)iVar4,0);
    glEnd();
    glBindTexture(0x84f5,0);
    (*qglMatrixMode)(0x1701);
    (*qglPopMatrix)();
    (*qglMatrixMode)(0x1700);
    (*qglPopMatrix)();
    glDisable(0x84f5);
  }
  else {
    (*qglBlitFramebufferEXT)(0,0,local_24,local_20[0],iVar7,iVar6,iVar5,iVar4,0x4000,0x2601);
  }
  (*qglBindFramebufferEXT)(0x8ca8,0);
LAB_001d6d6b:
  (*VID_FlipScreen)();
  return;
}


// GL_FindTexture  @ 001b32a0
int GL_FindTexture(char *identifier)

{
  int iVar1;
  int iVar2;
  gltexture_t *pgVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: gltexture_t * glt@[???] */
  iVar1 = -1;
  if (0 < numgltextures) {
    pgVar3 = gltextures;
    iVar1 = 0;
    while( true ) {
      iVar2 = Q_strcmp(identifier,pgVar3->identifier);
      if (iVar2 == 0) break;
      iVar1 = iVar1 + 1;
      pgVar3 = pgVar3 + 1;
      if (numgltextures <= iVar1) {
        return -1;
      }
    }
    iVar1 = gltextures[iVar1].texnum;
  }
  return iVar1;
}


// GL_FreeGLTex  @ 001b8080
void GL_FreeGLTex(gltexture_t *glt)

{
  uint uVar1;
  
                    /* Unresolved local var: int texnum@[???] */
  (*qglDeleteTextures)(1,(GLuint *)glt);
  uVar1 = (uint)glt->paletteIndex;
  if (-1 < (int)uVar1) {
    if (gGLPalette[uVar1].referenceCount < 2) {
      if (uVar1 < 0x15e) {
        gGLPalette[uVar1].tag = -1;
        gGLPalette[uVar1].referenceCount = 0;
      }
    }
    else {
      gGLPalette[uVar1].referenceCount = gGLPalette[uVar1].referenceCount + -1;
    }
  }
  Q_memset(glt,0,0x54);
  glt->servercount = -1;
  return;
}


// GL_GenTexture  @ 001b8610
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

GLint GL_GenTexture(void)

{
  GLuint local_10 [4];
  
                    /* Unresolved local var: GLuint tex@[???] */
  (*qglGenTextures)(1,local_10);
  return local_10[0];
}


// GL_Init  @ 001d67c0
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
  Sys_Error("Failed to query gl vendor string");
  return;
}


// GL_LoadFilterTexture  @ 001b9420
void GL_LoadFilterTexture(float r,float g,float b,float brightness)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  uint local_20 [4];
  
                    /* Unresolved local var: uchar * data@[???]
                       Unresolved local var: int pixelIndex@[???] */
  iVar7 = gl_FilterTexture;
  if (gl_FilterTexture == 0) {
                    /* Unresolved local var: GLuint tex@[???] */
    (*qglGenTextures)(1,local_20);
    gl_FilterTexture = local_20[0];
    puVar1 = malloc(0xc0);
    uVar5 = (int)(r * brightness * 255.0) & 0xff;
    uVar8 = (int)(g * brightness * 255.0) & 0xff;
    uVar3 = (uint)(brightness * b * 255.0);
    uVar4 = uVar3 & 0xff;
    uVar3 = (((uVar3 & 0xff) << 8 | uVar8) << 8 | uVar5) << 8 | uVar4;
                    /* Unresolved local var: int paletteIndex@[???] */
    uVar2 = local_20[0] & 0xffff;
    uVar6 = ((uVar5 << 8 | uVar4) << 8 | uVar8) << 8 | uVar5;
    uVar8 = ((uVar8 << 8 | uVar5) << 8 | uVar4) << 8 | uVar8;
    uVar10 = CONCAT44(uVar6,uVar3);
    bVar9 = uVar2 != currenttexture;
    uVar12 = CONCAT44(uVar3,uVar8);
    puVar1[4] = uVar10;
    puVar1[5] = uVar12;
    uVar11 = CONCAT44(uVar8,uVar6);
    puVar1[10] = uVar10;
    puVar1[0xb] = uVar12;
    puVar1[2] = uVar12;
    puVar1[3] = uVar11;
    puVar1[8] = uVar12;
    puVar1[9] = uVar11;
    *puVar1 = uVar11;
    puVar1[1] = uVar10;
    puVar1[6] = uVar11;
    puVar1[7] = uVar10;
    puVar1[0xc] = uVar11;
    puVar1[0xd] = uVar10;
    puVar1[0xe] = uVar12;
    puVar1[0xf] = uVar11;
    puVar1[0x10] = uVar10;
    puVar1[0x11] = uVar12;
    puVar1[0x12] = uVar11;
    puVar1[0x13] = uVar10;
    puVar1[0x14] = uVar12;
    puVar1[0x15] = uVar11;
    puVar1[0x16] = uVar10;
    puVar1[0x17] = uVar12;
    if (bVar9) {
      iVar7 = ((int)local_20[0] >> 0x10) + -1;
      currenttexture = uVar2;
      (*qglBindTexture)(0xde1,uVar2);
      if (((-1 < iVar7) && (iVar7 != g_currentpalette)) &&
         (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
        g_currentpalette = iVar7;
        (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(iVar7 * 0x308 + 0xe0c1a8));
      }
    }
    (*qglTexImage2D)(0xde1,0,0x1907,8,8,0,0x1907,0x1401,puVar1);
    (*qglTexParameteri)(0xde1,0x2802,0x2901);
    (*qglTexParameteri)(0xde1,0x2803,0x2901);
    (*qglTexParameteri)(0xde1,0x2800,0x2601);
    (*qglTexParameteri)(0xde1,0x2801,0x2601);
    (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
    free(puVar1);
    return;
  }
  puVar1 = malloc(0xc0);
  uVar2 = (int)(g * brightness * 255.0) & 0xff;
  uVar3 = (uint)(brightness * b * 255.0);
  uVar8 = uVar3 & 0xff;
  uVar5 = (int)(r * brightness * 255.0) & 0xff;
  uVar4 = ((uVar5 << 8 | uVar8) << 8 | uVar2) << 8 | uVar5;
  uVar3 = (((uVar3 & 0xff) << 8 | uVar2) << 8 | uVar5) << 8 | uVar8;
  uVar2 = ((uVar2 << 8 | uVar5) << 8 | uVar8) << 8 | uVar2;
  uVar11 = CONCAT44(uVar4,uVar3);
                    /* Unresolved local var: int paletteIndex@[???] */
  uVar8 = iVar7 & 0xffff;
  uVar10 = CONCAT44(uVar3,uVar2);
  bVar9 = uVar8 != currenttexture;
  uVar12 = CONCAT44(uVar2,uVar4);
  puVar1[2] = uVar10;
  puVar1[3] = uVar12;
  puVar1[4] = uVar11;
  puVar1[5] = uVar10;
  *puVar1 = uVar12;
  puVar1[1] = uVar11;
  puVar1[6] = uVar12;
  puVar1[7] = uVar11;
  puVar1[8] = uVar10;
  puVar1[9] = uVar12;
  puVar1[10] = uVar11;
  puVar1[0xb] = uVar10;
  puVar1[0xc] = uVar12;
  puVar1[0xd] = uVar11;
  puVar1[0xe] = uVar10;
  puVar1[0xf] = uVar12;
  puVar1[0x10] = uVar11;
  puVar1[0x11] = uVar10;
  puVar1[0x12] = uVar12;
  puVar1[0x13] = uVar11;
  puVar1[0x14] = uVar10;
  puVar1[0x15] = uVar12;
  puVar1[0x16] = uVar11;
  puVar1[0x17] = uVar10;
  if (bVar9) {
    iVar7 = (iVar7 >> 0x10) + -1;
    currenttexture = uVar8;
    (*qglBindTexture)(0xde1,uVar8);
    if (((-1 < iVar7) && (iVar7 != g_currentpalette)) &&
       (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
      g_currentpalette = iVar7;
      (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(iVar7 * 0x308 + 0xe0c1a8));
    }
  }
  (*qglTexSubImage2D)(0xde1,0,0,0,8,8,0x1907,0x1401,puVar1);
  free(puVar1);
  return;
}


// GL_LoadPicTexture  @ 001b9100
int GL_LoadPicTexture(qpic_t *pic,char *pszName)

{
  int iVar1;
  
                    /* Unresolved local var: uchar * pPal@[???] */
  iVar1 = GL_LoadTexture2(pszName,GLT_SYSTEM,pic->width,pic->height,pic->data,false,1,
                          pic->data + pic->width * pic->height + 2,gl_filter_max);
  return iVar1;
}


// GL_LoadTexture  @ 001b90a0
int GL_LoadTexture(char *identifier,GL_TEXTURETYPE textureType,int width,int height,uchar *data,
                  int mipmap,int iType,uchar *pPal)

{
  int iVar1;
  
  iVar1 = GL_LoadTexture2(identifier,textureType,width,height,data,mipmap,iType,pPal,gl_filter_max);
  return iVar1;
}


// GL_LoadTexture2  @ 001b8630
int GL_LoadTexture2(char *identifier,GL_TEXTURETYPE textureType,int width,int height,uchar *data,
                   qboolean mipmap,int iType,uchar *pPal,int filter)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uchar *puVar11;
  gltexture_t *pgVar12;
  int iVar13;
  int iVar14;
  uchar *puVar15;
  bool bVar16;
  gltexture_t *local_435c;
  uchar *local_4358;
  uint local_4354;
  uchar local_433c [16384];
  byte local_33c [768];
  int local_3c [4];
  int local_2c [3];
  GLuint local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: gltexture_t * glt@[???]
                       Unresolved local var: gltexture_t * slot@[???]
                       Unresolved local var: BOOL mustRescale@[???] */
  local_435c = (gltexture_t *)0x0;
  cVar2 = *identifier;
  while (cVar2 != '\0') {
    if (numgltextures < 1) goto LAB_001b8697;
    pgVar12 = gltextures;
    iVar14 = 0;
    iVar10 = numgltextures;
    while( true ) {
      while ((short)(pgVar12->servercount & -0x8000) != 0) {
        if (local_435c == (gltexture_t *)0x0) {
          local_435c = pgVar12;
        }
        iVar14 = iVar14 + 1;
        pgVar12 = pgVar12 + 1;
        if (iVar10 <= iVar14) goto LAB_001b8697;
      }
      iVar10 = Q_strcmp(identifier,pgVar12->identifier);
      if (iVar10 == 0) break;
      iVar14 = iVar14 + 1;
      pgVar12 = pgVar12 + 1;
      iVar10 = numgltextures;
      if (numgltextures <= iVar14) goto LAB_001b8697;
    }
    if ((pgVar12->width == width) && (pgVar12->height == height)) {
      if (0 < pgVar12->servercount) {
        pgVar12->servercount = (short)gHostSpawnCount;
      }
      if (-1 < pgVar12->paletteIndex) {
        return (pgVar12->paletteIndex + 1) * 0x10000 | pgVar12->texnum;
      }
      return pgVar12->texnum;
    }
    identifier[3] = identifier[3] + '\x01';
    cVar2 = *identifier;
  }
  Con_DPrintf("NULL Texture\n");
LAB_001b8697:
  if (local_435c == (gltexture_t *)0x0) {
    iVar10 = numgltextures + 1;
    local_435c = gltextures + numgltextures;
    numgltextures = iVar10;
    if (0x12bf < iVar10) {
      Sys_Error("Texture Overflow: MAX_GLTEXTURES");
    }
  }
  if (local_435c->texnum == 0) {
                    /* Unresolved local var: GLuint tex@[???] */
    (*qglGenTextures)(1,local_20);
    local_435c->texnum = local_20[0];
  }
  Q_strncpy(local_435c->identifier,identifier,0x3f);
  local_435c->identifier[0x3f] = '\0';
  local_435c->width = width;
  local_435c->height = height;
  local_435c->mipmap = mipmap;
  if (textureType == GLT_WORLD) {
    local_435c->servercount = (short)gHostSpawnCount;
  }
  else {
    local_435c->servercount = 0;
  }
  local_435c->paletteIndex = -1;
                    /* Unresolved local var: int paletteIndex@[???] */
  uVar5 = local_435c->texnum & 0xffff;
  if (uVar5 != currenttexture) {
    iVar10 = (local_435c->texnum >> 0x10) + -1;
    currenttexture = uVar5;
    (*qglBindTexture)(0xde1,uVar5);
    if (((-1 < iVar10) && (iVar10 != g_currentpalette)) &&
       (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
      g_currentpalette = iVar10;
      (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(iVar10 * 0x308 + 0xe0c1a8));
    }
  }
                    /* Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: int max_size@[???] */
  currenttexture = -1;
  if (g_bSupportsNPOTTextures == false) {
    ComputeScaledSize(local_3c,local_2c,width,height);
    if (width == local_3c[0]) goto LAB_001b87cb;
    bVar16 = true;
    iVar10 = local_3c[0];
  }
  else {
    local_3c[0] = width;
    local_2c[0] = height;
LAB_001b87cb:
    bVar16 = height != local_2c[0];
    iVar10 = width;
  }
  if (mipmap == false) {
    local_4358 = data;
    if (bVar16) {
      if ((0x80 < iVar10) || (0x80 < local_2c[0])) goto LAB_001b8910;
                    /* Unresolved local var: uchar * pTexture@[???]
                       Unresolved local var: uchar[16384] scaled@[???] */
      if (fs_perf_warnings.value != 0.0) {
        Con_DPrintf("fs_perf_warnings: resampling non-power-of-2 texture %s (%dx%d)\n",identifier,
                    width,height);
        iVar10 = local_3c[0];
      }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uint ufrac@[???]
                       Unresolved local var: uint vfrac@[???]
                       Unresolved local var: uint ufracstep@[???]
                       Unresolved local var: uint vfracstep@[???]
                       Unresolved local var: uchar * src@[???]
                       Unresolved local var: uchar * dest@[???] */
      local_4358 = local_433c;
      if (0 < local_2c[0]) {
        puVar11 = local_433c;
        uVar5 = (width << 0x10) / iVar10;
        uVar6 = (height << 0x10) / local_2c[0];
        local_4354 = uVar6 >> 2;
        local_4358 = (uchar *)0x0;
        puVar15 = data;
        do {
          if (0 < iVar10) {
            iVar14 = 0;
            uVar9 = uVar5 >> 2;
            do {
              puVar11[iVar14] = puVar15[uVar9 >> 0x10];
              iVar14 = iVar14 + 1;
              uVar9 = uVar9 + uVar5;
            } while (iVar14 != iVar10);
            puVar11 = puVar11 + iVar10;
          }
          local_4358 = (uchar *)((int)local_4358 + 1);
          uVar9 = local_4354 + uVar6;
          local_4354 = uVar9 & 0xffff;
          puVar15 = puVar15 + (uVar9 >> 0x10) * width;
        } while (local_4358 != (uchar *)local_2c[0]);
        local_4358 = local_433c;
      }
    }
    if (((qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0) && (iType == 0)) &&
       (gl_palette_tex.value != 0.0)) {
      iVar10 = 0;
      do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int tag@[???]
                       Unresolved local var: int limit@[???]
                       Unresolved local var: uchar[768] gammaPal@[???] */
        local_33c[iVar10] = texgammatable[pPal[iVar10]];
        iVar10 = iVar10 + 1;
      } while (iVar10 != 0x300);
                    /* Unresolved local var: int tag@[???]
                       Unresolved local var: int i@[???] */
      uVar5 = (uint)local_33c[0];
      iVar10 = 1;
      do {
        pbVar7 = local_33c + iVar10;
        uVar6 = (uint)local_33c[0];
        local_33c[0] = local_33c[iVar10 + 1];
        iVar10 = iVar10 + 2;
        uVar5 = (uVar5 + *pbVar7 ^ uVar6) + (uint)local_33c[0] ^ (uint)*pbVar7;
      } while (iVar10 != 0x2ff);
      pbVar7 = local_33c + 0x2ff;
      iVar10 = 1;
      do {
        bVar3 = *pbVar7;
        pbVar1 = pbVar7 + -1;
        pbVar7 = pbVar7 + 1;
        uVar5 = uVar5 + bVar3 ^ (uint)*pbVar1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      iVar14 = 0;
      iVar10 = (uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f);
      iVar13 = 0;
      do {
        if (*(int *)(gGLPalette[0].colors + iVar14 + -8) < 0) {
          Q_memcpy(gGLPalette[iVar13].colors,local_33c,0x300);
          gGLPalette[iVar13].referenceCount = 1;
          gGLPalette[iVar13].tag = iVar10;
LAB_001b8cd4:
          local_435c->paletteIndex = (short)iVar13;
          (*qglTexImage2D)(0xde1,0,0x80e5,local_3c[0],local_2c[0],0,0x1900,0x1401,local_4358);
          (*qglTexParameterf)(0xde1,0x2801,(float)filter);
          (*qglTexParameterf)(0xde1,0x2800,(float)filter);
          (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
          if (-1 < local_435c->paletteIndex) {
            return (local_435c->paletteIndex + 1) * 0x10000 | local_435c->texnum;
          }
          return local_435c->texnum;
        }
                    /* Unresolved local var: int i@[???] */
        if (iVar10 == *(int *)(gGLPalette[0].colors + iVar14 + -8)) {
          iVar8 = 0;
          while (local_33c[iVar8] == *(byte *)(iVar14 + 0xe0c1a8 + iVar8)) {
            iVar8 = iVar8 + 1;
            if (iVar8 == 0x300) {
              gGLPalette[iVar13].referenceCount = gGLPalette[iVar13].referenceCount + 1;
              goto LAB_001b8cd4;
            }
          }
        }
        iVar13 = iVar13 + 1;
        iVar14 = iVar14 + 0x308;
      } while (iVar13 != 0x158);
      local_435c->paletteIndex = -1;
    }
  }
LAB_001b8910:
  if (g_modfuncs.m_pfnTextureLoad != (PFN_TEXTURELOAD)0x0) {
    (*g_modfuncs.m_pfnTextureLoad)(identifier,width,height,(char *)data);
  }
  if ((iType == 4) && (textureType == GLT_SPRITE)) {
    GL_Upload32((uint *)data,width,height,mipmap,4,filter);
    sVar4 = local_435c->paletteIndex;
  }
  else {
    GL_Upload16(data,width,height,mipmap,iType,pPal,filter);
    sVar4 = local_435c->paletteIndex;
  }
  if (-1 < sVar4) {
    return (sVar4 + 1) * 0x10000 | local_435c->texnum;
  }
  return local_435c->texnum;
}


// GL_MakeAliasModelDisplayLists  @ 001d8cb0
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
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  char local_150 [260];
  uint local_4c [15];
  undefined1 uStack_d;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int * cmds@[???]
                       Unresolved local var: trivertx_t * verts@[???]
                       Unresolved local var: char[64] cache@[???]
                       Unresolved local var: char[260] fullpath@[???]
                       Unresolved local var: FileHandle_t f@[???] */
  paliashdr = hdr;
  aliasmodel = m;
  Q_strcpy((char *)local_4c,"glquake/");
  iVar3 = Q_strlen("glquake/");
  iVar4 = Q_strlen("progs/");
  COM_StripExtension(m->name + iVar4,(char *)(iVar3 + (int)local_4c));
  puVar10 = local_4c;
  do {
    puVar9 = puVar10;
    uVar5 = *puVar9 + 0xfefefeff & ~*puVar9;
    uVar6 = uVar5 & 0x80808080;
    puVar10 = puVar9 + 1;
  } while (uVar6 == 0);
  if ((uVar5 & 0x8080) == 0) {
    puVar10 = (uint *)((int)puVar9 + 6);
    uVar6 = uVar6 >> 0x10;
  }
  strncat((char *)local_4c,".ms2",
          (size_t)(&uStack_d + -(int)((int)puVar10 + (-3 - (uint)CARRY1((byte)uVar6,(byte)uVar6)))))
  ;
  pvVar7 = FS_Open((char *)local_4c,"rb");
  if (pvVar7 == (FileHandle_t)0x0) {
    Con_Printf("meshing %s...\n",m);
    BuildTris();
    snprintf(local_150,0x104,"%s",local_4c);
    pvVar7 = FS_Open(local_150,"wb");
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
      Sys_Error("GL_MakeAliasModelDisplayLists: num commands (%d) too large",numcommands);
    }
    FS_Read(&numorder,4,1,pvVar7);
    if (0x8000 < (uint)(numorder * 4)) {
      Sys_Error("GL_MakeAliasModelDisplayLists: num orders (%d) too large",numorder);
    }
    FS_Read(commands,numcommands << 2,1,pvVar7);
    FS_Read(vertexorder,numorder << 2,1,pvVar7);
    FS_Close(pvVar7);
  }
  paliashdr->poseverts = numorder;
  dest = Hunk_Alloc(numcommands << 2);
  paliashdr->commands = (int)dest - (int)paliashdr;
  Q_memcpy(dest,commands,numcommands << 2);
  ptVar8 = Hunk_Alloc(paliashdr->numposes * paliashdr->poseverts * 4);
  paVar2 = paliashdr;
  paliashdr->posedata = (int)ptVar8 - (int)paliashdr;
  iVar3 = paVar2->numposes;
  if (0 < iVar3) {
    iVar11 = 0;
    iVar4 = numorder;
    do {
      if (0 < iVar4) {
        iVar3 = 0;
        do {
          piVar1 = vertexorder + iVar3;
          iVar3 = iVar3 + 1;
          *ptVar8 = poseverts[iVar11][*piVar1];
          ptVar8 = ptVar8 + 1;
        } while (iVar3 < numorder);
        iVar3 = paliashdr->numposes;
        iVar4 = numorder;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < iVar3);
  }
  return;
}


// GL_MipMap  @ 001b3830
void GL_MipMap(uchar *in,int width,int height)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined1 auVar8 [15];
  undefined1 auVar9 [15];
  undefined1 auVar10 [15];
  undefined1 auVar11 [14];
  undefined1 auVar12 [14];
  undefined1 auVar13 [14];
  undefined1 auVar14 [15];
  undefined1 auVar15 [14];
  undefined1 auVar16 [15];
  undefined1 auVar17 [15];
  undefined1 auVar18 [15];
  undefined1 auVar19 [14];
  undefined1 auVar20 [14];
  undefined1 auVar21 [14];
  undefined1 auVar22 [15];
  undefined1 auVar23 [14];
  undefined1 auVar24 [15];
  undefined1 auVar25 [15];
  undefined1 auVar26 [15];
  undefined1 auVar27 [14];
  undefined1 auVar28 [14];
  undefined1 auVar29 [14];
  undefined1 auVar30 [15];
  undefined1 auVar31 [14];
  undefined1 auVar32 [15];
  undefined1 auVar33 [15];
  undefined1 auVar34 [15];
  undefined1 auVar35 [14];
  undefined1 auVar36 [14];
  undefined1 auVar37 [14];
  undefined1 auVar38 [15];
  undefined1 auVar39 [14];
  undefined1 auVar40 [15];
  undefined1 auVar41 [15];
  undefined1 auVar42 [15];
  undefined1 auVar43 [15];
  undefined1 auVar44 [15];
  undefined1 auVar45 [15];
  undefined1 auVar46 [15];
  undefined1 auVar47 [15];
  undefined1 auVar48 [15];
  undefined1 auVar49 [15];
  undefined1 auVar50 [15];
  undefined1 auVar51 [15];
  undefined1 auVar52 [15];
  undefined1 auVar53 [15];
  undefined1 auVar54 [15];
  undefined1 auVar55 [15];
  undefined1 auVar56 [15];
  undefined1 auVar57 [15];
  undefined1 auVar58 [15];
  undefined1 auVar59 [15];
  undefined1 auVar60 [15];
  undefined1 auVar61 [15];
  undefined1 auVar62 [15];
  undefined1 auVar63 [15];
  undefined1 auVar64 [15];
  undefined1 auVar65 [15];
  undefined1 auVar66 [15];
  uint uVar67;
  uint uVar68;
  undefined1 auVar69 [15];
  uint uVar70;
  undefined1 auVar71 [15];
  undefined1 auVar72 [14];
  undefined1 auVar73 [14];
  undefined1 auVar74 [14];
  uint uVar75;
  undefined1 auVar76 [15];
  undefined1 auVar77 [14];
  undefined1 auVar78 [14];
  undefined1 auVar79 [14];
  undefined1 auVar80 [14];
  undefined1 auVar81 [14];
  uint uVar82;
  undefined1 auVar83 [15];
  uint uVar84;
  uint uVar85;
  undefined1 auVar86 [15];
  undefined1 auVar87 [14];
  undefined1 auVar88 [14];
  undefined1 auVar89 [14];
  uint uVar90;
  undefined1 auVar91 [15];
  undefined1 auVar92 [14];
  undefined1 auVar93 [14];
  undefined1 auVar94 [14];
  undefined1 auVar95 [14];
  undefined1 auVar96 [13];
  undefined1 auVar97 [13];
  undefined1 auVar98 [13];
  uint uVar99;
  uint uVar100;
  undefined1 auVar101 [15];
  uint uVar102;
  undefined1 auVar103 [15];
  undefined1 auVar104 [14];
  undefined1 auVar105 [14];
  undefined1 auVar106 [14];
  uint uVar107;
  undefined1 auVar108 [15];
  undefined1 auVar109 [14];
  undefined1 auVar110 [14];
  undefined1 auVar111 [14];
  undefined1 auVar112 [14];
  undefined1 auVar113 [13];
  undefined1 auVar114 [13];
  undefined1 auVar115 [13];
  uint uVar116;
  uint uVar117;
  uint uVar118;
  undefined1 auVar119 [15];
  undefined1 auVar120 [14];
  undefined1 auVar121 [14];
  undefined1 auVar122 [14];
  uint uVar123;
  undefined1 auVar124 [15];
  undefined1 auVar125 [14];
  undefined1 auVar126 [14];
  undefined1 auVar127 [14];
  undefined1 auVar128 [14];
  undefined1 auVar129 [14];
  undefined1 auVar130 [15];
  undefined1 auVar131 [15];
  undefined1 auVar132 [15];
  undefined1 auVar133 [15];
  undefined1 auVar134 [15];
  undefined1 auVar135 [15];
  undefined1 auVar136 [15];
  undefined1 auVar137 [15];
  undefined1 auVar138 [15];
  undefined1 auVar139 [15];
  undefined1 auVar140 [15];
  undefined1 auVar141 [15];
  undefined1 auVar142 [15];
  undefined1 auVar143 [15];
  undefined1 auVar144 [15];
  undefined1 auVar145 [15];
  undefined1 auVar146 [15];
  undefined1 auVar147 [15];
  undefined1 auVar148 [15];
  undefined1 auVar149 [15];
  undefined1 auVar150 [15];
  undefined1 auVar151 [15];
  undefined1 auVar152 [15];
  undefined1 auVar153 [15];
  undefined1 auVar154 [15];
  undefined1 auVar155 [15];
  undefined1 auVar156 [15];
  undefined1 auVar157 [15];
  undefined1 auVar158 [15];
  undefined1 auVar159 [15];
  undefined1 auVar160 [15];
  undefined1 auVar161 [15];
  undefined1 auVar162 [15];
  undefined1 auVar163 [15];
  undefined1 auVar164 [15];
  undefined1 auVar165 [15];
  undefined1 auVar166 [15];
  undefined1 auVar167 [15];
  undefined1 auVar168 [15];
  undefined1 auVar169 [15];
  undefined1 auVar170 [15];
  undefined1 auVar171 [15];
  undefined1 auVar172 [15];
  byte bVar173;
  byte bVar174;
  byte bVar175;
  byte bVar176;
  byte bVar177;
  byte bVar178;
  byte bVar179;
  byte bVar180;
  byte bVar181;
  byte bVar182;
  byte bVar183;
  byte bVar184;
  byte bVar185;
  byte bVar186;
  byte bVar187;
  byte bVar188;
  byte bVar189;
  byte bVar190;
  byte bVar191;
  byte bVar192;
  byte bVar193;
  byte bVar194;
  byte bVar195;
  byte bVar196;
  byte bVar197;
  byte bVar198;
  byte bVar199;
  byte bVar200;
  byte bVar201;
  byte bVar202;
  byte bVar203;
  undefined4 uVar204;
  undefined4 uVar205;
  undefined4 uVar206;
  undefined4 uVar207;
  uint uVar208;
  uint uVar209;
  uint uVar210;
  uint uVar211;
  undefined1 auVar212 [16];
  undefined1 auVar213 [16];
  undefined1 auVar214 [16];
  undefined1 auVar215 [16];
  undefined1 auVar216 [16];
  undefined1 auVar217 [16];
  undefined1 auVar218 [16];
  undefined1 auVar219 [16];
  undefined1 auVar220 [16];
  undefined1 auVar221 [16];
  undefined1 auVar222 [16];
  undefined1 auVar223 [16];
  undefined1 auVar224 [16];
  undefined1 auVar225 [16];
  undefined1 auVar226 [16];
  undefined1 auVar227 [16];
  undefined1 auVar228 [16];
  undefined1 auVar229 [16];
  undefined1 auVar230 [16];
  undefined1 auVar231 [16];
  undefined1 auVar232 [16];
  undefined1 auVar233 [16];
  undefined1 auVar234 [16];
  undefined1 auVar235 [16];
  undefined1 auVar236 [16];
  undefined1 auVar237 [16];
  undefined1 auVar238 [16];
  undefined1 auVar239 [16];
  undefined1 auVar240 [16];
  undefined1 auVar241 [16];
  undefined1 auVar242 [16];
  undefined1 auVar243 [16];
  undefined1 auVar244 [16];
  undefined1 auVar245 [16];
  undefined1 auVar246 [16];
  undefined1 auVar247 [16];
  undefined1 auVar248 [16];
  undefined1 auVar249 [16];
  undefined1 auVar250 [16];
  undefined1 auVar251 [16];
  undefined1 auVar252 [16];
  undefined1 auVar253 [16];
  undefined1 auVar254 [16];
  undefined1 auVar255 [16];
  undefined1 auVar256 [16];
  undefined1 auVar257 [16];
  undefined1 auVar258 [16];
  undefined1 auVar259 [16];
  undefined1 auVar260 [16];
  undefined1 auVar261 [16];
  undefined1 auVar262 [16];
  undefined1 auVar263 [16];
  undefined1 auVar264 [16];
  undefined1 auVar265 [16];
  undefined1 auVar266 [16];
  undefined1 auVar267 [16];
  undefined1 auVar268 [16];
  undefined1 auVar269 [16];
  undefined1 auVar270 [16];
  undefined1 auVar271 [16];
  undefined1 auVar272 [16];
  undefined1 auVar273 [16];
  undefined1 auVar274 [16];
  undefined1 auVar275 [16];
  undefined1 auVar276 [16];
  undefined1 auVar277 [16];
  undefined1 auVar278 [16];
  undefined1 auVar279 [16];
  undefined1 auVar280 [16];
  undefined1 auVar281 [16];
  undefined1 auVar282 [16];
  undefined1 auVar283 [16];
  undefined1 auVar284 [16];
  undefined1 auVar285 [16];
  undefined1 auVar286 [16];
  undefined1 auVar287 [16];
  undefined1 auVar288 [16];
  undefined1 auVar289 [16];
  undefined1 auVar290 [16];
  undefined1 auVar291 [16];
  undefined1 auVar292 [15];
  unkuint9 Var293;
  undefined1 auVar294 [11];
  undefined1 auVar295 [15];
  unkuint9 Var296;
  undefined1 auVar297 [11];
  undefined1 auVar298 [13];
  undefined1 auVar299 [16];
  undefined1 auVar300 [16];
  undefined1 auVar301 [16];
  undefined1 auVar302 [16];
  undefined1 auVar303 [16];
  undefined1 auVar304 [16];
  undefined1 auVar305 [16];
  undefined1 auVar306 [16];
  undefined1 auVar307 [16];
  undefined1 auVar308 [16];
  undefined1 auVar309 [16];
  undefined1 auVar310 [16];
  undefined1 auVar311 [16];
  undefined1 auVar312 [16];
  undefined1 auVar313 [16];
  undefined1 auVar314 [16];
  undefined1 auVar315 [16];
  undefined1 auVar316 [16];
  undefined1 auVar317 [16];
  undefined1 auVar318 [16];
  undefined1 auVar319 [16];
  undefined1 auVar320 [16];
  undefined1 auVar321 [16];
  undefined1 auVar322 [16];
  undefined1 auVar323 [16];
  undefined1 auVar324 [16];
  undefined1 auVar325 [16];
  undefined1 auVar326 [16];
  undefined1 auVar327 [16];
  undefined1 auVar328 [16];
  undefined1 auVar329 [16];
  undefined1 auVar330 [16];
  undefined1 auVar331 [16];
  undefined1 auVar332 [16];
  undefined1 auVar333 [16];
  undefined1 auVar334 [16];
  undefined1 auVar335 [16];
  undefined1 auVar336 [16];
  undefined1 auVar337 [16];
  undefined1 auVar338 [16];
  undefined1 auVar339 [16];
  undefined1 auVar340 [16];
  undefined1 auVar341 [16];
  undefined1 auVar342 [16];
  undefined1 auVar343 [16];
  undefined1 auVar344 [16];
  undefined1 auVar345 [16];
  undefined1 auVar346 [16];
  undefined1 auVar347 [16];
  undefined1 auVar348 [16];
  undefined1 auVar349 [16];
  undefined1 auVar350 [16];
  undefined1 auVar351 [16];
  undefined1 auVar352 [16];
  undefined1 auVar353 [16];
  undefined1 auVar354 [16];
  undefined1 auVar355 [16];
  undefined1 auVar356 [16];
  undefined1 auVar357 [16];
  undefined1 auVar358 [16];
  undefined1 auVar359 [15];
  unkuint9 Var360;
  undefined1 auVar361 [11];
  undefined1 auVar362 [13];
  undefined1 auVar363 [16];
  undefined1 auVar364 [16];
  undefined1 auVar365 [16];
  undefined1 auVar366 [16];
  undefined1 auVar367 [16];
  undefined1 auVar368 [16];
  undefined1 auVar369 [16];
  undefined1 auVar370 [16];
  undefined1 auVar371 [16];
  undefined1 auVar372 [16];
  undefined1 auVar373 [16];
  undefined1 auVar374 [16];
  undefined1 auVar375 [16];
  undefined1 auVar376 [16];
  undefined1 auVar377 [16];
  undefined1 auVar378 [16];
  undefined1 auVar379 [16];
  undefined1 auVar380 [16];
  undefined1 auVar381 [16];
  undefined1 auVar382 [16];
  undefined1 auVar383 [16];
  undefined1 auVar384 [16];
  undefined1 auVar385 [16];
  undefined1 auVar386 [16];
  undefined1 auVar387 [16];
  undefined1 auVar388 [16];
  undefined1 auVar389 [16];
  undefined1 auVar390 [16];
  undefined1 auVar391 [16];
  undefined1 auVar392 [16];
  undefined1 auVar393 [16];
  undefined1 auVar394 [16];
  undefined1 auVar395 [16];
  undefined1 auVar396 [16];
  undefined1 auVar397 [16];
  undefined1 auVar398 [16];
  undefined1 auVar399 [16];
  undefined1 auVar400 [16];
  undefined1 auVar401 [16];
  undefined1 auVar402 [16];
  undefined1 auVar403 [16];
  undefined1 auVar404 [16];
  undefined1 auVar405 [16];
  undefined1 auVar406 [16];
  undefined1 auVar407 [16];
  undefined1 auVar408 [16];
  undefined1 auVar409 [16];
  undefined1 auVar410 [16];
  undefined1 auVar411 [16];
  undefined1 auVar412 [16];
  undefined1 auVar413 [16];
  undefined1 auVar414 [16];
  undefined1 auVar415 [16];
  undefined1 auVar416 [16];
  undefined1 auVar417 [16];
  undefined1 auVar418 [16];
  undefined1 auVar419 [16];
  undefined1 auVar420 [16];
  undefined1 auVar421 [16];
  undefined1 auVar422 [16];
  undefined1 auVar423 [14];
  undefined1 auVar424 [14];
  undefined1 auVar425 [14];
  undefined1 auVar426 [15];
  undefined1 auVar427 [11];
  undefined1 auVar428 [13];
  undefined1 auVar429 [14];
  undefined1 auVar430 [15];
  undefined1 auVar431 [11];
  undefined1 auVar432 [13];
  undefined1 auVar433 [15];
  undefined1 auVar434 [11];
  undefined1 auVar435 [16];
  undefined1 auVar436 [16];
  undefined1 auVar437 [16];
  undefined1 auVar438 [16];
  undefined1 auVar439 [16];
  undefined1 auVar440 [16];
  undefined1 auVar441 [16];
  undefined1 auVar442 [16];
  undefined1 auVar443 [16];
  undefined1 auVar444 [16];
  undefined1 auVar445 [16];
  undefined1 auVar446 [16];
  undefined1 auVar447 [16];
  undefined1 auVar448 [16];
  undefined1 auVar449 [16];
  undefined1 auVar450 [16];
  undefined1 auVar451 [16];
  undefined1 auVar452 [16];
  undefined1 auVar453 [16];
  undefined1 auVar454 [16];
  undefined1 auVar455 [16];
  undefined1 auVar456 [16];
  undefined1 auVar457 [16];
  undefined1 auVar458 [16];
  undefined1 auVar459 [16];
  undefined1 auVar460 [16];
  undefined1 auVar461 [16];
  undefined1 auVar462 [16];
  undefined1 auVar463 [16];
  undefined1 auVar464 [16];
  undefined1 auVar465 [16];
  undefined1 auVar466 [16];
  undefined1 auVar467 [16];
  undefined1 auVar468 [16];
  undefined1 auVar469 [16];
  undefined1 auVar470 [16];
  undefined1 auVar471 [16];
  undefined1 auVar472 [16];
  undefined1 auVar473 [16];
  undefined1 auVar474 [16];
  undefined1 auVar475 [16];
  undefined1 auVar476 [16];
  undefined1 auVar477 [16];
  undefined1 auVar478 [16];
  undefined1 auVar479 [16];
  undefined1 auVar480 [16];
  undefined1 auVar481 [16];
  undefined1 auVar482 [16];
  undefined1 auVar483 [16];
  undefined1 auVar484 [16];
  undefined1 auVar485 [16];
  undefined1 auVar486 [16];
  undefined1 auVar487 [16];
  undefined1 auVar488 [16];
  undefined1 auVar489 [16];
  undefined1 auVar490 [16];
  undefined1 auVar491 [16];
  undefined1 auVar492 [16];
  undefined1 auVar493 [16];
  undefined1 auVar494 [16];
  undefined1 auVar495 [15];
  undefined1 auVar496 [11];
  undefined1 auVar497 [13];
  undefined1 auVar498 [16];
  undefined1 auVar499 [16];
  undefined1 auVar500 [16];
  undefined1 auVar501 [16];
  undefined1 auVar502 [16];
  undefined1 auVar503 [16];
  undefined1 auVar504 [16];
  undefined1 auVar505 [16];
  undefined1 auVar506 [16];
  undefined1 auVar507 [16];
  undefined1 auVar508 [16];
  undefined1 auVar509 [16];
  undefined1 auVar510 [16];
  undefined1 auVar511 [16];
  undefined1 auVar512 [16];
  undefined1 auVar513 [16];
  undefined1 auVar514 [16];
  undefined1 auVar515 [16];
  undefined1 auVar516 [16];
  undefined1 auVar517 [16];
  undefined1 auVar518 [16];
  undefined1 auVar519 [16];
  undefined1 auVar520 [16];
  undefined1 auVar521 [16];
  undefined1 auVar522 [16];
  undefined1 auVar523 [16];
  undefined1 auVar524 [16];
  undefined1 auVar525 [16];
  undefined1 auVar526 [16];
  undefined1 auVar527 [16];
  undefined1 auVar528 [16];
  undefined1 auVar529 [16];
  undefined1 auVar530 [16];
  undefined1 auVar531 [16];
  undefined1 auVar532 [16];
  undefined1 auVar533 [16];
  undefined1 auVar534 [16];
  undefined1 auVar535 [16];
  undefined1 auVar536 [16];
  undefined1 auVar537 [16];
  undefined1 auVar538 [16];
  undefined1 auVar539 [16];
  undefined1 auVar540 [16];
  undefined1 auVar541 [16];
  undefined1 auVar542 [16];
  undefined1 auVar543 [14];
  undefined1 auVar544 [16];
  undefined1 auVar545 [16];
  undefined1 auVar546 [16];
  undefined1 auVar547 [16];
  undefined1 auVar548 [16];
  undefined1 auVar549 [16];
  undefined1 auVar550 [16];
  undefined1 auVar551 [16];
  undefined1 auVar552 [16];
  undefined1 auVar553 [16];
  undefined1 auVar554 [16];
  undefined1 auVar555 [16];
  undefined1 auVar556 [16];
  undefined1 auVar557 [16];
  undefined1 auVar558 [16];
  undefined1 auVar559 [14];
  undefined1 auVar560 [14];
  undefined1 auVar561 [15];
  undefined1 auVar562 [11];
  undefined1 auVar563 [13];
  undefined1 auVar564 [14];
  undefined1 auVar565 [13];
  undefined1 auVar566 [15];
  undefined1 auVar567 [11];
  undefined1 auVar568 [15];
  undefined1 auVar569 [11];
  undefined1 auVar570 [13];
  undefined1 auVar571 [16];
  undefined1 auVar572 [16];
  undefined1 auVar573 [16];
  undefined1 auVar574 [16];
  undefined1 auVar575 [16];
  undefined1 auVar576 [16];
  undefined1 auVar577 [16];
  undefined1 auVar578 [16];
  undefined1 auVar579 [16];
  undefined1 auVar580 [16];
  undefined1 auVar581 [16];
  undefined1 auVar582 [16];
  undefined1 auVar583 [16];
  undefined1 auVar584 [16];
  undefined1 auVar585 [16];
  undefined1 auVar586 [16];
  undefined1 auVar587 [16];
  undefined1 auVar588 [16];
  undefined1 auVar589 [16];
  undefined1 auVar590 [16];
  undefined1 auVar591 [16];
  undefined1 auVar592 [16];
  undefined1 auVar593 [16];
  undefined1 auVar594 [16];
  undefined1 auVar595 [16];
  undefined1 auVar596 [16];
  undefined1 auVar597 [16];
  undefined1 auVar598 [16];
  undefined1 auVar599 [16];
  undefined1 auVar600 [16];
  undefined1 auVar601 [16];
  undefined1 auVar602 [16];
  undefined1 auVar603 [16];
  undefined1 auVar604 [16];
  undefined1 auVar605 [16];
  undefined1 auVar606 [16];
  undefined1 auVar607 [16];
  undefined1 auVar608 [16];
  undefined1 auVar609 [16];
  undefined1 auVar610 [16];
  undefined1 auVar611 [16];
  undefined1 auVar612 [16];
  undefined1 auVar613 [16];
  undefined1 auVar614 [16];
  undefined1 auVar615 [16];
  undefined1 auVar616 [16];
  undefined1 auVar617 [16];
  undefined1 auVar618 [16];
  undefined1 auVar619 [16];
  undefined1 auVar620 [16];
  undefined1 auVar621 [16];
  undefined1 auVar622 [16];
  undefined1 auVar623 [16];
  undefined1 auVar624 [16];
  undefined1 auVar625 [16];
  undefined1 auVar626 [16];
  undefined1 auVar627 [16];
  undefined1 auVar628 [16];
  undefined1 auVar629 [16];
  undefined1 auVar630 [16];
  undefined1 auVar631 [15];
  undefined1 auVar632 [11];
  undefined1 auVar633 [13];
  undefined1 auVar634 [16];
  undefined1 auVar635 [16];
  undefined1 auVar636 [16];
  undefined1 auVar637 [16];
  undefined1 auVar638 [16];
  undefined1 auVar639 [16];
  undefined1 auVar640 [16];
  undefined1 auVar641 [16];
  undefined1 auVar642 [16];
  undefined1 auVar643 [16];
  undefined1 auVar644 [16];
  undefined1 auVar645 [16];
  undefined1 auVar646 [16];
  undefined1 auVar647 [16];
  undefined1 auVar648 [16];
  undefined1 auVar649 [16];
  undefined1 auVar650 [16];
  undefined1 auVar651 [16];
  undefined1 auVar652 [16];
  undefined1 auVar653 [16];
  undefined1 auVar654 [16];
  undefined1 auVar655 [16];
  undefined1 auVar656 [16];
  undefined1 auVar657 [16];
  undefined1 auVar658 [16];
  undefined1 auVar659 [16];
  undefined1 auVar660 [16];
  undefined1 auVar661 [16];
  undefined1 auVar662 [16];
  undefined1 auVar663 [16];
  undefined1 auVar664 [16];
  undefined1 auVar665 [16];
  undefined1 auVar666 [16];
  undefined1 auVar667 [16];
  undefined1 auVar668 [16];
  undefined1 auVar669 [16];
  undefined1 auVar670 [16];
  undefined1 auVar671 [16];
  undefined1 auVar672 [16];
  undefined1 auVar673 [16];
  undefined1 auVar674 [16];
  undefined1 auVar675 [16];
  undefined1 auVar676 [16];
  undefined1 auVar677 [16];
  undefined1 auVar678 [16];
  undefined1 auVar679 [16];
  undefined1 auVar680 [16];
  undefined1 auVar681 [16];
  undefined1 auVar682 [16];
  undefined1 auVar683 [16];
  undefined1 auVar684 [16];
  undefined1 auVar685 [16];
  undefined1 auVar686 [16];
  undefined1 auVar687 [16];
  undefined1 auVar688 [16];
  undefined1 auVar689 [14];
  undefined1 auVar690 [16];
  undefined1 auVar691 [16];
  undefined1 auVar692 [16];
  undefined1 auVar693 [16];
  undefined1 auVar694 [16];
  undefined1 auVar695 [14];
  undefined1 auVar696 [14];
  undefined1 auVar697 [15];
  undefined1 auVar698 [11];
  undefined1 auVar699 [13];
  undefined1 auVar700 [14];
  undefined1 auVar701 [13];
  undefined1 auVar702 [15];
  undefined1 auVar703 [11];
  undefined1 auVar704 [15];
  undefined1 auVar705 [11];
  undefined1 auVar706 [16];
  undefined1 auVar707 [16];
  undefined1 auVar708 [16];
  undefined1 auVar709 [16];
  undefined1 auVar710 [16];
  undefined1 auVar711 [16];
  undefined1 auVar712 [16];
  undefined1 auVar713 [16];
  undefined1 auVar714 [16];
  undefined1 auVar715 [16];
  undefined1 auVar716 [16];
  undefined1 auVar717 [16];
  undefined1 auVar718 [16];
  undefined1 auVar719 [16];
  undefined1 auVar720 [16];
  undefined1 auVar721 [16];
  undefined1 auVar722 [16];
  undefined1 auVar723 [16];
  undefined1 auVar724 [16];
  undefined1 auVar725 [16];
  undefined1 auVar726 [16];
  undefined1 auVar727 [16];
  undefined1 auVar728 [16];
  undefined1 auVar729 [16];
  undefined1 auVar730 [16];
  undefined1 auVar731 [16];
  undefined1 auVar732 [16];
  undefined1 auVar733 [16];
  undefined1 auVar734 [16];
  undefined1 auVar735 [16];
  undefined1 auVar736 [16];
  undefined1 auVar737 [16];
  undefined1 auVar738 [16];
  undefined1 auVar739 [16];
  undefined1 auVar740 [16];
  undefined1 auVar741 [16];
  undefined1 auVar742 [16];
  undefined1 auVar743 [16];
  undefined1 auVar744 [16];
  undefined1 auVar745 [16];
  undefined1 auVar746 [16];
  undefined1 auVar747 [16];
  undefined1 auVar748 [16];
  undefined1 auVar749 [16];
  undefined1 auVar750 [16];
  undefined1 auVar751 [16];
  undefined1 auVar752 [16];
  undefined1 auVar753 [16];
  undefined1 auVar754 [16];
  undefined1 auVar755 [16];
  undefined1 auVar756 [16];
  undefined1 auVar757 [16];
  undefined1 auVar758 [16];
  undefined1 auVar759 [16];
  undefined1 auVar760 [16];
  undefined1 auVar761 [16];
  undefined1 auVar762 [16];
  undefined1 auVar763 [16];
  undefined1 auVar764 [16];
  undefined1 auVar765 [16];
  undefined1 auVar766 [15];
  undefined1 auVar767 [11];
  undefined1 auVar768 [13];
  undefined1 auVar769 [16];
  undefined1 auVar770 [16];
  undefined1 auVar771 [16];
  undefined1 auVar772 [16];
  undefined1 auVar773 [16];
  undefined1 auVar774 [16];
  undefined1 auVar775 [16];
  undefined1 auVar776 [16];
  undefined1 auVar777 [16];
  undefined1 auVar778 [16];
  undefined1 auVar779 [16];
  undefined1 auVar780 [16];
  undefined1 auVar781 [16];
  undefined1 auVar782 [16];
  undefined1 auVar783 [16];
  undefined1 auVar784 [16];
  undefined1 auVar785 [16];
  undefined1 auVar786 [16];
  undefined1 auVar787 [16];
  undefined1 auVar788 [16];
  undefined1 auVar789 [16];
  undefined1 auVar790 [16];
  undefined1 auVar791 [16];
  undefined1 auVar792 [16];
  undefined1 auVar793 [16];
  undefined1 auVar794 [16];
  undefined1 auVar795 [16];
  undefined1 auVar796 [16];
  undefined1 auVar797 [16];
  undefined1 auVar798 [16];
  undefined1 auVar799 [16];
  undefined1 auVar800 [16];
  undefined1 auVar801 [16];
  undefined1 auVar802 [16];
  undefined1 auVar803 [16];
  undefined1 auVar804 [16];
  undefined1 auVar805 [16];
  undefined1 auVar806 [16];
  undefined1 auVar807 [16];
  undefined1 auVar808 [16];
  undefined1 auVar809 [16];
  undefined1 auVar810 [16];
  undefined1 auVar811 [16];
  undefined1 auVar812 [16];
  undefined1 auVar813 [16];
  undefined1 auVar814 [16];
  undefined1 auVar815 [16];
  undefined1 auVar816 [16];
  undefined1 auVar817 [16];
  undefined1 auVar818 [16];
  undefined1 auVar819 [16];
  undefined1 auVar820 [16];
  undefined1 auVar821 [16];
  undefined1 auVar822 [16];
  undefined1 auVar823 [16];
  undefined1 auVar824 [16];
  undefined1 auVar825 [16];
  undefined1 auVar826 [16];
  undefined1 auVar827 [16];
  undefined1 auVar828 [16];
  undefined1 auVar829 [14];
  undefined1 auVar830 [14];
  undefined1 auVar831 [14];
  undefined1 auVar832 [15];
  undefined1 auVar833 [11];
  undefined1 auVar834 [13];
  undefined1 auVar835 [14];
  undefined1 auVar836 [12];
  undefined1 auVar837 [12];
  undefined1 auVar838 [12];
  undefined1 auVar839 [12];
  undefined1 auVar840 [12];
  undefined1 auVar841 [12];
  undefined1 auVar842 [15];
  undefined1 auVar843 [15];
  undefined1 auVar844 [15];
  undefined1 auVar845 [15];
  undefined1 auVar846 [15];
  undefined1 auVar847 [15];
  undefined1 auVar848 [15];
  undefined1 auVar849 [15];
  undefined1 auVar850 [15];
  undefined1 auVar851 [15];
  undefined1 auVar852 [15];
  undefined1 auVar853 [15];
  undefined1 auVar854 [15];
  undefined1 auVar855 [15];
  undefined1 auVar856 [15];
  undefined1 auVar857 [15];
  undefined1 auVar858 [15];
  undefined1 auVar859 [15];
  undefined1 auVar860 [15];
  undefined1 auVar861 [15];
  undefined1 auVar862 [15];
  undefined1 auVar863 [15];
  undefined1 auVar864 [15];
  undefined1 auVar865 [15];
  undefined1 auVar866 [15];
  undefined1 auVar867 [15];
  undefined1 auVar868 [15];
  undefined1 auVar869 [15];
  undefined1 auVar870 [15];
  undefined1 auVar871 [15];
  undefined1 auVar872 [15];
  undefined1 auVar873 [15];
  undefined1 auVar874 [13];
  undefined1 auVar875 [13];
  undefined1 auVar876 [13];
  undefined1 auVar877 [13];
  undefined1 auVar878 [13];
  undefined1 auVar879 [13];
  undefined1 auVar880 [13];
  undefined1 auVar881 [13];
  undefined1 auVar882 [13];
  undefined1 auVar883 [13];
  undefined1 auVar884 [13];
  undefined1 auVar885 [13];
  undefined1 auVar886 [13];
  undefined1 auVar887 [13];
  undefined1 auVar888 [13];
  undefined1 auVar889 [13];
  undefined1 auVar890 [13];
  undefined1 auVar891 [13];
  undefined1 auVar892 [13];
  undefined1 auVar893 [13];
  undefined1 auVar894 [13];
  undefined1 auVar895 [13];
  undefined1 auVar896 [13];
  undefined1 auVar897 [13];
  undefined1 auVar898 [13];
  undefined1 auVar899 [13];
  undefined1 auVar900 [13];
  undefined1 auVar901 [13];
  undefined1 auVar902 [13];
  uint6 uVar903;
  uint6 uVar904;
  uint6 uVar905;
  uint6 uVar906;
  undefined1 auVar907 [13];
  uint6 uVar908;
  uint6 uVar909;
  uint6 uVar910;
  uint6 uVar911;
  undefined1 auVar912 [13];
  uint6 uVar913;
  uint6 uVar914;
  uint6 uVar915;
  uint6 uVar916;
  undefined1 auVar917 [13];
  undefined1 auVar918 [13];
  uint6 uVar919;
  uint6 uVar920;
  uint6 uVar921;
  uint6 uVar922;
  undefined3 uVar923;
  undefined3 uVar924;
  undefined3 uVar925;
  undefined3 uVar926;
  undefined8 uVar927;
  undefined8 uVar928;
  undefined5 uVar929;
  undefined5 uVar930;
  undefined5 uVar931;
  undefined5 uVar932;
  undefined8 uVar933;
  undefined8 uVar934;
  undefined1 auVar935 [14];
  undefined1 auVar936 [14];
  undefined1 auVar937 [14];
  undefined1 auVar938 [14];
  undefined1 auVar939 [14];
  byte bVar940;
  byte bVar941;
  undefined1 uVar942;
  int iVar943;
  uint uVar944;
  int iVar945;
  byte *pbVar946;
  uint uVar947;
  int iVar948;
  byte *pbVar949;
  byte *pbVar950;
  byte *pbVar951;
  byte *pbVar952;
  byte *pbVar953;
  byte *pbVar954;
  byte *pbVar955;
  byte *pbVar956;
  uint uVar957;
  undefined1 auVar959 [16];
  undefined1 auVar960 [16];
  undefined1 auVar968 [16];
  undefined1 auVar976 [16];
  undefined1 auVar984 [16];
  undefined1 auVar992 [16];
  undefined1 auVar1000 [16];
  undefined1 auVar1008 [16];
  undefined1 auVar1016 [16];
  undefined1 auVar1024 [16];
  undefined1 auVar1032 [16];
  undefined1 auVar1040 [16];
  undefined1 auVar1048 [16];
  undefined1 auVar1056 [16];
  undefined1 auVar1064 [16];
  undefined1 auVar1072 [16];
  uint uVar958;
  undefined1 auVar1080 [16];
  undefined1 auVar1088 [16];
  undefined1 auVar1096 [16];
  undefined1 auVar1104 [16];
  undefined1 auVar1112 [16];
  undefined1 auVar1120 [16];
  undefined1 auVar1128 [16];
  undefined1 auVar1136 [16];
  undefined1 auVar1144 [16];
  undefined1 auVar1152 [16];
  undefined1 auVar1160 [16];
  undefined1 auVar1168 [16];
  uint uVar1177;
  uint uVar1590;
  undefined1 auVar1181 [16];
  undefined1 auVar1182 [16];
  undefined1 auVar1190 [16];
  undefined1 auVar1198 [16];
  undefined1 auVar1206 [16];
  undefined1 auVar1214 [16];
  undefined1 auVar1222 [16];
  undefined1 auVar1230 [16];
  undefined1 auVar1238 [16];
  undefined1 auVar1246 [16];
  undefined1 auVar1254 [16];
  undefined1 auVar1262 [16];
  undefined1 auVar1270 [16];
  undefined1 auVar1278 [16];
  undefined1 auVar1286 [16];
  undefined1 auVar1294 [16];
  undefined1 auVar1302 [16];
  undefined1 auVar1310 [16];
  undefined1 auVar1318 [16];
  undefined1 auVar1326 [16];
  undefined1 auVar1334 [16];
  undefined1 auVar1342 [16];
  undefined1 auVar1350 [16];
  undefined1 auVar1358 [16];
  undefined1 auVar1366 [16];
  undefined1 auVar1374 [16];
  undefined1 auVar1382 [16];
  undefined1 auVar1390 [16];
  uint uVar1178;
  uint uVar1179;
  undefined1 auVar1398 [16];
  undefined1 auVar1406 [16];
  undefined1 auVar1414 [16];
  undefined1 auVar1422 [16];
  undefined1 auVar1430 [16];
  undefined1 auVar1438 [16];
  undefined1 auVar1446 [16];
  undefined1 auVar1454 [16];
  undefined1 auVar1462 [16];
  undefined1 auVar1470 [16];
  undefined1 auVar1478 [16];
  undefined1 auVar1486 [16];
  uint uVar1180;
  undefined1 auVar1494 [16];
  undefined1 auVar1502 [16];
  undefined1 auVar1510 [16];
  undefined1 auVar1518 [16];
  undefined1 auVar1526 [16];
  undefined1 auVar1534 [16];
  undefined1 auVar1542 [16];
  undefined1 auVar1550 [16];
  undefined1 auVar1558 [16];
  undefined1 auVar1566 [16];
  undefined1 auVar1574 [16];
  undefined1 auVar1582 [16];
  uint uVar1591;
  uint uVar1595;
  uint uVar1821;
  undefined1 auVar1596 [16];
  undefined1 auVar1604 [16];
  undefined1 auVar1612 [16];
  undefined1 auVar1620 [16];
  uint uVar1592;
  uint uVar1593;
  undefined1 auVar1628 [16];
  undefined1 auVar1636 [16];
  undefined1 auVar1644 [16];
  undefined1 auVar1652 [16];
  undefined1 auVar1660 [16];
  undefined1 auVar1668 [16];
  undefined1 auVar1676 [16];
  undefined1 auVar1684 [16];
  undefined1 auVar1692 [16];
  undefined1 auVar1700 [16];
  undefined1 auVar1708 [16];
  undefined1 auVar1716 [16];
  uint uVar1594;
  undefined1 auVar1724 [16];
  undefined1 auVar1732 [16];
  undefined1 auVar1740 [16];
  undefined1 auVar1748 [16];
  undefined1 auVar1756 [16];
  undefined1 auVar1764 [16];
  undefined1 auVar1772 [16];
  undefined1 auVar1780 [16];
  undefined1 auVar1788 [16];
  undefined1 auVar1796 [16];
  undefined1 auVar1804 [16];
  undefined1 auVar1812 [16];
  uint uVar1822;
  uint uVar1823;
  uint uVar1824;
  uint uVar1825;
  uint uVar1851;
  undefined1 uVar1852;
  undefined1 uVar1853;
  undefined1 auVar1826 [16];
  undefined1 auVar1827 [16];
  undefined1 auVar1835 [16];
  undefined1 auVar1843 [16];
  uint uVar1854;
  uint uVar1855;
  uint uVar1856;
  uint uVar1857;
  uint uVar1858;
  uint uVar1859;
  uint uVar1860;
  uint uVar1861;
  uint uVar1862;
  uint uVar1863;
  uint uVar1864;
  uint uVar1865;
  uint uVar1866;
  uint uVar1867;
  ushort uStack_114;
  ushort uStack_112;
  undefined1 local_10c;
  undefined1 uStack_10b;
  undefined1 uStack_10a;
  undefined1 uStack_109;
  undefined1 uStack_108;
  undefined1 uStack_107;
  undefined1 uStack_106;
  undefined1 uStack_105;
  undefined1 uStack_104;
  undefined1 uStack_103;
  undefined1 uStack_102;
  undefined1 uStack_101;
  undefined1 uStack_100;
  undefined1 uStack_ff;
  undefined1 uStack_fe;
  undefined1 uStack_fd;
  byte local_fc;
  byte bStack_fb;
  byte bStack_fa;
  byte bStack_f9;
  byte bStack_f8;
  byte bStack_f7;
  byte bStack_f6;
  byte bStack_f5;
  undefined1 uStack_f4;
  undefined1 uStack_f3;
  undefined1 uStack_f2;
  undefined1 uStack_f1;
  undefined1 uStack_f0;
  undefined1 uStack_ef;
  undefined1 uStack_ee;
  undefined1 uStack_ed;
  byte local_ec;
  byte bStack_eb;
  byte bStack_ea;
  byte bStack_e9;
  byte bStack_e8;
  byte bStack_e7;
  byte bStack_e6;
  byte bStack_e5;
  undefined2 uStack_e4;
  undefined2 uStack_e2;
  undefined1 uStack_e0;
  byte bStack_df;
  byte bStack_de;
  byte local_dc;
  byte bStack_db;
  byte bStack_da;
  byte bStack_d9;
  byte bStack_d8;
  byte bStack_d7;
  byte bStack_d6;
  byte bStack_d5;
  undefined2 uStack_d4;
  undefined2 uStack_d2;
  undefined1 uStack_d0;
  undefined1 uStack_cf;
  undefined1 uStack_ce;
  undefined1 uStack_cd;
  byte local_cc;
  byte bStack_cb;
  byte bStack_ca;
  byte bStack_c9;
  byte bStack_c8;
  byte bStack_c7;
  byte bStack_c6;
  byte bStack_c5;
  byte bStack_c4;
  byte bStack_c3;
  byte bStack_c2;
  byte bStack_c1;
  byte local_bc;
  undefined1 uStack_bb;
  undefined1 uStack_ba;
  undefined1 uStack_b9;
  undefined1 uStack_b8;
  undefined1 uStack_b7;
  undefined1 uStack_b6;
  undefined1 uStack_b5;
  undefined2 uStack_b4;
  undefined2 uStack_b2;
  undefined1 uStack_b0;
  undefined1 uStack_af;
  undefined1 uStack_ae;
  undefined1 uStack_ad;
  ushort uStack_a4;
  ushort uStack_a2;
  byte local_9c;
  undefined1 uStack_98;
  ushort uStack_94;
  ushort uStack_92;
  byte local_8c;
  undefined1 uStack_88;
  byte bStack_84;
  byte *local_7c;
  byte *local_78;
  undefined1 local_5c;
  undefined1 uStack_58;
  undefined1 uStack_54;
  uint local_48;
  int local_2c;
  undefined1 auVar961 [16];
  undefined1 auVar969 [16];
  undefined1 auVar977 [16];
  undefined1 auVar985 [16];
  undefined1 auVar993 [16];
  undefined1 auVar1001 [16];
  undefined1 auVar1009 [16];
  undefined1 auVar1017 [16];
  undefined1 auVar1025 [16];
  undefined1 auVar1033 [16];
  undefined1 auVar1041 [16];
  undefined1 auVar1049 [16];
  undefined1 auVar1057 [16];
  undefined1 auVar1065 [16];
  undefined1 auVar1073 [16];
  undefined1 auVar1081 [16];
  undefined1 auVar1089 [16];
  undefined1 auVar1097 [16];
  undefined1 auVar1105 [16];
  undefined1 auVar1113 [16];
  undefined1 auVar1121 [16];
  undefined1 auVar1129 [16];
  undefined1 auVar1137 [16];
  undefined1 auVar1145 [16];
  undefined1 auVar1153 [16];
  undefined1 auVar1161 [16];
  undefined1 auVar1169 [16];
  undefined1 auVar962 [16];
  undefined1 auVar970 [16];
  undefined1 auVar978 [16];
  undefined1 auVar986 [16];
  undefined1 auVar994 [16];
  undefined1 auVar1002 [16];
  undefined1 auVar1010 [16];
  undefined1 auVar1018 [16];
  undefined1 auVar1026 [16];
  undefined1 auVar1034 [16];
  undefined1 auVar1042 [16];
  undefined1 auVar1050 [16];
  undefined1 auVar1058 [16];
  undefined1 auVar1066 [16];
  undefined1 auVar1074 [16];
  undefined1 auVar1082 [16];
  undefined1 auVar1090 [16];
  undefined1 auVar1098 [16];
  undefined1 auVar1106 [16];
  undefined1 auVar1114 [16];
  undefined1 auVar1122 [16];
  undefined1 auVar1130 [16];
  undefined1 auVar1138 [16];
  undefined1 auVar1146 [16];
  undefined1 auVar1154 [16];
  undefined1 auVar1162 [16];
  undefined1 auVar1170 [16];
  undefined1 auVar963 [16];
  undefined1 auVar971 [16];
  undefined1 auVar979 [16];
  undefined1 auVar987 [16];
  undefined1 auVar995 [16];
  undefined1 auVar1003 [16];
  undefined1 auVar1011 [16];
  undefined1 auVar1019 [16];
  undefined1 auVar1027 [16];
  undefined1 auVar1035 [16];
  undefined1 auVar1043 [16];
  undefined1 auVar1051 [16];
  undefined1 auVar1059 [16];
  undefined1 auVar1067 [16];
  undefined1 auVar1075 [16];
  undefined1 auVar1083 [16];
  undefined1 auVar1091 [16];
  undefined1 auVar1099 [16];
  undefined1 auVar1107 [16];
  undefined1 auVar1115 [16];
  undefined1 auVar1123 [16];
  undefined1 auVar1131 [16];
  undefined1 auVar1139 [16];
  undefined1 auVar1147 [16];
  undefined1 auVar1155 [16];
  undefined1 auVar1163 [16];
  undefined1 auVar1171 [16];
  undefined1 auVar964 [16];
  undefined1 auVar972 [16];
  undefined1 auVar980 [16];
  undefined1 auVar988 [16];
  undefined1 auVar996 [16];
  undefined1 auVar1004 [16];
  undefined1 auVar1012 [16];
  undefined1 auVar1020 [16];
  undefined1 auVar1028 [16];
  undefined1 auVar1036 [16];
  undefined1 auVar1044 [16];
  undefined1 auVar1052 [16];
  undefined1 auVar1060 [16];
  undefined1 auVar1068 [16];
  undefined1 auVar1076 [16];
  undefined1 auVar1084 [16];
  undefined1 auVar1092 [16];
  undefined1 auVar1100 [16];
  undefined1 auVar1108 [16];
  undefined1 auVar1116 [16];
  undefined1 auVar1124 [16];
  undefined1 auVar1132 [16];
  undefined1 auVar1140 [16];
  undefined1 auVar1148 [16];
  undefined1 auVar1156 [16];
  undefined1 auVar1164 [16];
  undefined1 auVar1172 [16];
  undefined1 auVar965 [16];
  undefined1 auVar973 [16];
  undefined1 auVar981 [16];
  undefined1 auVar989 [16];
  undefined1 auVar997 [16];
  undefined1 auVar1005 [16];
  undefined1 auVar1013 [16];
  undefined1 auVar1021 [16];
  undefined1 auVar1029 [16];
  undefined1 auVar1037 [16];
  undefined1 auVar1045 [16];
  undefined1 auVar1053 [16];
  undefined1 auVar1061 [16];
  undefined1 auVar1069 [16];
  undefined1 auVar1077 [16];
  undefined1 auVar1085 [16];
  undefined1 auVar1093 [16];
  undefined1 auVar1101 [16];
  undefined1 auVar1109 [16];
  undefined1 auVar1117 [16];
  undefined1 auVar1125 [16];
  undefined1 auVar1133 [16];
  undefined1 auVar1141 [16];
  undefined1 auVar1149 [16];
  undefined1 auVar1157 [16];
  undefined1 auVar1165 [16];
  undefined1 auVar1173 [16];
  undefined1 auVar966 [16];
  undefined1 auVar974 [16];
  undefined1 auVar982 [16];
  undefined1 auVar990 [16];
  undefined1 auVar998 [16];
  undefined1 auVar1006 [16];
  undefined1 auVar1014 [16];
  undefined1 auVar1022 [16];
  undefined1 auVar1030 [16];
  undefined1 auVar1038 [16];
  undefined1 auVar1046 [16];
  undefined1 auVar1054 [16];
  undefined1 auVar1062 [16];
  undefined1 auVar1070 [16];
  undefined1 auVar1078 [16];
  undefined1 auVar1086 [16];
  undefined1 auVar1094 [16];
  undefined1 auVar1102 [16];
  undefined1 auVar1110 [16];
  undefined1 auVar1118 [16];
  undefined1 auVar1126 [16];
  undefined1 auVar1134 [16];
  undefined1 auVar1142 [16];
  undefined1 auVar1150 [16];
  undefined1 auVar1158 [16];
  undefined1 auVar1166 [16];
  undefined1 auVar1174 [16];
  undefined1 auVar967 [16];
  undefined1 auVar975 [16];
  undefined1 auVar983 [16];
  undefined1 auVar991 [16];
  undefined1 auVar999 [16];
  undefined1 auVar1007 [16];
  undefined1 auVar1015 [16];
  undefined1 auVar1023 [16];
  undefined1 auVar1031 [16];
  undefined1 auVar1039 [16];
  undefined1 auVar1047 [16];
  undefined1 auVar1055 [16];
  undefined1 auVar1063 [16];
  undefined1 auVar1071 [16];
  undefined1 auVar1079 [16];
  undefined1 auVar1087 [16];
  undefined1 auVar1095 [16];
  undefined1 auVar1103 [16];
  undefined1 auVar1111 [16];
  undefined1 auVar1119 [16];
  undefined1 auVar1127 [16];
  undefined1 auVar1135 [16];
  undefined1 auVar1143 [16];
  undefined1 auVar1151 [16];
  undefined1 auVar1159 [16];
  undefined1 auVar1167 [16];
  undefined1 auVar1175 [16];
  undefined1 uVar1176;
  undefined1 auVar1183 [16];
  undefined1 auVar1191 [16];
  undefined1 auVar1199 [16];
  undefined1 auVar1207 [16];
  undefined1 auVar1215 [16];
  undefined1 auVar1223 [16];
  undefined1 auVar1231 [16];
  undefined1 auVar1239 [16];
  undefined1 auVar1247 [16];
  undefined1 auVar1255 [16];
  undefined1 auVar1263 [16];
  undefined1 auVar1271 [16];
  undefined1 auVar1279 [16];
  undefined1 auVar1287 [16];
  undefined1 auVar1295 [16];
  undefined1 auVar1303 [16];
  undefined1 auVar1311 [16];
  undefined1 auVar1319 [16];
  undefined1 auVar1327 [16];
  undefined1 auVar1335 [16];
  undefined1 auVar1343 [16];
  undefined1 auVar1351 [16];
  undefined1 auVar1359 [16];
  undefined1 auVar1367 [16];
  undefined1 auVar1375 [16];
  undefined1 auVar1383 [16];
  undefined1 auVar1391 [16];
  undefined1 auVar1399 [16];
  undefined1 auVar1407 [16];
  undefined1 auVar1415 [16];
  undefined1 auVar1423 [16];
  undefined1 auVar1431 [16];
  undefined1 auVar1439 [16];
  undefined1 auVar1447 [16];
  undefined1 auVar1455 [16];
  undefined1 auVar1463 [16];
  undefined1 auVar1471 [16];
  undefined1 auVar1479 [16];
  undefined1 auVar1487 [16];
  undefined1 auVar1495 [16];
  undefined1 auVar1503 [16];
  undefined1 auVar1511 [16];
  undefined1 auVar1519 [16];
  undefined1 auVar1527 [16];
  undefined1 auVar1535 [16];
  undefined1 auVar1543 [16];
  undefined1 auVar1551 [16];
  undefined1 auVar1559 [16];
  undefined1 auVar1567 [16];
  undefined1 auVar1575 [16];
  undefined1 auVar1583 [16];
  undefined1 auVar1184 [16];
  undefined1 auVar1192 [16];
  undefined1 auVar1200 [16];
  undefined1 auVar1208 [16];
  undefined1 auVar1216 [16];
  undefined1 auVar1224 [16];
  undefined1 auVar1232 [16];
  undefined1 auVar1240 [16];
  undefined1 auVar1248 [16];
  undefined1 auVar1256 [16];
  undefined1 auVar1264 [16];
  undefined1 auVar1272 [16];
  undefined1 auVar1280 [16];
  undefined1 auVar1288 [16];
  undefined1 auVar1296 [16];
  undefined1 auVar1304 [16];
  undefined1 auVar1312 [16];
  undefined1 auVar1320 [16];
  undefined1 auVar1328 [16];
  undefined1 auVar1336 [16];
  undefined1 auVar1344 [16];
  undefined1 auVar1352 [16];
  undefined1 auVar1360 [16];
  undefined1 auVar1368 [16];
  undefined1 auVar1376 [16];
  undefined1 auVar1384 [16];
  undefined1 auVar1392 [16];
  undefined1 auVar1400 [16];
  undefined1 auVar1408 [16];
  undefined1 auVar1416 [16];
  undefined1 auVar1424 [16];
  undefined1 auVar1432 [16];
  undefined1 auVar1440 [16];
  undefined1 auVar1448 [16];
  undefined1 auVar1456 [16];
  undefined1 auVar1464 [16];
  undefined1 auVar1472 [16];
  undefined1 auVar1480 [16];
  undefined1 auVar1488 [16];
  undefined1 auVar1496 [16];
  undefined1 auVar1504 [16];
  undefined1 auVar1512 [16];
  undefined1 auVar1520 [16];
  undefined1 auVar1528 [16];
  undefined1 auVar1536 [16];
  undefined1 auVar1544 [16];
  undefined1 auVar1552 [16];
  undefined1 auVar1560 [16];
  undefined1 auVar1568 [16];
  undefined1 auVar1576 [16];
  undefined1 auVar1584 [16];
  undefined1 auVar1185 [16];
  undefined1 auVar1193 [16];
  undefined1 auVar1201 [16];
  undefined1 auVar1209 [16];
  undefined1 auVar1217 [16];
  undefined1 auVar1225 [16];
  undefined1 auVar1233 [16];
  undefined1 auVar1241 [16];
  undefined1 auVar1249 [16];
  undefined1 auVar1257 [16];
  undefined1 auVar1265 [16];
  undefined1 auVar1273 [16];
  undefined1 auVar1281 [16];
  undefined1 auVar1289 [16];
  undefined1 auVar1297 [16];
  undefined1 auVar1305 [16];
  undefined1 auVar1313 [16];
  undefined1 auVar1321 [16];
  undefined1 auVar1329 [16];
  undefined1 auVar1337 [16];
  undefined1 auVar1345 [16];
  undefined1 auVar1353 [16];
  undefined1 auVar1361 [16];
  undefined1 auVar1369 [16];
  undefined1 auVar1377 [16];
  undefined1 auVar1385 [16];
  undefined1 auVar1393 [16];
  undefined1 auVar1401 [16];
  undefined1 auVar1409 [16];
  undefined1 auVar1417 [16];
  undefined1 auVar1425 [16];
  undefined1 auVar1433 [16];
  undefined1 auVar1441 [16];
  undefined1 auVar1449 [16];
  undefined1 auVar1457 [16];
  undefined1 auVar1465 [16];
  undefined1 auVar1473 [16];
  undefined1 auVar1481 [16];
  undefined1 auVar1489 [16];
  undefined1 auVar1497 [16];
  undefined1 auVar1505 [16];
  undefined1 auVar1513 [16];
  undefined1 auVar1521 [16];
  undefined1 auVar1529 [16];
  undefined1 auVar1537 [16];
  undefined1 auVar1545 [16];
  undefined1 auVar1553 [16];
  undefined1 auVar1561 [16];
  undefined1 auVar1569 [16];
  undefined1 auVar1577 [16];
  undefined1 auVar1585 [16];
  undefined1 auVar1186 [16];
  undefined1 auVar1194 [16];
  undefined1 auVar1202 [16];
  undefined1 auVar1210 [16];
  undefined1 auVar1218 [16];
  undefined1 auVar1226 [16];
  undefined1 auVar1234 [16];
  undefined1 auVar1242 [16];
  undefined1 auVar1250 [16];
  undefined1 auVar1258 [16];
  undefined1 auVar1266 [16];
  undefined1 auVar1274 [16];
  undefined1 auVar1282 [16];
  undefined1 auVar1290 [16];
  undefined1 auVar1298 [16];
  undefined1 auVar1306 [16];
  undefined1 auVar1314 [16];
  undefined1 auVar1322 [16];
  undefined1 auVar1330 [16];
  undefined1 auVar1338 [16];
  undefined1 auVar1346 [16];
  undefined1 auVar1354 [16];
  undefined1 auVar1362 [16];
  undefined1 auVar1370 [16];
  undefined1 auVar1378 [16];
  undefined1 auVar1386 [16];
  undefined1 auVar1394 [16];
  undefined1 auVar1402 [16];
  undefined1 auVar1410 [16];
  undefined1 auVar1418 [16];
  undefined1 auVar1426 [16];
  undefined1 auVar1434 [16];
  undefined1 auVar1442 [16];
  undefined1 auVar1450 [16];
  undefined1 auVar1458 [16];
  undefined1 auVar1466 [16];
  undefined1 auVar1474 [16];
  undefined1 auVar1482 [16];
  undefined1 auVar1490 [16];
  undefined1 auVar1498 [16];
  undefined1 auVar1506 [16];
  undefined1 auVar1514 [16];
  undefined1 auVar1522 [16];
  undefined1 auVar1530 [16];
  undefined1 auVar1538 [16];
  undefined1 auVar1546 [16];
  undefined1 auVar1554 [16];
  undefined1 auVar1562 [16];
  undefined1 auVar1570 [16];
  undefined1 auVar1578 [16];
  undefined1 auVar1586 [16];
  undefined1 auVar1187 [16];
  undefined1 auVar1195 [16];
  undefined1 auVar1203 [16];
  undefined1 auVar1211 [16];
  undefined1 auVar1219 [16];
  undefined1 auVar1227 [16];
  undefined1 auVar1235 [16];
  undefined1 auVar1243 [16];
  undefined1 auVar1251 [16];
  undefined1 auVar1259 [16];
  undefined1 auVar1267 [16];
  undefined1 auVar1275 [16];
  undefined1 auVar1283 [16];
  undefined1 auVar1291 [16];
  undefined1 auVar1299 [16];
  undefined1 auVar1307 [16];
  undefined1 auVar1315 [16];
  undefined1 auVar1323 [16];
  undefined1 auVar1331 [16];
  undefined1 auVar1339 [16];
  undefined1 auVar1347 [16];
  undefined1 auVar1355 [16];
  undefined1 auVar1363 [16];
  undefined1 auVar1371 [16];
  undefined1 auVar1379 [16];
  undefined1 auVar1387 [16];
  undefined1 auVar1395 [16];
  undefined1 auVar1403 [16];
  undefined1 auVar1411 [16];
  undefined1 auVar1419 [16];
  undefined1 auVar1427 [16];
  undefined1 auVar1435 [16];
  undefined1 auVar1443 [16];
  undefined1 auVar1451 [16];
  undefined1 auVar1459 [16];
  undefined1 auVar1467 [16];
  undefined1 auVar1475 [16];
  undefined1 auVar1483 [16];
  undefined1 auVar1491 [16];
  undefined1 auVar1499 [16];
  undefined1 auVar1507 [16];
  undefined1 auVar1515 [16];
  undefined1 auVar1523 [16];
  undefined1 auVar1531 [16];
  undefined1 auVar1539 [16];
  undefined1 auVar1547 [16];
  undefined1 auVar1555 [16];
  undefined1 auVar1563 [16];
  undefined1 auVar1571 [16];
  undefined1 auVar1579 [16];
  undefined1 auVar1587 [16];
  undefined1 auVar1188 [16];
  undefined1 auVar1196 [16];
  undefined1 auVar1204 [16];
  undefined1 auVar1212 [16];
  undefined1 auVar1220 [16];
  undefined1 auVar1228 [16];
  undefined1 auVar1236 [16];
  undefined1 auVar1244 [16];
  undefined1 auVar1252 [16];
  undefined1 auVar1260 [16];
  undefined1 auVar1268 [16];
  undefined1 auVar1276 [16];
  undefined1 auVar1284 [16];
  undefined1 auVar1292 [16];
  undefined1 auVar1300 [16];
  undefined1 auVar1308 [16];
  undefined1 auVar1316 [16];
  undefined1 auVar1324 [16];
  undefined1 auVar1332 [16];
  undefined1 auVar1340 [16];
  undefined1 auVar1348 [16];
  undefined1 auVar1356 [16];
  undefined1 auVar1364 [16];
  undefined1 auVar1372 [16];
  undefined1 auVar1380 [16];
  undefined1 auVar1388 [16];
  undefined1 auVar1396 [16];
  undefined1 auVar1404 [16];
  undefined1 auVar1412 [16];
  undefined1 auVar1420 [16];
  undefined1 auVar1428 [16];
  undefined1 auVar1436 [16];
  undefined1 auVar1444 [16];
  undefined1 auVar1452 [16];
  undefined1 auVar1460 [16];
  undefined1 auVar1468 [16];
  undefined1 auVar1476 [16];
  undefined1 auVar1484 [16];
  undefined1 auVar1492 [16];
  undefined1 auVar1500 [16];
  undefined1 auVar1508 [16];
  undefined1 auVar1516 [16];
  undefined1 auVar1524 [16];
  undefined1 auVar1532 [16];
  undefined1 auVar1540 [16];
  undefined1 auVar1548 [16];
  undefined1 auVar1556 [16];
  undefined1 auVar1564 [16];
  undefined1 auVar1572 [16];
  undefined1 auVar1580 [16];
  undefined1 auVar1588 [16];
  undefined1 auVar1189 [16];
  undefined1 auVar1197 [16];
  undefined1 auVar1205 [16];
  undefined1 auVar1213 [16];
  undefined1 auVar1221 [16];
  undefined1 auVar1229 [16];
  undefined1 auVar1237 [16];
  undefined1 auVar1245 [16];
  undefined1 auVar1253 [16];
  undefined1 auVar1261 [16];
  undefined1 auVar1269 [16];
  undefined1 auVar1277 [16];
  undefined1 auVar1285 [16];
  undefined1 auVar1293 [16];
  undefined1 auVar1301 [16];
  undefined1 auVar1309 [16];
  undefined1 auVar1317 [16];
  undefined1 auVar1325 [16];
  undefined1 auVar1333 [16];
  undefined1 auVar1341 [16];
  undefined1 auVar1349 [16];
  undefined1 auVar1357 [16];
  undefined1 auVar1365 [16];
  undefined1 auVar1373 [16];
  undefined1 auVar1381 [16];
  undefined1 auVar1389 [16];
  undefined1 auVar1397 [16];
  undefined1 auVar1405 [16];
  undefined1 auVar1413 [16];
  undefined1 auVar1421 [16];
  undefined1 auVar1429 [16];
  undefined1 auVar1437 [16];
  undefined1 auVar1445 [16];
  undefined1 auVar1453 [16];
  undefined1 auVar1461 [16];
  undefined1 auVar1469 [16];
  undefined1 auVar1477 [16];
  undefined1 auVar1485 [16];
  undefined1 auVar1493 [16];
  undefined1 auVar1501 [16];
  undefined1 auVar1509 [16];
  undefined1 auVar1517 [16];
  undefined1 auVar1525 [16];
  undefined1 auVar1533 [16];
  undefined1 auVar1541 [16];
  undefined1 auVar1549 [16];
  undefined1 auVar1557 [16];
  undefined1 auVar1565 [16];
  undefined1 auVar1573 [16];
  undefined1 auVar1581 [16];
  undefined1 auVar1589 [16];
  undefined1 auVar1597 [16];
  undefined1 auVar1605 [16];
  undefined1 auVar1613 [16];
  undefined1 auVar1621 [16];
  undefined1 auVar1629 [16];
  undefined1 auVar1637 [16];
  undefined1 auVar1645 [16];
  undefined1 auVar1653 [16];
  undefined1 auVar1661 [16];
  undefined1 auVar1669 [16];
  undefined1 auVar1677 [16];
  undefined1 auVar1685 [16];
  undefined1 auVar1693 [16];
  undefined1 auVar1701 [16];
  undefined1 auVar1709 [16];
  undefined1 auVar1717 [16];
  undefined1 auVar1725 [16];
  undefined1 auVar1733 [16];
  undefined1 auVar1741 [16];
  undefined1 auVar1749 [16];
  undefined1 auVar1757 [16];
  undefined1 auVar1765 [16];
  undefined1 auVar1773 [16];
  undefined1 auVar1781 [16];
  undefined1 auVar1789 [16];
  undefined1 auVar1797 [16];
  undefined1 auVar1805 [16];
  undefined1 auVar1813 [16];
  undefined1 auVar1598 [16];
  undefined1 auVar1606 [16];
  undefined1 auVar1614 [16];
  undefined1 auVar1622 [16];
  undefined1 auVar1630 [16];
  undefined1 auVar1638 [16];
  undefined1 auVar1646 [16];
  undefined1 auVar1654 [16];
  undefined1 auVar1662 [16];
  undefined1 auVar1670 [16];
  undefined1 auVar1678 [16];
  undefined1 auVar1686 [16];
  undefined1 auVar1694 [16];
  undefined1 auVar1702 [16];
  undefined1 auVar1710 [16];
  undefined1 auVar1718 [16];
  undefined1 auVar1726 [16];
  undefined1 auVar1734 [16];
  undefined1 auVar1742 [16];
  undefined1 auVar1750 [16];
  undefined1 auVar1758 [16];
  undefined1 auVar1766 [16];
  undefined1 auVar1774 [16];
  undefined1 auVar1782 [16];
  undefined1 auVar1790 [16];
  undefined1 auVar1798 [16];
  undefined1 auVar1806 [16];
  undefined1 auVar1814 [16];
  undefined1 auVar1599 [16];
  undefined1 auVar1607 [16];
  undefined1 auVar1615 [16];
  undefined1 auVar1623 [16];
  undefined1 auVar1631 [16];
  undefined1 auVar1639 [16];
  undefined1 auVar1647 [16];
  undefined1 auVar1655 [16];
  undefined1 auVar1663 [16];
  undefined1 auVar1671 [16];
  undefined1 auVar1679 [16];
  undefined1 auVar1687 [16];
  undefined1 auVar1695 [16];
  undefined1 auVar1703 [16];
  undefined1 auVar1711 [16];
  undefined1 auVar1719 [16];
  undefined1 auVar1727 [16];
  undefined1 auVar1735 [16];
  undefined1 auVar1743 [16];
  undefined1 auVar1751 [16];
  undefined1 auVar1759 [16];
  undefined1 auVar1767 [16];
  undefined1 auVar1775 [16];
  undefined1 auVar1783 [16];
  undefined1 auVar1791 [16];
  undefined1 auVar1799 [16];
  undefined1 auVar1807 [16];
  undefined1 auVar1815 [16];
  undefined1 auVar1600 [16];
  undefined1 auVar1608 [16];
  undefined1 auVar1616 [16];
  undefined1 auVar1624 [16];
  undefined1 auVar1632 [16];
  undefined1 auVar1640 [16];
  undefined1 auVar1648 [16];
  undefined1 auVar1656 [16];
  undefined1 auVar1664 [16];
  undefined1 auVar1672 [16];
  undefined1 auVar1680 [16];
  undefined1 auVar1688 [16];
  undefined1 auVar1696 [16];
  undefined1 auVar1704 [16];
  undefined1 auVar1712 [16];
  undefined1 auVar1720 [16];
  undefined1 auVar1728 [16];
  undefined1 auVar1736 [16];
  undefined1 auVar1744 [16];
  undefined1 auVar1752 [16];
  undefined1 auVar1760 [16];
  undefined1 auVar1768 [16];
  undefined1 auVar1776 [16];
  undefined1 auVar1784 [16];
  undefined1 auVar1792 [16];
  undefined1 auVar1800 [16];
  undefined1 auVar1808 [16];
  undefined1 auVar1816 [16];
  undefined1 auVar1601 [16];
  undefined1 auVar1609 [16];
  undefined1 auVar1617 [16];
  undefined1 auVar1625 [16];
  undefined1 auVar1633 [16];
  undefined1 auVar1641 [16];
  undefined1 auVar1649 [16];
  undefined1 auVar1657 [16];
  undefined1 auVar1665 [16];
  undefined1 auVar1673 [16];
  undefined1 auVar1681 [16];
  undefined1 auVar1689 [16];
  undefined1 auVar1697 [16];
  undefined1 auVar1705 [16];
  undefined1 auVar1713 [16];
  undefined1 auVar1721 [16];
  undefined1 auVar1729 [16];
  undefined1 auVar1737 [16];
  undefined1 auVar1745 [16];
  undefined1 auVar1753 [16];
  undefined1 auVar1761 [16];
  undefined1 auVar1769 [16];
  undefined1 auVar1777 [16];
  undefined1 auVar1785 [16];
  undefined1 auVar1793 [16];
  undefined1 auVar1801 [16];
  undefined1 auVar1809 [16];
  undefined1 auVar1817 [16];
  undefined1 auVar1602 [16];
  undefined1 auVar1610 [16];
  undefined1 auVar1618 [16];
  undefined1 auVar1626 [16];
  undefined1 auVar1634 [16];
  undefined1 auVar1642 [16];
  undefined1 auVar1650 [16];
  undefined1 auVar1658 [16];
  undefined1 auVar1666 [16];
  undefined1 auVar1674 [16];
  undefined1 auVar1682 [16];
  undefined1 auVar1690 [16];
  undefined1 auVar1698 [16];
  undefined1 auVar1706 [16];
  undefined1 auVar1714 [16];
  undefined1 auVar1722 [16];
  undefined1 auVar1730 [16];
  undefined1 auVar1738 [16];
  undefined1 auVar1746 [16];
  undefined1 auVar1754 [16];
  undefined1 auVar1762 [16];
  undefined1 auVar1770 [16];
  undefined1 auVar1778 [16];
  undefined1 auVar1786 [16];
  undefined1 auVar1794 [16];
  undefined1 auVar1802 [16];
  undefined1 auVar1810 [16];
  undefined1 auVar1818 [16];
  undefined1 auVar1603 [16];
  undefined1 auVar1611 [16];
  undefined1 auVar1619 [16];
  undefined1 auVar1627 [16];
  undefined1 auVar1635 [16];
  undefined1 auVar1643 [16];
  undefined1 auVar1651 [16];
  undefined1 auVar1659 [16];
  undefined1 auVar1667 [16];
  undefined1 auVar1675 [16];
  undefined1 auVar1683 [16];
  undefined1 auVar1691 [16];
  undefined1 auVar1699 [16];
  undefined1 auVar1707 [16];
  undefined1 auVar1715 [16];
  undefined1 auVar1723 [16];
  undefined1 auVar1731 [16];
  undefined1 auVar1739 [16];
  undefined1 auVar1747 [16];
  undefined1 auVar1755 [16];
  undefined1 auVar1763 [16];
  undefined1 auVar1771 [16];
  undefined1 auVar1779 [16];
  undefined1 auVar1787 [16];
  undefined1 auVar1795 [16];
  undefined1 auVar1803 [16];
  undefined1 auVar1811 [16];
  undefined1 auVar1819 [16];
  undefined1 uVar1820;
  undefined1 auVar1828 [16];
  undefined1 auVar1836 [16];
  undefined1 auVar1844 [16];
  undefined1 auVar1829 [16];
  undefined1 auVar1837 [16];
  undefined1 auVar1845 [16];
  undefined1 auVar1830 [16];
  undefined1 auVar1838 [16];
  undefined1 auVar1846 [16];
  undefined1 auVar1831 [16];
  undefined1 auVar1839 [16];
  undefined1 auVar1847 [16];
  undefined1 auVar1832 [16];
  undefined1 auVar1840 [16];
  undefined1 auVar1848 [16];
  undefined1 auVar1833 [16];
  undefined1 auVar1841 [16];
  undefined1 auVar1849 [16];
  undefined1 auVar1834 [16];
  undefined1 auVar1842 [16];
  undefined1 auVar1850 [16];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uchar * out@[???] */
  if (0 < height >> 1) {
    local_2c = 0;
    iVar943 = width * 4;
    uVar944 = (iVar943 - 1U >> 3) + 1;
    iVar945 = uVar944 * 8;
    pbVar950 = in;
    do {
      pbVar952 = pbVar950;
      pbVar946 = in;
      if (0 < iVar943) {
        pbVar954 = in + iVar943;
        pbVar946 = in + iVar945;
        pbVar952 = pbVar950 + uVar944 * 4;
        uVar947 = iVar943 - 1U >> 7;
        if ((uVar947 == 0) ||
           (((((((((uVar944 < 0x10 || pbVar950 <= pbVar946 && in <= pbVar952) ||
                  pbVar950 <= pbVar954 + iVar945 && pbVar954 <= pbVar952) ||
                 pbVar950 <= pbVar954 + 4 + iVar945 && pbVar954 + 4 <= pbVar952) ||
                pbVar954 + 1 <= pbVar952 && pbVar950 <= pbVar954 + 1 + iVar945) ||
               pbVar954 + 5 <= pbVar952 && pbVar950 <= pbVar954 + 5 + iVar945) ||
              pbVar954 + 2 <= pbVar952 && pbVar950 <= pbVar954 + 2 + iVar945) ||
             pbVar954 + 6 <= pbVar952 && pbVar950 <= pbVar954 + 6 + iVar945) ||
            pbVar954 + 3 <= pbVar952 && pbVar950 <= pbVar954 + 3 + iVar945) ||
            pbVar954 + 7 <= pbVar952 && pbVar950 <= pbVar954 + 7 + iVar945)) {
          iVar948 = 0;
        }
        else {
          iVar948 = 0;
          local_48 = 0;
          pbVar949 = pbVar954;
          pbVar951 = pbVar954;
          pbVar953 = pbVar954;
          pbVar955 = pbVar954;
          pbVar956 = pbVar954;
          local_7c = pbVar954;
          local_78 = pbVar954;
          do {
            pbVar1 = in + iVar948 * 2;
            bVar173 = pbVar1[5];
            bVar174 = pbVar1[9];
            bVar175 = pbVar1[0xb];
            bVar176 = pbVar1[0xd];
            bVar177 = pbVar1[0xf];
            pbVar2 = in + iVar948 * 2 + 0x20;
            bVar178 = pbVar2[5];
            bVar179 = pbVar2[7];
            bVar180 = pbVar2[9];
            bVar181 = pbVar2[0xb];
            bVar182 = pbVar2[0xd];
            auVar836 = *(undefined1 (*) [12])(in + iVar948 * 2 + 0x10);
            uVar204 = *(undefined4 *)((undefined1 (*) [12])(in + iVar948 * 2 + 0x10))[1];
            auVar837 = *(undefined1 (*) [12])(in + iVar948 * 2 + 0x30);
            uVar205 = *(undefined4 *)((undefined1 (*) [12])(in + iVar948 * 2 + 0x30))[1];
            auVar838 = *(undefined1 (*) [12])(in + iVar948 * 2 + 0x40);
            uVar206 = *(undefined4 *)((undefined1 (*) [12])(in + iVar948 * 2 + 0x40))[1];
            auVar839 = *(undefined1 (*) [12])(in + iVar948 * 2 + 0x50);
            uVar207 = *(undefined4 *)((undefined1 (*) [12])(in + iVar948 * 2 + 0x50))[1];
            auVar840 = *(undefined1 (*) [12])(in + iVar948 * 2 + 0x60);
            uVar208 = *(uint *)((undefined1 (*) [12])(in + iVar948 * 2 + 0x60))[1];
            auVar841 = *(undefined1 (*) [12])(in + iVar948 * 2 + 0x70);
            uVar209 = *(uint *)((undefined1 (*) [12])(in + iVar948 * 2 + 0x70))[1];
            local_bc = auVar836[0];
            uStack_ba = auVar836[2];
            uStack_b9 = auVar836[3];
            uStack_b8 = auVar836[4];
            uStack_b7 = auVar836[5];
            uStack_b6 = auVar836[6];
            uStack_b5 = auVar836[7];
            uStack_b4._0_1_ = auVar836[8];
            uStack_b4._1_1_ = auVar836[9];
            uStack_b2._0_1_ = auVar836[10];
            uStack_b2._1_1_ = auVar836[0xb];
            uVar1820 = uStack_b2._1_1_;
            uStack_b0 = (undefined1)uVar204;
            uStack_af = (undefined1)((uint)uVar204 >> 8);
            uStack_ae = (undefined1)((uint)uVar204 >> 0x10);
            uStack_ad = (undefined1)((uint)uVar204 >> 0x18);
            uStack_bb = auVar836[1];
            uStack_104 = auVar837[8];
            uStack_103 = auVar837[9];
            uStack_102 = auVar837[10];
            uStack_101 = auVar837[0xb];
            uStack_100 = (undefined1)uVar205;
            uStack_ff = (undefined1)((uint)uVar205 >> 8);
            uStack_fe = (undefined1)((uint)uVar205 >> 0x10);
            uStack_fd = (undefined1)((uint)uVar205 >> 0x18);
            local_10c = auVar837[0];
            uStack_10a = auVar837[2];
            uStack_109 = auVar837[3];
            uStack_108 = auVar837[4];
            uStack_107 = auVar837[5];
            uStack_106 = auVar837[6];
            uStack_105 = auVar837[7];
            uStack_10b = auVar837[1];
            local_fc = auVar838[0];
            bStack_fa = auVar838[2];
            bStack_f9 = auVar838[3];
            bStack_f8 = auVar838[4];
            bStack_f7 = auVar838[5];
            bStack_f6 = auVar838[6];
            bStack_f5 = auVar838[7];
            local_dc = auVar839[0];
            bStack_da = auVar839[2];
            bStack_d9 = auVar839[3];
            bStack_d8 = auVar839[4];
            bStack_d7 = auVar839[5];
            bStack_d6 = auVar839[6];
            bStack_d5 = auVar839[7];
            uStack_f4 = auVar838[8];
            uStack_f3 = auVar838[9];
            uStack_f2 = auVar838[10];
            uStack_f1 = auVar838[0xb];
            uStack_f0 = (undefined1)uVar206;
            uStack_ef = (undefined1)((uint)uVar206 >> 8);
            uStack_ee = (undefined1)((uint)uVar206 >> 0x10);
            uStack_ed = (undefined1)((uint)uVar206 >> 0x18);
            uStack_d4._0_1_ = auVar839[8];
            uStack_d4._1_1_ = auVar839[9];
            uStack_d2._0_1_ = auVar839[10];
            uStack_d2._1_1_ = auVar839[0xb];
            uVar942 = uStack_d2._1_1_;
            uStack_d0 = (undefined1)uVar207;
            uStack_cf = (undefined1)((uint)uVar207 >> 8);
            uStack_ce = (undefined1)((uint)uVar207 >> 0x10);
            uStack_cd = (undefined1)((uint)uVar207 >> 0x18);
            bStack_fb = auVar838[1];
            bStack_db = auVar839[1];
            uStack_e4._0_1_ = auVar840[8];
            uStack_e4._1_1_ = auVar840[9];
            uStack_e2._0_1_ = auVar840[10];
            bVar940 = (byte)uStack_e2;
            uStack_e2._1_1_ = auVar840[0xb];
            bVar941 = uStack_e2._1_1_;
            uStack_e0 = (undefined1)uVar208;
            bStack_df = (byte)(uVar208 >> 8);
            bStack_de = (byte)(uVar208 >> 0x10);
            local_ec = auVar840[0];
            bStack_ea = auVar840[2];
            bStack_e9 = auVar840[3];
            bStack_e8 = auVar840[4];
            bStack_e7 = auVar840[5];
            bStack_e6 = auVar840[6];
            bStack_e5 = auVar840[7];
            bStack_c4 = auVar841[8];
            bStack_c3 = auVar841[9];
            bStack_c2 = auVar841[10];
            bStack_c1 = auVar841[0xb];
            local_cc = auVar841[0];
            bStack_ca = auVar841[2];
            bStack_c9 = auVar841[3];
            bStack_c8 = auVar841[4];
            bStack_c7 = auVar841[5];
            bStack_c6 = auVar841[6];
            bStack_c5 = auVar841[7];
            bStack_eb = auVar840[1];
            bStack_cb = auVar841[1];
            auVar216._1_8_ =
                 (longlong)
                 (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(pbVar2[0xf],bVar177
                                                                                ),bVar182),bVar176),
                                                      bVar181),bVar175),bVar180),
                           CONCAT11(bVar174,bVar177)) >> 8);
            auVar216[0] = bVar179;
            auVar216._9_7_ = 0;
            auVar215._10_6_ = 0;
            auVar215._0_10_ = SUB1610(auVar216 << 0x38,6);
            auVar214._11_5_ = 0;
            auVar214._0_11_ = SUB1611(auVar215 << 0x30,5);
            auVar213._12_4_ = 0;
            auVar213._0_12_ = SUB1612(auVar214 << 0x28,4);
            auVar212._13_3_ = 0;
            auVar212._0_13_ = SUB1613(auVar213 << 0x20,3);
            auVar1181._14_2_ = 0;
            auVar1181._0_14_ = SUB1614(auVar212 << 0x18,2);
            auVar1181 = auVar1181 << 0x10;
            auVar1189._0_14_ = auVar1181._0_14_;
            auVar1189[0xe] = bVar179;
            auVar1189[0xf] = uStack_105;
            auVar1188._14_2_ = auVar1189._14_2_;
            auVar1188._0_13_ = auVar1181._0_13_;
            auVar1188[0xd] = uStack_b5;
            auVar1187._13_3_ = auVar1188._13_3_;
            auVar1187._0_12_ = auVar1181._0_12_;
            auVar1187[0xc] = pbVar1[7];
            auVar1186._12_4_ = auVar1187._12_4_;
            auVar1186._0_11_ = auVar1181._0_11_;
            auVar1186[0xb] = uStack_107;
            auVar1185._11_5_ = auVar1186._11_5_;
            auVar1185._0_10_ = auVar1181._0_10_;
            auVar1185[10] = bVar178;
            auVar1184._10_6_ = auVar1185._10_6_;
            auVar1184._0_9_ = auVar1181._0_9_;
            auVar1184[9] = uStack_b7;
            auVar1183._9_7_ = auVar1184._9_7_;
            auVar1183._0_8_ = auVar1181._0_8_;
            auVar1183[8] = bVar173;
            auVar221._1_8_ = auVar1183._8_8_;
            auVar221[0] = uStack_109;
            auVar221._9_7_ = 0;
            auVar220._10_6_ = 0;
            auVar220._0_10_ = SUB1610(auVar221 << 0x38,6);
            auVar219._11_5_ = 0;
            auVar219._0_11_ = SUB1611(auVar220 << 0x30,5);
            auVar218._12_4_ = 0;
            auVar218._0_12_ = SUB1612(auVar219 << 0x28,4);
            auVar217._13_3_ = 0;
            auVar217._0_13_ = SUB1613(auVar218 << 0x20,3);
            auVar1182._14_2_ = 0;
            auVar1182._0_14_ = SUB1614(auVar217 << 0x18,2);
            auVar1182 = auVar1182 << 0x10;
            auVar1197._0_14_ = auVar1182._0_14_;
            auVar1197[0xe] = uStack_109;
            auVar1197[0xf] = uStack_101;
            auVar1196._14_2_ = auVar1197._14_2_;
            auVar1196._0_13_ = auVar1182._0_13_;
            auVar1196[0xd] = bVar181;
            auVar1195._13_3_ = auVar1196._13_3_;
            auVar1195._0_12_ = auVar1182._0_12_;
            auVar1195[0xc] = pbVar2[3];
            auVar1194._12_4_ = auVar1195._12_4_;
            auVar1194._0_11_ = auVar1182._0_11_;
            auVar1194[0xb] = uStack_b2._1_1_;
            auVar1193._11_5_ = auVar1194._11_5_;
            auVar1193._0_10_ = auVar1182._0_10_;
            auVar1193[10] = uStack_b9;
            auVar1192._10_6_ = auVar1193._10_6_;
            auVar1192._0_9_ = auVar1182._0_9_;
            auVar1192[9] = bVar175;
            auVar1191._9_7_ = auVar1192._9_7_;
            auVar1191._0_8_ = auVar1182._0_8_;
            auVar1191[8] = pbVar1[3];
            auVar226._1_8_ = auVar1191._8_8_;
            auVar226[0] = uStack_103;
            auVar226._9_7_ = 0;
            auVar225._10_6_ = 0;
            auVar225._0_10_ = SUB1610(auVar226 << 0x38,6);
            auVar224._11_5_ = 0;
            auVar224._0_11_ = SUB1611(auVar225 << 0x30,5);
            auVar223._12_4_ = 0;
            auVar223._0_12_ = SUB1612(auVar224 << 0x28,4);
            auVar222._13_3_ = 0;
            auVar222._0_13_ = SUB1613(auVar223 << 0x20,3);
            auVar1190._14_2_ = 0;
            auVar1190._0_14_ = SUB1614(auVar222 << 0x18,2);
            auVar1190 = auVar1190 << 0x10;
            auVar1205._0_14_ = auVar1190._0_14_;
            auVar1205[0xe] = uStack_103;
            auVar1205[0xf] = uStack_ff;
            auVar1204._14_2_ = auVar1205._14_2_;
            auVar1204._0_13_ = auVar1190._0_13_;
            auVar1204[0xd] = uStack_107;
            auVar1203._13_3_ = auVar1204._13_3_;
            auVar1203._0_12_ = auVar1190._0_12_;
            auVar1203[0xc] = uStack_10b;
            auVar1202._12_4_ = auVar1203._12_4_;
            auVar1202._0_11_ = auVar1190._0_11_;
            auVar1202[0xb] = bVar182;
            auVar1201._11_5_ = auVar1202._11_5_;
            auVar1201._0_10_ = auVar1190._0_10_;
            auVar1201[10] = bVar180;
            auVar1200._10_6_ = auVar1201._10_6_;
            auVar1200._0_9_ = auVar1190._0_9_;
            auVar1200[9] = bVar178;
            auVar1199._9_7_ = auVar1200._9_7_;
            auVar1199._0_8_ = auVar1190._0_8_;
            auVar1199[8] = pbVar2[1];
            auVar231._1_8_ = auVar1199._8_8_;
            auVar231[0] = uStack_af;
            auVar231._9_7_ = 0;
            auVar230._10_6_ = 0;
            auVar230._0_10_ = SUB1610(auVar231 << 0x38,6);
            auVar229._11_5_ = 0;
            auVar229._0_11_ = SUB1611(auVar230 << 0x30,5);
            auVar228._12_4_ = 0;
            auVar228._0_12_ = SUB1612(auVar229 << 0x28,4);
            auVar227._13_3_ = 0;
            auVar227._0_13_ = SUB1613(auVar228 << 0x20,3);
            auVar1198._14_2_ = 0;
            auVar1198._0_14_ = SUB1614(auVar227 << 0x18,2);
            auVar1198 = auVar1198 << 0x10;
            auVar236._1_8_ =
                 (longlong)
                 (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(uStack_d0,uStack_b0
                                                                                ),
                                                                        (undefined1)uStack_d4),
                                                               (byte)uStack_b4),bStack_d8),uStack_b8
                                            ),local_dc),CONCAT11(local_bc,uStack_b0)) >> 8);
            auVar236[0] = uStack_f0;
            auVar236._9_7_ = 0;
            auVar235._10_6_ = 0;
            auVar235._0_10_ = SUB1610(auVar236 << 0x38,6);
            auVar234._11_5_ = 0;
            auVar234._0_11_ = SUB1611(auVar235 << 0x30,5);
            auVar233._12_4_ = 0;
            auVar233._0_12_ = SUB1612(auVar234 << 0x28,4);
            auVar232._13_3_ = 0;
            auVar232._0_13_ = SUB1613(auVar233 << 0x20,3);
            auVar1826._14_2_ = 0;
            auVar1826._0_14_ = SUB1614(auVar232 << 0x18,2);
            auVar1826 = auVar1826 << 0x10;
            auVar1834._0_14_ = auVar1826._0_14_;
            auVar1834[0xe] = uStack_f0;
            auVar1834[0xf] = uStack_e0;
            auVar1833._14_2_ = auVar1834._14_2_;
            auVar1833._0_13_ = auVar1826._0_13_;
            auVar1833[0xd] = pbVar2[0xc];
            auVar1832._13_3_ = auVar1833._13_3_;
            auVar1832._0_12_ = auVar1826._0_12_;
            auVar1832[0xc] = pbVar1[0xc];
            auVar1831._12_4_ = auVar1832._12_4_;
            auVar1831._0_11_ = auVar1826._0_11_;
            auVar1831[0xb] = (byte)uStack_e4;
            auVar1830._11_5_ = auVar1831._11_5_;
            auVar1830._0_10_ = auVar1826._0_10_;
            auVar1830[10] = uStack_f4;
            auVar1829._10_6_ = auVar1830._10_6_;
            auVar1829._0_9_ = auVar1826._0_9_;
            auVar1829[9] = pbVar2[8];
            auVar1828._9_7_ = auVar1829._9_7_;
            auVar1828._0_8_ = auVar1826._0_8_;
            auVar1828[8] = pbVar1[8];
            auVar241._1_8_ = auVar1828._8_8_;
            auVar241[0] = bStack_e8;
            auVar241._9_7_ = 0;
            auVar240._10_6_ = 0;
            auVar240._0_10_ = SUB1610(auVar241 << 0x38,6);
            auVar239._11_5_ = 0;
            auVar239._0_11_ = SUB1611(auVar240 << 0x30,5);
            auVar238._12_4_ = 0;
            auVar238._0_12_ = SUB1612(auVar239 << 0x28,4);
            auVar237._13_3_ = 0;
            auVar237._0_13_ = SUB1613(auVar238 << 0x20,3);
            auVar1827._14_2_ = 0;
            auVar1827._0_14_ = SUB1614(auVar237 << 0x18,2);
            auVar1827 = auVar1827 << 0x10;
            auVar1842._0_14_ = auVar1827._0_14_;
            auVar1842[0xe] = bStack_e8;
            auVar1842[0xf] = bStack_c8;
            auVar1841._14_2_ = auVar1842._14_2_;
            auVar1841._0_13_ = auVar1827._0_13_;
            auVar1841[0xd] = bStack_d8;
            auVar1840._13_3_ = auVar1841._13_3_;
            auVar1840._0_12_ = auVar1827._0_12_;
            auVar1840[0xc] = bStack_f8;
            auVar1839._12_4_ = auVar1840._12_4_;
            auVar1839._0_11_ = auVar1827._0_11_;
            auVar1839[0xb] = uStack_108;
            auVar1838._11_5_ = auVar1839._11_5_;
            auVar1838._0_10_ = auVar1827._0_10_;
            auVar1838[10] = pbVar2[4];
            auVar1837._10_6_ = auVar1838._10_6_;
            auVar1837._0_9_ = auVar1827._0_9_;
            auVar1837[9] = uStack_b8;
            auVar1836._9_7_ = auVar1837._9_7_;
            auVar1836._0_8_ = auVar1827._0_8_;
            auVar1836[8] = pbVar1[4];
            auVar246._1_8_ = auVar1836._8_8_;
            auVar246[0] = local_cc;
            auVar246._9_7_ = 0;
            auVar245._10_6_ = 0;
            auVar245._0_10_ = SUB1610(auVar246 << 0x38,6);
            auVar244._11_5_ = 0;
            auVar244._0_11_ = SUB1611(auVar245 << 0x30,5);
            auVar243._12_4_ = 0;
            auVar243._0_12_ = SUB1612(auVar244 << 0x28,4);
            auVar242._13_3_ = 0;
            auVar242._0_13_ = SUB1613(auVar243 << 0x20,3);
            auVar1835._14_2_ = 0;
            auVar1835._0_14_ = SUB1614(auVar242 << 0x18,2);
            auVar1835 = auVar1835 << 0x10;
            auVar1850._0_14_ = auVar1835._0_14_;
            auVar1850[0xe] = local_cc;
            auVar1850[0xf] = bStack_c4;
            auVar1849._14_2_ = auVar1850._14_2_;
            auVar1849._0_13_ = auVar1835._0_13_;
            auVar1849[0xd] = (byte)uStack_e4;
            auVar1848._13_3_ = auVar1849._13_3_;
            auVar1848._0_12_ = auVar1835._0_12_;
            auVar1848[0xc] = local_ec;
            auVar1847._12_4_ = auVar1848._12_4_;
            auVar1847._0_11_ = auVar1835._0_11_;
            auVar1847[0xb] = (undefined1)uStack_d4;
            auVar1846._11_5_ = auVar1847._11_5_;
            auVar1846._0_10_ = auVar1835._0_10_;
            auVar1846[10] = local_dc;
            auVar1845._10_6_ = auVar1846._10_6_;
            auVar1845._0_9_ = auVar1835._0_9_;
            auVar1845[9] = uStack_f4;
            auVar1844._9_7_ = auVar1845._9_7_;
            auVar1844._0_8_ = auVar1835._0_8_;
            auVar1844[8] = local_fc;
            auVar251._1_8_ = auVar1844._8_8_;
            auVar251[0] = uStack_104;
            auVar251._9_7_ = 0;
            auVar250._10_6_ = 0;
            auVar250._0_10_ = SUB1610(auVar251 << 0x38,6);
            auVar249._11_5_ = 0;
            auVar249._0_11_ = SUB1611(auVar250 << 0x30,5);
            auVar248._12_4_ = 0;
            auVar248._0_12_ = SUB1612(auVar249 << 0x28,4);
            auVar247._13_3_ = 0;
            auVar247._0_13_ = SUB1613(auVar248 << 0x20,3);
            auVar1843._14_2_ = 0;
            auVar1843._0_14_ = SUB1614(auVar247 << 0x18,2);
            auVar1843 = auVar1843 << 0x10;
            uVar923 = CONCAT12(uStack_f0,CONCAT11(bStack_f8,uStack_100));
            uVar67 = CONCAT13(bStack_d8,uVar923);
            uVar929 = CONCAT14(uStack_d0,uVar67);
            auVar935[5] = bStack_e8;
            auVar935._0_5_ = uVar929;
            auVar1603[0xe] = uStack_af;
            auVar1603._0_14_ = auVar1198._0_14_;
            auVar1603[0xf] = uStack_cf;
            auVar1602._14_2_ = auVar1603._14_2_;
            auVar1602[0xd] = uStack_d4._1_1_;
            auVar1602._0_13_ = auVar1198._0_13_;
            auVar1601._13_3_ = auVar1602._13_3_;
            auVar1601[0xc] = uStack_b4._1_1_;
            auVar1601._0_12_ = auVar1198._0_12_;
            auVar1600._12_4_ = auVar1601._12_4_;
            auVar1600[0xb] = bStack_d7;
            auVar1600._0_11_ = auVar1198._0_11_;
            auVar1599._11_5_ = auVar1600._11_5_;
            auVar1599[10] = uStack_b7;
            auVar1599._0_10_ = auVar1198._0_10_;
            auVar1598._10_6_ = auVar1599._10_6_;
            auVar1598[9] = bStack_db;
            auVar1598._0_9_ = auVar1198._0_9_;
            auVar1597._9_7_ = auVar1598._9_7_;
            auVar1597[8] = uStack_bb;
            auVar1597._0_8_ = auVar1198._0_8_;
            auVar256._1_8_ = auVar1597._8_8_;
            auVar256[0] = uStack_ef;
            auVar256._9_7_ = 0;
            auVar255._10_6_ = 0;
            auVar255._0_10_ = SUB1610(auVar256 << 0x38,6);
            auVar254._11_5_ = 0;
            auVar254._0_11_ = SUB1611(auVar255 << 0x30,5);
            auVar253._12_4_ = 0;
            auVar253._0_12_ = SUB1612(auVar254 << 0x28,4);
            auVar252._13_3_ = 0;
            auVar252._0_13_ = SUB1613(auVar253 << 0x20,3);
            auVar1596._14_2_ = 0;
            auVar1596._0_14_ = SUB1614(auVar252 << 0x18,2);
            auVar1596 = auVar1596 << 0x10;
            auVar261._1_8_ =
                 (longlong)
                 (CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(uStack_ce,uStack_ae
                                                                                ),
                                                                        (undefined1)uStack_d2),
                                                               (undefined1)uStack_b2),bStack_d6),
                                             uStack_b6),bStack_da),CONCAT11(uStack_ba,uStack_ae)) >>
                 8);
            auVar261[0] = uStack_ee;
            auVar261._9_7_ = 0;
            auVar260._10_6_ = 0;
            auVar260._0_10_ = SUB1610(auVar261 << 0x38,6);
            auVar259._11_5_ = 0;
            auVar259._0_11_ = SUB1611(auVar260 << 0x30,5);
            auVar258._12_4_ = 0;
            auVar258._0_12_ = SUB1612(auVar259 << 0x28,4);
            auVar257._13_3_ = 0;
            auVar257._0_13_ = SUB1613(auVar258 << 0x20,3);
            auVar959._14_2_ = 0;
            auVar959._0_14_ = SUB1614(auVar257 << 0x18,2);
            auVar959 = auVar959 << 0x10;
            auVar1611._0_14_ = auVar1596._0_14_;
            auVar1611[0xe] = uStack_ef;
            auVar1611[0xf] = bStack_df;
            auVar1610._14_2_ = auVar1611._14_2_;
            auVar1610._0_13_ = auVar1596._0_13_;
            auVar1610[0xd] = bVar182;
            auVar1609._13_3_ = auVar1610._13_3_;
            auVar1609._0_12_ = auVar1596._0_12_;
            auVar1609[0xc] = bVar176;
            auVar1608._12_4_ = auVar1609._12_4_;
            auVar1608._0_11_ = auVar1596._0_11_;
            auVar1608[0xb] = uStack_e4._1_1_;
            auVar1607._11_5_ = auVar1608._11_5_;
            auVar1607._0_10_ = auVar1596._0_10_;
            auVar1607[10] = uStack_f3;
            auVar1606._10_6_ = auVar1607._10_6_;
            auVar1606._0_9_ = auVar1596._0_9_;
            auVar1606[9] = bVar180;
            auVar1605._9_7_ = auVar1606._9_7_;
            auVar1605._0_8_ = auVar1596._0_8_;
            auVar1605[8] = bVar174;
            auVar266._1_8_ = auVar1605._8_8_;
            auVar266[0] = bStack_e7;
            auVar266._9_7_ = 0;
            auVar265._10_6_ = 0;
            auVar265._0_10_ = SUB1610(auVar266 << 0x38,6);
            auVar264._11_5_ = 0;
            auVar264._0_11_ = SUB1611(auVar265 << 0x30,5);
            auVar263._12_4_ = 0;
            auVar263._0_12_ = SUB1612(auVar264 << 0x28,4);
            auVar262._13_3_ = 0;
            auVar262._0_13_ = SUB1613(auVar263 << 0x20,3);
            auVar1604._14_2_ = 0;
            auVar1604._0_14_ = SUB1614(auVar262 << 0x18,2);
            auVar1604 = auVar1604 << 0x10;
            auVar1619._0_14_ = auVar1604._0_14_;
            auVar1619[0xe] = bStack_e7;
            auVar1619[0xf] = bStack_c7;
            auVar1618._14_2_ = auVar1619._14_2_;
            auVar1618._0_13_ = auVar1604._0_13_;
            auVar1618[0xd] = bStack_d7;
            auVar1617._13_3_ = auVar1618._13_3_;
            auVar1617._0_12_ = auVar1604._0_12_;
            auVar1617[0xc] = bStack_f7;
            auVar1616._12_4_ = auVar1617._12_4_;
            auVar1616._0_11_ = auVar1604._0_11_;
            auVar1616[0xb] = uStack_107;
            auVar1615._11_5_ = auVar1616._11_5_;
            auVar1615._0_10_ = auVar1604._0_10_;
            auVar1615[10] = bVar178;
            auVar1614._10_6_ = auVar1615._10_6_;
            auVar1614._0_9_ = auVar1604._0_9_;
            auVar1614[9] = uStack_b7;
            auVar1613._9_7_ = auVar1614._9_7_;
            auVar1613._0_8_ = auVar1604._0_8_;
            auVar1613[8] = bVar173;
            auVar271._1_8_ = auVar1613._8_8_;
            auVar271[0] = bStack_cb;
            auVar271._9_7_ = 0;
            auVar270._10_6_ = 0;
            auVar270._0_10_ = SUB1610(auVar271 << 0x38,6);
            auVar269._11_5_ = 0;
            auVar269._0_11_ = SUB1611(auVar270 << 0x30,5);
            auVar268._12_4_ = 0;
            auVar268._0_12_ = SUB1612(auVar269 << 0x28,4);
            auVar267._13_3_ = 0;
            auVar267._0_13_ = SUB1613(auVar268 << 0x20,3);
            auVar1612._14_2_ = 0;
            auVar1612._0_14_ = SUB1614(auVar267 << 0x18,2);
            auVar1612 = auVar1612 << 0x10;
            auVar1627._0_14_ = auVar1612._0_14_;
            auVar1627[0xe] = bStack_cb;
            auVar1627[0xf] = bStack_c3;
            auVar1626._14_2_ = auVar1627._14_2_;
            auVar1626._0_13_ = auVar1612._0_13_;
            auVar1626[0xd] = uStack_e4._1_1_;
            auVar1625._13_3_ = auVar1626._13_3_;
            auVar1625._0_12_ = auVar1612._0_12_;
            auVar1625[0xc] = bStack_eb;
            auVar1624._12_4_ = auVar1625._12_4_;
            auVar1624._0_11_ = auVar1612._0_11_;
            auVar1624[0xb] = uStack_d4._1_1_;
            auVar1623._11_5_ = auVar1624._11_5_;
            auVar1623._0_10_ = auVar1612._0_10_;
            auVar1623[10] = bStack_db;
            auVar1622._10_6_ = auVar1623._10_6_;
            auVar1622._0_9_ = auVar1612._0_9_;
            auVar1622[9] = uStack_f3;
            auVar1621._9_7_ = auVar1622._9_7_;
            auVar1621._0_8_ = auVar1612._0_8_;
            auVar1621[8] = bStack_fb;
            auVar276._1_8_ = auVar1621._8_8_;
            auVar276[0] = uStack_103;
            auVar276._9_7_ = 0;
            auVar275._10_6_ = 0;
            auVar275._0_10_ = SUB1610(auVar276 << 0x38,6);
            auVar274._11_5_ = 0;
            auVar274._0_11_ = SUB1611(auVar275 << 0x30,5);
            auVar273._12_4_ = 0;
            auVar273._0_12_ = SUB1612(auVar274 << 0x28,4);
            auVar272._13_3_ = 0;
            auVar272._0_13_ = SUB1613(auVar273 << 0x20,3);
            auVar1620._14_2_ = 0;
            auVar1620._0_14_ = SUB1614(auVar272 << 0x18,2);
            auVar1620 = auVar1620 << 0x10;
            uVar924 = CONCAT12(uStack_ef,CONCAT11(bStack_f7,uStack_ff));
            uVar84 = CONCAT13(bStack_d7,uVar924);
            uVar930 = CONCAT14(uStack_cf,uVar84);
            auVar936[5] = bStack_e7;
            auVar936._0_5_ = uVar930;
            auVar967._0_14_ = auVar959._0_14_;
            auVar967[0xe] = uStack_ee;
            auVar967[0xf] = bStack_de;
            auVar966._14_2_ = auVar967._14_2_;
            auVar966._0_13_ = auVar959._0_13_;
            auVar966[0xd] = pbVar2[0xe];
            auVar965._13_3_ = auVar966._13_3_;
            auVar965._0_12_ = auVar959._0_12_;
            auVar965[0xc] = pbVar1[0xe];
            auVar964._12_4_ = auVar965._12_4_;
            auVar964._0_11_ = auVar959._0_11_;
            auVar964[0xb] = (byte)uStack_e2;
            auVar963._11_5_ = auVar964._11_5_;
            auVar963._0_10_ = auVar959._0_10_;
            auVar963[10] = uStack_f2;
            auVar962._10_6_ = auVar963._10_6_;
            auVar962._0_9_ = auVar959._0_9_;
            auVar962[9] = pbVar2[10];
            auVar961._9_7_ = auVar962._9_7_;
            auVar961._0_8_ = auVar959._0_8_;
            auVar961[8] = pbVar1[10];
            auVar281._1_8_ = auVar961._8_8_;
            auVar281[0] = bStack_e6;
            auVar281._9_7_ = 0;
            auVar280._10_6_ = 0;
            auVar280._0_10_ = SUB1610(auVar281 << 0x38,6);
            auVar279._11_5_ = 0;
            auVar279._0_11_ = SUB1611(auVar280 << 0x30,5);
            auVar278._12_4_ = 0;
            auVar278._0_12_ = SUB1612(auVar279 << 0x28,4);
            auVar277._13_3_ = 0;
            auVar277._0_13_ = SUB1613(auVar278 << 0x20,3);
            auVar960._14_2_ = 0;
            auVar960._0_14_ = SUB1614(auVar277 << 0x18,2);
            auVar960 = auVar960 << 0x10;
            auVar975._0_14_ = auVar960._0_14_;
            auVar975[0xe] = bStack_e6;
            auVar975[0xf] = bStack_c6;
            auVar974._14_2_ = auVar975._14_2_;
            auVar974._0_13_ = auVar960._0_13_;
            auVar974[0xd] = bStack_d6;
            auVar973._13_3_ = auVar974._13_3_;
            auVar973._0_12_ = auVar960._0_12_;
            auVar973[0xc] = bStack_f6;
            auVar972._12_4_ = auVar973._12_4_;
            auVar972._0_11_ = auVar960._0_11_;
            auVar972[0xb] = uStack_106;
            auVar971._11_5_ = auVar972._11_5_;
            auVar971._0_10_ = auVar960._0_10_;
            auVar971[10] = pbVar2[6];
            auVar970._10_6_ = auVar971._10_6_;
            auVar970._0_9_ = auVar960._0_9_;
            auVar970[9] = uStack_b6;
            auVar969._9_7_ = auVar970._9_7_;
            auVar969._0_8_ = auVar960._0_8_;
            auVar969[8] = pbVar1[6];
            auVar286._1_8_ = auVar969._8_8_;
            auVar286[0] = bStack_ca;
            auVar286._9_7_ = 0;
            auVar285._10_6_ = 0;
            auVar285._0_10_ = SUB1610(auVar286 << 0x38,6);
            auVar284._11_5_ = 0;
            auVar284._0_11_ = SUB1611(auVar285 << 0x30,5);
            auVar283._12_4_ = 0;
            auVar283._0_12_ = SUB1612(auVar284 << 0x28,4);
            auVar282._13_3_ = 0;
            auVar282._0_13_ = SUB1613(auVar283 << 0x20,3);
            auVar968._14_2_ = 0;
            auVar968._0_14_ = SUB1614(auVar282 << 0x18,2);
            auVar968 = auVar968 << 0x10;
            auVar983._0_14_ = auVar968._0_14_;
            auVar983[0xe] = bStack_ca;
            auVar983[0xf] = bStack_c2;
            auVar982._14_2_ = auVar983._14_2_;
            auVar982._0_13_ = auVar968._0_13_;
            auVar982[0xd] = (byte)uStack_e2;
            auVar981._13_3_ = auVar982._13_3_;
            auVar981._0_12_ = auVar968._0_12_;
            auVar981[0xc] = bStack_ea;
            auVar980._12_4_ = auVar981._12_4_;
            auVar980._0_11_ = auVar968._0_11_;
            auVar980[0xb] = (undefined1)uStack_d2;
            auVar979._11_5_ = auVar980._11_5_;
            auVar979._0_10_ = auVar968._0_10_;
            auVar979[10] = bStack_da;
            auVar978._10_6_ = auVar979._10_6_;
            auVar978._0_9_ = auVar968._0_9_;
            auVar978[9] = uStack_f2;
            auVar977._9_7_ = auVar978._9_7_;
            auVar977._0_8_ = auVar968._0_8_;
            auVar977[8] = bStack_fa;
            auVar291._1_8_ = auVar977._8_8_;
            auVar291[0] = uStack_102;
            auVar291._9_7_ = 0;
            auVar290._10_6_ = 0;
            auVar290._0_10_ = SUB1610(auVar291 << 0x38,6);
            auVar289._11_5_ = 0;
            auVar289._0_11_ = SUB1611(auVar290 << 0x30,5);
            auVar288._12_4_ = 0;
            auVar288._0_12_ = SUB1612(auVar289 << 0x28,4);
            auVar287._13_3_ = 0;
            auVar287._0_13_ = SUB1613(auVar288 << 0x20,3);
            auVar976._14_2_ = 0;
            auVar976._0_14_ = SUB1614(auVar287 << 0x18,2);
            auVar976 = auVar976 << 0x10;
            uVar925 = CONCAT12(uStack_ee,CONCAT11(bStack_f6,uStack_fe));
            uVar99 = CONCAT13(bStack_d6,uVar925);
            uVar931 = CONCAT14(uStack_ce,uVar99);
            auVar937[5] = bStack_e6;
            auVar937._0_5_ = uVar931;
            uVar926 = CONCAT12(uStack_f1,CONCAT11(bStack_f9,uStack_101));
            uVar117 = CONCAT13(bStack_d9,uVar926);
            uVar932 = CONCAT14(uStack_d2._1_1_,uVar117);
            auVar939[5] = bStack_e9;
            auVar939._0_5_ = uVar932;
            auVar935._6_8_ = 0;
            auVar8[0xe] = uStack_100;
            auVar8._0_14_ = auVar935 << 0x38;
            auVar836._4_8_ = 0;
            auVar836._0_4_ = uVar67;
            auVar51._12_3_ = (int3)(CONCAT26(auVar8._13_2_,CONCAT15(uStack_108,uVar929)) >> 0x28);
            auVar51._0_12_ = auVar836 << 0x38;
            uVar67 = auVar51._11_4_;
            uVar928 = CONCAT44(uVar67,CONCAT13(pbVar2[0xc],uVar923));
            auVar130._10_5_ = (int5)((ulonglong)uVar928 >> 0x18);
            auVar130._0_10_ = (unkuint10)CONCAT11(bStack_f8,uStack_100) << 0x38;
            uVar927 = CONCAT62(auVar130._9_6_,CONCAT11(pbVar2[4],uStack_100));
            auVar292._7_8_ = 0;
            auVar292._0_7_ = (uint7)((ulonglong)uVar927 >> 8);
            Var293 = CONCAT81(SUB158(auVar292 << 0x40,7),uStack_b0);
            auVar842._9_6_ = 0;
            auVar842._0_9_ = Var293;
            auVar294._1_10_ = SUB1510(auVar842 << 0x30,5);
            auVar294[0] = uStack_b8;
            auVar843._11_4_ = 0;
            auVar843._0_11_ = auVar294;
            auVar902._1_12_ = SUB1512(auVar843 << 0x20,3);
            auVar902[0] = pbVar1[0xc];
            auVar157[1] = 0;
            auVar157[0] = pbVar1[4];
            auVar157._2_13_ = auVar902;
            uVar923 = CONCAT12(uStack_ed,CONCAT11(bStack_f5,uStack_fd));
            uVar116 = CONCAT13(bStack_d5,uVar923);
            uVar929 = CONCAT14(uStack_cd,uVar116);
            auVar938[5] = bStack_e5;
            auVar938._0_5_ = uVar929;
            uVar1822 = CONCAT13(0,CONCAT12(uStack_f4,(ushort)local_fc));
            auVar9[0xd] = 0;
            auVar9._0_13_ = auVar1843._0_13_;
            auVar9[0xe] = uStack_104;
            auVar40[0xc] = local_10c;
            auVar40._0_12_ = auVar1843._0_12_;
            auVar40._13_2_ = auVar9._13_2_;
            auVar52[0xb] = 0;
            auVar52._0_11_ = auVar1843._0_11_;
            auVar52._12_3_ = auVar40._12_3_;
            uVar68 = auVar52._11_4_;
            auVar69[10] = pbVar2[8];
            auVar69._0_10_ = auVar1843._0_10_;
            auVar69._11_4_ = uVar68;
            auVar131[9] = 0;
            auVar131._0_9_ = auVar1843._0_9_;
            auVar131._10_5_ = auVar69._10_5_;
            auVar146[8] = *pbVar2;
            auVar146._0_8_ = auVar1843._0_8_;
            auVar146._9_6_ = auVar131._9_6_;
            auVar295._7_8_ = 0;
            auVar295._0_7_ = auVar146._8_7_;
            Var296 = CONCAT81(SUB158(auVar295 << 0x40,7),(byte)uStack_b4);
            auVar844._9_6_ = 0;
            auVar844._0_9_ = Var296;
            auVar297._1_10_ = SUB1510(auVar844 << 0x30,5);
            auVar297[0] = local_bc;
            auVar845._11_4_ = 0;
            auVar845._0_11_ = auVar297;
            auVar298._1_12_ = SUB1512(auVar845 << 0x20,3);
            auVar298[0] = pbVar1[8];
            auVar158[1] = 0;
            auVar158[0] = *pbVar1;
            auVar158._2_13_ = auVar298;
            auVar1181 = *(undefined1 (*) [16])(pbVar954 + iVar948 * 2);
            uVar1823 = CONCAT13(0,CONCAT12(uStack_f0,(ushort)bStack_f8));
            pbVar3 = pbVar954 + iVar948 * 2 + 0x10;
            bVar183 = *pbVar3;
            bVar184 = pbVar3[2];
            bVar185 = pbVar3[4];
            bVar186 = pbVar3[6];
            bVar187 = pbVar3[8];
            bVar188 = pbVar3[10];
            bVar189 = pbVar3[0xc];
            uVar1852 = auVar1181[8];
            uVar1853 = auVar1181[10];
            auVar1213._0_14_ = auVar1181._0_14_;
            auVar1213[0xe] = auVar1181[7];
            auVar1213[0xf] = pbVar3[7];
            auVar1212._14_2_ = auVar1213._14_2_;
            auVar1212._0_13_ = auVar1181._0_13_;
            auVar1212[0xd] = bVar186;
            auVar1211._13_3_ = auVar1212._13_3_;
            auVar1211._0_12_ = auVar1181._0_12_;
            auVar1211[0xc] = auVar1181[6];
            auVar1210._12_4_ = auVar1211._12_4_;
            auVar1210._0_11_ = auVar1181._0_11_;
            auVar1210[0xb] = pbVar3[5];
            auVar1209._11_5_ = auVar1210._11_5_;
            auVar1209._0_10_ = auVar1181._0_10_;
            auVar1209[10] = auVar1181[5];
            auVar1208._10_6_ = auVar1209._10_6_;
            auVar1208._0_9_ = auVar1181._0_9_;
            auVar1208[9] = bVar185;
            uVar1176 = auVar1181[4];
            auVar1207._9_7_ = auVar1208._9_7_;
            auVar1207._0_8_ = auVar1181._0_8_;
            auVar1207[8] = uVar1176;
            auVar303._1_8_ = auVar1207._8_8_;
            auVar303[0] = pbVar3[3];
            auVar303._9_7_ = 0;
            auVar302._10_6_ = 0;
            auVar302._0_10_ = SUB1610(auVar303 << 0x38,6);
            auVar301._11_5_ = 0;
            auVar301._0_11_ = SUB1611(auVar302 << 0x30,5);
            auVar300._12_4_ = 0;
            auVar300._0_12_ = SUB1612(auVar301 << 0x28,4);
            auVar299._13_3_ = 0;
            auVar299._0_13_ = SUB1613(auVar300 << 0x20,3);
            auVar1206._14_2_ = 0;
            auVar1206._0_14_ = SUB1614(auVar299 << 0x18,2);
            auVar1206 = auVar1206 << 0x10;
            auVar1221._0_14_ = auVar1206._0_14_;
            auVar1221[0xe] = pbVar3[3];
            auVar1221[0xf] = pbVar3[0xb];
            auVar1220._14_2_ = auVar1221._14_2_;
            auVar1220._0_13_ = auVar1206._0_13_;
            auVar1220[0xd] = auVar1181[0xb];
            auVar1219._13_3_ = auVar1220._13_3_;
            auVar1219._0_12_ = auVar1206._0_12_;
            auVar1219[0xc] = auVar1181[3];
            auVar1218._12_4_ = auVar1219._12_4_;
            auVar1218._0_11_ = auVar1206._0_11_;
            auVar1218[0xb] = bVar188;
            auVar1217._11_5_ = auVar1218._11_5_;
            auVar1217._0_10_ = auVar1206._0_10_;
            auVar1217[10] = bVar184;
            auVar1216._10_6_ = auVar1217._10_6_;
            auVar1216._0_9_ = auVar1206._0_9_;
            auVar1216[9] = uVar1853;
            auVar1215._9_7_ = auVar1216._9_7_;
            auVar1215._0_8_ = auVar1206._0_8_;
            auVar1215[8] = auVar1181[2];
            auVar308._1_8_ = auVar1215._8_8_;
            auVar308[0] = pbVar3[9];
            auVar308._9_7_ = 0;
            auVar307._10_6_ = 0;
            auVar307._0_10_ = SUB1610(auVar308 << 0x38,6);
            auVar306._11_5_ = 0;
            auVar306._0_11_ = SUB1611(auVar307 << 0x30,5);
            auVar305._12_4_ = 0;
            auVar305._0_12_ = SUB1612(auVar306 << 0x28,4);
            auVar304._13_3_ = 0;
            auVar304._0_13_ = SUB1613(auVar305 << 0x20,3);
            auVar1214._14_2_ = 0;
            auVar1214._0_14_ = SUB1614(auVar304 << 0x18,2);
            auVar1214 = auVar1214 << 0x10;
            auVar1229._0_14_ = auVar1214._0_14_;
            auVar1229[0xe] = pbVar3[9];
            auVar1229[0xf] = pbVar3[0xd];
            auVar1228._14_2_ = auVar1229._14_2_;
            auVar1228._0_13_ = auVar1214._0_13_;
            auVar1228[0xd] = pbVar3[5];
            auVar1227._13_3_ = auVar1228._13_3_;
            auVar1227._0_12_ = auVar1214._0_12_;
            auVar1227[0xc] = pbVar3[1];
            auVar1226._12_4_ = auVar1227._12_4_;
            auVar1226._0_11_ = auVar1214._0_11_;
            auVar1226[0xb] = auVar1181[0xd];
            auVar1225._11_5_ = auVar1226._11_5_;
            auVar1225._0_10_ = auVar1214._0_10_;
            auVar1225[10] = auVar1181[9];
            auVar1224._10_6_ = auVar1225._10_6_;
            auVar1224._0_9_ = auVar1214._0_9_;
            auVar1224[9] = auVar1181[5];
            auVar1223._9_7_ = auVar1224._9_7_;
            auVar1223._0_8_ = auVar1214._0_8_;
            auVar1223[8] = auVar1181[1];
            auVar313._1_8_ = auVar1223._8_8_;
            auVar313[0] = bVar189;
            auVar313._9_7_ = 0;
            auVar312._10_6_ = 0;
            auVar312._0_10_ = SUB1610(auVar313 << 0x38,6);
            auVar311._11_5_ = 0;
            auVar311._0_11_ = SUB1611(auVar312 << 0x30,5);
            auVar310._12_4_ = 0;
            auVar310._0_12_ = SUB1612(auVar311 << 0x28,4);
            auVar309._13_3_ = 0;
            auVar309._0_13_ = SUB1613(auVar310 << 0x20,3);
            auVar1222._14_2_ = 0;
            auVar1222._0_14_ = SUB1614(auVar309 << 0x18,2);
            auVar1222 = auVar1222 << 0x10;
            pbVar4 = pbVar954 + iVar948 * 2 + 0x20;
            bVar190 = pbVar4[4];
            bVar191 = pbVar4[8];
            bVar192 = pbVar4[0xc];
            auVar1237._0_14_ = auVar1222._0_14_;
            auVar1237[0xe] = bVar189;
            auVar1237[0xf] = pbVar3[0xe];
            auVar1236._14_2_ = auVar1237._14_2_;
            auVar1236._0_13_ = auVar1222._0_13_;
            auVar1236[0xd] = bVar188;
            auVar1235._13_3_ = auVar1236._13_3_;
            auVar1235._0_12_ = auVar1222._0_12_;
            auVar1235[0xc] = bVar187;
            auVar1234._12_4_ = auVar1235._12_4_;
            auVar1234._0_11_ = auVar1222._0_11_;
            auVar1234[0xb] = bVar186;
            auVar1233._11_5_ = auVar1234._11_5_;
            auVar1233._0_10_ = auVar1222._0_10_;
            auVar1233[10] = bVar185;
            auVar1232._10_6_ = auVar1233._10_6_;
            auVar1232._0_9_ = auVar1222._0_9_;
            auVar1232[9] = bVar184;
            auVar1231._9_7_ = auVar1232._9_7_;
            auVar1231._0_8_ = auVar1222._0_8_;
            auVar1231[8] = bVar183;
            auVar318._1_8_ = auVar1231._8_8_;
            auVar318[0] = auVar1181[0xe];
            auVar318._9_7_ = 0;
            auVar317._10_6_ = 0;
            auVar317._0_10_ = SUB1610(auVar318 << 0x38,6);
            auVar316._11_5_ = 0;
            auVar316._0_11_ = SUB1611(auVar317 << 0x30,5);
            auVar315._12_4_ = 0;
            auVar315._0_12_ = SUB1612(auVar316 << 0x28,4);
            auVar314._13_3_ = 0;
            auVar314._0_13_ = SUB1613(auVar315 << 0x20,3);
            auVar1230._14_2_ = 0;
            auVar1230._0_14_ = SUB1614(auVar314 << 0x18,2);
            auVar1230 = auVar1230 << 0x10;
            pbVar3 = pbVar954 + iVar948 * 2 + 0x30;
            bVar193 = pbVar3[4];
            bVar194 = pbVar3[8];
            auVar1245._0_14_ = auVar1230._0_14_;
            auVar1245[0xe] = auVar1181[0xe];
            auVar1245[0xf] = pbVar4[0xe];
            auVar1244._14_2_ = auVar1245._14_2_;
            auVar1244._0_13_ = auVar1230._0_13_;
            auVar1244[0xd] = bVar192;
            auVar1243._13_3_ = auVar1244._13_3_;
            auVar1243._0_12_ = auVar1230._0_12_;
            auVar1243[0xc] = auVar1181[0xc];
            auVar1242._12_4_ = auVar1243._12_4_;
            auVar1242._0_11_ = auVar1230._0_11_;
            auVar1242[0xb] = pbVar4[10];
            auVar1241._11_5_ = auVar1242._11_5_;
            auVar1241._0_10_ = auVar1230._0_10_;
            auVar1241[10] = uVar1853;
            auVar1240._10_6_ = auVar1241._10_6_;
            auVar1240._0_9_ = auVar1230._0_9_;
            auVar1240[9] = bVar191;
            auVar1239._9_7_ = auVar1240._9_7_;
            auVar1239._0_8_ = auVar1230._0_8_;
            auVar1239[8] = uVar1852;
            auVar323._1_8_ = auVar1239._8_8_;
            auVar323[0] = pbVar4[6];
            auVar323._9_7_ = 0;
            auVar322._10_6_ = 0;
            auVar322._0_10_ = SUB1610(auVar323 << 0x38,6);
            auVar321._11_5_ = 0;
            auVar321._0_11_ = SUB1611(auVar322 << 0x30,5);
            auVar320._12_4_ = 0;
            auVar320._0_12_ = SUB1612(auVar321 << 0x28,4);
            auVar319._13_3_ = 0;
            auVar319._0_13_ = SUB1613(auVar320 << 0x20,3);
            auVar1238._14_2_ = 0;
            auVar1238._0_14_ = SUB1614(auVar319 << 0x18,2);
            auVar1238 = auVar1238 << 0x10;
            auVar1253._0_14_ = auVar1238._0_14_;
            auVar1253[0xe] = pbVar4[6];
            auVar1253[0xf] = pbVar3[6];
            auVar1252._14_2_ = auVar1253._14_2_;
            auVar1252._0_13_ = auVar1238._0_13_;
            auVar1252[0xd] = bVar186;
            auVar1251._13_3_ = auVar1252._13_3_;
            auVar1251._0_12_ = auVar1238._0_12_;
            auVar1251[0xc] = auVar1181[6];
            auVar1250._12_4_ = auVar1251._12_4_;
            auVar1250._0_11_ = auVar1238._0_11_;
            auVar1250[0xb] = bVar193;
            auVar1249._11_5_ = auVar1250._11_5_;
            auVar1249._0_10_ = auVar1238._0_10_;
            auVar1249[10] = bVar190;
            auVar1248._10_6_ = auVar1249._10_6_;
            auVar1248._0_9_ = auVar1238._0_9_;
            auVar1248[9] = bVar185;
            auVar1247._9_7_ = auVar1248._9_7_;
            auVar1247._0_8_ = auVar1238._0_8_;
            auVar1247[8] = uVar1176;
            auVar328._1_8_ = auVar1247._8_8_;
            auVar328[0] = pbVar3[2];
            auVar328._9_7_ = 0;
            auVar327._10_6_ = 0;
            auVar327._0_10_ = SUB1610(auVar328 << 0x38,6);
            auVar326._11_5_ = 0;
            auVar326._0_11_ = SUB1611(auVar327 << 0x30,5);
            auVar325._12_4_ = 0;
            auVar325._0_12_ = SUB1612(auVar326 << 0x28,4);
            auVar324._13_3_ = 0;
            auVar324._0_13_ = SUB1613(auVar325 << 0x20,3);
            auVar1246._14_2_ = 0;
            auVar1246._0_14_ = SUB1614(auVar324 << 0x18,2);
            auVar1246 = auVar1246 << 0x10;
            auVar1261._0_14_ = auVar1246._0_14_;
            auVar1261[0xe] = pbVar3[2];
            auVar1261[0xf] = pbVar3[10];
            auVar1260._14_2_ = auVar1261._14_2_;
            auVar1260._0_13_ = auVar1246._0_13_;
            auVar1260[0xd] = pbVar4[10];
            auVar1259._13_3_ = auVar1260._13_3_;
            auVar1259._0_12_ = auVar1246._0_12_;
            auVar1259[0xc] = pbVar4[2];
            auVar1258._12_4_ = auVar1259._12_4_;
            auVar1258._0_11_ = auVar1246._0_11_;
            auVar1258[0xb] = bVar188;
            auVar1257._11_5_ = auVar1258._11_5_;
            auVar1257._0_10_ = auVar1246._0_10_;
            auVar1257[10] = bVar184;
            auVar1256._10_6_ = auVar1257._10_6_;
            auVar1256._0_9_ = auVar1246._0_9_;
            auVar1256[9] = uVar1853;
            auVar1255._9_7_ = auVar1256._9_7_;
            auVar1255._0_8_ = auVar1246._0_8_;
            auVar1255[8] = auVar1181[2];
            auVar333._1_8_ = auVar1255._8_8_;
            auVar333[0] = bVar194;
            auVar333._9_7_ = 0;
            auVar332._10_6_ = 0;
            auVar332._0_10_ = SUB1610(auVar333 << 0x38,6);
            auVar331._11_5_ = 0;
            auVar331._0_11_ = SUB1611(auVar332 << 0x30,5);
            auVar330._12_4_ = 0;
            auVar330._0_12_ = SUB1612(auVar331 << 0x28,4);
            auVar329._13_3_ = 0;
            auVar329._0_13_ = SUB1613(auVar330 << 0x20,3);
            auVar1254._14_2_ = 0;
            auVar1254._0_14_ = SUB1614(auVar329 << 0x18,2);
            auVar1254 = auVar1254 << 0x10;
            pbVar5 = pbVar954 + iVar948 * 2 + 0x50;
            bVar184 = *pbVar5;
            bVar186 = pbVar5[8];
            auVar1269._0_14_ = auVar1254._0_14_;
            auVar1269[0xe] = bVar194;
            auVar1269[0xf] = pbVar3[0xc];
            auVar1268._14_2_ = auVar1269._14_2_;
            auVar1268._0_13_ = auVar1254._0_13_;
            auVar1268[0xd] = bVar193;
            auVar1267._13_3_ = auVar1268._13_3_;
            auVar1267._0_12_ = auVar1254._0_12_;
            auVar1267[0xc] = *pbVar3;
            auVar1266._12_4_ = auVar1267._12_4_;
            auVar1266._0_11_ = auVar1254._0_11_;
            auVar1266[0xb] = bVar192;
            auVar1265._11_5_ = auVar1266._11_5_;
            auVar1265._0_10_ = auVar1254._0_10_;
            auVar1265[10] = bVar191;
            auVar1264._10_6_ = auVar1265._10_6_;
            auVar1264._0_9_ = auVar1254._0_9_;
            auVar1264[9] = bVar190;
            auVar1263._9_7_ = auVar1264._9_7_;
            auVar1263._0_8_ = auVar1254._0_8_;
            auVar1263[8] = *pbVar4;
            auVar338._1_8_ = auVar1263._8_8_;
            auVar338[0] = bVar189;
            auVar338._9_7_ = 0;
            auVar337._10_6_ = 0;
            auVar337._0_10_ = SUB1610(auVar338 << 0x38,6);
            auVar336._11_5_ = 0;
            auVar336._0_11_ = SUB1611(auVar337 << 0x30,5);
            auVar335._12_4_ = 0;
            auVar335._0_12_ = SUB1612(auVar336 << 0x28,4);
            auVar334._13_3_ = 0;
            auVar334._0_13_ = SUB1613(auVar335 << 0x20,3);
            auVar1262._14_2_ = 0;
            auVar1262._0_14_ = SUB1614(auVar334 << 0x18,2);
            auVar1262 = auVar1262 << 0x10;
            pbVar6 = pbVar954 + iVar948 * 2 + 0x40;
            bVar188 = pbVar6[8];
            pbVar7 = pbVar954 + iVar948 * 2 + 0x60;
            bVar195 = *pbVar7;
            bVar196 = pbVar7[8];
            auVar836 = *(undefined1 (*) [12])(pbVar954 + iVar948 * 2 + 0x70);
            local_8c = auVar836[0];
            uStack_88 = auVar836[4];
            bStack_84 = auVar836[8];
            auVar1277._0_14_ = auVar1262._0_14_;
            auVar1277[0xe] = bVar189;
            auVar1277[0xf] = pbVar5[0xc];
            auVar1276._14_2_ = auVar1277._14_2_;
            auVar1276._0_13_ = auVar1262._0_13_;
            auVar1276[0xd] = bVar186;
            auVar1275._13_3_ = auVar1276._13_3_;
            auVar1275._0_12_ = auVar1262._0_12_;
            auVar1275[0xc] = bVar187;
            auVar1274._12_4_ = auVar1275._12_4_;
            auVar1274._0_11_ = auVar1262._0_11_;
            auVar1274[0xb] = pbVar5[4];
            auVar1273._11_5_ = auVar1274._11_5_;
            auVar1273._0_10_ = auVar1262._0_10_;
            auVar1273[10] = bVar185;
            auVar1272._10_6_ = auVar1273._10_6_;
            auVar1272._0_9_ = auVar1262._0_9_;
            auVar1272[9] = bVar184;
            auVar1271._9_7_ = auVar1272._9_7_;
            auVar1271._0_8_ = auVar1262._0_8_;
            auVar1271[8] = bVar183;
            auVar343._1_8_ = auVar1271._8_8_;
            auVar343[0] = pbVar6[0xc];
            auVar343._9_7_ = 0;
            auVar342._10_6_ = 0;
            auVar342._0_10_ = SUB1610(auVar343 << 0x38,6);
            auVar341._11_5_ = 0;
            auVar341._0_11_ = SUB1611(auVar342 << 0x30,5);
            auVar340._12_4_ = 0;
            auVar340._0_12_ = SUB1612(auVar341 << 0x28,4);
            auVar339._13_3_ = 0;
            auVar339._0_13_ = SUB1613(auVar340 << 0x20,3);
            auVar1270._14_2_ = 0;
            auVar1270._0_14_ = SUB1614(auVar339 << 0x18,2);
            auVar1270 = auVar1270 << 0x10;
            auVar1285._0_14_ = auVar1270._0_14_;
            auVar1285[0xe] = pbVar6[0xc];
            auVar1285[0xf] = pbVar7[0xc];
            auVar1284._14_2_ = auVar1285._14_2_;
            auVar1284._0_13_ = auVar1270._0_13_;
            auVar1284[0xd] = bVar192;
            auVar1283._13_3_ = auVar1284._13_3_;
            auVar1283._0_12_ = auVar1270._0_12_;
            auVar1283[0xc] = auVar1181[0xc];
            auVar1282._12_4_ = auVar1283._12_4_;
            auVar1282._0_11_ = auVar1270._0_11_;
            auVar1282[0xb] = bVar196;
            auVar1281._11_5_ = auVar1282._11_5_;
            auVar1281._0_10_ = auVar1270._0_10_;
            auVar1281[10] = bVar188;
            auVar1280._10_6_ = auVar1281._10_6_;
            auVar1280._0_9_ = auVar1270._0_9_;
            auVar1280[9] = bVar191;
            auVar1279._9_7_ = auVar1280._9_7_;
            auVar1279._0_8_ = auVar1270._0_8_;
            auVar1279[8] = uVar1852;
            auVar348._1_8_ = auVar1279._8_8_;
            auVar348[0] = pbVar7[4];
            auVar348._9_7_ = 0;
            auVar347._10_6_ = 0;
            auVar347._0_10_ = SUB1610(auVar348 << 0x38,6);
            auVar346._11_5_ = 0;
            auVar346._0_11_ = SUB1611(auVar347 << 0x30,5);
            auVar345._12_4_ = 0;
            auVar345._0_12_ = SUB1612(auVar346 << 0x28,4);
            auVar344._13_3_ = 0;
            auVar344._0_13_ = SUB1613(auVar345 << 0x20,3);
            auVar1278._14_2_ = 0;
            auVar1278._0_14_ = SUB1614(auVar344 << 0x18,2);
            auVar1278 = auVar1278 << 0x10;
            auVar1293._0_14_ = auVar1278._0_14_;
            auVar1293[0xe] = pbVar7[4];
            auVar1293[0xf] = uStack_88;
            auVar1292._14_2_ = auVar1293._14_2_;
            auVar1292._0_13_ = auVar1278._0_13_;
            auVar1292[0xd] = pbVar5[4];
            auVar1291._13_3_ = auVar1292._13_3_;
            auVar1291._0_12_ = auVar1278._0_12_;
            auVar1291[0xc] = pbVar6[4];
            auVar1290._12_4_ = auVar1291._12_4_;
            auVar1290._0_11_ = auVar1278._0_11_;
            auVar1290[0xb] = bVar193;
            auVar1289._11_5_ = auVar1290._11_5_;
            auVar1289._0_10_ = auVar1278._0_10_;
            auVar1289[10] = bVar190;
            auVar1288._10_6_ = auVar1289._10_6_;
            auVar1288._0_9_ = auVar1278._0_9_;
            auVar1288[9] = bVar185;
            auVar1287._9_7_ = auVar1288._9_7_;
            auVar1287._0_8_ = auVar1278._0_8_;
            auVar1287[8] = uVar1176;
            auVar353._1_8_ = auVar1287._8_8_;
            auVar353[0] = local_8c;
            auVar353._9_7_ = 0;
            auVar352._10_6_ = 0;
            auVar352._0_10_ = SUB1610(auVar353 << 0x38,6);
            auVar351._11_5_ = 0;
            auVar351._0_11_ = SUB1611(auVar352 << 0x30,5);
            auVar350._12_4_ = 0;
            auVar350._0_12_ = SUB1612(auVar351 << 0x28,4);
            auVar349._13_3_ = 0;
            auVar349._0_13_ = SUB1613(auVar350 << 0x20,3);
            auVar1286._14_2_ = 0;
            auVar1286._0_14_ = SUB1614(auVar349 << 0x18,2);
            auVar1286 = auVar1286 << 0x10;
            auVar1301._0_14_ = auVar1286._0_14_;
            auVar1301[0xe] = local_8c;
            auVar1301[0xf] = bStack_84;
            auVar1300._14_2_ = auVar1301._14_2_;
            auVar1300._0_13_ = auVar1286._0_13_;
            auVar1300[0xd] = bVar196;
            auVar1299._13_3_ = auVar1300._13_3_;
            auVar1299._0_12_ = auVar1286._0_12_;
            auVar1299[0xc] = bVar195;
            auVar1298._12_4_ = auVar1299._12_4_;
            auVar1298._0_11_ = auVar1286._0_11_;
            auVar1298[0xb] = bVar186;
            auVar1297._11_5_ = auVar1298._11_5_;
            auVar1297._0_10_ = auVar1286._0_10_;
            auVar1297[10] = bVar184;
            auVar1296._10_6_ = auVar1297._10_6_;
            auVar1296._0_9_ = auVar1286._0_9_;
            auVar1296[9] = bVar188;
            auVar1295._9_7_ = auVar1296._9_7_;
            auVar1295._0_8_ = auVar1286._0_8_;
            auVar1295[8] = *pbVar6;
            auVar358._1_8_ = auVar1295._8_8_;
            auVar358[0] = bVar194;
            auVar358._9_7_ = 0;
            auVar357._10_6_ = 0;
            auVar357._0_10_ = SUB1610(auVar358 << 0x38,6);
            auVar356._11_5_ = 0;
            auVar356._0_11_ = SUB1611(auVar357 << 0x30,5);
            auVar355._12_4_ = 0;
            auVar355._0_12_ = SUB1612(auVar356 << 0x28,4);
            auVar354._13_3_ = 0;
            auVar354._0_13_ = SUB1613(auVar355 << 0x20,3);
            auVar1294._14_2_ = 0;
            auVar1294._0_14_ = SUB1614(auVar354 << 0x18,2);
            auVar1294 = auVar1294 << 0x10;
            uVar1177 = CONCAT13(0,CONCAT12(bVar188,(ushort)*pbVar6));
            auVar10[0xd] = 0;
            auVar10._0_13_ = auVar1294._0_13_;
            auVar10[0xe] = bVar194;
            auVar41[0xc] = *pbVar3;
            auVar41._0_12_ = auVar1294._0_12_;
            auVar41._13_2_ = auVar10._13_2_;
            auVar53[0xb] = 0;
            auVar53._0_11_ = auVar1294._0_11_;
            auVar53._12_3_ = auVar41._12_3_;
            uVar70 = auVar53._11_4_;
            auVar71[10] = bVar191;
            auVar71._0_10_ = auVar1294._0_10_;
            auVar71._11_4_ = uVar70;
            auVar132[9] = 0;
            auVar132._0_9_ = auVar1294._0_9_;
            auVar132._10_5_ = auVar71._10_5_;
            auVar147[8] = *pbVar4;
            auVar147._0_8_ = auVar1294._0_8_;
            auVar147._9_6_ = auVar132._9_6_;
            auVar359._7_8_ = 0;
            auVar359._0_7_ = auVar147._8_7_;
            Var360 = CONCAT81(SUB158(auVar359 << 0x40,7),bVar187);
            auVar846._9_6_ = 0;
            auVar846._0_9_ = Var360;
            auVar361._1_10_ = SUB1510(auVar846 << 0x30,5);
            auVar361[0] = bVar183;
            auVar847._11_4_ = 0;
            auVar847._0_11_ = auVar361;
            auVar362._1_12_ = SUB1512(auVar847 << 0x20,3);
            auVar362[0] = uVar1852;
            auVar159[1] = 0;
            auVar159[0] = auVar1181[0];
            auVar159._2_13_ = auVar362;
            auVar1181 = *(undefined1 (*) [16])(local_78 + 4);
            bVar183 = local_78[0x14];
            bVar185 = local_78[0x16];
            bVar187 = local_78[0x18];
            bVar189 = local_78[0x1a];
            bVar190 = local_78[0x1c];
            bVar191 = local_78[0x1e];
            bVar192 = local_78[0x20];
            auVar1309._0_14_ = auVar1181._0_14_;
            auVar1309[0xe] = auVar1181[7];
            auVar1309[0xf] = local_78[0x1b];
            auVar1308._14_2_ = auVar1309._14_2_;
            auVar1308._0_13_ = auVar1181._0_13_;
            auVar1308[0xd] = bVar189;
            auVar1307._13_3_ = auVar1308._13_3_;
            auVar1307._0_12_ = auVar1181._0_12_;
            auVar1307[0xc] = auVar1181[6];
            auVar1306._12_4_ = auVar1307._12_4_;
            auVar1306._0_11_ = auVar1181._0_11_;
            auVar1306[0xb] = local_78[0x19];
            auVar1305._11_5_ = auVar1306._11_5_;
            auVar1305._0_10_ = auVar1181._0_10_;
            auVar1305[10] = auVar1181[5];
            auVar1304._10_6_ = auVar1305._10_6_;
            auVar1304._0_9_ = auVar1181._0_9_;
            auVar1304[9] = bVar187;
            uVar1176 = auVar1181[4];
            auVar1303._9_7_ = auVar1304._9_7_;
            auVar1303._0_8_ = auVar1181._0_8_;
            auVar1303[8] = uVar1176;
            auVar367._1_8_ = auVar1303._8_8_;
            auVar367[0] = local_78[0x17];
            auVar367._9_7_ = 0;
            auVar366._10_6_ = 0;
            auVar366._0_10_ = SUB1610(auVar367 << 0x38,6);
            auVar365._11_5_ = 0;
            auVar365._0_11_ = SUB1611(auVar366 << 0x30,5);
            auVar364._12_4_ = 0;
            auVar364._0_12_ = SUB1612(auVar365 << 0x28,4);
            auVar363._13_3_ = 0;
            auVar363._0_13_ = SUB1613(auVar364 << 0x20,3);
            auVar1302._14_2_ = 0;
            auVar1302._0_14_ = SUB1614(auVar363 << 0x18,2);
            auVar1302 = auVar1302 << 0x10;
            uVar1852 = auVar1181[8];
            uVar1853 = auVar1181[10];
            auVar1317._0_14_ = auVar1302._0_14_;
            auVar1317[0xe] = local_78[0x17];
            auVar1317[0xf] = local_78[0x1f];
            auVar1316._14_2_ = auVar1317._14_2_;
            auVar1316._0_13_ = auVar1302._0_13_;
            auVar1316[0xd] = auVar1181[0xb];
            auVar1315._13_3_ = auVar1316._13_3_;
            auVar1315._0_12_ = auVar1302._0_12_;
            auVar1315[0xc] = auVar1181[3];
            auVar1314._12_4_ = auVar1315._12_4_;
            auVar1314._0_11_ = auVar1302._0_11_;
            auVar1314[0xb] = bVar191;
            auVar1313._11_5_ = auVar1314._11_5_;
            auVar1313._0_10_ = auVar1302._0_10_;
            auVar1313[10] = bVar185;
            auVar1312._10_6_ = auVar1313._10_6_;
            auVar1312._0_9_ = auVar1302._0_9_;
            auVar1312[9] = uVar1853;
            auVar1311._9_7_ = auVar1312._9_7_;
            auVar1311._0_8_ = auVar1302._0_8_;
            auVar1311[8] = auVar1181[2];
            auVar372._1_8_ = auVar1311._8_8_;
            auVar372[0] = local_78[0x1d];
            auVar372._9_7_ = 0;
            auVar371._10_6_ = 0;
            auVar371._0_10_ = SUB1610(auVar372 << 0x38,6);
            auVar370._11_5_ = 0;
            auVar370._0_11_ = SUB1611(auVar371 << 0x30,5);
            auVar369._12_4_ = 0;
            auVar369._0_12_ = SUB1612(auVar370 << 0x28,4);
            auVar368._13_3_ = 0;
            auVar368._0_13_ = SUB1613(auVar369 << 0x20,3);
            auVar1310._14_2_ = 0;
            auVar1310._0_14_ = SUB1614(auVar368 << 0x18,2);
            auVar1310 = auVar1310 << 0x10;
            auVar1325._0_14_ = auVar1310._0_14_;
            auVar1325[0xe] = local_78[0x1d];
            auVar1325[0xf] = local_78[0x21];
            auVar1324._14_2_ = auVar1325._14_2_;
            auVar1324._0_13_ = auVar1310._0_13_;
            auVar1324[0xd] = local_78[0x19];
            auVar1323._13_3_ = auVar1324._13_3_;
            auVar1323._0_12_ = auVar1310._0_12_;
            auVar1323[0xc] = local_78[0x15];
            auVar1322._12_4_ = auVar1323._12_4_;
            auVar1322._0_11_ = auVar1310._0_11_;
            auVar1322[0xb] = auVar1181[0xd];
            auVar1321._11_5_ = auVar1322._11_5_;
            auVar1321._0_10_ = auVar1310._0_10_;
            auVar1321[10] = auVar1181[9];
            auVar1320._10_6_ = auVar1321._10_6_;
            auVar1320._0_9_ = auVar1310._0_9_;
            auVar1320[9] = auVar1181[5];
            auVar1319._9_7_ = auVar1320._9_7_;
            auVar1319._0_8_ = auVar1310._0_8_;
            auVar1319[8] = auVar1181[1];
            auVar377._1_8_ = auVar1319._8_8_;
            auVar377[0] = bVar192;
            auVar377._9_7_ = 0;
            auVar376._10_6_ = 0;
            auVar376._0_10_ = SUB1610(auVar377 << 0x38,6);
            auVar375._11_5_ = 0;
            auVar375._0_11_ = SUB1611(auVar376 << 0x30,5);
            auVar374._12_4_ = 0;
            auVar374._0_12_ = SUB1612(auVar375 << 0x28,4);
            auVar373._13_3_ = 0;
            auVar373._0_13_ = SUB1613(auVar374 << 0x20,3);
            auVar1318._14_2_ = 0;
            auVar1318._0_14_ = SUB1614(auVar373 << 0x18,2);
            auVar1318 = auVar1318 << 0x10;
            bVar193 = local_78[0x28];
            bVar194 = local_78[0x2c];
            bVar197 = local_78[0x30];
            auVar1333._0_14_ = auVar1318._0_14_;
            auVar1333[0xe] = bVar192;
            auVar1333[0xf] = local_78[0x22];
            auVar1332._14_2_ = auVar1333._14_2_;
            auVar1332._0_13_ = auVar1318._0_13_;
            auVar1332[0xd] = bVar191;
            auVar1331._13_3_ = auVar1332._13_3_;
            auVar1331._0_12_ = auVar1318._0_12_;
            auVar1331[0xc] = bVar190;
            auVar1330._12_4_ = auVar1331._12_4_;
            auVar1330._0_11_ = auVar1318._0_11_;
            auVar1330[0xb] = bVar189;
            auVar1329._11_5_ = auVar1330._11_5_;
            auVar1329._0_10_ = auVar1318._0_10_;
            auVar1329[10] = bVar187;
            auVar1328._10_6_ = auVar1329._10_6_;
            auVar1328._0_9_ = auVar1318._0_9_;
            auVar1328[9] = bVar185;
            auVar1327._9_7_ = auVar1328._9_7_;
            auVar1327._0_8_ = auVar1318._0_8_;
            auVar1327[8] = bVar183;
            auVar382._1_8_ = auVar1327._8_8_;
            auVar382[0] = auVar1181[0xe];
            auVar382._9_7_ = 0;
            auVar381._10_6_ = 0;
            auVar381._0_10_ = SUB1610(auVar382 << 0x38,6);
            auVar380._11_5_ = 0;
            auVar380._0_11_ = SUB1611(auVar381 << 0x30,5);
            auVar379._12_4_ = 0;
            auVar379._0_12_ = SUB1612(auVar380 << 0x28,4);
            auVar378._13_3_ = 0;
            auVar378._0_13_ = SUB1613(auVar379 << 0x20,3);
            auVar1326._14_2_ = 0;
            auVar1326._0_14_ = SUB1614(auVar378 << 0x18,2);
            auVar1326 = auVar1326 << 0x10;
            bVar198 = local_78[0x38];
            bVar199 = local_78[0x3c];
            auVar1341._0_14_ = auVar1326._0_14_;
            auVar1341[0xe] = auVar1181[0xe];
            auVar1341[0xf] = local_78[0x32];
            auVar1340._14_2_ = auVar1341._14_2_;
            auVar1340._0_13_ = auVar1326._0_13_;
            auVar1340[0xd] = bVar197;
            auVar1339._13_3_ = auVar1340._13_3_;
            auVar1339._0_12_ = auVar1326._0_12_;
            auVar1339[0xc] = auVar1181[0xc];
            auVar1338._12_4_ = auVar1339._12_4_;
            auVar1338._0_11_ = auVar1326._0_11_;
            auVar1338[0xb] = local_78[0x2e];
            auVar1337._11_5_ = auVar1338._11_5_;
            auVar1337._0_10_ = auVar1326._0_10_;
            auVar1337[10] = uVar1853;
            auVar1336._10_6_ = auVar1337._10_6_;
            auVar1336._0_9_ = auVar1326._0_9_;
            auVar1336[9] = bVar194;
            auVar1335._9_7_ = auVar1336._9_7_;
            auVar1335._0_8_ = auVar1326._0_8_;
            auVar1335[8] = uVar1852;
            auVar387._1_8_ = auVar1335._8_8_;
            auVar387[0] = local_78[0x2a];
            auVar387._9_7_ = 0;
            auVar386._10_6_ = 0;
            auVar386._0_10_ = SUB1610(auVar387 << 0x38,6);
            auVar385._11_5_ = 0;
            auVar385._0_11_ = SUB1611(auVar386 << 0x30,5);
            auVar384._12_4_ = 0;
            auVar384._0_12_ = SUB1612(auVar385 << 0x28,4);
            auVar383._13_3_ = 0;
            auVar383._0_13_ = SUB1613(auVar384 << 0x20,3);
            auVar1334._14_2_ = 0;
            auVar1334._0_14_ = SUB1614(auVar383 << 0x18,2);
            auVar1334 = auVar1334 << 0x10;
            auVar1349._0_14_ = auVar1334._0_14_;
            auVar1349[0xe] = local_78[0x2a];
            auVar1349[0xf] = local_78[0x3a];
            auVar1348._14_2_ = auVar1349._14_2_;
            auVar1348._0_13_ = auVar1334._0_13_;
            auVar1348[0xd] = bVar189;
            auVar1347._13_3_ = auVar1348._13_3_;
            auVar1347._0_12_ = auVar1334._0_12_;
            auVar1347[0xc] = auVar1181[6];
            auVar1346._12_4_ = auVar1347._12_4_;
            auVar1346._0_11_ = auVar1334._0_11_;
            auVar1346[0xb] = bVar198;
            auVar1345._11_5_ = auVar1346._11_5_;
            auVar1345._0_10_ = auVar1334._0_10_;
            auVar1345[10] = bVar193;
            auVar1344._10_6_ = auVar1345._10_6_;
            auVar1344._0_9_ = auVar1334._0_9_;
            auVar1344[9] = bVar187;
            auVar1343._9_7_ = auVar1344._9_7_;
            auVar1343._0_8_ = auVar1334._0_8_;
            auVar1343[8] = uVar1176;
            auVar392._1_8_ = auVar1343._8_8_;
            auVar392[0] = local_78[0x36];
            auVar392._9_7_ = 0;
            auVar391._10_6_ = 0;
            auVar391._0_10_ = SUB1610(auVar392 << 0x38,6);
            auVar390._11_5_ = 0;
            auVar390._0_11_ = SUB1611(auVar391 << 0x30,5);
            auVar389._12_4_ = 0;
            auVar389._0_12_ = SUB1612(auVar390 << 0x28,4);
            auVar388._13_3_ = 0;
            auVar388._0_13_ = SUB1613(auVar389 << 0x20,3);
            auVar1342._14_2_ = 0;
            auVar1342._0_14_ = SUB1614(auVar388 << 0x18,2);
            auVar1342 = auVar1342 << 0x10;
            auVar1357._0_14_ = auVar1342._0_14_;
            auVar1357[0xe] = local_78[0x36];
            auVar1357[0xf] = local_78[0x3e];
            auVar1356._14_2_ = auVar1357._14_2_;
            auVar1356._0_13_ = auVar1342._0_13_;
            auVar1356[0xd] = local_78[0x2e];
            auVar1355._13_3_ = auVar1356._13_3_;
            auVar1355._0_12_ = auVar1342._0_12_;
            auVar1355[0xc] = local_78[0x26];
            auVar1354._12_4_ = auVar1355._12_4_;
            auVar1354._0_11_ = auVar1342._0_11_;
            auVar1354[0xb] = bVar191;
            auVar1353._11_5_ = auVar1354._11_5_;
            auVar1353._0_10_ = auVar1342._0_10_;
            auVar1353[10] = bVar185;
            auVar1352._10_6_ = auVar1353._10_6_;
            auVar1352._0_9_ = auVar1342._0_9_;
            auVar1352[9] = uVar1853;
            auVar1351._9_7_ = auVar1352._9_7_;
            auVar1351._0_8_ = auVar1342._0_8_;
            auVar1351[8] = auVar1181[2];
            auVar397._1_8_ = auVar1351._8_8_;
            auVar397[0] = bVar199;
            auVar397._9_7_ = 0;
            auVar396._10_6_ = 0;
            auVar396._0_10_ = SUB1610(auVar397 << 0x38,6);
            auVar395._11_5_ = 0;
            auVar395._0_11_ = SUB1611(auVar396 << 0x30,5);
            auVar394._12_4_ = 0;
            auVar394._0_12_ = SUB1612(auVar395 << 0x28,4);
            auVar393._13_3_ = 0;
            auVar393._0_13_ = SUB1613(auVar394 << 0x20,3);
            auVar1350._14_2_ = 0;
            auVar1350._0_14_ = SUB1614(auVar393 << 0x18,2);
            auVar1350 = auVar1350 << 0x10;
            bVar185 = local_78[0x54];
            bVar189 = local_78[0x5c];
            auVar1365._0_14_ = auVar1350._0_14_;
            auVar1365[0xe] = bVar199;
            auVar1365[0xf] = local_78[0x40];
            auVar1364._14_2_ = auVar1365._14_2_;
            auVar1364._0_13_ = auVar1350._0_13_;
            auVar1364[0xd] = bVar198;
            auVar1363._13_3_ = auVar1364._13_3_;
            auVar1363._0_12_ = auVar1350._0_12_;
            auVar1363[0xc] = local_78[0x34];
            auVar1362._12_4_ = auVar1363._12_4_;
            auVar1362._0_11_ = auVar1350._0_11_;
            auVar1362[0xb] = bVar197;
            auVar1361._11_5_ = auVar1362._11_5_;
            auVar1361._0_10_ = auVar1350._0_10_;
            auVar1361[10] = bVar194;
            auVar1360._10_6_ = auVar1361._10_6_;
            auVar1360._0_9_ = auVar1350._0_9_;
            auVar1360[9] = bVar193;
            auVar1359._9_7_ = auVar1360._9_7_;
            auVar1359._0_8_ = auVar1350._0_8_;
            auVar1359[8] = local_78[0x24];
            auVar402._1_8_ = auVar1359._8_8_;
            auVar402[0] = bVar192;
            auVar402._9_7_ = 0;
            auVar401._10_6_ = 0;
            auVar401._0_10_ = SUB1610(auVar402 << 0x38,6);
            auVar400._11_5_ = 0;
            auVar400._0_11_ = SUB1611(auVar401 << 0x30,5);
            auVar399._12_4_ = 0;
            auVar399._0_12_ = SUB1612(auVar400 << 0x28,4);
            auVar398._13_3_ = 0;
            auVar398._0_13_ = SUB1613(auVar399 << 0x20,3);
            auVar1358._14_2_ = 0;
            auVar1358._0_14_ = SUB1614(auVar398 << 0x18,2);
            auVar1358 = auVar1358 << 0x10;
            bVar191 = local_78[0x4c];
            bVar200 = local_78[100];
            bVar201 = local_78[0x6c];
            uVar210 = *(uint *)(local_78 + 0x74);
            uVar211 = *(uint *)(local_78 + 0x7c);
            local_5c = (undefined1)uVar210;
            uStack_58 = (undefined1)*(undefined4 *)(local_78 + 0x78);
            uStack_54 = (undefined1)uVar211;
            auVar1373._0_14_ = auVar1358._0_14_;
            auVar1373[0xe] = bVar192;
            auVar1373[0xf] = local_78[0x60];
            auVar1372._14_2_ = auVar1373._14_2_;
            auVar1372._0_13_ = auVar1358._0_13_;
            auVar1372[0xd] = bVar189;
            auVar1371._13_3_ = auVar1372._13_3_;
            auVar1371._0_12_ = auVar1358._0_12_;
            auVar1371[0xc] = bVar190;
            auVar1370._12_4_ = auVar1371._12_4_;
            auVar1370._0_11_ = auVar1358._0_11_;
            auVar1370[0xb] = local_78[0x58];
            auVar1369._11_5_ = auVar1370._11_5_;
            auVar1369._0_10_ = auVar1358._0_10_;
            auVar1369[10] = bVar187;
            auVar1368._10_6_ = auVar1369._10_6_;
            auVar1368._0_9_ = auVar1358._0_9_;
            auVar1368[9] = bVar185;
            auVar1367._9_7_ = auVar1368._9_7_;
            auVar1367._0_8_ = auVar1358._0_8_;
            auVar1367[8] = bVar183;
            auVar407._1_8_ = auVar1367._8_8_;
            auVar407[0] = local_78[0x50];
            auVar407._9_7_ = 0;
            auVar406._10_6_ = 0;
            auVar406._0_10_ = SUB1610(auVar407 << 0x38,6);
            auVar405._11_5_ = 0;
            auVar405._0_11_ = SUB1611(auVar406 << 0x30,5);
            auVar404._12_4_ = 0;
            auVar404._0_12_ = SUB1612(auVar405 << 0x28,4);
            auVar403._13_3_ = 0;
            auVar403._0_13_ = SUB1613(auVar404 << 0x20,3);
            auVar1366._14_2_ = 0;
            auVar1366._0_14_ = SUB1614(auVar403 << 0x18,2);
            auVar1366 = auVar1366 << 0x10;
            auVar1381._0_14_ = auVar1366._0_14_;
            auVar1381[0xe] = local_78[0x50];
            auVar1381[0xf] = local_78[0x70];
            auVar1380._14_2_ = auVar1381._14_2_;
            auVar1380._0_13_ = auVar1366._0_13_;
            auVar1380[0xd] = bVar197;
            auVar1379._13_3_ = auVar1380._13_3_;
            auVar1379._0_12_ = auVar1366._0_12_;
            auVar1379[0xc] = auVar1181[0xc];
            auVar1378._12_4_ = auVar1379._12_4_;
            auVar1378._0_11_ = auVar1366._0_11_;
            auVar1378[0xb] = bVar201;
            auVar1377._11_5_ = auVar1378._11_5_;
            auVar1377._0_10_ = auVar1366._0_10_;
            auVar1377[10] = bVar191;
            auVar1376._10_6_ = auVar1377._10_6_;
            auVar1376._0_9_ = auVar1366._0_9_;
            auVar1376[9] = bVar194;
            auVar1375._9_7_ = auVar1376._9_7_;
            auVar1375._0_8_ = auVar1366._0_8_;
            auVar1375[8] = uVar1852;
            auVar412._1_8_ = auVar1375._8_8_;
            auVar412[0] = local_78[0x68];
            auVar412._9_7_ = 0;
            auVar411._10_6_ = 0;
            auVar411._0_10_ = SUB1610(auVar412 << 0x38,6);
            auVar410._11_5_ = 0;
            auVar410._0_11_ = SUB1611(auVar411 << 0x30,5);
            auVar409._12_4_ = 0;
            auVar409._0_12_ = SUB1612(auVar410 << 0x28,4);
            auVar408._13_3_ = 0;
            auVar408._0_13_ = SUB1613(auVar409 << 0x20,3);
            auVar1374._14_2_ = 0;
            auVar1374._0_14_ = SUB1614(auVar408 << 0x18,2);
            auVar1374 = auVar1374 << 0x10;
            auVar1389._0_14_ = auVar1374._0_14_;
            auVar1389[0xe] = local_78[0x68];
            auVar1389[0xf] = uStack_58;
            auVar1388._14_2_ = auVar1389._14_2_;
            auVar1388._0_13_ = auVar1374._0_13_;
            auVar1388[0xd] = local_78[0x58];
            auVar1387._13_3_ = auVar1388._13_3_;
            auVar1387._0_12_ = auVar1374._0_12_;
            auVar1387[0xc] = local_78[0x48];
            auVar1386._12_4_ = auVar1387._12_4_;
            auVar1386._0_11_ = auVar1374._0_11_;
            auVar1386[0xb] = bVar198;
            auVar1385._11_5_ = auVar1386._11_5_;
            auVar1385._0_10_ = auVar1374._0_10_;
            auVar1385[10] = bVar193;
            auVar1384._10_6_ = auVar1385._10_6_;
            auVar1384._0_9_ = auVar1374._0_9_;
            auVar1384[9] = bVar187;
            auVar1383._9_7_ = auVar1384._9_7_;
            auVar1383._0_8_ = auVar1374._0_8_;
            auVar1383[8] = uVar1176;
            auVar417._1_8_ = auVar1383._8_8_;
            auVar417[0] = local_5c;
            auVar417._9_7_ = 0;
            auVar416._10_6_ = 0;
            auVar416._0_10_ = SUB1610(auVar417 << 0x38,6);
            auVar415._11_5_ = 0;
            auVar415._0_11_ = SUB1611(auVar416 << 0x30,5);
            auVar414._12_4_ = 0;
            auVar414._0_12_ = SUB1612(auVar415 << 0x28,4);
            auVar413._13_3_ = 0;
            auVar413._0_13_ = SUB1613(auVar414 << 0x20,3);
            auVar1382._14_2_ = 0;
            auVar1382._0_14_ = SUB1614(auVar413 << 0x18,2);
            auVar1382 = auVar1382 << 0x10;
            auVar1397._0_14_ = auVar1382._0_14_;
            auVar1397[0xe] = local_5c;
            auVar1397[0xf] = uStack_54;
            auVar1396._14_2_ = auVar1397._14_2_;
            auVar1396._0_13_ = auVar1382._0_13_;
            auVar1396[0xd] = bVar201;
            auVar1395._13_3_ = auVar1396._13_3_;
            auVar1395._0_12_ = auVar1382._0_12_;
            auVar1395[0xc] = bVar200;
            auVar1394._12_4_ = auVar1395._12_4_;
            auVar1394._0_11_ = auVar1382._0_11_;
            auVar1394[0xb] = bVar189;
            auVar1393._11_5_ = auVar1394._11_5_;
            auVar1393._0_10_ = auVar1382._0_10_;
            auVar1393[10] = bVar185;
            auVar1392._10_6_ = auVar1393._10_6_;
            auVar1392._0_9_ = auVar1382._0_9_;
            auVar1392[9] = bVar191;
            auVar1391._9_7_ = auVar1392._9_7_;
            auVar1391._0_8_ = auVar1382._0_8_;
            auVar1391[8] = local_78[0x44];
            auVar422._1_8_ = auVar1391._8_8_;
            auVar422[0] = bVar199;
            auVar422._9_7_ = 0;
            auVar421._10_6_ = 0;
            auVar421._0_10_ = SUB1610(auVar422 << 0x38,6);
            auVar420._11_5_ = 0;
            auVar420._0_11_ = SUB1611(auVar421 << 0x30,5);
            auVar419._12_4_ = 0;
            auVar419._0_12_ = SUB1612(auVar420 << 0x28,4);
            auVar418._13_3_ = 0;
            auVar418._0_13_ = SUB1613(auVar419 << 0x20,3);
            auVar1390._14_2_ = 0;
            auVar1390._0_14_ = SUB1614(auVar418 << 0x18,2);
            auVar1390 = auVar1390 << 0x10;
            auVar11._10_2_ = 0;
            auVar11._0_10_ = auVar158._0_10_;
            auVar11._12_2_ = (short)Var296;
            uVar903 = CONCAT42(auVar11._10_4_,auVar297._0_2_);
            auVar423._6_8_ = 0;
            auVar423._0_6_ = uVar903;
            auVar72._4_2_ = auVar298._0_2_;
            auVar72._0_4_ = auVar158._0_4_;
            auVar72._6_8_ = SUB148(auVar423 << 0x40,6);
            uVar1178 = CONCAT13(0,CONCAT12(bVar191,(ushort)local_78[0x44]));
            auVar12._10_2_ = 0;
            auVar12._0_10_ = auVar157._0_10_;
            auVar12._12_2_ = (short)Var293;
            uVar904 = CONCAT42(auVar12._10_4_,auVar294._0_2_);
            auVar424._6_8_ = 0;
            auVar424._0_6_ = uVar904;
            auVar73._4_2_ = auVar902._0_2_;
            auVar73._0_4_ = auVar157._0_4_;
            auVar73._6_8_ = SUB148(auVar424 << 0x40,6);
            auVar13._10_2_ = 0;
            auVar13._0_10_ = auVar159._0_10_;
            auVar13._12_2_ = (short)Var360;
            uVar905 = CONCAT42(auVar13._10_4_,auVar361._0_2_);
            auVar425._6_8_ = 0;
            auVar425._0_6_ = uVar905;
            auVar74._4_2_ = auVar362._0_2_;
            auVar74._0_4_ = auVar159._0_4_;
            auVar74._6_8_ = SUB148(auVar425 << 0x40,6);
            uStack_114 = auVar146._8_2_;
            uStack_112 = auVar69._10_2_;
            auVar14[0xd] = 0;
            auVar14._0_13_ = auVar1390._0_13_;
            auVar14[0xe] = bVar199;
            auVar42[0xc] = local_78[0x34];
            auVar42._0_12_ = auVar1390._0_12_;
            auVar42._13_2_ = auVar14._13_2_;
            auVar54[0xb] = 0;
            auVar54._0_11_ = auVar1390._0_11_;
            auVar54._12_3_ = auVar42._12_3_;
            uVar75 = auVar54._11_4_;
            auVar76[10] = bVar194;
            auVar76._0_10_ = auVar1390._0_10_;
            auVar76._11_4_ = uVar75;
            auVar133[9] = 0;
            auVar133._0_9_ = auVar1390._0_9_;
            auVar133._10_5_ = auVar76._10_5_;
            auVar148[8] = local_78[0x24];
            auVar148._0_8_ = auVar1390._0_8_;
            auVar148._9_6_ = auVar133._9_6_;
            auVar426._7_8_ = 0;
            auVar426._0_7_ = auVar148._8_7_;
            Var293 = CONCAT81(SUB158(auVar426 << 0x40,7),bVar190);
            auVar848._9_6_ = 0;
            auVar848._0_9_ = Var293;
            auVar427._1_10_ = SUB1510(auVar848 << 0x30,5);
            auVar427[0] = bVar183;
            auVar849._11_4_ = 0;
            auVar849._0_11_ = auVar427;
            auVar428._1_12_ = SUB1512(auVar849 << 0x20,3);
            auVar428[0] = uVar1852;
            auVar160[1] = 0;
            auVar160[0] = auVar1181[0];
            auVar160._2_13_ = auVar428;
            uVar1858 = (uint)uStack_114;
            auVar15._10_2_ = 0;
            auVar15._0_10_ = auVar160._0_10_;
            auVar15._12_2_ = (short)Var293;
            uVar906 = CONCAT42(auVar15._10_4_,auVar427._0_2_);
            auVar429._6_8_ = 0;
            auVar429._0_6_ = uVar906;
            auVar77._4_2_ = auVar428._0_2_;
            auVar77._0_4_ = auVar160._0_4_;
            auVar77._6_8_ = SUB148(auVar429 << 0x40,6);
            uStack_a4 = (ushort)((ulonglong)uVar927 >> 8);
            uStack_a2 = (ushort)((ulonglong)uVar928 >> 0x18);
            uVar1179 = (uint)uStack_a4;
            uVar1590 = (uint)uStack_a2;
            uVar1864 = (uint)uStack_112;
            uStack_94 = auVar147._8_2_;
            uStack_92 = auVar71._10_2_;
            uVar1859 = (uint)uStack_94;
            uVar1865 = (uint)uStack_92;
            auVar874[0xc] = (undefined1)uStack_d4;
            auVar874._0_12_ = ZEXT112(local_ec) << 0x40;
            auVar875._10_3_ = auVar874._10_3_;
            auVar875._0_10_ = (unkuint10)local_dc << 0x40;
            auVar78[4] = uStack_f4;
            auVar78._0_4_ = uVar1822;
            auVar78[5] = 0;
            auVar78._6_8_ = SUB148(ZEXT514(auVar875._8_5_) << 0x40,6);
            auVar876[0xc] = uStack_d0;
            auVar876._0_12_ = ZEXT112(bStack_e8) << 0x40;
            auVar877._10_3_ = auVar876._10_3_;
            auVar877._0_10_ = (unkuint10)bStack_d8 << 0x40;
            auVar79[4] = uStack_f0;
            auVar79._0_4_ = uVar1823;
            auVar79[5] = 0;
            auVar79._6_8_ = SUB148(ZEXT514(auVar877._8_5_) << 0x40,6);
            auVar878[0xc] = bVar186;
            auVar878._0_12_ = ZEXT112(bVar195) << 0x40;
            auVar879._10_3_ = auVar878._10_3_;
            auVar879._0_10_ = (unkuint10)bVar184 << 0x40;
            auVar80[4] = bVar188;
            auVar80._0_4_ = uVar1177;
            auVar80[5] = 0;
            auVar80._6_8_ = SUB148(ZEXT514(auVar879._8_5_) << 0x40,6);
            auVar880[0xc] = bVar189;
            auVar880._0_12_ = ZEXT112(bVar200) << 0x40;
            auVar881._10_3_ = auVar880._10_3_;
            auVar881._0_10_ = (unkuint10)bVar185 << 0x40;
            auVar81[4] = bVar191;
            auVar81._0_4_ = uVar1178;
            auVar81[5] = 0;
            auVar81._6_8_ = SUB148(ZEXT514(auVar881._8_5_) << 0x40,6);
            uVar1851 = (uint)(byte)uStack_e4;
            uVar1824 = CONCAT13(0,CONCAT12(uStack_ef,(ushort)bStack_f7));
            uVar1591 = CONCAT13(0,CONCAT12(uStack_f3,(ushort)bStack_fb));
            auVar16[0xd] = 0;
            auVar16._0_13_ = auVar1620._0_13_;
            auVar16[0xe] = uStack_103;
            auVar43[0xc] = uStack_10b;
            auVar43._0_12_ = auVar1620._0_12_;
            auVar43._13_2_ = auVar16._13_2_;
            auVar55[0xb] = 0;
            auVar55._0_11_ = auVar1620._0_11_;
            auVar55._12_3_ = auVar43._12_3_;
            uVar82 = auVar55._11_4_;
            auVar83[10] = bVar180;
            auVar83._0_10_ = auVar1620._0_10_;
            auVar83._11_4_ = uVar82;
            auVar134[9] = 0;
            auVar134._0_9_ = auVar1620._0_9_;
            auVar134._10_5_ = auVar83._10_5_;
            auVar149[8] = pbVar2[1];
            auVar149._0_8_ = auVar1620._0_8_;
            auVar149._9_6_ = auVar134._9_6_;
            auVar430._7_8_ = 0;
            auVar430._0_7_ = auVar149._8_7_;
            Var293 = CONCAT81(SUB158(auVar430 << 0x40,7),uStack_b4._1_1_);
            auVar850._9_6_ = 0;
            auVar850._0_9_ = Var293;
            auVar431._1_10_ = SUB1510(auVar850 << 0x30,5);
            auVar431[0] = uStack_bb;
            auVar851._11_4_ = 0;
            auVar851._0_11_ = auVar431;
            auVar432._1_12_ = SUB1512(auVar851 << 0x20,3);
            auVar432[0] = bVar174;
            auVar161[1] = 0;
            auVar161[0] = pbVar1[1];
            auVar161._2_13_ = auVar432;
            auVar1181 = *(undefined1 (*) [16])(local_7c + 1);
            auVar936._6_8_ = 0;
            auVar17[0xe] = uStack_ff;
            auVar17._0_14_ = auVar936 << 0x38;
            auVar837._4_8_ = 0;
            auVar837._0_4_ = uVar84;
            auVar56._12_3_ = (int3)(CONCAT26(auVar17._13_2_,CONCAT15(uStack_107,uVar930)) >> 0x28);
            auVar56._0_12_ = auVar837 << 0x38;
            uVar84 = auVar56._11_4_;
            uVar928 = CONCAT44(uVar84,CONCAT13(bVar182,uVar924));
            auVar135._10_5_ = (int5)((ulonglong)uVar928 >> 0x18);
            auVar135._0_10_ = (unkuint10)CONCAT11(bStack_f7,uStack_ff) << 0x38;
            uVar927 = CONCAT62(auVar135._9_6_,CONCAT11(bVar178,uStack_ff));
            auVar433._7_8_ = 0;
            auVar433._0_7_ = (uint7)((ulonglong)uVar927 >> 8);
            Var296 = CONCAT81(SUB158(auVar433 << 0x40,7),uStack_af);
            auVar852._9_6_ = 0;
            auVar852._0_9_ = Var296;
            auVar434._1_10_ = SUB1510(auVar852 << 0x30,5);
            auVar434[0] = uStack_b7;
            auVar853._11_4_ = 0;
            auVar853._0_11_ = auVar434;
            auVar907._1_12_ = SUB1512(auVar853 << 0x20,3);
            auVar907[0] = bVar176;
            auVar162[1] = 0;
            auVar162[0] = bVar173;
            auVar162._2_13_ = auVar907;
            bVar173 = local_7c[0x11];
            bVar174 = local_7c[0x13];
            bVar176 = local_7c[0x15];
            bVar178 = local_7c[0x17];
            bVar180 = local_7c[0x19];
            bVar182 = local_7c[0x1b];
            bVar183 = local_7c[0x1d];
            uVar1852 = auVar1181[8];
            uVar1853 = auVar1181[10];
            auVar1405._0_14_ = auVar1181._0_14_;
            auVar1405[0xe] = auVar1181[7];
            auVar1405[0xf] = local_7c[0x18];
            auVar1404._14_2_ = auVar1405._14_2_;
            auVar1404._0_13_ = auVar1181._0_13_;
            auVar1404[0xd] = bVar178;
            auVar1403._13_3_ = auVar1404._13_3_;
            auVar1403._0_12_ = auVar1181._0_12_;
            auVar1403[0xc] = auVar1181[6];
            auVar1402._12_4_ = auVar1403._12_4_;
            auVar1402._0_11_ = auVar1181._0_11_;
            auVar1402[0xb] = local_7c[0x16];
            auVar1401._11_5_ = auVar1402._11_5_;
            auVar1401._0_10_ = auVar1181._0_10_;
            auVar1401[10] = auVar1181[5];
            auVar1400._10_6_ = auVar1401._10_6_;
            auVar1400._0_9_ = auVar1181._0_9_;
            auVar1400[9] = bVar176;
            uVar1176 = auVar1181[4];
            auVar1399._9_7_ = auVar1400._9_7_;
            auVar1399._0_8_ = auVar1181._0_8_;
            auVar1399[8] = uVar1176;
            auVar439._1_8_ = auVar1399._8_8_;
            auVar439[0] = local_7c[0x14];
            auVar439._9_7_ = 0;
            auVar438._10_6_ = 0;
            auVar438._0_10_ = SUB1610(auVar439 << 0x38,6);
            auVar437._11_5_ = 0;
            auVar437._0_11_ = SUB1611(auVar438 << 0x30,5);
            auVar436._12_4_ = 0;
            auVar436._0_12_ = SUB1612(auVar437 << 0x28,4);
            auVar435._13_3_ = 0;
            auVar435._0_13_ = SUB1613(auVar436 << 0x20,3);
            auVar1398._14_2_ = 0;
            auVar1398._0_14_ = SUB1614(auVar435 << 0x18,2);
            auVar1398 = auVar1398 << 0x10;
            auVar1413._0_14_ = auVar1398._0_14_;
            auVar1413[0xe] = local_7c[0x14];
            auVar1413[0xf] = local_7c[0x1c];
            auVar1412._14_2_ = auVar1413._14_2_;
            auVar1412._0_13_ = auVar1398._0_13_;
            auVar1412[0xd] = auVar1181[0xb];
            auVar1411._13_3_ = auVar1412._13_3_;
            auVar1411._0_12_ = auVar1398._0_12_;
            auVar1411[0xc] = auVar1181[3];
            auVar1410._12_4_ = auVar1411._12_4_;
            auVar1410._0_11_ = auVar1398._0_11_;
            auVar1410[0xb] = bVar182;
            auVar1409._11_5_ = auVar1410._11_5_;
            auVar1409._0_10_ = auVar1398._0_10_;
            auVar1409[10] = bVar174;
            auVar1408._10_6_ = auVar1409._10_6_;
            auVar1408._0_9_ = auVar1398._0_9_;
            auVar1408[9] = uVar1853;
            auVar1407._9_7_ = auVar1408._9_7_;
            auVar1407._0_8_ = auVar1398._0_8_;
            auVar1407[8] = auVar1181[2];
            auVar444._1_8_ = auVar1407._8_8_;
            auVar444[0] = local_7c[0x1a];
            auVar444._9_7_ = 0;
            auVar443._10_6_ = 0;
            auVar443._0_10_ = SUB1610(auVar444 << 0x38,6);
            auVar442._11_5_ = 0;
            auVar442._0_11_ = SUB1611(auVar443 << 0x30,5);
            auVar441._12_4_ = 0;
            auVar441._0_12_ = SUB1612(auVar442 << 0x28,4);
            auVar440._13_3_ = 0;
            auVar440._0_13_ = SUB1613(auVar441 << 0x20,3);
            auVar1406._14_2_ = 0;
            auVar1406._0_14_ = SUB1614(auVar440 << 0x18,2);
            auVar1406 = auVar1406 << 0x10;
            auVar1421._0_14_ = auVar1406._0_14_;
            auVar1421[0xe] = local_7c[0x1a];
            auVar1421[0xf] = local_7c[0x1e];
            auVar1420._14_2_ = auVar1421._14_2_;
            auVar1420._0_13_ = auVar1406._0_13_;
            auVar1420[0xd] = local_7c[0x16];
            auVar1419._13_3_ = auVar1420._13_3_;
            auVar1419._0_12_ = auVar1406._0_12_;
            auVar1419[0xc] = local_7c[0x12];
            auVar1418._12_4_ = auVar1419._12_4_;
            auVar1418._0_11_ = auVar1406._0_11_;
            auVar1418[0xb] = auVar1181[0xd];
            auVar1417._11_5_ = auVar1418._11_5_;
            auVar1417._0_10_ = auVar1406._0_10_;
            auVar1417[10] = auVar1181[9];
            auVar1416._10_6_ = auVar1417._10_6_;
            auVar1416._0_9_ = auVar1406._0_9_;
            auVar1416[9] = auVar1181[5];
            auVar1415._9_7_ = auVar1416._9_7_;
            auVar1415._0_8_ = auVar1406._0_8_;
            auVar1415[8] = auVar1181[1];
            auVar449._1_8_ = auVar1415._8_8_;
            auVar449[0] = bVar183;
            auVar449._9_7_ = 0;
            auVar448._10_6_ = 0;
            auVar448._0_10_ = SUB1610(auVar449 << 0x38,6);
            auVar447._11_5_ = 0;
            auVar447._0_11_ = SUB1611(auVar448 << 0x30,5);
            auVar446._12_4_ = 0;
            auVar446._0_12_ = SUB1612(auVar447 << 0x28,4);
            auVar445._13_3_ = 0;
            auVar445._0_13_ = SUB1613(auVar446 << 0x20,3);
            auVar1414._14_2_ = 0;
            auVar1414._0_14_ = SUB1614(auVar445 << 0x18,2);
            auVar1414 = auVar1414 << 0x10;
            bVar184 = local_7c[0x25];
            bVar185 = local_7c[0x29];
            bVar186 = local_7c[0x2d];
            auVar1429._0_14_ = auVar1414._0_14_;
            auVar1429[0xe] = bVar183;
            auVar1429[0xf] = local_7c[0x1f];
            auVar1428._14_2_ = auVar1429._14_2_;
            auVar1428._0_13_ = auVar1414._0_13_;
            auVar1428[0xd] = bVar182;
            auVar1427._13_3_ = auVar1428._13_3_;
            auVar1427._0_12_ = auVar1414._0_12_;
            auVar1427[0xc] = bVar180;
            auVar1426._12_4_ = auVar1427._12_4_;
            auVar1426._0_11_ = auVar1414._0_11_;
            auVar1426[0xb] = bVar178;
            auVar1425._11_5_ = auVar1426._11_5_;
            auVar1425._0_10_ = auVar1414._0_10_;
            auVar1425[10] = bVar176;
            auVar1424._10_6_ = auVar1425._10_6_;
            auVar1424._0_9_ = auVar1414._0_9_;
            auVar1424[9] = bVar174;
            auVar1423._9_7_ = auVar1424._9_7_;
            auVar1423._0_8_ = auVar1414._0_8_;
            auVar1423[8] = bVar173;
            auVar454._1_8_ = auVar1423._8_8_;
            auVar454[0] = auVar1181[0xe];
            auVar454._9_7_ = 0;
            auVar453._10_6_ = 0;
            auVar453._0_10_ = SUB1610(auVar454 << 0x38,6);
            auVar452._11_5_ = 0;
            auVar452._0_11_ = SUB1611(auVar453 << 0x30,5);
            auVar451._12_4_ = 0;
            auVar451._0_12_ = SUB1612(auVar452 << 0x28,4);
            auVar450._13_3_ = 0;
            auVar450._0_13_ = SUB1613(auVar451 << 0x20,3);
            auVar1422._14_2_ = 0;
            auVar1422._0_14_ = SUB1614(auVar450 << 0x18,2);
            auVar1422 = auVar1422 << 0x10;
            bVar187 = local_7c[0x35];
            bVar188 = local_7c[0x39];
            auVar1437._0_14_ = auVar1422._0_14_;
            auVar1437[0xe] = auVar1181[0xe];
            auVar1437[0xf] = local_7c[0x2f];
            auVar1436._14_2_ = auVar1437._14_2_;
            auVar1436._0_13_ = auVar1422._0_13_;
            auVar1436[0xd] = bVar186;
            auVar1435._13_3_ = auVar1436._13_3_;
            auVar1435._0_12_ = auVar1422._0_12_;
            auVar1435[0xc] = auVar1181[0xc];
            auVar1434._12_4_ = auVar1435._12_4_;
            auVar1434._0_11_ = auVar1422._0_11_;
            auVar1434[0xb] = local_7c[0x2b];
            auVar1433._11_5_ = auVar1434._11_5_;
            auVar1433._0_10_ = auVar1422._0_10_;
            auVar1433[10] = uVar1853;
            auVar1432._10_6_ = auVar1433._10_6_;
            auVar1432._0_9_ = auVar1422._0_9_;
            auVar1432[9] = bVar185;
            auVar1431._9_7_ = auVar1432._9_7_;
            auVar1431._0_8_ = auVar1422._0_8_;
            auVar1431[8] = uVar1852;
            auVar459._1_8_ = auVar1431._8_8_;
            auVar459[0] = local_7c[0x27];
            auVar459._9_7_ = 0;
            auVar458._10_6_ = 0;
            auVar458._0_10_ = SUB1610(auVar459 << 0x38,6);
            auVar457._11_5_ = 0;
            auVar457._0_11_ = SUB1611(auVar458 << 0x30,5);
            auVar456._12_4_ = 0;
            auVar456._0_12_ = SUB1612(auVar457 << 0x28,4);
            auVar455._13_3_ = 0;
            auVar455._0_13_ = SUB1613(auVar456 << 0x20,3);
            auVar1430._14_2_ = 0;
            auVar1430._0_14_ = SUB1614(auVar455 << 0x18,2);
            auVar1430 = auVar1430 << 0x10;
            auVar1445._0_14_ = auVar1430._0_14_;
            auVar1445[0xe] = local_7c[0x27];
            auVar1445[0xf] = local_7c[0x37];
            auVar1444._14_2_ = auVar1445._14_2_;
            auVar1444._0_13_ = auVar1430._0_13_;
            auVar1444[0xd] = bVar178;
            auVar1443._13_3_ = auVar1444._13_3_;
            auVar1443._0_12_ = auVar1430._0_12_;
            auVar1443[0xc] = auVar1181[6];
            auVar1442._12_4_ = auVar1443._12_4_;
            auVar1442._0_11_ = auVar1430._0_11_;
            auVar1442[0xb] = bVar187;
            auVar1441._11_5_ = auVar1442._11_5_;
            auVar1441._0_10_ = auVar1430._0_10_;
            auVar1441[10] = bVar184;
            auVar1440._10_6_ = auVar1441._10_6_;
            auVar1440._0_9_ = auVar1430._0_9_;
            auVar1440[9] = bVar176;
            auVar1439._9_7_ = auVar1440._9_7_;
            auVar1439._0_8_ = auVar1430._0_8_;
            auVar1439[8] = uVar1176;
            auVar464._1_8_ = auVar1439._8_8_;
            auVar464[0] = local_7c[0x33];
            auVar464._9_7_ = 0;
            auVar463._10_6_ = 0;
            auVar463._0_10_ = SUB1610(auVar464 << 0x38,6);
            auVar462._11_5_ = 0;
            auVar462._0_11_ = SUB1611(auVar463 << 0x30,5);
            auVar461._12_4_ = 0;
            auVar461._0_12_ = SUB1612(auVar462 << 0x28,4);
            auVar460._13_3_ = 0;
            auVar460._0_13_ = SUB1613(auVar461 << 0x20,3);
            auVar1438._14_2_ = 0;
            auVar1438._0_14_ = SUB1614(auVar460 << 0x18,2);
            auVar1438 = auVar1438 << 0x10;
            auVar1453._0_14_ = auVar1438._0_14_;
            auVar1453[0xe] = local_7c[0x33];
            auVar1453[0xf] = local_7c[0x3b];
            auVar1452._14_2_ = auVar1453._14_2_;
            auVar1452._0_13_ = auVar1438._0_13_;
            auVar1452[0xd] = local_7c[0x2b];
            auVar1451._13_3_ = auVar1452._13_3_;
            auVar1451._0_12_ = auVar1438._0_12_;
            auVar1451[0xc] = local_7c[0x23];
            auVar1450._12_4_ = auVar1451._12_4_;
            auVar1450._0_11_ = auVar1438._0_11_;
            auVar1450[0xb] = bVar182;
            auVar1449._11_5_ = auVar1450._11_5_;
            auVar1449._0_10_ = auVar1438._0_10_;
            auVar1449[10] = bVar174;
            auVar1448._10_6_ = auVar1449._10_6_;
            auVar1448._0_9_ = auVar1438._0_9_;
            auVar1448[9] = uVar1853;
            auVar1447._9_7_ = auVar1448._9_7_;
            auVar1447._0_8_ = auVar1438._0_8_;
            auVar1447[8] = auVar1181[2];
            auVar469._1_8_ = auVar1447._8_8_;
            auVar469[0] = bVar188;
            auVar469._9_7_ = 0;
            auVar468._10_6_ = 0;
            auVar468._0_10_ = SUB1610(auVar469 << 0x38,6);
            auVar467._11_5_ = 0;
            auVar467._0_11_ = SUB1611(auVar468 << 0x30,5);
            auVar466._12_4_ = 0;
            auVar466._0_12_ = SUB1612(auVar467 << 0x28,4);
            auVar465._13_3_ = 0;
            auVar465._0_13_ = SUB1613(auVar466 << 0x20,3);
            auVar1446._14_2_ = 0;
            auVar1446._0_14_ = SUB1614(auVar465 << 0x18,2);
            auVar1446 = auVar1446 << 0x10;
            bVar174 = local_7c[0x51];
            bVar178 = local_7c[0x59];
            auVar1461._0_14_ = auVar1446._0_14_;
            auVar1461[0xe] = bVar188;
            auVar1461[0xf] = local_7c[0x3d];
            auVar1460._14_2_ = auVar1461._14_2_;
            auVar1460._0_13_ = auVar1446._0_13_;
            auVar1460[0xd] = bVar187;
            auVar1459._13_3_ = auVar1460._13_3_;
            auVar1459._0_12_ = auVar1446._0_12_;
            auVar1459[0xc] = local_7c[0x31];
            auVar1458._12_4_ = auVar1459._12_4_;
            auVar1458._0_11_ = auVar1446._0_11_;
            auVar1458[0xb] = bVar186;
            auVar1457._11_5_ = auVar1458._11_5_;
            auVar1457._0_10_ = auVar1446._0_10_;
            auVar1457[10] = bVar185;
            auVar1456._10_6_ = auVar1457._10_6_;
            auVar1456._0_9_ = auVar1446._0_9_;
            auVar1456[9] = bVar184;
            auVar1455._9_7_ = auVar1456._9_7_;
            auVar1455._0_8_ = auVar1446._0_8_;
            auVar1455[8] = local_7c[0x21];
            auVar474._1_8_ = auVar1455._8_8_;
            auVar474[0] = bVar183;
            auVar474._9_7_ = 0;
            auVar473._10_6_ = 0;
            auVar473._0_10_ = SUB1610(auVar474 << 0x38,6);
            auVar472._11_5_ = 0;
            auVar472._0_11_ = SUB1611(auVar473 << 0x30,5);
            auVar471._12_4_ = 0;
            auVar471._0_12_ = SUB1612(auVar472 << 0x28,4);
            auVar470._13_3_ = 0;
            auVar470._0_13_ = SUB1613(auVar471 << 0x20,3);
            auVar1454._14_2_ = 0;
            auVar1454._0_14_ = SUB1614(auVar470 << 0x18,2);
            auVar1454 = auVar1454 << 0x10;
            bVar182 = local_7c[0x49];
            bVar189 = local_7c[0x61];
            bVar190 = local_7c[0x69];
            bVar191 = local_7c[0x71];
            bVar192 = local_7c[0x79];
            auVar1469._0_14_ = auVar1454._0_14_;
            auVar1469[0xe] = bVar183;
            auVar1469[0xf] = local_7c[0x5d];
            auVar1468._14_2_ = auVar1469._14_2_;
            auVar1468._0_13_ = auVar1454._0_13_;
            auVar1468[0xd] = bVar178;
            auVar1467._13_3_ = auVar1468._13_3_;
            auVar1467._0_12_ = auVar1454._0_12_;
            auVar1467[0xc] = bVar180;
            auVar1466._12_4_ = auVar1467._12_4_;
            auVar1466._0_11_ = auVar1454._0_11_;
            auVar1466[0xb] = local_7c[0x55];
            auVar1465._11_5_ = auVar1466._11_5_;
            auVar1465._0_10_ = auVar1454._0_10_;
            auVar1465[10] = bVar176;
            auVar1464._10_6_ = auVar1465._10_6_;
            auVar1464._0_9_ = auVar1454._0_9_;
            auVar1464[9] = bVar174;
            auVar1463._9_7_ = auVar1464._9_7_;
            auVar1463._0_8_ = auVar1454._0_8_;
            auVar1463[8] = bVar173;
            auVar479._1_8_ = auVar1463._8_8_;
            auVar479[0] = local_7c[0x4d];
            auVar479._9_7_ = 0;
            auVar478._10_6_ = 0;
            auVar478._0_10_ = SUB1610(auVar479 << 0x38,6);
            auVar477._11_5_ = 0;
            auVar477._0_11_ = SUB1611(auVar478 << 0x30,5);
            auVar476._12_4_ = 0;
            auVar476._0_12_ = SUB1612(auVar477 << 0x28,4);
            auVar475._13_3_ = 0;
            auVar475._0_13_ = SUB1613(auVar476 << 0x20,3);
            auVar1462._14_2_ = 0;
            auVar1462._0_14_ = SUB1614(auVar475 << 0x18,2);
            auVar1462 = auVar1462 << 0x10;
            auVar1477._0_14_ = auVar1462._0_14_;
            auVar1477[0xe] = local_7c[0x4d];
            auVar1477[0xf] = local_7c[0x6d];
            auVar1476._14_2_ = auVar1477._14_2_;
            auVar1476._0_13_ = auVar1462._0_13_;
            auVar1476[0xd] = bVar186;
            auVar1475._13_3_ = auVar1476._13_3_;
            auVar1475._0_12_ = auVar1462._0_12_;
            auVar1475[0xc] = auVar1181[0xc];
            auVar1474._12_4_ = auVar1475._12_4_;
            auVar1474._0_11_ = auVar1462._0_11_;
            auVar1474[0xb] = bVar190;
            auVar1473._11_5_ = auVar1474._11_5_;
            auVar1473._0_10_ = auVar1462._0_10_;
            auVar1473[10] = bVar182;
            auVar1472._10_6_ = auVar1473._10_6_;
            auVar1472._0_9_ = auVar1462._0_9_;
            auVar1472[9] = bVar185;
            auVar1471._9_7_ = auVar1472._9_7_;
            auVar1471._0_8_ = auVar1462._0_8_;
            auVar1471[8] = uVar1852;
            auVar484._1_8_ = auVar1471._8_8_;
            auVar484[0] = local_7c[0x65];
            auVar484._9_7_ = 0;
            auVar483._10_6_ = 0;
            auVar483._0_10_ = SUB1610(auVar484 << 0x38,6);
            auVar482._11_5_ = 0;
            auVar482._0_11_ = SUB1611(auVar483 << 0x30,5);
            auVar481._12_4_ = 0;
            auVar481._0_12_ = SUB1612(auVar482 << 0x28,4);
            auVar480._13_3_ = 0;
            auVar480._0_13_ = SUB1613(auVar481 << 0x20,3);
            auVar1470._14_2_ = 0;
            auVar1470._0_14_ = SUB1614(auVar480 << 0x18,2);
            auVar1470 = auVar1470 << 0x10;
            auVar1485._0_14_ = auVar1470._0_14_;
            auVar1485[0xe] = local_7c[0x65];
            auVar1485[0xf] = local_7c[0x75];
            auVar1484._14_2_ = auVar1485._14_2_;
            auVar1484._0_13_ = auVar1470._0_13_;
            auVar1484[0xd] = local_7c[0x55];
            auVar1483._13_3_ = auVar1484._13_3_;
            auVar1483._0_12_ = auVar1470._0_12_;
            auVar1483[0xc] = local_7c[0x45];
            auVar1482._12_4_ = auVar1483._12_4_;
            auVar1482._0_11_ = auVar1470._0_11_;
            auVar1482[0xb] = bVar187;
            auVar1481._11_5_ = auVar1482._11_5_;
            auVar1481._0_10_ = auVar1470._0_10_;
            auVar1481[10] = bVar184;
            auVar1480._10_6_ = auVar1481._10_6_;
            auVar1480._0_9_ = auVar1470._0_9_;
            auVar1480[9] = bVar176;
            auVar1479._9_7_ = auVar1480._9_7_;
            auVar1479._0_8_ = auVar1470._0_8_;
            auVar1479[8] = uVar1176;
            auVar489._1_8_ = auVar1479._8_8_;
            auVar489[0] = bVar191;
            auVar489._9_7_ = 0;
            auVar488._10_6_ = 0;
            auVar488._0_10_ = SUB1610(auVar489 << 0x38,6);
            auVar487._11_5_ = 0;
            auVar487._0_11_ = SUB1611(auVar488 << 0x30,5);
            auVar486._12_4_ = 0;
            auVar486._0_12_ = SUB1612(auVar487 << 0x28,4);
            auVar485._13_3_ = 0;
            auVar485._0_13_ = SUB1613(auVar486 << 0x20,3);
            auVar1478._14_2_ = 0;
            auVar1478._0_14_ = SUB1614(auVar485 << 0x18,2);
            auVar1478 = auVar1478 << 0x10;
            auVar1493._0_14_ = auVar1478._0_14_;
            auVar1493[0xe] = bVar191;
            auVar1493[0xf] = bVar192;
            auVar1492._14_2_ = auVar1493._14_2_;
            auVar1492._0_13_ = auVar1478._0_13_;
            auVar1492[0xd] = bVar190;
            auVar1491._13_3_ = auVar1492._13_3_;
            auVar1491._0_12_ = auVar1478._0_12_;
            auVar1491[0xc] = bVar189;
            auVar1490._12_4_ = auVar1491._12_4_;
            auVar1490._0_11_ = auVar1478._0_11_;
            auVar1490[0xb] = bVar178;
            auVar1489._11_5_ = auVar1490._11_5_;
            auVar1489._0_10_ = auVar1478._0_10_;
            auVar1489[10] = bVar174;
            auVar1488._10_6_ = auVar1489._10_6_;
            auVar1488._0_9_ = auVar1478._0_9_;
            auVar1488[9] = bVar182;
            auVar1487._9_7_ = auVar1488._9_7_;
            auVar1487._0_8_ = auVar1478._0_8_;
            auVar1487[8] = local_7c[0x41];
            auVar494._1_8_ = auVar1487._8_8_;
            auVar494[0] = bVar188;
            auVar494._9_7_ = 0;
            auVar493._10_6_ = 0;
            auVar493._0_10_ = SUB1610(auVar494 << 0x38,6);
            auVar492._11_5_ = 0;
            auVar492._0_11_ = SUB1611(auVar493 << 0x30,5);
            auVar491._12_4_ = 0;
            auVar491._0_12_ = SUB1612(auVar492 << 0x28,4);
            auVar490._13_3_ = 0;
            auVar490._0_13_ = SUB1613(auVar491 << 0x20,3);
            auVar1486._14_2_ = 0;
            auVar1486._0_14_ = SUB1614(auVar490 << 0x18,2);
            auVar1486 = auVar1486 << 0x10;
            uVar1180 = CONCAT13(0,CONCAT12(bVar182,(ushort)local_7c[0x41]));
            auVar18[0xd] = 0;
            auVar18._0_13_ = auVar1486._0_13_;
            auVar18[0xe] = bVar188;
            auVar44[0xc] = local_7c[0x31];
            auVar44._0_12_ = auVar1486._0_12_;
            auVar44._13_2_ = auVar18._13_2_;
            auVar57[0xb] = 0;
            auVar57._0_11_ = auVar1486._0_11_;
            auVar57._12_3_ = auVar44._12_3_;
            uVar85 = auVar57._11_4_;
            auVar86[10] = bVar185;
            auVar86._0_10_ = auVar1486._0_10_;
            auVar86._11_4_ = uVar85;
            auVar136[9] = 0;
            auVar136._0_9_ = auVar1486._0_9_;
            auVar136._10_5_ = auVar86._10_5_;
            auVar150[8] = local_7c[0x21];
            auVar150._0_8_ = auVar1486._0_8_;
            auVar150._9_6_ = auVar136._9_6_;
            auVar495._7_8_ = 0;
            auVar495._0_7_ = auVar150._8_7_;
            Var360 = CONCAT81(SUB158(auVar495 << 0x40,7),bVar180);
            auVar854._9_6_ = 0;
            auVar854._0_9_ = Var360;
            auVar496._1_10_ = SUB1510(auVar854 << 0x30,5);
            auVar496[0] = bVar173;
            auVar855._11_4_ = 0;
            auVar855._0_11_ = auVar496;
            auVar497._1_12_ = SUB1512(auVar855 << 0x20,3);
            auVar497[0] = uVar1852;
            auVar163[1] = 0;
            auVar163[0] = auVar1181[0];
            auVar163._2_13_ = auVar497;
            bVar173 = pbVar951[0x15];
            bVar176 = pbVar951[0x17];
            bVar180 = pbVar951[0x19];
            bVar183 = pbVar951[0x1b];
            bVar184 = pbVar951[0x1d];
            bVar185 = pbVar951[0x1f];
            bVar186 = pbVar951[0x21];
            auVar1181 = *(undefined1 (*) [16])(pbVar951 + 5);
            auVar1501._0_14_ = auVar1181._0_14_;
            auVar1501[0xe] = auVar1181[7];
            auVar1501[0xf] = pbVar951[0x1c];
            auVar1500._14_2_ = auVar1501._14_2_;
            auVar1500._0_13_ = auVar1181._0_13_;
            auVar1500[0xd] = bVar183;
            auVar1499._13_3_ = auVar1500._13_3_;
            auVar1499._0_12_ = auVar1181._0_12_;
            auVar1499[0xc] = auVar1181[6];
            auVar1498._12_4_ = auVar1499._12_4_;
            auVar1498._0_11_ = auVar1181._0_11_;
            auVar1498[0xb] = pbVar951[0x1a];
            auVar1497._11_5_ = auVar1498._11_5_;
            auVar1497._0_10_ = auVar1181._0_10_;
            auVar1497[10] = auVar1181[5];
            auVar1496._10_6_ = auVar1497._10_6_;
            auVar1496._0_9_ = auVar1181._0_9_;
            auVar1496[9] = bVar180;
            uVar1176 = auVar1181[4];
            auVar1495._9_7_ = auVar1496._9_7_;
            auVar1495._0_8_ = auVar1181._0_8_;
            auVar1495[8] = uVar1176;
            auVar502._1_8_ = auVar1495._8_8_;
            auVar502[0] = pbVar951[0x18];
            auVar502._9_7_ = 0;
            auVar501._10_6_ = 0;
            auVar501._0_10_ = SUB1610(auVar502 << 0x38,6);
            auVar500._11_5_ = 0;
            auVar500._0_11_ = SUB1611(auVar501 << 0x30,5);
            auVar499._12_4_ = 0;
            auVar499._0_12_ = SUB1612(auVar500 << 0x28,4);
            auVar498._13_3_ = 0;
            auVar498._0_13_ = SUB1613(auVar499 << 0x20,3);
            auVar1494._14_2_ = 0;
            auVar1494._0_14_ = SUB1614(auVar498 << 0x18,2);
            auVar1494 = auVar1494 << 0x10;
            uVar1852 = auVar1181[8];
            uVar1853 = auVar1181[10];
            auVar1509._0_14_ = auVar1494._0_14_;
            auVar1509[0xe] = pbVar951[0x18];
            auVar1509[0xf] = pbVar951[0x20];
            auVar1508._14_2_ = auVar1509._14_2_;
            auVar1508._0_13_ = auVar1494._0_13_;
            auVar1508[0xd] = auVar1181[0xb];
            auVar1507._13_3_ = auVar1508._13_3_;
            auVar1507._0_12_ = auVar1494._0_12_;
            auVar1507[0xc] = auVar1181[3];
            auVar1506._12_4_ = auVar1507._12_4_;
            auVar1506._0_11_ = auVar1494._0_11_;
            auVar1506[0xb] = bVar185;
            auVar1505._11_5_ = auVar1506._11_5_;
            auVar1505._0_10_ = auVar1494._0_10_;
            auVar1505[10] = bVar176;
            auVar1504._10_6_ = auVar1505._10_6_;
            auVar1504._0_9_ = auVar1494._0_9_;
            auVar1504[9] = uVar1853;
            auVar1503._9_7_ = auVar1504._9_7_;
            auVar1503._0_8_ = auVar1494._0_8_;
            auVar1503[8] = auVar1181[2];
            auVar507._1_8_ = auVar1503._8_8_;
            auVar507[0] = pbVar951[0x1e];
            auVar507._9_7_ = 0;
            auVar506._10_6_ = 0;
            auVar506._0_10_ = SUB1610(auVar507 << 0x38,6);
            auVar505._11_5_ = 0;
            auVar505._0_11_ = SUB1611(auVar506 << 0x30,5);
            auVar504._12_4_ = 0;
            auVar504._0_12_ = SUB1612(auVar505 << 0x28,4);
            auVar503._13_3_ = 0;
            auVar503._0_13_ = SUB1613(auVar504 << 0x20,3);
            auVar1502._14_2_ = 0;
            auVar1502._0_14_ = SUB1614(auVar503 << 0x18,2);
            auVar1502 = auVar1502 << 0x10;
            auVar1517._0_14_ = auVar1502._0_14_;
            auVar1517[0xe] = pbVar951[0x1e];
            auVar1517[0xf] = pbVar951[0x22];
            auVar1516._14_2_ = auVar1517._14_2_;
            auVar1516._0_13_ = auVar1502._0_13_;
            auVar1516[0xd] = pbVar951[0x1a];
            auVar1515._13_3_ = auVar1516._13_3_;
            auVar1515._0_12_ = auVar1502._0_12_;
            auVar1515[0xc] = pbVar951[0x16];
            auVar1514._12_4_ = auVar1515._12_4_;
            auVar1514._0_11_ = auVar1502._0_11_;
            auVar1514[0xb] = auVar1181[0xd];
            auVar1513._11_5_ = auVar1514._11_5_;
            auVar1513._0_10_ = auVar1502._0_10_;
            auVar1513[10] = auVar1181[9];
            auVar1512._10_6_ = auVar1513._10_6_;
            auVar1512._0_9_ = auVar1502._0_9_;
            auVar1512[9] = auVar1181[5];
            auVar1511._9_7_ = auVar1512._9_7_;
            auVar1511._0_8_ = auVar1502._0_8_;
            auVar1511[8] = auVar1181[1];
            auVar512._1_8_ = auVar1511._8_8_;
            auVar512[0] = bVar186;
            auVar512._9_7_ = 0;
            auVar511._10_6_ = 0;
            auVar511._0_10_ = SUB1610(auVar512 << 0x38,6);
            auVar510._11_5_ = 0;
            auVar510._0_11_ = SUB1611(auVar511 << 0x30,5);
            auVar509._12_4_ = 0;
            auVar509._0_12_ = SUB1612(auVar510 << 0x28,4);
            auVar508._13_3_ = 0;
            auVar508._0_13_ = SUB1613(auVar509 << 0x20,3);
            auVar1510._14_2_ = 0;
            auVar1510._0_14_ = SUB1614(auVar508 << 0x18,2);
            auVar1510 = auVar1510 << 0x10;
            bVar187 = pbVar951[0x29];
            bVar188 = pbVar951[0x2d];
            bVar193 = pbVar951[0x31];
            auVar1525._0_14_ = auVar1510._0_14_;
            auVar1525[0xe] = bVar186;
            auVar1525[0xf] = pbVar951[0x23];
            auVar1524._14_2_ = auVar1525._14_2_;
            auVar1524._0_13_ = auVar1510._0_13_;
            auVar1524[0xd] = bVar185;
            auVar1523._13_3_ = auVar1524._13_3_;
            auVar1523._0_12_ = auVar1510._0_12_;
            auVar1523[0xc] = bVar184;
            auVar1522._12_4_ = auVar1523._12_4_;
            auVar1522._0_11_ = auVar1510._0_11_;
            auVar1522[0xb] = bVar183;
            auVar1521._11_5_ = auVar1522._11_5_;
            auVar1521._0_10_ = auVar1510._0_10_;
            auVar1521[10] = bVar180;
            auVar1520._10_6_ = auVar1521._10_6_;
            auVar1520._0_9_ = auVar1510._0_9_;
            auVar1520[9] = bVar176;
            auVar1519._9_7_ = auVar1520._9_7_;
            auVar1519._0_8_ = auVar1510._0_8_;
            auVar1519[8] = bVar173;
            auVar517._1_8_ = auVar1519._8_8_;
            auVar517[0] = auVar1181[0xe];
            auVar517._9_7_ = 0;
            auVar516._10_6_ = 0;
            auVar516._0_10_ = SUB1610(auVar517 << 0x38,6);
            auVar515._11_5_ = 0;
            auVar515._0_11_ = SUB1611(auVar516 << 0x30,5);
            auVar514._12_4_ = 0;
            auVar514._0_12_ = SUB1612(auVar515 << 0x28,4);
            auVar513._13_3_ = 0;
            auVar513._0_13_ = SUB1613(auVar514 << 0x20,3);
            auVar1518._14_2_ = 0;
            auVar1518._0_14_ = SUB1614(auVar513 << 0x18,2);
            auVar1518 = auVar1518 << 0x10;
            bVar194 = pbVar951[0x39];
            bVar197 = pbVar951[0x3d];
            auVar1533._0_14_ = auVar1518._0_14_;
            auVar1533[0xe] = auVar1181[0xe];
            auVar1533[0xf] = pbVar951[0x33];
            auVar1532._14_2_ = auVar1533._14_2_;
            auVar1532._0_13_ = auVar1518._0_13_;
            auVar1532[0xd] = bVar193;
            auVar1531._13_3_ = auVar1532._13_3_;
            auVar1531._0_12_ = auVar1518._0_12_;
            auVar1531[0xc] = auVar1181[0xc];
            auVar1530._12_4_ = auVar1531._12_4_;
            auVar1530._0_11_ = auVar1518._0_11_;
            auVar1530[0xb] = pbVar951[0x2f];
            auVar1529._11_5_ = auVar1530._11_5_;
            auVar1529._0_10_ = auVar1518._0_10_;
            auVar1529[10] = uVar1853;
            auVar1528._10_6_ = auVar1529._10_6_;
            auVar1528._0_9_ = auVar1518._0_9_;
            auVar1528[9] = bVar188;
            auVar1527._9_7_ = auVar1528._9_7_;
            auVar1527._0_8_ = auVar1518._0_8_;
            auVar1527[8] = uVar1852;
            auVar522._1_8_ = auVar1527._8_8_;
            auVar522[0] = pbVar951[0x2b];
            auVar522._9_7_ = 0;
            auVar521._10_6_ = 0;
            auVar521._0_10_ = SUB1610(auVar522 << 0x38,6);
            auVar520._11_5_ = 0;
            auVar520._0_11_ = SUB1611(auVar521 << 0x30,5);
            auVar519._12_4_ = 0;
            auVar519._0_12_ = SUB1612(auVar520 << 0x28,4);
            auVar518._13_3_ = 0;
            auVar518._0_13_ = SUB1613(auVar519 << 0x20,3);
            auVar1526._14_2_ = 0;
            auVar1526._0_14_ = SUB1614(auVar518 << 0x18,2);
            auVar1526 = auVar1526 << 0x10;
            auVar1541._0_14_ = auVar1526._0_14_;
            auVar1541[0xe] = pbVar951[0x2b];
            auVar1541[0xf] = pbVar951[0x3b];
            auVar1540._14_2_ = auVar1541._14_2_;
            auVar1540._0_13_ = auVar1526._0_13_;
            auVar1540[0xd] = bVar183;
            auVar1539._13_3_ = auVar1540._13_3_;
            auVar1539._0_12_ = auVar1526._0_12_;
            auVar1539[0xc] = auVar1181[6];
            auVar1538._12_4_ = auVar1539._12_4_;
            auVar1538._0_11_ = auVar1526._0_11_;
            auVar1538[0xb] = bVar194;
            auVar1537._11_5_ = auVar1538._11_5_;
            auVar1537._0_10_ = auVar1526._0_10_;
            auVar1537[10] = bVar187;
            auVar1536._10_6_ = auVar1537._10_6_;
            auVar1536._0_9_ = auVar1526._0_9_;
            auVar1536[9] = bVar180;
            auVar1535._9_7_ = auVar1536._9_7_;
            auVar1535._0_8_ = auVar1526._0_8_;
            auVar1535[8] = uVar1176;
            auVar527._1_8_ = auVar1535._8_8_;
            auVar527[0] = pbVar951[0x37];
            auVar527._9_7_ = 0;
            auVar526._10_6_ = 0;
            auVar526._0_10_ = SUB1610(auVar527 << 0x38,6);
            auVar525._11_5_ = 0;
            auVar525._0_11_ = SUB1611(auVar526 << 0x30,5);
            auVar524._12_4_ = 0;
            auVar524._0_12_ = SUB1612(auVar525 << 0x28,4);
            auVar523._13_3_ = 0;
            auVar523._0_13_ = SUB1613(auVar524 << 0x20,3);
            auVar1534._14_2_ = 0;
            auVar1534._0_14_ = SUB1614(auVar523 << 0x18,2);
            auVar1534 = auVar1534 << 0x10;
            auVar1549._0_14_ = auVar1534._0_14_;
            auVar1549[0xe] = pbVar951[0x37];
            auVar1549[0xf] = pbVar951[0x3f];
            auVar1548._14_2_ = auVar1549._14_2_;
            auVar1548._0_13_ = auVar1534._0_13_;
            auVar1548[0xd] = pbVar951[0x2f];
            auVar1547._13_3_ = auVar1548._13_3_;
            auVar1547._0_12_ = auVar1534._0_12_;
            auVar1547[0xc] = pbVar951[0x27];
            auVar1546._12_4_ = auVar1547._12_4_;
            auVar1546._0_11_ = auVar1534._0_11_;
            auVar1546[0xb] = bVar185;
            auVar1545._11_5_ = auVar1546._11_5_;
            auVar1545._0_10_ = auVar1534._0_10_;
            auVar1545[10] = bVar176;
            auVar1544._10_6_ = auVar1545._10_6_;
            auVar1544._0_9_ = auVar1534._0_9_;
            auVar1544[9] = uVar1853;
            auVar1543._9_7_ = auVar1544._9_7_;
            auVar1543._0_8_ = auVar1534._0_8_;
            auVar1543[8] = auVar1181[2];
            auVar532._1_8_ = auVar1543._8_8_;
            auVar532[0] = bVar197;
            auVar532._9_7_ = 0;
            auVar531._10_6_ = 0;
            auVar531._0_10_ = SUB1610(auVar532 << 0x38,6);
            auVar530._11_5_ = 0;
            auVar530._0_11_ = SUB1611(auVar531 << 0x30,5);
            auVar529._12_4_ = 0;
            auVar529._0_12_ = SUB1612(auVar530 << 0x28,4);
            auVar528._13_3_ = 0;
            auVar528._0_13_ = SUB1613(auVar529 << 0x20,3);
            auVar1542._14_2_ = 0;
            auVar1542._0_14_ = SUB1614(auVar528 << 0x18,2);
            auVar1542 = auVar1542 << 0x10;
            bVar176 = pbVar951[0x55];
            bVar183 = pbVar951[0x5d];
            auVar1557._0_14_ = auVar1542._0_14_;
            auVar1557[0xe] = bVar197;
            auVar1557[0xf] = pbVar951[0x41];
            auVar1556._14_2_ = auVar1557._14_2_;
            auVar1556._0_13_ = auVar1542._0_13_;
            auVar1556[0xd] = bVar194;
            auVar1555._13_3_ = auVar1556._13_3_;
            auVar1555._0_12_ = auVar1542._0_12_;
            auVar1555[0xc] = pbVar951[0x35];
            auVar1554._12_4_ = auVar1555._12_4_;
            auVar1554._0_11_ = auVar1542._0_11_;
            auVar1554[0xb] = bVar193;
            auVar1553._11_5_ = auVar1554._11_5_;
            auVar1553._0_10_ = auVar1542._0_10_;
            auVar1553[10] = bVar188;
            auVar1552._10_6_ = auVar1553._10_6_;
            auVar1552._0_9_ = auVar1542._0_9_;
            auVar1552[9] = bVar187;
            auVar1551._9_7_ = auVar1552._9_7_;
            auVar1551._0_8_ = auVar1542._0_8_;
            auVar1551[8] = pbVar951[0x25];
            auVar537._1_8_ = auVar1551._8_8_;
            auVar537[0] = bVar186;
            auVar537._9_7_ = 0;
            auVar536._10_6_ = 0;
            auVar536._0_10_ = SUB1610(auVar537 << 0x38,6);
            auVar535._11_5_ = 0;
            auVar535._0_11_ = SUB1611(auVar536 << 0x30,5);
            auVar534._12_4_ = 0;
            auVar534._0_12_ = SUB1612(auVar535 << 0x28,4);
            auVar533._13_3_ = 0;
            auVar533._0_13_ = SUB1613(auVar534 << 0x20,3);
            auVar1550._14_2_ = 0;
            auVar1550._0_14_ = SUB1614(auVar533 << 0x18,2);
            auVar1550 = auVar1550 << 0x10;
            bVar185 = pbVar951[0x4d];
            auVar1565._0_14_ = auVar1550._0_14_;
            auVar1565[0xe] = bVar186;
            auVar1565[0xf] = pbVar951[0x61];
            auVar1564._14_2_ = auVar1565._14_2_;
            auVar1564._0_13_ = auVar1550._0_13_;
            auVar1564[0xd] = bVar183;
            auVar1563._13_3_ = auVar1564._13_3_;
            auVar1563._0_12_ = auVar1550._0_12_;
            auVar1563[0xc] = bVar184;
            auVar1562._12_4_ = auVar1563._12_4_;
            auVar1562._0_11_ = auVar1550._0_11_;
            auVar1562[0xb] = pbVar951[0x59];
            auVar1561._11_5_ = auVar1562._11_5_;
            auVar1561._0_10_ = auVar1550._0_10_;
            auVar1561[10] = bVar180;
            auVar1560._10_6_ = auVar1561._10_6_;
            auVar1560._0_9_ = auVar1550._0_9_;
            auVar1560[9] = bVar176;
            auVar1559._9_7_ = auVar1560._9_7_;
            auVar1559._0_8_ = auVar1550._0_8_;
            auVar1559[8] = bVar173;
            auVar542._1_8_ = auVar1559._8_8_;
            auVar542[0] = pbVar951[0x51];
            auVar542._9_7_ = 0;
            auVar541._10_6_ = 0;
            auVar541._0_10_ = SUB1610(auVar542 << 0x38,6);
            auVar540._11_5_ = 0;
            auVar540._0_11_ = SUB1611(auVar541 << 0x30,5);
            auVar539._12_4_ = 0;
            auVar539._0_12_ = SUB1612(auVar540 << 0x28,4);
            auVar538._13_3_ = 0;
            auVar538._0_13_ = SUB1613(auVar539 << 0x20,3);
            auVar1558._14_2_ = 0;
            auVar1558._0_14_ = SUB1614(auVar538 << 0x18,2);
            auVar1558 = auVar1558 << 0x10;
            auVar19._10_2_ = 0;
            auVar19._0_10_ = auVar161._0_10_;
            auVar19._12_2_ = (short)Var293;
            uVar908 = CONCAT42(auVar19._10_4_,auVar431._0_2_);
            auVar543._6_8_ = 0;
            auVar543._0_6_ = uVar908;
            auVar87._4_2_ = auVar432._0_2_;
            auVar87._0_4_ = auVar161._0_4_;
            auVar87._6_8_ = SUB148(auVar543 << 0x40,6);
            auVar1573._0_14_ = auVar1558._0_14_;
            auVar1573[0xe] = pbVar951[0x51];
            auVar1573[0xf] = pbVar951[0x71];
            auVar1572._14_2_ = auVar1573._14_2_;
            auVar1572._0_13_ = auVar1558._0_13_;
            auVar1572[0xd] = bVar193;
            auVar1571._13_3_ = auVar1572._13_3_;
            auVar1571._0_12_ = auVar1558._0_12_;
            auVar1571[0xc] = auVar1181[0xc];
            auVar1570._12_4_ = auVar1571._12_4_;
            auVar1570._0_11_ = auVar1558._0_11_;
            auVar1570[0xb] = pbVar951[0x6d];
            auVar1569._11_5_ = auVar1570._11_5_;
            auVar1569._0_10_ = auVar1558._0_10_;
            auVar1569[10] = bVar185;
            auVar1568._10_6_ = auVar1569._10_6_;
            auVar1568._0_9_ = auVar1558._0_9_;
            auVar1568[9] = bVar188;
            auVar1567._9_7_ = auVar1568._9_7_;
            auVar1567._0_8_ = auVar1558._0_8_;
            auVar1567[8] = uVar1852;
            auVar548._1_8_ = auVar1567._8_8_;
            auVar548[0] = pbVar951[0x69];
            auVar548._9_7_ = 0;
            auVar547._10_6_ = 0;
            auVar547._0_10_ = SUB1610(auVar548 << 0x38,6);
            auVar546._11_5_ = 0;
            auVar546._0_11_ = SUB1611(auVar547 << 0x30,5);
            auVar545._12_4_ = 0;
            auVar545._0_12_ = SUB1612(auVar546 << 0x28,4);
            auVar544._13_3_ = 0;
            auVar544._0_13_ = SUB1613(auVar545 << 0x20,3);
            auVar1566._14_2_ = 0;
            auVar1566._0_14_ = SUB1614(auVar544 << 0x18,2);
            auVar1566 = auVar1566 << 0x10;
            auVar1581._0_14_ = auVar1566._0_14_;
            auVar1581[0xe] = pbVar951[0x69];
            auVar1581[0xf] = pbVar951[0x79];
            auVar1580._14_2_ = auVar1581._14_2_;
            auVar1580._0_13_ = auVar1566._0_13_;
            auVar1580[0xd] = pbVar951[0x59];
            auVar1579._13_3_ = auVar1580._13_3_;
            auVar1579._0_12_ = auVar1566._0_12_;
            auVar1579[0xc] = pbVar951[0x49];
            auVar1578._12_4_ = auVar1579._12_4_;
            auVar1578._0_11_ = auVar1566._0_11_;
            auVar1578[0xb] = bVar194;
            auVar1577._11_5_ = auVar1578._11_5_;
            auVar1577._0_10_ = auVar1566._0_10_;
            auVar1577[10] = bVar187;
            auVar1576._10_6_ = auVar1577._10_6_;
            auVar1576._0_9_ = auVar1566._0_9_;
            auVar1576[9] = bVar180;
            auVar1575._9_7_ = auVar1576._9_7_;
            auVar1575._0_8_ = auVar1566._0_8_;
            auVar1575[8] = uVar1176;
            auVar553._1_8_ = auVar1575._8_8_;
            auVar553[0] = pbVar951[0x75];
            auVar553._9_7_ = 0;
            auVar552._10_6_ = 0;
            auVar552._0_10_ = SUB1610(auVar553 << 0x38,6);
            auVar551._11_5_ = 0;
            auVar551._0_11_ = SUB1611(auVar552 << 0x30,5);
            auVar550._12_4_ = 0;
            auVar550._0_12_ = SUB1612(auVar551 << 0x28,4);
            auVar549._13_3_ = 0;
            auVar549._0_13_ = SUB1613(auVar550 << 0x20,3);
            auVar1574._14_2_ = 0;
            auVar1574._0_14_ = SUB1614(auVar549 << 0x18,2);
            auVar1574 = auVar1574 << 0x10;
            auVar1589._0_14_ = auVar1574._0_14_;
            auVar1589[0xe] = pbVar951[0x75];
            auVar1589[0xf] = pbVar951[0x7d];
            auVar1588._14_2_ = auVar1589._14_2_;
            auVar1588._0_13_ = auVar1574._0_13_;
            auVar1588[0xd] = pbVar951[0x6d];
            auVar1587._13_3_ = auVar1588._13_3_;
            auVar1587._0_12_ = auVar1574._0_12_;
            auVar1587[0xc] = pbVar951[0x65];
            auVar1586._12_4_ = auVar1587._12_4_;
            auVar1586._0_11_ = auVar1574._0_11_;
            auVar1586[0xb] = bVar183;
            auVar1585._11_5_ = auVar1586._11_5_;
            auVar1585._0_10_ = auVar1574._0_10_;
            auVar1585[10] = bVar176;
            auVar1584._10_6_ = auVar1585._10_6_;
            auVar1584._0_9_ = auVar1574._0_9_;
            auVar1584[9] = bVar185;
            auVar1583._9_7_ = auVar1584._9_7_;
            auVar1583._0_8_ = auVar1574._0_8_;
            auVar1583[8] = pbVar951[0x45];
            auVar558._1_8_ = auVar1583._8_8_;
            auVar558[0] = bVar197;
            auVar558._9_7_ = 0;
            auVar557._10_6_ = 0;
            auVar557._0_10_ = SUB1610(auVar558 << 0x38,6);
            auVar556._11_5_ = 0;
            auVar556._0_11_ = SUB1611(auVar557 << 0x30,5);
            auVar555._12_4_ = 0;
            auVar555._0_12_ = SUB1612(auVar556 << 0x28,4);
            auVar554._13_3_ = 0;
            auVar554._0_13_ = SUB1613(auVar555 << 0x20,3);
            auVar1582._14_2_ = 0;
            auVar1582._0_14_ = SUB1614(auVar554 << 0x18,2);
            auVar1582 = auVar1582 << 0x10;
            auVar20._10_2_ = 0;
            auVar20._0_10_ = auVar162._0_10_;
            auVar20._12_2_ = (short)Var296;
            uVar909 = CONCAT42(auVar20._10_4_,auVar434._0_2_);
            auVar559._6_8_ = 0;
            auVar559._0_6_ = uVar909;
            auVar88._4_2_ = auVar907._0_2_;
            auVar88._0_4_ = auVar162._0_4_;
            auVar88._6_8_ = SUB148(auVar559 << 0x40,6);
            auVar21._10_2_ = 0;
            auVar21._0_10_ = auVar163._0_10_;
            auVar21._12_2_ = (short)Var360;
            uVar910 = CONCAT42(auVar21._10_4_,auVar496._0_2_);
            auVar560._6_8_ = 0;
            auVar560._0_6_ = uVar910;
            auVar89._4_2_ = auVar497._0_2_;
            auVar89._0_4_ = auVar163._0_4_;
            auVar89._6_8_ = SUB148(auVar560 << 0x40,6);
            uStack_114 = auVar149._8_2_;
            uStack_112 = auVar83._10_2_;
            auVar22[0xd] = 0;
            auVar22._0_13_ = auVar1582._0_13_;
            auVar22[0xe] = bVar197;
            auVar45[0xc] = pbVar951[0x35];
            auVar45._0_12_ = auVar1582._0_12_;
            auVar45._13_2_ = auVar22._13_2_;
            auVar58[0xb] = 0;
            auVar58._0_11_ = auVar1582._0_11_;
            auVar58._12_3_ = auVar45._12_3_;
            uVar90 = auVar58._11_4_;
            auVar91[10] = bVar188;
            auVar91._0_10_ = auVar1582._0_10_;
            auVar91._11_4_ = uVar90;
            auVar137[9] = 0;
            auVar137._0_9_ = auVar1582._0_9_;
            auVar137._10_5_ = auVar91._10_5_;
            auVar151[8] = pbVar951[0x25];
            auVar151._0_8_ = auVar1582._0_8_;
            auVar151._9_6_ = auVar137._9_6_;
            auVar561._7_8_ = 0;
            auVar561._0_7_ = auVar151._8_7_;
            Var293 = CONCAT81(SUB158(auVar561 << 0x40,7),bVar184);
            auVar856._9_6_ = 0;
            auVar856._0_9_ = Var293;
            auVar562._1_10_ = SUB1510(auVar856 << 0x30,5);
            auVar562[0] = bVar173;
            auVar857._11_4_ = 0;
            auVar857._0_11_ = auVar562;
            auVar563._1_12_ = SUB1512(auVar857 << 0x20,3);
            auVar563[0] = uVar1852;
            auVar164[1] = 0;
            auVar164[0] = auVar1181[0];
            auVar164._2_13_ = auVar563;
            uVar1860 = (uint)uStack_114;
            auVar23._10_2_ = 0;
            auVar23._0_10_ = auVar164._0_10_;
            auVar23._12_2_ = (short)Var293;
            uVar911 = CONCAT42(auVar23._10_4_,auVar562._0_2_);
            auVar564._6_8_ = 0;
            auVar564._0_6_ = uVar911;
            auVar92._4_2_ = auVar563._0_2_;
            auVar92._0_4_ = auVar164._0_4_;
            auVar92._6_8_ = SUB148(auVar564 << 0x40,6);
            uStack_a4 = (ushort)((ulonglong)uVar927 >> 8);
            uStack_a2 = (ushort)((ulonglong)uVar928 >> 0x18);
            uVar1854 = (uint)uStack_a4;
            uVar1857 = (uint)uStack_a2;
            uVar1866 = (uint)uStack_112;
            uStack_94 = auVar150._8_2_;
            uStack_92 = auVar86._10_2_;
            uVar1861 = (uint)uStack_94;
            uVar1825 = CONCAT13(0,CONCAT12(bVar185,(ushort)pbVar951[0x45]));
            auVar882[0xc] = uStack_cf;
            auVar882._0_12_ = ZEXT112(bStack_e7) << 0x40;
            auVar883._10_3_ = auVar882._10_3_;
            auVar883._0_10_ = (unkuint10)bStack_d7 << 0x40;
            auVar93[4] = uStack_ef;
            auVar93._0_4_ = uVar1824;
            auVar93[5] = 0;
            auVar93._6_8_ = SUB148(ZEXT514(auVar883._8_5_) << 0x40,6);
            auVar884[0xc] = uStack_d4._1_1_;
            auVar884._0_12_ = ZEXT112(bStack_eb) << 0x40;
            auVar885._10_3_ = auVar884._10_3_;
            auVar885._0_10_ = (unkuint10)bStack_db << 0x40;
            auVar94[4] = uStack_f3;
            auVar94._0_4_ = uVar1591;
            auVar94[5] = 0;
            auVar94._6_8_ = SUB148(ZEXT514(auVar885._8_5_) << 0x40,6);
            auVar886[0xc] = bVar178;
            auVar886._0_12_ = ZEXT112(bVar189) << 0x40;
            auVar887._10_3_ = auVar886._10_3_;
            auVar887._0_10_ = (unkuint10)bVar174 << 0x40;
            auVar95[4] = bVar182;
            auVar95._0_4_ = uVar1180;
            auVar95[5] = 0;
            auVar95._6_8_ = SUB148(ZEXT514(auVar887._8_5_) << 0x40,6);
            auVar96[0xc] = bVar183;
            auVar96._0_12_ = ZEXT112(pbVar951[0x65]) << 0x40;
            auVar97._10_3_ = auVar96._10_3_;
            auVar97._0_10_ = (unkuint10)bVar176 << 0x40;
            auVar565._5_8_ = 0;
            auVar565._0_5_ = auVar97._8_5_;
            auVar98[4] = bVar185;
            auVar98._0_4_ = uVar1825;
            auVar98[5] = 0;
            auVar98._6_7_ = SUB137(auVar565 << 0x40,6);
            uVar1821 = (uint)uStack_e4._1_1_;
            uVar1862 = CONCAT13(0,CONCAT12(uStack_ee,(ushort)bStack_f6));
            auVar937._6_8_ = 0;
            auVar24[0xe] = uStack_fe;
            auVar24._0_14_ = auVar937 << 0x38;
            auVar838._4_8_ = 0;
            auVar838._0_4_ = uVar99;
            auVar59._12_3_ = (int3)(CONCAT26(auVar24._13_2_,CONCAT15(uStack_106,uVar931)) >> 0x28);
            auVar59._0_12_ = auVar838 << 0x38;
            uVar99 = auVar59._11_4_;
            uVar928 = CONCAT44(uVar99,CONCAT13(pbVar2[0xe],uVar925));
            auVar138._10_5_ = (int5)((ulonglong)uVar928 >> 0x18);
            auVar138._0_10_ = (unkuint10)CONCAT11(bStack_f6,uStack_fe) << 0x38;
            uVar927 = CONCAT62(auVar138._9_6_,CONCAT11(pbVar2[6],uStack_fe));
            auVar566._7_8_ = 0;
            auVar566._0_7_ = (uint7)((ulonglong)uVar927 >> 8);
            Var293 = CONCAT81(SUB158(auVar566 << 0x40,7),uStack_ae);
            auVar858._9_6_ = 0;
            auVar858._0_9_ = Var293;
            auVar567._1_10_ = SUB1510(auVar858 << 0x30,5);
            auVar567[0] = uStack_b6;
            auVar859._11_4_ = 0;
            auVar859._0_11_ = auVar567;
            auVar912._1_12_ = SUB1512(auVar859 << 0x20,3);
            auVar912[0] = pbVar1[0xe];
            auVar165[1] = 0;
            auVar165[0] = pbVar1[6];
            auVar165._2_13_ = auVar912;
            bVar173 = pbVar949[0x12];
            bVar174 = pbVar949[0x14];
            bVar176 = pbVar949[0x16];
            bVar178 = pbVar949[0x18];
            bVar180 = pbVar949[0x1a];
            bVar182 = pbVar949[0x1c];
            bVar183 = pbVar949[0x1e];
            auVar25[0xd] = 0;
            auVar25._0_13_ = auVar976._0_13_;
            auVar25[0xe] = uStack_102;
            auVar46[0xc] = uStack_10a;
            auVar46._0_12_ = auVar976._0_12_;
            auVar46._13_2_ = auVar25._13_2_;
            auVar60[0xb] = 0;
            auVar60._0_11_ = auVar976._0_11_;
            auVar60._12_3_ = auVar46._12_3_;
            uVar100 = auVar60._11_4_;
            auVar101[10] = pbVar2[10];
            auVar101._0_10_ = auVar976._0_10_;
            auVar101._11_4_ = uVar100;
            auVar139[9] = 0;
            auVar139._0_9_ = auVar976._0_9_;
            auVar139._10_5_ = auVar101._10_5_;
            auVar152[8] = pbVar2[2];
            auVar152._0_8_ = auVar976._0_8_;
            auVar152._9_6_ = auVar139._9_6_;
            auVar568._7_8_ = 0;
            auVar568._0_7_ = auVar152._8_7_;
            Var296 = CONCAT81(SUB158(auVar568 << 0x40,7),(undefined1)uStack_b2);
            auVar860._9_6_ = 0;
            auVar860._0_9_ = Var296;
            auVar569._1_10_ = SUB1510(auVar860 << 0x30,5);
            auVar569[0] = uStack_ba;
            auVar861._11_4_ = 0;
            auVar861._0_11_ = auVar569;
            auVar570._1_12_ = SUB1512(auVar861 << 0x20,3);
            auVar570[0] = pbVar1[10];
            auVar166[1] = 0;
            auVar166[0] = pbVar1[2];
            auVar166._2_13_ = auVar570;
            uVar957 = CONCAT13(0,CONCAT12(uStack_f2,(ushort)bStack_fa));
            auVar1181 = *(undefined1 (*) [16])(pbVar949 + 2);
            auVar991._0_14_ = auVar1181._0_14_;
            auVar991[0xe] = auVar1181[7];
            auVar991[0xf] = pbVar949[0x19];
            auVar990._14_2_ = auVar991._14_2_;
            auVar990._0_13_ = auVar1181._0_13_;
            auVar990[0xd] = bVar178;
            auVar989._13_3_ = auVar990._13_3_;
            auVar989._0_12_ = auVar1181._0_12_;
            auVar989[0xc] = auVar1181[6];
            auVar988._12_4_ = auVar989._12_4_;
            auVar988._0_11_ = auVar1181._0_11_;
            auVar988[0xb] = pbVar949[0x17];
            auVar987._11_5_ = auVar988._11_5_;
            auVar987._0_10_ = auVar1181._0_10_;
            auVar987[10] = auVar1181[5];
            auVar986._10_6_ = auVar987._10_6_;
            auVar986._0_9_ = auVar1181._0_9_;
            auVar986[9] = bVar176;
            uVar1176 = auVar1181[4];
            auVar985._9_7_ = auVar986._9_7_;
            auVar985._0_8_ = auVar1181._0_8_;
            auVar985[8] = uVar1176;
            auVar575._1_8_ = auVar985._8_8_;
            auVar575[0] = pbVar949[0x15];
            auVar575._9_7_ = 0;
            auVar574._10_6_ = 0;
            auVar574._0_10_ = SUB1610(auVar575 << 0x38,6);
            auVar573._11_5_ = 0;
            auVar573._0_11_ = SUB1611(auVar574 << 0x30,5);
            auVar572._12_4_ = 0;
            auVar572._0_12_ = SUB1612(auVar573 << 0x28,4);
            auVar571._13_3_ = 0;
            auVar571._0_13_ = SUB1613(auVar572 << 0x20,3);
            auVar984._14_2_ = 0;
            auVar984._0_14_ = SUB1614(auVar571 << 0x18,2);
            auVar984 = auVar984 << 0x10;
            uVar1852 = auVar1181[8];
            uVar1853 = auVar1181[10];
            auVar999._0_14_ = auVar984._0_14_;
            auVar999[0xe] = pbVar949[0x15];
            auVar999[0xf] = pbVar949[0x1d];
            auVar998._14_2_ = auVar999._14_2_;
            auVar998._0_13_ = auVar984._0_13_;
            auVar998[0xd] = auVar1181[0xb];
            auVar997._13_3_ = auVar998._13_3_;
            auVar997._0_12_ = auVar984._0_12_;
            auVar997[0xc] = auVar1181[3];
            auVar996._12_4_ = auVar997._12_4_;
            auVar996._0_11_ = auVar984._0_11_;
            auVar996[0xb] = bVar182;
            auVar995._11_5_ = auVar996._11_5_;
            auVar995._0_10_ = auVar984._0_10_;
            auVar995[10] = bVar174;
            auVar994._10_6_ = auVar995._10_6_;
            auVar994._0_9_ = auVar984._0_9_;
            auVar994[9] = uVar1853;
            auVar993._9_7_ = auVar994._9_7_;
            auVar993._0_8_ = auVar984._0_8_;
            auVar993[8] = auVar1181[2];
            auVar580._1_8_ = auVar993._8_8_;
            auVar580[0] = pbVar949[0x1b];
            auVar580._9_7_ = 0;
            auVar579._10_6_ = 0;
            auVar579._0_10_ = SUB1610(auVar580 << 0x38,6);
            auVar578._11_5_ = 0;
            auVar578._0_11_ = SUB1611(auVar579 << 0x30,5);
            auVar577._12_4_ = 0;
            auVar577._0_12_ = SUB1612(auVar578 << 0x28,4);
            auVar576._13_3_ = 0;
            auVar576._0_13_ = SUB1613(auVar577 << 0x20,3);
            auVar992._14_2_ = 0;
            auVar992._0_14_ = SUB1614(auVar576 << 0x18,2);
            auVar992 = auVar992 << 0x10;
            auVar1007._0_14_ = auVar992._0_14_;
            auVar1007[0xe] = pbVar949[0x1b];
            auVar1007[0xf] = pbVar949[0x1f];
            auVar1006._14_2_ = auVar1007._14_2_;
            auVar1006._0_13_ = auVar992._0_13_;
            auVar1006[0xd] = pbVar949[0x17];
            auVar1005._13_3_ = auVar1006._13_3_;
            auVar1005._0_12_ = auVar992._0_12_;
            auVar1005[0xc] = pbVar949[0x13];
            auVar1004._12_4_ = auVar1005._12_4_;
            auVar1004._0_11_ = auVar992._0_11_;
            auVar1004[0xb] = auVar1181[0xd];
            auVar1003._11_5_ = auVar1004._11_5_;
            auVar1003._0_10_ = auVar992._0_10_;
            auVar1003[10] = auVar1181[9];
            auVar1002._10_6_ = auVar1003._10_6_;
            auVar1002._0_9_ = auVar992._0_9_;
            auVar1002[9] = auVar1181[5];
            auVar1001._9_7_ = auVar1002._9_7_;
            auVar1001._0_8_ = auVar992._0_8_;
            auVar1001[8] = auVar1181[1];
            auVar585._1_8_ = auVar1001._8_8_;
            auVar585[0] = bVar183;
            auVar585._9_7_ = 0;
            auVar584._10_6_ = 0;
            auVar584._0_10_ = SUB1610(auVar585 << 0x38,6);
            auVar583._11_5_ = 0;
            auVar583._0_11_ = SUB1611(auVar584 << 0x30,5);
            auVar582._12_4_ = 0;
            auVar582._0_12_ = SUB1612(auVar583 << 0x28,4);
            auVar581._13_3_ = 0;
            auVar581._0_13_ = SUB1613(auVar582 << 0x20,3);
            auVar1000._14_2_ = 0;
            auVar1000._0_14_ = SUB1614(auVar581 << 0x18,2);
            auVar1000 = auVar1000 << 0x10;
            bVar184 = pbVar949[0x26];
            bVar185 = pbVar949[0x2a];
            bVar186 = pbVar949[0x2e];
            auVar1015._0_14_ = auVar1000._0_14_;
            auVar1015[0xe] = bVar183;
            auVar1015[0xf] = pbVar949[0x20];
            auVar1014._14_2_ = auVar1015._14_2_;
            auVar1014._0_13_ = auVar1000._0_13_;
            auVar1014[0xd] = bVar182;
            auVar1013._13_3_ = auVar1014._13_3_;
            auVar1013._0_12_ = auVar1000._0_12_;
            auVar1013[0xc] = bVar180;
            auVar1012._12_4_ = auVar1013._12_4_;
            auVar1012._0_11_ = auVar1000._0_11_;
            auVar1012[0xb] = bVar178;
            auVar1011._11_5_ = auVar1012._11_5_;
            auVar1011._0_10_ = auVar1000._0_10_;
            auVar1011[10] = bVar176;
            auVar1010._10_6_ = auVar1011._10_6_;
            auVar1010._0_9_ = auVar1000._0_9_;
            auVar1010[9] = bVar174;
            auVar1009._9_7_ = auVar1010._9_7_;
            auVar1009._0_8_ = auVar1000._0_8_;
            auVar1009[8] = bVar173;
            auVar590._1_8_ = auVar1009._8_8_;
            auVar590[0] = auVar1181[0xe];
            auVar590._9_7_ = 0;
            auVar589._10_6_ = 0;
            auVar589._0_10_ = SUB1610(auVar590 << 0x38,6);
            auVar588._11_5_ = 0;
            auVar588._0_11_ = SUB1611(auVar589 << 0x30,5);
            auVar587._12_4_ = 0;
            auVar587._0_12_ = SUB1612(auVar588 << 0x28,4);
            auVar586._13_3_ = 0;
            auVar586._0_13_ = SUB1613(auVar587 << 0x20,3);
            auVar1008._14_2_ = 0;
            auVar1008._0_14_ = SUB1614(auVar586 << 0x18,2);
            auVar1008 = auVar1008 << 0x10;
            bVar187 = pbVar949[0x36];
            bVar188 = pbVar949[0x3a];
            auVar1023._0_14_ = auVar1008._0_14_;
            auVar1023[0xe] = auVar1181[0xe];
            auVar1023[0xf] = pbVar949[0x30];
            auVar1022._14_2_ = auVar1023._14_2_;
            auVar1022._0_13_ = auVar1008._0_13_;
            auVar1022[0xd] = bVar186;
            auVar1021._13_3_ = auVar1022._13_3_;
            auVar1021._0_12_ = auVar1008._0_12_;
            auVar1021[0xc] = auVar1181[0xc];
            auVar1020._12_4_ = auVar1021._12_4_;
            auVar1020._0_11_ = auVar1008._0_11_;
            auVar1020[0xb] = pbVar949[0x2c];
            auVar1019._11_5_ = auVar1020._11_5_;
            auVar1019._0_10_ = auVar1008._0_10_;
            auVar1019[10] = uVar1853;
            auVar1018._10_6_ = auVar1019._10_6_;
            auVar1018._0_9_ = auVar1008._0_9_;
            auVar1018[9] = bVar185;
            auVar1017._9_7_ = auVar1018._9_7_;
            auVar1017._0_8_ = auVar1008._0_8_;
            auVar1017[8] = uVar1852;
            auVar595._1_8_ = auVar1017._8_8_;
            auVar595[0] = pbVar949[0x28];
            auVar595._9_7_ = 0;
            auVar594._10_6_ = 0;
            auVar594._0_10_ = SUB1610(auVar595 << 0x38,6);
            auVar593._11_5_ = 0;
            auVar593._0_11_ = SUB1611(auVar594 << 0x30,5);
            auVar592._12_4_ = 0;
            auVar592._0_12_ = SUB1612(auVar593 << 0x28,4);
            auVar591._13_3_ = 0;
            auVar591._0_13_ = SUB1613(auVar592 << 0x20,3);
            auVar1016._14_2_ = 0;
            auVar1016._0_14_ = SUB1614(auVar591 << 0x18,2);
            auVar1016 = auVar1016 << 0x10;
            auVar1031._0_14_ = auVar1016._0_14_;
            auVar1031[0xe] = pbVar949[0x28];
            auVar1031[0xf] = pbVar949[0x38];
            auVar1030._14_2_ = auVar1031._14_2_;
            auVar1030._0_13_ = auVar1016._0_13_;
            auVar1030[0xd] = bVar178;
            auVar1029._13_3_ = auVar1030._13_3_;
            auVar1029._0_12_ = auVar1016._0_12_;
            auVar1029[0xc] = auVar1181[6];
            auVar1028._12_4_ = auVar1029._12_4_;
            auVar1028._0_11_ = auVar1016._0_11_;
            auVar1028[0xb] = bVar187;
            auVar1027._11_5_ = auVar1028._11_5_;
            auVar1027._0_10_ = auVar1016._0_10_;
            auVar1027[10] = bVar184;
            auVar1026._10_6_ = auVar1027._10_6_;
            auVar1026._0_9_ = auVar1016._0_9_;
            auVar1026[9] = bVar176;
            auVar1025._9_7_ = auVar1026._9_7_;
            auVar1025._0_8_ = auVar1016._0_8_;
            auVar1025[8] = uVar1176;
            auVar600._1_8_ = auVar1025._8_8_;
            auVar600[0] = pbVar949[0x34];
            auVar600._9_7_ = 0;
            auVar599._10_6_ = 0;
            auVar599._0_10_ = SUB1610(auVar600 << 0x38,6);
            auVar598._11_5_ = 0;
            auVar598._0_11_ = SUB1611(auVar599 << 0x30,5);
            auVar597._12_4_ = 0;
            auVar597._0_12_ = SUB1612(auVar598 << 0x28,4);
            auVar596._13_3_ = 0;
            auVar596._0_13_ = SUB1613(auVar597 << 0x20,3);
            auVar1024._14_2_ = 0;
            auVar1024._0_14_ = SUB1614(auVar596 << 0x18,2);
            auVar1024 = auVar1024 << 0x10;
            auVar1039._0_14_ = auVar1024._0_14_;
            auVar1039[0xe] = pbVar949[0x34];
            auVar1039[0xf] = pbVar949[0x3c];
            auVar1038._14_2_ = auVar1039._14_2_;
            auVar1038._0_13_ = auVar1024._0_13_;
            auVar1038[0xd] = pbVar949[0x2c];
            auVar1037._13_3_ = auVar1038._13_3_;
            auVar1037._0_12_ = auVar1024._0_12_;
            auVar1037[0xc] = pbVar949[0x24];
            auVar1036._12_4_ = auVar1037._12_4_;
            auVar1036._0_11_ = auVar1024._0_11_;
            auVar1036[0xb] = bVar182;
            auVar1035._11_5_ = auVar1036._11_5_;
            auVar1035._0_10_ = auVar1024._0_10_;
            auVar1035[10] = bVar174;
            auVar1034._10_6_ = auVar1035._10_6_;
            auVar1034._0_9_ = auVar1024._0_9_;
            auVar1034[9] = uVar1853;
            auVar1033._9_7_ = auVar1034._9_7_;
            auVar1033._0_8_ = auVar1024._0_8_;
            auVar1033[8] = auVar1181[2];
            auVar605._1_8_ = auVar1033._8_8_;
            auVar605[0] = bVar188;
            auVar605._9_7_ = 0;
            auVar604._10_6_ = 0;
            auVar604._0_10_ = SUB1610(auVar605 << 0x38,6);
            auVar603._11_5_ = 0;
            auVar603._0_11_ = SUB1611(auVar604 << 0x30,5);
            auVar602._12_4_ = 0;
            auVar602._0_12_ = SUB1612(auVar603 << 0x28,4);
            auVar601._13_3_ = 0;
            auVar601._0_13_ = SUB1613(auVar602 << 0x20,3);
            auVar1032._14_2_ = 0;
            auVar1032._0_14_ = SUB1614(auVar601 << 0x18,2);
            auVar1032 = auVar1032 << 0x10;
            bVar174 = pbVar949[0x52];
            bVar178 = pbVar949[0x5a];
            auVar1047._0_14_ = auVar1032._0_14_;
            auVar1047[0xe] = bVar188;
            auVar1047[0xf] = pbVar949[0x3e];
            auVar1046._14_2_ = auVar1047._14_2_;
            auVar1046._0_13_ = auVar1032._0_13_;
            auVar1046[0xd] = bVar187;
            auVar1045._13_3_ = auVar1046._13_3_;
            auVar1045._0_12_ = auVar1032._0_12_;
            auVar1045[0xc] = pbVar949[0x32];
            auVar1044._12_4_ = auVar1045._12_4_;
            auVar1044._0_11_ = auVar1032._0_11_;
            auVar1044[0xb] = bVar186;
            auVar1043._11_5_ = auVar1044._11_5_;
            auVar1043._0_10_ = auVar1032._0_10_;
            auVar1043[10] = bVar185;
            auVar1042._10_6_ = auVar1043._10_6_;
            auVar1042._0_9_ = auVar1032._0_9_;
            auVar1042[9] = bVar184;
            auVar1041._9_7_ = auVar1042._9_7_;
            auVar1041._0_8_ = auVar1032._0_8_;
            auVar1041[8] = pbVar949[0x22];
            auVar610._1_8_ = auVar1041._8_8_;
            auVar610[0] = bVar183;
            auVar610._9_7_ = 0;
            auVar609._10_6_ = 0;
            auVar609._0_10_ = SUB1610(auVar610 << 0x38,6);
            auVar608._11_5_ = 0;
            auVar608._0_11_ = SUB1611(auVar609 << 0x30,5);
            auVar607._12_4_ = 0;
            auVar607._0_12_ = SUB1612(auVar608 << 0x28,4);
            auVar606._13_3_ = 0;
            auVar606._0_13_ = SUB1613(auVar607 << 0x20,3);
            auVar1040._14_2_ = 0;
            auVar1040._0_14_ = SUB1614(auVar606 << 0x18,2);
            auVar1040 = auVar1040 << 0x10;
            bVar182 = pbVar949[0x4a];
            bVar193 = pbVar949[0x62];
            bVar194 = pbVar949[0x6a];
            bVar197 = pbVar949[0x72];
            bVar198 = pbVar949[0x7a];
            auVar1055._0_14_ = auVar1040._0_14_;
            auVar1055[0xe] = bVar183;
            auVar1055[0xf] = pbVar949[0x5e];
            auVar1054._14_2_ = auVar1055._14_2_;
            auVar1054._0_13_ = auVar1040._0_13_;
            auVar1054[0xd] = bVar178;
            auVar1053._13_3_ = auVar1054._13_3_;
            auVar1053._0_12_ = auVar1040._0_12_;
            auVar1053[0xc] = bVar180;
            auVar1052._12_4_ = auVar1053._12_4_;
            auVar1052._0_11_ = auVar1040._0_11_;
            auVar1052[0xb] = pbVar949[0x56];
            auVar1051._11_5_ = auVar1052._11_5_;
            auVar1051._0_10_ = auVar1040._0_10_;
            auVar1051[10] = bVar176;
            auVar1050._10_6_ = auVar1051._10_6_;
            auVar1050._0_9_ = auVar1040._0_9_;
            auVar1050[9] = bVar174;
            auVar1049._9_7_ = auVar1050._9_7_;
            auVar1049._0_8_ = auVar1040._0_8_;
            auVar1049[8] = bVar173;
            auVar615._1_8_ = auVar1049._8_8_;
            auVar615[0] = pbVar949[0x4e];
            auVar615._9_7_ = 0;
            auVar614._10_6_ = 0;
            auVar614._0_10_ = SUB1610(auVar615 << 0x38,6);
            auVar613._11_5_ = 0;
            auVar613._0_11_ = SUB1611(auVar614 << 0x30,5);
            auVar612._12_4_ = 0;
            auVar612._0_12_ = SUB1612(auVar613 << 0x28,4);
            auVar611._13_3_ = 0;
            auVar611._0_13_ = SUB1613(auVar612 << 0x20,3);
            auVar1048._14_2_ = 0;
            auVar1048._0_14_ = SUB1614(auVar611 << 0x18,2);
            auVar1048 = auVar1048 << 0x10;
            auVar1063._0_14_ = auVar1048._0_14_;
            auVar1063[0xe] = pbVar949[0x4e];
            auVar1063[0xf] = pbVar949[0x6e];
            auVar1062._14_2_ = auVar1063._14_2_;
            auVar1062._0_13_ = auVar1048._0_13_;
            auVar1062[0xd] = bVar186;
            auVar1061._13_3_ = auVar1062._13_3_;
            auVar1061._0_12_ = auVar1048._0_12_;
            auVar1061[0xc] = auVar1181[0xc];
            auVar1060._12_4_ = auVar1061._12_4_;
            auVar1060._0_11_ = auVar1048._0_11_;
            auVar1060[0xb] = bVar194;
            auVar1059._11_5_ = auVar1060._11_5_;
            auVar1059._0_10_ = auVar1048._0_10_;
            auVar1059[10] = bVar182;
            auVar1058._10_6_ = auVar1059._10_6_;
            auVar1058._0_9_ = auVar1048._0_9_;
            auVar1058[9] = bVar185;
            auVar1057._9_7_ = auVar1058._9_7_;
            auVar1057._0_8_ = auVar1048._0_8_;
            auVar1057[8] = uVar1852;
            auVar620._1_8_ = auVar1057._8_8_;
            auVar620[0] = pbVar949[0x66];
            auVar620._9_7_ = 0;
            auVar619._10_6_ = 0;
            auVar619._0_10_ = SUB1610(auVar620 << 0x38,6);
            auVar618._11_5_ = 0;
            auVar618._0_11_ = SUB1611(auVar619 << 0x30,5);
            auVar617._12_4_ = 0;
            auVar617._0_12_ = SUB1612(auVar618 << 0x28,4);
            auVar616._13_3_ = 0;
            auVar616._0_13_ = SUB1613(auVar617 << 0x20,3);
            auVar1056._14_2_ = 0;
            auVar1056._0_14_ = SUB1614(auVar616 << 0x18,2);
            auVar1056 = auVar1056 << 0x10;
            auVar1071._0_14_ = auVar1056._0_14_;
            auVar1071[0xe] = pbVar949[0x66];
            auVar1071[0xf] = pbVar949[0x76];
            auVar1070._14_2_ = auVar1071._14_2_;
            auVar1070._0_13_ = auVar1056._0_13_;
            auVar1070[0xd] = pbVar949[0x56];
            auVar1069._13_3_ = auVar1070._13_3_;
            auVar1069._0_12_ = auVar1056._0_12_;
            auVar1069[0xc] = pbVar949[0x46];
            auVar1068._12_4_ = auVar1069._12_4_;
            auVar1068._0_11_ = auVar1056._0_11_;
            auVar1068[0xb] = bVar187;
            auVar1067._11_5_ = auVar1068._11_5_;
            auVar1067._0_10_ = auVar1056._0_10_;
            auVar1067[10] = bVar184;
            auVar1066._10_6_ = auVar1067._10_6_;
            auVar1066._0_9_ = auVar1056._0_9_;
            auVar1066[9] = bVar176;
            auVar1065._9_7_ = auVar1066._9_7_;
            auVar1065._0_8_ = auVar1056._0_8_;
            auVar1065[8] = uVar1176;
            auVar625._1_8_ = auVar1065._8_8_;
            auVar625[0] = bVar197;
            auVar625._9_7_ = 0;
            auVar624._10_6_ = 0;
            auVar624._0_10_ = SUB1610(auVar625 << 0x38,6);
            auVar623._11_5_ = 0;
            auVar623._0_11_ = SUB1611(auVar624 << 0x30,5);
            auVar622._12_4_ = 0;
            auVar622._0_12_ = SUB1612(auVar623 << 0x28,4);
            auVar621._13_3_ = 0;
            auVar621._0_13_ = SUB1613(auVar622 << 0x20,3);
            auVar1064._14_2_ = 0;
            auVar1064._0_14_ = SUB1614(auVar621 << 0x18,2);
            auVar1064 = auVar1064 << 0x10;
            auVar1079._0_14_ = auVar1064._0_14_;
            auVar1079[0xe] = bVar197;
            auVar1079[0xf] = bVar198;
            auVar1078._14_2_ = auVar1079._14_2_;
            auVar1078._0_13_ = auVar1064._0_13_;
            auVar1078[0xd] = bVar194;
            auVar1077._13_3_ = auVar1078._13_3_;
            auVar1077._0_12_ = auVar1064._0_12_;
            auVar1077[0xc] = bVar193;
            auVar1076._12_4_ = auVar1077._12_4_;
            auVar1076._0_11_ = auVar1064._0_11_;
            auVar1076[0xb] = bVar178;
            auVar1075._11_5_ = auVar1076._11_5_;
            auVar1075._0_10_ = auVar1064._0_10_;
            auVar1075[10] = bVar174;
            auVar1074._10_6_ = auVar1075._10_6_;
            auVar1074._0_9_ = auVar1064._0_9_;
            auVar1074[9] = bVar182;
            auVar1073._9_7_ = auVar1074._9_7_;
            auVar1073._0_8_ = auVar1064._0_8_;
            auVar1073[8] = pbVar949[0x42];
            auVar630._1_8_ = auVar1073._8_8_;
            auVar630[0] = bVar188;
            auVar630._9_7_ = 0;
            auVar629._10_6_ = 0;
            auVar629._0_10_ = SUB1610(auVar630 << 0x38,6);
            auVar628._11_5_ = 0;
            auVar628._0_11_ = SUB1611(auVar629 << 0x30,5);
            auVar627._12_4_ = 0;
            auVar627._0_12_ = SUB1612(auVar628 << 0x28,4);
            auVar626._13_3_ = 0;
            auVar626._0_13_ = SUB1613(auVar627 << 0x20,3);
            auVar1072._14_2_ = 0;
            auVar1072._0_14_ = SUB1614(auVar626 << 0x18,2);
            auVar1072 = auVar1072 << 0x10;
            uVar958 = CONCAT13(0,CONCAT12(bVar182,(ushort)pbVar949[0x42]));
            auVar26[0xd] = 0;
            auVar26._0_13_ = auVar1072._0_13_;
            auVar26[0xe] = bVar188;
            auVar47[0xc] = pbVar949[0x32];
            auVar47._0_12_ = auVar1072._0_12_;
            auVar47._13_2_ = auVar26._13_2_;
            auVar61[0xb] = 0;
            auVar61._0_11_ = auVar1072._0_11_;
            auVar61._12_3_ = auVar47._12_3_;
            uVar102 = auVar61._11_4_;
            auVar103[10] = bVar185;
            auVar103._0_10_ = auVar1072._0_10_;
            auVar103._11_4_ = uVar102;
            auVar140[9] = 0;
            auVar140._0_9_ = auVar1072._0_9_;
            auVar140._10_5_ = auVar103._10_5_;
            auVar153[8] = pbVar949[0x22];
            auVar153._0_8_ = auVar1072._0_8_;
            auVar153._9_6_ = auVar140._9_6_;
            auVar631._7_8_ = 0;
            auVar631._0_7_ = auVar153._8_7_;
            Var360 = CONCAT81(SUB158(auVar631 << 0x40,7),bVar180);
            auVar862._9_6_ = 0;
            auVar862._0_9_ = Var360;
            auVar632._1_10_ = SUB1510(auVar862 << 0x30,5);
            auVar632[0] = bVar173;
            auVar863._11_4_ = 0;
            auVar863._0_11_ = auVar632;
            auVar633._1_12_ = SUB1512(auVar863 << 0x20,3);
            auVar633[0] = uVar1852;
            auVar167[1] = 0;
            auVar167[0] = auVar1181[0];
            auVar167._2_13_ = auVar633;
            bVar173 = pbVar955[0x16];
            bVar176 = pbVar955[0x18];
            bVar180 = pbVar955[0x1a];
            bVar183 = pbVar955[0x1c];
            bVar184 = pbVar955[0x1e];
            bVar185 = pbVar955[0x20];
            bVar186 = pbVar955[0x22];
            auVar1181 = *(undefined1 (*) [16])(pbVar955 + 6);
            auVar1087._0_14_ = auVar1181._0_14_;
            auVar1087[0xe] = auVar1181[7];
            auVar1087[0xf] = pbVar955[0x1d];
            auVar1086._14_2_ = auVar1087._14_2_;
            auVar1086._0_13_ = auVar1181._0_13_;
            auVar1086[0xd] = bVar183;
            auVar1085._13_3_ = auVar1086._13_3_;
            auVar1085._0_12_ = auVar1181._0_12_;
            auVar1085[0xc] = auVar1181[6];
            auVar1084._12_4_ = auVar1085._12_4_;
            auVar1084._0_11_ = auVar1181._0_11_;
            auVar1084[0xb] = pbVar955[0x1b];
            auVar1083._11_5_ = auVar1084._11_5_;
            auVar1083._0_10_ = auVar1181._0_10_;
            auVar1083[10] = auVar1181[5];
            auVar1082._10_6_ = auVar1083._10_6_;
            auVar1082._0_9_ = auVar1181._0_9_;
            auVar1082[9] = bVar180;
            uVar1176 = auVar1181[4];
            auVar1081._9_7_ = auVar1082._9_7_;
            auVar1081._0_8_ = auVar1181._0_8_;
            auVar1081[8] = uVar1176;
            auVar638._1_8_ = auVar1081._8_8_;
            auVar638[0] = pbVar955[0x19];
            auVar638._9_7_ = 0;
            auVar637._10_6_ = 0;
            auVar637._0_10_ = SUB1610(auVar638 << 0x38,6);
            auVar636._11_5_ = 0;
            auVar636._0_11_ = SUB1611(auVar637 << 0x30,5);
            auVar635._12_4_ = 0;
            auVar635._0_12_ = SUB1612(auVar636 << 0x28,4);
            auVar634._13_3_ = 0;
            auVar634._0_13_ = SUB1613(auVar635 << 0x20,3);
            auVar1080._14_2_ = 0;
            auVar1080._0_14_ = SUB1614(auVar634 << 0x18,2);
            auVar1080 = auVar1080 << 0x10;
            uVar1852 = auVar1181[8];
            uVar1853 = auVar1181[10];
            auVar1095._0_14_ = auVar1080._0_14_;
            auVar1095[0xe] = pbVar955[0x19];
            auVar1095[0xf] = pbVar955[0x21];
            auVar1094._14_2_ = auVar1095._14_2_;
            auVar1094._0_13_ = auVar1080._0_13_;
            auVar1094[0xd] = auVar1181[0xb];
            auVar1093._13_3_ = auVar1094._13_3_;
            auVar1093._0_12_ = auVar1080._0_12_;
            auVar1093[0xc] = auVar1181[3];
            auVar1092._12_4_ = auVar1093._12_4_;
            auVar1092._0_11_ = auVar1080._0_11_;
            auVar1092[0xb] = bVar185;
            auVar1091._11_5_ = auVar1092._11_5_;
            auVar1091._0_10_ = auVar1080._0_10_;
            auVar1091[10] = bVar176;
            auVar1090._10_6_ = auVar1091._10_6_;
            auVar1090._0_9_ = auVar1080._0_9_;
            auVar1090[9] = uVar1853;
            auVar1089._9_7_ = auVar1090._9_7_;
            auVar1089._0_8_ = auVar1080._0_8_;
            auVar1089[8] = auVar1181[2];
            auVar643._1_8_ = auVar1089._8_8_;
            auVar643[0] = pbVar955[0x1f];
            auVar643._9_7_ = 0;
            auVar642._10_6_ = 0;
            auVar642._0_10_ = SUB1610(auVar643 << 0x38,6);
            auVar641._11_5_ = 0;
            auVar641._0_11_ = SUB1611(auVar642 << 0x30,5);
            auVar640._12_4_ = 0;
            auVar640._0_12_ = SUB1612(auVar641 << 0x28,4);
            auVar639._13_3_ = 0;
            auVar639._0_13_ = SUB1613(auVar640 << 0x20,3);
            auVar1088._14_2_ = 0;
            auVar1088._0_14_ = SUB1614(auVar639 << 0x18,2);
            auVar1088 = auVar1088 << 0x10;
            auVar1103._0_14_ = auVar1088._0_14_;
            auVar1103[0xe] = pbVar955[0x1f];
            auVar1103[0xf] = pbVar955[0x23];
            auVar1102._14_2_ = auVar1103._14_2_;
            auVar1102._0_13_ = auVar1088._0_13_;
            auVar1102[0xd] = pbVar955[0x1b];
            auVar1101._13_3_ = auVar1102._13_3_;
            auVar1101._0_12_ = auVar1088._0_12_;
            auVar1101[0xc] = pbVar955[0x17];
            auVar1100._12_4_ = auVar1101._12_4_;
            auVar1100._0_11_ = auVar1088._0_11_;
            auVar1100[0xb] = auVar1181[0xd];
            auVar1099._11_5_ = auVar1100._11_5_;
            auVar1099._0_10_ = auVar1088._0_10_;
            auVar1099[10] = auVar1181[9];
            auVar1098._10_6_ = auVar1099._10_6_;
            auVar1098._0_9_ = auVar1088._0_9_;
            auVar1098[9] = auVar1181[5];
            auVar1097._9_7_ = auVar1098._9_7_;
            auVar1097._0_8_ = auVar1088._0_8_;
            auVar1097[8] = auVar1181[1];
            auVar648._1_8_ = auVar1097._8_8_;
            auVar648[0] = bVar186;
            auVar648._9_7_ = 0;
            auVar647._10_6_ = 0;
            auVar647._0_10_ = SUB1610(auVar648 << 0x38,6);
            auVar646._11_5_ = 0;
            auVar646._0_11_ = SUB1611(auVar647 << 0x30,5);
            auVar645._12_4_ = 0;
            auVar645._0_12_ = SUB1612(auVar646 << 0x28,4);
            auVar644._13_3_ = 0;
            auVar644._0_13_ = SUB1613(auVar645 << 0x20,3);
            auVar1096._14_2_ = 0;
            auVar1096._0_14_ = SUB1614(auVar644 << 0x18,2);
            auVar1096 = auVar1096 << 0x10;
            bVar187 = pbVar955[0x2a];
            bVar188 = pbVar955[0x2e];
            bVar199 = pbVar955[0x32];
            auVar1111._0_14_ = auVar1096._0_14_;
            auVar1111[0xe] = bVar186;
            auVar1111[0xf] = pbVar955[0x24];
            auVar1110._14_2_ = auVar1111._14_2_;
            auVar1110._0_13_ = auVar1096._0_13_;
            auVar1110[0xd] = bVar185;
            auVar1109._13_3_ = auVar1110._13_3_;
            auVar1109._0_12_ = auVar1096._0_12_;
            auVar1109[0xc] = bVar184;
            auVar1108._12_4_ = auVar1109._12_4_;
            auVar1108._0_11_ = auVar1096._0_11_;
            auVar1108[0xb] = bVar183;
            auVar1107._11_5_ = auVar1108._11_5_;
            auVar1107._0_10_ = auVar1096._0_10_;
            auVar1107[10] = bVar180;
            auVar1106._10_6_ = auVar1107._10_6_;
            auVar1106._0_9_ = auVar1096._0_9_;
            auVar1106[9] = bVar176;
            auVar1105._9_7_ = auVar1106._9_7_;
            auVar1105._0_8_ = auVar1096._0_8_;
            auVar1105[8] = bVar173;
            auVar653._1_8_ = auVar1105._8_8_;
            auVar653[0] = auVar1181[0xe];
            auVar653._9_7_ = 0;
            auVar652._10_6_ = 0;
            auVar652._0_10_ = SUB1610(auVar653 << 0x38,6);
            auVar651._11_5_ = 0;
            auVar651._0_11_ = SUB1611(auVar652 << 0x30,5);
            auVar650._12_4_ = 0;
            auVar650._0_12_ = SUB1612(auVar651 << 0x28,4);
            auVar649._13_3_ = 0;
            auVar649._0_13_ = SUB1613(auVar650 << 0x20,3);
            auVar1104._14_2_ = 0;
            auVar1104._0_14_ = SUB1614(auVar649 << 0x18,2);
            auVar1104 = auVar1104 << 0x10;
            bVar202 = pbVar955[0x3a];
            bVar203 = pbVar955[0x3e];
            auVar1119._0_14_ = auVar1104._0_14_;
            auVar1119[0xe] = auVar1181[0xe];
            auVar1119[0xf] = pbVar955[0x34];
            auVar1118._14_2_ = auVar1119._14_2_;
            auVar1118._0_13_ = auVar1104._0_13_;
            auVar1118[0xd] = bVar199;
            auVar1117._13_3_ = auVar1118._13_3_;
            auVar1117._0_12_ = auVar1104._0_12_;
            auVar1117[0xc] = auVar1181[0xc];
            auVar1116._12_4_ = auVar1117._12_4_;
            auVar1116._0_11_ = auVar1104._0_11_;
            auVar1116[0xb] = pbVar955[0x30];
            auVar1115._11_5_ = auVar1116._11_5_;
            auVar1115._0_10_ = auVar1104._0_10_;
            auVar1115[10] = uVar1853;
            auVar1114._10_6_ = auVar1115._10_6_;
            auVar1114._0_9_ = auVar1104._0_9_;
            auVar1114[9] = bVar188;
            auVar1113._9_7_ = auVar1114._9_7_;
            auVar1113._0_8_ = auVar1104._0_8_;
            auVar1113[8] = uVar1852;
            auVar658._1_8_ = auVar1113._8_8_;
            auVar658[0] = pbVar955[0x2c];
            auVar658._9_7_ = 0;
            auVar657._10_6_ = 0;
            auVar657._0_10_ = SUB1610(auVar658 << 0x38,6);
            auVar656._11_5_ = 0;
            auVar656._0_11_ = SUB1611(auVar657 << 0x30,5);
            auVar655._12_4_ = 0;
            auVar655._0_12_ = SUB1612(auVar656 << 0x28,4);
            auVar654._13_3_ = 0;
            auVar654._0_13_ = SUB1613(auVar655 << 0x20,3);
            auVar1112._14_2_ = 0;
            auVar1112._0_14_ = SUB1614(auVar654 << 0x18,2);
            auVar1112 = auVar1112 << 0x10;
            auVar1127._0_14_ = auVar1112._0_14_;
            auVar1127[0xe] = pbVar955[0x2c];
            auVar1127[0xf] = pbVar955[0x3c];
            auVar1126._14_2_ = auVar1127._14_2_;
            auVar1126._0_13_ = auVar1112._0_13_;
            auVar1126[0xd] = bVar183;
            auVar1125._13_3_ = auVar1126._13_3_;
            auVar1125._0_12_ = auVar1112._0_12_;
            auVar1125[0xc] = auVar1181[6];
            auVar1124._12_4_ = auVar1125._12_4_;
            auVar1124._0_11_ = auVar1112._0_11_;
            auVar1124[0xb] = bVar202;
            auVar1123._11_5_ = auVar1124._11_5_;
            auVar1123._0_10_ = auVar1112._0_10_;
            auVar1123[10] = bVar187;
            auVar1122._10_6_ = auVar1123._10_6_;
            auVar1122._0_9_ = auVar1112._0_9_;
            auVar1122[9] = bVar180;
            auVar1121._9_7_ = auVar1122._9_7_;
            auVar1121._0_8_ = auVar1112._0_8_;
            auVar1121[8] = uVar1176;
            auVar663._1_8_ = auVar1121._8_8_;
            auVar663[0] = pbVar955[0x38];
            auVar663._9_7_ = 0;
            auVar662._10_6_ = 0;
            auVar662._0_10_ = SUB1610(auVar663 << 0x38,6);
            auVar661._11_5_ = 0;
            auVar661._0_11_ = SUB1611(auVar662 << 0x30,5);
            auVar660._12_4_ = 0;
            auVar660._0_12_ = SUB1612(auVar661 << 0x28,4);
            auVar659._13_3_ = 0;
            auVar659._0_13_ = SUB1613(auVar660 << 0x20,3);
            auVar1120._14_2_ = 0;
            auVar1120._0_14_ = SUB1614(auVar659 << 0x18,2);
            auVar1120 = auVar1120 << 0x10;
            auVar1135._0_14_ = auVar1120._0_14_;
            auVar1135[0xe] = pbVar955[0x38];
            auVar1135[0xf] = pbVar955[0x40];
            auVar1134._14_2_ = auVar1135._14_2_;
            auVar1134._0_13_ = auVar1120._0_13_;
            auVar1134[0xd] = pbVar955[0x30];
            auVar1133._13_3_ = auVar1134._13_3_;
            auVar1133._0_12_ = auVar1120._0_12_;
            auVar1133[0xc] = pbVar955[0x28];
            auVar1132._12_4_ = auVar1133._12_4_;
            auVar1132._0_11_ = auVar1120._0_11_;
            auVar1132[0xb] = bVar185;
            auVar1131._11_5_ = auVar1132._11_5_;
            auVar1131._0_10_ = auVar1120._0_10_;
            auVar1131[10] = bVar176;
            auVar1130._10_6_ = auVar1131._10_6_;
            auVar1130._0_9_ = auVar1120._0_9_;
            auVar1130[9] = uVar1853;
            auVar1129._9_7_ = auVar1130._9_7_;
            auVar1129._0_8_ = auVar1120._0_8_;
            auVar1129[8] = auVar1181[2];
            auVar668._1_8_ = auVar1129._8_8_;
            auVar668[0] = bVar203;
            auVar668._9_7_ = 0;
            auVar667._10_6_ = 0;
            auVar667._0_10_ = SUB1610(auVar668 << 0x38,6);
            auVar666._11_5_ = 0;
            auVar666._0_11_ = SUB1611(auVar667 << 0x30,5);
            auVar665._12_4_ = 0;
            auVar665._0_12_ = SUB1612(auVar666 << 0x28,4);
            auVar664._13_3_ = 0;
            auVar664._0_13_ = SUB1613(auVar665 << 0x20,3);
            auVar1128._14_2_ = 0;
            auVar1128._0_14_ = SUB1614(auVar664 << 0x18,2);
            auVar1128 = auVar1128 << 0x10;
            bVar176 = pbVar955[0x56];
            bVar183 = pbVar955[0x5e];
            auVar1143._0_14_ = auVar1128._0_14_;
            auVar1143[0xe] = bVar203;
            auVar1143[0xf] = pbVar955[0x42];
            auVar1142._14_2_ = auVar1143._14_2_;
            auVar1142._0_13_ = auVar1128._0_13_;
            auVar1142[0xd] = bVar202;
            auVar1141._13_3_ = auVar1142._13_3_;
            auVar1141._0_12_ = auVar1128._0_12_;
            auVar1141[0xc] = pbVar955[0x36];
            auVar1140._12_4_ = auVar1141._12_4_;
            auVar1140._0_11_ = auVar1128._0_11_;
            auVar1140[0xb] = bVar199;
            auVar1139._11_5_ = auVar1140._11_5_;
            auVar1139._0_10_ = auVar1128._0_10_;
            auVar1139[10] = bVar188;
            auVar1138._10_6_ = auVar1139._10_6_;
            auVar1138._0_9_ = auVar1128._0_9_;
            auVar1138[9] = bVar187;
            auVar1137._9_7_ = auVar1138._9_7_;
            auVar1137._0_8_ = auVar1128._0_8_;
            auVar1137[8] = pbVar955[0x26];
            auVar673._1_8_ = auVar1137._8_8_;
            auVar673[0] = bVar186;
            auVar673._9_7_ = 0;
            auVar672._10_6_ = 0;
            auVar672._0_10_ = SUB1610(auVar673 << 0x38,6);
            auVar671._11_5_ = 0;
            auVar671._0_11_ = SUB1611(auVar672 << 0x30,5);
            auVar670._12_4_ = 0;
            auVar670._0_12_ = SUB1612(auVar671 << 0x28,4);
            auVar669._13_3_ = 0;
            auVar669._0_13_ = SUB1613(auVar670 << 0x20,3);
            auVar1136._14_2_ = 0;
            auVar1136._0_14_ = SUB1614(auVar669 << 0x18,2);
            auVar1136 = auVar1136 << 0x10;
            bVar185 = pbVar955[0x4e];
            auVar1151._0_14_ = auVar1136._0_14_;
            auVar1151[0xe] = bVar186;
            auVar1151[0xf] = pbVar955[0x62];
            auVar1150._14_2_ = auVar1151._14_2_;
            auVar1150._0_13_ = auVar1136._0_13_;
            auVar1150[0xd] = bVar183;
            auVar1149._13_3_ = auVar1150._13_3_;
            auVar1149._0_12_ = auVar1136._0_12_;
            auVar1149[0xc] = bVar184;
            auVar1148._12_4_ = auVar1149._12_4_;
            auVar1148._0_11_ = auVar1136._0_11_;
            auVar1148[0xb] = pbVar955[0x5a];
            auVar1147._11_5_ = auVar1148._11_5_;
            auVar1147._0_10_ = auVar1136._0_10_;
            auVar1147[10] = bVar180;
            auVar1146._10_6_ = auVar1147._10_6_;
            auVar1146._0_9_ = auVar1136._0_9_;
            auVar1146[9] = bVar176;
            auVar1145._9_7_ = auVar1146._9_7_;
            auVar1145._0_8_ = auVar1136._0_8_;
            auVar1145[8] = bVar173;
            auVar678._1_8_ = auVar1145._8_8_;
            auVar678[0] = pbVar955[0x52];
            auVar678._9_7_ = 0;
            auVar677._10_6_ = 0;
            auVar677._0_10_ = SUB1610(auVar678 << 0x38,6);
            auVar676._11_5_ = 0;
            auVar676._0_11_ = SUB1611(auVar677 << 0x30,5);
            auVar675._12_4_ = 0;
            auVar675._0_12_ = SUB1612(auVar676 << 0x28,4);
            auVar674._13_3_ = 0;
            auVar674._0_13_ = SUB1613(auVar675 << 0x20,3);
            auVar1144._14_2_ = 0;
            auVar1144._0_14_ = SUB1614(auVar674 << 0x18,2);
            auVar1144 = auVar1144 << 0x10;
            auVar1159._0_14_ = auVar1144._0_14_;
            auVar1159[0xe] = pbVar955[0x52];
            auVar1159[0xf] = pbVar955[0x72];
            auVar1158._14_2_ = auVar1159._14_2_;
            auVar1158._0_13_ = auVar1144._0_13_;
            auVar1158[0xd] = bVar199;
            auVar1157._13_3_ = auVar1158._13_3_;
            auVar1157._0_12_ = auVar1144._0_12_;
            auVar1157[0xc] = auVar1181[0xc];
            auVar1156._12_4_ = auVar1157._12_4_;
            auVar1156._0_11_ = auVar1144._0_11_;
            auVar1156[0xb] = pbVar955[0x6e];
            auVar1155._11_5_ = auVar1156._11_5_;
            auVar1155._0_10_ = auVar1144._0_10_;
            auVar1155[10] = bVar185;
            auVar1154._10_6_ = auVar1155._10_6_;
            auVar1154._0_9_ = auVar1144._0_9_;
            auVar1154[9] = bVar188;
            auVar1153._9_7_ = auVar1154._9_7_;
            auVar1153._0_8_ = auVar1144._0_8_;
            auVar1153[8] = uVar1852;
            auVar683._1_8_ = auVar1153._8_8_;
            auVar683[0] = pbVar955[0x6a];
            auVar683._9_7_ = 0;
            auVar682._10_6_ = 0;
            auVar682._0_10_ = SUB1610(auVar683 << 0x38,6);
            auVar681._11_5_ = 0;
            auVar681._0_11_ = SUB1611(auVar682 << 0x30,5);
            auVar680._12_4_ = 0;
            auVar680._0_12_ = SUB1612(auVar681 << 0x28,4);
            auVar679._13_3_ = 0;
            auVar679._0_13_ = SUB1613(auVar680 << 0x20,3);
            auVar1152._14_2_ = 0;
            auVar1152._0_14_ = SUB1614(auVar679 << 0x18,2);
            auVar1152 = auVar1152 << 0x10;
            auVar1167._0_14_ = auVar1152._0_14_;
            auVar1167[0xe] = pbVar955[0x6a];
            auVar1167[0xf] = pbVar955[0x7a];
            auVar1166._14_2_ = auVar1167._14_2_;
            auVar1166._0_13_ = auVar1152._0_13_;
            auVar1166[0xd] = pbVar955[0x5a];
            auVar1165._13_3_ = auVar1166._13_3_;
            auVar1165._0_12_ = auVar1152._0_12_;
            auVar1165[0xc] = pbVar955[0x4a];
            auVar1164._12_4_ = auVar1165._12_4_;
            auVar1164._0_11_ = auVar1152._0_11_;
            auVar1164[0xb] = bVar202;
            auVar1163._11_5_ = auVar1164._11_5_;
            auVar1163._0_10_ = auVar1152._0_10_;
            auVar1163[10] = bVar187;
            auVar1162._10_6_ = auVar1163._10_6_;
            auVar1162._0_9_ = auVar1152._0_9_;
            auVar1162[9] = bVar180;
            auVar1161._9_7_ = auVar1162._9_7_;
            auVar1161._0_8_ = auVar1152._0_8_;
            auVar1161[8] = uVar1176;
            auVar688._1_8_ = auVar1161._8_8_;
            auVar688[0] = pbVar955[0x76];
            auVar688._9_7_ = 0;
            auVar687._10_6_ = 0;
            auVar687._0_10_ = SUB1610(auVar688 << 0x38,6);
            auVar686._11_5_ = 0;
            auVar686._0_11_ = SUB1611(auVar687 << 0x30,5);
            auVar685._12_4_ = 0;
            auVar685._0_12_ = SUB1612(auVar686 << 0x28,4);
            auVar684._13_3_ = 0;
            auVar684._0_13_ = SUB1613(auVar685 << 0x20,3);
            auVar1160._14_2_ = 0;
            auVar1160._0_14_ = SUB1614(auVar684 << 0x18,2);
            auVar1160 = auVar1160 << 0x10;
            auVar27._10_2_ = 0;
            auVar27._0_10_ = auVar166._0_10_;
            auVar27._12_2_ = (short)Var296;
            uVar913 = CONCAT42(auVar27._10_4_,auVar569._0_2_);
            auVar689._6_8_ = 0;
            auVar689._0_6_ = uVar913;
            auVar104._4_2_ = auVar570._0_2_;
            auVar104._0_4_ = auVar166._0_4_;
            auVar104._6_8_ = SUB148(auVar689 << 0x40,6);
            auVar1175._0_14_ = auVar1160._0_14_;
            auVar1175[0xe] = pbVar955[0x76];
            auVar1175[0xf] = pbVar955[0x7e];
            auVar1174._14_2_ = auVar1175._14_2_;
            auVar1174._0_13_ = auVar1160._0_13_;
            auVar1174[0xd] = pbVar955[0x6e];
            auVar1173._13_3_ = auVar1174._13_3_;
            auVar1173._0_12_ = auVar1160._0_12_;
            auVar1173[0xc] = pbVar955[0x66];
            auVar1172._12_4_ = auVar1173._12_4_;
            auVar1172._0_11_ = auVar1160._0_11_;
            auVar1172[0xb] = bVar183;
            auVar1171._11_5_ = auVar1172._11_5_;
            auVar1171._0_10_ = auVar1160._0_10_;
            auVar1171[10] = bVar176;
            auVar1170._10_6_ = auVar1171._10_6_;
            auVar1170._0_9_ = auVar1160._0_9_;
            auVar1170[9] = bVar185;
            auVar1169._9_7_ = auVar1170._9_7_;
            auVar1169._0_8_ = auVar1160._0_8_;
            auVar1169[8] = pbVar955[0x46];
            auVar694._1_8_ = auVar1169._8_8_;
            auVar694[0] = bVar203;
            auVar694._9_7_ = 0;
            auVar693._10_6_ = 0;
            auVar693._0_10_ = SUB1610(auVar694 << 0x38,6);
            auVar692._11_5_ = 0;
            auVar692._0_11_ = SUB1611(auVar693 << 0x30,5);
            auVar691._12_4_ = 0;
            auVar691._0_12_ = SUB1612(auVar692 << 0x28,4);
            auVar690._13_3_ = 0;
            auVar690._0_13_ = SUB1613(auVar691 << 0x20,3);
            auVar1168._14_2_ = 0;
            auVar1168._0_14_ = SUB1614(auVar690 << 0x18,2);
            auVar1168 = auVar1168 << 0x10;
            auVar28._10_2_ = 0;
            auVar28._0_10_ = auVar165._0_10_;
            auVar28._12_2_ = (short)Var293;
            uVar914 = CONCAT42(auVar28._10_4_,auVar567._0_2_);
            auVar695._6_8_ = 0;
            auVar695._0_6_ = uVar914;
            auVar105._4_2_ = auVar912._0_2_;
            auVar105._0_4_ = auVar165._0_4_;
            auVar105._6_8_ = SUB148(auVar695 << 0x40,6);
            auVar29._10_2_ = 0;
            auVar29._0_10_ = auVar167._0_10_;
            auVar29._12_2_ = (short)Var360;
            uVar915 = CONCAT42(auVar29._10_4_,auVar632._0_2_);
            auVar696._6_8_ = 0;
            auVar696._0_6_ = uVar915;
            auVar106._4_2_ = auVar633._0_2_;
            auVar106._0_4_ = auVar167._0_4_;
            auVar106._6_8_ = SUB148(auVar696 << 0x40,6);
            uStack_e4 = auVar152._8_2_;
            uStack_e2 = auVar101._10_2_;
            auVar30[0xd] = 0;
            auVar30._0_13_ = auVar1168._0_13_;
            auVar30[0xe] = bVar203;
            auVar48[0xc] = pbVar955[0x36];
            auVar48._0_12_ = auVar1168._0_12_;
            auVar48._13_2_ = auVar30._13_2_;
            auVar62[0xb] = 0;
            auVar62._0_11_ = auVar1168._0_11_;
            auVar62._12_3_ = auVar48._12_3_;
            uVar107 = auVar62._11_4_;
            auVar108[10] = bVar188;
            auVar108._0_10_ = auVar1168._0_10_;
            auVar108._11_4_ = uVar107;
            auVar141[9] = 0;
            auVar141._0_9_ = auVar1168._0_9_;
            auVar141._10_5_ = auVar108._10_5_;
            auVar154[8] = pbVar955[0x26];
            auVar154._0_8_ = auVar1168._0_8_;
            auVar154._9_6_ = auVar141._9_6_;
            auVar697._7_8_ = 0;
            auVar697._0_7_ = auVar154._8_7_;
            Var293 = CONCAT81(SUB158(auVar697 << 0x40,7),bVar184);
            auVar864._9_6_ = 0;
            auVar864._0_9_ = Var293;
            auVar698._1_10_ = SUB1510(auVar864 << 0x30,5);
            auVar698[0] = bVar173;
            auVar865._11_4_ = 0;
            auVar865._0_11_ = auVar698;
            auVar699._1_12_ = SUB1512(auVar865 << 0x20,3);
            auVar699[0] = uVar1852;
            auVar168[1] = 0;
            auVar168[0] = auVar1181[0];
            auVar168._2_13_ = auVar699;
            uVar1863 = (uint)uStack_e4;
            auVar31._10_2_ = 0;
            auVar31._0_10_ = auVar168._0_10_;
            auVar31._12_2_ = (short)Var293;
            uVar916 = CONCAT42(auVar31._10_4_,auVar698._0_2_);
            auVar700._6_8_ = 0;
            auVar700._0_6_ = uVar916;
            auVar109._4_2_ = auVar699._0_2_;
            auVar109._0_4_ = auVar168._0_4_;
            auVar109._6_8_ = SUB148(auVar700 << 0x40,6);
            uStack_b4 = (ushort)((ulonglong)uVar927 >> 8);
            uStack_b2 = (ushort)((ulonglong)uVar928 >> 0x18);
            uVar1855 = (uint)uStack_b4;
            uVar1867 = (uint)uStack_e2;
            uStack_a4 = auVar153._8_2_;
            uStack_a2 = auVar103._10_2_;
            uVar1592 = CONCAT13(0,CONCAT12(bVar185,(ushort)pbVar955[0x46]));
            auVar888[0xc] = uStack_ce;
            auVar888._0_12_ = ZEXT112(bStack_e6) << 0x40;
            auVar889._10_3_ = auVar888._10_3_;
            auVar889._0_10_ = (unkuint10)bStack_d6 << 0x40;
            auVar110[4] = uStack_ee;
            auVar110._0_4_ = uVar1862;
            auVar110[5] = 0;
            auVar110._6_8_ = SUB148(ZEXT514(auVar889._8_5_) << 0x40,6);
            auVar890[0xc] = (undefined1)uStack_d2;
            auVar890._0_12_ = ZEXT112(bStack_ea) << 0x40;
            auVar891._10_3_ = auVar890._10_3_;
            auVar891._0_10_ = (unkuint10)bStack_da << 0x40;
            auVar111[4] = uStack_f2;
            auVar111._0_4_ = uVar957;
            auVar111[5] = 0;
            auVar111._6_8_ = SUB148(ZEXT514(auVar891._8_5_) << 0x40,6);
            auVar892[0xc] = bVar178;
            auVar892._0_12_ = ZEXT112(bVar193) << 0x40;
            auVar893._10_3_ = auVar892._10_3_;
            auVar893._0_10_ = (unkuint10)bVar174 << 0x40;
            auVar112[4] = bVar182;
            auVar112._0_4_ = uVar958;
            auVar112[5] = 0;
            auVar112._6_8_ = SUB148(ZEXT514(auVar893._8_5_) << 0x40,6);
            auVar113[0xc] = bVar183;
            auVar113._0_12_ = ZEXT112(pbVar955[0x66]) << 0x40;
            auVar114._10_3_ = auVar113._10_3_;
            auVar114._0_10_ = (unkuint10)bVar176 << 0x40;
            auVar701._5_8_ = 0;
            auVar701._0_5_ = auVar114._8_5_;
            auVar115[4] = bVar185;
            auVar115._0_4_ = uVar1592;
            auVar115[5] = 0;
            auVar115._6_7_ = SUB137(auVar701 << 0x40,6);
            auVar938._6_8_ = 0;
            auVar32[0xe] = uStack_fd;
            auVar32._0_14_ = auVar938 << 0x38;
            auVar839._4_8_ = 0;
            auVar839._0_4_ = uVar116;
            auVar63._12_3_ = (int3)(CONCAT26(auVar32._13_2_,CONCAT15(uStack_105,uVar929)) >> 0x28);
            auVar63._0_12_ = auVar839 << 0x38;
            uVar116 = auVar63._11_4_;
            uVar933 = CONCAT44(uVar116,CONCAT13(pbVar2[0xf],uVar923));
            auVar142._10_5_ = (int5)((ulonglong)uVar933 >> 0x18);
            auVar142._0_10_ = (unkuint10)CONCAT11(bStack_f5,uStack_fd) << 0x38;
            uVar927 = CONCAT62(auVar142._9_6_,CONCAT11(bVar179,uStack_fd));
            auVar702._7_8_ = 0;
            auVar702._0_7_ = (uint7)((ulonglong)uVar927 >> 8);
            Var293 = CONCAT81(SUB158(auVar702 << 0x40,7),uStack_ad);
            auVar866._9_6_ = 0;
            auVar866._0_9_ = Var293;
            auVar703._1_10_ = SUB1510(auVar866 << 0x30,5);
            auVar703[0] = uStack_b5;
            auVar867._11_4_ = 0;
            auVar867._0_11_ = auVar703;
            auVar917._1_12_ = SUB1512(auVar867 << 0x20,3);
            auVar917[0] = bVar177;
            auVar169[1] = 0;
            auVar169[0] = pbVar1[7];
            auVar169._2_13_ = auVar917;
            uVar1856 = CONCAT13(0,CONCAT12(uStack_f1,(ushort)bStack_f9));
            auVar939._6_8_ = 0;
            auVar33[0xe] = uStack_101;
            auVar33._0_14_ = auVar939 << 0x38;
            auVar840._4_8_ = 0;
            auVar840._0_4_ = uVar117;
            auVar64._12_3_ = (int3)(CONCAT26(auVar33._13_2_,CONCAT15(uStack_109,uVar932)) >> 0x28);
            auVar64._0_12_ = auVar840 << 0x38;
            uVar117 = auVar64._11_4_;
            uVar934 = CONCAT44(uVar117,CONCAT13(bVar181,uVar926));
            auVar143._10_5_ = (int5)((ulonglong)uVar934 >> 0x18);
            auVar143._0_10_ = (unkuint10)CONCAT11(bStack_f9,uStack_101) << 0x38;
            uVar928 = CONCAT62(auVar143._9_6_,CONCAT11(pbVar2[3],uStack_101));
            auVar704._7_8_ = 0;
            auVar704._0_7_ = (uint7)((ulonglong)uVar928 >> 8);
            Var296 = CONCAT81(SUB158(auVar704 << 0x40,7),uVar1820);
            auVar868._9_6_ = 0;
            auVar868._0_9_ = Var296;
            auVar705._1_10_ = SUB1510(auVar868 << 0x30,5);
            auVar705[0] = uStack_b9;
            auVar869._11_4_ = 0;
            auVar869._0_11_ = auVar705;
            auVar918._1_12_ = SUB1512(auVar869 << 0x20,3);
            auVar918[0] = bVar175;
            auVar170[1] = 0;
            auVar170[0] = pbVar1[3];
            auVar170._2_13_ = auVar918;
            bVar173 = pbVar953[0x13];
            bVar174 = pbVar953[0x15];
            bVar175 = pbVar953[0x17];
            bVar176 = pbVar953[0x19];
            bVar177 = pbVar953[0x1b];
            bVar178 = pbVar953[0x1d];
            bVar179 = pbVar953[0x1f];
            uVar1593 = CONCAT13(0,CONCAT12(uStack_ed,(ushort)bStack_f5));
            auVar1181 = *(undefined1 (*) [16])(pbVar953 + 3);
            auVar1635._0_14_ = auVar1181._0_14_;
            auVar1635[0xe] = auVar1181[7];
            auVar1635[0xf] = pbVar953[0x1a];
            auVar1634._14_2_ = auVar1635._14_2_;
            auVar1634._0_13_ = auVar1181._0_13_;
            auVar1634[0xd] = bVar176;
            auVar1633._13_3_ = auVar1634._13_3_;
            auVar1633._0_12_ = auVar1181._0_12_;
            auVar1633[0xc] = auVar1181[6];
            auVar1632._12_4_ = auVar1633._12_4_;
            auVar1632._0_11_ = auVar1181._0_11_;
            auVar1632[0xb] = pbVar953[0x18];
            auVar1631._11_5_ = auVar1632._11_5_;
            auVar1631._0_10_ = auVar1181._0_10_;
            auVar1631[10] = auVar1181[5];
            auVar1630._10_6_ = auVar1631._10_6_;
            auVar1630._0_9_ = auVar1181._0_9_;
            auVar1630[9] = bVar175;
            uVar1820 = auVar1181[4];
            auVar1629._9_7_ = auVar1630._9_7_;
            auVar1629._0_8_ = auVar1181._0_8_;
            auVar1629[8] = uVar1820;
            auVar710._1_8_ = auVar1629._8_8_;
            auVar710[0] = pbVar953[0x16];
            auVar710._9_7_ = 0;
            auVar709._10_6_ = 0;
            auVar709._0_10_ = SUB1610(auVar710 << 0x38,6);
            auVar708._11_5_ = 0;
            auVar708._0_11_ = SUB1611(auVar709 << 0x30,5);
            auVar707._12_4_ = 0;
            auVar707._0_12_ = SUB1612(auVar708 << 0x28,4);
            auVar706._13_3_ = 0;
            auVar706._0_13_ = SUB1613(auVar707 << 0x20,3);
            auVar1628._14_2_ = 0;
            auVar1628._0_14_ = SUB1614(auVar706 << 0x18,2);
            auVar1628 = auVar1628 << 0x10;
            uVar1176 = auVar1181[8];
            uVar1852 = auVar1181[10];
            auVar1643._0_14_ = auVar1628._0_14_;
            auVar1643[0xe] = pbVar953[0x16];
            auVar1643[0xf] = pbVar953[0x1e];
            auVar1642._14_2_ = auVar1643._14_2_;
            auVar1642._0_13_ = auVar1628._0_13_;
            auVar1642[0xd] = auVar1181[0xb];
            auVar1641._13_3_ = auVar1642._13_3_;
            auVar1641._0_12_ = auVar1628._0_12_;
            auVar1641[0xc] = auVar1181[3];
            auVar1640._12_4_ = auVar1641._12_4_;
            auVar1640._0_11_ = auVar1628._0_11_;
            auVar1640[0xb] = bVar178;
            auVar1639._11_5_ = auVar1640._11_5_;
            auVar1639._0_10_ = auVar1628._0_10_;
            auVar1639[10] = bVar174;
            auVar1638._10_6_ = auVar1639._10_6_;
            auVar1638._0_9_ = auVar1628._0_9_;
            auVar1638[9] = uVar1852;
            auVar1637._9_7_ = auVar1638._9_7_;
            auVar1637._0_8_ = auVar1628._0_8_;
            auVar1637[8] = auVar1181[2];
            auVar715._1_8_ = auVar1637._8_8_;
            auVar715[0] = pbVar953[0x1c];
            auVar715._9_7_ = 0;
            auVar714._10_6_ = 0;
            auVar714._0_10_ = SUB1610(auVar715 << 0x38,6);
            auVar713._11_5_ = 0;
            auVar713._0_11_ = SUB1611(auVar714 << 0x30,5);
            auVar712._12_4_ = 0;
            auVar712._0_12_ = SUB1612(auVar713 << 0x28,4);
            auVar711._13_3_ = 0;
            auVar711._0_13_ = SUB1613(auVar712 << 0x20,3);
            auVar1636._14_2_ = 0;
            auVar1636._0_14_ = SUB1614(auVar711 << 0x18,2);
            auVar1636 = auVar1636 << 0x10;
            auVar1651._0_14_ = auVar1636._0_14_;
            auVar1651[0xe] = pbVar953[0x1c];
            auVar1651[0xf] = pbVar953[0x20];
            auVar1650._14_2_ = auVar1651._14_2_;
            auVar1650._0_13_ = auVar1636._0_13_;
            auVar1650[0xd] = pbVar953[0x18];
            auVar1649._13_3_ = auVar1650._13_3_;
            auVar1649._0_12_ = auVar1636._0_12_;
            auVar1649[0xc] = pbVar953[0x14];
            auVar1648._12_4_ = auVar1649._12_4_;
            auVar1648._0_11_ = auVar1636._0_11_;
            auVar1648[0xb] = auVar1181[0xd];
            auVar1647._11_5_ = auVar1648._11_5_;
            auVar1647._0_10_ = auVar1636._0_10_;
            auVar1647[10] = auVar1181[9];
            auVar1646._10_6_ = auVar1647._10_6_;
            auVar1646._0_9_ = auVar1636._0_9_;
            auVar1646[9] = auVar1181[5];
            auVar1645._9_7_ = auVar1646._9_7_;
            auVar1645._0_8_ = auVar1636._0_8_;
            auVar1645[8] = auVar1181[1];
            auVar720._1_8_ = auVar1645._8_8_;
            auVar720[0] = bVar179;
            auVar720._9_7_ = 0;
            auVar719._10_6_ = 0;
            auVar719._0_10_ = SUB1610(auVar720 << 0x38,6);
            auVar718._11_5_ = 0;
            auVar718._0_11_ = SUB1611(auVar719 << 0x30,5);
            auVar717._12_4_ = 0;
            auVar717._0_12_ = SUB1612(auVar718 << 0x28,4);
            auVar716._13_3_ = 0;
            auVar716._0_13_ = SUB1613(auVar717 << 0x20,3);
            auVar1644._14_2_ = 0;
            auVar1644._0_14_ = SUB1614(auVar716 << 0x18,2);
            auVar1644 = auVar1644 << 0x10;
            bVar180 = pbVar953[0x27];
            bVar181 = pbVar953[0x2b];
            bVar182 = pbVar953[0x2f];
            auVar1659._0_14_ = auVar1644._0_14_;
            auVar1659[0xe] = bVar179;
            auVar1659[0xf] = pbVar953[0x21];
            auVar1658._14_2_ = auVar1659._14_2_;
            auVar1658._0_13_ = auVar1644._0_13_;
            auVar1658[0xd] = bVar178;
            auVar1657._13_3_ = auVar1658._13_3_;
            auVar1657._0_12_ = auVar1644._0_12_;
            auVar1657[0xc] = bVar177;
            auVar1656._12_4_ = auVar1657._12_4_;
            auVar1656._0_11_ = auVar1644._0_11_;
            auVar1656[0xb] = bVar176;
            auVar1655._11_5_ = auVar1656._11_5_;
            auVar1655._0_10_ = auVar1644._0_10_;
            auVar1655[10] = bVar175;
            auVar1654._10_6_ = auVar1655._10_6_;
            auVar1654._0_9_ = auVar1644._0_9_;
            auVar1654[9] = bVar174;
            auVar1653._9_7_ = auVar1654._9_7_;
            auVar1653._0_8_ = auVar1644._0_8_;
            auVar1653[8] = bVar173;
            auVar725._1_8_ = auVar1653._8_8_;
            auVar725[0] = auVar1181[0xe];
            auVar725._9_7_ = 0;
            auVar724._10_6_ = 0;
            auVar724._0_10_ = SUB1610(auVar725 << 0x38,6);
            auVar723._11_5_ = 0;
            auVar723._0_11_ = SUB1611(auVar724 << 0x30,5);
            auVar722._12_4_ = 0;
            auVar722._0_12_ = SUB1612(auVar723 << 0x28,4);
            auVar721._13_3_ = 0;
            auVar721._0_13_ = SUB1613(auVar722 << 0x20,3);
            auVar1652._14_2_ = 0;
            auVar1652._0_14_ = SUB1614(auVar721 << 0x18,2);
            auVar1652 = auVar1652 << 0x10;
            bVar183 = pbVar953[0x37];
            bVar184 = pbVar953[0x3b];
            auVar1667._0_14_ = auVar1652._0_14_;
            auVar1667[0xe] = auVar1181[0xe];
            auVar1667[0xf] = pbVar953[0x31];
            auVar1666._14_2_ = auVar1667._14_2_;
            auVar1666._0_13_ = auVar1652._0_13_;
            auVar1666[0xd] = bVar182;
            auVar1665._13_3_ = auVar1666._13_3_;
            auVar1665._0_12_ = auVar1652._0_12_;
            auVar1665[0xc] = auVar1181[0xc];
            auVar1664._12_4_ = auVar1665._12_4_;
            auVar1664._0_11_ = auVar1652._0_11_;
            auVar1664[0xb] = pbVar953[0x2d];
            auVar1663._11_5_ = auVar1664._11_5_;
            auVar1663._0_10_ = auVar1652._0_10_;
            auVar1663[10] = uVar1852;
            auVar1662._10_6_ = auVar1663._10_6_;
            auVar1662._0_9_ = auVar1652._0_9_;
            auVar1662[9] = bVar181;
            auVar1661._9_7_ = auVar1662._9_7_;
            auVar1661._0_8_ = auVar1652._0_8_;
            auVar1661[8] = uVar1176;
            auVar730._1_8_ = auVar1661._8_8_;
            auVar730[0] = pbVar953[0x29];
            auVar730._9_7_ = 0;
            auVar729._10_6_ = 0;
            auVar729._0_10_ = SUB1610(auVar730 << 0x38,6);
            auVar728._11_5_ = 0;
            auVar728._0_11_ = SUB1611(auVar729 << 0x30,5);
            auVar727._12_4_ = 0;
            auVar727._0_12_ = SUB1612(auVar728 << 0x28,4);
            auVar726._13_3_ = 0;
            auVar726._0_13_ = SUB1613(auVar727 << 0x20,3);
            auVar1660._14_2_ = 0;
            auVar1660._0_14_ = SUB1614(auVar726 << 0x18,2);
            auVar1660 = auVar1660 << 0x10;
            auVar1675._0_14_ = auVar1660._0_14_;
            auVar1675[0xe] = pbVar953[0x29];
            auVar1675[0xf] = pbVar953[0x39];
            auVar1674._14_2_ = auVar1675._14_2_;
            auVar1674._0_13_ = auVar1660._0_13_;
            auVar1674[0xd] = bVar176;
            auVar1673._13_3_ = auVar1674._13_3_;
            auVar1673._0_12_ = auVar1660._0_12_;
            auVar1673[0xc] = auVar1181[6];
            auVar1672._12_4_ = auVar1673._12_4_;
            auVar1672._0_11_ = auVar1660._0_11_;
            auVar1672[0xb] = bVar183;
            auVar1671._11_5_ = auVar1672._11_5_;
            auVar1671._0_10_ = auVar1660._0_10_;
            auVar1671[10] = bVar180;
            auVar1670._10_6_ = auVar1671._10_6_;
            auVar1670._0_9_ = auVar1660._0_9_;
            auVar1670[9] = bVar175;
            auVar1669._9_7_ = auVar1670._9_7_;
            auVar1669._0_8_ = auVar1660._0_8_;
            auVar1669[8] = uVar1820;
            auVar735._1_8_ = auVar1669._8_8_;
            auVar735[0] = pbVar953[0x35];
            auVar735._9_7_ = 0;
            auVar734._10_6_ = 0;
            auVar734._0_10_ = SUB1610(auVar735 << 0x38,6);
            auVar733._11_5_ = 0;
            auVar733._0_11_ = SUB1611(auVar734 << 0x30,5);
            auVar732._12_4_ = 0;
            auVar732._0_12_ = SUB1612(auVar733 << 0x28,4);
            auVar731._13_3_ = 0;
            auVar731._0_13_ = SUB1613(auVar732 << 0x20,3);
            auVar1668._14_2_ = 0;
            auVar1668._0_14_ = SUB1614(auVar731 << 0x18,2);
            auVar1668 = auVar1668 << 0x10;
            auVar1683._0_14_ = auVar1668._0_14_;
            auVar1683[0xe] = pbVar953[0x35];
            auVar1683[0xf] = pbVar953[0x3d];
            auVar1682._14_2_ = auVar1683._14_2_;
            auVar1682._0_13_ = auVar1668._0_13_;
            auVar1682[0xd] = pbVar953[0x2d];
            auVar1681._13_3_ = auVar1682._13_3_;
            auVar1681._0_12_ = auVar1668._0_12_;
            auVar1681[0xc] = pbVar953[0x25];
            auVar1680._12_4_ = auVar1681._12_4_;
            auVar1680._0_11_ = auVar1668._0_11_;
            auVar1680[0xb] = bVar178;
            auVar1679._11_5_ = auVar1680._11_5_;
            auVar1679._0_10_ = auVar1668._0_10_;
            auVar1679[10] = bVar174;
            auVar1678._10_6_ = auVar1679._10_6_;
            auVar1678._0_9_ = auVar1668._0_9_;
            auVar1678[9] = uVar1852;
            auVar1677._9_7_ = auVar1678._9_7_;
            auVar1677._0_8_ = auVar1668._0_8_;
            auVar1677[8] = auVar1181[2];
            auVar740._1_8_ = auVar1677._8_8_;
            auVar740[0] = bVar184;
            auVar740._9_7_ = 0;
            auVar739._10_6_ = 0;
            auVar739._0_10_ = SUB1610(auVar740 << 0x38,6);
            auVar738._11_5_ = 0;
            auVar738._0_11_ = SUB1611(auVar739 << 0x30,5);
            auVar737._12_4_ = 0;
            auVar737._0_12_ = SUB1612(auVar738 << 0x28,4);
            auVar736._13_3_ = 0;
            auVar736._0_13_ = SUB1613(auVar737 << 0x20,3);
            auVar1676._14_2_ = 0;
            auVar1676._0_14_ = SUB1614(auVar736 << 0x18,2);
            auVar1676 = auVar1676 << 0x10;
            bVar174 = pbVar953[0x53];
            bVar176 = pbVar953[0x5b];
            auVar1691._0_14_ = auVar1676._0_14_;
            auVar1691[0xe] = bVar184;
            auVar1691[0xf] = pbVar953[0x3f];
            auVar1690._14_2_ = auVar1691._14_2_;
            auVar1690._0_13_ = auVar1676._0_13_;
            auVar1690[0xd] = bVar183;
            auVar1689._13_3_ = auVar1690._13_3_;
            auVar1689._0_12_ = auVar1676._0_12_;
            auVar1689[0xc] = pbVar953[0x33];
            auVar1688._12_4_ = auVar1689._12_4_;
            auVar1688._0_11_ = auVar1676._0_11_;
            auVar1688[0xb] = bVar182;
            auVar1687._11_5_ = auVar1688._11_5_;
            auVar1687._0_10_ = auVar1676._0_10_;
            auVar1687[10] = bVar181;
            auVar1686._10_6_ = auVar1687._10_6_;
            auVar1686._0_9_ = auVar1676._0_9_;
            auVar1686[9] = bVar180;
            auVar1685._9_7_ = auVar1686._9_7_;
            auVar1685._0_8_ = auVar1676._0_8_;
            auVar1685[8] = pbVar953[0x23];
            auVar745._1_8_ = auVar1685._8_8_;
            auVar745[0] = bVar179;
            auVar745._9_7_ = 0;
            auVar744._10_6_ = 0;
            auVar744._0_10_ = SUB1610(auVar745 << 0x38,6);
            auVar743._11_5_ = 0;
            auVar743._0_11_ = SUB1611(auVar744 << 0x30,5);
            auVar742._12_4_ = 0;
            auVar742._0_12_ = SUB1612(auVar743 << 0x28,4);
            auVar741._13_3_ = 0;
            auVar741._0_13_ = SUB1613(auVar742 << 0x20,3);
            auVar1684._14_2_ = 0;
            auVar1684._0_14_ = SUB1614(auVar741 << 0x18,2);
            auVar1684 = auVar1684 << 0x10;
            bVar178 = pbVar953[0x4b];
            bVar185 = pbVar953[99];
            bVar186 = pbVar953[0x6b];
            auVar836 = *(undefined1 (*) [12])(pbVar953 + 0x73);
            local_bc = auVar836[0];
            uStack_b8 = auVar836[4];
            uStack_b4._0_1_ = auVar836[8];
            auVar1699._0_14_ = auVar1684._0_14_;
            auVar1699[0xe] = bVar179;
            auVar1699[0xf] = pbVar953[0x5f];
            auVar1698._14_2_ = auVar1699._14_2_;
            auVar1698._0_13_ = auVar1684._0_13_;
            auVar1698[0xd] = bVar176;
            auVar1697._13_3_ = auVar1698._13_3_;
            auVar1697._0_12_ = auVar1684._0_12_;
            auVar1697[0xc] = bVar177;
            auVar1696._12_4_ = auVar1697._12_4_;
            auVar1696._0_11_ = auVar1684._0_11_;
            auVar1696[0xb] = pbVar953[0x57];
            auVar1695._11_5_ = auVar1696._11_5_;
            auVar1695._0_10_ = auVar1684._0_10_;
            auVar1695[10] = bVar175;
            auVar1694._10_6_ = auVar1695._10_6_;
            auVar1694._0_9_ = auVar1684._0_9_;
            auVar1694[9] = bVar174;
            auVar1693._9_7_ = auVar1694._9_7_;
            auVar1693._0_8_ = auVar1684._0_8_;
            auVar1693[8] = bVar173;
            auVar750._1_8_ = auVar1693._8_8_;
            auVar750[0] = pbVar953[0x4f];
            auVar750._9_7_ = 0;
            auVar749._10_6_ = 0;
            auVar749._0_10_ = SUB1610(auVar750 << 0x38,6);
            auVar748._11_5_ = 0;
            auVar748._0_11_ = SUB1611(auVar749 << 0x30,5);
            auVar747._12_4_ = 0;
            auVar747._0_12_ = SUB1612(auVar748 << 0x28,4);
            auVar746._13_3_ = 0;
            auVar746._0_13_ = SUB1613(auVar747 << 0x20,3);
            auVar1692._14_2_ = 0;
            auVar1692._0_14_ = SUB1614(auVar746 << 0x18,2);
            auVar1692 = auVar1692 << 0x10;
            auVar1707._0_14_ = auVar1692._0_14_;
            auVar1707[0xe] = pbVar953[0x4f];
            auVar1707[0xf] = pbVar953[0x6f];
            auVar1706._14_2_ = auVar1707._14_2_;
            auVar1706._0_13_ = auVar1692._0_13_;
            auVar1706[0xd] = bVar182;
            auVar1705._13_3_ = auVar1706._13_3_;
            auVar1705._0_12_ = auVar1692._0_12_;
            auVar1705[0xc] = auVar1181[0xc];
            auVar1704._12_4_ = auVar1705._12_4_;
            auVar1704._0_11_ = auVar1692._0_11_;
            auVar1704[0xb] = bVar186;
            auVar1703._11_5_ = auVar1704._11_5_;
            auVar1703._0_10_ = auVar1692._0_10_;
            auVar1703[10] = bVar178;
            auVar1702._10_6_ = auVar1703._10_6_;
            auVar1702._0_9_ = auVar1692._0_9_;
            auVar1702[9] = bVar181;
            auVar1701._9_7_ = auVar1702._9_7_;
            auVar1701._0_8_ = auVar1692._0_8_;
            auVar1701[8] = uVar1176;
            auVar755._1_8_ = auVar1701._8_8_;
            auVar755[0] = pbVar953[0x67];
            auVar755._9_7_ = 0;
            auVar754._10_6_ = 0;
            auVar754._0_10_ = SUB1610(auVar755 << 0x38,6);
            auVar753._11_5_ = 0;
            auVar753._0_11_ = SUB1611(auVar754 << 0x30,5);
            auVar752._12_4_ = 0;
            auVar752._0_12_ = SUB1612(auVar753 << 0x28,4);
            auVar751._13_3_ = 0;
            auVar751._0_13_ = SUB1613(auVar752 << 0x20,3);
            auVar1700._14_2_ = 0;
            auVar1700._0_14_ = SUB1614(auVar751 << 0x18,2);
            auVar1700 = auVar1700 << 0x10;
            auVar1715._0_14_ = auVar1700._0_14_;
            auVar1715[0xe] = pbVar953[0x67];
            auVar1715[0xf] = uStack_b8;
            auVar1714._14_2_ = auVar1715._14_2_;
            auVar1714._0_13_ = auVar1700._0_13_;
            auVar1714[0xd] = pbVar953[0x57];
            auVar1713._13_3_ = auVar1714._13_3_;
            auVar1713._0_12_ = auVar1700._0_12_;
            auVar1713[0xc] = pbVar953[0x47];
            auVar1712._12_4_ = auVar1713._12_4_;
            auVar1712._0_11_ = auVar1700._0_11_;
            auVar1712[0xb] = bVar183;
            auVar1711._11_5_ = auVar1712._11_5_;
            auVar1711._0_10_ = auVar1700._0_10_;
            auVar1711[10] = bVar180;
            auVar1710._10_6_ = auVar1711._10_6_;
            auVar1710._0_9_ = auVar1700._0_9_;
            auVar1710[9] = bVar175;
            auVar1709._9_7_ = auVar1710._9_7_;
            auVar1709._0_8_ = auVar1700._0_8_;
            auVar1709[8] = uVar1820;
            auVar760._1_8_ = auVar1709._8_8_;
            auVar760[0] = local_bc;
            auVar760._9_7_ = 0;
            auVar759._10_6_ = 0;
            auVar759._0_10_ = SUB1610(auVar760 << 0x38,6);
            auVar758._11_5_ = 0;
            auVar758._0_11_ = SUB1611(auVar759 << 0x30,5);
            auVar757._12_4_ = 0;
            auVar757._0_12_ = SUB1612(auVar758 << 0x28,4);
            auVar756._13_3_ = 0;
            auVar756._0_13_ = SUB1613(auVar757 << 0x20,3);
            auVar1708._14_2_ = 0;
            auVar1708._0_14_ = SUB1614(auVar756 << 0x18,2);
            auVar1708 = auVar1708 << 0x10;
            auVar1723._0_14_ = auVar1708._0_14_;
            auVar1723[0xe] = local_bc;
            auVar1723[0xf] = (byte)uStack_b4;
            auVar1722._14_2_ = auVar1723._14_2_;
            auVar1722._0_13_ = auVar1708._0_13_;
            auVar1722[0xd] = bVar186;
            auVar1721._13_3_ = auVar1722._13_3_;
            auVar1721._0_12_ = auVar1708._0_12_;
            auVar1721[0xc] = bVar185;
            auVar1720._12_4_ = auVar1721._12_4_;
            auVar1720._0_11_ = auVar1708._0_11_;
            auVar1720[0xb] = bVar176;
            auVar1719._11_5_ = auVar1720._11_5_;
            auVar1719._0_10_ = auVar1708._0_10_;
            auVar1719[10] = bVar174;
            auVar1718._10_6_ = auVar1719._10_6_;
            auVar1718._0_9_ = auVar1708._0_9_;
            auVar1718[9] = bVar178;
            auVar1717._9_7_ = auVar1718._9_7_;
            auVar1717._0_8_ = auVar1708._0_8_;
            auVar1717[8] = pbVar953[0x43];
            auVar765._1_8_ = auVar1717._8_8_;
            auVar765[0] = bVar184;
            auVar765._9_7_ = 0;
            auVar764._10_6_ = 0;
            auVar764._0_10_ = SUB1610(auVar765 << 0x38,6);
            auVar763._11_5_ = 0;
            auVar763._0_11_ = SUB1611(auVar764 << 0x30,5);
            auVar762._12_4_ = 0;
            auVar762._0_12_ = SUB1612(auVar763 << 0x28,4);
            auVar761._13_3_ = 0;
            auVar761._0_13_ = SUB1613(auVar762 << 0x20,3);
            auVar1716._14_2_ = 0;
            auVar1716._0_14_ = SUB1614(auVar761 << 0x18,2);
            auVar1716 = auVar1716 << 0x10;
            uVar1594 = CONCAT13(0,CONCAT12(bVar178,(ushort)pbVar953[0x43]));
            auVar34[0xd] = 0;
            auVar34._0_13_ = auVar1716._0_13_;
            auVar34[0xe] = bVar184;
            auVar49[0xc] = pbVar953[0x33];
            auVar49._0_12_ = auVar1716._0_12_;
            auVar49._13_2_ = auVar34._13_2_;
            auVar65[0xb] = 0;
            auVar65._0_11_ = auVar1716._0_11_;
            auVar65._12_3_ = auVar49._12_3_;
            uVar118 = auVar65._11_4_;
            auVar119[10] = bVar181;
            auVar119._0_10_ = auVar1716._0_10_;
            auVar119._11_4_ = uVar118;
            auVar144[9] = 0;
            auVar144._0_9_ = auVar1716._0_9_;
            auVar144._10_5_ = auVar119._10_5_;
            auVar155[8] = pbVar953[0x23];
            auVar155._0_8_ = auVar1716._0_8_;
            auVar155._9_6_ = auVar144._9_6_;
            auVar766._7_8_ = 0;
            auVar766._0_7_ = auVar155._8_7_;
            Var360 = CONCAT81(SUB158(auVar766 << 0x40,7),bVar177);
            auVar870._9_6_ = 0;
            auVar870._0_9_ = Var360;
            auVar767._1_10_ = SUB1510(auVar870 << 0x30,5);
            auVar767[0] = bVar173;
            auVar871._11_4_ = 0;
            auVar871._0_11_ = auVar767;
            auVar768._1_12_ = SUB1512(auVar871 << 0x20,3);
            auVar768[0] = uVar1176;
            auVar171[1] = 0;
            auVar171[0] = auVar1181[0];
            auVar171._2_13_ = auVar768;
            auVar1181 = *(undefined1 (*) [16])(pbVar956 + 7);
            bVar173 = pbVar956[0x17];
            bVar175 = pbVar956[0x19];
            bVar177 = pbVar956[0x1b];
            bVar179 = pbVar956[0x1d];
            bVar180 = pbVar956[0x1f];
            bVar181 = pbVar956[0x21];
            bVar182 = pbVar956[0x23];
            auVar1731._0_14_ = auVar1181._0_14_;
            auVar1731[0xe] = auVar1181[7];
            auVar1731[0xf] = pbVar956[0x1e];
            auVar1730._14_2_ = auVar1731._14_2_;
            auVar1730._0_13_ = auVar1181._0_13_;
            auVar1730[0xd] = bVar179;
            auVar1729._13_3_ = auVar1730._13_3_;
            auVar1729._0_12_ = auVar1181._0_12_;
            auVar1729[0xc] = auVar1181[6];
            auVar1728._12_4_ = auVar1729._12_4_;
            auVar1728._0_11_ = auVar1181._0_11_;
            auVar1728[0xb] = pbVar956[0x1c];
            auVar1727._11_5_ = auVar1728._11_5_;
            auVar1727._0_10_ = auVar1181._0_10_;
            auVar1727[10] = auVar1181[5];
            auVar1726._10_6_ = auVar1727._10_6_;
            auVar1726._0_9_ = auVar1181._0_9_;
            auVar1726[9] = bVar177;
            uVar1820 = auVar1181[4];
            auVar1725._9_7_ = auVar1726._9_7_;
            auVar1725._0_8_ = auVar1181._0_8_;
            auVar1725[8] = uVar1820;
            auVar773._1_8_ = auVar1725._8_8_;
            auVar773[0] = pbVar956[0x1a];
            auVar773._9_7_ = 0;
            auVar772._10_6_ = 0;
            auVar772._0_10_ = SUB1610(auVar773 << 0x38,6);
            auVar771._11_5_ = 0;
            auVar771._0_11_ = SUB1611(auVar772 << 0x30,5);
            auVar770._12_4_ = 0;
            auVar770._0_12_ = SUB1612(auVar771 << 0x28,4);
            auVar769._13_3_ = 0;
            auVar769._0_13_ = SUB1613(auVar770 << 0x20,3);
            auVar1724._14_2_ = 0;
            auVar1724._0_14_ = SUB1614(auVar769 << 0x18,2);
            auVar1724 = auVar1724 << 0x10;
            uVar1176 = auVar1181[8];
            uVar1852 = auVar1181[10];
            auVar1739._0_14_ = auVar1724._0_14_;
            auVar1739[0xe] = pbVar956[0x1a];
            auVar1739[0xf] = pbVar956[0x22];
            auVar1738._14_2_ = auVar1739._14_2_;
            auVar1738._0_13_ = auVar1724._0_13_;
            auVar1738[0xd] = auVar1181[0xb];
            auVar1737._13_3_ = auVar1738._13_3_;
            auVar1737._0_12_ = auVar1724._0_12_;
            auVar1737[0xc] = auVar1181[3];
            auVar1736._12_4_ = auVar1737._12_4_;
            auVar1736._0_11_ = auVar1724._0_11_;
            auVar1736[0xb] = bVar181;
            auVar1735._11_5_ = auVar1736._11_5_;
            auVar1735._0_10_ = auVar1724._0_10_;
            auVar1735[10] = bVar175;
            auVar1734._10_6_ = auVar1735._10_6_;
            auVar1734._0_9_ = auVar1724._0_9_;
            auVar1734[9] = uVar1852;
            auVar1733._9_7_ = auVar1734._9_7_;
            auVar1733._0_8_ = auVar1724._0_8_;
            auVar1733[8] = auVar1181[2];
            auVar778._1_8_ = auVar1733._8_8_;
            auVar778[0] = pbVar956[0x20];
            auVar778._9_7_ = 0;
            auVar777._10_6_ = 0;
            auVar777._0_10_ = SUB1610(auVar778 << 0x38,6);
            auVar776._11_5_ = 0;
            auVar776._0_11_ = SUB1611(auVar777 << 0x30,5);
            auVar775._12_4_ = 0;
            auVar775._0_12_ = SUB1612(auVar776 << 0x28,4);
            auVar774._13_3_ = 0;
            auVar774._0_13_ = SUB1613(auVar775 << 0x20,3);
            auVar1732._14_2_ = 0;
            auVar1732._0_14_ = SUB1614(auVar774 << 0x18,2);
            auVar1732 = auVar1732 << 0x10;
            auVar1747._0_14_ = auVar1732._0_14_;
            auVar1747[0xe] = pbVar956[0x20];
            auVar1747[0xf] = pbVar956[0x24];
            auVar1746._14_2_ = auVar1747._14_2_;
            auVar1746._0_13_ = auVar1732._0_13_;
            auVar1746[0xd] = pbVar956[0x1c];
            auVar1745._13_3_ = auVar1746._13_3_;
            auVar1745._0_12_ = auVar1732._0_12_;
            auVar1745[0xc] = pbVar956[0x18];
            auVar1744._12_4_ = auVar1745._12_4_;
            auVar1744._0_11_ = auVar1732._0_11_;
            auVar1744[0xb] = auVar1181[0xd];
            auVar1743._11_5_ = auVar1744._11_5_;
            auVar1743._0_10_ = auVar1732._0_10_;
            auVar1743[10] = auVar1181[9];
            auVar1742._10_6_ = auVar1743._10_6_;
            auVar1742._0_9_ = auVar1732._0_9_;
            auVar1742[9] = auVar1181[5];
            auVar1741._9_7_ = auVar1742._9_7_;
            auVar1741._0_8_ = auVar1732._0_8_;
            auVar1741[8] = auVar1181[1];
            auVar783._1_8_ = auVar1741._8_8_;
            auVar783[0] = bVar182;
            auVar783._9_7_ = 0;
            auVar782._10_6_ = 0;
            auVar782._0_10_ = SUB1610(auVar783 << 0x38,6);
            auVar781._11_5_ = 0;
            auVar781._0_11_ = SUB1611(auVar782 << 0x30,5);
            auVar780._12_4_ = 0;
            auVar780._0_12_ = SUB1612(auVar781 << 0x28,4);
            auVar779._13_3_ = 0;
            auVar779._0_13_ = SUB1613(auVar780 << 0x20,3);
            auVar1740._14_2_ = 0;
            auVar1740._0_14_ = SUB1614(auVar779 << 0x18,2);
            auVar1740 = auVar1740 << 0x10;
            bVar183 = pbVar956[0x2b];
            bVar184 = pbVar956[0x2f];
            bVar187 = pbVar956[0x33];
            auVar1755._0_14_ = auVar1740._0_14_;
            auVar1755[0xe] = bVar182;
            auVar1755[0xf] = pbVar956[0x25];
            auVar1754._14_2_ = auVar1755._14_2_;
            auVar1754._0_13_ = auVar1740._0_13_;
            auVar1754[0xd] = bVar181;
            auVar1753._13_3_ = auVar1754._13_3_;
            auVar1753._0_12_ = auVar1740._0_12_;
            auVar1753[0xc] = bVar180;
            auVar1752._12_4_ = auVar1753._12_4_;
            auVar1752._0_11_ = auVar1740._0_11_;
            auVar1752[0xb] = bVar179;
            auVar1751._11_5_ = auVar1752._11_5_;
            auVar1751._0_10_ = auVar1740._0_10_;
            auVar1751[10] = bVar177;
            auVar1750._10_6_ = auVar1751._10_6_;
            auVar1750._0_9_ = auVar1740._0_9_;
            auVar1750[9] = bVar175;
            auVar1749._9_7_ = auVar1750._9_7_;
            auVar1749._0_8_ = auVar1740._0_8_;
            auVar1749[8] = bVar173;
            auVar788._1_8_ = auVar1749._8_8_;
            auVar788[0] = auVar1181[0xe];
            auVar788._9_7_ = 0;
            auVar787._10_6_ = 0;
            auVar787._0_10_ = SUB1610(auVar788 << 0x38,6);
            auVar786._11_5_ = 0;
            auVar786._0_11_ = SUB1611(auVar787 << 0x30,5);
            auVar785._12_4_ = 0;
            auVar785._0_12_ = SUB1612(auVar786 << 0x28,4);
            auVar784._13_3_ = 0;
            auVar784._0_13_ = SUB1613(auVar785 << 0x20,3);
            auVar1748._14_2_ = 0;
            auVar1748._0_14_ = SUB1614(auVar784 << 0x18,2);
            auVar1748 = auVar1748 << 0x10;
            bVar188 = pbVar956[0x3b];
            bVar199 = pbVar956[0x3f];
            auVar1763._0_14_ = auVar1748._0_14_;
            auVar1763[0xe] = auVar1181[0xe];
            auVar1763[0xf] = pbVar956[0x35];
            auVar1762._14_2_ = auVar1763._14_2_;
            auVar1762._0_13_ = auVar1748._0_13_;
            auVar1762[0xd] = bVar187;
            auVar1761._13_3_ = auVar1762._13_3_;
            auVar1761._0_12_ = auVar1748._0_12_;
            auVar1761[0xc] = auVar1181[0xc];
            auVar1760._12_4_ = auVar1761._12_4_;
            auVar1760._0_11_ = auVar1748._0_11_;
            auVar1760[0xb] = pbVar956[0x31];
            auVar1759._11_5_ = auVar1760._11_5_;
            auVar1759._0_10_ = auVar1748._0_10_;
            auVar1759[10] = uVar1852;
            auVar1758._10_6_ = auVar1759._10_6_;
            auVar1758._0_9_ = auVar1748._0_9_;
            auVar1758[9] = bVar184;
            auVar1757._9_7_ = auVar1758._9_7_;
            auVar1757._0_8_ = auVar1748._0_8_;
            auVar1757[8] = uVar1176;
            auVar793._1_8_ = auVar1757._8_8_;
            auVar793[0] = pbVar956[0x2d];
            auVar793._9_7_ = 0;
            auVar792._10_6_ = 0;
            auVar792._0_10_ = SUB1610(auVar793 << 0x38,6);
            auVar791._11_5_ = 0;
            auVar791._0_11_ = SUB1611(auVar792 << 0x30,5);
            auVar790._12_4_ = 0;
            auVar790._0_12_ = SUB1612(auVar791 << 0x28,4);
            auVar789._13_3_ = 0;
            auVar789._0_13_ = SUB1613(auVar790 << 0x20,3);
            auVar1756._14_2_ = 0;
            auVar1756._0_14_ = SUB1614(auVar789 << 0x18,2);
            auVar1756 = auVar1756 << 0x10;
            auVar1771._0_14_ = auVar1756._0_14_;
            auVar1771[0xe] = pbVar956[0x2d];
            auVar1771[0xf] = pbVar956[0x3d];
            auVar1770._14_2_ = auVar1771._14_2_;
            auVar1770._0_13_ = auVar1756._0_13_;
            auVar1770[0xd] = bVar179;
            auVar1769._13_3_ = auVar1770._13_3_;
            auVar1769._0_12_ = auVar1756._0_12_;
            auVar1769[0xc] = auVar1181[6];
            auVar1768._12_4_ = auVar1769._12_4_;
            auVar1768._0_11_ = auVar1756._0_11_;
            auVar1768[0xb] = bVar188;
            auVar1767._11_5_ = auVar1768._11_5_;
            auVar1767._0_10_ = auVar1756._0_10_;
            auVar1767[10] = bVar183;
            auVar1766._10_6_ = auVar1767._10_6_;
            auVar1766._0_9_ = auVar1756._0_9_;
            auVar1766[9] = bVar177;
            auVar1765._9_7_ = auVar1766._9_7_;
            auVar1765._0_8_ = auVar1756._0_8_;
            auVar1765[8] = uVar1820;
            auVar798._1_8_ = auVar1765._8_8_;
            auVar798[0] = pbVar956[0x39];
            auVar798._9_7_ = 0;
            auVar797._10_6_ = 0;
            auVar797._0_10_ = SUB1610(auVar798 << 0x38,6);
            auVar796._11_5_ = 0;
            auVar796._0_11_ = SUB1611(auVar797 << 0x30,5);
            auVar795._12_4_ = 0;
            auVar795._0_12_ = SUB1612(auVar796 << 0x28,4);
            auVar794._13_3_ = 0;
            auVar794._0_13_ = SUB1613(auVar795 << 0x20,3);
            auVar1764._14_2_ = 0;
            auVar1764._0_14_ = SUB1614(auVar794 << 0x18,2);
            auVar1764 = auVar1764 << 0x10;
            auVar1779._0_14_ = auVar1764._0_14_;
            auVar1779[0xe] = pbVar956[0x39];
            auVar1779[0xf] = pbVar956[0x41];
            auVar1778._14_2_ = auVar1779._14_2_;
            auVar1778._0_13_ = auVar1764._0_13_;
            auVar1778[0xd] = pbVar956[0x31];
            auVar1777._13_3_ = auVar1778._13_3_;
            auVar1777._0_12_ = auVar1764._0_12_;
            auVar1777[0xc] = pbVar956[0x29];
            auVar1776._12_4_ = auVar1777._12_4_;
            auVar1776._0_11_ = auVar1764._0_11_;
            auVar1776[0xb] = bVar181;
            auVar1775._11_5_ = auVar1776._11_5_;
            auVar1775._0_10_ = auVar1764._0_10_;
            auVar1775[10] = bVar175;
            auVar1774._10_6_ = auVar1775._10_6_;
            auVar1774._0_9_ = auVar1764._0_9_;
            auVar1774[9] = uVar1852;
            auVar1773._9_7_ = auVar1774._9_7_;
            auVar1773._0_8_ = auVar1764._0_8_;
            auVar1773[8] = auVar1181[2];
            auVar803._1_8_ = auVar1773._8_8_;
            auVar803[0] = bVar199;
            auVar803._9_7_ = 0;
            auVar802._10_6_ = 0;
            auVar802._0_10_ = SUB1610(auVar803 << 0x38,6);
            auVar801._11_5_ = 0;
            auVar801._0_11_ = SUB1611(auVar802 << 0x30,5);
            auVar800._12_4_ = 0;
            auVar800._0_12_ = SUB1612(auVar801 << 0x28,4);
            auVar799._13_3_ = 0;
            auVar799._0_13_ = SUB1613(auVar800 << 0x20,3);
            auVar1772._14_2_ = 0;
            auVar1772._0_14_ = SUB1614(auVar799 << 0x18,2);
            auVar1772 = auVar1772 << 0x10;
            bVar175 = pbVar956[0x57];
            bVar179 = pbVar956[0x5f];
            auVar1787._0_14_ = auVar1772._0_14_;
            auVar1787[0xe] = bVar199;
            auVar1787[0xf] = pbVar956[0x43];
            auVar1786._14_2_ = auVar1787._14_2_;
            auVar1786._0_13_ = auVar1772._0_13_;
            auVar1786[0xd] = bVar188;
            auVar1785._13_3_ = auVar1786._13_3_;
            auVar1785._0_12_ = auVar1772._0_12_;
            auVar1785[0xc] = pbVar956[0x37];
            auVar1784._12_4_ = auVar1785._12_4_;
            auVar1784._0_11_ = auVar1772._0_11_;
            auVar1784[0xb] = bVar187;
            auVar1783._11_5_ = auVar1784._11_5_;
            auVar1783._0_10_ = auVar1772._0_10_;
            auVar1783[10] = bVar184;
            auVar1782._10_6_ = auVar1783._10_6_;
            auVar1782._0_9_ = auVar1772._0_9_;
            auVar1782[9] = bVar183;
            auVar1781._9_7_ = auVar1782._9_7_;
            auVar1781._0_8_ = auVar1772._0_8_;
            auVar1781[8] = pbVar956[0x27];
            auVar808._1_8_ = auVar1781._8_8_;
            auVar808[0] = bVar182;
            auVar808._9_7_ = 0;
            auVar807._10_6_ = 0;
            auVar807._0_10_ = SUB1610(auVar808 << 0x38,6);
            auVar806._11_5_ = 0;
            auVar806._0_11_ = SUB1611(auVar807 << 0x30,5);
            auVar805._12_4_ = 0;
            auVar805._0_12_ = SUB1612(auVar806 << 0x28,4);
            auVar804._13_3_ = 0;
            auVar804._0_13_ = SUB1613(auVar805 << 0x20,3);
            auVar1780._14_2_ = 0;
            auVar1780._0_14_ = SUB1614(auVar804 << 0x18,2);
            auVar1780 = auVar1780 << 0x10;
            bVar181 = pbVar956[0x4f];
            bVar202 = pbVar956[0x67];
            bVar203 = pbVar956[0x6f];
            auVar836 = *(undefined1 (*) [12])(pbVar956 + 0x77);
            local_9c = auVar836[0];
            uStack_98 = auVar836[4];
            uStack_94._0_1_ = auVar836[8];
            auVar1795._0_14_ = auVar1780._0_14_;
            auVar1795[0xe] = bVar182;
            auVar1795[0xf] = pbVar956[99];
            auVar1794._14_2_ = auVar1795._14_2_;
            auVar1794._0_13_ = auVar1780._0_13_;
            auVar1794[0xd] = bVar179;
            auVar1793._13_3_ = auVar1794._13_3_;
            auVar1793._0_12_ = auVar1780._0_12_;
            auVar1793[0xc] = bVar180;
            auVar1792._12_4_ = auVar1793._12_4_;
            auVar1792._0_11_ = auVar1780._0_11_;
            auVar1792[0xb] = pbVar956[0x5b];
            auVar1791._11_5_ = auVar1792._11_5_;
            auVar1791._0_10_ = auVar1780._0_10_;
            auVar1791[10] = bVar177;
            auVar1790._10_6_ = auVar1791._10_6_;
            auVar1790._0_9_ = auVar1780._0_9_;
            auVar1790[9] = bVar175;
            auVar1789._9_7_ = auVar1790._9_7_;
            auVar1789._0_8_ = auVar1780._0_8_;
            auVar1789[8] = bVar173;
            auVar813._1_8_ = auVar1789._8_8_;
            auVar813[0] = pbVar956[0x53];
            auVar813._9_7_ = 0;
            auVar812._10_6_ = 0;
            auVar812._0_10_ = SUB1610(auVar813 << 0x38,6);
            auVar811._11_5_ = 0;
            auVar811._0_11_ = SUB1611(auVar812 << 0x30,5);
            auVar810._12_4_ = 0;
            auVar810._0_12_ = SUB1612(auVar811 << 0x28,4);
            auVar809._13_3_ = 0;
            auVar809._0_13_ = SUB1613(auVar810 << 0x20,3);
            auVar1788._14_2_ = 0;
            auVar1788._0_14_ = SUB1614(auVar809 << 0x18,2);
            auVar1788 = auVar1788 << 0x10;
            auVar1803._0_14_ = auVar1788._0_14_;
            auVar1803[0xe] = pbVar956[0x53];
            auVar1803[0xf] = pbVar956[0x73];
            auVar1802._14_2_ = auVar1803._14_2_;
            auVar1802._0_13_ = auVar1788._0_13_;
            auVar1802[0xd] = bVar187;
            auVar1801._13_3_ = auVar1802._13_3_;
            auVar1801._0_12_ = auVar1788._0_12_;
            auVar1801[0xc] = auVar1181[0xc];
            auVar1800._12_4_ = auVar1801._12_4_;
            auVar1800._0_11_ = auVar1788._0_11_;
            auVar1800[0xb] = bVar203;
            auVar1799._11_5_ = auVar1800._11_5_;
            auVar1799._0_10_ = auVar1788._0_10_;
            auVar1799[10] = bVar181;
            auVar1798._10_6_ = auVar1799._10_6_;
            auVar1798._0_9_ = auVar1788._0_9_;
            auVar1798[9] = bVar184;
            auVar1797._9_7_ = auVar1798._9_7_;
            auVar1797._0_8_ = auVar1788._0_8_;
            auVar1797[8] = uVar1176;
            auVar818._1_8_ = auVar1797._8_8_;
            auVar818[0] = pbVar956[0x6b];
            auVar818._9_7_ = 0;
            auVar817._10_6_ = 0;
            auVar817._0_10_ = SUB1610(auVar818 << 0x38,6);
            auVar816._11_5_ = 0;
            auVar816._0_11_ = SUB1611(auVar817 << 0x30,5);
            auVar815._12_4_ = 0;
            auVar815._0_12_ = SUB1612(auVar816 << 0x28,4);
            auVar814._13_3_ = 0;
            auVar814._0_13_ = SUB1613(auVar815 << 0x20,3);
            auVar1796._14_2_ = 0;
            auVar1796._0_14_ = SUB1614(auVar814 << 0x18,2);
            auVar1796 = auVar1796 << 0x10;
            auVar1811._0_14_ = auVar1796._0_14_;
            auVar1811[0xe] = pbVar956[0x6b];
            auVar1811[0xf] = uStack_98;
            auVar1810._14_2_ = auVar1811._14_2_;
            auVar1810._0_13_ = auVar1796._0_13_;
            auVar1810[0xd] = pbVar956[0x5b];
            auVar1809._13_3_ = auVar1810._13_3_;
            auVar1809._0_12_ = auVar1796._0_12_;
            auVar1809[0xc] = pbVar956[0x4b];
            auVar1808._12_4_ = auVar1809._12_4_;
            auVar1808._0_11_ = auVar1796._0_11_;
            auVar1808[0xb] = bVar188;
            auVar1807._11_5_ = auVar1808._11_5_;
            auVar1807._0_10_ = auVar1796._0_10_;
            auVar1807[10] = bVar183;
            auVar1806._10_6_ = auVar1807._10_6_;
            auVar1806._0_9_ = auVar1796._0_9_;
            auVar1806[9] = bVar177;
            auVar1805._9_7_ = auVar1806._9_7_;
            auVar1805._0_8_ = auVar1796._0_8_;
            auVar1805[8] = uVar1820;
            auVar823._1_8_ = auVar1805._8_8_;
            auVar823[0] = local_9c;
            auVar823._9_7_ = 0;
            auVar822._10_6_ = 0;
            auVar822._0_10_ = SUB1610(auVar823 << 0x38,6);
            auVar821._11_5_ = 0;
            auVar821._0_11_ = SUB1611(auVar822 << 0x30,5);
            auVar820._12_4_ = 0;
            auVar820._0_12_ = SUB1612(auVar821 << 0x28,4);
            auVar819._13_3_ = 0;
            auVar819._0_13_ = SUB1613(auVar820 << 0x20,3);
            auVar1804._14_2_ = 0;
            auVar1804._0_14_ = SUB1614(auVar819 << 0x18,2);
            auVar1804 = auVar1804 << 0x10;
            auVar1819._0_14_ = auVar1804._0_14_;
            auVar1819[0xe] = local_9c;
            auVar1819[0xf] = (byte)uStack_94;
            auVar1818._14_2_ = auVar1819._14_2_;
            auVar1818._0_13_ = auVar1804._0_13_;
            auVar1818[0xd] = bVar203;
            auVar1817._13_3_ = auVar1818._13_3_;
            auVar1817._0_12_ = auVar1804._0_12_;
            auVar1817[0xc] = bVar202;
            auVar1816._12_4_ = auVar1817._12_4_;
            auVar1816._0_11_ = auVar1804._0_11_;
            auVar1816[0xb] = bVar179;
            auVar1815._11_5_ = auVar1816._11_5_;
            auVar1815._0_10_ = auVar1804._0_10_;
            auVar1815[10] = bVar175;
            auVar1814._10_6_ = auVar1815._10_6_;
            auVar1814._0_9_ = auVar1804._0_9_;
            auVar1814[9] = bVar181;
            auVar1813._9_7_ = auVar1814._9_7_;
            auVar1813._0_8_ = auVar1804._0_8_;
            auVar1813[8] = pbVar956[0x47];
            auVar828._1_8_ = auVar1813._8_8_;
            auVar828[0] = bVar199;
            auVar828._9_7_ = 0;
            auVar827._10_6_ = 0;
            auVar827._0_10_ = SUB1610(auVar828 << 0x38,6);
            auVar826._11_5_ = 0;
            auVar826._0_11_ = SUB1611(auVar827 << 0x30,5);
            auVar825._12_4_ = 0;
            auVar825._0_12_ = SUB1612(auVar826 << 0x28,4);
            auVar824._13_3_ = 0;
            auVar824._0_13_ = SUB1613(auVar825 << 0x20,3);
            auVar1812._14_2_ = 0;
            auVar1812._0_14_ = SUB1614(auVar824 << 0x18,2);
            auVar1812 = auVar1812 << 0x10;
            auVar35._10_2_ = 0;
            auVar35._0_10_ = auVar170._0_10_;
            auVar35._12_2_ = (short)Var296;
            uVar919 = CONCAT42(auVar35._10_4_,auVar705._0_2_);
            auVar829._6_8_ = 0;
            auVar829._0_6_ = uVar919;
            auVar120._4_2_ = auVar918._0_2_;
            auVar120._0_4_ = auVar170._0_4_;
            auVar120._6_8_ = SUB148(auVar829 << 0x40,6);
            uVar1595 = CONCAT13(0,CONCAT12(bVar181,(ushort)pbVar956[0x47]));
            auVar36._10_2_ = 0;
            auVar36._0_10_ = auVar169._0_10_;
            auVar36._12_2_ = (short)Var293;
            uVar920 = CONCAT42(auVar36._10_4_,auVar703._0_2_);
            auVar830._6_8_ = 0;
            auVar830._0_6_ = uVar920;
            auVar121._4_2_ = auVar917._0_2_;
            auVar121._0_4_ = auVar169._0_4_;
            auVar121._6_8_ = SUB148(auVar830 << 0x40,6);
            auVar37._10_2_ = 0;
            auVar37._0_10_ = auVar171._0_10_;
            auVar37._12_2_ = (short)Var360;
            uVar921 = CONCAT42(auVar37._10_4_,auVar767._0_2_);
            auVar831._6_8_ = 0;
            auVar831._0_6_ = uVar921;
            auVar122._4_2_ = auVar768._0_2_;
            auVar122._0_4_ = auVar171._0_4_;
            auVar122._6_8_ = SUB148(auVar831 << 0x40,6);
            auVar38[0xd] = 0;
            auVar38._0_13_ = auVar1812._0_13_;
            auVar38[0xe] = bVar199;
            auVar50[0xc] = pbVar956[0x37];
            auVar50._0_12_ = auVar1812._0_12_;
            auVar50._13_2_ = auVar38._13_2_;
            auVar66[0xb] = 0;
            auVar66._0_11_ = auVar1812._0_11_;
            auVar66._12_3_ = auVar50._12_3_;
            uVar123 = auVar66._11_4_;
            auVar124[10] = bVar184;
            auVar124._0_10_ = auVar1812._0_10_;
            auVar124._11_4_ = uVar123;
            auVar145[9] = 0;
            auVar145._0_9_ = auVar1812._0_9_;
            auVar145._10_5_ = auVar124._10_5_;
            auVar156[8] = pbVar956[0x27];
            auVar156._0_8_ = auVar1812._0_8_;
            auVar156._9_6_ = auVar145._9_6_;
            auVar832._7_8_ = 0;
            auVar832._0_7_ = auVar156._8_7_;
            Var293 = CONCAT81(SUB158(auVar832 << 0x40,7),bVar180);
            auVar872._9_6_ = 0;
            auVar872._0_9_ = Var293;
            auVar833._1_10_ = SUB1510(auVar872 << 0x30,5);
            auVar833[0] = bVar173;
            auVar873._11_4_ = 0;
            auVar873._0_11_ = auVar833;
            auVar834._1_12_ = SUB1512(auVar873 << 0x20,3);
            auVar834[0] = uVar1176;
            auVar172[1] = 0;
            auVar172[0] = auVar1181[0];
            auVar172._2_13_ = auVar834;
            uStack_d4 = (ushort)((ulonglong)uVar928 >> 8);
            uStack_d2 = (ushort)((ulonglong)uVar934 >> 0x18);
            auVar39._10_2_ = 0;
            auVar39._0_10_ = auVar172._0_10_;
            auVar39._12_2_ = (short)Var293;
            uVar922 = CONCAT42(auVar39._10_4_,auVar833._0_2_);
            auVar835._6_8_ = 0;
            auVar835._0_6_ = uVar922;
            auVar125._4_2_ = auVar834._0_2_;
            auVar125._0_4_ = auVar172._0_4_;
            auVar125._6_8_ = SUB148(auVar835 << 0x40,6);
            uStack_e4 = (ushort)((ulonglong)uVar927 >> 8);
            uStack_e2 = (ushort)((ulonglong)uVar933 >> 0x18);
            uStack_114 = auVar155._8_2_;
            uStack_112 = auVar119._10_2_;
            auVar894[0xc] = uVar942;
            auVar894._0_12_ = ZEXT112(bStack_e9) << 0x40;
            auVar895._10_3_ = auVar894._10_3_;
            auVar895._0_10_ = (unkuint10)bStack_d9 << 0x40;
            auVar126[4] = uStack_f1;
            auVar126._0_4_ = uVar1856;
            auVar126[5] = 0;
            auVar126._6_8_ = SUB148(ZEXT514(auVar895._8_5_) << 0x40,6);
            auVar896[0xc] = uStack_cd;
            auVar896._0_12_ = ZEXT112(bStack_e5) << 0x40;
            auVar897._10_3_ = auVar896._10_3_;
            auVar897._0_10_ = (unkuint10)bStack_d5 << 0x40;
            auVar127[4] = uStack_ed;
            auVar127._0_4_ = uVar1593;
            auVar127[5] = 0;
            auVar127._6_8_ = SUB148(ZEXT514(auVar897._8_5_) << 0x40,6);
            auVar898[0xc] = bVar176;
            auVar898._0_12_ = ZEXT112(bVar185) << 0x40;
            auVar899._10_3_ = auVar898._10_3_;
            auVar899._0_10_ = (unkuint10)bVar174 << 0x40;
            auVar128[4] = bVar178;
            auVar128._0_4_ = uVar1594;
            auVar128[5] = 0;
            auVar128._6_8_ = SUB148(ZEXT514(auVar899._8_5_) << 0x40,6);
            auVar900[0xc] = bVar179;
            auVar900._0_12_ = ZEXT112(bVar202) << 0x40;
            auVar901._10_3_ = auVar900._10_3_;
            auVar901._0_10_ = (unkuint10)bVar175 << 0x40;
            auVar129[4] = bVar181;
            auVar129._0_4_ = uVar1595;
            auVar129[5] = 0;
            auVar129._6_8_ = SUB148(ZEXT514(auVar901._8_5_) << 0x40,6);
            pbVar1 = pbVar950 + iVar948;
            *pbVar1 = (byte)((int)((auVar158._0_4_ & 0xffff) + (auVar157._0_4_ & 0xffff) +
                                   (auVar159._0_4_ & 0xffff) + (auVar160._0_4_ & 0xffff)) >> 2);
            pbVar1[1] = (byte)((int)((auVar162._0_4_ & 0xffff) + (auVar161._0_4_ & 0xffff) +
                                     (auVar163._0_4_ & 0xffff) + (auVar164._0_4_ & 0xffff)) >> 2);
            pbVar1[2] = (byte)((int)((auVar165._0_4_ & 0xffff) + (auVar166._0_4_ & 0xffff) +
                                     (auVar167._0_4_ & 0xffff) + (auVar168._0_4_ & 0xffff)) >> 2);
            pbVar1[3] = (byte)((int)((auVar170._0_4_ & 0xffff) + (auVar169._0_4_ & 0xffff) +
                                     (auVar171._0_4_ & 0xffff) + (auVar172._0_4_ & 0xffff)) >> 2);
            pbVar1[4] = (byte)(auVar72._4_4_ + auVar73._4_4_ + auVar74._4_4_ + auVar77._4_4_ >> 2);
            pbVar1[5] = (byte)(auVar88._4_4_ + auVar87._4_4_ + auVar89._4_4_ + auVar92._4_4_ >> 2);
            pbVar1[6] = (byte)(auVar105._4_4_ + auVar104._4_4_ + auVar106._4_4_ + auVar109._4_4_ >>
                              2);
            pbVar1[7] = (byte)(auVar120._4_4_ + auVar121._4_4_ + auVar122._4_4_ + auVar125._4_4_ >>
                              2);
            pbVar1[8] = (byte)((int)uVar903 + (int)uVar904 + (int)uVar905 + (int)uVar906 >> 2);
            pbVar1[9] = (byte)((int)uVar909 + (int)uVar908 + (int)uVar910 + (int)uVar911 >> 2);
            pbVar1[10] = (byte)((int)uVar914 + (int)uVar913 + (int)uVar915 + (int)uVar916 >> 2);
            pbVar1[0xb] = (byte)((int)uVar919 + (int)uVar920 + (int)uVar921 + (int)uVar922 >> 2);
            pbVar1[0xc] = (byte)((int)((auVar11._10_4_ >> 0x10) + (auVar12._10_4_ >> 0x10) +
                                       (auVar13._10_4_ >> 0x10) + (auVar15._10_4_ >> 0x10)) >> 2);
            pbVar1[0xd] = (byte)((int)((auVar20._10_4_ >> 0x10) + (auVar19._10_4_ >> 0x10) +
                                       (auVar21._10_4_ >> 0x10) + (auVar23._10_4_ >> 0x10)) >> 2);
            pbVar1[0xe] = (byte)((int)((auVar28._10_4_ >> 0x10) + (auVar27._10_4_ >> 0x10) +
                                       (auVar29._10_4_ >> 0x10) + (auVar31._10_4_ >> 0x10)) >> 2);
            pbVar1[0xf] = (byte)((int)((auVar35._10_4_ >> 0x10) + (auVar36._10_4_ >> 0x10) +
                                       (auVar37._10_4_ >> 0x10) + (auVar39._10_4_ >> 0x10)) >> 2);
            local_48 = local_48 + 1;
            pbVar1 = pbVar950 + iVar948 + 0x10;
            *pbVar1 = (byte)((int)(uVar1179 + uVar1858 + uVar1859 + (uint)auVar148._8_2_) >> 2);
            pbVar1[1] = (byte)((int)(uVar1854 + uVar1860 + uVar1861 + (uint)auVar151._8_2_) >> 2);
            pbVar1[2] = (byte)((int)(uVar1855 + uVar1863 + (uint)uStack_a4 + (uint)auVar154._8_2_)
                              >> 2);
            pbVar1[3] = (byte)((int)((uint)uStack_e4 + (uint)uStack_d4 + (uint)uStack_114 +
                                    (uint)auVar156._8_2_) >> 2);
            pbVar1[4] = (byte)((int)(uVar1590 + uVar1864 + uVar1865 + (uint)auVar76._10_2_) >> 2);
            pbVar1[5] = (byte)((int)(uVar1857 + uVar1866 + (uint)uStack_92 + (uint)auVar91._10_2_)
                              >> 2);
            pbVar1[6] = (byte)((int)(uStack_b2 + uVar1867 + (uint)uStack_a2 + (uint)auVar108._10_2_)
                              >> 2);
            pbVar1[7] = (byte)((int)((uint)uStack_e2 + (uint)uStack_d2 + (uint)uStack_112 +
                                    (uint)auVar124._10_2_) >> 2);
            pbVar1[8] = (byte)((int)((uVar67 >> 8 & 0xffff) + (uVar68 >> 8 & 0xffff) +
                                     (uVar70 >> 8 & 0xffff) + (uVar75 >> 8 & 0xffff)) >> 2);
            pbVar1[9] = (byte)((int)((uVar84 >> 8 & 0xffff) + (uVar82 >> 8 & 0xffff) +
                                     (uVar85 >> 8 & 0xffff) + (uVar90 >> 8 & 0xffff)) >> 2);
            pbVar1[10] = (byte)((int)((uVar99 >> 8 & 0xffff) + (uVar100 >> 8 & 0xffff) +
                                      (uVar102 >> 8 & 0xffff) + (uVar107 >> 8 & 0xffff)) >> 2);
            pbVar1[0xb] = (byte)((int)((uVar116 >> 8 & 0xffff) + (uVar117 >> 8 & 0xffff) +
                                       (uVar118 >> 8 & 0xffff) + (uVar123 >> 8 & 0xffff)) >> 2);
            pbVar1[0xc] = (byte)((int)((uVar67 >> 0x18) + (uVar68 >> 0x18) + (uVar70 >> 0x18) +
                                      (uVar75 >> 0x18)) >> 2);
            pbVar1[0xd] = (byte)((int)((uVar84 >> 0x18) + (uVar82 >> 0x18) + (uVar85 >> 0x18) +
                                      (uVar90 >> 0x18)) >> 2);
            pbVar1[0xe] = (byte)((int)((uVar99 >> 0x18) + (uVar100 >> 0x18) + (uVar102 >> 0x18) +
                                      (uVar107 >> 0x18)) >> 2);
            pbVar1[0xf] = (byte)((int)((uVar116 >> 0x18) + (uVar117 >> 0x18) + (uVar118 >> 0x18) +
                                      (uVar123 >> 0x18)) >> 2);
            pbVar1 = pbVar950 + iVar948 + 0x20;
            *pbVar1 = (byte)((int)((uVar1822 & 0xffff) + (uVar1823 & 0xffff) + (uVar1177 & 0xffff) +
                                  (uVar1178 & 0xffff)) >> 2);
            pbVar1[1] = (byte)((int)((uVar1591 & 0xffff) + (uVar1824 & 0xffff) + (uVar1180 & 0xffff)
                                    + (uVar1825 & 0xffff)) >> 2);
            pbVar1[2] = (byte)((int)((uVar1862 & 0xffff) + (uVar957 & 0xffff) + (uVar958 & 0xffff) +
                                    (uVar1592 & 0xffff)) >> 2);
            pbVar1[3] = (byte)((int)((uVar1856 & 0xffff) + (uVar1593 & 0xffff) + (uVar1594 & 0xffff)
                                    + (uVar1595 & 0xffff)) >> 2);
            pbVar1[4] = (byte)(auVar78._4_4_ + auVar79._4_4_ + auVar80._4_4_ + auVar81._4_4_ >> 2);
            pbVar1[5] = (byte)(auVar94._4_4_ + auVar93._4_4_ + auVar95._4_4_ + auVar98._4_4_ >> 2);
            pbVar1[6] = (byte)(auVar110._4_4_ + auVar111._4_4_ + auVar112._4_4_ + auVar115._4_4_ >>
                              2);
            pbVar1[7] = (byte)(auVar126._4_4_ + auVar127._4_4_ + auVar128._4_4_ + auVar129._4_4_ >>
                              2);
            pbVar1[8] = (byte)(auVar875._8_4_ + auVar877._8_4_ + auVar879._8_4_ + auVar881._8_4_ >>
                              2);
            pbVar1[9] = (byte)(auVar885._8_4_ + auVar883._8_4_ + auVar887._8_4_ + auVar97._8_4_ >> 2
                              );
            pbVar1[10] = (byte)(auVar889._8_4_ + auVar891._8_4_ + auVar893._8_4_ + auVar114._8_4_ >>
                               2);
            pbVar1[0xb] = (byte)(auVar895._8_4_ + auVar897._8_4_ + auVar899._8_4_ + auVar901._8_4_
                                >> 2);
            pbVar1[0xc] = (byte)((int)((uint)(uint3)(auVar874._10_3_ >> 0x10) +
                                       (uint)(uint3)(auVar876._10_3_ >> 0x10) +
                                       (uint)(uint3)(auVar878._10_3_ >> 0x10) +
                                      (uint)(uint3)(auVar880._10_3_ >> 0x10)) >> 2);
            pbVar1[0xd] = (byte)((int)((uint)(uint3)(auVar884._10_3_ >> 0x10) +
                                       (uint)(uint3)(auVar882._10_3_ >> 0x10) +
                                       (uint)(uint3)(auVar886._10_3_ >> 0x10) +
                                      (uint)(uint3)(auVar96._10_3_ >> 0x10)) >> 2);
            pbVar1[0xe] = (byte)((int)((uint)(uint3)(auVar888._10_3_ >> 0x10) +
                                       (uint)(uint3)(auVar890._10_3_ >> 0x10) +
                                       (uint)(uint3)(auVar892._10_3_ >> 0x10) +
                                      (uint)(uint3)(auVar113._10_3_ >> 0x10)) >> 2);
            pbVar1[0xf] = (byte)((int)((uint)(uint3)(auVar894._10_3_ >> 0x10) +
                                       (uint)(uint3)(auVar896._10_3_ >> 0x10) +
                                       (uint)(uint3)(auVar898._10_3_ >> 0x10) +
                                      (uint)(uint3)(auVar900._10_3_ >> 0x10)) >> 2);
            pbVar1 = pbVar950 + iVar948 + 0x30;
            *pbVar1 = (byte)((int)((uint)local_ec + (uint)bStack_e8 + (uint)bVar195 + (uint)bVar200)
                            >> 2);
            pbVar1[1] = (byte)((int)((uint)bStack_eb + (uint)bStack_e7 + (uint)bVar189 +
                                    (auVar1586._12_4_ & 0xff)) >> 2);
            pbVar1[2] = (byte)((int)((uint)bStack_e6 + (uint)bStack_ea + (uint)bVar193 +
                                    (auVar1172._12_4_ & 0xff)) >> 2);
            pbVar1[3] = (byte)((int)((uint)bStack_e5 + (uint)bStack_e9 + (uint)bVar185 +
                                    (uint)bVar202) >> 2);
            pbVar1[4] = (byte)((int)(uVar1851 + (uVar208 & 0xff) + (uint)bVar196 + (uint)bVar201) >>
                              2);
            pbVar1[5] = (byte)((int)(uVar1821 + bStack_df + (uint)bVar190 +
                                    (auVar1586._12_4_ >> 8 & 0xff)) >> 2);
            pbVar1[6] = (byte)((int)((uint)bStack_de + (uint)bVar940 + (uint)bVar194 +
                                    (auVar1172._12_4_ >> 8 & 0xff)) >> 2);
            pbVar1[7] = (byte)((int)((uVar208 >> 0x18) + (uint)bVar941 + (uint)bVar186 +
                                    (uint)bVar203) >> 2);
            pbVar1[8] = (byte)((int)((uint)local_cc + (uint)bStack_c8 + (uint)local_8c +
                                    (uVar210 & 0xff)) >> 2);
            pbVar1[9] = (byte)((int)((uint)bStack_cb + (uint)bStack_c7 + (uint)bVar191 +
                                    (auVar1586._12_4_ >> 0x10 & 0xff)) >> 2);
            pbVar1[10] = (byte)((int)((uint)bStack_c6 + (uint)bStack_ca + (uint)bVar197 +
                                     (auVar1172._12_4_ >> 0x10 & 0xff)) >> 2);
            pbVar1[0xb] = (byte)((int)((uint)bStack_c5 + (uint)bStack_c9 + (uint)local_bc +
                                      (uint)local_9c) >> 2);
            pbVar1[0xc] = (byte)((int)((uint)bStack_c4 + (uVar209 & 0xff) + (uint)bStack_84 +
                                      (uVar211 & 0xff)) >> 2);
            pbVar1[0xd] = (byte)((int)((uint)bStack_c3 + (uVar209 >> 8 & 0xff) + (uint)bVar192 +
                                      (auVar1586._12_4_ >> 0x18)) >> 2);
            pbVar1[0xe] = (byte)((int)((uVar209 >> 0x10 & 0xff) + (uint)bStack_c2 + (uint)bVar198 +
                                      (auVar1172._12_4_ >> 0x18)) >> 2);
            pbVar1[0xf] = (byte)((int)((uVar209 >> 0x18) + (uint)bStack_c1 + (uint)(byte)uStack_b4 +
                                      (uint)(byte)uStack_94) >> 2);
            iVar948 = iVar948 + 0x40;
            pbVar951 = pbVar951 + 0x80;
            local_78 = local_78 + 0x80;
            pbVar949 = pbVar949 + 0x80;
            local_7c = local_7c + 0x80;
            pbVar955 = pbVar955 + 0x80;
            pbVar953 = pbVar953 + 0x80;
            pbVar956 = pbVar956 + 0x80;
          } while (local_48 < uVar947);
          iVar948 = uVar947 * 0x80;
          in = in + iVar948;
          pbVar950 = pbVar950 + uVar947 * 0x40;
          if (uVar944 == uVar947 * 0x10) goto LAB_001b525c;
          pbVar954 = in + iVar943;
        }
        do {
          iVar948 = iVar948 + 8;
          *pbVar950 = (byte)((int)((uint)pbVar954[4] + (uint)*in + (uint)in[4] + (uint)*pbVar954) >>
                            2);
          pbVar950[1] = (byte)((int)((uint)pbVar954[5] +
                                    (uint)in[1] + (uint)in[5] + (uint)pbVar954[1]) >> 2);
          pbVar950[2] = (byte)((int)((uint)pbVar954[6] +
                                    (uint)in[2] + (uint)in[6] + (uint)pbVar954[2]) >> 2);
          pbVar949 = in + 7;
          pbVar951 = in + 3;
          in = in + 8;
          pbVar953 = pbVar954 + 3;
          pbVar955 = pbVar954 + 7;
          pbVar954 = pbVar954 + 8;
          pbVar950[3] = (byte)((int)((uint)*pbVar955 +
                                    (uint)*pbVar951 + (uint)*pbVar949 + (uint)*pbVar953) >> 2);
          pbVar950 = pbVar950 + 4;
        } while (iVar948 < iVar943);
      }
LAB_001b525c:
      local_2c = local_2c + 1;
      in = pbVar946 + iVar943;
      pbVar950 = pbVar952;
    } while (local_2c != height >> 1);
  }
  return;
}


// GL_PaletteAdd  @ 001b8410
short GL_PaletteAdd(uchar *pPal,qboolean isSky)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte local_31c [780];
  
  if (qglColorTableEXT == (_func_void_int_int_int_int_int_void_ptr *)0x0) {
    return -1;
  }
  iVar6 = 0;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int tag@[???]
                       Unresolved local var: int limit@[???]
                       Unresolved local var: uchar[768] gammaPal@[???] */
    local_31c[iVar6] = texgammatable[pPal[iVar6]];
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x300);
                    /* Unresolved local var: int tag@[???]
                       Unresolved local var: int i@[???] */
  uVar7 = (uint)local_31c[0];
  iVar6 = 1;
  do {
    pbVar4 = local_31c + iVar6;
    uVar3 = (uint)local_31c[0];
    local_31c[0] = local_31c[iVar6 + 1];
    iVar6 = iVar6 + 2;
    uVar7 = (uVar7 + *pbVar4 ^ uVar3) + (uint)local_31c[0] ^ (uint)*pbVar4;
  } while (iVar6 != 0x2ff);
  pbVar4 = local_31c + 0x2ff;
  iVar6 = 1;
  do {
    bVar2 = *pbVar4;
    pbVar1 = pbVar4 + -1;
    pbVar4 = pbVar4 + 1;
    uVar7 = uVar7 + bVar2 ^ (uint)*pbVar1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar8 = (uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f);
  uVar3 = ~-(uint)(isSky == false) & 0x158;
  iVar6 = gGLPalette[uVar3].tag;
  iVar5 = uVar3 * 0x308;
  uVar7 = uVar3;
  if (-1 < iVar6) {
    do {
                    /* Unresolved local var: int i@[???] */
      if (iVar6 == iVar8) {
        iVar6 = 0;
        while (local_31c[iVar6] == *(byte *)(iVar5 + 0xe0c1a8 + iVar6)) {
          iVar6 = iVar6 + 1;
          if (iVar6 == 0x300) {
            gGLPalette[uVar7].referenceCount = gGLPalette[uVar7].referenceCount + 1;
            return (short)uVar7;
          }
        }
      }
      uVar7 = uVar7 + 1;
      if ((int)((-(uint)(isSky == false) & 0xfffffffa) + 0x15e) <= (int)uVar7) {
        return -1;
      }
      iVar6 = *(int *)(gGLPalette[1].colors + iVar5 + -8);
      iVar5 = iVar5 + 0x308;
    } while (-1 < iVar6);
    uVar3 = (uint)(short)uVar7;
  }
  Q_memcpy(gGLPalette[uVar7].colors,local_31c,0x300);
  gGLPalette[uVar7].referenceCount = 1;
  gGLPalette[uVar7].tag = iVar8;
  return (short)uVar3;
}


// GL_PaletteClear  @ 001b82c0
void GL_PaletteClear(int index)

{
  if ((uint)index < 0x15e) {
    gGLPalette[index].tag = -1;
    gGLPalette[index].referenceCount = 0;
  }
  return;
}


// GL_PaletteClearSky  @ 001b83a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_PaletteClearSky(void)

{
                    /* Unresolved local var: int i@[???] */
  gGLPalette[0x158].tag = -1;
  gGLPalette[0x158].referenceCount = 0;
  gGLPalette[0x159].tag = -1;
  gGLPalette[0x159].referenceCount = 0;
  gGLPalette[0x15a].tag = -1;
  gGLPalette[0x15a].referenceCount = 0;
  gGLPalette[0x15c].tag = -1;
  gGLPalette[0x15c].referenceCount = 0;
  gGLPalette[0x15d].tag = -1;
  gGLPalette[0x15b].tag = -1;
  gGLPalette[0x15b].referenceCount = 0;
  gGLPalette[0x15d].referenceCount = 0;
  return;
}


// GL_PaletteEqual  @ 001b8360
int GL_PaletteEqual(uchar *pPal1,int tag1,uchar *pPal2,int tag2)

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
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x300);
  return 1;
}


// GL_PaletteInit  @ 001b8290
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_PaletteInit(void)

{
  GL_PALETTE *pGVar1;
  
                    /* Unresolved local var: int i@[???] */
  pGVar1 = gGLPalette;
  do {
    pGVar1->tag = -1;
    pGVar1->referenceCount = 0;
    pGVar1 = pGVar1 + 1;
  } while (pGVar1 != (GL_PALETTE *)&DAT_00e4e690);
  return;
}


// GL_PaletteSelect  @ 001b85b0
void GL_PaletteSelect(int paletteIndex)

{
  if ((g_currentpalette != paletteIndex) &&
     (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
    g_currentpalette = paletteIndex;
    (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(paletteIndex * 0x308 + 0xe0c1a8))
    ;
  }
  return;
}


// GL_PaletteTag  @ 001b82f0
int GL_PaletteTag(uchar *pPal)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  
                    /* Unresolved local var: int tag@[???]
                       Unresolved local var: int i@[???] */
  iVar6 = 1;
  bVar3 = *pPal;
  uVar2 = (uint)bVar3;
  do {
    pbVar5 = pPal + iVar6;
    uVar4 = (uint)bVar3;
    bVar3 = pPal[iVar6 + 1];
    iVar6 = iVar6 + 2;
    uVar2 = (uVar2 + *pbVar5 ^ uVar4) + (uint)bVar3 ^ (uint)*pbVar5;
  } while (iVar6 != 0x2ff);
  pbVar5 = pPal + 0x2ff;
  iVar6 = 1;
  do {
    bVar3 = *pbVar5;
    pbVar1 = pbVar5 + -1;
    pbVar5 = pbVar5 + 1;
    uVar2 = uVar2 + bVar3 ^ (uint)*pbVar1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return (uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f);
}


// GL_ResampleAlphaTexture  @ 001b0be0
void __regparm3
GL_ResampleAlphaTexture(uchar *in,int inwidth,int inheight,uchar *out,int outwidth,int outheight)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uchar *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint *local_840;
  int local_82c;
  byte local_81c [1024];
  byte local_41c [1036];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uchar * inrow@[???]
                       Unresolved local var: uchar * inrow2@[???]
                       Unresolved local var: uint frac@[???]
                       Unresolved local var: uint fracstep@[???]
                       Unresolved local var: uchar[1024] p1@[???]
                       Unresolved local var: uchar[1024] p2@[???]
                       Unresolved local var: uchar * pix1@[???]
                       Unresolved local var: uchar * pix2@[???]
                       Unresolved local var: uchar * pix3@[???]
                       Unresolved local var: uchar * pix4@[???] */
  if (0 < (int)out) {
    uVar1 = (inwidth << 0x10) / (int)out;
    puVar6 = (uchar *)0x0;
    uVar4 = uVar1 >> 2;
    do {
      local_81c[(int)puVar6] = (byte)(uVar4 >> 0x10);
      puVar6 = puVar6 + 1;
      uVar4 = uVar4 + uVar1;
    } while (puVar6 != out);
    puVar6 = (uchar *)0x0;
    iVar2 = (uVar1 >> 2) * 3;
    do {
      local_41c[(int)puVar6] = (byte)((uint)iVar2 >> 0x10);
      puVar6 = puVar6 + 1;
      iVar2 = iVar2 + uVar1;
    } while (puVar6 != out);
  }
  if (0 < outwidth) {
    local_840 = GL_Upload32::scaled;
    local_82c = 0;
    do {
      iVar2 = (int)((((float)local_82c + 0.25) * (float)inheight) / (float)outwidth) * inwidth;
      iVar3 = (int)((((float)local_82c + 0.75) * (float)inheight) / (float)outwidth) * inwidth;
      if (0 < (int)out) {
        puVar6 = (uchar *)0x0;
        do {
          pbVar9 = in + (uint)local_81c[(int)puVar6] + iVar2;
          pbVar5 = in + (uint)local_81c[(int)puVar6] + iVar3;
          pbVar8 = in + (uint)local_41c[(int)puVar6] + iVar2;
          pbVar7 = in + (uint)local_41c[(int)puVar6] + iVar3;
          *(uchar *)((int)local_840 + (int)puVar6) =
               (uchar)((int)((uint)*pbVar7 + (uint)*pbVar9 + (uint)*pbVar8 + (uint)*pbVar5) >> 2);
          puVar6[(int)((int)local_840 + 1)] =
               (uchar)((int)((uint)pbVar7[1] + (uint)pbVar9[1] + (uint)pbVar8[1] + (uint)pbVar5[1])
                      >> 2);
          puVar6[(int)((int)local_840 + 2)] =
               (uchar)((int)((uint)pbVar7[2] + (uint)pbVar9[2] + (uint)pbVar8[2] + (uint)pbVar5[2])
                      >> 2);
          puVar6[(int)((int)local_840 + 3)] =
               (uchar)((int)((uint)pbVar7[3] + (uint)pbVar9[3] + (uint)pbVar8[3] + (uint)pbVar5[3])
                      >> 2);
          puVar6 = puVar6 + 1;
        } while (puVar6 != out);
      }
      local_82c = local_82c + 1;
      local_840 = (uint *)((int)local_840 + (int)out);
    } while (local_82c != outwidth);
  }
  return;
}


// GL_ResampleAlphaTexture  @ 001b3530
void GL_ResampleAlphaTexture
               (uchar *in,int inwidth,int inheight,uchar *out,int outwidth,int outheight)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  int local_824;
  byte local_81c [1024];
  byte local_41c [1036];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uchar * inrow@[???]
                       Unresolved local var: uchar * inrow2@[???]
                       Unresolved local var: uint frac@[???]
                       Unresolved local var: uint fracstep@[???]
                       Unresolved local var: uchar[1024] p1@[???]
                       Unresolved local var: uchar[1024] p2@[???]
                       Unresolved local var: uchar * pix1@[???]
                       Unresolved local var: uchar * pix2@[???]
                       Unresolved local var: uchar * pix3@[???]
                       Unresolved local var: uchar * pix4@[???] */
  if (0 < outwidth) {
    uVar1 = (inwidth << 0x10) / outwidth;
    iVar5 = 0;
    uVar3 = uVar1 >> 2;
    do {
      local_81c[iVar5] = (byte)(uVar3 >> 0x10);
      iVar5 = iVar5 + 1;
      uVar3 = uVar3 + uVar1;
    } while (iVar5 != outwidth);
    iVar6 = 0;
    iVar5 = (uVar1 >> 2) * 3;
    do {
      local_41c[iVar6] = (byte)((uint)iVar5 >> 0x10);
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + uVar1;
    } while (iVar6 != outwidth);
  }
  if (0 < outheight) {
    local_824 = 0;
    do {
      iVar5 = (int)((((float)local_824 + 0.25) * (float)inheight) / (float)outheight) * inwidth;
      iVar6 = (int)((((float)local_824 + 0.75) * (float)inheight) / (float)outheight) * inwidth;
      if (0 < outwidth) {
        iVar2 = 0;
        do {
          pbVar9 = in + (uint)local_81c[iVar2] + iVar5;
          pbVar4 = in + (uint)local_81c[iVar2] + iVar6;
          pbVar8 = in + (uint)local_41c[iVar2] + iVar5;
          pbVar7 = in + (uint)local_41c[iVar2] + iVar6;
          out[iVar2] = (uchar)((int)((uint)*pbVar7 + (uint)*pbVar9 + (uint)*pbVar8 + (uint)*pbVar4)
                              >> 2);
          out[iVar2 + 1] =
               (uchar)((int)((uint)pbVar7[1] + (uint)pbVar9[1] + (uint)pbVar8[1] + (uint)pbVar4[1])
                      >> 2);
          out[iVar2 + 2] =
               (uchar)((int)((uint)pbVar7[2] + (uint)pbVar9[2] + (uint)pbVar8[2] + (uint)pbVar4[2])
                      >> 2);
          out[iVar2 + 3] =
               (uchar)((int)((uint)pbVar7[3] + (uint)pbVar9[3] + (uint)pbVar8[3] + (uint)pbVar4[3])
                      >> 2);
          iVar2 = iVar2 + 1;
        } while (iVar2 != outwidth);
      }
      local_824 = local_824 + 1;
      out = out + outwidth;
    } while (local_824 != outheight);
  }
  return;
}


// GL_ResampleTexture  @ 001b09c0
void __regparm3
GL_ResampleTexture(uint *in,int inwidth,int inheight,uint *out,int outwidth,int outheight)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  byte *pbVar7;
  int *piVar8;
  uint *puVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  int local_2034;
  uint *local_2030;
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
                       Unresolved local var: uchar * pix1@[???]
                       Unresolved local var: uchar * pix2@[???]
                       Unresolved local var: uchar * pix3@[???]
                       Unresolved local var: uchar * pix4@[???] */
  if (0 < (int)out) {
    uVar2 = (inwidth << 0x10) / (int)out;
    piVar8 = local_201c;
    piVar1 = piVar8 + (int)out;
    uVar6 = uVar2 >> 2;
    do {
      *piVar8 = (uVar6 >> 0x10) << 2;
      piVar8 = piVar8 + 1;
      uVar6 = uVar6 + uVar2;
    } while (piVar8 != piVar1);
    piVar8 = local_101c;
    piVar1 = piVar8 + (int)out;
    uVar6 = (uVar2 >> 2) * 3;
    do {
      *piVar8 = (uVar6 >> 0x10) << 2;
      piVar8 = piVar8 + 1;
      uVar6 = uVar6 + uVar2;
    } while (piVar8 != piVar1);
  }
  if (0 < outwidth) {
    local_2030 = GL_Upload32::scaled;
    local_2034 = 0;
    do {
      iVar3 = (int)((((float)local_2034 + 0.25) * (float)inheight) / (float)outwidth) * inwidth;
      iVar4 = (int)((((float)local_2034 + 0.75) * (float)inheight) / (float)outwidth) * inwidth;
      if (0 < (int)out) {
        puVar9 = (uint *)0x0;
        puVar5 = local_2030;
        do {
          piVar1 = local_201c + (int)puVar9;
          piVar8 = local_101c + (int)puVar9;
          puVar9 = (uint *)((int)puVar9 + 1);
          pbVar11 = (byte *)((int)in + *piVar1 + iVar3 * 4);
          pbVar7 = (byte *)((int)in + *piVar1 + iVar4 * 4);
          pbVar10 = (byte *)((int)in + *piVar8 + iVar3 * 4);
          pbVar12 = (byte *)((int)in + *piVar8 + iVar4 * 4);
          *(char *)puVar5 =
               (char)((int)((uint)*pbVar12 + (uint)*pbVar11 + (uint)*pbVar10 + (uint)*pbVar7) >> 2);
          *(char *)((int)puVar5 + 1) =
               (char)((int)((uint)pbVar12[1] + (uint)pbVar11[1] + (uint)pbVar10[1] + (uint)pbVar7[1]
                           ) >> 2);
          *(char *)((int)puVar5 + 2) =
               (char)((int)((uint)pbVar12[2] + (uint)pbVar11[2] + (uint)pbVar10[2] + (uint)pbVar7[2]
                           ) >> 2);
          *(char *)((int)puVar5 + 3) =
               (char)((int)((uint)pbVar12[3] + (uint)pbVar11[3] + (uint)pbVar10[3] + (uint)pbVar7[3]
                           ) >> 2);
          puVar5 = puVar5 + 1;
        } while (puVar9 != out);
      }
      local_2034 = local_2034 + 1;
      local_2030 = local_2030 + (int)out;
    } while (local_2034 != outwidth);
  }
  return;
}


// GL_ResampleTexture  @ 001b3310
void GL_ResampleTexture(uint *in,int inwidth,int inheight,uint *out,int outwidth,int outheight)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  byte *pbVar7;
  int *piVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  int local_2028;
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
                       Unresolved local var: uchar * pix1@[???]
                       Unresolved local var: uchar * pix2@[???]
                       Unresolved local var: uchar * pix3@[???]
                       Unresolved local var: uchar * pix4@[???] */
  if (0 < outwidth) {
    uVar2 = (inwidth << 0x10) / outwidth;
    piVar8 = local_201c;
    piVar1 = piVar8 + outwidth;
    uVar6 = uVar2 >> 2;
    do {
      *piVar8 = (uVar6 >> 0x10) << 2;
      piVar8 = piVar8 + 1;
      uVar6 = uVar6 + uVar2;
    } while (piVar8 != piVar1);
    piVar8 = local_101c;
    piVar1 = piVar8 + outwidth;
    uVar6 = (uVar2 >> 2) * 3;
    do {
      *piVar8 = (uVar6 >> 0x10) << 2;
      piVar8 = piVar8 + 1;
      uVar6 = uVar6 + uVar2;
    } while (piVar8 != piVar1);
  }
  if (0 < outheight) {
    local_2028 = 0;
    do {
      iVar3 = (int)((((float)local_2028 + 0.25) * (float)inheight) / (float)outheight) * inwidth;
      iVar4 = (int)((((float)local_2028 + 0.75) * (float)inheight) / (float)outheight) * inwidth;
      if (0 < outwidth) {
        iVar9 = 0;
        puVar5 = out;
        do {
          piVar1 = local_201c + iVar9;
          piVar8 = local_101c + iVar9;
          iVar9 = iVar9 + 1;
          pbVar11 = (byte *)((int)in + *piVar1 + iVar3 * 4);
          pbVar7 = (byte *)((int)in + *piVar1 + iVar4 * 4);
          pbVar10 = (byte *)((int)in + *piVar8 + iVar3 * 4);
          pbVar12 = (byte *)((int)in + *piVar8 + iVar4 * 4);
          *(char *)puVar5 =
               (char)((int)((uint)*pbVar12 + (uint)*pbVar11 + (uint)*pbVar10 + (uint)*pbVar7) >> 2);
          *(char *)((int)puVar5 + 1) =
               (char)((int)((uint)pbVar12[1] + (uint)pbVar11[1] + (uint)pbVar10[1] + (uint)pbVar7[1]
                           ) >> 2);
          *(char *)((int)puVar5 + 2) =
               (char)((int)((uint)pbVar12[2] + (uint)pbVar11[2] + (uint)pbVar10[2] + (uint)pbVar7[2]
                           ) >> 2);
          *(char *)((int)puVar5 + 3) =
               (char)((int)((uint)pbVar12[3] + (uint)pbVar11[3] + (uint)pbVar10[3] + (uint)pbVar7[3]
                           ) >> 2);
          puVar5 = puVar5 + 1;
        } while (iVar9 != outwidth);
      }
      local_2028 = local_2028 + 1;
      out = out + outwidth;
    } while (local_2028 != outheight);
  }
  return;
}


// GL_ResampleTexturePoint  @ 001b3770
void GL_ResampleTexturePoint
               (uchar *in,int inwidth,int inheight,uchar *out,int outwidth,int outheight)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int local_20;
  uint local_1c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uint ufrac@[???]
                       Unresolved local var: uint vfrac@[???]
                       Unresolved local var: uint ufracstep@[???]
                       Unresolved local var: uint vfracstep@[???]
                       Unresolved local var: uchar * src@[???]
                       Unresolved local var: uchar * dest@[???] */
  if (0 < outheight) {
    local_20 = 0;
    uVar1 = (inwidth << 0x10) / outwidth;
    uVar2 = (inheight << 0x10) / outheight;
    local_1c = uVar2 >> 2;
    do {
      if (0 < outwidth) {
        iVar3 = 0;
        uVar4 = uVar1 >> 2;
        do {
          out[iVar3] = in[uVar4 >> 0x10];
          iVar3 = iVar3 + 1;
          uVar4 = uVar4 + uVar1;
        } while (iVar3 != outwidth);
        out = out + outwidth;
      }
      local_20 = local_20 + 1;
      uVar4 = local_1c + uVar2;
      local_1c = uVar4 & 0xffff;
      in = in + (uVar4 >> 0x10) * inwidth;
    } while (local_20 != outheight);
  }
  return;
}


// GL_SelectTexture  @ 001b1120
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


// GL_SetMode  @ 001d7570
int GL_SetMode(HWND mainwindow,HDC *pmaindc,HGLRC *pbaseRC,int fD3D,char *pszDriver,char *pszCmdLine
              )

{
  int iVar1;
  char *pcVar2;
  GLenum GVar3;
  long lVar4;
  undefined4 local_3c;
  GLsizei local_38;
  GLsizei local_34;
  long local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  GLsizei local_14;
  GLsizei local_10 [3];
  
                    /* Unresolved local var: int iVidCmd@[???]
                       Unresolved local var: int vid_level@[???] */
  gfMiniDriver = 0;
  if (pmaindc != (HDC *)0x0) {
    *pmaindc = (HDC)0x0;
  }
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
  iVar1 = Host_GetVideoLevel();
  if (0 < iVar1) {
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
  s_MSAAFBO.s_hBackBufferDB = 0;
  s_MSAAFBO.s_hBackBufferTex = 0;
  s_BackBufferFBO.s_hBackBufferFBO = 0;
  s_BackBufferFBO.s_hBackBufferCB = 0;
  s_BackBufferFBO.s_hBackBufferDB = 0;
  s_BackBufferFBO.s_hBackBufferTex = 0;
  s_MSAAFBO.s_hBackBufferCB = 0;
  VideoMode_GetCurrentVideoMode(&local_14,local_10,(int *)0x0);
  if (((qglRenderbufferStorageMultisampleEXT ==
        (_func_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei *)0x0) || (bDoMSAAFBO < 1)) ||
     ((gl_extensions == (char *)0x0 ||
      (pcVar2 = Q_strstr(gl_extensions,"GL_EXT_framebuffer_multisample"), pcVar2 == (char *)0x0))))
  {
    Con_DPrintf("MSAA backbuffer rendering disabled.\n");
    s_MSAAFBO.s_hBackBufferFBO = 0;
  }
  else {
    (*qglGenFramebuffersEXT)(1,&s_MSAAFBO.s_hBackBufferFBO);
    (*qglBindFramebufferEXT)(0x8d40,s_MSAAFBO.s_hBackBufferFBO);
    (*qglGenRenderbuffersEXT)(1,(GLuint *)0xf35a34);
    (*qglBindRenderbufferEXT)(0x8d41,s_MSAAFBO.s_hBackBufferCB);
    (*qglRenderbufferStorageMultisampleEXT)(0x8d41,4,0x8058,local_14,local_10[0]);
    (*qglFramebufferRenderbufferEXT)(0x8d40,0x8ce0,0x8d41,s_MSAAFBO.s_hBackBufferCB);
    (*qglGenRenderbuffersEXT)(1,(GLuint *)0xf35a38);
    (*qglBindRenderbufferEXT)(0x8d41,s_MSAAFBO.s_hBackBufferDB);
    (*qglRenderbufferStorageMultisampleEXT)(0x8d41,4,0x81a6,local_14,local_10[0]);
    (*qglFramebufferRenderbufferEXT)(0x8d40,0x8d00,0x8d41,s_MSAAFBO.s_hBackBufferDB);
    GVar3 = (*qglCheckFramebufferStatusEXT)(0x8d40);
    if (GVar3 != 0x8cd5) {
      if (s_MSAAFBO.s_hBackBufferFBO != 0) {
        (*qglDeleteFramebuffersEXT)(1,&s_MSAAFBO.s_hBackBufferFBO);
      }
      s_MSAAFBO.s_hBackBufferFBO = 0;
      if (s_MSAAFBO.s_hBackBufferCB != 0) {
        (*qglDeleteRenderbuffersEXT)(1,(GLuint *)0xf35a34);
      }
      s_MSAAFBO.s_hBackBufferCB = 0;
      if (s_MSAAFBO.s_hBackBufferDB != 0) {
        (*qglDeleteRenderbuffersEXT)(1,(GLuint *)0xf35a38);
      }
      s_MSAAFBO.s_hBackBufferDB = 0;
      if (s_MSAAFBO.s_hBackBufferTex != 0) {
        (*qglDeleteTextures)(1,(GLuint *)0xf35a3c);
      }
      s_MSAAFBO.s_hBackBufferTex = 0;
      Con_DPrintf("Error initializing MSAA frame buffer\n");
      s_MSAAFBO.s_hBackBufferFBO = 0;
    }
  }
  if (0 < bDoScaledFBO) {
                    /* Unresolved local var: int GL_TEX_MODE@[???] */
    if (s_MSAAFBO.s_hBackBufferFBO != 0) {
      glEnable(0x809d);
    }
    glEnable(0x84f5);
    (*qglGenFramebuffersEXT)(1,&s_BackBufferFBO.s_hBackBufferFBO);
    (*qglBindFramebufferEXT)(0x8d40,s_BackBufferFBO.s_hBackBufferFBO);
    if (s_MSAAFBO.s_hBackBufferFBO == 0) {
      (*qglGenRenderbuffersEXT)(1,(GLuint *)0xf35a98);
      (*qglBindRenderbufferEXT)(0x8d41,s_BackBufferFBO.s_hBackBufferDB);
      (*qglRenderbufferStorageEXT)(0x8d41,0x81a6,local_14,local_10[0]);
      (*qglFramebufferRenderbufferEXT)(0x8d40,0x8d00,0x8d41,s_BackBufferFBO.s_hBackBufferDB);
    }
    glGenTextures(1,0xf35a9c);
    glBindTexture(0x84f5,s_BackBufferFBO.s_hBackBufferTex);
    glTexParameteri(0x84f5,0x2800,0x2601);
    glTexParameteri(0x84f5,0x2801,0x2601);
    glTexParameteri(0x84f5,0x2802,0x812f);
    glTexParameteri(0x84f5,0x2803,0x812f);
    glTexEnvi(0x2300,0x2200,0x1e01);
    glTexImage2D(0x84f5,0,0x1908,local_14,local_10[0],0,0x1908,0x1401,0);
    (*qglFramebufferTexture2DEXT)(0x8d40,0x8ce0,0x84f5,s_BackBufferFBO.s_hBackBufferTex,0);
    glBindTexture(0x84f5,0);
    glDisable(0x84f5);
  }
  if ((bDoScaledFBO == 0) || (GVar3 = (*qglCheckFramebufferStatusEXT)(0x8d40), GVar3 != 0x8cd5)) {
                    /* Unresolved local var: int iFreq@[???]
                       Unresolved local var: int refresh@[???]
                       Unresolved local var: SDL_DisplayMode requestedMode@[???]
                       Unresolved local var: SDL_DisplayMode mode@[???] */
    FreeFBOObjects();
    lVar4 = 0;
    iVar1 = COM_CheckParm("-freq");
    if (iVar1 != 0) {
      lVar4 = strtol(com_argv[iVar1 + 1],(char **)0x0,10);
      Con_DPrintf("Setting refresh rate to %dHz\n",lVar4);
    }
    local_3c = 0;
    local_38 = local_14;
    local_34 = local_10[0];
    local_30 = lVar4;
    iVar1 = SDL_GetClosestDisplayMode(0,&local_3c,&local_28);
    if (iVar1 == 0) {
      Sys_Error("Error initializing Main frame buffer\n");
    }
    Con_DPrintf("Setting closest display mode: width:%d height:%d freq:%d format:%u\n",local_24,
                local_20,local_1c,local_28);
    if (bDoScaledFBO == 0) {
      Con_DPrintf("FBO backbuffer rendering disabled.\n",local_24,local_20,local_1c,local_28);
    }
    else {
      Con_DPrintf("FBO backbuffer rendering disabled due to create error.\n",local_24,local_20,
                  local_1c,local_28);
    }
    SDL_SetWindowDisplayMode(mainwindow,&local_28);
    bNeedsFullScreenModeSwitch = 1;
    VideoMode_RestoreVideo();
  }
  if (bDoScaledFBO < 1) {
    return 1;
  }
  (*qglBindFramebufferEXT)(0x8d40,0);
  return 1;
}


// GL_Shutdown  @ 001d7db0
void GL_Shutdown(HWND hwnd,HDC hdc,HGLRC hglrc)

{
  if (s_MSAAFBO.s_hBackBufferFBO != 0) {
    (*qglDeleteFramebuffersEXT)(1,&s_MSAAFBO.s_hBackBufferFBO);
  }
  s_MSAAFBO.s_hBackBufferFBO = 0;
  if (s_MSAAFBO.s_hBackBufferCB != 0) {
    (*qglDeleteRenderbuffersEXT)(1,(GLuint *)0xf35a34);
  }
  s_MSAAFBO.s_hBackBufferCB = 0;
  if (s_MSAAFBO.s_hBackBufferDB != 0) {
    (*qglDeleteRenderbuffersEXT)(1,(GLuint *)0xf35a38);
  }
  s_MSAAFBO.s_hBackBufferDB = 0;
  if (s_MSAAFBO.s_hBackBufferTex != 0) {
    (*qglDeleteTextures)(1,(GLuint *)0xf35a3c);
  }
  s_MSAAFBO.s_hBackBufferTex = 0;
  if (s_BackBufferFBO.s_hBackBufferFBO != 0) {
    (*qglDeleteFramebuffersEXT)(1,&s_BackBufferFBO.s_hBackBufferFBO);
  }
  s_BackBufferFBO.s_hBackBufferFBO = 0;
  if (s_BackBufferFBO.s_hBackBufferCB != 0) {
    (*qglDeleteRenderbuffersEXT)(1,(GLuint *)0xf35a94);
  }
  s_BackBufferFBO.s_hBackBufferCB = 0;
  if (s_BackBufferFBO.s_hBackBufferDB != 0) {
    (*qglDeleteRenderbuffersEXT)(1,(GLuint *)0xf35a98);
  }
  s_BackBufferFBO.s_hBackBufferDB = 0;
  if (s_BackBufferFBO.s_hBackBufferTex != 0) {
    (*qglDeleteTextures)(1,(GLuint *)0xf35a9c);
  }
  s_BackBufferFBO.s_hBackBufferTex = 0;
  return;
}


// GL_SubdivideSurface  @ 001dfbf0
void GL_SubdivideSurface(msurface_t *fa)

{
  vec_t *pvVar1;
  uint numverts;
  int iVar2;
  vec_t *pvVar3;
  int iVar4;
  mvertex_t *pmVar5;
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
    Sys_Error("Too many edges in model %s\n",loadmodel);
    return;
  }
  if (numverts != 0) {
    pvVar3 = local_31c;
    pvVar1 = pvVar3 + numverts * 3;
    iVar4 = fa->firstedge << 2;
    do {
      iVar2 = *(int *)((int)loadmodel->surfedges + iVar4);
      if (iVar2 < 1) {
        pmVar5 = loadmodel->vertexes + loadmodel->edges[-iVar2].v[1];
      }
      else {
        pmVar5 = loadmodel->vertexes + loadmodel->edges[iVar2].v[0];
      }
      iVar4 = iVar4 + 4;
      *pvVar3 = pmVar5->position[0];
      pvVar3[1] = pmVar5->position[1];
      pvVar3[2] = pmVar5->position[2];
      pvVar3 = pvVar3 + 3;
    } while (pvVar3 != pvVar1);
  }
  local_320 = local_31c;
  SubdividePolygon(numverts,local_320);
  return;
}


// GL_Texels_f  @ 001b06d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_Texels_f(void)

{
  Con_Printf("Current uploaded texels: %i\n",texels);
  return;
}


// GL_UnloadTexture  @ 001b81d0
void GL_UnloadTexture(char *identifier)

{
  int iVar1;
  uint uVar2;
  gltexture_t *dest;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: gltexture_t * glt@[???] */
  if (0 < numgltextures) {
    dest = gltextures;
    iVar3 = 0;
    do {
      iVar1 = Q_strcmp(identifier,dest->identifier);
      if (iVar1 == 0) {
        if ((short)(dest->servercount & -0x8000) != 0) {
          return;
        }
                    /* Unresolved local var: int texnum@[???] */
        (*qglDeleteTextures)(1,(GLuint *)dest);
        uVar2 = (uint)dest->paletteIndex;
        if (-1 < (int)uVar2) {
          if (gGLPalette[uVar2].referenceCount < 2) {
            if (uVar2 < 0x15e) {
              gGLPalette[uVar2].tag = -1;
              gGLPalette[uVar2].referenceCount = 0;
            }
          }
          else {
            gGLPalette[uVar2].referenceCount = gGLPalette[uVar2].referenceCount + -1;
          }
        }
        Q_memset(dest,0,0x54);
        dest->servercount = -1;
        return;
      }
      iVar3 = iVar3 + 1;
      dest = dest + 1;
    } while (iVar3 < numgltextures);
  }
  return;
}


// GL_UnloadTextures  @ 001b8110
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void GL_UnloadTextures(void)

{
  uint uVar1;
  int iVar2;
  gltexture_t *dest;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: gltexture_t * glt@[???] */
  if (0 < numgltextures) {
    dest = gltextures;
    iVar3 = 0;
    iVar2 = numgltextures;
    do {
      if ((0 < dest->servercount) && (dest->servercount != gHostSpawnCount)) {
        (*qglDeleteTextures)(1,(GLuint *)dest);
        uVar1 = (uint)dest->paletteIndex;
        if (-1 < (int)uVar1) {
          if (gGLPalette[uVar1].referenceCount < 2) {
            if (uVar1 < 0x15e) {
              gGLPalette[uVar1].tag = -1;
              gGLPalette[uVar1].referenceCount = 0;
            }
          }
          else {
                    /* Unresolved local var: int texnum@[???] */
            gGLPalette[uVar1].referenceCount = gGLPalette[uVar1].referenceCount + -1;
          }
        }
        Q_memset(dest,0,0x54);
        iVar2 = numgltextures;
        dest->servercount = -1;
      }
      iVar3 = iVar3 + 1;
      dest = dest + 1;
    } while (iVar3 < iVar2);
  }
  return;
}


// GL_Upload16  @ 001b7d50
void GL_Upload16(uchar *data,int width,int height,qboolean mipmap,int iType,uchar *pPal,int filter)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  byte *pbVar7;
  uint count;
  int local_30;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: qboolean noalpha@[???]
                       Unresolved local var: int p@[???]
                       Unresolved local var: uchar * pb@[???] */
  count = width * height;
  local_30 = iType;
  if (0x12c000 < count) {
    Con_Printf("Can\'t upload (%ix%i) texture, it\'s > 640*480 bytes\n");
    return;
  }
  if (iType != 2) {
    if (pPal == (uchar *)0x0) {
      return;
    }
    iVar6 = 0;
    do {
      pPal[iVar6] = texgammatable[pPal[iVar6]];
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0x300);
    if (((iType == 3) || (iType == 1)) || (iType == 4)) {
      if (count != 0) {
        if (iType == 3) {
          uVar3 = 0;
          do {
            GL_Upload16::trans[uVar3] =
                 (uint)data[uVar3] << 0x18 | *(uint *)(pPal + 0x2fd) & 0xffffff;
            uVar3 = uVar3 + 1;
          } while (uVar3 != count);
          goto LAB_001b7e46;
        }
        if (iType == 4) {
          uVar3 = 0;
          do {
            GL_Upload16::trans[uVar3] =
                 *(uint *)(pPal + (uint)data[uVar3] * 3) & 0xffffff | (uint)data[uVar3] << 0x18;
            uVar3 = uVar3 + 1;
          } while (uVar3 != count);
          goto LAB_001b7e46;
        }
        bVar1 = true;
        uVar3 = 0;
        do {
          while (data[uVar3] == 0xff) {
            bVar1 = false;
            GL_Upload16::trans[uVar3] = 0;
            uVar3 = uVar3 + 1;
            if (uVar3 == count) goto LAB_001b7e3c;
          }
          GL_Upload16::trans[uVar3] = *(uint *)(pPal + (uint)data[uVar3] * 3) | 0xff000000;
          uVar3 = uVar3 + 1;
        } while (uVar3 != count);
LAB_001b7e3c:
        if (!bVar1) goto LAB_001b7e46;
      }
      local_30 = 0;
      goto LAB_001b7e46;
    }
    if (iType == 0) {
      if ((count & 3) != 0) {
        Sys_Error("GL_Upload16: s&3");
      }
      if (gl_dither.value == 0.0) {
        if (count != 0) {
          iVar6 = 0;
          do {
            GL_Upload16::trans[iVar6] = *(uint *)(pPal + (uint)data[iVar6] * 3) | 0xff000000;
            GL_Upload16::trans[iVar6 + 1] = *(uint *)(pPal + (uint)data[iVar6 + 1] * 3) | 0xff000000
            ;
            GL_Upload16::trans[iVar6 + 2] = *(uint *)(pPal + (uint)data[iVar6 + 2] * 3) | 0xff000000
            ;
            GL_Upload16::trans[iVar6 + 3] = *(uint *)(pPal + (uint)data[iVar6 + 3] * 3) | 0xff000000
            ;
            iVar6 = iVar6 + 4;
          } while (iVar6 != (count - 1 & 0xfffffffc) + 4);
        }
      }
      else if (count != 0) {
        uVar3 = 0;
        do {
                    /* Unresolved local var: uchar r@[???]
                       Unresolved local var: uchar g@[???]
                       Unresolved local var: uchar b@[???]
                       Unresolved local var: uchar * ppix@[???] */
          pbVar7 = pPal + (uint)data[uVar3] * 3;
          bVar4 = *pbVar7 >> 6 | *pbVar7;
          *pbVar7 = bVar4;
          bVar5 = pbVar7[1] >> 6 | pbVar7[1];
          pbVar7[1] = bVar5;
          bVar2 = pbVar7[2] >> 6 | pbVar7[2];
          pbVar7[2] = bVar2;
          GL_Upload16::trans[uVar3] = bVar4 | 0xff000000 | (uint)bVar5 << 8 | (uint)bVar2 << 0x10;
          uVar3 = uVar3 + 1;
        } while (uVar3 != count);
      }
      goto LAB_001b7e46;
    }
    if (iType != 2) {
      Con_Printf("Upload16:Bogus texture type!/n");
      goto LAB_001b7e46;
    }
  }
  Q_memcpy(GL_Upload16::trans,data,count);
LAB_001b7e46:
  GL_Upload32(GL_Upload16::trans,width,height,mipmap,local_30,filter);
  return;
}


// GL_Upload32  @ 001b55c0
void GL_Upload32(uint *data,int width,int height,qboolean mipmap,int iType,int filter)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined1 (*pauVar3) [12];
  uint *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [14];
  undefined1 auVar11 [14];
  undefined1 auVar12 [14];
  undefined1 auVar13 [14];
  undefined1 auVar14 [14];
  undefined1 auVar15 [14];
  undefined1 auVar16 [14];
  undefined1 auVar17 [14];
  undefined1 auVar18 [14];
  undefined1 auVar19 [14];
  undefined1 auVar20 [14];
  undefined1 auVar21 [14];
  undefined1 auVar22 [14];
  undefined1 auVar23 [14];
  undefined1 auVar24 [14];
  undefined1 auVar25 [14];
  undefined1 auVar26 [14];
  undefined1 auVar27 [14];
  undefined1 auVar28 [14];
  undefined1 auVar29 [14];
  undefined1 auVar30 [14];
  undefined1 auVar31 [14];
  undefined1 auVar32 [14];
  undefined1 auVar33 [14];
  undefined1 auVar34 [14];
  undefined1 auVar35 [14];
  undefined1 auVar36 [14];
  undefined1 auVar37 [14];
  undefined1 auVar38 [14];
  undefined1 auVar39 [14];
  undefined1 auVar40 [14];
  undefined1 auVar41 [14];
  undefined1 auVar42 [14];
  undefined1 auVar43 [14];
  undefined1 auVar44 [14];
  undefined1 auVar45 [14];
  byte bVar46;
  byte bVar47;
  byte bVar48;
  byte bVar49;
  byte bVar50;
  byte bVar51;
  byte bVar52;
  byte bVar53;
  byte bVar54;
  byte bVar55;
  byte bVar56;
  byte bVar57;
  byte bVar58;
  byte bVar59;
  byte bVar60;
  byte bVar61;
  byte bVar62;
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
  byte bVar78;
  byte bVar79;
  byte bVar80;
  byte bVar81;
  byte bVar82;
  byte bVar83;
  byte bVar84;
  byte bVar85;
  byte bVar86;
  byte bVar87;
  byte bVar88;
  byte bVar89;
  byte bVar90;
  byte bVar91;
  byte bVar92;
  byte bVar93;
  byte bVar94;
  byte bVar95;
  byte bVar96;
  byte bVar97;
  byte bVar98;
  byte bVar99;
  byte bVar100;
  byte bVar101;
  byte bVar102;
  byte bVar103;
  byte bVar104;
  byte bVar105;
  byte bVar106;
  byte bVar107;
  byte bVar108;
  byte bVar109;
  byte bVar110;
  byte bVar111;
  byte bVar112;
  byte bVar113;
  byte bVar114;
  byte bVar115;
  byte bVar116;
  byte bVar117;
  undefined4 uVar118;
  undefined4 uVar119;
  undefined4 uVar120;
  undefined4 uVar121;
  undefined4 uVar122;
  undefined4 uVar123;
  undefined4 uVar124;
  undefined4 uVar125;
  uint uVar126;
  uint uVar127;
  uint uVar128;
  uint uVar129;
  uint uVar130;
  uint uVar131;
  uint uVar132;
  uint uVar133;
  uint uVar134;
  uint uVar135;
  uint uVar136;
  uint uVar137;
  uint uVar138;
  uint uVar139;
  uint uVar140;
  uint uVar141;
  uint uVar142;
  uint uVar143;
  uint uVar144;
  uint uVar145;
  uint uVar146;
  uint uVar147;
  uint uVar148;
  uint uVar149;
  uint uVar150;
  uint uVar151;
  uint uVar152;
  uint uVar153;
  uint uVar154;
  uint uVar155;
  uint uVar156;
  uint uVar157;
  uint uVar158;
  uint uVar159;
  uint uVar160;
  uint uVar161;
  uint uVar162;
  uint uVar163;
  uint uVar164;
  uint uVar165;
  uint uVar166;
  undefined1 auVar167 [16];
  undefined1 auVar168 [16];
  undefined1 auVar169 [16];
  undefined1 auVar170 [16];
  undefined1 auVar171 [16];
  undefined1 auVar172 [16];
  undefined1 auVar173 [16];
  undefined1 auVar174 [16];
  undefined1 auVar175 [16];
  undefined1 auVar176 [16];
  undefined1 auVar177 [16];
  undefined1 auVar178 [16];
  undefined1 auVar179 [16];
  undefined1 auVar180 [16];
  undefined1 auVar181 [16];
  undefined1 auVar182 [16];
  undefined1 auVar183 [16];
  undefined1 auVar184 [16];
  undefined1 auVar185 [16];
  undefined1 auVar186 [16];
  undefined1 auVar187 [16];
  undefined1 auVar188 [16];
  undefined1 auVar189 [16];
  undefined1 auVar190 [16];
  undefined1 auVar191 [16];
  undefined1 auVar192 [16];
  undefined1 auVar193 [16];
  undefined1 auVar194 [16];
  undefined1 auVar195 [16];
  undefined1 auVar196 [16];
  undefined1 auVar197 [16];
  undefined1 auVar198 [16];
  undefined1 auVar199 [16];
  undefined1 auVar200 [16];
  undefined1 auVar201 [16];
  undefined1 auVar202 [16];
  undefined1 auVar203 [16];
  undefined1 auVar204 [16];
  undefined1 auVar205 [16];
  undefined1 auVar206 [16];
  undefined1 auVar207 [16];
  undefined1 auVar208 [16];
  undefined1 auVar209 [16];
  undefined1 auVar210 [16];
  undefined1 auVar211 [16];
  undefined1 auVar212 [16];
  undefined1 auVar213 [16];
  undefined1 auVar214 [16];
  undefined1 auVar215 [16];
  undefined1 auVar216 [16];
  undefined1 auVar217 [16];
  undefined1 auVar218 [16];
  undefined1 auVar219 [16];
  undefined1 auVar220 [16];
  undefined1 auVar221 [16];
  undefined1 auVar222 [16];
  undefined1 auVar223 [16];
  undefined1 auVar224 [16];
  undefined1 auVar225 [16];
  undefined1 auVar226 [16];
  undefined1 auVar227 [14];
  undefined1 auVar228 [12];
  unkuint10 Var229;
  undefined1 auVar230 [14];
  undefined1 auVar231 [16];
  undefined1 auVar232 [16];
  undefined1 auVar233 [16];
  undefined1 auVar234 [16];
  undefined1 auVar235 [16];
  undefined1 auVar236 [16];
  undefined1 auVar237 [16];
  undefined1 auVar238 [16];
  undefined1 auVar239 [16];
  undefined1 auVar240 [16];
  undefined1 auVar241 [16];
  undefined1 auVar242 [16];
  undefined1 auVar243 [16];
  undefined1 auVar244 [16];
  undefined1 auVar245 [16];
  undefined1 auVar246 [16];
  undefined1 auVar247 [16];
  undefined1 auVar248 [16];
  undefined1 auVar249 [16];
  undefined1 auVar250 [16];
  undefined1 auVar251 [16];
  undefined1 auVar252 [16];
  undefined1 auVar253 [16];
  undefined1 auVar254 [16];
  undefined1 auVar255 [16];
  undefined1 auVar256 [16];
  undefined1 auVar257 [16];
  undefined1 auVar258 [16];
  undefined1 auVar259 [16];
  undefined1 auVar260 [16];
  undefined1 auVar261 [16];
  undefined1 auVar262 [16];
  undefined1 auVar263 [16];
  undefined1 auVar264 [16];
  undefined1 auVar265 [16];
  undefined1 auVar266 [16];
  undefined1 auVar267 [16];
  undefined1 auVar268 [16];
  undefined1 auVar269 [16];
  undefined1 auVar270 [16];
  undefined1 auVar271 [16];
  undefined1 auVar272 [16];
  undefined1 auVar273 [16];
  undefined1 auVar274 [16];
  undefined1 auVar275 [16];
  undefined1 auVar276 [16];
  undefined1 auVar277 [16];
  undefined1 auVar278 [16];
  undefined1 auVar279 [16];
  undefined1 auVar280 [16];
  undefined1 auVar281 [16];
  undefined1 auVar282 [16];
  undefined1 auVar283 [16];
  undefined1 auVar284 [16];
  undefined1 auVar285 [16];
  undefined1 auVar286 [16];
  undefined1 auVar287 [16];
  undefined1 auVar288 [16];
  undefined1 auVar289 [16];
  undefined1 auVar290 [16];
  undefined1 auVar291 [14];
  undefined1 auVar292 [12];
  undefined1 auVar293 [14];
  undefined1 auVar294 [16];
  undefined1 auVar295 [16];
  undefined1 auVar296 [16];
  undefined1 auVar297 [16];
  undefined1 auVar298 [16];
  undefined1 auVar299 [16];
  undefined1 auVar300 [16];
  undefined1 auVar301 [16];
  undefined1 auVar302 [16];
  undefined1 auVar303 [16];
  undefined1 auVar304 [16];
  undefined1 auVar305 [16];
  undefined1 auVar306 [16];
  undefined1 auVar307 [16];
  undefined1 auVar308 [16];
  undefined1 auVar309 [16];
  undefined1 auVar310 [16];
  undefined1 auVar311 [16];
  undefined1 auVar312 [16];
  undefined1 auVar313 [16];
  undefined1 auVar314 [16];
  undefined1 auVar315 [16];
  undefined1 auVar316 [16];
  undefined1 auVar317 [16];
  undefined1 auVar318 [16];
  undefined1 auVar319 [16];
  undefined1 auVar320 [16];
  undefined1 auVar321 [16];
  undefined1 auVar322 [16];
  undefined1 auVar323 [16];
  undefined1 auVar324 [16];
  undefined1 auVar325 [16];
  undefined1 auVar326 [16];
  undefined1 auVar327 [16];
  undefined1 auVar328 [16];
  undefined1 auVar329 [16];
  undefined1 auVar330 [16];
  undefined1 auVar331 [16];
  undefined1 auVar332 [16];
  undefined1 auVar333 [16];
  undefined1 auVar334 [16];
  undefined1 auVar335 [16];
  undefined1 auVar336 [16];
  undefined1 auVar337 [16];
  undefined1 auVar338 [16];
  undefined1 auVar339 [16];
  undefined1 auVar340 [16];
  undefined1 auVar341 [16];
  undefined1 auVar342 [16];
  undefined1 auVar343 [16];
  undefined1 auVar344 [16];
  undefined1 auVar345 [16];
  undefined1 auVar346 [16];
  undefined1 auVar347 [16];
  undefined1 auVar348 [16];
  undefined1 auVar349 [16];
  undefined1 auVar350 [16];
  undefined1 auVar351 [16];
  undefined1 auVar352 [16];
  undefined1 auVar353 [16];
  undefined1 auVar354 [14];
  undefined1 auVar355 [12];
  undefined1 auVar356 [14];
  undefined1 auVar357 [16];
  undefined1 auVar358 [16];
  undefined1 auVar359 [16];
  undefined1 auVar360 [16];
  undefined1 auVar361 [16];
  undefined1 auVar362 [16];
  undefined1 auVar363 [16];
  undefined1 auVar364 [16];
  undefined1 auVar365 [16];
  undefined1 auVar366 [16];
  undefined1 auVar367 [16];
  undefined1 auVar368 [16];
  undefined1 auVar369 [16];
  undefined1 auVar370 [16];
  undefined1 auVar371 [16];
  undefined1 auVar372 [16];
  undefined1 auVar373 [16];
  undefined1 auVar374 [16];
  undefined1 auVar375 [16];
  undefined1 auVar376 [16];
  undefined1 auVar377 [16];
  undefined1 auVar378 [16];
  undefined1 auVar379 [16];
  undefined1 auVar380 [16];
  undefined1 auVar381 [16];
  undefined1 auVar382 [16];
  undefined1 auVar383 [16];
  undefined1 auVar384 [16];
  undefined1 auVar385 [16];
  undefined1 auVar386 [16];
  undefined1 auVar387 [16];
  undefined1 auVar388 [16];
  undefined1 auVar389 [16];
  undefined1 auVar390 [16];
  undefined1 auVar391 [16];
  undefined1 auVar392 [16];
  undefined1 auVar393 [16];
  undefined1 auVar394 [16];
  undefined1 auVar395 [16];
  undefined1 auVar396 [16];
  undefined1 auVar397 [16];
  undefined1 auVar398 [16];
  undefined1 auVar399 [16];
  undefined1 auVar400 [16];
  undefined1 auVar401 [16];
  undefined1 auVar402 [16];
  undefined1 auVar403 [16];
  undefined1 auVar404 [16];
  undefined1 auVar405 [16];
  undefined1 auVar406 [16];
  undefined1 auVar407 [16];
  undefined1 auVar408 [16];
  undefined1 auVar409 [16];
  undefined1 auVar410 [16];
  undefined1 auVar411 [16];
  undefined1 auVar412 [16];
  undefined1 auVar413 [16];
  undefined1 auVar414 [16];
  undefined1 auVar415 [16];
  undefined1 auVar416 [16];
  undefined1 auVar417 [14];
  undefined1 auVar418 [12];
  undefined1 auVar419 [14];
  undefined1 auVar420 [13];
  undefined1 auVar421 [11];
  undefined1 auVar422 [13];
  undefined1 auVar423 [11];
  undefined1 auVar424 [13];
  undefined1 auVar425 [13];
  undefined1 auVar426 [13];
  undefined1 auVar427 [11];
  undefined1 auVar428 [13];
  undefined1 auVar429 [13];
  undefined1 auVar430 [13];
  undefined1 auVar431 [11];
  undefined1 auVar432 [15];
  undefined1 auVar433 [15];
  undefined1 auVar434 [15];
  undefined1 auVar435 [15];
  undefined1 auVar436 [15];
  undefined1 auVar437 [15];
  undefined1 auVar438 [15];
  undefined1 auVar439 [15];
  undefined1 auVar440 [13];
  undefined1 auVar441 [13];
  undefined1 auVar442 [13];
  undefined1 auVar443 [13];
  undefined1 auVar444 [13];
  undefined1 auVar445 [13];
  uint3 uVar446;
  undefined1 auVar447 [15];
  undefined1 auVar448 [13];
  undefined1 auVar449 [13];
  undefined1 auVar450 [13];
  undefined1 auVar451 [13];
  undefined1 auVar452 [13];
  undefined1 auVar453 [13];
  undefined1 auVar454 [13];
  undefined1 auVar455 [13];
  undefined1 auVar456 [13];
  undefined1 auVar457 [13];
  undefined1 auVar458 [13];
  undefined1 auVar459 [13];
  undefined1 auVar460 [13];
  undefined1 auVar461 [13];
  uint3 uVar462;
  undefined1 auVar463 [15];
  undefined1 auVar464 [13];
  undefined1 auVar465 [13];
  undefined1 auVar466 [13];
  undefined1 auVar467 [13];
  undefined1 auVar468 [13];
  undefined1 auVar469 [13];
  undefined1 auVar470 [13];
  undefined1 auVar471 [13];
  undefined1 auVar472 [13];
  undefined1 auVar473 [13];
  undefined1 auVar474 [13];
  undefined1 auVar475 [13];
  uint3 uVar476;
  undefined1 auVar477 [15];
  undefined1 auVar478 [13];
  undefined1 auVar479 [13];
  undefined1 auVar480 [13];
  undefined1 auVar481 [13];
  undefined1 auVar482 [13];
  undefined1 auVar483 [13];
  undefined1 auVar484 [13];
  undefined1 auVar485 [13];
  undefined1 auVar486 [13];
  undefined1 auVar487 [13];
  undefined1 auVar488 [13];
  undefined1 auVar489 [13];
  uint3 uVar490;
  undefined1 auVar491 [15];
  undefined1 auVar492 [13];
  undefined1 auVar493 [13];
  undefined1 auVar494 [13];
  undefined1 auVar495 [13];
  undefined1 auVar496 [13];
  undefined1 auVar497 [13];
  undefined1 auVar498 [13];
  undefined1 auVar499 [13];
  undefined1 auVar500 [15];
  undefined1 auVar501 [15];
  undefined1 auVar502 [15];
  undefined1 auVar503 [15];
  undefined1 auVar504 [15];
  undefined1 auVar505 [15];
  undefined1 auVar506 [15];
  undefined1 auVar507 [15];
  undefined1 auVar508 [15];
  undefined1 auVar509 [15];
  undefined1 auVar510 [15];
  undefined1 auVar511 [15];
  uint6 uVar512;
  uint6 uVar513;
  uint6 uVar514;
  uint6 uVar515;
  byte bVar516;
  uint3 uVar517;
  byte bVar518;
  byte bVar519;
  byte bVar520;
  int iVar521;
  uint uVar522;
  int iVar523;
  uint *puVar524;
  uint *puVar525;
  uint *puVar526;
  uint *puVar527;
  uint *puVar528;
  uint *puVar529;
  uint *puVar530;
  uint *puVar531;
  uint *puVar532;
  uint uVar533;
  uint uVar534;
  uint *puVar535;
  undefined1 auVar536 [16];
  undefined1 auVar544 [16];
  undefined1 auVar552 [16];
  undefined1 auVar560 [16];
  undefined1 auVar568 [16];
  undefined1 auVar576 [16];
  undefined1 auVar584 [16];
  undefined1 auVar592 [16];
  undefined1 auVar600 [16];
  undefined1 auVar608 [16];
  undefined1 auVar616 [16];
  undefined1 auVar624 [16];
  undefined1 auVar633 [16];
  undefined1 auVar641 [16];
  undefined1 auVar649 [16];
  undefined1 auVar657 [16];
  undefined1 auVar665 [16];
  undefined1 auVar673 [16];
  undefined1 auVar681 [16];
  undefined1 auVar689 [16];
  undefined1 auVar697 [16];
  undefined1 auVar705 [16];
  undefined1 auVar713 [16];
  undefined1 auVar721 [16];
  undefined1 auVar729 [16];
  undefined1 auVar737 [16];
  undefined1 auVar745 [16];
  undefined1 auVar753 [16];
  undefined1 auVar761 [16];
  undefined1 auVar769 [16];
  undefined1 auVar777 [16];
  undefined1 auVar785 [16];
  undefined1 auVar793 [16];
  undefined1 auVar801 [16];
  undefined1 auVar809 [16];
  undefined1 auVar817 [16];
  undefined1 auVar825 [16];
  undefined1 auVar826 [16];
  undefined1 auVar834 [16];
  undefined1 auVar842 [16];
  undefined1 auVar850 [16];
  undefined1 auVar858 [16];
  undefined1 auVar866 [16];
  undefined1 auVar874 [16];
  undefined1 auVar882 [16];
  undefined1 auVar890 [16];
  undefined1 auVar898 [16];
  undefined1 auVar906 [16];
  undefined1 auVar914 [16];
  undefined1 uVar923;
  undefined1 uVar924;
  undefined1 auVar922 [16];
  undefined1 auVar925 [16];
  undefined1 auVar926 [16];
  int *bpp;
  undefined4 local_15c;
  byte bStack_158;
  byte bStack_157;
  byte bStack_156;
  byte bStack_155;
  byte bStack_154;
  byte bStack_153;
  byte bStack_152;
  byte bStack_151;
  byte local_14c;
  byte bStack_14b;
  byte bStack_14a;
  byte bStack_149;
  byte bStack_148;
  byte bStack_147;
  byte bStack_146;
  byte bStack_145;
  undefined1 uStack_144;
  undefined1 uStack_143;
  undefined1 uStack_142;
  undefined1 uStack_141;
  undefined1 uStack_140;
  undefined1 uStack_13f;
  undefined1 uStack_13e;
  undefined1 uStack_13d;
  byte local_13c;
  byte bStack_13b;
  byte bStack_13a;
  byte bStack_139;
  byte bStack_138;
  byte bStack_137;
  byte bStack_136;
  byte bStack_135;
  undefined1 uStack_134;
  byte bStack_133;
  byte local_12c;
  byte bStack_12b;
  byte bStack_12a;
  byte bStack_129;
  byte bStack_128;
  byte bStack_127;
  byte bStack_126;
  byte bStack_125;
  undefined1 uStack_124;
  undefined1 uStack_123;
  undefined1 uStack_122;
  undefined1 uStack_121;
  undefined1 uStack_120;
  undefined1 uStack_11f;
  undefined1 uStack_11e;
  undefined1 uStack_11d;
  undefined1 uStack_114;
  byte local_10c;
  byte bStack_10b;
  byte bStack_10a;
  byte bStack_109;
  byte bStack_108;
  byte bStack_107;
  byte bStack_106;
  byte bStack_105;
  undefined1 uStack_104;
  undefined1 uStack_103;
  undefined1 uStack_102;
  undefined1 uStack_101;
  undefined1 uStack_100;
  undefined1 uStack_ff;
  undefined1 uStack_fe;
  undefined1 uStack_fd;
  undefined1 local_ec;
  undefined1 uStack_e8;
  undefined1 uStack_e4;
  uint *local_d4;
  uint *local_d0;
  uint local_a0;
  undefined1 local_9c;
  undefined1 uStack_98;
  undefined1 uStack_94;
  int local_74;
  int local_5c;
  GLint local_58;
  GLenum local_54;
  uint *local_4c [4];
  int local_3c [4];
  int local_2c [2];
  int local_24;
  int local_20 [4];
  undefined1 auVar537 [16];
  undefined1 auVar545 [16];
  undefined1 auVar553 [16];
  undefined1 auVar561 [16];
  undefined1 auVar569 [16];
  undefined1 auVar577 [16];
  undefined1 auVar585 [16];
  undefined1 auVar593 [16];
  undefined1 auVar601 [16];
  undefined1 auVar609 [16];
  undefined1 auVar617 [16];
  undefined1 auVar625 [16];
  undefined1 auVar538 [16];
  undefined1 auVar546 [16];
  undefined1 auVar554 [16];
  undefined1 auVar562 [16];
  undefined1 auVar570 [16];
  undefined1 auVar578 [16];
  undefined1 auVar586 [16];
  undefined1 auVar594 [16];
  undefined1 auVar602 [16];
  undefined1 auVar610 [16];
  undefined1 auVar618 [16];
  undefined1 auVar626 [16];
  undefined1 auVar539 [16];
  undefined1 auVar547 [16];
  undefined1 auVar555 [16];
  undefined1 auVar563 [16];
  undefined1 auVar571 [16];
  undefined1 auVar579 [16];
  undefined1 auVar587 [16];
  undefined1 auVar595 [16];
  undefined1 auVar603 [16];
  undefined1 auVar611 [16];
  undefined1 auVar619 [16];
  undefined1 auVar627 [16];
  undefined1 auVar540 [16];
  undefined1 auVar548 [16];
  undefined1 auVar556 [16];
  undefined1 auVar564 [16];
  undefined1 auVar572 [16];
  undefined1 auVar580 [16];
  undefined1 auVar588 [16];
  undefined1 auVar596 [16];
  undefined1 auVar604 [16];
  undefined1 auVar612 [16];
  undefined1 auVar620 [16];
  undefined1 auVar628 [16];
  undefined1 auVar541 [16];
  undefined1 auVar549 [16];
  undefined1 auVar557 [16];
  undefined1 auVar565 [16];
  undefined1 auVar573 [16];
  undefined1 auVar581 [16];
  undefined1 auVar589 [16];
  undefined1 auVar597 [16];
  undefined1 auVar605 [16];
  undefined1 auVar613 [16];
  undefined1 auVar621 [16];
  undefined1 auVar629 [16];
  undefined1 auVar542 [16];
  undefined1 auVar550 [16];
  undefined1 auVar558 [16];
  undefined1 auVar566 [16];
  undefined1 auVar574 [16];
  undefined1 auVar582 [16];
  undefined1 auVar590 [16];
  undefined1 auVar598 [16];
  undefined1 auVar606 [16];
  undefined1 auVar614 [16];
  undefined1 auVar622 [16];
  undefined1 auVar630 [16];
  undefined1 auVar543 [16];
  undefined1 auVar551 [16];
  undefined1 auVar559 [16];
  undefined1 auVar567 [16];
  undefined1 auVar575 [16];
  undefined1 auVar583 [16];
  undefined1 auVar591 [16];
  undefined1 auVar599 [16];
  undefined1 auVar607 [16];
  undefined1 auVar615 [16];
  undefined1 auVar623 [16];
  undefined1 auVar631 [16];
  undefined1 uVar632;
  undefined1 auVar634 [16];
  undefined1 auVar642 [16];
  undefined1 auVar650 [16];
  undefined1 auVar658 [16];
  undefined1 auVar666 [16];
  undefined1 auVar674 [16];
  undefined1 auVar682 [16];
  undefined1 auVar690 [16];
  undefined1 auVar698 [16];
  undefined1 auVar706 [16];
  undefined1 auVar714 [16];
  undefined1 auVar722 [16];
  undefined1 auVar730 [16];
  undefined1 auVar738 [16];
  undefined1 auVar746 [16];
  undefined1 auVar754 [16];
  undefined1 auVar762 [16];
  undefined1 auVar770 [16];
  undefined1 auVar778 [16];
  undefined1 auVar786 [16];
  undefined1 auVar794 [16];
  undefined1 auVar802 [16];
  undefined1 auVar810 [16];
  undefined1 auVar818 [16];
  undefined1 auVar635 [16];
  undefined1 auVar643 [16];
  undefined1 auVar651 [16];
  undefined1 auVar659 [16];
  undefined1 auVar667 [16];
  undefined1 auVar675 [16];
  undefined1 auVar683 [16];
  undefined1 auVar691 [16];
  undefined1 auVar699 [16];
  undefined1 auVar707 [16];
  undefined1 auVar715 [16];
  undefined1 auVar723 [16];
  undefined1 auVar731 [16];
  undefined1 auVar739 [16];
  undefined1 auVar747 [16];
  undefined1 auVar755 [16];
  undefined1 auVar763 [16];
  undefined1 auVar771 [16];
  undefined1 auVar779 [16];
  undefined1 auVar787 [16];
  undefined1 auVar795 [16];
  undefined1 auVar803 [16];
  undefined1 auVar811 [16];
  undefined1 auVar819 [16];
  undefined1 auVar636 [16];
  undefined1 auVar644 [16];
  undefined1 auVar652 [16];
  undefined1 auVar660 [16];
  undefined1 auVar668 [16];
  undefined1 auVar676 [16];
  undefined1 auVar684 [16];
  undefined1 auVar692 [16];
  undefined1 auVar700 [16];
  undefined1 auVar708 [16];
  undefined1 auVar716 [16];
  undefined1 auVar724 [16];
  undefined1 auVar732 [16];
  undefined1 auVar740 [16];
  undefined1 auVar748 [16];
  undefined1 auVar756 [16];
  undefined1 auVar764 [16];
  undefined1 auVar772 [16];
  undefined1 auVar780 [16];
  undefined1 auVar788 [16];
  undefined1 auVar796 [16];
  undefined1 auVar804 [16];
  undefined1 auVar812 [16];
  undefined1 auVar820 [16];
  undefined1 auVar637 [16];
  undefined1 auVar645 [16];
  undefined1 auVar653 [16];
  undefined1 auVar661 [16];
  undefined1 auVar669 [16];
  undefined1 auVar677 [16];
  undefined1 auVar685 [16];
  undefined1 auVar693 [16];
  undefined1 auVar701 [16];
  undefined1 auVar709 [16];
  undefined1 auVar717 [16];
  undefined1 auVar725 [16];
  undefined1 auVar733 [16];
  undefined1 auVar741 [16];
  undefined1 auVar749 [16];
  undefined1 auVar757 [16];
  undefined1 auVar765 [16];
  undefined1 auVar773 [16];
  undefined1 auVar781 [16];
  undefined1 auVar789 [16];
  undefined1 auVar797 [16];
  undefined1 auVar805 [16];
  undefined1 auVar813 [16];
  undefined1 auVar821 [16];
  undefined1 auVar638 [16];
  undefined1 auVar646 [16];
  undefined1 auVar654 [16];
  undefined1 auVar662 [16];
  undefined1 auVar670 [16];
  undefined1 auVar678 [16];
  undefined1 auVar686 [16];
  undefined1 auVar694 [16];
  undefined1 auVar702 [16];
  undefined1 auVar710 [16];
  undefined1 auVar718 [16];
  undefined1 auVar726 [16];
  undefined1 auVar734 [16];
  undefined1 auVar742 [16];
  undefined1 auVar750 [16];
  undefined1 auVar758 [16];
  undefined1 auVar766 [16];
  undefined1 auVar774 [16];
  undefined1 auVar782 [16];
  undefined1 auVar790 [16];
  undefined1 auVar798 [16];
  undefined1 auVar806 [16];
  undefined1 auVar814 [16];
  undefined1 auVar822 [16];
  undefined1 auVar639 [16];
  undefined1 auVar647 [16];
  undefined1 auVar655 [16];
  undefined1 auVar663 [16];
  undefined1 auVar671 [16];
  undefined1 auVar679 [16];
  undefined1 auVar687 [16];
  undefined1 auVar695 [16];
  undefined1 auVar703 [16];
  undefined1 auVar711 [16];
  undefined1 auVar719 [16];
  undefined1 auVar727 [16];
  undefined1 auVar735 [16];
  undefined1 auVar743 [16];
  undefined1 auVar751 [16];
  undefined1 auVar759 [16];
  undefined1 auVar767 [16];
  undefined1 auVar775 [16];
  undefined1 auVar783 [16];
  undefined1 auVar791 [16];
  undefined1 auVar799 [16];
  undefined1 auVar807 [16];
  undefined1 auVar815 [16];
  undefined1 auVar823 [16];
  undefined1 auVar640 [16];
  undefined1 auVar648 [16];
  undefined1 auVar656 [16];
  undefined1 auVar664 [16];
  undefined1 auVar672 [16];
  undefined1 auVar680 [16];
  undefined1 auVar688 [16];
  undefined1 auVar696 [16];
  undefined1 auVar704 [16];
  undefined1 auVar712 [16];
  undefined1 auVar720 [16];
  undefined1 auVar728 [16];
  undefined1 auVar736 [16];
  undefined1 auVar744 [16];
  undefined1 auVar752 [16];
  undefined1 auVar760 [16];
  undefined1 auVar768 [16];
  undefined1 auVar776 [16];
  undefined1 auVar784 [16];
  undefined1 auVar792 [16];
  undefined1 auVar800 [16];
  undefined1 auVar808 [16];
  undefined1 auVar816 [16];
  undefined1 auVar824 [16];
  undefined1 auVar827 [16];
  undefined1 auVar835 [16];
  undefined1 auVar843 [16];
  undefined1 auVar851 [16];
  undefined1 auVar859 [16];
  undefined1 auVar867 [16];
  undefined1 auVar875 [16];
  undefined1 auVar883 [16];
  undefined1 auVar891 [16];
  undefined1 auVar899 [16];
  undefined1 auVar907 [16];
  undefined1 auVar915 [16];
  undefined1 auVar828 [16];
  undefined1 auVar836 [16];
  undefined1 auVar844 [16];
  undefined1 auVar852 [16];
  undefined1 auVar860 [16];
  undefined1 auVar868 [16];
  undefined1 auVar876 [16];
  undefined1 auVar884 [16];
  undefined1 auVar892 [16];
  undefined1 auVar900 [16];
  undefined1 auVar908 [16];
  undefined1 auVar916 [16];
  undefined1 auVar829 [16];
  undefined1 auVar837 [16];
  undefined1 auVar845 [16];
  undefined1 auVar853 [16];
  undefined1 auVar861 [16];
  undefined1 auVar869 [16];
  undefined1 auVar877 [16];
  undefined1 auVar885 [16];
  undefined1 auVar893 [16];
  undefined1 auVar901 [16];
  undefined1 auVar909 [16];
  undefined1 auVar917 [16];
  undefined1 auVar830 [16];
  undefined1 auVar838 [16];
  undefined1 auVar846 [16];
  undefined1 auVar854 [16];
  undefined1 auVar862 [16];
  undefined1 auVar870 [16];
  undefined1 auVar878 [16];
  undefined1 auVar886 [16];
  undefined1 auVar894 [16];
  undefined1 auVar902 [16];
  undefined1 auVar910 [16];
  undefined1 auVar918 [16];
  undefined1 auVar831 [16];
  undefined1 auVar839 [16];
  undefined1 auVar847 [16];
  undefined1 auVar855 [16];
  undefined1 auVar863 [16];
  undefined1 auVar871 [16];
  undefined1 auVar879 [16];
  undefined1 auVar887 [16];
  undefined1 auVar895 [16];
  undefined1 auVar903 [16];
  undefined1 auVar911 [16];
  undefined1 auVar919 [16];
  undefined1 auVar832 [16];
  undefined1 auVar840 [16];
  undefined1 auVar848 [16];
  undefined1 auVar856 [16];
  undefined1 auVar864 [16];
  undefined1 auVar872 [16];
  undefined1 auVar880 [16];
  undefined1 auVar888 [16];
  undefined1 auVar896 [16];
  undefined1 auVar904 [16];
  undefined1 auVar912 [16];
  undefined1 auVar920 [16];
  undefined1 auVar833 [16];
  undefined1 auVar841 [16];
  undefined1 auVar849 [16];
  undefined1 auVar857 [16];
  undefined1 auVar865 [16];
  undefined1 auVar873 [16];
  undefined1 auVar881 [16];
  undefined1 auVar889 [16];
  undefined1 auVar897 [16];
  undefined1 auVar905 [16];
  undefined1 auVar913 [16];
  undefined1 auVar921 [16];
  
                    /* Unresolved local var: int iComponent@[???]
                       Unresolved local var: int iFormat@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int scaled_width@[???]
                       Unresolved local var: int scaled_height@[???]
                       Unresolved local var: qboolean f4444@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int bpp@[???] */
  bpp = local_2c;
  uVar533 = width * height;
  VideoMode_GetCurrentVideoMode(&local_24,local_20,bpp);
  giTotalTexBytes = giTotalTexBytes + uVar533;
  if (iType != 2) {
    giTotalTexBytes = width * 2 * height + giTotalTexBytes;
  }
  giTotalTextures = giTotalTextures + 1;
  if ((gl_spriteblend.value != 0.0) &&
     ((((iType == 3 || (iType == 1)) || (iType == 4)) && (0 < (int)uVar533)))) {
    uVar522 = 0;
    puVar525 = data;
    do {
      while (*puVar525 != 0) {
        uVar522 = uVar522 + 1;
        puVar525 = puVar525 + 1;
        if (uVar522 == uVar533) goto joined_r0x001b5646;
      }
      uVar534 = uVar522 + 1;
      bpp = (int *)width;
      BoxFilter3x3((uchar *)puVar525,(uchar *)data,width,height,(int)uVar522 % width,
                   (int)uVar522 / width);
      uVar522 = uVar534;
      puVar525 = puVar525 + 1;
    } while (uVar534 != uVar533);
  }
joined_r0x001b5646:
  puVar525 = (uint *)width;
  iVar521 = height;
  uVar522 = uVar533;
  if (g_bSupportsNPOTTextures == false) {
    ComputeScaledSize((int *)local_4c,local_3c,width,height);
    puVar525 = local_4c[0];
    iVar521 = local_3c[0];
    uVar522 = (int)local_4c[0] * local_3c[0];
  }
  local_3c[0] = iVar521;
  local_4c[0] = puVar525;
  if (0x80000 < uVar522) {
    Sys_Error("GL_LoadTexture: too big");
  }
  switch(iType) {
  case 0:
    local_54 = 0x1908;
    local_58 = 0x8058;
    if (local_2c[0] == 0x10) {
      local_58 = 0x8051;
    }
    break;
  case 1:
  case 3:
    local_54 = 0x1908;
    local_58 = (uint)(local_2c[0] != 0x10) * 2 + 0x8056;
    break;
  case 2:
    local_54 = 0x1909;
    local_58 = 0x8040;
    break;
  case 4:
    local_54 = 0x1908;
    local_58 = (local_2c[0] != 0x10) + 0x8057;
  }
  if (((uint *)width == local_4c[0]) && (height == local_3c[0])) {
                    /* Unresolved local var: int iNum@[???] */
    if (mipmap != false) {
      if (iType != 2) {
        uVar533 = uVar533 * 4;
      }
      Q_memcpy(GL_Upload32::scaled,data,uVar533);
      texels = texels + (int)local_4c[0] * local_3c[0];
      (*qglTexImage2D)(0xde1,0,local_58,(GLsizei)local_4c[0],local_3c[0],0,local_54,0x1401,
                       GL_Upload32::scaled);
LAB_001b58ff:
                    /* Unresolved local var: int miplevel@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uchar * out@[???] */
      local_5c = 0;
      while ((1 < (int)local_4c[0] || (1 < local_3c[0]))) {
        local_3c[0] = local_3c[0] >> 1;
        if (0 < local_3c[0]) {
          local_74 = 0;
          puVar527 = GL_Upload32::scaled;
          iVar521 = (int)local_4c[0] * 4;
          uVar533 = (iVar521 - 1U >> 3) + 1;
          puVar525 = GL_Upload32::scaled;
          do {
            puVar526 = puVar525;
            puVar529 = puVar527;
            if (0 < iVar521) {
              puVar532 = puVar527 + (int)local_4c[0];
              puVar529 = puVar527 + uVar533 * 2;
              puVar526 = puVar525 + uVar533;
              uVar522 = iVar521 - 1U >> 7;
              if ((uVar522 == 0) ||
                 (((((((((uVar533 < 0x10 || puVar525 <= puVar529 && puVar527 <= puVar526) ||
                        puVar525 <= puVar532 + uVar533 * 2 && puVar532 <= puVar526) ||
                       puVar525 <= puVar532 + 1 + uVar533 * 2 && puVar532 + 1 <= puVar526) ||
                      (uint *)((int)puVar532 + 1U) <= puVar526 &&
                      puVar525 <= (uint *)((int)puVar532 + 1U) + uVar533 * 2) ||
                     (uint *)((int)puVar532 + 5U) <= puVar526 &&
                     puVar525 <= (uint *)((int)puVar532 + 5U) + uVar533 * 2) ||
                    (uint *)((int)puVar532 + 2U) <= puVar526 &&
                    puVar525 <= (uint *)((int)puVar532 + 2U) + uVar533 * 2) ||
                   (uint *)((int)puVar532 + 6U) <= puVar526 &&
                   puVar525 <= (uint *)((int)puVar532 + 6U) + uVar533 * 2) ||
                  (uint *)((int)puVar532 + 3U) <= puVar526 &&
                  puVar525 <= (uint *)((int)puVar532 + 3U) + uVar533 * 2) ||
                  (uint *)((int)puVar532 + 7U) <= puVar526 &&
                  puVar525 <= (uint *)((int)puVar532 + 7U) + uVar533 * 2)) {
                iVar523 = 0;
              }
              else {
                iVar523 = 0;
                local_a0 = 0;
                puVar524 = puVar532;
                puVar528 = puVar532;
                puVar530 = puVar532;
                puVar531 = puVar532;
                puVar535 = puVar532;
                local_d4 = puVar532;
                local_d0 = puVar532;
                do {
                  pbVar1 = (byte *)((int)puVar527 + iVar523 * 2);
                  pbVar2 = (byte *)((int)puVar527 + iVar523 * 2 + 0x20);
                  bVar46 = *pbVar2;
                  bVar47 = pbVar2[1];
                  bVar48 = pbVar2[2];
                  bVar49 = pbVar2[3];
                  bVar50 = pbVar2[4];
                  bVar51 = pbVar2[5];
                  bVar52 = pbVar2[6];
                  bVar53 = pbVar2[7];
                  bVar54 = pbVar2[8];
                  bVar55 = pbVar2[9];
                  bVar56 = pbVar2[10];
                  bVar57 = pbVar2[0xb];
                  bVar58 = pbVar2[0xc];
                  bVar59 = pbVar2[0xd];
                  bVar60 = pbVar2[0xe];
                  bVar61 = pbVar2[0xf];
                  pbVar2 = (byte *)((int)puVar527 + iVar523 * 2 + 0x10);
                  uVar118 = *(undefined4 *)pbVar2;
                  uVar119 = *(undefined4 *)(pbVar2 + 4);
                  uVar120 = *(undefined4 *)(pbVar2 + 8);
                  uVar121 = *(undefined4 *)(pbVar2 + 0xc);
                  pauVar3 = (undefined1 (*) [12])((int)puVar527 + iVar523 * 2 + 0x30);
                  auVar228 = *pauVar3;
                  uVar534 = *(uint *)pauVar3[1];
                  local_10c = (byte)uVar118;
                  bStack_10b = (byte)((uint)uVar118 >> 8);
                  bStack_10a = (byte)((uint)uVar118 >> 0x10);
                  bStack_109 = (byte)((uint)uVar118 >> 0x18);
                  bStack_108 = (byte)uVar119;
                  bStack_107 = (byte)((uint)uVar119 >> 8);
                  bStack_106 = (byte)((uint)uVar119 >> 0x10);
                  bStack_105 = (byte)((uint)uVar119 >> 0x18);
                  uStack_104 = (undefined1)uVar120;
                  uStack_103 = (undefined1)((uint)uVar120 >> 8);
                  uStack_102 = (undefined1)((uint)uVar120 >> 0x10);
                  uStack_101 = (undefined1)((uint)uVar120 >> 0x18);
                  uStack_100 = (undefined1)uVar121;
                  uStack_ff = (undefined1)((uint)uVar121 >> 8);
                  uStack_fe = (undefined1)((uint)uVar121 >> 0x10);
                  uStack_fd = (undefined1)((uint)uVar121 >> 0x18);
                  pbVar2 = (byte *)((int)puVar527 + iVar523 * 2 + 0x40);
                  uVar118 = *(undefined4 *)pbVar2;
                  uVar119 = *(undefined4 *)(pbVar2 + 4);
                  uVar120 = *(undefined4 *)(pbVar2 + 8);
                  uVar121 = *(undefined4 *)(pbVar2 + 0xc);
                  pbVar2 = (byte *)((int)puVar527 + iVar523 * 2 + 0x50);
                  uVar122 = *(undefined4 *)pbVar2;
                  uVar123 = *(undefined4 *)(pbVar2 + 4);
                  uVar124 = *(undefined4 *)(pbVar2 + 8);
                  uVar125 = *(undefined4 *)(pbVar2 + 0xc);
                  local_14c = (byte)uVar118;
                  bStack_14b = (byte)((uint)uVar118 >> 8);
                  bStack_14a = (byte)((uint)uVar118 >> 0x10);
                  bStack_149 = (byte)((uint)uVar118 >> 0x18);
                  bStack_148 = (byte)uVar119;
                  bStack_147 = (byte)((uint)uVar119 >> 8);
                  bStack_146 = (byte)((uint)uVar119 >> 0x10);
                  bStack_145 = (byte)((uint)uVar119 >> 0x18);
                  uStack_144 = (undefined1)uVar120;
                  uStack_143 = (undefined1)((uint)uVar120 >> 8);
                  uStack_142 = (undefined1)((uint)uVar120 >> 0x10);
                  uStack_141 = (undefined1)((uint)uVar120 >> 0x18);
                  uStack_140 = (undefined1)uVar121;
                  uStack_13f = (undefined1)((uint)uVar121 >> 8);
                  uStack_13e = (undefined1)((uint)uVar121 >> 0x10);
                  uStack_13d = (undefined1)((uint)uVar121 >> 0x18);
                  local_12c = (byte)uVar122;
                  bStack_12b = (byte)((uint)uVar122 >> 8);
                  bStack_12a = (byte)((uint)uVar122 >> 0x10);
                  bStack_129 = (byte)((uint)uVar122 >> 0x18);
                  bStack_128 = (byte)uVar123;
                  bStack_127 = (byte)((uint)uVar123 >> 8);
                  bStack_126 = (byte)((uint)uVar123 >> 0x10);
                  bStack_125 = (byte)((uint)uVar123 >> 0x18);
                  uStack_124 = (undefined1)uVar124;
                  uStack_123 = (undefined1)((uint)uVar124 >> 8);
                  uStack_122 = (undefined1)((uint)uVar124 >> 0x10);
                  uStack_121 = (undefined1)((uint)uVar124 >> 0x18);
                  uStack_120 = (undefined1)uVar125;
                  uStack_11f = (undefined1)((uint)uVar125 >> 8);
                  uStack_11e = (undefined1)((uint)uVar125 >> 0x10);
                  uStack_11d = (undefined1)((uint)uVar125 >> 0x18);
                  puVar4 = (uint *)((int)puVar527 + iVar523 * 2 + 0x60);
                  uVar126 = *puVar4;
                  uVar127 = puVar4[1];
                  uVar128 = puVar4[2];
                  uVar129 = puVar4[3];
                  puVar4 = (uint *)((int)puVar527 + iVar523 * 2 + 0x70);
                  uVar130 = *puVar4;
                  uVar131 = puVar4[1];
                  uVar132 = puVar4[2];
                  uVar133 = puVar4[3];
                  local_13c = (byte)uVar126;
                  bStack_13b = (byte)(uVar126 >> 8);
                  bStack_13a = (byte)(uVar126 >> 0x10);
                  bStack_139 = (byte)(uVar126 >> 0x18);
                  bStack_138 = (byte)uVar127;
                  bStack_137 = (byte)(uVar127 >> 8);
                  bStack_136 = (byte)(uVar127 >> 0x10);
                  bStack_135 = (byte)(uVar127 >> 0x18);
                  uStack_134 = (undefined1)uVar128;
                  bStack_133 = (byte)(uVar128 >> 8);
                  uStack_114 = (undefined1)uVar132;
                  bStack_154 = auVar228[8];
                  bStack_153 = auVar228[9];
                  bStack_152 = auVar228[10];
                  bStack_151 = auVar228[0xb];
                  local_15c._0_1_ = auVar228[0];
                  bVar516 = (byte)local_15c;
                  local_15c._2_1_ = auVar228[2];
                  bVar519 = local_15c._2_1_;
                  local_15c._3_1_ = auVar228[3];
                  bVar520 = local_15c._3_1_;
                  bStack_158 = auVar228[4];
                  bStack_157 = auVar228[5];
                  bStack_156 = auVar228[6];
                  bStack_155 = auVar228[7];
                  local_15c._1_1_ = auVar228[1];
                  bVar518 = local_15c._1_1_;
                  local_15c._0_3_ = CONCAT12(bStack_133,CONCAT11(uStack_114,uStack_134));
                  uVar517 = (uint3)local_15c;
                  pbVar2 = (byte *)((int)puVar532 + iVar523 * 2);
                  bVar62 = pbVar2[8];
                  local_15c = CONCAT13(0,CONCAT12(uStack_140,(ushort)bStack_148));
                  pbVar5 = (byte *)((int)puVar532 + iVar523 * 2 + 0x10);
                  pbVar6 = (byte *)((int)puVar532 + iVar523 * 2 + 0x20);
                  bVar63 = *pbVar6;
                  bVar64 = pbVar6[8];
                  pbVar6 = (byte *)((int)puVar532 + iVar523 * 2 + 0x30);
                  bVar65 = *pbVar6;
                  bVar66 = pbVar6[8];
                  pbVar6 = (byte *)((int)puVar532 + iVar523 * 2 + 0x50);
                  pbVar7 = (byte *)((int)puVar532 + iVar523 * 2 + 0x40);
                  bVar67 = pbVar7[8];
                  pbVar8 = (byte *)((int)puVar532 + iVar523 * 2 + 0x60);
                  bVar68 = *pbVar8;
                  bVar69 = pbVar8[8];
                  puVar4 = (uint *)((int)puVar532 + iVar523 * 2 + 0x70);
                  uVar134 = *puVar4;
                  uVar135 = puVar4[2];
                  auVar9 = *(undefined1 (*) [16])(local_d0 + 1);
                  bVar75 = (byte)local_d0[5];
                  bVar70 = *(byte *)((int)local_d0 + 0x16);
                  bVar76 = (byte)local_d0[6];
                  bVar71 = *(byte *)((int)local_d0 + 0x1a);
                  bVar77 = (byte)local_d0[7];
                  bVar72 = *(byte *)((int)local_d0 + 0x1e);
                  bVar78 = (byte)local_d0[8];
                  auVar640._0_14_ = auVar9._0_14_;
                  auVar640[0xe] = auVar9[7];
                  auVar640[0xf] = *(byte *)((int)local_d0 + 0x1b);
                  auVar639._14_2_ = auVar640._14_2_;
                  auVar639._0_13_ = auVar9._0_13_;
                  auVar639[0xd] = bVar71;
                  auVar638._13_3_ = auVar639._13_3_;
                  auVar638._0_12_ = auVar9._0_12_;
                  auVar638[0xc] = auVar9[6];
                  auVar637._12_4_ = auVar638._12_4_;
                  auVar637._0_11_ = auVar9._0_11_;
                  auVar637[0xb] = *(byte *)((int)local_d0 + 0x19);
                  auVar636._11_5_ = auVar637._11_5_;
                  auVar636._0_10_ = auVar9._0_10_;
                  auVar636[10] = auVar9[5];
                  auVar635._10_6_ = auVar636._10_6_;
                  auVar635._0_9_ = auVar9._0_9_;
                  auVar635[9] = bVar76;
                  uVar632 = auVar9[4];
                  auVar634._9_7_ = auVar635._9_7_;
                  auVar634._0_8_ = auVar9._0_8_;
                  auVar634[8] = uVar632;
                  auVar171._1_8_ = auVar634._8_8_;
                  auVar171[0] = *(byte *)((int)local_d0 + 0x17);
                  auVar171._9_7_ = 0;
                  auVar170._10_6_ = 0;
                  auVar170._0_10_ = SUB1610(auVar171 << 0x38,6);
                  auVar169._11_5_ = 0;
                  auVar169._0_11_ = SUB1611(auVar170 << 0x30,5);
                  auVar168._12_4_ = 0;
                  auVar168._0_12_ = SUB1612(auVar169 << 0x28,4);
                  auVar167._13_3_ = 0;
                  auVar167._0_13_ = SUB1613(auVar168 << 0x20,3);
                  auVar633._14_2_ = 0;
                  auVar633._0_14_ = SUB1614(auVar167 << 0x18,2);
                  auVar633 = auVar633 << 0x10;
                  uVar923 = auVar9[8];
                  uVar924 = auVar9[10];
                  auVar648._0_14_ = auVar633._0_14_;
                  auVar648[0xe] = *(byte *)((int)local_d0 + 0x17);
                  auVar648[0xf] = *(byte *)((int)local_d0 + 0x1f);
                  auVar647._14_2_ = auVar648._14_2_;
                  auVar647._0_13_ = auVar633._0_13_;
                  auVar647[0xd] = auVar9[0xb];
                  auVar646._13_3_ = auVar647._13_3_;
                  auVar646._0_12_ = auVar633._0_12_;
                  auVar646[0xc] = auVar9[3];
                  auVar645._12_4_ = auVar646._12_4_;
                  auVar645._0_11_ = auVar633._0_11_;
                  auVar645[0xb] = bVar72;
                  auVar644._11_5_ = auVar645._11_5_;
                  auVar644._0_10_ = auVar633._0_10_;
                  auVar644[10] = bVar70;
                  auVar643._10_6_ = auVar644._10_6_;
                  auVar643._0_9_ = auVar633._0_9_;
                  auVar643[9] = uVar924;
                  auVar642._9_7_ = auVar643._9_7_;
                  auVar642._0_8_ = auVar633._0_8_;
                  auVar642[8] = auVar9[2];
                  auVar176._1_8_ = auVar642._8_8_;
                  auVar176[0] = *(byte *)((int)local_d0 + 0x1d);
                  auVar176._9_7_ = 0;
                  auVar175._10_6_ = 0;
                  auVar175._0_10_ = SUB1610(auVar176 << 0x38,6);
                  auVar174._11_5_ = 0;
                  auVar174._0_11_ = SUB1611(auVar175 << 0x30,5);
                  auVar173._12_4_ = 0;
                  auVar173._0_12_ = SUB1612(auVar174 << 0x28,4);
                  auVar172._13_3_ = 0;
                  auVar172._0_13_ = SUB1613(auVar173 << 0x20,3);
                  auVar641._14_2_ = 0;
                  auVar641._0_14_ = SUB1614(auVar172 << 0x18,2);
                  auVar641 = auVar641 << 0x10;
                  auVar656._0_14_ = auVar641._0_14_;
                  auVar656[0xe] = *(byte *)((int)local_d0 + 0x1d);
                  auVar656[0xf] = *(byte *)((int)local_d0 + 0x21);
                  auVar655._14_2_ = auVar656._14_2_;
                  auVar655._0_13_ = auVar641._0_13_;
                  auVar655[0xd] = *(byte *)((int)local_d0 + 0x19);
                  auVar654._13_3_ = auVar655._13_3_;
                  auVar654._0_12_ = auVar641._0_12_;
                  auVar654[0xc] = *(byte *)((int)local_d0 + 0x15);
                  auVar653._12_4_ = auVar654._12_4_;
                  auVar653._0_11_ = auVar641._0_11_;
                  auVar653[0xb] = auVar9[0xd];
                  auVar652._11_5_ = auVar653._11_5_;
                  auVar652._0_10_ = auVar641._0_10_;
                  auVar652[10] = auVar9[9];
                  auVar651._10_6_ = auVar652._10_6_;
                  auVar651._0_9_ = auVar641._0_9_;
                  auVar651[9] = auVar9[5];
                  auVar650._9_7_ = auVar651._9_7_;
                  auVar650._0_8_ = auVar641._0_8_;
                  auVar650[8] = auVar9[1];
                  auVar181._1_8_ = auVar650._8_8_;
                  auVar181[0] = bVar78;
                  auVar181._9_7_ = 0;
                  auVar180._10_6_ = 0;
                  auVar180._0_10_ = SUB1610(auVar181 << 0x38,6);
                  auVar179._11_5_ = 0;
                  auVar179._0_11_ = SUB1611(auVar180 << 0x30,5);
                  auVar178._12_4_ = 0;
                  auVar178._0_12_ = SUB1612(auVar179 << 0x28,4);
                  auVar177._13_3_ = 0;
                  auVar177._0_13_ = SUB1613(auVar178 << 0x20,3);
                  auVar649._14_2_ = 0;
                  auVar649._0_14_ = SUB1614(auVar177 << 0x18,2);
                  auVar649 = auVar649 << 0x10;
                  bVar79 = (byte)local_d0[10];
                  bVar80 = (byte)local_d0[0xb];
                  bVar81 = (byte)local_d0[0xc];
                  auVar664._0_14_ = auVar649._0_14_;
                  auVar664[0xe] = bVar78;
                  auVar664[0xf] = *(byte *)((int)local_d0 + 0x22);
                  auVar663._14_2_ = auVar664._14_2_;
                  auVar663._0_13_ = auVar649._0_13_;
                  auVar663[0xd] = bVar72;
                  auVar662._13_3_ = auVar663._13_3_;
                  auVar662._0_12_ = auVar649._0_12_;
                  auVar662[0xc] = bVar77;
                  auVar661._12_4_ = auVar662._12_4_;
                  auVar661._0_11_ = auVar649._0_11_;
                  auVar661[0xb] = bVar71;
                  auVar660._11_5_ = auVar661._11_5_;
                  auVar660._0_10_ = auVar649._0_10_;
                  auVar660[10] = bVar76;
                  auVar659._10_6_ = auVar660._10_6_;
                  auVar659._0_9_ = auVar649._0_9_;
                  auVar659[9] = bVar70;
                  auVar658._9_7_ = auVar659._9_7_;
                  auVar658._0_8_ = auVar649._0_8_;
                  auVar658[8] = bVar75;
                  auVar186._1_8_ = auVar658._8_8_;
                  auVar186[0] = auVar9[0xe];
                  auVar186._9_7_ = 0;
                  auVar185._10_6_ = 0;
                  auVar185._0_10_ = SUB1610(auVar186 << 0x38,6);
                  auVar184._11_5_ = 0;
                  auVar184._0_11_ = SUB1611(auVar185 << 0x30,5);
                  auVar183._12_4_ = 0;
                  auVar183._0_12_ = SUB1612(auVar184 << 0x28,4);
                  auVar182._13_3_ = 0;
                  auVar182._0_13_ = SUB1613(auVar183 << 0x20,3);
                  auVar657._14_2_ = 0;
                  auVar657._0_14_ = SUB1614(auVar182 << 0x18,2);
                  auVar657 = auVar657 << 0x10;
                  bVar82 = (byte)local_d0[0xe];
                  bVar83 = (byte)local_d0[0xf];
                  auVar672._0_14_ = auVar657._0_14_;
                  auVar672[0xe] = auVar9[0xe];
                  auVar672[0xf] = *(byte *)((int)local_d0 + 0x32);
                  auVar671._14_2_ = auVar672._14_2_;
                  auVar671._0_13_ = auVar657._0_13_;
                  auVar671[0xd] = bVar81;
                  auVar670._13_3_ = auVar671._13_3_;
                  auVar670._0_12_ = auVar657._0_12_;
                  auVar670[0xc] = auVar9[0xc];
                  auVar669._12_4_ = auVar670._12_4_;
                  auVar669._0_11_ = auVar657._0_11_;
                  auVar669[0xb] = *(byte *)((int)local_d0 + 0x2e);
                  auVar668._11_5_ = auVar669._11_5_;
                  auVar668._0_10_ = auVar657._0_10_;
                  auVar668[10] = uVar924;
                  auVar667._10_6_ = auVar668._10_6_;
                  auVar667._0_9_ = auVar657._0_9_;
                  auVar667[9] = bVar80;
                  auVar666._9_7_ = auVar667._9_7_;
                  auVar666._0_8_ = auVar657._0_8_;
                  auVar666[8] = uVar923;
                  auVar191._1_8_ = auVar666._8_8_;
                  auVar191[0] = *(byte *)((int)local_d0 + 0x2a);
                  auVar191._9_7_ = 0;
                  auVar190._10_6_ = 0;
                  auVar190._0_10_ = SUB1610(auVar191 << 0x38,6);
                  auVar189._11_5_ = 0;
                  auVar189._0_11_ = SUB1611(auVar190 << 0x30,5);
                  auVar188._12_4_ = 0;
                  auVar188._0_12_ = SUB1612(auVar189 << 0x28,4);
                  auVar187._13_3_ = 0;
                  auVar187._0_13_ = SUB1613(auVar188 << 0x20,3);
                  auVar665._14_2_ = 0;
                  auVar665._0_14_ = SUB1614(auVar187 << 0x18,2);
                  auVar665 = auVar665 << 0x10;
                  auVar680._0_14_ = auVar665._0_14_;
                  auVar680[0xe] = *(byte *)((int)local_d0 + 0x2a);
                  auVar680[0xf] = *(byte *)((int)local_d0 + 0x3a);
                  auVar679._14_2_ = auVar680._14_2_;
                  auVar679._0_13_ = auVar665._0_13_;
                  auVar679[0xd] = bVar71;
                  auVar678._13_3_ = auVar679._13_3_;
                  auVar678._0_12_ = auVar665._0_12_;
                  auVar678[0xc] = auVar9[6];
                  auVar677._12_4_ = auVar678._12_4_;
                  auVar677._0_11_ = auVar665._0_11_;
                  auVar677[0xb] = bVar82;
                  auVar676._11_5_ = auVar677._11_5_;
                  auVar676._0_10_ = auVar665._0_10_;
                  auVar676[10] = bVar79;
                  auVar675._10_6_ = auVar676._10_6_;
                  auVar675._0_9_ = auVar665._0_9_;
                  auVar675[9] = bVar76;
                  auVar674._9_7_ = auVar675._9_7_;
                  auVar674._0_8_ = auVar665._0_8_;
                  auVar674[8] = uVar632;
                  auVar196._1_8_ = auVar674._8_8_;
                  auVar196[0] = *(byte *)((int)local_d0 + 0x36);
                  auVar196._9_7_ = 0;
                  auVar195._10_6_ = 0;
                  auVar195._0_10_ = SUB1610(auVar196 << 0x38,6);
                  auVar194._11_5_ = 0;
                  auVar194._0_11_ = SUB1611(auVar195 << 0x30,5);
                  auVar193._12_4_ = 0;
                  auVar193._0_12_ = SUB1612(auVar194 << 0x28,4);
                  auVar192._13_3_ = 0;
                  auVar192._0_13_ = SUB1613(auVar193 << 0x20,3);
                  auVar673._14_2_ = 0;
                  auVar673._0_14_ = SUB1614(auVar192 << 0x18,2);
                  auVar673 = auVar673 << 0x10;
                  auVar688._0_14_ = auVar673._0_14_;
                  auVar688[0xe] = *(byte *)((int)local_d0 + 0x36);
                  auVar688[0xf] = *(byte *)((int)local_d0 + 0x3e);
                  auVar687._14_2_ = auVar688._14_2_;
                  auVar687._0_13_ = auVar673._0_13_;
                  auVar687[0xd] = *(byte *)((int)local_d0 + 0x2e);
                  auVar686._13_3_ = auVar687._13_3_;
                  auVar686._0_12_ = auVar673._0_12_;
                  auVar686[0xc] = *(byte *)((int)local_d0 + 0x26);
                  auVar685._12_4_ = auVar686._12_4_;
                  auVar685._0_11_ = auVar673._0_11_;
                  auVar685[0xb] = bVar72;
                  auVar684._11_5_ = auVar685._11_5_;
                  auVar684._0_10_ = auVar673._0_10_;
                  auVar684[10] = bVar70;
                  auVar683._10_6_ = auVar684._10_6_;
                  auVar683._0_9_ = auVar673._0_9_;
                  auVar683[9] = uVar924;
                  auVar682._9_7_ = auVar683._9_7_;
                  auVar682._0_8_ = auVar673._0_8_;
                  auVar682[8] = auVar9[2];
                  auVar201._1_8_ = auVar682._8_8_;
                  auVar201[0] = bVar83;
                  auVar201._9_7_ = 0;
                  auVar200._10_6_ = 0;
                  auVar200._0_10_ = SUB1610(auVar201 << 0x38,6);
                  auVar199._11_5_ = 0;
                  auVar199._0_11_ = SUB1611(auVar200 << 0x30,5);
                  auVar198._12_4_ = 0;
                  auVar198._0_12_ = SUB1612(auVar199 << 0x28,4);
                  auVar197._13_3_ = 0;
                  auVar197._0_13_ = SUB1613(auVar198 << 0x20,3);
                  auVar681._14_2_ = 0;
                  auVar681._0_14_ = SUB1614(auVar197 << 0x18,2);
                  auVar681 = auVar681 << 0x10;
                  bVar70 = (byte)local_d0[0x15];
                  bVar71 = (byte)local_d0[0x17];
                  auVar696._0_14_ = auVar681._0_14_;
                  auVar696[0xe] = bVar83;
                  auVar696[0xf] = (byte)local_d0[0x10];
                  auVar695._14_2_ = auVar696._14_2_;
                  auVar695._0_13_ = auVar681._0_13_;
                  auVar695[0xd] = bVar82;
                  auVar694._13_3_ = auVar695._13_3_;
                  auVar694._0_12_ = auVar681._0_12_;
                  auVar694[0xc] = (byte)local_d0[0xd];
                  auVar693._12_4_ = auVar694._12_4_;
                  auVar693._0_11_ = auVar681._0_11_;
                  auVar693[0xb] = bVar81;
                  auVar692._11_5_ = auVar693._11_5_;
                  auVar692._0_10_ = auVar681._0_10_;
                  auVar692[10] = bVar80;
                  auVar691._10_6_ = auVar692._10_6_;
                  auVar691._0_9_ = auVar681._0_9_;
                  auVar691[9] = bVar79;
                  auVar690._9_7_ = auVar691._9_7_;
                  auVar690._0_8_ = auVar681._0_8_;
                  auVar690[8] = (byte)local_d0[9];
                  auVar206._1_8_ = auVar690._8_8_;
                  auVar206[0] = bVar78;
                  auVar206._9_7_ = 0;
                  auVar205._10_6_ = 0;
                  auVar205._0_10_ = SUB1610(auVar206 << 0x38,6);
                  auVar204._11_5_ = 0;
                  auVar204._0_11_ = SUB1611(auVar205 << 0x30,5);
                  auVar203._12_4_ = 0;
                  auVar203._0_12_ = SUB1612(auVar204 << 0x28,4);
                  auVar202._13_3_ = 0;
                  auVar202._0_13_ = SUB1613(auVar203 << 0x20,3);
                  auVar689._14_2_ = 0;
                  auVar689._0_14_ = SUB1614(auVar202 << 0x18,2);
                  auVar689 = auVar689 << 0x10;
                  bVar72 = (byte)local_d0[0x13];
                  bVar73 = (byte)local_d0[0x19];
                  bVar74 = (byte)local_d0[0x1b];
                  uVar136 = local_d0[0x1d];
                  uVar137 = local_d0[0x1f];
                  local_9c = (undefined1)uVar136;
                  uStack_98 = (undefined1)local_d0[0x1e];
                  uStack_94 = (undefined1)uVar137;
                  auVar704._0_14_ = auVar689._0_14_;
                  auVar704[0xe] = bVar78;
                  auVar704[0xf] = (byte)local_d0[0x18];
                  auVar703._14_2_ = auVar704._14_2_;
                  auVar703._0_13_ = auVar689._0_13_;
                  auVar703[0xd] = bVar71;
                  auVar702._13_3_ = auVar703._13_3_;
                  auVar702._0_12_ = auVar689._0_12_;
                  auVar702[0xc] = bVar77;
                  auVar701._12_4_ = auVar702._12_4_;
                  auVar701._0_11_ = auVar689._0_11_;
                  auVar701[0xb] = (byte)local_d0[0x16];
                  auVar700._11_5_ = auVar701._11_5_;
                  auVar700._0_10_ = auVar689._0_10_;
                  auVar700[10] = bVar76;
                  auVar699._10_6_ = auVar700._10_6_;
                  auVar699._0_9_ = auVar689._0_9_;
                  auVar699[9] = bVar70;
                  auVar698._9_7_ = auVar699._9_7_;
                  auVar698._0_8_ = auVar689._0_8_;
                  auVar698[8] = bVar75;
                  auVar211._1_8_ = auVar698._8_8_;
                  auVar211[0] = (byte)local_d0[0x14];
                  auVar211._9_7_ = 0;
                  auVar210._10_6_ = 0;
                  auVar210._0_10_ = SUB1610(auVar211 << 0x38,6);
                  auVar209._11_5_ = 0;
                  auVar209._0_11_ = SUB1611(auVar210 << 0x30,5);
                  auVar208._12_4_ = 0;
                  auVar208._0_12_ = SUB1612(auVar209 << 0x28,4);
                  auVar207._13_3_ = 0;
                  auVar207._0_13_ = SUB1613(auVar208 << 0x20,3);
                  auVar697._14_2_ = 0;
                  auVar697._0_14_ = SUB1614(auVar207 << 0x18,2);
                  auVar697 = auVar697 << 0x10;
                  auVar712._0_14_ = auVar697._0_14_;
                  auVar712[0xe] = (byte)local_d0[0x14];
                  auVar712[0xf] = (byte)local_d0[0x1c];
                  auVar711._14_2_ = auVar712._14_2_;
                  auVar711._0_13_ = auVar697._0_13_;
                  auVar711[0xd] = bVar81;
                  auVar710._13_3_ = auVar711._13_3_;
                  auVar710._0_12_ = auVar697._0_12_;
                  auVar710[0xc] = auVar9[0xc];
                  auVar709._12_4_ = auVar710._12_4_;
                  auVar709._0_11_ = auVar697._0_11_;
                  auVar709[0xb] = bVar74;
                  auVar708._11_5_ = auVar709._11_5_;
                  auVar708._0_10_ = auVar697._0_10_;
                  auVar708[10] = bVar72;
                  auVar707._10_6_ = auVar708._10_6_;
                  auVar707._0_9_ = auVar697._0_9_;
                  auVar707[9] = bVar80;
                  auVar706._9_7_ = auVar707._9_7_;
                  auVar706._0_8_ = auVar697._0_8_;
                  auVar706[8] = uVar923;
                  auVar216._1_8_ = auVar706._8_8_;
                  auVar216[0] = (byte)local_d0[0x1a];
                  auVar216._9_7_ = 0;
                  auVar215._10_6_ = 0;
                  auVar215._0_10_ = SUB1610(auVar216 << 0x38,6);
                  auVar214._11_5_ = 0;
                  auVar214._0_11_ = SUB1611(auVar215 << 0x30,5);
                  auVar213._12_4_ = 0;
                  auVar213._0_12_ = SUB1612(auVar214 << 0x28,4);
                  auVar212._13_3_ = 0;
                  auVar212._0_13_ = SUB1613(auVar213 << 0x20,3);
                  auVar705._14_2_ = 0;
                  auVar705._0_14_ = SUB1614(auVar212 << 0x18,2);
                  auVar705 = auVar705 << 0x10;
                  auVar720._0_14_ = auVar705._0_14_;
                  auVar720[0xe] = (byte)local_d0[0x1a];
                  auVar720[0xf] = uStack_98;
                  auVar719._14_2_ = auVar720._14_2_;
                  auVar719._0_13_ = auVar705._0_13_;
                  auVar719[0xd] = (byte)local_d0[0x16];
                  auVar718._13_3_ = auVar719._13_3_;
                  auVar718._0_12_ = auVar705._0_12_;
                  auVar718[0xc] = (byte)local_d0[0x12];
                  auVar717._12_4_ = auVar718._12_4_;
                  auVar717._0_11_ = auVar705._0_11_;
                  auVar717[0xb] = bVar82;
                  auVar716._11_5_ = auVar717._11_5_;
                  auVar716._0_10_ = auVar705._0_10_;
                  auVar716[10] = bVar79;
                  auVar715._10_6_ = auVar716._10_6_;
                  auVar715._0_9_ = auVar705._0_9_;
                  auVar715[9] = bVar76;
                  auVar714._9_7_ = auVar715._9_7_;
                  auVar714._0_8_ = auVar705._0_8_;
                  auVar714[8] = uVar632;
                  auVar221._1_8_ = auVar714._8_8_;
                  auVar221[0] = local_9c;
                  auVar221._9_7_ = 0;
                  auVar220._10_6_ = 0;
                  auVar220._0_10_ = SUB1610(auVar221 << 0x38,6);
                  auVar219._11_5_ = 0;
                  auVar219._0_11_ = SUB1611(auVar220 << 0x30,5);
                  auVar218._12_4_ = 0;
                  auVar218._0_12_ = SUB1612(auVar219 << 0x28,4);
                  auVar217._13_3_ = 0;
                  auVar217._0_13_ = SUB1613(auVar218 << 0x20,3);
                  auVar713._14_2_ = 0;
                  auVar713._0_14_ = SUB1614(auVar217 << 0x18,2);
                  auVar713 = auVar713 << 0x10;
                  auVar728._0_14_ = auVar713._0_14_;
                  auVar728[0xe] = local_9c;
                  auVar728[0xf] = uStack_94;
                  auVar727._14_2_ = auVar728._14_2_;
                  auVar727._0_13_ = auVar713._0_13_;
                  auVar727[0xd] = bVar74;
                  auVar726._13_3_ = auVar727._13_3_;
                  auVar726._0_12_ = auVar713._0_12_;
                  auVar726[0xc] = bVar73;
                  auVar725._12_4_ = auVar726._12_4_;
                  auVar725._0_11_ = auVar713._0_11_;
                  auVar725[0xb] = bVar71;
                  auVar724._11_5_ = auVar725._11_5_;
                  auVar724._0_10_ = auVar713._0_10_;
                  auVar724[10] = bVar70;
                  auVar723._10_6_ = auVar724._10_6_;
                  auVar723._0_9_ = auVar713._0_9_;
                  auVar723[9] = bVar72;
                  auVar722._9_7_ = auVar723._9_7_;
                  auVar722._0_8_ = auVar713._0_8_;
                  auVar722[8] = (byte)local_d0[0x11];
                  auVar226._1_8_ = auVar722._8_8_;
                  auVar226[0] = bVar83;
                  auVar226._9_7_ = 0;
                  auVar225._10_6_ = 0;
                  auVar225._0_10_ = SUB1610(auVar226 << 0x38,6);
                  auVar224._11_5_ = 0;
                  auVar224._0_11_ = SUB1611(auVar225 << 0x30,5);
                  auVar223._12_4_ = 0;
                  auVar223._0_12_ = SUB1612(auVar224 << 0x28,4);
                  auVar222._13_3_ = 0;
                  auVar222._0_13_ = SUB1613(auVar223 << 0x20,3);
                  auVar721._14_2_ = 0;
                  auVar721._0_14_ = SUB1614(auVar222 << 0x18,2);
                  auVar721 = auVar721 << 0x10;
                  uVar142 = CONCAT13(0,CONCAT12(pbVar1[8],(ushort)*pbVar1));
                  auVar440[0xc] = uStack_104;
                  auVar440._0_12_ = ZEXT112(bVar46) << 0x40;
                  auVar441._10_3_ = auVar440._10_3_;
                  auVar441._0_10_ = (unkuint10)local_10c << 0x40;
                  auVar14[4] = pbVar1[8];
                  auVar14._0_4_ = uVar142;
                  auVar14[5] = 0;
                  auVar14._6_8_ = SUB148(ZEXT514(auVar441._8_5_) << 0x40,6);
                  uVar157 = CONCAT13(0,CONCAT12(pbVar1[0xc],(ushort)pbVar1[4]));
                  auVar442[0xc] = uStack_100;
                  auVar442._0_12_ = ZEXT112(bVar50) << 0x40;
                  auVar443._10_3_ = auVar442._10_3_;
                  auVar443._0_10_ = (unkuint10)bStack_108 << 0x40;
                  auVar15[4] = pbVar1[0xc];
                  auVar15._0_4_ = uVar157;
                  auVar15[5] = 0;
                  auVar15._6_8_ = SUB148(ZEXT514(auVar443._8_5_) << 0x40,6);
                  uVar161 = CONCAT13(0,CONCAT12(bVar62,(ushort)*pbVar2));
                  auVar444[0xc] = pbVar5[8];
                  auVar444._0_12_ = ZEXT112(bVar63) << 0x40;
                  auVar445._10_3_ = auVar444._10_3_;
                  auVar445._0_10_ = (unkuint10)*pbVar5 << 0x40;
                  auVar16[4] = bVar62;
                  auVar16._0_4_ = uVar161;
                  auVar16[5] = 0;
                  auVar16._6_8_ = SUB148(ZEXT514(auVar445._8_5_) << 0x40,6);
                  auVar432[0xd] = 0;
                  auVar432._0_13_ = auVar721._0_13_;
                  auVar432[0xe] = bVar83;
                  auVar436[0xc] = (byte)local_d0[0xd];
                  auVar436._0_12_ = auVar721._0_12_;
                  auVar436._13_2_ = auVar432._13_2_;
                  uVar446 = auVar436._12_3_;
                  auVar447[0xb] = 0;
                  auVar447._0_11_ = auVar721._0_11_;
                  auVar447._12_3_ = uVar446;
                  auVar500[10] = bVar80;
                  auVar500._0_10_ = auVar721._0_10_;
                  auVar500._11_4_ = auVar447._11_4_;
                  auVar504[9] = 0;
                  auVar504._0_9_ = auVar721._0_9_;
                  auVar504._10_5_ = auVar500._10_5_;
                  auVar508[8] = (byte)local_d0[9];
                  auVar508._0_8_ = auVar721._0_8_;
                  auVar508._9_6_ = auVar504._9_6_;
                  Var229 = CONCAT91((unkuint9)auVar508._8_7_ << 8,bVar77);
                  auVar421[10] = 0;
                  auVar421._0_10_ = Var229;
                  auVar228._1_11_ = auVar421 << 8;
                  auVar228[0] = bVar75;
                  auVar420[0xc] = 0;
                  auVar420._0_12_ = auVar228;
                  auVar227._1_13_ = auVar420 << 8;
                  auVar227[0] = uVar923;
                  auVar925[1] = 0;
                  auVar925[0] = auVar9[0];
                  auVar925._2_14_ = auVar227;
                  auVar10._10_2_ = 0;
                  auVar10._0_10_ = auVar925._0_10_;
                  auVar10._12_2_ = (short)Var229;
                  uVar512 = CONCAT42(auVar10._10_4_,auVar228._0_2_);
                  auVar230._6_8_ = 0;
                  auVar230._0_6_ = uVar512;
                  auVar17._4_2_ = auVar227._0_2_;
                  auVar17._0_4_ = auVar925._0_4_;
                  auVar17._6_8_ = SUB148(auVar230 << 0x40,6);
                  uVar153 = CONCAT13(0,CONCAT12(uStack_144,(ushort)local_14c));
                  auVar448[0xc] = uStack_124;
                  auVar448._0_12_ = ZEXT112(local_13c) << 0x40;
                  auVar449._10_3_ = auVar448._10_3_;
                  auVar449._0_10_ = (unkuint10)local_12c << 0x40;
                  auVar18[4] = uStack_144;
                  auVar18._0_4_ = uVar153;
                  auVar18[5] = 0;
                  auVar18._6_8_ = SUB148(ZEXT514(auVar449._8_5_) << 0x40,6);
                  auVar450[0xc] = uStack_120;
                  auVar450._0_12_ = ZEXT112(bStack_138) << 0x40;
                  auVar451._10_3_ = auVar450._10_3_;
                  auVar451._0_10_ = (unkuint10)bStack_128 << 0x40;
                  auVar19[4] = uStack_140;
                  auVar19._0_4_ = local_15c;
                  auVar19[5] = 0;
                  auVar19._6_8_ = SUB148(ZEXT514(auVar451._8_5_) << 0x40,6);
                  uVar164 = CONCAT13(0,CONCAT12(bVar67,(ushort)*pbVar7));
                  auVar452[0xc] = pbVar6[8];
                  auVar452._0_12_ = ZEXT112(bVar68) << 0x40;
                  auVar453._10_3_ = auVar452._10_3_;
                  auVar453._0_10_ = (unkuint10)*pbVar6 << 0x40;
                  auVar20[4] = bVar67;
                  auVar20._0_4_ = uVar164;
                  auVar20[5] = 0;
                  auVar20._6_8_ = SUB148(ZEXT514(auVar453._8_5_) << 0x40,6);
                  uVar166 = CONCAT13(0,CONCAT12(bVar72,(ushort)(byte)local_d0[0x11]));
                  auVar454[0xc] = bVar71;
                  auVar454._0_12_ = ZEXT112(bVar73) << 0x40;
                  auVar455._10_3_ = auVar454._10_3_;
                  auVar455._0_10_ = (unkuint10)bVar70 << 0x40;
                  auVar21[4] = bVar72;
                  auVar21._0_4_ = uVar166;
                  auVar21[5] = 0;
                  auVar21._6_8_ = SUB148(ZEXT514(auVar455._8_5_) << 0x40,6);
                  bVar62 = *(byte *)((int)local_d4 + 0x21);
                  bVar67 = *(byte *)((int)local_d4 + 0x29);
                  bVar75 = *(byte *)((int)local_d4 + 0x31);
                  bVar70 = *(byte *)((int)local_d4 + 0x39);
                  bVar76 = *(byte *)((int)local_d4 + 0x61);
                  bVar71 = *(byte *)((int)local_d4 + 0x69);
                  bVar77 = *(byte *)((int)local_d4 + 0x71);
                  bVar72 = *(byte *)((int)local_d4 + 0x79);
                  bVar78 = *(byte *)((int)puVar528 + 0x15);
                  bVar79 = *(byte *)((int)puVar528 + 0x17);
                  bVar80 = *(byte *)((int)puVar528 + 0x19);
                  bVar81 = *(byte *)((int)puVar528 + 0x1b);
                  bVar82 = *(byte *)((int)puVar528 + 0x1d);
                  bVar83 = *(byte *)((int)puVar528 + 0x1f);
                  bVar84 = *(byte *)((int)puVar528 + 0x21);
                  auVar9 = *(undefined1 (*) [16])((int)puVar528 + 5);
                  auVar736._0_14_ = auVar9._0_14_;
                  auVar736[0xe] = auVar9[7];
                  auVar736[0xf] = (byte)puVar528[7];
                  auVar735._14_2_ = auVar736._14_2_;
                  auVar735._0_13_ = auVar9._0_13_;
                  auVar735[0xd] = bVar81;
                  auVar734._13_3_ = auVar735._13_3_;
                  auVar734._0_12_ = auVar9._0_12_;
                  auVar734[0xc] = auVar9[6];
                  auVar733._12_4_ = auVar734._12_4_;
                  auVar733._0_11_ = auVar9._0_11_;
                  auVar733[0xb] = *(byte *)((int)puVar528 + 0x1a);
                  auVar732._11_5_ = auVar733._11_5_;
                  auVar732._0_10_ = auVar9._0_10_;
                  auVar732[10] = auVar9[5];
                  auVar731._10_6_ = auVar732._10_6_;
                  auVar731._0_9_ = auVar9._0_9_;
                  auVar731[9] = bVar80;
                  uVar632 = auVar9[4];
                  auVar730._9_7_ = auVar731._9_7_;
                  auVar730._0_8_ = auVar9._0_8_;
                  auVar730[8] = uVar632;
                  auVar235._1_8_ = auVar730._8_8_;
                  auVar235[0] = (byte)puVar528[6];
                  auVar235._9_7_ = 0;
                  auVar234._10_6_ = 0;
                  auVar234._0_10_ = SUB1610(auVar235 << 0x38,6);
                  auVar233._11_5_ = 0;
                  auVar233._0_11_ = SUB1611(auVar234 << 0x30,5);
                  auVar232._12_4_ = 0;
                  auVar232._0_12_ = SUB1612(auVar233 << 0x28,4);
                  auVar231._13_3_ = 0;
                  auVar231._0_13_ = SUB1613(auVar232 << 0x20,3);
                  auVar729._14_2_ = 0;
                  auVar729._0_14_ = SUB1614(auVar231 << 0x18,2);
                  auVar729 = auVar729 << 0x10;
                  uVar923 = auVar9[8];
                  uVar924 = auVar9[10];
                  auVar744._0_14_ = auVar729._0_14_;
                  auVar744[0xe] = (byte)puVar528[6];
                  auVar744[0xf] = (byte)puVar528[8];
                  auVar743._14_2_ = auVar744._14_2_;
                  auVar743._0_13_ = auVar729._0_13_;
                  auVar743[0xd] = auVar9[0xb];
                  auVar742._13_3_ = auVar743._13_3_;
                  auVar742._0_12_ = auVar729._0_12_;
                  auVar742[0xc] = auVar9[3];
                  auVar741._12_4_ = auVar742._12_4_;
                  auVar741._0_11_ = auVar729._0_11_;
                  auVar741[0xb] = bVar83;
                  auVar740._11_5_ = auVar741._11_5_;
                  auVar740._0_10_ = auVar729._0_10_;
                  auVar740[10] = bVar79;
                  auVar739._10_6_ = auVar740._10_6_;
                  auVar739._0_9_ = auVar729._0_9_;
                  auVar739[9] = uVar924;
                  auVar738._9_7_ = auVar739._9_7_;
                  auVar738._0_8_ = auVar729._0_8_;
                  auVar738[8] = auVar9[2];
                  auVar240._1_8_ = auVar738._8_8_;
                  auVar240[0] = *(byte *)((int)puVar528 + 0x1e);
                  auVar240._9_7_ = 0;
                  auVar239._10_6_ = 0;
                  auVar239._0_10_ = SUB1610(auVar240 << 0x38,6);
                  auVar238._11_5_ = 0;
                  auVar238._0_11_ = SUB1611(auVar239 << 0x30,5);
                  auVar237._12_4_ = 0;
                  auVar237._0_12_ = SUB1612(auVar238 << 0x28,4);
                  auVar236._13_3_ = 0;
                  auVar236._0_13_ = SUB1613(auVar237 << 0x20,3);
                  auVar737._14_2_ = 0;
                  auVar737._0_14_ = SUB1614(auVar236 << 0x18,2);
                  auVar737 = auVar737 << 0x10;
                  auVar752._0_14_ = auVar737._0_14_;
                  auVar752[0xe] = *(byte *)((int)puVar528 + 0x1e);
                  auVar752[0xf] = *(byte *)((int)puVar528 + 0x22);
                  auVar751._14_2_ = auVar752._14_2_;
                  auVar751._0_13_ = auVar737._0_13_;
                  auVar751[0xd] = *(byte *)((int)puVar528 + 0x1a);
                  auVar750._13_3_ = auVar751._13_3_;
                  auVar750._0_12_ = auVar737._0_12_;
                  auVar750[0xc] = *(byte *)((int)puVar528 + 0x16);
                  auVar749._12_4_ = auVar750._12_4_;
                  auVar749._0_11_ = auVar737._0_11_;
                  auVar749[0xb] = auVar9[0xd];
                  auVar748._11_5_ = auVar749._11_5_;
                  auVar748._0_10_ = auVar737._0_10_;
                  auVar748[10] = auVar9[9];
                  auVar747._10_6_ = auVar748._10_6_;
                  auVar747._0_9_ = auVar737._0_9_;
                  auVar747[9] = auVar9[5];
                  auVar746._9_7_ = auVar747._9_7_;
                  auVar746._0_8_ = auVar737._0_8_;
                  auVar746[8] = auVar9[1];
                  auVar245._1_8_ = auVar746._8_8_;
                  auVar245[0] = bVar84;
                  auVar245._9_7_ = 0;
                  auVar244._10_6_ = 0;
                  auVar244._0_10_ = SUB1610(auVar245 << 0x38,6);
                  auVar243._11_5_ = 0;
                  auVar243._0_11_ = SUB1611(auVar244 << 0x30,5);
                  auVar242._12_4_ = 0;
                  auVar242._0_12_ = SUB1612(auVar243 << 0x28,4);
                  auVar241._13_3_ = 0;
                  auVar241._0_13_ = SUB1613(auVar242 << 0x20,3);
                  auVar745._14_2_ = 0;
                  auVar745._0_14_ = SUB1614(auVar241 << 0x18,2);
                  auVar745 = auVar745 << 0x10;
                  bVar85 = *(byte *)((int)puVar528 + 0x29);
                  bVar86 = *(byte *)((int)puVar528 + 0x2d);
                  bVar87 = *(byte *)((int)puVar528 + 0x31);
                  auVar760._0_14_ = auVar745._0_14_;
                  auVar760[0xe] = bVar84;
                  auVar760[0xf] = *(byte *)((int)puVar528 + 0x23);
                  auVar759._14_2_ = auVar760._14_2_;
                  auVar759._0_13_ = auVar745._0_13_;
                  auVar759[0xd] = bVar83;
                  auVar758._13_3_ = auVar759._13_3_;
                  auVar758._0_12_ = auVar745._0_12_;
                  auVar758[0xc] = bVar82;
                  auVar757._12_4_ = auVar758._12_4_;
                  auVar757._0_11_ = auVar745._0_11_;
                  auVar757[0xb] = bVar81;
                  auVar756._11_5_ = auVar757._11_5_;
                  auVar756._0_10_ = auVar745._0_10_;
                  auVar756[10] = bVar80;
                  auVar755._10_6_ = auVar756._10_6_;
                  auVar755._0_9_ = auVar745._0_9_;
                  auVar755[9] = bVar79;
                  auVar754._9_7_ = auVar755._9_7_;
                  auVar754._0_8_ = auVar745._0_8_;
                  auVar754[8] = bVar78;
                  auVar250._1_8_ = auVar754._8_8_;
                  auVar250[0] = auVar9[0xe];
                  auVar250._9_7_ = 0;
                  auVar249._10_6_ = 0;
                  auVar249._0_10_ = SUB1610(auVar250 << 0x38,6);
                  auVar248._11_5_ = 0;
                  auVar248._0_11_ = SUB1611(auVar249 << 0x30,5);
                  auVar247._12_4_ = 0;
                  auVar247._0_12_ = SUB1612(auVar248 << 0x28,4);
                  auVar246._13_3_ = 0;
                  auVar246._0_13_ = SUB1613(auVar247 << 0x20,3);
                  auVar753._14_2_ = 0;
                  auVar753._0_14_ = SUB1614(auVar246 << 0x18,2);
                  auVar753 = auVar753 << 0x10;
                  bVar88 = *(byte *)((int)puVar528 + 0x39);
                  bVar89 = *(byte *)((int)puVar528 + 0x3d);
                  auVar768._0_14_ = auVar753._0_14_;
                  auVar768[0xe] = auVar9[0xe];
                  auVar768[0xf] = *(byte *)((int)puVar528 + 0x33);
                  auVar767._14_2_ = auVar768._14_2_;
                  auVar767._0_13_ = auVar753._0_13_;
                  auVar767[0xd] = bVar87;
                  auVar766._13_3_ = auVar767._13_3_;
                  auVar766._0_12_ = auVar753._0_12_;
                  auVar766[0xc] = auVar9[0xc];
                  auVar765._12_4_ = auVar766._12_4_;
                  auVar765._0_11_ = auVar753._0_11_;
                  auVar765[0xb] = *(byte *)((int)puVar528 + 0x2f);
                  auVar764._11_5_ = auVar765._11_5_;
                  auVar764._0_10_ = auVar753._0_10_;
                  auVar764[10] = uVar924;
                  auVar763._10_6_ = auVar764._10_6_;
                  auVar763._0_9_ = auVar753._0_9_;
                  auVar763[9] = bVar86;
                  auVar762._9_7_ = auVar763._9_7_;
                  auVar762._0_8_ = auVar753._0_8_;
                  auVar762[8] = uVar923;
                  auVar255._1_8_ = auVar762._8_8_;
                  auVar255[0] = *(byte *)((int)puVar528 + 0x2b);
                  auVar255._9_7_ = 0;
                  auVar254._10_6_ = 0;
                  auVar254._0_10_ = SUB1610(auVar255 << 0x38,6);
                  auVar253._11_5_ = 0;
                  auVar253._0_11_ = SUB1611(auVar254 << 0x30,5);
                  auVar252._12_4_ = 0;
                  auVar252._0_12_ = SUB1612(auVar253 << 0x28,4);
                  auVar251._13_3_ = 0;
                  auVar251._0_13_ = SUB1613(auVar252 << 0x20,3);
                  auVar761._14_2_ = 0;
                  auVar761._0_14_ = SUB1614(auVar251 << 0x18,2);
                  auVar761 = auVar761 << 0x10;
                  auVar776._0_14_ = auVar761._0_14_;
                  auVar776[0xe] = *(byte *)((int)puVar528 + 0x2b);
                  auVar776[0xf] = *(byte *)((int)puVar528 + 0x3b);
                  auVar775._14_2_ = auVar776._14_2_;
                  auVar775._0_13_ = auVar761._0_13_;
                  auVar775[0xd] = bVar81;
                  auVar774._13_3_ = auVar775._13_3_;
                  auVar774._0_12_ = auVar761._0_12_;
                  auVar774[0xc] = auVar9[6];
                  auVar773._12_4_ = auVar774._12_4_;
                  auVar773._0_11_ = auVar761._0_11_;
                  auVar773[0xb] = bVar88;
                  auVar772._11_5_ = auVar773._11_5_;
                  auVar772._0_10_ = auVar761._0_10_;
                  auVar772[10] = bVar85;
                  auVar771._10_6_ = auVar772._10_6_;
                  auVar771._0_9_ = auVar761._0_9_;
                  auVar771[9] = bVar80;
                  auVar770._9_7_ = auVar771._9_7_;
                  auVar770._0_8_ = auVar761._0_8_;
                  auVar770[8] = uVar632;
                  auVar260._1_8_ = auVar770._8_8_;
                  auVar260[0] = *(byte *)((int)puVar528 + 0x37);
                  auVar260._9_7_ = 0;
                  auVar259._10_6_ = 0;
                  auVar259._0_10_ = SUB1610(auVar260 << 0x38,6);
                  auVar258._11_5_ = 0;
                  auVar258._0_11_ = SUB1611(auVar259 << 0x30,5);
                  auVar257._12_4_ = 0;
                  auVar257._0_12_ = SUB1612(auVar258 << 0x28,4);
                  auVar256._13_3_ = 0;
                  auVar256._0_13_ = SUB1613(auVar257 << 0x20,3);
                  auVar769._14_2_ = 0;
                  auVar769._0_14_ = SUB1614(auVar256 << 0x18,2);
                  auVar769 = auVar769 << 0x10;
                  auVar784._0_14_ = auVar769._0_14_;
                  auVar784[0xe] = *(byte *)((int)puVar528 + 0x37);
                  auVar784[0xf] = *(byte *)((int)puVar528 + 0x3f);
                  auVar783._14_2_ = auVar784._14_2_;
                  auVar783._0_13_ = auVar769._0_13_;
                  auVar783[0xd] = *(byte *)((int)puVar528 + 0x2f);
                  auVar782._13_3_ = auVar783._13_3_;
                  auVar782._0_12_ = auVar769._0_12_;
                  auVar782[0xc] = *(byte *)((int)puVar528 + 0x27);
                  auVar781._12_4_ = auVar782._12_4_;
                  auVar781._0_11_ = auVar769._0_11_;
                  auVar781[0xb] = bVar83;
                  auVar780._11_5_ = auVar781._11_5_;
                  auVar780._0_10_ = auVar769._0_10_;
                  auVar780[10] = bVar79;
                  auVar779._10_6_ = auVar780._10_6_;
                  auVar779._0_9_ = auVar769._0_9_;
                  auVar779[9] = uVar924;
                  auVar778._9_7_ = auVar779._9_7_;
                  auVar778._0_8_ = auVar769._0_8_;
                  auVar778[8] = auVar9[2];
                  auVar265._1_8_ = auVar778._8_8_;
                  auVar265[0] = bVar89;
                  auVar265._9_7_ = 0;
                  auVar264._10_6_ = 0;
                  auVar264._0_10_ = SUB1610(auVar265 << 0x38,6);
                  auVar263._11_5_ = 0;
                  auVar263._0_11_ = SUB1611(auVar264 << 0x30,5);
                  auVar262._12_4_ = 0;
                  auVar262._0_12_ = SUB1612(auVar263 << 0x28,4);
                  auVar261._13_3_ = 0;
                  auVar261._0_13_ = SUB1613(auVar262 << 0x20,3);
                  auVar777._14_2_ = 0;
                  auVar777._0_14_ = SUB1614(auVar261 << 0x18,2);
                  auVar777 = auVar777 << 0x10;
                  bVar79 = *(byte *)((int)puVar528 + 0x55);
                  bVar81 = *(byte *)((int)puVar528 + 0x5d);
                  auVar792._0_14_ = auVar777._0_14_;
                  auVar792[0xe] = bVar89;
                  auVar792[0xf] = *(byte *)((int)puVar528 + 0x41);
                  auVar791._14_2_ = auVar792._14_2_;
                  auVar791._0_13_ = auVar777._0_13_;
                  auVar791[0xd] = bVar88;
                  auVar790._13_3_ = auVar791._13_3_;
                  auVar790._0_12_ = auVar777._0_12_;
                  auVar790[0xc] = *(byte *)((int)puVar528 + 0x35);
                  auVar789._12_4_ = auVar790._12_4_;
                  auVar789._0_11_ = auVar777._0_11_;
                  auVar789[0xb] = bVar87;
                  auVar788._11_5_ = auVar789._11_5_;
                  auVar788._0_10_ = auVar777._0_10_;
                  auVar788[10] = bVar86;
                  auVar787._10_6_ = auVar788._10_6_;
                  auVar787._0_9_ = auVar777._0_9_;
                  auVar787[9] = bVar85;
                  auVar786._9_7_ = auVar787._9_7_;
                  auVar786._0_8_ = auVar777._0_8_;
                  auVar786[8] = *(byte *)((int)puVar528 + 0x25);
                  auVar270._1_8_ = auVar786._8_8_;
                  auVar270[0] = bVar84;
                  auVar270._9_7_ = 0;
                  auVar269._10_6_ = 0;
                  auVar269._0_10_ = SUB1610(auVar270 << 0x38,6);
                  auVar268._11_5_ = 0;
                  auVar268._0_11_ = SUB1611(auVar269 << 0x30,5);
                  auVar267._12_4_ = 0;
                  auVar267._0_12_ = SUB1612(auVar268 << 0x28,4);
                  auVar266._13_3_ = 0;
                  auVar266._0_13_ = SUB1613(auVar267 << 0x20,3);
                  auVar785._14_2_ = 0;
                  auVar785._0_14_ = SUB1614(auVar266 << 0x18,2);
                  auVar785 = auVar785 << 0x10;
                  bVar83 = *(byte *)((int)puVar528 + 0x45);
                  bVar90 = *(byte *)((int)puVar528 + 0x4d);
                  bVar91 = *(byte *)((int)puVar528 + 0x65);
                  bVar92 = *(byte *)((int)puVar528 + 0x6d);
                  bVar93 = *(byte *)((int)puVar528 + 0x75);
                  bVar94 = *(byte *)((int)puVar528 + 0x7d);
                  uVar143 = CONCAT13(0,CONCAT12(pbVar1[9],(ushort)pbVar1[1]));
                  auVar800._0_14_ = auVar785._0_14_;
                  auVar800[0xe] = bVar84;
                  auVar800[0xf] = *(byte *)((int)puVar528 + 0x61);
                  auVar799._14_2_ = auVar800._14_2_;
                  auVar799._0_13_ = auVar785._0_13_;
                  auVar799[0xd] = bVar81;
                  auVar798._13_3_ = auVar799._13_3_;
                  auVar798._0_12_ = auVar785._0_12_;
                  auVar798[0xc] = bVar82;
                  auVar797._12_4_ = auVar798._12_4_;
                  auVar797._0_11_ = auVar785._0_11_;
                  auVar797[0xb] = *(byte *)((int)puVar528 + 0x59);
                  auVar796._11_5_ = auVar797._11_5_;
                  auVar796._0_10_ = auVar785._0_10_;
                  auVar796[10] = bVar80;
                  auVar795._10_6_ = auVar796._10_6_;
                  auVar795._0_9_ = auVar785._0_9_;
                  auVar795[9] = bVar79;
                  auVar794._9_7_ = auVar795._9_7_;
                  auVar794._0_8_ = auVar785._0_8_;
                  auVar794[8] = bVar78;
                  auVar275._1_8_ = auVar794._8_8_;
                  auVar275[0] = *(byte *)((int)puVar528 + 0x51);
                  auVar275._9_7_ = 0;
                  auVar274._10_6_ = 0;
                  auVar274._0_10_ = SUB1610(auVar275 << 0x38,6);
                  auVar273._11_5_ = 0;
                  auVar273._0_11_ = SUB1611(auVar274 << 0x30,5);
                  auVar272._12_4_ = 0;
                  auVar272._0_12_ = SUB1612(auVar273 << 0x28,4);
                  auVar271._13_3_ = 0;
                  auVar271._0_13_ = SUB1613(auVar272 << 0x20,3);
                  auVar793._14_2_ = 0;
                  auVar793._0_14_ = SUB1614(auVar271 << 0x18,2);
                  auVar793 = auVar793 << 0x10;
                  auVar456[0xc] = uStack_103;
                  auVar456._0_12_ = ZEXT112(bVar47) << 0x40;
                  auVar457._10_3_ = auVar456._10_3_;
                  auVar457._0_10_ = (unkuint10)bStack_10b << 0x40;
                  auVar22[4] = pbVar1[9];
                  auVar22._0_4_ = uVar143;
                  auVar22[5] = 0;
                  auVar22._6_8_ = SUB148(ZEXT514(auVar457._8_5_) << 0x40,6);
                  auVar808._0_14_ = auVar793._0_14_;
                  auVar808[0xe] = *(byte *)((int)puVar528 + 0x51);
                  auVar808[0xf] = *(byte *)((int)puVar528 + 0x71);
                  auVar807._14_2_ = auVar808._14_2_;
                  auVar807._0_13_ = auVar793._0_13_;
                  auVar807[0xd] = bVar87;
                  auVar806._13_3_ = auVar807._13_3_;
                  auVar806._0_12_ = auVar793._0_12_;
                  auVar806[0xc] = auVar9[0xc];
                  auVar805._12_4_ = auVar806._12_4_;
                  auVar805._0_11_ = auVar793._0_11_;
                  auVar805[0xb] = bVar92;
                  auVar804._11_5_ = auVar805._11_5_;
                  auVar804._0_10_ = auVar793._0_10_;
                  auVar804[10] = bVar90;
                  auVar803._10_6_ = auVar804._10_6_;
                  auVar803._0_9_ = auVar793._0_9_;
                  auVar803[9] = bVar86;
                  auVar802._9_7_ = auVar803._9_7_;
                  auVar802._0_8_ = auVar793._0_8_;
                  auVar802[8] = uVar923;
                  auVar280._1_8_ = auVar802._8_8_;
                  auVar280[0] = *(byte *)((int)puVar528 + 0x69);
                  auVar280._9_7_ = 0;
                  auVar279._10_6_ = 0;
                  auVar279._0_10_ = SUB1610(auVar280 << 0x38,6);
                  auVar278._11_5_ = 0;
                  auVar278._0_11_ = SUB1611(auVar279 << 0x30,5);
                  auVar277._12_4_ = 0;
                  auVar277._0_12_ = SUB1612(auVar278 << 0x28,4);
                  auVar276._13_3_ = 0;
                  auVar276._0_13_ = SUB1613(auVar277 << 0x20,3);
                  auVar801._14_2_ = 0;
                  auVar801._0_14_ = SUB1614(auVar276 << 0x18,2);
                  auVar801 = auVar801 << 0x10;
                  auVar816._0_14_ = auVar801._0_14_;
                  auVar816[0xe] = *(byte *)((int)puVar528 + 0x69);
                  auVar816[0xf] = *(byte *)((int)puVar528 + 0x79);
                  auVar815._14_2_ = auVar816._14_2_;
                  auVar815._0_13_ = auVar801._0_13_;
                  auVar815[0xd] = *(byte *)((int)puVar528 + 0x59);
                  auVar814._13_3_ = auVar815._13_3_;
                  auVar814._0_12_ = auVar801._0_12_;
                  auVar814[0xc] = *(byte *)((int)puVar528 + 0x49);
                  auVar813._12_4_ = auVar814._12_4_;
                  auVar813._0_11_ = auVar801._0_11_;
                  auVar813[0xb] = bVar88;
                  auVar812._11_5_ = auVar813._11_5_;
                  auVar812._0_10_ = auVar801._0_10_;
                  auVar812[10] = bVar85;
                  auVar811._10_6_ = auVar812._10_6_;
                  auVar811._0_9_ = auVar801._0_9_;
                  auVar811[9] = bVar80;
                  auVar810._9_7_ = auVar811._9_7_;
                  auVar810._0_8_ = auVar801._0_8_;
                  auVar810[8] = uVar632;
                  auVar285._1_8_ = auVar810._8_8_;
                  auVar285[0] = bVar93;
                  auVar285._9_7_ = 0;
                  auVar284._10_6_ = 0;
                  auVar284._0_10_ = SUB1610(auVar285 << 0x38,6);
                  auVar283._11_5_ = 0;
                  auVar283._0_11_ = SUB1611(auVar284 << 0x30,5);
                  auVar282._12_4_ = 0;
                  auVar282._0_12_ = SUB1612(auVar283 << 0x28,4);
                  auVar281._13_3_ = 0;
                  auVar281._0_13_ = SUB1613(auVar282 << 0x20,3);
                  auVar809._14_2_ = 0;
                  auVar809._0_14_ = SUB1614(auVar281 << 0x18,2);
                  auVar809 = auVar809 << 0x10;
                  auVar824._0_14_ = auVar809._0_14_;
                  auVar824[0xe] = bVar93;
                  auVar824[0xf] = bVar94;
                  auVar823._14_2_ = auVar824._14_2_;
                  auVar823._0_13_ = auVar809._0_13_;
                  auVar823[0xd] = bVar92;
                  auVar822._13_3_ = auVar823._13_3_;
                  auVar822._0_12_ = auVar809._0_12_;
                  auVar822[0xc] = bVar91;
                  auVar821._12_4_ = auVar822._12_4_;
                  auVar821._0_11_ = auVar809._0_11_;
                  auVar821[0xb] = bVar81;
                  auVar820._11_5_ = auVar821._11_5_;
                  auVar820._0_10_ = auVar809._0_10_;
                  auVar820[10] = bVar79;
                  auVar819._10_6_ = auVar820._10_6_;
                  auVar819._0_9_ = auVar809._0_9_;
                  auVar819[9] = bVar90;
                  auVar818._9_7_ = auVar819._9_7_;
                  auVar818._0_8_ = auVar809._0_8_;
                  auVar818[8] = bVar83;
                  auVar290._1_8_ = auVar818._8_8_;
                  auVar290[0] = bVar89;
                  auVar290._9_7_ = 0;
                  auVar289._10_6_ = 0;
                  auVar289._0_10_ = SUB1610(auVar290 << 0x38,6);
                  auVar288._11_5_ = 0;
                  auVar288._0_11_ = SUB1611(auVar289 << 0x30,5);
                  auVar287._12_4_ = 0;
                  auVar287._0_12_ = SUB1612(auVar288 << 0x28,4);
                  auVar286._13_3_ = 0;
                  auVar286._0_13_ = SUB1613(auVar287 << 0x20,3);
                  auVar817._14_2_ = 0;
                  auVar817._0_14_ = SUB1614(auVar286 << 0x18,2);
                  auVar817 = auVar817 << 0x10;
                  uVar158 = CONCAT13(0,CONCAT12(pbVar1[0xd],(ushort)pbVar1[5]));
                  auVar458[0xc] = uStack_ff;
                  auVar458._0_12_ = ZEXT112(bVar51) << 0x40;
                  auVar459._10_3_ = auVar458._10_3_;
                  auVar459._0_10_ = (unkuint10)bStack_107 << 0x40;
                  auVar23[4] = pbVar1[0xd];
                  auVar23._0_4_ = uVar158;
                  auVar23[5] = 0;
                  auVar23._6_8_ = SUB148(ZEXT514(auVar459._8_5_) << 0x40,6);
                  uVar162 = CONCAT13(0,CONCAT12(*(byte *)((int)local_d4 + 9),
                                                (ushort)*(byte *)((int)local_d4 + 1)));
                  auVar460[0xc] = *(byte *)((int)local_d4 + 0x19);
                  auVar460._0_12_ = ZEXT112(bVar62) << 0x40;
                  auVar461._10_3_ = auVar460._10_3_;
                  auVar461._0_10_ = (unkuint10)*(byte *)((int)local_d4 + 0x11) << 0x40;
                  auVar24[4] = *(byte *)((int)local_d4 + 9);
                  auVar24._0_4_ = uVar162;
                  auVar24[5] = 0;
                  auVar24._6_8_ = SUB148(ZEXT514(auVar461._8_5_) << 0x40,6);
                  auVar433[0xd] = 0;
                  auVar433._0_13_ = auVar817._0_13_;
                  auVar433[0xe] = bVar89;
                  auVar437[0xc] = *(byte *)((int)puVar528 + 0x35);
                  auVar437._0_12_ = auVar817._0_12_;
                  auVar437._13_2_ = auVar433._13_2_;
                  uVar462 = auVar437._12_3_;
                  auVar463[0xb] = 0;
                  auVar463._0_11_ = auVar817._0_11_;
                  auVar463._12_3_ = uVar462;
                  auVar501[10] = bVar86;
                  auVar501._0_10_ = auVar817._0_10_;
                  auVar501._11_4_ = auVar463._11_4_;
                  auVar505[9] = 0;
                  auVar505._0_9_ = auVar817._0_9_;
                  auVar505._10_5_ = auVar501._10_5_;
                  auVar509[8] = *(byte *)((int)puVar528 + 0x25);
                  auVar509._0_8_ = auVar817._0_8_;
                  auVar509._9_6_ = auVar505._9_6_;
                  Var229 = CONCAT91((unkuint9)auVar509._8_7_ << 8,bVar82);
                  auVar423[10] = 0;
                  auVar423._0_10_ = Var229;
                  auVar292._1_11_ = auVar423 << 8;
                  auVar292[0] = bVar78;
                  auVar422[0xc] = 0;
                  auVar422._0_12_ = auVar292;
                  auVar291._1_13_ = auVar422 << 8;
                  auVar291[0] = uVar923;
                  auVar825[1] = 0;
                  auVar825[0] = auVar9[0];
                  auVar825._2_14_ = auVar291;
                  auVar11._10_2_ = 0;
                  auVar11._0_10_ = auVar825._0_10_;
                  auVar11._12_2_ = (short)Var229;
                  uVar513 = CONCAT42(auVar11._10_4_,auVar292._0_2_);
                  auVar293._6_8_ = 0;
                  auVar293._0_6_ = uVar513;
                  auVar25._4_2_ = auVar291._0_2_;
                  auVar25._0_4_ = auVar825._0_4_;
                  auVar25._6_8_ = SUB148(auVar293 << 0x40,6);
                  uVar147 = CONCAT13(0,CONCAT12(uStack_13f,(ushort)bStack_147));
                  auVar464[0xc] = uStack_11f;
                  auVar464._0_12_ = ZEXT112(bStack_137) << 0x40;
                  auVar465._10_3_ = auVar464._10_3_;
                  auVar465._0_10_ = (unkuint10)bStack_127 << 0x40;
                  auVar26[4] = uStack_13f;
                  auVar26._0_4_ = uVar147;
                  auVar26[5] = 0;
                  auVar26._6_8_ = SUB148(ZEXT514(auVar465._8_5_) << 0x40,6);
                  uVar154 = CONCAT13(0,CONCAT12(uStack_143,(ushort)bStack_14b));
                  auVar466[0xc] = uStack_123;
                  auVar466._0_12_ = ZEXT112(bStack_13b) << 0x40;
                  auVar467._10_3_ = auVar466._10_3_;
                  auVar467._0_10_ = (unkuint10)bStack_12b << 0x40;
                  auVar27[4] = uStack_143;
                  auVar27._0_4_ = uVar154;
                  auVar27[5] = 0;
                  auVar27._6_8_ = SUB148(ZEXT514(auVar467._8_5_) << 0x40,6);
                  uVar165 = CONCAT13(0,CONCAT12(*(byte *)((int)local_d4 + 0x49),
                                                (ushort)*(byte *)((int)local_d4 + 0x41)));
                  auVar468[0xc] = *(byte *)((int)local_d4 + 0x59);
                  auVar468._0_12_ = ZEXT112(bVar76) << 0x40;
                  auVar469._10_3_ = auVar468._10_3_;
                  auVar469._0_10_ = (unkuint10)*(byte *)((int)local_d4 + 0x51) << 0x40;
                  auVar28[4] = *(byte *)((int)local_d4 + 0x49);
                  auVar28._0_4_ = uVar165;
                  auVar28[5] = 0;
                  auVar28._6_8_ = SUB148(ZEXT514(auVar469._8_5_) << 0x40,6);
                  auVar424[0xc] = bVar81;
                  auVar424._0_12_ = ZEXT112(bVar91) << 0x40;
                  auVar425._10_3_ = auVar424._10_3_;
                  auVar425._0_10_ = (unkuint10)bVar79 << 0x40;
                  auVar29._6_8_ = SUB148(ZEXT514(auVar425._8_5_) << 0x40,6);
                  auVar29._0_6_ = (uint6)bVar90 << 0x20;
                  bVar78 = *(byte *)((int)puVar524 + 0x22);
                  bVar79 = *(byte *)((int)puVar524 + 0x2a);
                  bVar80 = *(byte *)((int)puVar524 + 0x32);
                  bVar81 = *(byte *)((int)puVar524 + 0x3a);
                  bVar82 = *(byte *)((int)puVar524 + 0x62);
                  bVar84 = *(byte *)((int)puVar524 + 0x6a);
                  bVar85 = *(byte *)((int)puVar524 + 0x72);
                  bVar86 = *(byte *)((int)puVar524 + 0x7a);
                  bVar87 = *(byte *)((int)puVar531 + 0x16);
                  bVar88 = (byte)puVar531[6];
                  bVar89 = *(byte *)((int)puVar531 + 0x1a);
                  bVar102 = (byte)puVar531[7];
                  bVar95 = *(byte *)((int)puVar531 + 0x1e);
                  bVar103 = (byte)puVar531[8];
                  bVar96 = *(byte *)((int)puVar531 + 0x22);
                  auVar9 = *(undefined1 (*) [16])((int)puVar531 + 6);
                  auVar543._0_14_ = auVar9._0_14_;
                  auVar543[0xe] = auVar9[7];
                  auVar543[0xf] = *(byte *)((int)puVar531 + 0x1d);
                  auVar542._14_2_ = auVar543._14_2_;
                  auVar542._0_13_ = auVar9._0_13_;
                  auVar542[0xd] = bVar102;
                  auVar541._13_3_ = auVar542._13_3_;
                  auVar541._0_12_ = auVar9._0_12_;
                  auVar541[0xc] = auVar9[6];
                  auVar540._12_4_ = auVar541._12_4_;
                  auVar540._0_11_ = auVar9._0_11_;
                  auVar540[0xb] = *(byte *)((int)puVar531 + 0x1b);
                  auVar539._11_5_ = auVar540._11_5_;
                  auVar539._0_10_ = auVar9._0_10_;
                  auVar539[10] = auVar9[5];
                  auVar538._10_6_ = auVar539._10_6_;
                  auVar538._0_9_ = auVar9._0_9_;
                  auVar538[9] = bVar89;
                  uVar632 = auVar9[4];
                  auVar537._9_7_ = auVar538._9_7_;
                  auVar537._0_8_ = auVar9._0_8_;
                  auVar537[8] = uVar632;
                  auVar298._1_8_ = auVar537._8_8_;
                  auVar298[0] = *(byte *)((int)puVar531 + 0x19);
                  auVar298._9_7_ = 0;
                  auVar297._10_6_ = 0;
                  auVar297._0_10_ = SUB1610(auVar298 << 0x38,6);
                  auVar296._11_5_ = 0;
                  auVar296._0_11_ = SUB1611(auVar297 << 0x30,5);
                  auVar295._12_4_ = 0;
                  auVar295._0_12_ = SUB1612(auVar296 << 0x28,4);
                  auVar294._13_3_ = 0;
                  auVar294._0_13_ = SUB1613(auVar295 << 0x20,3);
                  auVar536._14_2_ = 0;
                  auVar536._0_14_ = SUB1614(auVar294 << 0x18,2);
                  auVar536 = auVar536 << 0x10;
                  uVar923 = auVar9[8];
                  uVar924 = auVar9[10];
                  auVar551._0_14_ = auVar536._0_14_;
                  auVar551[0xe] = *(byte *)((int)puVar531 + 0x19);
                  auVar551[0xf] = *(byte *)((int)puVar531 + 0x21);
                  auVar550._14_2_ = auVar551._14_2_;
                  auVar550._0_13_ = auVar536._0_13_;
                  auVar550[0xd] = auVar9[0xb];
                  auVar549._13_3_ = auVar550._13_3_;
                  auVar549._0_12_ = auVar536._0_12_;
                  auVar549[0xc] = auVar9[3];
                  auVar548._12_4_ = auVar549._12_4_;
                  auVar548._0_11_ = auVar536._0_11_;
                  auVar548[0xb] = bVar103;
                  auVar547._11_5_ = auVar548._11_5_;
                  auVar547._0_10_ = auVar536._0_10_;
                  auVar547[10] = bVar88;
                  auVar546._10_6_ = auVar547._10_6_;
                  auVar546._0_9_ = auVar536._0_9_;
                  auVar546[9] = uVar924;
                  auVar545._9_7_ = auVar546._9_7_;
                  auVar545._0_8_ = auVar536._0_8_;
                  auVar545[8] = auVar9[2];
                  auVar303._1_8_ = auVar545._8_8_;
                  auVar303[0] = *(byte *)((int)puVar531 + 0x1f);
                  auVar303._9_7_ = 0;
                  auVar302._10_6_ = 0;
                  auVar302._0_10_ = SUB1610(auVar303 << 0x38,6);
                  auVar301._11_5_ = 0;
                  auVar301._0_11_ = SUB1611(auVar302 << 0x30,5);
                  auVar300._12_4_ = 0;
                  auVar300._0_12_ = SUB1612(auVar301 << 0x28,4);
                  auVar299._13_3_ = 0;
                  auVar299._0_13_ = SUB1613(auVar300 << 0x20,3);
                  auVar544._14_2_ = 0;
                  auVar544._0_14_ = SUB1614(auVar299 << 0x18,2);
                  auVar544 = auVar544 << 0x10;
                  auVar559._0_14_ = auVar544._0_14_;
                  auVar559[0xe] = *(byte *)((int)puVar531 + 0x1f);
                  auVar559[0xf] = *(byte *)((int)puVar531 + 0x23);
                  auVar558._14_2_ = auVar559._14_2_;
                  auVar558._0_13_ = auVar544._0_13_;
                  auVar558[0xd] = *(byte *)((int)puVar531 + 0x1b);
                  auVar557._13_3_ = auVar558._13_3_;
                  auVar557._0_12_ = auVar544._0_12_;
                  auVar557[0xc] = *(byte *)((int)puVar531 + 0x17);
                  auVar556._12_4_ = auVar557._12_4_;
                  auVar556._0_11_ = auVar544._0_11_;
                  auVar556[0xb] = auVar9[0xd];
                  auVar555._11_5_ = auVar556._11_5_;
                  auVar555._0_10_ = auVar544._0_10_;
                  auVar555[10] = auVar9[9];
                  auVar554._10_6_ = auVar555._10_6_;
                  auVar554._0_9_ = auVar544._0_9_;
                  auVar554[9] = auVar9[5];
                  auVar553._9_7_ = auVar554._9_7_;
                  auVar553._0_8_ = auVar544._0_8_;
                  auVar553[8] = auVar9[1];
                  auVar308._1_8_ = auVar553._8_8_;
                  auVar308[0] = bVar96;
                  auVar308._9_7_ = 0;
                  auVar307._10_6_ = 0;
                  auVar307._0_10_ = SUB1610(auVar308 << 0x38,6);
                  auVar306._11_5_ = 0;
                  auVar306._0_11_ = SUB1611(auVar307 << 0x30,5);
                  auVar305._12_4_ = 0;
                  auVar305._0_12_ = SUB1612(auVar306 << 0x28,4);
                  auVar304._13_3_ = 0;
                  auVar304._0_13_ = SUB1613(auVar305 << 0x20,3);
                  auVar552._14_2_ = 0;
                  auVar552._0_14_ = SUB1614(auVar304 << 0x18,2);
                  auVar552 = auVar552 << 0x10;
                  bVar97 = *(byte *)((int)puVar531 + 0x2a);
                  bVar98 = *(byte *)((int)puVar531 + 0x2e);
                  bVar99 = *(byte *)((int)puVar531 + 0x32);
                  auVar567._0_14_ = auVar552._0_14_;
                  auVar567[0xe] = bVar96;
                  auVar567[0xf] = (byte)puVar531[9];
                  auVar566._14_2_ = auVar567._14_2_;
                  auVar566._0_13_ = auVar552._0_13_;
                  auVar566[0xd] = bVar103;
                  auVar565._13_3_ = auVar566._13_3_;
                  auVar565._0_12_ = auVar552._0_12_;
                  auVar565[0xc] = bVar95;
                  auVar564._12_4_ = auVar565._12_4_;
                  auVar564._0_11_ = auVar552._0_11_;
                  auVar564[0xb] = bVar102;
                  auVar563._11_5_ = auVar564._11_5_;
                  auVar563._0_10_ = auVar552._0_10_;
                  auVar563[10] = bVar89;
                  auVar562._10_6_ = auVar563._10_6_;
                  auVar562._0_9_ = auVar552._0_9_;
                  auVar562[9] = bVar88;
                  auVar561._9_7_ = auVar562._9_7_;
                  auVar561._0_8_ = auVar552._0_8_;
                  auVar561[8] = bVar87;
                  auVar313._1_8_ = auVar561._8_8_;
                  auVar313[0] = auVar9[0xe];
                  auVar313._9_7_ = 0;
                  auVar312._10_6_ = 0;
                  auVar312._0_10_ = SUB1610(auVar313 << 0x38,6);
                  auVar311._11_5_ = 0;
                  auVar311._0_11_ = SUB1611(auVar312 << 0x30,5);
                  auVar310._12_4_ = 0;
                  auVar310._0_12_ = SUB1612(auVar311 << 0x28,4);
                  auVar309._13_3_ = 0;
                  auVar309._0_13_ = SUB1613(auVar310 << 0x20,3);
                  auVar560._14_2_ = 0;
                  auVar560._0_14_ = SUB1614(auVar309 << 0x18,2);
                  auVar560 = auVar560 << 0x10;
                  bVar100 = *(byte *)((int)puVar531 + 0x3a);
                  bVar101 = *(byte *)((int)puVar531 + 0x3e);
                  auVar575._0_14_ = auVar560._0_14_;
                  auVar575[0xe] = auVar9[0xe];
                  auVar575[0xf] = (byte)puVar531[0xd];
                  auVar574._14_2_ = auVar575._14_2_;
                  auVar574._0_13_ = auVar560._0_13_;
                  auVar574[0xd] = bVar99;
                  auVar573._13_3_ = auVar574._13_3_;
                  auVar573._0_12_ = auVar560._0_12_;
                  auVar573[0xc] = auVar9[0xc];
                  auVar572._12_4_ = auVar573._12_4_;
                  auVar572._0_11_ = auVar560._0_11_;
                  auVar572[0xb] = (byte)puVar531[0xc];
                  auVar571._11_5_ = auVar572._11_5_;
                  auVar571._0_10_ = auVar560._0_10_;
                  auVar571[10] = uVar924;
                  auVar570._10_6_ = auVar571._10_6_;
                  auVar570._0_9_ = auVar560._0_9_;
                  auVar570[9] = bVar98;
                  auVar569._9_7_ = auVar570._9_7_;
                  auVar569._0_8_ = auVar560._0_8_;
                  auVar569[8] = uVar923;
                  auVar318._1_8_ = auVar569._8_8_;
                  auVar318[0] = (byte)puVar531[0xb];
                  auVar318._9_7_ = 0;
                  auVar317._10_6_ = 0;
                  auVar317._0_10_ = SUB1610(auVar318 << 0x38,6);
                  auVar316._11_5_ = 0;
                  auVar316._0_11_ = SUB1611(auVar317 << 0x30,5);
                  auVar315._12_4_ = 0;
                  auVar315._0_12_ = SUB1612(auVar316 << 0x28,4);
                  auVar314._13_3_ = 0;
                  auVar314._0_13_ = SUB1613(auVar315 << 0x20,3);
                  auVar568._14_2_ = 0;
                  auVar568._0_14_ = SUB1614(auVar314 << 0x18,2);
                  auVar568 = auVar568 << 0x10;
                  auVar583._0_14_ = auVar568._0_14_;
                  auVar583[0xe] = (byte)puVar531[0xb];
                  auVar583[0xf] = (byte)puVar531[0xf];
                  auVar582._14_2_ = auVar583._14_2_;
                  auVar582._0_13_ = auVar568._0_13_;
                  auVar582[0xd] = bVar102;
                  auVar581._13_3_ = auVar582._13_3_;
                  auVar581._0_12_ = auVar568._0_12_;
                  auVar581[0xc] = auVar9[6];
                  auVar580._12_4_ = auVar581._12_4_;
                  auVar580._0_11_ = auVar568._0_11_;
                  auVar580[0xb] = bVar100;
                  auVar579._11_5_ = auVar580._11_5_;
                  auVar579._0_10_ = auVar568._0_10_;
                  auVar579[10] = bVar97;
                  auVar578._10_6_ = auVar579._10_6_;
                  auVar578._0_9_ = auVar568._0_9_;
                  auVar578[9] = bVar89;
                  auVar577._9_7_ = auVar578._9_7_;
                  auVar577._0_8_ = auVar568._0_8_;
                  auVar577[8] = uVar632;
                  auVar323._1_8_ = auVar577._8_8_;
                  auVar323[0] = (byte)puVar531[0xe];
                  auVar323._9_7_ = 0;
                  auVar322._10_6_ = 0;
                  auVar322._0_10_ = SUB1610(auVar323 << 0x38,6);
                  auVar321._11_5_ = 0;
                  auVar321._0_11_ = SUB1611(auVar322 << 0x30,5);
                  auVar320._12_4_ = 0;
                  auVar320._0_12_ = SUB1612(auVar321 << 0x28,4);
                  auVar319._13_3_ = 0;
                  auVar319._0_13_ = SUB1613(auVar320 << 0x20,3);
                  auVar576._14_2_ = 0;
                  auVar576._0_14_ = SUB1614(auVar319 << 0x18,2);
                  auVar576 = auVar576 << 0x10;
                  auVar591._0_14_ = auVar576._0_14_;
                  auVar591[0xe] = (byte)puVar531[0xe];
                  auVar591[0xf] = (byte)puVar531[0x10];
                  auVar590._14_2_ = auVar591._14_2_;
                  auVar590._0_13_ = auVar576._0_13_;
                  auVar590[0xd] = (byte)puVar531[0xc];
                  auVar589._13_3_ = auVar590._13_3_;
                  auVar589._0_12_ = auVar576._0_12_;
                  auVar589[0xc] = (byte)puVar531[10];
                  auVar588._12_4_ = auVar589._12_4_;
                  auVar588._0_11_ = auVar576._0_11_;
                  auVar588[0xb] = bVar103;
                  auVar587._11_5_ = auVar588._11_5_;
                  auVar587._0_10_ = auVar576._0_10_;
                  auVar587[10] = bVar88;
                  auVar586._10_6_ = auVar587._10_6_;
                  auVar586._0_9_ = auVar576._0_9_;
                  auVar586[9] = uVar924;
                  auVar585._9_7_ = auVar586._9_7_;
                  auVar585._0_8_ = auVar576._0_8_;
                  auVar585[8] = auVar9[2];
                  auVar328._1_8_ = auVar585._8_8_;
                  auVar328[0] = bVar101;
                  auVar328._9_7_ = 0;
                  auVar327._10_6_ = 0;
                  auVar327._0_10_ = SUB1610(auVar328 << 0x38,6);
                  auVar326._11_5_ = 0;
                  auVar326._0_11_ = SUB1611(auVar327 << 0x30,5);
                  auVar325._12_4_ = 0;
                  auVar325._0_12_ = SUB1612(auVar326 << 0x28,4);
                  auVar324._13_3_ = 0;
                  auVar324._0_13_ = SUB1613(auVar325 << 0x20,3);
                  auVar584._14_2_ = 0;
                  auVar584._0_14_ = SUB1614(auVar324 << 0x18,2);
                  auVar584 = auVar584 << 0x10;
                  bVar88 = *(byte *)((int)puVar531 + 0x56);
                  bVar102 = *(byte *)((int)puVar531 + 0x5e);
                  auVar599._0_14_ = auVar584._0_14_;
                  auVar599[0xe] = bVar101;
                  auVar599[0xf] = *(byte *)((int)puVar531 + 0x42);
                  auVar598._14_2_ = auVar599._14_2_;
                  auVar598._0_13_ = auVar584._0_13_;
                  auVar598[0xd] = bVar100;
                  auVar597._13_3_ = auVar598._13_3_;
                  auVar597._0_12_ = auVar584._0_12_;
                  auVar597[0xc] = *(byte *)((int)puVar531 + 0x36);
                  auVar596._12_4_ = auVar597._12_4_;
                  auVar596._0_11_ = auVar584._0_11_;
                  auVar596[0xb] = bVar99;
                  auVar595._11_5_ = auVar596._11_5_;
                  auVar595._0_10_ = auVar584._0_10_;
                  auVar595[10] = bVar98;
                  auVar594._10_6_ = auVar595._10_6_;
                  auVar594._0_9_ = auVar584._0_9_;
                  auVar594[9] = bVar97;
                  auVar593._9_7_ = auVar594._9_7_;
                  auVar593._0_8_ = auVar584._0_8_;
                  auVar593[8] = *(byte *)((int)puVar531 + 0x26);
                  auVar333._1_8_ = auVar593._8_8_;
                  auVar333[0] = bVar96;
                  auVar333._9_7_ = 0;
                  auVar332._10_6_ = 0;
                  auVar332._0_10_ = SUB1610(auVar333 << 0x38,6);
                  auVar331._11_5_ = 0;
                  auVar331._0_11_ = SUB1611(auVar332 << 0x30,5);
                  auVar330._12_4_ = 0;
                  auVar330._0_12_ = SUB1612(auVar331 << 0x28,4);
                  auVar329._13_3_ = 0;
                  auVar329._0_13_ = SUB1613(auVar330 << 0x20,3);
                  auVar592._14_2_ = 0;
                  auVar592._0_14_ = SUB1614(auVar329 << 0x18,2);
                  auVar592 = auVar592 << 0x10;
                  bVar103 = *(byte *)((int)puVar531 + 0x46);
                  bVar104 = *(byte *)((int)puVar531 + 0x4e);
                  bVar105 = *(byte *)((int)puVar531 + 0x66);
                  bVar106 = *(byte *)((int)puVar531 + 0x6e);
                  bVar107 = *(byte *)((int)puVar531 + 0x76);
                  bVar108 = *(byte *)((int)puVar531 + 0x7e);
                  auVar607._0_14_ = auVar592._0_14_;
                  auVar607[0xe] = bVar96;
                  auVar607[0xf] = *(byte *)((int)puVar531 + 0x62);
                  auVar606._14_2_ = auVar607._14_2_;
                  auVar606._0_13_ = auVar592._0_13_;
                  auVar606[0xd] = bVar102;
                  auVar605._13_3_ = auVar606._13_3_;
                  auVar605._0_12_ = auVar592._0_12_;
                  auVar605[0xc] = bVar95;
                  auVar604._12_4_ = auVar605._12_4_;
                  auVar604._0_11_ = auVar592._0_11_;
                  auVar604[0xb] = *(byte *)((int)puVar531 + 0x5a);
                  auVar603._11_5_ = auVar604._11_5_;
                  auVar603._0_10_ = auVar592._0_10_;
                  auVar603[10] = bVar89;
                  auVar602._10_6_ = auVar603._10_6_;
                  auVar602._0_9_ = auVar592._0_9_;
                  auVar602[9] = bVar88;
                  auVar601._9_7_ = auVar602._9_7_;
                  auVar601._0_8_ = auVar592._0_8_;
                  auVar601[8] = bVar87;
                  auVar338._1_8_ = auVar601._8_8_;
                  auVar338[0] = *(byte *)((int)puVar531 + 0x52);
                  auVar338._9_7_ = 0;
                  auVar337._10_6_ = 0;
                  auVar337._0_10_ = SUB1610(auVar338 << 0x38,6);
                  auVar336._11_5_ = 0;
                  auVar336._0_11_ = SUB1611(auVar337 << 0x30,5);
                  auVar335._12_4_ = 0;
                  auVar335._0_12_ = SUB1612(auVar336 << 0x28,4);
                  auVar334._13_3_ = 0;
                  auVar334._0_13_ = SUB1613(auVar335 << 0x20,3);
                  auVar600._14_2_ = 0;
                  auVar600._0_14_ = SUB1614(auVar334 << 0x18,2);
                  auVar600 = auVar600 << 0x10;
                  auVar615._0_14_ = auVar600._0_14_;
                  auVar615[0xe] = *(byte *)((int)puVar531 + 0x52);
                  auVar615[0xf] = *(byte *)((int)puVar531 + 0x72);
                  auVar614._14_2_ = auVar615._14_2_;
                  auVar614._0_13_ = auVar600._0_13_;
                  auVar614[0xd] = bVar99;
                  auVar613._13_3_ = auVar614._13_3_;
                  auVar613._0_12_ = auVar600._0_12_;
                  auVar613[0xc] = auVar9[0xc];
                  auVar612._12_4_ = auVar613._12_4_;
                  auVar612._0_11_ = auVar600._0_11_;
                  auVar612[0xb] = bVar106;
                  auVar611._11_5_ = auVar612._11_5_;
                  auVar611._0_10_ = auVar600._0_10_;
                  auVar611[10] = bVar104;
                  auVar610._10_6_ = auVar611._10_6_;
                  auVar610._0_9_ = auVar600._0_9_;
                  auVar610[9] = bVar98;
                  auVar609._9_7_ = auVar610._9_7_;
                  auVar609._0_8_ = auVar600._0_8_;
                  auVar609[8] = uVar923;
                  auVar343._1_8_ = auVar609._8_8_;
                  auVar343[0] = *(byte *)((int)puVar531 + 0x6a);
                  auVar343._9_7_ = 0;
                  auVar342._10_6_ = 0;
                  auVar342._0_10_ = SUB1610(auVar343 << 0x38,6);
                  auVar341._11_5_ = 0;
                  auVar341._0_11_ = SUB1611(auVar342 << 0x30,5);
                  auVar340._12_4_ = 0;
                  auVar340._0_12_ = SUB1612(auVar341 << 0x28,4);
                  auVar339._13_3_ = 0;
                  auVar339._0_13_ = SUB1613(auVar340 << 0x20,3);
                  auVar608._14_2_ = 0;
                  auVar608._0_14_ = SUB1614(auVar339 << 0x18,2);
                  auVar608 = auVar608 << 0x10;
                  uVar148 = CONCAT13(0,CONCAT12(pbVar1[10],(ushort)pbVar1[2]));
                  auVar623._0_14_ = auVar608._0_14_;
                  auVar623[0xe] = *(byte *)((int)puVar531 + 0x6a);
                  auVar623[0xf] = *(byte *)((int)puVar531 + 0x7a);
                  auVar622._14_2_ = auVar623._14_2_;
                  auVar622._0_13_ = auVar608._0_13_;
                  auVar622[0xd] = *(byte *)((int)puVar531 + 0x5a);
                  auVar621._13_3_ = auVar622._13_3_;
                  auVar621._0_12_ = auVar608._0_12_;
                  auVar621[0xc] = *(byte *)((int)puVar531 + 0x4a);
                  auVar620._12_4_ = auVar621._12_4_;
                  auVar620._0_11_ = auVar608._0_11_;
                  auVar620[0xb] = bVar100;
                  auVar619._11_5_ = auVar620._11_5_;
                  auVar619._0_10_ = auVar608._0_10_;
                  auVar619[10] = bVar97;
                  auVar618._10_6_ = auVar619._10_6_;
                  auVar618._0_9_ = auVar608._0_9_;
                  auVar618[9] = bVar89;
                  auVar617._9_7_ = auVar618._9_7_;
                  auVar617._0_8_ = auVar608._0_8_;
                  auVar617[8] = uVar632;
                  auVar348._1_8_ = auVar617._8_8_;
                  auVar348[0] = bVar107;
                  auVar348._9_7_ = 0;
                  auVar347._10_6_ = 0;
                  auVar347._0_10_ = SUB1610(auVar348 << 0x38,6);
                  auVar346._11_5_ = 0;
                  auVar346._0_11_ = SUB1611(auVar347 << 0x30,5);
                  auVar345._12_4_ = 0;
                  auVar345._0_12_ = SUB1612(auVar346 << 0x28,4);
                  auVar344._13_3_ = 0;
                  auVar344._0_13_ = SUB1613(auVar345 << 0x20,3);
                  auVar616._14_2_ = 0;
                  auVar616._0_14_ = SUB1614(auVar344 << 0x18,2);
                  auVar616 = auVar616 << 0x10;
                  auVar470[0xc] = uStack_102;
                  auVar470._0_12_ = ZEXT112(bVar48) << 0x40;
                  auVar471._10_3_ = auVar470._10_3_;
                  auVar471._0_10_ = (unkuint10)bStack_10a << 0x40;
                  auVar30[4] = pbVar1[10];
                  auVar30._0_4_ = uVar148;
                  auVar30[5] = 0;
                  auVar30._6_8_ = SUB148(ZEXT514(auVar471._8_5_) << 0x40,6);
                  auVar631._0_14_ = auVar616._0_14_;
                  auVar631[0xe] = bVar107;
                  auVar631[0xf] = bVar108;
                  auVar630._14_2_ = auVar631._14_2_;
                  auVar630._0_13_ = auVar616._0_13_;
                  auVar630[0xd] = bVar106;
                  auVar629._13_3_ = auVar630._13_3_;
                  auVar629._0_12_ = auVar616._0_12_;
                  auVar629[0xc] = bVar105;
                  auVar628._12_4_ = auVar629._12_4_;
                  auVar628._0_11_ = auVar616._0_11_;
                  auVar628[0xb] = bVar102;
                  auVar627._11_5_ = auVar628._11_5_;
                  auVar627._0_10_ = auVar616._0_10_;
                  auVar627[10] = bVar88;
                  auVar626._10_6_ = auVar627._10_6_;
                  auVar626._0_9_ = auVar616._0_9_;
                  auVar626[9] = bVar104;
                  auVar625._9_7_ = auVar626._9_7_;
                  auVar625._0_8_ = auVar616._0_8_;
                  auVar625[8] = bVar103;
                  auVar353._1_8_ = auVar625._8_8_;
                  auVar353[0] = bVar101;
                  auVar353._9_7_ = 0;
                  auVar352._10_6_ = 0;
                  auVar352._0_10_ = SUB1610(auVar353 << 0x38,6);
                  auVar351._11_5_ = 0;
                  auVar351._0_11_ = SUB1611(auVar352 << 0x30,5);
                  auVar350._12_4_ = 0;
                  auVar350._0_12_ = SUB1612(auVar351 << 0x28,4);
                  auVar349._13_3_ = 0;
                  auVar349._0_13_ = SUB1613(auVar350 << 0x20,3);
                  auVar624._14_2_ = 0;
                  auVar624._0_14_ = SUB1614(auVar349 << 0x18,2);
                  auVar624 = auVar624 << 0x10;
                  uVar155 = CONCAT13(0,CONCAT12(pbVar1[0xe],(ushort)pbVar1[6]));
                  auVar472[0xc] = uStack_fe;
                  auVar472._0_12_ = ZEXT112(bVar52) << 0x40;
                  auVar473._10_3_ = auVar472._10_3_;
                  auVar473._0_10_ = (unkuint10)bStack_106 << 0x40;
                  auVar31[4] = pbVar1[0xe];
                  auVar31._0_4_ = uVar155;
                  auVar31[5] = 0;
                  auVar31._6_8_ = SUB148(ZEXT514(auVar473._8_5_) << 0x40,6);
                  uVar159 = CONCAT13(0,CONCAT12(*(byte *)((int)puVar524 + 10),
                                                (ushort)*(byte *)((int)puVar524 + 2)));
                  auVar474[0xc] = *(byte *)((int)puVar524 + 0x1a);
                  auVar474._0_12_ = ZEXT112(bVar78) << 0x40;
                  auVar475._10_3_ = auVar474._10_3_;
                  auVar475._0_10_ = (unkuint10)*(byte *)((int)puVar524 + 0x12) << 0x40;
                  auVar32[4] = *(byte *)((int)puVar524 + 10);
                  auVar32._0_4_ = uVar159;
                  auVar32[5] = 0;
                  auVar32._6_8_ = SUB148(ZEXT514(auVar475._8_5_) << 0x40,6);
                  auVar434[0xd] = 0;
                  auVar434._0_13_ = auVar624._0_13_;
                  auVar434[0xe] = bVar101;
                  auVar438[0xc] = *(byte *)((int)puVar531 + 0x36);
                  auVar438._0_12_ = auVar624._0_12_;
                  auVar438._13_2_ = auVar434._13_2_;
                  uVar476 = auVar438._12_3_;
                  auVar477[0xb] = 0;
                  auVar477._0_11_ = auVar624._0_11_;
                  auVar477._12_3_ = uVar476;
                  auVar502[10] = bVar98;
                  auVar502._0_10_ = auVar624._0_10_;
                  auVar502._11_4_ = auVar477._11_4_;
                  auVar506[9] = 0;
                  auVar506._0_9_ = auVar624._0_9_;
                  auVar506._10_5_ = auVar502._10_5_;
                  auVar510[8] = *(byte *)((int)puVar531 + 0x26);
                  auVar510._0_8_ = auVar624._0_8_;
                  auVar510._9_6_ = auVar506._9_6_;
                  Var229 = CONCAT91((unkuint9)auVar510._8_7_ << 8,bVar95);
                  auVar427[10] = 0;
                  auVar427._0_10_ = Var229;
                  auVar355._1_11_ = auVar427 << 8;
                  auVar355[0] = bVar87;
                  auVar426[0xc] = 0;
                  auVar426._0_12_ = auVar355;
                  auVar354._1_13_ = auVar426 << 8;
                  auVar354[0] = uVar923;
                  auVar922[1] = 0;
                  auVar922[0] = auVar9[0];
                  auVar922._2_14_ = auVar354;
                  auVar12._10_2_ = 0;
                  auVar12._0_10_ = auVar922._0_10_;
                  auVar12._12_2_ = (short)Var229;
                  uVar514 = CONCAT42(auVar12._10_4_,auVar355._0_2_);
                  auVar356._6_8_ = 0;
                  auVar356._0_6_ = uVar514;
                  auVar33._4_2_ = auVar354._0_2_;
                  auVar33._0_4_ = auVar922._0_4_;
                  auVar33._6_8_ = SUB148(auVar356 << 0x40,6);
                  uVar150 = CONCAT13(0,CONCAT12(uStack_13e,(ushort)bStack_146));
                  auVar478[0xc] = uStack_11e;
                  auVar478._0_12_ = ZEXT112(bStack_136) << 0x40;
                  auVar479._10_3_ = auVar478._10_3_;
                  auVar479._0_10_ = (unkuint10)bStack_126 << 0x40;
                  auVar34[4] = uStack_13e;
                  auVar34._0_4_ = uVar150;
                  auVar34[5] = 0;
                  auVar34._6_8_ = SUB148(ZEXT514(auVar479._8_5_) << 0x40,6);
                  uVar144 = CONCAT13(0,CONCAT12(uStack_142,(ushort)bStack_14a));
                  auVar480[0xc] = uStack_122;
                  auVar480._0_12_ = ZEXT112(bStack_13a) << 0x40;
                  auVar481._10_3_ = auVar480._10_3_;
                  auVar481._0_10_ = (unkuint10)bStack_12a << 0x40;
                  auVar35[4] = uStack_142;
                  auVar35._0_4_ = uVar144;
                  auVar35[5] = 0;
                  auVar35._6_8_ = SUB148(ZEXT514(auVar481._8_5_) << 0x40,6);
                  uVar163 = CONCAT13(0,CONCAT12(*(byte *)((int)puVar524 + 0x4a),
                                                (ushort)*(byte *)((int)puVar524 + 0x42)));
                  auVar482[0xc] = *(byte *)((int)puVar524 + 0x5a);
                  auVar482._0_12_ = ZEXT112(bVar82) << 0x40;
                  auVar483._10_3_ = auVar482._10_3_;
                  auVar483._0_10_ = (unkuint10)*(byte *)((int)puVar524 + 0x52) << 0x40;
                  auVar36[4] = *(byte *)((int)puVar524 + 0x4a);
                  auVar36._0_4_ = uVar163;
                  auVar36[5] = 0;
                  auVar36._6_8_ = SUB148(ZEXT514(auVar483._8_5_) << 0x40,6);
                  auVar428[0xc] = bVar102;
                  auVar428._0_12_ = ZEXT112(bVar105) << 0x40;
                  auVar429._10_3_ = auVar428._10_3_;
                  auVar429._0_10_ = (unkuint10)bVar88 << 0x40;
                  auVar37._6_8_ = SUB148(ZEXT514(auVar429._8_5_) << 0x40,6);
                  auVar37._0_6_ = (uint6)bVar104 << 0x20;
                  bVar87 = *(byte *)((int)puVar530 + 0x23);
                  bVar88 = *(byte *)((int)puVar530 + 0x2b);
                  bVar89 = *(byte *)((int)puVar530 + 0x33);
                  bVar102 = *(byte *)((int)puVar530 + 0x3b);
                  bVar95 = *(byte *)((int)puVar530 + 99);
                  bVar96 = *(byte *)((int)puVar530 + 0x6b);
                  uVar138 = *(uint *)((int)puVar530 + 0x73);
                  uVar139 = *(uint *)((int)puVar530 + 0x7b);
                  auVar9 = *(undefined1 (*) [16])((int)puVar535 + 7);
                  bVar97 = *(byte *)((int)puVar535 + 0x17);
                  bVar98 = *(byte *)((int)puVar535 + 0x19);
                  bVar99 = *(byte *)((int)puVar535 + 0x1b);
                  bVar100 = *(byte *)((int)puVar535 + 0x1d);
                  bVar101 = *(byte *)((int)puVar535 + 0x1f);
                  bVar109 = *(byte *)((int)puVar535 + 0x21);
                  bVar110 = *(byte *)((int)puVar535 + 0x23);
                  auVar833._0_14_ = auVar9._0_14_;
                  auVar833[0xe] = auVar9[7];
                  auVar833[0xf] = *(byte *)((int)puVar535 + 0x1e);
                  auVar832._14_2_ = auVar833._14_2_;
                  auVar832._0_13_ = auVar9._0_13_;
                  auVar832[0xd] = bVar100;
                  auVar831._13_3_ = auVar832._13_3_;
                  auVar831._0_12_ = auVar9._0_12_;
                  auVar831[0xc] = auVar9[6];
                  auVar830._12_4_ = auVar831._12_4_;
                  auVar830._0_11_ = auVar9._0_11_;
                  auVar830[0xb] = (byte)puVar535[7];
                  auVar829._11_5_ = auVar830._11_5_;
                  auVar829._0_10_ = auVar9._0_10_;
                  auVar829[10] = auVar9[5];
                  auVar828._10_6_ = auVar829._10_6_;
                  auVar828._0_9_ = auVar9._0_9_;
                  auVar828[9] = bVar99;
                  uVar632 = auVar9[4];
                  auVar827._9_7_ = auVar828._9_7_;
                  auVar827._0_8_ = auVar9._0_8_;
                  auVar827[8] = uVar632;
                  auVar361._1_8_ = auVar827._8_8_;
                  auVar361[0] = *(byte *)((int)puVar535 + 0x1a);
                  auVar361._9_7_ = 0;
                  auVar360._10_6_ = 0;
                  auVar360._0_10_ = SUB1610(auVar361 << 0x38,6);
                  auVar359._11_5_ = 0;
                  auVar359._0_11_ = SUB1611(auVar360 << 0x30,5);
                  auVar358._12_4_ = 0;
                  auVar358._0_12_ = SUB1612(auVar359 << 0x28,4);
                  auVar357._13_3_ = 0;
                  auVar357._0_13_ = SUB1613(auVar358 << 0x20,3);
                  auVar826._14_2_ = 0;
                  auVar826._0_14_ = SUB1614(auVar357 << 0x18,2);
                  auVar826 = auVar826 << 0x10;
                  uVar923 = auVar9[8];
                  uVar924 = auVar9[10];
                  auVar841._0_14_ = auVar826._0_14_;
                  auVar841[0xe] = *(byte *)((int)puVar535 + 0x1a);
                  auVar841[0xf] = *(byte *)((int)puVar535 + 0x22);
                  auVar840._14_2_ = auVar841._14_2_;
                  auVar840._0_13_ = auVar826._0_13_;
                  auVar840[0xd] = auVar9[0xb];
                  auVar839._13_3_ = auVar840._13_3_;
                  auVar839._0_12_ = auVar826._0_12_;
                  auVar839[0xc] = auVar9[3];
                  auVar838._12_4_ = auVar839._12_4_;
                  auVar838._0_11_ = auVar826._0_11_;
                  auVar838[0xb] = bVar109;
                  auVar837._11_5_ = auVar838._11_5_;
                  auVar837._0_10_ = auVar826._0_10_;
                  auVar837[10] = bVar98;
                  auVar836._10_6_ = auVar837._10_6_;
                  auVar836._0_9_ = auVar826._0_9_;
                  auVar836[9] = uVar924;
                  auVar835._9_7_ = auVar836._9_7_;
                  auVar835._0_8_ = auVar826._0_8_;
                  auVar835[8] = auVar9[2];
                  auVar366._1_8_ = auVar835._8_8_;
                  auVar366[0] = (byte)puVar535[8];
                  auVar366._9_7_ = 0;
                  auVar365._10_6_ = 0;
                  auVar365._0_10_ = SUB1610(auVar366 << 0x38,6);
                  auVar364._11_5_ = 0;
                  auVar364._0_11_ = SUB1611(auVar365 << 0x30,5);
                  auVar363._12_4_ = 0;
                  auVar363._0_12_ = SUB1612(auVar364 << 0x28,4);
                  auVar362._13_3_ = 0;
                  auVar362._0_13_ = SUB1613(auVar363 << 0x20,3);
                  auVar834._14_2_ = 0;
                  auVar834._0_14_ = SUB1614(auVar362 << 0x18,2);
                  auVar834 = auVar834 << 0x10;
                  auVar849._0_14_ = auVar834._0_14_;
                  auVar849[0xe] = (byte)puVar535[8];
                  auVar849[0xf] = (byte)puVar535[9];
                  auVar848._14_2_ = auVar849._14_2_;
                  auVar848._0_13_ = auVar834._0_13_;
                  auVar848[0xd] = (byte)puVar535[7];
                  auVar847._13_3_ = auVar848._13_3_;
                  auVar847._0_12_ = auVar834._0_12_;
                  auVar847[0xc] = (byte)puVar535[6];
                  auVar846._12_4_ = auVar847._12_4_;
                  auVar846._0_11_ = auVar834._0_11_;
                  auVar846[0xb] = auVar9[0xd];
                  auVar845._11_5_ = auVar846._11_5_;
                  auVar845._0_10_ = auVar834._0_10_;
                  auVar845[10] = auVar9[9];
                  auVar844._10_6_ = auVar845._10_6_;
                  auVar844._0_9_ = auVar834._0_9_;
                  auVar844[9] = auVar9[5];
                  auVar843._9_7_ = auVar844._9_7_;
                  auVar843._0_8_ = auVar834._0_8_;
                  auVar843[8] = auVar9[1];
                  auVar371._1_8_ = auVar843._8_8_;
                  auVar371[0] = bVar110;
                  auVar371._9_7_ = 0;
                  auVar370._10_6_ = 0;
                  auVar370._0_10_ = SUB1610(auVar371 << 0x38,6);
                  auVar369._11_5_ = 0;
                  auVar369._0_11_ = SUB1611(auVar370 << 0x30,5);
                  auVar368._12_4_ = 0;
                  auVar368._0_12_ = SUB1612(auVar369 << 0x28,4);
                  auVar367._13_3_ = 0;
                  auVar367._0_13_ = SUB1613(auVar368 << 0x20,3);
                  auVar842._14_2_ = 0;
                  auVar842._0_14_ = SUB1614(auVar367 << 0x18,2);
                  auVar842 = auVar842 << 0x10;
                  bVar111 = *(byte *)((int)puVar535 + 0x2b);
                  bVar112 = *(byte *)((int)puVar535 + 0x2f);
                  bVar113 = *(byte *)((int)puVar535 + 0x33);
                  auVar857._0_14_ = auVar842._0_14_;
                  auVar857[0xe] = bVar110;
                  auVar857[0xf] = *(byte *)((int)puVar535 + 0x25);
                  auVar856._14_2_ = auVar857._14_2_;
                  auVar856._0_13_ = auVar842._0_13_;
                  auVar856[0xd] = bVar109;
                  auVar855._13_3_ = auVar856._13_3_;
                  auVar855._0_12_ = auVar842._0_12_;
                  auVar855[0xc] = bVar101;
                  auVar854._12_4_ = auVar855._12_4_;
                  auVar854._0_11_ = auVar842._0_11_;
                  auVar854[0xb] = bVar100;
                  auVar853._11_5_ = auVar854._11_5_;
                  auVar853._0_10_ = auVar842._0_10_;
                  auVar853[10] = bVar99;
                  auVar852._10_6_ = auVar853._10_6_;
                  auVar852._0_9_ = auVar842._0_9_;
                  auVar852[9] = bVar98;
                  auVar851._9_7_ = auVar852._9_7_;
                  auVar851._0_8_ = auVar842._0_8_;
                  auVar851[8] = bVar97;
                  auVar376._1_8_ = auVar851._8_8_;
                  auVar376[0] = auVar9[0xe];
                  auVar376._9_7_ = 0;
                  auVar375._10_6_ = 0;
                  auVar375._0_10_ = SUB1610(auVar376 << 0x38,6);
                  auVar374._11_5_ = 0;
                  auVar374._0_11_ = SUB1611(auVar375 << 0x30,5);
                  auVar373._12_4_ = 0;
                  auVar373._0_12_ = SUB1612(auVar374 << 0x28,4);
                  auVar372._13_3_ = 0;
                  auVar372._0_13_ = SUB1613(auVar373 << 0x20,3);
                  auVar850._14_2_ = 0;
                  auVar850._0_14_ = SUB1614(auVar372 << 0x18,2);
                  auVar850 = auVar850 << 0x10;
                  bVar114 = *(byte *)((int)puVar535 + 0x3b);
                  bVar115 = *(byte *)((int)puVar535 + 0x3f);
                  auVar865._0_14_ = auVar850._0_14_;
                  auVar865[0xe] = auVar9[0xe];
                  auVar865[0xf] = *(byte *)((int)puVar535 + 0x35);
                  auVar864._14_2_ = auVar865._14_2_;
                  auVar864._0_13_ = auVar850._0_13_;
                  auVar864[0xd] = bVar113;
                  auVar863._13_3_ = auVar864._13_3_;
                  auVar863._0_12_ = auVar850._0_12_;
                  auVar863[0xc] = auVar9[0xc];
                  auVar862._12_4_ = auVar863._12_4_;
                  auVar862._0_11_ = auVar850._0_11_;
                  auVar862[0xb] = *(byte *)((int)puVar535 + 0x31);
                  auVar861._11_5_ = auVar862._11_5_;
                  auVar861._0_10_ = auVar850._0_10_;
                  auVar861[10] = uVar924;
                  auVar860._10_6_ = auVar861._10_6_;
                  auVar860._0_9_ = auVar850._0_9_;
                  auVar860[9] = bVar112;
                  auVar859._9_7_ = auVar860._9_7_;
                  auVar859._0_8_ = auVar850._0_8_;
                  auVar859[8] = uVar923;
                  auVar381._1_8_ = auVar859._8_8_;
                  auVar381[0] = *(byte *)((int)puVar535 + 0x2d);
                  auVar381._9_7_ = 0;
                  auVar380._10_6_ = 0;
                  auVar380._0_10_ = SUB1610(auVar381 << 0x38,6);
                  auVar379._11_5_ = 0;
                  auVar379._0_11_ = SUB1611(auVar380 << 0x30,5);
                  auVar378._12_4_ = 0;
                  auVar378._0_12_ = SUB1612(auVar379 << 0x28,4);
                  auVar377._13_3_ = 0;
                  auVar377._0_13_ = SUB1613(auVar378 << 0x20,3);
                  auVar858._14_2_ = 0;
                  auVar858._0_14_ = SUB1614(auVar377 << 0x18,2);
                  auVar858 = auVar858 << 0x10;
                  auVar873._0_14_ = auVar858._0_14_;
                  auVar873[0xe] = *(byte *)((int)puVar535 + 0x2d);
                  auVar873[0xf] = *(byte *)((int)puVar535 + 0x3d);
                  auVar872._14_2_ = auVar873._14_2_;
                  auVar872._0_13_ = auVar858._0_13_;
                  auVar872[0xd] = bVar100;
                  auVar871._13_3_ = auVar872._13_3_;
                  auVar871._0_12_ = auVar858._0_12_;
                  auVar871[0xc] = auVar9[6];
                  auVar870._12_4_ = auVar871._12_4_;
                  auVar870._0_11_ = auVar858._0_11_;
                  auVar870[0xb] = bVar114;
                  auVar869._11_5_ = auVar870._11_5_;
                  auVar869._0_10_ = auVar858._0_10_;
                  auVar869[10] = bVar111;
                  auVar868._10_6_ = auVar869._10_6_;
                  auVar868._0_9_ = auVar858._0_9_;
                  auVar868[9] = bVar99;
                  auVar867._9_7_ = auVar868._9_7_;
                  auVar867._0_8_ = auVar858._0_8_;
                  auVar867[8] = uVar632;
                  auVar386._1_8_ = auVar867._8_8_;
                  auVar386[0] = *(byte *)((int)puVar535 + 0x39);
                  auVar386._9_7_ = 0;
                  auVar385._10_6_ = 0;
                  auVar385._0_10_ = SUB1610(auVar386 << 0x38,6);
                  auVar384._11_5_ = 0;
                  auVar384._0_11_ = SUB1611(auVar385 << 0x30,5);
                  auVar383._12_4_ = 0;
                  auVar383._0_12_ = SUB1612(auVar384 << 0x28,4);
                  auVar382._13_3_ = 0;
                  auVar382._0_13_ = SUB1613(auVar383 << 0x20,3);
                  auVar866._14_2_ = 0;
                  auVar866._0_14_ = SUB1614(auVar382 << 0x18,2);
                  auVar866 = auVar866 << 0x10;
                  auVar881._0_14_ = auVar866._0_14_;
                  auVar881[0xe] = *(byte *)((int)puVar535 + 0x39);
                  auVar881[0xf] = *(byte *)((int)puVar535 + 0x41);
                  auVar880._14_2_ = auVar881._14_2_;
                  auVar880._0_13_ = auVar866._0_13_;
                  auVar880[0xd] = *(byte *)((int)puVar535 + 0x31);
                  auVar879._13_3_ = auVar880._13_3_;
                  auVar879._0_12_ = auVar866._0_12_;
                  auVar879[0xc] = *(byte *)((int)puVar535 + 0x29);
                  auVar878._12_4_ = auVar879._12_4_;
                  auVar878._0_11_ = auVar866._0_11_;
                  auVar878[0xb] = bVar109;
                  auVar877._11_5_ = auVar878._11_5_;
                  auVar877._0_10_ = auVar866._0_10_;
                  auVar877[10] = bVar98;
                  auVar876._10_6_ = auVar877._10_6_;
                  auVar876._0_9_ = auVar866._0_9_;
                  auVar876[9] = uVar924;
                  auVar875._9_7_ = auVar876._9_7_;
                  auVar875._0_8_ = auVar866._0_8_;
                  auVar875[8] = auVar9[2];
                  auVar391._1_8_ = auVar875._8_8_;
                  auVar391[0] = bVar115;
                  auVar391._9_7_ = 0;
                  auVar390._10_6_ = 0;
                  auVar390._0_10_ = SUB1610(auVar391 << 0x38,6);
                  auVar389._11_5_ = 0;
                  auVar389._0_11_ = SUB1611(auVar390 << 0x30,5);
                  auVar388._12_4_ = 0;
                  auVar388._0_12_ = SUB1612(auVar389 << 0x28,4);
                  auVar387._13_3_ = 0;
                  auVar387._0_13_ = SUB1613(auVar388 << 0x20,3);
                  auVar874._14_2_ = 0;
                  auVar874._0_14_ = SUB1614(auVar387 << 0x18,2);
                  auVar874 = auVar874 << 0x10;
                  bVar98 = *(byte *)((int)puVar535 + 0x57);
                  bVar100 = *(byte *)((int)puVar535 + 0x5f);
                  auVar889._0_14_ = auVar874._0_14_;
                  auVar889[0xe] = bVar115;
                  auVar889[0xf] = *(byte *)((int)puVar535 + 0x43);
                  auVar888._14_2_ = auVar889._14_2_;
                  auVar888._0_13_ = auVar874._0_13_;
                  auVar888[0xd] = bVar114;
                  auVar887._13_3_ = auVar888._13_3_;
                  auVar887._0_12_ = auVar874._0_12_;
                  auVar887[0xc] = *(byte *)((int)puVar535 + 0x37);
                  auVar886._12_4_ = auVar887._12_4_;
                  auVar886._0_11_ = auVar874._0_11_;
                  auVar886[0xb] = bVar113;
                  auVar885._11_5_ = auVar886._11_5_;
                  auVar885._0_10_ = auVar874._0_10_;
                  auVar885[10] = bVar112;
                  auVar884._10_6_ = auVar885._10_6_;
                  auVar884._0_9_ = auVar874._0_9_;
                  auVar884[9] = bVar111;
                  auVar883._9_7_ = auVar884._9_7_;
                  auVar883._0_8_ = auVar874._0_8_;
                  auVar883[8] = *(byte *)((int)puVar535 + 0x27);
                  auVar396._1_8_ = auVar883._8_8_;
                  auVar396[0] = bVar110;
                  auVar396._9_7_ = 0;
                  auVar395._10_6_ = 0;
                  auVar395._0_10_ = SUB1610(auVar396 << 0x38,6);
                  auVar394._11_5_ = 0;
                  auVar394._0_11_ = SUB1611(auVar395 << 0x30,5);
                  auVar393._12_4_ = 0;
                  auVar393._0_12_ = SUB1612(auVar394 << 0x28,4);
                  auVar392._13_3_ = 0;
                  auVar392._0_13_ = SUB1613(auVar393 << 0x20,3);
                  auVar882._14_2_ = 0;
                  auVar882._0_14_ = SUB1614(auVar392 << 0x18,2);
                  auVar882 = auVar882 << 0x10;
                  bVar109 = *(byte *)((int)puVar535 + 0x4f);
                  bVar116 = *(byte *)((int)puVar535 + 0x67);
                  bVar117 = *(byte *)((int)puVar535 + 0x6f);
                  uVar140 = *(uint *)((int)puVar535 + 0x77);
                  uVar141 = *(uint *)((int)puVar535 + 0x7f);
                  local_ec = (undefined1)uVar140;
                  uStack_e8 = (undefined1)*(undefined4 *)((int)puVar535 + 0x7b);
                  uStack_e4 = (undefined1)uVar141;
                  auVar897._0_14_ = auVar882._0_14_;
                  auVar897[0xe] = bVar110;
                  auVar897[0xf] = *(byte *)((int)puVar535 + 99);
                  auVar896._14_2_ = auVar897._14_2_;
                  auVar896._0_13_ = auVar882._0_13_;
                  auVar896[0xd] = bVar100;
                  auVar895._13_3_ = auVar896._13_3_;
                  auVar895._0_12_ = auVar882._0_12_;
                  auVar895[0xc] = bVar101;
                  auVar894._12_4_ = auVar895._12_4_;
                  auVar894._0_11_ = auVar882._0_11_;
                  auVar894[0xb] = *(byte *)((int)puVar535 + 0x5b);
                  auVar893._11_5_ = auVar894._11_5_;
                  auVar893._0_10_ = auVar882._0_10_;
                  auVar893[10] = bVar99;
                  auVar892._10_6_ = auVar893._10_6_;
                  auVar892._0_9_ = auVar882._0_9_;
                  auVar892[9] = bVar98;
                  auVar891._9_7_ = auVar892._9_7_;
                  auVar891._0_8_ = auVar882._0_8_;
                  auVar891[8] = bVar97;
                  auVar401._1_8_ = auVar891._8_8_;
                  auVar401[0] = *(byte *)((int)puVar535 + 0x53);
                  auVar401._9_7_ = 0;
                  auVar400._10_6_ = 0;
                  auVar400._0_10_ = SUB1610(auVar401 << 0x38,6);
                  auVar399._11_5_ = 0;
                  auVar399._0_11_ = SUB1611(auVar400 << 0x30,5);
                  auVar398._12_4_ = 0;
                  auVar398._0_12_ = SUB1612(auVar399 << 0x28,4);
                  auVar397._13_3_ = 0;
                  auVar397._0_13_ = SUB1613(auVar398 << 0x20,3);
                  auVar890._14_2_ = 0;
                  auVar890._0_14_ = SUB1614(auVar397 << 0x18,2);
                  auVar890 = auVar890 << 0x10;
                  auVar905._0_14_ = auVar890._0_14_;
                  auVar905[0xe] = *(byte *)((int)puVar535 + 0x53);
                  auVar905[0xf] = *(byte *)((int)puVar535 + 0x73);
                  auVar904._14_2_ = auVar905._14_2_;
                  auVar904._0_13_ = auVar890._0_13_;
                  auVar904[0xd] = bVar113;
                  auVar903._13_3_ = auVar904._13_3_;
                  auVar903._0_12_ = auVar890._0_12_;
                  auVar903[0xc] = auVar9[0xc];
                  auVar902._12_4_ = auVar903._12_4_;
                  auVar902._0_11_ = auVar890._0_11_;
                  auVar902[0xb] = bVar117;
                  auVar901._11_5_ = auVar902._11_5_;
                  auVar901._0_10_ = auVar890._0_10_;
                  auVar901[10] = bVar109;
                  auVar900._10_6_ = auVar901._10_6_;
                  auVar900._0_9_ = auVar890._0_9_;
                  auVar900[9] = bVar112;
                  auVar899._9_7_ = auVar900._9_7_;
                  auVar899._0_8_ = auVar890._0_8_;
                  auVar899[8] = uVar923;
                  auVar406._1_8_ = auVar899._8_8_;
                  auVar406[0] = *(byte *)((int)puVar535 + 0x6b);
                  auVar406._9_7_ = 0;
                  auVar405._10_6_ = 0;
                  auVar405._0_10_ = SUB1610(auVar406 << 0x38,6);
                  auVar404._11_5_ = 0;
                  auVar404._0_11_ = SUB1611(auVar405 << 0x30,5);
                  auVar403._12_4_ = 0;
                  auVar403._0_12_ = SUB1612(auVar404 << 0x28,4);
                  auVar402._13_3_ = 0;
                  auVar402._0_13_ = SUB1613(auVar403 << 0x20,3);
                  auVar898._14_2_ = 0;
                  auVar898._0_14_ = SUB1614(auVar402 << 0x18,2);
                  auVar898 = auVar898 << 0x10;
                  auVar913._0_14_ = auVar898._0_14_;
                  auVar913[0xe] = *(byte *)((int)puVar535 + 0x6b);
                  auVar913[0xf] = uStack_e8;
                  auVar912._14_2_ = auVar913._14_2_;
                  auVar912._0_13_ = auVar898._0_13_;
                  auVar912[0xd] = *(byte *)((int)puVar535 + 0x5b);
                  auVar911._13_3_ = auVar912._13_3_;
                  auVar911._0_12_ = auVar898._0_12_;
                  auVar911[0xc] = *(byte *)((int)puVar535 + 0x4b);
                  auVar910._12_4_ = auVar911._12_4_;
                  auVar910._0_11_ = auVar898._0_11_;
                  auVar910[0xb] = bVar114;
                  auVar909._11_5_ = auVar910._11_5_;
                  auVar909._0_10_ = auVar898._0_10_;
                  auVar909[10] = bVar111;
                  auVar908._10_6_ = auVar909._10_6_;
                  auVar908._0_9_ = auVar898._0_9_;
                  auVar908[9] = bVar99;
                  auVar907._9_7_ = auVar908._9_7_;
                  auVar907._0_8_ = auVar898._0_8_;
                  auVar907[8] = uVar632;
                  auVar411._1_8_ = auVar907._8_8_;
                  auVar411[0] = local_ec;
                  auVar411._9_7_ = 0;
                  auVar410._10_6_ = 0;
                  auVar410._0_10_ = SUB1610(auVar411 << 0x38,6);
                  auVar409._11_5_ = 0;
                  auVar409._0_11_ = SUB1611(auVar410 << 0x30,5);
                  auVar408._12_4_ = 0;
                  auVar408._0_12_ = SUB1612(auVar409 << 0x28,4);
                  auVar407._13_3_ = 0;
                  auVar407._0_13_ = SUB1613(auVar408 << 0x20,3);
                  auVar906._14_2_ = 0;
                  auVar906._0_14_ = SUB1614(auVar407 << 0x18,2);
                  auVar906 = auVar906 << 0x10;
                  auVar921._0_14_ = auVar906._0_14_;
                  auVar921[0xe] = local_ec;
                  auVar921[0xf] = uStack_e4;
                  auVar920._14_2_ = auVar921._14_2_;
                  auVar920._0_13_ = auVar906._0_13_;
                  auVar920[0xd] = bVar117;
                  auVar919._13_3_ = auVar920._13_3_;
                  auVar919._0_12_ = auVar906._0_12_;
                  auVar919[0xc] = bVar116;
                  auVar918._12_4_ = auVar919._12_4_;
                  auVar918._0_11_ = auVar906._0_11_;
                  auVar918[0xb] = bVar100;
                  auVar917._11_5_ = auVar918._11_5_;
                  auVar917._0_10_ = auVar906._0_10_;
                  auVar917[10] = bVar98;
                  auVar916._10_6_ = auVar917._10_6_;
                  auVar916._0_9_ = auVar906._0_9_;
                  auVar916[9] = bVar109;
                  auVar915._9_7_ = auVar916._9_7_;
                  auVar915._0_8_ = auVar906._0_8_;
                  auVar915[8] = *(byte *)((int)puVar535 + 0x47);
                  auVar416._1_8_ = auVar915._8_8_;
                  auVar416[0] = bVar115;
                  auVar416._9_7_ = 0;
                  auVar415._10_6_ = 0;
                  auVar415._0_10_ = SUB1610(auVar416 << 0x38,6);
                  auVar414._11_5_ = 0;
                  auVar414._0_11_ = SUB1611(auVar415 << 0x30,5);
                  auVar413._12_4_ = 0;
                  auVar413._0_12_ = SUB1612(auVar414 << 0x28,4);
                  auVar412._13_3_ = 0;
                  auVar412._0_13_ = SUB1613(auVar413 << 0x20,3);
                  auVar914._14_2_ = 0;
                  auVar914._0_14_ = SUB1614(auVar412 << 0x18,2);
                  auVar914 = auVar914 << 0x10;
                  uVar151 = CONCAT13(0,CONCAT12(pbVar1[0xb],(ushort)pbVar1[3]));
                  auVar484[0xc] = uStack_101;
                  auVar484._0_12_ = ZEXT112(bVar49) << 0x40;
                  auVar485._10_3_ = auVar484._10_3_;
                  auVar485._0_10_ = (unkuint10)bStack_109 << 0x40;
                  auVar38[4] = pbVar1[0xb];
                  auVar38._0_4_ = uVar151;
                  auVar38[5] = 0;
                  auVar38._6_8_ = SUB148(ZEXT514(auVar485._8_5_) << 0x40,6);
                  uVar149 = CONCAT13(0,CONCAT12(pbVar1[0xf],(ushort)pbVar1[7]));
                  auVar486[0xc] = uStack_fd;
                  auVar486._0_12_ = ZEXT112(bVar53) << 0x40;
                  auVar487._10_3_ = auVar486._10_3_;
                  auVar487._0_10_ = (unkuint10)bStack_105 << 0x40;
                  auVar39[4] = pbVar1[0xf];
                  auVar39._0_4_ = uVar149;
                  auVar39[5] = 0;
                  auVar39._6_8_ = SUB148(ZEXT514(auVar487._8_5_) << 0x40,6);
                  uVar145 = CONCAT13(0,CONCAT12(*(byte *)((int)puVar530 + 0xb),
                                                (ushort)*(byte *)((int)puVar530 + 3)));
                  auVar488[0xc] = *(byte *)((int)puVar530 + 0x1b);
                  auVar488._0_12_ = ZEXT112(bVar87) << 0x40;
                  auVar489._10_3_ = auVar488._10_3_;
                  auVar489._0_10_ = (unkuint10)*(byte *)((int)puVar530 + 0x13) << 0x40;
                  auVar40[4] = *(byte *)((int)puVar530 + 0xb);
                  auVar40._0_4_ = uVar145;
                  auVar40[5] = 0;
                  auVar40._6_8_ = SUB148(ZEXT514(auVar489._8_5_) << 0x40,6);
                  auVar435[0xd] = 0;
                  auVar435._0_13_ = auVar914._0_13_;
                  auVar435[0xe] = bVar115;
                  auVar439[0xc] = *(byte *)((int)puVar535 + 0x37);
                  auVar439._0_12_ = auVar914._0_12_;
                  auVar439._13_2_ = auVar435._13_2_;
                  uVar490 = auVar439._12_3_;
                  auVar491[0xb] = 0;
                  auVar491._0_11_ = auVar914._0_11_;
                  auVar491._12_3_ = uVar490;
                  auVar503[10] = bVar112;
                  auVar503._0_10_ = auVar914._0_10_;
                  auVar503._11_4_ = auVar491._11_4_;
                  auVar507[9] = 0;
                  auVar507._0_9_ = auVar914._0_9_;
                  auVar507._10_5_ = auVar503._10_5_;
                  auVar511[8] = *(byte *)((int)puVar535 + 0x27);
                  auVar511._0_8_ = auVar914._0_8_;
                  auVar511._9_6_ = auVar507._9_6_;
                  Var229 = CONCAT91((unkuint9)auVar511._8_7_ << 8,bVar101);
                  auVar431[10] = 0;
                  auVar431._0_10_ = Var229;
                  auVar418._1_11_ = auVar431 << 8;
                  auVar418[0] = bVar97;
                  auVar430[0xc] = 0;
                  auVar430._0_12_ = auVar418;
                  auVar417._1_13_ = auVar430 << 8;
                  auVar417[0] = uVar923;
                  auVar926[1] = 0;
                  auVar926[0] = auVar9[0];
                  auVar926._2_14_ = auVar417;
                  auVar13._10_2_ = 0;
                  auVar13._0_10_ = auVar926._0_10_;
                  auVar13._12_2_ = (short)Var229;
                  uVar515 = CONCAT42(auVar13._10_4_,auVar418._0_2_);
                  auVar419._6_8_ = 0;
                  auVar419._0_6_ = uVar515;
                  auVar41._4_2_ = auVar417._0_2_;
                  auVar41._0_4_ = auVar926._0_4_;
                  auVar41._6_8_ = SUB148(auVar419 << 0x40,6);
                  uVar146 = CONCAT13(0,CONCAT12(uStack_141,(ushort)bStack_149));
                  auVar492[0xc] = uStack_121;
                  auVar492._0_12_ = ZEXT112(bStack_139) << 0x40;
                  auVar493._10_3_ = auVar492._10_3_;
                  auVar493._0_10_ = (unkuint10)bStack_129 << 0x40;
                  auVar42[4] = uStack_141;
                  auVar42._0_4_ = uVar146;
                  auVar42[5] = 0;
                  auVar42._6_8_ = SUB148(ZEXT514(auVar493._8_5_) << 0x40,6);
                  uVar152 = CONCAT13(0,CONCAT12(uStack_13d,(ushort)bStack_145));
                  auVar494[0xc] = uStack_11d;
                  auVar494._0_12_ = ZEXT112(bStack_135) << 0x40;
                  auVar495._10_3_ = auVar494._10_3_;
                  auVar495._0_10_ = (unkuint10)bStack_125 << 0x40;
                  auVar43[4] = uStack_13d;
                  auVar43._0_4_ = uVar152;
                  auVar43[5] = 0;
                  auVar43._6_8_ = SUB148(ZEXT514(auVar495._8_5_) << 0x40,6);
                  uVar156 = CONCAT13(0,CONCAT12(*(byte *)((int)puVar530 + 0x4b),
                                                (ushort)*(byte *)((int)puVar530 + 0x43)));
                  auVar496[0xc] = *(byte *)((int)puVar530 + 0x5b);
                  auVar496._0_12_ = ZEXT112(bVar95) << 0x40;
                  auVar497._10_3_ = auVar496._10_3_;
                  auVar497._0_10_ = (unkuint10)*(byte *)((int)puVar530 + 0x53) << 0x40;
                  auVar44[4] = *(byte *)((int)puVar530 + 0x4b);
                  auVar44._0_4_ = uVar156;
                  auVar44[5] = 0;
                  auVar44._6_8_ = SUB148(ZEXT514(auVar497._8_5_) << 0x40,6);
                  uVar160 = CONCAT13(0,CONCAT12(bVar109,(ushort)*(byte *)((int)puVar535 + 0x47)));
                  auVar498[0xc] = bVar100;
                  auVar498._0_12_ = ZEXT112(bVar116) << 0x40;
                  auVar499._10_3_ = auVar498._10_3_;
                  auVar499._0_10_ = (unkuint10)bVar98 << 0x40;
                  auVar45[4] = bVar109;
                  auVar45._0_4_ = uVar160;
                  auVar45[5] = 0;
                  auVar45._6_8_ = SUB148(ZEXT514(auVar499._8_5_) << 0x40,6);
                  pbVar1 = (byte *)((int)puVar525 + iVar523);
                  *pbVar1 = (byte)((int)((uVar142 & 0xffff) + (uVar157 & 0xffff) +
                                         (uVar161 & 0xffff) + (auVar925._0_4_ & 0xffff)) >> 2);
                  pbVar1[1] = (byte)((int)((uVar158 & 0xffff) + (uVar143 & 0xffff) +
                                           (uVar162 & 0xffff) + (auVar825._0_4_ & 0xffff)) >> 2);
                  pbVar1[2] = (byte)((int)((uVar155 & 0xffff) + (uVar148 & 0xffff) +
                                           (uVar159 & 0xffff) + (auVar922._0_4_ & 0xffff)) >> 2);
                  pbVar1[3] = (byte)((int)((uVar151 & 0xffff) + (uVar149 & 0xffff) +
                                           (uVar145 & 0xffff) + (auVar926._0_4_ & 0xffff)) >> 2);
                  pbVar1[4] = (byte)(auVar14._4_4_ + auVar15._4_4_ + auVar16._4_4_ + auVar17._4_4_
                                    >> 2);
                  pbVar1[5] = (byte)(auVar23._4_4_ + auVar22._4_4_ + auVar24._4_4_ + auVar25._4_4_
                                    >> 2);
                  pbVar1[6] = (byte)(auVar31._4_4_ + auVar30._4_4_ + auVar32._4_4_ + auVar33._4_4_
                                    >> 2);
                  pbVar1[7] = (byte)(auVar38._4_4_ + auVar39._4_4_ + auVar40._4_4_ + auVar41._4_4_
                                    >> 2);
                  pbVar1[8] = (byte)(auVar441._8_4_ + auVar443._8_4_ + auVar445._8_4_ + (int)uVar512
                                    >> 2);
                  pbVar1[9] = (byte)(auVar459._8_4_ + auVar457._8_4_ + auVar461._8_4_ + (int)uVar513
                                    >> 2);
                  pbVar1[10] = (byte)(auVar473._8_4_ + auVar471._8_4_ + auVar475._8_4_ +
                                      (int)uVar514 >> 2);
                  pbVar1[0xb] = (byte)(auVar485._8_4_ + auVar487._8_4_ + auVar489._8_4_ +
                                       (int)uVar515 >> 2);
                  pbVar1[0xc] = (byte)((int)((uint)(uint3)(auVar440._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar442._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar444._10_3_ >> 0x10) +
                                            (auVar10._10_4_ >> 0x10)) >> 2);
                  pbVar1[0xd] = (byte)((int)((uint)(uint3)(auVar458._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar456._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar460._10_3_ >> 0x10) +
                                            (auVar11._10_4_ >> 0x10)) >> 2);
                  pbVar1[0xe] = (byte)((int)((uint)(uint3)(auVar472._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar470._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar474._10_3_ >> 0x10) +
                                            (auVar12._10_4_ >> 0x10)) >> 2);
                  pbVar1[0xf] = (byte)((int)((uint)(uint3)(auVar484._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar486._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar488._10_3_ >> 0x10) +
                                            (auVar13._10_4_ >> 0x10)) >> 2);
                  local_a0 = local_a0 + 1;
                  pbVar1 = (byte *)((int)puVar525 + iVar523 + 0x10);
                  *pbVar1 = (byte)((int)((uint)bVar50 + (uint)bVar46 + (uint)bVar63 +
                                        (uint)auVar508._8_2_) >> 2);
                  pbVar1[1] = (byte)((int)((uint)bVar51 + (uint)bVar47 + (uint)bVar62 +
                                          (uint)auVar509._8_2_) >> 2);
                  pbVar1[2] = (byte)((int)((uint)bVar52 + (uint)bVar48 + (uint)bVar78 +
                                          (uint)auVar510._8_2_) >> 2);
                  pbVar1[3] = (byte)((int)((uint)bVar53 + (uint)bVar49 + (uint)bVar87 +
                                          (uint)auVar511._8_2_) >> 2);
                  pbVar1[4] = (byte)((int)((uint)bVar58 + (uint)bVar54 + (uint)bVar64 +
                                          (uint)auVar500._10_2_) >> 2);
                  pbVar1[5] = (byte)((int)((uint)bVar59 + (uint)bVar55 + (uint)bVar67 +
                                          (uint)auVar501._10_2_) >> 2);
                  pbVar1[6] = (byte)((int)((uint)bVar60 + (uint)bVar56 + (uint)bVar79 +
                                          (uint)auVar502._10_2_) >> 2);
                  pbVar1[7] = (byte)((int)((uint)bVar61 + (uint)bVar57 + (uint)bVar88 +
                                          (uint)auVar503._10_2_) >> 2);
                  pbVar1[8] = (byte)((int)((uint)bStack_158 + (uint)bVar516 + (uint)bVar65 +
                                          (uVar446 & 0xffff)) >> 2);
                  pbVar1[9] = (byte)((int)((uint)bStack_157 + (uint)bVar518 + (uint)bVar75 +
                                          (uVar462 & 0xffff)) >> 2);
                  pbVar1[10] = (byte)((int)((uint)bStack_156 + (uint)bVar519 + (uint)bVar80 +
                                           (uVar476 & 0xffff)) >> 2);
                  pbVar1[0xb] = (byte)((int)((uint)bStack_155 + (uint)bVar520 + (uint)bVar89 +
                                            (uVar490 & 0xffff)) >> 2);
                  pbVar1[0xc] = (byte)((int)((uVar534 & 0xff) + (uint)bStack_154 + (uint)bVar66 +
                                            (uint)(uVar446 >> 0x10)) >> 2);
                  pbVar1[0xd] = (byte)((int)((uVar534 >> 8 & 0xff) + (uint)bStack_153 + (uint)bVar70
                                            + (uint)(uVar462 >> 0x10)) >> 2);
                  pbVar1[0xe] = (byte)((int)((uVar534 >> 0x10 & 0xff) + (uint)bStack_152 +
                                             (uint)bVar81 + (uint)(uVar476 >> 0x10)) >> 2);
                  pbVar1[0xf] = (byte)((int)((uVar534 >> 0x18) + (uint)bStack_151 + (uint)bVar102 +
                                            (uint)(uVar490 >> 0x10)) >> 2);
                  pbVar1 = (byte *)((int)puVar525 + iVar523 + 0x20);
                  *pbVar1 = (byte)((int)((uVar153 & 0xffff) + (local_15c & 0xffff) +
                                         (uVar164 & 0xffff) + (uVar166 & 0xffff)) >> 2);
                  pbVar1[1] = (byte)((int)((uVar154 & 0xffff) + (uVar147 & 0xffff) +
                                           (uVar165 & 0xffff) +
                                          (CONCAT12(bVar90,(ushort)bVar83) & 0xffff)) >> 2);
                  pbVar1[2] = (byte)((int)((uVar150 & 0xffff) + (uVar144 & 0xffff) +
                                           (uVar163 & 0xffff) +
                                          (CONCAT12(bVar104,(ushort)bVar103) & 0xffff)) >> 2);
                  pbVar1[3] = (byte)((int)((uVar146 & 0xffff) + (uVar152 & 0xffff) +
                                           (uVar156 & 0xffff) + (uVar160 & 0xffff)) >> 2);
                  pbVar1[4] = (byte)(auVar18._4_4_ + auVar19._4_4_ + auVar20._4_4_ + auVar21._4_4_
                                    >> 2);
                  pbVar1[5] = (byte)(auVar27._4_4_ + auVar26._4_4_ + auVar28._4_4_ + auVar29._4_4_
                                    >> 2);
                  pbVar1[6] = (byte)(auVar34._4_4_ + auVar35._4_4_ + auVar36._4_4_ + auVar37._4_4_
                                    >> 2);
                  pbVar1[7] = (byte)(auVar42._4_4_ + auVar43._4_4_ + auVar44._4_4_ + auVar45._4_4_
                                    >> 2);
                  pbVar1[8] = (byte)(auVar449._8_4_ + auVar451._8_4_ + auVar453._8_4_ +
                                     auVar455._8_4_ >> 2);
                  pbVar1[9] = (byte)(auVar467._8_4_ + auVar465._8_4_ + auVar469._8_4_ +
                                     auVar425._8_4_ >> 2);
                  pbVar1[10] = (byte)(auVar479._8_4_ + auVar481._8_4_ + auVar483._8_4_ +
                                      auVar429._8_4_ >> 2);
                  pbVar1[0xb] = (byte)(auVar493._8_4_ + auVar495._8_4_ + auVar497._8_4_ +
                                       auVar499._8_4_ >> 2);
                  pbVar1[0xc] = (byte)((int)((uint)(uint3)(auVar448._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar450._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar452._10_3_ >> 0x10) +
                                            (uint)(uint3)(auVar454._10_3_ >> 0x10)) >> 2);
                  pbVar1[0xd] = (byte)((int)((uint)(uint3)(auVar466._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar464._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar468._10_3_ >> 0x10) +
                                            (uint)(uint3)(auVar424._10_3_ >> 0x10)) >> 2);
                  pbVar1[0xe] = (byte)((int)((uint)(uint3)(auVar478._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar480._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar482._10_3_ >> 0x10) +
                                            (uint)(uint3)(auVar428._10_3_ >> 0x10)) >> 2);
                  pbVar1[0xf] = (byte)((int)((uint)(uint3)(auVar492._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar494._10_3_ >> 0x10) +
                                             (uint)(uint3)(auVar496._10_3_ >> 0x10) +
                                            (uint)(uint3)(auVar498._10_3_ >> 0x10)) >> 2);
                  pbVar1 = (byte *)((int)puVar525 + iVar523 + 0x30);
                  *pbVar1 = (byte)((int)((uVar126 & 0xff) + (uVar127 & 0xff) + (uint)bVar68 +
                                        (uint)bVar73) >> 2);
                  pbVar1[1] = (byte)((int)((uint)bStack_13b + (uint)bStack_137 + (uint)bVar76 +
                                          (uint)bVar91) >> 2);
                  pbVar1[2] = (byte)((int)((uint)bStack_136 + (uint)bStack_13a + (uint)bVar82 +
                                          (uint)bVar105) >> 2);
                  pbVar1[3] = (byte)((int)((uint)bStack_135 + (uint)bStack_139 + (uint)bVar95 +
                                          (uint)bVar116) >> 2);
                  pbVar1[4] = (byte)((int)((uVar517 & 0xff) + (uVar129 & 0xff) + (uint)bVar69 +
                                          (uint)bVar74) >> 2);
                  pbVar1[5] = (byte)((int)((uint)bStack_133 + (uVar129 >> 8 & 0xff) + (uint)bVar71 +
                                          (uint)bVar92) >> 2);
                  pbVar1[6] = (byte)((int)((uVar129 >> 0x10 & 0xff) + (uVar128 >> 0x10 & 0xff) +
                                           (uint)bVar84 + (uint)bVar106) >> 2);
                  pbVar1[7] = (byte)((int)((uVar129 >> 0x18) + (uVar128 >> 0x18) + (uint)bVar96 +
                                          (uint)bVar117) >> 2);
                  pbVar1[8] = (byte)((int)((uVar130 & 0xff) + (uVar131 & 0xff) + (uVar134 & 0xff) +
                                          (uVar136 & 0xff)) >> 2);
                  pbVar1[9] = (byte)((int)((uVar130 >> 8 & 0xff) + (uVar131 >> 8 & 0xff) +
                                           (uint)bVar77 + (uint)bVar93) >> 2);
                  pbVar1[10] = (byte)((int)((uVar131 >> 0x10 & 0xff) + (uVar130 >> 0x10 & 0xff) +
                                            (uint)bVar85 + (uint)bVar107) >> 2);
                  pbVar1[0xb] = (byte)((int)((uVar131 >> 0x18) + (uVar130 >> 0x18) +
                                             (uVar138 & 0xff) + (uVar140 & 0xff)) >> 2);
                  pbVar1[0xc] = (byte)((int)(((uVar517 & 0xff00) >> 8) + (uVar133 & 0xff) +
                                             (uVar135 & 0xff) + (uVar137 & 0xff)) >> 2);
                  pbVar1[0xd] = (byte)((int)((uVar132 >> 8 & 0xff) + (uVar133 >> 8 & 0xff) +
                                             (uint)bVar72 + (uint)bVar94) >> 2);
                  pbVar1[0xe] = (byte)((int)((uVar133 >> 0x10 & 0xff) + (uVar132 >> 0x10 & 0xff) +
                                             (uint)bVar86 + (uint)bVar108) >> 2);
                  pbVar1[0xf] = (byte)((int)((uVar133 >> 0x18) + (uVar132 >> 0x18) +
                                             (uVar139 & 0xff) + (uVar141 & 0xff)) >> 2);
                  iVar523 = iVar523 + 0x40;
                  puVar528 = puVar528 + 0x20;
                  local_d0 = local_d0 + 0x20;
                  puVar524 = puVar524 + 0x20;
                  local_d4 = local_d4 + 0x20;
                  puVar531 = puVar531 + 0x20;
                  puVar530 = puVar530 + 0x20;
                  puVar535 = puVar535 + 0x20;
                } while (local_a0 < uVar522);
                iVar523 = uVar522 * 0x80;
                puVar527 = puVar527 + uVar522 * 0x20;
                puVar525 = puVar525 + uVar522 * 0x10;
                if (uVar533 == uVar522 * 0x10) goto LAB_001b74fc;
                puVar532 = puVar527 + (int)local_4c[0];
              }
              do {
                iVar523 = iVar523 + 8;
                *(byte *)puVar525 =
                     (byte)((int)((uint)(byte)puVar532[1] +
                                 (uint)(byte)*puVar527 + (uint)(byte)puVar527[1] +
                                 (uint)(byte)*puVar532) >> 2);
                *(byte *)((int)puVar525 + 1) =
                     (byte)((int)((uint)*(byte *)((int)puVar532 + 5) +
                                 (uint)*(byte *)((int)puVar527 + 1) +
                                 (uint)*(byte *)((int)puVar527 + 5) +
                                 (uint)*(byte *)((int)puVar532 + 1)) >> 2);
                *(byte *)((int)puVar525 + 2) =
                     (byte)((int)((uint)*(byte *)((int)puVar532 + 6) +
                                 (uint)*(byte *)((int)puVar527 + 2) +
                                 (uint)*(byte *)((int)puVar527 + 6) +
                                 (uint)*(byte *)((int)puVar532 + 2)) >> 2);
                pbVar1 = (byte *)((int)puVar527 + 7);
                pbVar2 = (byte *)((int)puVar527 + 3);
                puVar527 = puVar527 + 2;
                pbVar5 = (byte *)((int)puVar532 + 3);
                pbVar6 = (byte *)((int)puVar532 + 7);
                puVar532 = puVar532 + 2;
                *(byte *)((int)puVar525 + 3) =
                     (byte)((int)((uint)*pbVar6 + (uint)*pbVar2 + (uint)*pbVar1 + (uint)*pbVar5) >>
                           2);
                puVar525 = puVar525 + 1;
              } while (iVar523 < iVar521);
            }
LAB_001b74fc:
            local_74 = local_74 + 1;
            puVar527 = puVar529 + (int)local_4c[0];
            puVar525 = puVar526;
          } while (local_74 != local_3c[0]);
        }
        local_4c[0] = (uint *)((int)local_4c[0] >> 1);
        if ((int)local_4c[0] < 1) {
          local_4c[0] = (uint *)0x1;
        }
        if (local_3c[0] < 1) {
          local_3c[0] = 1;
        }
        local_5c = local_5c + 1;
        texels = texels + local_3c[0] * (int)local_4c[0];
        (*qglTexImage2D)(0xde1,local_5c,local_58,(GLsizei)local_4c[0],local_3c[0],0,local_54,0x1401,
                         GL_Upload32::scaled);
      }
      (*qglTexParameterf)(0xde1,0x2801,(float)gl_filter_min);
      (*qglTexParameterf)(0xde1,0x2800,(float)gl_filter_max);
      goto LAB_001b5834;
    }
    (*qglTexImage2D)(0xde1,0,local_58,width,height,0,local_54,0x1401,data);
  }
  else {
    if (iType == 2) {
      GL_ResampleAlphaTexture((uchar *)data,width,height,(uchar *)local_4c[0],local_3c[0],(int)bpp);
    }
    else {
      GL_ResampleTexture(data,width,height,local_4c[0],local_3c[0],(int)bpp);
    }
    texels = texels + (int)local_4c[0] * local_3c[0];
    (*qglTexImage2D)(0xde1,0,local_58,(GLsizei)local_4c[0],local_3c[0],0,local_54,0x1401,
                     GL_Upload32::scaled);
    if (mipmap != false) goto LAB_001b58ff;
  }
  (*qglTexParameterf)(0xde1,0x2801,(float)filter);
  (*qglTexParameterf)(0xde1,0x2800,(float)filter);
LAB_001b5834:
  (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
  return;
}


