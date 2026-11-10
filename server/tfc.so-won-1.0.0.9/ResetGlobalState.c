// ResetGlobalState__Fv  @ 0011d880
void ResetGlobalState__Fv(void)

{
  ClearStates__12CGlobalState(&gGlobalState);
  gInitHUD = 1;
  return;
}


