#include<iostream>
#include<string.h>
using namespace std ;

struct Student {
    int rollno;
    float sgpa;
    char name[30];
};

void display(struct Student s[30] , int n ){
    for (int i=0;i<n;i++){
        cout<<"\n"<<s[i].rollno<<"\t"<<s[i].name<<"\t"<<s[i].sgpa;
    }
}

void binary(struct Student s[30] , int n){
    int temp1 , i , j ;
    float temp2;
    char temp3 [30] , data[30];
    int left=0 , right=n-1 , mid , flag =0;

    for (int i=1;i<n;i++){
        strcpy (temp3,s[i].name);
        temp2=s[i].sgpa;
        temp1=s[i].rollno;
        j=i-1;
        while(j>=0 && strcmp(s[j].name,temp3)>0){
            strcpy(s[j+1].name,s[j].name);
            s[j+1].sgpa=s[j].sgpa;
            s[j+1].rollno=s[j].rollno;
            j--;
        }
        strcpy(s[j+1].name,temp3);
        s[j+1].sgpa=temp2;
        s[j+1].rollno=temp1;
    }
    cout<<"Enter data or name to search:";
    cin>>data;
    while(left<=right){
        mid=(left+right)/2;
        if(strcmp (data,s[mid].name)==0){
            flag =1 ;
            cout<<"record found";
            cout<<"\n"<<s[mid].rollno<<"\t"<<s[mid].name<<"\t"<<s[mid].sgpa;
            break;
        }
        else if (strcmp (data,s[mid].name)<0){
            right = mid-1;
        }
        else {
            left = mid +1;
        }
    }
    if(flag==0){
        cout<<"\nRecord not found";
    }
}

int partition(struct Student s[30] , int n , int lb , int ub ){
    int start , end ,temp2 ;
    char temp3 [30];
    float temp1 , pivot ;
    pivot = s[lb].sgpa;
    start= lb ;
    end = ub ;
    while(start <end){
        while(s[start].sgpa<=pivot){
            start++;
        }
        while(s[end].sgpa>pivot){
            end--;
        }
    
        if (start<end){
            temp1 = s[start].sgpa;
            s[start].sgpa = s[end].sgpa;
            s[end].sgpa = temp1;

            temp2 = s[start].rollno;
            s[start].rollno = s[end].rollno;
            s[end].rollno = temp2;

            strcpy(temp3 , s[start].name);
            strcpy(s[start].name , s[end].name);
            strcpy(s[end].name , temp3);

        }
    }
    temp1=s[lb].sgpa;
    s[lb].sgpa=s[end].sgpa;
    s[end].sgpa=temp1;

    temp2=s[lb].rollno;
    s[lb].rollno=s[end].rollno;
    s[end].rollno=temp2;

    strcpy(temp3 , s[lb].name);
    strcpy(s[lb].name , s[end].name);
    strcpy(s[end].name , temp3);
    return end ;
}

void quick (struct Student s[30] , int n , int lb , int ub){
    int loc , i , count=0;
    if(lb<ub){
        loc = partition(s,n,lb,ub);
        quick(s,n,lb,loc-1);
        quick(s,n,loc+1,ub);
    }
    cout<<"\n Top ten toppers:";
    for(i=n-1;i>=0;i--){
        count++;
        if(count>10){
            break;
        }
        cout<<"\n"<<s[i].rollno<<"\t"<<s[i].name<<"\t"<<s[i].sgpa;
    }
}

int main(){
    struct Student s[30];
    int i,n, ch ;
    cout<<"\nEnter total Students:";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"\nEnter students roll number , name , sgpa:";
        cin>>s[i].rollno;
        cin>>s[i].name;
        cin>>s[i].sgpa;
    }
    display(s,n);
    do{
        cout<<"\n1. Binary Search(to search Student according to name)";
        cout<<"\n2. Quick Sort (to display top ten toppers)";
        cout<<"\n3. Exit..";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch)
        {
        case 1: 
            binary(s,n);
            break;
        
        case 2:
            quick(s,n,0,n-1);
            break;
        
        default:
            break;
        }
    }while(ch!=2);
    return 0;
}

