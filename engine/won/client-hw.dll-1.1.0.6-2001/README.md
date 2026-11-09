# hw.dll, WON 1.1.0.6 (client engine, 2001)

The Windows client engine from Half-Life 1.1.0.6 (2001). It cuts each frame's command time to whole milliseconds and throws the fraction away, which is likely where 'fps_max 100 is best' comes from (docs/won-comparison.md).

- **Binary:** `hw.dll`
- **Release:** Half-Life 1.1.0.6 (Windows), WON era
- **MD5 of the original:** `00333d2df780d77a2fcc864428751484`
- **Contents:** Ghidra decompile, one file per name prefix or C++ class. Windows build without symbols, so most functions are named by address.

The original binary is not included.
