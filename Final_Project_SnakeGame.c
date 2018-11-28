#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>


int width=25,height=25,gameOver;
int x,y,fruitX,fruitY,score,flag,ch;
int tailX[100],tailY[100];
int countTail=0,temp,temp1;
char s[10],ch1;

struct
{
    char name[20];
    int score;
}snake;

void delay(int milli_seconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

void setup()
{
    gameOver=0;
    x=width/2;
    y=height/2;

    label1:
        fruitX=rand()%(width-1);
        if(fruitX==0)
            goto label1;

    label2:
        fruitY=rand()%(height-1);
        if(fruitY==0)
            goto label2;
    score=0;
}

void draw()
{
    int i,j,k;
    system("cls");
    for(i=0;i<width;i++)
    {
        printf("\t\t\t");
        for(j=0;j<height;j++)
        {
            if(i==0 || i==height-1 || j==0 || j==width-1)
            {
                printf("*");
            }
            else
            {
                if(i==x && j==y)
                    printf("@");
                else if(i==fruitX && j==fruitY)
                    printf("F");
                else
                {
                    int ch=0;
                    for(k=0;k<countTail;k++)
                    {
                        if(i==tailX[k] && j==tailY[k])
                        {
                            printf("o");
                            ch=1;
                        }
                    }
                    if(ch==0)
                    printf(" ");
                }

            }

        }
        printf("\n");
    }
    printf("SCORE = %d",score);
    printf("                                               BEST SCORE = %d\n",temp);
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\tSNAKE GAME powered by 2018PGCACA37\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");


}

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':
                flag=1;
                break;
            case 'd':
                flag=2;
                break;
            case 'w':
                flag=3;
                break;
            case 's':
                flag=4;
                break;
            case 'x':
                gameOver=1;
                break;
        }
    }
}

void logic()
{
    int i;
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(i=1;i<countTail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }

    switch(flag)
    {
        case 1:
            y--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x--;
            break;
        case 4:
            x++;
            break;
        default:
            break;
    }
    if(x==0 || x==width-1|| y==0 || y==height-1)
        gameOver=1;
    for(i=0;i<countTail;i++)
    {
        if(x==tailX[i] && y==tailY[i])
            gameOver=1;
    }
    if(x==fruitX && y==fruitY)
    {
        label3:
            fruitX=rand()%(width-1);
            if(fruitX==0)
                goto label3;

        label4:
            fruitY=rand()%(height-1);
            if(fruitY==0)
                goto label4;
        score+=1;
        countTail++;
    }
}
void snakeSpeed()
{
    if(countTail<3)
        {
            printf("LEVEL : BEGINNERS\n");
            delay(400);
        }

        else if(countTail<10)
        {
            printf("LEVEL : CONQUEROR\n");
            delay(150);
        }

        else if(countTail<20)
        {
            printf("LEVEL : PRO\n");
            delay(100);
        }

        else
        {
            printf("LEVEL : SUPER PRO\n");
            delay(50);
        }
}
void startScreen()
{
    printf("\n\n\t\tGAME RULES : ");
    printf("\n\n\t\t\tA --> LEFT MOVEMENT\n\t\t\tD --> RIGHT MOVEMENT\n\t\t\tW --> TOP MOVEMENT\n\t\t\tS --> DOWN MOVEMENT");
    printf("\n\n\t\tHey %s , Get ready to rock and roll :)",snake.name);
    printf("\n\n\n\t\tHIT any key to continue...");
    while(!kbhit())
    {

    }
    printf("\n\nGame starts in ...\n");
    printf("\n\n");
    delay(1000);
    printf("1\t");
    delay(1000);
    printf("2\t");
    delay(1000);
    printf("3\t");
    delay(1000);
    printf("4\t");
}


