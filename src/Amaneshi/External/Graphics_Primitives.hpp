#pragma once

#include "Setup_OpenGL.hpp"

#include <vector>

namespace amaneshi
{
	namespace graphics
	{

		class Point
		{
		public:
			double x;
			double y;
			double z;
			Point() : x(0), y(0), z(0) {};
			Point(double x, double y) : x(x), y(y), z(0) {};
			Point(double x, double y, double z) : x(x), y(y), z(z) {};
		};

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

		class Primitive
		{
		public:
			virtual void CompileShaders() = 0;
			virtual void Render() = 0;
			Point Position;
			Color Color;
			// TODO do I contain textures or is that still passed to the shader struct?
		};

		class Polygon : public Primitive
		{
		public:
			std::vector<Point> Points;
			amaneshi::opengl::PolygonShader GLShader;
			void CompileShaders() override;
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