#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>  
#include<fstream>    
#include<ctime>    
#include<stdlib.h>
#include<windows.h>          // USE THIS FOR SLEEP FUNCTON TO MAKE LOADING PROCESS HELP TAKEN FROM INTERNET
using namespace std;
int i = 0;                   // global i for struct array 
struct studentInfo {

	char firstName[13];
	char lastName[13];
	string fatherName;
	char email[30];
	int session;
	int enrollment;
	char gender;
	char phoneNumber[12];
	char password[5];

}myArray[50];               // struct array to store information of students

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^1^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void menu();
void adminView();
void addStudent(studentInfo myArray);
void studentSigin();
void searchStudent();
void displayInformation(int);
void editProfile(int j);
string gradesCalculation(int);
string finalGrade(int);
void generateReport();
void courseDetails();

int main()
{

	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t   LOADING ";
	char x = 219;                    // this is Ascii value equal to "ALT KEY"
	for (int i = 0; i < 40; i++)
	{

		cout << x;
		Sleep(100);                 //suspends the execution of the program for a specified period of time 
	}
	cout << " COMPLETED 100 % " << endl;

	cout << "\n\t\t=======================WELOME TO STUDENT MANGEMENT SYSTEM========================" << endl;
	cout << endl;

	menu();


	_getch();
	return 0;
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^2^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void addStudent(studentInfo myArray[])
{

	cout << "----------------------------------------------" << endl;
	cout << "\tADD STUDENT INFORMATION" << endl;
	cout << "----------------------------------------------" << endl;

	ofstream myFile;
	myFile.open("Example.txt", ios::app);

	cout << " Enter The Enrollment Number of The Student :";
	cin >> myArray[i].enrollment;

	myFile << myArray[i].enrollment << "\t\t";

	cout << "\n Enter The First Name of The Student :";
	cin >> myArray[i].firstName;
	myFile << myArray[i].firstName << "  ";

	cout << "\n Enter The Last Name of The Student :";
	cin >> myArray[i].lastName;
	myFile << myArray[i].lastName << "\t\t";

	cout << "\n Enter The Father Name of The Student :";
	cin.ignore();               //When cin.getline() reads from the input, there is a newline character left in the input stream, so it doesn't read your c-string. Use cin.ignore() before calling getline(). THIS HELP IS TAKEN FROM INTERNET
	getline(cin, myArray[i].fatherName);


	cout << "\n Enter Gender of The Student :";
	cin >> myArray[i].gender;
	myFile << myArray[i].gender << "\t\t  ";

	cout << "\n Enter Session/Year of The Student:";
	cin >> myArray[i].session;
	myFile << myArray[i].session << "\t\t";

	cout << "\n Enter A Valid Phone Numeber of The Student:";
	cin >> myArray[i].phoneNumber;
	myFile << myArray[i].phoneNumber << endl;

	myFile.close();
	cout << "\n Enter A Valid Email Address of The Student: ";
	cin >> myArray[i].email;

	cout << "\n Enter A 4-Digit Password For Student: ";
	char pin1[5];

	for (int k = 0; k < 4; k++)
	{
		pin1[k] = _getch();   // ignores the enter key
		cout << "*";
	}
	pin1[4] = '\0';
	strcpy_s(myArray[i].password, pin1);

	system("cls");

	cout << "\n\tSTUDENT ADDED SUCCESSFULLY";
	i++;
	// incrementation of struct array by 1 when each student registerd

	char ch;
	cout << "\n\n\tDo you want to add more (y/n)" << endl;
	cin >> ch;
	switch (ch)
	{
	case 'Y':
	case 'y':
		system("cls");
		addStudent(myArray);  // calls the struct array
		break;

	case'n':
	case'N':
		system("cls");
		break;
	}

}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

void menu()
{




	while (1)
	{
		cout << "\n\t\t\t\t\tWHAT DO YOU WANT TO DO " << endl;
		cout << "\n\t\tFor Register Student: Press 1" << setw(40) << "For Admin LogIn: Press 2" << endl;
		cout << "\t\tFor Student LogIn: Press 3 " << setw(44) << "For Search Student:Press 4" << endl;
		cout << "\t\tFor Exit :Press 5" << endl;
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			system("cls");
			addStudent(myArray);


		}
		if (choice == 2)
		{
			system("cls");
			adminView();

		}
		if (choice == 3)
		{
			system("cls");
			studentSigin();

		}
		if (choice == 4)
		{
			system("cls");
			searchStudent();

		}
		if (choice == 5)
		{
			system("cls");
			exit(0);
		}

	}

}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

