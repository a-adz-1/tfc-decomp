// UpdateStatus__Fv  @ 0808a0a0
void UpdateStatus__Fv(void)

{
  longdouble lVar1;
  float local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined1 local_124 [32];
  char local_104 [256];
  
  lVar1 = (longdouble)Sys_FloatTime();
  Host_GetHostInfo();
  fpsTotal_480 = fpsTotal_480 + local_134;
  count_479 = count_479 + 1;
  if (0.5 <= (double)lVar1 - tLast_478) {
    if (count_479 < 1) {
      local_134 = 0.0;
    }
    else {
      local_134 = fpsTotal_480 / (float)count_479;
    }
    tLast_478 = (double)lVar1;
    sprintf(local_104,"%.1f fps %2i(%2i spec)/%2i on %16s",(double)local_134,local_130,local_12c,
            local_128,local_124);
    fpsTotal_480 = 0.0;
    count_479 = 0;
    WriteStatusText__FPCc(local_104);
  }
  return;
}


