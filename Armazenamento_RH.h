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

    printf("Matricula\tNome\t\tIdade\tCargo\t\t\tSalário\n");
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

void aumentaC(char cargo[25]){
    int tam = 23;
    size_t comp = strlen(cargo);

    if(comp > 0 && cargo[comp - 1] == '\n'){
        cargo[comp-1] = '\0';
    }
    for(int i = comp; i < tam; i++){
        cargo[i] = ' ';
    }
}

void aumentaN(char nome[40]){
    int tam = 36;
    size_t comp = strlen(nome);
    if(comp > 0 && nome[comp -1] == '\n'){
        nome[comp-1] = '\0';
    }
    for(int i = comp; i < tam; i++){
        nome[i] = ' ';
    }
}

void BuscaNaArvore(NoAvr *A, int alt, int matricula, char *novo_nome, int nova_idade, char *novo_cargo, float novo_salario)
{
    int flag;
    NoAvr *Pai;
    if(A == NULL){
        printf("\n\t->Sua arvore esta vazia");
        return;
    } else {
        Pai = A;
        flag = 0;
        while(flag==0){
            if(Pai->matricula < matricula){
                Pai = Pai->dir;
            } else if (Pai->matricula > matricula){
                Pai = Pai->esq;
            } else{
                switch(alt){
                case 0:
                    strcpy(Pai->nome, novo_nome);
                    break;
                case 1:
                    Pai->idade = nova_idade;
                    break;
                case 2:
                    strcpy(Pai->cargo, novo_cargo);
                    break;
                case 3:
                    Pai->salario = novo_salario;
                    break;
                default:
                    printf("\n\t->Não existe essa informação");
                    break;
                }
                flag = 1;
            }
        }

    }

}

void BuscaInfo(NoAvr *A, int matricula)
{
    int flag;
    NoAvr *Pai;
    if(A == NULL){
        printf("\n\t->Sua arvore esta vazia");
        return;
    } else {
        Pai = A;
        flag = 0;
        while(flag==0){
            if(Pai->matricula < matricula){
                Pai = Pai->dir;
            } else if (Pai->matricula > matricula){
                Pai = Pai->esq;
            } else{
                printf("\n\t\t->funcionario encontrado\n\n");
                printf("Matricula\tNome\t\tIdade\tCargo\t\t\tSalário\n\n");
                printf("%d\t\t%-10s\t%d\t%-15s\t%.2f\n", Pai->matricula, Pai->nome, Pai->idade, Pai->cargo, Pai->salario);

                flag = 1;
            }
        }

    }

}

NoAvr* MaisVelho(NoAvr *A) {
    if (A == NULL) {
        printf("\n\t-> A árvore está vazia!\n");
        return NULL;
    }

    NoAvr *maisVelho = A;
    if (A->esq != NULL) {
        NoAvr *esquerdo = MaisVelho(A->esq);
        if (esquerdo != NULL && esquerdo->idade > maisVelho->idade) {
            maisVelho = esquerdo;
        }
    }
    if (A->dir != NULL) {
        NoAvr *direito = MaisVelho(A->dir);
        if (direito != NULL && direito->idade > maisVelho->idade) {
            maisVelho = direito;
        }
    }

    return maisVelho;
}

NoAvr* MaisNovo(NoAvr *A) {
    if (A == NULL) {
        printf("\n\t-> A árvore está vazia!\n");
        return NULL;
    }

    NoAvr *maisNovo = A;
    if (A->esq != NULL) {
        NoAvr *esquerdo = MaisNovo(A->esq);
        if (esquerdo != NULL && esquerdo->idade < maisNovo->idade) {
            maisNovo = esquerdo;
        }
    }
    if (A->dir != NULL) {
        NoAvr *direito = MaisNovo(A->dir);
        if (direito != NULL && direito->idade < maisNovo->idade) {
            maisNovo = direito;
        }
    }

    return maisNovo;
}

void BuscaCargo(NoAvr *A, char *cargo) {

    if (A == NULL) {
        return;
    }
    NoAvr *Pai = A;


    if (strcmp(Pai->cargo, cargo) == 0) {
         printf("%d\t\t%-10s\t%d\t%-15s\t%.2f\n", Pai->matricula, Pai->nome, Pai->idade, Pai->cargo, Pai->salario);
    }
    if (Pai->esq != NULL) {
        BuscaCargo(Pai->esq, cargo);
    }
    if (A->dir != NULL) {
        BuscaCargo(Pai->dir, cargo);
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
