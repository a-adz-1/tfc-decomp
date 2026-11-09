// gl_texturemode_hook_callback  @ 00159070
void gl_texturemode_hook_callback(cvar_t *cvar)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  gltexture_t *pgVar6;
  quake_mode_t *pqVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: gltexture_t * glt@[???]
                       Unresolved local var: char * mode@[???]
                       Unresolved local var: qboolean bPreferFiltering@[???]
                       Unresolved local var: qboolean bNearestFilteringSelected@[???] */
  if (cvar != (cvar_t *)0x0) {
    pcVar1 = cvar->string;
    pqVar7 = modes;
    iVar5 = 0;
    while (iVar3 = Q_strcasecmp(pqVar7->name,pcVar1), iVar3 != 0) {
      iVar5 = iVar5 + 1;
      pqVar7 = pqVar7 + 1;
      if (iVar5 == 6) {
        Con_Printf("bad filter name\n");
        return;
      }
    }
    iVar3 = 0;
    pgVar6 = gltextures;
    gl_filter_min = modes[iVar5].minimize;
    gl_filter_max = modes[iVar5].maximize;
    iVar5 = numgltextures;
    if (0 < numgltextures) {
      do {
        while (pgVar6->mipmap == false) {
          iVar3 = iVar3 + 1;
          pgVar6 = pgVar6 + 1;
          if (iVar5 <= iVar3) goto LAB_001591fa;
        }
                    /* Unresolved local var: int paletteIndex@[???] */
        uVar4 = pgVar6->texnum & 0xffff;
        if (uVar4 != currenttexture) {
          iVar5 = (pgVar6->texnum >> 0x10) + -1;
          currenttexture = uVar4;
          (*qglBindTexture)(0xde1,uVar4);
          if (((-1 < iVar5) && (iVar5 != g_currentpalette)) &&
             (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
            g_currentpalette = iVar5;
            (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,(void *)(iVar5 * 0x308 + 0xdfa368)
                               );
          }
        }
        iVar3 = iVar3 + 1;
        pgVar6 = pgVar6 + 1;
        (*qglTexParameterf)(0xde1,0x2801,(float)gl_filter_min);
        (*qglTexParameterf)(0xde1,0x2800,(float)gl_filter_max);
        (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
        iVar5 = numgltextures;
      } while (iVar3 < numgltextures);
    }
LAB_001591fa:
    bVar2 = r_prefertexturefiltering.value == 1.0;
    iVar5 = Q_strcasecmp(pcVar1,"GL_NEAREST");
    if ((iVar5 == 0) && (bVar2)) {
      Cvar_Set("r_prefertexturefiltering","0");
    }
  }
  return;
}


