/*******************************************************************
* @Copyright          : Copyright 2024, SamRB-dev
* @File Name          : ApplicationHeader.h
* @Description        : An important header that contains the class
                        definition for GTKmm.
* @Version            : 1.0
* @Github             : 
* @License            : BSD-3-Clause     
* @Reference          : https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/sec-helloworld.html
/******************************************************************/ 

#include <gtkmm-4.0/gtkmm/grid.h>
#include <gtkmm-4.0/gtkmm/application.h>
#include <gtkmm-4.0/gtkmm/box.h>
#include <gtkmm-4.0/gtkmm/button.h>
#include <gtkmm-4.0/gtkmm/enums.h>
#include <gtkmm-4.0/gtkmm/grid.h>
#include <gtkmm-4.0/gtkmm/label.h>
#include <gtkmm-4.0/gtkmm/window.h>
#include <gtkmm-4.0/gtkmm/stack.h>
#include <gtkmm-4.0/gtkmm/stackswitcher.h>
#include <gtkmm-4.0/gtkmm/textview.h>
#include <gtkmm-4.0/gtkmm/textbuffer.h>
#include <gtkmm-4.0/gtkmm/spinbutton.h>
#include <string>


class MyWindow: public Gtk::Window {
    public:
        // Main window
        MyWindow();

    protected:
        /*Functions for handling signals*/
        // page functions
        void caesar_page_click();
        void rot13_page_click();
        void atbash_page_click();
        void affine_page_click();
        void md5_page_click();
        void sha1_page_click();
        void sha256_page_click();
        void hex_page_click();
        void stegoNull_page_click();

        // Button operations
        void caesar_encrypt_click();
        void caesar_decrypt_click();
        void rot13_encrypt_click();
        void rot13_decrypt_click();
        void atbash_magic_click();
        void affine_encrypt_click();
        void affine_decrypt_click();
        void md5_hash_click();
        void sha1_hash_click();
        void sha256_hash_click();
        void hex_encode_click();
        void null_decipher_click();
        void exit_event_click();

        // universals
        void MenuButton_click();

        /* Widgets */
        // Box & grid
        Gtk::Box mainPageBox; // Main Frame
        Gtk::Stack pageStack;
        Gtk::StackSwitcher stackSwitch;

        Gtk::Box mainMenu; // Main Menu
        Gtk::Box childBox_1; // Section 1
        Gtk::Grid grid;
        Gtk::Box childBox_2; // Section 2
        Gtk::Grid grid_2;
        Gtk::Box childBox_3; // Section 3
        Gtk::Grid grid_3;
        Gtk::Box childBox_4; // Section 4
        Gtk::Grid grid_4;
        Gtk::Box caesarCipherPage; // Cipher Page with I/O
        Gtk::Grid caesarGrid;
        Gtk::Box rot13CipherPage; // ROT13 page
        Gtk::Grid rot13Grid;
        Gtk::Box atbashCipherPage; // Atbash page
        Gtk::Box affineCipherPage; // Affine
        Gtk::Grid affineGrid;
        Gtk::Box md5HashPage; // Hash pages
        Gtk::Box sha1HashPage;
        Gtk::Box sha256HashPage;
        Gtk::Box hexEncodingPage; // Encoder page
        Gtk::Box nullStegoPage; // Stego page

