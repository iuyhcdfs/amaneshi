#include "Graphics_Primitives.hpp"
#include "Graphics_Interface.hpp"


static const int Temp_dimensionCount = 3;

void amaneshi::graphics::Polygon::CompileShaders()
{
	if (amaneshi::graphics::API == "opengl")
	{
		GLShader.PointCount = this->Points.size();
		GLShader.Points = new float[GLShader.PointCount * Temp_dimensionCount];
		int i = 0;
		for (Point p : this->Points)
		{
			GLShader.Points[i++] = p.x;
			GLShader.Points[i++] = p.y;
			GLShader.Points[i++] = p.z;
		}
		GLShader.CompileShaders();
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
