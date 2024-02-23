#include <iostream>
#include <string>
#include <vector>
#include <graphics.h>
#include <Windows.h>
using namespace std;


const int cellSize = 60;
const int maxrow=15;
const int maxcol=15;
int row;
int col;


void drawCell(int x, int y, vector<vector<int>>position) {
    int value=1;
    setcolor(LIGHTGRAY);
    rectangle(x, y, x + cellSize, y + cellSize);


for (int i=0;i<position.size();i++)
{
    int reqrow=200+position[i][1]*cellSize;
    int reqcol=100+position[i][0]*cellSize;

    if (x==reqrow && y==reqcol){
        value=0;
        break;
    }


}
    if (value == 1) {
        setfillstyle(HATCH_FILL,YELLOW);
        floodfill(x + cellSize / 2, y + cellSize / 2,LIGHTGRAY);

}



}

void animation(vector<vector<int>>position)
{
    for (int i=0;i<position.size();i++)
    {
        int reqrow=200+position[i][1]*cellSize;
        int reqcol=100+position[i][0]*cellSize;
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(reqrow + cellSize / 2, reqcol + cellSize / 2,LIGHTGRAY);

    delay(1000);
    }

}




//check if down is visited
bool down(int currrow,int currcol,int visited[][maxcol],int arr[][maxcol])
{
    if(currrow==row-1)
    {
        return false;
    }

    if(arr[currrow+1][currcol]!=0 && visited[currrow+1][currcol]==0)
    {
        return true;
    }
    return false;
}


//check if left is visited
bool left(int currrow,int currcol,int visited[][maxcol],int arr[][maxcol])
{
    if(currcol==0)
    {
        return false;
    }

    if(arr[currrow][currcol-1]!=0 && visited[currrow][currcol-1]==0)
    {
        return true;
    }
    return false;
}

//check if right is visited
bool right(int currrow,int currcol,int visited[][maxcol],int arr[][maxcol])
{
    if(currcol==col-1)
    {
        return false;
    }

    if(arr[currrow][currcol+1]!=0 &&visited[currrow][currcol+1]==0)
    {
        return true;
    }
    return false;
}

//check if up is visited
bool up(int currrow,int currcol,int visited[][maxcol],int arr[][maxcol])
{
    if(currrow==0)
    {
        return false;
    }

    if(arr[currrow-1][currcol]!=0 && visited[currrow-1][currcol]==0)
    {
        return true;
    }
    return false;
}


void ratinamaze(int currrow,int currcol,int visited[][maxcol],string& str,int arr[][maxcol],vector<string>&ans,vector<vector<vector<int>>>&position,vector<vector<int>>&interme)
{
    visited[currrow][currcol]=1;
    interme.push_back({currrow,currcol});

    if (currrow==row-1 && currcol==col-1)
    {

        visited[currrow][currcol]=0;
        position.push_back(interme);
        ans.push_back(str);
        str.pop_back();
        interme.pop_back();

        return;
    }

    if((down(currrow,currcol,visited,arr)))
    {
        str.push_back('d');

        ratinamaze(currrow+1,currcol,visited,str,arr,ans,position,interme);
    }
    if((left(currrow,currcol,visited,arr)))
    {
        str.push_back('l');

        ratinamaze(currrow,currcol-1,visited,str,arr,ans,position,interme);
    }

    if((right(currrow,currcol,visited,arr)))
    {

        str.push_back('r');

        ratinamaze(currrow,currcol+1,visited,str,arr,ans,position,interme);
    }

    if((up(currrow,currcol,visited,arr)))
    {

        str.push_back('u');

        ratinamaze(currrow-1,currcol,visited,str,arr,ans,position,interme);
    }
    visited[currrow][currcol]=0;
    str.pop_back();
    interme.pop_back();
    return;





}
int main()
{
    char ch;

//some mazes
//  row=6;
//  col=7;
//  int arr[maxrow][maxcol]={{1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1},{0,0,0,0,0,0,1}};



row=10;
col=15;
int arr[maxrow][maxcol] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};





//define maze by user itself
//cout<<"Enter the dimensions of maze"<<endl;
//cin>>row;
//cin>>col;

//cout<<"Now let's define maze:"<<endl;
//cout<<"Enter 1 for open path and 0 for block path:"<<endl;
//for (int i=0;i<row;i++)
//{
//
//    for (int j=0;j<col;j++)
//    {
//        int a;
//        cout<<"arr["<<i<<"]["<<j<<"]:";
//        cin>>arr[i][j];
//    }
//}



    int visited[maxrow][maxcol]={};
    string str;
    vector<string>ans;

    vector<vector<vector<int>>>position;
    vector<vector<int>>interme;



    ratinamaze(0,0,visited,str,arr,ans,position,interme);

    cout<<"Follow instructions to solve the maze:"<<endl;
    for (int i=0;i<ans.size();i++)
    {
        cout<<i+1<<" method:"<<endl<<endl;
        for (int j=0;j<ans[i].size();j++)
        {
             ch=ans[i][j];
        switch(ch)
        {
        case 'l':
            {
                cout<<"Go left."<<endl;
            break;
            }
        case 'r':
            {
                cout<<"Go right."<<endl;
            break;
            }
        case 'u':
            {
                cout<<"Go up."<<endl;
            break;
            }
        case 'd':
            {
                cout<<"Go down."<<endl;
            break;
            }
        }
        }
        cout<<endl;

    }


  int Width = GetSystemMetrics(SM_CXSCREEN);

    int Height = GetSystemMetrics(SM_CYSCREEN);

initwindow(Width,Height,"MAZE-VISUALIZER");

setbkcolor(3);
cleardevice();
int x=700;
int y=150;
outtextxy(x,y,"WELCOME TO MAZE-SOLVER");
y=600;
outtextxy(x,y,"ENTER ANY KEY TO CONTINUE");
getch();
cleardevice();







    for (int k=0;k<position.size();k++)
    {

        for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int x = 200+j * cellSize;
            int y = 100+i * cellSize;
            drawCell(x, y, position[k]);


            if (i==row-1 && j==col-1)
            {
                animation(position[k]);
            }
        }

    }
    int x=700;
    int y=750;
    outtextxy(x,y,"ENTER ANY KEY TO CONTINUE");
    getch();

    cleardevice();
    }
     x=700;
     y=250;
    outtextxy(x,y,"THANK-YOU");
    x=650;
    y=600;
    outtextxy(x,y,"ENTER ANY KEY TO EXIT");
    getch();
    closegraph();


}
