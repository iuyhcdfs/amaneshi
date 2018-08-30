#include "Graphics_Interface.hpp"
#include "Graphics_Window.hpp"
#include <Amaneshi/External_Modes.hpp>
#include <Amaneshi/Internal/Math_Position.hpp>

namespace amaneshi 
{
	namespace graphics
	{
		static const int DimensionCount = 3;


		void Sphere::CompileShaders()
		{
			#ifdef GRAPHICS_OPENGL
			{
				if (!Shader.IsConfigured)
				{
					Shader.Location = &Center->x;
					Shader.Radius = this->Radius;
					Shader.IsConfigured = true;
				}
				Shader.CompileShaders();
			}
			#endif
		}

		void Sphere::Render()
		{
			#ifdef GRAPHICS_OPENGL
			{
				// this is where we could 
				this->Shader.Draw();
			}
			#endif
		}


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
			#ifdef GRAPHICS_OPENGL
			{
				this->Shader.Draw();
			}
			#endif

		}
	}
}