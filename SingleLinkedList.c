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
    } else {
        struct Film *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void tampilkanDaftar(struct Film *head) {
    if (head == NULL) {
        printf("Daftar film kosong.\n");
        return;
    }
    printf("Daftar Film:\n");
    while (head != NULL) {
        printf("Judul: %s, Tahun: %d\n", head->judul, head->tahun);
        head = head->next;
    }
}

void hapusSemua(struct Film **head) {
    struct Film *temp = *head;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
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
