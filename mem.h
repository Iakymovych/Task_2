#ifndef mem
#include <stdio.h>
#define S size_t        // size of elements
#define true int

//el of memory
struct el{
	unsigned size;
	unsigned address;
	true free; //busy or no
};

static void *beg;         //begin my heap
static unsigned s;       //size my heap
static unsigned a = 0;
static unsigned	s_el = 0;  // size of element
static struct el * element = NULL;

/**
* @brief function to create heap
* @param  size  size of HEAP
* @return       pointer to begin of heap
*/
void* my_mem(size_t size);

/**
* @brief allocate memory el
* @param  size size of el in bytes
* @return      pointer to allocated el or NULL
*/
unsigned my_malloc(size_t size);

/**
* @brief  deallocatr memory el
* @param  pointer  pointer to a memory el previously allocated with malloc
*/
void my_free(unsigned pointer);

/**
* @brief  function clear our heap
* @return none
*/
void free_mem();

/**
* @brief  function to show memory map
* @return  none
*/
void my_map();




#endif 