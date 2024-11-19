#include <stdio.h>

int main() {
    char estado, codigoCarta[4], nomeCidade[50];
    int populacao, pontosTuristicos;
    float area, pib, densidadePopulacional, pibPerCapita;

    printf("Digite o estado: ");
    scanf("%c", &estado);

    printf("Digite o Código da Carta: ");
    scanf("%s", codigoCarta);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]s", nomeCidade);

    printf("Digite a População: ");
    scanf("%d", &populacao);

    printf("Digite a Área: ");
    scanf("%f", &area);

    printf("Digite o PIB: ");
    scanf("%f", &pib);

    printf("Digite a Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos);

    densidadePopulacional = (float)populacao/area;
    pibPerCapita = (pib/(float)populacao)*1000000000;

    printf("\nEstado: %c\n", estado); 
    printf("Código da Carta: %s\n", codigoCarta); 
    printf("Nome da Cidade: %s\n", nomeCidade); 
    printf("População: %d\n", populacao); 
    printf("Área: %.2f km²\n", area); 
    printf("Densidade Populacional: %.2f pessoas/km²\n", densidadePopulacional); 
    printf("PIB: %.2f bilhões de reais\n", pib); 
    printf("PIB per Capita: %.2f reais\n", pibPerCapita); 
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos); 

    return 0;
}