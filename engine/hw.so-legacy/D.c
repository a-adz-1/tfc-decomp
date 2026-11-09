// D_FillRect  @ 001d13c0
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
  (*qglVertex2f)((float)(r->x + r->width),(float)r->y);
  (*qglVertex2f)((float)(r->x + r->width),(float)(r->y + r->height));
  (*qglVertex2f)((float)r->x,(float)(r->y + r->height));
  (*qglEnd)();
  (*qglDisable)(0xbc0);
  (*qglEnable)(0xb71);
  (*qglColor3f)(1.0,1.0,1.0);
  (*qglEnable)(0xde1);
                    /* WARNING: Could not recover jumptable at 0x001d155c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*qglDisable)(0xbe2);
  return;
}


// D_FlushCaches  @ 0020b1f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void D_FlushCaches(void)

{
  return;
}


// D_SetFadeColor  @ 001dfce0
void D_SetFadeColor(int r,int g,int b,int fog)

{
  gWaterColor.r = r;
  gWaterColor.g = g;
  gWaterColor.b = b;
  cshift_water.percent = fog;
  cshift_water.destcolor[2] = b;
  cshift_water.destcolor[1] = g;
  cshift_water.destcolor[0] = r;
  return;
}


