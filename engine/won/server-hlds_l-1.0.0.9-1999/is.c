// is_del__t18string_char_traits1Zcc  @ 08099f18
byte is_del__t18string_char_traits1Zcc(char param_1)

{
  return (byte)((ushort)*(undefined2 *)(__ctype_b + param_1 * 2) >> 0xd) & 1;
}


