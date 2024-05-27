#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

const int max_data = 99;

// ?? ??? ???? ????? LINKED LIST ????? ???? ??? ?? //

// Linked List Pulsa
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
    }
}

// Ya masa gatau
void tampil_pulsa_admin()
{
    if (kosong() == true)
    {
        cout << "Tidak ada data." << endl;
    }
    else
    {
        current = head;
        do
        {
            cout << "Data : " << current->name << endl;
            cout << "Harga : " << current->price << endl;
            cout << "Id : " << current->id << endl;
            current = current->next;
            cout << endl;
        } while (current != head);
    }
}

// Ya masa gatau
void tampil_pulsa()
{
    if (kosong() == true)
    {
        cout << "Tidak ada data." << endl;
    }
    else
    {
        int count = 1;
        current = head;
        do
        {
            cout << count << ". " << "Data : " << current->name << " Harga : " << current->price << endl;
            current = current->next;
            count++;
        } while (current != head);
    }
}

// ?? ??? ???? ????? REKENING (ARRAY) ????? ???? ??? ?? //

string BCA[99] = {"1223456789 A/N RAKA ANDRIY SHEVCHENKO", "123456789 A/N P", "123456789 A/N Q"};
string GP[99] = {"1223456789 A/N RAKA ANDRIY SHEVCHENKO", "123456789 A/N P", "123456789 A/N Q"};
string DN[99] = {"1223456789 A/N RAKA ANDRIY SHEVCHENKO", "123456789 A/N P", "123456789 A/N Q"};

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
void tambahgp()
{
    string data;
    int i = countNonEmpty(GP);

    cout << "Masukkan nomor rekening baru dan A/N nya : " << endl;
    cin.ignore();
    getline(cin, data);
    GP[i] = data;

    cout << "Nomor rekening berhasil ditambahkan." << endl;
}

// Tambah Data
void tambahdn()
{
    string data;
    int i = countNonEmpty(DN);

    cout << "Masukkan nomor rekening baru dan A/N nya : " << endl;
    cin.ignore();
    getline(cin, data);
    DN[i] = data;

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
void hapusgp(int cari)
{
    int j = countNonEmpty(GP);
    for (int i = cari - 1; i < j; i++)
    {
        GP[i] = GP[i + 1];
    }
}

// Hapus Data
void hapusdn(int cari)
{
    int j = countNonEmpty(DN);
    for (int i = cari - 1; i < j; i++)
    {
        DN[i] = DN[i + 1];
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
void tampil_GP()
{
    int jGP = countNonEmpty(GP);
    for (int i = 0; i < jGP; i++)
    {
        cout << GP[i] << endl;
    }
}

// Masa gatau
void tampil_DN()
{
    int jDN = countNonEmpty(DN);
    for (int i = 0; i < jDN; i++)
    {
        cout << DN[i] << endl;
    }
}

// ?? ??? ???? ????? KERANJANG (STACK) ????? ???? ??? ?? //

int total = 0;

// Struct Keranjang
struct Keranjang
{
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

void tambahk(int cari)
{
    wanted = head;
    while (wanted != NULL && wanted->id != cari)
    {
        wanted = wanted->next;
    }

    if (wanted == NULL)
    {
        cout << "Data tidak ditemukan." << endl;
    }
    else if (!fullk())
    {
        cart.atas++;
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
        cart.atas--;
    }
    else
    {
        cout << "Data Kosong." << endl;
    }
}

void tampilk()
{
    cout << "Isi Keranjang Anda : " << endl;
    if (!kosongk())
    {
        int count = 1;
        for (int i = cart.atas; i >= 0; i--)
        {
            cout << count << ". " << cart.nama_data[i] << "\t" << cart.harga_produk[i] << endl;
            count++;
        }
        cout << "\nTotal Belanjaanmu : " << total << endl;
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
    string nama_pesanan[max_data];
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
    if (order.belakang == max_data - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Nomor Telepon Pembeli
intptr_t nom;

// Tambah data pesanan
void tambaho()
{
    if (kosongo() == 1)
    {
        order.depan = order.belakang = 0;
        for (int i = cart.atas; i > -1; i--)
        {
            order.nama_pesanan[order.belakang] = cart.nama_data[i];
            order.belakang++;
            cart.atas--;
        }
    }
    else
    {
        if (fullo() == 0)
        {
            order.depan = order.belakang = 0;
            for (int i = cart.atas; i > -1; i--)
            {
                order.nama_pesanan[order.belakang] = cart.nama_data[i];
                order.belakang++;
                cart.atas--;
            }
        }
    }
    cout << "\n\nHarap Transfer ke salah satu rekening saja." << endl;
    cout << "Harap masukkan nomor tujuan : ";
    cin >> nom;
    cout << "\nTerima Kasih Telah Membeli Produk Kami." << endl;
    system("pause");
}

void tampilo()
{
    if (kosongo() == 0)
    {
        cout << "Daftar Pesanan : " << endl;
        int count = 1;
        for (int i = order.depan; i < order.belakang; i++)
        {
            cout << count << ". " << order.nama_pesanan[i] << " Nomor Pembeli : " << nom << endl;
            count++;
        }
    }
    else
    {
        cout << "Tidak ada pesanan. " << endl;
    }
}
