// grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep  @ 0004d314
int grab__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
              (int param_1)

{
  if (*(char *)(param_1 + 0xc) == '\0') {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    param_1 = param_1 + 0x10;
  }
  else {
    param_1 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                        (param_1);
  }
  return param_1;
}


