#version 400 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 texCoord;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

out vec2 v_texCoord;
out vec3 fragPos;
out vec3 normal;

void main()
{
	fragPos = vec3(model * vec4(aPos, 1.0));
	normal = mat3(transpose(inverse(model))) * aNormal;
	gl_Position = projection * view * vec4(fragPos, 1.0);
	v_texCoord = texCoord;
}