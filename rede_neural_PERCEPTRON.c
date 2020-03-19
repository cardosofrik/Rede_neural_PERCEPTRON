#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define entrada 3
#define saida 2
#define in 4

int main(){
    float w[entrada][saida],err,erro[saida], ni[saida],errom, bias, eta, entradas[in][saida], saidas[in][saida], phi[saida];

    int x, cont, contt, contin = 0, epocas,testeerro = 0, funcao;
   
   char continuar = 's';
   for (x=0; x < entrada; x++)
      for (cont=0; cont < saida; cont++)
          w[x][cont] = 0;

   printf("[ B  ] - entrada de valor de bias : ");
   scanf("%f", &bias);
   printf("[ AP ] - entrada de valor de aprendizagem : ");
   scanf("%f", &eta);
   printf("[ I  ] -entrada de valor de interacao : ");
   scanf("%d", &epocas);
   printf("[ R  ] - entrada de valor, quantidade de erros esperados : ");
   scanf("%f", &err);
   printf("=====================================================\n");
   printf("Qual funcao deseja usar :\n1 - Degraus.\n2 - Sigmoide\n");
   scanf("%d", &funcao);
   printf("=====================================================\n");
   printf("[ INF ] - Informe os Dados de Entrada e Saida para o Treinamento.\n\n");

   for ( x=0; x < in ; x++)
     for (cont=0; cont < saida ; cont++){
         printf("[ N ] - entrada %d, neuronio %d : ", x + 1, cont + 1);
         scanf("%f", &entradas[x][cont]);
         }
    printf("=====================================================\n");
   for ( x=0; x < in ; x++)
     for( cont=0; cont < saida; cont++){
         printf("[ S ] - saida %d neuronio %d : ",x + 1, cont + 1);
         scanf("%f", &saidas[x][cont]);
   printf("[ inf ] - Todos os pesos iniciais sao zero.\n[ inf ] - Inicializando o processo Interativo\n");


   cont = 0 ;
   while((cont < epocas) && !testeerro && (continuar != 'n'))
     cont++;
     printf("Interacao >> %d  \n", cont);

     for (x=0; x< entrada -1; x++)
       printf("Entradas >>  %f  \n", entradas[contin][x]);

     for ( x=0; x < saida; x++){
       ni[x] = ni[x] + w[contt + 1][x]*entradas[contin][contt];

       switch(funcao){
         case 1:
              if (ni[x] > 0) phi[x] = 1;
              else phi[x] = 0;
              break;
         case 2:
              phi[x] = 1/(1 + exp(-ni[x]));
              break;
         }
    erro[x] = saidas[contin][x] -phi[x];
    printf("[ inf ] - Saida Desejada :  %f \n", saidas[contin][x]);
    printf("[ inf ] -  Saida da rede: %f \n", phi[x]);
    
    errom = 0;
    for ( x=0; x < saida; x++)
     errom = errom + erro[x] / saida;
     printf("[ MEDIO ] - Erro Geral:  %f \n", errom);
     for ( x=0; x < saida; x++)
        if ( abs(errom) < err) testeerro = 1;
        else testeerro = 0;
    printf("\n=====================================================\n");
    printf("[ C ] -Corrigindo pesos");
    printf("\n=====================================================\n");
    for ( x=0; x < entrada; x++)
      for ( contt = 0 ; contt < saida; contt++)
         if (x == 0) w[x][contt] = w[x][contt] + eta * erro[contt]*bias;
         else w[x][contt] = w[x][contt] + eta * erro[contt] * entradas[contin][x - 1];

    for ( x=0; x < entrada; x++)
      for (cont=0; contt <  saida; contt++)
        printf("w[%d][%d] = %f\n", x, contt, w[x][contt]);
    printf("[ INF ] - Inicializar novamente ?\n");
    scanf("%c", &continuar);
    contin++;
    if( contin > entrada) contin = 0;
        printf("Finalizado\n");
}
}


}


































