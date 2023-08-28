//controle de posição baseado X e Y com referência no plano cartesiano.
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define X 20 //colunas
#define Y 10 //linhas

//função para aparecimento aleatório das maçãs na posição Y
int aleatappy() { 
        static unsigned s = 74; 
        auto unsigned n = s%10; 
        s += s/10;

    return n; 
}

//função para aparecimento aleatório das maçãs na posição X
int aleatappx() {
        static unsigned s = 93; 
        auto unsigned n = s%10; 
        s += s/10; 

    return n; 
}

//imprimindo a base e definindo as proporções e condições de impressão de cada elemento.
void base(int cobray, int cobrax, int appy, int appx, int corpoy, int corpox){
   
    for(int y = 0; y <= Y; y++){
        for(int x = 0; x <= X; x++){
            if(y == 0 || x == 0 || y == Y || x == X){
                //bordas
                printf("#");
            }else if(x == cobrax && y == cobray){
                //cobra definida como espaço vazio com  fundo azul
                printf("\x1b[44m \x1b[0m");
            }else if(y == appy && x == appx){
                //maçãs
                printf("+");
            }else if(corpoy == y && corpox == x){
                //corpo da cobra
                printf("\x1b[44m \x1b[0m");
            }else{
                //espaço vazio
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
void jogo(int cobray, int cobrax, int appy, int appx, int corpoy, int corpox){
    int infi = 1, move = 3, score = 0, aux = 0, direciona, moveantes, tempo = 80;

    while(infi){
        direciona = 0;
        moveantes = move; 
        
        if(aux == 1){
            tempo -= 6;
        }
        
        Sleep(tempo);
        system("cls");
    
        base(cobray, cobrax, appy, appx, corpoy, corpox);

        //selecionando direção de movimento da cobrinha.
        if(kbhit()){//kbhit(keyboard hit): função que verifica se alguma tecla foi pressionada.
           
            switch(entradamove()){
                case 1: //a - esquerda 
                    if(moveantes != 1 && moveantes != 3){
                        direciona = 1;
                        move = 1;
                        break;
                    }
                    break;
                case 2: //w - cima
                    if(moveantes != 2 && moveantes != 4){
                        direciona = 1;
                        move = 2;
                        break;
                    }
                    break;
                case 3: //d - direito
                    if(moveantes != 3 && moveantes != 1){
                        direciona = 1;
                        move = 3;
                        break;
                    }
                 break;
                case 4: //s - baixo
                    if(moveantes != 4 && moveantes != 2){
                        direciona = 1;
                        move = 4;
                        break;
                    }
                default:
                    break;
            }
     
        }

        //movimentação automatica da cobrinha
        switch(move){
            case 1: //a - esquerda 
               
                if(cobrax - 1 > 0){
                    corpox = cobrax;
                    cobrax--;
                    
                    if(moveantes == 2){
                        if(direciona){
                            corpoy--;
                        }
                    }

                    if(moveantes == 4){
                        if(direciona){
                            corpoy++;
                        }
                    }
                    break;
                }else{
                    infi = 0;
                    break;
                }
            
                
                break;
            case 2: //w - cima
              
                if(cobray - 1 > 0){
                    corpoy = cobray;
                    cobray--;

                    if(moveantes == 3){
                        if(direciona){
                            corpox++;
                        }
                    }

                    if(moveantes == 1){
                         if(direciona){
                            corpox--;
                        }
                    }
                    break;
                }else{
                    infi = 0;
                    break;

                }
            
                break;
            case 3: //d - direita 
         
                if(cobrax + 1 < X){
                    corpox = cobrax;
                    cobrax++;

                    if(moveantes == 2){
                        if(direciona){
                            corpoy--;
                        }
                    }

                    if(moveantes == 4){
                        if(direciona){
                            corpoy++;
                        }
                    }
                    break;
                }else{
                    infi = 0;
                    break;
                }
             
                break;
            
            case 4: //s - baixo
       
                if(cobray + 1 < Y){
                    corpoy = cobray;
                    cobray++;

                    if(moveantes == 1){
                        if(direciona){
                            corpox--;
                        }
                    }

                    if(moveantes == 3){
                        if(direciona){
                            corpox++;
                        }
                    }
                    
                    break;
                }else{
                    infi = 0;
                    break;
                }
                   
                break;
            
            default:
                break;
        }

        
            if(cobray == appy && cobrax == appx){
                appy = aleatappy(), appx = aleatappx();
                aux = 1;
                score++;
            }else{
                aux = 0;
            }

            printf("\nSCORE: %d\n", score);
    }
}

int main(){
    int cobrax = 5, cobray = 5, appy = aleatappy(), appx = aleatappx();
    int corpox = 5, corpoy = 5;
    char resp;

    do{
        //esconder cursor
        printf("\e[?25l");

        jogo(cobray, cobrax, appy, appx, corpoy, corpox);

        printf("GAME OVER!\nJogar novamente?[s/n]: ");
        scanf(" %c", &resp);

    }while(resp == 's' || resp == 'S');

    return 0;
}