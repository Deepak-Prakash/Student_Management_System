#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<conio.h>

using namespace std;

 
 
class student
{
    //int ind;
	int idnum;
	char name[50];
    int age;
    char phone[50],address[50];
    int sem;
    char branch[50];
	int S1, S2, S3, S4, S5,S6,S7,S8;
    int c1,c2,c3,c4,c5,c6,c7,c8;
    int g1,g2,g3,g4,g5,g6,g7,g8;
    float gpa;
	//double per;
	//char grade;
	int calculate(int x);
    void calgpa();	
public:
	void getdata();		
	void showdata() const;	
	void show_tabular() const;
	int getIDNum() const;
}; 
 
 
int student::calculate(int x)
{
	//per=(S1+S2+S3+S4+S5)/5.0;
    //int per=x;
    int grade;
	if(x>=90)
		grade=10;
	else if(x>=80)
		grade=9;
	else if(x>=70)
		grade=8;
	else if(x>=60)
		grade=7;
	else if(x>=50)
		grade=6;
	else if(x>=45)
		grade=5;
    else if(x>=40)
		grade=4;
	else
		grade=0;
    //cout<<grade<<"\t";
    return grade;
}
 
void student::calgpa()
{
    float totcredit,total;
    g1=calculate(S1);
    g2=calculate(S2);
    g3=calculate(S3);
    g4=calculate(S4);
    g5=calculate(S5);
    g6=calculate(S6);
    g7=calculate(S7);
    g8=calculate(S8);
    totcredit=c1+c2+c3+c4+c5+c6+c7+c8;
    total=c1*g1+c2*g2+c3*g3+c4*g4+c5*g5+c6*g6+c7*g7+c8*g8;
    //cout<<totcredit<<"  "<<total<<endl;
    gpa=total/totcredit;
    //cout<<gpa<<endl;
    
}

void student::getdata()
{
	cout<<"\nEnter The USN of the student ";
	cin>>idnum;
	cout<<"\n\nEnter student's Name: ";
	cin.ignore();
	cin.getline(name,50);
    //gets(name);
    cout<<"\n\nEnter student's Age: ";
	cin>>age;
    cout<<"\n\nEnter student's Phone: ";
	cin.ignore();
	cin.getline(phone,50);
    cout<<"\n\nEnter student's Address: ";
	// cin.ignore();
	// cin.getline(address,50);
	gets(address);
    cout<<"\n\nEnter student's Semester: ";
	cin>>sem;
    cout<<"\n\nEnter student's Branch: ";
	cin.ignore();
	cin.getline(branch,50);
	cout<<"\nEnter student's S1 marks and credit: ";
	cin>>S1>>c1;
	cout<<"\nEnter student's S2 marks and credit: ";
	cin>>S2>>c2;
	cout<<"\nEnter student's S3 marks and credit: ";
	cin>>S3>>c3;
	cout<<"\nEnter student's S4 marks and credit: ";
	cin>>S4>>c4;
	cout<<"\nEnter student's S5 marks and credit: ";
	cin>>S5>>c5;
    cout<<"\nEnter student's S6 marks and credit: ";
	cin>>S6>>c6;
    cout<<"\nEnter student's S7 marks and credit: ";
	cin>>S7>>c7;
    cout<<"\nEnter student's S8 marks and credit: ";
	cin>>S8>>c8;
	//calculate();
    calgpa();
}
 
void student::showdata() const
{
	cout<<"\nUSN: "<<idnum;
	cout<<"\nName: "<<name;
    cout<<"\nAge: "<<age;
    cout<<"\nPhone: "<<phone;
    cout<<"\nAddress: "<<address;
    cout<<"\nSemester: "<<sem;
    cout<<"\nBranch: "<<branch;
	cout<<"\nS1: "<<S1;
	cout<<"\nS2: "<<S2;
	cout<<"\nS3: "<<S3;
	cout<<"\nS4: "<<S4;
	cout<<"\nS5: "<<S5;
    cout<<"\nS6: "<<S6;
    cout<<"\nS7: "<<S7;
    cout<<"\nS8: "<<S8;
	cout<<"\nGPA: "<<gpa;
	//cout<<"\nLetter Grade: "<<grade;
}
 
