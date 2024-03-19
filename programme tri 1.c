#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5000

// Function prototypes
void afficherMenu();
int lireNombresDepuisFichier(const char *nomFichier, int tableau[]);
void generateRandomNumbersToFile(const char *fileName, int numNumbers);
void ecrireNombresDansFichier(const char *nomFichier, int tableau[], int taille);
void triSimple(int tableau[], int taille);
void triSelection(int tableau[], int taille);
void triBulle(int tableau[], int taille);
void triInsertion(int tableau[], int taille);
void triRapide(int tableau[], int debut, int fin);
void triFusion(int tableau[], int debut, int fin);
void tourDeHanoi(int n, char depart, char auxiliaire, char destination);
double calculerTempsExecution(clock_t debut, clock_t fin);

int main() {
    int nombres[MAX_SIZE];
    int taille = 0;
    char nomFichier[100]; // Assuming maximum file name length of 100 characters

    // Display the menu
    int choix;
    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("\n");
                printf("**************************************************\n");
                printf("Creation de fichier avec des nombres aleatoires...\n");
                printf("Entrez le nombre de nombres aleatoires a generer : ");
                int numNumbers;
                scanf("%d", &numNumbers);
                generateRandomNumbersToFile("random_numbers.txt", numNumbers);
                printf("**************************************************\n");
                break;
            case 2:
                printf("\n");
                printf("**************************************************\n");
                printf("Entrez le nom du fichier (avec extension .txt) : ");
                scanf("%s", nomFichier);
                taille = lireNombresDepuisFichier(nomFichier, nombres);
                if (taille == -1) {
                    printf("Erreur lors de la lecture du fichier.\n");
                    return 1;
                }
                printf("Fichier lu avec succes.\n");
                printf("**************************************************\n");
                break;
            case 3:
                printf("\n");
                printf("**************************************************\n");
                printf("Tri Simple en cours...\n");
                clock_t debutTS = clock();
                triSimple(nombres, taille);
                clock_t finTS = clock();
                ecrireNombresDansFichier("tri_simple.txt", nombres, taille);
                printf("Nombres tries enregistres dans tri_simple.txt\n");
                printf("Duree du tri simple : %.6f secondes\n", calculerTempsExecution(debutTS, finTS));
                printf("**************************************************\n");
                break;
            case 4:
                printf("\n");
                printf("**************************************************\n");
                printf("Tri par Selection en cours...\n");
                clock_t debutSS = clock();
                triSelection(nombres, taille);
                clock_t finSS = clock();
                ecrireNombresDansFichier("tri_par_selection.txt", nombres, taille);
                printf("Nombres tries enregistres dans tri_par_selection.txt\n");
                printf("Duree du tri par selection : %.6f secondes\n", calculerTempsExecution(debutSS, finSS));
                printf("**************************************************\n");
                break;
            case 5:
                printf("\n");
                printf("**************************************************\n");
                printf("Tri par Bulle en cours...\n");
                clock_t debutTB = clock();
                triBulle(nombres, taille);
                clock_t finTB = clock();
                ecrireNombresDansFichier("tri_par_bulle.txt", nombres, taille);
                printf("Nombres tries enregistres dans tri_par_bulle.txt\n");
                printf("Duree du tri par bulle : %.6f secondes\n", calculerTempsExecution(debutTB, finTB));
                printf("**************************************************\n");
                break;
            case 6:
                printf("\n");
                printf("**************************************************\n");
                printf("Tri par Insertion en cours...\n");
                clock_t debutTI = clock();
                triInsertion(nombres, taille);
                clock_t finTI = clock();
                ecrireNombresDansFichier("tri_par_insertion.txt", nombres, taille);
                printf("Nombres tries enregistres dans tri_par_insertion.txt\n");
                printf("Duree du tri par insertion : %.6f secondes\n", calculerTempsExecution(debutTI, finTI));
                printf("**************************************************\n");
                break;
            case 7:
                printf("\n");
                printf("**************************************************\n");
                printf("Tri Rapide en cours...\n");
                clock_t debutTR = clock();
                triRapide(nombres, 0, taille - 1);
                clock_t finTR = clock();
                ecrireNombresDansFichier("tri_rapide.txt", nombres, taille);
                printf("Nombres triés enregistres dans tri_rapide.txt\n");
                printf("Duree du tri rapide : %.6f secondes\n", calculerTempsExecution(debutTR, finTR));
                break;
            case 8:
                printf("\n");
                printf("Tri par Fusion en cours...\n");
                clock_t debutTF = clock();
                triFusion(nombres, 0, taille - 1);
                clock_t finTF = clock();
                ecrireNombresDansFichier("tri_par_fusion.txt", nombres, taille);
                printf("Nombres tries enregistres dans tri_par_fusion.txt\n");
                printf("Duree du tri par fusion : %.6f secondes\n", calculerTempsExecution(debutTF, finTF));
                printf("**************************************************\n");
                break;
            case 9:
                printf("\n");
                printf("**************************************************\n");
                printf("Algorithme de la Tour de Hanoi en cours...\n");
                printf("Entrez le nombre de disques : ");
                int n;
                scanf("%d", &n);
                printf("Instructions pour la Tour de Hanoi avec %d disques :\n", n);
                tourDeHanoi(n, 'A', 'C', 'B');
                printf("**************************************************\n");
                break;
            case 10:
                printf("\n");
                printf("**************************************************\n");
                printf("Exécution de tous les tris...\n");
                trierTousLesTris(nombres, taille);
                printf("**************************************************\n");
                break;
            case 11:
                printf("\n");
                printf("Quitter le programme.\n");
                break;
            default:
                printf("\n");
                printf("Choix invalide. Veuillez choisir une option valide.\n");
                break;
        }
    } while (choix != 9);

    return 0;
}

