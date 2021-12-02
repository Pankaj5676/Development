#include<iostream>
using namespace std;


////Stucture for the "Singly Linear Linked-List" ,"Singly Circular Linked-List","Stack" and "Que".

template <typename T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

////Stucture for the "Doubly Linear Linked-List" and "Doubly Circular Linked-List".

template<typename T>
struct nodeD
{
	T data;
	struct nodeD *next;
	struct nodeD *prev;
};


//Class of Singly Linear Linked-List

template <class T>
class SinglyLL
{
private:
   nodeS <T> * first;
    int size;
    
public:
SinglyLL();
void InsertFirst(T);
void InsertLast(T);
void InsertAtPos(T,int);
void DeleteFirst();
void DeleteLast();
void DeleteAtPos(int);
void Display();
int Count();   
};


////Class of Singly Circular Linked-List

template<class T>
class SignlyCL
{
	private :
	nodeS <T> * first;
	nodeS <T> * last;
	int size;
	
	public :
	SignlyCL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
	
};


///Class of Doubly Linear Linked-List

template<class T>
class DoublyLL
{
	private:
	nodeD <T> * first;
	int size;
	
	public:
	DoublyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
};


////Class of Doubly Circular Linked-List

template<class T>
class DoublyCL
{
private:
    nodeD <T> * first;
    nodeD <T> *last;
    int size;
    
public:
    DoublyCL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};


///Class of Stack

template<class T>
class Stack
{
	private:
	nodeS <T> * first;
	
	public :
	Stack();
	void Push(T);
	void Pop();
	void Display();
};


///class of Queue

template<class T>
 class Queue
 {
	private :
     nodeS<T> * first;

public :
Queue();
void eQueue(T);
void dQueue();
void Display();	
 };
 
 
 

////////////////////////////////////////////////////////////////////////////

//SinglyLL

