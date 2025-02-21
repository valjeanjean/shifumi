#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
#include <unistd.h>
#include <time.h>

/*
    Faire fonction avec if(multi_or_pc == PC){
    
        appel fonction boucle while(multi_or_pc == PC)

    }else if(multi_or_pc == MULTIPLAYER){
    
        appel fonction boucle while (multi_or_pc == MULTIPLAYER)
    }
*/

#define PIERRE 1   
#define FEUILLE 2
#define CISEAUX 3 
#define QUIT 0
#define MAX_LENGTH 255
#define MULTIPLAYER 2
#define PC 1

/* BANDEAU D'AFFICHAGE */
void game_start_display(){
    
    printf("---------------------- ShiFuMi ! --------------------\n\n");
}

/* CHOIX DE JOUER CONTRE QUELQU'UN OU CONTRE LE PC */
int ask_gameplay(){
    
    char user_gameplay_choice[MAX_LENGTH]; 
    int user_atoi = 8;
    
    printf("Tout d'abord, souhaitez vous jouer contre l'ordinateur ou en multijoueur?\n");
    printf("Saisissez 1 pour jouer contre l'IA, 2 pour jouer en multijoueur :\n");
    fgets(user_gameplay_choice, sizeof(user_gameplay_choice), stdin);
    user_atoi = atoi(user_gameplay_choice); 
    
    if(user_atoi == 1){
        
        return 1;
        
    }else if(user_atoi == 2){
        
        return 2;
        
    }else{
        
        return 0;
    }
}

/* CHOIX DU PSEUDO */
void ask_username_display(char *first_username, int taille){
    
    fgets(first_username, taille, stdin);
    first_username[strcspn(first_username, "\n")] = 0;
    printf("Vous avez choisi le pseudo %s.\n", first_username);
}

/* CHOIX PIERRE FEUILLE CISEAUX */
void player_choice_display(char *first_username, char *stock_choice, int taille){
    
    sleep(1);
    printf("%s, saisissez 1 pour la PIERRE, 2 pour la FEUILLE, 3 pour CISEAUX :\n", first_username);
    printf("Vous pouvez également quitter le jeu en saisissant 0.\n");
    fgets(stock_choice, taille, stdin);
}

void rappel_score(char *player_username, int score){ // 
    
    printf("Score de %s : %d\n", player_username, score);
}

/* COMPARAISON PIERRE FEUILLE CISEAUX ET RÉSULTAT */
int verif_results(int atoiJ1, int atoiJ2){
    
    int sommeAtoi = 0;
    sommeAtoi = atoiJ1 + atoiJ2;
    
    if(atoiJ1 == atoiJ2){ // Égalité
        
        return 0;
    }
    
    if(sommeAtoi == 3 && atoiJ1 > 1){ // Cas où le coup joué est pierre vs feuille avec J1 jouant feuille (J1 gagne)
        
        sleep(1);
        printf("La feuille enveloppe la pierre !\n");
        return 1; // J1 gagne
        
    }else if(sommeAtoi == 3 && atoiJ2 > 1){ // Cas où le coup joué est pierre vs feuille avec J2 jouant feuille (J2 gagne)
        
        sleep(1);
        printf("La feuille enveloppe la pierre !\n");
        return 2; // J2 gagne
    }
    
    if(sommeAtoi == 4 && atoiJ1 > 2){ // Cas où le coup joué est ciseaux vs pierre avec J1 jouant ciseaux (J2 gagne car la pierre (1) bat les ciseaux (3))
        
        sleep(1);
        printf("La pierre bat les ciseaux !\n");
        return 2;
        
    }else if(sommeAtoi == 4 && atoiJ2 > 2){ // Cas où le coup joué est ciseaux vs pierre avec J2 jouant ciseaux (J1 gagne car la pierre (1) bat les ciseaux (3))
        
        sleep(1);
        printf("La pierre bat les ciseaux !\n");
        return 1;
    }
    
    if(sommeAtoi == 5 && atoiJ1 > 2){ // Cas où le coup joué est Ciseaux vs Feuille avec J1 jouant Ciseaux (J1 gagne car les ciseaux coupent la feuille)
        
        sleep(1);
        printf("Les ciseaux coupent la feuille !\n");
        return 1;
        
    }else if(sommeAtoi == 5 && atoiJ2 > 2){
        
        sleep(1);
        printf("Les ciseaux coupent la feuille !\n");
        return 2;
    }
    
}

