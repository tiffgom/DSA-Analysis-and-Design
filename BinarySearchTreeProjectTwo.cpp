#include "BinarySearchTreeProjectTwo.h"

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
	// Root is equal to nullptr
	root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {

}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
	// Call inOrder fuction with root as parameter
	this->inOrder(root);
}

/**
 * Insert a course
 */
void BinarySearchTree::Insert(Course course) {
	// If the root is empty, then assign root to new node course
	if (root == nullptr) {
		root = new Node(course);
	}
	// Else if root is not empty, add Node root and course
	else {
		addNode(root, course);
	}
}

/**
 * Search for a course
 */
Course BinarySearchTree::Search(string courseId) {
	Course course;
	// Set current node equal to root
	Node* current = root;

	// While-loop until bottom reached or matching courseId found
	while (current != nullptr) {
		// If match found, return current course
		if (current->course.courseId.compare(courseId) == 0) {
			return current->course;
		}
		// If course is smaller than current node then traverse left
		if (courseId.compare(current->course.courseId) < 0) {
			current = current->left;
		}
		// If course is larger than current node then traverse right
		else {
			current = current->right;
		}
	}

	return course;
}

/**
 * Add a course to some node (recursive)
 *
 * @param node Current node in tree
 * @param course Course to be added
 */
void BinarySearchTree::addNode(Node* node, Course course) {
	// If node is larger than the course then add to left subtree
	if (node->course.courseId.compare(course.courseId) > 0) {
		// If left node is empty, then this node becomes left
		if (node->left == nullptr) {
			node->left = new Node(course);
		}
		// Else recurse down the left node
		else {
			addNode(node->left, course);
		}
	}
	// Else add to right subtree
	else {
		// If right node is empty, then this node becomes right
		if (node->right == nullptr) {
			// this node becomes right
			node->right = new Node(course);
		}
		// Else recurse down the right node
		else {
			addNode(node->right, course);
		}
	}



}

void BinarySearchTree::inOrder(Node* node) {

	// If the root is not empty, begin traversing the tree
	if (root != nullptr) {

		// If left node is not empty, traverse left side
		if (node->left != nullptr) {
			inOrder(node->left);
		}

		// Output center node: course Id, course name
		cout << node->course.courseId << ", " << node->course.courseName << endl;

		// If right node is not empty, traverse right side
		if (node->right != nullptr) {
			inOrder(node->right);
		}
	}
}



