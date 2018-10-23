#include <iostream>
#include <string.h>
using namespace std;
char a[100][100],col[100][100],row[10];
int col1[10]={1,7,15,23,31,39,47,55,63,69},lin[10]={1,4,9,14,19,24,29,34,39,43},t[10][10],col2[10][10],coox,cooy,xra,yra,xrn,yrn;
//--------------------------------------------------------------------------------------------
void display2()
{
    int i,j;
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
            cout<<t[i][j]<<"  ";
        cout<<endl;
    }
}

void flipt()
{
    int i,j,x,y;
    x=8;
    y=8;
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            col2[i][j]=0;
        }
    }
    for(i=1;i<=8;i++)
    {
        y=8;
        for(j=1;j<=8;j++)
        {
            col2[i][j]=t[x][y];
            y--;
        }
        x--;
    }
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            t[i][j]=col2[i][j];
        }
    }
}

void select(int x,int y)
{
    char c;
    c=254;
    x--;
    y--;
    y--;
    y--;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y=y-6;
    x++;
    a[x][y]=c;
    y=y+6;
    a[x][y]=c;
    x++;
    y=y-6;
    a[x][y]=c;
    y=y+6;
    a[x][y]=c;
    y=y-6;
    x++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
}

void display()
{
    int i,j;
    for (i=0;i<=45;i++)
    {
        for (j=0;j<=71;j++)
            cout<<a[i][j];
        cout<<endl;
    }
}

void black(int x,int y)
{
    x++;
    y--;
    a[x][y]='B';
    y++;
    a[x][y]='L';
    y++;
    a[x][y]='A';
    y++;
    a[x][y]='C';
    y++;
    a[x][y]='K';
}

void white(int x,int y)
{
    x++;
    y--;
    a[x][y]='W';
    y++;
    a[x][y]='H';
    y++;
    a[x][y]='I';
    y++;
    a[x][y]='T';
    y++;
    a[x][y]='E';
}

void whitebox(int x,int y)
{
    char c;
    c=177;
    x--;y--;y--;y--;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y=y-6;x++;a[x][y]=c;y=y+6;a[x][y]=c;x++;y=y-6;a[x][y]=c;y=y+6;a[x][y]=c;y=y-6;x++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;
}

void whiteboxn(int xx,int yy)
{
    whitebox(xx,yy);
    yy=yy-2;
    char c;
    c=177;
    a[xx][yy]=c;yy++;a[xx][yy]=c;yy++;a[xx][yy]=c;yy++;a[xx][yy]=c;yy++;a[xx][yy]=c;xx++;yy=yy-4;a[xx][yy]=c;yy++;a[xx][yy]=c;yy++;a[xx][yy]=c;yy++;a[xx][yy]=c;yy++;a[xx][yy]=c;
}

void whiteboxoo(int x,int y)
{
    char c;
    c=177;
    x--;y--;y--;y--;col[x][y]=c;y++;col[x][y]=c;y++;col[x][y]=c;y++;col[x][y]=c;y++;col[x][y]=c;y++;col[x][y]=c;y++;col[x][y]=c;y=y-6;x++;col[x][y]=c;y=y+6;col[x][y]=c;x++;y=y-6;col[x][y]=c;y=y+6;col[x][y]=c;y=y-6;x++;col[x][y]=c;y++;col[x][y]=c;y++;col[x][y]=c;y++;col[x][y]=c;y++;col[x][y]=c;y++;col[x][y]=c;y++;col[x][y]=c;
}

void whiteboxnn(int xx,int yy)
{
    whiteboxoo(xx,yy);
    yy=yy-2;
    char c;
    c=177;
    col[xx][yy]=c;yy++;col[xx][yy]=c;yy++;col[xx][yy]=c;yy++;col[xx][yy]=c;yy++;col[xx][yy]=c;xx++;yy=yy-4;col[xx][yy]=c;yy++;col[xx][yy]=c;yy++;col[xx][yy]=c;yy++;col[xx][yy]=c;yy++;col[xx][yy]=c;
}

void resetcol()
{
    int ok,x1,i,j;
    char charm;
    for (i=2;i<=42;i++)
    {
        if(i==2 || i==42)
        {
            x1=i;
            strcpy(col[i],"    --------------------------------------------------------------- ");
        }
        else
        {
            if(i-5==x1)
            {
                strcpy(col[i],"   |-------|-------|-------|-------|-------|-------|-------|-------|");
                x1=i;
            }
            else
                strcpy(col[i],"   |       |       |       |       |       |       |       |       |");
        }
    }
    ok=1;
    for(i=1;i<=8;i++)
    {
        if (ok==1)
            ok=0;
        else
            ok=1;
        for(j=1;j<=8;j++)
        {
            if (ok==1)
                ok=0;
            else
                ok=1;
            if (ok==1)
            {
                if (t[i][j]==0)
                    whiteboxnn(lin[i],col1[j]);
                else
                    whiteboxoo(lin[i],col1[j]);
            }
        }
    }
    i=lin[0];
    charm='A';
    for (j=1;j<=8;j++)
    {
        col[i][col1[j]]=charm;
        charm++;
    }
    i=lin[9];
    charm='A';
    for (j=1;j<=8;j++)
    {
        col[i][col1[j]]=charm;
        charm++;
    }
    j=col1[0];
    charm='1';
    for (i=1;i<=8;i++)
    {
        col[lin[i]][j]=charm;
        charm++;
    }
    j=col1[9];
    charm='1';
    for (i=1;i<=8;i++)
    {
        col[lin[i]][j]=charm;
        charm++;
    }
}

void deselect(int x,int y)
{
    char c;
    resetcol();
    x--;
    y--;
    y--;
    if (col[x][y]==' ')
    {
        c=' ';
    }
    else
    {
        c=177;
    }
    y--;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y=y-6;
    x++;
    a[x][y]=c;
    y=y+6;
    a[x][y]=c;
    x++;
    y=y-6;
    a[x][y]=c;
    y=y+6;
    a[x][y]=c;
    y=y-6;
    x++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
}

