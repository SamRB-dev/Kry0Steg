#include <gtkmm-4.0/gtkmm/application.h>
#include <gtkmm-4.0/gtkmm/box.h>
#include <gtkmm-4.0/gtkmm/button.h>
#include <gtkmm-4.0/gtkmm/enums.h>
#include <gtkmm-4.0/gtkmm/grid.h>
#include <gtkmm-4.0/gtkmm/label.h>
#include <gtkmm-4.0/gtkmm/window.h>

class MyWindow: public Gtk::Window {
    public:
        // Main window
        MyWindow();

    protected:
        /* Widgets */
        // Box & grid
        Gtk::Box mainPageBox; // Main Page
        Gtk::Box childBox_1; // Section 1
        Gtk::Grid grid;
        Gtk::Box childBox_2; // Section 2
        Gtk::Grid grid_2;

        // Labels
        Gtk::Label childBox_1_title;
        Gtk::Label childBox_2_title;

        // Buttons
        Gtk::Button caesarCipher;
        Gtk::Button rot13Cipher;
        Gtk::Button atbashCipher;
        Gtk::Button affineCipher;
        Gtk::Button md5Hash;
        Gtk::Button sha1Hash;
        Gtk::Button sha256Hash;

};

MyWindow::MyWindow(): 
    mainPageBox(Gtk::Orientation::VERTICAL), 

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
    sha256Hash("SHA256")
    {
    set_title("Kry0steg GUI");
    set_default_size(600, 600);

    // Spacing and margin
    childBox_1.set_spacing(10);
    childBox_2.set_spacing(10);
    mainPageBox.set_margin(25);
    mainPageBox.set_spacing(15);
    grid.set_row_spacing(10);
    grid.set_column_spacing(10);
    grid_2.set_row_spacing(10);
    grid_2.set_column_spacing(10);

    // Alignemnt 
    childBox_1_title.set_halign(Gtk::Align::CENTER);
    childBox_2_title.set_halign(Gtk::Align::CENTER);
    mainPageBox.set_halign(Gtk::Align::CENTER);

    // Attach and align widgets on the grid
    grid.attach(caesarCipher, 2,0,1,1);
    grid.attach(rot13Cipher, 4,0,1,1);
    grid.attach(atbashCipher, 2,1,1,1);
    grid.attach(affineCipher, 4,1,1,1);
    grid_2.attach(md5Hash, 2,0);
    grid_2.attach(sha1Hash, 4,0);
    grid_2.attach(sha256Hash, 6,0);
    grid_2.attach(sha256Hash, 6,0);


    // Button customization
    caesarCipher.set_size_request(50,70);
    rot13Cipher.set_size_request(50,70);
    atbashCipher.set_size_request(50,70);
    affineCipher.set_size_request(50, 70);
    md5Hash.set_size_request(50,70);
    sha1Hash.set_size_request(50,70);
    sha256Hash.set_size_request(50,70);
    
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

    // Append widgets to child container
    childBox_1.append(childBox_1_title);
    childBox_1.append(grid);
    childBox_2.append(childBox_2_title);
    childBox_2.append(grid_2);

    // Append child container to main container
    mainPageBox.append(childBox_1);
    mainPageBox.append(childBox_2);
    set_child(mainPageBox);
}

int main(int argc, char *argv[]){
    auto app = Gtk::Application::create("org.gtkmm.kry0steg");
    return app->make_window_and_run<MyWindow>(argc, argv);
}