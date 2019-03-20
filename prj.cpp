#include <stdio.h>
#include <stdlib.h>
void criador_chave(int chave[],int numero_cores,int tamanho_chave){
  for(int i=0;i<tamanho_chave;i++)
  {
    chave[i]=rand()%numero_cores;
  }
}

int main(){

  int numero_jogadores=0,tamanho_chave=1,numero_cores=0;

while(numero_jogadores<1 || numero_jogadores>4){
  puts("Quantos Jogadores de 1 a 4:");
  scanf("%d",&numero_jogadores);}
while(numero_cores<6 || numero_cores>12){
puts("\nNumero de cores de 6 a 12:");
scanf("%d",&numero_cores);
}
while(tamanho_chave<4 || tamanho_chave>8){
  fflush(stdin);
  puts("\nTamanho da chave de 4 a 8:");
  scanf("%d",&tamanho_chave);
}

  int chave[tamanho_chave];
  char Nome_jogadores[numero_jogadores][20];

  for(int i=0;i<numero_jogadores;i++)
  {

    puts("\nNome dos jogadores");
    scanf(" %s", Nome_jogadores[i]);
}
printf("%s", Nome_jogadores[1]);
  return 0;}
