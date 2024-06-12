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
        // Widgets
        Gtk::Box mainPageBox;
        Gtk::Box childBox_1;
        Gtk::Grid grid;
        Gtk::Label childBox_1_title;
        Gtk::Button caesarCipher;
        Gtk::Button rot13Cipher;
        Gtk::Button atbashCipher;
        Gtk::Button affineCipher;
};

MyWindow::MyWindow(): 
    mainPageBox(Gtk::Orientation::VERTICAL), 

    // Section 1: Symmetric Substitution Ciphers
    childBox_1(Gtk::Orientation::VERTICAL),
    childBox_1_title("Symmetric Substitution Ciphers"),
    caesarCipher("Caesar's Cipher"),
    rot13Cipher("ROT13 Cipher"),
    atbashCipher("Atbash Cipher"),
    affineCipher("Affine Cipher")
    {
    set_title("Kry0steg GUI");
    set_default_size(600, 600);

    // Spacing and margin
    childBox_1.set_spacing(10);
    mainPageBox.set_margin(10);
    grid.set_row_spacing(10);
    grid.set_column_spacing(10);

    // Alignemnt 
    childBox_1_title.set_halign(Gtk::Align::CENTER);
    mainPageBox.set_halign(Gtk::Align::CENTER);

    // Attach and align widgets on the grid
    grid.attach(caesarCipher, 2,0,1,1);
    grid.attach(rot13Cipher, 4,0,1,1);
    grid.attach(atbashCipher, 2,1,1,1);
    grid.attach(affineCipher, 4,1,1,1);

    // Button customization
    caesarCipher.set_size_request(50,70);
    rot13Cipher.set_size_request(50,70);
    atbashCipher.set_size_request(50,70);
    affineCipher.set_size_request(50, 70);

    caesarCipher.set_hexpand(false);
    rot13Cipher.set_hexpand(false);
    atbashCipher.set_hexpand(false);
    affineCipher.set_hexpand(false);

    rot13Cipher.set_vexpand(false);
    caesarCipher.set_vexpand(false);
    atbashCipher.set_vexpand(false);
    affineCipher.set_vexpand(false);

    // Append widgets to child container
    childBox_1.append(childBox_1_title);
    childBox_1.append(grid);

    // Append child container to main container
    mainPageBox.append(childBox_1);
    set_child(mainPageBox);
}

int main(int argc, char *argv[]){
    auto app = Gtk::Application::create("org.gtkmm.kry0steg");
    return app->make_window_and_run<MyWindow>(argc, argv);
}