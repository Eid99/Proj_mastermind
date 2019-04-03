#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// FUNCAO DE CRIACAO DA CHAVE SENHA
void criador_chave(char chave[],int numero_cores,int tamanho_chave, char repetir_cores){
  int cor,repeticao[numero_cores],voltar_rand=0,j=0,i;
  srand ( time(NULL) );
  for(i=0;i<tamanho_chave;i++)
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

  int numero_jogadores=0,tamanho_chave=1,numero_cores=0,numero_tentativas,h,tempo_max;


//QUATIDADE DE JOGADORES
while(numero_jogadores<1 || numero_jogadores>4){
  fflush(stdin);
  puts("Quantos Jogadores de 1 a 4:");
  scanf("%d",&numero_jogadores);}


  //NUMERO DE CORES
while(numero_cores<6 || numero_cores>12){
  fflush(stdin);
  puts("\nNumero de cores de 6 a 12:");
  scanf(" %d",&numero_cores);
}

//TAMANHO DA CHAVE SECRETA
while(tamanho_chave<4 || tamanho_chave>8){
  fflush(stdin);
  puts("\nTamanho da chave de 4 a 8:");
  scanf(" %d",&tamanho_chave);
}


//NUMERO DE JOGADAS EM CADA JOGO
while(numero_tentativas<10||numero_tentativas>20){
  fflush(stdin);
  puts("\nNumero de tentativas 10 a 20:");
  scanf(" %d",&numero_tentativas);
}

//TEMPO MAXIMO DE CADA JOGO
while(tempo_max<60||tempo_max>300){
  fflush(stdin);
  puts("\nTempo de maximo por jogada: 60 a 300 segundos");
  scanf(" %d",&tempo_max);
}


  int j,w,y,q,pretas=0,brancas=021,d,i;
  char chave[tamanho_chave],nome_jogadores[numero_jogadores][20],escolha[tamanho_chave];
  char repetir_cores;
  int maior_pretas,menor_t,listas_jogadas2[numero_jogadores],lista_t3[numero_jogadores],listas_jogadas3[numero_jogadores];
  int lista_t2[numero_jogadores],numero_pretas2[numero_jogadores],listas_jogadas[numero_jogadores],quantidade_jogos[numero_jogadores];
  clock_t end_t=0,start_t=0,timer_t=0;
  int numero_pretas3[numero_jogadores], menor_jogadas,tempo_medio[numero_jogadores],numero_pretas1[numero_jogadores],vencedor_1,vencedor_2,vencedor_3;


// REPETICAO DE CORES
    while(repetir_cores!='S' && repetir_cores!='N' && repetir_cores!='s' && repetir_cores!='n'){
    puts("\nSera permitido repetir cores S/N:");
    scanf(" %c",&repetir_cores);
  }

  //NOME DOS JOGADORES
  for(i=0;i<numero_jogadores;i++)
  {
    fflush(stdin);
    puts("\nNome dos jogadores max.20:");
    scanf(" %s", nome_jogadores[i]);
}


//QUANTOS JOGOS CADA JOGADOR IRA FAZER
for(i=0;i<numero_jogadores;i++)
{
  fflush(stdin);
  printf("\n\nQuantos jogos o jogador %s vai fazer, MAX:5",nome_jogadores[i]);
  puts("\n");
  scanf(" %d", &quantidade_jogos[i]);
}



//FIM DA INICIALIZACAO



/// COMECO DO JOGO
system("cls");

for(i=0;i<numero_jogadores;i++){ //TROCA DE JOGADOR
  system("cls");


//VARIAVEIS DAS ESTATISTICAS
numero_pretas2[i]={0};
lista_t2[i]={400};
lista_t3[i]={0};
numero_pretas3[i]={0};
listas_jogadas3[i]={30};
numero_pretas1[i]={0};


for(d=0;d<quantidade_jogos[i];d++){// INICIALIZACAO DE DIFERENTES JOGOS
  system("cls");
  printf("\n\nVez do Jogador : %s\nJogada:%d de %d\n",nome_jogadores[i],d+1,quantidade_jogos[i]);

  criador_chave(chave, numero_cores,tamanho_chave,repetir_cores);
  for(q=0;q<tamanho_chave;q++){
    printf("%c\n",chave[q]);
  }

  time(&start_t);
  start_t = (start_t-end_t);
  timer_t=0;

  for(j=0,brancas=0,pretas=0;j<numero_tentativas && pretas!=tamanho_chave && timer_t<=tempo_max ;j++){//CONTAGEM DE JOGADAS
    printf("\n\nTentativa:%d de %d\n", j+1,numero_tentativas);

    for(w=0,brancas=0,pretas=0;w<tamanho_chave && timer_t<=tempo_max;w++){
      time(&timer_t);
      timer_t=(timer_t-start_t-end_t);
      fflush(stdin);
      puts("Escolha a cor:");
      scanf(" %c",&escolha[w]);
      if(escolha[w]==chave[w]){//CONTAGEM POSICOES CERTAS

      pretas++;}

      }


    for(h=0;h<tamanho_chave;h++){// CONTAGEM DE CORES CERTAS
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
  }time(&end_t);
}


// CALCULO DA ESTATISTICAS 1

tempo_medio[i]+=timer_t;
if(numero_pretas1[i]<=pretas){
  numero_pretas1[i]=pretas;

}



  // CALCULO DA ESTATISTICAS 2

  if((lista_t2[i]>timer_t)&&(numero_pretas2[i]<=pretas)){

    lista_t2[i]={timer_t};
    numero_pretas2[i]=pretas;
    listas_jogadas2[i]=j;
  }


    // CALCULO DA ESTATISTICAS 3
    if((lista_t3[i]<timer_t)&&(listas_jogadas3[i]>j)){
      lista_t2[i]=timer_t;
      numero_pretas3[i]=pretas;
      listas_jogadas3[i]=j;}






}
// CONTINUACAO DO CALCULO DA ESTATISTICAS 1

for(i=0;i<numero_jogadores;i++){
  tempo_medio[i]/=quantidade_jogos[i];
}


//ESTATICAS 1
for(i=0,maior_pretas=0,menor_t=400;i<numero_jogadores;i++){
  if(numero_pretas1[i]>maior_pretas){
    if(tempo_medio[i]<menor_t){
      vencedor_1=i;
      menor_t=tempo_medio[i];
      maior_pretas=numero_pretas1[i];}}}
      system("cls");

  printf("\nNome do vencedor do torneio: %s\n",nome_jogadores[vencedor_1]);





// ESTATISTICAS 2

for(i=0,maior_pretas=0,menor_t=400, menor_jogadas=499;i<numero_jogadores;i++){
  if(numero_pretas2[i]>maior_pretas){
    if(lista_t2[i]<menor_t){
      vencedor_2=i;
      menor_t=lista_t2[i];
      maior_pretas=numero_pretas2[i];
      menor_jogadas=listas_jogadas[i];



    }
    else if(lista_t2[i]==menor_t && listas_jogadas[i]<menor_jogadas){
        vencedor_2=i;
        menor_t=lista_t2[i];
        maior_pretas=numero_pretas2[i];
        menor_jogadas=listas_jogadas2[i];

      }
    }}
printf("\nNome do vencedor para jogo mais rapido %s\n",nome_jogadores[vencedor_2]);





// ESTATISTICAS 3
for(i=0,maior_pretas=0,menor_t=400, menor_jogadas=499;i<numero_jogadores;i++){
if(numero_pretas3[i]>maior_pretas){
  if(listas_jogadas[i]<menor_jogadas){
    vencedor_3=i;
    menor_t=lista_t3[i];
    maior_pretas=numero_pretas3[i];
    menor_jogadas=listas_jogadas3[i];



  }
  else if(lista_t3[i]==menor_t && lista_t2[i]<menor_t){
      vencedor_3=i;
      menor_t=lista_t3[i];
      maior_pretas=numero_pretas3[i];
      menor_jogadas=listas_jogadas3[i];
    }}}


    printf("\nNome do vencedor para jogo mais curto %s\n",nome_jogadores[vencedor_3]);




return 0;}
