#include <h3.h>
#include "components\spritecomponent.h"
#include "components\cameracomponent.h"
#include <stdlib.h>
#include<math.h>

#ifndef NDEBUG
# pragma comment(lib, "h3-s-d.lib")
#else // !NDEBUG
# pragma comment(lib, "h3-s.lib")
#endif // !NDEBUG

int width;
int height;

int main(int argc, char** argv)
{
	width = 1280;
	height = 720;

	char bullet_name[15];
	int index_bullet = 0;



	H3Handle h3 = H3_Init((SH3InitParams) {
		.fullscreen = false,
			.height = height,
			.width = width,
			.windowTitle = "The Last of Horde Hydrogen Engine 3"
	});


	H3Handle scene = H3_Scene_Create(h3, true);
	H3Handle player = H3_Object_Create(scene, "player", NULL);


	//H3_Object_AddComponent(player, SPRITECOMPONENT_CREATE("assets/Player.png", 0x22));
	H3_Object_SetRenderOrder(player, 1);
	H3_Object_Translate(player, width / 2, height / 2);
	H3_Object_EnablePhysics(player, H3_BOX_COLLIDER(CDT_Dynamic, 50, 50, 0x22, false));




	while (H3_DoFrame(h3, scene)) {

	}
	return 0;
}
