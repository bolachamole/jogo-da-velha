#include "stdio.h"
#include "check.h"

void print_matriz(char jogo[3][3]){
    printf("%c | %c | %c\n", jogo[0][0], jogo[0][1], jogo[0][2]);
    printf("%c | %c | %c\n", jogo[1][0], jogo[1][1], jogo[1][2]);
    printf("%c | %c | %c\n", jogo[2][0], jogo[2][1], jogo[2][2]);
}

int main(){
    printf("JOGO DA VELHA!\nFormato de resposta: n m, onde 'n' é o número da linha e 'm' o número da coluna\n");
    int rodada, cond = -1;
    char s = ' ';
    char jogo[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            jogo[i][j] = ' ';
        }
    }
    while(!((s != 'X') ^ (s != 'O'))){
        printf("Quem vai primeiro? X ou O (o maiúsculo)?\n");
        scanf("%c%*c", &s);
    }
    if(s == 'X'){
        rodada = 1;
    } else{
        rodada = 2;
    }

    while(cond < 0){
        if(rodada == 1){
            printf("VEZ DO X!\n");
        } else{
            printf("VEZ DO O!\n");
        }
        print_matriz(jogo);

        int m, n;
        printf("Onde marcar?\n");
        scanf("%d%*c %d%*c", &m, &n);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if((i+1 == m) && (j+1 == n)){
                    if(jogo[i][j] != ' '){
                        printf("Já preenchido!\n");
                    } else if(rodada == 1){
                        jogo[i][j] = 'X';
                        rodada++;
                    } else{
                        jogo[i][j] = 'O';
                        rodada--;
                    }
                }
            }
        }

        if(checa_dp(jogo) || checa_ds(jogo) || checa_lin(jogo) || checa_col(jogo)){
            cond = 1;
        } else if(checa_velha(jogo)){
            cond = 0;
        }
    }
    print_matriz(jogo);

    if(cond > 0){
        if (rodada == 1){
            printf("O venceu!\n");
        } else if (rodada == 2){
            printf("X venceu!\n");
        }
    } else{
        printf("Velhou!\n");
    }
}