void afficherMenu() {
    printf("\n******** Menu: ********\n");
    printf("1. Generer un fichier text contenant des nombres aleatoires\n");
    printf("2. Entrer un fichier .txt\n");
    printf("3. Tri Simple\n");
    printf("4. Tri par Selection\n");
    printf("5. Tri par Bulle\n");
    printf("6. Tri par Insertion\n");
    printf("7. Tri Rapide (Quicksort)\n");
    printf("8. Tri par Fusion\n");
    printf("9. Algorithme de la Tour de Hanoi\n");
    printf("10. Faire Tout les tris et afficher les durees en ordre\n");
    printf("11. Quitter\n");
    printf("Choix : ");
}

int lireNombresDepuisFichier(const char *nomFichier, int tableau[]) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        return -1; // Error opening file
    }

    int nombre, taille = 0;
    while (fscanf(fichier, "%d", &nombre) != EOF && taille < MAX_SIZE) {
        tableau[taille++] = nombre;
    }

    fclose(fichier);
    return taille;
}

void generateRandomNumbersToFile(const char *fileName, int numNumbers) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Erreur\n");
        return;
    }

    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < numNumbers; ++i) {
        // Generate random positive integer numbers between 0 and 100000
        int randomNumber = rand() % 100001; // 100001 to include upper bound
        fprintf(file, "%d\n", randomNumber); // Write to file
    }

    fclose(file);
    printf("Fichier **** %s **** contenant des nombres aleatoires avec succes\n", fileName);
}

void ecrireNombresDansFichier(const char *nomFichier, int tableau[], int taille) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour l'écriture.\n");
        return;
    }

    for (int i = 0; i < taille; ++i) {
        fprintf(fichier, "%d\n", tableau[i]);
    }

    fclose(fichier);
}

void triSimple(int tableau[], int taille) {
    int i, j, temp;
    for (i = 0; i < taille - 1; i++) {
        for (j = 0; j < taille - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }
}

void triSelection(int tableau[], int taille) {
    int i, j, min_idx, temp;
    for (i = 0; i < taille - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < taille; j++)
            if (tableau[j] < tableau[min_idx])
                min_idx = j;
        temp = tableau[min_idx];
        tableau[min_idx] = tableau[i];
        tableau[i] = temp;
    }
}

void triBulle(int tableau[], int taille) {
    int i, j, temp;
    for (i = 0; i < taille - 1; i++)
        for (j = 0; j < taille - i - 1; j++)
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
}

