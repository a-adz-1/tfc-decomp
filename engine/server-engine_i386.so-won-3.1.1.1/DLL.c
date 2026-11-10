// DLL_SetModKey  @ 00094c64
void DLL_SetModKey(undefined4 *param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = Q_stricmp(param_2,"url_info");
  if (iVar1 == 0) {
    *param_1 = 1;
    Q_strncpy(param_1 + 1,param_3,0xff);
    *(undefined1 *)((int)param_1 + 0x103) = 0;
  }
  else {
    iVar1 = Q_stricmp(param_2,"url_dl");
    if (iVar1 == 0) {
      *param_1 = 1;
      Q_strncpy(param_1 + 0x41,param_3,0xff);
      *(undefined1 *)((int)param_1 + 0x203) = 0;
    }
    else {
      iVar1 = Q_stricmp(param_2,"version");
      if (iVar1 == 0) {
        *param_1 = 1;
        iVar1 = atoi(param_3);
        param_1[0x89] = iVar1;
      }
      else {
        iVar1 = Q_stricmp(param_2,&DAT_000e70ff);
        if (iVar1 == 0) {
          *param_1 = 1;
          iVar1 = atoi(param_3);
          param_1[0x8a] = iVar1;
        }
        else {
          iVar1 = Q_stricmp(param_2,"svonly");
          if (iVar1 == 0) {
            *param_1 = 1;
            iVar1 = atoi(param_3);
            param_1[0x8b] = (uint)(iVar1 != 0);
          }
          else {
            iVar1 = Q_stricmp(param_2,"cldll");
            if (iVar1 == 0) {
              *param_1 = 1;
              iVar1 = atoi(param_3);
              param_1[0x8c] = (uint)(iVar1 != 0);
            }
            else {
              iVar1 = Q_stricmp(param_2,"secure");
              if (iVar1 == 0) {
                *param_1 = 1;
                iVar1 = atoi(param_3);
                param_1[0x8d] = (uint)(iVar1 != 0);
              }
              else {
                iVar1 = Q_stricmp(param_2,"hlversion");
                if (iVar1 == 0) {
                  Q_strncpy(param_1 + 0x81,param_3,0x1f);
                  *(undefined1 *)((int)param_1 + 0x223) = 0;
                }
                else {
                  iVar1 = Q_stricmp(param_2,"fallback_dir");
                  if (iVar1 == 0) {
                    COM_AddDefaultDir(param_3);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


