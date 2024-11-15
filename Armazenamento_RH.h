#ifndef ARMAZENAMENTO_RH_H_INCLUDED
#define ARMAZENAMENTO_RH_H_INCLUDED

typedef struct Nos
{
    int matricula;
    char nome[40];
    int idade;
    char cargo[25];
    float salario;
    struct Nos *dir;
    struct Nos *esq;

}NoAvr;

typedef struct funcionarios
{
    int matricula;
    char nome[40];
    int idade;
    char cargo[25];
    float salario;
}Funcionarios;

typedef struct avr
{
    NoAvr *raiz;
}Avr;


void imprimeArvIN(NoAvr *A){

    if (A == NULL){
        printf("\t\nArvore esta vazia!!");
        return;
    }else{
        printf("%d\t\t%-10s\t%d\t%-15s\t%.2f\n", A->matricula, A->nome, A->idade, A->cargo, A->salario);
        if(A->dir != NULL){
            imprimeArvIN(A->dir);
        }
        if(A->esq != NULL){
            imprimeArvIN(A->esq);
        }
    }
}

void imprimeArvPOS(NoAvr *A){

    printf("Matricula\tNome\t\tIdade\tCargo\t\t\tSal�rio\n");
    printf("---------------------------------------------------------------\n");

    if (A == NULL){
        printf("\t\nArvore esta vazia!!");
        return;
    }else{
        if(A->dir != NULL){
            imprimeArvPOS(A->dir);
        }
        if(A->esq != NULL){
            imprimeArvPOS(A->esq);
        }
        printf("%d\t\t%-10s\t%d\t%-15s\t%.2f\n", A->matricula, A->nome, A->idade, A->cargo, A->salario);
    }
}

void BuscaNaArvore(NoAvr *A, int alt, int matricula, char *novo_nome, int nova_idade, char *novo_cargo, float novo_salario)
{
    int flag;
    NoAvr *Pai;
    if(A == NULL)
    {
        printf("\n�rvore vazia, sem elementos para a busca.");
        return;
    }
    else
    {
        Pai = A;
        flag = 0;
        while(flag == 0)
        {
            if(Pai->matricula <= matricula)
            {
                if(Pai->dir==NULL)
                {
                    if(alt == 0){
                        strcpy(Pai->nome, novo_nome);
                        flag = 1;
                    }else if(alt == 1){
                        Pai->idade = nova_idade;
                        flag = 1;
                    }else if(alt == 2){
                        strcpy(Pai->cargo, novo_cargo);
                        flag = 1;
                    }else{
                        Pai->salario = novo_salario;
                        flag = 1;
                    }
                }
                else

                {
                    Pai->dir=Pai;
                }
            }
            else
            {
                if(Pai->esq==NULL)
                {
                    if(alt == 0){
                       strcpy(Pai->nome, novo_nome);
                        flag = 1;
                    }else if(alt == 1){
                        Pai->idade = nova_idade;
                        flag = 1;
                    }else if(alt == 2){
                        strcpy(Pai->cargo, novo_cargo);
                        flag = 1;
                    }else{
                        Pai->salario = novo_salario;
                        flag = 1;
                    }
                }
                else
                {
                    Pai->esq=Pai;
                }
            }
        }
    }
}

Avr* CriaArvore()
{
    Avr *aux;
    aux= (Avr*)malloc(sizeof(Avr));
    aux-> raiz = NULL;
    return aux;
}

int VaziaArvore(Avr* A)
{
    if(A-> raiz == NULL)
    {
        return 1;
    }
    return 0;
}

NoAvr * aux_insere(NoAvr *no, int matricula, char *nome, int idade, char *cargo, float salario){

    int flag;
    NoAvr *Pai;
    NoAvr *novo = (NoAvr*)malloc (sizeof(NoAvr));
    novo->matricula = matricula;
    strcpy(novo->nome, nome);
    novo->idade = idade;
    strcpy(novo->cargo, cargo);
    novo->salario = salario;

    novo->esq = NULL;
    novo->dir = NULL;
    if(no == NULL){
        return novo;
    } else {
        Pai = no;
        flag = 0;
        while(flag==0){
            if(Pai->matricula<matricula)
            {
                if(Pai->dir == NULL)
                {
                    Pai->dir = novo;
                    flag = 1;
                } else
                {
                    Pai = Pai->dir;
                }
            } else
            {
                if(Pai->matricula > matricula)
                {
                    if(Pai->esq == NULL)
                    {
                        Pai->esq = novo;
                        flag = 1;
                    }else
                    {
                        Pai = Pai->esq;
                    }
                }
            }
        }
    }
    return no;
}

void insere_Arvore(Avr *arvore, int matricula, char *nome, int idade, char *cargo, float salario){

    arvore->raiz = aux_insere(arvore->raiz, matricula, nome, idade, cargo, salario);

}




#endif // ARMAZENAMENTO_RH_H_INCLUDED
