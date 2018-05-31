#include <camera.h>
#include <cglm/cglm.h>

void updateCameraVectors(struct Camera * camera) {
	vec3 front = {0.0f, 0.0f, 0.0f};
	front[0] = cosf(glm_rad(camera->Yaw)) * cosf(glm_rad(camera->Pitch));
	front[1] = sinf(glm_rad(camera->Pitch));
	front[2] = sinf(glm_rad(camera->Yaw)) * cosf(glm_rad(camera->Pitch));
	glm_vec_normalize_to(front, camera->Front);

	vec3 current;
	glm_vec_cross(camera->Front, camera->WorldUp, current);
	glm_vec_normalize_to(current, camera->Right);

	glm_vec_cross(camera->Right, camera->Front, current);
	glm_vec_normalize_to(current, camera->Up);

}

struct Camera createCamera(vec3 position) {
	struct Camera camera;
	glm_vec_copy(position, camera.Position);
	glm_vec_copy((vec3){0.0f, 1.0f, 0.0f}, camera.WorldUp);
	camera.Yaw = YAW;
	camera.Pitch = PITCH;
	camera.MouseSensitivity = SENSITIVITY;
	camera.MovementSpeed = SPEED;
	camera.Zoom = ZOOM;
	updateCameraVectors(&camera);
	return camera;
}

void processKeyboard(struct Camera * camera, enum Camera_Movement direction, float deltaTime)
{
	float velocity = camera->MovementSpeed * deltaTime;
	if (direction == FORWARD)
		glm_vec_muladds(camera->Front, velocity, camera->Position);
	if (direction == BACKWARD)
		glm_vec_muladds(camera->Front, -velocity, camera->Position);
	if (direction == LEFT)
		glm_vec_muladds(camera->Right, -velocity, camera->Position);
	if (direction == RIGHT)
		glm_vec_muladds(camera->Right, velocity, camera->Position);
}
void processMouseMovement(struct Camera * camera, float xOffset, float yOffset) {
	xOffset *= camera->MouseSensitivity;
	yOffset *= camera->MouseSensitivity;

	camera->Yaw += xOffset;
	camera->Pitch += yOffset;

	if (camera->Pitch > 89.0f) {
		camera->Pitch = 89.0f;
	}
	if (camera->Pitch < -89.0f) {
		camera->Pitch = -89.0f;
	}
	updateCameraVectors(camera);
}

void getViewMatrix(struct Camera * camera, mat4 result) {
	vec3 sum;
	glm_vec_add(camera->Position, camera->Front, sum);
	glm_lookat(camera->Position, sum, camera->Up, result);
}
