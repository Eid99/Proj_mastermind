#include <stdio.h>
#include <stdlib.h>
void criador_chave(int chave[]){
  int n_chave;
  n_chave=rand()%12-6;
}

int main(){

  int numero_jogadores=0,tamanho_chave=1;

while(numero_jogadores<1 || numero_jogadores>4){
  puts("Quantos Jogadores de 1 a 4:");
  scanf("%d",&numero_jogadores);}
while(tamanho_chave<4 || tamanho_chave>8){
  fflush(stdin);
  puts("Tamanho da chave de 4 a 8:");
  scanf("%d",&tamanho_chave);
}

  int chave[tamanho_chave];
  char Nome_jogadores[numero_jogadores][20];

  for(int i=0;i<numero_jogadores;i++)
  {



    puts("Nome dos jogadores");
    scanf(" %s", &Nome_jogadores[i]);
}
printf("%s", Nome_jogadores[1]);
  return 0;}
