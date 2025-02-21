#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
#include <unistd.h>
#include <time.h>

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
        
    
    /*while(multi_or_pc != PC && multi_or_pc != MULTIPLAYER){

        printf("Non reconnu\n");
        multi_or_pc = ask_gameplay();
    
    
        if(multi_or_pc == 1 || multi_or_pc == 2){

            break;
        }
    }*/

    if(multi_or_pc == MULTIPLAYER){

    if(multi_or_pc == MULTIPLAYER){

        printf("Veuillez saisir le pseudonyme du premier joueur.\n");
        ask_username_display(player1_username, MAX_LENGTH); 
        printf("Veuillez saisir le pseudonyme du deuxième joueur.\n");
        ask_username_display(player2_username, MAX_LENGTH);


    }

    while(multi_or_pc == MULTIPLAYER){ 
    
        printf("Veuillez saisir le pseudonyme du premier joueur.\n");
        ask_username_display(player1_username, MAX_LENGTH); 
        printf("Veuillez saisir le pseudonyme du deuxième joueur.\n");
        ask_username_display(player2_username, MAX_LENGTH);


    }

    while(multi_or_pc == MULTIPLAYER){ 
    

        player_choice_display(player1_username, p1_choice, sizeof(p1_choice));

        player1_move = atoi(p1_choice); 
    
                                    /* Boucle de vérification entrée utilisateur joueur 1 */
        /*---------------------------------------------------------------------------------------------------------------*/
        while(player1_move != PIERRE && player1_move != FEUILLE & player1_move != CISEAUX && player1_move != QUIT){

            printf("Non reconnu. Saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n");
            fgets(p1_choice, sizeof(p1_choice), stdin);
            player1_move = atoi(p1_choice);

        }

        if(player1_move == QUIT){

            printf("\nVous avez décidé de quitter le jeu! A bientôt.\n");
            printf("\n---------------------- GAME OVER ! --------------------\n");
            break;
        }

        if(player1_move == PIERRE){

            printf("%s, vous avez choisi Pierre.\n", player1_username); 
            sleep(1);
            system("clear");
            
        }else if(player1_move == FEUILLE){ 

            printf("%s, vous avez choisi Feuille.\n", player1_username);
            sleep(1);
            system("clear");

        }else if(player1_move == CISEAUX){

            printf("%s, vous avez choisi Ciseaux.\n", player1_username); 
            sleep(1);
            system("clear");

        }
        
        player_choice_display(player2_username, p2_choice, sizeof(p2_choice)); 
        player2_move = atoi(p2_choice);


                                /* Boucle de vérification entrée utilisateur joueur 2 */
        /*---------------------------------------------------------------------------------------------------------------*/
        while(player2_move != PIERRE && player2_move != FEUILLE & player2_move != CISEAUX && player2_move != QUIT){

            printf("Non reconnu. Saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n");
            fgets(p2_choice, sizeof(p2_choice), stdin);
            player2_move = atoi(p2_choice);

        }

        if(player2_move == QUIT){

            printf("\nVous avez décidé de quitter le jeu! A bientôt.\n");
            printf("\n---------------------- GAME OVER ! --------------------\n");
            break;
        }

        if(player2_move == PIERRE){ // Utiliser également switch ici!

            printf("%s, vous avez choisi Pierre.\n", player2_username);
            sleep(1);
            system("clear");
            
        }else if(player2_move == FEUILLE){

            printf("%s, vous avez choisi Feuille.\n", player2_username);
            sleep(1);
            system("clear");
            
        }else if(player2_move == CISEAUX){

            printf("%s, vous avez choisi Ciseaux.\n", player2_username);
            sleep(1);
            system("clear");

        }

        call_verif = verif_results(player1_move, player2_move);

        if(call_verif == 0){

            printf("ÉGALITÉ!\n");
            rappel_score(player1_username, player1_score);
            rappel_score(player2_username, player2_score);

        }else if(call_verif == 1){

            printf("Joueur 1 gagne!\n\n");
            player1_score++;
            rappel_score(player1_username, player1_score);
            rappel_score(player2_username, player2_score);

        }else if(call_verif == 2){

            printf("Joueur 2 gagne!\n\n");
            player2_score++;
            rappel_score(player1_username, player1_score);
            rappel_score(player2_username, player2_score);
        }

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
    }

    while(multi_or_pc == PC){
        

        player_choice_display(player1_username, p1_choice, sizeof(p1_choice));

        player1_move = atoi(p1_choice);

        while(player1_move != PIERRE && player1_move != FEUILLE & player1_move != CISEAUX && player1_move != QUIT){

            printf("Non reconnu. Saisissez 1 pour la pierre, 2 pour la feuille, 3 pour ciseaux :\n\n");
            fgets(p1_choice, sizeof(p1_choice), stdin);
            player1_move = atoi(p1_choice);

        }

        if(player1_move == QUIT){

            printf("\nVous avez décidé de quitter le jeu! A bientôt.\n");
            printf("\n---------------------- GAME OVER ! --------------------\n");
            break;
        }

        if(player1_move == PIERRE){

            printf("%s, vous avez choisi Pierre.\n", player1_username); //Rajouter des breaks ? + préférer switch à else if (faire attention, switch case n'accepte que les variables constantes)
            sleep(1);
            system("clear");
            
        }else if(player1_move == FEUILLE){ 

            printf("%s, vous avez choisi Feuille.\n", player1_username);
            sleep(1);
            system("clear");

        }else if(player1_move == CISEAUX){

            printf("%s, vous avez choisi Ciseaux.\n", player1_username); // Encapsuler ça dans une fonction!
            sleep(1);
            system("clear");

        }

        /* Sélection choix PC */       
        if(random_value == PIERRE){

            printf("Le PC a choisi PIERRE !\n"); 
            sleep(1);
            system("clear");
            
        }else if(random_value == FEUILLE){ 

            printf("Le PC a choisi FEUILLE !\n");
            sleep(1);
            system("clear");

        }else if(random_value == CISEAUX){

            printf("Le PC a choisi CISEAUX !\n"); 
            sleep(1);
            system("clear");

        }

        call_verif = verif_results(player1_move, random_value);

        if(call_verif == 0){

            printf("ÉGALITÉ!\n");
            rappel_score(player1_username, player_ScorevsPC);
            rappel_score(pc_username, pc_scoreVSplayer);

        }else if(call_verif == 1){

            printf("Bien joué ! Vous gagnez 1 point.\n\n");
            player_ScorevsPC++;
            rappel_score(player1_username, player_ScorevsPC);
            rappel_score(pc_username, pc_scoreVSplayer);

        }else if(call_verif == 2){

            printf("Le PC gagne!\n\n");
            pc_scoreVSplayer++;
            rappel_score(player1_username, player_ScorevsPC);
            rappel_score(pc_username, pc_scoreVSplayer);
        }

    }

        FILE *fichier_end = fopen("score_file", "w");
        
        // Actualisation des scores dans le fichier score_file
        fprintf(fichier_end, "%d %d", player_ScorevsPC, pc_scoreVSplayer); 
        printf("Votre score sera enregistré pour cette valeur : %d\n", player_ScorevsPC);
        printf("Le score du PC sera enregistré à cette valeur : %d\n", pc_scoreVSplayer);
        fclose(fichier_end);

    return 0;
}
