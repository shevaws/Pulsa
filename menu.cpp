#include "LL.h"

//Submenu 1 (Data)
void menu1(int pilih) {
    menu1:
    int pilihan;
    cout << ">>>>> Sub-Menu Pulsa <<<<<" << endl;
    cout << '\n';
    tampil_pulsa_admin();
    cout << "\n1. Tambah Pulsa" << endl;
    cout << "2. Edit Pulsa" << endl;
    cout << "3. Hapus Pulsa" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan;

    if (pilihan == 1) {
        string name;
        int price;
        int id;
        
        cout << "Masukkan Nama Pulsa : ";
        cin.ignore();
        getline(cin, name);
        cout << "Masukkan Harga : ";
        cin >> price;
        cout << "Masukkan Id : ";
        cin >> id;

        tambahp(name, price, id);
        goto menu1;
    } else if (pilihan == 2) {
        int cari;

        cout << "Masukkan id Data yang ingin diubah : ";
        cin >> cari;
        
        editp(cari);
        goto menu1;
    } else if (pilihan == 3) {
        int cari;

        cout << "Masukkan id data yang ingin dihapus : ";
        cin >> cari;

        hapusp(cari);
        goto menu1;
    } else {
        cout << "Harap pilih pilihan yang tersedia." << endl;
        goto menu1;
    }
}

//Submenu 2 (Rekening Tujuan)
void menu2(int pilih) {
    menu2:
    int pilihan;
    cout << ">>>>> Sub-Menu Rekening Tujuan <<<<<" << endl;
    cout << '\n';
    cout << "BCA : " << endl;
    rek();
    tampil_BCA();
    cout << '\n';
    cout << "Gopay : " << endl;
    rek();
    tampil_GP();
    cout << '\n';
    cout << "Dana : " << endl;
    rek();
    tampil_DN();
    cout << "\n1. Tambah Rekening" << endl;
    cout << "2. Edit Rekening" << endl;
    cout << "3. Hapus Rekening" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan;
}

//Ya gitu
void menu_admin() {
    system ("cls");
    int pilih;
    cout << "Menu Admin ARRZ" << endl;
    cout << "1. Edit Pulsa" << endl;
    cout << "2. Edit Rekening" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilih;
    
    if (pilih == 1) {
        menu1(1);
    } else if (pilih == 2) {
        menu2(2);
    }
}

//Sama aja
void menu_user() {
    int pilihu;
    system ("cls");
    cout << "===== Selamat Datang di Counter ARRZ =====" << endl;
    cout << "Pulsa Yang Tersedia : " << endl;
    cout << '\n';
    tampil_pulsa();
    cout << '\n';
    cout << "1. Beli Pulsa" << endl;
    cout << "2. Cek Keranjang" << endl;
    cout << "3. Bayar" << endl;
    cout << "Masukkan Pilihan Anda : ";
    cin >> pilihu;

    switch (pilihu) {
        case 1:
        int carip;
        cout << "Masukkan Nomor Item : ";
        cin >> carip;
        tambahk(carip);
        break;

        case 2: 
        tampilk();
        break;

        case 3:
        int pilihm;
        cout << "Pilih Metode Pembayaran : " << endl;
        cout << "1. BCA" << endl;
        cout << "2. Gopay" << endl;
        cout << "3. Dana" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilihm;
        
        if (pilihm == 1) {
            rek();
            tampil_BCA();
        } else if (pilihm == 2) {
            rek();
            tampil_GP();
        } else if (pilihm == 3) {
            rek();
            tampil_DN();
        }
        
        default:
        cout << "Harap pilih sesuai pilihan.";
        break;
    }
}

//Login kang
void admin() {
    string username = "arrz";
    string password = "123";
    string user;
    string pass;
    cout << "\nAdmin ARRZ" << endl;
    cout << "Username: ";
    cin >> user;
    if (user == username){
        cout << "Password: ";
        cin >> pass;
        if (pass == password){
            cout << "Berhasil login, akan redirect ke menu admin." << endl;
            sleep(2);
            system("cls");
            menu_admin();
        }
        else {
            cout << "Incorrect Password!" << endl;
        }
    }
    else {
        cout << "Incorrect Username!" << endl;
    }   
}


int main(int argc, char const *argv[])
{
    tambahp("Raka", 5000, 1);
    awal:
    system("cls");
    int pilih;
    cout << ">>>>> E-Counter ARRZ <<<<<" << endl;
    cout << "Login Sebagai: " << endl;
    cout << "1. Admin\n2. User" << endl;
    cout << "Masukkan Pilihan : ";
    cin >> pilih;

    if (pilih == 1) {
        admin();
        goto awal;
    } else if (pilih == 2) {
        menu_user();
        goto awal;
    }
    
    return 0;
}
