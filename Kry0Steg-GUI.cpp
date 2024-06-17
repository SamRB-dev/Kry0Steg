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
// #include <utility>

/* Custom Headers */
#include "include/GeneralCiphers.h"
#include "include/HashFunctions.h"
#include "include/Encoders.h"
#include "include/SteganoFunctions.h"

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

MyWindow::MyWindow(): 
    mainPageBox(Gtk::Orientation::VERTICAL), 

    /*Main Menu*/
    mainMenu(Gtk::Orientation::VERTICAL),
    // Section 1: Symmetric Substitution Ciphers
    childBox_1(Gtk::Orientation::VERTICAL),
    childBox_1_title("Symmetric Substitution Ciphers"),
    caesarCipher("Caesar's Cipher"),
    rot13Cipher("ROT13 Cipher"),
    atbashCipher("Atbash Cipher"),
    affineCipher("Affine Cipher"),
    // Section 2: Hashing
    childBox_2(Gtk::Orientation::VERTICAL),
    childBox_2_title("Hashing"),
    md5Hash("MD5"),
    sha1Hash("SHA1"),
    sha256Hash("SHA256"),
    // Section 3: Encoders
    childBox_3(Gtk::Orientation::VERTICAL),
    childBox_3_title("Encoders"),
    text2Hex("Hex Encoding"),
    // Section 4: Stego
    childBox_4(Gtk::Orientation::VERTICAL),
    childBox_4_title("Steganography"),
    nullCipher("Null Cipher"),
    // Section 5: AES file encryption

    /*Caesar's Cipher Page*/
    caesarCipherPage(Gtk::Orientation::VERTICAL),
    CaesarCipherPage_Encrypt("Encrypt"),
    CaesarCipherPage_Decrypt("Decrypt"),
    caesarCipherPage_Input_Label("Enter Plain Text or Encrypted Text"),
    caesarCipherPage_Output_Label("Generated Output"),
    caesarCipherPage_Key_Label("Enter Key [Default 5]"),
    CaesarCipherPage_MenuButton("Menu"),

    /*ROT13 Page*/
    rot13CipherPage(Gtk::Orientation::VERTICAL),
    Rot13CipherPage_Encrypt("Encrypt"),
    Rot13CipherPage_Decrypt("Decrypt"),
    rot13CipherPage_Input_Label("Enter Plain Text or Encrypted Text"),
    rot13CipherPage_Output_Label("Generate Ouput"),
    Rot13CipherPage_MenuButton("Menu"),

    /*Atbash Page*/
    atbashCipherPage(Gtk::Orientation::VERTICAL),
    AtbashMagic("Atbash Magic"),
    atbashCipherPage_Input_Label("Enter Plain Text or Encrypted Text"),
    atbashCipherPage_Output_Label("Generated Output"),
    AtbashCipherPage_MenuButton("Menu"),

    /*Affine Page*/
    affineCipherPage(Gtk::Orientation::VERTICAL),
    AffineCipherPage_Encrypt("Encrypt"),
    AffineCipherPage_Decrypt("Decrypt"),
    affineCipherPage_Input_Label("Enter Plain Text or Encrypted Text"),
    affineCipherPage_Output_Label("Generate Output"),
    AffineCipherPage_MenuButton("Menu"),
    affineCipherPage_Key_1_Label("Key A"),
    affineCipherPage_Key_2_Label("Key B"),

    /*MD5 page*/
    md5HashPage(Gtk::Orientation::VERTICAL),
    Md5HashPage_Hash("Hash"),
    Md5HashPage_MenuButton("Menu"),
    md5HashPage_Input_label("Enter Message for hashing"),
    md5HashPage_Output_Label("Generated Output"),

    /*SHA1 Page*/
    sha1HashPage(Gtk::Orientation::VERTICAL),
    Sha1HashPage_Hash("Hash"),
    Sha1HashPage_MenuButton("Menu"),
    sha1HashPage_Input_Label("Enter Message for hashing"),
    sha1HashPage_Output_Label("Generated Output"),

    /*SHA256 page*/
    sha256HashPage(Gtk::Orientation::VERTICAL),
    Sha256HashPage_Hash("Hash"),
    Sha256HashPage_MenuButton("Menu"),
    sha256HashPage_Input_Label("Enter Message for hashing"),
    sha256HashPage_Output_Label("Generated Output"),

    /*Hex Encoding*/
    hexEncodingPage(Gtk::Orientation::VERTICAL),
    HexEncodingPage_Encode("Encode"),
    HexEncodingPage_MenuButton("Menu"),
    hexEncodingPage_Input_Label("Enter Message"),
    hexEncodingPage_Output_Label("Generated Output"),

    /*Null cipher page*/
    nullStegoPage(Gtk::Orientation::VERTICAL),
    NullStegoPage_Decipher("Decipher"),
    NullStegoPage_MenuButton("Menu"),
    nullStegoPage_Input_Label("Enter Message"),
    nullStegoPage_Output_Label("Generated Output")
    /*Note: In GTK, widgets can be attached to one container at a time which 
    means components from one frame/page/container might not work in another
    container. - https://docs.gtk.org/gtk3/method.Container.add.html*/
    {
    set_title("Kry0Steg GUI");
    set_default_size(350, 350);
    set_resizable(false);

    // Spacing and margin
    mainPageBox.set_margin(35);
    mainPageBox.set_spacing(15);

    /*Main Menu*/
    mainMenu.set_spacing(25); // Space between widgets
    childBox_1.set_spacing(15);
    childBox_2.set_spacing(15);
    childBox_3.set_spacing(15);
    childBox_4.set_spacing(15);

    grid.set_row_spacing(15);
    grid.set_column_spacing(15);
    grid.set_column_homogeneous(true); 
    grid.set_row_homogeneous(true);

    grid_2.set_row_spacing(15);
    grid_2.set_column_spacing(15);
    grid_2.set_column_homogeneous(true);
    grid_2.set_row_homogeneous(true);

    grid_3.set_row_spacing(15);
    grid_3.set_column_spacing(15);

    grid_4.set_row_spacing(15);
    grid_4.set_column_spacing(15);

    caesarGrid.set_row_spacing(15);
    caesarGrid.set_column_spacing(15);
    rot13Grid.set_row_spacing(15);
    rot13Grid.set_column_spacing(15);
    affineGrid.set_column_spacing(15);
    affineGrid.set_row_spacing(15);

    /*Caesar Cipher Page*/
    caesarCipherPage.set_spacing(15);
    caesarCipherPage.set_margin(45);

    /*Rot13 page*/
    rot13CipherPage.set_spacing(15);
    rot13CipherPage.set_margin(45);

    /*Atbash Page*/
    atbashCipherPage.set_spacing(15);
    atbashCipherPage.set_margin(45);

    /*Affine Page*/
    affineCipherPage.set_spacing(15);
    affineCipherPage.set_margin(45);

    /*MD5 Page*/
    md5HashPage.set_spacing(15);
    md5HashPage.set_margin(45);

    /*SHA1 page*/
    sha1HashPage.set_spacing(15);
    sha1HashPage.set_margin(45);

    /*SHA256 page*/
    sha256HashPage.set_spacing(15);
    sha256HashPage.set_margin(45);

    /*Hexcoding page*/
    hexEncodingPage.set_spacing(15);
    hexEncodingPage.set_margin(45);

    /*Null Cipher Page*/
    nullStegoPage.set_spacing(15);
    nullStegoPage.set_margin(45);

    // Alignemnt 
    mainPageBox.set_halign(Gtk::Align::BASELINE_CENTER);
    mainPageBox.set_valign(Gtk::Align::BASELINE_CENTER);
    childBox_1_title.set_halign(Gtk::Align::CENTER);
    childBox_2_title.set_halign(Gtk::Align::CENTER);
    childBox_3_title.set_halign(Gtk::Align::CENTER);
    childBox_4_title.set_halign(Gtk::Align::CENTER);
    grid_3.set_halign(Gtk::Align::CENTER);
    grid_4.set_halign(Gtk::Align::CENTER);
    caesarGrid.set_halign(Gtk::Align::CENTER);
    rot13Grid.set_halign(Gtk::Align::CENTER);
    affineGrid.set_halign(Gtk::Align::CENTER);

    // Attach and align widgets on the grid
    grid.attach(caesarCipher, 3,0);
    grid.attach(rot13Cipher, 5,0);
    grid.attach(atbashCipher, 3,1);
    grid.attach(affineCipher, 5,1);
    grid_2.attach(md5Hash, 4,0);
    grid_2.attach(sha1Hash, 6,0);
    grid_2.attach(sha256Hash, 8,0);
    grid_3.attach(text2Hex,4,0);
    grid_4.attach(nullCipher, 4,0);
    caesarGrid.attach(CaesarCipherPage_Encrypt, 2,1);
    caesarGrid.attach(CaesarCipherPage_Decrypt, 4,1);
    rot13Grid.attach(Rot13CipherPage_Encrypt, 2,1);
    rot13Grid.attach(Rot13CipherPage_Decrypt, 4,1);
    affineGrid.attach(AffineCipherPage_Encrypt, 2, 1);
    affineGrid.attach(AffineCipherPage_Decrypt, 4, 1);

    // Button customization
    caesarCipher.set_size_request(20,45);
    // rot13Cipher.set_size_request(50,70);
    // atbashCipher.set_size_request(50,70);
    // affineCipher.set_size_request(50, 70);
    md5Hash.set_size_request(20,45);
    // sha1Hash.set_size_request(50,70);
    // sha256Hash.set_size_request(50,70);
    text2Hex.set_size_request(50,70);
    nullCipher.set_size_request(50,70);
    CaesarCipherPage_Encrypt.set_size_request(50,70);
    CaesarCipherPage_Decrypt.set_size_request(50,70);
    Rot13CipherPage_Encrypt.set_size_request(50, 70);
    Rot13CipherPage_Decrypt.set_size_request(50, 70);
    AffineCipherPage_Encrypt.set_size_request(50, 70);
    AffineCipherPage_Decrypt.set_size_request(50, 70);
    CaesarCipherPage_MenuButton.set_size_request(30,30);
    AtbashMagic.set_size_request(50, 70);
    Md5HashPage_Hash.set_size_request(50, 70);
    Sha1HashPage_Hash.set_size_request(50, 70);
    Sha256HashPage_Hash.set_size_request(50, 70);
    HexEncodingPage_Encode.set_size_request(50, 70);
    NullStegoPage_Decipher.set_size_request(50,  70);

    // caesarCipher.set_hexpand(false);
    // rot13Cipher.set_hexpand(false);
    // atbashCipher.set_hexpand(false);
    // affineCipher.set_hexpand(false);
    md5Hash.set_hexpand(false);
    sha1Hash.set_hexpand(false);
    sha256Hash.set_hexpand(false);

    // rot13Cipher.set_vexpand(false);
    // caesarCipher.set_vexpand(false);
    // atbashCipher.set_vexpand(false);
    // affineCipher.set_vexpand(false);
    md5Hash.set_vexpand(false);
    sha1Hash.set_vexpand(false);
    sha256Hash.set_vexpand(false);

    // Textviews
    inputBuffer = Gtk::TextBuffer::create();
    outputBuffer = Gtk::TextBuffer::create();
    CaesarCipherInputView.set_buffer(inputBuffer);
    CaesarCipherOutputView.set_buffer(outputBuffer);
    Rot13CipherInputView.set_buffer(inputBuffer);
    Rot13CipherOutputView.set_buffer(outputBuffer);
    AtbashCipherInputView.set_buffer(inputBuffer);
    AtbashCIpherOutputView.set_buffer(outputBuffer);
    AffineCipherInputView.set_buffer(inputBuffer);
    AffineCipherOutputView.set_buffer(outputBuffer);
    Md5HashInputView.set_buffer(inputBuffer);
    Md5HashOutputView.set_buffer(outputBuffer);
    Sha1HashInputView.set_buffer(inputBuffer);
    Sha1HashOutputView.set_buffer(outputBuffer);
    Sha256HashInputView.set_buffer(inputBuffer);
    Sha256HashOutputView.set_buffer(outputBuffer);
    HexEncodingInputView.set_buffer(inputBuffer);
    HexEncodingOutputView.set_buffer(outputBuffer);
    NullStegoInputView.set_buffer(inputBuffer);
    NullStegoOutputView.set_buffer(outputBuffer);

    CaesarCipherInputView.set_size_request(250, 100);
    CaesarCipherOutputView.set_size_request(250, 100);
    Rot13CipherInputView.set_size_request(250, 100);
    Rot13CipherOutputView.set_size_request(250, 100);
    AtbashCipherInputView.set_size_request(250, 100);
    AtbashCIpherOutputView.set_size_request(250, 100);
    AffineCipherInputView.set_size_request(250, 100);
    AffineCipherOutputView.set_size_request(250,100);
    Md5HashInputView.set_size_request(250, 100);
    Md5HashOutputView.set_size_request(250, 100);
    Sha1HashInputView.set_size_request(250, 100);
    Sha1HashOutputView.set_size_request(250, 100);
    Sha256HashInputView.set_size_request(250, 100);
    Sha256HashOutputView.set_size_request(250, 100);
    HexEncodingInputView.set_size_request(250, 100);
    HexEncodingOutputView.set_size_request(250, 100);
    NullStegoInputView.set_size_request(250, 100);
    NullStegoOutputView.set_size_request(250, 100);

    // SpinButton
    CaesarCipherKeyInput.set_adjustment(Gtk::Adjustment::create(5,0,25)); 
        // adjusts spin buttons numeric range from 0 to 25 with defualt being 5
    AffineCipherKeyInput_1.set_adjustment(Gtk::Adjustment::create(5,0,25));
    AffineCipherKeyInput_2.set_adjustment(Gtk::Adjustment::create(5,0,25));

    /* Append widgets to child container */
    childBox_1.append(childBox_1_title);
    childBox_1.append(grid);
    childBox_2.append(childBox_2_title);
    childBox_2.append(grid_2);
    childBox_3.append(childBox_3_title);
    childBox_3.append(grid_3);
    childBox_4.append(childBox_4_title);
    childBox_4.append(grid_4);
    // Caesar Cipher Page
    caesarCipherPage.append(caesarCipherPage_Input_Label);
    caesarCipherPage.append(CaesarCipherInputView);
    caesarCipherPage.append(caesarCipherPage_Key_Label);
    caesarCipherPage.append(CaesarCipherKeyInput);
    caesarCipherPage.append(caesarGrid);
    caesarCipherPage.append(caesarCipherPage_Output_Label);
    caesarCipherPage.append(CaesarCipherOutputView);
    caesarCipherPage.append(CaesarCipherPage_MenuButton);    
    // Rot13 page
    rot13CipherPage.append(rot13CipherPage_Input_Label);
    rot13CipherPage.append(Rot13CipherInputView);
    rot13CipherPage.append(rot13Grid);
    rot13CipherPage.append(rot13CipherPage_Output_Label);
    rot13CipherPage.append(Rot13CipherOutputView);
    rot13CipherPage.append(Rot13CipherPage_MenuButton);
    // Atbash
    atbashCipherPage.append(atbashCipherPage_Input_Label);
    atbashCipherPage.append(AtbashCipherInputView);
    atbashCipherPage.append(AtbashMagic);
    atbashCipherPage.append(atbashCipherPage_Output_Label);
    atbashCipherPage.append(AtbashCIpherOutputView);
    atbashCipherPage.append(AtbashCipherPage_MenuButton);
    // Affine
    affineCipherPage.append(affineCipherPage_Input_Label);
    affineCipherPage.append(AffineCipherInputView);
    affineCipherPage.append(affineCipherPage_Key_1_Label);
    affineCipherPage.append(AffineCipherKeyInput_1);
    affineCipherPage.append(affineCipherPage_Key_2_Label);
    affineCipherPage.append(AffineCipherKeyInput_2);
    affineCipherPage.append(affineGrid);
    affineCipherPage.append(AffineCipherOutputView);
    affineCipherPage.append(AffineCipherPage_MenuButton);
    // MD5
    md5HashPage.append(md5HashPage_Input_label);
    md5HashPage.append(Md5HashInputView);
    md5HashPage.append(Md5HashPage_Hash);
    md5HashPage.append(md5HashPage_Output_Label);
    md5HashPage.append(Md5HashOutputView);
    md5HashPage.append(Md5HashPage_MenuButton);
    // SHA1
    sha1HashPage.append(sha1HashPage_Input_Label);
    sha1HashPage.append(Sha1HashInputView);
    sha1HashPage.append(Sha1HashPage_Hash);
    sha1HashPage.append(sha1HashPage_Output_Label);
    sha1HashPage.append(Sha1HashOutputView);
    sha1HashPage.append(Sha1HashPage_MenuButton);
    // SHA256
    sha256HashPage.append(sha256HashPage_Input_Label);
    sha256HashPage.append(Sha256HashInputView);
    sha256HashPage.append(Sha256HashPage_Hash);
    sha256HashPage.append(sha256HashPage_Output_Label);
    sha256HashPage.append(Sha256HashOutputView);
    sha256HashPage.append(Sha256HashPage_MenuButton);
    // Hexcoding
    hexEncodingPage.append(hexEncodingPage_Input_Label);
    hexEncodingPage.append(HexEncodingInputView);
    hexEncodingPage.append(HexEncodingPage_Encode);
    hexEncodingPage.append(hexEncodingPage_Output_Label);
    hexEncodingPage.append(HexEncodingOutputView);
    hexEncodingPage.append(HexEncodingPage_MenuButton);
    // NullStego page
    nullStegoPage.append(nullStegoPage_Input_Label);
    nullStegoPage.append(NullStegoInputView);
    nullStegoPage.append(NullStegoPage_Decipher);
    nullStegoPage.append(nullStegoPage_Output_Label);
    nullStegoPage.append(NullStegoOutputView);
    nullStegoPage.append(NullStegoPage_MenuButton);

    // Append child container to main containers
    // mainPageBox.append(childBox_1);
    // mainPageBox.append(childBox_2);
    mainMenu.append(childBox_1);
    mainMenu.append(childBox_2);
    mainMenu.append(childBox_3);
    mainMenu.append(childBox_4);
    mainPageBox.append(pageStack);
    mainPageBox.append(stackSwitch);
    pageStack.add(mainMenu, "menu", "Menu");
    pageStack.add(caesarCipherPage, "page1", "Caesar Cipher");
    pageStack.add(rot13CipherPage, "page2", "ROT13");
    pageStack.add(atbashCipherPage, "page3", "Atbash");
    pageStack.add(affineCipherPage, "page4", "Affine");
    pageStack.add(md5HashPage, "page5", "MD5");
    pageStack.add(sha1HashPage, "page6", "SHA1");
    pageStack.add(sha256HashPage, "page7", "SHA256");
    pageStack.add(hexEncodingPage, "page8", "Hex Encoding");
    pageStack.add(nullStegoPage, "page9", "Stego - Null Cipher");
    set_child(mainPageBox);

    /* Connecting Signals */ 
    // Page Switching
    caesarCipher.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::caesar_page_click));
    rot13Cipher.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::rot13_page_click));
    atbashCipher.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::atbash_page_click));
    affineCipher.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::affine_page_click));
    md5Hash.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::md5_page_click));
    sha1Hash.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::sha1_page_click));
    sha256Hash.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::sha256_page_click));
    text2Hex.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::hex_page_click));
    nullCipher.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::stegoNull_page_click));

    // Back-2-Menu
    CaesarCipherPage_MenuButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::MenuButton_click));
    Rot13CipherPage_MenuButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::MenuButton_click));
    AtbashCipherPage_MenuButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::MenuButton_click));
    AffineCipherPage_MenuButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::MenuButton_click));
    Md5HashPage_MenuButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::MenuButton_click));
    Sha1HashPage_MenuButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::MenuButton_click));
    Sha256HashPage_MenuButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::MenuButton_click));
    HexEncodingPage_MenuButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::MenuButton_click));
    NullStegoPage_MenuButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::MenuButton_click));

    // Button press event handling
    CaesarCipherPage_Encrypt.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::caesar_encrypt_click));
    CaesarCipherPage_Decrypt.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::caesar_decrypt_click));
    Rot13CipherPage_Encrypt.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::rot13_encrypt_click));
    Rot13CipherPage_Decrypt.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::rot13_decrypt_click));
    AtbashMagic.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::atbash_magic_click));
    AffineCipherPage_Encrypt.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::affine_encrypt_click));
    AffineCipherPage_Decrypt.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::affine_decrypt_click));
    Md5HashPage_Hash.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::md5_hash_click));
    Sha1HashPage_Hash.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::sha1_hash_click));
    Sha256HashPage_Hash.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::sha256_hash_click));
    HexEncodingPage_Encode.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::hex_encode_click));
    NullStegoPage_Decipher.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::null_decipher_click));
}

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
// Entry Point
int main(int argc, char *argv[]){
    auto app = Gtk::Application::create("org.gtkmm.kry0steg");
    return app->make_window_and_run<MyWindow>(argc, argv);
}
