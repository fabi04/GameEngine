#include "StaticShader.h"
#include <sstream>

void StaticShader::getAllUniformLocations()
{
	_location_modelMatrix = Shader::getUniformLocation("model");
	_location_projectionMatrix = Shader::getUniformLocation("projection");
	_location_viewMatrix = Shader::getUniformLocation("view");
	_location_materialDiffuse = Shader::getUniformLocation("material.diffuse");
	_location_materialSpecular = Shader::getUniformLocation("material.specular");
	_location_materialShininess= Shader::getUniformLocation("material.shininess");

	for (unsigned int i = 0; i < MAXLIGHTS; i++)
	{
		std::stringstream lightPos;
		lightPos << "pointLights[" << i << "].position";
		_location_lightPos[i] = Shader::getUniformLocation(lightPos.str());
		std::stringstream ambient;
		ambient << "pointLights[" << i << "].ambient";
		_location_lightAmbient[i] = Shader::getUniformLocation(ambient.str());
		std::stringstream diffuse;
		diffuse << "pointLights[" << i << "].diffuse";
		_location_lightDiffuse[i] = Shader::getUniformLocation(diffuse.str());
		std::stringstream specular;
		specular << "pointLights[" << i << "].specular";
		_location_lightSpecular[i] = Shader::getUniformLocation(specular.str());
		std::stringstream constant;
		constant << "pointLights[" << i << "].constant";
		_location_lightConstant[i] = Shader::getUniformLocation(constant.str());
		std::stringstream linear;
		linear << "pointLights[" << i << "].linear";
		_location_lightLinear[i] = Shader::getUniformLocation(linear.str());
		std::stringstream quadratic;
		quadratic << "pointLights[" << i << "].quadratic";
		_location_lightQuadratic[i] = Shader::getUniformLocation(quadratic.str());
	}
}

void StaticShader::bindAttributes()
{
	Shader::bindAttribute(0, "position");
}

StaticShader::StaticShader(const char* vertexFile, const char* fragmentFile) : Shader(vertexFile, fragmentFile)
{
	getAllUniformLocations();
}

void StaticShader::loadViewMatrix(const Camera& camera) 
{
	Shader::loadMat4(_location_viewMatrix, camera.getViewMatrix());
}

void StaticShader::loadProjectionMatrix(const glm::mat4& projection)
{
	Shader::loadMat4(_location_projectionMatrix, projection);
}

void StaticShader::loadModelMatrix(const glm::mat4& model)
{
	Shader::loadMat4(_location_modelMatrix, model);
}

void StaticShader::loadLights(const std::vector<Light>& lights)
{
}

//void StaticShader::loadLights(const std::vector<Light>& lights)
//{
//	Shader::loadFloat(_location_maxLights, MAXLIGHTS);
//	for (unsigned int i = 0; i < MAXLIGHTS; i++)
//	{
//		if (i < lights.size())
//		{
//			Shader::loadVec3(_location_lightPos[i], lights[i].pos);
//			Shader::loadVec3(_location_lightColor[i], lights[i].getColor());
//			Shader::loadVec3(_location_attenuation[i], lights[i].getAttenuation());
//		}
//		else
//		{
//			Shader::loadVec3(_location_lightPos[i], {0.0f, 0.0f, 0.0f});
//			Shader::loadVec3(_location_lightColor[i], {0.0f, 0.0f, 0.0f});
//			Shader::loadVec3(_location_attenuation[i], {1.0f, 0.0f, 0.0f});
//		}
//	}
//}

void StaticShader::loadPointLights(const std::vector<PointLight>& lights)
{
	for (unsigned int i = 0; i < 1; i++)
	{
		if (i < lights.size())
		{
			Shader::loadVec3(_location_lightPos[i], lights[i].pos);
			Shader::loadVec3(_location_lightDiffuse[i], lights[i].diffuse);
			Shader::loadVec3(_location_lightAmbient[i], lights[i].ambient);
			Shader::loadVec3(_location_lightSpecular[i], lights[i].specular);
			Shader::loadFloat(_location_lightConstant[i], lights[i].constant);
			Shader::loadFloat(_location_lightLinear[i], lights[i].linear);
			Shader::loadFloat(_location_lightQuadratic[i], lights[i].quadratic);

		}
		else
		{
			Shader::loadVec3(_location_lightPos[i], {});
			Shader::loadVec3(_location_lightDiffuse[i], {});
			Shader::loadVec3(_location_lightAmbient[i], {});
			Shader::loadVec3(_location_lightSpecular[i], {});
		}
	}
}

void StaticShader::loadMaterial(const BaseModel& model)
{
	Material material = model.getMaterial();
	Shader::loadInt(_location_materialDiffuse, 0);
	Shader::loadInt(_location_materialSpecular, 1);
	Shader::loadFloat(_location_materialShininess, material.shininess);

}


