// tri_BoxinPVS  @ 001c04a0
int tri_BoxinPVS(float *mins,float *maxs)

{
  mnode_t *pmVar1;
  
  pmVar1 = PVSNode((cl.worldmodel)->nodes,mins,maxs);
  return (uint)(pmVar1 != (mnode_t *)0x0);
}


// tri_GL_Begin  @ 001c0400
void tri_GL_Begin(int primitiveCode)

{
  VGUI2_ResetCurrentTexture();
                    /* WARNING: Could not recover jumptable at 0x001c041c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglBegin)(g_GL_Modes[primitiveCode]);
  return;
}


// tri_GL_Brightness  @ 001c0250
void tri_GL_Brightness(float x)

{
  (*qglColor4f)(x * gGlR * gGlW,gGlG * x * gGlW,gGlB * x * gGlW,1.0);
  return;
}


// tri_GL_Color4f  @ 001c00c0
void tri_GL_Color4f(float x,float y,float z,float w)

{
  if (gRenderMode == 4) {
                    /* Unresolved local var: float alpha@[???] */
    (*qglColor4ub)((GLubyte)(int)(x * 255.9),(GLubyte)(int)(y * 255.9),(GLubyte)(int)(z * 255.9),
                   (GLubyte)(int)(w * 255.0));
  }
  else {
    (*qglColor4f)(w * x,w * y,w * z,1.0);
  }
  gGlR = x;
  gGlG = y;
  gGlB = z;
  gGlW = w;
  return;
}


// tri_GL_Color4fRendermode  @ 001c05d0
void tri_GL_Color4fRendermode(float x,float y,float z,float w,int rendermode)

