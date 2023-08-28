#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

// Gregory Wilson Wijaya 210711167
// William Ongky Wijaya 210711141
// Samuel Juang 210711201
// Maureen Violetta Setiawan 210711194

typedef char string[50];
typedef struct NodeChild* AddressChild;
typedef struct NodeParent* AddressParent;
typedef struct Node* Address;

typedef struct{
    int idDokter;
    string namaDokter;
    string tanggalBergabung;
    string usernameDok;
    string passwordDok;
}DataP;

typedef struct{
    int idHewan;
    string tanggal;
    string diagnosa;
    string obat;
    int id_riwayat;
}DataC;

typedef struct{
    int idHewan;
    string namaHewan;
    string tanggalLahir;
    string jenisHewan;
    string jenisKelamin;
}DataH;

typedef struct NodeChild{
	DataC dataChild;
	AddressChild next;
}NodeChild;

typedef struct NodeParent{
	DataP dataParent;
	AddressParent next;
	AddressChild firstChild;
}NodeParent;

typedef struct{
	AddressParent firstParent;
}Multilist;

typedef struct Node{
    DataH dataHewan;
    Address next;
}Node;

typedef struct{
    Address first;
}List;

//header tampilan
void movingText();
void printMenu();
void repeatingText();
void printXb();
void gotoxy(int x, int y);
int tampilAdmin(int menuKelola);
int readPassword(char *pass, int length);
int readLine(char* str);
void red();
void white();
void yellow();
void green();
void blue();
void cyan();
int tampilAdmin2(int menuKelola2);
int tampilMenuHewan(int menuKelola);
int tampilMenuDokter (int menuKelola, int count);
void kotak();
void kotakAwal();


//header multilist
void createEmpty(Multilist *l); 
AddressChild alokasiChild(DataC data);
AddressParent alokasiParent(DataP data);
bool isEmpty(Multilist l);
bool isUnikParent(Multilist l, DataP DP);
bool isUnikChild(Multilist l, DataC DC);
bool haveChild(AddressParent ap);
void insertFirstParent(Multilist *l, AddressParent newNode);
AddressParent findDokter(Multilist L, DataP DP);
void insertFirstChild(Multilist l, DataP idDokter, DataC data);
void printOne(Multilist l, AddressParent p);
void printDokter(Multilist l);
void editData(AddressParent oldNode, DataP DP);
void deleteFirst(Multilist *l);
void deleteAt(Multilist *l, AddressParent hapus);
void printHewanRiw(Multilist l, List Hewan, int idHew);
void printAllHewan(Multilist l, List Hewan);
void printRiwayat(AddressParent ap, List hewan, int *count);
void printBelumDiag(AddressParent ap, List hewan, int *count);
AddressChild isFoundChild(Multilist L,int id);
AddressChild isFoundChildInParent(AddressParent p,int id);
void deleteFirstChild(AddressParent l, int id);
bool isUniqueChild(int id, Multilist l);
void deleteAtChild(AddressParent *AP, int id);
void deleteAllChild(AddressParent parent);
AddressParent findUsername(Multilist l, string username);
AddressParent findDokterNama(string username, Multilist M);

// header linked list
void createEmptyList(List *L);
bool isEmptyList(List L);
Address alokasi(DataH data);
void insertFirstList(List *L, Address newNode);
void insertLastList(List *L, Address newNode);
void insertAfter(Address before, Address newNode);
Address findLastAnjing(List l);
Address findLastBurung(List l);
void insertBinatang(List *L,DataH hewan);
void deleteFirstHewan(List *L);
void deleteAtHewan(List *L, int id, Multilist *M);
void printHewan(List L);
Address isFoundHewanID(List L, int id);

