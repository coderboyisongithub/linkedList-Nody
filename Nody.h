#ifndef LIST_
#define LIST_

#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>

#define FLUSH_ free();
#define FOOD_ int;

//use this payload to feed your data and cast its pointer to void while inserting to list or stack..


/*
					Mr.owl says
			    ______________
			   /              \
			  /  ___     ___   \    _____________________
			  |  \_/     \_/   |   /Don't Dare to copy ! |
			  |	     ;f;       |  /______________________|
			   \\            //
			   / \ _______ /  \
			  / 			   \
			 //    \\\///      \\
			///    ///\\\      \\\
		   /////             \\\\\\
		  ////////////\\\\\\\\\\\\\\
		 ////////////  \\\\\\\\\\\\\\
		/////////\\\\  /////\\\\\\\\\\
	   ////////\\\\\\\////////\\\\\\\\\
	  ///////   \\\\\\///////  \\\\\\\\\
	 /////       \\\\\//////       \\\\\\
	              {}      {}  
			 }{{}}}{}}  {}}{}{{}{
		  

*/
struct linked_list
{
	void *payload;
	linked_list *next,*prev,*my;
linked_list* attach_next(void *src)
{
	
	if(my->next!=NULL)
		{printf("restricted node creation..bridge already occupied!!");
	_getch();
	exit(0);
	}
	else{
		my->next=(linked_list*)malloc(sizeof(linked_list));
		my->next->prev=my;
		my->next->next=NULL;
		my->next->my=my->next;
		my->next->payload=src;
		return my->next;
	}
	}
linked_list* get_root()
{
	linked_list *tmp=my;while(tmp->prev!=NULL){tmp=tmp->prev;}return tmp;
}
linked_list *get_tip()
{
	linked_list *tmp=my;while(tmp->next!=NULL){tmp=tmp->next;}return tmp;
}
void kill(linked_list *target)
{
	if(target!=NULL)
	{
		linked_list *t=search(target);
		if(t!=NULL) //means if target found in list..
		{
			//time to verify weather target is on root node or tip or b/w some where..
			if(t->next==NULL &&t->prev!=NULL)//tip node...
			{
				t->prev->next=t->next;
				linked_list* target_node=t->get_root();
				free(t);
			}
			else if(t->next!=NULL &&t->prev!=NULL) //centernode
			{
				t->prev->next=t->next;
				t->next->prev=t->prev;
				free(t);
			}
			else if(t->prev=NULL) //root node....
			{
			return;
			}
		}
		else
			puts("!!TARGET NOT FOUND IN LIST TO KILL..");return;
	}
	else
	{
		puts("\n!!CANT KILL NULL POINTER\n");return;
	}

}
linked_list* search(linked_list *target)
{
	linked_list *dummyPtr=(linked_list*)(get_root());
	while(dummyPtr!=NULL)
	{
		if(dummyPtr==target)
		{
			return dummyPtr; //if found..

		}
		else
			dummyPtr=dummyPtr->next;
	}
	return NULL; //if not found...
}
};
linked_list* init_List()
{
	linked_list *ref;
	ref=(linked_list*)malloc(sizeof(linked_list));
	ref->my=ref;
	ref->payload=NULL;
	ref->next=NULL;
	ref->prev=NULL;
	return ref;

}
class LIST_LINKED
{
	
	int nodes;

	
void copyNode(linked_list *dst,linked_list *src)
	{
		dst->my=src->my;
		dst->next=src->next;
		dst->payload=src->payload;
		dst->prev=src->prev;

		printf("\ncpynode:%p %p %p",src->my,src->payload,src->next);
		return;

	}

public:
	linked_list *list,*root;
	LIST_LINKED()
	{
		list=init_List();
		root=list;
		nodes=1;
	}

