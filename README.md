 # ToDo
 - General Symmetric Ciphers, Type: Header
   - Substituion ciphers
    - Ceasar cipher - Complete
    - Rot13 - done
    - Atbash Cipher - done
    - Affine - Done
    - Playfair
   - Transposition ciphers
   - Stream
   - Block

- Encoders, Type: Header
   - Xor
   - text <=> bin/hex
   - Base64

- Hashing, Type: Header - Done

- Brute Force, Type: Header
- Steganography
   - Null cipher (Text steg)
   - Image Steg

# Dependencies
- gtkmm 4.0
- openssl

# Linux compilation with gcc
## With Gtkmm 
```
g++ Kry0Steg-GUI.cpp -o Kry0Steg `pkg-config --cflags --libs gtkmm-4.0`
```

# Cross Compilation - mingw-w64 TBA

# Current State