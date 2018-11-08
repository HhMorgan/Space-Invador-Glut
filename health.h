//#include "Obstacle.h"
#include <iostream>
using namespace std;
class Health :public Drawable
{
public:
	Health(float x, float y, int frame0)
	{
		this->xMin = x;
		this->yMin = y;
		this->frame0 = frame0;
	}
	void draw(short choice, int amount)
	{
		glPushMatrix();
		glTranslatef(this->xMin, this->yMin, 0.0f);
		switch (choice)
		{
		case 0:
			drawRedHp(amount);
			this->xMax = xMin + 7 * pixelSize;
			this->yMax = yMin + 9 * pixelSize;
			break;
		case 1:
			drawGreenHp(amount);
			this->xMax = xMin + 7 * pixelSize;
			this->yMax = yMin + 9 * pixelSize;
			break;
		}
		glPopMatrix();
	}
	
	
private:
	void drawRedHp(int amount)
	{
		float reds[3] = { 0.0f, 1.0f, 0.2 };
		float greens[3] = { 0.0f, 0.0f, 0.2 };
		float blues[3] = { 0.0f, 0.0f, 0.2 };
		
			int laserPixels[5][1] = {
			{ 2 },
			{ 1 },
			{ 1 },
			{ 1 },
			{ 2 },
			};


			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < amount/7; j++)
				{
					
					if (laserPixels[i][0])
					{
						drawPixel(j, i, reds[laserPixels[i][0]], greens[laserPixels[i][0]], blues[laserPixels[i][0]]);
					}

				}

			}
	}
	
	void drawGreenHp(int amount)
	{
		float reds[3] = { 0.0f, 0.0f, 0.2 };
		float greens[3] = { 0.0f, 1.0f, 0.2 };
		float blues[3] = { 0.0f, 0.0f, 0.2 };

		int laserPixels[5][1] = {
			{ 2 },
		{ 1 },
		{ 1 },
		{ 1 },
		{ 2 },
		};


		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < amount * 3; j++)
			{

				if (laserPixels[i][0])
				{
					drawPixel(j, i, reds[laserPixels[i][0]], greens[laserPixels[i][0]], blues[laserPixels[i][0]]);
				}

			}

		}
	}
	
};