#include<stdio.h>
void letter(char,int);
int main(){
    int a1,i;
    char c1[30],a2[3];
    printf("\n");
    for(int j=1;j==1;j++){
        printf("Enter a String: ");
        scanf(" %[^\n]",c1);

        for(i=1;i<=8;i++){
            for(a1=0;c1[a1]!='\0';a1++){
                letter(c1[a1],i);
                if(c1[a1]==' ') printf("    ");
                printf("  ");
            }
            printf("\n");
        }
        printf("need again? (yes-1 or y or Y) ");
        scanf(" %s",a2);
        if(a2[0]=='1' || a2[0]=='y' || a2[0]=='Y')  j=j-1;
    }
}
void letter(char a1,int k){
    if(a1=='a' || a1=='A'){
        if(k==1)    printf("      ____      ");
        if(k==2)    printf("     / /\\ \\     ");
        if(k==3)    printf("    / /  \\ \\    ");
        if(k==4)    printf("   / /____\\ \\   ");
        if(k==5)    printf("  /  ______  \\  ");
        if(k==6)    printf(" / /        \\ \\ ");
        if(k==7)    printf("/_/          \\_\\");
    }
    else if(a1=='b' || a1=='B'){
        if(k==1)    printf(" _________ ");
        if(k==2)    printf("|  ______ \\");
        if(k==3)    printf("| |     / /");
        if(k==4)    printf("| |____/_/ ");
        if(k==5)    printf("|  _____  \\");
        if(k==6)    printf("| |_____/ /");
        if(k==7)    printf("|________/ ");
    }
    else if(a1=='c' || a1=='C'){
        if(k==1)    printf(" _________ ");
        if(k==2)    printf("|   ______|");
        if(k==3)    printf("|  |       ");
        if(k==4)    printf("|  |       ");
        if(k==5)    printf("|  |       ");
        if(k==6)    printf("|  |______ ");
        if(k==7)    printf("|_________|");
    }
    else if(a1=='d' || a1=='D'){
        if(k==1)    printf(" _______   ");
        if(k==2)    printf("|  ____ \\  ");
        if(k==3)    printf("| |    \\ \\ ");
        if(k==4)    printf("| |     \\ \\");
        if(k==5)    printf("| |     / /");
        if(k==6)    printf("| |____/ / ");
        if(k==7)    printf("|_______/  ");
    }
    else if(a1=='e' || a1=='E'){
        if(k==1)    printf(" ________ ");
        if(k==2)    printf("|  ______|");
        if(k==3)    printf("| |______ ");
        if(k==4)    printf("|  ______|");
        if(k==5)    printf("| |       ");
        if(k==6)    printf("| |______ ");
        if(k==7)    printf("|________|");
    }
    else if(a1=='f' || a1=='F'){
        if(k==1)    printf(" _________ ");
        if(k==2)    printf("|  _______|");
        if(k==3)    printf("| |        ");
        if(k==4)    printf("| |_______ ");
        if(k==5)    printf("| |_______|");
        if(k==6)    printf("| |        ");
        if(k==7)    printf("|_|        ");
    }
    else if(a1=='g' || a1=='G'){
        if(k==1)    printf(" _________  ");
        if(k==2)    printf("|  _______| ");
        if(k==3)    printf("| |   _____ ");
        if(k==4)    printf("| |  |___  |");
        if(k==5)    printf("| |______| |");
        if(k==6)    printf("|________| |");
        if(k==7)    printf("    _____|_|");
    }
    else if(a1=='h' || a1=='H'){
        if(k==1)    printf(" __      __ ");
        if(k==2)    printf("|  |    |  |");
        if(k==3)    printf("|  |____|  |");
        if(k==4)    printf("|   ____   |");
        if(k==5)    printf("|  |    |  |");
        if(k==6)    printf("|  |    |  |");
        if(k==7)    printf("|__|    |__|");
    }
    else if(a1=='i' || a1=='I'){
        if(k==1)    printf(" ____________ ");
        if(k==2)    printf("|____    ____|");
        if(k==3)    printf("     |  |     ");
        if(k==4)    printf("     |  |     ");
        if(k==5)    printf("     |  |     ");
        if(k==6)    printf(" ____|  |____ ");
        if(k==7)    printf("|____________|");
    }
    else if(a1=='j' || a1=='J'){
        if(k==1)    printf(" ____________ ");
        if(k==2)    printf("|____    ____|");
        if(k==3)    printf("     |  |     ");
        if(k==4)    printf("     |  |     ");
        if(k==5)    printf("     |  |     ");
        if(k==6)    printf(" ____|  |     ");
        if(k==7)    printf("|_______|     ");
    }
    else if(a1=='k' || a1=='K'){
        if(k==1)    printf(" __     _ ");
        if(k==2)    printf("|  |  /  /");
        if(k==3)    printf("|  | /  / ");
        if(k==4)    printf("|  |/  /  ");
        if(k==5)    printf("|  |\\  \\  ");
        if(k==6)    printf("|  | \\  \\ ");
        if(k==7)    printf("|__|  \\ _\\");
    }
    else if(a1=='l' || a1=='L'){
        if(k==1)    printf(" _        ");
        if(k==2)    printf("| |       ");
        if(k==3)    printf("| |       ");
        if(k==4)    printf("| |       ");
        if(k==5)    printf("| |       ");
        if(k==6)    printf("| |______ ");
        if(k==7)    printf("|________|");
    }
    else if(a1=='m' || a1=='M'){
        if(k==1)    printf(" ___      ___ ");
        if(k==2)    printf("| | \\    / | |");
        if(k==3)    printf("| |\\ \\  / /| |");
        if(k==4)    printf("| | \\ \\/ / | |");
        if(k==5)    printf("| |  \\__/  | |");
        if(k==6)    printf("| |        | |");
        if(k==7)    printf("|_|        |_|");
    }
    else if(a1=='n' || a1=='N'){
        if(k==1)    printf(" ___      _ ");
        if(k==2)    printf("|   \\    | |");
        if(k==3)    printf("| |\\ \\   | |");
        if(k==4)    printf("| | \\ \\  | |");
        if(k==5)    printf("| |  \\ \\ | |");
        if(k==6)    printf("| |   \\ \\| |");
        if(k==7)    printf("|_|    \\___|");
    }
    else if(a1=='o' || a1=='O'){
        if(k==1)    printf(" _________ ");
        if(k==2)    printf("|  _____  |");
        if(k==3)    printf("| |     | |");
        if(k==4)    printf("| |     | |");
        if(k==5)    printf("| |     | |");
        if(k==6)    printf("| |_____| |");
        if(k==7)    printf("|_________|");
    }
    else if(a1=='p' || a1=='P'){
        if(k==1)    printf(" __________ ");
        if(k==2)    printf("|   ____   |");
        if(k==3)    printf("|  |    |  |");
        if(k==4)    printf("|  |____|  |");
        if(k==5)    printf("|   _______|");
        if(k==6)    printf("|  |        ");
        if(k==7)    printf("|__|        ");
    }
    else if(a1=='q' || a1=='Q'){
        if(k==1)    printf(" _______ ");
        if(k==2)    printf("||     ||");
        if(k==3)    printf("||     ||");
        if(k==4)    printf("||   _ ||");
        if(k==5)    printf("||___\\\\||");
        if(k==6)    printf("      \\\\ ");
        if(k==7)    printf("       \\\\");
    }
    else if(a1=='r' || a1=='R'){
        if(k==1)    printf(" _______ ");
        if(k==2)    printf("||     ||");
        if(k==3)    printf("||     ||");
        if(k==4)    printf("||_____||");
        if(k==5)    printf("||   \\\\  ");
        if(k==6)    printf("||    \\\\ ");
        if(k==7)    printf("||     \\\\");
    }
    else if(a1=='s' || a1=='S'){
    if(k==1)    printf(" _______ ");
    if(k==2)    printf("|  _____|");
    if(k==3)    printf("| |      ");
    if(k==4)    printf("|_|_____ ");
    if(k==5)    printf("      | |");
    if(k==6)    printf(" _____| |");
    if(k==7)    printf("|_______|");
    }
    else if(a1=='t' || a1=='T'){
        if(k==1)    printf(" ___________ ");
        if(k==2)    printf("|_____ _____|");
        if(k==3)    printf("     | |     ");
        if(k==4)    printf("     | |     ");
        if(k==5)    printf("     | |     ");
        if(k==6)    printf("     | |     ");
        if(k==7)    printf("     |_|     ");
    }
    else if(a1=='u' || a1=='U'){
        if(k==1)    printf(" _       _ ");
        if(k==2)    printf("| |     | |");
        if(k==3)    printf("| |     | |");
        if(k==4)    printf("| |     | |");
        if(k==5)    printf("| |     | |");
        if(k==6)    printf("| |_____| |");
        if(k==7)    printf("|_________|");
    }
    else if(a1=='v' || a1=='V'){
        if(k==1)    printf(" _            _ ");
        if(k==2)    printf("\\  \\        /  /");
        if(k==3)    printf(" \\  \\      /  / ");
        if(k==4)    printf("  \\  \\    /  /  ");
        if(k==5)    printf("   \\  \\  /  /   ");
        if(k==6)    printf("    \\  \\/  /    ");
        if(k==7)    printf("     \\____/     ");
    }
    else if(a1=='w' || a1=='W'){
        if(k==1)    printf("__                  __");
        if(k==2)    printf("\\ \\                / /");
        if(k==3)    printf(" \\ \\      __      / / ");
        if(k==4)    printf("  \\ \\    /  \\    / /  ");
        if(k==5)    printf("   \\ \\  / /\\ \\  / /   ");
        if(k==6)    printf("    \\ \\/ /  \\ \\/ /    ");
        if(k==7)    printf("     \\__/    \\__/     ");
    }
    else if(a1=='x' || a1=='X'){
        if(k==1)    printf(" __     __ ");
        if(k==2)    printf(" \\  \\  /  /");
        if(k==3)    printf("  \\  \\/  / ");
        if(k==4)    printf("   \\  \\ /  ");
        if(k==5)    printf("   / \\  \\  ");
        if(k==6)    printf("  /  /\\  \\ ");
        if(k==7)    printf(" /__/  \\__\\");
    }
    else if(a1=='y' || a1=='Y'){
        if(k==1)    printf("___    ___ ");
        if(k==2)    printf("\\  \\  /  / ");
        if(k==3)    printf(" \\  \\/  /  ");
        if(k==4)    printf("  \\    /   ");
        if(k==5)    printf("   \\  /    ");
        if(k==6)    printf("   |  |    ");
        if(k==7)    printf("   |__|    ");
    }
    else if(a1=='z' || a1=='Z'){
        if(k==1)    printf(" ________  ");
        if(k==2)    printf("|_____   / ");
        if(k==3)    printf("     /  /  ");
        if(k==4)    printf("    /  /   ");
        if(k==5)    printf("   /  /    ");
        if(k==6)    printf("  /  /____ ");
        if(k==7)    printf(" /________|");
    }
}
