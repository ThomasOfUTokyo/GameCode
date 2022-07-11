//This is my code of snake game

#include <iostream>
#include <ncurses.h>

using namespace std;
bool gameOver;
const int width = 40;
const int height = 40;
int x,y,fruitx, fruity,score;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

int TailX[100],TailY[100];
int nTail = 0;

void Setup()
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);

    gameOver = false;
    dir = STOP;
    x=width/2;
    y=height/2;
    fruitx = rand()%width;
    fruity = rand()%height;
    score = 0;
}
void Draw()
{
    system("cls");//system("clear");
    for (int i=0; i <width+2; i++)
    cout<<"#";
    cout<< endl;

    for (int i =0; i<height;i++)
    {
        for (int j = 0; j<width; j++)
        {
            if (j ==0)
            cout<<"#";
            
            if(i==y && j==x)
            cout<<"O";
            else if (i == fruity && j == fruitx)
            cout<<"F";

            else
            cout<<" ";

            if (j==width-1)
            cout<<"#";

            else
            for (int k = 0; k<nTail; k++)
            {
                if (TailX[k]==j&& TailY[k]==i)
                mvprintw(i,j,"o");
            }
        }
        cout<<endl;
    }

    for (int i=0; i<width+2; i++)
    cout<<"#";
    cout<<endl;

}
void Input()
{
    keypad(stdscr,TRUE);
    halfdelay(1);
    int c =getch();
    switch(c)
    {
        case KEY_LEFT:
        dir = LEFT;
        break;
        case KEY_RIGHT:
        dir = RIGHT;
        break;
        case KEY_UP:
        dir = UP;
        break;
        case KEY_DOWN:
        dir = DOWN;
        break;
        case 113:
        gameOver = true;
        break;
    }
}
void Logic()
{
    int prevX = TailX[0];
    int prevY = TailY[0];
    int prev2X,prev2Y;
    TailX[0] = x;
    TailY[0] = y;
    
    for (int i = 1; i < nTail; i++)
    {
        prev2X = TailX[i];
        prev2Y = TailY[i];
        TailX[i] = prevX;
        TailY[i] = prevY;
    }
    

    switch(dir)
    {
        case LEFT:
        x--;
        break;
        case RIGHT:
        x++;
        break;
        case UP:
        y++;
        break;
        case DOWN:
        y--;
        break;
        default:
        break;
    }

    if(x > width || x<1||y<1||y>height)
    gameOver = true;

    if (x == fruitx && y== fruity)
    {
        score++;
        fruitx = (rand()%width)+1;
        fruity = (rand()%height)+1;
        nTail++; 
    }

    for (int i = 0; i<nTail; i++)
        if (TailX[i]== x && TailY[i] ==y)
        {
            gameOver = true;
        }

}
int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        //Sleep(10);
    }
    return 0;
}
