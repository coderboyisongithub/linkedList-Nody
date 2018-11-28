#include "stdafx.h"
#include "Nody.h"


STACK_CHILD stack;

struct payload
{
	int data;
};
void main()
{
	payload *pkg=(payload*)malloc(sizeof(payload)); //first one 
	
	pkg->data=10;
	
	stack.push((void*)pkg);  //pushing to stack..
	
	pkg=(payload*)malloc(sizeof(payload)); //another one
	pkg->data=20;
	
	stack.push((void*)pkg);

	printf("stack size:%d",stack.get_stack());

	payload *pop;
	while(!stack.isEmpty())
	{
		pop=(payload*)stack.pop();
		printf("payload data:%d",pop->data);
	}

	_getch();

}
