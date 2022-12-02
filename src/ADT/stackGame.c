#include <stdio.h>
#include <stdlib.h>
#include "stackGame.h"

void CreateEmptySG(stackGame *S){
    Top(*S) = NilSG;
}
/* I.S. sembarang{} */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySG(stackGame S){
    return (Top(S) == NilSG);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullSG(stackGame S){
    return (Top(S) == MaxSG-1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushSG(stackGame * S, Game game){
    Top(*S) += 1;
    InfoTop(*S) = game;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopSG(stackGame * S, Game* game){
    *game = InfoTop(*S);
    Top(*S) -= 1;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void CopyStackSG(stackGame Sin, stackGame *Sout){
    stackGame Stemp;
    Game X;
    CreateEmptySG(Sout);
    CreateEmptySG(&Stemp);
    while(!IsEmptySG(Sin)){
        PopSG(&Sin,&X);
        PushSG(&Stemp, X);
    }
    while(!IsEmptySG(Stemp)){
        PopSG(&Stemp,&X);
        PushSG(&Sin, X);
        PushSG(Sout, X);
    }
}
int LengthSG(stackGame S){
    stackGame S2;
    int length = 0;
    Game X;
    CopyStackSG(S,&S2);
    while(!IsEmptySG(S2) && length <= MaxSG){
        PopSG(&S2, &X);
        length++;
    }
    return length;
}

void PrintAllSG(stackGame S){
    stackGame sTemp; 
    CreateEmptySG(&sTemp);
    int i = 1; Game game;
    while (!IsEmptySG(S)) {
        PopSG(&S, &game);
        printf("%d. %s\n", i, game.TabWord);
        i++;
        PushSG(&sTemp, game);
    }
    while (!IsEmptySG(sTemp)) {
        PopSG(&sTemp, &game);
        PushSG(&S, game);
    }
}

void PrintSomeSG(stackGame S, int n){
    stackGame sTemp; 
    CreateEmptySG(&sTemp);
    int i = 1; Game game;
    for (i = 1; i <= n; i++){
        PopSG(&S, &game);
        printf("%d. %s\n", i, game.TabWord);
        PushSG(&sTemp, game);
    }
    for (i = 1; i <= n; i++){
        PopSG(&sTemp, &game);
        PushSG(&S, game);
    }
}
