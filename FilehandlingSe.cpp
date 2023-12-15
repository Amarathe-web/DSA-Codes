#include <iostream>
#include <fstream>
using namespace std;

class student
{

	int roll_no;
	char Name[30];
	char Division[5];
	char Address[50];

	public:
		void accept();
		void display();
		int rollno()
		{
			return roll_no;
		}
};


void student::accept()
{
	cout<<"\nEnter Roll Number: ";
	cin>>roll_no;

	cout<<"\nEnter Name: ";
	cin.ignore();
	cin.getline(Name,30);
	
	cout<<"\nEnter Division: ";
	cin>>Division;
	
	cout<<"\nEnter Address: ";
	cin>>Address;

	cout<<"\n";
}


void student::display()
{
	cout<<"\n    "<<roll_no<<"\t  "<<Name<<"  \t\t "<<Division<<"\t      "<<Address;
}


void create()
{
	student s;
	int n, i;

	ofstream out("Student.txt");  // ofstream helps to create file and do write operation 
	cout<<"\nHow many records do you want to enter?: ";
	cin>>n;

	for(i=0;i<n;i++)
	{
		s.accept();
		out.write((char *)&s,sizeof(s));
	}

	out.close();
}


void display()
{
	student s;
	ifstream infile("Student.txt");
	while(infile.read((char *)&s, sizeof(s)))
	{
		s.display();
	}

	infile.close();
}



void search()
{
	int n, flag=0;

	cout<<"\nEnter Roll Number To Be Searched: ";
	cin>>n;
	ifstream infile("Student.txt");

	student s;
	while(infile.read((char *)&s,sizeof(s)))
	{
		if(s.rollno()==n)
		{
			cout<<"\nRecord Found\n";
			cout<<"\nRoll Number          Name                      Division         Address";
			s.display();
			flag=1;
			break;
		}
	}

	if(flag==0)
	{
		cout<<"\nRecord Not Found.";
	}

	infile.close();
}




void add_record()
{
	student s;
	ofstream outfile("Student.txt",ios::app);
	s.accept();
	outfile.write((char *)&s,sizeof(s));
	outfile.close();
	cout<<"Record Successfully Added.";
}



int main()
{
	int choice;
	// int roll_no,Marks;
	// char Name[30];
	
	do
	{   cout<<"\n";
		cout<<"\nMenu:\n1) Create Database.\n2) Display.\n3) Add record.\n4) Search Record.\n5) Exit.";
		cout<<"\n\nEnter Your Choice:  ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"\n";
				create();
				break;

			case 2:
				cout<<"\n";
				cout<<"\nRoll Number          Name                      Division         Address";
				display();
				break;

			case 3:
				cout<<"\n";
				add_record();
				break;

			case 4:
				cout<<"\n";
				search();
				break;

			case 5:
				cout<<"\n";
				cout<<"You Have Successfully Exitted...";
				break;
		} 
	}
	while(choice!=5);

	return 0;
}

/*
#include <iostream>
#include<fstream>
using namespace std;

class Student{
	int rollno;
	char name [30];
	char division[5];
	char address[50];

	public :
		void accept();
		void display();
		int rollno(){
			return rollno;
		}
};

void Student::accept(){
	cout<<"Enter roll no:";
	cin>>rollno;

	cout<<<"Enter the name:";
	cin.ignore();
	cin.getline(name,30);

	cout<<"Enter Division:";
	cin>>division;

	cout<<"Enter the address:";
	cin.ignore();
	cin.getline(address,50);

	cout<<"\n";
}

void Student::display(){
	cout<<"\n"<<rollno<<"\t"<<name<<"\t"<<division<<"\t"<<address;
}

void create(){
	Student s;
	int n , i;
	ofstream out("Student.txt");
	cout<<"Enter No. of records wants:";
	cin>>n;
	for(i=0;i<n;i++){
		s.accept();
		out.write((char *)&s, sizeof(s));
	}
	out.close();
}

void display(){
	Student s ;
	ifstream infile("Student.txt");
	while(infile.read((char *)&s , sizeof(s))){
		s.display();
	}
	infile.close();
}

void search{
	int n , flag =0;
	cout<<"Enter the roll number to search:";
	cin>>n;
	ifstream infile("Student.txt");
	Student s;
	while(infile.read((char *)&s , sizeof(s))){
		if(s.rollno == n ){
			flag =1 ;
			cout<<"Record found ";
			cout<<"\nRollno        Name            division          Address";
			s.display();
			break;
		}
	}
	if(flag==0){
		cout<<"record not found.";
	}
	infile.close();
}


int main (){
	int ch;

	do {
		cout<<"\n1. Create";
		cout<<"\n2. display";
		cout<<"\n3. Search";
		cout<<"\nEnter your choice:";
		cin>>ch;

		switch (ch)
		{
		case 1:
			create();
			break;

		case 2:
			cout<<"\nRoll Number          Name                      Division         Address";
			display();
			break;

		case 3:
			search();
			break;
		
		default:
			break;
		}

	}while(ch!=4);
	return 0;
*/