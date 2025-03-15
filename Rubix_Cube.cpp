#include<stdio.h>

int layer_1(char arr[7][3][3]);
int layer_1_s1(char arr[7][3][3],int base);
int layer_1_s2(char arr[7][3][3]);
int layer_1_s3(char arr[7][3][3]);
void layer_1_s4(char arr[7][3][3]);
void layer_1_2(char arr[7][3][3]);
int layer_1_small(char arr[7][3][3],int,int);

void layer_2(char arr[7][3][3]);

void layer_3(char arr[7][3][3]);

void turn_1(char arr1[3][3]);
void move(char arr[7][3][3],int k,char c,int a);

void up(char arr1[3][3],char arr2[3][3],char arr3[3][3],char arr4[3][3], char arr5[3][3],int);
void down(char arr1[3][3],char arr2[3][3],char arr3[3][3],char arr4[3][3], char arr5[3][3],int);
void left(char arr1[3][3],char arr2[3][3],char arr3[3][3],char arr4[3][3], char arr5[3][3],int);
void right(char arr1[3][3],char arr2[3][3],char arr3[3][3],char arr4[3][3], char arr5[3][3],int);
void face(char arr1[3][3],char arr2[3][3],char arr3[3][3],char arr4[3][3], char arr5[3][3],int);
void back(char arr1[3][3],char arr2[3][3],char arr3[3][3],char arr4[3][3], char arr5[3][3],int);

