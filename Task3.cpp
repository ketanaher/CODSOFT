#include<iostream>
using namespace std;
char board[9] = { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };
void show_board();
void get_x_move_player_choice();
void get_o_move_player_choice();
int count_board(char symbol);
char check_winner();
void player();
int main(){
    show_board();
    player();
    return 0;
} 
void player(){
    string x_player_name, o_player_name;
    cout<<"Enter the x player's name "<<endl;
    cin>>x_player_name;
    cout<<"Enter the o player's name"<<endl;
    cin>>o_player_name;
    while(true){
        system("cls");
        show_board();
        if(count_board('X') == count_board('O')){
            cout<<x_player_name<<" s turn "<<endl;
            get_x_move_player_choice();

        }
        else{
            cout<<o_player_name<<" o Turn "<<endl;
            get_o_move_player_choice();

        }
        char winner =check_winner();
        if(winner =='X'){
            system("cls");
            show_board();
            cout<<"Congratulation's "<<x_player_name<<" you won the Game "<<endl;
            cout<<"Well played "<<o_player_name<<endl;
            break;
        }
        else if(winner =='O'){
            system("cls");
            show_board();
            cout<<"Congratulation's "<<o_player_name<<"you Won the Game"<<endl;
            cout<<"Well played "<<x_player_name<<endl;
            break;
        }
        else if(winner == 'D'){
            cout<<"Game is Draw"<<endl;
            break;
        }
    }
}

void get_x_move_player_choice(){
    while(true){
        cout<<"Select your position (1 -9): ";
        int choice;
        cin>>choice;
        choice--;
        if(choice < 0 || choice>8){
            cout<<"Please select your choice From(1 - 9) "<<endl;
        }
        else if(board[choice] !=' '){
            cout<<"Please select an empty position "<<endl;
        }
        else{
            board[choice] = 'X';
            break;
        }
    }
}

void get_o_move_player_choice(){
    while(true){
        cout<<"Select your position (1 -9): ";
        int choice;
        cin>>choice;
        choice--;
        if(choice < 0 || choice>8){
            cout<<"Please select your choice From(1 - 9) "<<endl;
        }
        else if(board[choice] !=' '){
            cout<<"Please select an empty position "<<endl;
        }
        else{
            board[choice] = 'O';
            break;
        }
    }
}
int count_board(char symbol){
    int total;
    total=0;
    for(int i=0;i<9;i++){
        if(board[i] == symbol)
            total+=1;
    }
    return total;
}
char check_winner(){
    if(board[0]==board[1] && board[1]==board[2]&&board[0]!=' ')
        return board[0];
    if(board[3]==board[4] && board[4]==board[5]&&board[3]!=' ')
    return board[3];
    if(board[6]==board[7] && board[7]==board[8]&&board[6]!=' ')
    return board[6];
    // vertical
    if(board[0] == board[3] && board[3] == board[6]&& board[0] !=' ')
        return board[0];
    if(board[1] == board[4] && board[4] == board[7]&& board[1] !=' ')
        return board[1];
    if(board[2] == board[5] && board[5] == board[8]&& board[2] !=' ')
        return board[2];

    // in digonal
    if(board[0]==board[4] && board[4] == board[8] && board[0]!= ' ')
        return board[0];
    if(board[2] == board[4] && board[4] == board[6] && board[2]!=' ')
        return board[2];
    if(count_board('X')+ count_board('O')<9)
        return 'C';
    else
        return 'D';
}
// This function for shoeing the board
void show_board(){
    cout<< " "<<"    |   "<<"    |   "<<endl;
    cout<< " "<<board[0]<<"   |   "<<board[1]<<"   |   "<<board[2]<<endl;
    cout<<"-------------------"<<endl;
    cout<< " "<<"    |   "<<"    |   "<<endl;
    cout<< " "<<board[3]<<"   |   "<<board[4]<<"   |   "<<board[5]<<endl;
    cout<<"-------------------"<<endl;
    cout<< " "<<"    |   "<<"    |   "<<endl;
    cout<< " "<<board[6]<<"   |   "<<board[7]<<"   |   "<<board[8]<<endl;

} 