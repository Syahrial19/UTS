#include "panen.h"
#include <iostream>

void createList(List &L) {
    L.first = NULL;
}

address createNewElm(Panen x) {
    address p = new ElmList;
    p->info = x;
    p->next = NULL;
    return p;
}

void tambahData(List &L, Panen x) {
    address p = createNewElm(x);
    p->next = L.first;
    L.first = p;
}

address panenTerbanyak(List L) {
    if (L.first == NULL) return NULL;

    address max = L.first;
    address p = L.first->next;

    while (p != NULL) {
        if (p->info.jumlah > max->info.jumlah) {
            max = p;
        }
        p = p->next;
    }
    return max;
}

void panenBulanan(List L, string bulanCari) {
    address p = L.first;
    bool ketemu = false;

    while (p != NULL) {
        if (p->info.bulan == bulanCari) {
            cout << p->info.namaTanaman << " ";
            ketemu = true;
        }
        p = p->next;
    }

    if (!ketemu) {
        cout << "Tidak ada data";
    }
    cout << endl;
}

void tampilkanList(List L) {
    address p = L.first;
    int i = 1;

    if (p == NULL) {
        cout << "List kosong\n";
        return;
    }

    while (p != NULL) {
        cout << i++ << ". "
             << p->info.namaTanaman << " | "
             << p->info.bulan << " | "
             << p->info.jumlah << " kg\n";
        p = p->next;
    }
}