template <class T>
SinglyLL<T>:: SinglyLL()
    {
        first = NULL;
        size = 0;
    }
    
	template <class T>
    void SinglyLL<T>::InsertFirst(T no)
    {
         nodeS<T> * newn = new  nodeS<T>;  // newn = (PnodeS)malloc(sizeof(nodeS))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }
    
	template <class T>
    void SinglyLL<T>::InsertLast(T no)
    {
         nodeS<T> * newn = new  nodeS<T>;  // newn = (PnodeS)malloc(sizeof(nodeS))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
             nodeS<T> * temp = first;
            
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }
    
	template <class T>
	void SinglyLL<T>::InsertAtPos(T no,int ipos)
	{
		nodeS <T>* newn=new nodeS<T>;
		
		newn->data=no;
		newn->next=NULL;
		if(ipos<1||ipos>(size+1))
		{
			return;
		}
		else if(ipos==1)
		{
			InsertFirst(no);
		}
		else if(ipos==(size+1))
			{
				InsertLast(no);
			}
		else
		{
			nodeS <T> * temp=first;
			int i=0; 
			for(i=1;i<ipos-1;i++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->next=newn;
			size++;
		}
		
		
	}
	
	template <class T>
    void SinglyLL<T>::DeleteFirst()
    {
         nodeS <T> *temp = first;
        
        if(first != NULL)
        {
            first = first->next;
            delete temp;
            size--;
        }
    }
    
	template <class T>
    void SinglyLL<T>::DeleteLast()
    {
        nodeS<T> * temp = first;
        
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }
 
 template <class T>
     void SinglyLL<T>::DeleteAtPos(int ipos)
	 {
	 nodeS <T> * temp=first;
	 
      if(ipos<1||ipos>(size+1))
	  {
		  return;
	  }		  
	  else if(ipos==1)
	  {
		  DeleteFirst();	  
	  }
	  else if(ipos==size)
		  {
			  DeleteLast();
		  }
	  else 
	  {
		  int i=0;
		  nodeS <T> * Targeted=NULL;
		  for(i=1;i<ipos-1;i++)
		  {
			  temp=temp->next;
		  }
		  Targeted=temp->next;
		  temp->next=Targeted->next;
		  delete (Targeted);
	  size--;
	  }
			  
	 }
 
 template <class T>
    void SinglyLL<T>::Display()
    {
         nodeS<T> *temp = first;
        
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
	template <class T>
    int SinglyLL<T>:: Count()
    {
        return size;
    }




/////////////////////////////////////////////////////////////
//function defination of Singly Circular Linked-List

template<class T>
SignlyCL<T>::SignlyCL()
	{
		first=NULL;
		last=NULL;
		size=0;
	}
	
	template<class T>
	void SignlyCL<T>::Display ()
	{
		nodeS <T> * temp=first;
	if((first == NULL) && (last == NULL))
        {
            return;
        }
        
        do
        {
            cout<<"|"<<temp->data<<"|-> ";
            temp = temp->next;
        }while(temp != last->next);
        
        cout<<"\n";
	}
	
	template<class T>
	int SignlyCL<T>::Count()
	{
		return size;
	}
	
	template<class T>
	void SignlyCL<T>::InsertFirst(T no)
	{
	 
     nodeS <T> * newn=new nodeS <T>;
         
   	 newn->data = no;
        newn->next = NULL;
        
        if((first == NULL) && (last == NULL))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        
        last->next = first;
        size++;
	}
	
	template<class T>
	void SignlyCL<T>::InsertLast(T no)
	{
     nodeS <T> * newn=new nodeS <T>;
         
   	 newn->data = no;
        newn->next = NULL;
        
        if((first == NULL) && (last == NULL))
        {
            first = newn;
            last = newn;
        }
        else
        {
            last->next = newn;
            last = newn;
        }
        
        last->next = first;
        size++;
	}
	
	template<class T>
	void SignlyCL<T>:: InsertAtPos(T no,int ipos)
	{if((ipos < 1) || (ipos > (size+1)))
        {
            return;
        }
        
        if(ipos ==1)
        {
            InsertFirst(no);
        }
        else if(ipos == size+1)
        {
            InsertLast(no);
        }
        else
        {
            nodeS <T> * newn=new nodeS <T>;
            
            newn->data = no;
            newn->next = NULL;
            
            nodeS <T> * temp = first;
            
            for(int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }
            
            newn->next = temp->next;
            temp->next = newn;
            
            size++;
        }
	}
	
	template<class T>
	void SignlyCL<T>::DeleteFirst()
	{
		if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            first = first->next;
            delete last->next;
            last->next = first;
        }
        size--;
	}
	
	template<class T>
	void SignlyCL<T>::DeleteLast()
	{
		nodeS <T> * temp=first;
		if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            while(temp->next != last)
            {
                temp = temp -> next;
            }
            
            delete last;
            last = temp;
                
            last->next = first;
        }
        size--;
		
	}
	
	template<class T>
	void SignlyCL<T>::DeleteAtPos(int ipos)
	{
		if((ipos < 1) || (ipos > size))
        {
            return;
        }
        
        if(ipos ==1)
        {
            DeleteFirst();
        }
        else if(ipos == size)
        {
            DeleteLast();
        }
        else
        {
            nodeS <T> * temp= first;
            for(int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }
            
         nodeS <T> * targated = temp->next;
            
            temp->next = targated->next;    // temp->next = temp->next->next;
            delete targated;
            
            size--;
        }
	}


/////////////////////////////////////////////////////////////////
//Function Defination of Doubly Linear Linked-List

template<class T>
DoublyLL<T>::DoublyLL()
	{
		first=NULL;
		size=0;
	}
	
	template<class T>
	void DoublyLL<T>::InsertFirst(T no)
	{
		nodeD <T> * newn=new nodeD <T>;
		
		newn->data=no;
		newn->next=NULL;
		
		if(first==NULL)
		{
			first=newn;
		}
		else
		{
			newn->next=first;
			first->prev=newn;
			first=newn;
		}
		size++;
	}
	
	template<class T>
	void DoublyLL<T>:: InsertLast(T no)
	{
		
		nodeD <T> * newn=new nodeD<T>;
		
		newn->data=no;
		newn->next=NULL;
		
		if(first==NULL)
		{
			first=newn;
		}
		else 
			
		{
			nodeD <T> * temp=first;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newn;
			newn->prev=temp;
		}
		size++;
	}
	
	template<class T>
	void DoublyLL<T>:: DeleteFirst()
	{
		nodeD <T> * temp=first;
		
		if(first==NULL)
		{	
			return;
		}
		else if(first->next==NULL)
		{
			delete first;
			first=NULL;
		}
		else
		{
			first=first->next;
			delete (first->prev);
			first->prev=NULL;
		}
		size--;
	}
	
	template<class T>
	void DoublyLL<T>:: DeleteLast()
	{
	 nodeD <T> * temp=first;
      if(first==NULL)
	  {
		  return;
	  }		  
	  else if(first->next==NULL)
	  {
		  delete first;
		  first=NULL;
		  size--;	  
	  }
	  else
		  {
      		  while(temp->next!=NULL)
			  {
				  temp=temp->next;
			  }	  
			  temp->prev->next=NULL;
			  delete temp;
	  }
	  size--;
	}
	
	template<class T>
	void DoublyLL<T>:: InsertAtPos(T no,int ipos)
	{
		
		nodeD <T> * newn=new nodeD <T>;
		
		newn->data=no;
		newn->next=NULL;
		
		if(ipos<1||ipos>(size+1))
		{
			return;
		}
		else if(ipos==1)
		{
			InsertFirst(no);
		}
			else if(ipos==(size+1))
			{
				InsertLast(no);
			}
		else
		{
			nodeD <T> * temp=first;
			int i=0; 
			for(i=1;i<ipos-1;i++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			newn->next->prev=newn;
			temp->next=newn;
			newn->prev=temp;
			size++;
		}
		
	}
	
	template<class T>
	void DoublyLL<T>:: DeleteAtPos(int ipos)
	{
	 nodeD <T> * temp=first;
	 
      if(ipos<1||ipos>(size+1))
	  {
		  return;
	  }		  
	  else if(ipos==1)
	  {
		  DeleteFirst();	  
	  }
	  else if(ipos==size)
		  {
			  DeleteLast();
		  }
	  else 
	  {
		  int i=0;
		  for(i=1;i<ipos-1;i++)
		  {
			  temp=temp->next;
		  }
		  temp->next=temp->next->next;
		  delete (temp->next->prev);
		  temp->next->prev=temp;
		  		  size--;
	  }
	}
	
	template<class T>
	void DoublyLL<T>::Display()
	{
		nodeD <T> * temp=first;
		
		while(temp!=NULL)
		{
			cout<<"|"<<temp->data<<"|"<<"->"<<"\t";
			temp=temp->next;
		}
		cout<<"NULL";
	}
	
	template<class T>
	int DoublyLL<T>::Count()
	{
		return size;
	}
	
	
///////////////////////////////////////////////////////////////////////
//Function Defination of Doubly Circular Linked-List

template<class T>
DoublyCL<T> ::DoublyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }

template<class T>
void DoublyCL <T>:: InsertFirst(T no)
{
    nodeD <T> * newn = new nodeD <T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}


template<class T>
void DoublyCL <T>:: InsertLast(T no)
{
    nodeD <T> * newn = new nodeD <T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}

template<class T>
void DoublyCL <T>:: Display()
{
    nodeD <T> * temp = first;
    
    for(int i = 1; i <= size; i++)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int DoublyCL <T>:: Count()
{
    return size;
}

template<class T>
void DoublyCL <T>:: DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template<class T>
void DoublyCL <T>:: DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        last = last -> prev;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}

template<class T>
void DoublyCL <T>:: InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > size+1))
    {
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size +1)
    {
        InsertLast(no);
    }
    else
    {
        nodeD <T> * newn= new nodeD <T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        nodeD <T> * temp = first;
        
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size ++;
    }
}

