#ifndef ARMAZENAMENTO_RH_H_INCLUDED
#define ARMAZENAMENTO_RH_H_INCLUDED

typedef struct Nos
{
    int info;
    Nos *dir;
    Nos *esq;
}NoAvr;

typedef struct Avr
{
    NoAvr* raiz;
}Avr;

Avr* CriaArvore()
{
    Avr *aux;
    aux= (Avr*)malloc(sizeof(Avr));
    aux-> raiz = NULL;
    return aux;
}

int VaziaArvore(Arv* A)
{
    if(A-> raiz == NULL)
    {
        return 1;
    }
    return 0;
}

NoAvr* aux_InsereArv(NoAvr *A, int num)
{
    NoAvr *Pai;
    NoAvr *novo = (NoAvr)malloc(sizeof(NoAvr));
    novo->info=num;
    novo->esq=NULL;
    novo->dir=NULL;

    if(A == NULL)
    {
        return novo;
    }
    else
    {
        Pai = A;
        flag = 0;
        while(flag == 0)
        {
            if(Pai->info<num)
            {
                if(Pai->dir==NULL)
                {
                    Pai->info = novo;
                    flag = 1;
                }
                else
                {
                    Pai->dir=Pai;
                }
            }
            else(Pai->info>num)
            {
                if(Pai->esq==NULL)
                {
                    Pai->info = novo;
                    flag = 1;
                }
                else
                {
                    Pai->esq=Pai;
                }
            }
        }
    }
    return A;
}

void InsereAvr(Avr *Ar, int num)
{
    Ar->raiz=aux_InsereArv(Ar->raiz,num);
}

void RemoveAvr(Avr *Ar int num)
{
    NoAvr *aux = Ar-> raiz;
    if(aux->info==num && aux->dir ==NULL && auz->esq == NULL)
    {
        free(aux);
        free(RAIZ);
        return NULL;
    }
    Ar->raiz = RemoveAvr_aux(Ar->raiz, num);
    return Ar;
}
NoAvr* RemoverAvr_aux(NoAvr *A, int num)
{
    if(pai==NULL)
    {
        printf("\n\tNada Encontrado!");
    }
    else{
        if(num>pai->info)
        {
            pai->dir = RemoverAvr_aux(pai->dir, num);
        }else{
            if(num<pai->info)
            {
                pai->esq = RemoveAvr_aux(pai->esq, num);
            }
    }
    else{
        if(pai->dir == NULL && pai->esq == NULL)
        {
            free(pai);
            pai = NULL;
        }
        else{
            if(pai->esq == NULL)
            {
                NoAvr *aux = pai;
                pai=pai->dir;
                free(aux);
            }
            else{
                if(pai->dir = NULL)
                {
                    NoArv* aux = pai;
                    pai = pai->esq;
                    free(aux);
                }
                else {
                    NoAvr *aux;
                    aux = pai->esq;
                    while(aux->dir!=NULL){
                        aux = aux->dir;
                    }
                    pai->info = aux->info;
                    aux->info = num;
                    pai->esq = RemoverAvr_aux(pai->esq, num);
                }
            }
        }
      }
    }
    return pai;
}





#endif // ARMAZENAMENTO_RH_H_INCLUDED
