#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>
using namespace std;
const int LEFT=1, RIGHT=2, BOTTOM=4, TOP=8;
int xl, yl, xh, yh;

int getcode(int x, int y){
	int CODE = 0;
	if(y > yh) CODE = CODE|TOP;
	if(y < yl) CODE = CODE|BOTTOM;
	if(x < xl) CODE = CODE|LEFT;
	if(x > xh) CODE = CODE|RIGHT;
	return CODE;
}

int main(){
    int permission=0, accept=0;
    int x, y, outcode, outcode1, outcode2;
	cout<<"Enter Rectangle Coefficients (Left, Top, Right, Below): ";
	cin>>xl>>yl>>xh>>yh;
	int x1,y1,x2,y2;
	cout<<"Enter Line Coefficients (x1,y1,x2,y2): ";
	cin>>x1>>y1>>x2>>y2;
	int gd0 = DETECT, gm0;
   initgraph(&gd0, &gm0, "");
	setcolor(BLUE);
	line(x1,y1,x2,y2);
    rectangle(xl,yl,xh,yh);

	outcode1=getcode(x1,y1);
	outcode2=getcode(x2,y2);
	while(1){
		float m =(float)((y2-y1)/(x2-x1));

		if(outcode1==0 && outcode2==0){
			accept = 1;
			break;
		}
		else if((outcode1 & outcode2)!=0)
			break;
		else{
			if(outcode1==0)
				outcode = outcode2;
			else
				outcode = outcode1;
			if(outcode & TOP){
				x = x1+ (yh-y1)/m;
				y = yh;
			}
			else if(outcode & BOTTOM){
				x = x1+ (yl-y1)/m;
				y = yl;
			}else if(outcode & LEFT){
				x = xl;
				y = y1+ m*(xl-x1);
			}else if(outcode & RIGHT){
				x = xh;
				y = y1+ m*(xh-x1);
			}

			if(outcode == outcode1){
				x1 = x;
				y1 = y;
				outcode1 = getcode(x1,y1);
			}
			else{
				x2 = x;
				y2 = y;
				outcode2 = getcode(x2,y2);
			}
		}
	}
	setcolor(WHITE);
	if(accept==1){
        cout<<"To See Graph After Clipping Press 1:";
        cin>>permission;
        if(permission!=1)return 0;
        closegraph();
        int gd1= DETECT, gm1;
        initgraph(&gd1, &gm1, "");
		line(x1,y1,x2,y2);
		setcolor(RED);
		rectangle(xl,yl,xh,yh);
	}
	getch();
	closegraph();
	return 0;
}
