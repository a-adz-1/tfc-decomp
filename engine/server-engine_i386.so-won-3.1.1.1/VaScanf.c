// VaScanf__10CUtlBufferPCcPv  @ 000d8108
int VaScanf__10CUtlBufferPCcPv(int param_1,char *param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  long *plVar2;
  ulong *puVar3;
  float *pfVar4;
  char cVar5;
  int iVar6;
  undefined1 *puVar7;
  long lVar8;
  char *pcVar9;
  ulong uVar10;
  byte *pbVar11;
  uint uVar12;
  double dVar13;
  char **ppcVar14;
  char *local_10;
  char local_9;
  int local_8;
  
  if ((*(char *)(param_1 + 0x14) == '\0') && (cVar5 = IsText__C10CUtlBuffer(param_1), cVar5 != '\0')
     ) {
    local_8 = 0;
    while( true ) {
      local_9 = *param_2;
      pcVar9 = param_2 + 1;
      if (local_9 == '\0') break;
      iVar6 = Size__C10CUtlBuffer(param_1);
      if (iVar6 <= *(int *)(param_1 + 0xc)) {
        *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 2;
        return local_8;
      }
      if (local_9 == ' ') {
        EatWhiteSpace__10CUtlBuffer(param_1);
        param_2 = pcVar9;
      }
      else if (local_9 == '%') {
        param_2 = param_2 + 2;
        if (*pcVar9 == '\0') {
          return local_8;
        }
        switch(*pcVar9) {
        case 'c':
          puVar1 = (undefined1 *)*param_3;
          puVar7 = (undefined1 *)__vc__t10CUtlMemory1ZUci(param_1,*(undefined4 *)(param_1 + 0xc));
          *puVar1 = *puVar7;
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          break;
        case 'd':
        case 'i':
          plVar2 = (long *)*param_3;
          iVar6 = 10;
          ppcVar14 = &local_10;
          pcVar9 = (char *)PeekGet__C10CUtlBufferi(param_1,0);
          lVar8 = strtol(pcVar9,ppcVar14,iVar6);
          *plVar2 = lVar8;
          pcVar9 = (char *)PeekGet__C10CUtlBufferi(param_1,0);
          if (local_10 == pcVar9) {
            return local_8;
          }
          iVar6 = Base__10CUtlBuffer(param_1);
          *(int *)(param_1 + 0xc) = (int)local_10 - iVar6;
          break;
        default:
          return local_8;
        case 'f':
          pfVar4 = (float *)*param_3;
          ppcVar14 = &local_10;
          pcVar9 = (char *)PeekGet__C10CUtlBufferi(param_1,0);
          dVar13 = strtod(pcVar9,ppcVar14);
          *pfVar4 = (float)dVar13;
          pcVar9 = (char *)PeekGet__C10CUtlBufferi(param_1,0);
          if (local_10 == pcVar9) {
            return local_8;
          }
          iVar6 = Base__10CUtlBuffer(param_1);
          *(int *)(param_1 + 0xc) = (int)local_10 - iVar6;
          break;
        case 's':
          GetString__10CUtlBufferPc(param_1,*param_3);
          break;
        case 'u':
          puVar3 = (ulong *)*param_3;
          iVar6 = 10;
          ppcVar14 = &local_10;
          pcVar9 = (char *)PeekGet__C10CUtlBufferi(param_1,0);
          uVar10 = strtoul(pcVar9,ppcVar14,iVar6);
          *puVar3 = uVar10;
          pcVar9 = (char *)PeekGet__C10CUtlBufferi(param_1,0);
          if (local_10 == pcVar9) {
            return local_8;
          }
          iVar6 = Base__10CUtlBuffer(param_1);
          *(int *)(param_1 + 0xc) = (int)local_10 - iVar6;
        }
        param_3 = param_3 + 1;
        local_8 = local_8 + 1;
      }
      else {
        uVar12 = (uint)local_9;
        pbVar11 = (byte *)__vc__t10CUtlMemory1ZUci(param_1,*(undefined4 *)(param_1 + 0xc));
        if (uVar12 != *pbVar11) {
          return local_8;
        }
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        param_2 = pcVar9;
      }
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


