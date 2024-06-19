# Original Repo: [SamRB-dev/Kry0Steg](https://github.com/SamRB-dev/Kry0Steg)
![License](https://img.shields.io/badge/License-BSD%203%20Clause-blue.svg)

**Kry0Steg** is a simple cryptographic toolkit providing classical ciphers, hashing, encoding and steganography tools with graphical user interface written with C++ and GTK C++ binding called GTKmm. Our project was heavily inspired by the tools like [Cryptii](https://cryptii.com/), [CyberChef](https://gchq.github.io/CyberChef/) and aims to provide the tools natively without requiring internet connection.

## Current Features
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

## Dependencies
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

## Linux compilation with gcc
### With Gtkmm 
```bash
g++ Kry0Steg-GUI.cpp -o Kry0Steg `pkg-config --cflags --libs gtkmm-4.0` -l ssl -l crypto
```
or execute make file

```bash
make
```

## Cross Compilation - mingw-w64 - TBA
### MSYS2
- pacman -Syuu
- pacman -S mingw-w64-x86_64-toolchain base-devel
- pacman -S mingw-w64-x86_64-{gtkmm-4.0,openssl}

## Project Demo
[Demo](https://youtu.be/slqB0bqXF3I?si=Yw37n8IDRk61e0xV)

## Reference
- [Gtkmm Examples](https://github.com/gammasoft71/Examples_Gtkmm)
- [Programming with gtkmm 4](https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/index.html)