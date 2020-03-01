#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>
using namespace std;

int main(){
   int xa, ya, r;
   INPUT:
	cout<<"Enter Center Coordinate: ";
	cin>>xa>>ya;
	cout<<"Enter Radius: ";
	cin>>r;
	if(xa-r<0 || ya-r<0){
	    cout<<"INVALID INPUT!";
        goto INPUT;
	}
    int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
	int x = r, y = 0;
    putpixel(y + xa, -x + ya, RED);
    putpixel(x + xa, -y + ya, RED);
    putpixel(y + xa, x+ ya, RED);
    putpixel(-y + xa, x + ya, RED);
	int P = 1 - r;
	while (x > y){
		y++;
		if (P <= 0)
			P = P + 2*y + 1;
		else{
			x--;
			P = P + 2*y - 2*x + 1;
		}
		if (x < y)break;
        putpixel(x + xa, y + ya, RED);
        putpixel(-x + xa, y + ya, RED);
        putpixel(x + xa, -y + ya, RED);
        putpixel(-x + xa, -y + ya, RED);
		if (x != y){
            putpixel(y + xa, x + ya, RED);
            putpixel(-y + xa, x + ya, RED);
            putpixel(y + xa, -x + ya, RED);
            putpixel(-y + xa, -x + ya, RED);
		}
		delay(100);
	}
	getch();
   closegraph();
	return 0;
}
