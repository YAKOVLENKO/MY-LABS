#include "./../SDL2_gfxPrimitives.h"
#include <SDL.h>
#include <stdio.h>
#include <cstdlib>
#include <sstream>

/////////////CIRCLE/////////////
class TCircle
{
protected:
	size_t index_of_colour;
	bool key;
	int tc_x;
	int tc_y;

public:
	
	TCircle()
	{
		index_of_colour = rand() % 4 ;
		key = 0;
		tc_x = -10;
		tc_y = -10;
	}	
	~TCircle()
	{
		index_of_colour = 0;
		key = 0;
		tc_x = -10;
		tc_y = -10;
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
		tc_x = x;
		tc_y = y;
	}
	int GetX()
	{
		return tc_x;
	}
	int GetY()
	{
		return tc_y;
	}
	TCircle ChangeColour(int colour)
	{
		this->index_of_colour = colour;
		return *this;
	}
	int GetColour()
	{
		return index_of_colour;
	}
	TCircle ChangeKey(bool val)
	{
		this->key = val;
		return *this;
	}
	bool GetKey()
	{
		return key;
	}
};
/////////////CIRCLE/////////////

/////////////MAIN CIRCLE/////////////
class TMainCircle : public TCircle
{
public:
	TMainCircle() : TCircle()
	{
		
	}
	~TMainCircle() 
	{
		//index_of_colour = 0;
		//key = 0;
		//tc_x = -10;
		//tc_y = -10;
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
		tc_x = x;
		tc_y = y;
	};

};
/////////////MAIN CIRCLE/////////////

/////////////MASS/////////////
class LineOfCircles
{
	public:
	TCircle** aab;
	LineOfCircles()
	{
		aab = new TCircle*[9];
		for (int i = 0; i < 9; ++i)
		{
			aab[i] = new TCircle[10];
			for (int j = 6; j < 10; ++j)
			{
				aab[i][j].ChangeColour(-1);
			}
		}
	}
	 /////////////////////////////////////////destructor////////////////////////////////////////
	~LineOfCircles()
	{
		for (int i = 0; i < 9; ++i)
			delete[] aab[i];
		delete[] aab;

	}
	
