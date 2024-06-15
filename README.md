# Original Repo: [SamRB-dev/Kry0Steg]()
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
### gtkmm-4.0
#### Manjaro/Arch Installation
```bash
sudo pacman -Syu gtkmm-4.0
```
### OpenSSL
#### Manjaro/Arch Installation
```bash
sudo pacman -Syu openssl
```

# Linux compilation with gcc
## With Gtkmm 
```
g++ Kry0Steg-GUI.cpp -o Kry0Steg `pkg-config --cflags --libs gtkmm-4.0`
```

# Cross Compilation - mingw-w64 
## MSYS2
- pacman -Syuu
- pacman -S mingw-w64-x86_64-toolchain base-devel
- pacman -S mingw-w64-x86_64-{gtkmm-4.0,openssl}

# Reference
- [Gtkmm Examples](https://github.com/gammasoft71/Examples_Gtkmm)
- [Programming with gtkmm 4](https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/index.html)