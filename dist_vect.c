#include <stdio.h>
#include <stdlib.h>

void rout_table();
int d[10][10], via[10][10];
int i, j, k , l, m ,n , g[10][10], temp[10][10], ch, cost;

int main(){
    char ll, mm;
    system("clear");
    printf("enter the value of no. of nodes\n");
    scanf("%d", &n);

    rout_table();
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            temp[i][j] = g[i][j];
    
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            via[i][j] = i;
    
    while(1)
    {
        for(i=0; i<n ; i++)
            for(j=0; j<n; j++)
                if(d[i][j])
                for(k=0; k<n; k++)
                    if(g[i][j] + g[j][k] < g[i][k]){
                        g[i][k] = g[i][j] + g[j][k];
                        via[i][k] = j;
                    }
        
        for(i=0; i<n; i++){
            printf("table for router %c\n", i+97);
            for(j=0; j<n; j++)
                printf("%c:: %d via %c\n", j+97, g[i][j], via[i][j]+97);
            sleep(3);
        }

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                g[i][j] = temp[i][j];
        
        printf("\n do you want to change the cost(1/0) \n");
        scanf("%d", &ch);

        if(ch==1)
        {
            printf("enter the vertices which you want to change the cost\n");
            scanf("%d %d", &l, &m);
            printf("enter the cost\n");
            scanf("%d", &cost);
            g[l-1][m-1] = cost;
            g[m-1][l-1] = cost;

            for(i=0; i<n; i++)
                for(j=0; j<n; j++)
                    temp[i][j] = g[i][j];
                continue;
        } else{
        break;
        }
    }
}


    void rout_table(){
        printf("\n Enter the routing table: \n");
        printf("\t|");
        for(i=1; i<=n; i++)
            printf("%c\t",i+96);
        printf("\n");
        for(i=0; i<=n; i++)
            printf("--------------");
        printf("\n");
        for(i=0; i<n; i++){
            printf("%c      |", i+97);
            for(j=0; j<n; j++){
                scanf("%d", &g[i][j]);
                if(g[i][j] != 999)
                    d[i][j] = 1;
            }
        }
    }
