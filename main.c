#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "math.h"
#include "funcoes.h"
#define TRUE 1
#define FALSE 0


//edited by tgloureiro
//Cabecalho para o temporizador
#ifdef _WIN32
#include <time.h>
#else
#include <sys/times.h>
#include <sys/unistd.h>
#endif


//Funcao para calculo do tempo do programa
float getTime() {
#ifdef _WIN32
    clock_t start = clock();
    return (float)start / CLOCKS_PER_SEC;
#else
    struct tms tempo;
    clock_t tempotic;
    float cpt = sysconf(_SC_CLK_TCK);
    times(&tempo);
    tempotic = tempo.tms_utime ;
    return ( (float) (tempotic/cpt) );
#endif
}


int main()
{
    int i;
    int Vertice;
    int Aresta;
    int v1,v2;
    int k;
    int temp;
    int rodadamenor = 10000;

    int *vet;
    int *num;
    int **grafomatrix;
    int *vet_perm;
    int *vet_aux;

    //CALCULO DO TEMPO DE EXECUCAO DO PROGRAMA
    // O tempo eh calculado como a subtracao de dois tempos
    int K = 10000000;
    float s = getTime();
    int* vec = (int*) malloc (K * sizeof(int));
    for (i = 0; i < K; i++) {
        vec[i] = i;
    }
    //Fim da execucao do tempo de programa


    scanf("%d", &Vertice);

    vet = (int*)calloc(Vertice+1,sizeof(int));
    num = (int*)calloc(Vertice+1,sizeof(int));
    vet_aux = (int*)calloc(Vertice,sizeof(int));
    vet_perm = (int*)calloc(Vertice,sizeof(int));

    //Cria Grafo
    grafomatrix = (int**)calloc(Vertice,sizeof(int*)); //Criacao do grafo em memoria dinamica(Matriz adjacente de 2 dimensoes)
    for(i = 0; i < Vertice; i++)
    {
        grafomatrix[i] = (int*)calloc(Vertice,sizeof(int));//alocação de uma coluna completa para o grafo; Todo o conteudo inicia com 0, por causa do calloc.
    }

    scanf("%d",&Aresta) ;

    for(i = 0; i < Aresta; i++)
    {
        scanf("%d %d",&v1,&v2);

        grafomatrix[v1-1][v2-1] = 1; //Preenchimento do grafo nao-direcional
        grafomatrix[v2-1][v1-1] = 1;
        // printf("[%d][%d] = %d\n", v1-1, v2-1, grafomatrix[v1-1][v2-1]);
    }

    // Criar os Vetores de Permutação 
    for(i = 1; i <= Vertice; i++)
    {
        vet[i-1] = i;
        //printf("%d ",vet[i-1]);
    }
    //printf("\n");


    // Realiza a Permutação 
    for(k = 1 ; k <= Vertice; k++)
    {
        num[k] = 1;
    }

    num[Vertice] = 0;
    temp = Vertice;

    while(1)
    {
        if(num[temp]==Vertice)
        {
            temp--;
            if(temp == 0)
            {
                break;
            }
        }
        else
        {
            num[temp]++;
            while(temp < Vertice)
            {
                temp++;
                num[temp]=1;
            }
 
            for(k = 1; k <= Vertice; k++)
            {
                vet_perm[k-1] = num[k];
                //printf("%d ", vet_perm[k-1]);
            }
            //printf("\n");

            Verifica(grafomatrix,vet_aux,vet_perm,Vertice,&rodadamenor);
        }
    }


    printf("\nTempo gasto em segundos: %.5fs\n\n", getTime() - s);
    free(vec);
    //Free
    free(vet);
    free(vet_perm);
    free(num);
    free(vet_aux);
    for(i = 0; i< Vertice;i++)
    {
        free(grafomatrix[i]);
    }
    free(grafomatrix);


    return 0;
}

