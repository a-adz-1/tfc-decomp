// DLL_SetModKey  @ 0007a3b0
void DLL_SetModKey(modinfo_t *pinfo,char *pkey,char *pvalue)

{
  int iVar1;
  long lVar2;
  
  iVar1 = Q_stricmp(pkey,"url_info");
  if (iVar1 == 0) {
    pinfo->bIsMod = true;
    Q_strncpy(pinfo->szInfo,pvalue,0xff);
    pinfo->szInfo[0xff] = '\0';
    return;
  }
  iVar1 = Q_stricmp(pkey,"url_dl");
  if (iVar1 == 0) {
    pinfo->bIsMod = true;
    Q_strncpy(pinfo->szDL,pvalue,0xff);
    pinfo->szDL[0xff] = '\0';
  }
  else {
    iVar1 = Q_stricmp(pkey,"version");
    if (iVar1 == 0) {
      pinfo->bIsMod = true;
      lVar2 = strtol(pvalue,(char **)0x0,10);
      pinfo->version = lVar2;
      return;
    }
    iVar1 = Q_stricmp(pkey,"size");
    if (iVar1 == 0) {
      pinfo->bIsMod = true;
      lVar2 = strtol(pvalue,(char **)0x0,10);
      pinfo->size = lVar2;
    }
    else {
      iVar1 = Q_stricmp(pkey,"svonly");
      if (iVar1 == 0) {
        pinfo->bIsMod = true;
        lVar2 = strtol(pvalue,(char **)0x0,10);
        pinfo->svonly = (uint)(lVar2 != 0);
      }
      else {
        iVar1 = Q_stricmp(pkey,"cldll");
        if (iVar1 == 0) {
          pinfo->bIsMod = true;
          lVar2 = strtol(pvalue,(char **)0x0,10);
          pinfo->cldll = (uint)(lVar2 != 0);
        }
        else {
          iVar1 = Q_stricmp(pkey,"secure");
          if (iVar1 == 0) {
            pinfo->bIsMod = true;
            lVar2 = strtol(pvalue,(char **)0x0,10);
            pinfo->secure = (uint)(lVar2 != 0);
          }
          else {
            iVar1 = Q_stricmp(pkey,"hlversion");
            if (iVar1 == 0) {
              Q_strncpy(pinfo->szHLVersion,pvalue,0x1f);
              pinfo->szHLVersion[0x1f] = '\0';
            }
            else {
              iVar1 = Q_stricmp(pkey,"edicts");
              if (iVar1 == 0) {
                lVar2 = strtol(pvalue,(char **)0x0,10);
                if (lVar2 < 0x4b0) {
                  lVar2 = 0x4b0;
                }
                pinfo->num_edicts = lVar2;
              }
              else {
                iVar1 = Q_stricmp(pkey,"crcclientdll");
                if (iVar1 == 0) {
                  pinfo->bIsMod = true;
                  lVar2 = strtol(pvalue,(char **)0x0,10);
                  pinfo->clientcrccheck = (uint)(lVar2 != 0);
                }
                else {
                  iVar1 = Q_stricmp(pkey,"type");
                  if (iVar1 == 0) {
                    iVar1 = strcasecmp(pvalue,"singleplayer_only");
                    if (iVar1 == 0) {
                      pinfo->type = SINGLEPLAYER_ONLY;
                    }
                    else {
                      iVar1 = strcasecmp(pvalue,"multiplayer_only");
                      pinfo->type = -(uint)(iVar1 == 0) & MULTIPLAYER_ONLY;
                    }
                  }
                  else {
                    iVar1 = Q_stricmp(pkey,"fallback_dir");
                    if (iVar1 == 0) {
                      COM_AddDefaultDir(pvalue);
                      return;
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
  return;
}


