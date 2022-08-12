#ifndef SNOWTIRE_H_
#define SNOWTIRE_H_

#include "tire.h"

typedef struct _Snowtire Snowtire;

struct _Snowtire{
	Tire super;

	unsigned int chains;
};

Snowtire* snowtire_constructor(unsigned int radius, char* company, unsigned chains);
void snowtire_init(Snowtire *snowtire, unsigned int radius, char* company, unsigned chains);
void snowtire_delete(Snowtire *snowtire);

Snowtire* snowtire_constructor(unsigned int radius, char* company, unsigned chains)
{
	Snowtire *snowtire = (Snowtire*)malloc(sizeof(Snowtire));

	snowtire_init(snowtire, radius, company, chains);

	return snowtire;
}

void snowtire_init(Snowtire *snowtire, unsigned int radius, char* company, unsigned chains)
{
	Tire *tire = (Tire*) snowtire;						// Super Class로 바꿔서 속성 물려받기
	
	tire_init(tire, radius, company);					// Super init

	snowtire->chains = 5;								// 확장
}

void snowtire_delete(Snowtire *snowtire)
{
	free(snowtire);
}


#endif