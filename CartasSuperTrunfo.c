#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char estado, codigo[4], nome[50];
    int populacao, pontosTuristicos;
    float area, pib, densidadePopulacional, pibPerCapita;
    float superPoder;
} Cidade;

void lerDados(Cidade* cidade);
void calcularPropriedades(Cidade* cidade);
void printarDados(Cidade* cidade);
void compararCartas(Cidade* c1, Cidade* c2);

int main() {
    int n;
    printf("Quantas cidades deseja cadastrar? ");
    scanf("%d", &n);

    Cidade* cidades = malloc(n * sizeof(Cidade));

    for (int i = 0; i < n; i++) {
        printf("\n--- Cadastrando Cidade %d ---\n", i + 1);
        lerDados(&cidades[i]);
        calcularPropriedades(&cidades[i]);
    }

    printf("\n--- Dados Cadastrados ---\n");
    for (int i = 0; i < n; i++) {
        printarDados(&cidades[i]);
    }

    int c1, c2;
    printf("\nDigite os índices das duas cidades para comparar (1 a %d): ", n);
    scanf("%d %d", &c1, &c2);

    compararCartas(&cidades[c1 - 1], &cidades[c2 - 1]);

    free(cidades);
    return 0;
}

void lerDados(Cidade* cidade) {
    printf("Digite o estado: ");
    scanf(" %c", &cidade->estado);
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
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &cidade->pontosTuristicos);
}

void calcularPropriedades(Cidade* cidade) {
    cidade->densidadePopulacional = cidade->populacao / cidade->area;
    cidade->pibPerCapita = cidade->pib / cidade->populacao;
    cidade->superPoder = cidade->densidadePopulacional + cidade->pibPerCapita + cidade->pontosTuristicos;
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
    printf("Super Poder: %.2f\n", cidade->superPoder);
}

void compararCartas(Cidade* c1, Cidade* c2) {
    printf("\nComparando %s e %s:\n", c1->nome, c2->nome);
    printf("Densidade Populacional: %s vence\n", c1->densidadePopulacional < c2->densidadePopulacional ? c1->nome : c2->nome);
    printf("PIB per Capita: %s vence\n", c1->pibPerCapita > c2->pibPerCapita ? c1->nome : c2->nome);
    printf("Pontos Turísticos: %s vence\n", c1->pontosTuristicos > c2->pontosTuristicos ? c1->nome : c2->nome);
    printf("Super Poder: %s vence\n", c1->superPoder > c2->superPoder ? c1->nome : c2->nome);
}
