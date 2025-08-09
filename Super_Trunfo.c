#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
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
    // Dados prontos das cartas
    struct Carta carta1 = {'A', "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    struct Carta carta2 = {'B', "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    // Exibição organizada
    printf("=== Carta 1 ===\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.cidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta1.pontos);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.cidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta2.pontos);

    return 0;
}

