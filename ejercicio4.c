#include<stdio.h>
typedef struct {
    int number,count;
}Moda;
void ordenarVectorCount(Moda v[], int n);
void ordenarVectorValue(Moda v[], int n);
int main()
{
    Moda moda[4];
    int matrix[3][4]={{1,2,3,4},{1,2,3,4},{1,2,3,4}},
    arrayModa[3]={0},
    countModa=0,
    busqActiva=0;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(countModa==0)
            {
                moda[countModa].number=matrix[i][j];
                moda[countModa].count=1;
                countModa++;
            }
            else
                for(int h=0;h<countModa&&busqActiva!=1;h++)
                {
                    if(matrix[i][j]==moda[h].number)
                    {
                        moda[h].count++;
                        busqActiva=1;
                    }
                    if(moda[h].number==0)
                    {
                        moda[h].number=matrix[i][j];
                        countModa++;
                    }

                }
        }
        ordenarVectorCount(&moda,countModa);
        ordenarVectorValue(&moda,countModa);
        arrayModa[i]=moda[1].number;
    }


    return 0;
}void ordenarVectorValue(Moda v[], int n) {
    int i, j;
    Moda aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j].number > v[j + 1].number) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

// Ordena por el campo count
void ordenarVectorCount(Moda v[], int n) {
    int i, j;
    Moda aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j].count > v[j + 1].count) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}
