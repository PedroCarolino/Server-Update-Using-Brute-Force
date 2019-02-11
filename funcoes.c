#include "funcoes.h"

void Verifica(int **grafomatrix, int *vet_aux, int *vet_perm, int Vertice, int *rodadamenor)
{
    int i,j,rodada,ac;
    int flag[Vertice];
    int temp;

    flag[0] = 1;
    //printf("flag[0] = %d\n",flag[0]);
    for(i = 0; i < Vertice; i++) //Andando no Nó
    {
        for(j = i+1; j < Vertice; j++) //Andando na linha do Nó
        {
            //printf("valor i = %d\n",i);
            //printf("valor j = %d\n", j);
            //printf("grafomatrix[%d][%d] = %d\n",i,j,grafomatrix[i][j]);
            if(grafomatrix[i][j] == 1)
            {
                //printf("Vet_perm[i] = %d\n",vet_perm[i]);
                //printf("Vet_perm[j] = %d\n",vet_perm[j]);

                if(vet_perm[i] == vet_perm[j])
                {
                    //printf("Sao vizinhos e estao na mesma rodada\n");
                    //printf("Break\n");
                    temp = flag[i];
                    flag[j] = temp + 1;
                    //printf("flag v[%d] = %d\n",j,flag[j]);
                    break;
                }
                else
                {
                    //printf("Sao vizinhos e estao em rodadas diferentes\n");
                    flag[j] = vet_perm[j];
                    //printf("flag nv[%d] = %d\n",j,flag[j]);
                }
            }
            else
            {
                //printf("Vet_perm[i] = %d\n",vet_perm[i]);
                //printf("Vet_perm[j] = %d\n",vet_perm[j]);
                if(vet_perm[i] == vet_perm[j])
                {
                    //printf("Não sao vizinhos e estao na msma rodada\n");
                    flag[j] = flag[i];
                    //printf("flag nv[%d] = %d\n",j,flag[j]);
                }
                else
                {
                    //printf("Não sao vizinhos e nao estao na mesma rodada\n");
                    flag[j] = flag[i];

                }
            }
        }
    }

    ac = 0;
    rodada = 0;

    for(i = 0; i < Vertice; i++)
    {
        //printf("flag final[%d] = %d\n",i,flag[i]);
        if(flag[i] == vet_perm[i])
        {
            //printf("deu bom \n");
            ac++;
        }
    }
    if(ac == Vertice)
    {
        rodada = calc_maior(vet_perm, Vertice);
        //printf("rodada = %d\n",rodada);

        if(rodada < *rodadamenor)
        {
            *rodadamenor = rodada;
            printf("rodadamenor = %d\n",*rodadamenor);

            for(i = 0; i < Vertice; i++)
            {
                vet_aux[i] = flag[i];
                printf("vet_final[%d] = %d ",i,vet_aux[i]);
                printf("\n");   
            } 

            Imprime(&*rodadamenor,vet_aux,Vertice);         
        }
    } 

}

int calc_maior(int *vet_perm, int Vertice)
{
    int i, maior;

    maior = vet_perm[0];
    for(i = 0; i < Vertice; i++)
    {
        if(vet_perm[i] >= maior)
        {
            maior = vet_perm[i];
        }
    }   

    return maior; 
}


void Imprime(int *rodadamenor, int *vet_aux, int Vertice)
{
    int i = 0;
    FILE *arq_saida_rodada;
    FILE *arq_saida_alocacao;

    arq_saida_rodada = fopen("rodada.txt","w");
    arq_saida_alocacao = fopen("alocacao.txt","w");

    fprintf(arq_saida_rodada,"%d\n",*rodadamenor);

    for(i = 0; i < Vertice; i++)
    {
        fprintf(arq_saida_alocacao,"%d %d\n",i+1,vet_aux[i]);
    }

    fclose(arq_saida_alocacao);
    fclose(arq_saida_rodada);
}

