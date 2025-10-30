// Copyright (c) 2025 Anagar Games
// MIT License

#ifndef OL_WINDOW_HPP
#define OL_WINDOW_HPP

#include <string>
#include <cstdint>
#include <iostream>

namespace OL
{
	enum class WIN_FLAG
	{
	
	};

	class Window
	{
	public:
		Window(std::string& title_a = "Oriol Window", 
			   uint32_t width_a = 1920, uint32_t height_a = 1000,
			   uint32_t pos_x_a = 100,  uint32_t pos_y_a = 100,
			   );
		~Window();

	private:
	};
}

#endif
