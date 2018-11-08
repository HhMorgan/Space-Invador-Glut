#include "Drawable.h"
#include <iostream>
using namespace std;
class Obstacle :public Drawable
{
public:
	Obstacle(float x, float y, int frame0)
	{
		this->xMin = x;
		this->yMin = y;
		this->frame0 = frame0;
	}
	void draw(short choice)
	{
		glPushMatrix();
		glTranslatef(this->xMin, this->yMin, 0.0f);
		switch (choice)
		{
		case 0:
			drawBlock();
			this->xMax = xMin + 7 * pixelSize;
			this->yMax = yMin + 9 * pixelSize;
			break;
		case 1:
			drawLaser();
			this->xMax = xMin + 28 * pixelSize;
			this->yMax = yMin + 5 * pixelSize;
			//cout << "xMax : " << xMax << ", yMAx : " << yMax<<"\n";
			break;
		case 2:
			drawDefender();
			this->xMax = xMin + 17 * pixelSize;
			this->yMax = yMin + 12 * pixelSize;
			break;
		}
		glPopMatrix();
	}
	~Obstacle() {}
	float getXMax()
	{
		return this->xMax;
	}
	float getXMin()
	{
		return this->xMin;
	}
	float getYMax()
	{
		return this->yMax;
	}
	float getYMin()
	{
		return this->yMin;
	}
	bool collideWithObstacle(Obstacle obstacle)
	{
		bool collideX = xMax > obstacle.getXMin() && xMax < obstacle.getXMax() ||
			xMin > obstacle.getXMin() && xMin < obstacle.getXMax();
		bool collideY = this->yMax > obstacle.getYMin() && this->yMax < obstacle.getYMax() ||
			this->yMin > obstacle.getYMin() && this->yMin < obstacle.getYMax();
		return collideX & collideY;
	}
private:
	void drawLaser()
	{
		float reds[2] = { 0.0f, 1.0f };
		float greens[2] = { 0.0f, 0.0f };
		float blues[2] = { 0.0f, 1.0f };
		
			int laserPixels[5][2] = {
			{ 1, 1 },
			{ 1, 1 },
			{ 1, 1 },
			{ 1, 1 },
			{ 1, 1 },
			};


			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					if (laserPixels[i][j])
					{
						drawPixel(j, i, reds[laserPixels[i][j]], greens[laserPixels[i][j]], blues[laserPixels[i][j]]);
					}

				}

			}
	}
	
	void drawBlock()
	{
		float reds[8] = { 0.0f, 0.3f, 0.37f, 0.58, 0.71, 0.88f, 0.85f, 0.88 };
		float greens[8] = { 0.0f, 0.3f, 0.0f, 0.18, 0.31, 0.76f, 0.38f, 0.21 };
		float blues[8] = { 0.0f, 0.31f, 0.58f, 0.82, 0.94, 0.13f, 0.04f, 0.13 };

		int blockPixels[9][7] = {
			{ 0, 0, 1, 1, 1, 0, 0 },
			{ 0, 1, 2, 2, 2, 1, 0 },
			{ 1, 2, 3, 3, 3, 2, 1 },
			{ 1, 3, 3, 4, 3, 3, 1 },
			{ 1, 3, 4, 5, 4, 3, 1 },
			{ 0, 1, 5, 6, 5, 1, 0 },
			{ 0, 0, 1, 6, 1, 0, 0 },
			{ 0, 0, 0, 1, 7, 1, 0 },
			{ 0, 0, 0, 0, 1, 7, 0 },
		};


		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (blockPixels[i][j])
				{
					drawPixel(j, i, reds[blockPixels[i][j]], greens[blockPixels[i][j]], blues[blockPixels[i][j]]);
				}

			}

		}
	}
	void drawDefender()
	{
		
		if (frame0==0)
		{
			float reds[4] = { 0.0f, 0.3f, 0.2f, 0.1f };
			float greens[4] = { 0.0f, 0.3f, 0.34f, 0.7f };
			float blues[4] = { 0.0f, 0.31f, 0.36f, 0.76f };
			int defenderPixels[12][19] = {
				{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 2, 2, 1, 1, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 1, 3, 1, 3, 3, 3, 3, 3, 1, 3, 1, 0, 0, 0, 0 },
				{ 0, 0, 0, 1, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 3, 1, 0, 0, 0 },
				{ 0, 0, 1, 3, 3, 3, 1, 2, 3, 3, 3, 2, 1, 3, 3, 3, 1, 0, 0 },
				{ 0, 1, 3, 3, 3, 3, 1, 2, 2, 3, 2, 2, 1, 3, 3, 3, 3, 1, 0 },
				{ 1, 2, 3, 2, 3, 1, 1, 2, 3, 3, 3, 2, 1, 1, 3, 2, 3, 2, 1 },
				{ 1, 2, 2, 2, 1, 2, 1, 3, 3, 3, 3, 3, 1, 2, 1, 2, 2, 2, 1 },
				{ 0, 1, 1, 1, 0, 1, 0, 1, 2, 2, 2, 1, 0, 1, 0, 1, 1, 1, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			};
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 19; j++)
				{
					if (defenderPixels[i][j])
					{
						drawPixel(j, i, reds[defenderPixels[i][j]], greens[defenderPixels[i][j]], blues[defenderPixels[i][j]]);
					}

				}

			}
		}
		if (frame0 == 1)
		{
			float reds[4] = { 0.0f, 0.3f, 0.2f, 0.1f };
			float greens[4] = { 0.0f, 0.3f, 0.34f, 0.7f };
			float blues[4] = { 0.0f, 0.31f, 0.36f, 0.76f };
			int defenderPixels[13][19] = {
			{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 1, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 3, 1, 3, 3, 3, 2, 2, 1, 1, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 3, 3, 1, 3, 3, 3, 3, 3, 1, 3, 1, 0, 0, 0, 0 },
			{ 0, 0, 1, 3, 3, 3, 1, 2, 3, 3, 3, 3, 1, 3, 3, 1, 0, 0, 0 },
			{ 0, 1, 3, 3, 3, 3, 1, 2, 2, 3, 3, 2, 1, 3, 3, 3, 1, 0, 0 },
			{ 1, 2, 3, 2, 3, 1, 1, 2, 3, 3, 2, 2, 1, 3, 3, 3, 3, 1, 0 },
			{ 1, 2, 2, 2, 1, 2, 1, 3, 3, 3, 3, 2, 1, 1, 3, 2, 3, 2, 1 },
			{ 0, 1, 1, 1, 0, 1, 0, 1, 2, 3, 3, 3, 1, 2, 1, 2, 2, 2, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 0, 1, 0, 1, 1, 1, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			};
			for (int i = 0; i < 13; i++)
			{
				for (int j = 0; j < 19; j++)
				{
					if (defenderPixels[i][j])
					{
						drawPixel(j, i, reds[defenderPixels[i][j]], greens[defenderPixels[i][j]], blues[defenderPixels[i][j]]);
					}

				}

			}
		}
			

			if (frame0 == 2)
			{
				float reds[4] = { 0.0f, 0.3f, 0.2f, 0.1f };
				float greens[4] = { 0.0f, 0.3f, 0.34f, 0.7f };
				float blues[4] = { 0.0f, 0.31f, 0.36f, 0.76f };
				int defenderPixels[13][19] = {
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0/**/, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 1, 1/**/, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 1, 2, 2/**/, 3, 2, 2, 1, 1, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 1, 1, 2, 2/**/, 3, 3, 3, 1, 3, 1, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 1, 3, 1, 3, 3/**/, 3, 3, 3, 1, 3, 3, 1, 0, 0, 0 },
				{ 0, 0, 0, 1, 3, 3, 1, 3, 3/**/, 3, 3, 2, 1, 3, 3, 3, 1, 0, 0 },
				{ 0, 0, 1, 3, 3, 3, 1, 2, 3/**/, 3, 2, 2, 1, 3, 3, 3, 3, 1, 0 },
				{ 0, 1, 3, 3, 3, 3, 1, 2, 2/**/, 3, 3, 2, 1, 1, 3, 2, 3, 2, 1 },
				{ 1, 2, 3, 2, 3, 1, 1, 2, 3/**/, 3, 3, 3, 1, 2, 1, 2, 2, 2, 1 },
				{ 1, 2, 2, 2, 1, 2, 1, 3, 3/**/, 2, 2, 1, 0, 1, 0, 1, 1, 1, 0 },
				{ 0, 1, 1, 1, 0, 1, 0, 1, 2/**/, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 1, 2/**/, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 1/**/, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				};
				for (int i = 0; i < 13; i++)
				{
					for (int j = 0; j < 19; j++)
					{
						if (defenderPixels[i][j])
						{
							drawPixel(j, i, reds[defenderPixels[i][j]], greens[defenderPixels[i][j]], blues[defenderPixels[i][j]]);
						}

					}

				}
			}
			
		
	}
};