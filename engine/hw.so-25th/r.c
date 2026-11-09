// r_prefertexturefiltering_hook_callback  @ 001ba280
void r_prefertexturefiltering_hook_callback(cvar_t *cvar)

{
  if (cvar != (cvar_t *)0x0) {
    if (cvar->value != 0.0) {
      Cvar_Set("gl_texturemode","GL_LINEAR_MIPMAP_LINEAR");
      return;
    }
    Cvar_Set("gl_texturemode","GL_NEAREST");
  }
  return;
}


