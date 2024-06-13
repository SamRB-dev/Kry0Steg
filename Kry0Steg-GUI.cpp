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

/* Custom Headers */
#include "Headers/GeneralCiphers.h"
class MyWindow: public Gtk::Window {
    public:
        // Main window
        MyWindow();

    protected:
        /*Functions for handling signals*/
        void caesar_page_click();
        void goToMenuButton_click();
        void caesar_encrypt_click();
        void caesar_decrypt_click();

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

        Gtk::Box caesarCipherPage; // Cipher Page with I/O
        Gtk::Grid caesarGrid;

        // Labels
        Gtk::Label childBox_1_title;
        Gtk::Label childBox_2_title;
        Gtk::Label caesarCipherPage_Input_Label;
        Gtk::Label caesarCipherPage_Output_Label;

        // Buttons
        Gtk::Button caesarCipher;
        Gtk::Button rot13Cipher;
        Gtk::Button atbashCipher;
        Gtk::Button affineCipher;
        Gtk::Button md5Hash;
        Gtk::Button sha1Hash;
        Gtk::Button sha256Hash;
        Gtk::Button CipherPage_Encrypt;
        Gtk::Button CipherPage_Decrypt;
        Gtk::Button goToMenuButton; // Common

        // Textviews & buffers
        Gtk::TextView inputView;
        Gtk::TextView outputView;
        Glib::RefPtr<Gtk::TextBuffer> inputBuffer;
        Glib::RefPtr<Gtk::TextBuffer> outputBuffer;
};

MyWindow::MyWindow(): 
    mainPageBox(Gtk::Orientation::VERTICAL), 
    goToMenuButton("Menu"),

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

    /*Caesar's Cipher Page*/
    caesarCipherPage(Gtk::Orientation::VERTICAL),
    CipherPage_Encrypt("Encrypt"),
    CipherPage_Decrypt("Decrypt"),
    caesarCipherPage_Input_Label("Enter Plain Text or Encrypted Text"),
    caesarCipherPage_Output_Label("Generated Output")
    {
    set_title("Kry0steg GUI");
    set_default_size(600, 600);

    // Spacing and margin
    mainPageBox.set_margin(55);
    mainPageBox.set_spacing(15);
    /*Main Menu*/
    mainMenu.set_spacing(15);
    childBox_1.set_spacing(10);
    childBox_2.set_spacing(10);
    grid.set_row_spacing(10);
    grid.set_column_spacing(10);
    grid_2.set_row_spacing(10);
    grid_2.set_column_spacing(10);
    caesarGrid.set_row_spacing(10);
    caesarGrid.set_column_spacing(10);

    /*Caesar Cipher Page*/
    caesarCipherPage.set_spacing(15);
    caesarCipherPage.set_margin(45);

    // Alignemnt 
    childBox_1_title.set_halign(Gtk::Align::CENTER);
    childBox_2_title.set_halign(Gtk::Align::CENTER);
    mainPageBox.set_halign(Gtk::Align::BASELINE_CENTER);
    mainPageBox.set_valign(Gtk::Align::BASELINE_CENTER);
    caesarGrid.set_halign(Gtk::Align::CENTER);

    // Attach and align widgets on the grid
    grid.attach(caesarCipher, 4,0);
    grid.attach(rot13Cipher, 6,0);
    grid.attach(atbashCipher, 8,0);
    grid.attach(affineCipher, 6,1);
    grid_2.attach(md5Hash, 4,0);
    grid_2.attach(sha1Hash, 6,0);
    grid_2.attach(sha256Hash, 8,0);
    caesarGrid.attach(CipherPage_Encrypt, 2,1);
    caesarGrid.attach(CipherPage_Decrypt, 4,1);

    // Button customization
    caesarCipher.set_size_request(50,70);
    rot13Cipher.set_size_request(50,70);
    atbashCipher.set_size_request(50,70);
    affineCipher.set_size_request(50, 70);
    md5Hash.set_size_request(50,70);
    sha1Hash.set_size_request(50,70);
    sha256Hash.set_size_request(50,70);
    CipherPage_Encrypt.set_size_request(50,70);
    CipherPage_Decrypt.set_size_request(50,70);
    goToMenuButton.set_size_request(30,30);
    
    caesarCipher.set_hexpand(false);
    rot13Cipher.set_hexpand(false);
    atbashCipher.set_hexpand(false);
    affineCipher.set_hexpand(false);
    md5Hash.set_hexpand(false);
    sha1Hash.set_hexpand(false);
    sha256Hash.set_hexpand(false);

    rot13Cipher.set_vexpand(false);
    caesarCipher.set_vexpand(false);
    atbashCipher.set_vexpand(false);
    affineCipher.set_vexpand(false);
    md5Hash.set_vexpand(false);
    sha1Hash.set_vexpand(false);
    sha256Hash.set_vexpand(false);

    // Textviews
    inputBuffer = Gtk::TextBuffer::create();
    outputBuffer = Gtk::TextBuffer::create();
    inputView.set_buffer(inputBuffer);
    outputView.set_buffer(outputBuffer);
    inputView.set_size_request(250, 100);
    outputView.set_size_request(250, 100);

    /* Append widgets to child container */
    childBox_1.append(childBox_1_title);
    childBox_1.append(grid);
    childBox_2.append(childBox_2_title);
    childBox_2.append(grid_2);
    // Caesar Cipher Page
    caesarCipherPage.append(caesarCipherPage_Input_Label);
    caesarCipherPage.append(inputView);
    caesarCipherPage.append(caesarGrid);
    caesarCipherPage.append(caesarCipherPage_Output_Label);
    caesarCipherPage.append(outputView);
    caesarCipherPage.append(goToMenuButton);

    // Append child container to main containers
    // mainPageBox.append(childBox_1);
    // mainPageBox.append(childBox_2);
    mainMenu.append(childBox_1);
    mainMenu.append(childBox_2);
    mainPageBox.append(pageStack);
    mainPageBox.append(stackSwitch);
    pageStack.add(mainMenu, "menu", "Menu");
    pageStack.add(caesarCipherPage, "page1", "Caesar Cipher");
    set_child(mainPageBox);

    // Connecting Signals
    caesarCipher.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::caesar_page_click));
    goToMenuButton.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::goToMenuButton_click));
    CipherPage_Encrypt.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::caesar_encrypt_click));
}

// Signal Handler
void MyWindow::caesar_page_click(){
    pageStack.set_visible_child("page1");
}

void MyWindow::goToMenuButton_click(){
    pageStack.set_visible_child("menu");
}

void MyWindow::caesar_encrypt_click(){
    Glib::ustring inputStr = inputBuffer->get_text();
    std::string inputRawStr = inputStr.raw();
    std::string cipheredText = caesarCipher(inputRawStr, 5, 'e');
    outputBuffer->set_text(cipheredText);
}

int main(int argc, char *argv[]){
    auto app = Gtk::Application::create("org.gtkmm.kry0steg");
    return app->make_window_and_run<MyWindow>(argc, argv);
}