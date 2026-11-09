// vgui2::VGuiControls_Init  @ 00233d40
bool vgui2::VGuiControls_Init(char *moduleName,CreateInterfaceFn *factoryList,int numFactories)

{
  IVGui *pIVar1;
  IPanel *pIVar2;
  IBaseInterface *pIVar3;
  ISchemeManager *pIVar4;
  ISystem *pIVar5;
  IInput *pIVar6;
  ILocalize *pIVar7;
  IFileSystem *pIVar8;
  IKeyValues *pIVar9;
  int iVar10;
  bool bVar11;
  
  strncpy(g_szControlsModuleName,moduleName,0x100);
  g_szControlsModuleName[0xff] = '\0';
  setlocale(0,"");
  setlocale(2,"");
  setlocale(3,"");
  setlocale(4,"");
                    /* Unresolved local var: void * retval@[???]
                       Unresolved local var: int i@[???] */
  if (numFactories < 1) {
    g_pVGuiInterface = (IVGui *)0x0;
    g_pLocalizeInterface = (ILocalize *)0x0;
    g_pFileSystemInterface = (IFileSystem *)0x0;
    g_pKeyValuesInterface = (IKeyValues *)0x0;
    bVar11 = false;
    g_pPanelInterface = (IPanel *)0x0;
    g_pSurfaceInterface = (ISurface *)0x0;
    g_pSchemeInterface = (ISchemeManager *)0x0;
    g_pSystemInterface = (ISystem *)0x0;
    g_pInputInterface = (IInput *)0x0;
  }
  else {
    iVar10 = 0;
    do {
                    /* Unresolved local var: CreateInterfaceFn factory@[???] */
      if ((factoryList[iVar10] != (CreateInterfaceFn)0x0) &&
         (pIVar1 = (IVGui *)(*factoryList[iVar10])("VGUI_ivgui006",(int *)0x0),
         pIVar1 != (IVGui *)0x0)) goto LAB_00233df1;
      iVar10 = iVar10 + 1;
    } while (iVar10 != numFactories);
    pIVar1 = (IVGui *)0x0;
LAB_00233df1:
    iVar10 = 0;
    g_pVGuiInterface = pIVar1;
    do {
                    /* Unresolved local var: void * retval@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CreateInterfaceFn factory@[???] */
      if ((factoryList[iVar10] != (CreateInterfaceFn)0x0) &&
         (pIVar2 = (IPanel *)(*factoryList[iVar10])("VGUI_Panel007",(int *)0x0),
         pIVar2 != (IPanel *)0x0)) goto LAB_00233e21;
      iVar10 = iVar10 + 1;
    } while (iVar10 != numFactories);
    pIVar2 = (IPanel *)0x0;
LAB_00233e21:
    iVar10 = 0;
    g_pPanelInterface = pIVar2;
    do {
                    /* Unresolved local var: void * retval@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CreateInterfaceFn factory@[???] */
      if ((factoryList[iVar10] != (CreateInterfaceFn)0x0) &&
         (pIVar3 = (*factoryList[iVar10])("VGUI_Surface026",(int *)0x0),
         pIVar3 != (IBaseInterface *)0x0)) goto LAB_00233e51;
      iVar10 = iVar10 + 1;
    } while (iVar10 != numFactories);
    pIVar3 = (IBaseInterface *)0x0;
LAB_00233e51:
    iVar10 = 0;
    g_pSurfaceInterface = (ISurface *)pIVar3;
    do {
                    /* Unresolved local var: void * retval@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CreateInterfaceFn factory@[???] */
      if ((factoryList[iVar10] != (CreateInterfaceFn)0x0) &&
         (pIVar4 = (ISchemeManager *)(*factoryList[iVar10])("VGUI_Scheme009",(int *)0x0),
         pIVar4 != (ISchemeManager *)0x0)) goto LAB_00233e81;
      iVar10 = iVar10 + 1;
    } while (iVar10 != numFactories);
    pIVar4 = (ISchemeManager *)0x0;
LAB_00233e81:
    iVar10 = 0;
    g_pSchemeInterface = pIVar4;
    do {
                    /* Unresolved local var: void * retval@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CreateInterfaceFn factory@[???] */
      if ((factoryList[iVar10] != (CreateInterfaceFn)0x0) &&
         (pIVar5 = (ISystem *)(*factoryList[iVar10])("VGUI_System009",(int *)0x0),
         pIVar5 != (ISystem *)0x0)) goto LAB_00233eb1;
      iVar10 = iVar10 + 1;
    } while (iVar10 != numFactories);
    pIVar5 = (ISystem *)0x0;
LAB_00233eb1:
    iVar10 = 0;
    g_pSystemInterface = pIVar5;
    do {
                    /* Unresolved local var: void * retval@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CreateInterfaceFn factory@[???] */
      if ((factoryList[iVar10] != (CreateInterfaceFn)0x0) &&
         (pIVar6 = (IInput *)(*factoryList[iVar10])("VGUI_Input004",(int *)0x0),
         pIVar6 != (IInput *)0x0)) goto LAB_00233ee1;
      iVar10 = iVar10 + 1;
    } while (iVar10 != numFactories);
    pIVar6 = (IInput *)0x0;
LAB_00233ee1:
    iVar10 = 0;
    g_pInputInterface = pIVar6;
    do {
                    /* Unresolved local var: void * retval@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CreateInterfaceFn factory@[???] */
      if ((factoryList[iVar10] != (CreateInterfaceFn)0x0) &&
         (pIVar7 = (ILocalize *)(*factoryList[iVar10])("VGUI_Localize003",(int *)0x0),
         pIVar7 != (ILocalize *)0x0)) goto LAB_00233f11;
      iVar10 = iVar10 + 1;
    } while (iVar10 != numFactories);
    pIVar7 = (ILocalize *)0x0;
LAB_00233f11:
    iVar10 = 0;
    g_pLocalizeInterface = pIVar7;
    do {
                    /* Unresolved local var: void * retval@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CreateInterfaceFn factory@[???] */
      if ((factoryList[iVar10] != (CreateInterfaceFn)0x0) &&
         (pIVar8 = (IFileSystem *)(*factoryList[iVar10])("VFileSystem009",(int *)0x0),
         pIVar8 != (IFileSystem *)0x0)) goto LAB_00233f41;
      iVar10 = iVar10 + 1;
    } while (iVar10 != numFactories);
    pIVar8 = (IFileSystem *)0x0;
LAB_00233f41:
    iVar10 = 0;
    g_pFileSystemInterface = pIVar8;
    do {
                    /* Unresolved local var: void * retval@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CreateInterfaceFn factory@[???] */
      if ((factoryList[iVar10] != (CreateInterfaceFn)0x0) &&
         (pIVar9 = (IKeyValues *)(*factoryList[iVar10])("KeyValues003",(int *)0x0),
         pIVar9 != (IKeyValues *)0x0)) goto LAB_00233f7b;
      iVar10 = iVar10 + 1;
    } while (iVar10 != numFactories);
    pIVar9 = (IKeyValues *)0x0;
LAB_00233f7b:
    bVar11 = false;
    g_pKeyValuesInterface = pIVar9;
    if (g_pVGuiInterface != (IVGui *)0x0) {
      (**(code **)(*(int *)g_pVGuiInterface + 8))(g_pVGuiInterface,factoryList,numFactories);
      if (g_pKeyValuesInterface != (IKeyValues *)0x0) {
        (**(code **)(*(int *)g_pKeyValuesInterface + 8))(g_pKeyValuesInterface,0x18);
      }
      bVar11 = false;
      if (((((g_pSchemeInterface != (ISchemeManager *)0x0) &&
            (g_pSurfaceInterface != (ISurface *)0x0)) && (g_pSystemInterface != (ISystem *)0x0)) &&
          ((g_pInputInterface != (IInput *)0x0 && (g_pVGuiInterface != (IVGui *)0x0)))) &&
         ((g_pFileSystemInterface != (IFileSystem *)0x0 &&
          ((g_pLocalizeInterface != (ILocalize *)0x0 && (g_pKeyValuesInterface != (IKeyValues *)0x0)
           ))))) {
        bVar11 = g_pPanelInterface != (IPanel *)0x0;
      }
    }
  }
  return bVar11;
}


// vgui2::VGuiControls_Shutdown  @ 00234080
void vgui2::VGuiControls_Shutdown(void)

{
  return;
}


