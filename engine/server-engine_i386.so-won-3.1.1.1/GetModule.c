// GetModule__13SystemWrapperPcN21  @ 00098fa4
int GetModule__13SystemWrapperPcN21
              (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FindModule__13SystemWrapperPcT1(param_1,param_2,param_4);
  if (iVar1 == 0) {
    iVar2 = GetLibrary__13SystemWrapperPc(param_1,param_3);
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (**(code **)(iVar2 + 0x1004))(param_2,0);
      if (iVar1 == 0) {
        (**(code **)(*param_1 + 0x4c))
                  (param_1,"ERROR! System::GetModule: interface \"%s\" not found in library %s.\n",
                   param_2,iVar2);
        iVar1 = 0;
      }
      else {
        (**(code **)(*param_1 + 0x8c))(param_1,iVar1,param_4);
      }
    }
  }
  return iVar1;
}


