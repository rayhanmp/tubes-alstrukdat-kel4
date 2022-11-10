#include "ADT/mesinkata.h"
#include "ADT/mesinkarakter.h"
#include "ADT/arrayGame.h"
#include "ADT/queueGame.h"
#include "Commands/deletegame.h"
#include "Commands/creategame.h"
#include "Commands/commandlain.h"
#include "Commands/load.h"
#include "Commands/quit.h"
#include "Commands/save.h"
#include "Commands/playgame.h"
#include "Commands/listGame.h"
#include "Commands/queueGame.h"
#include "Commands/skipgame.h"
#include "Commands/start.h"
#include "diner_dash/diner_dash.c"



int main(){
    INISIALISASI ARRAY GAME
    arrGame arrayGame;
    MakeArray(&arrayGame);
    queueGame qGame;
    CreateQueue(&qGame);
    boolean play = true;

    //MAIN PROGRAM
    printf(" /$$$$$$$  /$$   /$$  /$$$$$$  /$$      /$$  /$$$$$$ \n");
    printf("| $$__  $$| $$$ | $$ /$$__  $$| $$$    /$$$ /$$__  $$\n");
    printf("| $$  \\ $$| $$$$| $$| $$  \\ $$| $$$$  /$$$$| $$  \\ $$\n");
    printf("| $$$$$$$ | $$ $$ $$| $$  | $$| $$ $$/$$ $$| $$  | $$\n");
    printf("| $$__  $$| $$  $$$$| $$  | $$| $$  $$$| $$| $$  | $$\n");
    printf("| $$  \\ $$| $$\\  $$$| $$  | $$| $$\\  $ | $$| $$  | $$\n");
    printf("| $$$$$$$/| $$ \\  $$|  $$$$$$/| $$ \\/  | $$|  $$$$$$/\n");
    printf("|_______/ |__/  \\__/ \\______/ |__/     |__/ \\______/ \n");

    
    while(play){
        clearWord();
        printf("MASUKKAN COMMAND: ");
        STARTWORD_INPUT();
        if(isKataEqual(currentWord,"START")){
            start(&arrayGame);
        }
        else if(isKataEqual(currentWord,"LOAD")){
            ADVWORD_INPUT();
            load(&arrayGame, currentWord.TabWord);
        }
        else if(isKataEqual(currentWord,"SAVE")){
            ADVWORD_INPUT();
            save(&arrayGame, currentWord.TabWord);
        }
        else if(isKataEqual(currentWord,"CREATE")){
            ADVWORD_INPUT();
            createGame(&arrayGame);
        }
        else if(isKataEqual(currentWord,"LIST")){
            ADVWORD_INPUT();
            listGame(arrayGame);
        }
        else if(isKataEqual(currentWord,"DELETE")){
            ADVWORD_INPUT();
            deleteGame(&arrayGame,qGame);
        }
        else if(isKataEqual(currentWord,"QUEUE")){
            ADVWORD_INPUT();
            deleteGame(&arrayGame,qGame);
        }
        else if(isKataEqual(currentWord,"PLAY")){
            ADVWORD_INPUT();
            deleteGame(&arrayGame,qGame);
        }
        else if(isKataEqual(currentWord,"SKIPGAME")){
            ADVWORD_INPUT();
            skipGame(arrayGame, &qGame, wordToInt(currentWord));
        }
        else if(isKataEqual(currentWord,"HELP")){
            // quit();
            // play = false;
        }
        else if(isKataEqual(currentWord,"QUIT")){
            quit();
            play = false;
        }
        else{
            cmdLain();
        }
    }
    return 0;
}