void triInsertion(int tableau[], int taille) {
    int i, cle, j;
    for (i = 1; i < taille; i++) {
        cle = tableau[i];
        j = i - 1;
        while (j >= 0 && tableau[j] > cle) {
            tableau[j + 1] = tableau[j];
            j = j - 1;
        }
        tableau[j + 1] = cle;
    }
}

void triRapide(int tableau[], int debut, int fin) {
    if (debut < fin) {
        int pivot = tableau[fin];
        int i = debut - 1;
        for (int j = debut; j < fin; j++) {
            if (tableau[j] < pivot) {
                i++;
                int temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
            }
        }
        int temp = tableau[i + 1];
        tableau[i + 1] = tableau[fin];
        tableau[fin] = temp;

        int pivotIndex = i + 1;

        triRapide(tableau, debut, pivotIndex - 1);
        triRapide(tableau, pivotIndex + 1, fin);
    }
}

void triFusion(int tableau[], int debut, int fin) {
    if (debut < fin) {
        int milieu = debut + (fin - debut) / 2;
        triFusion(tableau, debut, milieu);
        triFusion(tableau, milieu + 1, fin);

        int tailleGauche = milieu - debut + 1;
        int tailleDroite = fin - milieu;

        int gauche[tailleGauche], droite[tailleDroite];

        for (int i = 0; i < tailleGauche; i++) {
            gauche[i] = tableau[debut + i];
        }
        for (int j = 0; j < tailleDroite; j++) {
            droite[j] = tableau[milieu + 1 + j];
        }

        int i = 0, j = 0, k = debut;
        while (i < tailleGauche && j < tailleDroite) {
            if (gauche[i] <= droite[j]) {
                tableau[k] = gauche[i];
                i++;
            } else {
                tableau[k] = droite[j];
                j++;
            }
            k++;
        }

        while (i < tailleGauche) {
            tableau[k] = gauche[i];
            i++;
            k++;
        }

        while (j < tailleDroite) {
            tableau[k] = droite[j];
            j++;
            k++;
        }
    }
}

void tourDeHanoi(int n, char depart, char destination, char auxiliaire) {
    if (n == 1) {
        printf("Deplacer le disque 1 de %c vers %c\n", depart, destination);
        return;
    }
    tourDeHanoi(n - 1, depart, auxiliaire, destination);
    printf("Deplacer le disque %d de %c vers %c\n", n, depart, destination);
    tourDeHanoi(n - 1, auxiliaire, destination, depart);
}

// Function to perform all sorts and display their execution times in ascending order
void trierTousLesTris(int nombres[], int taille) {
    clock_t debut, fin;
    double tempsExecution[MAX_SIZE] = {0}; // Array to store execution times
    char *nomsTris[] = {"Tri Simple", "Tri par Sélection", "Tri par Bulle", "Tri par Insertion", "Tri Rapide", "Tri par Fusion"};
    void (*fonctionsTris[])(int[], int) = {triSimple, triSelection, triBulle, triInsertion, triRapide, triFusion};

    // Perform each sort and measure its execution time
    for (int i = 0; i < 6; i++) {
        printf("**************************************************\n");
        printf("%s en cours...\n", nomsTris[i]);
        debut = clock();
        fonctionsTris[i](nombres, taille);
        fin = clock();
        tempsExecution[i] = calculerTempsExecution(debut, fin);
        printf("%s terminé.\n", nomsTris[i]);
        printf("Temps d'exécution : %.6f secondes\n", tempsExecution[i]);
    }

    // Sort the execution times in ascending order
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (tempsExecution[i] > tempsExecution[j]) {
                double temp = tempsExecution[i];
                tempsExecution[i] = tempsExecution[j];
                tempsExecution[j] = temp;
                char *tempNom = nomsTris[i];
                nomsTris[i] = nomsTris[j];
                nomsTris[j] = tempNom;
            }
        }
    }

    // Display the sorted execution times
    printf("\n***********************************\n");
    printf("\nDurees de tri en ordre croissant :\n");
    for (int i = 0; i < 6; i++) {
        printf("%s : %.6f secondes\n", nomsTris[i], tempsExecution[i]);
    }
}




double calculerTempsExecution(clock_t debut, clock_t fin) {
    return ((double) (fin - debut)) / CLOCKS_PER_SEC;
}


