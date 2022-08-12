#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tire.h"
#include "snowtire.h"

void basicClassTest()
{
	Tire *tire = tire_constructor(10, "금호타이어");

	printf("<Tire Instance>\n");
	printf("tire->radius = %d\n", tire->radius);
	printf("tire->company = %s\n", tire->company);
	printf("tire->rolling = %s\n", tire->rolling ? "true" : "false");

	tire->roll(tire);

	printf("tire->rolling = %s\n", tire->rolling ? "true" : "false");

	tire->stop(tire);

	printf("tire->rolling = %s\n", tire->rolling ? "true" : "false");

	free(tire);
}

void InheritanceTest()
{
	Tire *tire = tire_constructor(10, "금호타이어");

	Snowtire *snowtire = snowtire_constructor(10, "한국타이어", 5);

	((Tire*)snowtire)->roll((Tire*)snowtire);
	printf("snowtire->rolling = %s\n", ((Tire*)snowtire)->rolling ? "true" : "false");

	((Tire*)snowtire)->stop((Tire*)snowtire);
	printf("snowtire->rolling = %s\n", ((Tire*)snowtire)->rolling ? "true" : "false");	
}


int main()
{
	printf("====== Basic Class Test ======\n");
	basicClassTest();
	printf("====== Inheritance Test ======\n");
	InheritanceTest();	
}