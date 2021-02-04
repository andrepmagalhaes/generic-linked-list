//ALUNO - ANDRE PIMENTEL MAGALHAES
//RA - 1901570771

// Implementar em C um TAD de lista encadeada genérica com informações do tipo Aluno. A Lista deverá
// ser implementada como um TAD - tipo abstrato de dados - codificado usando arquivo fonte de header (.h)
// e arquivo fonte com a implementação das funções definidas no arquivo header (.c).
// Deve possuir as seguintes funções:
// 1. Cria Lista;
// 2. Insere na lista (no início);
// 3. Percorre a lista (considerando as situações de busca, impressão e retirada de elementos);
// 4. Verifica se a lista está vazia;
// 5. Libera a lista (memória alocada);
// Segue a estrutura do tipo de informação Aluno da lista:
// struct aluno{
//  int matrícula;
//  char nome[50];
// }
// O programa DEVE possuir um Menu com as seguintes opções:
// 1. Inserir aluno;
// 2. Buscar aluno (por matrícula);
// 3. Imprimir alunos;
// 4. Retirar aluno (por matrícula);
// 5. Verifica se lista está vazia;
// 6. Sair;
// Sobre o formato da entrega:
// Os trabalhos podem ser desenvolvidos individualmente ou em duplas e os arquivos .c e .h devem ser
// enviados via Moodle, na Tarefa criada "Atividade 1 - Lista simplesmente encadeada genérica”.
// A professora poderá solicitar uma breve apresentação do funcionamento do código. 

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int matricula;
    char nome[50];
} aluno;

int matriculaCounter = 0;

genericList* findByMatricula(int matricula, void (*callback)(void*, int))
{

    genericList *aux3;
    genericList *aux = initialAdress;
    aluno *aux2 = (aluno*) initialAdress->data;
    int flag = 0;

    if(aux == initialAdress && aux2->matricula == matricula)
    {
        aux3 = aux;
        flag = 1;
    }
    else
    {
        while(aux->next != NULL)
        {
            aux3 = aux->next;
            aux2 = (aluno*) (aux3)->data;

            if((aux2->matricula) == matricula)
            {
                break;
            }
            
            aux = aux->next;

        }
        if((aux == initialAdress && aux->next == NULL) || (aux->next == NULL && aux2->matricula != matricula))
        {

            aux = NULL;
        }
    }
    callback(aux, flag);
}

void insertNode(void* paramData){

    system("cls");

    genericList *newGenericData = (genericList*) malloc(sizeof(genericList));
    newGenericData->data = paramData;
    newGenericData->next = NULL;

    if(initialAdress == NULL)
    {
        initialAdress = newGenericData;
    }
    else
    {
        genericList *aux = initialAdress;

        while(aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = newGenericData;
    }
}

void printAll()
{
    genericList *aux = initialAdress;

    system("cls");
    printf("================================================================");
    printf("\n");
    printf("MATRICULA    |    NOME");
    printf("\n");
    printf("\n");
    while(aux != NULL)
    {
        aluno *aux2 = (aluno*) aux->data;

        printf("    %i        |    %s", aux2->matricula, aux2->nome);
        printf("\n");

        aux = aux->next;
    }
    printf("\n");
    printf("================================================================");
    printf("\n");
    system("pause");
}

void checkIfEmpty()
{
    system("cls");
    if(initialAdress == NULL)
    {
        printf("A lista esta vazia");
    }
    else
    {
        printf("A lista nao esta vazia");
    }
    printf("\n");
    system("pause");
}

void printByMatricula(void* param, int flag)
{
    genericList *param2 = (genericList*) param;

    // printf("data: %d | next: %d \n",param3->data, param3->next);
    // system("pause");
    // printf("data: %d | next: %d \n",param4->data, param4->next);
    // system("pause");
    // printf("data: %d | next: %d \n",param4->data, param4->next);
    // system("pause");

    // aluno* jooj = (aluno*) (param2[1]->data);
    // printf("%d \n", &jooj->matricula);
    // system("pause");

    system("cls");
    if(param2 == NULL)
    {
        printf("Nenhum aluno foi encontrado com a matricula informada");
        printf("\n");
    }
    else
    {
        aluno *data;
        if(param2 == initialAdress && param2->next == NULL)
        {
            data = (aluno*) ((param2)->data);
        }
        else
        {
            data = (aluno*) ((param2->next)->data);
        }
        
        printf("================================================================");
        printf("\n");
        printf("MATRICULA    |    NOME");
        printf("\n");
        printf("\n");
        printf("    %i        |    %s", data->matricula, data->nome);
        printf("\n");
        printf("\n");
        printf("================================================================");
        printf("\n");
    } 
    system("pause");
}

void interface()
{

    system("cls");
    printf("================================================");
    printf("\n");
    printf("\n");
    printf("1. Inserir Aluno");
    printf("\n");
    printf("2. Buscar Aluno (por matricula)");
    printf("\n");
    printf("3. Imprimir Alunos;");
    printf("\n");
    printf("4. Retirar Aluno (por matricula)");
    printf("\n");
    printf("5. Verificar se a lista esta vazia");
    printf("\n");
    printf("6. Sair");
    printf("\n");
    printf("\n");
    printf("================================================");
    printf("\n");
    printf("\n");
}

void caseDefault()
{
    system("cls");
    printf("Comando Invalido");
    system("pause");
}

void newAluno()
{
    aluno* newAluno = (aluno*) malloc(sizeof(aluno));

    matriculaCounter++;
    newAluno->matricula = matriculaCounter;

    system("cls");
    printf("Digite o nome do Aluno: ");
    scanf("%s", newAluno->nome);
    clearBuffer();
    insertNode(newAluno);
}

void searchByMatricula()
{

    if(initialAdress == NULL)
    {
        system("cls");
        printf("A lista nao contem nenhum aluno");
        printf("\n");
        system("pause");
    }
    else
    {
        int matricula = 0;

        system("cls");
        printf("Digite o numero da matricula a se pesquisar: ");
        scanf("%i", &matricula);
        findByMatricula(matricula, printByMatricula);
    }
    
}

void removeByMatricula(void* data, int flag)
{
    system("cls");

    genericList* removeData = (genericList*) data;
    genericList* aux;

    // for(int i = 0 ; i< 3 ; i++)
    // {
    //     printf("node: %i", removeData[i]);
    //     printf("\n");
    //     printf("proximo: %i", &removeData[i].next);
    //     printf("\n");
    // }
    // system("pause");

    if(removeData == NULL)
    {
        printf("Numero de matricula nao encontrado");
    }
    else
    {
        if(removeData == initialAdress && removeData->next == NULL)
        {
            free(removeData);
            initialAdress = NULL;
        }
        else if((removeData == initialAdress) && flag == 1)
        {
            initialAdress = removeData->next;
            free(removeData);
        }
        else
        {
            aux = (removeData->next)->next;
            free(removeData->next);
            removeData->next = aux;
            
        }
        printf("Aluno deletado com sucesso!");
    }
    printf("\n");
    system("pause");
}

void initRemoveByMatricula()
{
    int matricula = 0;

    system("cls");
    printf("Digite o numero da matricula que se deseja excluir: ");
    scanf("%i", &matricula);

    findByMatricula(matricula, removeByMatricula);
}