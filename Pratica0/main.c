#include <stdio.h>
int main()
{
    double s = 0.0, M[12][12];
    char T;
    int i, j;
    scanf("%c", &T);
    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%lf", &M[i][j]);
        }
    }
    for(i = 0; i < 5 ; i++){
        for(j = 0; j < 12; j++){
            if (j > i && j < 11 - i){
                s+=M[i][j];
            }
        }
    }
    if(T == 'M')
        s = s/30;
    
    printf("%.1lf\n", s);
    return 0;
}
