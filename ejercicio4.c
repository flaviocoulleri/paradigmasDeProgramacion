#include<stdio.h>
typedef struct
{
    int number,count;
} Moda;
void ordenarVectorCount(Moda v[], int n);
void ordenarVectorValue(Moda v[], int n);
int main()
{
    Moda moda[4];
    int matrix[3][4]=
    {
        {1, 2, 2, 1},
        {4, 4, 3, 3},
        {5, 5, 5, 6}
    },
    arrayModa[3]= {0},countModa,
                  busqActiva=0;

    for(int i=0; i<3; i++)
    {
        for(int k=0; k<4; k++)
        {
            moda[k].count=0;
            moda[k].number=0;

        }
        countModa=0;
        for(int j=0; j<4; j++)
        {
            busqActiva=0;
            if(countModa==0)
            {
                moda[countModa].number=matrix[i][j];
                moda[countModa].count=1;
                countModa++;
            }
            else
                for(int h=0; h<countModa&&busqActiva!=1; h++)
                {
                    if(matrix[i][j]==moda[h].number)
                    {
                        moda[h].count++;
                        busqActiva=1;
                    }
                }
            if(busqActiva == 0)
            {
                moda[countModa].number = matrix[i][j];
                moda[countModa].count = 1;
                countModa++;
            }

        }
        ordenarVectorValue(moda,countModa);
        ordenarVectorCount(moda,countModa);
        arrayModa[i]=moda[0].number;
    }

    for(int i=0; i<3; i++)
        printf("%d ",arrayModa[i]);
    return 0;
}

//hacer un ordenar generico asi no lo hago 2 funciones para ordenar
void ordenarVectorValue(Moda v[], int n)
{
    int i, j;
    Moda aux;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (v[j].number < v[j + 1].number)
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void ordenarVectorCount(Moda v[], int n)
{
    int i, j;
    Moda aux;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (v[j].count < v[j + 1].count)
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

