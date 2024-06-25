#include <iostream>
#include <string>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int max_data = 99;

// ?? ??? ???? ????? LINKED LIST ????? ???? ??? ?? //

// Function Prototype
void edittxt();

// Linked List Pulsadf
struct Item
{
    string name;
    int price;
    int id;
    Item *next;
    Item *prev;
};

// Defined? apa namanya gatau pokoknya bikin variabel
Item *head;
Item *tail;
Item *pulsa;
Item *current;
Item *wanted;

// Buat Node Baru
void buat_pulsa(string nama, int harga, int id)
{
    pulsa = new Item;
    pulsa->name = nama;
    pulsa->price = harga;
    pulsa->id = id;
    pulsa->next = NULL;
    pulsa->prev = NULL;
}

// Inisialisasi
void inisialisasi_pulsa()
{
    head == NULL;
    tail == NULL;
}

// var isEmpty
bool kosong()
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Buat Jadiin CDLL gitu? gatau juga kalo sepemahamanku gt
void tambahp(string nama, int harga, int id)
{
    pulsa = nullptr;
    buat_pulsa(nama, harga, id);

    if (kosong())
    {
        head = pulsa;
        tail = pulsa;
    }
    else
    {
        tail->next = pulsa;
        pulsa->prev = tail;
        tail = pulsa;
    }

    tail->next = head;
    head->prev = tail;

    ofstream outfile("Data.txt", ios::app);

    if (!outfile)
    {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    if (head == NULL && tail == NULL)
    {
        outfile << "Tidak ada pesanan." << endl;
    }
    else
    {
        if (pulsa != nullptr)
        {

            outfile << pulsa->name << endl;
            outfile << pulsa->price << endl;
            outfile << pulsa->id << endl;
        }
    }

    outfile.close();
    if (!outfile.good())
    {
        cerr << "Error occurred during writing to file." << endl;
    }
}

// Edit Data
void editp(int cari)
{
    if (kosong())
    {
        cout << "Tidak ada data." << endl;
    }
    else
    {
        wanted = head;

        while (wanted->next != head && wanted->id != cari)
        {
            wanted = wanted->next;
        }

        if (wanted->id != cari)
        {
            cout << "Data tidak ada." << endl;
        }
        else
        {
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, wanted->name);
            cout << "Masukkan Harga : ";
            cin >> wanted->price;
            cout << "Masukkan Id : ";
            cin >> wanted->id;

            cout << "\nData Berhasil diUpdate." << endl;

            edittxt();
        }
    }
}

// Hapus Data
void hapusp(int cari)
{
    if (kosong())
    {
        cout << "Tidak ada data." << endl;
    }
    else
    {
        wanted = head;

        while (wanted->next != head && wanted->id != cari)
        {
            wanted = wanted->next;
        }

        if (wanted->id != cari)
        {
            cout << "Data tidak ada." << endl;
        }
        else if (wanted == head && wanted == tail)
        {
            head = tail = NULL;
            cout << "\nData berhasil dihapus. " << endl;
        }
        else
        {
            if (wanted == head)
            {
                head = wanted->next;
                tail->next = head;
                head->prev = tail;
            }
            else if (wanted == tail)
            {
                tail = wanted->prev;
                tail->next = head;
                head->prev = tail;
            }
            else
            {
                wanted->prev->next = wanted->next;
                wanted->next->prev = wanted->prev;
            }
            delete wanted;
            cout << "\nData berhasil dihapus. " << endl;
        }
        edittxt();
    }
}

