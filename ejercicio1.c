#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[3][3] = {{2,2,3},{4,2,6},{7,8,4}}, diagonal=0, primero = 1;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
            {
                
                if(primero==1)
                {
                    primero = 0;
                }
                else
                {
                    if(matriz[i][j] != diagonal)
                    {
                        printf("No cumple.");
                        return 1; //SIN RETURN O NOS CAGA A PEDO EL PROFE
                    }
                }
                diagonal+=matriz[i][j];
                
            }
            
        }
    }
    printf("Cumple");
    return 0;
}
