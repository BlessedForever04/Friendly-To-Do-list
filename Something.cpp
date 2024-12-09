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
    getline(cin, newstring); //This line here is just for capturing the new line buffer by cin>>
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
    ofstream file("data.txt");
    file<<"";
    file.close();
    system("cls");
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
int main(){
    ifstream file("data.txt", ios::in);
    if(!file){ //Cheacks if file is present in the local directory of our code
        ofstream NewFile("data.txt"); // If "data.txt" is not present then it creates one for storing data
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
        cout<<"4: Clear all tasks\n";
        cout<<"5: Exit\n";
        cout<<": ";
        cin>>input;

        switch(input){
            case 1:
            getline(cin, line);
            add();
            break;

            case 2:
            Delete();
            break;

            case 3:
            modify();
            break;

            case 4:
            clearall();
            break;

            case 5:
            break;

            default:
            system("cls");
            cout<<"Enter valid input"<<endl;
            break;
        }
    }
}

// this can be changed