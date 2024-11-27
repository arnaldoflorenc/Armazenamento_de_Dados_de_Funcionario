#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "Armazenamento_RH.h"

void insereFuncionarios(Avr *Pai){
    int matricula;
    float salario;
    char nome[40];
    int idade;
    char cargo[25];
    int numfunc;
    FILE *dados;
    Funcionarios *func;

    dados = fopen("Dados.txt", "r");
    if(dados == NULL){
        printf("\nARQUIVO NÃO INICIALIZADO!!!");
        system("pause");
        exit(0);
    }

    fscanf(dados, "%d", &numfunc);
    func = (Funcionarios*)malloc(numfunc*sizeof(Funcionarios));

    for(int i = 0; i< numfunc; i++){
        fscanf(dados,"%d", &func[i].matricula);
        fgets(func[i].nome,40, dados);
        fscanf(dados,"%d", &func[i].idade);
        fgets(func[i].cargo,25, dados);
        fscanf(dados,"%f", &func[i].salario);

        insere_Arvore(Pai, func[i].matricula, func[i].nome, func[i].idade, func[i].cargo, func[i].salario);
    }

    printf("\n\nMatricula\tNome\t\t\t\t\tIdade\tCargo\t\t\t\tSalário\n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    imprimeArvIN(Pai->raiz);
    fclose(dados);
}

void buscaFuncionario(Avr *Pai){
    int matricula, nova_idade, alt, op;
    char novo_nome[40];
    char novo_cargo[25];
    float novo_salario;

    printf("\n\n----------------------------------------------------\n");
    printf("\n\t->>Digite a Matricula do Funcionario que deseja alterar: ");
    scanf("%d", &matricula);

    do{
        printf("\n\t[1]. Nome ");
        printf("\n\t[2]. Idade ");
        printf("\n\t[3]. Cargo");
        printf("\n\t[4]. Salário");
        printf("\n\t[5]. Sair");

        printf("\n\t->>Qual informação deseja alterar: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\n\t->Digite o novo Nome: ");
                fflush(stdin);
                fgets(novo_nome, 40, stdin);
                novo_nome[strcspn(novo_nome, "\n")] = '\0';
                aumentaN(novo_nome);

                alt = 0;
                break;
            case 2:
                printf("\n\t->Digite o nova Idade: ");
                scanf("%d", &nova_idade);
                alt = 1;
                break;
            case 3:
                printf("\n\t->Digite o novo Cargo: ");
                fflush(stdin);
                fgets(novo_cargo, 25, stdin);
                novo_cargo[strcspn(novo_cargo, "\n")] = '\0';
                aumentaC(novo_cargo);

                alt = 2;
                break;
            case 4:
                printf("\n\t->Digite o nova Salário: ");
                scanf("%f", &novo_salario);
                alt = 3;
                break;
            case 5:
                break;
            default:
                printf("\n\tOPÇÃO NÃO ENCONTRADA, RETORNANDO AO MENU...");
                return;
        }
        BuscaNaArvore(Pai->raiz, alt, matricula, novo_nome, nova_idade, novo_cargo, novo_salario);
    }while(op != 5);
    imprimeArvIN(Pai->raiz);
}

int main(){
    int op;

    setlocale(LC_ALL,"portuguese");

    Avr *Pai = CriaArvore();


    do{
        printf("\n\n----------------------------------------------------\n");
        printf("\n\t\t>>>>>Menu<<<<<");
        printf("\n\t[1]. Inserir Dados ");
        printf("\n\t[2]. Atualizar Dados ");
        printf("\n\t[3]. Incluir novo Funcionario");
        printf("\n\t[4]. Remover Funcionario");
        printf("\n\t[5]. Buscar");
        printf("\n\t[6]. Mais velho e Mais novo");
        printf("\n\t[7]. Imprimiir com Base no cargo ");
        printf("\n\t[8]. Finalizar ");

        do{
            fflush(stdin);
            printf("\n\t\t ->Opção desejada:");
            scanf("%d",&op);
        }while(op < 0  || op > 8);

        switch(op){
            case 1:
                insereFuncionarios(Pai);
                break;
            case 2:
                imprimeArvIN(Pai->raiz);
                buscaFuncionario(Pai);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                break;
        }
    }while(op != 8);
    return 0;
}
