#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <limits>
//fstream for file handling
//cstdlib for clearing terminal after each iteration
// using namespace std;

//add() adds the task in local storage (data.txt) file;
void add(){
    std::fstream file("data.txt", std::ios::app); //ios::app and fstream for specifically appending the data inserted to file to avoid rewriting
    std::cout<<"Enter task: ";
    std::string task;
    getline(std::cin, task);
    file<<task<<"\n";
    file.close();
    system("cls"); //clears the terminal after each iteration or successful function call
}

//delete() function deletes any task within list with task number as input;
void Delete(){
    std::ifstream file("data.txt"); //std::ifstream for only reading the file and not writing anything
    std::cout<<"Enter task number to delete: ";
    int target; // Target is task's number (example: task number 3 or task number 8)
    std::cin>>target;
    std::vector <std::string> history;
    std::string line;


    //First loop fills up vector
    while(std::getline(file, line)){
        history.push_back(line);
    }
    file.close();
    std::ofstream file2("data.txt"); //std::ofstream for writing (overwriting) task into file

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
    std::ifstream file("data.txt");
    std::cout<<"Enter task number to modify: ";
    int target;
    std::cin>>target;
    std::cout<<"Enter new task: ";
    std::string newTask;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //added std::cin.ignore() to remove std::cin's new line buffer
    std::getline(std::cin, newTask); //this acts as primary getLine function for newTask
    std::vector <std::string> history;
    std::string line;

    int i = 1;
    while(getline(file, line)){
        if (i == target) {
            history.push_back(newTask);
            i++;
        } else {
            history.push_back(line);
            i++;
        }
    }


    file.close();
    std::ofstream file2("data.txt");

    for (auto task : history) {
        file2 << task << '\n';
    }
    file2.close();
    system("cls");
}

//Clearall() function clears the whole to-do list, just deletes all tasks.
void clearall(){
    int confirm = 3;
    std::cout<<"1 - Yes / 0 - No"<<std::endl<<": ";
    std::cin>>confirm;
    if(confirm == 0){
        system("cls");
        return;
    }
    else{
        if(confirm == 1){
            std::ofstream file("data.txt");
            file<<"";
            file.close();
            system("cls");
        }
        else{
            std::cout<<"Enter valid input";
            clearall();
        }
    }
}

//print() function prints all the tasks in the list
void print(){
    std::ifstream file("data.txt");
    int counter = 1; //simple counter to print task number
    std::string line;
    std::cout<<"         Tasks"<<std::endl;
    std::cout<<"-------------------------"<<std::endl;
    while(getline(file, line)){
        std::cout<<counter<<". "<<line<<std::endl;
        counter++;
    }
    if(counter == 1){
        std::cout<<"    --- No tasks ---"<<std::endl;
    }
    std::cout<<"-------------------------"<<std::endl;
    file.close();
}

//Swapping() functions swaps 2 tasks (their position), 2 inputs are required (their task number);
void swapping(){
    int t1, t2; //target 1 and target 2
    std::string line;
    std::cout<<"Enter task to swap: ";
    std::cin>>t1;
    std::cout<<"Enter task to swap with: ";
    std::cin>>t2;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //added std::cin.ignore() to remove std::cin's new line buffer

    std::ifstream input("data.txt");
    std::vector <std::string> history;
    while(getline(input, line)){
        history.push_back(line);
    }
    input.close();
    swap(history[t1-1], history[t2-1]);
    std::ofstream write("data.txt");
    for(int i = 0; i< history.size(); i++){
        write<<history[i]<<"\n";
    }
    write.close();
    system("cls");
}

int main(){
    std::ifstream file("data.txt", std::ios::in);
    if(!file){ //Cheacks if file is present in the local directory of our code
        std::ofstream NewFile("data.txt"); // If "data.txt" is not present then it creates one for storing data
        NewFile.close();
    }
    int input;
    std::string line;

    while(true){
        std::cout<<"\nYour friendly To-Do list:\n\n";
        print();
        std::cout<<std::endl;
        std::cout<<"1: Add task\n";
        std::cout<<"2: Delete task\n";
        std::cout<<"3: Modify task\n";
        std::cout<<"4: Swap tasks\n";
        std::cout<<"5: Clear all tasks\n";
        std::cout<<"6: Exit\n";
        std::cout<<": ";
        std::cin>>input;
        std::cin.ignore(10,'\n');

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
            std::cout<<"1 - Yes / 0 - No"<<std::endl<<": ";
            std::cin>>input;
            if(input == 0){
                input = 7;
            }
            else{
                if(input == 1){
                    return 0;
                }
                else{
                    std::cout<<"Wrong input, cant perform task";
                }
            }

            default:
            system("cls");
            std::cout<<"Enter valid input"<<std::endl;
            break;
        }
    }
}
//Thanks for reading the code,
//This code can be more optimized and object oriented using classes and their instances i.e class ToDo, class Task etc
