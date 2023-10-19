#pragma once

#include <SDL.h>
#include <iostream>
#include <fstream>

using namespace std;

#define SCREEN_WIDTH 1280;
#define SCREEN_HEIGHT 640;

class Engine
{
private:
	static Engine* Instance; //

	SDL_Window* Window; // cửa sổ
	SDL_Renderer* Renderer; // kết xuất
	bool isRunning; // kiểm tra game đang chạy
public:
	static Engine* GetInstance();

	bool Init(); // Khởi tạo
	void Render(); // kết xuất ra màn hình
	void Quit(); // thoát game
	void Clean(); // dọn dẹp bộ nhớ trước khi thoát game
};
