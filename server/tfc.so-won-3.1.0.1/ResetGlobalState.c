// ResetGlobalState__Fv  @ 0011330c
void ResetGlobalState__Fv(void)

{
  ClearStates__12CGlobalState(&gGlobalState);
  gInitHUD = 1;
  return;
}


