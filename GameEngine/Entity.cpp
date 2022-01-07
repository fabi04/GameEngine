#include "Entity.h"

Entity::Entity::Entity(std::shared_ptr<Model> model) : _model(model)
{
	rotX = rotY = _scale = 0.0;
	textureIndex = 0;
}

Entity::Entity::Entity()
{
}

int Entity::Entity::getRotX()
{
	return rotX;
}

int Entity::Entity::getRotY()
{
	return rotY;
}

void Entity::Entity::setRotX(float rot)
{
	rotX = rot;
}

void Entity::Entity::setRotY(float rot)
{
	rotY = rot;
}

float Entity::Entity::getScale()
{
	return _scale;
}

void Entity::Entity::setScale(float scale)
{
	_scale = scale;
}

std::shared_ptr<Model> Entity::Entity::getRawModel()
{
	return _model;
}

Entity::Entity3D::Entity3D(glm::vec3& pos, float rotX, float rotY, float rotZ) : _pos(pos), rotZ(rotZ)
{
	rotX = rotX;
	rotY = rotY;
}

Entity::Entity3D::Entity3D(glm::vec3& pos, std::shared_ptr<Model> model) : _pos(pos)
{
	_model = model;
}

Entity::Entity3D::Entity3D(std::shared_ptr<Model> model)
{
	_model = model;
}

void Entity::Entity3D::increasePos(float dX, float dY, float dZ)
{
	_pos.x += dX;
	_pos.y += dY;
	_pos.z += dZ;
}

void Entity::Entity3D::setPos(glm::vec3& pos)
{
	_pos = pos;
}

void Entity::Entity3D::increaseRot(float dx, float dy, float dz)
{
	rotX += dx;
	rotY += dy;
	rotZ += dz;
}

glm::vec3 Entity::Entity3D::getPos()
{
	return _pos;
}

void Entity::Entity3D::setRot(glm::vec3& rot)
{

}

int Entity::Entity3D::getRotZ()
{
	return rotZ;
}

void Entity::Entity3D::setRotZ(float dz)
{
	rotZ = dz;
}
