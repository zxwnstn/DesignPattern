#pragma once

#include "pch.h"

namespace Static {

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

	template<typename T>
	struct ColoredShape : T
	{
		static_assert(std::is_base_of_v<Shape, T>, "Template argument must be a Shape");

		template<typename... Args>
		ColoredShape(const std::string& color, Args&& ...args)
			: T(std::forward<Args>(args)...), color(color)
		{}

		std::string color;

		std::string str() const override
		{
			std::ostringstream oss;
			oss << T::str() << "has the color " << color;
			return oss.str();
		}
	};
	

	template<typename T>
	struct TransparentShape : T
	{
		static_assert(std::is_base_of_v<Shape, T>, "Template argument must be a Shape");

		uint8_t transparency;

		template<typename... Args>
		TransparentShape(const uint8_t transparency, Args&& ...args)
			: T(std::forward<Args>(args)...), transparency(transparency)
		{}

		std::string str() const override
		{
			std::ostringstream oss;
			oss << T::str() << " has " << static_cast<float>(transparency) / 255.0f * 100.0f
				<< " transparency";
			return oss.str();
		}
	};


	inline void exec()
	{
		ColoredShape<TransparentShape<Circle>> circle("red", 51, 3.0f);
		std::cout << circle.str() << std::endl;;
	}

}