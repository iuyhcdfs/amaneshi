#pragma once
#include <Math_Position.hpp>
#include "Messy_OpenGL.hpp"
#include <vector>

namespace amaneshi
{
	namespace graphics
	{
		struct Color
		{
			double r;
			double g;
			double b;
			double a;
			Color() : r(0), g(0), b(0), a(1) {};
			Color(double r, double g, double b) : r(r), g(g), b(b), a(1) {};
			Color(double r, double g, double b, double a) : r(r), g(g), b(b), a(a) {};
		};

		class Renderable
		{
		public:
			virtual void CompileShaders() = 0;// depreciated
			virtual void Render() = 0;
		};

		class Polygon : public Renderable
		{
		public:
			std::vector<amaneshi::math::Point> Points;
			amaneshi::opengl::OldPolygonShader Shader;
			void CompileShaders() override;// depreciated
			void Render() override;
		};

		class Sphere : public Renderable
		{
		public:
			amaneshi::math::Point * Center;
			float * Radius;
			amaneshi::opengl::SphereShader Shader;
			void CompileShaders() override;// depreciated
			void Render() override;
		};



		/*
		class Circle : public Primitive
		{
		public:
			double Radius;
			amaneshi::opengl::CircleShader GLShader;
			void CompileShaders() override;
			void Render() override;
		};
		*/
	}
}