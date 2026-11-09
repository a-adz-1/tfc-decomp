// FUN_0804bbe4  @ 0804bbe4
void FUN_0804bbe4(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}


// _._10EasySocket  @ 0808db60
void ___10EasySocket(int param_1,uint param_2)

{
  *(undefined1 **)(param_1 + 0x1c) = __vt_10EasySocket;
  close__10EasySocket(param_1);
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._11AuthRequest  @ 08091100
void ___11AuthRequest(int param_1,undefined4 param_2)

{
  *(undefined1 **)(param_1 + 0x8028) = __vt_11AuthRequest;
  if (*(int *)(param_1 + 0x803c) != 0) {
    DeleteEGPublicKey__16WON_CryptFactoryP15WON_EGPublicKey(*(undefined4 *)(param_1 + 0x803c));
  }
  if (*(int *)(param_1 + 0x8040) != 0) {
    DeleteEGPrivateKey__16WON_CryptFactoryP16WON_EGPrivateKey(*(undefined4 *)(param_1 + 0x8040));
  }
  if (*(int *)(param_1 + 0x8030) != 0) {
    DeleteAuthCertificate1__15WON_AuthFactoryP20WON_AuthCertificate1
              (*(undefined4 *)(param_1 + 0x8030));
  }
  if (*(int *)(param_1 + 0x802c) != 0) {
    DeleteAuthPublicKeyBlock1__15WON_AuthFactoryP23WON_AuthPublicKeyBlock1
              (*(undefined4 *)(param_1 + 0x802c));
  }
  if (*(int *)(param_1 + 0x8038) != 0) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(undefined4 *)(param_1 + 0x8038))
    ;
  }
  if (*(int *)(param_1 + 0x8034) != 0) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(undefined4 *)(param_1 + 0x8034))
    ;
  }
  ___15EasyTitanSocket(param_1 + 0x8064,2);
  ___12TitanRequest(param_1,param_2);
  return;
}


// _._11WriteBuffer  @ 08090a50
void ___11WriteBuffer(int *param_1,uint param_2)

