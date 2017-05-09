#include "./../SDL2_gfxPrimitives.h"
#include <SDL.h>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <sstream>


class TCircle
{
protected:
	size_t index_of_colour;
	bool key;
	size_t circles_with_the_same_color_near;

public:
	
	TCircle()
	{
		index_of_colour = rand() % 4 ;
		key = 0;
		circles_with_the_same_color_near = 0;
	}
	~TCircle()
	{
		index_of_colour = 0;
		key = 0;
		circles_with_the_same_color_near = 0;
	}
	virtual void PrintCircle(SDL_Renderer* renderer, size_t x, size_t y)
	{
		if (index_of_colour == 0)
			filledCircleColor(renderer, x, y, 20, 0xffff00ff);
		if (index_of_colour == 1)
			filledCircleColor(renderer, x, y, 20, 0xFF0000FF); // x, y, R
		if (index_of_colour == 2)
			filledCircleColor(renderer, x, y, 20, 0xFF00FFFF);
		if (index_of_colour == 3)
			filledCircleColor(renderer, x, y, 20, 0xff00ff00);
	}
};

class TMainCircle : public TCircle
{
public:
	TMainCircle() : TCircle()
	{
		key = 1;
	}
	~TMainCircle()
	{
		index_of_colour = 0;
		key = 0;
		circles_with_the_same_color_near = 0;
	};
	void PrintCircle(SDL_Renderer* renderer, int x, int y) ///////////////virtual/////////////////////
	{
		if (index_of_colour == 0)
			filledCircleColor(renderer, x, y, 20, 0xffff00ff);
		if (index_of_colour == 1)
			filledCircleColor(renderer, x, y, 20, 0xFF0000FF); // x, y, R
		if (index_of_colour == 2)
			filledCircleColor(renderer, x, y, 20, 0xFF00FFFF);
		if (index_of_colour == 3)
			filledCircleColor(renderer, x, y, 20, 0xff00ff00);
	};

};


class LineOfCircles
{
	TCircle** aab;
public:
	LineOfCircles()
	{
		aab = new TCircle*[9];
		for (int i = 0; i < 9; ++i)
		{
			aab[i] = new TCircle[6];
			{
				for (int j = 0; j < 6; ++j)
				{
					TCircle tmp;
					aab[i][j] = tmp;
				}
			}
		}
	}
	
	void PrintLine(SDL_Renderer* renderer)
	{
		int k = 0;
		for (int i = 40; i <= 360; i += 40)
		{
			int m = 0;
			for (int j = 40; j <= 240; j += 40)
			{
				if (m % 2 == 0)
				{
					if (k != 8)
						aab[k][m].PrintCircle(renderer, i + 20, j);
					++m;
				}
				else
				{
					aab[k][m].PrintCircle(renderer, i, j);
					++m;
				}
			}
			++k;
		}
	}
};



#define WIDTH 400 
#define HEIGHT 700 

int main(int argc, char* argv[])
{

	SDL_Window *window = SDL_CreateWindow("SDL2_gfx test", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	SDL_Event e;

	int quit = 0;
	
	Uint8 *keystate;
	
	LineOfCircles nile;
	
	TMainCircle aa;
	
	int pos = 1, x = 200, y = 500; // для стрелки
	int real_x = 0, real_y = 100; // для стрелки и движения шара
	int length_of_line = 100; // длина стрелки
	int x_for_ball = 200, y_for_ball = 600; // движение шарика
	bool push = 0; // начать движение шара

	int arm = 1; // чтобы шарик не уходил вбок

	while (!quit)
	{
		if (SDL_PollEvent(&e))
		  switch (e.type) { // Смотрим, что за событие
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) 
					{ 
                        case SDLK_RIGHT:
							if (x >= 200 && x < 290)
							{
								real_x += 10;
								x = 200 + real_x;
								real_y = sqrt(pow(length_of_line, 2) - pow(real_x, 2));
								y = 600 - real_y;
							}
							if (x < 200)
							{
								real_x -= 10;
								x = 200 - real_x;
								real_y = sqrt(pow(length_of_line, 2) - pow(real_x, 2));
								y = 600 - real_y;
								
							}
                            break;
                        case SDLK_LEFT:
							if (x > 200)
							{
								real_x -= 10;
								x = 200 + real_x;
								real_y = sqrt(pow(length_of_line, 2) - pow(real_x, 2));
								y = 600 - real_y;
							}
							if (x <= 200 && x > 110)
							{
								real_x += 10;
								x = 200 - real_x;
								real_y = sqrt(pow(length_of_line, 2) - pow(real_x, 2));
								y = 600 - real_y;
							}
							break;
						case SDLK_SPACE:
							push = true;
                    }
                    break;
            }
        
		SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, 0xFF);
		SDL_RenderClear(renderer);			
		
		nile.PrintLine(renderer);
		if (push)
		{
			switch (arm)
			{
			case 1:
				if (x >= 200)
					x_for_ball += real_x / 10;
				if (x < 200)
					x_for_ball -= real_x / 10;
				y_for_ball -= real_y / 10;
				if (x_for_ball >= 360 || x_for_ball <= 40) arm = 2;
				break;
			case 2:
				if (x >= 200)
					x_for_ball -= real_x / 10;
				if (x < 200)
					x_for_ball += real_x / 10;
				y_for_ball -= real_y / 10;
				if (x_for_ball >= 360 || x_for_ball <= 40) arm = 1;
				break;
			}
		}
		aa.PrintCircle(renderer, x_for_ball, y_for_ball);
		

		SDL_RenderDrawLine(renderer, x, y, 200, 600);


		thickLineColor(renderer, 0, 0, WIDTH, 0, 40, 0xFF00FFFF);
		thickLineColor(renderer, 0, 0, 0, HEIGHT, 40, 0xFF00FFFF);
		thickLineColor(renderer, WIDTH, 0, WIDTH, HEIGHT, 40, 0xFF00FFFF);
		thickLineColor(renderer, 0, HEIGHT, WIDTH, HEIGHT, 40, 0xFF00FFFF);
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}