int startEventLoop_multi(int gameplay_type, char *first_username, char *second_username, char *P1choice_array, char *P2choice_array, int p1Score, int p2Score){
    
    int player1_move_atoi = -1, player2_move_atoi = -1;
    int getVerif = -1;
    
    while(gameplay_type == MULTIPLAYER){ 
        
        player_choice_display(first_username, P1choice_array, sizeof(P1choice_array));
        
        player1_move_atoi = atoi(P1choice_array); 
        
                            /* Boucle de vérification entrée utilisateur joueur 1 */
        /*---------------------------------------------------------------------------------------------------------------*/
        while(player1_move_atoi != PIERRE && player1_move_atoi != FEUILLE & player1_move_atoi != CISEAUX && player1_move_atoi != QUIT){
            
            printf("Non reconnu. Saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n");
            fgets(P1choice_array, sizeof(P1choice_array), stdin);
            player1_move_atoi = atoi(P1choice_array);
        }
        
        if(player1_move_atoi == QUIT){
            
            printf("\nVous avez décidé de quitter le jeu! A bientôt.\n");
            printf("\n---------------------- GAME OVER ! --------------------\n");
            break;
        }
        
        if(player1_move_atoi == PIERRE){
            
            printf("%s, vous avez choisi Pierre.\n", first_username); 
            sleep(1);
            system("clear");
            
        }else if(player1_move_atoi == FEUILLE){ 
            
            printf("%s, vous avez choisi Feuille.\n", first_username);
            sleep(1);
            system("clear");
            
        }else if(player1_move_atoi == CISEAUX){
            
            printf("%s, vous avez choisi Ciseaux.\n", first_username); 
            sleep(1);
            system("clear");
        }
        
        player_choice_display(second_username, P2choice_array, sizeof(P2choice_array)); 
        player2_move_atoi = atoi(P2choice_array);
        
                                /* Boucle de vérification entrée utilisateur joueur 2 */
        /*---------------------------------------------------------------------------------------------------------------*/
        while(player2_move_atoi != PIERRE && player2_move_atoi != FEUILLE & player2_move_atoi != CISEAUX && player2_move_atoi != QUIT){
            
            printf("Non reconnu. Saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n");
            fgets(P2choice_array, sizeof(P2choice_array), stdin);
            player2_move_atoi = atoi(P2choice_array); 
        }
        
        if(player2_move_atoi == QUIT){
            
            printf("\nVous avez décidé de quitter le jeu! A bientôt.\n");
            printf("\n---------------------- GAME OVER ! --------------------\n");
            break;
        }

        if(player2_move_atoi == PIERRE){ // Utiliser également switch ici!
            
            printf("%s, vous avez choisi Pierre.\n", second_username);
            sleep(1);
            system("clear");
            
        }else if(player2_move_atoi == FEUILLE){
            
            printf("%s, vous avez choisi Feuille.\n", second_username);
            sleep(1);
            system("clear");
            
        }else if(player2_move_atoi == CISEAUX){
            
            printf("%s, vous avez choisi Ciseaux.\n", second_username);
            sleep(1);
            system("clear");
        }
        
        getVerif = verif_results(player1_move_atoi, player2_move_atoi);
        
        if(getVerif == 0){
            
            printf("ÉGALITÉ!\n");
            rappel_score(first_username, p1Score);
            rappel_score(second_username, p2Score);
            
        }else if(getVerif == 1){
            
            printf("Joueur 1 gagne!\n\n");
            p1Score++;
            rappel_score(first_username, p1Score);
            rappel_score(second_username, p2Score);
            
        }else if(getVerif == 2){
            
            printf("Joueur 2 gagne!\n\n");
            p2Score++;
            rappel_score(first_username, p1Score);
            rappel_score(second_username, p2Score);
        }     
    }  
}

int startEventLoop_PC(int gameplay_type, char *first_username, char *PC_username, char *P1choice_array, int p1Score, int PCscore, int rand_value){
    
    int player1_move_atoi = -1;
    int getVerif = -1;
    
    while(gameplay_type == PC){
        
        player_choice_display(first_username, P1choice_array, sizeof(P1choice_array));
        
        player1_move_atoi = atoi(P1choice_array);
        
        while(player1_move_atoi != PIERRE && player1_move_atoi != FEUILLE & player1_move_atoi != CISEAUX && player1_move_atoi != QUIT){
            
            printf("Non reconnu. Saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n");
            fgets(P1choice_array, sizeof(P1choice_array), stdin);
            player1_move_atoi = atoi(P1choice_array);
        }
        
        if(player1_move_atoi == QUIT){
            
            printf("\nVous avez décidé de quitter le jeu! A bientôt.\n");
            printf("\n---------------------- GAME OVER ! --------------------\n");
            break;
        }

        if(player1_move_atoi == PIERRE){
            
            printf("%s, vous avez choisi Pierre.\n", first_username); //Rajouter des breaks ? + préférer switch à else if (faire attention, switch case n'accepte que les variables constantes)
            sleep(1);
            system("clear");
            
        }else if(player1_move_atoi == FEUILLE){ 
            
            printf("%s, vous avez choisi Feuille.\n", first_username);
            sleep(1);
            system("clear");
            
        }else if(player1_move_atoi == CISEAUX){
            
            printf("%s, vous avez choisi Ciseaux.\n", first_username); // Encapsuler ça dans une fonction!
            sleep(1);
            system("clear");
        }
        
        /* Sélection choix PC */       
        if(rand_value == PIERRE){
            
            printf("Le PC a choisi PIERRE !\n"); 
            sleep(1);
            system("clear");
            
        }else if(rand_value == FEUILLE){ 
            
            printf("Le PC a choisi FEUILLE !\n");
            sleep(1);
            system("clear");
            
        }else if(rand_value == CISEAUX){
            
            printf("Le PC a choisi CISEAUX !\n"); 
            sleep(1);
            system("clear");  
        }
        
        getVerif = verif_results(player1_move_atoi, rand_value);
        
        if(getVerif == 0){
            
            printf("ÉGALITÉ!\n");
            rappel_score(first_username, p1Score);
            rappel_score(PC_username, PCscore);
            
        }else if(getVerif == 1){
            
            printf("Bien joué ! Vous gagnez 1 point.\n\n");
            p1Score++;
            rappel_score(first_username, p1Score);
            rappel_score(PC_username, PCscore);
            
        }else if(getVerif == 2){
            
            printf("Le PC gagne!\n\n");
            PCscore++;
            rappel_score(first_username, p1Score);
            rappel_score(PC_username, PCscore);
        }   
    } 
}

