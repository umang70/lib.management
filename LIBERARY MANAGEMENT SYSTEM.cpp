#include <iostream>

#include<fstream>
using namespace std;
class library
{
	private:
		struct Node
		{
			int id;
			string name;
			string author; 
			string publisher;
			Node *next_add;
		};
	public:
		Node *head = NULL;
		void menu();
		void insert();
		void search();
		void update();
		void del();
		void sort();
		void show();
};
int main() 
{
     library obj;
	 obj.menu(); 	
}
void library::menu()
{
   	p:
   	system ("cls");
   	int choice;
   	cout<<"\n\n\t\t\t***********************************";
   	cout<<"\n\n\t\t\t*****LIBRARAY MANAGMENT SYSTEM*****";
   	cout<<"\n\n\t\t\t***********************************";
   	cout<<"\n\n 1.INSERT NEW RECORD";
   	cout<<"\n\n 2.SEARCH RECORD";
   	cout<<"\n\n 3.UPDATE RECORD";
   	cout<<"\n\n 4.DELETE RECORD";
   	cout<<"\n\n 5.SHOW ALL RECORD";
   	cout<<"\n\n 6.EXIT";
   	cout<<"\n\n ENTER YOUR CHOICE : ";
   	cin>>choice;
   	switch(choice)
   	{
   	    case 1:
   	    	insert();
   	    	break;
   	    case 2:
   	    	search();
   	    	break;
   	    case 3:
   	    	update();
   	    	break;
   	    case 4:
   	    	del();
   	    	break;
   	    case 5:
   	    	sort();
   	    	show();
   	    	break;
   	    case 6:
   	    	exit(0);
   	    default:
   	    	cout<<"\n\n Invalid choice.. Please try again...";		     			
   	}
//	getch();
	goto p;
}
void library::insert() 
{	
	system ("cls");
   	cout<<"\n\n\t\t\t***********************************";
   	cout<<"\n\n\t\t\t*****LIBRARAY MANAGMENT SYSTEM*****";
   	cout<<"\n\n\t\t\t***********************************";	
   	Node *new_node = new Node;
   	cout<<"\n\n Book ID : ";
   	cin>>new_node -> id; 
   	cout<<"\n\n Name :";
   	cin>>new_node -> name;
   	cout<<"\n\n Author Name :";
   	cin>>new_node -> author;
   	cout<<"\n\n Publisher Name :";
   	cin>>new_node -> publisher;
   	new_node ->  next_add = NULL;
   	if(head == NULL)
   	{
   	    head = new_node;
	}
	else
	{
		Node *ptr = head;
		while(ptr -> next_add != NULL) 
		{
			ptr = ptr-> next_add;
		}
		ptr -> next_add = new_node;
	}
	cout<<"\n\n\t\t\t NEW BOOK INSERTED SUCCESSSFULLY...."; 
}
void library::search()
{
	system ("cls");
	int t_id,found=0;
   	cout<<"\n\n\t\t\t***********************************";
   	cout<<"\n\n\t\t\t*****LIBRARAY MANAGMENT SYSTEM*****";
   	cout<<"\n\n\t\t\t***********************************";
	if(head == NULL)
	{
		cout<<"\n\n LINKED LIST IS EMPTY...";
	}
	else
	{
		cout<<"\n\n BOOK ID : ";
		cin>>t_id;
		Node *ptr = head;
		while(ptr !=NULL)
		{
			if(t_id == ptr ->id)
			{
				system ("cls");
   	    	    cout<<"\n\n\t\t\t***********************************";
   	    		cout<<"\n\n\t\t\t*****LIBRARAY MANAGMENT SYSTEM*****";
   	    		cout<<"\n\n\t\t\t***********************************";
				cout<<"\n\n Book ID : "<<ptr-> id;
				cout<<"\n\n Book Namae : "<<ptr-> name;
				cout<<"\n\n Author Name : "<<ptr-> author;
				cout<<"\n\n Publisher Nme : "<<ptr-> publisher ;
				found++; 
			}
			ptr = ptr -> next_add;
		}
		if (found == 0)	
		{
			cout<<"\n\n BOOK ID IS INVALID...: ";
		}
	}
}
void library::update()	
{
	system ("cls");
	int t_id,found=0;
   	cout<<"\n\n\t\t\t***********************************";
   	cout<<"\n\n\t\t\t*****LIBRARAY MANAGMENT SYSTEM*****";
   	cout<<"\n\n\t\t\t***********************************";
	if(head == NULL)
	{
		cout<<"\n\n LINKED LIST IS EMPTY...";
	}
	else
	{
		cout<<"\n\n BOOK ID : ";
		cin>>t_id;
		Node *ptr = head;
		while(ptr !=NULL)
		{
			if(t_id == ptr ->id)
			{
				system ("cls");
   	    	    cout<<"\n\n\t\t\t***********************************";
   	    		cout<<"\n\n\t\t\t*****LIBRARAY MANAGMENT SYSTEM*****";
   	    		cout<<"\n\n\t\t\t***********************************";	
				cout<<"\n\n Book ID : ";
				cin>>ptr-> id;
				cout<<"\n\n Book Nmae : ";
				cin>>ptr-> name;
				cout<<"\n\n Author Name : ";
				cin>>ptr-> author;
				cout<<"\n\n Publisher Name : ";
				cin>>ptr-> publisher ;
				found++; 
				cout<<"\n\n\t\t\t UPDATED BOOK SUCCESSFULLY : ";
			}
			ptr = ptr -> next_add;
		}
		if (found == 0)	
		{
			cout<<"\n\n BOOK ID IS INVALID...: ";
		}
	}
}
void library::del()
{
	system ("cls");
	int t_id,found=0;
   	cout<<"\n\n\t\t\t***********************************";
   	cout<<"\n\n\t\t\t*****LIBRARAY MANAGMENT SYSTEM*****";
   	cout<<"\n\n\t\t\t***********************************";
	if(head == NULL)
	{
		cout<<"\n\n LINKED LIST IS EMPTY...";	
	}
	else
	{
		cout<<"\n\n Book ID : ";
		cin>>t_id;
		if(t_id == head -> id)
		{
			Node *ptr =head;
			head = head ->next_add;
			delete ptr;
			cout<<"\n\n DELETED BOOK SUCCESSFULLY...";
			found++;
		}
		else
		{
			Node *pre = head;
			Node *ptr =head;
			while(ptr != NULL)
			{
				if(t_id == ptr -> id)
				{
					pre -> next_add = ptr -> next_add;
					delete ptr;
					cout<<"\n\n DELETED BOOK SUCCESSFULLY...";
					found++;
					break;
				}
				pre =ptr;
				ptr= ptr -> next_add;						
			}
		}
		if(found ==0)
		{
			cout<<"\n\n Book ID is invalid...";
		}
	}			
}
void library::sort()
{
	if(head == NULL)
	{
	   	system ("cls");
	   	cout<<"\n\n\t\t\t***********************************";
   	    cout<<"\n\n\t\t\t*****LIBRARAY MANAGMENT SYSTEM*****";
   	    cout<<"\n\n\t\t\t***********************************";	
	   	cout<<"\n\n LINKED LIST IS EMPTY...";
	  // 	getch();
	   	menu();  	
	}
	int count=0,t_id;
	string t_name,t_author,t_publisher;
	Node *ptr = head;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr -> next_add;	 	
	} 	
	for(int i=1;i<=count;i++)
	{
		Node *ptr = head;
		for(int j=1;j<count;j++)
		{
			if(ptr -> id > ptr ->next_add -> id)	
			{
			   	//save data into temporary variables
			   	t_id     = ptr->id;
				t_name   = ptr->name;
				t_author = ptr->author;
				t_author = ptr->publisher;
				//save dta into current node
				ptr -> id = ptr -> next_add -> id;
				ptr -> name = ptr -> next_add -> name;
				ptr -> author = ptr -> next_add -> author;
				ptr -> publisher = ptr -> next_add -> publisher;
				//save data into next node
				ptr -> next_add -> id = t_id;
				ptr -> next_add -> name = t_name;
				ptr -> next_add -> author = t_author;
				ptr -> next_add -> publisher = t_publisher;
			}
			ptr = ptr ->next_add;
		}
	}
}
void library::show()
{
	system ("cls");	       
   	cout<<"\n\n\t\t\t***********************************";
   	cout<<"\n\n\t\t\t*****LIBRARAY MANAGMENT SYSTEM*****";
   	cout<<"\n\n\t\t\t***********************************";			
	Node *ptr = head;
	while(ptr !=NULL)
	{
		cout<<"\n\n Book ID : "<<ptr-> id;
		cout<<"\n\n Book Nmae : "<<ptr-> name;
		cout<<"\n\n Author Name : "<<ptr-> author;
		cout<<"\n\n Publisher Nme : "<<ptr-> publisher ;
		cout<<"\n\n\n***********************************";
		ptr = ptr -> next_add;
	}			 	
}

	