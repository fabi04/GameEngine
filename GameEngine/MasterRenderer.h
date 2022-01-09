#pragma once
#ifndef MASTERRENDERER
#define MASTERRENDERER
#include <memory>
#include "StaticShader.h"
#include "Entity.h"
#include "Light.h"

class MasterRenderer
{
protected:
	MasterRenderer(StaticShader* shader);
private:
	StaticShader* _shader;
	static std::shared_ptr<MasterRenderer> _instance;
	std::vector<PointLight> _lights;
	std::vector<DirLight> _dirLights;
	std::vector<Model> _models;

	void prepare() const;
	void cleanUp() const;
	void prepareInstance(const Model& model) ;
public:
	MasterRenderer(MasterRenderer& other) = delete;
	void operator=(const MasterRenderer& other) = delete;
	template <class T> void add(const T& instance);
	static MasterRenderer* getInstance(StaticShader* shader);
	void prepareRender() const;
	void render(const Model& model);
	//void render(const IndexedModel& model);
};

#endif

