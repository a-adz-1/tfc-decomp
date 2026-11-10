// VoiceServerDebug__FPCce  @ 0013aac4
void VoiceServerDebug__FPCce(char *param_1)

{
  char local_1004 [4096];
  
  if ((byte)((float)voice_serverdebug._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)voice_serverdebug._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)voice_serverdebug._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)
  {
    vsnprintf(local_1004,0x1000,param_1,&stack0x00000008);
    (*DAT_0019f794)(1,&DAT_0015bfbb,local_1004);
  }
  return;
}