        // Labels
        Gtk::Label childBox_1_title; // menu
        Gtk::Label childBox_2_title;
        Gtk::Label childBox_3_title;
        Gtk::Label childBox_4_title;
        Gtk::Label caesarCipherPage_Input_Label; // Caesar page
        Gtk::Label caesarCipherPage_Output_Label;
        Gtk::Label caesarCipherPage_Key_Label;
        Gtk::Label rot13CipherPage_Input_Label; // rot13 page
        Gtk::Label rot13CipherPage_Output_Label;
        Gtk::Label atbashCipherPage_Input_Label; // Atbash
        Gtk::Label atbashCipherPage_Output_Label;
        Gtk::Label affineCipherPage_Input_Label; // Affine
        Gtk::Label affineCipherPage_Output_Label;
        Gtk::Label affineCipherPage_Key_1_Label;
        Gtk::Label affineCipherPage_Key_2_Label;
        Gtk::Label md5HashPage_Input_label;
        Gtk::Label md5HashPage_Output_Label;
        Gtk::Label sha1HashPage_Input_Label;
        Gtk::Label sha1HashPage_Output_Label;
        Gtk::Label sha256HashPage_Input_Label;
        Gtk::Label sha256HashPage_Output_Label;
        Gtk::Label hexEncodingPage_Input_Label;
        Gtk::Label hexEncodingPage_Output_Label;
        Gtk::Label nullStegoPage_Input_Label;
        Gtk::Label nullStegoPage_Output_Label;

        // Buttons
        Gtk::Button caesarCipher; // Section 1
        Gtk::Button rot13Cipher;
        Gtk::Button atbashCipher;
        Gtk::Button affineCipher;
        Gtk::Button md5Hash; // s2
        Gtk::Button sha1Hash;
        Gtk::Button sha256Hash;
        Gtk::Button text2Hex; // s3
        Gtk::Button nullCipher; // s4
        Gtk::Button exitButton; 

        Gtk::Button CaesarCipherPage_Encrypt;
        Gtk::Button CaesarCipherPage_Decrypt;
        Gtk::Button Rot13CipherPage_Encrypt;
        Gtk::Button Rot13CipherPage_Decrypt;
        Gtk::Button AtbashMagic;
        Gtk::Button AffineCipherPage_Encrypt;
        Gtk::Button AffineCipherPage_Decrypt;
        Gtk::Button Md5HashPage_Hash;
        Gtk::Button Sha1HashPage_Hash;
        Gtk::Button Sha256HashPage_Hash;
        Gtk::Button HexEncodingPage_Encode;
        Gtk::Button NullStegoPage_Decipher;

        Gtk::Button CaesarCipherPage_MenuButton;
        Gtk::Button Rot13CipherPage_MenuButton;
        Gtk::Button AtbashCipherPage_MenuButton;
        Gtk::Button AffineCipherPage_MenuButton;
        Gtk::Button Md5HashPage_MenuButton;
        Gtk::Button Sha1HashPage_MenuButton;
        Gtk::Button Sha256HashPage_MenuButton;
        Gtk::Button HexEncodingPage_MenuButton;
        Gtk::Button NullStegoPage_MenuButton;

        // Textviews, Entry, SpinButton & buffers
        Gtk::TextView CaesarCipherInputView;
        Gtk::TextView CaesarCipherOutputView;
        Gtk::TextView Rot13CipherInputView;
        Gtk::TextView Rot13CipherOutputView;
        Gtk::TextView AtbashCipherInputView;
        Gtk::TextView AtbashCIpherOutputView;
        Gtk::TextView AffineCipherInputView;
        Gtk::TextView AffineCipherOutputView;
        Gtk::TextView Md5HashInputView;
        Gtk::TextView Md5HashOutputView;
        Gtk::TextView Sha1HashInputView;
        Gtk::TextView Sha1HashOutputView;
        Gtk::TextView Sha256HashInputView;
        Gtk::TextView Sha256HashOutputView;
        Gtk::TextView HexEncodingInputView;
        Gtk::TextView HexEncodingOutputView;
        Gtk::TextView NullStegoInputView;
        Gtk::TextView NullStegoOutputView;

        // Smart pointers for buffers 
        Glib::RefPtr<Gtk::TextBuffer> inputBuffer;
        Glib::RefPtr<Gtk::TextBuffer> outputBuffer;

        Gtk::SpinButton CaesarCipherKeyInput;
        Gtk::SpinButton AffineCipherKeyInput_1;
        Gtk::SpinButton AffineCipherKeyInput_2;
};