{
  param_1[3] = (int)__vt_11WriteBuffer;
  if (*param_1 != 0) {
    __builtin_vec_delete(*param_1);
  }
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._11logic_error  @ 0809aa58
void ___11logic_error(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  iVar2 = *(int *)(iVar1 + -8);
  *(int *)(iVar1 + -8) = iVar2 + -1;
  if (iVar2 == 1) {
    if (*(int *)(iVar1 + -0xc) + 0x10U < 0x81) {
      iVar2 = (*(int *)(iVar1 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(iVar1 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar2);
      *(void **)(&DAT_080ab95c + iVar2) = (void *)(iVar1 + -0x10);
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free((void *)(iVar1 + -0x10));
    }
  }
  *param_1 = __vt_9exception;
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._11range_error  @ 0809a598
void ___11range_error(undefined4 param_1,undefined4 param_2)

{
  ___13runtime_error(param_1,param_2);
  return;
}


// _._12TitanRequest  @ 08094f80
void ___12TitanRequest(int *param_1,uint param_2)

{
  undefined4 *__ptr;
  int *piVar1;
  int iVar2;
  
  param_1[0x200a] = (int)__vt_12TitanRequest;
  if (param_1[0x2008] != 0) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(param_1[0x2008]);
    param_1[0x2008] = 0;
  }
  iVar2 = *param_1;
  __ptr = (undefined4 *)(iVar2 + -0x10);
  piVar1 = (int *)(iVar2 + -8);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    if (*(int *)(iVar2 + -0xc) + 0x10U < 0x81) {
      iVar2 = (*(int *)(iVar2 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *__ptr = *(undefined4 *)(&DAT_080ab95c + iVar2);
      *(undefined4 **)(&DAT_080ab95c + iVar2) = __ptr;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free(__ptr);
    }
  }
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._12domain_error  @ 0809a99c
void ___12domain_error(undefined4 param_1,undefined4 param_2)

{
  ___11logic_error(param_1,param_2);
  return;
}


// _._12length_error  @ 0809a864
void ___12length_error(undefined4 param_1,undefined4 param_2)

{
  ___11logic_error(param_1,param_2);
  return;
}


// _._12out_of_range  @ 0809a7c8
void ___12out_of_range(undefined4 param_1,undefined4 param_2)

{
  ___11logic_error(param_1,param_2);
  return;
}


// _._13runtime_error  @ 0809a6b0
void ___13runtime_error(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  iVar2 = *(int *)(iVar1 + -8);
  *(int *)(iVar1 + -8) = iVar2 + -1;
  if (iVar2 == 1) {
    if (*(int *)(iVar1 + -0xc) + 0x10U < 0x81) {
      iVar2 = (*(int *)(iVar1 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(iVar1 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar2);
      *(void **)(&DAT_080ab95c + iVar2) = (void *)(iVar1 + -0x10);
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free((void *)(iVar1 + -0x10));
    }
  }
  *param_1 = __vt_9exception;
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._14overflow_error  @ 0809a4fc
void ___14overflow_error(undefined4 param_1,undefined4 param_2)

{
  ___13runtime_error(param_1,param_2);
  return;
}


// _._15EasyTitanSocket  @ 0808d8f0
void ___15EasyTitanSocket(int param_1,undefined4 param_2)

{
  *(undefined1 **)(param_1 + 0x1c) = __vt_15EasyTitanSocket;
  if (*(int *)(param_1 + 0x20) != 0) {
    __builtin_vec_delete(*(undefined4 *)(param_1 + 0x20));
  }
  ___10EasySocket(param_1,param_2);
  return;
}


// _._15underflow_error  @ 0809a460
void ___15underflow_error(undefined4 param_1,undefined4 param_2)

{
  ___13runtime_error(param_1,param_2);
  return;
}


// _._16invalid_argument  @ 0809a900
void ___16invalid_argument(undefined4 param_1,undefined4 param_2)

{
  ___11logic_error(param_1,param_2);
  return;
}


// _._22_IO_istream_withassign  @ 0809cc64
void ___22_IO_istream_withassign(int *param_1,uint param_2)

{
  int iVar1;
  
  *(undefined1 **)(*param_1 + 0x1c) = __vt_22_IO_istream_withassign_3ios;
  *(undefined1 **)(*param_1 + 0x1c) = __vt_7istream_3ios;
  if ((param_2 & 2) != 0) {
    iVar1 = *param_1;
    *(undefined1 **)(iVar1 + 0x1c) = __vt_3ios;
    iVar1 = *(int *)(iVar1 + 0x18);
    if (iVar1 != 0) {
      __builtin_vec_delete(iVar1);
    }
  }
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._22_IO_ostream_withassign  @ 0809cbc4
void ___22_IO_ostream_withassign(int *param_1,uint param_2)

{
  int iVar1;
  
  *(undefined1 **)(*param_1 + 0x1c) = __vt_22_IO_ostream_withassign_3ios;
  *(undefined1 **)(*param_1 + 0x1c) = __vt_7ostream_3ios;
  if ((param_2 & 2) != 0) {
    iVar1 = *param_1;
    *(undefined1 **)(iVar1 + 0x1c) = __vt_3ios;
    iVar1 = *(int *)(iVar1 + 0x18);
    if (iVar1 != 0) {
      __builtin_vec_delete(iVar1);
    }
  }
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._7istream  @ 0809d2c0
void ___7istream(int *param_1,uint param_2)

{
  int iVar1;
  
  *(undefined1 **)(*param_1 + 0x1c) = __vt_7istream_3ios;
  if ((param_2 & 2) != 0) {
    iVar1 = *param_1;
    *(undefined1 **)(iVar1 + 0x1c) = __vt_3ios;
    iVar1 = *(int *)(iVar1 + 0x18);
    if (iVar1 != 0) {
      __builtin_vec_delete(iVar1);
    }
  }
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._7ostream  @ 0809d5b0
void ___7ostream(int *param_1,uint param_2)

{
  int iVar1;
  
  *(undefined1 **)(*param_1 + 0x1c) = __vt_7ostream_3ios;
  if ((param_2 & 2) != 0) {
    iVar1 = *param_1;
    *(undefined1 **)(iVar1 + 0x1c) = __vt_3ios;
    iVar1 = *(int *)(iVar1 + 0x18);
    if (iVar1 != 0) {
      __builtin_vec_delete(iVar1);
    }
  }
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._8iostream  @ 0809cd70
void ___8iostream(int *param_1,uint param_2)

{
  int iVar1;
  
  *(undefined1 **)(*param_1 + 0x1c) = __vt_8iostream_3ios;
  *(undefined1 **)(param_1[2] + 0x1c) = __vt_7ostream_3ios;
  *(undefined1 **)(*param_1 + 0x1c) = __vt_7istream_3ios;
  if ((param_2 & 2) != 0) {
    iVar1 = *param_1;
    *(undefined1 **)(iVar1 + 0x1c) = __vt_3ios;
    iVar1 = *(int *)(iVar1 + 0x18);
    if (iVar1 != 0) {
      __builtin_vec_delete(iVar1);
    }
  }
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 08099628
void ___t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
               (int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + -8);
  *(int *)(iVar1 + -8) = iVar2 + -1;
  if (iVar2 == 1) {
    if (*(int *)(iVar1 + -0xc) + 0x10U < 0x81) {
      iVar2 = (*(int *)(iVar1 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(iVar1 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar2);
      *(void **)(&DAT_080ab95c + iVar2) = (void *)(iVar1 + -0x10);
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free((void *)(iVar1 + -0x10));
    }
  }
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _DotProduct  @ 08061ec0
longdouble _DotProduct(float *param_1,float *param_2)

{
  return (longdouble)param_1[2] * (longdouble)param_2[2] +
         (longdouble)param_1[1] * (longdouble)param_2[1] +
         (longdouble)*param_1 * (longdouble)*param_2;
}


// _ForceReloadProfile  @ 08088810
void _ForceReloadProfile(void)

{
  return;
}


// _GLOBAL_.D.WSAGetLastError__Fv  @ 0808ee80
void _GLOBAL__D_WSAGetLastError__Fv(void)

{
  stopWinsock__10EasySocket();
  return;
}


// _GLOBAL_.I.WSAGetLastError__Fv  @ 0808ee90
void _GLOBAL__I_WSAGetLastError__Fv(void)

{
  startWinsock__10EasySocket();
  return;
}


// _Host_Frame  @ 08058ee0
void _Host_Frame(void)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = __sigsetjmp(host_enddemo,0);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = Host_FilterTime();
  if (iVar1 == 0) {
    return;
  }
  R_SetStackBase();
  if ((cls - 3U < 2) && (DAT_081b9180 == 3)) {
    cls = 5;
  }
  Sys_SendKeyEvents();
  if (g_bInactive != 0) {
    return;
  }
  IN_Commands();
  Cbuf_Execute();
  if (cls == 5) {
    ClientDLL_UpdateClientData();
  }
  if (sv != 0) {
    CL_SendCmd();
    Host_ServerFrame();
    if (sv != 0) goto LAB_08058f86;
  }
  if (cls == 0) {
    Host_CheckForRcon();
  }
LAB_08058f86:
  CL_ReadPackets();
  if (sv == 0) {
    CL_SendCmd();
  }
  CL_EmitEntities();
  CL_CheckForResend();
  CL_CheckResourceResend();
  do {
    iVar1 = CL_RequestMissingResources();
  } while (iVar1 != 0);
  WON_HandleClientAuthMsgs();
  SV_CheckTimeouts();
  WON_HandleServerAuthMsgs();
  host_time = host_time + host_frametime;
  lVar2 = (longdouble)Sys_FloatTime();
  time1_167 = (double)lVar2;
  if (((gfBackground == 0) && (SCR_UpdateScreen(), cl_inmovie != 0)) &&
     ((byte)((byte)((ushort)((ushort)NAN(scr_con_current) << 10) >> 8) |
            (byte)((ushort)((ushort)(scr_con_current == 0.0) << 0xe) >> 8)) == 0x40)) {
    func_0x08178be8();
  }
  lVar2 = (longdouble)Sys_FloatTime();
  time2_168 = (double)lVar2;
  CL_UpdateSoundFade();
  if (gfBackground == 0) {
    if (DAT_081b9180 == 3) {
      S_Update(r_origin,vpn,vright,vup);
      CL_DecayLights();
    }
    else {
      S_Update(vec3_origin,vec3_origin,vec3_origin,vec3_origin);
    }
  }
  time0_166 = time3_169;
  lVar2 = (longdouble)Sys_FloatTime();
  time3_169 = (double)lVar2;
  Host_Speeds(time0_166,time1_167,time2_168,(double)lVar2);
  if ((((byte)giSubState & 4) != 0) && (cls == 1)) {
    giActive = 2;
  }
  host_framecount = host_framecount + 1;
  return;
}


// _IO_getline  @ 0809db48
void _IO_getline(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  _IO_getline_info(param_1,param_2,param_3,param_4,param_5,0);
  return;
}


// _IO_getline_info  @ 0809db74
undefined1 *
_IO_getline_info(_IO_FILE *param_1,undefined1 *param_2,uint param_3,int param_4,int param_5,
                undefined4 *param_6)

{
  int iVar1;
  char *pcVar2;
  uint __n;
  size_t __n_00;
  undefined1 *__dest;
  
  __dest = param_2;
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
LAB_0809dc78:
  do {
    if (param_3 == 0) {
LAB_0809dc82:
      return __dest + -(int)param_2;
    }
    __n = (int)param_1->_IO_read_end - (int)param_1->_IO_read_ptr;
    if ((int)__n < 1) {
      iVar1 = __uflow(param_1);
      if (iVar1 == -1) {
        if (param_6 != (undefined4 *)0x0) {
          *param_6 = 0xffffffff;
        }
        goto LAB_0809dc82;
      }
      if (iVar1 == param_4) {
        if (param_5 < 1) {
          if (param_5 < 0) {
            _IO_sputbackc(param_1,param_4);
          }
        }
        else {
          *__dest = (undefined1)param_4;
          __dest = __dest + 1;
        }
        goto LAB_0809dc82;
      }
      *__dest = (char)iVar1;
      __dest = __dest + 1;
      param_3 = param_3 - 1;
      goto LAB_0809dc78;
    }
    if (param_3 <= __n) {
      __n = param_3;
    }
    pcVar2 = memchr(param_1->_IO_read_ptr,param_4,__n);
    if (pcVar2 != (char *)0x0) {
      __n_00 = (int)pcVar2 - (int)param_1->_IO_read_ptr;
      if ((-1 < param_5) && (pcVar2 = pcVar2 + 1, 0 < param_5)) {
        __n_00 = __n_00 + 1;
      }
      memcpy(__dest,param_1->_IO_read_ptr,__n_00);
      param_1->_IO_read_ptr = pcVar2;
      return __dest + (__n_00 - (int)param_2);
    }
    memcpy(__dest,param_1->_IO_read_ptr,__n);
    __dest = __dest + __n;
    param_3 = param_3 - __n;
    param_1->_IO_read_ptr = param_1->_IO_read_ptr + __n;
  } while( true );
}


// _VectorAdd  @ 08061f20
void _VectorAdd(float *param_1,float *param_2,float *param_3)

{
  *param_3 = *param_1 + *param_2;
  param_3[1] = param_1[1] + param_2[1];
  param_3[2] = param_1[2] + param_2[2];
  return;
}


// _VectorCopy  @ 08061f50
void _VectorCopy(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  return;
}


// _VectorSubtract  @ 08061ef0
void _VectorSubtract(float *param_1,float *param_2,float *param_3)

{
  *param_3 = *param_1 - *param_2;
  param_3[1] = param_1[1] - param_2[1];
  param_3[2] = param_1[2] - param_2[2];
  return;
}


// __10EasySocket  @ 0808db00
void __10EasySocket(undefined4 *param_1)

{
  param_1[7] = __vt_10EasySocket;
  *param_1 = 0xffffffff;
  param_1[1] = 0;
  param_1[6] = 0;
  return;
}


// __10EasySocketQ210EasySocket10SocketType  @ 0808db30
undefined4 * __10EasySocketQ210EasySocket10SocketType(undefined4 *param_1,undefined4 param_2)

{
  param_1[7] = __vt_10EasySocket;
  *param_1 = 0xffffffff;
  param_1[1] = param_2;
  param_1[6] = 0;
  return param_1;
}


// __10EasySocketRC10EasySocket  @ 0808eeb0
void __10EasySocketRC10EasySocket(int param_1)

{
  *(undefined1 **)(param_1 + 0x1c) = __vt_10EasySocket;
  return;
}


// __10ReadBufferPCcUl  @ 080905f0
undefined4 * __10ReadBufferPCcUl(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[2] = param_3;
  *param_1 = param_2;
  param_1[1] = 0;
  return param_1;
}


// __11AuthRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i  @ 08090fa0
int __11AuthRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
              (int param_1,undefined4 param_2,undefined4 param_3)

{
  __12TitanRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
            (param_1,param_2,param_3);
  *(undefined1 **)(param_1 + 0x8028) = __vt_11AuthRequest;
  __10EasySocket(param_1 + 0x8064);
  *(undefined1 **)(param_1 + 0x8080) = __vt_15EasyTitanSocket;
  *(undefined4 *)(param_1 + 0x8084) = 0;
  *(undefined4 *)(param_1 + 0x8088) = 0;
  Auth_InitError__11AuthRequest(param_1);
  *(undefined4 *)(param_1 + 0x802c) = 0;
  *(undefined4 *)(param_1 + 0x803c) = 0;
  *(undefined4 *)(param_1 + 0x8040) = 0;
  *(undefined4 *)(param_1 + 0x8030) = 0;
  *(undefined4 *)(param_1 + 0x8038) = 0;
  *(undefined4 *)(param_1 + 0x8034) = 0;
  *(undefined4 *)(param_1 + 0x8044) = 0;
  setType__10EasySocketQ210EasySocket10SocketType(param_1 + 0x8064,1);
  setMaxMsgSize__15EasyTitanSocketUl(param_1 + 0x8064,0x1000);
  *(undefined4 *)(param_1 + 0x8058) = 0;
  *(undefined4 *)(param_1 + 0x8048) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x804c) = 0;
  readServerKey__11AuthRequest(param_1);
  return param_1;
}


// __11WriteBufferRC11WriteBuffer  @ 08090930
int * __11WriteBufferRC11WriteBuffer(int *param_1,int param_2)

{
  void *__dest;
  int iVar1;
  void *__src;
  size_t __n;
  
  param_1[3] = (int)__vt_11WriteBuffer;
  iVar1 = *(int *)(param_2 + 4);
  param_1[1] = iVar1;
  iVar1 = __builtin_vec_new(iVar1);
  *param_1 = iVar1;
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("mBuffer","/e/quiver/goldsrc/common/WriteBuffer.cpp",0x37,
                  "WriteBuffer::WriteBuffer(const class WriteBuffer &)");
  }
  iVar1 = getSize__C11WriteBuffer(param_2);
  param_1[2] = iVar1;
  __dest = (void *)*param_1;
  __src = (void *)getBuffer__C11WriteBuffer(param_2);
  __n = getSize__C11WriteBuffer(param_2);
  memcpy(__dest,__src,__n);
  return param_1;
}


// __11logic_errorRC11logic_error  @ 0809e5dc
undefined4 * __11logic_errorRC11logic_error(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  *param_1 = __vt_11logic_error;
  iVar1 = *(int *)(param_2 + 4);
  if (*(char *)(iVar1 + -4) == '\0') {
    *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 1;
  }
  else {
    iVar1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (iVar1 + -0x10);
  }
  param_1[1] = iVar1;
  return param_1;
}


// __11logic_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0809a9d4
undefined4 *
__11logic_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
          (undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  *param_1 = __vt_11logic_error;
  iVar1 = *param_2;
  if (*(char *)(iVar1 + -4) == '\0') {
    *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 1;
  }
  else {
    iVar1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (iVar1 + -0x10);
  }
  param_1[1] = iVar1;
  return param_1;
}


// __11range_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0809a510
undefined4 *
__11range_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
          (undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  *param_1 = __vt_13runtime_error;
  iVar1 = *param_2;
  if (*(char *)(iVar1 + -4) == '\0') {
    *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 1;
  }
  else {
    iVar1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (iVar1 + -0x10);
  }
  param_1[1] = iVar1;
  *param_1 = __vt_11range_error;
  return param_1;
}


// __12TitanRequest  @ 08094cf0
undefined4 * __12TitanRequest(undefined4 *param_1)

{
  undefined *puVar1;
  
  param_1[0x200a] = __vt_12TitanRequest;
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    puVar1 = &force_to_data;
  }
  else {
    puVar1 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (
                       _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                       );
  }
  *param_1 = puVar1;
  initTitanRequest__12TitanRequest(param_1);
  return param_1;
}


// __12TitanRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i  @ 08094df0
int * __12TitanRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                (int *param_1,int *param_2,int param_3)

{
  undefined4 *__ptr;
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  
  param_1[0x200a] = (int)__vt_12TitanRequest;
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    puVar2 = &force_to_data;
  }
  else {
    puVar2 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (
                       _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                       );
  }
  *param_1 = (int)puVar2;
  initTitanRequest__12TitanRequest(param_1);
  if (param_2 != param_1) {
    iVar3 = *param_1;
    __ptr = (undefined4 *)(iVar3 + -0x10);
    piVar1 = (int *)(iVar3 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      if (*(int *)(iVar3 + -0xc) + 0x10U < 0x81) {
        iVar3 = (*(int *)(iVar3 + -0xc) + 0x17U >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0___node_allocator_lock);
        *__ptr = *(undefined4 *)(&DAT_080ab95c + iVar3);
        *(undefined4 **)(&DAT_080ab95c + iVar3) = __ptr;
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        free(__ptr);
      }
    }
    iVar3 = *param_2;
    if (*(char *)(iVar3 + -4) == '\0') {
      *(int *)(iVar3 + -8) = *(int *)(iVar3 + -8) + 1;
    }
    else {
      iVar3 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (iVar3 + -0x10);
    }
    *param_1 = iVar3;
  }
  param_1[1] = param_3;
  iVar3 = getAddrFromString__10EasySocketRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                    (param_1);
  param_1[0x2002] = iVar3;
  return param_1;
}


// __12domain_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0809a914
undefined4 *
__12domain_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
          (undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  *param_1 = __vt_11logic_error;
  iVar1 = *param_2;
  if (*(char *)(iVar1 + -4) == '\0') {
    *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 1;
  }
  else {
    iVar1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (iVar1 + -0x10);
  }
  param_1[1] = iVar1;
  *param_1 = __vt_12domain_error;
  return param_1;
}


// __12length_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0809a7dc
undefined4 *
__12length_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
          (undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  *param_1 = __vt_11logic_error;
  iVar1 = *param_2;
  if (*(char *)(iVar1 + -4) == '\0') {
    *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 1;
  }
  else {
    iVar1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (iVar1 + -0x10);
  }
  param_1[1] = iVar1;
  *param_1 = __vt_12length_error;
  return param_1;
}


// __12out_of_rangeRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0809a740
undefined4 *
__12out_of_rangeRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
          (undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  *param_1 = __vt_11logic_error;
  iVar1 = *param_2;
  if (*(char *)(iVar1 + -4) == '\0') {
    *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 1;
  }
  else {
    iVar1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (iVar1 + -0x10);
  }
  param_1[1] = iVar1;
  *param_1 = __vt_12out_of_range;
  return param_1;
}


// __13runtime_error  @ 0809a5ac
undefined4 * __13runtime_error(undefined4 *param_1)

{
  undefined *puVar1;
  
  *param_1 = __vt_13runtime_error;
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    puVar1 = &force_to_data;
  }
  else {
    puVar1 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (
                       _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                       );
  }
  param_1[1] = puVar1;
  return param_1;
}


// __13runtime_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0809a62c
undefined4 *
__13runtime_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
          (undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  *param_1 = __vt_13runtime_error;
  iVar1 = *param_2;
  if (*(char *)(iVar1 + -4) == '\0') {
    *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 1;
  }
  else {
    iVar1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (iVar1 + -0x10);
  }
  param_1[1] = iVar1;
  return param_1;
}


// __14overflow_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0809a474
undefined4 *
__14overflow_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
          (undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  *param_1 = __vt_13runtime_error;
  iVar1 = *param_2;
  if (*(char *)(iVar1 + -4) == '\0') {
    *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 1;
  }
  else {
    iVar1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (iVar1 + -0x10);
  }
  param_1[1] = iVar1;
  *param_1 = __vt_14overflow_error;
  return param_1;
}


// __15EasyTitanSocket  @ 0808da60
int __15EasyTitanSocket(int param_1)

{
  __10EasySocket(param_1);
  *(undefined1 **)(param_1 + 0x1c) = __vt_15EasyTitanSocket;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return param_1;
}


// __15EasyTitanSocketQ210EasySocket10SocketTypeUl  @ 0808d860
int __15EasyTitanSocketQ210EasySocket10SocketTypeUl
              (int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  __10EasySocketQ210EasySocket10SocketType(param_1,param_2);
  *(undefined1 **)(param_1 + 0x1c) = __vt_15EasyTitanSocket;
  uVar1 = __builtin_vec_new(param_3);
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  *(undefined4 *)(param_1 + 0x24) = param_3;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return param_1;
}


// __15EasyTitanSocketRC15EasyTitanSocket  @ 0808daa0
int __15EasyTitanSocketRC15EasyTitanSocket(int param_1)

{
  __10EasySocket(param_1);
  *(undefined1 **)(param_1 + 0x1c) = __vt_15EasyTitanSocket;
  return param_1;
}


// __15underflow_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0809a3d8
undefined4 *
__15underflow_errorRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
          (undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  *param_1 = __vt_13runtime_error;
  iVar1 = *param_2;
  if (*(char *)(iVar1 + -4) == '\0') {
    *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 1;
  }
  else {
    iVar1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (iVar1 + -0x10);
  }
  param_1[1] = iVar1;
  *param_1 = __vt_15underflow_error;
  return param_1;
}


// __16invalid_argumentRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 0809a878
undefined4 *
__16invalid_argumentRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
          (undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  *param_1 = __vt_11logic_error;
  iVar1 = *param_2;
  if (*(char *)(iVar1 + -4) == '\0') {
    *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 1;
  }
  else {
    iVar1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (iVar1 + -0x10);
  }
  param_1[1] = iVar1;
  *param_1 = __vt_16invalid_argument;
  return param_1;
}


// __7istreami  @ 0809d224
int * __7istreami(int *param_1,int param_2)

{
  if (param_2 != 0) {
    *param_1 = (int)(param_1 + 2);
    param_1[9] = (int)__vt_3ios;
    *(undefined1 *)((int)param_1 + 0x1a) = 4;
    *(undefined1 *)((int)param_1 + 0x1b) = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    *(undefined2 *)(param_1 + 6) = 0x20;
    param_1[5] = 0x11;
    param_1[7] = 6;
    param_1[8] = 0;
  }
  *(undefined1 **)(*param_1 + 0x1c) = __vt_7istream_3ios;
  param_1[1] = 0;
  return param_1;
}


// __7istreamiP9streambufP7ostream  @ 0809aae8
int * __7istreamiP9streambufP7ostream(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  
  if (param_2 != 0) {
    *param_1 = (int)(param_1 + 2);
    param_1[9] = (int)__vt_3ios;
    *(undefined1 *)((int)param_1 + 0x1a) = 4;
    *(undefined1 *)((int)param_1 + 0x1b) = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    *(undefined2 *)(param_1 + 6) = 0x20;
    param_1[5] = 0x11;
    param_1[7] = 6;
    param_1[8] = 0;
  }
  *(undefined1 **)(*param_1 + 0x1c) = __vt_7istream_3ios;
  piVar1 = (int *)0x0;
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
  }
  if (param_3 == 0) {
    *(undefined1 *)((int)piVar1 + 0x12) = 4;
  }
  else {
    *(undefined1 *)((int)piVar1 + 0x12) = 0;
  }
  *(undefined1 *)((int)piVar1 + 0x13) = 0;
  *piVar1 = param_3;
  piVar1[1] = param_4;
  piVar1[2] = 0;
  *(undefined2 *)(piVar1 + 4) = 0x20;
  piVar1[3] = 0x11;
  piVar1[5] = 6;
  piVar1[6] = 0;
  param_1[1] = 0;
  return param_1;
}


// __7ostreami  @ 0809d51c
int * __7ostreami(int *param_1,int param_2)

{
  if (param_2 != 0) {
    *param_1 = (int)(param_1 + 1);
    param_1[8] = (int)__vt_3ios;
    *(undefined1 *)((int)param_1 + 0x16) = 4;
    *(undefined1 *)((int)param_1 + 0x17) = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    *(undefined2 *)(param_1 + 5) = 0x20;
    param_1[4] = 0x11;
    param_1[6] = 6;
    param_1[7] = 0;
  }
  *(undefined1 **)(*param_1 + 0x1c) = __vt_7ostream_3ios;
  return param_1;
}


// __7ostreamiP9streambufP7ostream  @ 0809c5a8
int * __7ostreamiP9streambufP7ostream(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  
  if (param_2 != 0) {
    *param_1 = (int)(param_1 + 1);
    param_1[8] = (int)__vt_3ios;
    *(undefined1 *)((int)param_1 + 0x16) = 4;
    *(undefined1 *)((int)param_1 + 0x17) = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    *(undefined2 *)(param_1 + 5) = 0x20;
    param_1[4] = 0x11;
    param_1[6] = 6;
    param_1[7] = 0;
  }
  *(undefined1 **)(*param_1 + 0x1c) = __vt_7ostream_3ios;
  piVar1 = (int *)0x0;
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
  }
  if (param_3 == 0) {
    *(undefined1 *)((int)piVar1 + 0x12) = 4;
  }
  else {
    *(undefined1 *)((int)piVar1 + 0x12) = 0;
  }
  *(undefined1 *)((int)piVar1 + 0x13) = 0;
  *piVar1 = param_3;
  piVar1[1] = param_4;
  piVar1[2] = 0;
  *(undefined2 *)(piVar1 + 4) = 0x20;
  piVar1[3] = 0x11;
  piVar1[5] = 6;
  piVar1[6] = 0;
  return param_1;
}


// __8iostreami  @ 0809ccbc
int * __8iostreami(int *param_1,int param_2)

{
  if (param_2 != 0) {
    param_1[2] = (int)(param_1 + 3);
    *param_1 = (int)(param_1 + 3);
    param_1[10] = (int)__vt_3ios;
    *(undefined1 *)((int)param_1 + 0x1e) = 4;
    *(undefined1 *)((int)param_1 + 0x1f) = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    *(undefined2 *)(param_1 + 7) = 0x20;
    param_1[6] = 0x11;
    param_1[8] = 6;
    param_1[9] = 0;
  }
  *(undefined1 **)(*param_1 + 0x1c) = __vt_7istream_3ios;
  param_1[1] = 0;
  *(undefined1 **)(param_1[2] + 0x1c) = __vt_7ostream_3ios;
  *(undefined1 **)(*param_1 + 0x1c) = __vt_8iostream_3ios;
  return param_1;
}


// __8iostreamiP9streambufP7ostream  @ 0809ca0c
int * __8iostreamiP9streambufP7ostream(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  
  if (param_2 != 0) {
    param_1[2] = (int)(param_1 + 3);
    *param_1 = (int)(param_1 + 3);
    param_1[10] = (int)__vt_3ios;
    *(undefined1 *)((int)param_1 + 0x1e) = 4;
    *(undefined1 *)((int)param_1 + 0x1f) = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    *(undefined2 *)(param_1 + 7) = 0x20;
    param_1[6] = 0x11;
    param_1[8] = 6;
    param_1[9] = 0;
  }
  *(undefined1 **)(*param_1 + 0x1c) = __vt_7istream_3ios;
  param_1[1] = 0;
  *(undefined1 **)(param_1[2] + 0x1c) = __vt_7ostream_3ios;
  *(undefined1 **)(*param_1 + 0x1c) = __vt_8iostream_3ios;
  piVar1 = (int *)0x0;
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
  }
  if (param_3 == 0) {
    *(undefined1 *)((int)piVar1 + 0x12) = 4;
  }
  else {
    *(undefined1 *)((int)piVar1 + 0x12) = 0;
  }
  *(undefined1 *)((int)piVar1 + 0x13) = 0;
  *piVar1 = param_3;
  piVar1[1] = param_4;
  piVar1[2] = 0;
  *(undefined2 *)(piVar1 + 4) = 0x20;
  piVar1[3] = 0x11;
  piVar1[5] = 6;
  piVar1[6] = 0;
  return param_1;
}


// __apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc  @ 0809943c
void __apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
               (int *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar3 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_2 == '\0') goto LAB_08099484;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08099484;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08099484;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08099484;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08099483;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08099482;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08099482:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08099483:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08099484:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,*(undefined4 *)(*param_1 + -0x10),0,param_2,(int)puVar2 - (int)param_2);
  return;
}


// __apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 080994a0
void __apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
               (int *param_1,undefined4 param_2)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (param_1,*(undefined4 *)(*param_1 + -0x10),0,param_2,0,0xffffffff);
  return;
}


// __apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0c  @ 0809941c
void __apl__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0c
               (int *param_1,char param_2)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,*(undefined4 *)(*param_1 + -0x10),0,1,(int)param_2);
  return;
}


// __as__10EasySocketRC10EasySocket  @ 0808eea0
undefined4 __as__10EasySocketRC10EasySocket(undefined4 param_1)

{
  return param_1;
}


// __as__11WriteBufferRC11WriteBuffer  @ 080909b0
int * __as__11WriteBufferRC11WriteBuffer(int *param_1,int *param_2)

{
  void *__dest;
  uint uVar1;
  int iVar2;
  void *__src;
  size_t __n;
  
  if (param_2 != param_1) {
    uVar1 = getSize__C11WriteBuffer(param_2);
    if ((uint)param_1[1] < uVar1) {
      if (*param_1 != 0) {
        __builtin_vec_delete(*param_1);
      }
      iVar2 = getSize__C11WriteBuffer(param_2);
      param_1[1] = iVar2;
      iVar2 = __builtin_vec_new(iVar2);
      *param_1 = iVar2;
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("mBuffer","/e/quiver/goldsrc/common/WriteBuffer.cpp",0x56,
                      "class WriteBuffer & WriteBuffer::operator =(const class WriteBuffer &)");
      }
    }
    iVar2 = getSize__C11WriteBuffer(param_2);
    param_1[2] = iVar2;
    __dest = (void *)*param_1;
    __src = (void *)getBuffer__C11WriteBuffer(param_2);
    __n = getSize__C11WriteBuffer(param_2);
    memcpy(__dest,__src,__n);
  }
  return param_1;
}


