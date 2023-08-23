// │, ┐,┌,─,└,┘, 32(espaço) characteres base.
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define VAZIO 32
#define COBRA 46
#define X 10
#define Y 10

//imprimindo o tabuleiro e definindo as proporções
void baseTabuleiro(int posic[10][10]){
   
        printf("┌");
        for(int i = 0; i < 10; i++){
            printf("─");
        }
        printf("┐\n");

        //linha
        for(int i = 0; i < 10; i++){
            printf("│");

            //coluna
            for(int j = 0; j < 10; j++){
                if(posic[i][j] == COBRA){
                    printf("\x1b[44m%c\x1b[0m", posic[i][j]);
                }else{
                    printf("%c", posic[i][j]);
                }

                
            }
            printf("│\n");
        }

        printf("└");
        for(int i = 0; i < 10; i++){
            printf("─");
        }
        printf("┘\n");

    
}

//entrada de dados para movimentação da cobra
int entradamove(){
    char move = getch();//vai pedir uma entrada do usuário sem precisar confirmar com enter
    
    //retorno de valor definido a depender da tecla digitada
    switch(move){
        case 'w':
            return 1;
            break;

        case 'a':
            return 2;
            break;

        case 's':
            return 3;
            break;

        case 'd':
            return 4;
            break;
        
        default:
            return 5;
            
    }

}

//funcionamento do jogo
void jogo(int posic[10][10]){
    int i, j;

    while(1){
        baseTabuleiro(posic);
        //OBS: não tá fazendo com que a cobrinha se movimente sozinha.
        //OBS: a cobrinha vai para última linha quando aperta 's'.
        //OBS: a cobrinha some se for para baixo na coluna '0' vulgo primeira coluna.
        //OBS: problemas para aparecer na coluna 0.
        //OBS: atravessar a borda de cima ou de baixo não reaparece na borda oposta.
        //OBS: atravessar a borda dos lados reaparece na linha de baixo ou de cima e não na mesma.

        //linha
        for( i = 0; i < 10; i++){
            //coluna
            for( j = 0; j < 10; j++){
                
 				if(posic[i][j+1] == VAZIO){
                    printf("%c", posic[i][j]);

                    posic[i][j+1] = VAZIO;
                    posic[i][j] = COBRA;
                    break;
                }
                
            }
        }

        //selecionando direção de movimento da cobrinha
        /*if(kbhit()){//kbhit(keyboard hit): função que verifica se alguma tecla foi pressionada.
            switch(entradamove()){
                case 1: //w - pra cima 
                    
                    //linha
                    for( i = 0; i < 10; i++){
                        //coluna
                        for( j = 0; j < 10; j++){
                            if(posic[i][j] == COBRA){
                               
                                    if(posic[i-1][j] == VAZIO){
                                        
                                        posic[i-1][j] = COBRA;
                                        posic[i][j] = VAZIO;
                                        break;
                                    }    
                               
                            }
                            
                        }
                    }
                    break;
                case 2: //a - pra esquerda 
                    //linha
                    for( i = 0; i < 10; i++){
                        //coluna
                        for( j = 0; j < 10; j++){
                            if(posic[i][j] == COBRA){
                                if(j - 1 >= 0){
                                    if(posic[i][j-1] == VAZIO){

                                        posic[i][j-1] = COBRA;
                                        posic[i][j] = VAZIO;
                                        break;
                                    }    
                                }else{
                                    posic[i][9] = COBRA;
                                    posic[i][j] = VAZIO;
                                    break;
                                }
                            }
                            
                        }
                    }
                    break;
                case 3: //s - pra baixo - OBS: NÃO TA PRONTO XXX
                    //linha
                    for( i = 0; i < 10; i++){
                        //coluna
                        for( j = 0; j < 10; j++){
                            
                            if(posic[i][j] == COBRA){
                                
                                    if(posic[i+1][j] == VAZIO){

                                        posic[i+1][j] = COBRA;
                                        posic[i][j] = VAZIO;
                                        break;
                                    }    
                              
                            }
                            
                        }
                    }
                    break;
                case 4: //d - pra direita 
                    //linha
                    for( i = 0; i < 10; i++){
                        //coluna
                        for( j = 0; j < 10; j++){
                            if(posic[i][j] == COBRA){
                                if(j + 1 <= 9){
                                    if(posic[i][j+1] == VAZIO){

                                        posic[i][j+1] = COBRA;
                                        posic[i][j] = VAZIO;
                                        break;
                                    }    
                                }else{
                                    posic[i][0] = COBRA;
                                    posic[i][j] = VAZIO;
                                    break;
                                }
                            }
                            
                        }
                    }
                    break;
            }
            
        }*/
        Sleep(1000);
        system("cls");
    }
    
}


int main(){
    int espaco[10][10];//tamanho do tabuleiro

    //esconder cursor
    printf("\e[?25l");

    //atribuindo o char ('espaço' pra ficar vazio), em uma array, por um número de tipo int baseando na tabela ascii. 
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
           if(!(i == 0 && j == 0)){
                espaco[i][j] = VAZIO;
           }else{
                espaco[0][0] = COBRA;
           }
 
        }
    }

    jogo(espaco);

    return 0;
}