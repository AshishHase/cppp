/*
                    Assignment No:2
    Aim
          Implement Priority Queue as ADT Using Single Linked List For Srevicing   Paitents in an hospital with prioritiws as 1.Serious(top priority) 2.Medium illness(medium priority) 3.General(Least Priority).
          
          Name:Ashish Manesh Hase
          Roll No:34
          Date of Performance:  /  /2020
          Date of Submission:   /  /2020
*/
#include<iostream>
#include<string.h>
using namespace std;
class queue
{
     struct node
     {
          int pr;
          char name[20];
          struct node *next;
     } *front;
        public:
          queue()
          {
               front=NULL;
          }
void insert(char name[10],int pr);
void remove();
void display();

int isempty()
{
     if(front==NULL)
          return 1;
     else
          return 0;
}
};
/* Function To Insert Patient Name With Their Priorityt */
void queue::insert(char name[10],int pr)
{
     node *temp,*prev,*new1;
     new1=new node;
     strcpy(new1->name,name);
     new1->pr=pr;
     new1->next=NULL;
     if(front==NULL)
     front=new1;
     else
     {
          temp=front;
          while(temp!=NULL&&new1->pr<=temp->pr)
          {
               prev=temp;
               temp=temp->next;
           }
       if(temp==front)
       {
          new1->next=front;
          front=new1;
       }
          else
          {
               new1->next=temp;
               prev->next=new1;
          }
        }
 }
 /* Function To Delete Patient With their Priority*/ 
 void queue::remove()
 {
     node *temp=front;
     front=front->next;
     cout<<"\nPatient="<<temp->name;
     cout<<"\nGot The Treatment With Priority="<<temp->pr;
     delete temp;
 }
 /* Function To display wating list of patient in Hospital */
 void queue::display()
 {
     node *temp=front;
     cout<<"\nname\tPriority";
     while(temp!=NULL)
     {
          cout<<"\n"<<temp->name<<"\t"<<temp->pr;
          temp=temp->next;
      }
  }
  int main()
  {
     queue q;
     int ch,prt,t;
     char name[20];
     
     while(1)
     {
     cout<<"\n*****MENU******"; 
     cout<<"\n1.* Patient Enter Detail On Hospital*\n2.*Service To Patient*\n3.*Dispalay waiting  List*\n";
     cout<<"\n**Enter Your Choice**\t";
     cin>>ch;
     switch(ch)
     {
          case 1: cout<<"\nEnter Name of patient";
                   cin>>name;
                   cout<<"\nEnter priority to patient";
                   cin>>prt;
                   q.insert(name,prt);
                   break;
          case 2: if(q.isempty())
                   cout<<"\nNo patient In hospital";
                   else
                   q.remove();
                   break;
          case 3: cout<<"\nThe Total Patient List with their Priority is\t";
                   q.display();
                   break;
        }
        }
        return 0;
  }
  
  /*
         ***OUTPUT***
  student@ITPL20:~$ g++ priQ.cpp
student@ITPL20:~$ ./a.out

*****MENU******
1.* Patient Enter Detail On Hospital*
2.*Service To Patient*
3.*Dispalay waiting  List*

**Enter Your Choice**	1

Enter Name of patient Ashish

Enter priority to patient 1

*****MENU******
1.* Patient Enter Detail On Hospital*
2.*Service To Patient*
3.*Dispalay waiting  List*

**Enter Your Choice**	1

Enter Name of patient Dinesh

Enter priority to patient 2

*****MENU******
1.* Patient Enter Detail On Hospital*
2.*Service To Patient*
3.*Dispalay waiting  List*

**Enter Your Choice**	1

Enter Name of patient Onkar

Enter priority to patient 3

*****MENU******
1.* Patient Enter Detail On Hospital*
2.*Service To Patient*
3.*Dispalay waiting  List*

**Enter Your Choice**	1

Enter Name of patient Dipak

Enter priority to patient 2

*****MENU******
1.* Patient Enter Detail On Hospital*
2.*Service To Patient*
3.*Dispalay waiting  List*

**Enter Your Choice**	3

The Total Patient List with their Priority is	
name	Priority
Onkar	3
Dinesh	2
Dipak	2
Ashish	1
*****MENU******
1.* Patient Enter Detail On Hospital*
2.*Service To Patient*
3.*Dispalay waiting  List*

**Enter Your Choice**	3

The Total Patient List with their Priority is	
name	Priority
Onkar	3
Dinesh	2
Dipak	2
Ashish	1
*****MENU******
1.* Patient Enter Detail On Hospital*
2.*Service To Patient*
3.*Dispalay waiting  List*

**Enter Your Choice**	2

Patient=Onkar
Got The Treatment With Priority=3
*****MENU******
1.* Patient Enter Detail On Hospital*
2.*Service To Patient*
3.*Dispalay waiting  List*

**Enter Your Choice**	2

Patient=Dinesh
Got The Treatment With Priority=2
*****MENU******
1.* Patient Enter Detail On Hospital*
2.*Service To Patient*
3.*Dispalay waiting  List*

**Enter Your Choice**	2

Patient=Dipak
Got The Treatment With Priority=2
*****MENU******
1.* Patient Enter Detail On Hospital*
2.*Service To Patient*
3.*Dispalay waiting  List*

**Enter Your Choice**	2

Patient=Ashish
Got The Treatment With Priority=1
*****MENU******
1.* Patient Enter Detail On Hospital*
2.*Service To Patient*
3.*Dispalay waiting  List*

**Enter Your Choice**	2

No patient In hospital
*****MENU******
1.* Patient Enter Detail On Hospital*
2.*Service To Patient*
3.*Dispalay waiting  List*

**Enter Your Choice**	

*/

     
         
