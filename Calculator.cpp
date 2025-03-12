#include<stdio.h>
#include<math.h>
double num(char[100]);
double solve(char[100],double[100]);
double power(double,double);
double factorial(double);
int main(){
    printf("\n");
    int i,j,a=0,b,c,t,n,check=0,dots=0;
    char m[100];
    char p[100];
    double arr[100];

    for(b=1;b==1;b++){
        printf("enter:  ");
        scanf(" %[^\n]",m);
        for(n=0;m[n]!='\0';n++);
        // inserting two more brackets before and after eqn...
        for(i=n;i>0;i--){
            m[i]=m[i-1];
        }
        m[n+1]=')'; m[0]='('; n=n+2;
        //checking valid inputs...
        for(i=1,c=0;i<n-1;i++){
            if(m[i]=='(')
                c=c+1;
            else if(m[i]==')')
                c=c-1;
            if(c<0) break;
        }
        if(c!=0){
            printf("brackets are not valid\nagain ");
            b=b-1;
        }
        j=0,c=0;

        for(i=0,j=0;i<n;i++){
            if(!(m[i]>=48 && m[i]<=57)){
                if(m[i]=='.')    j++;
                if(m[i]!='.' && j>=1)    j--;
                if(j==2)    break;
            }
        }
        if(j==2){
            printf("invalid dots\nagain ");
            b=b-1;
        }

        for(j=0;j<n;j++){
            if((m[j]=='-' && m[j-1]=='(') || m[j]=='.')   c=1;
            if(!((m[j]>=48 && m[j]<=57)  )){
                if(m[j]=='!' && c==1){
                    printf("cannot solve factorial for negative numbers or decimals.. \nagain ");
                    b=b-1;  break;
                }
                if(m[j]!='-' && m[j]!='.'){
                    c=0;
                }
            }
        }  
    }
    // giving single spaces for numerical values... && converting the numbers in string into float values...
    for(i=0,j=0;i<n;i++){
        for(c=i+1;c<n;c++){
            if(!(m[c]>=49 && m[c]<=57)){
                check=c;
                break;
            }
        }
        if((m[i]>=48 && m[i]<=57) || m[i]=='.'|| ((m[i]=='-' && m[check]!='^') && (m[i-1]=='(' || m[i-1]=='^' || m[i-1]=='*' || m[i-1]=='+' || m[i-1]=='-' || m[i-1]=='/' || i==0))){
            p[a++]=m[i];
            m[i]=' ';
        }
        else if(!(m[i]>=48 && m[i]<=57) && m[i-1]==' ' && i!=0){
            arr[j++]=num(p);
            b=j;
            for(t=0;t<a;t++){
                p[t]='\0';
            }
            a=0;
        }
    }
    if(p[0]!='\0'){
        arr[j]=num(p);
        b=j+1;
    }

    if(m[n-1]==' ')    m[n-1]='\0';
    
    char rand[100];
    for(i=0,j=0,check=0;i<n;i++){       // changing string into normal equation.....
        if(m[i]==' '){      // checking if there are any numbers...
            check++;
            if(m[i-1]==')') rand[j++]='*';      // if number after close bracket,then it will place * there...
        }
        if(m[i]!=' '){
            if(check==0){       // if there are no numbers infront of the characters
            //if m[i] is closed bracket and infront there are numbers or faactorial or closed bracket, it will place * before closed bracket(between m[i&i-1])
                if(m[i]=='(' && ( m[i-1]== ')' || m[i-1]==' ' || m[i-1]=='!'))  rand[j++]='*';
                rand[j++]=m[i];
            }
            else{   // if there are numbers infront of characters
                rand[j++]=' ';
                if(m[i]=='(')   rand[j++]='*';
                rand[j++]=m[i];
            }
            check=0;
        } 
    }
    for(i=0;i<j;i++)    m[i]=rand[i];

    for(i=j;i<100;i++)    m[i]='\0';
    for(i=b;i<100;i++)    arr[i]='\0';

    for(i=0,c=65;i<j;i++)
        if(m[i]==' ')    m[i]=c++;

    double ans=solve(m,arr);
    printf("answer: %f\n",ans);
}
double num(char m[100]){
    int i,k,n=0,o=1,p,count=0;
    double l,j=0;
    for(k=0;m[k]!='\0';k++);
    for(i=0;i<k;i++){
        if(m[i]=='-')   count=1;
        if(m[i]=='.'){
            n=i;
            continue;
        }  
        l=(double)(m[i] - '\0');
        if(l==48)  l=0;
        else if(l==49)  l=1;
        else if(l==50)  l=2;
        else if(l==51)  l=3;
        else if(l==52)  l=4;
        else if(l==53)  l=5;
        else if(l==54)  l=6;
        else if(l==55)  l=7;
        else if(l==56)  l=8;
        else if(l==57)  l=9;
        else    continue;
        if(m[n]!='.')   j=j*10+l;
        else{
            for(p=1;p<=o;p++){
                l=l/10;
            }
            j=j+l;
            o++;
        }
    }
    if(count)   j=-j;  
    return j;
}
double solve(char m[100],double arr[100]){
    int i,j,a,b,x,y,z,alpha,count;

    for(z=1;z==1;z++){
        for(i=0,x=0 ; m[i]!='\0' ; i++,x++){    // char array size
            if(m[i]=='(')   a=i,count=0;
            if(i>a && m[i]==')' && count==0)    b=i,count++;    // to find the first opened bracket..
        }
        // int array size
        for(y=1;y==1;y++){
            count=0;
            for(i=a;i<=b;i++){
                if(m[i]=='!'){
                    count++;
                    alpha=m[i-1]-65;
                    arr[alpha]=factorial(arr[alpha]);
                    for(j=i;j<=x;j++){
                        m[j]=m[j+1];
                        m[j+1]='\0';
                    }
                    break;
                }
            }
            if(!count){
                for(i=b;i>=a;i--){
                    if(m[i]=='^'){
                        count+=2;
                        alpha=m[i-1]-65;
                        arr[alpha]=pow(arr[alpha],arr[alpha+1]);
                        break;
                    }
                }
            }
            if(!count){
                for(i=a;i<=b;i++){
                    if(m[i]=='%'){
                        count+=2;
                        alpha=m[i-1]-65;
                        arr[alpha]=(arr[alpha]/100)*arr[alpha+1];
                        break;
                    }
                }
            }
            if(!count){
                for(i=a;i<=b;i++){
                    if(m[i]=='/'){
                        count+=2;
                        alpha=m[i-1]-65;
                        arr[alpha]=arr[alpha]/arr[alpha+1];
                        break;
                    }
                }
            }
            if(!count){
                for(i=a;i<=b;i++){
                    if(m[i]=='*'){
                        count+=2;
                        alpha=m[i-1]-65;
                        arr[alpha]=arr[alpha]*arr[alpha+1];
                        break;
                    }
                    
                }
            }
            if(!count){
                for(i=a;i<=b;i++){
                    if(m[i]=='+'){
                        count+=2;
                        alpha=m[i-1]-65;
                        arr[alpha]=arr[alpha]+arr[alpha+1];
                        break;
                    }
                    if(m[i]=='-'){
                        count+=2;
                        alpha=m[i-1]-65;
                        arr[alpha]=arr[alpha]-arr[alpha+1];
                        break;
                    }
                }
            }
            if(count==2){
                for(j=i;j<=x;j++){
                    m[j]=m[j+2];
                    m[j+2]='\0';
                    if(m[j]>=65 && m[j]<=90)    m[j]=m[j]-1;
                }
                for(j=alpha+1;m[j]!='\0';j++){
                    arr[j]=arr[j+1];
                    arr[j+1]=0;
                }
                arr[j-1]='\0';
            }
            for(i=0;i<count;i++)    b--;
            for(i=a+1;i<b;i++){
                if(m[a+1]=='-' && m[a+2]>=65 && m[a+2]<=90 && m[a+3]==')'){
                    arr[alpha]=-arr[alpha];
                    y=1;
                    break;;
                }
                if(!(m[i]>=65 && m[i]<=90))  y=0;
            }
        }
        m[a]=m[a+1];
        for(i=a+1;i<=x;i++){
            m[i]=m[i+2];
            m[i+2]='\0';
        }
        for(i=0;i<x;i++){
            if(m[i]=='('){
                z--;
                break;
            }
        }
    }
    return arr[alpha];
}
double factorial(double a){
    int k=(int)a;
    for(int i=1;i<k;i++){
        a=a*i;
    }
    if(k==0)    a=1;
    return a;
}
// 5(8*7+(9^2(78+98)-98(2)+7)-345*2)+5(8*7+(9^2(78+98-982)))
// 5(8*7+(9^2(78+98)-98(2)+7)-3.45*2)+5(8*7+(9^2(78+98-9.82)))
// 5(8*7+(9^2)(78+98)-98(2)+7)-3.45*2)+5(8*7+(9^2(78+98-9.82)))
// 989*(87+((87*78)+98(7+9)+987))
// 989(87+(87*78)+987+9)+987
// 989(87+87*78+987^2+987/9)+987+986+985+984+987
// 989(987+9)+987
// 989+(87+((87*78)+98 7+9+987))
// 989*987+9+987
// 5(6*5)5
// 5(8*7+(9^2(78+98)-98(2)+7)-345*2)
