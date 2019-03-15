#include<iostream>
using namespace std;
//node class
class node{
	public:
		int data;
		node *left;
		node *right;
		node(int value){
			left=NULL;
			right=NULL;
			data=value;
		}
};
//class binary search tree
class bst{
	public:
		node * root;
		bst(){
			root=NULL;
		}
		//insert
	void inser(int value){
		inserthelper(root, value);
	}
	void inserthelper(node *curr, int value){
		if(curr==NULL){
			curr = new node(value);
			if(root == NULL){
				root = curr;
				return ;
			}
		}
		//else compare the curr data with value
		else if(value < curr->data){
		//if  value < curr data
		//if left is null insert it
		//else move left and call inserthelper
		if(curr->left==NULL) curr->left = new node(value);
	    else  inserthelper(curr->left , value);
		}
		else{
				//else move right and call insert helper
		 if(curr->right ==NULL) curr->right= new node(value);
		 else inserthelper(curr->right , value);
		}
	}
	//display
	void display(){
		display2(root);
		cout<<endl;
	}
	void display2(node * curr){
		if(curr==NULL) return;
		//display left
		display2(curr->left);
		//display curr
		cout<<curr->data<<"->";
		//display right
		display2(curr->right);
	}
	 node displayFancy(int spaces){
        // Increase number of spaces
        // Display right
        // print req spaces
        // Display curr
        // Display left
        /*
        Sample output
                16
            14
                12
        10
                8
            6
                4
        */
    }
	//search
	node * search(node * curr , int value){
		        // If reached end of tree. or value found
			if(curr==NULL|| curr->data==value) return curr;
			else if (value < curr->data) return search(curr->left,value);
			else return search (curr->right , value);
	}

};
int main(){
	bst b1;
	b1.inser(5);
	b1.inser(2);
	b1.inser(1);
	b1.display();
	b1.inser(4);
	b1.inser(6);
	b1.inser(6);
	b1.inser(9);
	b1.inser(7);
	b1.display();
	int x;
	cout<<"enter the number which you wnat to check"<<endl;
	cin>>x;
	if (b1.search (b1.root,x)!=NULL) cout<<"Number is found.";
	else cout<<"Number is not found.";
	return 0;
}
