#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[3];
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib; // em bilhões de reais
    int numPontosTuristicos;
};

// Função para calcular a densidade demográfica
float calcularDensidade(int populacao, float area) {
    if (area <= 0.0f) return 0.0f; // evita divisão por zero
    return (float)populacao / area;
}

// Função para calcular o PIB per capita
float calcularPIBperCapita(float pib, int populacao) {
    if (populacao <= 0) return 0.0f; // evita divisão por zero
    return (pib * 1000000000.0f) / populacao; // converte bilhões para reais
}

// Função para exibir uma carta de forma organizada
void exibirCarta(struct Carta c) {
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nomeCidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.numPontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", calcularDensidade(c.populacao, c.area));
    printf("PIB per Capita: R$ %.2f\n", calcularPIBperCapita(c.pib, c.populacao));
    printf("------------------------------\n");
}

// Função para comparar dois valores e imprimir o resultado
void compararValores(char *atributo, float valor1, float valor2, int maiorVence) {
    printf("Comparando %s...\n", atributo);

    if (valor1 == valor2) {
        printf("Empate! Ambos têm %.2f\n\n", valor1);
    } else {
        if (maiorVence) {
            if (valor1 > valor2)
                printf("Carta 1 venceu (%s maior: %.2f)\n\n", atributo, valor1);
            else
                printf("Carta 2 venceu (%s maior: %.2f)\n\n", atributo, valor2);
        } else { // menor vence
            if (valor1 < valor2)
                printf("Carta 1 venceu (%s menor: %.2f)\n\n", atributo, valor1);
            else
                printf("Carta 2 venceu (%s menor: %.2f)\n\n", atributo, valor2);
        }
    }
}

int main() {
    struct Carta carta1 = {"A", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    struct Carta carta2 = {"B", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    printf("===== CARTA 1 =====\n");
    exibirCarta(carta1);

    printf("===== CARTA 2 =====\n");
    exibirCarta(carta2);

    int opcao;
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (menor vence)\n");
    printf("6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            compararValores("População", carta1.populacao, carta2.populacao, 1);
            break;
        case 2:
            compararValores("Área", carta1.area, carta2.area, 1);
            break;
        case 3:
            compararValores("PIB", carta1.pib, carta2.pib, 1);
            break;
        case 4:
            compararValores("Pontos Turísticos", carta1.numPontosTuristicos, carta2.numPontosTuristicos, 1);
            break;
        case 5:
            compararValores("Densidade Demográfica", 
                calcularDensidade(carta1.populacao, carta1.area),
                calcularDensidade(carta2.populacao, carta2.area), 0);
            break;
        case 6:
            compararValores("PIB per Capita", 
                calcularPIBperCapita(carta1.pib, carta1.populacao),
                calcularPIBperCapita(carta2.pib, carta2.populacao), 1);
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
