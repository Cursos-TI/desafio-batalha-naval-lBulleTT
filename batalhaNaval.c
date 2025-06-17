#include <stdio.h> // Inclui a biblioteca padrão de entrada/saída, necessária para printf


// Define o tamanho do tabuleiro como 10x10, conforme requisito do Nível Aventureiro.
#define TAMANHO_TABULEIRO 10

int main() {
    // Declaração do tabuleiro de Batalha Naval como uma matriz 2D de 10x10.
    // Inicialmente, todas as posições são zeradas (0), indicando que não há navio.
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    printf("--- Batalha Naval - Nível Aventureiro ---\n");
    printf("Objetivo: Posicionar 4 navios em um tabuleiro 10x10 e exibi-los.\n");
    printf("0 = Posição Vazia, 1 = Navio\n");

    // --- Posicionamento dos Navios ---
    // Escolhi posições que garantam que os navios fiquem separados e claramente visíveis.

    // Navio 1: Vertical (3 partes)
    // Local: Canto superior esquerdo, próximo ao início.
    // Ocupará (0,0), (1,0), (2,0)
    printf("\nPosicionando Navio Vertical (3 partes) em (0,0)...\n");
    int nv_linha_ini = 0; // Linha inicial
    int nv_coluna_ini = 0; // Coluna inicial
    int nv_tamanho = 3;    // Tamanho do navio vertical

    // Loop para preencher as células do navio vertical.
    // A coluna (nv_coluna_ini) permanece fixa, a linha (i) varia.
    for (int i = 0; i < nv_tamanho; i++) {
        // Verifica se a posição está dentro dos limites do tabuleiro para evitar erros.
        if (nv_linha_ini + i < TAMANHO_TABULEIRO) {
            tabuleiro[nv_linha_ini + i][nv_coluna_ini] = 1; // Marca a posição com '1' (navio)
        } else {
            printf("Aviso: Navio Vertical excedeu os limites do tabuleiro em (%d, %d).\n", nv_linha_ini + i, nv_coluna_ini);
            break; // Interrompe o loop se sair dos limites
        }
    }

    // Navio 2: Horizontal (4 partes)
    // Local: Parte central direita.
    // Ocupará (4,5), (4,6), (4,7), (4,8)
    printf("Posicionando Navio Horizontal (4 partes) em (4,5)...\n");
    int nh_linha_ini = 4; // Linha inicial
    int nh_coluna_ini = 5; // Coluna inicial
    int nh_tamanho = 4;    // Tamanho do navio horizontal

    // Loop para preencher as células do navio horizontal.
    // A linha (nh_linha_ini) permanece fixa, a coluna (j) varia.
    for (int j = 0; j < nh_tamanho; j++) {
        // Verifica se a posição está dentro dos limites do tabuleiro.
        if (nh_coluna_ini + j < TAMANHO_TABULEIRO) {
            tabuleiro[nh_linha_ini][nh_coluna_ini + j] = 1; // Marca a posição com '1' (navio)
        } else {
            printf("Aviso: Navio Horizontal excedeu os limites do tabuleiro em (%d, %d).\n", nh_linha_ini, nh_coluna_ini + j);
            break; // Interrompe o loop se sair dos limites
        }
    }

    // Navio 3: Diagonal Principal (superior esquerda para inferior direita) (3 partes)
    // Local: Parte inferior esquerda, começando mais para baixo e para a direita.
    // Ocupará (6,1), (7,2), (8,3)
    printf("Posicionando Navio Diagonal Principal (3 partes) em (6,1)...\n");
    int ndp_linha_ini = 6; // Linha inicial
    int ndp_coluna_ini = 1; // Coluna inicial
    int ndp_tamanho = 3;     // Tamanho do navio diagonal principal

    // Loop para preencher as células do navio diagonal principal.
    // Tanto a linha (k) quanto a coluna (k) aumentam a cada iteração.
    for (int k = 0; k < ndp_tamanho; k++) {
        // Verifica se ambas as coordenadas estão dentro dos limites do tabuleiro.
        if (ndp_linha_ini + k < TAMANHO_TABULEIRO && ndp_coluna_ini + k < TAMANHO_TABULEIRO) {
            tabuleiro[ndp_linha_ini + k][ndp_coluna_ini + k] = 1; // Marca a posição com '1' (navio)
        } else {
            printf("Aviso: Navio Diagonal Principal excedeu os limites do tabuleiro em (%d, %d).\n", ndp_linha_ini + k, ndp_coluna_ini + k);
            break; // Interrompe o loop se sair dos limites
        }
    }

    // Navio 4: Diagonal Secundária (superior direita para inferior esquerda) (3 partes)
    // Local: Canto superior direito, começando mais para cima e para a direita.
    // Ocupará (1,8), (2,7), (3,6)
    printf("Posicionando Navio Diagonal Secundária (3 partes) em (1,8)...\n");
    int nds_linha_ini = 1; // Linha inicial
    int nds_coluna_ini = 8; // Coluna inicial
    int nds_tamanho = 3;     // Tamanho do navio diagonal secundária

    // Loop para preencher as células do navio diagonal secundária.
    // A linha (l) aumenta, a coluna (l) diminui a cada iteração.
    for (int l = 0; l < nds_tamanho; l++) {
        // Verifica se ambas as coordenadas estão dentro dos limites do tabuleiro.
        // A linha deve ser menor que TAMANHO_TABULEIRO e a coluna deve ser maior ou igual a 0.
        if (nds_linha_ini + l < TAMANHO_TABULEIRO && nds_coluna_ini - l >= 0) {
            tabuleiro[nds_linha_ini + l][nds_coluna_ini - l] = 1; // Marca a posição com '1' (navio)
        } else {
            printf("Aviso: Navio Diagonal Secundária excedeu os limites do tabuleiro em (%d, %d).\n", nds_linha_ini + l, nds_coluna_ini - l);
            break; // Interrompe o loop se sair dos limites
        }
    }

    // --- Exibição Completa do Tabuleiro ---

    printf("\n\n--- TABULEIRO DE BATALHA NAVAL ---\n");
    printf("   "); // Espaço para o rótulo da linha

    // Imprime o cabeçalho das colunas (0 a 9) para facilitar a leitura.
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d  ", j); // Imprime o número da coluna seguido de dois espaços
    }
    printf("\n"); // Quebra de linha após o cabeçalho das colunas

    // Linha separadora para melhorar a visualização.
    printf("   --------------------------------\n");

    // Percorre cada célula do tabuleiro para exibi-la.
    // O loop externo (i) itera sobre as linhas.
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i); // Imprime o número da linha e um separador '|'
        // O loop interno (j) itera sobre as colunas da linha atual.
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d  ", tabuleiro[i][j]); // Imprime o valor da célula (0 ou 1) seguido de dois espaços
        }
        printf("\n"); // Quebra de linha após cada linha do tabuleiro para formatar o grid
    }



    return 0; // Indica que o programa terminou com sucesso.
}
