/*******************************************************************
* @Copyright          : Copyright 2024, SamRB-dev
* @File Name          : ApplicationHeader.h
* @Description        : An important header that handles events for
                        application class.
* @Version            : 1.0
* @Github             : 
* @License            : CC-BY-NC-SA     
* @Reference          : https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/sec-helloworld.html
/******************************************************************/ 

/* Custom Headers */
#include "ApplicationHeader.h"

/* Signal Hanlders */ 
// Page Switchers
void MyWindow::caesar_page_click(){
    pageStack.set_visible_child("page1");
}

void MyWindow::rot13_page_click(){
    pageStack.set_visible_child("page2");
}

void MyWindow::atbash_page_click(){
    pageStack.set_visible_child("page3");
}

void MyWindow::affine_page_click(){
    pageStack.set_visible_child("page4");
}

void MyWindow::md5_page_click(){
    pageStack.set_visible_child("page5");
}

void MyWindow::sha1_page_click(){
    pageStack.set_visible_child("page6");
}

void MyWindow::sha256_page_click(){
    pageStack.set_visible_child("page7");
}

void MyWindow::hex_page_click(){
    pageStack.set_visible_child("page8");
}

void MyWindow::stegoNull_page_click(){
    pageStack.set_visible_child("page9");
}

void MyWindow::MenuButton_click(){
    pageStack.set_visible_child("menu");
}

// Operations
void MyWindow::caesar_encrypt_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    int cipherKey = CaesarCipherKeyInput.get_value_as_int(); // For SpinButton 
    std::string cipheredText = GeneralCiphers::caesarCipher(inputRawStr, cipherKey, 'e');
    outputBuffer->set_text(cipheredText);
}

void MyWindow::caesar_decrypt_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    int cipherKey = CaesarCipherKeyInput.get_value_as_int(); // Ref: Line 224
    std::string plainText = GeneralCiphers::caesarCipher(inputRawStr, cipherKey, 'd');
    outputBuffer->set_text(plainText);
}

void MyWindow::rot13_encrypt_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    std::string cipherText = GeneralCiphers::caesarCipher(inputRawStr, 13, 'e');
    outputBuffer->set_text(cipherText);
}

void MyWindow::rot13_decrypt_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    std::string plainText = GeneralCiphers::caesarCipher(inputRawStr, 13, 'd');
    outputBuffer->set_text(plainText);
}

void MyWindow::atbash_magic_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    std::string magicText = GeneralCiphers::atbashCipher(inputRawStr);
    outputBuffer->set_text(magicText);
}

void MyWindow::affine_encrypt_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    int cipherKeyA = AffineCipherKeyInput_1.get_value_as_int();
    int cipherKeyB = AffineCipherKeyInput_2.get_value_as_int();
    std::string cipherText = GeneralCiphers::AffineCipherEncrypt(inputRawStr, cipherKeyA, cipherKeyB);
    outputBuffer->set_text(cipherText);
}

void MyWindow::affine_decrypt_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    int cipherKeyA = AffineCipherKeyInput_1.get_value_as_int();
    int cipherKeyB = AffineCipherKeyInput_2.get_value_as_int();
    std::string plainText = GeneralCiphers::AffineCipherDecrypt(inputRawStr, cipherKeyA, cipherKeyB);
    outputBuffer->set_text(plainText);
}

void MyWindow::md5_hash_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    std::string hashText = HashFunctions::hash_MD5(inputRawStr);
    outputBuffer->set_text(hashText);
}

void MyWindow::sha1_hash_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    std::string hashText = HashFunctions::hash_SHA1(inputRawStr);
    outputBuffer->set_text(hashText);
}

void MyWindow::sha256_hash_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    std::string hashText = HashFunctions::hash_SHA256(inputRawStr);
    outputBuffer->set_text(hashText);
}

void MyWindow::hex_encode_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    std::string encodedText = Encoders::text2hex(inputRawStr);
    outputBuffer->set_text(encodedText);
}

void MyWindow::null_decipher_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    std::string decipheredText = SteganoFunctions::stego_nullCipher_firstOrder(inputRawStr);
    outputBuffer->set_text(decipheredText);
}

void MyWindow::exit_event_click(){
    hide();
}