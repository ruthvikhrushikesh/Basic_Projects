#include<stdio.h>
void board(char arr[3][3]);
void input(char arr[3][3],int);
int win(char arr[3][3]);
int main(){
    int a,b,c=1;
    char arr[3][3];
    printf("\n\nNOTE:-\n-------------\nPLAYER 1-- X\nPLAYER 2-- O\n-------------\nGAMANINCHAGALARU!!\n\n");
    while(c==1){
        for(a=0;a<3;a++)
            for(b=0;b<3;b++)    arr[a][b]=' ';
        board(arr);
        for(a=1;a<=9;a++){
            printf("player %d turn: \n",(a%2) ? 1 : 2);
            input(arr,a);
            board(arr);
            b=win(arr);
            if(b==1){
                printf("player %d GELICHAADU!!\n",(a%2) ? 1 : 2);
                break;
            }
        }
        if(a==10)    printf("\nEEMUNDHI LEY INKO AATA AADU!\n");
        printf("inko aadaali anukuntey 1 nokku: ");
        scanf("%d",&c);
    }
}

void board(char arr[3][3]){
    int i,j;
    printf(" --- --- ---\n");
    for(i=0;i<3;i++){
        printf("|");
        for(j=0;j<3;j++){
            printf(" %c |",arr[i][j]);
        }
        printf("\n --- --- ---\n");
    }
}

void input(char arr[3][3],int k){
    int i,j,a;
    for(a=1;a==1;a++){
        printf("enter row and column: ");
        scanf("%d %d",&i,&j);
        i=i-1 , j=j-1;
        if(i<0 || i>2 || j<0 || j>2){
            printf("Numbers Chuusi Kottu numbers rAAvAA !!\n");
            a--;    continue;
        }
        else if(arr[i][j]!=' '){
            printf("Sarigga chusi input ivvu.. AAta rAAdhAA!!\n");
            a--;    continue;
        }
        (k%2==1) ? arr[i][j]='X' : arr[i][j]='O';
    }
}

int win(char arr[3][3]){
    int i,j;
    for(i=0;i<3;i++){
        if(arr[i][0]!=' ' && arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2])    return 1;
        if(arr[0][i]!=' ' && arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i])    return 1;
    }
    if(arr[1][1]!=' '){
        if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2])    return 1;
        if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0])    return 1;
    }
    return 0;
}
