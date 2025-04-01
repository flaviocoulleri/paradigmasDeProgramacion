#include<stdio.h>

int main()
{
    int mat[3][4] = {{8, 2, -3, 4},{5, -6, -6, 20},{21, 1, -5, 0}},
    matrizRes[3][4]={{0}};
    
    int limIzq = 0, limSup = 0, limDer = 3, limInf = 2;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            matrizRes[i][j]+=mat[i][j];
            if(i-1 >= 0)
                matrizRes[i][j] += mat[i-1][j];
            if(i+1 <= 2)
                matrizRes[i][j] += mat[i+1][j];
            if(j-1 >= 0)
                matrizRes[i][j] += mat[i][j-1];
            if(j+1 <= 3)
                matrizRes[i][j] += mat[i][j+1];
                
            printf("%d ",matrizRes[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}
