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
TPessoa *alocaNo();

int main()
{
    FILE *p1, *p2;
    TCabeca *prim = NULL;
    int op = 1;
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
            	//contY = lerArquivoY(p1);
            	//contZ = lerArquivoY(p2);
            	//printf("%d %d\n", contY, contZ);
                insereLista(cabeca, p1);
                imprimeLista(cabeca->pY);
        	}
        }
    }

    //fclose(p1);
    //fclose(p2);
}

void insereLista(TCabeca *pprim, FILE *p)
{
    while(!feof(p))
    {
        TPessoa *novo=alocaNo(p), *aux=NULL;
	    if (novo == NULL) return;
        if(pprim->pY == NULL)
        {
            pprim -> pY = novo;
            return;
        }
	    aux = pprim->pY;
        pprim->pY = novo;
        novo->pprox = aux;
        aux->pprox = NULL;
    }
}
void imprimeLista(TPessoa *p)
{
	if(p)
	{
		while(p!=NULL)//while(p)
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
TPessoa *alocaNo(FILE *parquivo)
{
    TPessoa *novo = NULL;
    novo = (TPessoa *)malloc(sizeof(TPessoa));
    if(novo)
    {
        fscanf(parquivo, "%s %d %d %d %s\n", novo->nome, &novo->idade, &novo->dose1, &novo->dose2, novo->vacina);
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

/*int lerArquivoY(FILE *parquivo)
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
}*/
