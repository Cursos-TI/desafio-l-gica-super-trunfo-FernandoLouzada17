#include <stdio.h>

int main() {
    // --- Dados da Carta 1 (inseridos diretamente no código) ---
    char estado1 = 'A';
    char codigoCarta1[4] = "A01";
    char nomeCidade1[50] = "São Paulo";
    unsigned long int populacao1 = 12325000;
    float area1 = 1521.11;
    float pib1 = 699.28;
    int pontosTuristicos1 = 50;
    
    // --- Dados da Carta 2 (inseridos diretamente no código) ---
    char estado2 = 'B';
    char codigoCarta2[4] = "B02";
    char nomeCidade2[50] = "Rio de Janeiro";
    unsigned long int populacao2 = 6748000;
    float area2 = 1200.25;
    float pib2 = 300.50;
    int pontosTuristicos2 = 30;

    // --- Variáveis para os resultados calculados ---
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;

    // --- Cálculos para a Carta 1 ---
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;
    superPoder1 = (float)populacao1 + area1 + (pib1 * 1000000000.0) + (float)pontosTuristicos1 + pibPerCapita1 + (1.0 / densidadePopulacional1);

    // --- Cálculos para a Carta 2 ---
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;
    superPoder2 = (float)populacao2 + area2 + (pib2 * 1000000000.0) + (float)pontosTuristicos2 + pibPerCapita2 + (1.0 / densidadePopulacional2);

    // --- Variáveis de Comparação ---
    int venceu_populacao = populacao1 > populacao2;
    int venceu_area = area1 > area2;
    int venceu_pib = pib1 > pib2;
    int venceu_pontos = pontosTuristicos1 > pontosTuristicos2;
    int venceu_densidade = densidadePopulacional1 < densidadePopulacional2; // Menor densidade vence
    int venceu_pib_per_capita = pibPerCapita1 > pibPerCapita2;
    int venceu_super_poder = superPoder1 > superPoder2;

    // ==================================================================
    // NOVA SEÇÃO: Exibição dos dados das cartas antes da comparação
    // ==================================================================
    printf("--- Dados das Cartas ---\n\n");

    // Exibição dos Dados da Carta 1
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigoCarta1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\n");

    // Exibição dos Dados da Carta 2
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigoCarta2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);


    // --- Exibição dos Resultados da Comparação ---
    printf("\n\n--- Comparacao de Cartas ---\n\n");

    printf("Populacao: Carta %d venceu (%d)\n", (venceu_populacao ? 1 : 2), venceu_populacao);
    printf("Area: Carta %d venceu (%d)\n", (venceu_area ? 1 : 2), venceu_area);
    printf("PIB: Carta %d venceu (%d)\n", (venceu_pib ? 1 : 2), venceu_pib);
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", (venceu_pontos ? 1 : 2), venceu_pontos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", (venceu_densidade ? 1 : 2), venceu_densidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", (venceu_pib_per_capita ? 1 : 2), venceu_pib_per_capita);
    printf("Super Poder: Carta %d venceu (%d)\n", (venceu_super_poder ? 1 : 2), venceu_super_poder);

    return 0;
}