// __as__15EasyTitanSocketRC15EasyTitanSocket  @ 0808da90
undefined4 __as__15EasyTitanSocketRC15EasyTitanSocket(undefined4 param_1)

{
  return param_1;
}


// __as__22_IO_istream_withassignR22_IO_istream_withassign  @ 0809cc1c
void __as__22_IO_istream_withassignR22_IO_istream_withassign(undefined4 param_1,undefined4 param_2)

{
  __as__22_IO_istream_withassignR7istream(param_1,param_2);
  return;
}


// __as__22_IO_istream_withassignR7istream  @ 0809dc94
void __as__22_IO_istream_withassignR7istream(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_2 != param_1) {
    piVar3 = (int *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      piVar3 = (int *)*param_1;
    }
    piVar2 = (int *)0x0;
    if (param_2 != (undefined4 *)0x0) {
      piVar2 = (int *)*param_2;
    }
    iVar1 = *piVar2;
    if (iVar1 == 0) {
      *(undefined1 *)((int)piVar3 + 0x12) = 4;
    }
    else {
      *(undefined1 *)((int)piVar3 + 0x12) = 0;
    }
    *(undefined1 *)((int)piVar3 + 0x13) = 0;
    *piVar3 = iVar1;
    piVar3[1] = 0;
    piVar3[2] = 0;
    *(undefined2 *)(piVar3 + 4) = 0x20;
    piVar3[3] = 0x11;
    piVar3[5] = 6;
    piVar3[6] = 0;
    param_1[1] = 0;
  }
  return;
}


// __as__22_IO_ostream_withassignR22_IO_ostream_withassign  @ 0809cb7c
void __as__22_IO_ostream_withassignR22_IO_ostream_withassign(undefined4 param_1,undefined4 param_2)

{
  __as__22_IO_ostream_withassignR7ostream(param_1,param_2);
  return;
}


// __as__22_IO_ostream_withassignR7ostream  @ 0809dd04
void __as__22_IO_ostream_withassignR7ostream(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_2 != param_1) {
    piVar3 = (int *)0x0;
    if (param_1 != (undefined4 *)0x0) {
      piVar3 = (int *)*param_1;
    }
    piVar2 = (int *)0x0;
    if (param_2 != (undefined4 *)0x0) {
      piVar2 = (int *)*param_2;
    }
    iVar1 = *piVar2;
    if (iVar1 == 0) {
      *(undefined1 *)((int)piVar3 + 0x12) = 4;
    }
    else {
      *(undefined1 *)((int)piVar3 + 0x12) = 0;
    }
    *(undefined1 *)((int)piVar3 + 0x13) = 0;
    *piVar3 = iVar1;
    piVar3[1] = 0;
    piVar3[2] = 0;
    *(undefined2 *)(piVar3 + 4) = 0x20;
    piVar3[3] = 0x11;
    piVar3[5] = 6;
    piVar3[6] = 0;
  }
  return;
}


// __as__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc  @ 080994dc
void __as__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
               (undefined4 param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar3 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_2 == '\0') goto LAB_08099524;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08099524;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08099524;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08099524;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08099523;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08099522;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08099522:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08099523:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08099524:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,0,0xffffffff,param_2,(int)puVar2 - (int)param_2);
  return;
}


// __as__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 080999f8
int * __as__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                (int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != param_1) {
    iVar2 = *param_1;
    iVar1 = *(int *)(iVar2 + -8);
    *(int *)(iVar2 + -8) = iVar1 + -1;
    if (iVar1 == 1) {
      if (*(int *)(iVar2 + -0xc) + 0x10U < 0x81) {
        iVar1 = (*(int *)(iVar2 + -0xc) + 0x17U >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0___node_allocator_lock);
        *(undefined4 *)(iVar2 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar1);
        *(void **)(&DAT_080ab95c + iVar1) = (void *)(iVar2 + -0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        free((void *)(iVar2 + -0x10));
      }
    }
    iVar2 = *param_2;
    if (*(char *)(iVar2 + -4) == '\0') {
      *(int *)(iVar2 + -8) = *(int *)(iVar2 + -8) + 1;
    }
    else {
      iVar2 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (iVar2 + -0x10);
    }
    *param_1 = iVar2;
  }
  return param_1;
}


// __as__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0c  @ 080994c0
void __as__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0c
               (undefined4 param_1,char param_2)

{
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,0,0xffffffff,1,(int)param_2);
  return;
}


// __dl__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepPv  @ 08099dec
void __dl__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepPv
               (undefined4 *param_1)

{
  int iVar1;
  
  if (param_1[1] + 0x10 < 0x81) {
    iVar1 = (param_1[1] + 0x17 >> 3) * 4;
    pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    *param_1 = *(undefined4 *)(&DAT_080ab95c + iVar1);
    *(undefined4 **)(&DAT_080ab95c + iVar1) = param_1;
    pthread_mutex_unlock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
    ;
  }
  else {
    free(param_1);
  }
  return;
}


