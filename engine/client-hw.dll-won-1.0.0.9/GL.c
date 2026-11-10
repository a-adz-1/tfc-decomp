// GL_Init  @ 10083620
void GL_Init(void)

{
                    /* 0x83620  19  GL_Init */
  DAT_10559ff0 = (*DAT_10999d88)(0x1f00);
  Con_DPrintf(s_GL_VENDOR___s_100dabbc,DAT_10559ff0);
  DAT_1055a034 = (*DAT_10999d88)(0x1f01);
  Con_DPrintf(s_GL_RENDERER___s_100dabcc,DAT_1055a034);
  DAT_1055a03c = (*DAT_10999d88)(0x1f02);
  Con_DPrintf(s_GL_VERSION___s_100dabe0,DAT_1055a03c);
  DAT_10559ff8 = (*DAT_10999d88)(0x1f03);
  Con_DPrintf(s_GL_EXTENSIONS___s_100dabf0,DAT_10559ff8);
  FUN_100830e0();
  FUN_10083250();
  (*DAT_10999fe0)(0x3f800000,0,0,0);
  (*DAT_10999fc4)(0x404);
  (*DAT_10999890)(0xde1);
  (*DAT_10999890)(0xbc0);
  (*DAT_109999d8)(0x205,0);
  (*DAT_10999b48)(0x408,0x1b02);
  (*DAT_1099a018)(0x1d00);
  (*DAT_10999cac)(0xde1,0x2801,0x46180000);
  (*DAT_10999cac)(0xde1,0x2800,0x46180000);
  (*DAT_10999cac)(0xde1,0x2802,0x46240400);
  (*DAT_10999cac)(0xde1,0x2803,0x46240400);
  (*DAT_10999d4c)(0x302,0x303);
  (*DAT_109997e8)(0x2300,0x2200,0x45f00800);
  FUN_10083360();
  return;
}


// GL_SetMode  @ 10083960
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 GL_SetMode(HWND param_1,undefined4 *param_2,int *param_3,int param_4,int param_5)

{
  HMODULE hLibModule;
  HDC pHVar1;
  int iVar2;
  HWND unaff_EBX;
  
                    /* 0x83960  20  GL_SetMode */
  DAT_10559ff4 = 0;
  if (param_4 != 0) {
    DAT_100da55c = 1;
    _DAT_100da554 = 0x3f800000;
  }
  *param_3 = 0;
  *param_2 = 0;
  if (param_4 == 0) {
    if (param_5 != 0) {
      iVar2 = FUN_100a31a0(param_5,s_opengl32_100dac90);
      DAT_10559ff4 = 0;
      if (iVar2 == 0) {
        DAT_10559ff4 = 1;
      }
    }
    hLibModule = (HMODULE)FUN_1004afb0(param_5);
  }
  else {
    hLibModule = (HMODULE)QGL_D3DInit(0);
  }
  if (hLibModule == (HMODULE)0x0) {
    if (param_5 == 0) {
      FUN_10085dc0(s_Error_initializing_gl_driver__ch_100dac9c);
    }
    else {
      FUN_10085dc0(s_Error_initializing_gl_driver__ch_100dacec,param_5);
    }
  }
  else {
    pHVar1 = GetDC(param_1);
    *param_2 = pHVar1;
    iVar2 = FUN_10083830(pHVar1);
    if (iVar2 != 0) {
      Sleep(100);
      iVar2 = (*qwglCreateContext)(*param_2);
      *param_3 = iVar2;
      if (iVar2 != 0) {
        Sleep(100);
        iVar2 = (*qwglMakeCurrent)(*param_2,*param_3);
        if (iVar2 != 0) {
          Sleep(100);
          return 1;
        }
      }
    }
  }
  if (hLibModule != (HMODULE)0x0) {
    (*qwglMakeCurrent)(0,0);
    if (*param_3 != 0) {
      (*qwglDeleteContext)(*param_3);
    }
    if ((HDC)*param_2 != (HDC)0x0) {
      ReleaseDC(unaff_EBX,(HDC)*param_2);
    }
    FreeLibrary(hLibModule);
  }
  return 0;
}


// GL_Shutdown  @ 10083ab0
void GL_Shutdown(int param_1)

{
  HWND unaff_EBX;
  HDC unaff_retaddr;
  
                    /* 0x83ab0  21  GL_Shutdown */
  (*qwglMakeCurrent)(0,0);
  if (param_1 != 0) {
    (*qwglDeleteContext)(param_1);
  }
  ReleaseDC(unaff_EBX,unaff_retaddr);
  return;
}


