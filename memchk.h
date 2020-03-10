#ifndef _MEMCHK_H
#define _MEMCHK_H


#include <iostream>
using std::cout;
using std::endl;

struct MEM
{
	void*	addr;
	int		line;
	char	name[256];
};

MEM mem[1024];
int count = 0;

void* operator new(size_t sz, char* file, int line)
{
	void* p = malloc(sz);

	mem[count].addr = p;
	mem[count].line = line;

	strcpy(mem[count].name, file);

	++count;

	return p;
}

void operator delete(void* p)
{
	for(int i = 0 ; i < count ; ++i)
	{
		if(p == mem[i].addr)
		{
			mem[i] = mem[count-1];
			--count;
			break;
		}
	}
	free(p);
}

int debug_main();

int main()
{
	debug_main();
	
	if(count == 0)
	{
		cout << "NO MEMORY LEAK" << endl;
	}
	else
	{
		cout << "DETECTED MEMORY LEAK : " << count << endl;
		for(int i = 0 ; i < count ; ++i)
		{
			cout << mem[i].name << "(" << mem[i].line << ") : " << mem[i].addr << endl;
		}
	}
}

#define new new(__FILE__, __LINE__)

#define main debug_main


#endif//_MEMCHK_H