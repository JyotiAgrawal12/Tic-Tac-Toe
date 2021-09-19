#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,col;
bool draw= false;

void display_board(){
	system("cls");
	cout<<"\t\t     TIC-TAC-TOE     \n"<<endl;
	cout<<"\t\t     PLAYER1[X]"<<endl;
	cout<<"\t\t     PLAYER2[O]\n"<<endl;

	cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
		
	
	
}

void player_turn(){
	int choice;
	
	if(turn=='X'){
		cout<<"PLAYER1 [X]:\n";
	}
	else if(turn=='O'){
		cout<<"PLAYER1 [O]:\n";
		
	}
	
	cin>>choice;
	
	switch(choice){
		
		case 1:
			row=0;col=0;
			break;
			
		case 2:
				row=0;col=1;
			break;
			
		case 3:
				row=0;col=2;
			break;
		case 4:
				row=1;col=0;
			break;	
		case 5:
				row=1;col=1;
			break;
			case 6:
				row=1;col=2;
			break;
			case 7:
				row=2;col=0;
			break;
			case 8:
				row=2;col=1;
			break;
			case 9:
			row=2;col=2;
			break;
				
			default:
				cout<<"invalid";
			}
			
			if(turn=='X'&&board[row][col]!='X' &&board[row][col]!='O'){
				board[row][col]='X';
				turn='O';
			}
			else if(turn=='O' &&board[row][col]!='X' &&board[row][col]!='O'){
				board[row][col]='O';
				turn='X';
			}
			else{
				cout<<"Box already filled\n try again\t";
				player_turn();
				
			}
			display_board();
	
}

bool gameover(){
	for(int i=0;i<3;i++){
		if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]||board[0][i]==board[1][i]&&board[0][i]==board[2][i]){
			return false;
			
		}
		if(board[0][0]==board[1][1]&&board[0][0]==board[2][2] || board[0][2]==board[1][1]&&board[0][2]==board[2][0] ){
			return false;
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j]!='X'||board[i][j]!='O'){
				return true;
			}
		}
	}
	
	draw=true;
	return false;
		
	
}

int main(){
	
	while(gameover()){
		
	
	
	
	display_board();
	player_turn();
	gameover();

	
	
	
	
	
}
if(turn=='X' &&draw ==false){
	cout<<"PLAYER1 [O] wins";
}
else if(turn=='O' &&draw ==false){
	cout<<"PLAYER2 [X] wins";
}
else{
	cout<<"GAME OVER";
}
		
	
	


return 0;
}