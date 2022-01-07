#pragma once
#ifndef STATICSHADER
#define STATICSHADER
#include "Shader.h"
#include "Camera.h"
#include "Light.h"
#include "Model.h"
#define MAXLIGHTS 1

class StaticShader : public Shader
{
private:
	unsigned int _location_modelMatrix;
	unsigned int _location_projectionMatrix;
	unsigned int _location_viewMatrix;
	unsigned int _location_maxLights;
	unsigned int _location_lightPos[MAXLIGHTS];
	unsigned int _location_lightAmbient[MAXLIGHTS];
	unsigned int _location_lightSpecular[MAXLIGHTS];
	unsigned int _location_lightDiffuse[MAXLIGHTS];
	unsigned int _location_lightConstant[MAXLIGHTS];
	unsigned int _location_lightLinear[MAXLIGHTS];
	unsigned int _location_lightQuadratic[MAXLIGHTS];
	unsigned int _location_materialDiffuse;
	unsigned int _location_materialSpecular;
	unsigned int _location_materialShininess;

public:
	StaticShader(const char* vertexFile, const char* fragmentFile);
	void getAllUniformLocations() override;
	void bindAttributes() override;
	void loadViewMatrix(const Camera& camera);
	void loadProjectionMatrix(const glm::mat4& projection);
	void loadModelMatrix(const glm::mat4& model);
	void loadLights(const std::vector<Light>& lights);
	void loadPointLights(const std::vector<PointLight>& lights);
	void loadDirLights(const std::vector<DirLight>& lights);
	void loadMaterial(const BaseModel& model);
};

#endif

