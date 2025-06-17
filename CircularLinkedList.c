#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Film {
    char judul[100];
    int tahun;
    struct Film *next;
};

void tambahFilm(struct Film **head, char judul[], int tahun) {
    struct Film *baru = (struct Film*)malloc(sizeof(struct Film));
    strcpy(baru->judul, judul);
    baru->tahun = tahun;
    baru->next = NULL;

    if (*head == NULL) {
        *head = baru;
        (*head)->next = *head; 
    } else {
        struct Film *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = baru;
        baru->next = *head; 
    }
}

void tampilkanDaftar(struct Film *head) {
    if (head == NULL) {
        printf("Daftar film kosong.\n");
        return;
    }
    printf("Daftar Film:\n");
    struct Film *temp = head;
    do {
        printf("Judul: %s, Tahun: %d\n", temp->judul, temp->tahun);
        temp = temp->next;
    } while (temp != head);
}

void hapusSemua(struct Film **head) {
    if (*head == NULL)
        return;
    struct Film *temp = *head;
    struct Film *hapus;
    do {
        hapus = temp;
        temp = temp->next;
        free(hapus);
    } while (temp != *head);
    *head = NULL;
}

int main() {
    struct Film *daftarFilm = NULL;

    tambahFilm(&daftarFilm, "Interstellar", 2014);
    tambahFilm(&daftarFilm, "The wolf of wall street", 2014);
    tambahFilm(&daftarFilm, "The Dark Knight", 2008);
    tambahFilm(&daftarFilm, "The good the bad and the ugly", 1966);
    tambahFilm(&daftarFilm, "Dune part two", 2024);

    tampilkanDaftar(daftarFilm);

    hapusSemua(&daftarFilm);

    return 0;
}
