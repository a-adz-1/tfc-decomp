// gl_texturemode_hook_callback  @ 001b0e20
void gl_texturemode_hook_callback(cvar_t *cvar)

{
  char *s2;
  int iVar1;
  uint uVar2;
  gltexture_t *pgVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: gltexture_t * glt@[???]
                       Unresolved local var: char * mode@[???] */
  if (cvar != (cvar_t *)0x0) {
    s2 = cvar->string;
    iVar1 = Q_strcasecmp(modes[0].name,s2);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = Q_strcasecmp(modes[1].name,s2);
      if (iVar1 == 0) {
        iVar1 = 1;
      }
      else {
        iVar1 = Q_strcasecmp(modes[2].name,s2);
        if (iVar1 == 0) {
          iVar1 = 2;
        }
        else {
          iVar1 = Q_strcasecmp(modes[3].name,s2);
          if (iVar1 == 0) {
            iVar1 = 3;
          }
          else {
            iVar1 = Q_strcasecmp(modes[4].name,s2);
            if (iVar1 == 0) {
              iVar1 = 4;
            }
            else {
              iVar1 = Q_strcasecmp(modes[5].name,s2);
              if (iVar1 != 0) {
                Con_Printf("bad filter name\n");
                return;
              }
              iVar1 = 5;
            }
          }
        }
      }
    }
    gl_filter_min = modes[iVar1].minimize;
    gl_filter_max = modes[iVar1].maximize;
    if (0 < numgltextures) {
      pgVar3 = gltextures;
      iVar4 = 0;
      iVar1 = numgltextures;
      do {
        if (pgVar3->mipmap != false) {
                    /* Unresolved local var: int paletteIndex@[???] */
          uVar2 = pgVar3->texnum & 0xffff;
          if (uVar2 != currenttexture) {
            iVar1 = (pgVar3->texnum >> 0x10) + -1;
            currenttexture = uVar2;
            (*qglBindTexture)(0xde1,uVar2);
            if (((-1 < iVar1) && (iVar1 != g_currentpalette)) &&
               (qglColorTableEXT != (_func_void_int_int_int_int_int_void_ptr *)0x0)) {
              g_currentpalette = iVar1;
              (*qglColorTableEXT)(0x81fb,0x1907,0x100,0x1907,0x1401,
                                  (void *)(iVar1 * 0x308 + 0xe0c1a8));
            }
          }
          (*qglTexParameterf)(0xde1,0x2801,(float)gl_filter_min);
          (*qglTexParameterf)(0xde1,0x2800,(float)gl_filter_max);
          (*qglTexParameterf)(0xde1,0x84fe,gl_ansio.value);
          iVar1 = numgltextures;
        }
        iVar4 = iVar4 + 1;
        pgVar3 = pgVar3 + 1;
      } while (iVar4 < iVar1);
    }
  }
  return;
}