// __eq__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_b  @ 08098090
bool __eq__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_b
               (uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_1 & 3;
  puVar1 = param_1;
  if (uVar4 != 0) {
    puVar2 = param_1;
    if ((POPCOUNT(uVar4) & 1U) != 0) {
      if (uVar4 != 2) {
        if ((char)*param_1 == '\0') goto LAB_080980db;
        puVar2 = (uint *)((int)param_1 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_080980db;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_080980db;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar4 = *puVar2;
    if ((char)uVar4 == '\0') goto LAB_080980db;
    if ((char)(uVar4 >> 8) == '\0') goto LAB_080980da;
    if ((uVar4 & 0xff0000) == 0) goto LAB_080980d9;
    puVar1 = puVar2 + 1;
  } while ((uVar4 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_080980d9:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_080980da:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_080980db:
  iVar3 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
                    (param_2,param_1,0,(int)puVar2 - (int)param_1);
  return iVar3 == 0;
}


// __eq__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_b  @ 0809802c
bool __eq__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_b
               (undefined4 param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar4 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar4) & 1U) != 0) {
      if (uVar4 != 2) {
        if ((char)*param_2 == '\0') goto LAB_08098077;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08098077;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08098077;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar4 = *puVar2;
    if ((char)uVar4 == '\0') goto LAB_08098077;
    if ((char)(uVar4 >> 8) == '\0') goto LAB_08098076;
    if ((uVar4 & 0xff0000) == 0) goto LAB_08098075;
    puVar1 = puVar2 + 1;
  } while ((uVar4 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098075:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098076:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08098077:
  iVar3 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
                    (param_1,param_2,0,(int)puVar2 - (int)param_2);
  return iVar3 == 0;
}


// __eq__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b  @ 080980f4
bool __eq__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b
               (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
                    (param_1,param_2,0,0xffffffff);
  return iVar1 == 0;
}


// __ge__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_b  @ 08097c0c
bool __ge__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_b
               (uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_1 & 3;
  puVar1 = param_1;
  if (uVar4 != 0) {
    puVar2 = param_1;
    if ((POPCOUNT(uVar4) & 1U) != 0) {
      if (uVar4 != 2) {
        if ((char)*param_1 == '\0') goto LAB_08097c57;
        puVar2 = (uint *)((int)param_1 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08097c57;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08097c57;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar4 = *puVar2;
    if ((char)uVar4 == '\0') goto LAB_08097c57;
    if ((char)(uVar4 >> 8) == '\0') goto LAB_08097c56;
    if ((uVar4 & 0xff0000) == 0) goto LAB_08097c55;
    puVar1 = puVar2 + 1;
  } while ((uVar4 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097c55:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097c56:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097c57:
  iVar3 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
                    (param_2,param_1,0,(int)puVar2 - (int)param_1);
  return iVar3 < 1;
}


// __ge__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_b  @ 08097ba8
uint __ge__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_b
               (undefined4 param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar3 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_2 == '\0') goto LAB_08097bf3;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08097bf3;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08097bf3;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08097bf3;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08097bf2;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08097bf1;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097bf1:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097bf2:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097bf3:
  uVar3 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
                    (param_1,param_2,0,(int)puVar2 - (int)param_2);
  return ~uVar3 >> 0x1f;
}


// __ge__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b  @ 08097c70
uint __ge__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b
               (undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
                    (param_1,param_2,0,0xffffffff);
  return ~uVar1 >> 0x1f;
}


// __gt__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_b  @ 08097ddc
uint __gt__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_b
               (uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_1 & 3;
  puVar1 = param_1;
  if (uVar3 != 0) {
    puVar2 = param_1;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_1 == '\0') goto LAB_08097e27;
        puVar2 = (uint *)((int)param_1 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08097e27;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08097e27;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08097e27;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08097e26;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08097e25;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097e25:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097e26:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097e27:
  uVar3 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
                    (param_2,param_1,0,(int)puVar2 - (int)param_1);
  return uVar3 >> 0x1f;
}


// __gt__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_b  @ 08097d78
bool __gt__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_b
               (undefined4 param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar4 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar4) & 1U) != 0) {
      if (uVar4 != 2) {
        if ((char)*param_2 == '\0') goto LAB_08097dc3;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08097dc3;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08097dc3;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar4 = *puVar2;
    if ((char)uVar4 == '\0') goto LAB_08097dc3;
    if ((char)(uVar4 >> 8) == '\0') goto LAB_08097dc2;
    if ((uVar4 & 0xff0000) == 0) goto LAB_08097dc1;
    puVar1 = puVar2 + 1;
  } while ((uVar4 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097dc1:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097dc2:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097dc3:
  iVar3 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
                    (param_1,param_2,0,(int)puVar2 - (int)param_2);
  return 0 < iVar3;
}


// __gt__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b  @ 08097e40
bool __gt__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b
               (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
                    (param_1,param_2,0,0xffffffff);
  return 0 < iVar1;
}


// __le__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_b  @ 08097cf4
uint __le__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_b
               (uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_1 & 3;
  puVar1 = param_1;
  if (uVar3 != 0) {
    puVar2 = param_1;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_1 == '\0') goto LAB_08097d3f;
        puVar2 = (uint *)((int)param_1 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08097d3f;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08097d3f;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08097d3f;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08097d3e;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08097d3d;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097d3d:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097d3e:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097d3f:
  uVar3 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
                    (param_2,param_1,0,(int)puVar2 - (int)param_1);
  return ~uVar3 >> 0x1f;
}


// __le__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_b  @ 08097c90
bool __le__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_b
               (undefined4 param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar4 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar4) & 1U) != 0) {
      if (uVar4 != 2) {
        if ((char)*param_2 == '\0') goto LAB_08097cdb;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08097cdb;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08097cdb;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar4 = *puVar2;
    if ((char)uVar4 == '\0') goto LAB_08097cdb;
    if ((char)(uVar4 >> 8) == '\0') goto LAB_08097cda;
    if ((uVar4 & 0xff0000) == 0) goto LAB_08097cd9;
    puVar1 = puVar2 + 1;
  } while ((uVar4 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097cd9:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097cda:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097cdb:
  iVar3 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
                    (param_1,param_2,0,(int)puVar2 - (int)param_2);
  return iVar3 < 1;
}


// __le__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b  @ 08097d58
bool __le__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b
               (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
                    (param_1,param_2,0,0xffffffff);
  return iVar1 < 1;
}


// __length_error__FPCc  @ 0809a1b4
void __length_error__FPCc(uint *param_1)

{
  undefined *puVar1;
  int iVar2;
  code *pcVar3;
  undefined *puVar4;
  uint *puVar5;
  uint *puVar6;
  int *piVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined1 **ppuVar10;
  undefined1 *puVar11;
  undefined *local_10;
  undefined1 *local_c;
  undefined *local_8;
  
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    local_10 = &force_to_data;
  }
  else {
    local_10 = (undefined *)
               clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                         (
                         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                         );
  }
  uVar9 = (uint)param_1 & 3;
  puVar5 = param_1;
  if (uVar9 != 0) {
    puVar6 = param_1;
    if ((POPCOUNT(uVar9) & 1U) != 0) {
      if (uVar9 != 2) {
        if ((char)*param_1 == '\0') goto LAB_0809a22b;
        puVar6 = (uint *)((int)param_1 + 1);
      }
      if ((char)*puVar6 == '\0') goto LAB_0809a22b;
      puVar6 = (uint *)((int)puVar6 + 1);
    }
    if ((char)*puVar6 == '\0') goto LAB_0809a22b;
    puVar5 = (uint *)((int)puVar6 + 1);
  }
  do {
    puVar6 = puVar5;
    uVar9 = *puVar6;
    if ((char)uVar9 == '\0') goto LAB_0809a22b;
    if ((char)(uVar9 >> 8) == '\0') goto LAB_0809a22a;
    if ((uVar9 & 0xff0000) == 0) goto LAB_0809a229;
    puVar5 = puVar6 + 1;
  } while ((uVar9 & 0xff000000) != 0);
  puVar6 = (uint *)((int)puVar6 + 1);
LAB_0809a229:
  puVar6 = (uint *)((int)puVar6 + 1);
LAB_0809a22a:
  puVar6 = (uint *)((int)puVar6 + 1);
LAB_0809a22b:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (&local_10,0,0xffffffff,param_1,(int)puVar6 - (int)param_1);
  ppuVar10 = &local_c;
  local_c = __vt_11logic_error;
  if (local_10[-4] == '\0') {
    *(int *)(local_10 + -8) = *(int *)(local_10 + -8) + 1;
    local_8 = local_10;
  }
  else {
    local_8 = (undefined *)
              clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (local_10 + -0x10);
  }
  local_c = __vt_12length_error;
  piVar7 = (int *)__eh_alloc(8);
  __11logic_errorRC11logic_error(piVar7,ppuVar10);
  *piVar7 = (int)__vt_12length_error;
  puVar11 = &stack0xffffffdc;
  do {
    *(undefined4 *)(puVar11 + -4) = 2;
    *(undefined1 ***)(puVar11 + -8) = ppuVar10;
    *(undefined4 *)(puVar11 + -0xc) = 0x809a2b4;
    ___11logic_error();
    puVar4 = local_10;
    puVar1 = local_10 + -0x10;
    iVar2 = *(int *)(local_10 + -8);
    *(int *)(local_10 + -8) = iVar2 + -1;
    if (iVar2 == 1) {
      if (*(int *)(local_10 + -0xc) + 0x10U < 0x81) {
        iVar2 = (*(int *)(local_10 + -0xc) + 0x17U >> 3) * 4;
        ppuVar10 = (undefined1 **)(iVar2 + -4);
        *(undefined1 **)(puVar11 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar11 + -8) = 0x809a30b;
        pthread_mutex_lock(*(pthread_mutex_t **)(puVar11 + -4));
        *(undefined4 *)(puVar4 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar2);
        *(undefined **)(&DAT_080ab95c + iVar2) = puVar1;
        *(undefined1 **)(puVar11 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar11 + -8) = 0x809a32a;
        pthread_mutex_unlock(*(pthread_mutex_t **)(puVar11 + -4));
      }
      else {
        *(undefined **)(puVar11 + -4) = puVar1;
        *(undefined4 *)(puVar11 + -8) = 0x809a2f1;
        free(*(void **)(puVar11 + -4));
      }
    }
    *(code **)(puVar11 + -4) = ___12length_error;
    pcVar3 = *(code **)(*piVar7 + 4);
    *(undefined4 *)(puVar11 + -8) = 0x809a339;
    uVar8 = (*pcVar3)();
    *(undefined4 *)(puVar11 + -8) = uVar8;
    *(int **)(puVar11 + -0xc) = piVar7;
    *(undefined4 *)(puVar11 + -0x10) = 0x809a340;
    __cp_push_exception();
    *(undefined4 *)(puVar11 + -0x10) = 0x809a345;
    __throw();
    *(undefined4 *)(puVar11 + -0x10) = 0x809a34d;
    terminate__Fv();
    *(undefined4 *)(puVar11 + -0x10) = 2;
    *(undefined1 ***)(puVar11 + -0x14) = ppuVar10;
    *(undefined4 *)(puVar11 + -0x18) = 0x809a358;
    ___11logic_error();
    *(undefined4 *)(puVar11 + -0x10) = 0x809a2a9;
    __throw();
    puVar11 = puVar11 + -0xc;
  } while( true );
}


// __ls__7ostreamP9streambuf  @ 0809c4ac
/* WARNING: Removing unreachable block (ram,0x0809c4f5) */
/* WARNING: Removing unreachable block (ram,0x0809c58d) */

int * __ls__7ostreamP9streambuf(int *param_1,_IO_FILE *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  size_t sVar3;
  size_t sVar4;
  undefined1 local_2014 [8208];
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2[1] != 0) {
      flush__7ostream(puVar2[1]);
      puVar2 = (undefined4 *)*param_1;
    }
    _IO_flockfile((_IO_FILE *)*puVar2);
    iVar1 = *(int *)*param_1;
    do {
      sVar4 = _IO_sgetn(param_2,local_2014,0x2000);
      if (sVar4 == 0) goto LAB_0809c560;
      sVar3 = (**(code **)(*(int *)(iVar1 + 0x4c) + 0x1c))(iVar1,local_2014,sVar4);
    } while (sVar3 == sVar4);
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 4;
LAB_0809c560:
    _IO_funlockfile(*(_IO_FILE **)*param_1);
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0xd) & 0x60) != 0) {
      do_osfx__7ostream(param_1);
    }
  }
  return param_1;
}


// __ls__7ostreamPCSc  @ 0809d3a8
void __ls__7ostreamPCSc(undefined4 param_1,undefined4 param_2)

{
  __ls__7ostreamPCc(param_1,param_2);
  return;
}


// __ls__7ostreamPCUc  @ 0809d3bc
void __ls__7ostreamPCUc(undefined4 param_1,undefined4 param_2)

{
  __ls__7ostreamPCc(param_1,param_2);
  return;
}


// __ls__7ostreamPCc  @ 0809c300
/* WARNING: Removing unreachable block (ram,0x0809c346) */
/* WARNING: Removing unreachable block (ram,0x0809c495) */

int * __ls__7ostreamPCc(int *param_1,uint *param_2)

{
  char cVar1;
  _IO_FILE *p_Var2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  __ssize_t _Var8;
  uint *puVar9;
  int iVar10;
  
  iVar4 = 0;
  if (param_1 != (int *)0x0) {
    iVar4 = *param_1;
  }
  if (*(char *)(iVar4 + 0x12) != '\0') {
    return param_1;
  }
  puVar6 = (undefined4 *)*param_1;
  if (puVar6[1] != 0) {
    flush__7ostream(puVar6[1]);
    puVar6 = (undefined4 *)*param_1;
  }
  _IO_flockfile((_IO_FILE *)*puVar6);
  if (param_2 == (uint *)0x0) {
    param_2 = &DAT_080a95be;
  }
  uVar5 = (uint)param_2 & 3;
  puVar3 = param_2;
  if (uVar5 != 0) {
    puVar9 = param_2;
    if ((POPCOUNT(uVar5) & 1U) != 0) {
      if (uVar5 != 2) {
        if ((char)*param_2 == '\0') goto LAB_0809c3a9;
        puVar9 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar9 == '\0') goto LAB_0809c3a9;
      puVar9 = (uint *)((int)puVar9 + 1);
    }
    if ((char)*puVar9 == '\0') goto LAB_0809c3a9;
    puVar3 = (uint *)((int)puVar9 + 1);
  }
  do {
    puVar9 = puVar3;
    uVar5 = *puVar9;
    if ((char)uVar5 == '\0') goto LAB_0809c3a9;
    if ((char)(uVar5 >> 8) == '\0') goto LAB_0809c3a8;
    if ((uVar5 & 0xff0000) == 0) goto LAB_0809c3a7;
    puVar3 = puVar9 + 1;
  } while ((uVar5 & 0xff000000) != 0);
  puVar9 = (uint *)((int)puVar9 + 1);
LAB_0809c3a7:
  puVar9 = (uint *)((int)puVar9 + 1);
LAB_0809c3a8:
  puVar9 = (uint *)((int)puVar9 + 1);
LAB_0809c3a9:
  iVar10 = (int)puVar9 - (int)param_2;
  iVar4 = 0;
  if (param_1 != (int *)0x0) {
    iVar4 = *param_1;
  }
  iVar7 = *(int *)(iVar4 + 8);
  *(undefined4 *)(iVar4 + 8) = 0;
  iVar4 = 0;
  if (param_1 != (int *)0x0) {
    iVar4 = *param_1;
  }
  cVar1 = *(char *)(iVar4 + 0x10);
  puVar6 = (undefined4 *)0x0;
  if (param_1 != (int *)0x0) {
    puVar6 = (undefined4 *)*param_1;
  }
  p_Var2 = (_IO_FILE *)*puVar6;
  iVar4 = 0;
  if (iVar10 < iVar7) {
    iVar4 = iVar7 - iVar10;
  }
  iVar7 = 0;
  if (param_1 != (int *)0x0) {
    iVar7 = *param_1;
  }
  if (((((*(byte *)(iVar7 + 0xc) & 2) == 0) && (0 < iVar4)) &&
      (_Var8 = _IO_padn(p_Var2,(int)cVar1,iVar4), _Var8 != iVar4)) ||
     (iVar7 = (**(code **)((int)p_Var2->_offset + 0x1c))(p_Var2,param_2,iVar10), iVar7 != iVar10)) {
    iVar4 = 0;
    if (param_1 != (int *)0x0) {
      iVar4 = *param_1;
    }
    *(byte *)(iVar4 + 0x12) = *(byte *)(iVar4 + 0x12) | 4;
  }
  else {
    iVar10 = 0;
    if (param_1 != (int *)0x0) {
      iVar10 = *param_1;
    }
    if ((((*(byte *)(iVar10 + 0xc) & 2) != 0) && (0 < iVar4)) &&
       (_Var8 = _IO_padn(p_Var2,(int)cVar1,iVar4), _Var8 != iVar4)) {
      iVar4 = 0;
      if (param_1 != (int *)0x0) {
        iVar4 = *param_1;
      }
      *(byte *)(iVar4 + 0x12) = *(byte *)(iVar4 + 0x12) | 4;
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
    iVar4 = 0;
    if (param_1 != (int *)0x0) {
      iVar4 = *param_1;
    }
    if ((*(byte *)(iVar4 + 0xd) & 0x60) != 0) {
      do_osfx__7ostream(param_1);
    }
  }
  return param_1;
}


// __ls__7ostreamPFR3ios_R3ios  @ 0809d31c
undefined4 * __ls__7ostreamPFR3ios_R3ios(undefined4 *param_1,code *param_2)

{
  (*param_2)(*param_1);
  return param_1;
}


// __ls__7ostreamPFR7ostream_R7ostream  @ 0809d334
void __ls__7ostreamPFR7ostream_R7ostream(undefined4 param_1,code *param_2)

{
  (*param_2)(param_1);
  return;
}


// __ls__7ostreamSc  @ 0809d3d0
void __ls__7ostreamSc(undefined4 param_1,char param_2)

{
  __ls__7ostreamc(param_1,(int)param_2);
  return;
}


// __ls__7ostreamUc  @ 0809d3e8
void __ls__7ostreamUc(undefined4 param_1,char param_2)

{
  __ls__7ostreamc(param_1,(int)param_2);
  return;
}


// __ls__7ostreamUi  @ 0809bc1c
/* WARNING: Removing unreachable block (ram,0x0809bc5d) */
/* WARNING: Removing unreachable block (ram,0x0809bc89) */

int * __ls__7ostreamUi(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2[1] != 0) {
      flush__7ostream(puVar2[1]);
      puVar2 = (undefined4 *)*param_1;
    }
    _IO_flockfile((_IO_FILE *)*puVar2);
    write_int__FR7ostreamUxi(param_1,param_2,0,0);
  }
  return param_1;
}


// __ls__7ostreamUl  @ 0809bd40
/* WARNING: Removing unreachable block (ram,0x0809bd81) */
/* WARNING: Removing unreachable block (ram,0x0809bdad) */

int * __ls__7ostreamUl(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2[1] != 0) {
      flush__7ostream(puVar2[1]);
      puVar2 = (undefined4 *)*param_1;
    }
    _IO_flockfile((_IO_FILE *)*puVar2);
    write_int__FR7ostreamUxi(param_1,param_2,0,0);
  }
  return param_1;
}


// __ls__7ostreamUs  @ 0809d378
void __ls__7ostreamUs(undefined4 param_1,undefined2 param_2)

{
  __ls__7ostreamUi(param_1,param_2);
  return;
}


// __ls__7ostreamUx  @ 0809be70
/* WARNING: Removing unreachable block (ram,0x0809beb1) */
/* WARNING: Removing unreachable block (ram,0x0809bede) */

int * __ls__7ostreamUx(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2[1] != 0) {
      flush__7ostream(puVar2[1]);
      puVar2 = (undefined4 *)*param_1;
    }
    _IO_flockfile((_IO_FILE *)*puVar2);
    write_int__FR7ostreamUxi(param_1,param_2,param_3,0);
  }
  return param_1;
}


