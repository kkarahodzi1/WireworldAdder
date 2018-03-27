#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define _WIN32_WINNT 0x0500
#include<windows.h>
//Dodati komentare
//provjeriti libove
// jos fixova? pa na github
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//Funkcija èekanja
void wait(int ms=1000)
{
    clock_t poc = clock();
    while(clock()-poc<ms);
}

//Funkcija za namjestanje velicine prozore(https://www.3dbuzz.com/forum/threads/102195-How-do-you-resize-a-console-window-in-C?p=835004#post835004)
void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}


//Funkcija za gašenje kursora(https://stackoverflow.com/questions/18028808/blinking-underscore-with-console)
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

//Ispis matrice
void ispisi(std::vector<std::vector<char>> &m)
{
    for(int i=0;i<m.size();i++)
    {
        ShowConsoleCursor(false);
        for(int j=0;j<m[i].size();j++)
            std::cout << m[i][j];
        std::cout << "\n";
    }

}

//Funkcija za provjeru da li provodnik treba postati glava elektrona
int susjedi(int i,int j,std::vector<std::vector<char>> &m,char glava)
{
    int br{};
    if(i>0)
    {
        if(j>0)
            if(m[i-1][j-1]==glava) br++;
        if(m[i-1][j]==glava) br++;
        if(j<m[0].size()-1)
            if(m[i-1][j+1]==glava) br++;
    }
    if(j>0)
        if(m[i][j-1]==glava) br++;
    if(j<m[0].size()-1)
        if(m[i][j+1]==glava) br++;
    if(i<m.size()-1)
    {
        if(j>0)
            if(m[i+1][j-1]==glava) br++;
        if(m[i+1][j]==glava) br++;
        if(j<m[0].size()-1)
            if(m[i+1][j+1]==glava) br++;
    }
    return br;
}

//Funkcija za pravljenje matrice znakova
std::vector<std::vector<char>> matBool(int vis,int sir)
{
    std::vector<std::vector<char>> m(vis);
    for(int i=0;i<vis;i++) m[i].resize(sir);
    return m;
}