template<class T>
void DoublyCL <T>:: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size))
    {
        return;
    }
    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        nodeD <T> * temp = first;
        
        for(int i = 1; i < ipos -1 ; i ++)
        {
            temp = temp -> next;
        }
       
        temp -> next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
        size--;
    }
}


////////////////////////////////////////////////////////////
///Function Defination of Stack

template<class T>
Stack<T>::Stack()
{
	first=NULL;
}

template<class T>
void Stack<T>::Push(T no)
{
	nodeS <T> * newn=new nodeS<T>;
	
	newn->data=no;
	newn->next=NULL;
	
	if(first==NULL)
	{
		first=newn;
	}
	else
	{
		newn->next=first;
	    first=newn;	 
	}
}

template<class T>
void Stack<T>::Pop()
{
	if(first==NULL)
	{
		return;
	}
	else
	{
		 nodeS<T> * temp=first;
		first=first->next;
		delete temp;
	}
}

template<class T>
void Stack<T>::Display()
{
	nodeS <T>* temp=first;
	
	while(temp!=NULL)
	{
		cout<<"|"<<temp->data<<"|\n";
		temp=temp->next;
	}
}



//////////////////////////////////////////////////////////////
///Function Defination of Queue


 template<class T>
 Queue<T>::Queue()
 {
	 first=NULL;
 }
 
 template<class T>
 void Queue<T>::eQueue(T no)
 {
	 nodeS <T>* newn=new  nodeS <T>;
	 
	 newn->next=NULL;
	 newn->data=no;
	 
	 if(first==NULL)
	 {
		 first=newn;
	 }
	 else
	 {
		  nodeS<T> * temp=first;
		 
		 while(temp->next!=NULL)
		 {
			 temp=temp->next;
		 }
		 temp->next=newn;
	 }
 }
 
 
 template<class T>
void Queue<T>::dQueue()
{
	if(first==NULL)
	{
		return;
	}
	else
	{
		 nodeS<T> * temp=first;
		first=first->next;
		delete temp;
	}
}
 
 template<class T>
 void Queue<T>::Display()
 {
	 nodeS<T> * temp=first;
	 while(temp!=NULL)
	 {
		 cout<<temp->data<<"\t";
	 temp=temp->next;
	 }
 }

////////////////////
//Entry point Functions
int main()
{
	DoublyCL <int>obj;
	obj.InsertFirst(10);
	obj.Display();
	
	return 0;
}
