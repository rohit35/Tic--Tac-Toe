#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#define ON 1
#define OFF 0
void doCursor(int);
void newLine();
void board();
int checkwin();
void new_game();
int ply_1_score=0;
int ply_2_score=0;
void exit_sec();
void leader_board(char *ply_1,char *ply_2,int winning_player);
char *int_char(int src);
void playing_stage(char *ply_1,char*ply_2);
int square[9] = {1,2,3,4,5,6,7,8,9};
void newLine()
{
    moveto(0,gety()+textheight("A"));
}
void getGrString(char *inputString)
{
    int stringIndex=0;
    int xVal[255];
    char inputChar, outString[2];
    int oldColor;
    outString[1]=0;
    xVal[0]=getx();
    do
    {
        doCursor(ON);
        inputChar=getch();
        doCursor(OFF);
        if (inputChar==0) getch();
        else
        {
            if (inputChar==8)
            {
                oldColor=getcolor();
                --stringIndex;
                if (stringIndex<0) stringIndex=0;
                moveto(xVal[stringIndex],gety());
                setcolor(getbkcolor());
                outString[0]=inputString[stringIndex];
                outtext(outString);
                moveto(xVal[stringIndex],gety());
                setcolor(oldColor);
            }
            else
            {
                inputString[stringIndex]=inputChar;
                outString[0]=inputChar;
                outtext(outString);
                ++stringIndex;
                xVal[stringIndex]=getx();
            }
        }
    }
    while(inputChar!=13 && inputChar!=10);
    inputString[stringIndex]=0;
}
void doCursor(int on)
{
    int curX,oldColor;
    char uBarStr[2] = { '_',0 };
    if (!on)
    {
        oldColor=getcolor();
        setcolor(getbkcolor());
    }
    curX=getx();
    outtext(uBarStr);
    moveto(curX,gety());
    if (!on) setcolor(oldColor);
}
int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    errorcode = graphresult();
    if (errorcode != grOk)  /* an error occurred */
    {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        return(1);
    }
    setbkcolor(BLACK);
    setcolor(RED);
    settextstyle(6,0,6);
    outtextxy(140,75,"Tic -Tac -Toe");
    setcolor(BLUE);
    settextstyle(8,0,8);
    outtextxy(190,140,"GAME");
    settextstyle(4,0,4);
    setcolor(GREEN);
    outtextxy(180,250,"press any key");
    getch();
    new_game();
    closegraph();
}
void new_game()
{
    cleardevice();
    setcolor(GREEN);
    outtext("     ***Players Details***");
    newLine();
    newLine();
    setcolor(RED);
    char player_1[100],player_2[100];
    outtext("Player 1 Name:");
    setcolor(YELLOW);
    getGrString(player_1);
    newLine();
    newLine();
    setcolor(RED);
    outtext("Player 2 Name:");
    setcolor(YELLOW);
    getGrString(player_2);
    newLine();
    newLine();
    outtext("Get Ready to face each other");
    newLine();
    newLine();
    setcolor(GREEN);
    outtext("Press any Key");
    getch();
    playing_stage(player_1,player_2);
}
int char_to_int(char*num)
{
    int length=strlen(num);
    int var=1;
    int i,c=0,temp;
    for(i=0; i<length; i++)
    {
        if(i==0 && num[i]==45 )
        {
            var=-1;
        }
        else
        {
            temp=(num[i]-48);
            c=c*10+temp;
        }
    }
    c=c*var;
    return c;
}
void playing_stage(char *ply_1,char *ply_2)
{
    cleardevice();
    int mark,player = 1, i, choice;
    char data[10];
    do
    {
        board();
        for(choice=0; choice<12; choice++)
        {
            newLine();
        }
        outtext("                              ");
        player = (player % 2) ? 1 : 2;
        setcolor(BLUE);
        outtextxy(10,320,"Player");
        if(player==1)
        {
            outtextxy(10,370,ply_1);
        }
        else
        {
            outtextxy(10,370,ply_2);
        }
        setcolor(GREEN);
        outtextxy(10,420,"Enter A Number: ");
        getGrString(data);
        choice = data[0]-48;
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && square[0] == 1)
            square[0] = mark;

        else if (choice == 2 && square[1] == 2)
            square[1] = mark;

        else if (choice == 3 && square[2] == 3)
            square[2] = mark;

        else if (choice == 4 && square[3] == 4)
            square[3] = mark;

        else if (choice == 5 && square[4] == 5)
            square[4] = mark;

        else if (choice == 6 && square[5] == 6)
            square[5] = mark;

        else if (choice == 7 && square[6] == 7)
            square[6] = mark;

        else if (choice == 8 && square[7] == 8)
            square[7] = mark;

        else if (choice == 9 && square[8] == 9)
            square[8] = mark;

        else
        {
            board();
            outtextxy(10,420,"Invalid Move..! Press Any Key");

            player--;
            getch();
        }
        i = checkwin();
        player++;
    }
    while (i ==  - 1);

    board();

    if (i == 1)
        if(player==1)
        {
            outtextxy(10,420,ply_2);
        }
        else
        {
            outtextxy(10,420,ply_2);
        }
    outtextxy(220,420,"Win's");
    leader_board(ply_1,ply_2,player);
}
void leader_board(char *ply_1,char *ply_2,int winning_player)
{
    int arrow=0,total=3,loop=1;
    char x;
    if(winning_player-1==1)
    {
        ply_1_score++;
    }
    else
    {
        ply_2_score++;
    }
    while(loop)
    {
        cleardevice();
        outtext("           LEADER_BOARD");
        rectangle(40,100,590,280);
        line(270,100,270,280);
        line(380,100,380,280);
        line(40,200,590,200);
        setcolor(BLUE);
        outtextxy(60,150,ply_1);
        outtextxy(400,150,ply_2);
        outtextxy(80,230,int_char(ply_1_score));
        outtextxy(420,230,int_char(ply_2_score));
        setcolor(RED);
        outtextxy(290,150,"VS");
        if(arrow==0)
            outtextxy(200,300,"->Play_Again");
        else
            outtextxy(200,300,"    Play_Again");
        if(arrow==1)
            outtextxy(200,340,"->New_Game");
        else
            outtextxy(200,340,"    New_Game");
        if(arrow==2)
            outtextxy(200,380,"->Quit");
        else
            outtextxy(200,380,"    Quit");
        setcolor(GREEN);
        outtextxy(120,410,"Use the Arrow Keys..");
        outtextxy(50,440,"Press Enter For Selecting..");
        x=getch();
        switch(x)
        {
        case 'H':
            arrow--;
            break;
        case 'P':
            arrow++;
            break;
        case 13:
            if(arrow==0)
            {
                int i;
                for(i=0; i<9; i++)
                {
                    square[i]=i+1;
                }
                playing_stage(ply_1,ply_2);
                loop=0;
            }
            else if(arrow==1)
            {
                int i;
                for(i=0; i<9; i++)
                {
                    square[i]=i+1;
                }
                ply_1_score=ply_2_score =0;
                new_game();
                loop=0;
            }
            else if(arrow==2)
            {
                loop=0;

            }
            break;
        default:
            outtextxy(170,430,"Enter Valid choice");
        }
        if(arrow<0 || arrow>=3)
            arrow=0;
        setcolor(GREEN);
    }
    exit_sec();
}
void exit_sec()
{

    cleardevice();
    setcolor(YELLOW);
    settextstyle(BOLD_FONT,HORIZ_DIR,0);
    outtextxy(100,200," Thank you for playing...!");
    delay(1500);
}
int checkwin()
{
    if (square[0] == square[1] && square[1] == square[2])
        return 1;

    else if (square[3] == square[4] && square[4] == square[5])
        return 1;

    else if (square[6] == square[7] && square[7] == square[8])
        return 1;

    else if (square[0] == square[3] && square[3] == square[6])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[0] == square[4] && square[4] == square[8])
        return 1;

    else if (square[2] == square[4] && square[4] == square[6])
        return 1;

    else if (square[0] != 1 && square[1] != 2 && square[2] != 3 &&
             square[3] != 4 && square[4] != 5 && square[5] != 6 && square[6]
             != 7 && square[7] != 8 && square[8] != 9)

        return 0;
    else
        return  - 1;
}
char *int_char(int src)
{
    char r,*string=(char*)malloc(100*sizeof(char));
    int n=src,j=0,temp=0;
    if(src<0)
    {
        n=n*-1;
        temp=1;
    }
    if(n==0)
    {
        string[j++]='0';
    }
    while(n!=0)
    {
        r=n%10;
        string[j++]=(r+48);
        n/=10;
    }
    if(temp==1)
    {
        string[j++]=45;
    }
    string[j]='\0';
    strrev(string);
    return string;
}
void board()
{
    cleardevice();
    setcolor(RED);
    settextstyle(4,0,4);
    outtextxy(200,0,"Tic - Tac - Toe");
    setcolor(GREEN);
    newLine();
    rectangle(180,40,540,380);
    line(300,40,300,380);
    line(420,40,420,380);
    line(180,150,540,150);
    line(180,280,540,280);
    if(square[0]==1)
        outtextxy(220,75,int_char(square[0]));
    else if (square[0]==88)
        outtextxy(220,75,"X");
    else
        outtextxy(220,75,"O");
    if(square[1]==2)
        outtextxy(340,75,int_char(square[1]));
    else if (square[1]==88)
        outtextxy(340,75,"X");
    else
        outtextxy(340,75,"O");
    if(square[2]==3)
        outtextxy(460,75,int_char(square[2]));
    else if(square[2]==88)
        outtextxy(460,75,"X");
    else
        outtextxy(460,75,"O");
    if(square[3]==4)
        outtextxy(220,200,int_char(square[3]));
    else if(square[3]==88)
        outtextxy(220,200,"X");
    else
        outtextxy(220,200,"O");

    if(square[4]==5)
        outtextxy(340,200,int_char(square[4]));
    else if(square[4]==88)
        outtextxy(340,200,"X");
    else
        outtextxy(340,200,"O");


    if(square[5]==6)
        outtextxy(460,200,int_char(square[5]));
    else if(square[5]==88)
        outtextxy(460,200,"X");
    else
        outtextxy(460,200,"O");

    if(square[6]==7)
        outtextxy(220,320,int_char(square[6]));
    else if(square[6]==88)
        outtextxy(220,320,"X");
    else
        outtextxy(220,320,"O");

    if(square[7]==8)
        outtextxy(340,320,int_char(square[7]));
    else if(square[7]==88)
        outtextxy(340,320,"X");
    else
        outtextxy(340,320,"O");

    if(square[8]==9)
        outtextxy(460,320,int_char(square[8]));
    else if(square[8]==88)
        outtextxy(460,320,"X");
    else
        outtextxy(460,320,"O");

}
