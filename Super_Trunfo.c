#include <stdio.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Função para calcular densidade demográfica
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para exibir carta de forma organizada
void exibirCarta(Carta c) {
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nomeCidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", calcularDensidade(c.populacao, c.area));
}

// Função para exibir o menu de atributos
void exibirMenu(int excluido) {
    printf("\nEscolha um atributo para comparar:\n");
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Pontos Turísticos\n");
    if (excluido != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
}

// Função para obter o valor do atributo
float obterAtributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return calcularDensidade(c.populacao, c.area);
        default: return 0;
    }
}

// Função para comparar dois atributos
int compararAtributos(float valor1, float valor2, int atributo) {
    // Para densidade demográfica, menor valor vence
    if (atributo == 5) {
        return (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0;
    }
    // Para os outros atributos, maior valor vence
    return (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
}

int main() {
    // Cartas pré-cadastradas
    Carta carta1 = {'A', "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    Carta carta2 = {'B', "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    printf("\n--- Carta 1 ---\n");
    exibirCarta(carta1);

    printf("\n--- Carta 2 ---\n");
    exibirCarta(carta2);

    int atributo1 = 0, atributo2 = 0;

    // Escolha do primeiro atributo
    exibirMenu(0);
    scanf("%d", &atributo1);

    // Escolha do segundo atributo (não pode ser o mesmo)
    do {
        exibirMenu(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 == atributo1) {
            printf("Você já escolheu este atributo. Escolha outro.\n");
        }
    } while (atributo2 == atributo1);

    // Obter valores dos atributos
    float valor1A1 = obterAtributo(carta1, atributo1);
    float valor1A2 = obterAtributo(carta1, atributo2);
    float valor2A1 = obterAtributo(carta2, atributo1);
    float valor2A2 = obterAtributo(carta2, atributo2);

    // Comparação individual
    int vencedorA1 = compararAtributos(valor1A1, valor2A1, atributo1);
    int vencedorA2 = compararAtributos(valor1A2, valor2A2, atributo2);

    // Soma dos atributos
    float soma1 = valor1A1 + valor1A2;
    float soma2 = valor2A1 + valor2A2;

    // Determinar vencedor final
    int vencedorFinal = (soma1 > soma2) ? 1 : (soma2 > soma1) ? 2 : 0;

    // Exibição do resultado
    printf("\n--- Resultado ---\n");
    printf("%s vs %s\n", carta1.nomeCidade, carta2.nomeCidade);
    printf("Atributo 1: %.2f vs %.2f\n", valor1A1, valor2A1);
    printf("Atributo 2: %.2f vs %.2f\n", valor1A2, valor2A2);
    printf("Soma dos atributos: %.2f vs %.2f\n", soma1, soma2);

    if (vencedorFinal == 0) {
        printf("Empate!\n");
    } else {
        printf("Vencedor: %s\n", (vencedorFinal == 1) ? carta1.nomeCidade : carta2.nomeCidade);
    }

    return 0;
}
