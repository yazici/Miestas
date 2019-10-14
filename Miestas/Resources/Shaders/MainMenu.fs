#version 330 core

out vec4 FragColor;

in vec2 fTexCoords;

uniform sampler2D texture1;

void main()
{
	//FragColor = vec4(0.2, 0.2, 0.3, 1.0);
	FragColor = texture(texture1, fTexCoords);
}