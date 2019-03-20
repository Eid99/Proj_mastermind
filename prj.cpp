#include <stdio.h>
int main(){
  int numero_jogadores;
  puts("Quantos Jogadores");
  scanf("%d",&numero_jogadores);
char Nome_jogadores[numero_jogadores][20];

  for(int i=0;i<numero_jogadores;i++)
  {



    puts("Nome dos Nome jogadores");
    scanf(" %s", Nome_jogadores[i]);
}
printf("%s", Nome_jogadores[1]);
  return 0;}