// __ls__7ostreamb  @ 0809d360
void __ls__7ostreamb(undefined4 param_1,undefined1 param_2)

{
  __ls__7ostreami(param_1,param_2);
  return;
}


// __ls__7ostreamc  @ 0809b7cc
/* WARNING: Removing unreachable block (ram,0x0809b817) */
/* WARNING: Removing unreachable block (ram,0x0809b878) */

int * __ls__7ostreamc(int *param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2[1] != 0) {
      flush__7ostream(puVar2[1]);
      puVar2 = (undefined4 *)*param_1;
    }
    _IO_flockfile((_IO_FILE *)*puVar2);
    iVar1 = _IO_putc((int)param_2,*(_IO_FILE **)*param_1);
    if (iVar1 == -1) {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 4;
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0xd) & 0x60) != 0) {
      do_osfx__7ostream(param_1);
    }
  }
  return param_1;
}


// __ls__7ostreamd  @ 0809bef4
/* WARNING: Removing unreachable block (ram,0x0809bf3a) */
/* WARNING: Removing unreachable block (ram,0x0809c0df) */

int * __ls__7ostreamd(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 local_44;
  undefined1 *local_40;
  int local_3c [3];
  byte local_30;
  int local_2c;
  int local_28 [9];
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    puVar4 = (undefined4 *)*param_1;
    if (puVar4[1] != 0) {
      flush__7ostream(puVar4[1]);
      puVar4 = (undefined4 *)*param_1;
    }
    _IO_flockfile((_IO_FILE *)*puVar4);
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(uint *)(iVar1 + 0xc) & 0x1800) == 0x1000) {
      local_44 = 0x66;
    }
    else {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      if ((*(uint *)(iVar1 + 0xc) & 0x1800) == 0x800) {
        iVar1 = 0;
        if (param_1 != (int *)0x0) {
          iVar1 = *param_1;
        }
        local_44 = 0x65;
        if ((*(byte *)(iVar1 + 0xd) & 2) != 0) {
          local_44 = 0x45;
        }
      }
      else {
        iVar1 = 0;
        if (param_1 != (int *)0x0) {
          iVar1 = *param_1;
        }
        local_44 = 0x67;
        if ((*(byte *)(iVar1 + 0xd) & 2) != 0) {
          local_44 = 0x47;
        }
      }
    }
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    iVar1 = *(int *)(iVar1 + 0x14);
    if (iVar1 < 1) {
      iVar2 = 0;
      if (param_1 != (int *)0x0) {
        iVar2 = *param_1;
      }
      if ((*(byte *)(iVar2 + 0xd) & 0x10) == 0) {
        iVar1 = 6;
      }
    }
    piVar5 = local_3c;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar5 = 0;
      piVar5 = piVar5 + 1;
    }
    local_3c[0] = iVar1;
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    local_3c[1] = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar1 + 8) = 0;
    local_3c[2] = local_44;
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    iVar2 = 0;
    if (param_1 != (int *)0x0) {
      iVar2 = *param_1;
    }
    iVar3 = 0;
    if (param_1 != (int *)0x0) {
      iVar3 = *param_1;
    }
    local_30 = local_30 & 0x97 | ((byte)((uint)*(undefined4 *)(iVar1 + 0xc) >> 8) & 1) << 3 |
               ((byte)(*(uint *)(iVar2 + 0xc) >> 1) & 1) << 5 |
               ((byte)(*(uint *)(iVar3 + 0xc) >> 10) & 1) << 6;
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    local_2c = (int)*(short *)(iVar1 + 0x10);
    piVar5 = local_3c;
    piVar6 = local_28;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar6 = *piVar5;
      piVar5 = piVar5 + 1;
      piVar6 = piVar6 + 1;
    }
    local_40 = &stack0x00000008;
    puVar4 = (undefined4 *)0x0;
    if (param_1 != (int *)0x0) {
      puVar4 = (undefined4 *)*param_1;
    }
    iVar1 = __printf_fp(*puVar4,local_28,&local_40);
    if (iVar1 < 0) {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 6;
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0xd) & 0x60) != 0) {
      do_osfx__7ostream(param_1);
    }
  }
  return param_1;
}


// __ls__7ostreamf  @ 0809d344
void __ls__7ostreamf(undefined4 param_1,float param_2)

{
  __ls__7ostreamd(param_1,(double)param_2);
  return;
}


// __ls__7ostreami  @ 0809bb7c
/* WARNING: Removing unreachable block (ram,0x0809bbbd) */
/* WARNING: Removing unreachable block (ram,0x0809bc06) */

int * __ls__7ostreami(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2[1] != 0) {
      flush__7ostream(puVar2[1]);
      puVar2 = (undefined4 *)*param_1;
    }
    _IO_flockfile((_IO_FILE *)*puVar2);
    uVar3 = 1;
    if (param_2 < 0) {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      if ((*(byte *)(iVar1 + 0xc) & 0x60) == 0) {
        param_2 = -param_2;
        uVar3 = 0xffffffff;
      }
    }
    write_int__FR7ostreamUxi(param_1,param_2,0,uVar3);
  }
  return param_1;
}


// __ls__7ostreaml  @ 0809bca0
/* WARNING: Removing unreachable block (ram,0x0809bce1) */
/* WARNING: Removing unreachable block (ram,0x0809bd2a) */

int * __ls__7ostreaml(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2[1] != 0) {
      flush__7ostream(puVar2[1]);
      puVar2 = (undefined4 *)*param_1;
    }
    _IO_flockfile((_IO_FILE *)*puVar2);
    uVar3 = 1;
    if (param_2 < 0) {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      if ((*(byte *)(iVar1 + 0xc) & 0x60) == 0) {
        param_2 = -param_2;
        uVar3 = 0xffffffff;
      }
    }
    write_int__FR7ostreamUxi(param_1,param_2,0,uVar3);
  }
  return param_1;
}


// __ls__7ostreamr  @ 0809c0f8
/* WARNING: Removing unreachable block (ram,0x0809c13e) */
/* WARNING: Removing unreachable block (ram,0x0809c2e9) */

int * __ls__7ostreamr(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 local_44;
  undefined1 *local_40;
  int local_3c [3];
  byte local_30;
  int local_2c;
  int local_28 [9];
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    puVar4 = (undefined4 *)*param_1;
    if (puVar4[1] != 0) {
      flush__7ostream(puVar4[1]);
      puVar4 = (undefined4 *)*param_1;
    }
    _IO_flockfile((_IO_FILE *)*puVar4);
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(uint *)(iVar1 + 0xc) & 0x1800) == 0x1000) {
      local_44 = 0x66;
    }
    else {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      if ((*(uint *)(iVar1 + 0xc) & 0x1800) == 0x800) {
        iVar1 = 0;
        if (param_1 != (int *)0x0) {
          iVar1 = *param_1;
        }
        local_44 = 0x65;
        if ((*(byte *)(iVar1 + 0xd) & 2) != 0) {
          local_44 = 0x45;
        }
      }
      else {
        iVar1 = 0;
        if (param_1 != (int *)0x0) {
          iVar1 = *param_1;
        }
        local_44 = 0x67;
        if ((*(byte *)(iVar1 + 0xd) & 2) != 0) {
          local_44 = 0x47;
        }
      }
    }
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    iVar1 = *(int *)(iVar1 + 0x14);
    if (iVar1 < 1) {
      iVar2 = 0;
      if (param_1 != (int *)0x0) {
        iVar2 = *param_1;
      }
      if ((*(byte *)(iVar2 + 0xd) & 0x10) == 0) {
        iVar1 = 6;
      }
    }
    piVar5 = local_3c;
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar5 = 0;
      piVar5 = piVar5 + 1;
    }
    local_3c[0] = iVar1;
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    local_3c[1] = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar1 + 8) = 0;
    local_3c[2] = local_44;
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    iVar2 = 0;
    if (param_1 != (int *)0x0) {
      iVar2 = *param_1;
    }
    iVar3 = 0;
    if (param_1 != (int *)0x0) {
      iVar3 = *param_1;
    }
    local_30 = local_30 & 0x97 | 1 | ((byte)((uint)*(undefined4 *)(iVar1 + 0xc) >> 8) & 1) << 3 |
               ((byte)(*(uint *)(iVar2 + 0xc) >> 1) & 1) << 5 |
               ((byte)(*(uint *)(iVar3 + 0xc) >> 10) & 1) << 6;
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    local_2c = (int)*(short *)(iVar1 + 0x10);
    piVar5 = local_3c;
    piVar6 = local_28;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar6 = *piVar5;
      piVar5 = piVar5 + 1;
      piVar6 = piVar6 + 1;
    }
    local_40 = &stack0x00000008;
    puVar4 = (undefined4 *)0x0;
    if (param_1 != (int *)0x0) {
      puVar4 = (undefined4 *)*param_1;
    }
    iVar1 = __printf_fp(*puVar4,local_28,&local_40);
    if (iVar1 < 0) {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 6;
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0xd) & 0x60) != 0) {
      do_osfx__7ostream(param_1);
    }
  }
  return param_1;
}


// __ls__7ostreams  @ 0809d390
void __ls__7ostreams(undefined4 param_1,short param_2)

{
  __ls__7ostreami(param_1,(int)param_2);
  return;
}


// __ls__7ostreamx  @ 0809bdc4
/* WARNING: Removing unreachable block (ram,0x0809be0a) */
/* WARNING: Removing unreachable block (ram,0x0809be59) */

int * __ls__7ostreamx(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  bool bVar4;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2[1] != 0) {
      flush__7ostream(puVar2[1]);
      puVar2 = (undefined4 *)*param_1;
    }
    _IO_flockfile((_IO_FILE *)*puVar2);
    uVar3 = 1;
    if (param_3 < 0) {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      if ((*(byte *)(iVar1 + 0xc) & 0x60) == 0) {
        bVar4 = param_2 != 0;
        param_2 = -param_2;
        param_3 = -(param_3 + (uint)bVar4);
        uVar3 = 0xffffffff;
      }
    }
    write_int__FR7ostreamUxi(param_1,param_2,param_3,uVar3);
  }
  return param_1;
}


