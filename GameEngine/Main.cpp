#define SDL_MAIN_HANDLED // avoid using main in SDL2main.lib
#include <SDL.h>
#include <Gl/glew.h>
#include <SDL_opengl.h>
#include <glm.hpp>
#include <iostream>

#ifdef _WIN32
#include <SDL.h>
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")
#else
#include <SDL.h>
#endif

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Window.h"
#include "Shader.h"
#include "MasterRenderer.h"
#include "Loader.h"
#include "Entity.h"
#include "VertexArray.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "EventListener.h"
#include "Camera.h"
#include "Light.h"


int main(int argc, char* argv[])
{
	Window* window = new Window("game", 1000, 800);
	glewExperimental = GL_TRUE;
	glewInit();


    Texture texture("..//res//container2.png");
    Texture specular("..//res//specular.png");

    Material mat = { &texture, &specular, 64.0f };
	std::vector<float> vertices;
    loadOBJ("..//res//monkey.obj", vertices);
	VertexArray va(vertices.size() / 8);
	VertexBuffer vb(&vertices[0], vertices.size() * sizeof(float));
	VertexBufferLayout layout;
	layout.push<float>(3);
	layout.push<float>(3);
    layout.push<float>(2);
	va.addBuffer(vb, layout);

	StaticShader shader = StaticShader("vertexShader.vs", "fragmentShader.fs");
	MasterRenderer* renderer = MasterRenderer::getInstance(&shader);
    Model model_(va, mat);
    PointLight light = {glm::vec3(1.2f, 1.0f, 2.0f), glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f, 0.09f, 0.032};
   // PointLight light2 = { glm::vec3(1.2f, -1.0f, -2.0f), glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f) , 1.0f, 0.09f, 0.032};
    DirLight dirLight = {glm::vec3(-0.2f, -1.0f, -0.3f), glm::vec3(0.05f, 0.05f, 0.05f), glm::vec3(0.4f, 0.04f, 0.04f), glm::vec3(0.5f, 0.5f, 0.5f)};
	Camera camera;
    glm::vec3 pos(2.0f, 2.0f, 2.0f);
    Entity::Entity3D ent(pos, std::make_shared<Model>(model_));
    renderer->add<PointLight>(light);
    renderer->add<DirLight>(dirLight);
	renderer->add<Model>(model_);
    renderer->prepareRender();
	while (!window->isClosed())
	{
        renderer->render(model_);
		camera.processInput();
		shader.loadProjectionMatrix(glm::perspective(glm::radians(45.0f), (float) window->getHeight() / (float) window->getWidth(), 0.1f, 100.0f));
		shader.loadViewMatrix(camera);
        shader.loadVec3(shader.getUniformLocation("viewPos"), camera.getPos());
		glm::mat4 model = glm::mat4(1.0f);
		//model = glm::translate(model, ent.getPos());
		shader.loadModelMatrix(model);
		window->update();
	}

	delete window;
	return 0;
}