int main()
{
    HWND hwnd = GetConsoleWindow();
    if( hwnd != NULL ){ SetWindowPos(hwnd ,0,0,0 ,1100,400 ,SWP_SHOWWINDOW|SWP_NOMOVE); }
    char provodnik=219,glava='H',rep='t';
    std::vector<std::vector<char>> m,n;
    m=matBool(16,127);
    m[1][1]=m[1][7]=m[1][13]=m[1][19]=m[1][25]=m[1][31]=m[1][37]=m[1][43]=m[1][64]=m[1][59]=m[1][60]=m[1][61]=m[1][62]=m[1][63]=
    m[2][58]=m[2][65]=m[2][78]=m[2][84]=m[2][90]=m[2][96]=m[2][102]=m[2][108]=m[2][114]=m[2][120]=m[2][126]=
    m[3][0]=m[3][1]=m[3][2]=m[3][3]=m[3][4]=m[3][5]=m[3][6]=m[3][7]=m[3][8]=m[3][9]=m[3][10]=m[3][11]=m[3][12]=m[3][13]=m[3][14]=m[3][15]=m[3][16]=m[3][17]=m[3][18]=m[3][19]=m[3][20]=m[3][21]=m[3][22]=m[3][23]=m[3][24]=m[3][25]=m[3][26]=m[3][27]=m[3][28]=m[3][29]=m[3][30]=m[3][31]=m[3][32]=m[3][33]=m[3][34]=m[3][35]=m[3][36]=m[3][37]=m[3][38]=m[3][39]=m[3][40]=m[3][41]=m[3][42]=m[3][43]=m[3][44]=m[3][45]=m[3][46]=m[3][47]=m[3][48]=m[3][54]=m[3][55]=m[3][56]=m[3][57]=m[3][61]=m[3][60]=m[3][67]=m[3][64]=m[3][65]=m[3][66]=
    m[4][49]=m[4][53]=m[4][59]=m[4][64]=m[4][96]=m[4][67]=m[4][68]=m[4][69]=m[4][70]=m[4][71]=m[4][72]=m[4][73]=m[4][74]=m[4][75]=m[4][76]=m[4][77]=m[4][78]=m[4][79]=m[4][80]=m[4][81]=m[4][82]=m[4][83]=m[4][84]=m[4][85]=m[4][86]=m[4][87]=m[4][88]=m[4][89]=m[4][90]=m[4][91]=m[4][92]=m[4][93]=m[4][94]=m[4][95]=m[4][96]=m[4][97]=m[4][98]=m[4][99]=m[4][100]=m[4][101]=m[4][102]=m[4][103]=m[4][104]=m[4][105]=m[4][106]=m[4][107]=m[4][108]=m[4][109]=m[4][110]=m[4][111]=m[4][112]=m[4][113]=m[4][114]=m[4][115]=m[4][116]=m[4][117]=m[4][118]=m[4][119]=m[4][120]=m[4][121]=m[4][122]=m[4][123]=m[4][124]=m[4][125]=m[4][126]=
    m[5][50]=m[5][51]=m[5][48]=m[5][49]=m[5][53]=m[5][57]=m[5][59]=m[5][60]=m[5][67]=m[5][64]=m[5][65]=m[5][66]=
    m[6][48]=m[6][52]=m[6][51]=m[6][58]=m[6][54]=m[6][55]=m[6][56]=m[6][57]=m[6][65]=
    m[7][50]=m[7][51]=m[7][48]=m[7][49]=m[7][53]=m[7][57]=m[7][59]=m[7][64]=
    m[8][49]=m[8][53]=m[8][59]=m[8][63]=
    m[9][0]=m[9][1]=m[9][2]=m[9][3]=m[9][4]=m[9][5]=m[9][6]=m[9][7]=m[9][8]=m[9][9]=m[9][10]=m[9][11]=m[9][12]=m[9][13]=m[9][14]=m[9][15]=m[9][16]=m[9][17]=m[9][18]=m[9][19]=m[9][20]=m[9][21]=m[9][22]=m[9][23]=m[9][24]=m[9][25]=m[9][26]=m[9][27]=m[9][28]=m[9][29]=m[9][30]=m[9][31]=m[9][32]=m[9][33]=m[9][34]=m[9][35]=m[9][36]=m[9][37]=m[9][38]=m[9][39]=m[9][40]=m[9][41]=m[9][42]=m[9][43]=m[9][44]=m[9][45]=m[9][46]=m[9][47]=m[9][48]=m[9][49]=m[9][52]=m[9][53]=m[9][54]=m[9][58]=m[9][59]=m[9][60]=m[9][62]=
    m[10][50]=m[10][53]=m[10][59]=m[10][62]=
    m[11][1]=m[11][7]=m[11][13]=m[11][19]=m[11][25]=m[11][31]=m[11][37]=m[11][43]=m[11][50]=m[11][52]=m[11][54]=m[11][58]=m[11][60]=m[11][61]=
    m[12][50]=m[12][52]=m[12][54]=m[12][58]=m[12][60]=
    m[13][51]=m[13][54]=m[13][57]=m[13][58]=m[13][59]=
    m[14][54]=m[14][58]=
    m[15][55]=m[15][56]=m[15][57]=provodnik;

    m[4][62]=rep;
    m[5][61]=glava;


    int prvi,drugi;
    unos:
    std::system("CLS");
    std::cout << "Unesite prvi sabirak (0-255)\n";
    std::cin >> prvi;
    std::cin.get();
    if(prvi>255 || prvi<0) goto unos;
    std::cout << "Unesite drugi sabirak (0-255)\n";
    std::cin >> drugi;
    std::cin.get();
    if(drugi>255 || drugi<0) goto unos;

    if(prvi&128)
    {
        m[3][0]=rep;
        m[3][1]=glava;
    }
    if(prvi&64)
    {
        m[3][6]=rep;
        m[3][7]=glava;
    }
    if(prvi&32)
    {
        m[3][12]=rep;
        m[3][13]=glava;
    }
    if(prvi&16)
    {
        m[3][18]=rep;
        m[3][19]=glava;
    }
    if(prvi&8)
    {
        m[3][24]=rep;
        m[3][25]=glava;
    }
    if(prvi&4)
    {
        m[3][30]=rep;
        m[3][31]=glava;
    }
    if(prvi&2)
    {
        m[3][36]=rep;
        m[3][37]=glava;
    }
    if(prvi&1)
    {
        m[3][42]=rep;
        m[3][43]=glava;
    }


    if(drugi&128)
    {
        m[9][0]=rep;
        m[9][1]=glava;
    }
    if(drugi&64)
    {
        m[9][6]=rep;
        m[9][7]=glava;
    }
    if(drugi&32)
    {
        m[9][12]=rep;
        m[9][13]=glava;
    }
    if(drugi&16)
    {
        m[9][18]=rep;
        m[9][19]=glava;
    }
    if(drugi&8)
    {
        m[9][24]=rep;
        m[9][25]=glava;
    }
    if(drugi&4)
    {
        m[9][30]=rep;
        m[9][31]=glava;
    }
    if(drugi&2)
    {
        m[9][36]=rep;
        m[9][37]=glava;
    }
    if(drugi&1)
    {
        m[9][42]=rep;
        m[9][43]=glava;
    }


    ispisi(m);
    std::cin.get();
    for(int i=0;i<84;i++)
    {
        n=m;
        wait(50);
        for(int i=0;i<m.size();i++)
            for(int j=0;j<m[i].size();j++)
            {
                if(m[i][j]==glava) n[i][j]=rep;
                else if(m[i][j]==rep) n[i][j]=provodnik;
                else if(m[i][j]==provodnik && (susjedi(i,j,m,glava)==2 || susjedi(i,j,m,glava)==1)) n[i][j]=glava;
            }
        m=n;
        std::system("CLS");
        ispisi(m);
    }
    std::cout << "Rjesenje je " << (m[4][78]==glava?'1' : '0')  << (m[4][84]==glava?'1' : '0')<< (m[4][90]==glava?'1' : '0') << (m[4][96]==glava?'1' : '0') << (m[4][102]==glava?'1' : '0') << (m[4][108]==glava?'1' : '0') << (m[4][114]==glava?'1' : '0') << (m[4][120]==glava?'1' : '0') << (m[4][126]==glava?'1' : '0') <<"(" << prvi + drugi <<")";
    return 0;
}
