#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CAISSES 10

void caisse(int id, int nb_places, int* places_restantes) {
    int places_vendues = 0;
    srand(time(NULL) + id);
    while (*places_restantes > 0) {
        int nb_places_a_vendre = rand() % 7 + 1;
        if (nb_places_a_vendre > *places_restantes) {
            nb_places_a_vendre = *places_restantes;
        }
        usleep((rand() % 3000 + 1000) * 1000);
        places_vendues += nb_places_a_vendre;
        *places_restantes -= nb_places_a_vendre;
        printf("Caisse %d : vendu %d places, restantes %d\n", id, nb_places_a_vendre, *places_restantes);
    }
    printf("Caisse %d : plus de places disponibles, fermeture\n", id);
    exit(0);
}

void afficheur(int nb_caisses, char* titre, int* places_restantes) {
    while (*places_restantes > 0) {
        printf("%s : %d places restantes\n", titre, *places_restantes);
        sleep(5);
    }
    printf("%s : toutes les places ont été vendues\n", titre);
    int i;
    for (i = 0; i < nb_caisses; i++) {
        wait(NULL);
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage : %s nb_caisses titre nb_places\n", argv[0]);
        exit(1);
    }
    int nb_caisses = atoi(argv[1]);
    char* titre = argv[2];
    int nb_places = atoi(argv[3]);
    int places_restantes = nb_places;
    pid_t pid[MAX_CAISSES];
    int i;
    for (i = 0; i < nb_caisses; i++) {
        pid[i] = fork();
        if (pid[i] == -1) {
            printf("Erreur de fork()\n");
            exit(1);
        }
        else if (pid[i] == 0) {
            caisse(i, nb_places, &places_restantes);
        }
    }
    afficheur(nb_caisses, titre, &places_restantes);
    return 0;
}
