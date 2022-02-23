#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>


using namespace std;
#ifndef BINARYSEARCHTREEPROJECTTWO_H_
#define BINARYSEARCHTREEPROJECTTWO_H_


// Define a structure to hold course information
struct Course {
	string courseId;
	string courseName;
	string prerequ;
	// Default course constructor 
	Course() {
		courseId = "Course";
		courseName = "not found.";
		prerequ = "0";
	}
};

// Internal structure for tree node
struct Node {
	Course course;
	// Node pointer for left and right
	Node* left;
	Node* right;

	// Default constructor
	Node() {
		left = nullptr;
		right = nullptr;
	}

	// Initialize with a given course
	Node(Course aCourse) : Node() {
		this->course = aCourse;
	}
};

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {
private:
	Node* root;

	void addNode(Node* node, Course course);
	void inOrder(Node* node);
	

public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void InOrder();
	void Insert(Course course);
	Course Search(string courseNum);
};

#endif

/* BINARYSEARCHTREEPROJECTTWO_H_ */