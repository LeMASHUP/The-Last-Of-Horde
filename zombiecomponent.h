#ifndef _H3_COMPONENTS_ZOMBIECOMPONENT_H_
#define _H3_COMPONENTS_ZOMBIECOMPONENT_H_

#include <h3.h>

#define ZOMBIECOMPONENT_TYPEID 0x80000071

H3_CAPI_BEGIN_BLOCK
void ZombieComponent_Terminate(void* properties);
void ZombieComponent_Update(H3Handle h3, SH3Transform* transform, void* properties);

void* ZombieComponent_CreateProperties(H3Handle scene);
void Zombie_Component_Collisions(H3Handle Object, SH3Collision collisions);
H3_CAPI_END_BLOCK

#define ZOMBIECOMPONENT_CREATE(SCENE)                                          \
	(SH3Component) {                                                            \
		.Init               = NULL,                                                      \
		.Terminate          = ZombieComponent_Terminate,                                 \
		.Update             = ZombieComponent_Update,                                      \
		.isInitialized      = false,                                                     \
		.componentType      = ZOMBIECOMPONENT_TYPEID,                                    \
		.properties         = ZombieComponent_CreateProperties(SCENE), \
		.OnCollisionEnter = Zombie_Component_Collisions, \
	}

#endif /* _H3_COMPONENTS_ZOMBIECOMPONENT_H_ */
#pragma once
#pragma once
