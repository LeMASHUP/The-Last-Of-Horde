#include "playercomponent.h"
#include <stdlib.h>

typedef struct
{
	int bip;
	H3Handle Scene;
} PlayerComponent_Properties;

void PlayerComponent_Terminate(void* properties)
{
	free(properties);
}

void PlayerComponent_Update(H3Handle h3, SH3Transform* transform, void* properties) {
	PlayerComponent_Properties* props = (PlayerComponent_Properties*)properties;
}

void* PlayerComponent_CreateProperties(H3Handle scene)
{
	PlayerComponent_Properties* properties = malloc(sizeof(PlayerComponent_Properties));
	H3_ASSERT_CONSOLE(properties, "Failed to allocate properties");
	properties->Scene = scene;
	return properties;
}

void Player_Component_Collisions(H3Handle object, SH3Collision collisions) {
	//if (H3_Object_HasComponent(collisions.other, ))
}
