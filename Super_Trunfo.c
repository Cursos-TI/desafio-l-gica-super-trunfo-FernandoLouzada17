#include <stdio.h>

// Estrutura que representa uma carta
struct Carta {
    char estado;        // Letra do estado
    char codigo[4];     // Código da carta
    char cidade[50];    // Nome da cidade
    int populacao;      // População
    float area;         // Área em km²
    float pib;          // PIB em bilhões de reais
    int pontos;         // Pontos turísticos
};

int main() {
    // Duas cartas pré-definidas
    struct Carta carta1 = {'A', "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    struct Carta carta2 = {'B', "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    // Cálculo da densidade populacional
    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;

    // Cálculo do PIB per capita
    float pibPerCapita1 = (carta1.pib * 1000000000) / carta1.populacao; // PIB convertido para reais
    float pibPerCapita2 = (carta2.pib * 1000000000) / carta2.populacao;

    // Exibição das cartas com cálculos
    printf("=== Carta 1 ===\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.cidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta1.pontos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: %.2f reais\n", pibPerCapita1);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.cidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta2.pontos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: %.2f reais\n", pibPerCapita2);

    // ======================
    // COMPARAÇÃO (Atributo fixo: População)
    // ======================
    printf("\n=== Comparacao de Cartas (Atributo: Populacao) ===\n");
    printf("Carta 1 - %s: %d habitantes\n", carta1.cidade, carta1.populacao);
    printf("Carta 2 - %s: %d habitantes\n", carta2.cidade, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}