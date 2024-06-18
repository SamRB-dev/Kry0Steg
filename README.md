# Original Repo: [SamRB-dev/Kry0Steg](https://github.com/SamRB-dev/Kry0Steg)
# Current Features
 - General Symmetric Ciphers
    - Ceasar cipher
    - Rot13 - done
    - Atbash Cipher 
    - Affine - Done

- Encoders, Type: Header
   - text => hex
- Hashing
   - MD5
   - SHA1
   - SHA256

- Steganography
   - Null cipher (Text steg)

# Dependencies
### Dev tools
#### Manjaro/Arch Installation
```bash 
sudo pacman -Syu base-devel
```
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
```bash
g++ Kry0Steg-GUI.cpp -o Kry0Steg `pkg-config --cflags --libs gtkmm-4.0` -l ssl -l crypto
```
or execute make file

```bash
make
```

# Cross Compilation - mingw-w64 - TBA
## MSYS2
- pacman -Syuu
- pacman -S mingw-w64-x86_64-toolchain base-devel
- pacman -S mingw-w64-x86_64-{gtkmm-4.0,openssl}

# Project Demo
<iframe width="560" height="315" src="https://www.youtube.com/embed/slqB0bqXF3I?si=UYPIqcPH-Ms8qbxH" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# Reference
- [Gtkmm Examples](https://github.com/gammasoft71/Examples_Gtkmm)
- [Programming with gtkmm 4](https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/index.html)