void input(char arr[3][3]);
void view(char arr[3][3]);
int main(){
    char arr[7][3][3];  // leaving first 2d array and using other 6 2d arrays in 3d array...
    int i,j,k,a,b,a1[6];
    char cube[55]="wwrwywgywybgbrybowworrwyoryggrgogbgoorbygoyrgooywbbbbr";
    for(k=1;k<7;k++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                arr[k][i][j]=' ';
            }
        }
        a1[k-1]=0;
    }
    arr[1][1][1]='g'; arr[2][1][1]='o'; arr[3][1][1]='y'; arr[4][1][1]='r'; arr[5][1][1]='w'; arr[6][1][1]='b';
    printf("\n-------------------- CUBE SOLVER ---------------------\n\n");
    printf("M.U.K.H.Y.A.A.M.S.A.A.L.U:-\nTAKE GREEN COLOUR AS TOP AND BLUE COLOUR AS BOTTOM....\nFOR GREEN TAKE ORANGE AS BOTTOM...\nFOR BLUE TAKE ORANGE AS TOP...\n\nGamaninchagalaru!!!\n\n\n");
    input(arr[3]);  arr[3][1][1]='y';
    input(arr[4]);  arr[4][1][1]='r';
    input(arr[5]);  arr[5][1][1]='w';
    input(arr[2]);  arr[2][1][1]='o';
    input(arr[1]);  arr[1][1][1]='g';
    input(arr[6]);  arr[6][1][1]='b';
    for(k=1;k<7;k++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(arr[k][i][j]=='g')   a1[0]++;
                if(arr[k][i][j]=='o')   a1[1]++;
                if(arr[k][i][j]=='y')   a1[2]++;
                if(arr[k][i][j]=='r')   a1[3]++;
                if(arr[k][i][j]=='w')   a1[4]++;
                if(arr[k][i][j]=='b')   a1[5]++;
            }
        }
    }
    for(k=0;k<6;k++){
        if(a1[k]!=9)    printf("\nits wrong input\n");
    }
    // int l=0;
    // for(i=3;i<=5;i++){
    //     for(j=0;j<3;j++){
    //         for(k=0;k<3;k++){
    //             arr[i][j][k]=cube[l++];
    //         }
    //     }
    // }
    // for(i=2;i>=1;i--){
    //     for(j=0;j<3;j++){
    //         for(k=0;k<3;k++){
    //             arr[i][j][k]=cube[l++];
    //         }
    //     }
    // }
    // for(j=0;j<3;j++){
    //     for(k=0;k<3;k++){
    //         arr[6][j][k]=cube[l++];
    //     }
    // }

    for(i=0;i<3;i++){ 
        for(j=0;j<3;j++){
            if(arr[1][i][j]!='g'){
                layer_1(arr);
                i=-1; break;
            }
        }
    }
    layer_1_s4(arr);
    i=1;
    while(i<=6){
        layer_1_s3(arr);
        i++;
    }
    view(arr[1]);   
    view(arr[2]);   view(arr[3]);   view(arr[4]);   view(arr[5]);
    view(arr[6]);
}
// face(arr[2],arr[1],arr[3],arr[6],arr[5],1);
// back(arr[4],arr[1],arr[3],arr[6],arr[5],1);
// left(arr[5],arr[2],arr[1],arr[4],arr[6],1);
// right(arr[3],arr[2],arr[1],arr[4],arr[6],1);
// down(arr[6],arr[2],arr[3],arr[4],arr[5],1);
// up(arr[1],arr[2],arr[3],arr[4],arr[5],1);
int layer_1(char arr[7][3][3]){
    int i=0,j,a=0,b=0,c=0,m,k,n,count=0;
    i=layer_1_s1(arr,20);
   // special cases
    if(i){
        for(;;i++){   // down
            if(arr[i][1][1]==arr[i][2][1]){         // if green is in arr[6]---blue
                printf(count==1 ? "D " : count==2 ? "D2 " : count==3 ? "D' " : "");
                if(i==2){
                    face(arr[2],arr[1],arr[3],arr[6],arr[5],2);     printf("F2 ");
                }
                else if(i==3){
                    right(arr[3],arr[2],arr[1],arr[4],arr[6],2);    printf("R2 ");
                }
                else if(i==4){
                    back(arr[4],arr[1],arr[3],arr[6],arr[5],2);     printf("B2 ");
                }
                else{
                    left(arr[5],arr[2],arr[1],arr[4],arr[6],2);     printf("L2 ");
                }
                return 0;
            }
            else{
                down(arr[6],arr[2],arr[3],arr[4],arr[5],1);    count++;
            }
            if(i==5)    i=1;
        }
    }
    printf("\n");
    for(c=2,b=0;c<=5;c++){
        if(arr[c][1][0]=='g'){  // if green is in faces (orange,yellow,red,white)
            m=1,n=2;    b=1;
            break;
        }
        if(arr[c][1][2]=='g'){
            m=1,n=0;    b=2;
            break;
        }
        if(arr[c][2][1]=='g'){
            c==2 ? m=0 : c==3 ? m=1 : c==4 ? m=2 : m=1;
            c==2 ? n=1 : c==3 ? n=2 : c==4 ? n=1 : n=0;
            b=4;    break;
        }
        if(arr[c][0][1]=='g'){
            c==2 ? m=2 : c==3 ? m=1 : c==4 ? m=0 : m=1;
            c==2 ? n=1 : c==3 ? n=2 : c==4 ? n=1 : n=0;
            b=3;    break;
        }

    }
    i=c+1,j=c-1;    // right--i left--j face--c back--(else)
    (i==6) ? i=2 : (j==1) ? j=5 : 0;
    // printf("\nc=%d m=%d n=%d i=%d j=%d a=%d b=%d\n",c,m,n,i,j,a,b);
    if(c!=6){
        if(arr[c][1][0]=='g' && b==1){  //b=2
            if(arr[j][m][n]==arr[c][1][1]){
                move(arr,c,'u',1);   move(arr,c,'l',3);
                move(arr,c,'u',3);
            }
            else if(arr[j][m][n]==arr[i][1][1]){
                move(arr,c,'f',2);  move(arr,c,'r',1);
            }
            else{
                move(arr,c,'u',3);  move(arr,c,'l',3);
                move(arr,c,'u',1); 
            }
        }
        else if(arr[c][1][2]=='g' && b==2){ //b=3
            if(arr[i][m][n]==arr[c][1][1]){
                move(arr,c,'u',3);  move(arr,c,'r',1);
                move(arr,c,'u',1);
            }
            else if(arr[i][m][n]==arr[j][1][1]){
                move(arr,c,'f',2);  move(arr,c,'l',3);
            }
            else{
                move(arr,c,'u',1);  move(arr,c,'r',1);
                move(arr,c,'u',3);
            }
        }
        else if(arr[c][0][1]=='g' && b==3){  //b=1
            if(arr[1][m][n]==arr[c][1][1]){
                move(arr,c,'u',1);  move(arr,c,'l',1);
                move(arr,c,'u',3);  move(arr,c,'f',1);
            }
            else{
                move(arr,c,'u',3);  move(arr,c,'r',1);
                move(arr,c,'u',1);  move(arr,c,'b',1);
            }
        }
        else if(arr[c][2][1]=='g' && b==4){ //b=4
            if(arr[6][m][n]==arr[c][1][1]){
                move(arr,c,'f',1);  move(arr,c,'u',1);
                move(arr,c,'l',3);  move(arr,c,'u',3);
            }
            else{
                move(arr,c,'d',1);  move(arr,c,'r',3);
                move(arr,c,'b',1);
            }
        }
    }
    layer_1_s2(arr);
    // upto here plus completed...
    for(i=0,n=1,c=2;i<3;i++){
        for(j=0;j<3;j++){
            if((i+j)%2==1){
                if(!(arr[1][i][j]=='g' && arr[c][0][1]==arr[c][1][1]))  n=0;    // checking plus is completed or not...
                c++;
            }
        }
    }
    if(n){
        for(i=2;i<=5;i++){
            for(j=0;j<3;j++){
                if(j%2==0 && arr[i][2][j]=='g'){
                    layer_1_2(arr); i=1; break;
                }
            }
        }
        for(k=1;k<=4;k++){
            k==1 ? (i=0,j=0) : k==2 ? (i=0,j=2) : k==3 ? (i=2,j=0) : (i=2,j=2);
            if(arr[6][i][j]=='g'){
                for(c=2;c<=5;c++){
                    if(arr[c][0][0]=='g'){
                        c==2 ? (i=0,j=0) : c==3 ? (i=0,j=1) : c==4 ? (i=2,j=2) : (i=2,j=0);
                    }
                    else if(arr[c][0][2]=='g'){
                        c==5 ? (i=0,j=0) : c==2 ? (i=0,j=1) : c==3 ? (i=2,j=2) : (i=2,j=0);
                    }
                    if(arr[c][0][0]=='g' || arr[c][0][2]=='g'){
                        for(n=0;n<3;n++){
                            if(arr[6][i][j]=='g')   break;
                            down(arr[6],arr[2],arr[3],arr[4],arr[5],1);
                        }
                        printf(n==1 ? "D " : n==2 ? "D2 " : n==3 ? "D' " : 0);
                        break;
                    }
                }
                if(c!=6){
                    if(arr[c][0][0]=='g'){
                        move(arr,c,'l',1);  move(arr,c,'d',3);  move(arr,c,'l',3);
                    }
                    else{
                        move(arr,c,'r',3);  move(arr,c,'d',1);  move(arr,c,'r',1);
                    }
                    break;
                }
                else{
                    for(c=2;c<=5;c++){
                        c==2 ? (i=2,j=2) : c==3 ? (i=0,j=2) : c==4 ? (i=0,j=0) : (i=2,j=0);
                        if(arr[1][i][j]!='g'){
                            i==0 ? i=2 : i=0;
                            for(n=0;n<3;n++){
                                if(arr[6][i][j]=='g')   break;
                                down(arr[6],arr[2],arr[3],arr[4],arr[5],1);
                            }
                            printf(n==1 ? "D " : n==2 ? "D2 " : n==3 ? "D' " : 0);
                            break;
                        }
                    }
                    move(arr,c,'r',3);  move(arr,c,'d',1);  move(arr,c,'r',1);
                }
            }
        }
        if(k==5){
            for(c=2;c<=5;c++){
                i=c-1,j=c+1;
                c==2 ? i=5 : c==5 ? j=2 : 0;
                if(arr[c][0][0]=='g'){
                    if(arr[i][0][2]==arr[i][1][1] || arr[i][0][2]==arr[c][1][1]){
                        move(arr,c,'l',1);  move(arr,c,'d',3);  move(arr,c,'l',3);  break;
                    }
                    else{
                        move(arr,c,'f',3);  move(arr,c,'d',3);  move(arr,c,'f',1);  break;
                    }
                }
                else if(arr[c][0][2]=='g'){
                    if(arr[j][0][0]==arr[j][1][1] || arr[j][0][0]==arr[c][1][1]){
                        move(arr,c,'r',3);  move(arr,c,'d',1);  move(arr,c,'r',1);  break;
                    }
                    else{
                        move(arr,c,'f',1);  move(arr,c,'d',1);  move(arr,c,'f',3);  break;
                    }
                }
            }
        }
    }
    return 0;
}

