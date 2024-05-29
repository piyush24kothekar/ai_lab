#include<iostream>
#include<limits.h>
char board[]={'1','2','3','4','5','6','7','8','9'};
char ai='X';
char human='O';
void displayboard()
{
    printf("\n%c|%c|%c",board[0],board[1],board[2]);
    printf("\n%c|%c|%c",board[3],board[4],board[5]);
    printf("\n%c|%c|%c",board[6],board[7],board[8]);
    printf("\n\n");
}

char checkwinner()
{
    for (int  i = 0; i < 9; i+=3)
    {
        if(board[i]==board[i+1] && board[i+1]==board[i+3])
        {
            return board[i];
        }
    }

    for(int i=0;i<3;i++)
    {
        if(board[i]==board[i+3] && board[i+3]==board[i+6])
        {
            return board[i];
        }
    }

    if(board[0]==board[4] && board[4]==board[8])
    {
        return board[0];
    }

    
    if(board[2]==board[4] && board[4]==board[6])
    {
        return board[2];
    }

    int draw=1;
    for(int i=0;i<9;i++)
    {
        if(board[i]!='X' && board[i]!='O')
        {
            draw=0;
            break;
        }
    }
    
    if(draw)
    {
        return 'D';
    }
    return 'Y';

}

int minmax(char player)
{
    char ch=checkwinner();
    if(checkwinner()==ai)
    {
        return 1;
    }
    else if(checkwinner()==human)
    {
        return 0;
    }
    else if(checkwinner()=='D')
    {
        return -1;
    }
    int bestscore;
    if(player==ai)
    {
        bestscore=INT_MIN;
        for(int i=0;i<9;i++)
        {
            if(board[i]!='X' && board[i]!='O')
            {
                char ch=board[i];
                board[i]=ai;
                int score=minmax(human);
                board[i]=ch;
                if(score>bestscore)
                {
                    bestscore=score;
                }
            }
        }
    }
    else
    {
        bestscore=INT_MAX;
        for(int i=0;i<9;i++)
        {
            if(board[i]!='X' && board[i]!='O')
            {
                char ch=board[i];
                board[i]=human;
                int score=minmax(ai);
                board[i]=ch;
                if(score<bestscore)
                {
                    bestscore=score;
                }
            }
        }
    }
    return bestscore;
}
void aimove()
{
    int bestscore=INT_MIN;
    int bestmove=-1;
    for(int i=0;i<9;i++)
    {
        if(board[i]!='X' && board[i]!='O')
        {
            char ch=board[i];
            board[i]=ai;
            int score=minmax(human);
            board[i]=ch;
            if(score>bestscore)
            {
                bestscore=score;
                bestmove=i;
            }
        }
    }
    board[bestmove]=ai;
}

void humanmove()
{
    int move;
    do
    {
        printf("Enter the valid number (1-9)\n");
        scanf("%d",&move);
        move--;
        if(board[move]=='X' || board[move]=='O')
        {
            printf("Enter a valid move");
        }
    } while (move<0 || move>9 || board[move]=='X' || board[move]=='O');
    board[move]=human;
}
int main()
{
    int turn=0;
    while(1){
        displayboard();
        if(checkwinner()!='Y')
        {   
            if(checkwinner()=='X')
            {
                printf("ai won\n");
            }
            else if(checkwinner()=='O')
            {
                printf("human won");
            }
            else if(checkwinner()=='D')
            {
                printf("match drawn");
            }
            break;
        }else
        {
            if(turn==0)
            {
                aimove();
                turn =1;
            }
            else
            {
                humanmove();
                turn=0;
            }
        }
    }
    return 0;
}