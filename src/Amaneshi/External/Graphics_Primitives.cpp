#include "Graphics_Primitives.hpp"
#include "Graphics_Interface.hpp"

void amaneshi::graphics::Polygon::CompileShaders()
{
	if (amaneshi::graphics::API == "opengl")
	{
		GLShader.CompileShaders(this->Points);
	}
}

void amaneshi::graphics::Polygon::Render()
{
	if (amaneshi::graphics::API == "opengl")
	{
		this->GLShader.Draw();
	}
}

void amaneshi::graphics::Circle::Render()
{

}