// __lt__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_b  @ 08097ec4
bool __lt__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_b
               (uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_1 & 3;
  puVar1 = param_1;
  if (uVar4 != 0) {
    puVar2 = param_1;
    if ((POPCOUNT(uVar4) & 1U) != 0) {
      if (uVar4 != 2) {
        if ((char)*param_1 == '\0') goto LAB_08097f0f;
        puVar2 = (uint *)((int)param_1 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08097f0f;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08097f0f;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar4 = *puVar2;
    if ((char)uVar4 == '\0') goto LAB_08097f0f;
    if ((char)(uVar4 >> 8) == '\0') goto LAB_08097f0e;
    if ((uVar4 & 0xff0000) == 0) goto LAB_08097f0d;
    puVar1 = puVar2 + 1;
  } while ((uVar4 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097f0d:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097f0e:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097f0f:
  iVar3 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
                    (param_2,param_1,0,(int)puVar2 - (int)param_1);
  return 0 < iVar3;
}


// __lt__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_b  @ 08097e60
uint __lt__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_b
               (undefined4 param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar3 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar3) & 1U) != 0) {
      if (uVar3 != 2) {
        if ((char)*param_2 == '\0') goto LAB_08097eab;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08097eab;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08097eab;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar3 = *puVar2;
    if ((char)uVar3 == '\0') goto LAB_08097eab;
    if ((char)(uVar3 >> 8) == '\0') goto LAB_08097eaa;
    if ((uVar3 & 0xff0000) == 0) goto LAB_08097ea9;
    puVar1 = puVar2 + 1;
  } while ((uVar3 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097ea9:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097eaa:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097eab:
  uVar3 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
                    (param_1,param_2,0,(int)puVar2 - (int)param_2);
  return uVar3 >> 0x1f;
}


// __lt__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b  @ 08097f28
uint __lt__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b
               (undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
                    (param_1,param_2,0,0xffffffff);
  return uVar1 >> 0x1f;
}


// __ne__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_b  @ 08097fa8
bool __ne__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_b
               (uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_1 & 3;
  puVar1 = param_1;
  if (uVar4 != 0) {
    puVar2 = param_1;
    if ((POPCOUNT(uVar4) & 1U) != 0) {
      if (uVar4 != 2) {
        if ((char)*param_1 == '\0') goto LAB_08097ff3;
        puVar2 = (uint *)((int)param_1 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08097ff3;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08097ff3;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar4 = *puVar2;
    if ((char)uVar4 == '\0') goto LAB_08097ff3;
    if ((char)(uVar4 >> 8) == '\0') goto LAB_08097ff2;
    if ((uVar4 & 0xff0000) == 0) goto LAB_08097ff1;
    puVar1 = puVar2 + 1;
  } while ((uVar4 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097ff1:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097ff2:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097ff3:
  iVar3 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
                    (param_2,param_1,0,(int)puVar2 - (int)param_1);
  return iVar3 != 0;
}


// __ne__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_b  @ 08097f44
bool __ne__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_b
               (undefined4 param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar4 != 0) {
    puVar2 = param_2;
    if ((POPCOUNT(uVar4) & 1U) != 0) {
      if (uVar4 != 2) {
        if ((char)*param_2 == '\0') goto LAB_08097f8f;
        puVar2 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar2 == '\0') goto LAB_08097f8f;
      puVar2 = (uint *)((int)puVar2 + 1);
    }
    if ((char)*puVar2 == '\0') goto LAB_08097f8f;
    puVar1 = (uint *)((int)puVar2 + 1);
  }
  do {
    puVar2 = puVar1;
    uVar4 = *puVar2;
    if ((char)uVar4 == '\0') goto LAB_08097f8f;
    if ((char)(uVar4 >> 8) == '\0') goto LAB_08097f8e;
    if ((uVar4 & 0xff0000) == 0) goto LAB_08097f8d;
    puVar1 = puVar2 + 1;
  } while ((uVar4 & 0xff000000) != 0);
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097f8d:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097f8e:
  puVar2 = (uint *)((int)puVar2 + 1);
LAB_08097f8f:
  iVar3 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUiUi
                    (param_1,param_2,0,(int)puVar2 - (int)param_2);
  return iVar3 != 0;
}


// __ne__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b  @ 0809800c
bool __ne__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_b
               (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = compare__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
                    (param_1,param_2,0,0xffffffff);
  return iVar1 != 0;
}


// __nw__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi  @ 08099bc8
undefined4 *
__nw__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUiUi
          (int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint __size;
  
  __size = param_2 + param_1;
  if (__size < 0x81) {
    iVar1 = (__size + 7 >> 3) * 4;
    pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    puVar2 = *(undefined4 **)(&DAT_080ab95c + iVar1);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)refill__t24__default_alloc_template2b1i0Ui(__size + 7 & 0xfffffff8);
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      *(undefined4 *)(&DAT_080ab95c + iVar1) = *puVar2;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
  }
  else {
    puVar2 = malloc(__size);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)oom_malloc__t23__malloc_alloc_template1i0Ui(__size);
    }
  }
  return puVar2;
}


// __out_of_range__FPCc  @ 08099f90
void __out_of_range__FPCc(uint *param_1)

{
  undefined *puVar1;
  int iVar2;
  code *pcVar3;
  undefined *puVar4;
  uint *puVar5;
  uint *puVar6;
  int *piVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined1 **ppuVar10;
  undefined1 *puVar11;
  undefined *local_10;
  undefined1 *local_c;
  undefined *local_8;
  
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    local_10 = &force_to_data;
  }
  else {
    local_10 = (undefined *)
               clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                         (
                         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                         );
  }
  uVar9 = (uint)param_1 & 3;
  puVar5 = param_1;
  if (uVar9 != 0) {
    puVar6 = param_1;
    if ((POPCOUNT(uVar9) & 1U) != 0) {
      if (uVar9 != 2) {
        if ((char)*param_1 == '\0') goto LAB_0809a007;
        puVar6 = (uint *)((int)param_1 + 1);
      }
      if ((char)*puVar6 == '\0') goto LAB_0809a007;
      puVar6 = (uint *)((int)puVar6 + 1);
    }
    if ((char)*puVar6 == '\0') goto LAB_0809a007;
    puVar5 = (uint *)((int)puVar6 + 1);
  }
  do {
    puVar6 = puVar5;
    uVar9 = *puVar6;
    if ((char)uVar9 == '\0') goto LAB_0809a007;
    if ((char)(uVar9 >> 8) == '\0') goto LAB_0809a006;
    if ((uVar9 & 0xff0000) == 0) goto LAB_0809a005;
    puVar5 = puVar6 + 1;
  } while ((uVar9 & 0xff000000) != 0);
  puVar6 = (uint *)((int)puVar6 + 1);
LAB_0809a005:
  puVar6 = (uint *)((int)puVar6 + 1);
LAB_0809a006:
  puVar6 = (uint *)((int)puVar6 + 1);
LAB_0809a007:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (&local_10,0,0xffffffff,param_1,(int)puVar6 - (int)param_1);
  ppuVar10 = &local_c;
  local_c = __vt_11logic_error;
  if (local_10[-4] == '\0') {
    *(int *)(local_10 + -8) = *(int *)(local_10 + -8) + 1;
    local_8 = local_10;
  }
  else {
    local_8 = (undefined *)
              clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (local_10 + -0x10);
  }
  local_c = __vt_12out_of_range;
  piVar7 = (int *)__eh_alloc(8);
  __11logic_errorRC11logic_error(piVar7,ppuVar10);
  *piVar7 = (int)__vt_12out_of_range;
  puVar11 = &stack0xffffffdc;
  do {
    *(undefined4 *)(puVar11 + -4) = 2;
    *(undefined1 ***)(puVar11 + -8) = ppuVar10;
    *(undefined4 *)(puVar11 + -0xc) = 0x809a090;
    ___11logic_error();
    puVar4 = local_10;
    puVar1 = local_10 + -0x10;
    iVar2 = *(int *)(local_10 + -8);
    *(int *)(local_10 + -8) = iVar2 + -1;
    if (iVar2 == 1) {
      if (*(int *)(local_10 + -0xc) + 0x10U < 0x81) {
        iVar2 = (*(int *)(local_10 + -0xc) + 0x17U >> 3) * 4;
        ppuVar10 = (undefined1 **)(iVar2 + -4);
        *(undefined1 **)(puVar11 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar11 + -8) = 0x809a0e7;
        pthread_mutex_lock(*(pthread_mutex_t **)(puVar11 + -4));
        *(undefined4 *)(puVar4 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar2);
        *(undefined **)(&DAT_080ab95c + iVar2) = puVar1;
        *(undefined1 **)(puVar11 + -4) = _t24__default_alloc_template2b1i0___node_allocator_lock;
        *(undefined4 *)(puVar11 + -8) = 0x809a106;
        pthread_mutex_unlock(*(pthread_mutex_t **)(puVar11 + -4));
      }
      else {
        *(undefined **)(puVar11 + -4) = puVar1;
        *(undefined4 *)(puVar11 + -8) = 0x809a0cd;
        free(*(void **)(puVar11 + -4));
      }
    }
    *(code **)(puVar11 + -4) = ___12out_of_range;
    pcVar3 = *(code **)(*piVar7 + 4);
    *(undefined4 *)(puVar11 + -8) = 0x809a115;
    uVar8 = (*pcVar3)();
    *(undefined4 *)(puVar11 + -8) = uVar8;
    *(int **)(puVar11 + -0xc) = piVar7;
    *(undefined4 *)(puVar11 + -0x10) = 0x809a11c;
    __cp_push_exception();
    *(undefined4 *)(puVar11 + -0x10) = 0x809a121;
    __throw();
    *(undefined4 *)(puVar11 + -0x10) = 0x809a129;
    terminate__Fv();
    *(undefined4 *)(puVar11 + -0x10) = 2;
    *(undefined1 ***)(puVar11 + -0x14) = ppuVar10;
    *(undefined4 *)(puVar11 + -0x18) = 0x809a134;
    ___11logic_error();
    *(undefined4 *)(puVar11 + -0x10) = 0x809a085;
    __throw();
    puVar11 = puVar11 + -0xc;
  } while( true );
}


// __pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21  @ 0809856c
undefined4 *
__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_PCX01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21
          (undefined4 *param_1,uint *param_2,undefined4 param_3)

{
  int iVar1;
  undefined *puVar2;
  uint *puVar3;
  uint *puVar4;
  undefined *puVar5;
  uint uVar6;
  undefined *local_8;
  
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    local_8 = &force_to_data;
  }
  else {
    local_8 = (undefined *)
              clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (
                        _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                        );
  }
  uVar6 = (uint)param_2 & 3;
  puVar3 = param_2;
  if (uVar6 != 0) {
    puVar4 = param_2;
    if ((POPCOUNT(uVar6) & 1U) != 0) {
      if (uVar6 != 2) {
        if ((char)*param_2 == '\0') goto LAB_080985e3;
        puVar4 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar4 == '\0') goto LAB_080985e3;
      puVar4 = (uint *)((int)puVar4 + 1);
    }
    if ((char)*puVar4 == '\0') goto LAB_080985e3;
    puVar3 = (uint *)((int)puVar4 + 1);
  }
  do {
    puVar4 = puVar3;
    uVar6 = *puVar4;
    if ((char)uVar6 == '\0') goto LAB_080985e3;
    if ((char)(uVar6 >> 8) == '\0') goto LAB_080985e2;
    if ((uVar6 & 0xff0000) == 0) goto LAB_080985e1;
    puVar3 = puVar4 + 1;
  } while ((uVar6 & 0xff000000) != 0);
  puVar4 = (uint *)((int)puVar4 + 1);
LAB_080985e1:
  puVar4 = (uint *)((int)puVar4 + 1);
LAB_080985e2:
  puVar4 = (uint *)((int)puVar4 + 1);
LAB_080985e3:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (&local_8,0,0xffffffff,param_2,(int)puVar4 - (int)param_2);
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (&local_8,*(undefined4 *)(local_8 + -0x10),0,param_3,0,0xffffffff);
  if (local_8[-4] == '\0') {
    *(int *)(local_8 + -8) = *(int *)(local_8 + -8) + 1;
    puVar5 = local_8;
  }
  else {
    puVar5 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (local_8 + -0x10);
  }
  puVar2 = local_8;
  *param_1 = puVar5;
  puVar5 = local_8 + -0x10;
  iVar1 = *(int *)(local_8 + -8);
  *(int *)(local_8 + -8) = iVar1 + -1;
  if (iVar1 == 1) {
    if (*(int *)(local_8 + -0xc) + 0x10U < 0x81) {
      iVar1 = (*(int *)(local_8 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar1);
      *(undefined **)(&DAT_080ab95c + iVar1) = puVar5;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free(puVar5);
    }
  }
  return param_1;
}


// __pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_t12basic_string3ZX01ZX11ZX21  @ 08098268
int * __pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21PCX01_t12basic_string3ZX01ZX11ZX21
                (int *param_1,int *param_2,uint *param_3)

{
  void *__ptr;
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int local_8;
  
  local_8 = *param_2;
  if (*(char *)(local_8 + -4) == '\0') {
    *(int *)(local_8 + -8) = *(int *)(local_8 + -8) + 1;
  }
  else {
    local_8 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (local_8 + -0x10);
  }
  uVar5 = (uint)param_3 & 3;
  puVar2 = param_3;
  if (uVar5 != 0) {
    puVar3 = param_3;
    if ((POPCOUNT(uVar5) & 1U) != 0) {
      if (uVar5 != 2) {
        if ((char)*param_3 == '\0') goto LAB_080982dc;
        puVar3 = (uint *)((int)param_3 + 1);
      }
      if ((char)*puVar3 == '\0') goto LAB_080982dc;
      puVar3 = (uint *)((int)puVar3 + 1);
    }
    if ((char)*puVar3 == '\0') goto LAB_080982dc;
    puVar2 = (uint *)((int)puVar3 + 1);
  }
  do {
    puVar3 = puVar2;
    uVar5 = *puVar3;
    if ((char)uVar5 == '\0') goto LAB_080982dc;
    if ((char)(uVar5 >> 8) == '\0') goto LAB_080982db;
    if ((uVar5 & 0xff0000) == 0) goto LAB_080982da;
    puVar2 = puVar3 + 1;
  } while ((uVar5 & 0xff000000) != 0);
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_080982da:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_080982db:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_080982dc:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (&local_8,*(undefined4 *)(local_8 + -0x10),0,param_3,(int)puVar3 - (int)param_3);
  if (*(char *)(local_8 + -4) == '\0') {
    *(int *)(local_8 + -8) = *(int *)(local_8 + -8) + 1;
    iVar4 = local_8;
  }
  else {
    iVar4 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (local_8 + -0x10);
  }
  iVar1 = local_8;
  *param_1 = iVar4;
  __ptr = (void *)(local_8 + -0x10);
  iVar4 = *(int *)(local_8 + -8);
  *(int *)(local_8 + -8) = iVar4 + -1;
  if (iVar4 == 1) {
    if (*(int *)(local_8 + -0xc) + 0x10U < 0x81) {
      iVar4 = (*(int *)(local_8 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(iVar1 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar4);
      *(void **)(&DAT_080ab95c + iVar4) = __ptr;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free(__ptr);
    }
  }
  return param_1;
}


// __pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_t12basic_string3ZX01ZX11ZX21  @ 0809871c
int * __pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21T0_t12basic_string3ZX01ZX11ZX21
                (int *param_1,int *param_2,undefined4 param_3)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = *param_2;
  if (*(char *)(local_8 + -4) == '\0') {
    *(int *)(local_8 + -8) = *(int *)(local_8 + -8) + 1;
  }
  else {
    local_8 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (local_8 + -0x10);
  }
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (&local_8,*(undefined4 *)(local_8 + -0x10),0,param_3,0,0xffffffff);
  if (*(char *)(local_8 + -4) == '\0') {
    *(int *)(local_8 + -8) = *(int *)(local_8 + -8) + 1;
    iVar2 = local_8;
  }
  else {
    iVar2 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (local_8 + -0x10);
  }
  iVar1 = local_8;
  *param_1 = iVar2;
  __ptr = (void *)(local_8 + -0x10);
  iVar2 = *(int *)(local_8 + -8);
  *(int *)(local_8 + -8) = iVar2 + -1;
  if (iVar2 == 1) {
    if (*(int *)(local_8 + -0xc) + 0x10U < 0x81) {
      iVar2 = (*(int *)(local_8 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(iVar1 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar2);
      *(void **)(&DAT_080ab95c + iVar2) = __ptr;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free(__ptr);
    }
  }
  return param_1;
}


// __pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21X01_t12basic_string3ZX01ZX11ZX21  @ 08098114
int * __pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_RCt12basic_string3ZX01ZX11ZX21X01_t12basic_string3ZX01ZX11ZX21
                (int *param_1,int *param_2,char param_3)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = *param_2;
  if (*(char *)(local_8 + -4) == '\0') {
    *(int *)(local_8 + -8) = *(int *)(local_8 + -8) + 1;
  }
  else {
    local_8 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (local_8 + -0x10);
  }
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (&local_8,*(undefined4 *)(local_8 + -0x10),0,1,(int)param_3);
  if (*(char *)(local_8 + -4) == '\0') {
    *(int *)(local_8 + -8) = *(int *)(local_8 + -8) + 1;
    iVar2 = local_8;
  }
  else {
    iVar2 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (local_8 + -0x10);
  }
  iVar1 = local_8;
  *param_1 = iVar2;
  __ptr = (void *)(local_8 + -0x10);
  iVar2 = *(int *)(local_8 + -8);
  *(int *)(local_8 + -8) = iVar2 + -1;
  if (iVar2 == 1) {
    if (*(int *)(local_8 + -0xc) + 0x10U < 0x81) {
      iVar2 = (*(int *)(local_8 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(iVar1 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar2);
      *(void **)(&DAT_080ab95c + iVar2) = __ptr;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free(__ptr);
    }
  }
  return param_1;
}


// __pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_X01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21  @ 080983fc
undefined4 *
__pl__H3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_X01RCt12basic_string3ZX01ZX11ZX21_t12basic_string3ZX01ZX11ZX21
          (undefined4 *param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *local_8;
  
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    local_8 = &force_to_data;
  }
  else {
    local_8 = (undefined *)
              clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (
                        _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                        );
  }
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (&local_8,0,0xffffffff,1,(int)param_2);
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (&local_8,*(undefined4 *)(local_8 + -0x10),0,param_3,0,0xffffffff);
  if (local_8[-4] == '\0') {
    *(int *)(local_8 + -8) = *(int *)(local_8 + -8) + 1;
    puVar3 = local_8;
  }
  else {
    puVar3 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (local_8 + -0x10);
  }
  puVar2 = local_8;
  *param_1 = puVar3;
  puVar3 = local_8 + -0x10;
  iVar1 = *(int *)(local_8 + -8);
  *(int *)(local_8 + -8) = iVar1 + -1;
  if (iVar1 == 1) {
    if (*(int *)(local_8 + -0xc) + 0x10U < 0x81) {
      iVar1 = (*(int *)(local_8 + -0xc) + 0x17U >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      *(undefined4 *)(puVar2 + -0x10) = *(undefined4 *)(&DAT_080ab95c + iVar1);
      *(undefined **)(&DAT_080ab95c + iVar1) = puVar3;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      free(puVar3);
    }
  }
  return param_1;
}


// __rs__7istreamP9streambuf  @ 0809b718
int * __rs__7istreamP9streambuf(int *param_1,_IO_FILE *param_2)

{
  _IO_FILE *__fp;
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    _IO_flockfile(*(_IO_FILE **)*param_1);
    if (*(int *)(*param_1 + 4) != 0) {
      flush__7ostream(*(int *)(*param_1 + 4));
    }
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0xc) & 1) == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = _skip_ws__7istream(param_1);
    }
    if (iVar1 == 0) {
      return param_1;
    }
    puVar2 = (undefined4 *)0x0;
    if (param_1 != (int *)0x0) {
      puVar2 = (undefined4 *)*param_1;
    }
    __fp = (_IO_FILE *)*puVar2;
    do {
      iVar1 = _IO_getc(__fp);
      if (iVar1 == -1) {
        iVar1 = 0;
        if (param_1 != (int *)0x0) {
          iVar1 = *param_1;
        }
        *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 1;
        return param_1;
      }
      iVar1 = _IO_putc(iVar1,param_2);
    } while (iVar1 != -1);
  }
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
  return param_1;
}


// __rs__7istreamPFR3ios_R3ios  @ 0809cde0
undefined4 * __rs__7istreamPFR3ios_R3ios(undefined4 *param_1,code *param_2)

{
  (*param_2)(*param_1);
  return param_1;
}


// __rs__7istreamPFR7istream_R7istream  @ 0809cdd0
void __rs__7istreamPFR7istream_R7istream(undefined4 param_1,code *param_2)

{
  (*param_2)(param_1);
  return;
}


// __rs__7istreamPSc  @ 0809ce20
void __rs__7istreamPSc(undefined4 param_1,undefined4 param_2)

{
  __rs__7istreamPc(param_1,param_2);
  return;
}


// __rs__7istreamPUc  @ 0809ce34
void __rs__7istreamPUc(undefined4 param_1,undefined4 param_2)

{
  __rs__7istreamPc(param_1,param_2);
  return;
}


// __rs__7istreamPc  @ 0809af88
int * __rs__7istreamPc(int *param_1,char *param_2)

{
  _IO_FILE *__fp;
  int iVar1;
  char *pcVar2;
  int local_c;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  local_c = *(int *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 8) = 0;
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  pcVar2 = param_2;
  if (*(char *)(iVar1 + 0x12) == '\0') {
    _IO_flockfile(*(_IO_FILE **)*param_1);
    if (*(int *)(*param_1 + 4) != 0) {
      flush__7ostream(*(int *)(*param_1 + 4));
    }
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0xc) & 1) == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = _skip_ws__7istream(param_1);
    }
    if (iVar1 == 0) goto LAB_0809b05f;
    __fp = *(_IO_FILE **)*param_1;
    while( true ) {
      iVar1 = _IO_getc(__fp);
      if (iVar1 == -1) break;
      if (((*(byte *)(__ctype_b + 1 + iVar1 * 2) & 0x20) != 0) || (local_c == 1)) {
        sputbackc__9streambufc(__fp,(int)(char)iVar1);
        goto LAB_0809b04e;
      }
      *pcVar2 = (char)iVar1;
      pcVar2 = pcVar2 + 1;
      local_c = local_c + -1;
    }
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 1;
LAB_0809b04e:
    if (pcVar2 != param_2) goto LAB_0809b05f;
  }
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
LAB_0809b05f:
  *pcVar2 = '\0';
  return param_1;
}


// __rs__7istreamRSc  @ 0809cdf8
void __rs__7istreamRSc(undefined4 param_1,undefined4 param_2)

{
  __rs__7istreamRc(param_1,param_2);
  return;
}


// __rs__7istreamRUc  @ 0809ce0c
void __rs__7istreamRUc(undefined4 param_1,undefined4 param_2)

{
  __rs__7istreamRc(param_1,param_2);
  return;
}


// __rs__7istreamRUi  @ 0809b408
undefined4 __rs__7istreamRUi(undefined4 param_1,int *param_2)

{
  int iVar1;
  int local_10 [2];
  int local_8;
  
  iVar1 = read_int__FR7istreamRUxRi(param_1,local_10,&local_8);
  if (iVar1 != 0) {
    if (local_8 != 0) {
      local_10[0] = -local_10[0];
    }
    *param_2 = local_10[0];
  }
  return param_1;
}


// __rs__7istreamRUl  @ 0809b488
undefined4 __rs__7istreamRUl(undefined4 param_1,int *param_2)

{
  int iVar1;
  int local_10 [2];
  int local_8;
  
  iVar1 = read_int__FR7istreamRUxRi(param_1,local_10,&local_8);
  if (iVar1 != 0) {
    if (local_8 != 0) {
      local_10[0] = -local_10[0];
    }
    *param_2 = local_10[0];
  }
  return param_1;
}


// __rs__7istreamRUs  @ 0809b388
undefined4 __rs__7istreamRUs(undefined4 param_1,short *param_2)

{
  int iVar1;
  short local_10 [4];
  int local_8;
  
  iVar1 = read_int__FR7istreamRUxRi(param_1,local_10,&local_8);
  if (iVar1 != 0) {
    if (local_8 != 0) {
      local_10[0] = -local_10[0];
    }
    *param_2 = local_10[0];
  }
  return param_1;
}


// __rs__7istreamRUx  @ 0809b50c
undefined4 __rs__7istreamRUx(undefined4 param_1,int *param_2)

{
  int iVar1;
  bool bVar2;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = read_int__FR7istreamRUxRi(param_1,&local_10,&local_8);
  if (iVar1 != 0) {
    if (local_8 != 0) {
      bVar2 = local_10 != 0;
      local_10 = -local_10;
      local_c = -(local_c + (uint)bVar2);
    }
    *param_2 = local_10;
    param_2[1] = local_c;
  }
  return param_1;
}


// __rs__7istreamRb  @ 0809b550
undefined4 __rs__7istreamRb(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = read_int__FR7istreamRUxRi(param_1,&local_10,&local_8);
  if (iVar1 != 0) {
    if (local_8 != 0) {
      bVar2 = local_10 != 0;
      local_10 = -local_10;
      local_c = -(local_c + (uint)bVar2);
    }
    *(bool *)param_2 = local_10 != 0 || local_c != 0;
  }
  return param_1;
}


// __rs__7istreamRc  @ 0809aef4
int * __rs__7istreamRc(int *param_1,undefined1 *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    _IO_flockfile(*(_IO_FILE **)*param_1);
    if (*(int *)(*param_1 + 4) != 0) {
      flush__7ostream(*(int *)(*param_1 + 4));
    }
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0xc) & 1) == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = _skip_ws__7istream(param_1);
    }
    if (iVar1 != 0) {
      iVar1 = _IO_getc(*(_IO_FILE **)*param_1);
      if (iVar1 == -1) {
        iVar1 = 0;
        if (param_1 != (int *)0x0) {
          iVar1 = *param_1;
        }
        *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 3;
      }
      else {
        *param_2 = (char)iVar1;
      }
    }
  }
  else {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
  }
  return param_1;
}


