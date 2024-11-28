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
                    printf("\n\t->N�o existe essa informa��o");
                    break;
                }
                flag = 1;
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
NoAvr* Remover_aux(NoAvr *Pai, int num){
   if(Pai == NULL){
    printf("\n\t\tN�o foi encontrado nada.");
   } else {
       if (num > Pai->matricula){
        Pai->dir = Remover_aux(Pai->dir, num);
       }
       else{
        if(num < Pai->matricula){
            Pai->esq = Remover_aux(Pai->esq, num);
        } else{
            if(Pai->dir == NULL && Pai->esq == NULL){
                free(Pai);
                Pai = NULL;
            }
            else{
                if(Pai->esq == NULL){
                    NoAvr *aux = Pai;
                    Pai = Pai->dir;
                    free(aux);
                } else {
                    if(Pai ->esq == NULL){
                        NoAvr *aux = Pai;
                        Pai = Pai->dir;
                        free(aux);
                    }
                    else{
                        NoAvr *aux;
                        aux = Pai -> esq;
                        while(aux->dir != NULL){
                            aux = aux->dir;
                        }
                        Pai->matricula = aux->matricula;
                        strcpy(Pai->nome, aux->nome);
                        Pai->idade = aux->idade;
                        strcpy(Pai->cargo, aux->cargo);
                        Pai->salario = aux->salario;
                        aux->matricula = num;
                        Pai->esq = Remover_aux(Pai->esq, num);
                        }
                    }
                }
            }
        }
    }
    return Pai;
}

Avr* Remover(Avr *Pai, int num ){
    NoAvr *aux = Pai->raiz;
    if(aux->matricula==num && aux->dir==NULL && aux->esq==NULL)
    {
        free(aux);
        free(Pai);
        return NULL;
    }

    Pai->raiz = Remover_aux(Pai->raiz,num);
    return Pai;
}

#endif // ARMAZENAMENTO_RH_H_INCLUDED