void adminView()
{
	cout << "\n\t\t======================WELOME TO ADMIN PORTAL=======================\n" << endl;
	char pin[5];
	int count1 = 0;
	do {
		count1++;
		cout << "\nEnter Your Pin : " << endl;
		for (int i = 0; i < 4; i++)
		{
			pin[i] = _getch();
			cout << "*";
		}
		pin[4] = '\0';

		if (count1 > 4)
		{
			cout << " \nTOO MANY WRONG ATTEMPTS LOGIN AGAIN!!" << endl;
			menu();
		}

	} while (strcmp(pin, "1234") != 0);

	if (!strcmp(pin, "1234"))
	{
		ifstream readFile;
		readFile.open("Example.txt", ios::in);

		cout << endl << "Your are A valid user" << endl;
		cout << "====================================================================================================" << endl;
		cout << "Enrollement\t  Name\t\t\tgender\t\tsession\t\tPhone Number" << endl;
		cout << "====================================================================================================" << endl;



		while (!readFile.eof())   //read all data from file
		{
			readFile >> myArray[i].enrollment;
			cout << myArray[i].enrollment << "\t\t";

			readFile >> myArray[i].firstName;
			cout << myArray[i].firstName << " ";

			readFile >> myArray[i].lastName;
			cout << myArray[i].lastName << "\t\t";

			readFile >> myArray[i].gender;
			cout << myArray[i].gender << "\t\t";

			readFile >> myArray[i].session;
			cout << myArray[i].session << "\t\t";

			readFile >> myArray[i].phoneNumber;
			cout << myArray[i].phoneNumber << "\n";


			cout << endl;
		}
		readFile.close();

		cout << "\n====================================================================================================" << endl;
	}
	else
		cout << endl << "Your are NOT A valid user : " << endl;


}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
void displayInformation(int j)
{
	cout << "\n\t\t\t***********Personal profile***********\n" << endl;
	cout << "\t\t\tNAME :\t\t" << myArray[j].firstName << " " << myArray[j].lastName << endl;
	cout << "\t\t\tFATHER NAME:\t" << myArray[j].fatherName << endl;
	cout << "\t\t\tENROLLMENT NO:\t" << myArray[j].enrollment << endl;
	cout << "\t\t\tGENDER:\t\t" << myArray[j].gender << endl;
	cout << "\t\t\tSESSION:\t" << myArray[j].session << endl;
	cout << "\t\t\tPHONE NUMBER:\t" << myArray[j].phoneNumber << endl;
	cout << "\t\t\tEmail :\t\t" << myArray[j].email << endl;
	cout << "\n\t\t\t***********************************\n" << endl;

}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

void editProfile(int j)
{
	int choice;
	cout << "\t\t======================EDIT PROFILE MENU===================" << endl;
	cout << " \n\t\tWelcome to Edit menu here you can change following\n";
	cout << "\n Press 1 for Your First Name\n Press 2 for Your Last Name\n Press 3 for Father Name\n";
	cout << " Press 4 for Session\n Press 5 for Phone Number\n Press 6 for Email address\n Press 7 For Password" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << " Enter new First Name : ";
		cin >> myArray[j].firstName;
		break;
	case 2:
		cout << " Enter new Last Name : ";
		cin >> myArray[j].lastName;
		break;
	case 3:
		cout << " Enter new Father Name : ";
		cin.ignore();
		getline(cin, myArray[j].fatherName);
		break;
	case 4:
		cout << " Enter new session : ";
		cin >> myArray[j].session;
		break;
	case 5:
		cout << " Enter new Phone No :";
		cin >> myArray[j].phoneNumber;
		break;
	case 6:
		cout << " Enter new Valid Email Address :";
		cin >> myArray[j].email;
		break;//     ^^^^^^^^^^^^^^^     //
	case 7:
		cout << "Enter New Password :";
		cin >> myArray[j].password;
		break;
	}
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

