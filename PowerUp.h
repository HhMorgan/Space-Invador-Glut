#include "Obstacle.h"

class PowerUp:public Drawable
{
public:
	PowerUp(float x, float y, int frame0)
	{
		this->xMin = x;
		this->yMin = y;
		this->xMax = x + 7 * pixelSize;
        this->yMax = y + 13 * pixelSize;
        this->frame0 = frame0;
    }
	void draw(short choice)
	{
        glPushMatrix();
        glTranslatef(this->xMin, this->yMin, 0.0f);
		switch (choice)
		{
		case 0:
			drawPowerUp();
			break;
		case 1:
			drawEnergyUp();
			break;
		}
        glPopMatrix();
	}
    ~PowerUp() {}
    float getXMax()
    {
        return this->xMax;
    }
    float getXMin()
    {
        return this->xMin - 2 * pixelSize;
    }
    float getYMax()
    {
        return this->yMax;
    }
    float getYMin()
    {
        return this->yMin;
    }
private:
	
	void drawPowerUp()
	{
		float reds[4] = { 0.0f , 1.0f, 1.0f, 0.0f };
		float greens[4] = { 0.0f, 1.0f, 0.0f, 0.0f };
		float blues[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
		int cratePixels[6][6] = {
			{ 0, 1, 1, 1, 0 },
			{ 1, 2, 3, 3, 1 },
			{ 1, 2, 2, 2, 1 },
			{ 1, 2, 3, 2, 1 },
			{ 1, 2, 2, 2, 1 },
			{ 0, 1, 1, 1, 0 }
		};
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (cratePixels[i][j])
				{
					drawPixel(j + 1, i + 2, reds[cratePixels[i][j]], greens[cratePixels[i][j]], blues[cratePixels[i][j]]);
				}
			}
		}
	}
	void drawEnergyUp()
	{
		float reds[4] = { 0.0f , 1.0f, 0.0f, 0.0f };
		float greens[4] = { 0.0f, 1.0f, 1.0f, 0.0f };
		float blues[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
		int cratePixels[6][6] = {
			{ 0, 1, 1, 1, 0 },
			{ 1, 3, 2, 3, 1 },
			{ 1, 3, 2, 3, 1 },
			{ 1, 3, 3, 3, 1 },
			{ 1, 3, 2, 3, 1 },
			{ 0, 1, 1, 1, 0 }
		};
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (cratePixels[i][j])
				{
					drawPixel(j + 1, i + 2, reds[cratePixels[i][j]], greens[cratePixels[i][j]], blues[cratePixels[i][j]]);
				}
			}
		}
	}
};