#include<stdio.h>

int path[6][6];
int start,end; // A = 0,B = 1 ,... , F = 5

int ways[300];
int count = 0;

int s[300];
int c = 0;

void findPath(int a,int b){
    if(a == b){
        int k;
        for(k = 0;k < count;k++){
            switch(ways[k]){
                case 0:
                    printf("A ");
                break;
                case 1:
                    printf("B ");
                break;
                case 2:
                    printf("C ");
                break;
                case 3:
                    printf("D ");
                break;
                case 4:
                    printf("E ");
                break;
                case 5:
                    printf("F ");
                break;
            }
        }
        printf("\n");
    }else{
        int i;
        int sum = -2;
        int p = -2;
        for(i = 0;i < 6;i++){
            if(path[a][i] != 0){

                int j,d = 1;
                for(j = 0;j < count;j++){
                    if(ways[j] == i){
                        d = 0;
                    }
                }

                if(d == 1){
                    ways[count] = i;
                    count++;
                    findPath(i,b);
                    count--;
                    if(sum == -2){
                        sum = path[a][i];
                        p = i;
                    }
                    if(path[a][i] < sum){
                        sum = path[a][i];
                        p = i;
                    }
                }

            }
        }
        int d = 0;
        for(i = 0; i < c;i++){
            if(s[i] == p){
                d = 1;
            }
        }
        if(d == 0){
            s[c] = p;c++;
        }
    }

}

int main(){

    path[1][1] = path[2][2] = path[3][3] = path[4][4] = path[5][5] = 0;
    path[0][1] = path[1][0] = 7;
    path[0][2] = path[2][0] = 1;
    path[0][3] = path[3][0] = 0;
    path[0][4] = path[4][0] = 2;
    path[0][5] = path[5][0] = 0;

    path[1][2] = path[2][1] = 2;
    path[1][3] = path[3][1] = 1;
    path[1][4] = path[4][1] = 0;
    path[1][5] = path[5][1] = 0;

    path[2][3] = path[3][2] = 21;
    path[2][4] = path[4][2] = 10;
    path[2][5] = path[5][2] = 9;

    path[3][4] = path[4][3] = 0;
    path[3][5] = path[5][3] = 5;

    path[4][5] = path[5][4] = 30;

    scanf("%d %d",&start,&end);
    ways[0] = start;count++;
    findPath(start,end);
    s[c] = start;c++;
    printf("Shortest Way : ");
    int i;
    for(i = c-1;i >= 0; i--){
        switch(s[i]){
            case 0:printf("A ");break;
            case 1:printf("B ");break;
            case 2:printf("C ");break;
            case 3:printf("D ");break;
            case 4:printf("E ");break;
            case 5:printf("F ");break;
        }
    }
    return 0;
}
