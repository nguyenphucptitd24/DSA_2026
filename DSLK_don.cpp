#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
int main (){
	Node* node1 = new Node();
	node1->data = 10;
	node1->next = NULL;
	
	Node* head = node1;
	
	Node* node2 = new Node();
	node2->data = 20;
	node2->next = NULL;
	
	node1->next = node2;
	
	Node* temp = head;
	while(temp != NULL){
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}