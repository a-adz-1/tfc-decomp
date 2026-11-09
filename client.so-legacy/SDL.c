// SDL_GetCursorPos  @ 00095920
void SDL_GetCursorPos(POINT *p)

{
  (*gEngfuncs.GetMousePosition)(&p->x,&p->y);
  return;
}


// SDL_SetCursorPos  @ 00095940
void SDL_SetCursorPos(int x,int y)

{
  return;
}


