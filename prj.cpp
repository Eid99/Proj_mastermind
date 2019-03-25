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
  char repetir_cores='e';
  int i,maior;
  int lista_t[4],numero_pretas[4], listas_jogadas[4];
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



//FIM DA INICIALIZACAO

/// COMECO DO JOGO
for(int i=0;i<numero_jogadores;i++){ //TROCA DE JOGADOR



printf("\n\nVez do Jogador : %s\n",nome_jogadores[i]);
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
    if (numero_pretas[j]<pretas){
      numero_pretas[j]=pretas;
    }

  if(timer_t>tempo_max){
    printf("Tempo de jogada acabou\n");
  }
  listas_jogadas[i]=j;


  }
  time(&end_t);
  lista_t[i]={timer_t};
}



// ESTATICAS

for(i=0,maior=0;i<numero_jogadores;i++){
  if(lista_t[i]<=lista_t[maior]){
    if(numero_pretas[i]>=numero_pretas[maior]){
    maior=i;
}}}
printf("Nome do vencedor do torneio:Chave acertada em menos tempo\t %s\n",nome_jogadores[maior]);
for(i=0,maior=0;i<numero_jogadores;i++){
  if(numero_pretas[i]>=numero_pretas[maior]){
    if(lista_t[i]<=lista_t[maior]){
    maior=i;
}}}
printf("Nome do vencedor do torneio: Jogador com mais chaves certas em menos tempo medio de jogo.\t  %s\n",nome_jogadores[maior]);


for(i=0,maior=0;i<numero_jogadores;i++){
  if(numero_pretas[i]>=numero_pretas[maior]){
    if(listas_jogadas[i]<=listas_jogadas[maior]){
    maior=i;
    }}}


printf("Nome do vencedor para o jogo mais curto: Chave acertada em menos jogadas\t %s\n",nome_jogadores[maior]);




  return 0;}
