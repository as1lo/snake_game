#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define X 10
#define Y 10

//imprimindo o tabuleiro e definindo as proporções
void baseTabuleiro(int cobrax, int cobray){

    for(int x = 0; x <= X; x++){
        for(int y = 0; y <= Y; y++){
            if(x == 0 || y == 0 || x == X || y == Y){
                printf("#");
            }else if(x == cobrax && y == cobray){
                printf("\x1b[44m \x1b[0m");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    
}

//entrada de dados para movimentação da cobra
int entradamove(){
    char move;

    move = getch();

    //retorno de valor definido a depender da tecla digitada
    switch(move){
        case 'w':
            return 2;
            break;

        case 'a':
            return 1;
            break;

        case 's':
            return 4;
            break;

        case 'd':
            return 3;
            break;
        
        case 'W':
            return 2;
            break;

        case 'A':
            return 1;
            break;

        case 'S':
            return 4;
            break;

        case 'D':
            return 3;
            break;
        
        default:
            return 5;
            
    }

}

//funcionamento do jogo
void jogo(int cobrax, int cobray){
    int infi = 1, move = 1;

    while(1){

        Sleep(200);
        system("cls");
    
        baseTabuleiro(cobrax, cobray);

        //selecionando direção de movimento da cobrinha
        if(kbhit()){//kbhit(keyboard hit): função que verifica se alguma tecla foi pressionada.
           
            switch(entradamove()){
                case 1: //a - esquerda 
                    move = 1;
                    break;

                case 2: //w - cima
                    move = 2;
                    break;
                    
                case 3: //d - direito
                    move = 3;
                    break;

                case 4: //s - baixo
                    move = 4;
                    break;
                
                default:
                    break;
            }
     
        }

        //movimentação automatica da cobrinha
        switch(move){
            case 1: //a - esquerda 
               
                if(cobray - 1 >= 0){
                    cobray--;
                    break;
                }else{
                    infi = 0;
                    break;
                }
            
                
                break;
            case 2: //w - cima
              
                        if(cobrax - 1 >= 0){
                            cobrax--;
                            break;

                        }else{
                            infi = 0;
                            break;

                        }
                    
                
                break;
            case 3: //d - direita 
         
                        if(cobray + 1 < Y){
                            cobray++;
                            break;
                        }else{
                            infi = 0;
                            break;
                        }
             
                break;
            
            case 4: //s - baixo
       
                        if(cobrax + 1 < X){
                            cobrax++;
                            break;
                        }else{
                            infi = 0;
                            break;
                        }
                   
                break;
            
            default:
                break;
        }
 
    }
}

int main(){
    int cobrax = 5, cobray = 5;
    char resp;

    do{
        //esconder cursor
        printf("\e[?25l");

        jogo(cobrax, cobray);

        printf("GAME OVER!\nJogar novamente?[s/n]: ");
        scanf(" %c", &resp);

    }while(resp == 's' || resp == 'S');

    return 0;
}