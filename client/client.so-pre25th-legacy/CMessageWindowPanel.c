// CMessageWindowPanel_Create  @ 000b17a0
CMenuPanel *
CMessageWindowPanel_Create
          (char *szMOTD,char *szTitle,int iShadeFullscreen,int iRemoveMe,int x,int y,int wide,
          int tall)

{
  CMessageWindowPanel *this;
  
  this = operator_new(0xd8);
  CMessageWindowPanel::CMessageWindowPanel
            (this,szMOTD,szTitle,iShadeFullscreen,iRemoveMe,x,y,wide,tall);
  return &this->super_CMenuPanel;
}


