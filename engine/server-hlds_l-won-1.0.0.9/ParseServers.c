// ParseServers__FPcPi  @ 08089850
undefined4 ParseServers__FPcPi(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint16_t uVar3;
  FILE *__stream;
  size_t __size;
  void *__ptr;
  undefined4 uVar4;
  void *pvVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 local_164;
  int local_15c;
  undefined1 local_154 [2];
  uint16_t local_152;
  in_addr local_150;
  char local_144 [256];
  char local_44 [64];
  
  local_15c = 0;
  iVar2 = *param_2;
  *param_2 = 0;
  __stream = fopen("valve\\woncomm.lst","rb");
  if (__stream == (FILE *)0x0) {
    local_164 = 0;
  }
  else {
    fseek(__stream,0,2);
    __size = ftell(__stream);
    fseek(__stream,0,0);
    if ((__size - 1 < 0x4000) && (__ptr = malloc(__size + 1), __ptr != (void *)0x0)) {
      fread(__ptr,__size,1,__stream);
      fclose(__stream);
      *(undefined1 *)(__size + (int)__ptr) = 0;
      local_164 = 0;
      pvVar5 = __ptr;
LAB_08089924:
      uVar4 = COM_Parse(pvVar5);
      iVar7 = -1;
      pcVar6 = &com_token;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      if (iVar7 != -2) {
        iVar7 = Q_strcasecmp(&com_token,&DAT_080a72d6);
        pvVar5 = (void *)COM_Parse(uVar4);
        iVar8 = -1;
        pcVar6 = &com_token;
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        if ((iVar8 != -2) && (iVar8 = Q_strcasecmp(&com_token,&DAT_080a72db), iVar8 == 0)) {
          do {
            pvVar5 = (void *)COM_Parse(pvVar5);
            iVar8 = -1;
            pcVar6 = &com_token;
            do {
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            if ((iVar8 == -2) || (iVar8 = Q_strcasecmp(&com_token,&DAT_080a72dd), iVar8 == 0))
            goto LAB_08089924;
            sprintf(local_144,"%s",&com_token);
            pvVar5 = (void *)COM_Parse(pvVar5);
            iVar8 = -1;
            pcVar6 = &com_token;
            do {
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            if ((iVar8 == -2) || (iVar8 = Q_strcasecmp(&com_token,&DAT_080a72bf), iVar8 != 0))
            goto LAB_08089924;
            pvVar5 = (void *)COM_Parse(pvVar5);
            iVar8 = -1;
            pcVar6 = &com_token;
            do {
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            if (iVar8 == -2) goto LAB_08089924;
            uVar4 = __strtol_internal(&com_token,0,10,0);
            sprintf(local_44,"%s:%i",local_144,uVar4);
            memset(local_154,0,0x10);
            iVar8 = NET_StringToSockaddrX__FPcP8sockaddr(local_44,local_154);
            if (iVar8 != 0) {
              uVar3 = ntohs(local_152);
              uVar9 = (uint)uVar3;
              if (uVar9 == 0) {
                uVar9 = 0x1b59;
              }
              pcVar6 = inet_ntoa(local_150);
              sprintf(local_44,"%s:%i",pcVar6,uVar9);
            }
            if (iVar7 == 0) {
              strncpy((char *)(param_1 + local_15c * 0x104),local_44,0x104);
              local_15c = local_15c + 1;
              local_164 = 1;
            }
            if (iVar2 <= local_15c) goto LAB_08089924;
          } while( true );
        }
      }
      *param_2 = local_15c;
      free(__ptr);
    }
    else {
      fclose(__stream);
      local_164 = 0;
    }
  }
  return local_164;
}


