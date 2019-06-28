#include <stdio.h>

struct MinMax{
   unsigned int min,max;
};

struct MinMax minMax(unsigned int array[], unsigned int inicio, unsigned int fim)
{
    struct MinMax resultado, metadeEsq, metadeDir;
    int mid;

    if(inicio == fim)
    {
      resultado.min = array[fim];
      resultado.max = array[fim];
      return resultado;
    }

    if(fim  == inicio + 1)
    {
      if(array[inicio] > array[fim])
      {
        resultado.min = array[fim];
        resultado.max = array[inicio];
      }else
      {
        resultado.min = array[inicio];
        resultado.max = array[fim];
      }

      return resultado;
    }

    mid = (inicio + fim) / 2;
    metadeEsq = minMax(array, inicio, mid);
    metadeDir = minMax(array, mid + 1, fim);

    if(metadeEsq.min < metadeDir.min) resultado.min = metadeEsq.min;
    else resultado.min = metadeDir.min;

    if(metadeEsq.max > metadeDir.max) resultado.max = metadeEsq.max;
    else resultado.max = metadeDir.max;

    return resultado;
}

int main(void)
{
  unsigned int tam; 
  struct MinMax resultado;

  printf("Digite o tamanho do vetor: ");
  scanf("%u", &tam);

  unsigned int vetor[tam];

  for(unsigned int i = 0; i < tam; i++)
  {
    printf("Digite um número: ");
    scanf("%u", &vetor[i]);
  }

  resultado = minMax(vetor, 0, tam -1);

  puts("Maior | Menor");
  puts("-------------");
  printf("  %u\t  %u\n", resultado.max, resultado.min);
  
  return 0;
}
