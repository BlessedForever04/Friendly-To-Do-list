#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
//fstream for file handling
//cstdlib for clearing terminal after each iteration
using namespace std;

//add() adds the task in local storage (data.txt) file;
void add(){
    fstream file("data.txt", ios::app); //ios::app and fstream for specifically appending the data inserted to file to avoid rewriting
    cout<<"Enter task: ";
    string task;
    getline(cin, task);
    file<<task<<"\n";
    file.close();
    system("cls"); //clears the terminal after each iteration or successful function call
}

//delete() function deletes any task within list with task number as input;
void Delete(){
    ifstream file("data.txt"); //ifstream for only reading the file and not writing anything
    cout<<"Enter task number to delete: ";
    int target; // Target is task's number (example: task number 3 or task number 8)
    cin>>target;
    vector <string> history;
    string line;


    //First loop fills up vector
    while(getline(file, line)){
        history.push_back(line);
    }
    file.close();
    ofstream file2("data.txt"); //ofstream for writing (overwriting) task into file

    //second loop refills the data.txt with required update and changes
    for(int i = 0; i < history.size() ; i++){
        if(i+1 != target){
            file2<<history[i]<<"\n";
        }
    }
    file2.close();
    system("cls");
}

//Modify() function modifies any task, we have to enter updated or completely new task as input;
//acts similar to delete() function with smaller chnages;
void modify(){
    ifstream file("data.txt");
    cout<<"Enter task number to modify: ";
    int target;
    cin>>target;
    cout<<"Enter new task: ";
    string NewTask;
    cin.ignore(10, '\n'); //added cin.ignore() to remove cin's new line buffer
    getline(cin, NewTask); //this acts as primary getLine function for NewTask
    vector <string> history;
    string line;

    while(getline(file, line)){
        history.push_back(line);
    }

    file.close();
    ofstream file2("data.txt");

    for(int i = 0; i < history.size() ; i++){
        if(i+1 != target){
            file2<<history[i]<<"\n";
        }
        else{
            file2<<NewTask<<"\n";
        }
    }
    file2.close();
    system("cls");
}

//Clearall() function clears the whole to-do list, just deletes all tasks.
void clearall(){
    int confirm = 3;
    cout<<"1 - Yes / 0 - No"<<endl<<": ";
    cin>>confirm;
    if(confirm == 0){
        system("cls");
        return;
    }
    else{
        if(confirm == 1){
            ofstream file("data.txt");
            file<<"";
            file.close();
            system("cls");
        }
        else{
            cout<<"Enter valid input";
            clearall();
        }
    }
}

//print() function prints all the tasks in the list
void print(){
    ifstream file("data.txt");
    int counter = 1; //simple counter to print task number
    string line;
    cout<<"         Tasks"<<endl;
    cout<<"-------------------------"<<endl;
    while(getline(file, line)){
        cout<<counter<<". "<<line<<endl;
        counter++;
    }
    if(counter == 1){
        cout<<"    --- No tasks ---"<<endl;
    }
    cout<<"-------------------------"<<endl;
    file.close();
}

//Swapping() functions swaps 2 tasks (their position), 2 inputs are required (their task number);
void swapping(){
    int t1, t2; //target 1 and target 2
    string line;
    cout<<"Enter task to swap: ";
    cin>>t1;
    cout<<"Enter task to swap with: ";
    cin>>t2;
    cin.ignore(10,'\n');

    ifstream file("data.txt");
    vector <string> history;
    while(getline(file, line)){
        history.push_back(line);
    }
    file.close();
    swap(history[t1-1], history[t2-1]);
    ofstream filee("data.txt");
    for(int i = 0; i< history.size(); i++){
        filee<<history[i]<<"\n";
    }
    filee.close();
    system("cls");
}

int main(){
    ifstream file("data.txt", ios::in);
    if(!file){ //Cheacks if file is present in the local directory of our code
        ofstream NewFile("data.txt"); // If "data.txt" is not present then it creates one for storing data
        NewFile.close();
    }
    int input;
    string line;
    
    while(input != 11){
        cout<<"\nYour friendly To-Do list:\n\n";
        print();
        cout<<endl;
        cout<<"1: Add task\n";
        cout<<"2: Delete task\n";
        cout<<"3: Modify task\n";
        cout<<"4: Swap tasks\n";
        cout<<"5: Clear all tasks\n";
        cout<<"6: Exit\n";
        cout<<": ";
        cin>>input;
        cin.ignore(10,'\n');

        switch(input){
            case 1:
            add();
            break;

            case 2:
            Delete();
            break;

            case 3:
            modify();
            break;

            case 4:
            swapping();
            break;

            case 5:
            clearall();
            break;

            case 6:
            //Confirmation, just in case someone press is accidently
            cout<<"1 - Yes / 0 - No"<<endl<<": ";
            cin>>input;
            if(input == 0){
                input = 7;
            }
            else{
                if(input == 1){
                    input = 11;
                    break;
                }
                else{
                    cout<<"Wrong input, cant perform task";
                }
            }

            default:
            system("cls");
            cout<<"Enter valid input"<<endl;
            break;
        }
    }
}
//Thanks for reading the code,
//This code can be more optimized and object oriented using classes and their instances i.e class ToDo, class Task etc
