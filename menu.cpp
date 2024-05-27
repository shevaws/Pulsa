#include "LL.h"

// Submenu 1 (Data)
void menu1(int pilih)
{
menu1:
    int pilihan;
    cout << ">>>>> Sub-Menu Pulsa <<<<<" << endl;
    cout << '\n';
    tampil_pulsa_admin();
    cout << "\n1. Tambah Pulsa" << endl;
    cout << "2. Edit Pulsa" << endl;
    cout << "3. Hapus Pulsa" << endl;
    cout << "0. Kembali" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan;

    if (pilihan == 1)
    {
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
    }
    else if (pilihan == 2)
    {
        int cari;

        cout << "Masukkan id Data yang ingin diubah : ";
        cin >> cari;

        editp(cari);
        goto menu1;
    }
    else if (pilihan == 3)
    {
        int cari;

        cout << "Masukkan id data yang ingin dihapus : ";
        cin >> cari;

        hapusp(cari);
        goto menu1;
    }
    else if (pilihan == 0)
    {
        return;
    }

    else
    {
        cout << "Harap pilih pilihan yang tersedia." << endl;
        goto menu1;
    }
}

// Submenu 2 (Rekening Tujuan)
void menu2(int pilih)
{
menu2:
    int pilihan;
    cout << ">>>>> Sub-Menu Rekening Tujuan <<<<<" << endl;
    cout << '\n';
    cout << "BCA : " << endl;
    tampil_BCA();
    cout << '\n';
    cout << "Gopay : " << endl;
    tampil_GP();
    cout << '\n';
    cout << "Dana : " << endl;
    tampil_DN();
    cout << "\n1. Tambah Rekening" << endl;
    cout << "2. Hapus Rekening" << endl;
    cout << "0. Kembali" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        cout << "Harap pilih method yang ingin ditambahkan : ";
        int p;
        cin >> p;
        if (p == 1)
        {
            tambahbca();
            sleep(1);
            goto menu2;
        }
        else if (p == 2)
        {
            tambahgp();
            sleep(1);
            goto menu2;
        }
        else if (p == 3)
        {
            tambahdn();
            sleep(1);
            goto menu2;
        }
        else if (p == 0)
        {
            return;
        }

        else
        {
            cout << "Harap pilh sesuai pilihan yang ada." << endl;
            goto menu2;
        }

        break;
    case 2:
        int m;
        cout << "Method mana yang ingin dihapus rekeningnya (index) : ";
        cin >> m;
        if (m == 1)
        {
            tampil_BCA();
            cout << endl;
            int carir;
            cout << "Pilih index data yang ingin dihapus : ";
            cin >> carir;
            hapusbca(carir);
            cout << "Data berhasil dihapus." << endl;
            sleep(1);
            goto menu2;
        }
        else if (m == 2)
        {
            tampil_GP();
            cout << endl;
            int carir;
            cout << "Pilih index data yang ingin dihapus : ";
            cin >> carir;
            hapusgp(carir);
            cout << "Data berhasil dihapus." << endl;
            sleep(1);
            goto menu2;
        }
        else if (m == 3)
        {
            tampil_DN();
            cout << endl;
            int carir;
            cout << "Pilih index data yang ingin dihapus : ";
            cin >> carir;
            hapusdn(carir);
            cout << "Data berhasil dihapus." << endl;
            sleep(1);
            goto menu2;
        }

        break;
    default:
        cout << "Harap pilih sesuai pilihan." << endl;
        break;
    }
}

// Ya gitu
void menu_admin()
{
    int pilih;
    do
    {
        system("cls");
        cout << "Menu Admin ARRZ" << endl;
        cout << "1. Edit Pulsa" << endl;
        cout << "2. Edit Rekening" << endl;
        cout << "3. Lihat Pesanan" << endl;
        cout << "0. Logout" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilih;

        if (pilih == 1)
        {
            menu1(1);
        }
        else if (pilih == 2)
        {
            menu2(2);
        }
        else if (pilih == 3)
        {
            tampilo();
            cout << endl;
            system("pause");
        }
    } while (pilih != 0);
}

// Sama aja
void menu_user()
{
awalu:
    int pilihu;
    do
    {
        system("cls");
        cout << "===== Selamat Datang di Counter ARRZ =====" << endl;
        cout << "Pulsa Yang Tersedia : " << endl;
        cout << '\n';
        tampil_pulsa();
        cout << '\n';
        cout << "1. Beli Pulsa" << endl;
        cout << "2. Cek Keranjang" << endl;
        cout << "3. Bayar" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan Pilihan Anda : ";
        cin >> pilihu;

        switch (pilihu)
        {
        case 1:
            int carip;
            cout << "Masukkan Nomor Item : ";
            cin >> carip;
            tambahk(carip);
            break;

        case 2:
            tampilk();
            cout << endl;
            system("pause");
            break;

        case 3:
            int pilihm;
            cout << "Pilih Metode Pembayaran : " << endl;
            cout << "1. BCA" << endl;
            cout << "2. Gopay" << endl;
            cout << "3. Dana" << endl;
            cout << "Masukkan pilihan anda : ";
            cin >> pilihm;

            if (pilihm == 1)
            {
                tampil_BCA();
                tambaho();
            }
            else if (pilihm == 2)
            {
                tampil_GP();
                tambaho();
            }
            else if (pilihm == 3)
            {
                tampil_DN();
                tambaho();
            }
            break;
        default:
            cout << "Harap pilih sesuai pilihan." << endl;
            break;
        }
    } while (pilihu != 0);
}

// Login kang
void admin()
{
    string username = "arrz";
    string password = "123";
    string user;
    string pass;
    cout << "\nAdmin ARRZ" << endl;
    cout << "Username: ";
    cin >> user;
    if (user == username)
    {
        cout << "Password: ";
        cin >> pass;
        if (pass == password)
        {
            cout << "Berhasil login, akan redirect ke menu admin." << endl;
            sleep(2);
            system("cls");
            menu_admin();
        }
        else
        {
            cout << "Incorrect Password!" << endl;
        }
    }
    else
    {
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

    if (pilih == 1)
    {
        admin();
        goto awal;
    }
    else if (pilih == 2)
    {
        menu_user();
        goto awal;
    }

    return 0;
}
