R"(
#version 400

in vec3 vertexPoint;

void main() 
{
	gl_Position = vec4(vertexPoint, 1.0);
}
)"