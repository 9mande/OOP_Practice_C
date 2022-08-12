#ifndef TIRE_H_
#define TIRE_H_

typedef struct _Tire Tire;

struct _Tire{
	void (*roll)(struct Tire *tire);
	void (*stop)(struct Tire *tire);

	unsigned int radius;
	char* company;
	bool rolling;
};


Tire* tire_constructor(unsigned int radius, char* company);
void tire_roll(Tire *tire);
void tire_stop(Tire *tire);


Tire* tire_constructor(unsigned int radius, char* company) // 생성자
{
	Tire *tire = malloc(sizeof(Tire));

	tire->radius = radius;
	tire->company = company;
	tire->rolling = false;

	tire->roll = tire_roll;
	tire->stop = tire_stop;

	return tire;
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


#endif