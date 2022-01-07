#pragma once
#ifndef ENTITY
#define ENTITY

#include <glm.hpp>
#include <memory>
#include "Model.h"

namespace Entity
{
	class Entity
	{
	protected:
		float rotX, rotY;
		float _scale;
		int textureIndex;
		std::shared_ptr<Model> _model;
	public:
		Entity(std::shared_ptr<Model> model);
		Entity();
		int getRotX();
		int getRotY();
		void setRotX(float rot);
		void setRotY(float rot);
		float getScale();
		void setScale(float _scale);
		std::shared_ptr<Model> getRawModel();
		
	};

	class Entity3D : public Entity
	{
	private:
		glm::vec3 _pos;
		float rotZ;
	public:
		Entity3D(glm::vec3& pos, float rotX, float rotY, float rotZ);
		Entity3D(glm::vec3& pos, std::shared_ptr<Model> model);
		Entity3D(std::shared_ptr<Model> model);
		Entity3D();

		void increasePos(float dX, float dy, float dZ);
		void setPos(glm::vec3& pos);
		void increaseRot(float dx, float dy, float dz);
		glm::vec3 getPos();
		void setRot(glm::vec3& rot);
		int getRotZ();
		void setRotZ(float dz);

	};

	class Entity2D : public Entity
	{
	private:
		glm::vec2 _pos;
	public:
		Entity2D();
		Entity2D(glm::vec2& pos);
		Entity2D(glm::vec2& pos, float rotX, float rotY);
	};

};

#endif