	void copyTo(LIST_LINKED &dest)
	{
		if(!dest.isEmpty())
		{
			dest.destroy();
		}
		linked_list *iter=getFirstNode();
		
		printf("\n\nCPY::FUNC\n");
		while(dest.getsize()!=getsize())
		{
			dest.insert(iter->payload);
			//experimental suggest not to uncomment this section..
			//payload *dat=(payload*)dest.list->payload;
			//printf("%s\n",dat->str);
			iter=iter->next;

		}
	}
	
void insert(void *food)
	{
		if(food!=NULL){
		list=list->attach_next(food);
		nodes+=1;}
		else
			{puts("null pointer cant be listed..");
		return;}
	}
	linked_list *getFirstNode()
	{
		return list->get_root()->next;
	}
	int getsize()
	{return (nodes-1);}
void destroy()
	{
		printf("\n\n FUNCTION DESTROY CALLED..");
		if(list->next==NULL && list->prev==NULL)
		{
			puts("\nLIST_LINKED::OPERATION::destroy()->list empty ...nothing to destroy");
			return;
		}

		while(getsize()!=0)
		{
			printf("\nLIST_LINKED::OPERATION::destroy()-> list node mem block:0x%x size remaining(%d)",list,getsize());

			list=list->prev;
			free(list->next);
			list->next=NULL;
			nodes-=1;

		}
		printf("\nseed node block:%x list r/w header node:%x",root,list);
		/*copyNode(list,dummyPtr);
		list=dummyPtr;
		*/
		
	//	printf("\n\n data::lost%x %x %x",list,root,dummyPtr);

		printf("\nremaining nodes:%d list seed block :0x%x",getsize(),root);
		//printf("\n\nlist data::%x",list->next);
	}
	void viewAll(bool newline)
	{
		linked_list *dummyPtr=root;
		if(newline==false)
		while(dummyPtr!=NULL)
		{
			//printf("||tree NODE:0x%x # list NODE:0x%x|||==>",dummyPtr->payload,dummyPtr->my);
			dummyPtr=dummyPtr->next;
		}
		else
			while(dummyPtr!=NULL)
		{
			printf("|tree NODE:0x%x # list NODE:0x%x||",dummyPtr->payload,dummyPtr->my);
			printf("\n || \n");printf(" \\/ \n");
			dummyPtr=dummyPtr->next;
		}
		printf("XXXNULL");
	}
	bool isEmpty()
	{
		return (getsize()==0 ? true:false);
	}
	
};

class STACK_CHILD
{
	linked_list *top;
	int stacks;
	linked_list* get_end()
	{
		linked_list *dummyPtr=top;
		while(dummyPtr->prev!=NULL)
		{
			dummyPtr=dummyPtr->prev;
		}
		return dummyPtr;

	}
public:
	STACK_CHILD()
	{
	top=init_List();
	//printf("\n0x%x",top);
	stacks=1;
	}
	
	void push(void *link)
	{
		linked_list* tmp=init_List();
		tmp->payload=link; //link to payload..
		tmp->prev=top;  //backlink
		top=tmp;
		stacks+=1;
	}
	void* pop()
	{
		void *tmp;
		tmp=top->payload;
		
		/*payload *data=(payload*)tmp;
		printf("\ndata :%s",data->str);
		*/

		linked_list *iter=top;
		if(top->prev!=NULL)
				{
				top=top->prev;  //mov to prev node
				//printf("\n0x%x",iter);
				free(iter);
				//puts("payload deleted");
				stacks-=1;
				return tmp;
				}
		else
			{puts("STACK::OPERATION::pop()->null exception in stack operation...");
		
			if(top->payload!=NULL)
				{free(top->payload);
				top->payload=NULL;
				}
		top->next=top->prev=NULL;
		}

	}
	void invert()
	{
		STACK_CHILD *stack;
		linked_list *list_buffer=(linked_list*)malloc(sizeof(linked_list)*stacks),*dummyPtr=top;

		for(int i=0;i<stacks;i++)
		{
			list_buffer[i].payload=pop();
		}
		for(int i=(stacks-1);i<=0;i--)
		{
			push(list_buffer[i].payload);
		}
	}
	void viewStack()
	{
		if(top->prev==NULL && top->next==NULL) //first stack payload ...no data member further..
		{
			puts("STACK::OPERATION::viewstack()->!error----stack empty..");
			return;
		}
		else
		{
		linked_list *dummyPtr=top;
		do
		{
			printf("\nSTACK::OPERATION::viewstack()->stack element (payload)mem block.:0x%x stack node at:0x%3x",dummyPtr->payload,dummyPtr);
			dummyPtr=dummyPtr->prev;
		}while(dummyPtr->next!=NULL);
	}
	}
	int get_stack()
	{ return (stacks-1);}
	void clearStack()
	{
		if(!isEmpty())
		{ 
			while(get_stack()!=0)
			{
				pop();
			}
		}
		else
		{
			printf("\nSTACK::OPERATION::clearstack()->stack is empty");
			return ;
		}
	}

	bool isEmpty()
	{
		return (get_stack()==0 ? true:false);
	}

};

#endif
