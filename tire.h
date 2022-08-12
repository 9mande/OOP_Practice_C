#ifndef TIRE_H_
#define TIRE_H_

#include "object.h"

typedef struct _Tire Tire;

/* Tire class extends object class*/
struct _Tire{
	Object super;

	/* Field */
	unsigned int radius;
	char* company;
	bool rolling;

	/* Method */
	void (*roll)(Tire *tire);
	void (*stop)(Tire *tire);
};


Tire* tire_constructor(unsigned int radius, char* company);
void tire_init(Tire *tire, unsigned int radius, char* company);
void tire_roll(Tire *tire);
void tire_stop(Tire *tire);
void tire_delete(Tire *tire);


/* 생성자 */
Tire* tire_constructor(unsigned int radius, char* company)
{
	Tire *tire = (Tire*)malloc(sizeof(Tire));

	tire_init(tire, radius, company);

	return tire;
}

/* init */
void tire_init(Tire *tire, unsigned int radius, char* company)
{
	Object *object = (Object*) tire;

	object_init(object);

	tire->radius = radius;
	tire->company = company;
	tire->rolling = false;

	tire->roll = tire_roll;
	tire->stop = tire_stop;
}

void tire_roll(Tire *tire)
{
	printf("Tire Roll\n");
	tire->rolling = true;
}

void tire_stop(Tire *tire)
{
	printf("Tire Stop\n");
	tire->rolling = false;
}

void tire_delete(Tire *tire)
{
	free(tire);
}


#endif