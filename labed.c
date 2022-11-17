#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa
{
    char nome[15];
    int idade, dose1, dose2; // considere valor 1 para vacinado e 0 não vacinado
    char vacina[10];         // nome da vacina que tomou na 1ª dose
    struct Pessoa *pprox;
} TPessoa;

typedef struct Cabeca
{
    TPessoa *pY;
    TPessoa *pZ;
} TCabeca;
/*
TPessoa *inserelistainiciopy(TCabeca *pprim, FILE *parquivo);
TPessoa *inserelistainiciopz(TCabeca *pprim, FILE *parquivo);
TPessoa *unificar(TPessoa *p1, TPessoa *p2);
*/
TCabeca *criaLista();
void insereLista(TCabeca *pprim, FILE *p);
int lerArquivoY(FILE *parquivo);
void imprimeLista(TPessoa *p);
TPessoa *alocaNo(FILE *parquivo);
TPessoa *unificar(TPessoa *p1, TPessoa *p2, TCabeca *cabeca);

int main()
{
    FILE *p1, *p2;
    TCabeca *prim = NULL;
    int op = 1, op3;
	TCabeca *cabeca = criaLista();
    while (op != 5)
    {
        printf("1 - Unificar arquivos de dados - Pessoas\n2 - Busca pessoa - Vacinar\n3 - Imprimir informacoes das pessoas\n4 - Desalocar todas as pessoas\n5 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        	case 1:
        	{
                p1 = fopen("postoY.dat", "r");
                //p2 = fopen("postoZ.dat", "r");
            	int contY, contZ;
                TPessoa *teste = NULL;
            	contY = lerArquivoY(p1);
            	//contZ = lerArquivoY(p2);
            	//printf("%d %d\n", contY, contZ);
                insereLista(cabeca, p1);
                imprimeLista(cabeca->pY);
        	}break;
            case 3:
            {
                printf("1-Pessoas posto Y\n 2-Pessoas posto Z\n 3-Pessoas posto YZ\n");
                lerarquvios(op3, cabeca);

            }break;
            case 4:
            {
                desaloca(cabeca,p1,p2,p1);//Falta o arquivo unificado pra chamada da função free no lugar do p1
            }break;
        }
    }

    //fclose(p1);
    //fclose(p2);
}

void insereLista(TCabeca *pprim, FILE *p)
{
    while(!(feof(p)))
    {
        TPessoa *novo=alocaNo(p), *aux=NULL;
	    if (novo == NULL) return;
        if(pprim->pY == NULL)
        {
            pprim->pY = novo;
            printf("Opa\n");
            return;
        }
	    aux = pprim->pY;
        pprim->pY = novo;
        novo->pprox = aux;
        aux->pprox = NULL;
    }
    return;
}
void imprimeLista(TPessoa *p)
{
	if(p)
	{
		while(p)//while(p)
		{
			printf("%s %d %d %d %s\n", p->nome, p->idade, p->dose1, p->dose2, p->vacina);
			p = p->pprox;
		}
	}
	else
    {
        printf("\nLista vazia!");
    }
}

TPessoa *lerarquvios(int op3, TCabeca *cabeca)//opcao 3 ler listas
{
    scanf("%d", &op3);
    switch(op3)
    {
        case 1:
        {
            for(TPessoa *tmp = cabeca->pY; tmp != NULL; tmp = tmp->pprox)
            {
                printf("%s %d %d %d %s\n", tmp->nome, tmp->idade, tmp->dose1, tmp->dose2, tmp->vacina);
            }
        }break;
        case 2:
        {
            for(TPessoa *tmp = cabeca->pZ; tmp != NULL; tmp = tmp->pprox)
            {
                printf("%s %d %d %d %s\n", tmp->nome, tmp->idade, tmp->dose1, tmp->dose2, tmp->vacina);
            }
        }break;
        case 3:
        {
            for(TPessoa *tmp = cabeca->pZ; tmp != NULL; tmp = tmp->pprox)//Aqui muda o posto para o unificado, no tmp = cabeca->pZ para tmp = cabeca->pYZ
            {
                printf("%s %d %d %d %s\n", tmp->nome, tmp->idade, tmp->dose1, tmp->dose2, tmp->vacina);
            }
        }break;
        default:
        {
            printf("numero invalido, informe outro\n");
            scanf("%d", &op3);
        }
    }
    return NULL;
}

TPessoa *alocaNo(FILE *parquivo)
{
    TPessoa *novo = NULL;
    novo = (TPessoa *)malloc(sizeof(TPessoa));
    if(novo)
    {
        fscanf(parquivo, "%s %d %d %d %s\n", novo->nome, &novo->idade, &novo->dose1, &novo->dose2, novo->vacina);
        printf("linha\n");
    }
    else
    {
        return NULL;
    }
    novo->pprox = NULL;
    return(novo);
}

TCabeca *criaLista()
{
	TCabeca *cabeca=NULL;
	cabeca = (TCabeca *)malloc(sizeof(TCabeca));
	if (cabeca == NULL) return NULL;
	cabeca->pY = NULL;
	cabeca->pZ = NULL;
	return cabeca;
}

TPessoa *unificar(TPessoa *p1, TPessoa *p2, TCabeca *cabeca)
{
    TPessoa *p3 = NULL;
    p3 = (TPessoa *)malloc(sizeof(TPessoa));
  	if(!p3) return NULL;
  	if(cabeca->pY == NULL)
    {
      p3->pprox = cabeca->pY;
      cabeca->pY = p3;
      cabeca->pZ = p3;
    }
  	else
  	{
    	p3->pprox = cabeca->pY;
      	cabeca->pY = p3;
  	}
}

int lerArquivoY(FILE *parquivo)
{
    TPessoa *temp = NULL;
    temp = (TPessoa *)malloc(sizeof(TPessoa));
    char nome[15];
    char vacina[10];
    int idade, dose1, dose2;
    int cont = 0;
    while (!feof(parquivo))
    {
        fscanf(parquivo, "%s %d %d %d %s\n", temp->nome, &temp->idade, &temp->dose1, &temp->dose2, temp->vacina);
        cont++;
    }
    free(temp);
    temp = NULL;
    return cont;
}

TCabeca *desaloca(TCabeca *Cabeca, TPessoa *p1, TPessoa *p2, TPessoa *p3)//opcao 4
{
    TPessoa *tmp = NULL, *tmp2 = NULL, *tmp3 = NULL;
    while(p1)
    {
        tmp = p1->pprox;
        free(p1);
        p1 = tmp;
        printf("Free p1\n");
    }
    printf("list 1 esvaziada ou lista vazia\n");
    while(p2)
    {
        tmp = p2->pprox;
        free(p2);
        p2 = tmp;
        printf("Free p2\n");
    }
    printf("list 2 esvaziada ou lista vazia\n");
    while(p3)
    {
        tmp = p3->pprox;
        free(p3);
        p3 = tmp;
        printf("Free p3\n");
    }
    printf("list 3 esvaziada ou lista vazia\n");
    return NULL;
}