void flip()
{
    flipt();
    int i,j,x,y;
    resetcol();
    //--------------------------------------------------------------------------------------------
    for (i=1;i<=45;i++)
    {
        for (j=1;j<=71;j++)
        {
            if ((a[i][j]=='N' && a[i][j+1]=='e') || a[i][j]=='A')
            {
                a[i][j]=' ';
                j++;
                a[i][j]=' ';
                j++;
                a[i][j]=' ';
            }
        }
    }
    //--------------------------------------------------------------------------------------------
    x=8;
    for(i=1;i<=8;i++)
    {
        y=8;
        for(j=1;j<=8;j++)
        {
            col[lin[i]][col1[j]]=a[lin[x]][col1[y]];
            y--;
        }
        x--;
    }
    for(i=1;i<=45;i++)
    {
        for(j=1;j<=71;j++)
        {
            a[i][j]=col[i][j];
        }
    }
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            if(t[i][j]>0)
            {
                white(lin[i],col1[j]);
            }
            if(t[i][j]<0)
            {
                black(lin[i],col1[j]);
            }
        }
    }
}

void conversion()
{
    coox=row[0]-48;
    if (row[1]=='A')
        cooy=1;
    if (row[1]=='B')
        cooy=2;
    if (row[1]=='C')
        cooy=3;
    if (row[1]=='D')
        cooy=4;
    if (row[1]=='E')
        cooy=5;
    if (row[1]=='F')
        cooy=6;
    if (row[1]=='G')
        cooy=7;
    if (row[1]=='H')
        cooy=8;
}

void arrange()
{
    char s2[3];
    s2[0]=0;
    s2[1]=0;
    if (row[0]>'0' && row[0]<'9')
    {
        if(row[1]>96 && row[1]<'i')
        {
            if (row[1]=='a')
                row[1]='A';
            if (row[1]=='b')
                row[1]='B';
            if (row[1]=='c')
                row[1]='C';
            if (row[1]=='d')
                row[1]='D';
            if (row[1]=='e')
                row[1]='E';
            if (row[1]=='f')
                row[1]='F';
            if (row[1]=='g')
                row[1]='G';
            if (row[1]=='h')
                row[1]='H';
        }
    }
    if(row[0]>96 && row[0]<'i')
    {
        if (row[0]=='a')
            row[0]='A';
        if (row[0]=='b')
            row[0]='B';
        if (row[0]=='c')
            row[0]='C';
        if (row[0]=='d')
            row[0]='D';
        if (row[0]=='e')
            row[0]='E';
        if (row[0]=='f')
            row[0]='F';
        if (row[0]=='g')
            row[0]='G';
        if (row[0]=='h')
            row[0]='H';
        s2[1]=row[0];
        s2[0]=row[1];
        row[0]=s2[0];
        row[1]=s2[1];
    }
    if (row[0]>=64 && row[0]<'I')
    {
        s2[1]=row[0];
        s2[0]=row[1];
        row[0]=s2[0];
        row[1]=s2[1];
    }
    conversion();
}

int verifycoo()
{
    cin >> row;
    if (strlen(row)==2)
    {
        if ((row[0]>'0' && row[0]<'9') || (row[0]>96 && row[0]<'i') || (row[0]>64 && row[0]<'I'))
        {
            if ((row[1]>'0' && row[1]<'9') || (row[1]>96 && row[1]<'i') || (row[1]>64 && row[1]<'I'))
            {
                if ((row[0]>'0' && row[0]<'9') && ((row[1]>96 && row[1]<'i') || (row[1]>=64 && row[1]<'I')))
                    return 1;
                if ((row[1]>'0' && row[1]<'9') && ((row[0]>96 && row[0]<'i') || (row[0]>=64 && row[0]<'I')))
                    return 1;
                return 0;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

void removal(int x,int y)
{
    int t=0,i,j;
    y=y-2;
    x--;
    resetcol();
    if (col[x][y]!=' ')
        t=1;
    y--;
    if (t==1)
    {
        for (i=x;i<=x+3;i++)
        {
            for (j=y;j<=y+6;j++)
            {
                a[i][j]=177;
            }
        }
    }
    else
    {
        for (i=x;i<=x+3;i++)
        {
            for (j=y;j<=y+6;j++)
            {
                a[i][j]=' ';
            }
        }
    }
}

void printpiece(int x,int y)
{
    int xx,yy;
    xx=lin[x];
    yy=col1[y];
    yy--;
    yy--;
    if (t[x][y]==1)
    {
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]='P';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy=yy-2;
        white(xx,yy);
        xx++;
        yy=yy-2;
        a[xx][yy]=' ';
        yy=yy+4;
        a[xx][yy]=' ';
    }
    if (t[x][y]==2)
    {
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]='R';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy=yy-2;
        white(xx,yy);
        xx++;
        yy=yy-2;
        a[xx][yy]=' ';
        yy=yy+4;
        a[xx][yy]=' ';
    }
    if (t[x][y]==3)
    {
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]='N';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy=yy-2;
        white(xx,yy);
        xx++;
        yy=yy-2;
        a[xx][yy]=' ';
        yy=yy+4;
        a[xx][yy]=' ';
    }
    if (t[x][y]==4)
    {
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]='B';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy=yy-2;
        white(xx,yy);
        xx++;
        yy=yy-2;
        a[xx][yy]=' ';
        yy=yy+4;
        a[xx][yy]=' ';
    }
    if (t[x][y]==5)
    {
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]='Q';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy=yy-2;
        white(xx,yy);
        xx++;
        yy=yy-2;
        a[xx][yy]=' ';
        yy=yy+4;
        a[xx][yy]=' ';
    }
    if (t[x][y]==6)
    {
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]='K';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy=yy-2;
        white(xx,yy);
        xx++;
        yy=yy-2;
        a[xx][yy]=' ';
        yy=yy+4;
        a[xx][yy]=' ';
    }
    if (t[x][y]==-1)
    {
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]='P';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy=yy-2;
        black(xx,yy);
        xx++;
        yy=yy-2;
        a[xx][yy]=' ';
        yy=yy+4;
        a[xx][yy]=' ';
    }
    if (t[x][y]==-2)
    {
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]='R';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy=yy-2;
        black(xx,yy);
        xx++;
        yy=yy-2;
        a[xx][yy]=' ';
        yy=yy+4;
        a[xx][yy]=' ';
    }
    if (t[x][y]==-3)
    {
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]='N';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy=yy-2;
        black(xx,yy);
        xx++;
        yy=yy-2;
        a[xx][yy]=' ';
        yy=yy+4;
        a[xx][yy]=' ';
    }
    if (t[x][y]==-4)
    {
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]='B';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy=yy-2;
        black(xx,yy);
        xx++;
        yy=yy-2;
        a[xx][yy]=' ';
        yy=yy+4;
        a[xx][yy]=' ';
    }
    if (t[x][y]==-5)
    {
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]='Q';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy=yy-2;
        black(xx,yy);
        xx++;
        yy=yy-2;
        a[xx][yy]=' ';
        yy=yy+4;
        a[xx][yy]=' ';
    }
    if (t[x][y]==-6)
    {
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]='K';
        yy++;
        a[xx][yy]=' ';
        yy++;
        a[xx][yy]=' ';
        yy=yy-2;
        black(xx,yy);
        xx++;
        yy=yy-2;
        a[xx][yy]=' ';
        yy=yy+4;
        a[xx][yy]=' ';
    }
}
//--------------------------------------------------------------------------------------------
int oppose(int xx1,int yy1,int xx2,int yy2)
{
    if (t[xx1][yy1]>0 && t[xx2][yy2]<0)
        return 1;
    if (t[xx1][yy1]<0 && t[xx2][yy2]>0)
        return 1;
    return 0;
}

