/*
Experiment NO=4
Title=Expression is Application Of Binary tree 
1.Create Expression tree
2.create recersive Infix
3.recersive Prefix
4.Non recersive infix
5.Nn recersive prefix

Name=Ashish Hase
Roll NO=34
Date Of Performance=  /  /2020
Date Of Submission=  /  2020
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
     char data;
     node *l,*r;
};
class stack
{
node *data[10];
int top;
public :
	
	stack()
	{
	top=-1;
	
	}
	
	int isEmpty()
	{
		if(top==-1)
			return 1;
		else 
		 	return 0; 
	
		}
	
	void push(node *p)
	{
		data[++top]=p;
	}
	
	node *pop()
	{
		return data[top--];
	}
};
class extree
{
     public:
     node *root;
     extree()
     {
          root=NULL;
     }
     void create ()
     {
          int i;
          char post[10];
          node *p;
          stack s;
          cout<<"\nEnter Postfix Expression";
          cin>>post;
          for(i=0;post[i]!='\0';i++)
          {
               p=new node;
               p->data=post[i];
               p->l=p->r=NULL;
               if(isalnum(p->data))
               {
                    s.push(p);
               }
        else
        {
          p->r=s.pop();
          p->l=s.pop();
          s.push(p);
        }
    }
    root=s.pop();
}
void rec_in(node *t)
{
     if(t!=NULL)
     {
          rec_in(t->l);
               cout<<t->data;
          rec_in(t->r);
     }
 }
 void nonrec_in()
 {
     node *t=root;
     stack s;
     while(t!=NULL||!s.isEmpty())
     {
          if(t!=NULL)
          {
               s.push(t);
               t=t->l;
          }
          else
          {
          t=s.pop();
          cout<<t->data;
          t=t->r;
          }
     }
 }
 void rec_pre(node *t)
 {
     if(t!=NULL)
     {
          cout<<t->data;
          rec_pre(t->l);
          rec_pre(t->r);
     }
 }
 void nonrec_pre()
 {
     node *t=root;
     stack s;
     while(t!=NULL||!s.isEmpty())
     {
          if(t!=NULL)
          {
          cout<<t->data;
          s.push(t);
          t=t->l;
     }
     else
     {
     t=s.pop();
     t=t->r;
     }
 }
}
};
int main()
{
     int ch;
     extree e;
     while(1)
     {
          cout<<"\n1.create\n2.Recurcive Infix\n3.Non Recurcive Infix\n4.Recursive Prifix\n5.non Recersive prifix\n";
           cout<<"\nEnter Your Choice";
           cin>>ch;
           switch(ch)
           {
               case 1: e.create();
                         break;
               case 2: e.rec_in(e.root);
                         break;
               case 3:e.nonrec_in();
                         break;
               case 4:e.rec_pre(e.root);
                             break;
                case 5:e.nonrec_pre();
                break;
           }
          
      }
 return 0;
 }
     
/*
student@ITPL20:~$ cd Desktop
student@ITPL20:~/Desktop$ g++ expp.cpp
student@ITPL20:~/Desktop$ ./a.out

1.create
2.Recurcive Infix
3.Non Recurcive Infix
4.Recursive Prifix
5.non Recersive prifix

Enter Your Choice1

Enter Postfix Expression
PQR-*s+    

1.create
2.Recurcive Infix
3.Non Recurcive Infix
4.Recursive Prifix
5.non Recersive prifix

Enter Your Choice2
P*Q-R+s
1.create
2.Recurcive Infix
3.Non Recurcive Infix
4.Recursive Prifix
5.non Recersive prifix

Enter Your Choice3
P*Q-R+s
1.create
2.Recurcive Infix
3.Non Recurcive Infix
4.Recursive Prifix
5.non Recersive prifix

Enter Your Choice4
+*P-QRs
1.create
2.Recurcive Infix
3.Non Recurcive Infix
4.Recursive Prifix
5.non Recersive prifix

Enter Your Choice5
+*P-QRs
1.create
2.Recurcive Infix
3.Non Recurcive Infix
4.Recursive Prifix
5.non Recersive prifix

Enter Your Choice
*/
