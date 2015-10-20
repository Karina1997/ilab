#include<stdlib.h>
#include<stdio.h>
#include <assert.h>
struct steak//right is stack 
{
	int leng;
	int pos;
	char * st;
};

/*
	1. First of all, if you are not clear about what is the .h and .c files, ask me.
	2. There are no checks, Ilya Ded told you a lot about.
 	3. Names of variables should be clear. 
*/
bool steak_ok(steak * ps);
void steak_dump(steak * ps);
void steak_ctor(steak * ps);
void steak_dtor(steak * ps);
void push(steak * ps, char c);
void pop(steak * ps);
char peek(steak * ps);

int main()
{
	steak ps;
    steak *pps = &ps;
	steak_ctor(pps);
	char c = 'a';
	push(pps, c);
	 c = 'b';
	push(pps, c);
	c = 'v';
	push(pps, c);
	pop(pps);
	printf("bool: %d",steak_ok(pps));
	steak_dump(pps);
	system("pause");
}

bool steak_ok(steak * ps)
{
	return ps && ps->leng && ps->pos && ps->st;//unappropriate checks. Check if leng or pos < 0 also. 
}

void steak_dump(steak * ps)
{
	printf("\nlen:%d, pos:%d , el:%c, \nFull steak:", ps->leng, ps->pos, *(ps->st + ps->pos - 1 ));
	for (int i= 0; i < ps->pos; i++) printf("%c, ",*(ps->st + i ));
}

void steak_ctor(steak * ps)
{
	assert(ps);
	ps->st = (char*) malloc ( 10 * sizeof(char));//checks after malloc
	ps->pos = 0;
	ps->leng = 10;//checks

}

void steak_dtor(steak * ps)
{
	free(ps->st);//checks
	ps->pos = 0;
	ps->leng = 0;

}

void push(steak * ps, char c)
{//where are checks?(stack_ok)
	if  ((ps->pos) < (ps->leng))
	{
		*(ps->st + (ps->pos)) = c;
	}
	else 
	{
		ps->st = (char*) realloc (ps->st, 10 * sizeof(char));// it will change to 10 bytes, but not add 10 more bytes.
		ps->leng += 10;// ps->st is changed. you need to copy whole stack. 
		*(ps->st + ps->pos) = c;
	}//after all. checks also should be
	ps->pos++;
}


void pop(steak * ps)
{//checks
	if (ps->pos == 0) 
	{
		printf("STACK_UNDERFLOW"); 
		abort();
	}
	else 
	{
		ps->pos--;
		*(ps->st + ps->pos) = 0;
	}
}

char peek(steak * ps)
{//checks that stack is ok
	if (ps->pos == 0) 
	{
		printf("STACK_UNDERFLOW"); 
		abort();
	}
	else 
		return *(ps->st + ps->pos- 1);ps->st[ps->pos]
}
