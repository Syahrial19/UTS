#ifndef PANEN_H
#define PANEN_H

#include <string>
using namespace std;

struct Panen {
    string namaTanaman;
    string bulan;
    int jumlah;
};

typedef struct ElmList* address;

struct ElmList {
    Panen info;
    address next;
};

struct List {
    address first;
};

/* fungsi & prosedur */
void createList(List &L);
address createNewElm(Panen x);
void tambahData(List &L, Panen x);
address panenTerbanyak(List L);
void panenBulanan(List L, string bulanCari);
void tampilkanList(List L);

#endif
