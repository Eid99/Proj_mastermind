#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

// FUNCAO DE CRIACAO DA CHAVE SENHA//
void criador_chave(char chave[],int numero_cores,int tamanho_chave, char repetir_cores){
  int cor,repeticao[numero_cores]={0},voltar_rand=0,j=0;
  srand ( time(NULL) );
  for(int i=0;i<tamanho_chave;i++)
  {
    voltar_rand=0;
    do{

      cor=rand()%numero_cores+1;   //ESCOLHA DA COR


      // CONTROLE DA REPETICAO
      for(j=0; j<numero_cores  && (repetir_cores=='N'|| repetir_cores=='n');j++){
        if (repeticao[j]==cor){
          voltar_rand=1;
          break;
          }
          else{
          voltar_rand=0;

        }
      }


    }while(voltar_rand==1);

      switch (cor) {
        case 1: chave[i]='A'; break;
        case 2: chave[i]='B'; break;
        case 3: chave[i]='C'; break;
        case 4: chave[i]='D'; break;
        case 5: chave[i]='E'; break;
        case 6: chave[i]='F'; break;
        case 7: chave[i]='G'; break;
        case 8: chave[i]='H'; break;
        case 9: chave[i]='I'; break;
        case 10: chave[i]='J'; break;
        case 11: chave[i]='K'; break;
        case 12: chave[i]='L'; break;
      }repeticao[i]=cor;


    }


}

// FIM DA CRIACAO DA CHAVE SENHA



int main(){
// INICIALIZACAO
srand ( time(NULL) );

  int numero_jogadores=0,tamanho_chave=1,numero_cores=0,numero_jogadas;

while(numero_jogadores<1 || numero_jogadores>4){
  fflush(stdin);
  puts("Quantos Jogadores de 1 a 4:");
  scanf("%d",&numero_jogadores);}
while(numero_cores<6 || numero_cores>12){
  fflush(stdin);
  puts("\nNumero de cores de 6 a 12:");
  scanf(" %d",&numero_cores);
}
while(tamanho_chave<4 || tamanho_chave>8){
  fflush(stdin);
  puts("\nTamanho da chave de 4 a 8:");
  scanf(" %d",&tamanho_chave);
}
while(numero_jogadas<10||numero_jogadas>20){
  fflush(stdin);
  puts("\nNumero de jogadas 10 a 20:");
  scanf(" %d",&numero_jogadas);
}



  int j,w,y,q,pretas,brancas;
  char chave[tamanho_chave],nome_jogadores[numero_jogadores][20],escolha[tamanho_chave];
  char repetir_cores='e';


  while(repetir_cores!='S' && repetir_cores!='N' && repetir_cores!='s' && repetir_cores!='n'){
    puts("Sera permitido repetir cores S/N:");
    scanf(" %c",&repetir_cores);
  }
  for(int i=0;i<numero_jogadores;i++)
  {
    fflush(stdin);
    puts("\nNome dos jogadores max.20:");
    scanf(" %s", nome_jogadores[i]);
}



//FIM DA INICIALIZACAO

/// COMECO DO JOGO
for(int i=0;i<numero_jogadores;i++){ //TROCA DE JOGADOR
  printf("\nVez do Jogador %s\n",nome_jogadores[i]);
  criador_chave(chave, numero_cores,tamanho_chave,repetir_cores);
  for(q=0;q<tamanho_chave;q++){
    printf("%c\n",chave[q]);
  }
  for(j=0;j<numero_jogadas && brancas!=tamanho_chave;j++){//CONTAGEM DE JOGADAS
    printf("\nFaltam %d\n",(numero_jogadas-j));
    for(w=0,brancas=0;w<tamanho_chave;w++){
      puts("Escolha a cor:");
      scanf(" %c",&escolha[w]);
      if(escolha[w]==chave[w]){
        brancas++;
      }
    }
    for(w=0,pretas=0;w<tamanho_chave;w++){
      for(y=0;y<tamanho_chave;y++){
        if(escolha[y]==chave[w]){
          pretas++;
        }
      }
    }pretas=pretas-brancas;
    printf("B%dP%d",brancas,pretas);

  }

}




  return 0;}