int main(){
    
    /* DÉCLARATION DE TABLEAUX POUR LES PSEUDOS & STOCK DU COUP CHOISI */
    char player1_username[MAX_LENGTH], player2_username[MAX_LENGTH], p1_choice[MAX_LENGTH], p2_choice[MAX_LENGTH];
    char pc_username[MAX_LENGTH] = "PC";
    
    /* Déclaration des variables pour les scores */
    int player1_score = 0, player2_score = 0, player_ScorevsPC = 0, pc_scoreVSplayer = 0;
    
    /* Déclarations de variables pour le calcul d'atoi */
    int player1_move = -1, player2_move = -1, call_verif = -1;
    int multi_or_pc = -1;
    
    /* Aléatoire */
    srand(time(NULL));
    int random_value = (rand() % 3) + 1;
    
    game_start_display();
    
    do{
        
        multi_or_pc = ask_gameplay();
        
        if(multi_or_pc == 1 || multi_or_pc == 2){
            
            break;
        }
        
         printf("Non reconnu\n");

        }while(multi_or_pc != PC && multi_or_pc != MULTIPLAYER);
        
        if(multi_or_pc == MULTIPLAYER){
            
            printf("Veuillez saisir le pseudonyme du premier joueur.\n");
            ask_username_display(player1_username, MAX_LENGTH); 
            printf("Veuillez saisir le pseudonyme du deuxième joueur.\n");
            ask_username_display(player2_username, MAX_LENGTH);
            
            startEventLoop_multi(multi_or_pc, player1_username, player2_username, p1_choice, p2_choice, player1_score, player2_score);
        }
        
        if(multi_or_pc == PC){
            
            printf("Vous avez décidé de jouer contre l'ordinateur. Préparez vous!\n");
            printf("Veuillez saisir votre pseudo pour cette partie :\n");
            ask_username_display(player1_username, MAX_LENGTH);
            
            // Lecture des scores contenus dans le fichier score_file
            FILE* fichier_start = fopen("score_file", "r"); 
            fscanf(fichier_start, "%d %d", &player_ScorevsPC, &pc_scoreVSplayer);
            printf("\nLes scores de vos précédentes parties ont été enregistrées.\n");
            printf("Votre score : %d\n", player_ScorevsPC);
            printf("Score du PC : %d\n\n", pc_scoreVSplayer);
            fclose(fichier_start);
            
            startEventLoop_PC(multi_or_pc, player1_username, pc_username, p1_choice, player_ScorevsPC, pc_scoreVSplayer, random_value);
        }
        
        FILE *fichier_end = fopen("score_file", "w");
        
        // Actualisation des scores dans le fichier score_file
        fprintf(fichier_end, "%d %d", player_ScorevsPC, pc_scoreVSplayer); 
        printf("Votre score sera enregistré pour cette valeur : %d\n", player_ScorevsPC);
        printf("Le score du PC sera enregistré à cette valeur : %d\n", pc_scoreVSplayer);
        fclose(fichier_end);
        
        return 0;
    }
    
    
    
    
    /*while(multi_or_pc != PC && multi_or_pc != MULTIPLAYER){
        
    printf("Non reconnu\n");
    multi_or_pc = ask_gameplay();
    
    
    if(multi_or_pc == 1 || multi_or_pc == 2){
        
    break;
}
}*/


                        /* EXEMPLE : */
/* switch(multi_or_pc){

    case MULTIPLAYER :
    appel fonction pour cette boucle while : while(multi_or_pc == MULTIPLAYER)
    break;

    case PC : 
    appel fonction pour l'autre boucle while == PC
    break;




} 

*/