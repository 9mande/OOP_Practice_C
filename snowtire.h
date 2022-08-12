#ifndef SNOWTIRE_H_
#define SNOWTIRE_H_

#include "tire.h"

typedef struct _Snowtire Snowtire;

struct _Snowtire{
	Tire super;

	unsigned int chains;
};


Snowtire* snowtire_constructor(unsigned int radius, char* company, unsigned chains)
{
	Snowtire *snowtire = malloc(sizeof(Snowtire));

	Tire *tire = (Tire*) snowtire; // Super Class로 바꿔서 속성 물려받기
	tire->radius = radius;
	tire->company = company;
	tire->rolling = false;

	tire->roll = tire_roll; // 오버라이딩은 이 함수를 변경하면 될 것 같다.
	tire->stop = tire_stop;

	snowtire->chains = 5;   // 확장

	return snowtire;
}



#endif