void student::show_tabular() const
{
	cout<<idnum<<setw(7)<<" "<<name<<setw(13)<<age<<setw(5)<<sem<<setw(5)<<branch<<setw(7)<<S1<<setw(4)<<S2<<setw(4)<<S3<<setw(4)
		<<S4<<setw(4)<<S5<<setw(4)<<S6<<setw(4)<<S7<<setw(4)<<S8<<setw(4)<<setw(8)<<gpa<<endl;
}
 
int  student::getIDNum() const
{
	return idnum;
}
 
 
 
void SaveStudent();	
void displayAll();	
void Searchdisplay(int);	
void modifyStudent(int);	
void deleteStudent(int);	
void DisplayClassResult();	
void DisplayResult();			
void control();
void login(int x);
void stuview();
void adminview();

 
 
 
 
void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
    	cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}
 
 
 
void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}
 
 
 
void display_sp(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.getIDNum()==n)
		{
	  		 st.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}
 
 
void modify_student(int n)
{
	bool found=false;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
    	while(!File.eof() && found==false)
	{
 
		File.read(reinterpret_cast<char *> (&st), sizeof(student));
		if(st.getIDNum()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata();
		    	int pos=(-1)*static_cast<int>(sizeof(st));
		    	File.seekp(pos,ios::cur);
		    	File.write(reinterpret_cast<char *> (&st), sizeof(student));
		    	cout<<"\n\n\t Record Updated";
		    	found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();
}
 
 
 
void delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.getIDNum()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}
 
 
void class_result()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"================================================================================\n";
	cout<<"USN        Name          Age  Sem  Branch  S1  S2  S3  S4  S5  S6  S7  S8    GPA"<<endl;
	cout<<"================================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.show_tabular();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}
 
void adminview()
{
    char ch;
	int num;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); 
	do
	{
	system("cls");
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6. DISPLAY CLASS RESULT";
	cout<<"\n\n\t7. EXIT";
	cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\n\tPlease Enter Your Choice (1-7): ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter Student's USN: "; cin>>num;
				display_sp(num); break;
	case '4':	cout<<"\n\n\tPlease Enter Student's USN: "; cin>>num;
			modify_student(num);break;
	case '5':	cout<<"\n\n\tPlease Enter Student's USN: "; cin>>num;
			delete_student(num);break;
	case '6' :	class_result(); break;
	case '7':	control();
	default:	cout<<"\a"; 
		
    }
	}while(1);
}

void stuview()
{
    int num;
    cout<<"\n\n\tPlease Enter Student's USN: "; cin>>num;
		display_sp(num);
}

void control()
{
    int ch;
	system("cls");
    do{
    system("cls");
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
    cout<<"\n\n\t1.ADMIN";
	cout<<"\n\n\t2.STUDENT";
    cout<<"\n\n\t3.EXIT";
    cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\n\tPlease Enter Your Choice (1-3): ";
	cin>>ch;
    if(ch==1 || ch==2)
        login(ch);
    else if(ch==3)
        exit(0);
    else
    {
        cout<<"\nInvalid Choice\n\n";
        getch();
    }
    }while(1);


}

void login(int x)
{
    char c,pass[20];
    char set[20]="admin123";
    if(x==1)
    {
        system("cls");
        cout<<"\n\n\tENTER ADMIN PASSWORD\n";
        //c=getch();
        //cout<<"\b*";
        cin.ignore();
	    cin.getline(pass,20);
        //if(pass==set)
        if(!strcmp(pass,set))
            adminview();
        else{
            cout<<"\n\n\tPassword Incorrect"<<endl;
            getch();
            control();
        }

    }
    else
        stuview();
}

int main()
{
    // ofstream outFile;
	// outFile.open("student.dat",ios::binary|ios::trunc);
    // outFile.close();
	control();
    
	return 0;
}