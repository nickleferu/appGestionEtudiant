#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Etudiant {
    char matricule[20];
    char nom[50];
    char prenom[50];
    char sexe[10];
    int age;
    float note1, note2, note3;
    struct Etudiant *suivant;
} Etudiant;


void ajouter_etudiant(Etudiant **liste, char *matricule, char *nom, char *prenom, char *sexe, int age, float note1, float note2, float note3) {
    Etudiant *nouvel_etudiant = malloc(sizeof(Etudiant));
    strcpy(nouvel_etudiant->matricule, matricule);
    strcpy(nouvel_etudiant->nom, nom);
    strcpy(nouvel_etudiant->prenom, prenom);
    strcpy(nouvel_etudiant->sexe, sexe);
    nouvel_etudiant->age = age;
    nouvel_etudiant->note1 = note1;
    nouvel_etudiant->note2 = note2;
    nouvel_etudiant->note3 = note3;
    nouvel_etudiant->suivant = *liste;
    *liste = nouvel_etudiant;
}


void mettre_a_jour_etudiant(Etudiant *liste, char *matricule, float nouvelle_note1, float nouvelle_note2, float nouvelle_note3) {
    Etudiant *etudiant_actuel = liste;
    while (etudiant_actuel != NULL) {
        if (strcmp(etudiant_actuel->matricule, matricule) == 0) {
            etudiant_actuel->note1 = nouvelle_note1;
            etudiant_actuel->note2 = nouvelle_note2;
            etudiant_actuel->note3 = nouvelle_note3;
            return;
        }
        etudiant_actuel = etudiant_actuel->suivant;
    }
}


void supprimer_etudiant(Etudiant **liste, char *matricule) {
    Etudiant *etudiant_actuel = *liste;
    Etudiant *etudiant_precedent = NULL;
    while (etudiant_actuel != NULL) {
        if (strcmp(etudiant_actuel->matricule, matricule) == 0) {
            if (etudiant_precedent == NULL) {
                *liste = etudiant_actuel->suivant;
            } else {
                etudiant_precedent->suivant = etudiant_actuel->suivant;
            }
            free(etudiant_actuel);
            return;
        }
        etudiant_precedent = etudiant_actuel;
        etudiant_actuel = etudiant_actuel->suivant;
    }
}


void afficher_etudiants(Etudiant *liste) {
    Etudiant *etudiant_actuel = liste;
    while (etudiant_actuel != NULL) {
        printf("Matricule : %s\n", etudiant_actuel->matricule);
        printf("Nom : %s\n", etudiant_actuel->nom);
        printf("Prénom : %s\n", etudiant_actuel->prenom);
        printf("Sexe : %s\n", etudiant_actuel->sexe);
        printf("Âge : %d\n", etudiant_actuel->age);
        printf("Note 1 : %.2f\n", etudiant_actuel->note1);
        printf("Note 2 : %.2f\n", etudiant_actuel->note2);
        printf("Note 3 : %.2f\n", etudiant_actuel->note3);
        printf("\n");
        etudiant_actuel = etudiant_actuel->suivant;
    }
}

int main() {
    Etudiant *liste_etudiants = NULL;
    int choix;
    do {
        printf("Menu :\n");
        printf("1 - Ajouter un étudiant\n");
        printf("2 - Mettre à jour un étudiant\n");
        printf("3 - Supprimer un étudiant\n");
        printf("4 - Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
            
                break;
            case 2:
            
                break;
            case 3:
                
                break;
            case 4:

                break;
            default:
                printf("Choix invalide !\n");
        }
    } while (choix != 4);
    return 0;
}