void studentSigin()
{
	int random2;
	int random;
	int count = 0;
	int check = 0;
	int enrollment1;
	cout << " Enter your Enrollment No and Password for Login \n\n Enrollment NO :";
	cin >> enrollment1;
	for (int j = 0; j < i; j++)
	{
		if (enrollment1 == myArray[j].enrollment)
		{
			check++;                 // check enrollment is present in struct array
			char pin[5];
			do {
				count++;
				cout << "\n Password :";
				for (int i = 0; i < 4; i++)
				{
					pin[i] = _getch();   // with getch pin is not shown own console 
					cout << "*";
				}
				pin[4] = '\0';

				if (count > 4)    //if password is enter wrong for 5 times it has option to reset it
				{
					int ch;
					char email[30];
					cout << "\n\t\t TOO MANT WRONG ATTEMTS RESET PASSWORD!!" << endl;
					cout << "\n To Reset Your Password By Email: Press 1 \n To Reset Your Password By Phone Number: Press 2" << endl;
					cin >> ch;

					if (ch == 1)
					{
						cout << "Enter Your Email Address" << endl; //reset password by email
						cin.ignore();  //
						cin.getline(email, 30);
						if (!strcmp(myArray[j].email, email))
						{
							srand(time(0));

							random = rand() % 99999;   //generate  5-digit random number
							cout << "\t\tHERE IS THE CODE :" << random;


							do
							{
								cout << "\nEnter code which we sent to You Via-Email ";
								cin >> random2;

								if (random2 == random)
								{
									char ch4;
									cout << "Enter Your new password :";
									cin >> myArray[j].password;

									cout << "\n PASSWORD CHANGED SUCCESSFULLY" << endl;
									cout << "\n Do You want to SigIn Again (y/n)" << endl;

									cin >> ch4;

									switch (ch4)
									{
									case 'y':
									case'Y':
										system("cls");
										studentSigin();
										break;

									case'N':
									case'n':
										break;

									default:
										cout << "Invalid Entry" << endl;
									}

								}
								else {

									cout << "\t\tTry Again!!";
								}

							} while (random2 != random);
						}
						else
							cout << "\n\tINVALID E-MAIL ADDRESS!";

						menu();

					}
					else if (ch == 2)
					{
						char phone2[15];
						cout << " Enter Your Phone Number" << endl;  // reset by phone number
						cin >> phone2;
						if (!strcmp(myArray[j].phoneNumber, phone2))
						{
							srand(time(0));

							random = rand() % 99999;
							cout << "\t\tHERE IS THE CODE :" << random;
							do
							{
								cout << "\nEnter code which we sent to You Via-Text Message ";
								cin >> random2;
								if (random2 == random)
								{
									char ch4;
									cout << "\t\tEnter Your new password :";
									cin >> myArray[j].password;

									cout << "\n PASSWORD CHANGED SUCCESSFULLY" << endl;
									cout << "\n Do You want to SigIn Again (y/n)" << endl;
									cin >> ch4;

									switch (ch4)
									{
									case 'y':
									case'Y':
										system("cls");
										studentSigin();
										break;

									case'N':
									case'n':
										break;

									default:
										cout << "Invalid Entry" << endl;
									}
								}
								else {

									cout << "\t\tTry Again!!";
								}
							} while (random2 != random);

						}
						else
							cout << "\n\tINVALID PHONE NUMBER!";
						menu();
					}
				}

			} while ((strcmp(myArray[j].password, pin) != 0));


			if ((!strcmp(myArray[j].password, pin)) || (myArray[j].password))
			{
				system("cls");
				cout << "\n\t\t======================WELOME TO STUDENT PORTAL=======================\n" << endl;

				cout << "\t\t\tPASSWORD:\t\t" << myArray[j].password << endl;
				displayInformation(j);  // calls the function to display personal information 
				while (1)
				{
					int ch;

					cout << "\n\t\t===================AVAILABLE OPERATIONS===================" << endl;

					cout << "\n\t For Geneate Report:\tPress 1\n\t For Registered Courses:Press 2" << endl;
					cout << "\t For Edit Profile:\tPress 3\n\t For Main Menu:\t\tPress 4 " << endl;


					cin >> ch;
					if (ch == 1)
					{
						system("cls");
						generateReport();

					}
					if (ch == 2)
					{
						system("cls");
						courseDetails();
					}
					if (ch == 3)
					{
						system("cls");
						editProfile(j);

						char ch4;

						cout << " UPDATED SUCCESFULLY SIGN IN AGAIN TO SEE THE RESULT " << endl;
						cout << "\n Do You want to SigIn Again (y/n)" << endl;
						cin >> ch4;

						system("cls");

						switch (ch4)
						{
						case 'y':
						case'Y':
							studentSigin();
							break;

						case'N':
						case'n':
							break;

						default:
							cout << "Invalid Entry" << endl;
						}



					}
					if (ch == 4)
					{
						system("cls");
						menu();

					}

				}
			}

		}

	}

	if (check == 0)   // if enrollment is incorrect or data is not exist
	{
		system("cls");
		int ch3;
		cout << "\n\t\t****!! Not found !!****\n \tFirst Resgistered yourself Or Enrollment is Incorrect" << endl;
		cout << "\n For register :Press 1\n For Checking the Register Students :Press 2" << endl;
		cin >> ch3;
		if (ch3 == 1)
		{
			system("cls");
			addStudent(myArray);
		}
		if (ch3 == 2)     // see the enrollments of enrolled students
		{
			system("cls");
			cout << "\t\t============================================" << endl;
			cout << "\t\tEnrollments\t\tName\n";
			cout << "\t\t============================================" << endl;
			int j = 0;
			while (j < i)
			{

				cout << "\t\t" << myArray[j].enrollment << "\t\t" << myArray[j].firstName << " " << myArray[j].lastName << endl;
				j++;
			}
			cout << "\t\t============================================" << endl;
			char ch4;
			cout << "Do You Want to SigIn Again (y/n)" << endl;
			cin >> ch4;

			system("cls");

			switch (ch4)
			{
			case 'y':
			case'Y':
				studentSigin();
				break;
			case'N':
			case'n':
				menu();
				break;
			default:
				cout << "Invalid Entry" << endl;
			}
		}

	}
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

void searchStudent()
{
	cout << "\n\t\t======================WELOME TO SEARCH MENU=======================\n" << endl;
	int check1 = 0;
	int choice5;
	cout << " Press 1 to Search by First Name\n Press 2 to Search by Last Name\n Press 3 to Search by Enrollment Number\n";
	cin >> choice5;
	if (choice5 == 1)
	{
		string fname;
		cout << "\nEnter First Name of student :";
		cin >> fname;

		for (int j = 0; j <= i; j++)
		{

			if (fname.compare(myArray[j].firstName) == 0)
			{
				check1++;                     // check for student exist in array of struct or not
				displayInformation(j);
			}

		}
		if (check1 == 0)   // if not found in the then this works
		{
			char ch2;
			cout << " Not found First Resgistered Yourself " << endl;
			cout << "\n\t\tDo You want to Registern Yourself (y/n)" << endl;
			cin >> ch2;
			switch (ch2) {
			case 'y':
			case'Y':
				addStudent(myArray);
				break;
			case'N':
			case'n':
				menu();
				break;
			default:
				cout << "Invalid Entry" << endl;
			}
		}
	}
	else if (choice5 == 2)
	{
		string lname;
		cout << "\nEnter Last Name of student :";
		cin >> lname;

		for (int j = 0; j <= i; j++)
		{

			if (lname.compare(myArray[j].lastName) == 0)
			{
				check1++;
				displayInformation(j);
			}

		}
		if (check1 == 0)
		{
			char ch2;
			cout << " Not found First Resgistered Yourself " << endl;
			cout << "\n\t\tDo You want to Registern Yourself (y/n)" << endl;
			cin >> ch2;
			switch (ch2)
			{
			case 'y':
			case'Y':
				addStudent(myArray);
				break;

			case'N':
			case'n':
				menu();
				break;

			default:
				cout << "Invalid Entry" << endl;
			}
		}
	}
	else	if (choice5 == 3)
	{
		int check2;
		int enrollment2;
		cout << " \nEnter Enrollment Number of Student :";
		cin >> enrollment2;
		for (int j = 0; j <= i; j++)
		{

			if (enrollment2 == myArray[j].enrollment)
			{
				check1++;
				displayInformation(j);

			}
		}
		if (check1 == 0)
		{
			cout << " \n\t\t ****!! Not found !!****\n \t\tFirst Resgistered yourself" << endl;

			cout << "\n\t Do You want to Registern Yourself (y/n)" << endl;
			char ch3;


			cin >> ch3;
			switch (ch3)
			{
			case 'y':
			case'Y':
				addStudent(myArray);
				break;

			case'N':
			case'n':
				menu();
				break;

			default:
				cout << "Invalid Entry" << endl;
			}
		}
	}

}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

string gradesCalculation(int marks)
{
	string grade;
	if (marks >= 85 && marks <= 100)
	{
		grade = "A";
	}
	else if (marks >= 80 && marks <= 84)
	{
		grade = "A-";
	}
	else if (marks >= 75 && marks <= 79)
	{
		grade = "B+";
	}
	else if (marks >= 71 && marks <= 74)
	{
		grade = "B";
	}
	else if (marks >= 68 && marks <= 70)
	{
		grade = "B-";
	}
	else if (marks >= 64 && marks <= 67)
	{
		grade = "C+";
	}
	else if (marks >= 60 && marks <= 63)
	{
		grade = "C";
	}
	else if (marks >= 57 && marks <= 59)
	{
		grade = "C-";
	}
	else if (marks >= 53 && marks <= 56)
	{
		grade = "D+";
	}
	else if (marks >= 50 && marks <= 52)
	{
		grade = "D";
	}
	else if (marks < 50)
	{
		grade = "F";
	}
	return grade;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

string finalGrade(int gpa)
{
	string grade1;
	if (gpa <= 4 && gpa >= 3.67)
	{
		grade1 = "A";
	}
	else if (gpa < 3.67 && gpa >= 3.33)
	{
		grade1 = "A-";
	}
	else if (gpa < 3.33 && gpa >= 3)
	{
		grade1 = "B+";
	}
	else if (gpa < 3 && gpa >= 2.67)
	{
		grade1 = "B";
	}
	else if (gpa < 2.67 && gpa >= 2.33)
	{
		grade1 = "B-";
	}
	else if (gpa < 2.33 && gpa >= 2)
	{
		grade1 = "C+";
	}
	else if (gpa < 2 && gpa >= 1.87)
	{
		grade1 = "C";
	}
	else if (gpa < 1.87 && gpa >= 1.33)
	{
		grade1 = "C-";
	}
	else if (gpa < 1.33 && gpa >= 1)
	{
		grade1 = "D";
	}
	else if (gpa < 1)
	{
		grade1 = "F";
	}
	return grade1;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

void generateReport()
{
	cout << "\n\t\t======================WELOME TO REPORT GENERATION MENU=======================\n" << endl;
	float finalGpa;
	float sum = 0.0;
	float gpa;
	string grade;
	int creditHour[34];
	float totalCredit = 0.0;
	int number;
	cout << "Enter number of subjects :";
	cin >> number;
	int* myMarks = new int[number];
	string* myGrades = new string[number];   //dynamic string for tabular view because one grade may contain 2 char e.g A+ so if we don;t use this it can disturb our tabular view
	for (int i = 0; i < number; i++)
	{
		cout << "\nEnter Marks of Subject " << i + 1 << ": ";
		cin >> myMarks[i];
		myGrades[i] = gradesCalculation(myMarks[i]);
		cout << "Enter the credit hour of subject " << i + 1 << ": ";
		cin >> creditHour[i];
		totalCredit = totalCredit + creditHour[i];
	}
	system("cls");

	cout << "\n\n\TOTAL CREDIT HOURS YOU STUDIED THIS SEMESTER ARE:" << totalCredit << endl;

	for (int i = 0; i < number; i++)
	{
		grade = myGrades[i];

		if (grade[0] == 'A')
		{
			gpa = 4 * creditHour[i];
			sum = sum + gpa;
		}
		else if (grade[0] == 'A' && grade[1] == '-')
		{
			gpa = 3.67 * creditHour[i];
			sum = sum + gpa;
		}
		else if (grade[0] == 'B' && grade[1] == '+')
		{
			gpa = 3.33 * creditHour[i];
			sum = sum + gpa;
		}
		else if (grade[0] == 'B')
		{
			gpa = 3.0 * creditHour[i];
			sum = sum + gpa;
		}
		else if (grade[0] == 'B' && grade[1] == '-')
		{
			gpa = 2.67 * creditHour[i];
			sum = sum + gpa;
		}
		else if (grade[0] == 'C' && grade[1] == '+')
		{
			gpa = 2.33 * creditHour[i];
			sum = sum + gpa;
		}
		else if (grade[0] == 'C')
		{
			gpa = 2.0 * creditHour[i];
			sum = sum + gpa;
		}
		else if (grade[0] == 'C' && grade[1] == '-')
		{
			gpa = 1.87 * creditHour[i];
			sum = sum + gpa;
		}
		else if (grade[0] == 'D' && grade[1] == '+')
		{
			gpa = 1.33 * creditHour[i];
			sum = sum + gpa;
		}
		else if (grade[0] == 'D')
		{
			gpa = 1.0 * creditHour[i];
			sum = sum + gpa;
		}
		else if (grade[0] == 'F')
		{
			gpa = 0.0 * creditHour[i];
			sum = sum + gpa;
		}


	}

	finalGpa = (sum / totalCredit);

	cout << "\n\t\t\t**********!!!YOUR REPORT!!!**********" << endl;

	cout << "\n\t======================================================================" << endl;
	cout << "  \t\tMarks\t\tGrades\t\tCredit Hours" << endl;
	cout << "\t======================================================================" << endl;

	for (int i = 0; i < number; i++)
	{
		cout << " \t\t" << myMarks[i] << "\t\t" << myGrades[i] << "\t\t" << creditHour[i] << endl;
	}
	cout << "\t======================================================================" << endl;

	cout << "\n\tYour GPA according to your marks is :\t" << finalGpa << "\tGrade is:" << finalGrade(finalGpa) << endl;

}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

void courseDetails()
{

	string field;
	cout << "Enter the field name [computer science , Mechanical, Electricals,civil]: " << endl;

	cin.ignore();   //When cin.getline() reads from the input, there is a newline character left in the input stream, so it doesn't read your c-string. Use cin.ignore() before calling getline(). THIS HELP IS TAKEN FROM INTERNET
	getline(cin, field);

	if (field == "computer science" || field == "computer science")

	{
		int choice4;
		cout << "Registerd Courses  According to Your Semester\nEnter Your Semester:";

		cin >> choice4;
		switch (choice4)
		{
		case 1:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 1\n \tCalculas \n\tComputer Programming\n\tPhysics\n\tEnglish\n\tLabs" << endl;
			break;
		case 2:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 2\n\tMachine learning\n\tAlgorithms\n\tStatistics\n\tWeb development" << endl;
			break;
		case 3:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 3\n\tProbability and Statistics\n\tMultivariable  Calculus\n\tComputer Organization& Assembly Language\n\tData Structures and Algorithms" << endl;
			break;
		case 4:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 4\n\tDatabase Management Systems\n\tData Communication and Networking\n\tTheory of Automata\n\tDifferential Equations" << endl;
			break;
		case 5:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 5\n\tOperating Systems\n\tSoftware Engineering\n\tCompiler Construction\n\tDesign and Analysis of Algorithms\n\tIslamic Studies/Ethics" << endl;
			break;
		case 6:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 6\n\tInternship" << endl;
			break;
		case 7:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 7\n\tProject   l\n\tParallel & Distributed Computing\n\tPakistan Studies\n\tUniversity  Elective   III\n\tElective 3 (3+0 or 2+1)\n\tElective 4 (3+0 or 2+1)" << endl;
			break;
		case 8:
			cout << "Course outline of Semester 8\n\tProject   II\n\tInformation  Security\n\tUniversity  Elective   IVs\n\tWeb Engineering\n\tWeb Engineering Lab\n\tDigital Image Processing" << endl;
			break;
		default:
			cout << "Invalid Entry";
		}

	}



	else if (field == "civil" || field == "Civil")

	{
		int choice4;
		cout << "Registerd Courses  According to Your Semester\nEnter Your Semester:";
		cin >> choice4;
		switch (choice4)
		{
		case 1:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 1 \n\tHydraulics\n\tSolid Mechanics\n\tBreadth I\n\tMathematics III\n\tAlgorithms\n\tStatistics\n\tWeb development" << endl;
			break;
		case 2:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 2\n\tStructural Analysis\n\tWater Resources Engineering\n\tSurveying I\n\tSurveying II\n\tData Communication and Networking\n\tTheory of Automata\n\tDifferentialEquations" << endl;
			break;
		case 3:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 3\n\tOperating Systems\n\tSoftware Engineering\n\tCompiler Construction\n\tDesign and Analysis of Algorithms\n\tIslamic Studies/Ethics" << endl;
			break;
		case 4:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 4\n\tMechanics of Materials\n\tFluid Mechanics-me\n\tEngineering Geology\n\tSurveying II\n\tWeb Engineering\n\tWebEngineering Lab\n\tDigital Image Processing" << endl;
			break;
		case 5:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 5 \n\tPhysics\n\tEnvironmental science\n\tComputer programming \n\tChemistry I\n\tBasic of computer programming" << endl;
			break;
		case 6:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 6\n\tInternship" << endl;
			break;
		case 7:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 7\n\tMathematics\n\tBasic electrical Engineering\n\tChemistry I\n\tBasic of computer programming" << endl;
			break;
		case 8:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 8\n\tApplied Thermodynamics - I\n\tMachine Design\n\tMechanical Measurements\n\tHeat and Mass Transfer" << endl;
			break;
		default:
			cout << "Invalid Entry " << endl;

		}
	}



	else if (field == "Electricals" || field == "electricals")

	{
		int choice4;
		cout << "Registerd Courses  According to Your Semester\nEnter Your Semester:";
		cin >> choice4;
		switch (choice4)
		{
		case 1:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 1 \n\tPhysics\n\tEnvironmental science\n\tComputer programming \n\tTechnical English" << endl;
			break;
		case 2:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 2\n \tCalculas \n\tProgramming\n\tPhysics\n\tEnglish\n\tComputer Organization& Assembly Language\n\tData Structures and Algorithms" << endl;
			break;
		case 3:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 3\n\tDatabase Management Systems\n\tData Communication and Networking\n\tTheory of Automata\n\tDifferential Equations" << endl;
			break;
		case 4:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 4\n\tMathematics\n\tBasic electrical Engineering\n\tChemistry I\n\tMechanical Measurements\n\tHeat and Mass Transfer" << endl;
			break;
		case 5:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 5\n\tApplied Thermodynamics - I\n\tMachine Design\n\tMechanical Measurements\n\tHeat and Mass Transfer" << endl;
			break;
		case 6:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 6\n\tApplied Thermodynamics - I\n\tMachine Design\n\tMechanical Measurements\n\tHeat and Mass Transfer" << endl;
			break;
		case 7:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 7\n\tInternship" << endl;
			break;
		case 8:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 8\n\tProject   l\n\tParallel & Distributed Computing\n\tPakistan Studies\n\tUniversity  Elective   III\n\tDynamics of Machinery\n\tDesign of Machine Elements" << endl;
		default:
			cout << "Invalid Entry " << endl;
		}
	}


	else if (field == "Mechanical" || field == "mechanical")

	{
		int choice4;
		cout << "Registerd Courses  According to Your Semester\nEnter Your Semester:";
		cin >> choice4;
		switch (choice4)
		{
		case 1:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 1\n\tFluid Mechanics - II\n\tManufacturing Technology - II\n\tDynamics of Machinery\n\tDesign of Machine Elements" << endl;
			break;
		case 2:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 2\n\tHydraulics\n\tSolid Mechanics\n\tBreadth I\n\tMathematics III\n\tAlgorithms\n\tStatistics\n\tWeb development" << endl;
			break;
		case 3:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 3\n\tMathematics\n\tBasic electrical Engineering\n\tChemistry I\n\tDesign and Analysis of Algorithms\n\tIslamic Studies/Ethics" << endl;
			break;
		case 4:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 4\n\tApplied Thermodynamics - I\n\tMachine Design\n\tMechanical Measurements\n\tHeat and Mass Transfer" << endl;
			break;
		case 5:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 5\n\tMathematics\n\tBasic electrical Engineering\n\tChemistry I\n\tMechanical Measurements\n\tHeat and Mass Transfer" << endl;
			break;
		case 6:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 6\n\tInternship" << endl;
			break;
		case 7:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 7\n\tPhysics\n\tEnvironmental science\n\tComputer programming n\tData Communication and Networking\n\tTheory of Automata\n\tDifferential Equations" << endl;
			break;
		case 8:
			cout << "---------------------------" << endl;
			cout << "Course outline of Semester 8\n\tProject   l\n\tParallel & Distributed Computing\n\tPakistan Studies\n\tUniversity  Elective   III\n\tElective 3 (3+0 or 2+1)\n\tElective 4 (3+0 or 2+1)" << endl;
			break;
		default:
			cout << "Invalid Entry " << endl;
		}
	}
	else
	{
		cout << "The entered field is wrong";
	}

}



