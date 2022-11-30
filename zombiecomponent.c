#include "zombiecomponent.h"
#include <stdlib.h>

typedef struct
{
	int bip;
	H3Handle Scene;
} ZombieComponent_Properties;

void ZombieComponent_Terminate(void* properties)
{
	free(properties);
}

void ZombieComponent_Update(H3Handle h3, SH3Transform* transform, void* properties) {
	ZombieComponent_Properties* props = (ZombieComponent_Properties*)properties;
}

void* ZombieComponent_CreateProperties(H3Handle scene)
{
	ZombieComponent_Properties* properties = malloc(sizeof(ZombieComponent_Properties));
	H3_ASSERT_CONSOLE(properties, "Failed to allocate properties");
	properties->Scene = scene;
	return properties;
}

void Zombie_Component_Collisions(H3Handle object, SH3Collision collisions) {
	//if (H3_Object_HasComponent(collisions.other, ))
}
#pragma once