int movepawninvers(int x1,int y1,int x2,int y2)
{
    int x;
    x=x1;
    if (t[x2][y2]==0 && y1==y2)
    {
        if (x1==7)
        {
            x1++;
            if (x1==x2)
                return 1;
            x1++;
            if (x1==x2)
                return 1;
        }
        x1=x;
        x1++;
        if(x1==x2)
            return 1;
    }
    if (t[x2][y2]!=0)
    {
        if (oppose(x1,y1,x2,y2)==1)
        {
            x1++;
            y1++;
            if (x1==x2 && y1==y2)
            {
                return 1;
            }
            y1--;
            y1--;
            if (x1==x2 && y1==y2)
            {
                return 1;
            }
        }
    }
    return 0;
}

int movepawn(int x1,int y1,int x2,int y2)
{
    int x;
    x=x1;
    if (t[x2][y2]==0 && y1==y2)
    {
        if (x1==7)
        {
            x1--;
            if (x1==x2)
                return 1;
            x1--;
            if (x1==x2)
                return 1;
        }
        x1=x;
        x1--;
        if(x1==x2)
            return 1;
    }
    if (t[x2][y2]!=0)
    {
        if (oppose(x1,y1,x2,y2)==1)
        {
            x1--;
            y1--;
            if (x1==x2 && y1==y2)
            {
                return 1;
            }
            y1++;
            y1++;
            if (x1==x2 && y1==y2)
            {
                return 1;
            }
        }
    }
    return 0;
}

int moverook(int x1,int y1,int x2,int y2)
{
    int i,ok=1;
    if (t[x2][y2]==0)
    {
        if (y1==y2)
        {
            if (x1<x2)
                for (i=x1+1;i<=x2;i++)
                {
                    if (t[i][y1]!=0)
                        ok=0;
                }
            else
                for (i=x1-1;i>=x2;i--)
                {
                    if (t[i][y1]!=0)
                        ok=0;
                }
            if (ok==1)
                return 1;
        }
        if (x1==x2)
        {
            if (y1<y2)
                for (i=y1+1;i<=y2;i++)
                {
                    if (t[x1][i]!=0)
                        ok=0;
                }
            else
                for (i=y1-1;i>=y2;i--)
                {
                    if (t[x1][i]!=0)
                        ok=0;
                }
            if (ok==1)
                return 1;
        }
    }
    else
    {
        if (oppose(x1,y1,x2,y2)==1)
        {
            if (y1==y2)
            {
                if (x1<x2)
                    for (i=x1+1;i<x2;i++)
                    {
                        if (t[i][y1]!=0)
                            ok=0;
                    }
                else
                    for (i=x1-1;i>x2;i--)
                    {
                        if (t[i][y1]!=0)
                            ok=0;
                    }
                if (ok==1)
                    return 1;
            }
            if (x1==x2)
            {
                if (y1<y2)
                    for (i=y1+1;i<y2;i++)
                    {
                        if (t[x1][i]!=0)
                            ok=0;
                    }
                else
                    for (i=y1-1;i>y2;i--)
                    {
                        if (t[x1][i]!=0)
                            ok=0;
                    }
                if (ok==1)
                    return 1;
            }
        }
    }
    return 0;
}

int moveknight(int x1,int y1,int x2,int y2)
{
    if (t[x2][y2]==0)
    {
        if (x1-2==x2 && y1+1==y2)
            return 1;
        if (x1-2==x2 && y1-1==y2)
            return 1;
        if (x1+1==x2 && y1-2==y2)
            return 1;
        if (x1-1==x2 && y1-2==y2)
            return 1;
        if (x1+2==x2 && y1+1==y2)
            return 1;
        if (x1+2==x2 && y1-1==y2)
            return 1;
        if (x1-1==x2 && y1+2==y2)
            return 1;
        if (x1+1==x2 && y1+2==y2)
            return 1;
    }
    else
    {
        if (oppose(x1,y1,x2,y2)==1)
        {
            if (x1-2==x2 && y1+1==y2)
                return 1;
            if (x1-2==x2 && y1-1==y2)
                return 1;
            if (x1+1==x2 && y1-2==y2)
                return 1;
            if (x1-1==x2 && y1-2==y2)
                return 1;
            if (x1+2==x2 && y1+1==y2)
                return 1;
            if (x1+2==x2 && y1-1==y2)
                return 1;
            if (x1-1==x2 && y1+2==y2)
                return 1;
            if (x1+1==x2 && y1+2==y2)
                return 1;
        }
    }
}

