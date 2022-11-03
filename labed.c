#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa
{
    char nome[15];
    int idade, dose1, dose2; //considere valor 1 para vacinado e 0 não vacinado
    char vacina[10]; //nome da vacina que tomou na 1ª dose
    struct Pessoa *pprox;
}TPessoa;
typedef struct Cabeca
{
    TPessoa*pY;
    TPessoa*pZ;
}TCabeca;

TPessoa* unificar(TPessoa *p1, TPessoa *p2);
TPessoa* ler(TPessoa *p1, TPessoa *p2);

int main()
{
    FILE* p1=NULL, p2=NULL;
    TCabeca *prim=NULL;
    int op=1;
    p1 = fopen("r", "postoY.dat");
    p2 = fopen("r", "postoZ.dat");
    while(op != 5)
    {
        printf("1 - Unificar arquivos de dados - Pessoas\n2 - Busca pessoa – Vacinar\n3 – Imprimir informações das pessoas\n4 – Desalocar todas as pessoas\n5 - Sair");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
            {
                
            }
        }
    }

    fclose(p1);
    fclose(p2);
}

TPessoa* unificar(TPessoa *p1, TPessoa *p2)
{
    TPessoa* p3=NULL;
    p3 =(TPessoa*) malloc(sizeof(TPessoa));
    
}
TPessoa* inserelistainiciopy(TCabeca *pprim, FILE *parquivo)
{
    char nome[15];
    char vacina[10];
    if((pprim->pY))
    {
        return *pprim;
    }
    pprim->pY =(TPessoa) malloc(sizeof(TPessoa));
    


}

TPessoa* inserelistainiciopy(TCabeca *pprim, FILE *parquivo)
{

    if(!(pprim->pZ))
    {

    }

}

TPessoa* ler(TPessoa *p1, TPessoa *p2)
{

}