// __rs__7istreamRd  @ 0809b618
int * __rs__7istreamRd(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    _IO_flockfile(*(_IO_FILE **)*param_1);
    if (*(int *)(*param_1 + 4) != 0) {
      flush__7ostream(*(int *)(*param_1 + 4));
    }
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0xc) & 1) == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = _skip_ws__7istream(param_1);
    }
    if (iVar1 != 0) {
      scan__7istreamPCce(param_1,&DAT_080a9590,param_2);
    }
  }
  else {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
  }
  return param_1;
}


// __rs__7istreamRf  @ 0809b698
int * __rs__7istreamRf(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    _IO_flockfile(*(_IO_FILE **)*param_1);
    if (*(int *)(*param_1 + 4) != 0) {
      flush__7ostream(*(int *)(*param_1 + 4));
    }
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0xc) & 1) == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = _skip_ws__7istream(param_1);
    }
    if (iVar1 != 0) {
      scan__7istreamPCce(param_1,&DAT_080a9594,param_2);
    }
  }
  else {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
  }
  return param_1;
}


// __rs__7istreamRi  @ 0809b3c8
undefined4 __rs__7istreamRi(undefined4 param_1,int *param_2)

{
  int iVar1;
  int local_10 [2];
  int local_8;
  
  iVar1 = read_int__FR7istreamRUxRi(param_1,local_10,&local_8);
  if (iVar1 != 0) {
    if (local_8 != 0) {
      local_10[0] = -local_10[0];
    }
    *param_2 = local_10[0];
  }
  return param_1;
}


// __rs__7istreamRl  @ 0809b448
undefined4 __rs__7istreamRl(undefined4 param_1,int *param_2)

{
  int iVar1;
  int local_10 [2];
  int local_8;
  
  iVar1 = read_int__FR7istreamRUxRi(param_1,local_10,&local_8);
  if (iVar1 != 0) {
    if (local_8 != 0) {
      local_10[0] = -local_10[0];
    }
    *param_2 = local_10[0];
  }
  return param_1;
}


// __rs__7istreamRr  @ 0809b598
int * __rs__7istreamRr(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    _IO_flockfile(*(_IO_FILE **)*param_1);
    if (*(int *)(*param_1 + 4) != 0) {
      flush__7ostream(*(int *)(*param_1 + 4));
    }
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0xc) & 1) == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = _skip_ws__7istream(param_1);
    }
    if (iVar1 != 0) {
      scan__7istreamPCce(param_1,&DAT_080a958c,param_2);
    }
  }
  else {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
  }
  return param_1;
}


// __rs__7istreamRs  @ 0809b348
undefined4 __rs__7istreamRs(undefined4 param_1,short *param_2)

