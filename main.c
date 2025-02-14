#include <stdio.h>
#include <math.h>

void gerarQuadrado()
{
    int linha, coluna, size;
    char model;
    printf("\tGerador de Quadrados.\n\n");
    printf("C para totalmente preenchido.\n");
    printf("B para apenas as bordas.\n");
    printf("P para bordas e diagonal principal.\n");
    printf("S para bordas e diagonal secundária.\n");
    printf("H para dividido horizontalmente.\n");
    printf("V para dividido verticalmente.\n\n");
    printf("Escolha o modelo: ");
    scanf(" %c", &model);
    printf("\nEscolha o tamanho: ");
    scanf("%d", &size);
    printf("\n");
    
    switch (model)
    {
    case 'C':
        for (linha = 0; linha < size; linha++)
        {
            for (coluna = 0; coluna < size; coluna++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;
    case 'B':
        for (linha = 0; linha < size; linha++)
        {
            for (coluna = 0; coluna < size; coluna++)
            {
                if (linha == 0 || linha == size - 1 || coluna == 0 || coluna == size - 1)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
        break;
    case 'P':
        for (linha = 0; linha < size; linha++)
        {
            for (coluna = 0; coluna < size; coluna++)
            {
                if (linha == 0 || linha == size - 1 || coluna == 0 || coluna == size - 1 || coluna == linha)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
        break;
    case 'S':
        for (linha = 0; linha < size; linha++)
        {
            for (coluna = 0; coluna < size; coluna++)
            {
                if (linha == 0 || linha == size - 1 || coluna == 0 || coluna == size - 1 || linha == size - coluna - 1)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
        break;
    case 'H':
        for (linha = 0; linha < size; linha++)
        {
            for (coluna = 0; coluna < size; coluna++)
            {
                if (linha == 0 || linha == size - 1 || coluna == 0 || coluna == size - 1 || linha == size / 2)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
        break;
    case 'V':
        for (linha = 0; linha < size; linha++)
        {
            for (coluna = 0; coluna < size; coluna++)
            {
                if (linha == 0 || linha == size - 1 || coluna == 0 || coluna == size - 1 || coluna == size / 2)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
        break;
    default:
        printf("\nNão existe essa opção.\n");
    }
}

void gerarTriangulo()
{
    int tamanho, linha, coluna;
    char opt;
    printf("\tGerador de Triângulos.\n\n");
    printf("C para totalmente preenchido\n");
    printf("V para vazio\n\n");
    printf("Escolha o modelo: ");
    scanf(" %c", &opt);
    printf("\nTamanho da altura: ");
    scanf("%d", &tamanho);
    printf("\n");

    switch (opt)
    {
    case 'C':
        for (linha = 1; linha <= tamanho; linha++)
        {
            for (coluna = 1; coluna <= tamanho * 2 - 1; coluna++)
            {
                if (coluna >= tamanho - (linha - 1) && coluna <= tamanho + (linha - 1))
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
        break;
    case 'V':
        for (linha = 1; linha <= tamanho; linha++)
        {
            for (coluna = 1; coluna <= tamanho * 2 - 1; coluna++)
            {
                if (coluna == tamanho - (linha - 1) || coluna == tamanho + (linha - 1) || linha == tamanho)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
        break;
    default:
        printf("Opção inválida.\n");
    }
}

void gerarCirculo()
{
    int raio;
    char cheio;

    printf("\tGerador de círculos\n\n");
    printf("C para totalmente preenchido\n");
    printf("V para vazio\n\n");

    printf("Escolha o modelo: ");
    scanf(" %c", &cheio);
    printf("\n");
    printf("Digite o raio: ");
    scanf("%d", &raio);
    printf("\n");

    for (int y = -raio; y <= raio; y++)
    {
        for (int x = -raio; x <= raio; x++)
        {
            double distancia = sqrt(x * x + y * y);
            if ((cheio == 'C' && distancia <= raio) || (cheio == 'V' && distancia >= raio - 0.5 && distancia <= raio + 0.5))
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main()
{
    int opt;
    printf("\tGerador de formas\n\n1 - Quadrado\n2 - Triângulo\n3 - Círculo\n\nEscolha a forma: ");
    scanf("%d", &opt);
    printf("\n");

    switch (opt)
    {
    case 1:
        gerarQuadrado();
        break;
    case 2:
        gerarTriangulo();
        break;
    case 3:
        gerarCirculo();
        break;
    default:
        printf("Opção inválida.\n");
    }
    return 0;
}
