#include "Engine.h"
#include <cstdlib>
#include <SDL_ttf.h>
#include <ctime>
#include <SDL_image.h>

Engine* Engine::Instance = nullptr;

Engine* Engine::GetInstance()
{
	return Instance = (Instance != nullptr) ? Instance : new Engine();
}

bool Engine::Init()	// Hàm khởi tạo trò chơi, nếu tạo thành công trả về true, ngược lại false
{
	srand((int)time(0));
	isRunning = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
	{
		SDL_Log("Fail to initialize SDL: %s", SDL_GetError()); // THÔNG MÀN HÌNH CONSOLE
		return isRunning = false;
	}

	Window = SDL_CreateWindow("Little Boy Advanture", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 640, 0);
	SDL_Delay(10000);
	
	if (Window == NULL)
	{
		SDL_Log("Fail to initialize Window: %s", SDL_GetError());
		return isRunning = false;
	}

	/* tham số thứ 3 lad cách trình kết xuất (renderer) hoạt động
		đồng bộ nó với tần số của hệ thống
	*/
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Renderer == NULL)
	{
		SDL_Log("Fail to initialize renderer: %s", SDL_GetError());
		isRunning = false;
		return isRunning;
	}
}

void Engine::Clean() // dọn dẹp vùng nhớ
{
	if (isRunning == false)
	{
		TTF_Quit();
		SDL_DestroyRenderer(Renderer);
		SDL_DestroyWindow(Window);

		IMG_Quit();
		SDL_Quit();

		SDL_Log("everything has been deleted");
	}
}