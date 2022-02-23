
//====================================================================================
// Name        : Final Project 2.cpp
// Author      : Tiffany Gomez
// Version     : 1.0
// Date        : 02-18-2022
// Description : Project 2: This program uses a Binary Search Tree to hold
//                          ABCU courses from a csv data file. Advisors have
//                          the option to load their file of choice, print a
//                          course list that has been sorted in alphanumerical 
//							order a course list, and search and (if found) the
//                          course using its course Id. Additionally, for each
//                          course found, the prerequisites for each course 
//                          (if any) will be listed.
//====================================================================================
#include "BinarySearchTreeProjectTwo.h"

int main() {
	// Define a binary search tree to hold all courses
	BinarySearchTree* bst;
	bst = new BinarySearchTree();
	Course course;
	
	// Declare variables
	string searchCourse;			// course name of user input
	string fileName;				// filen name of user input
	string line;
	ifstream file;
	fileName = "";


	int choice = 0;
	// While-loop to print menu unless user chooses to exit
	while (choice != 4) {
		cout << endl;
		cout << "Welcome to the course planner."<<endl;
		cout << "--------------------------------------"<<endl;
		cout << "1. Load Data Structure." <<endl;
		cout << "2. Print Course List."<<endl;
		cout << "3. Print Course." << endl;
		cout << "4. Exit" << endl;
		cout << "--------------------------------------" << endl;
		cout << endl;
		cout << "What would you like to do? : ";

		// Get user input and access case to match user choice
		cin >> choice;
		switch (choice) {

		// Open, parse, and load file
		case 1:
			// Prompt and get file name
			cout << "Please enter the file you wish to load: (i.e. ABCU_Advising_Program_Input.txt): " << endl;
			cin >> fileName;

			// Open file
			file.open(fileName);
			// If file fails to open
			if (!file.is_open()) {
				cout << "File has failed to load." << endl;
			}
			// If file opens
			else {
				cout << fileName << " has successfuly loaded!" << endl;
			}

			// Parse file
			while (getline(file, line)) {
				// Declare input names
				string courseNum;
				string courseName;
				string prerequ;

				// Read ',' seperated values
				stringstream ss(line);

				// Course placeholder
				Course course;
				getline(ss, courseNum, ',');
				course.courseId = courseNum;
				getline(ss, courseName, ',');
				course.courseName = courseName;
				getline(ss, prerequ);
				course.prerequ = prerequ;

				// Add course to BST
				bst->Insert(course);
			}

			// Close file
			file.close();
			break;
		
		// Print sorted course list
		case 2:
			cout << endl;
			cout << "Here is a sample schedule: " <<endl;
			cout << "********************************************"<<endl;
			// Call function to sort loaded list
			bst->InOrder();
			cout << "********************************************" << endl;
			break;

		// Search and print a user's given course
		case 3: {
			//Prompt and get course to search
			cout << "What course do you want to know about? (i.e. CSCI100):  ";
			cin >> searchCourse;

			// Loop for and capitalize user input to match data
			for (unsigned int i = 0; i < searchCourse.size(); i++) {
				searchCourse[i] = toupper(searchCourse[i]);
			}

			// Create placeholder for called Search method with user input as parameter
			Course hold = bst->Search(searchCourse);

			// Print results of search
			cout << hold.courseId << ", " << hold.courseName << "\n";
			cout << "Prerequisites: " << hold.prerequ << "\n";
			break;
		}

		// Exit and print goodbye message
		case 4:
			cout << "Thank you for using the course planner!" << endl;
			return 1;

		// Output message for wrong user menu input
		default:
			cout << choice << " is not a valid option." <<endl;
			break;




		}

	}

	return 0;
}