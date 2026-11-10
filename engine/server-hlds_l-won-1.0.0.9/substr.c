// substr__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi  @ 08098a48
undefined4 *
substr__Ct12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    puVar1 = &force_to_data;
  }
  else {
    puVar1 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (
                       _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                       );
  }
  *param_1 = puVar1;
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUi
            (param_1,0,0xffffffff,param_2,param_3,param_4);
  return param_1;
}


