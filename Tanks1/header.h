void move(char map[][30],int &x,int &y,int dir){
// 0-right 1-left 2-up 3-down
	if(dir==0){
		if(map[x][y+1]==' '){
			map[x][y+1]='=';
			map[x][y]=' ';
			y++;
		}
	}
	if(dir==1){
		if(map[x][y-1]==' '){
			map[x][y-1]='=';
			map[x][y]=' ';
			y--;
		}
	}
	if(dir==2){
		if(map[x-1][y]==' '){
			map[x-1][y]='H';
			map[x][y]=' ';
			x--;
		}
	}
	if(dir==3){
		if(map[x+1][y]==' '){
			map[x+1][y]='H';
			map[x][y]=' ';
			x++;
		}
	}
}
void Enemy_move(char map[][30],int x,int y,int &x1,int &y1){
	int q1=0;
	int q2=0;
	q1=rand()%5;
	switch (q1){
	case 0:{
	if (x>x1){
		if(map[x1+1][y1]==' '){
			map [x1][y1]=' ';
			x1++;
			map [x1][y1]='v';
		}
	}
	if (x<x1){
		if(map[x1-1][y1]==' '){
			map [x1][y1]=' ';
			x1--;
			map [x1][y1]='^';
		}
	}break;
		   }
	case 1:{
	if (y>y1){
		if(map[x1][y1+1]==' '){
			map [x1][y1]=' ';
			y1++;	
			map [x1][y1]='>';
			break;
		}
	}
	if (y<y1){
		if(map[x1][y1-1]==' '){
			map [x1][y1]=' ';
			y1--;
			map [x1][y1]='<';
			break;
		}
	}
		   }
	case 3:{
	if (y>y1){
		if(map[x1][y1+1]==' '){
			map [x1][y1]=' ';
			y1++;
			map [x1][y1]='>';
		}
	}
	if (y<y1){
		if(map[x1][y1-1]==' '){
			map [x1][y1]=' ';
			y1--;
			map [x1][y1]='<';
		}
	break;
	}
		   }
	case 4:{
	if (x>x1){
		map [x1][y1]=' ';
		x1++;
		map [x1][y1]='v';
	}
	if (x<x1){
		map [x1][y1]=' ';
		x1--;
		map [x1][y1]='^';
	break;
	}
		}
	case 2:{
		q2=rand()%4;
		if (q2==0){
		map [x1][y1]=' ';
		x1++;
		map [x1][y1]='>';
	}
	if (q2==1){
		map [x1][y1]=' ';
		x1--;
		map [x1][y1]='<';
	}
	if (q2==2){
		map [x1][y1]=' ';
		y1--;
		map [x1][y1]='^';
	}
	if (q2==3){
		map [x1][y1]=' ';
		y1++;
		map [x1][y1]='v';
	}
		}
	}
}
/*void Enemy_move_v2(char map[][30],int x,int y,int &x1,int &y1){
	int random=rand()%5;  //0-vertikalurad,1-vertkalurad,2horizontalurad,3horizontalurad,4-random
	switch(random){
	case 0:{
		)
		   }
	}
}*/
void shoot(char map[][30],int x,int y,int dir,int &bull_dir,bool &flow,int &bull_x, int &bull_y){
	if(flow==false){
		switch(dir){
	case 0:{
		if(map[x][y+1]!='#'){
			map[x][y+1]='o';
			if(map[x][y]=='o')map[x][y]=' '; 
			bull_x=x;
			bull_y=y+1;
			bull_dir=dir;
			flow=true;
		   }
		break;
		}
	case 1:{
		if(map[x][y-1]!='#'){
			map[x][y-1]='o';
			if(map[x][y]=='o')map[x][y]=' ';
			bull_x=x;
			bull_y=y-1;
			flow=true;
			bull_dir=dir;
		}
		break;
		   }
	case 2:{
		if(map[x-1][y]!='#'){
			map[x-1][y]='o';
			if(map[x][y]=='o')map[x][y]=' ';
			bull_x=x-1;
			bull_y=y;
			flow=true;
			bull_dir=dir;
		}break;

		   }
	case 3:{
		if(map[x+1][y]!='#'){
			map[x+1][y]='o';
			if(map[x][y]='o')map[x][y]=' ';
			bull_x=x+1;
			bull_y=y;
			flow=true;
			bull_dir=dir;
		}break;
		   }
	}
	}
	if(flow==true){
		switch(bull_dir){
		case 0:{
			if(map[bull_x][bull_y+1]!='#'){
				map[bull_x][bull_y]=' ';
				bull_y++;
				map[bull_x][bull_y]='o';
			}
			else {
				flow=false;
				bull_x=-9;
				bull_y=-9;
				bull_dir=-9;
			}
			break;
			 }
		case 1:{
			if(map[bull_x][bull_y-1]!='#'){
				map[bull_x][bull_y]=' ';
				bull_y--;
				map[bull_x][bull_y]='o';

			}
				else {
				flow=false;
				bull_x=-9;
				bull_y=-9;
				bull_dir=-9;
			}
			break;
			   }
		case 2:{
			if(map[bull_x-1][bull_y]!='#'){
				map[bull_x][bull_y]=' ';
				bull_x--;
				map[bull_x][bull_y]='o';
			}
			else {
				flow=false;
				bull_x=-9;
				bull_y=-9;
				bull_dir=-9;
			}break;
			   }
		case 3:{
			if(map[bull_x+1][bull_y]!='#'){
				map[bull_x][bull_y]=' ';
			bull_x++;
			map[bull_x][bull_y]='o';
			}
			else {
				flow=false;
				bull_x=-9;
				bull_y=-9;
				bull_dir=-9;
			}break;
			 }
		}
	}
}