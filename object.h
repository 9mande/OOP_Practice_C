#ifndef OBJECT_H_
#define OBJECT_H_

typedef struct _Object Object;

/* Tire Class */
struct _Object{
	/* Field */

	/* Method */
	unsigned long long (*address)(Object *object);
	bool (*equals)(Object *this, Object *object);
};


Object* object_constructor();
void object_init(Object *object);
unsigned long long object_address(Object *object);
bool object_equals(Object *this, Object *object);
void object_delete(Object *object);

/* 생성자 */
Object* object_constructor()
{
	Object *object = (Object*)malloc(sizeof(Object));

	object_init(object);

	return object;
}

/* init */
void object_init(Object *object)
{
	object->address = object_address;
	object->equals = object_equals;
}

unsigned long long object_address(Object *object)
{
	return object;
}

bool object_equals(Object *this, Object *object)
{
	return this == object;
}

void object_delete(Object *object)
{
	free(object);
}


#endif