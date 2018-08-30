#include "Graphics_Interface.hpp"
#include "Graphics_Window.hpp"
#include <Amaneshi/External_Modes.hpp>
#include <Amaneshi/Internal/Math_Position.hpp>

namespace amaneshi 
{
	namespace graphics
	{
		static const int DimensionCount = 3;

		void Polygon::CompileShaders()
		{
			#ifdef GRAPHICS_OPENGL
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
			#endif
		}

		void Polygon::Render()
		{
			if (amaneshi::graphics::API == "opengl")
			{
				this->Shader.Draw();
			}
		}

		void Sphere::CompileShaders()
		{
			#ifdef GRAPHICS_OPENGL
			{
				Shader.Location = new float[1 * DimensionCount];
				Shader.Radius = 
			}
			#endif
		}
	}
}