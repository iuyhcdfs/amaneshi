#include "Graphics_Interface.hpp"
#include "Graphics_Window.hpp"
#include <Math_Position.hpp>

namespace amaneshi 
{
	namespace graphics
	{
		static const int DimensionCount = 3;


		void Sphere::CompileShaders()
		{
			if (!Shader.IsConfigured)
			{
				Shader.Location = &Center->x;
				Shader.Radius = this->Radius;
				Shader.IsConfigured = true;
			}
			Shader.CompileShaders();
		}

		void Sphere::Render()
		{
			// this is where we could 
			this->Shader.Draw();
		}


		void Polygon::CompileShaders()
		{
			Shader.PointCount = this->Points.size();
			Shader.Points = new float[Shader.PointCount * DimensionCount];
			int i = 0;
			for (amaneshi::math::Point p : this->Points)
			{
				Shader.Points[i++] = p.x;
				Shader.Points[i++] = p.y;
				Shader.Points[i++] = p.z;
			}
			Shader.CompileShaders();
		}

		void Polygon::Render()
		{
			this->Shader.Draw();
		}
	}
}