#include <iostream>
#include<string.h>
using namespace std ;

struct  Student
{
    int rollno;
    float sgpa;
    char name[30];
};

void display(struct Student s[20] , int n ){
    for(int i=0;i<n;i++){
        cout<<"\n"<<s[i].rollno<<" \t "<<s[i].name<<" \t "<<s[i].sgpa;
    }
}

//sarch students according to sgpa
void linear(struct Student s[20] , int n )
{
    int count = 0;
    float sa ;
    cout<<"Enter sgpa to search ";
    cin>>sa;
    for(int i=0;i<n;i++){
        if(s[i].sgpa==sa){
            count++;
            cout<<"\n"<<s[i].rollno<<" \t "<<s[i].name<<" \t "<<s[i].sgpa;
        }
    }
    cout<<"Total records found "<<count ;
}

void bubble(struct Student s[30] , int n){
    int temp1;
    float temp2;
    char temp3[30];

    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if(s[j].rollno>s[j+1].rollno){

                temp1=s[j].rollno;
                s[j].rollno=s[j+1].rollno;
                s[j+1].rollno=temp1;

                temp2=s[j].sgpa;
                s[j].sgpa=s[j+1].sgpa;
                s[j+1].sgpa=temp2;

                strcpy(temp3,s[j].name);
                strcpy(s[j].name,s[j+1].name);
                strcpy(s[j+1].name , temp3);

            }
        }
    }
    display(s,n);
}


void insertion(struct Student s[30] , int n ){
    int temp1, i, j ; 
    float temp2 ;
    char temp3[30];

    for ( i=1;i<n;i++){
        strcpy(temp3,s[i].name);
        temp1=s[i].rollno;
        temp2=s[i].sgpa;
        j=i-1;

        while ( j>=0 && strcmp(s[j].name , temp3)>0){
            strcpy (s[j+1].name , s[j].name);
            s[j+1].rollno = s[j].rollno;
            s[j+1].sgpa = s[j].sgpa;
            j--;
        }

        strcpy (s[j+1].name , temp3);
        s[j+1].rollno = temp1;
        s[j+1].sgpa = temp2;
    }
    display(s,n);
}

int main (){
    struct Student s[30] ;
    int ch , n ;
    cout<<"Enter the number of Student:";
    cin>>n;
    for (int i=0;i<n;i++){
        cout<<"Enter the rollno , name , sgpa of Student: ";
        cin>>s[i].rollno;
        cin>>s[i].name;
        cin>>s[i].sgpa;
    }
    display(s,n);
    do{
        cout <<"\n ";
        cout<<"\nSelect from the option ";

        cout<<"\n1. Linear (Search Student according to sgpa)";
        cout<<"\n2. Bubble (Sort Student according to their Rollno)";
        cout<<"\n3. Insertion (Sort  Student according to their name )";
        cout<<"\n4. Exit.";
        cout<<"\nEnter your Choice:";
        cin>>ch;
        switch(ch){
            case 1:
                linear(s,n);
                break;

            case 2:
                bubble(s,n);
                break;

            case 3:
                insertion(s,n);
                break;

            case 4:
                break;
        }
    }while(ch!=4);
    return 0;
}