void layer_1_2(char arr[7][3][3]){
    int a,b,c,i,j,k;
    // view(arr[1]);
    for(c=2,b=0;c<=5;c++){
        i=c+1,j=c-1;
        c>3 ? k=c-2 : k=c+2;
        j==1 ? j=5 : i==6 ? i=2 : 0;
        if(arr[c][2][0]=='g'){
            if(arr[j][2][2]==arr[c][1][1] && !(b==3 || b==4 || b==5 || b==6))  a=c,b=1;
            if(arr[j][2][2]==arr[i][1][1] && !(b==3 || b==4 || b==5 || b==6))  a=c,b=2;
            if(arr[j][2][2]==arr[j][1][1])  a=c,b=3;
            if(arr[j][2][2]==arr[k][1][1])  a=c,b=4;
        }
        else if(arr[c][2][2]=='g'){
            if(arr[i][2][0]==arr[i][1][1])  a=c,b=5;
            if(arr[i][2][0]==arr[k][1][1])  a=c,b=6;
            if(arr[i][2][0]==arr[c][1][1] && !(b==3 || b==4 || b==5 || b==6))  a=c,b=7;
            if(arr[i][2][0]==arr[j][1][1] && !(b==3 || b==4 || b==5 || b==6))  a=c,b=8;
        }
    }
    i=a+1,j=a-1;
    a>3 ? k=a-2 : k=a+2;
    j==1 ? j=5 : i==6 ? i=2 : 0;
    // printf("\na=%d b=%d i=%d j=%d k=%d\n",a,b,i,j,k);
    if(b){
        if(b==1){
            move(arr,a,'d',1);  move(arr,a,'r',3);  move(arr,a,'d',3);  move(arr,a,'r',1);
        }
        else if(b==2){
            move(arr,k,'d',3);  move(arr,k,'l',1);  move(arr,k,'d',3);  move(arr,k,'l',3);
        }
        else if(b==3){
            move(arr,j,'r',3);  move(arr,j,'d',3);  move(arr,j,'r',1);
        }
        else if(b==4){
            move(arr,j,'l',1);  move(arr,j,'d',3);  move(arr,j,'l',3);
        }
        else if(b==5){
            move(arr,a,'f',1);  move(arr,a,'d',1);  move(arr,a,'f',3);
        }
        else if(b==6){
            move(arr,i ,'r',3);  move(arr,i,'d',1);  move(arr,i,'r',1);
        }
        else if(b==7){
            move(arr,a,'d',3);  move(arr,a,'l',1);  move(arr,a,'d',1);  move(arr,a,'l',3);
        }
        else if(b==8){
            move(arr,k,'d',1);  move(arr,k,'r',3);  move(arr,k,'d',1);  move(arr,k,'r',1);
        }
    }
}
int layer_1_s1(char arr[7][3][3],int base){ 
    if(base<=1) return 0;
    int a=0,i,j,m,n=0,c=0,count;
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                if((i+j)%2!=0 && arr[1][i][j]=='g') c++;
                // rbyoywwrrryygrgbbwowgrwoorroywyoggwobggogoyrbwbgwbbbyy
        for(i=1;i<=4;i++){
            count=0;
            if(arr[1][2][1]=='g' && arr[2][0][1]==arr[2][1][1]) a=i,count++;
            if(arr[1][1][2]=='g' && arr[3][0][1]==arr[3][1][1]) a=i,count++;
            if(arr[1][0][1]=='g' && arr[4][0][1]==arr[4][1][1]) a=i,count++;
            if(arr[1][1][0]=='g' && arr[5][0][1]==arr[5][1][1]) a=i,count++;
            if((c!=1 && count<2) || (c==1 && count!=1))
                up(arr[1],arr[2],arr[3],arr[4],arr[5],1),n++;
            else  break;
        }
        // printf("\na=%d i=%d n=%d count=%d \n",a,i,n,count);
        if(i==5 && a){
            if(a!=1)   a==4 ? move(arr,2,'u',1) : move(arr,2,'u',a);
        }
        else  printf(n==1 ? "U " : n==2 ? "U2 " : n==3 ? "U' " : 0);

    for(a=2;a<=5;a++){
        i=a+1,j=a-1;    
        (i==6) ? i=2 : (j==1) ? j=5 : 0;

        if(arr[a][1][0]=='g' && arr[j][1][2]==arr[j][1][1]){
            move(arr,a,'l',3);  layer_1_s1(arr,base-1);  
        }
        if(arr[a][1][2]=='g' && arr[i][1][0]==arr[i][1][1]){
            move(arr,a,'r',1);  layer_1_s1(arr,base-1);
        }
    }

    for(a=2;a<=5;a++){
        i=a+1,j=a-1;    
        (i==6) ? i=2 : (j==1) ? j=5 : 0;
        
        a==2 ? m=2 : a==3 ? m=1 : a==4 ? m=0 : m=1;
        a==2 ? n=1 : a==3 ? n=2 : a==4 ? n=1 : n=0;
        if(arr[a][0][1]=='g' && arr[1][m][n]==arr[i][1][1]){
            move(arr,a,'f',1);  move(arr,a,'r',1);  layer_1_s1(arr,base-1);
        }
        if(arr[a][0][1]=='g' && arr[1][m][n]==arr[j][1][1]){
            move(arr,a,'f',3);  move(arr,a,'l',3);  layer_1_s1(arr,base-1);
        }

        a==2 ? m=0 : a==3 ? m=1 : a==4 ? m=2 : m=1;
        a==2 ? n=1 : a==3 ? n=2 : a==4 ? n=1 : n=0;
        if(arr[a][2][1]=='g' && arr[6][m][n]==arr[i][1][1]){
            move(arr,a,'f',3);  move(arr,a,'r',1);  layer_1_s1(arr,base-1);
        }
        if(arr[a][2][1]=='g' && arr[6][m][n]==arr[j][1][1]){
            move(arr,a,'f',1);  move(arr,a,'l',3);  layer_1_s1(arr,base-1);
        }
    }
    
    i=0;
    if(arr[6][0][1]=='g'){      // if green edges are in blue face
        i=2;
        if(arr[2][1][1]==arr[2][2][1])  a=1;
    }   
    if(arr[6][1][2]=='g'){
        if(a!=1)    i=3;
        if(arr[3][1][1]==arr[3][2][1])  a=1;
    }   
    if(arr[6][2][1]=='g'){
        if(a!=1)    i=4;
        if(arr[4][1][1]==arr[4][2][1])  a=1;
    }
    if(arr[6][1][0]=='g'){
        if(a!=1)    i=5;
        if(arr[5][1][1]==arr[5][2][1])  a=1;
    }
    if(a!=1){
        if(arr[6][0][1]=='g' && arr[6][1][2]=='g'){
            if(arr[2][2][1]==arr[3][1][1] && arr[3][2][1]==arr[4][1][1])  i=2;}
        if(arr[6][1][2]=='g' && arr[6][2][1]=='g'){
            if(arr[3][2][1]==arr[4][1][1] && arr[4][2][1]==arr[5][1][1])  i=3;}
        if(arr[6][2][1]=='g' && arr[6][1][0]=='g'){
            if(arr[4][2][1]==arr[5][1][1] && arr[5][2][1]==arr[2][1][1])  i=4;}
    }
    return i;
}
int layer_1_s2(char arr[7][3][3]){
    int i=0,j,n,count,a,c;
    if(arr[1][0][1]=='g' && arr[1][1][0]=='g' && arr[1][1][2]=='g' && arr[1][2][1]=='g'){
        for(i=2;i<=5;i++)
            if(arr[i][0][1]!=arr[i][1][1])  break;      // if all green edges are set...
        count=0;
        if(i!=6){
            n=0;
            for(j=1;j<=4;j++){
                count=0;
                for(a=2;a<=5;a++){
                    if(arr[a][0][1]==arr[a][1][1])  count++;
                    else    i=c,c=a;
                }
                if(count>=2)  continue;
                else{
                    up(arr[1],arr[2],arr[3],arr[4],arr[5],1);   n++;
                }   
            }
            printf(n==1 ? "U " : n==2 ? "U2 " : n==3 ? "U' " : 0);
        }
        if(count==2){
            if((c+i)%2==0){
                move(arr,c,'u',2);  move(arr,c,'f',1);  move(arr,c,'b',1);
                move(arr,c,'u',2);  move(arr,c,'f',3);  move(arr,c,'b',3);
            }
            else{
                if(c==5 && i==2)    c=2;
                move(arr,c,'f',2);  move(arr,c,'d',3);  move(arr,c,'l',2);
                move(arr,c,'d',1);  move(arr,c,'f',2);
            }
        }
    }
    return 0;
}
int layer_1_s3(char arr[7][3][3]){
    int i,j,b,c;
    char d;
    for(c=2;c<=5;c++){
        if((d=arr[c][0][1])!=arr[c][1][1])  break;
    }
    if(c!=6){
        layer_1_small(arr,c,1);
        while(1){
            // yyybywrrrrrwbrybwbowrowywbywooroobobgggggggggowwybbory
            // ryowyrbwbyrrbrrrbbwwwywywwyooyooobbrgggggggggoyyrbboow
            c==2 ? (i=3,j=5) : c==3 ? (i=4,j=2) : c==4 ? (i=5,j=3) : c==5 ? (i=2,j=4) : 0;
            if(d==arr[j][1][1]){
                d=arr[j][0][1];
                move(arr,c,'d',1);  layer_1_small(arr,j,1);
                c=j;
            }
            else if(d==arr[i][1][1]){ 
                d=arr[i][0][1];
                move(arr,c,'d',3);  layer_1_small(arr,i,1);
                c=i;
            }
            else{
                c>3 ? i=c-2 : i=c+2;
                d=arr[i][0][1];    layer_1_small(arr,i,1);
                c=i;
            }
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if(arr[1][i][j]!='g')   break;
                }
                if(j!=3)    break;
            }
            if(i==3)    break;
        }
    }
    else{
        for(c=2;c<=5;c++){
            for(i=0;i<=2;i+=2){
                if(arr[c][0][i]!=arr[c][1][1])  break;
            }
            if(i!=4)    break;
        }
        c==2 ? (i=3,j=5) : c==3 ? (i=4,j=2) : c==4 ? (i=5,j=3) : (i=2,j=4);
        if(c==6)    return 1;
        else if(arr[c][0][2]!=arr[c][1][1]){
            if(arr[c][0][2]==arr[i][1][1]){
                move(arr,i,'l',1);  move(arr,i,'d',1);  move(arr,i,'l',3);
            }
            else {
                move(arr,c,'r',3);  move(arr,c,'d',3);  move(arr,c,'r',1);
            }
        }
        else{
            if(arr[c][0][0]==arr[i][1][1]){
                move(arr,c,'l',1);  move(arr,c,'d',1);  move(arr,c,'l',3);
            }
            else {
                move(arr,j,'r',3);  move(arr,c,'d',3);  move(arr,c,'j',1);
            }
        }
        for(i=0;i<=2;i+=2){
            for(j=0;j<=2;j+=2){
                if(arr[1][i][j]!='g'){
                    layer_1_2(arr);
                    i=-2; break;
                }
            }
        }
    }
    return 0;
}

