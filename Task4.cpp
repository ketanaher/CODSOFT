#include<iostream>
#include<string>
using namespace std;
class node {
    public:
    string task;
    string status;
    node* next;

    node(string task1) {
        this->task = task1;
        this->status = "Pending";
        this->next = NULL;
    }
};
class Listing {
    public:
    string tasks;
    node* head = NULL;
    string input_Task(){
        cin.ignore();
        cout << "Enter the task:";
        getline(cin, tasks);
        return tasks;
    }
    void add_the_Task() {
        List : input_Task();           
        struct node* newNode = new node(tasks);
        if(head == NULL) {
            head = newNode;
            cout << "Task Added Succesfully in the list...." << endl;
            return;
        }
        else{
            node *Temp;
            Temp = head;
            while(Temp -> next != NULL){
                Temp = Temp -> next;
            }
            Temp -> next = newNode;
            cout << "Task Added Succesfully in the list...." << endl;
        }    
    }
    void updateTask(int position) {   
        int current_position = 1;
        node* temp = head;
        if(temp==NULL){
            cout<<"There is no task to update"<<endl;
        }
        else{
        while(current_position != position){
           temp = temp -> next;
           current_position++;
        }
        temp->status ="Complete";
        cout << "Task is marked as complete succesfully......" << endl;
        }
    }
    void DeleteTask(int position) {
        int current_position = 1;
        node* prev = head;
        if(position == 1) {
            head = head -> next;
            free(prev);
            cout << "\nTask deleted succesfully..." << endl;
            return;
        }
        while(current_position != position - 1){
            prev = prev -> next;
            current_position++;
        }
        node* temp = prev -> next;
        prev -> next = prev -> next -> next;
        free(temp);
        cout << "\nTask deleted succesfully..." << endl;
    }
    void Display() {
        struct node *temp;
        temp = head;
        if(temp==NULL){
            cout<<"There is no entry in the list"<<endl;
        }
        else{
        cout << "_____***To Do List***_____" << endl;
        cout << endl;
        int i = 1;
        while(temp != NULL){
            cout << i << ") Work : " << temp -> task << " = status :" << temp -> status;
            cout << endl;
            temp = temp -> next;
            i++;
        }
        cout << "\n_____________________________________________________" << endl;
        }
    }
};
int main() {
    Listing l1;
    int iChoice,position;
    
    do {
        cout << "_______________________________________________________" <<endl;
        cout << "1)Add the new task \n2)Mark the task as Completed \n3)Displaying the task with there Status \n4)Remove the task from the list \n5)Exit from program" << endl;
        cout << "_______________________________________________________" <<endl;
        cout << "what do you want to do? enter your choice -> ";
        cin >> iChoice;
        cout << "\n_____________________________________________________" << endl;
        switch(iChoice) {
            case 1:
                l1.add_the_Task();
                break;
            case 2:
                cout << "Enter the position of task on which task mark as completed:";
                cin >> position;
                l1.updateTask(position);
                break;
            case 3:
                l1.Display();
                break;
             case 4:
                cout << "Enter the position of task which is to be deleted:";
                cin >> position;
                l1.DeleteTask(position);
                break;
            case 5:
                cout << "Exit...." << endl;
                cout<<"----------Thank you----------"<<endl;
                break;     
        }
    }while(iChoice != 5);

    return 0;
}