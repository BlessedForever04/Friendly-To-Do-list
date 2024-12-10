#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
//fstream for file handling
//cstdlib for clearing terminal after each iteration
using namespace std;

void add(){
    fstream file("data.txt", ios::app); //ios::app and fstream for specifically appending the data inserted to file to avoid rewriting
    cout<<"Enter task: ";
    string task;
    getline(cin, task);
    file<<task<<"\n";
    file.close();
    system("cls"); //clears the terminal for iteration or successful function call
}

void Delete(){
    ifstream file("data.txt"); //ifstream for only reading the file and not writing anything
    cout<<"Enter task number to delete: ";
    int target;
    cin>>target;
    vector <string> history;
    string line;

    while(getline(file, line)){
        history.push_back(line);
    }
    file.close();
    ofstream file2("data.txt"); //ofstream for writing (overwriting) task into file
    cout<<history.size()<<endl;
    for(int i = 0; i < history.size() ; i++){
        if(i+1 != target){
            file2<<history[i]<<"\n";
        }
    }
    file2.close();
    system("cls");
}

void modify(){
    ifstream file("data.txt");
    cout<<"Enter task number to modify: ";
    int target;
    cin>>target;
    cout<<"Enter new task: ";
    string newstring;
    cin.ignore(10, '\n'); //added cin.ignore() to remove cin's new line buffer
    getline(cin, newstring); //this acts as primary getLine function for newstring
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
            file2<<newstring<<"\n";
        }
    }
    file2.close();
    system("cls");
}

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

void swapping(){
    cout<<"Enter task to swap: ";
    int t1, t2;
    string line;
    cin>>t1;
    cout<<"Enter task to swap with: ";
    cin>>t2;
    getline(cin, line);

    ifstream file("data.txt");
    vector <string> history;
    while(getline(file, line)){
        history.push_back(line);
    }
    file.close();
    swap(history[t1-1], history[t2-1]);
    ofstream filew("data.txt");
    for(int i = 0; i< history.size(); i++){
        filew<<history[i]<<"\n";
    }
    filew.close();
    system("cls");
}

int main(){
    ifstream file("data.txt", ios::in);
    if(!file){ //Cheacks if file is present in the local directory of our code
        ofstream NewFile("data.txt"); // If "data.txt" is not present then it creates one for storing data
        NewFile.close();
    }
    int input = 0;
    string line;
    
    while(input!=5){
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
            cout<<"1 - Yes / 0 - No"<<endl<<": ";
            cin>>input;
            if(input == 0){
                input = 7;
            }
            else{
                if(input == 1){
                    input = 5;
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
