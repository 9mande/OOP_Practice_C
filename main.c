#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tire.h"
#include "snowtire.h"
#include "object.h"

void basicObjectTest();
void basicClassTest();
void InheritanceTest();


int main()
{
	printf("\n====== Basic Object Test ======\n");
	basicObjectTest();
	printf("\n====== Basic Class Test ======\n");
	basicClassTest();
	printf("\n====== Inheritance Test ======\n");
	InheritanceTest();
}

void basicObjectTest()
{
	Object *a = object_constructor();
	printf("object A address : %#x\n", a->address(a));

	Object *b = object_constructor();
	printf("object B address : %#x\n", b->address(b));

	printf("A == B : %s\n", a->equals(a, b) ? "true" : "false");

	Object *c = b;
	printf("object C address : %#x\n", c->address(c));	
	b = c;

	printf("B == C : %s\n", b->equals(b, c) ? "true" : "false");

	object_delete(a);
	object_delete(b);
}

void basicClassTest()
{
	Tire *tire = tire_constructor(10, "금호타이어");

	printf("<Object Instance>\n");
	printf("object tire address : %#x\n", ((Object*)tire)->address((Object*)tire));

	printf("<Tire Instance>\n");
	printf("tire->radius = %d\n", tire->radius);
	printf("tire->company = %s\n", tire->company);
	printf("tire->rolling = %s\n", tire->rolling ? "true" : "false");

	tire->roll(tire);

	printf("tire->rolling = %s\n", tire->rolling ? "true" : "false");

	tire->stop(tire);

	printf("tire->rolling = %s\n", tire->rolling ? "true" : "false");

	tire_delete(tire);
}

void InheritanceTest()
{
	Tire *tire = tire_constructor(10, "금호타이어");

	Snowtire *snowtire = snowtire_constructor(10, "한국타이어", 5);

	((Tire*)snowtire)->roll((Tire*)snowtire);
	printf("snowtire->rolling = %s\n", ((Tire*)snowtire)->rolling ? "true" : "false");

	((Tire*)snowtire)->stop((Tire*)snowtire);
	printf("snowtire->rolling = %s\n", ((Tire*)snowtire)->rolling ? "true" : "false");	

	tire_delete(tire);
}