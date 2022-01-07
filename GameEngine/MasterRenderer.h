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
	void prepare() const;
	void cleanUp() const;
	void prepareInstance(const Model& model) ;
public:
	MasterRenderer(MasterRenderer& other) = delete;
	void operator=(const MasterRenderer& other) = delete;

	static MasterRenderer* getInstance(StaticShader* shader);
	void render(const Model& model, const std::vector<PointLight>& lights, const std::vector<DirLight>& dirLights);
	void render(const IndexedModel& model, const std::vector<PointLight>& lights, const std::vector<DirLight>& dirLights);
};

#endif