void layer_1_s4(char arr[7][3][3]){
    int i,count,a=0,c;
    for(i=1;i<=3;i++){
        count=0;
        for(c=2;c<=5;c++){
            if(arr[c][0][1]==arr[c][1][1])  count++;
        }
        if(count<2){
            a++;
            up(arr[1],arr[2],arr[3],arr[4],arr[5],1);
        }
        else    break;
    }
    printf(a==3 ? "U' " : a==2 ? "U2 " : a==1 ? "U " : 0);
}

// yrywyyrrrryrorwbyywowrwybbboworoowobgggggggggobwwbboby

int layer_1_small(char arr[7][3][3],int c,int a){
    move(arr,c,'r',1);  move(arr,c,'l',3);  move(arr,c,'f',a);
    move(arr,c,'r',3);  move(arr,c,'l',1);
    printf("\n");
    return 0;
}

void move(char arr[7][3][3],int k,char c,int a){
    int i,j;
    char b;
    for(i=1;i<=a;i++){
        if((c=='f' && k==2) || (c=='l' && k==3) || (c=='b' && k==4) || (c=='r' && k==5)){
            face(arr[2],arr[1],arr[3],arr[6],arr[5],1);
            b='F';
        }
        else if((c=='r' && k==2) || (c=='f' && k==3) || (c=='l' && k==4) || (c=='b' && k==5)){
            right(arr[3],arr[2],arr[1],arr[4],arr[6],1);
            b='R';
        }
        else if((c=='b' && k==2) || (c=='r' && k==3) || (c=='f' && k==4) || (c=='l' && k==5)){
            back(arr[4],arr[1],arr[3],arr[6],arr[5],1);
            b='B';
        }
        else if((c=='l' && k==2) || (c=='b' && k==3) || (c=='r' && k==4) || (c=='f' && k==5)){
            left(arr[5],arr[2],arr[1],arr[4],arr[6],1);
            b='L';
        }
        if(c=='u'){
            if(k==3)    for(j=1;j<=3;j++)   turn_1(arr[1]);
            if(k==4)    for(j=1;j<=2;j++)   turn_1(arr[1]);
            if(k==5)    turn_1(arr[1]);
            b='U';
            up(arr[1],arr[2],arr[3],arr[4],arr[5],1);

            if(k==3)    turn_1(arr[1]);
            if(k==4)    for(j=1;j<=2;j++)   turn_1(arr[1]);
            if(k==5)    for(j=1;j<=3;j++)   turn_1(arr[1]);
        }
        if(c=='d'){
            if(k==3)    turn_1(arr[6]); 
            if(k==4)    for(j=1;j<=2;j++)   turn_1(arr[6]);
            if(k==5)    for(j=1;j<=3;j++)   turn_1(arr[6]);
            b='D';
            down(arr[6],arr[2],arr[3],arr[4],arr[5],1);

            if(k==3)    for(j=1;j<=3;j++)   turn_1(arr[6]);
            if(k==4)    for(j=1;j<=2;j++)   turn_1(arr[6]);
            if(k==5)    turn_1(arr[6]);
        }
    }
    printf("%c",b);
    printf(a==1 ? " " : a==2 ? "2 " : "' ");
}
void input(char arr[3][3]){
    int i,j;
    view(arr);
    for(i=0;i<3;i++){
        printf("enter %d row: ",i+1);
        scanf(" %c %c %c",&arr[i][0],&arr[i][1],&arr[i][2]);
    }
    view(arr);
}
void view(char arr[3][3]){
    int i,j;
    printf("\n-------------\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)    printf("| %c ",arr[i][j]);
        printf("|\n-------------\n");
    }
}
void down(char arr1[3][3],char arr2[3][3],char arr3[3][3],char arr4[3][3], char arr5[3][3],int k){
    char b1[3],a[3],b2[3],b0[3];
    int i;
    for(i=0;i<3;i++){
        a[i]=arr2[2][i];
    }
    for(i=0;i<3;i++){
        turn_1(arr1);
        arr2[2][i]=arr5[2][i];
        arr5[2][i]=arr4[2][i];
        arr4[2][i]=arr3[2][i]; 
        arr3[2][i]=a[i];
    }
    if(k>1) down(arr1,arr2,arr3,arr4,arr5,k-1);
}
void up(char arr1[3][3],char arr2[3][3],char arr3[3][3],char arr4[3][3], char arr5[3][3],int k){
    char b1[3],a[3],b2[3],b0[3];
    int i;
    for(i=0;i<3;i++){ 
        a[i]=arr2[0][i];
    }
    for(i=0;i<3;i++){
        arr2[0][i]=arr5[0][i];
        arr5[0][i]=arr4[0][i];
        arr4[0][i]=arr3[0][i];
        arr3[0][i]=a[i];
    }
    turn_1(arr1);
    if(k<3) up(arr1,arr2,arr3,arr4,arr5,k+1);
}
void right(char arr1[3][3],char arr2[3][3],char arr3[3][3],char arr4[3][3], char arr5[3][3],int k){
    char b1[3],a[3],b2[3],b0[3],c[3];
    int i;
    for(i=0;i<3;i++){
        a[i]=arr3[i][2];    c[i]=arr4[i][0];
    }
    for(i=0;i<3;i++){
        arr3[i][2]=arr2[i][2];
        arr2[i][2]=arr5[i][2];
        arr4[i][0]=a[2-i];
        arr5[i][2]=c[2-i];
        turn_1(arr1);
    }
    if(k>1) right(arr1,arr2,arr3,arr4,arr5,k-1);
}
void left(char arr1[3][3],char arr2[3][3],char arr3[3][3],char arr4[3][3], char arr5[3][3],int k){
    char b[3],a[3];
    int i;
    for(i=0;i<3;i++){
        a[i]=arr3[i][0];    b[i]=arr4[i][2];
    }
    for(i=0;i<3;i++){
        arr3[i][0]=arr2[i][0];
        arr2[i][0]=arr5[i][0];
        arr4[i][2]=a[2-i];
        arr5[i][0]=b[2-i];
    }
    turn_1(arr1);
    if(k<3) left(arr1,arr2,arr3,arr4,arr5,k+1);
}
void face(char arr1[3][3],char arr2[3][3],char arr3[3][3],char arr4[3][3], char arr5[3][3],int k){
    int i,j;    char a[3],b[3];
    for(i=0;i<3;i++){
        a[i]=arr2[2][i];
    }
    for(i=0;i<3;i++){
        arr2[2][2-i]=arr5[i][2];
        arr5[i][2]=arr4[0][i];
        arr4[0][i]=arr3[2-i][0];
        arr3[2-i][0]=a[2-i];
        turn_1(arr1);
    }
    if(k>1) face(arr1,arr2,arr3,arr4,arr5,k-1);
}
void back(char arr1[3][3],char arr2[3][3],char arr3[3][3],char arr4[3][3], char arr5[3][3],int k){
    int i,j;    char a[3],b[3];
    for(i=0;i<3;i++){
        a[i]=arr2[0][i];
    }
    for(i=0;i<3;i++){
        arr2[0][2-i]=arr5[i][0];
        arr5[i][0]=arr4[2][i];
        arr4[2][i]=arr3[2-i][2];
        arr3[2-i][2]=a[2-i];
    }
    turn_1(arr1);
    if(k<3) back(arr1,arr2,arr3,arr4,arr5,k+1); 
}
void turn_1(char arr1[3][3]){
    int i,j;
    char a1[3],a2[3],a3[3];
    for(i=0;i<3;i++){
        a1[i]=arr1[i][0]; a2[i]=arr1[i][1]; a3[i]=arr1[i][2];
    }
    for(i=0;i<3;i++){
        arr1[2][i]=a1[i]; arr1[1][i]=a2[i]; arr1[0][i]=a3[i];
    }
}
// wwrgyyoryyoygrrobbrorgwwobwbyrgooobggybwgbwrgbywobwyrg
// wwrwywgywybgbrybowworrwyoryggrgogbgoorbygoyrgooywbbbbr
// wwrwywoyyybrbrbbwgbyrowyoybgorgogwgywrbbgoyggorgobrwro
// bgwoyrowwggggrrbyoyyywwywwybrwoobbwyrorbgyrbooggbbogrr
// gybyygybgwwwrrgobbgrywwgwrbbbroogobgrorygorwyyrowbooyw
// ggbyyywrgwrobrowogbwbbwgyoorbrworwrbybrogyywygwoybgogr
// ygbgyorwywrywroorooowgwybryobroorgbwbbrbgygybrwgybgwwg
// owwwyoororowwrbwwrgbyowybrgobbgobrgyrybyggbrwyogybgyrg
// yrwbyyorgbogbrwyybrorgwrrbygobwoorygwwogggyyobgwwbbwro
// wwbbyrrygworyrworrgoorwggooyborooybyygrygggybbwbwbgwbw
// ybwrygrybgwgyryrgrwbbrwgyowygoroboryoorwgyoogbwbbbogww
// rrwwyyyyybbobrobyygbybwogwwbygworbogwworggrgwrgogborro
// gorbyyyobwrggrworbwwwowyrryboybowgbboggggyogorrrwbbwyy
// yyywywyorbrwbrbwrybwwrwobbroooworgorogrggggggwygybboyb
// oyyoywbbybrrbrobrgwwwywyryboogbowwwwggrgggggyorrrboybo
// owwoyobbogbgwrogbwyrbgwygrrybbroybywryrwggorwygrgboowy
// goroybwrryybrrbgygowbowwrobybyrowrgowgbgggowowrgybyybw
// yyywywyorbrwbrbwrybwwrwobbroooworgorogrggggggwygybboyb
// yywryrbwrorgbrbyoyrwwowybryrooboyrbowgggggbggbwwwbooyg
// yoobybwwrwwwyrbgogroyrwyrwygybroorrobrbyggogobgggbbyww
// yybryrwyrwrrwryybbwwwowwobroooooybbbggrggggggyworbbyog
// U set...
// gygwybwobrobyryyrwwroowboroywrworyborgwgggggybogybwbbr
// yoobyboobyybyrbwrrrrywwwwowrwbroorygygggggggogrwybwbbo   
// gybwyboobrrbyrowrryoybwwwowrworobryyogygggggwgrgybwbbo
// rybbyboobroworbwryrwowwwbowgryroyryybgygggwgggrgybwobo
// gwboyyowgwrworboywbybowwrbgrorrowyybogrgggygyoryrbbgbw
// bowbyyowgrrborwrywywyowwryygywroorrgogbgggogobbwrbbgby
// brooywowrwwgorywrwroyowygrygyybobgbbwgbgggogrrrywbboyb
// wybbywoorowgbrowworryywbgbyrogoorrybwgwgggggobryybwyrb
