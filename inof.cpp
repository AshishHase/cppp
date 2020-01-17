/*
               Assigenment No:01
     Aim
          Implement Stack as an ADT using Link List and use this ADT for conversion of Infix To Postfix ,Infix to Prefix And Evaluation of PostFix And Prefix Expression:
                    
                    Name: Ashish Manesh Hae
                    
                    Roll No:34
                    
                    Date of Performance:  /  /2020
                    
                    Date Of Submission:  /  /2020
*/                                    
#include<iostream>
#include<string.h>
#include<math.h>
#include"stack.cpp"
class post
{
     public:
/*Function To Convert Infix Expression Into Postfix Form*/
     void inftopof(char inf[],char pof[],int ch)
     {
          stack s;
          int i,j=0;
          for(i=0;inf[i]!='\0';i++)
          {
               int x=inf[i];
               if(isalnum(x))
               {
                    pof[j++]=x;
               }
           else if(x=='(')
           {
               s.push(x);
           }
           else if(x==')')
           {
           while((x=s.pop())!='(')
           pof[j++]=x;
           }
           else
           {
           if(ch==1)
           {
               while(!s.isempty()&&icp(x)<=isp(s.topdata()))
               {
                    pof[j++]=s.pop();
               }
               s.push(x);
             }
               if(ch==2)
               {
           while(!s.isempty()&&icp(x)<isp(s.topdata()))
           {
                    pof[j++]=s.pop();
           }
                s.push(x);
            }
           }
           }
           while(!s.isempty())
           {
               pof[j++]=s.pop();
            }
            pof[j]='\0';
           }
           int icp(char x)
           {
               switch(x)
               {
                    case '+':
                    case '-':return 1;
                    case '*':
                    case '/':
                    case '%':return 2;
                    case '^':return 3;
                    case '(':return 4;
                    return 5;
                 }
               }
          int isp(char x)
          {
               if(x=='(')
                    return 0;
               else if(x=='+'||x=='-')
                    return 1;
                else if(x=='*'||x=='/')
                         return 2;
                 else if(x=='^')
                         return 3;
                   return 4;
            }
          void strrev(char inf[])
          {
               int i=0,j;
               j=strlen(inf)-1;
               char temp;
               while(i<j)
               {
                    temp=inf[i];
                    inf[i]=inf[j];
                    inf[j]=temp;
                    i++;
                    j--;
                }
             }
/* Function To Convert Infix Expression To Prefix Form*/
           void inftopre(char inf[],char pre[])
           {   int i;
               strrev(inf);
               for(int i=0;inf[i]!='\0';i++)
               {
                    if(inf[i]=='(')
                    inf[i]=')';
                    else if(inf[i]==')')
                    inf[i]='(';
                }
              inftopof(inf,pre,2);
              strrev(pre);
            }
 float eval(char x,float x1,float x2)
 {   
     switch(x)
     {
          case '+': return x1+x2;
          case '-': return x1-x2;
          case '*': return x1*x2;
          case '/': return x1/x2;
          case '%': return int(x1) % int(x2);
          case '^': return pow(x1,x2);
      }
     return -1;
 }
 float posteval(char pof[])
 {
     float x,op1,op2,val;
     stack s;
     for(int i=0;pof[i]!='\0';i++)
     {
          x=pof[i];
          if(isalpha(x))
          {
               cout<<"\nEnter value ofx";
               cin>>val;
               s.push(val);
           }
         else if(isdigit(x))
         {
          s.push(x-48);
         }
         else
         {
               op2=s.pop();
               op1=s.pop();
               val=eval(x,op1,op2);
               s.push(val);
          }
        }
        val=s.pop();
        return val;
}
float preeval(char pre[])
{
     float x,op1,op2,val;
     stack s;
    for(int i=0;pre[i]!='\0';i++)
     {
          x=pre[i];
          if(isalpha(x))
          {
               cout<<"\nenter value of x";
               cin>>val;
               s.push(val);
            }
            else if(isdigit(x))
            {
               s.push(x-48);
             }
            else
            {
            op1=s.pop();
            op2=s.pop();
            val=eval(x,op1,op2);
            s.push(val);
            }
         }
         val=s.pop();
         return val;
   }
  };            
               
           int main()
           {
               post p;
               char a[30],pof[30],pre[30];
               float val,val1;     
                int ch;
               while(1)
               {
               cout<<"\n1.**Infix to postfix**\n2.**infix to prefix**\n3.**Evaluation of  postfix**\n4.**evaluation of prefix**";
               cout<<"\nEnter your choice\t";
               cin>>ch;
               switch(ch)
               {
              case 1: cout<<"\nenter the infix expression\t";
               cin>>a;
               p.inftopof(a,pof,1);
               cout<<"\n\tAfter conversion the postfix expression is\t"<<pof;
               break;
              case 2:cout<<"\nEnter infix expression\t";
                   cin>>a;
                   p.inftopre(a,pre);
                   cout<<"\n\tAfter conversion prefix expression is\t"<<pre; 
              case 3:cout<<"\nEnter expression\t";
                     cin>>pof;
                     val=p.posteval(pof);
                     cout<<"\nAfter evalution the result is\t"<<val;
              break;
              case 4:cout<<"\nEnter Expression\t";
                     cin>>pre;
                     p.strrev(pre);
                     val1=p.preeval(pre);
                     cout<<"\nAfter Evaluation result is\t"<<val1;
                     break;
              }
              }
              return 0;
             }   
             
             
/*
student@ITPL20:~$ g++ inof.cpp
student@ITPL20:~$ ./a.out

1.**Infix to postfix**
2.**infix to prefix**
3.**Evaluation of  postfix**
4.**evaluation of prefix**
Enter your choice	1

enter the infix expression	A*(B+C)/D-G

	After conversion the postfix expression is	ABC+*D/G-
1.**Infix to postfix**
2.**infix to prefix**
3.**Evaluation of  postfix**
4.**evaluation of prefix**
Enter your choice	1

enter the infix expression	2*(3/4)+2-6

	After conversion the postfix expression is	234/*2+6-
Enter your choice	2

Enter infix expression	(A+B)*(C-D)

	After conversion prefix expression is	*+AB-CD


Enter your choice	2

Enter infix expression	P*Q^R+S        

	After conversion prefix expression is	+*P^QRS

Enter your choice	3

Enter expression	123+-4^

After evalution the result is	256

Enter your choice	4

Enter Expression	+-*2345

After Evaluation result is	7
1.**Infix to postfix**
2.**infix to prefix**
3.**Evaluation of  postfix**
4.**evaluation of prefix**
Enter your choice	4

Enter Expression	+-^*145567  

After Evaluation result is	1025
1.**Infix to postfix**
2.**infix to prefix**
3.**Evaluation of  postfix**
4.**evaluation of prefix**
Enter your choice	
*/


              
          