	void PrintLine(SDL_Renderer* renderer)
	{
		int k = 0;
		for (int i = 40; i <= 360; i += 40)
		{
			int m = 0;
			for (int j = 40; j <= 400; j += 40)
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
/////////////MASS/////////////


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

	int i_for_checking = 0;
	int j_for_checking = 0;;

	int arm = 1; // чтобы шарик не уходил вбок

	///////////////mass///////////////
	int** MassXY;

	int k = 40;
	int m = 40;
	MassXY = new int*[36];
	for (int i = 0; i < 36; ++i)
	{
		MassXY[i] = new int[2];
		MassXY[i][0] = k;
		MassXY[i][1] = m;
		if (k == 360)
		{
			m += 40;
			k = 0;
		}
		k += 40;
	}
	///////////////mass///////////////



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
					break;
				case SDLK_UP:
					if (aa.GetColour() != 3)
						aa.ChangeColour(aa.GetColour() + 1);
					else
						aa.ChangeColour(0);
					break;
				case SDLK_DOWN:
					if (aa.GetColour() != 0)
						aa.ChangeColour(aa.GetColour() - 1);
					else
						aa.ChangeColour(3);
					break;
				}
				break;
			}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
		thickLineColor(renderer, 0, 450, WIDTH, 450, 10, 0xFFFFFFFF);
		nile.PrintLine(renderer);
		if (push)
		{
			switch (arm)
			{
			case 1:
				for (int i = 0; i < 9; ++i)
				{

					for (int j = 0; j < 10; ++j)
					{
						if (nile.aab[i][j].GetX() > -10 && nile.aab[i][j].GetColour() >= 0)
							if ((abs(x_for_ball - nile.aab[i][j].GetX()) < 30) &&
								(abs(y_for_ball - nile.aab[i][j].GetY()) < 30))
							{
								i_for_checking = i;
								j_for_checking = j;
								arm = 3;

							}
					}

				}
				if (x >= 200)
					x_for_ball += real_x / 10;
				if (x < 200)
					x_for_ball -= real_x / 10;
				y_for_ball -= real_y / 10;
				if (x_for_ball >= 360 || x_for_ball <= 40) arm = 2;
				if (y_for_ball <= 0) arm = 4;
				break;
			case 2:
				for (int i = 0; i < 9; ++i)
				{
					{
						for (int j = 0; j < 10; ++j)
						{
							if (nile.aab[i][j].GetX() > -10 && nile.aab[i][j].GetColour() >= 0)
								if ((abs(x_for_ball - nile.aab[i][j].GetX()) < 30) &&
									(abs(y_for_ball - nile.aab[i][j].GetY()) < 30))
								{
									i_for_checking = i;
									j_for_checking = j;
									arm = 3;
								}
						}
					}
				}
				if (x >= 200)
					x_for_ball -= real_x / 10;
				if (x < 200)
					x_for_ball += real_x / 10;
				y_for_ball -= real_y / 10;
				if (x_for_ball >= 360 || x_for_ball <= 40) arm = 1;
				if (y_for_ball <= 0) arm = 4;
				break;
			case 3:
				if (!(y_for_ball == nile.aab[i_for_checking][j_for_checking].GetY()))
				{
					if (y_for_ball - nile.aab[i_for_checking][j_for_checking].GetY() > 0) //  если главный шар ниже
					{
						y_for_ball = nile.aab[i_for_checking][j_for_checking].GetY() + 40;
					}
					if (y_for_ball - nile.aab[i_for_checking][j_for_checking].GetY() < 0) // если главный шар выше
					{
						y_for_ball = nile.aab[i_for_checking][j_for_checking].GetY() - 40;
					}
					if (x_for_ball - nile.aab[i_for_checking][j_for_checking].GetX() > 0)
					{
						x_for_ball = nile.aab[i_for_checking][j_for_checking].GetX() + 20;
					}
					if (x_for_ball - nile.aab[i_for_checking][j_for_checking].GetX() < 0)
					{
						x_for_ball = nile.aab[i_for_checking][j_for_checking].GetX() - 20;
					}
					if (x_for_ball == nile.aab[i_for_checking][j_for_checking].GetX())
					{
						if (x_for_ball == 360)
						{
							x_for_ball = nile.aab[i_for_checking][j_for_checking].GetX() - 20;
						}
						else
						{
							x_for_ball = nile.aab[i_for_checking][j_for_checking].GetX() + 20;
						}

					}
					int j_new_ball = y_for_ball / 40 - 1;
					int i_new_ball = (x_for_ball + 20 * (j_new_ball % 2 - 1)) / 40 - 1;

					if (nile.aab[i_new_ball][j_new_ball].GetColour() == -1)
						nile.aab[i_new_ball][j_new_ball].ChangeColour(aa.GetColour());

					x_for_ball = 200;
					y_for_ball = 600;
					//push = false;
					
					int count = 1;
					nile.aab[i_new_ball][j_new_ball].ChangeKey(1);
					int main_colour = nile.aab[i_new_ball][j_new_ball].GetColour();
					int wine = 0;
					while (wine != 36)
					{
						
					for (int i = 0; i < 9; ++i)
						for (int j = 0; j < 10; ++j)
						{
							if (nile.aab[i][j].GetColour() == nile.aab[i_new_ball][j_new_ball].GetColour())
							{
								for (int gx = -20; gx <= 20; gx += 40)
									for (int gy = -40; gy <= 40; gy += 80)
									{
										int catJ = (nile.aab[i][j].GetY() + gy) / 40 - 1;
										int dogI = ((nile.aab[i][j].GetX() + gx) + 20 * (catJ % 2 - 1)) / 40 - 1;
										if ((catJ >= 0 && catJ < 10) && (dogI >= 0 && dogI < 9))
										{
											if (nile.aab[dogI][catJ].GetKey() == 1 && nile.aab[i][j].GetKey() != 1 && nile.aab[dogI][catJ].GetColour() != -1)
											{
												nile.aab[i][j].ChangeKey(1);
												++count;
											}
										}
									}
								if (i + 1 < 9 && nile.aab[i][j].GetKey() != 1)
									if (nile.aab[i + 1][j].GetKey() == 1 && nile.aab[i + 1][j].GetColour() != -1)
									{
										nile.aab[i][j].ChangeKey(1);
										++count;
									}
								if (i - 1 >= 0 && nile.aab[i][j].GetKey() != 1 && nile.aab[i - 1][j].GetColour() != -1)
									if (nile.aab[i - 1][j].GetKey() == 1)
									{
										nile.aab[i][j].ChangeKey(1);
										++count;
									}
							}
						}
					++wine;
					}
					if (count < 3)
						for (int i = 0; i < 9; ++i)
							for (int j = 0; j < 10; ++j)
							{
								nile.aab[i][j].ChangeKey(0);
							}
					
					for (int i = 0; i < 9; ++i)
					{
						for (int j = 0; j < 10; ++j)
							if (nile.aab[i][j].GetKey() == 1)
								nile.aab[i][j].ChangeColour(-1);
					}
					///////deleting///////



						arm = 1;
					}


					push = false;
					break;
					case 4:
						y_for_ball = 600; 
						x_for_ball = 200;
						arm = 1;
						push = false;
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
