#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<iostream>
#include <stdlib.h>
using namespace std;
int Hash(string name);
void Insert(string name, string classtype);
int showMenu();
bool lookup(string name, string classtype);
bool check(string name);
void dump();
int Array_Size;

class symbol_info{
    public:
    string name;
    string classtype;
    symbol_info *next;
};

class Symbol_Table{
    public:
     symbol_info **head_Of_Array;

bool check(string name){

int position = Hash(name);
    symbol_info* temp = head_Of_Array[position];
    while( temp != NULL ){
        if( ( temp->name == name )){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void Insert(string name, string classtype){
    int position = Hash(name);

    if( head_Of_Array[position] == NULL ){
        head_Of_Array[position] = new symbol_info();
        head_Of_Array[position]->name = name;
        head_Of_Array[position]->classtype = classtype;
        head_Of_Array[position]->next = NULL;
    }
    else{
        symbol_info* newNode = new symbol_info();
        newNode->name = name;
        newNode->classtype = classtype;
        symbol_info* nextNode = head_Of_Array[position];
        head_Of_Array[position] = newNode;
        newNode->next = nextNode;
    }
}
bool lookup(string name, string classtype){
    int position = Hash(name);
    symbol_info* temp = head_Of_Array[position];
    while( temp != NULL ){
        if( (temp->name == name ) && (temp->classtype == classtype ) ){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void dump(){
    for(int i = 0; i < Array_Size;i++){
        printf("[%d] :", i);
        symbol_info* temp = head_Of_Array[i];

        if (temp == NULL)
        {
           cout<<"Empty";
        }
        else
        {
            while( temp != NULL ){
            cout<<"->"<<"["<<temp->name<<"|"<<temp->classtype<<"]";
            temp = temp->next;
       }
        }
   printf("\n\n");
    }
}
};


int Hash(string name){
    int idx = 0;
    for(int i = 0; name[i]; ++i){
        idx = (idx*(i+7)) + name[i];
    }
    return (idx %Array_Size);
}

int main(){

    Symbol_Table ST;
    cout << "Enter the Size of Array:";
    cin>>Array_Size;
    ST.head_Of_Array=new symbol_info *[Array_Size];

    for(int i=0;i<Array_Size;i++){
        ST.head_Of_Array[i]=NULL;
    }
    int choice = showMenu();
    while( 1 ){

        string name;
        string classtype;


        switch(choice){
        case 1:
            {
                //int x=0;
                cout << "Insert Selected:\n";
                cin>>name>>classtype;
                if( ST.check(name) ){

                    cout<<"Already Exist This name\n";
                }
                else{
                    printf("\nInsert In Index:%d\n\n", Hash(name) );
                    ST.Insert(name, classtype);
                }
            }
            break;
        case 2:
            {
                cout << "Search Selected:\n";

                cin>>name>>classtype;


                if( ST.lookup(name, classtype) ){
                    printf("FOUND\t");
                    cout<<"In Index:"<<Hash(name)<<"\n";
                }else{
                    printf("\tNOT FOUND\n");
                }
            }
            break;
        case 3:
            {
            cout << "Show Selected\n";
            ST.dump();
            }
            break;
        case 4:
            {
                cout<<"Exit";
                exit(0);
            }

        default:
            return 0;
        };

        choice = showMenu();
    }
    getch();
    return 0;
}



int showMenu(){
    string message = "1. Insert\n"
                     "2. Lookup \n"
                     "3. Dump\n"
                     "4. Exit\n"
                     ;
    cout << message << "\n";
    cout << "User Choice: ";
    int choice;
    cin>>choice;
    return choice;
}
