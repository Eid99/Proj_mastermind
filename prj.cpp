#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;


void criador_chave(int chave[],int numero_cores,int tamanho_chave, char repetir_cores){
  int cor,repeticao[numero_cores]={0},voltar_rand=0,j=0;
  srand ( time(NULL) );
  for(int i=0;i<tamanho_chave;i++)
  {
    voltar_rand=0;
    do{


      cor=rand()%numero_cores+1;
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





int main(){
// INICIALIZACAO
srand ( time(NULL) );

  int numero_jogadores=0,tamanho_chave=1,numero_cores=0;

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



  int chave[tamanho_chave];
  char Nome_jogadores[numero_jogadores][20];
  char repetir_cores='e';


  while(repetir_cores!='S' && repetir_cores!='N' && repetir_cores!='s' && repetir_cores!='n'){
    puts("Sera permitido repetir cores: S/N");
    scanf(" %c",&repetir_cores);
  }
  for(int i=0;i<numero_jogadores;i++)
  {
    fflush(stdin);
    puts("\nNome dos jogadores");
    scanf(" %s", Nome_jogadores[i]);
}

criador_chave(chave, numero_cores,tamanho_chave,repetir_cores);
for(int i=0;i<tamanho_chave;i++){
  printf("%c\n",chave[i]);
}
//FIM DA INICIALIZACAO



  return 0;}
