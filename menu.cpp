#include "LL.h"

using namespace std;

// Submenu 1 (Data)
void menu1(int pilih)
{
menu1:
    system("cls");
    int pilihan;
    cout << "====================================" << endl;
    cout << "          >> Sub-Menu e-wallet <<      " << endl;
    cout << "====================================" << endl;
    cout << '\n';
    read();
    display_admin();
    cout << "\n1. Tambah e-wallet" << endl;
    cout << "2. Edit e-wallet" << endl;
    cout << "3. Hapus e-wallet" << endl;
    cout << "0. Kembali" << endl;
    cout << "------------------------------------" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan;

    if (pilihan == 1)
    {
        string name;
        int price;
        int id;

        cout << "Masukkan Nama e-wallet : ";
        cin.ignore();
        getline(cin, name);
        cout << "Masukkan Harga : ";
        cin >> price;
        cout << "Masukkan Id : ";
        cin >> id;

        tambahp(name, price, id);

        sleep(1);
        goto menu1;
    }
    else if (pilihan == 2)
    {
        int cari;

        cout << "Masukkan id Data yang ingin diubah : ";
        cin >> cari;

        editp(cari);
        sleep(1);
        goto menu1;
    }
    else if (pilihan == 3)
    {
        int cari;

        cout << "Masukkan id data yang ingin dihapus : ";
        cin >> cari;

        hapusp(cari);
        sleep(1);
        goto menu1;
    }
    else if (pilihan == 0)
    {
        return;
    }
    else
    {
        cout << "Harap pilih pilihan yang tersedia." << endl;
        sleep(1);
        goto menu1;
    }
}

// Submenu 2 (Rekening Tujuan)
void menu2(int pilih)
{
menu2:
    system("cls");
    int pilihan;
    cout << "=========================================" << endl;
    cout << "       >> Sub-Menu Rekening Tujuan <<    " << endl;
    cout << "=========================================" << endl;
    cout << '\n';
    cout << "BCA : " << endl;
    tampil_BCA();
    cout << '\n';
    cout << "BNI : " << endl;
    tampil_BNI();
    cout << '\n';
    cout << "MANDIRI : " << endl;
    tampil_Mandiri();
    cout << "\n1. Tambah Rekening" << endl;
    cout << "2. Hapus Rekening" << endl;
    cout << "0. Kembali" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        cout << "Harap pilih method yang ingin ditambahkan (Masukkan nomor metode): ";
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
            tambahBNI();
            sleep(1);
            goto menu2;
        }
        else if (p == 3)
        {
            tambahMandiri();
            sleep(1);
            goto menu2;
        }
        else if (p == 0)
        {
            return;
        }
        else
        {
            cout << "Harap pilih sesuai pilihan yang ada." << endl;
            sleep(1);
            goto menu2;
        }

        break;
    case 2:
        int m;
        cout << "Method mana yang ingin dihapus rekeningnya (nomor) : ";
        cin >> m;
        if (m == 1)
        {
            tampil_BCA();
            cout << endl;
            int carir;
            cout << "Pilih nomor data yang ingin dihapus : ";
            cin >> carir;
            hapusbca(carir);
            cout << "Data berhasil dihapus." << endl;
            sleep(1);
            goto menu2;
        }
        else if (m == 2)
        {
            tampil_BNI();
            cout << endl;
            int carir;
            cout << "Pilih nomor data yang ingin dihapus : ";
            cin >> carir;
            hapusBNI(carir);
            cout << "Data berhasil dihapus." << endl;
            sleep(1);
            goto menu2;
        }
        else if (m == 3)
        {
            tampil_Mandiri();
            cout << endl;
            int carir;
            cout << "Pilih nomor data yang ingin dihapus : ";
            cin >> carir;
            hapusMandiri(carir);
            cout << "Data berhasil dihapus." << endl;
            sleep(1);
            goto menu2;
        }

        break;
    default:
        cout << "Harap pilih sesuai pilihan." << endl;
        sleep(1);
        break;
    }
}

