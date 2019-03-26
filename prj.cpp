#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// FUNCAO DE CRIACAO DA CHAVE SENHA//
void criador_chave(char chave[],int numero_cores,int tamanho_chave, char repetir_cores){
  int cor,repeticao[numero_cores],voltar_rand=0,j=0;
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

  int numero_jogadores=0,tamanho_chave=1,numero_cores=0,numero_jogadas,h,tempo_max;

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
while(tempo_max<60||tempo_max>300){
  fflush(stdin);
  puts("\nTempo de maximo por jogada: 60 a 300 segundos");
  scanf(" %d",&tempo_max);
}


  int j,w,y,q,pretas=0,brancas=021;
  char chave[tamanho_chave],nome_jogadores[numero_jogadores][20],escolha[tamanho_chave];
  char repetir_cores='e',vencedor_1,vencedor_2,vencedor_3;
  int i,maior_pretas,menor_t;
  int lista_t[4][1],numero_pretas[4][1], listas_jogadas[4],quantidade_jogos[numero_jogadores][1];
  clock_t end_t=0,start_t=0,timer_t=0;



    while(repetir_cores!='S' && repetir_cores!='N' && repetir_cores!='s' && repetir_cores!='n'){
    puts("\nSera permitido repetir cores S/N:");
    scanf(" %c",&repetir_cores);
  }
  for(i=0;i<numero_jogadores;i++)
  {
    fflush(stdin);
    puts("\nNome dos jogadores max.20:");
    scanf(" %s", nome_jogadores[i]);
}
for(i=0;i<numero_jogadores;i++)
{
  fflush(stdin);
  printf("\n\nQuantos jogos o jogador %s vai fazer, MAX:5\n",nome_jogadores[i]);
  puts("\n");
  scanf(" %d", quantidade_jogos[i]);
}



//FIM DA INICIALIZACAO

/// COMECO DO JOGO
system("cls");

for(int i=0;i<numero_jogadores;i++){ //TROCA DE JOGADOR
  system("cls");




for(int d=0;d<*quantidade_jogos[i];d++){
  printf("\n\nVez do Jogador : %s\nJogada:%d de %d\n",nome_jogadores[i],d,*quantidade_jogos[i]);

  criador_chave(chave, numero_cores,tamanho_chave,repetir_cores);
  for(q=0;q<tamanho_chave;q++){
    printf("%c\n",chave[q]);
  }time(&start_t);
  start_t = (start_t-end_t);
  timer_t=0;

  for(j=0,brancas=0,pretas=0;j<numero_jogadas && pretas!=tamanho_chave && timer_t<=tempo_max ;j++){//CONTAGEM DE JOGADAS

    for(w=0,brancas=0,pretas=0;w<tamanho_chave && timer_t<=tempo_max;w++){
      time(&timer_t);
      timer_t=(timer_t-start_t-end_t);


      puts("Escolha a cor:");
      scanf(" %c",&escolha[w]);
      if(escolha[w]==chave[w]){

      pretas++;}

      }


    for(h=0;h<tamanho_chave;h++){
      for(y=0;y<tamanho_chave;y++){
        if(escolha[y]==chave[h]){
          brancas++;
          break;
        }


      }
    }
    brancas=brancas-pretas;

    printf("P%dB%d\n",pretas,brancas);


    }

  if(timer_t>tempo_max){
    printf("Tempo de jogada acabou\n");
  }
  listas_jogadas[i]=j;


  }
  time(&end_t);
  if((*lista_t[i]>timer_t)&&(*numero_pretas[i]<pretas)){
    *lista_t[i]={timer_t};
    *numero_pretas[i]=pretas;
  }

}



// ESTATICAS

for(i=0,maior_pretas=0,menor_t=0;i<numero_jogadores;i++){
  if(*numero_pretas[i]>maior_pretas){
    if(*lista_t[i]<menor_t){
      vencedor_2=i;
    }
  }

}
printf("Nome do vencedor para jogo mais rapido %s\n",nome_jogadores[vencedor_2]);
return 0;}
