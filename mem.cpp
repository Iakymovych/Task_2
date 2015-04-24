#include "mem.h"
#include <stdlib.h>

void * my_mem(size_t size){
	if (size == 0){
		return NULL;
	}
	beg = malloc(size);
	if (beg != NULL){
		element = (struct el *) beg;
		if (element != NULL)
		{
			s = size;
			a = 0;
			s_el = 0;
			
			element[a].address = 0;
			element[a].free = 0;
			element[a].size = sizeof(S);
			a++;
		}
		return beg;
	}
	else{
		return NULL;
	}
}

unsigned my_malloc(size_t size){
	if (size > (s - s_el))
	{
		return NULL;
	}
	for (unsigned i = 0; i < a; ++i)
	{
		if (!element[i].free && element[i].size >= size)
		{
			if (element[i].size > size)
			{
				a++;
				for (unsigned j = i + 2; j < a; j++){
					if (j == 0)
						element[j].address = 0;
					else
						element[j].address = element[j - 1].address;
					element[j].size = element[j - 1].size;
					element[j].free = element[j - 1].free;
				}
				element[i + 1].size = element[i].size - size;
				element[i + 1].free = 0;
			}
			if (i == 0)
				element[i].address = 0;
			else
				element[i].address = element[i - 1].size;
			element[i].free = 1;
			element[i].size = size;
			element[i + 1].address = element[i].address + size;
			s_el += size;
			return element[i].address;
		}
	}
	element[a].free = 1;
	element[a].address = element[a - 1].address + element[a - 1].size;
	element[a].size = size;
	s_el += size;
	a++;
	return element[a - 1].address;
}

void my_free(unsigned pointer)
{
	for (unsigned i = 0; i < a; ++i)
		if ((element[i].address == pointer) && (element[i].free))
		{
			element[i].free = 0;
			s_el -= element[i].size;
			if ((i > 0) && (i < a))
			{
				if ((!element[i - 1].free) && (!element[i].free))
				{
					element[i - 1].size += element[i].size;
					for (unsigned j = i; j < a; j++)
					{
						element[j].address = element[j + 1].address;
						element[j].free = element[j + 1].free;
						element[j].size = element[j + 1].size;
					}
					a--;
				}
			}
			if ((a == (i + 1)) && (!element[i].free))
			{
				element[i].address = NULL;
				element[i].size = NULL;
				element[i].free = NULL;
				--a;
			}
			break;
		}
}


void my_map(){
	for (unsigned i = 0; i < a; ++i)
	{
		printf("   %d\t\t%X\t\t%d\t\t%d\n", element[i].address,
		(unsigned)beg + element[i].address,
		element[i].size, element[i].free);
	}
	printf("\n FREE memory %d\n", (s - s_el));
	printf("\n");
}

void free_mem(){
	if (!beg){
		return ;
	}
	free(element);
}