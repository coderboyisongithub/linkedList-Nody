# linkedList-Nody
Generic C/C++ implementation for linked list and stack data structure

struct payload is defined as to keep what-ever payload you would like to manage with help of list or stack implementation...
Example:
1.Basic data type variable(char,float,int....)
just create a variable and edit a payload structure(of any name you want... and cast it to void pointer before attaching to list or stack

//Code..
//payload edited..
  struct payload
  {
  int data;
  int *data_ptr;
  };
//implementation
#include <nody.h>
payload *p;
void main()
{
  int var=10;
  p=(payload*)malloc(sizeof(payload));
  
  p->data=var;       //attaching value .
  p->data_ptr=&var; //attaching pointer.
  
  LIST_LINKED list;
  STACK_CHILD stack;
  
  stack.push((void*)p);   //cast structure pointer to void pointer
  payload *retrev_data=(payload*)stack.pop(); //cast void pointer to structure formate back again..
  
  list.insert((void*)p); //again casting back to void pointer...for an upload...
 return;
} 

2.User Types...
if dealing with own type the following change would be required in above code...

  struct usertype
  {
/*Zombie coder's brain's junk..
  ..... 
  .....
  .....
  */
  };
  
//Code
   struct payload
  {
usertype *ptr;
usertype variable;
  };
  ...and just implement it like before..Easy..
  
  
