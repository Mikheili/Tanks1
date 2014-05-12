#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include<Windows.h>
#include"header.h"
using namespace std;
int main (){
//start:
   srand(time(0));
   char map [20][30] =
   {
   "#############################",
   "#                           #",
   "#                           #",
   "#             V             #",
   "#                           #",
   "#                           #",
   "#                           #",
   "#                           #",
   "#                           #",
   "#                           #",
   "#                           #",
   "#                           #",
   "#                           #",
   "#                           #",
   "#             H             #",
   "#                           #",
   "#                           #",                
   "#                           #",
   "#############################",
   };
   int x=14,y=14;
   int x1=3,y1=14;
   system("color ac");
   while(1){
	 system("cls");
     for (int i = 0; i < 20; i ++){  
		cout <<map[i]<< endl;
	}
	 bool flow=false;
	 int bull_dir;
		Sleep(150);
		int dir=-9;
		if(GetAsyncKeyState(VK_RIGHT))dir=0;
		if(GetAsyncKeyState(VK_LEFT))dir=1;
		if(GetAsyncKeyState(VK_UP))dir=2;	
		if(GetAsyncKeyState(VK_DOWN))dir=3;
		move(map,x,y,dir);
		int bull_x=x,bull_y=y;
		Enemy_move(map,x,y,x1,y1);
		if(flow==false){
			if(GetAsyncKeyState(VK_SPACE))shoot(map,x,y,dir,bull_dir,flow,bull_x,bull_y);
		}
		if(flow==true)shoot(map,x,y,dir,bull_dir,flow,bull_x,bull_y);
}
}
