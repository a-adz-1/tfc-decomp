// type_info::`scalar_deleting_destructor'  @ 100a6db0
/* Library Function - Single Match
    public: virtual void * __thiscall type_info::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 1998 Release */

void * __thiscall type_info::_scalar_deleting_destructor_(type_info *this,uint param_1)

{
  ~type_info(this);
  if ((param_1 & 1) != 0) {
    FUN_100a4f30(this);
  }
  return this;
}


// type_info::~type_info  @ 100a6d80
/* Library Function - Single Match
    public: virtual __thiscall type_info::~type_info(void)
   
   Library: Visual Studio 1998 Release */

void __thiscall type_info::~type_info(type_info *this)

{
  *(undefined ***)this = &PTR__scalar_deleting_destructor__100ba414;
  __lock(0x1b);
  if (*(void **)(this + 4) != (void *)0x0) {
    _free(*(void **)(this + 4));
  }
  FUN_100a7ed0(0x1b);
  return;
}


