/*
    Adicionei funções pra facilitar minha vida na hora de cadastrar mais cidades.
    Pra usar as funções, fiz uma estrutura e tive que trocar pra usar ponteiros e o valor se manter entre elas.
*/

#include <stdio.h>
typedef struct {
    char estado, codigo[4], nome[50];
    int populacao, pontosTuristicos;
    float area, pib, densidadePopulacional, pibPerCapita;
} Cidade;

void lerDados(Cidade* cidade);
void calcularPropriedades(Cidade* cidade);
void printarDados(Cidade* cidade);

int main() {
    Cidade* cidade = malloc(sizeof(Cidade));

    lerDados(cidade);
    calcularPropriedades(cidade);
    printarDados(cidade);

    free(cidade);
    return 0;
}

void lerDados(Cidade* cidade) {
    printf("Digite o estado: ");
    scanf("%c", &cidade->estado);

    printf("Digite o Código da Carta: ");
    scanf("%s", cidade->codigo);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]s", cidade->nome);

    printf("Digite a População: ");
    scanf("%d", &cidade->populacao);

    printf("Digite a Área: ");
    scanf("%f", &cidade->area);

    printf("Digite o PIB: ");
    scanf("%f", &cidade->pib);

    printf("Digite a Número de Pontos Turísticos: ");
    scanf("%d", &cidade->pontosTuristicos);
}

void calcularPropriedades(Cidade* cidade) {
    int bilhao = 1000000000;
    cidade->densidadePopulacional = (float)cidade->populacao/cidade->area;
    cidade->pibPerCapita = (cidade->pib/(float)cidade->populacao)*bilhao;
}

void printarDados(Cidade* cidade) {
    printf("\nEstado: %c\n", cidade->estado); 
    printf("Código da Carta: %s\n", cidade->codigo); 
    printf("Nome da Cidade: %s\n", cidade->nome); 
    printf("População: %d\n", cidade->populacao); 
    printf("Área: %.2f km²\n", cidade->area); 
    printf("Densidade Populacional: %.2f pessoas/km²\n", cidade->densidadePopulacional); 
    printf("PIB: %.2f bilhões de reais\n", cidade->pib); 
    printf("PIB per Capita: %.2f reais\n", cidade->pibPerCapita); 
    printf("Número de Pontos Turísticos: %d\n", cidade->pontosTuristicos); 
}