// Ya masa gatau
// Menampilkan datanya
void display_admin()
{
    if (head == nullptr)
    {
        cout << "Tidak ada data." << endl;
        return;
    }

    Item *ptr;
    ptr = head;
    do
    {
        cout << "Nama Data : " << ptr->name << endl;
        cout << "Harga : " << ptr->price << endl;
        cout << "Id : " << ptr->id << endl;
        cout << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

// Menampilkan datanya
void display()
{
    if (head == nullptr)
    {
        cout << "No data to display." << endl;
        return;
    }

    Item *ptr;
    ptr = head;
    int count = 1;
    do
    {
        cout << count << ". ";
        cout << "Nama Data : " << ptr->name << endl;
        cout << "Harga : " << ptr->price << endl;
        cout << endl;
        ptr = ptr->next;
        count++;
    } while (ptr != head);
}

// ?? ??? ???? ????? REKENING (ARRAY) ????? ???? ??? ?? //

string BCA[99] = {"1223456789 A/N RAKA ANDRIY SHEVCHENKO", "123456789 A/N P", "123456789 A/N Q"};
string BNI[99] = {"1223456789 A/N RAKA ANDRIY SHEVCHENKO", "123456789 A/N P", "123456789 A/N Q"};
string Mandiri[99] = {"1223456789 A/N RAKA ANDRIY SHEVCHENKO", "123456789 A/N P", "123456789 A/N Q"};

// Ngitung Data
int countNonEmpty(const string arr[])
{
    int count = 0;
    while (arr[count] != "")
    {
        ++count;
    }
    return count;
}

// Tambah Data
void tambahbca()
{
    string data;
    int i = countNonEmpty(BCA);

    cout << "Masukkan nomor rekening baru dan A/N nya : " << endl;
    cin.ignore();
    getline(cin, data);
    BCA[i] = data;

    cout << "Nomor rekening berhasil ditambahkan." << endl;
}

// Tambah Data
void tambahBNI()
{
    string data;
    int i = countNonEmpty(BNI);

    cout << "Masukkan nomor rekening baru dan A/N nya : " << endl;
    cin.ignore();
    getline(cin, data);
    BNI[i] = data;

    cout << "Nomor rekening berhasil ditambahkan." << endl;
}

// Tambah Data
void tambahMandiri()
{
    string data;
    int i = countNonEmpty(Mandiri);

    cout << "Masukkan nomor rekening baru dan A/N nya : " << endl;
    cin.ignore();
    getline(cin, data);
    Mandiri[i] = data;

    cout << "Nomor rekening berhasil ditambahkan." << endl;
}

// Hapus Data
void hapusbca(int cari)
{
    int j = countNonEmpty(BCA);
    for (int i = cari - 1; i < j; i++)
    {
        BCA[i] = BCA[i + 1];
    }
}

// Hapus Data
void hapusBNI(int cari)
{
    int j = countNonEmpty(BNI);
    for (int i = cari - 1; i < j; i++)
    {
        BNI[i] = BNI[i + 1];
    }
}

// Hapus Data
void hapusMandiri(int cari)
{
    int j = countNonEmpty(Mandiri);
    for (int i = cari - 1; i < j; i++)
    {
        Mandiri[i] = Mandiri[i + 1];
    }
}

// Masa gatau
void tampil_BCA()
{
    int jBCA = countNonEmpty(BCA);
    for (int i = 0; i < jBCA; i++)
    {
        cout << BCA[i] << endl;
    }
}

// Masa gatau
void tampil_BNI()
{
    int jBNI = countNonEmpty(BNI);
    for (int i = 0; i < jBNI; i++)
    {
        cout << BNI[i] << endl;
    }
}

// Masa gatau
void tampil_Mandiri()
{
    int jMandiri = countNonEmpty(Mandiri);
    for (int i = 0; i < jMandiri; i++)
    {
        cout << Mandiri[i] << endl;
    }
}

// ?? ??? ???? ????? KERANJANG (STACK) ????? ???? ??? ?? //

int total = 0;

// Struct Keranjang
struct Keranjang
{
    int idUser[max_data];
    string nama_data[max_data];
    int harga_produk[max_data];
    int atas = -1;
};
Keranjang cart;

void inisialisasi_keranjang()
{
    head = NULL;
    tail = NULL;
}

bool kosongk()
{
    if (cart.atas == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool fullk()
{
    if (cart.atas == max_data - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void tambahk(int cari, int idUser)
{
    wanted = head;
    do
    {
        if (wanted->id == cari)
        {
            break;
        }
        wanted = wanted->next;
    } while (wanted != head);

    if (wanted == NULL || wanted->id != cari)
    {
        cout << "Data tidak ditemukan." << endl;
    }
    else if (!fullk())
    {
        cart.atas++;
        cart.idUser[cart.atas] = idUser;
        cart.nama_data[cart.atas] = wanted->name;
        cart.harga_produk[cart.atas] = wanted->price;
        total += cart.harga_produk[cart.atas];

        cout << "Data telah ditambahkan ke keranjang." << endl;
    }
}

void hapusk()
{
    if (!kosongk())
    {
        cout << "Data berhasil dihapus." << endl;
        total -= cart.harga_produk[cart.atas];
        cart.atas--;
    }
    else
    {
        cout << "Data Kosong." << endl;
    }
}

void tampilk(int idUser)
{
    cout << "Isi Keranjang Anda : " << endl;
    if (!kosongk())
    {
        int count = 1;
        bool found = false;
        for (int i = cart.atas; i >= 0; i--)
        {
            if (idUser == -1 || cart.idUser[i] == idUser)
            {
                cout << count << ". " << cart.nama_data[i] << "\t" << cart.harga_produk[i] << endl;
                count++;
                found = true;
            }
        }
        if (found)
        {
            cout << "\nTotal Belanjaanmu : " << total << endl;
        }
        else
        {
            cout << "Keranjangmu masih kosong nih" << endl;
        }
    }
    else
    {
        cout << "Keranjangmu masih kosong nih" << endl;
    }
}

// ?? ??? ???? ????? PESANAN (QUEUE) ????? ???? ??? ?? //

// Struct Pesanan
struct Pesanan
{
    int idUser[max_data];
    string nama_pesanan[max_data];
    long long int nom[max_data];
    int depan = -1;
    int belakang = -1;
};
Pesanan order;

// Iya
void inisialisasi_order()
{
    head = NULL;
    tail = NULL;
}

// If kosong
bool kosongo()
{
    if (order.belakang == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// If full
bool fullo()
{
    if ((order.belakang + 1) % max_data == order.depan)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Tambah data pesanan
void tambaho(int idUser)
{
    if (kosongo())
    {
        order.depan = 0;
        order.belakang = 0;
    }
    else if (fullo())
    {
        cout << "Order queue is full!" << endl;
        return;
    }
    else
    {
        order.belakang++;
    }

    while (cart.atas >= 0)
    {
        order.nama_pesanan[order.belakang] = cart.nama_data[cart.atas];
        cart.atas--;

        if (cart.atas >= 0)
        {
            order.belakang++;
        }
    }

    order.idUser[order.belakang] = idUser;
    cout << "\n\nHarap Transfer ke salah satu rekening saja." << endl;
    cout << "Harap masukkan nomor tujuan: ";
    cin >> order.nom[order.belakang];
    cout << "\nTerima Kasih Telah Membeli Produk Kami." << endl;
    system("pause");
}

void hapuso()
{
    if (!kosongo())
    {
        for (int i = order.depan; i < order.belakang; i++)
        {
            order.idUser[i] = order.idUser[i + 1];
            order.nama_pesanan[i] = order.nama_pesanan[i + 1];
            order.nom[i] = order.nom[i + 1];
        }
        order.belakang--;
    }
}

// Ya gitu
void tampilo(int idUser)
{
    if (kosongo() == 0)
    {
        int i = order.depan;
        bool found = false;
        for (i; i <= order.belakang; i++)
        {
            if (idUser == -1 || order.idUser[i] == idUser)
            {
                cout << order.nama_pesanan[i] << " Nomor Tujuan : " << order.nom[i] << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "Tidak ada pesanan. " << endl;
        }
    }
    else
    {
        cout << "Tidak ada pesanan. " << endl;
    }
}

// Save Orderan ke File .txt
void saveToFile()
{
    ofstream outfile("Orderan.txt");

    if (!outfile)
    {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    if (order.belakang == -1)
    {
        outfile << "Tidak ada pesanan." << endl;
    }
    else
    {
        int i = order.depan;
        for (i; i <= order.belakang; i++)
        {
            outfile << "-------------------------" << endl;
            outfile << "Id User: " << order.idUser[i] << endl;
            outfile << "Nama Item: " << order.nama_pesanan[i] << endl;
            outfile << "Nomor Tujuan: " << order.nom[i] << endl;
            outfile << "-------------------------" << endl;
        }

        // do
        // {
        //     i = (i + 1) % max_data;
        // } while (i != (order.belakang + 1) % max_data);
    }

    outfile.close();
    if (!outfile.good())
    {
        cerr << "Error occurred during writing to file." << endl;
    }
}

// Edit data .txt
void edito()
{
    ofstream outFile("Orderan.txt");
    if (!outFile)
    {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    Item *ptr = head;
    if (ptr != nullptr)
    {
        do
        {
            outFile << ptr->name << endl;
            outFile << ptr->price << endl;
            outFile << ptr->id << endl;
            ptr = ptr->next;
        } while (ptr != head);
    }
    outFile.close();
}

// Baca data dari .txt
void read()
{
    head = tail = NULL;          // inisialisasi
    string filename("Data.txt"); // Inisialisasi Nama File
    ifstream inFile(filename);   // Load dari file

    if (inFile.fail()) // Kalo file gabisa dibuka
    {
        cout << "File tidak dapat dibuka" << endl;
        cout << "Harap cek file dengan benar." << endl;
        exit(1);
    }

    string line;
    while (getline(inFile, line)) // Kalo bisa
    {
        // Proses buat node baru
        current = new Item;
        current->next = NULL;
        current->prev = NULL;

        current->name = line;
        // Read the price
        if (!getline(inFile, line))
        {
            delete current;
            break;
        }
        current->price = stoi(line);

        // Read the id
        if (!getline(inFile, line))
        {
            delete current;
            break;
        }
        current->id = stoi(line);

        // Masukin data ke LL
        if (head == NULL) // Kalo data pertama
        {
            head = current;
            tail = current;
        }
        else // Kalo bukan data pertama
        {
            tail->next = current;
            current->prev = tail;
            tail = current;
        }
        tail = current; // Ya gitulah jir
    }
    inFile.close(); // Kalo uda ya tutup filenya

    if (head != nullptr && tail != nullptr)
    {
        tail->next = head;
        head->prev = tail;
    }
}

// Edit data .txt
void edittxt()
{
    ofstream outFile("Data.txt");
    if (!outFile)
    {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    Item *ptr = head;
    if (ptr != nullptr)
    {
        do
        {
            outFile << ptr->name << endl;
            outFile << ptr->price << endl;
            outFile << ptr->id << endl;
            ptr = ptr->next;
        } while (ptr != head);
    }
    outFile.close();
}

// ?? ??? ???? ????? User (Hashtable) ????? ???? ??? ?? //

void ec(string &pw);

const int max_user = 99;
struct User
{
    int idUser;
    string uname;
    string pw;
} user[max_user];

int jumlah_user = 0;

int reg()
{
    cout << "==========\t USER \t ==========" << endl;
    cout << "Masukkan Username (No space, symbol, etc.) : ";
    cin >> user[jumlah_user].uname;
    cout << "Masukkan Password : ";
    cin >> user[jumlah_user].pw;
    user[jumlah_user].idUser = jumlah_user;

    return jumlah_user++;
}

int log()
{
    string un;
    string pws;
    cout << "Masukkan Username : ";
    cin >> un;
    cout << "Masukkan Password : ";
    cin >> pws;
    for (int i = 0; i <= jumlah_user; i++)
    {
        if (un == user[i].uname && pws == user[i].pw)
        {
            return i;
        }
    }
    return -1;
}

void tampil_user()
{
    if (jumlah_user == 0)
    {
        cout << "Tidak ada user." << endl;
        return;
    }
    else
    {
        for (int i = 0; i < jumlah_user; i++)
        {
            string encrypted_pw = user[i].pw;
            ec(encrypted_pw);
            cout << "idUser : " << user[i].idUser << " Username : " << user[i].uname << " Passwword : " << encrypted_pw << endl;
        }
    }
}

void ec(string &pw)
{
    for (size_t i = 0; i < pw.length(); i++)
    {
        pw[i] = pw[i] + (rand() % 26);
    }
}