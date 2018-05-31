#ifndef INC_3DSHOWCASE_CAMERA_H
#define INC_3DSHOWCASE_CAMERA_H
#include <cglm/cglm.h>

#define YAW          -90.0f;
#define PITCH         0.0f;
#define SPEED         2.5f;
#define SENSITIVITY   0.1f;
#define ZOOM          45.0f;

enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

struct Camera {
	float Yaw;
	float Pitch;

	float MovementSpeed;
	float MouseSensitivity;
	float Zoom;

	vec3 Position;
	vec3 Front;
	vec3 Up;
	vec3 Right;
	vec3 WorldUp;
};
struct Camera createCamera(vec3 position);
void getViewMatrix(struct Camera * camera, mat4 result);
void processKeyboard(struct Camera * camera, enum Camera_Movement direction, float deltaTime);
void processMouseMovement(struct Camera * camera, float xOffset, float yOffset);

#endif //INC_3DSHOWCASE_CAMERA_H
