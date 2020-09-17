#pragma once

#include "pch.h"

namespace Dynamic {

	struct Shape
	{
		virtual std::string str() const = 0;
	};

	struct Circle : Shape
	{
		float radius;

		explicit Circle(const float radius)
			: radius(radius)
		{}

		void resize(float factor)
		{
			radius *= factor;
		}

		std::string str() const override
		{
			std::ostringstream oss;
			oss << "A circle of radius " << radius;
			return oss.str();
		}
	};

	struct ColoredShape : Shape
	{
		Shape& shape;
		std::string color;

		ColoredShape(Shape& shape, const std::string& color)
			: shape(shape), color(color)
		{}

		std::string str() const override
		{
			std::ostringstream oss;
			oss << shape.str() << " has the color " << color;
			return oss.str();
		}
	};

	struct TransparentShape : Shape
	{
		Shape& shape;
		uint8_t transparency;

		TransparentShape(Shape& shape, const uint8_t transparency)
			: shape(shape), transparency(transparency)
		{}

		std::string str() const override
		{
			std::ostringstream oss;
			oss << shape.str() << " has "
				<< static_cast<float>(transparency) / 255.0f * 100
				<< "% transparency";
			return oss.str();
		}
	};

	inline void exec()
	{
		Circle circle(5.0f);
		TransparentShape demiCircle(circle, 85);
		std::cout << demiCircle.str() << std::endl;
	}
}
