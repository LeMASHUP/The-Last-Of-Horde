#include <h3.h>
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#include "playercomponent.h"
#include "zombiecomponent.h"
#include "bulletcomponent.h"
#include "components\spritecomponent.h"
#include "components\cameracomponent.h"
#include "components\maplayercomponent.h"


#ifndef NDEBUG
# pragma comment(lib, "h3-s-d.lib")
#else // !NDEBUG
# pragma comment(lib, "h3-s.lib")
#endif // !NDEBUG

char bullet_name[15];
int index_bullet = 0;

int width;
int height;
float playerx;
float playery;
float dx;
float dy;
float bx;
float by;
float px;
float py;
float angle;
int mousex;
int mousey;
int gunstate = 0;
float playerid;
int ammo = 10;
int ammoleft = 35;


int main(int argc, char** argv)
{
	width = 1920;
	height = 1080;


	//SH3Component cam = CAMERACOMPONENT_CREATE(playery, playerx);


	H3Handle h3 = H3_Init((SH3InitParams) {
		.fullscreen = true,
			.height = height,
			.width = width,
			.windowTitle = "The Last of Horde Hydrogen Engine 3"
	});


	H3Handle scene = H3_Scene_Create(h3, true);
	H3Handle player = H3_Object_Create(scene, "player", NULL);
	H3Handle cameraroot = H3_Object_Create(scene, "cameraroot", NULL);

	
	
	H3_Object_AddComponent(player, SPRITECOMPONENT_CREATE("assets/Playerglock.png", 0x22));
	H3_Object_SetRenderOrder(player, 1);
	H3_Object_Translate(player, 0, 0);
	//H3_Object_EnablePhysics(player, H3_BOX_COLLIDER(CDT_Dynamic, 32, 32, 0x22, false));
	H3_Object_AddComponent(player, PLAYERCOMPONENT_CREATE(scene));
	H3_Object_GetComponent(player, playerid);

	

	H3Handle accueil_map = H3_Map_Load("assets/maptest.tmx"); // une sorte d'accès à ta map (n'est pas la map dans la scène, la charge uniquement)
	H3Handle map1 = H3_Object_Create(scene, "map1", NULL); //Crée la map dans la scène -> différent d'en haut qui load uniquement (celle ci va permettre de la place dans la scène)
	H3_Object_AddComponent(map1, MAPLAYERCOMPONENT_CREATE(accueil_map, "background")); //Comme pour les collisions, sauf qu'ici tu appelles un composant pour afficher ton layer décoratif (fond et sol du jeu)
	H3_Map_RegisterObjectLayerForPhysicsInScene(scene, accueil_map, "collisions"); //dans ta map Tiled tu as des layers, dont un qui doit s'appeler collisions (celui que tu appelles du coup)

	H3_Object_AddComponent(cameraroot, CAMERACOMPONENT_CREATE(playerx, playery));

	while (H3_DoFrame(h3, scene)) {

		H3_Transform_GetPosition(H3_Object_GetTransform(player), &playerx, &playery);
		H3_Input_GetMousePos(h3, &mousex, &mousey);
		dy = mousey - playery;
		dx = mousex - playerx;
		angle = atan2(dy, dx) * 180 / 3.141593;
		H3_Object_SetRotation(player, angle);
		printf("%f\n", angle);


		if (H3_Input_IsKeyPressed(K_Down)) {
			gunstate = 1;
		}

		if (gunstate = 1) {
			H3_Object_RemoveComponent(player, playerid);
			
		}

		if (ammo > 0) {

			if (H3_Input_IsMouseBtnPressed(MB_Right)) {
				snprintf(bullet_name, 15, "%d", index_bullet++);
				H3Handle bullet = H3_Object_Create(scene, bullet_name, NULL);
				H3_Object_EnablePhysics(bullet, H3_BOX_COLLIDER(CDT_Dynamic, 5, 5, 0x22, true));
				H3_Object_SetTranslation(bullet, playerx, playery+4);
				H3_Object_AddComponent(bullet, SPRITECOMPONENT_CREATE("assets/ammo.png", A_Center));
				//H3_Object_AddComponent(bullet, BULLETCOMPONENT_CREATE());
				H3_Object_AddVelocity(bullet, dx, dy);
				H3_Object_GetVelocity(bullet, &bx, &by);
				H3_Object_SetVelocity(bullet, bx, by);
				ammo -= 1;
			}
			else {
				if (ammoleft > 0) {
					//wait(3);
					ammoleft -= 10;
					ammo += 10;
				}
			}
		}

		if (H3_Input_IsKeyDown(K_S)) {
			H3_Object_Translate(player, 0, 1);
			//H3_Object_Translate(glock, 0, 1);
		}

		if (H3_Input_IsKeyDown(K_D)) {
			H3_Object_Translate(player, 1, 0);
			//H3_Object_Translate(glock, 1, 0);
		}

		if (H3_Input_IsKeyDown(K_Q)) {
			H3_Object_Translate(player, -1, 0);
			//H3_Object_Translate(glock, -1, 0);
		}

		if (H3_Input_IsKeyDown(K_Z)) {
			H3_Object_Translate(player, 0, -1);
			//H3_Object_Translate(glock, 0, -1);
		}
	}
	return 0;
}
