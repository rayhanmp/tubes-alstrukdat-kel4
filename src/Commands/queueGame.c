#include "queueGame.h"

void QueueGame(queueGame *q, arrGame arr) {
    int num;
  
    printf("Berikut adalah daftar antrian game-mu\n");
    PrintQueue(*q);
  
    printf("\n");

    ListGame()
      
    printf("\n");
  
    printf("Nomor game yang mau ditambahkan ke antrian: ");
    STARTWORD_INPUT();
    num = wordToInt(currentWord);

    if (num>0 && num<=arr.Length) {
        Enqueue(&q, arr[num-1]);
        printf("Game berhasil ditambahkan kedalam daftar antrian.");
    }
    else {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.");
    }

}