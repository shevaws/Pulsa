#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

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

// function protypes
void menu();
void read();
void display_students();

// Baca data dari .txt
void read()
{
    head = tail = NULL;                  // inisialisasi
    string filename("Data.txt");         // Inisialisasi Nama File
    ifstream inFile(filename, ios::app); // Load dari file

    if (inFile.fail()) // Kalo file gabisa dibuka
    {
        cout << "File tidak dapat dibuka" << endl;
        cout << "Harap cek file dengan benar." << endl;
        exit(1);
    }

    while (true) // Kalo bisa
    {
        // Proses buat node baru
        current = new Item;
        current->next = NULL;
        // Masukin data dari .txt ke node baru
        getline(inFile, current->name);
        inFile >> current->price;
        inFile >> current->id;

        // Kalo gabisa
        if (inFile.fail())
        {
            delete current; // hapus data
            break;
        }

        // Masukin data ke LL
        if (head == NULL) // Kalo data pertama
        {
            head = current;
        }
        else // Kalo bukan data pertama
        {
            tail->next = current;
        }
        tail = current; // Ya gitulah jir
    }
    inFile.close(); // Kalo uda ya tutup filenya'
}

// Menampilkan datanya
void display()
{
    Item *ptr;
    ptr = head;
    while (ptr != NULL) {
        cout << "Nama Data : " << ptr->name << endl;
        cout << "Harga : " << ptr->price << endl;
        cout << "Id : " << ptr->id << endl;
        ptr = ptr->next;
    }
}

int
main()
{
    read();
    cout << "The linked list is: " << endl;
    display();
    return 0;
}