{
  if (rendermode != 4) {
                    /* WARNING: Could not recover jumptable at 0x001c060b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglColor4f)(w * x,y * w,z * w,1.0);
    return;
  }
  gGlW = w * 0.003921569;
                    /* WARNING: Could not recover jumptable at 0x001c062f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglColor4f)(x,y,z,w);
  return;
}


// tri_GL_Color4ub  @ 001c01b0
void tri_GL_Color4ub(byte r,byte g,byte b,byte a)

{
  gGlR = (float)r * 0.003921569;
  gGlG = (float)g * 0.003921569;
  gGlB = (float)b * 0.003921569;
  gGlW = (float)a * 0.003921569;
                    /* WARNING: Could not recover jumptable at 0x001c0246. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglColor4f)(gGlR,gGlG,gGlB,1.0);
  return;
}


// tri_GL_CullFace  @ 001c0640
void tri_GL_CullFace(TRICULLSTYLE style)

{
  if (style == TRI_FRONT) {
    (*qglEnable)(0xb44);
                    /* WARNING: Could not recover jumptable at 0x001c0681. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglCullFace)(0x404);
    return;
  }
  if (style == TRI_NONE) {
                    /* WARNING: Could not recover jumptable at 0x001c065a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*qglDisable)(0xb44);
    return;
  }
  return;
}


// tri_GL_End  @ 001c0080
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void tri_GL_End(void)

{
                    /* WARNING: Could not recover jumptable at 0x001c0080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglEnd)();
  return;
}


// tri_GL_RenderMode  @ 001c02a0
void tri_GL_RenderMode(int mode)

{
  switch(mode) {
  case 0:
    (*qglDisable)(0xbe2);
    (*qglDepthMask)('\x01');
    (*qglShadeModel)(0x1d00);
    gRenderMode = mode;
    return;
  case 1:
  case 2:
    (*qglBlendFunc)(0x302,0x303);
    (*qglEnable)(0xbe2);
    (*qglShadeModel)(0x1d01);
    break;
  case 4:
    (*qglEnable)(0xbe2);
    (*qglTexEnvf)(0x2300,0x2200,8448.0);
    (*qglBlendFunc)(0x302,0x303);
    (*qglShadeModel)(0x1d01);
    (*qglDepthMask)('\0');
    gRenderMode = mode;
    return;
  case 5:
    (*qglBlendFunc)(1,1);
    (*qglEnable)(0xbe2);
    (*qglDepthMask)('\0');
    (*qglShadeModel)(0x1d01);
    gRenderMode = mode;
    return;
  }
  gRenderMode = mode;
  return;
}


// tri_GL_TexCoord2f  @ 001c0090
void tri_GL_TexCoord2f(float u,float v)

{
                    /* WARNING: Could not recover jumptable at 0x001c0090. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglTexCoord2f)(u,v);
  return;
}


// tri_GL_Vertex3f  @ 001c00b0
void tri_GL_Vertex3f(float x,float y,float z)

{
                    /* WARNING: Could not recover jumptable at 0x001c00b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglVertex3f)(x,y,z);
  return;
}


// tri_GL_Vertex3fv  @ 001c00a0
void tri_GL_Vertex3fv(float *worldPnt)

{
                    /* WARNING: Could not recover jumptable at 0x001c00a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglVertex3fv)(worldPnt);
  return;
}


// tri_GetMatrix  @ 001c03f0
void tri_GetMatrix(int pname,float *matrix)

{
                    /* WARNING: Could not recover jumptable at 0x001c03f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglGetFloatv)(pname,matrix);
  return;
}


// tri_LightAtPoint  @ 001c04e0
void tri_LightAtPoint(float *vPos,float *value)

{
  colorVec local_1c;
  
                    /* Unresolved local var: colorVec vLightColor@[???] */
  R_LightPoint(&local_1c,vPos);
  *value = (float)local_1c.r;
  value[1] = (float)local_1c.g;
  value[2] = (float)local_1c.b;
  return;
}


// tri_ScreenTransform  @ 001c0480
int tri_ScreenTransform(float *world,float *screen)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = gWorldToScreen[8] * world[2] + gWorldToScreen[4] * world[1] + gWorldToScreen[0] * *world +
          gWorldToScreen[0xc];
  *screen = fVar1;
  fVar3 = gWorldToScreen[9] * world[2] + gWorldToScreen[5] * world[1] + gWorldToScreen[1] * *world +
          gWorldToScreen[0xd];
  screen[1] = fVar3;
  fVar2 = gWorldToScreen[0xb] * world[2] + gWorldToScreen[7] * world[1] + gWorldToScreen[3] * *world
          + gWorldToScreen[0xf];
  if (fVar2 != 0.0) {
    fVar2 = 1.0 / fVar2;
    *screen = fVar1 * fVar2;
    screen[1] = fVar3 * fVar2;
  }
  return (uint)(fVar2 <= 0.0);
}


// tri_WorldTransform  @ 001c0490
void tri_WorldTransform(float *screen,float *world)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = gScreenToWorld[8] * screen[2] +
          gScreenToWorld[4] * screen[1] + gScreenToWorld[0] * *screen + gScreenToWorld[0xc];
  *world = fVar1;
  fVar4 = gScreenToWorld[9] * screen[2] +
          gScreenToWorld[5] * screen[1] + gScreenToWorld[1] * *screen + gScreenToWorld[0xd];
  world[1] = fVar4;
  fVar3 = gScreenToWorld[0xe] +
          gScreenToWorld[10] * screen[2] +
          gScreenToWorld[6] * screen[1] + gScreenToWorld[2] * *screen;
  world[2] = fVar3;
  fVar2 = gScreenToWorld[0xb] * screen[2] +
          gScreenToWorld[7] * screen[1] + gScreenToWorld[3] * *screen + gScreenToWorld[0xf];
  if (fVar2 != 0.0) {
    fVar2 = 1.0 / fVar2;
    *world = fVar1 * fVar2;
    world[1] = fVar4 * fVar2;
    world[2] = fVar3 * fVar2;
  }
  return;
}