{
  int iVar1;
  short local_10 [4];
  int local_8;
  
  iVar1 = read_int__FR7istreamRUxRi(param_1,local_10,&local_8);
  if (iVar1 != 0) {
    if (local_8 != 0) {
      local_10[0] = -local_10[0];
    }
    *param_2 = local_10[0];
  }
  return param_1;
}


// __rs__7istreamRx  @ 0809b4c8
undefined4 __rs__7istreamRx(undefined4 param_1,int *param_2)

{
  int iVar1;
  bool bVar2;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = read_int__FR7istreamRUxRi(param_1,&local_10,&local_8);
  if (iVar1 != 0) {
    if (local_8 != 0) {
      bVar2 = local_10 != 0;
      local_10 = -local_10;
      local_c = -(local_c + (uint)bVar2);
    }
    *param_2 = local_10;
    param_2[1] = local_c;
  }
  return param_1;
}


// __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 080999c4
undefined4 *
__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0(undefined4 *param_1)

{
  undefined *puVar1;
  
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    puVar1 = &force_to_data;
  }
  else {
    puVar1 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (
                       _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                       );
  }
  *param_1 = puVar1;
  return param_1;
}


// __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc  @ 08099740
undefined4 *
__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
          (undefined4 *param_1,uint *param_2)

{
  uint *puVar1;
  undefined *puVar2;
  uint *puVar3;
  uint uVar4;
  
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    puVar2 = &force_to_data;
  }
  else {
    puVar2 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (
                       _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                       );
  }
  *param_1 = puVar2;
  uVar4 = (uint)param_2 & 3;
  puVar1 = param_2;
  if (uVar4 != 0) {
    puVar3 = param_2;
    if ((POPCOUNT(uVar4) & 1U) != 0) {
      if (uVar4 != 2) {
        if ((char)*param_2 == '\0') goto LAB_080997b2;
        puVar3 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar3 == '\0') goto LAB_080997b2;
      puVar3 = (uint *)((int)puVar3 + 1);
    }
    if ((char)*puVar3 == '\0') goto LAB_080997b2;
    puVar1 = (uint *)((int)puVar3 + 1);
  }
  do {
    puVar3 = puVar1;
    uVar4 = *puVar3;
    if ((char)uVar4 == '\0') goto LAB_080997b2;
    if ((char)(uVar4 >> 8) == '\0') goto LAB_080997b1;
    if ((uVar4 & 0xff0000) == 0) goto LAB_080997b0;
    puVar1 = puVar3 + 1;
  } while ((uVar4 & 0xff000000) != 0);
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_080997b0:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_080997b1:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_080997b2:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,0,0xffffffff,param_2,(int)puVar3 - (int)param_2);
  return param_1;
}


// __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi  @ 0809982c
undefined4 *
__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCcUi
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    puVar1 = &force_to_data;
  }
  else {
    puVar1 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (
                       _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                       );
  }
  *param_1 = puVar1;
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,0,0xffffffff,param_2,param_3);
  return param_1;
}


// __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0  @ 08099994
int * __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0
                (int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (*(char *)(iVar1 + -4) == '\0') {
    *(int *)(iVar1 + -8) = *(int *)(iVar1 + -8) + 1;
  }
  else {
    iVar1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                      (iVar1 + -0x10);
  }
  *param_1 = iVar1;
  return param_1;
}


// __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi  @ 08099890
undefined4 *
__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0RCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    puVar1 = &force_to_data;
  }
  else {
    puVar1 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (
                       _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                       );
  }
  *param_1 = puVar1;
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (param_1,0,0xffffffff,param_2,param_3,param_4);
  return param_1;
}


// __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic  @ 080996ac
undefined4 *
__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uic
          (undefined4 *param_1,undefined4 param_2,char param_3)

{
  undefined *puVar1;
  
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    puVar1 = &force_to_data;
  }
  else {
    puVar1 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (
                       _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                       );
  }
  *param_1 = puVar1;
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiUic
            (param_1,0,0xffffffff,param_2,(int)param_3);
  return param_1;
}


// __tf10EasySocket  @ 0808eed0
undefined4 * __tf10EasySocket(void)

{
  if (__ti10EasySocket == 0) {
    __rtti_user(&__ti10EasySocket,"10EasySocket");
  }
  return &__ti10EasySocket;
}


// __tf11AuthRequest  @ 08094c50
undefined4 * __tf11AuthRequest(void)

{
  if (__ti11AuthRequest == 0) {
    __tf12TitanRequest();
    __rtti_si(&__ti11AuthRequest,"11AuthRequest",&__ti12TitanRequest);
  }
  return &__ti11AuthRequest;
}


// __tf11WriteBuffer  @ 08090cf0
undefined4 * __tf11WriteBuffer(void)

{
  if (__ti11WriteBuffer == 0) {
    __rtti_user(&__ti11WriteBuffer,"11WriteBuffer");
  }
  return &__ti11WriteBuffer;
}


// __tf11logic_error  @ 0809aa28
undefined4 * __tf11logic_error(void)

{
  if (__ti11logic_error == 0) {
    __tf9exception();
    __rtti_si(&__ti11logic_error,"11logic_error",&__ti9exception);
  }
  return &__ti11logic_error;
}


// __tf11range_error  @ 0809a568
undefined4 * __tf11range_error(void)

{
  if (__ti11range_error == 0) {
    __tf13runtime_error();
    __rtti_si(&__ti11range_error,"11range_error",&__ti13runtime_error);
  }
  return &__ti11range_error;
}


// __tf12TitanRequest  @ 08095ce0
undefined4 * __tf12TitanRequest(void)

{
  if (__ti12TitanRequest == 0) {
    __rtti_user(&__ti12TitanRequest,"12TitanRequest");
  }
  return &__ti12TitanRequest;
}


// __tf12domain_error  @ 0809a96c
undefined4 * __tf12domain_error(void)

{
  if (__ti12domain_error == 0) {
    __tf11logic_error();
    __rtti_si(&__ti12domain_error,"12domain_error",&__ti11logic_error);
  }
  return &__ti12domain_error;
}


// __tf12length_error  @ 0809a834
undefined4 * __tf12length_error(void)

{
  if (__ti12length_error == 0) {
    __tf11logic_error();
    __rtti_si(&__ti12length_error,"12length_error",&__ti11logic_error);
  }
  return &__ti12length_error;
}


// __tf12out_of_range  @ 0809a798
undefined4 * __tf12out_of_range(void)

{
  if (__ti12out_of_range == 0) {
    __tf11logic_error();
    __rtti_si(&__ti12out_of_range,"12out_of_range",&__ti11logic_error);
  }
  return &__ti12out_of_range;
}


// __tf13runtime_error  @ 0809a680
undefined4 * __tf13runtime_error(void)

{
  if (__ti13runtime_error == 0) {
    __tf9exception();
    __rtti_si(&__ti13runtime_error,"13runtime_error",&__ti9exception);
  }
  return &__ti13runtime_error;
}


// __tf14overflow_error  @ 0809a4cc
undefined4 * __tf14overflow_error(void)

{
  if (__ti14overflow_error == 0) {
    __tf13runtime_error();
    __rtti_si(&__ti14overflow_error,"14overflow_error",&__ti13runtime_error);
  }
  return &__ti14overflow_error;
}


// __tf15EasyTitanSocket  @ 0808dac0
undefined4 * __tf15EasyTitanSocket(void)

{
  if (__ti15EasyTitanSocket == 0) {
    __tf10EasySocket();
    __rtti_si(&__ti15EasyTitanSocket,"15EasyTitanSocket",&__ti10EasySocket);
  }
  return &__ti15EasyTitanSocket;
}


// __tf15underflow_error  @ 0809a430
undefined4 * __tf15underflow_error(void)

{
  if (__ti15underflow_error == 0) {
    __tf13runtime_error();
    __rtti_si(&__ti15underflow_error,"15underflow_error",&__ti13runtime_error);
  }
  return &__ti15underflow_error;
}


// __tf16invalid_argument  @ 0809a8d0
undefined4 * __tf16invalid_argument(void)

{
  if (__ti16invalid_argument == 0) {
    __tf11logic_error();
    __rtti_si(&__ti16invalid_argument,"16invalid_argument",&__ti11logic_error);
  }
  return &__ti16invalid_argument;
}


// __tf22_IO_istream_withassign  @ 0809cc30
undefined4 * __tf22_IO_istream_withassign(void)

{
  if (__ti22_IO_istream_withassign == 0) {
    __tf7istream();
    __rtti_class(&__ti22_IO_istream_withassign,"22_IO_istream_withassign",&PTR___ti7istream_080a9628
                 ,1);
  }
  return &__ti22_IO_istream_withassign;
}


// __tf22_IO_ostream_withassign  @ 0809cb90
undefined4 * __tf22_IO_ostream_withassign(void)

{
  if (__ti22_IO_ostream_withassign == 0) {
    __tf7ostream();
    __rtti_class(&__ti22_IO_ostream_withassign,"22_IO_ostream_withassign",&PTR___ti7ostream_080a9604
                 ,1);
  }
  return &__ti22_IO_ostream_withassign;
}


// __tf7istream  @ 0809d28c
undefined4 * __tf7istream(void)

{
  if (__ti7istream == 0) {
    __tf3ios();
    __rtti_class(&__ti7istream,"7istream",&PTR___ti3ios_080a9668,1);
  }
  return &__ti7istream;
}


// __tf7ostream  @ 0809d57c
undefined4 * __tf7ostream(void)

{
  if (__ti7ostream == 0) {
    __tf3ios();
    __rtti_class(&__ti7ostream,"7ostream",&PTR___ti3ios_080a9668,1);
  }
  return &__ti7ostream;
}


// __tf8iostream  @ 0809cd38
undefined4 * __tf8iostream(void)

{
  if (__ti8iostream == 0) {
    __tf7ostream();
    __tf7istream();
    __rtti_class(&__ti8iostream,"8iostream",&PTR___ti7istream_080a964c,2);
  }
  return &__ti8iostream;
}


// __thunk_12__._8iostream  @ 0809e648
void __thunk_12____8iostream(void)

{
  ___8iostream();
  return;
}


// __thunk_4__._22_IO_ostream_withassign  @ 0809e630
void __thunk_4____22_IO_ostream_withassign(void)

{
  ___22_IO_ostream_withassign();
  return;
}


// __thunk_4__._7ostream  @ 0809e660
void __thunk_4____7ostream(void)

{
  ___7ostream();
  return;
}


// __thunk_8__._22_IO_istream_withassign  @ 0809e63c
void __thunk_8____22_IO_istream_withassign(void)

{
  ___22_IO_istream_withassign();
  return;
}


// __thunk_8__._7istream  @ 0809e654
void __thunk_8____7istream(void)

{
  ___7istream();
  return;
}


// __vc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 08098f00
int __vc__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
              (int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == *(int *)(*param_1 + -0x10)) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)*(char *)(param_2 + *param_1);
  }
  return iVar1;
}


// __vc__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi  @ 08099330
int __vc__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3RepUi
              (int param_1,int param_2)

{
  return param_1 + 0x10 + param_2;
}


// __vc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui  @ 080991dc
int __vc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Ui
              (int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (1 < *(uint *)(iVar1 + -8)) {
    alloc__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0Uib
              (param_1,*(undefined4 *)(iVar1 + -0x10),1);
    iVar1 = *param_1;
  }
  *(undefined1 *)(iVar1 + -4) = 1;
  return param_2 + *param_1;
}


// _find__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCccUiUi  @ 08098d78
uint _find__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCccUiUi
               (int param_1,char param_2,uint param_3,uint param_4)

{
  while( true ) {
    if (param_4 <= param_3) {
      return 0xffffffff;
    }
    if (*(char *)(param_3 + param_1) == param_2) break;
    param_3 = param_3 + 1;
  }
  return param_3;
}


// _fini  @ 0809e670
void _fini(void)

{
  gcc2_compiled_();
  return;
}


// _init  @ 0804bbb0
int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  __gmon_start__();
  frame_dummy();
  iVar1 = gcc2_compiled_();
  return iVar1;
}


// _sb_readline__FP9streambufRlc  @ 0809d7fc
int _sb_readline__FP9streambufRlc(_IO_FILE *param_1,int *param_2,char param_3)

{
  int iVar1;
  size_t __n;
  int iVar2;
  int iVar3;
  int local_208;
  undefined1 local_204 [512];
  
  iVar2 = (int)param_3;
  __n = _IO_getline_info(param_1,local_204,0x200,iVar2,0xffffffff,&local_208);
  if (local_208 != -1) {
    local_208 = _IO_getc(param_1);
  }
  iVar1 = *param_2;
  iVar3 = iVar1 + __n;
  *param_2 = iVar3;
  if ((local_208 == -1) || (local_208 == iVar2)) {
    iVar2 = __builtin_vec_new(*param_2 + 1);
    if (iVar2 != 0) {
      *(undefined1 *)(*param_2 + iVar2) = 0;
      memcpy((void *)((iVar2 + *param_2) - __n),local_204,__n);
    }
  }
  else {
    *param_2 = iVar3 + 1;
    iVar2 = _sb_readline__FP9streambufRlc(param_1,param_2,iVar2);
    if (iVar2 != 0) {
      memcpy((void *)(iVar1 + iVar2),local_204,__n);
      *(undefined1 *)(iVar3 + iVar2) = (undefined1)local_208;
    }
  }
  return iVar2;
}


// _skip_ws__7istream  @ 0809c804
undefined4 _skip_ws__7istream(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = skip_ws__FP9streambuf(*(undefined4 *)*param_1);
  if (iVar1 == -1) {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 3;
    uVar2 = 0;
  }
  else {
    sputbackc__9streambufc(*(undefined4 *)*param_1,(int)(char)iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


// _start  @ 0804c640
void processEntry _start(__func *param_1,EVP_PKEY_CTX *param_2)

{
  int __status;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  if (param_1 != (__func *)0x0) {
    atexit(param_1);
  }
  __libc_init_first();
  puVar1 = &stack0x00000004;
  environ = &stack0x00000008 + (int)param_2 * 4;
  puVar2 = environ;
  puVar3 = environ;
  _init(param_2);
  atexit(_fini);
  __status = main(param_2,puVar1,puVar2,puVar3);
                    /* WARNING: Subroutine does not return */
  exit(__status);
}