int movebishop(int x1,int y1,int x2,int y2)
{
    int i,j,ok;
    if (t[x2][y2]==0)
    {
        ok=1;
        i=x1;
        j=y1;
        if (x1>x2 && y1<y2)
        while (i>x2 && j<y2)
        {
            i--;
            j++;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
        i=x1;
        j=y1;
        if (x1<x2 && y1<y2)
        while (i<x2 && j<y2)
        {
            i++;
            j++;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
        i=x1;
        j=y1;
        if (x1<x2 && y1>y2)
        while (i<x2 && j>y2)
        {
            i++;
            j--;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
        i=x1;
        j=y1;
        if (x1>x2 && y1>y2)
        while (i>x2 && j>y2)
        {
            i--;
            j--;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
    }
    else
    {
        if (oppose(x1,y1,x2,y2)==1)
        {
            ok=1;
            i=x1;
            j=y1;
            if (x1>x2 && y1<y2)
            while (i>=x2 && j<=y2)
            {
                i--;
                j++;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
            i=x1;
            j=y1;
            if (x1<x2 && y1<y2)
            while (i<=x2 && j<=y2)
            {
                i++;
                j++;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
            i=x1;
            j=y1;
            if (x1<x2 && y1>y2)
            while (i<=x2 && j>=y2)
            {
                i++;
                j--;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
            i=x1;
            j=y1;
            if (x1>x2 && y1>y2)
            while (i>=x2 && j>=y2)
            {
                i--;
                j--;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int movequeen(int x1,int y1,int x2,int y2)
{
    int i,j,ok=1;
    if (t[x2][y2]==0)
    {
        if (y1==y2)
        {
            if (x1<x2)
                for (i=x1+1;i<=x2;i++)
                {
                    if (t[i][y1]!=0)
                        ok=0;
                }
            else
                for (i=x1-1;i>=x2;i--)
                {
                    if (t[i][y1]!=0)
                        ok=0;
                }
            if (ok==1)
                return 1;
        }
        if (x1==x2)
        {
            if (y1<y2)
                for (i=y1+1;i<=y2;i++)
                {
                    if (t[x1][i]!=0)
                        ok=0;
                }
            else
                for (i=y1-1;i>=y2;i--)
                {
                    if (t[x1][i]!=0)
                        ok=0;
                }
            if (ok==1)
                return 1;
        }
//--------------------------------------------------------------------------------------------
        ok=1;
        i=x1;
        j=y1;
        if (x1>x2 && y1<y2)
        while (i>x2 && j<y2)
        {
            i--;
            j++;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
        i=x1;
        j=y1;
        if (x1<x2 && y1<y2)
        while (i<x2 && j<y2)
        {
            i++;
            j++;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
        i=x1;
        j=y1;
        if (x1<x2 && y1>y2)
        while (i<x2 && j>y2)
        {
            i++;
            j--;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
        i=x1;
        j=y1;
        if (x1>x2 && y1>y2)
        while (i>x2 && j>y2)
        {
            i--;
            j--;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
    }
    else
    {
        if (oppose(x1,y1,x2,y2)==1)
        {
            if (y1==y2)
            {
                if (x1<x2)
                    for (i=x1+1;i<x2;i++)
                    {
                        if (t[i][y1]!=0)
                            ok=0;
                    }
                else
                    for (i=x1-1;i>x2;i--)
                    {
                        if (t[i][y1]!=0)
                            ok=0;
                    }
                if (ok==1)
                    return 1;
            }
            if (x1==x2)
            {
                if (y1<y2)
                    for (i=y1+1;i<y2;i++)
                    {
                        if (t[x1][i]!=0)
                            ok=0;
                    }
                else
                    for (i=y1-1;i>y2;i--)
                    {
                        if (t[x1][i]!=0)
                            ok=0;
                    }
                if (ok==1)
                    return 1;
            }
    //--------------------------------------------------------------------------------------------
            ok=1;
            i=x1;
            j=y1;
            if (x1>x2 && y1<y2)
            while (i>=x2 && j<=y2)
            {
                i--;
                j++;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
            i=x1;
            j=y1;
            if (x1<x2 && y1<y2)
            while (i<=x2 && j<=y2)
            {
                i++;
                j++;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
            i=x1;
            j=y1;
            if (x1<x2 && y1>y2)
            while (i<=x2 && j>=y2)
            {
                i++;
                j--;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
            i=x1;
            j=y1;
            if (x1>x2 && y1>y2)
            while (i>=x2 && j>=y2)
            {
                i--;
                j--;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int moveking(int x1,int y1,int x2,int y2)
{
    int i,j;
    if (t[x2][y2]==0)
    {
        i=x1;
        j=y1;
        i++;
        j++;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        i--;
        j++;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        i++;
        j--;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        i--;
        j--;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        i++;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        i--;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        j++;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        j--;
        if (i==x2 && j==y2)
            return 1;
    }
    else
    {
        if (oppose(x1,y1,x2,y2)==1)
        {
            i=x1;
            j=y1;
            i++;
            j++;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            i--;
            j++;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            i++;
            j--;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            i--;
            j--;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            i++;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            i--;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            j++;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            j--;
            if (i==x2 && j==y2)
                return 1;
        }
    }
    return 0;
}

void changepawn(int x1,int y1)
{
    int ok=0;
    char ch;
    while (ok==0)
    {
        cout<<"\ \ \ \ To which piece do you want to change?(R,B,N,Q):";
        cin>>ch;
        if (ch=='r')
            ch='R';
        if (ch=='b')
            ch='B';
        if (ch=='n')
            ch='N';
        if (ch=='q')
            ch='Q';
        if (ch=='R')
        {
            if (t[x1][y1]>0)
            {
                t[x1][y1]=2;
                printpiece(x1,y1);
                white(lin[x1],col1[y1]);
                ok=1;
            }
            if (t[x1][y1]<0)
            {
                t[x1][y1]=-2;
                printpiece(x1,y1);
                black(lin[x1],col1[y1]);
                ok=1;
            }
        }
        if (ch=='N')
        {
            if (t[x1][y1]>0)
            {
                t[x1][y1]=3;
                printpiece(x1,y1);
                white(lin[x1],col1[y1]);
                ok=1;
            }
            if (t[x1][y1]<0)
            {
                t[x1][y1]=-3;
                printpiece(x1,y1);
                black(lin[x1],col1[y1]);
                ok=1;
            }
        }
        if (ch=='B')
        {
            if (t[x1][y1]>0)
            {
                t[x1][y1]=4;
                printpiece(x1,y1);
                white(lin[x1],col1[y1]);
                ok=1;
            }
            if (t[x1][y1]<0)
            {
                t[x1][y1]=-4;
                printpiece(x1,y1);
                black(lin[x1],col1[y1]);
                ok=1;
            }
        }
        if (ch=='Q')
        {
            if (t[x1][y1]>0)
            {
                t[x1][y1]=5;
                printpiece(x1,y1);
                white(lin[x1],col1[y1]);
                ok=1;
            }
            if (t[x1][y1]<0)
            {
                t[x1][y1]=-5;
                printpiece(x1,y1);
                black(lin[x1],col1[y1]);
                ok=1;
            }
        }
    }
}

int chess(int xx1,int yy1)
{
    int i,j;
    if (t[xx1][yy1]>0)
    {
        for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                if (t[i][j]<0)
                {
                    if (t[i][j]==-1)
                    {
                        if (movepawninvers(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==-2)
                    {
                        if (moverook(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==-3)
                    {
                        if (moveknight(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==-4)
                    {
                        if (movebishop(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==-5)
                    {
                        if (movequeen(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==-6)
                    {
                        if (moveking(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    if (t[xx1][yy1]<0)
    {
         for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                if (t[i][j]>0)
                {
                    if (t[i][j]==1)
                    {
                        if (movepawninvers(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==2)
                    {
                        if (moverook(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==3)
                    {
                        if (moveknight(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==4)
                    {
                        if (movebishop(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==5)
                    {
                        if (movequeen(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==6)
                    {
                        if (moveking(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int verified(int x1,int y1,int x2,int y2)
{
    if (t[x1][y1]>0)
        if (x1==x2)
            if (t[x1][y1]==6)
            {
                if (t[x2][y2]==2)
                {
                    if (y2-y1==3)
                    {
                        if (t[x1][y1+1]==0 && t[x1][y1+2]==0)
                        {
                            return 1;
                        }
                    }
                    if (y1-y2==4)
                    {
                        if (t[x1][y1-1]==0 && t[x1][y1-2]==0 && t[x1][y1-3]==0)
                        {
                            return 1;
                        }
                    }
                }
            }
    if (t[x1][y1]<0)
    {
        if (x1==x2)
            if (t[x1][y1]==-6)
            {
                if (t[x2][y2]==-2)
                {
                    if (y1-y2==3)
                    {
                        if (t[x1][y1-1]==0 && t[x1][y1-2]==0)
                        {
                            return 1;
                        }
                    }
                    if (y2-y1==4)
                    {
                        if (t[x1][y1+1]==0 && t[x1][y1+2]==0 && t[x1][y1+3]==0)
                        {
                            return 1;
                        }
                    }
                }
            }
    }
    return 0;
}

void castling(int x1,int y1,int x2,int y2)
{
    if (t[x1][y1]>0)
        if (x1==x2)
            if (t[x1][y1]==6)
            {
                if (t[x2][y2]==2)
                {
                    if (y2-y1==3)
                    {
                        if (t[x1][y1+1]==0 && t[x1][y1+2]==0)
                        {
                            t[x1][y1+1]=2;
                            t[x1][y1+2]=6;
                            t[x1][y1]=0;
                            t[x2][y2]=0;
                            a[lin[x1]][col1[y1+1]]='T';
                            printpiece(x1,y1+1);
                            a[lin[x1]][col1[y1+2]]='R';
                            printpiece(x1,y1+2);
                            removal(lin[x1],col1[y1]);
                            removal(lin[x2],col1[y2]);
                        }
                    }
                    if (y1-y2==4)
                    {
                        if (t[x1][y1-1]==0 && t[x1][y1-2]==0 && t[x1][y1-3]==0)
                        {
                            t[x1][y1-1]=2;
                            t[x1][y1-2]=6;
                            t[x1][y1]=0;
                            t[x2][y2]=0;
                            a[lin[x1]][col1[y1-1]]='R';
                            printpiece(x1,y1-1);
                            a[lin[x1]][col1[y1-2]]='K';
                            printpiece(x1,y1-2);
                            removal(lin[x1],col1[y1]);
                            removal(lin[x2],col1[y2]);
                        }
                    }
                }
            }
    if (t[x1][y1]<0)
    {
        if (x1==x2)
            if (t[x1][y1]==-6)
            {
                if (t[x2][y2]==-2)
                {
                    if (y1-y2==3)
                    {
                        if (t[x1][y1-1]==0 && t[x1][y1-2]==0)
                        {
                            t[x1][y1-1]=-2;
                            t[x1][y1-2]=-6;
                            t[x1][y1]=0;
                            t[x2][y2]=0;
                            a[lin[x1]][col1[y1-1]]='R';
                            printpiece(x1,y1-1);
                            a[lin[x1]][col1[y1-2]]='K';
                            printpiece(x1,y1-2);
                            removal(lin[x1],col1[y1]);
                            removal(lin[x2],col1[y2]);
                        }
                    }
                    if (y2-y1==4)
                    {
                        if (t[x1][y1+1]==0 && t[x1][y1+2]==0 && t[x1][y1+3]==0)
                        {
                            t[x1][y1+1]=-2;
                            t[x1][y1+2]=-6;
                            t[x1][y1]=0;
                            t[x2][y2]=0;
                            a[lin[x1]][col1[y1+1]]='R';
                            printpiece(x1,y1+1);
                            a[lin[x1]][col1[y1+2]]='K';
                            printpiece(x1,y1+2);
                            removal(lin[x1],col1[y1]);
                            removal(lin[x2],col1[y2]);
                        }
                    }
                }
            }
    }
}

int move(int coox1,int cooy1,int coox2,int cooy2)
{
    if (t[coox1][cooy1]==1)
    {
        if (movepawn(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==2)
    {
        if (moverook(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==3)
    {
        if (moveknight(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==4)
    {
        if (movebishop(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==5)
    {
        if (movequeen(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==6)
    {
        if (moveking(coox1,cooy1,coox2,cooy2)==1)
        {
            t[coox2][cooy2]=6;
            if (chess(coox2,cooy2)==0)
                return 1;
            t[coox2][cooy2]=0;
        }
        return 0;
    }
    if (t[coox1][cooy1]==-1)
    {
        if (movepawn(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==-2)
    {
        if (moverook(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==-3)
    {
        if (moveknight(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==-4)
    {
        if (movebishop(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==-5)
    {
        if (movequeen(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==-6)
    {
        if (moveking(coox1,cooy1,coox2,cooy2)==1)
        {
            t[coox2][cooy2]=-6;
            if (chess(coox2,cooy2)==0)
                return 1;
            t[coox2][cooy2]=0;
        }
        return 0;
    }
}

int checkmate(int x,int y)
{
    int i,j,ok=1,i2,j2,xx,yy,var,var2;
    if (t[x][y]>0)
    {
        for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                for (i2=1;i2<=8;i2++)
                {
                    for (j2=1;j2<=8;j2++)
                    {
                        if (t[i2][j2]>0)
                        {
                            if (t[i2][j2]==1)
                            {
                                if (movepawn(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=1;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=1;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==2)
                            {
                                if (moverook(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=2;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=2;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==3)
                            {
                                if (moveknight(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=3;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=3;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==4)
                            {
                                if (movebishop(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=4;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=4;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==5)
                            {
                                if (movequeen(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=5;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=5;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==6)
                            {
                                if (moveking(i2,j2,i,j)==1)
                                {
                                    xx=i;
                                    yy=j;
                                    var=t[xx][yy];
                                    t[i2][j2]=0;
                                    t[xx][yy]=6;
                                    if (chess(xx,yy)==0)
                                    {
                                        ok=0;
                                    }
                                    t[xx][yy]=var;
                                    t[i2][j2]=6;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (t[x][y]<0)
    {
        for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                for (i2=1;i2<=8;i2++)
                {
                    for (j2=1;j2<=8;j2++)
                    {
                        if (t[i2][j2]<0)
                        {
                            if (t[i2][j2]==-1)
                            {
                                if (movepawn(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-1;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=-1;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-2)
                            {
                                if (moverook(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-2;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=-2;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-3)
                            {
                                if (moveknight(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-3;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=-3;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-4)
                            {
                                if (movebishop(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-4;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=-4;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-5)
                            {
                                if (movequeen(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-5;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=-5;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-6)
                            {
                                if (moveking(i2,j2,i,j)==1)
                                {
                                    xx=i;
                                    yy=j;
                                    var=t[xx][yy];
                                    t[i2][j2]=0;
                                    t[xx][yy]=-6;
                                    if (chess(xx,yy)==0)
                                    {
                                        ok=0;
                                    }
                                    t[xx][yy]=var;
                                    t[i2][j2]=-6;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (ok==1)
        return 1;
    else
        return 0;
}

int stalemate(int x,int y)
{
    int i,j,i2,j2,ok=0,xx,yy,var;
    if (t[x][y]>0)
    {
        for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                for (i2=1;i2<=8;i2++)
                {
                    for (j2=1;j2<=8;j2++)
                    {
                        if (t[i2][j2]>0)
                        {
                            if (t[i2][j2]==1)
                            {
                                if (movepawn(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=1;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=1;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==2)
                            {
                                if (moverook(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=2;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=2;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==3)
                            {
                                if (moveknight(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=3;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=3;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==4)
                            {
                                if (movebishop(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=4;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=4;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==5)
                            {
                                if (movequeen(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=5;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=5;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==6)
                            {
                                if (moveking(i2,j2,i,j)==1)
                                {
                                    xx=i;
                                    yy=j;
                                    var=t[xx][yy];
                                    t[i2][j2]=0;
                                    t[xx][yy]=6;
                                    if (chess(xx,yy)==0)
                                    {
                                        ok=1;
                                    }
                                    t[xx][yy]=var;
                                    t[i2][j2]=6;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (t[x][y]<0)
    {
        for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                for (i2=1;i2<=8;i2++)
                {
                    for (j2=1;j2<=8;j2++)
                    {
                        if (t[i2][j2]<0)
                        {
                            if (t[i2][j2]==-1)
                            {
                                if (movepawn(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-1;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=-1;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-2)
                            {
                                if (moverook(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-2;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=-2;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-3)
                            {
                                if (moveknight(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-3;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=-3;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-4)
                            {
                                if (movebishop(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-4;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=-4;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-5)
                            {
                                if (movequeen(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-5;
                                    t[i2][j2]=0;
                                    if (chess(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=-5;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-6)
                            {
                                if (moveking(i2,j2,i,j)==1)
                                {
                                    xx=i;
                                    yy=j;
                                    var=t[xx][yy];
                                    t[i2][j2]=0;
                                    t[xx][yy]=-6;
                                    if (chess(xx,yy)==0)
                                    {
                                        ok=1;
                                    }
                                    t[xx][yy]=var;
                                    t[i2][j2]=-6;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (ok==1)
        return 1;
    else
        return 0;
}

int main()
{
    int i,j,ok,x1,x2,y1,y2,whitee[4]={0,1,1,1},blackre[4]={0,1,1,1};
    char p1[256],p2[256],charm;
    xra=8;
    yra=5;
    xrn=8;
    yrn=4;
    cout<<"\ \ \ \ PLAYER NAME 1:";
    cin>>p1;
    cout<<"\ \ \ \ PLAYER NAME 2:";
    cin>>p2;
    cout<<endl;
    cout<<"\ \ \ \ Rules:";
    cout<<endl;
    cout<<endl;
    cout<<"\ \ \ \ This game does not accept this pass.";
    cout<<endl;
    cout<<"\ \ \ \ To select a track, enter the track coordinates again.";
    cout<<endl;
    cout<<"\ \ \ \ The order of coordinates is random.";
    cout<<endl;
    cout<<endl;
    cout<<"\ \ \ \ Pieces:";
    cout<<endl;
    cout<<endl;
    cout<<"\ \ \ \ R=Rook";
    cout<<endl;
    cout<<"\ \ \ \ P=Pawn";
    cout<<endl;
    cout<<"\ \ \ \ N=Knight";
    cout<<endl;
    cout<<"\ \ \ \ B=Bishop";
    cout<<endl;
    cout<<"\ \ \ \ Q=Queen";
    cout<<endl;
    cout<<"\ \ \ \ K=King";
    cout<<endl<<endl;
    cout<<"\ \ \ \ The game starts:";
    cout<<endl<<endl;

    i=2;
    for (j=1;j<=8;j++)
    {
        t[i][j]=-1;
    }
    i=7;
    for (j=1;j<=8;j++)
    {
        t[i][j]=1;
    }
    x1=1;
    x2=8;
    y1=1;
    y2=8;
    t[x1][y1]=-2;
    t[x1][y2]=-2;
    t[x2][y1]=2;
    t[x2][y2]=2;

    y1=2;
    y2=7;
    t[x1][y1]=-3;
    t[x1][y2]=-3;
    t[x2][y1]=3;
    t[x2][y2]=3;

    y1=3;
    y2=6;
    t[x1][y1]=-4;
    t[x1][y2]=-4;
    t[x2][y1]=4;
    t[x2][y2]=4;

    y1=4;
    y2=5;
    t[x1][y1]=-5;
    t[x1][y2]=-6;
    t[x2][y1]=5;
    t[x2][y2]=6;

    for (i=2;i<=42;i++)
    {
        if(i==2 || i==42)
        {
            x1=i;
            strcpy(a[i],"    --------------------------------------------------------------- ");
        }
        else
        {
            if(i-5==x1)
            {
                strcpy(a[i],"   |-------|-------|-------|-------|-------|-------|-------|-------|");
                x1=i;
            }
            else
                strcpy(a[i],"   |       |       |       |       |       |       |       |       |");
        }
    }

    ok=1;
    for(i=1;i<=8;i++)
    {
        if (ok==1)
            ok=0;
        else
            ok=1;
        for(j=1;j<=8;j++)
        {
            if (ok==1)
                ok=0;
            else
                ok=1;
            if (ok==1)
            {
                if (t[i][j]==0)
                    whiteboxn(lin[i],col1[j]);
                else
                    whiteboxoo(lin[i],col1[j]);
            }
        }
    }

    i=lin[0];
    charm='A';
    for (j=1;j<=8;j++)
    {
        a[i][col1[j]]=charm;
        charm++;
    }
    i=lin[9];
    charm='A';
    for (j=1;j<=8;j++)
    {
        a[i][col1[j]]=charm;
        charm++;
    }
    j=col1[0];
    charm='1';
    for (i=1;i<=8;i++)
    {
        a[lin[i]][j]=charm;
        charm++;
    }
    j=col1[9];
    charm='1';
    for (i=1;i<=8;i++)
    {
        a[lin[i]][j]=charm;
        charm++;
    }

    i=lin[2];
    for (j=1;j<=8;j++)
    {
       a[i][col1[j]]='P';
       black(i,col1[j]);
    }
    i=lin[7];
    for (j=1;j<=8;j++)
    {
       a[i][col1[j]]='P';
       white(i,col1[j]);
    }

    x1=lin[1];
    x2=lin[8];
    y1=col1[1];
    y2=col1[8];
    a[x1][y1]='R';
    a[x1][y2]='R';
    a[x2][y1]='R';
    a[x2][y2]='R';

    y1=col1[2];
    y2=col1[7];
    a[x1][y1]='N';
    a[x1][y2]='N';
    a[x2][y1]='N';
    a[x2][y2]='N';

    y1=col1[3];
    y2=col1[6];
    a[x1][y1]='B';
    a[x1][y2]='B';
    a[x2][y1]='B';
    a[x2][y2]='B';

    y1=col1[4];
    y2=col1[5];
    a[x1][y1]='Q';
    a[x1][y2]='K';
    a[x2][y1]='Q';
    a[x2][y2]='K';

    i=lin[1];
    for(j=1;j<=8;j++)
    {
        black(i,col1[j]);
    }
    i=lin[8];
    for(j=1;j<=8;j++)
    {
        white(i,col1[j]);
    }

    int sw=2,okk,xx,yy,okkk,dis,ok10,sahh=0,v,v2,sm=0;
    ok=1;
    while(ok==1)
    {
        display();
        if(sw==1)
            sw=2;
        else
            sw=1;
        if (sw==1)
            cout<<"\ \ \ \ "<<p1<<" ENTER YOUR MOVE:"<<endl;
        else
            cout<<"\ \ \ \ "<<p2<<" ENTER YOUR MOVE:"<<endl;
        okk=0;
        while(okk==0)
        {
            if (verifycoo()==1)
                if (sw==1)
                {
                    arrange();
                    if(t[coox][cooy]>0)
                        okk=1;
                    else
                        cout<<"\ \ \ \ Wrong Coordinates:";
                }
                else
                {
                    arrange();
                    if(t[coox][cooy]<0)
                        okk=1;
                    else
                        cout<<"\ \ \ \ Wrong Coordinates:";
                }
            else
                cout<<"\ \ \ \ Wrong Coordinates:";
        }
        okkk=0;
        select(lin[coox],col1[cooy]);
        xx=coox;
        yy=cooy;
        dis=1;
        ok10=0;
        while(okkk==0)
        {
            display();
            if (sahh==1)
                cout<<"\ \ \ \ You are in chess. retry:";
            sahh=0;
            if (dis==1)
            {
                xx=coox;
                yy=cooy;
                cout<<"\ \ \ \ Move to coordinates:";
            }
            if (ok10==1 && dis==0)
                cout<<"\ \ \ \ Move not allowed. retry:";
            dis=0;
            ok10=0;
            if (verifycoo()==1)
            {
                arrange();
                if (coox==xx && cooy==yy)
                {
                    dis=1;
                    deselect(lin[coox],col1[cooy]);
                    okk=0;
                    display();
                    cout<<"\ \ \ \ Enter new coordinates:";
                    while(okk==0)
                    {
                        if (verifycoo()==1)
                            if (sw==1)
                            {
                                arrange();
                                if(t[coox][cooy]>0)
                                    okk=1;
                                else
                                    cout<<"\ \ \ \ Wrong Coordinates:";
                            }
                            else
                            {
                                arrange();
                                if(t[coox][cooy]<0)
                                    okk=1;
                                else
                                    cout<<"\ \ \ \ Wrong Coordinates:";
                            }
                        else
                            cout<<"\ \ \ \Wrong Coordinates:";
                    }
                    select(lin[coox],col1[cooy]);
                }
            }
            if(move(xx,yy,coox,cooy)==1)
            {
                if (sw==1)
                {
                    if (xx==8 && yy==1)
                        whitee[1]=0;
                    if (xx==8 && yy==5)
                    {
                        whitee[2]=0;
                    }
                    if (xx==8 && yy==8)
                        whitee[3]=0;
                }
                else
                {
                    if (xx==8 && yy==1)
                        blackre[1]=0;
                    if (xx==8 && yy==4)
                        blackre[2]=0;
                    if (xx==8 && yy==8)
                        blackre[3]=0;
                }
                if (t[xx][yy]==6)
                {
                    xra=coox;
                    yra=cooy;
                }
                if (t[xx][yy]==-6)
                {
                    xrn=coox;
                    yrn=cooy;
                }
                if (sw==1)
                {
                    if (chess(xra,yra)==0)
                    {
                        v2=t[coox][cooy];
                        t[coox][cooy]=t[xx][yy];
                        t[xx][yy]=0;
                        if (chess(xra,yra)==0)
                        {
                            okkk=1;
                            deselect(lin[xx],col1[yy]);
                            removal(lin[xx],col1[yy]);
                            printpiece(coox,cooy);
                        }
                        else
                        {
                            t[xx][yy]=t[coox][cooy];
                            t[coox][cooy]=v2;
                        }
                    }
                    else
                    {
                        sahh=1;
                        v=t[coox][cooy];
                        t[coox][cooy]=9;
                        if (chess(xra,yra)==0)
                        {
                            sahh=0;
                            okkk=1;
                            t[coox][cooy]=t[xx][yy];
                            t[xx][yy]=0;
                            deselect(lin[xx],col1[yy]);
                            removal(lin[xx],col1[yy]);
                            printpiece(coox,cooy);
                        }
                        else
                        {
                            t[coox][cooy]=v;
                        }
                    }
                }
                else
                {
                    if (chess(xrn,yrn)==0)
                    {
                        v2=t[coox][cooy];
                        t[coox][cooy]=t[xx][yy];
                        t[xx][yy]=0;
                        if (chess(xrn,yrn)==0)
                        {
                            okkk=1;
                            deselect(lin[xx],col1[yy]);
                            removal(lin[xx],col1[yy]);
                            printpiece(coox,cooy);
                        }
                        else
                        {
                            t[xx][yy]=t[coox][cooy];
                            t[coox][cooy]=v2;
                        }
                    }
                    else
                    {
                        sahh=1;
                        v=t[coox][cooy];
                        t[coox][cooy]=9;
                        if (chess(xrn,yrn)==0)
                        {
                            sahh=0;
                            okkk=1;
                            t[coox][cooy]=t[xx][yy];
                            t[xx][yy]=0;
                            deselect(lin[xx],col1[yy]);
                            removal(lin[xx],col1[yy]);
                            printpiece(coox,cooy);
                        }
                        else
                        {
                            t[coox][cooy]=v;
                        }
                    }
                }

            }
            else
            {
                ok10=1;
                if (sw==1)
                {
                    if (xx==8 && yy==5)
                    {
                        if (whitee[1]==1 && whitee[2]==1 && coox==8 && cooy==1)
                        {
                            if (verified(xx,yy,coox,cooy)==1)
                            {
                                whitee[1]=0;
                                whitee[2]=0;
                                deselect(lin[xx],col1[yy]);
                                castling(xx,yy,coox,cooy);
                                okkk=1;
                            }
                        }
                        else
                        {
                            if (whitee[2]==1 && whitee[3]==1 && coox==8 && cooy==8)
                            {
                                if (verified(xx,yy,coox,cooy)==1)
                                {
                                    whitee[2]=0;
                                    whitee[3]=0;
                                    deselect(lin[xx],col1[yy]);
                                    castling(xx,yy,coox,cooy);
                                    okkk=1;
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (xx==8 && yy==4)
                    {
                        if (blackre[1]==1 && blackre[2]==1 && coox==8 && cooy==1)
                        {
                            if (verified(xx,yy,coox,cooy)==1)
                            {
                                blackre[1]=0;
                                blackre[2]=0;
                                deselect(lin[xx],col1[yy]);
                                castling(xx,yy,coox,cooy);
                                okkk=1;
                            }
                        }
                        else
                        {
                            if (blackre[2]==1 && blackre[3]==1 && coox==8 && cooy==8)
                            {
                                if (verified(xx,yy,coox,cooy)==1)
                                {
                                    blackre[2]=0;
                                    blackre[3]=0;
                                    deselect(lin[xx],col1[yy]);
                                    castling(xx,yy,coox,cooy);
                                    okkk=1;

                                }
                            }
                        }
                    }
                }
            }
        }
        i=1;
        for (j=1;j<=8;j++)
        {
            if (sw==1)
            {
                if (t[i][j]==1)
                {
                    changepawn(i,j);
                }
            }
            else
            {
                if (t[i][j]==-1)
                {
                    changepawn(i,j);
                }
            }
        }
        flip();
        if (sw==1)
        {
            if (chess(xrn,yrn)==1)
            {
                if(checkmate(xrn,yrn)==1)
                {
                    ok=0;
                    sm=1;
                }
            }
        }
        else
        {
            if (chess(xra,yra)==1)
            {
                if (checkmate(xra,yra)==1)
                {
                    ok=0;
                    sm=1;
                }
            }
        }
        if (sw==1)
        {
            if (stalemate(xrn,yrn)==0)
            {
                ok=0;
            }
        }
        else
        {
            if (stalemate(xra,yra)==0)
            {
                ok=0;
            }
        }
    }
    display();
    if (sm==1)
    {
        cout<<"\ \ \ \ CHECK MATE !!!"<<endl<<endl;
        cout<<"\ \ \ \ WINNER ";
        if (sw==1)
            cout<<p1<<" !!!";
        else
            cout<<p2<<" !!!";
    }
    else
        cout<<"\ \ \ \ Stalemate !!! DRAW.";

}
