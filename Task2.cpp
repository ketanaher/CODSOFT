#include<iostream>
using namespace std;
class calculator{
    float num1,num2;
    public:
    void addition(){
        cout<<"Addition is:-"<<num1+num2<<endl;
    }
    void substraction(){
        cout<<"substraction is:-"<<num1-num2<<endl;
    }
    void multiplication(){
        cout<<"multiplication of the numbers is:-"<<num1*num2<<endl;
    }
    void division(){
        if(num2==0){
            cout<<"the division is not possible"<<endl;
        }
        else{
            cout<<"division is:-"<<num1/num2<<endl;
        }
    }
    void input(){
        cout<<"Enter the two numbers"<<endl;
        cin>>num1>>num2;
    }

};
int main(){
    calculator c;
    char ch;
    do{
        cout<<"-----------MAIN MANU-------------"<<endl;
        cout<<"+ for addition\n- for substraction\n* for multiplication\n/ for division\n0 for exit"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"enter your choice"<<endl;
        cin>>ch;
        switch(ch){
            case '+':
                c.input();
                c.addition();
                break;
            case '-':
                c.input();
                c.substraction();
                break;
            case '*':
                c.input();
                c.multiplication();
                break;
            case '/':
                c.input();
                c.division();
                break;
            case '0':
                cout<<"--------thank you--------"<<endl;
                break;
            default:
             cout<<"enter the valid operation"<<endl;
            
        }
    }while(ch!='0');
    return 0;
}