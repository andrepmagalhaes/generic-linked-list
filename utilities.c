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

void clearBuffer()
{
    while( getchar() != '\n' );
}