// Menu Admin
void menu_admin()
{
    int pilih;
    do
    {
        system("cls");
        cout << "===================================" << endl;
        cout << "           Menu Admin ARRZ         " << endl;
        cout << "===================================" << endl;
        cout << "1. Edit e-wallet" << endl;
        cout << "2. Edit Rekening" << endl;
        cout << "3. Lihat Pesanan" << endl;
        cout << "4. Lihat User" << endl;
        cout << "0. Logout" << endl;
        cout << "-----------------------------------" << endl;
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
            tampilo(-1);
            cout << endl;
            system("pause");
        }
        else if (pilih == 4)
        {
            tampil_user();
            system("pause");
        }
    } while (pilih != 0);
}

// Menu User
void menu_user()
{
awalu:
    int pilihu;
    int pil;
    bool isLogin = false;

    int currentIdUser = -1;

    while (!isLogin)
    {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pil;
        if (pil == 1)
        {
            currentIdUser = reg();
            isLogin = true;
        }
        else if (pil == 2)
        {
            currentIdUser = log();
            if (currentIdUser != -1)
            {
                cout << "Berhasil Login." << endl;
                isLogin = true;
            }
            else
            {
                cout << "Login Gagal." << endl;
            }
        }
        else if (pil == 0)
        {
            return;
        }
        else
        {
            cout << "Harap Masukkan sesuai pilihan." << endl;
        }
    }

    do
    {
        system("cls");
        cout << "==============================================" << endl;
        cout << "  ===== Selamat Datang di Counter ARRZ =====  " << endl;
        cout << "==============================================" << endl;
        cout << "e-wallet Yang Tersedia : " << endl;
        cout << '\n';
        read();
        display();
        cout << '\n';
        cout << "1. Beli e-wallet" << endl;
        cout << "2. Cek Keranjang" << endl;
        cout << "3. Bayar" << endl;
        cout << "4. Lihat Pesanan" << endl;
        cout << "0. Keluar" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Masukkan Pilihan Anda : ";
        cin >> pilihu;

        switch (pilihu)
        {
        case 1:
            int carip;
            cout << "Masukkan Nomor Item : ";
            cin >> carip;
            tambahk(carip, currentIdUser);
            sleep(1);
            break;

        case 2:
            tampilk(currentIdUser);
            cout << endl;
            cout << "1. Hapus Item (LIFO)" << endl;
            cout << "0. Kembali" << endl;
            cout << "Masukkan Pilihan : ";
            int pilk;
            cin >> pilk;
            if (pilk == 1)
            {
                hapusk();
            }
            else if (pilk == 0)
            {
                break;
            }
            else
            {
                cout << "Harap pilih menu yang tersedia." << endl;
            }
            break;

        case 3:
            int pilihm;
            cout << "Pilih Metode Pembayaran : " << endl;
            cout << "1. BCA" << endl;
            cout << "2. BNI" << endl;
            cout << "3. MANDIRI" << endl;
            cout << "Masukkan pilihan anda : ";
            cin >> pilihm;

            if (pilihm == 1)
            {
                tampil_BCA();
                tambaho(currentIdUser);
                saveToFile();
            }
            else if (pilihm == 2)
            {
                tampil_BNI();
                tambaho(currentIdUser);
                saveToFile();
            }
            else if (pilihm == 3)
            {
                tampil_Mandiri();
                tambaho(currentIdUser);
                saveToFile();
            }
            break;
        case 4:
            tampilo(currentIdUser);
            cout << endl;
            cout << "1. Batalkan Pesanan (FIFO)" << endl;
            cout << "0. Kembali" << endl;
            cout << "Masukkan Pilihan : ";
            int pilo;
            cin >> pilo;
            if (pilo == 1)
            {
                hapuso();
                saveToFile();
            }
            else if (pilo == 0)
            {
                break;
            }
            else
            {
                cout << "Harap pilih menu yang tersedia." << endl;
            }
            break;

        default:
            cout << "Harap pilih sesuai pilihan." << endl;
            break;
        }
    } while (pilihu != 0);
}

// Login Admin
void admin()
{
    string username = "arrz";
    string password = "123";
    string user;
    string pass;
    cout << "\n===================================" << endl;
    cout << "             Admin ARRZ            " << endl;
    cout << "===================================" << endl;
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
awal:
    system("cls");
    int pilih;
    cout << "===================================" << endl;
    cout << "        >> E-Counter ARRZ <<       " << endl;
    cout << "===================================" << endl;
    cout << "Login Sebagai: " << endl;
    cout << "1. Admin\n2. User" << endl;
    cout << "-----------------------------------" << endl;
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