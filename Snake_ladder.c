#include<stdio.h>
#include<windows.h>
void loadingBar()
{

   // 0 - black background,
    // A - Green Foreground
    system("color 0A");

    // Initialize char for printing
    // loading bar
    char a = 177, b = 219;

    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t");
    printf("Loading...\n\n");
    printf("\t\t\t\t\t");

    // Print initial loading bar
    for (int i = 0; i < 26; i++)
        printf("%c", a);

    // Set the cursor again starting
    // point of loading bar
    printf("\r");
    printf("\t\t\t\t\t");

    // Print loading bar progress
    for (int i = 0; i < 26; i++) {
        printf("%c", b);

        // Sleep for 0.105 second
        Sleep(105);
    }
}
void Playgame()
{
    int n;
    printf("\n\n\n\nHow many player will be playing(max 4): ");
    scanf("%d",&n);
    if(n<1||n>4){
        printf("\n\n\nSorry it's unplayable!\n");
        main();
    }
    else{
        int px=0,py=0,p,c[n],a[10][10],i,j,t;
        //array initialisation
        for(i=0;i<10;i++){
            for(j=0;j<10;j++)
                a[i][j]=0;
        }
        for(i=0;i<n;i++)
            c[i]=0;
        while(a[9][9]==0){
        //no. of chances in each cycle is n
        for(p=1;p<=n;p++)
        {
            for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                if(p==a[i][j]){
                    px=i;
                    py=j;
                    break;
                }
                else{
                    px=0;
                    py=0;
                }}
                if(px==i&&py==j)break;
            }
            printf("px and py: %d and %d\n\n",px,py);
            printf("It's player %d turn \n",p);
            getch();
            t=rand()%6+1;
            printf("\nYou've got: %d\n",t);
            if(t==6&&c[p-1]==0) {
                c[p-1]=c[p-1]+1;
                printf("\nPlayer %d pawn is ready to move\n",p);
                printf("\n\nIt's player %d turn \n",p);
                t=rand()%6+1;
                while(t%6==0){
                        printf("\nPress any key to play again: ");
                        getch();
                        t=t+rand()%6+1;
                }
                printf("\nYou've got (in total): %d\n",t);
                a[px][py]=0;
                py=py+(px+t)/10;
                px=px+t%10-1;
                if(px>9&&py>9){
                    px=i;
                    py=j;
                }
                else if(px>9)px=px%10;
                a[px][py]=p;
            }
            else if(t==6&&c[p-1]!=0){
                printf("Press any key to play again: ");
                getch();
                t=t+rand()%6+1;
                while(t%6==0){
                     printf("Press any key to play again: ");
                    getch();
                    t=t+rand()%6+1;
                }
                a[px][py]=0;
                py=py+(px+t)/10;
                px=px+t%10;
                if(px>9&&py>9){
                    px=i;
                    py=j;
                }
                else if(px>9)px=px%10;
                a[px][py]=p;
            }
            else if(t!=6&&c[p-1]!=0){
                a[px][py]=0;
                py=py+(px+t)/10;
                px=px+t%10;
                if(px>9&&py>9){
                    px=i;
                    py=j;
                }
                else if(px>9)px=px%10;
                a[px][py]=p;
            }
            //snake and ladder conditions are added
            //three stairs: 6 to 45; 30 to 86; 57 to 96
            //three snakes: 43 to 4;98 to 40; 87 to 49
            if((px==5&&py==0)||(px==9&&py==2)||(px==6&&py==5)){
                if(px==5){printf("Here's the LADDER to 45\n");a[5][0]=0;px=4;py=4;a[px][py]=p;}
                if(px==9){printf("Here's the LADDER to 86\n");a[9][2]=0;px=5;py=8;a[px][py]=p;}
                if(px==6){printf("Here's the LADDER to 96\n");a[6][5]=0;px=5;py=9;a[px][py]=p;}
            }
            else if((px==2&&py==4)||(px==7&&py==9)||(px==6&&py==8)){
                if(px==2){printf("OOps! SNAKE to 4\n");a[2][4]=0;px=3;py=0;a[px][py]=p;}
               if(px==8){printf("OOps! SNAKE to 40\n");a[8][9]=0;px=9;py=3;a[px][py]=p;}
            	 if(px==6){printf("OOps! SNAKE to 49\n");a[6][8]=0;px=8;py=4;a[px][py]=p;}
            }
            //finishing code
            if(px==9&&py==9){
                printf("\n\n\t\t\t\t\t\tplayer %d won the game\n\n",p);
                getch();
                return;
            }
            printf("\nBoard Position is now:\n\n");
            for(i=0;i<10;i++){
            for(j=0;j<10;j++)
                printf("%d ",a[i][j]);
            printf("\n");
            }
        }
        printf("\n\n");


        }
    }
}
int main()
{
    loadingBar();
    printf("\n\n\nPress any key to continue: ");
    getch();
    int choice;
    printf("\n\n\n\t\t\t\t Main Menu\n\n\n\n");
    printf("\n\n\n\n1)Play Game\n\n2)Game Tutorial\n\n\n");
    printf("Please select between choice 1 and 2: ");
    scanf("%d",&choice);
    if(choice==1) Playgame();
    else{
        printf("\n\n\n\nThere will be a dice with six outcomes 1,2,3,4,5 and 6\nIt will give you one random output among those outcomes for each turn\nThe pieces will not start to move untill you'll get 6 as you outcome\nThe player has to move his piece accordingly in a constant direction\nThe Player who reaches to the top of the places first, will win the game\n\n");
        getch();
        main();
    }
    return 0;
}
