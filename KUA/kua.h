#ifndef KUA_H_INCLUDED
#define KUA_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define up(P) P->up
#define down(P) P->down
#define info(P) P->info
#define first(L) (L).first
#define last(L) (L).last

struct ttl {
    int tgl,bln,thn;
    string tempat;
};

struct infotype {
    long nik,status;
    string nama,pekerjaan,alamat;
    ttl lahir;
};

typedef struct elmlist *address;
typedef struct elmlist_r *address_r;

struct elmlist{
    infotype info;
    address next;
    address prev;
};

struct elmlist_r{
    address_r next;
    address_r prev;
    address up;
    address down;
};

struct List {
    address first;
    address last;
};

struct List_r {
    address_r first;
    address_r last;
};

/* Manajemen Memory */
address alokasi(infotype x);
address_r alokasi_r(address x, address y);
void dealokasi(address P);
void dealokasi_r(address_r P);

/* Proses Pada Semua List */
address findElm(List L, infotype x);
address_r findElm_rs(List_r L, address X);
address findElm_ri(List_r L, address Y);
void printInfo(List L, address P);
infotype insertInfo();
void sorting(List &L, infotype x);

/* Pembuatan List */
void createList(List &L);
void createList_r(List_r &L);

/* Penambahan Elemen */
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address Prec);

void insertFirst_r(List_r &L, address_r P);
void insertLast_r(List_r &L, address_r P);
void insertAfter_r(List_r &L, address_r P, address_r Prec);

/* Penghapusan Elemen */
void delFirst(List &L, address &P);
void delLast(List &L, address &P);
void delAfter(List &L, address &P, address Prec);

void delFirst_r(List_r &L, address_r &P);
void delLast_r(List_r &L, address_r &P);
void delAfter_r(List_r &L, address_r &P, address_r Prec);

void delData(List &L, address &P);
void delData_r(List_r &L, address_r &P);

void editList(List &L, address P);
void tukar(List &L, address P, address Q);

void sortAs_nik(List L);
void sortDes_nik(List L);
void sortAs_usia(List L);
void sortDes_usia(List L);

#endif // KUA_H_INCLUDED
