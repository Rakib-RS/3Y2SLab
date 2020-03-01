#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>
using namespace std;

int getPt( int n1 , int n2 , float perc){
        return n1 + (n2 - n1)*perc;
    }

int main(){
   int xa, ya, xb, yb, x1, y1, x2, y2, x3, y3, x, y;
   cout<<"Enter 3 Points (x1,y1,x2,y2,x3,y3): ";
   cin>>x1>>y1>>x2>>y2>>x3>>y3;
	int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
    setfillstyle(SOLID_FILL, RED);
   circle(x1,y1, 5);
    floodfill(x1,y1, WHITE);
   circle(x2,y2, 5);
    floodfill(x2,y2, WHITE);
   circle(x3,y3, 5);
    floodfill(x3,y3, WHITE);
    setcolor(WHITE);
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    for( float i=0; i<1; i=i+0.00001 ){
        xa = getPt( x1 , x2 , i );
        ya = getPt( y1 , y2 , i );
        xb = getPt( x2 , x3 , i );
        yb = getPt( y2 , y3 , i );

        x = getPt( xa , xb , i );
        y = getPt( ya , yb , i );

        putpixel( x , y , RED );
    }
    getch();
	closegraph();
    return 0;
}
