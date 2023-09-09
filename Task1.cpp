#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    srand((unsigned int)time(NULL));
    int number = (rand() %100)+1;
    int guess_number=0;
    do
    {
        cout<<"Enter the guess(1-100): ";
        cin>>guess_number;

        if(guess_number>number){
            cout<<"Guess lower number!"<<endl;
        }
        else if(guess_number<number){
            cout<<"Guess higher number!"<<endl;
        }
        else{
            cout<<"You won the game!"<<endl;
        }
    } while (guess_number != number);
    return 0;
}