int main()
{
    int m,n;
    FILE *pr,*fp1;
    pr=fopen("bestscore","r+");
    fscanf(pr,"%d",&temp);
    fclose(pr);
    fp1=fopen("database","rb+");
    if(fp1==NULL)
    {
        fp1=fopen("database","wb+");
        if(fp1==NULL)
        {
            puts("Error in opening file\n");
        }
    }

    system("color 0a");
    label6:
        {
            printf("\n\t\t\t\t\t\tWELCOME TO THE SNAKE GAME...let's start CONQUERING\n\t@Bishop Corporation ltd\n\n\n");
    printf("\n\n\t\t\t1. -> Start Game\n\n\t\t\t2. -> View Best Scores\n\n\t\t\t3. -> About Game & Developers\n\n");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        goto label5;


    case 2:
        {
            system("cls");
            printf("\n\t\t\t\t\t\t\t\tBEST SCORES OF ALL TIMES");
            printf("\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            rewind(fp1);
            printf("\n\t\t\t\t\t\t\t\tNAME\t\tSCORE\n\n");
            while(fread(&snake,sizeof(snake),1,fp1)==1)
            {
                //printf("%s\t\t",snake.name);
                //printf("%d\n",snake.score);
                printf("\t\t\t\t\t\t\t     %s\t\t",snake.name);
                printf("%d\n",snake.score);
                printf("\n");
            }
            printf("\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            exit(1);
        }

    case 3:
        system("cls");
        printf("\n\t\t\t\t\t\t\t\tAbout Game & Developers");
        printf("\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
        printf("\n\n\t\t\t\t\tSnake is the common name for a video game concept where the player maneuvers a line\n\t\t\t\twhich grows in length, with the line itself being a primary obstacle.This Game is developed\n\t\t\t\t& powered by Bishop Corporation ltd & led by **DEEPANSHU GUPTA** & **RAJKUMAR VERMA** under the Guidance of Mr. C S Azad.\n\n\n\n\n\n\n\n");
        printf("\n\n\n\n\t1. --> Press 1 for MAIN MENU\n\n\t2. --> Press 2 to EXIT \n\n\t");
        label7:
        scanf("%d",&temp1);
        if(temp1==1)
        {
            system("cls");
            goto label6;
        }
        else if(temp1==2)
            exit(1);
        else
        {
            printf("Enter valid choice");
            goto label7;
        }



        return 0;
    }

    label5:
        {
            printf("\nEnter your name : ");
            scanf("%s",snake.name);
            startScreen();
            label8:
            setup();
            while(1)
            {
                if(gameOver==1)
                    {
                        if(score>temp)
                        {
                            printf("\n\n\t\tYou Scored : %d\n\n\tWell Done!! You Made it...You have become the SNAKE CONQUEROR & the best Scorer till now..CONGRATULATIONS!!!",score);
                            pr=fopen("bestscore","w");
                            fprintf(pr,"%d",score);
                            fclose(pr);
                            snake.score=score;
                            printf("%s\t%d",snake.name,snake.score);
                            fseek(fp1,0,2);
                            fwrite(&snake,sizeof(snake),1,fp1);
                            fclose(fp1);
                            printf("\n\n\tPLAY AGAIN (Y/N) : ");
                            fflush(stdin);
                            scanf("%c",&ch1);
                            if(ch1 == 'y'|| ch1 ==  'Y')
                            {
                                countTail=0;
                                goto label8;
                            }
                            else
                            {
                                system("cls");
                                goto label6;
                            }

                        }
                        else
                        {
                            printf("\n\n\t\tYou Scored : %d\n\n\tYou are still not the best...BETTER LUCK NEXT TIME",score);
                            printf("\n\n\tPLAY AGAIN (Y/N) : ");
                            fflush(stdin);
                            scanf("%c",&ch1);
                            if(ch1 == 'y'|| ch1 ==  'Y')
                            {
                                countTail=0;
                                goto label8;
                            }

                            else
                            {
                                system("cls");
                                goto label6;
                            }

                        }

                        break;
                    }
            draw();
            input();
            logic();
            snakeSpeed();
            }
        }
        }


    return 0;
}


