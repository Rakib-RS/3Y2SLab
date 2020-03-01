#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main(){
    int gdrive = DETECT,gmode;
    initgraph(&gdrive,&gmode,"");
    int n=0;
    while(1){
        n++;
        setcolor(rand()%20);
        line(rand()%100,rand()%300,rand()%600,rand()%400);
        delay(100);
        if(n>25){
            cleardevice();
            n=0;
        }
    }
    getch();
    closegraph();

return 0;
}
