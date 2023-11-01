#include <stdio.h>
#include <stdlib.h>
#define VETTAM 100

void append(int vet[], int *tam, int val, int tamMax)
{
    if (*tam < tamMax)
    {
        vet[*tam] = val;
        (*tam)++; // Aumenta o tamanho do vetor
    }
    else
    {
        printf("O vetor está cheio. Não é possível adicionar mais elementos.\n");
    }
}

int somarVetor(int vetor[], int tamanho)
{
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += vetor[i];
    }
    return soma;
}

int main()
{
    FILE *arquivo;     // Declara um ponteiro de arquivo
    int vetor[VETTAM]; // Declara um vetor de inteiros
    int contador = 0;  // Contador para o número de inteiros lidos do arquivo

    // Tenta abrir o arquivo para leitura
    arquivo = fopen("entrada.txt", "r");

    // Verifique se o arquivo foi aberto com sucesso
    if (arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
        return 1; // Saia do programa com um código de erro
    }

    // Leia os inteiros do arquivo e armazene-os no vetor
    while (fscanf(arquivo, "%d", &vetor[contador]) == 1)
    {
        contador++;

        // Verifique se o vetor está cheio
        if (contador >= VETTAM)
        {
            printf("O vetor está cheio. Aumente o tamanho do vetor ou o limite de "
                   "inteiros lidos.\n");
            break;
        }
    }

    // Feche o arquivo
    fclose(arquivo);

    // Exiba os inteiros armazenados no vetor
    printf("Números inteiros lidos do arquivo:\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Declaranado variáveis para melhor localização no vetor e nos laços de
    // repetição

    int tamPendrives;
    int vetorTestes[100];
    int testes = 0;
    int antigarep = 0;
    int armazenamento = 0;
    int rep = 0;
    int sum = 0;
    int n = 0;
    testes = vetor[0];
    armazenamento = vetor[1];
    rep = vetor[2];

    // fazendo a soma e a verificação se é possível armazdenar todos os arquivos
    // no espaço disponível
    for (int g = 0; g < testes; g++)
    {

        printf("armazenamento %d\n", armazenamento);
        printf("rep %d\n", rep);
        printf("antigarep %d\n", antigarep);

        for (int i = 3 + antigarep; i < rep + 3; i++)
        {
            printf("i = %d ", i);
            printf("vetor%d ", vetor[i]);
            vetorTestes[n] = vetor[i];
            n++;
            sum = sum + vetor[i];
        }

        if (sum > armazenamento)
        {
            printf("Impossível gravar todos os arquivos nos pendrives.");
            return 1;
        }

        printf("\n");
        printf("soma %d ", sum);
        printf("\n");

        printf("tamanho: %d\n", n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", vetorTestes[i]);
        }
        printf("\n");
        printf("\n");
        // fazendo a distribuição dos arquivos respeitando o limite de cada pendrive

        tamPendrives = armazenamento / 2;
        int tamPenA = 0;
        int tamPenB = 0;
        int soma = 0;
        int na = 0;

        int PendriveA[tamPendrives];
        int PendriveB[tamPendrives];

        for (int i = 0; i < n; i++)
        {

            if (soma + vetorTestes[i] > tamPendrives)
            {
                append(PendriveB, &tamPenB, vetorTestes[i], tamPendrives);
                soma = somarVetor(PendriveA, tamPenA);
            }

            else if (soma < tamPendrives)
            {
                append(PendriveA, &tamPenA, vetorTestes[i], tamPendrives);
                soma = somarVetor(PendriveA, tamPenA);
            }

            else
                append(PendriveB, &tamPenB, vetorTestes[i], tamPendrives);
            soma = somarVetor(PendriveA, tamPenA);
        }
        printf("%d GB \n", armazenamento);
        printf("Pendrive A (%d GB)\n", tamPendrives);
        for (int i = 0; i < tamPenA; i++)
            printf("%d GB \n", PendriveA[i]);
        printf("\n");
        printf("Pendrive B (%d GB)\n", tamPendrives);
        for (int i = 0; i < tamPenB; i++)
            printf("%d GB \n", PendriveB[i]);
        printf("\n");

        // Limpando os pendrives para nova execução e reajustando valores
        for (int i = 0; i < tamPenA; i++)
        {
            PendriveA[i] = 0;
            PendriveB[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            vetorTestes[i] = 0;
        }

        antigarep = rep + 2;
        armazenamento = vetor[rep + 3];
        rep = vetor[rep + 4];
    }
    return 0; // Saia do programa com sucesso
}
