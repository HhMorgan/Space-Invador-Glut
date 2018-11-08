#include "PowerUp.h"
#include "Boss.h"
#include <iostream>
using namespace std;
class Ship : public Drawable
{
protected:
	int health;
public:
	Ship(float x, float y, int frame0, int health)
	{
		this->xMin = x;
		this->yMin = y;
		this->xMax = x + 49 * pixelSize;
        this->yMax = y + 23 * pixelSize;
        this->frame0 = frame0;
		this->health = health;
	}
    ~Ship() {}
    bool collideWithObstacle(Obstacle obstacle)
    {
		float xMinOriginal = xMin + 10 * pixelSize;
		float xMaxOriginal = xMinOriginal+ 13 * pixelSize;
		float yMinOriginal = yMin + 17 * pixelSize;
		float yMaxOriginal = yMinOriginal + 11 * pixelSize;
		bool collideWingX = xMaxOriginal > obstacle.getXMin() && xMaxOriginal < obstacle.getXMax() ||
			xMinOriginal > obstacle.getXMin() && xMinOriginal < obstacle.getXMax();
		bool collideCenterX = xMinOriginal + ((xMaxOriginal - xMinOriginal) / 2)> obstacle.getXMin() &&
							  xMinOriginal + ((xMaxOriginal - xMinOriginal) / 2) < obstacle.getXMax();
        bool collideWingY = this->yMax > obstacle.getYMin() && this->yMax < obstacle.getYMax() ||
                        this->yMin > obstacle.getYMin() && this->yMin < obstacle.getYMax();
		bool collideCenterY = yMaxOriginal > obstacle.getYMin() && yMaxOriginal < obstacle.getYMax() ||
						      yMinOriginal > obstacle.getYMin() && yMinOriginal < obstacle.getYMax()||
							  yMinOriginal + ((yMaxOriginal - yMinOriginal) / 2)> obstacle.getYMin() && 
							  yMinOriginal + ((yMaxOriginal - yMinOriginal) / 2) < obstacle.getYMax();
        return (collideWingX & collideWingY) || (collideCenterX & collideCenterY);
    }
    bool collideWithPowerUp(PowerUp powerUp)
    {
		float xMinOriginal = xMin + 10 * pixelSize;
		float xMaxOriginal = xMinOriginal + 13 * pixelSize;
		float yMinOriginal = yMin + 17 * pixelSize;
		float yMaxOriginal = yMinOriginal + 11 * pixelSize;
		bool collideWingX = xMaxOriginal > powerUp.getXMin() && xMaxOriginal < powerUp.getXMax() ||
			xMinOriginal > powerUp.getXMin() && xMinOriginal < powerUp.getXMax();
		bool collideCenterX = xMinOriginal + ((xMaxOriginal - xMinOriginal) / 2)> powerUp.getXMin() &&
			xMinOriginal + ((xMaxOriginal - xMinOriginal) / 2) < powerUp.getXMax();
		bool collideWingY = this->yMax > powerUp.getYMin() && this->yMax < powerUp.getYMax() ||
			this->yMin > powerUp.getYMin() && this->yMin < powerUp.getYMax();
		bool collideCenterY = yMaxOriginal > powerUp.getYMin() && yMaxOriginal < powerUp.getYMax() ||
			yMinOriginal > powerUp.getYMin() && yMinOriginal < powerUp.getYMax() ||
			yMinOriginal + ((yMaxOriginal - yMinOriginal) / 2)> powerUp.getYMin() &&
			yMinOriginal + ((yMaxOriginal - yMinOriginal) / 2) < powerUp.getYMax();
		return (collideWingX & collideWingY) || (collideCenterX & collideCenterY);
    }
	bool collideWithBoss(Boss boss)
	{
		float xMinOriginal = xMin + 10 * pixelSize;
		float xMaxOriginal = xMinOriginal + 13 * pixelSize;
		float yMinOriginal = yMin + 17 * pixelSize;
		float yMaxOriginal = yMinOriginal + 11 * pixelSize;
		bool collideWingX = xMaxOriginal > boss.getXMin() && xMaxOriginal < boss.getXMax() ||
			xMinOriginal > boss.getXMin() && xMinOriginal < boss.getXMax();
		bool collideCenterX = xMinOriginal + ((xMaxOriginal - xMinOriginal) / 2)> boss.getXMin() &&
			xMinOriginal + ((xMaxOriginal - xMinOriginal) / 2) < boss.getXMax();
		bool collideWingY = this->yMax > boss.getYMin() && this->yMax < boss.getYMax() ||
			this->yMin > boss.getYMin() && this->yMin < boss.getYMax();
		bool collideCenterY = yMaxOriginal > boss.getYMin() && yMaxOriginal < boss.getYMax() ||
			yMinOriginal > boss.getYMin() && yMinOriginal < boss.getYMax() ||
			yMinOriginal + ((yMaxOriginal - yMinOriginal) / 2)> boss.getYMin() &&
			yMinOriginal + ((yMaxOriginal - yMinOriginal) / 2) < boss.getYMax();
		return (collideWingX & collideWingY) || (collideCenterX & collideCenterY);
	}
    void draw()
	{
        glPushMatrix();
        glTranslatef(this->xMin, this->yMin, 0.0f);
		
		drawBase();
		
        glPopMatrix();
	}
	int getHealth()
	{
		return this->health;
	}
private:
	
	void drawBase()
	{
		float reds[5] = { 0.0f, 1.0f, 1.0f, 0.0f, 0.38f };
		float greens[5] = { 0.0f, 1.0f, 0.0f, 0.0f, 0.38f };
		float blues[5] = { 0.0f, 1.0f, 0.0f, 1.0f, 0.38f };

		
		if (frame0==0)
		{
			int sailPixels[18][24] = {
				/* 0 */        /* 5 */        /* 10 */       /* 15 */			
	   /*0*/{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0 },
			{ 0, 0, 0, 1, 2, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 2, 1, 0, 0, 0 },
			{ 0, 0, 0, 1, 2, 1, 4, 1, 0, 1, 4, 4, 4, 4, 1, 0, 1, 4, 1, 2, 1, 0, 0, 0 },
	   /*5*/{ 0, 0, 0, 1, 2, 2, 2, 4, 1, 1, 3, 4, 4, 4, 1, 1, 4, 2, 2, 2, 1, 0, 0, 0 },
			{ 0, 0, 0, 1, 2, 2, 2, 4, 4, 1, 3, 4, 4, 4, 1, 4, 4, 2, 2, 2, 1, 0, 0, 0 },
			{ 0, 0, 0, 1, 2, 2, 2, 2, 4, 4, 4, 4, 3, 4, 4, 4, 2, 2, 2, 2, 1, 0, 0, 0 },
			{ 0, 0, 0, 1, 1, 2, 2, 2, 4, 4, 2, 4, 3, 4, 4, 4, 2, 2, 2, 1, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 2, 2, 2, 4, 4, 4, 3, 4, 4, 4, 4, 2, 2, 2, 1, 0, 0, 0, 0 },
	  /*10*/{ 0, 0, 0, 0, 0, 1, 2, 2, 2, 3, 4, 3, 3, 4, 3, 2, 2, 2, 1, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 1, 2, 2, 4, 4, 3, 3, 3, 4, 2, 2, 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 3, 2, 4, 3, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 4, 4, 4, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 3, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  /*15*/{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 3, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			
			

			};
			for (int i = 0; i < 18; i++)
			{
				for (int j = 0; j < 24; j++)
				{
					if (sailPixels[i][j])
					{
						drawPixel(j + 5, i + 12, reds[sailPixels[i][j]], greens[sailPixels[i][j]], blues[sailPixels[i][j]]);
					}
				}
			}
		}
		else {
			if (frame0 == 1 )
			{
				float reds[5] = { 0.0f, 1.0f, 1.0f, 0.0f, 0.38f };
				float greens[5] = { 0.0f, 1.0f, 1.0f, 0.0f, 0.38f };
				float blues[5] = { 0.0f, 1.0f, 0.0f, 1.0f, 0.38f };
				int sailPixels[19][24] = {
					
				/* 0 */        /* 5 */        /* 10 */       /* 15 */
		   /*0*/{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },//
				{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0 },
				{ 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 2, 1, 0, 0, 0 },
				{ 0, 0, 0, 1, 2, 1, 1, 0, 0, 0, 1, 1, 4, 4, 1, 0, 1, 4, 1, 2, 1, 0, 0, 0 },
		   /*5*/{ 0, 0, 0, 1, 2, 1, 4, 1, 0, 1, 4, 4, 4, 4, 1, 1, 4, 2, 2, 2, 1, 0, 0, 0 },
				{ 0, 0, 0, 1, 2, 2, 2, 4, 1, 1, 3, 4, 4, 4, 1, 4, 4, 2, 2, 2, 1, 0, 0, 0 },
				{ 0, 0, 0, 1, 2, 2, 2, 4, 4, 1, 3, 4, 3, 4, 4, 4, 2, 2, 2, 2, 1, 0, 0, 0 },
				{ 0, 0, 0, 1, 2, 2, 2, 2, 4, 4, 4, 4, 3, 4, 4, 4, 2, 2, 2, 1, 1, 0, 0, 0 },
				{ 0, 0, 0, 1, 1, 2, 2, 2, 4, 4, 2, 4, 4, 4, 4, 4, 2, 2, 2, 1, 0, 0, 0, 0 },
		  /*10*/{ 0, 0, 0, 0, 1, 2, 2, 2, 4, 4, 4, 3, 3, 4, 3, 2, 2, 2, 1, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 1, 2, 2, 2, 3, 4, 3, 3, 3, 4, 2, 2, 1, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 1, 2, 2, 4, 4, 3, 4, 3, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 3, 2 , 4, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 4, 4, 3, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		  /*15*/{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

				};
				for (int i = 0; i < 19; i++)
				{
					for (int j = 0; j < 24; j++)
					{
						if (sailPixels[i][j])
						{
							drawPixel(j + 5, i + 12, reds[sailPixels[i][j]], greens[sailPixels[i][j]], blues[sailPixels[i][j]]);
						}
					}
				}
			}
			else {
				if (frame0 == 2)
				{
					float reds[5] = { 0.0f, 1.0f, 0.0f, 0.0f, 0.38f };
					float greens[5] = { 0.0f, 1.0f, 1.0f, 0.0f, 0.38f };
					float blues[5] = { 0.0f, 1.0f, 1.0f, 1.0f, 0.38f };
					int sailPixels[19][24] = {
						
			   /*0*/{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
					{ 0, 0, 0, 1, 2, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0 },
					{ 0, 0, 0, 1, 2, 1, 4, 1, 0, 1, 4, 4, 1, 1, 0, 0, 0, 1, 1, 2, 1, 0, 0, 0 },
			   /*5*/{ 0, 0, 0, 1, 2, 2, 2, 4, 1, 1, 3, 4, 4, 4, 1, 0, 1, 4, 1, 2, 1, 0, 0, 0 },
					{ 0, 0, 0, 1, 2, 2, 2, 4, 4, 1, 3, 4, 4, 4, 1, 1, 4, 2, 2, 2, 1, 0, 0, 0 },
					{ 0, 0, 0, 1, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 1, 4, 4, 2, 2, 2, 1, 0, 0, 0 },
					{ 0, 0, 0, 1, 1, 2, 2, 2, 4, 4, 2, 4, 3, 4, 4, 4, 2, 2, 2, 2, 1, 0, 0, 0 },
					{ 0, 0, 0, 0, 1, 2, 2, 2, 4, 4, 4, 3, 3, 4, 4, 4, 2, 2, 2, 1, 1, 0, 0, 0 },
			  /*10*/{ 0, 0, 0, 0, 0, 1, 2, 2, 2, 3, 4, 3, 4, 4, 4, 4, 2, 2, 2, 1, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 1, 2, 2, 4, 4, 3, 3, 4, 3, 2, 2, 2, 1, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 3, 2, 3, 3, 4, 2, 2, 1, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 4, 4, 4, 3, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			  /*15*/{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 3, 3, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },


					};
					for (int i = 0; i < 19; i++)
					{
						for (int j = 0; j < 24; j++)
						{
							if (sailPixels[i][j])
							{
								drawPixel(j + 5, i + 12, reds[sailPixels[i][j]], greens[sailPixels[i][j]], blues[sailPixels[i][j]]);
							}
						}
					}
				}
				else 
				{
					if (frame0 == 3)
					{
						float reds[5] = { 0.0f, 1.0f, 0.78f, 0.0f, 0.38f };
						float greens[5] = { 0.0f, 1.0f, 0.78f, 0.0f, 0.38f };
						float blues[5] = { 0.0f, 1.0f, 0.78f, 1.0f, 0.38f };

						int sailPixels[18][24] = {
							/* 0 */        /* 5 */        /* 10 */       /* 15 */
				   /*0*/{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
						{ 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0 },
						{ 0, 0, 0, 1, 2, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 2, 1, 0, 0, 0 },
						{ 0, 0, 0, 1, 2, 1, 4, 1, 0, 1, 4, 3, 3, 4, 1, 0, 1, 4, 1, 2, 1, 0, 0, 0 },
				   /*5*/{ 0, 0, 0, 1, 2, 2, 2, 4, 1, 1, 4, 3, 3, 4, 1, 1, 4, 2, 2, 2, 1, 0, 0, 0 },
						{ 0, 0, 0, 1, 2, 2, 2, 4, 4, 1, 4, 3, 3, 4, 1, 4, 4, 2, 2, 2, 1, 0, 0, 0 },
						{ 0, 0, 0, 1, 2, 2, 2, 2, 4, 4, 4, 3, 3, 4, 4, 4, 2, 2, 2, 2, 1, 0, 0, 0 },
						{ 0, 0, 0, 1, 1, 2, 2, 2, 4, 4, 4, 3, 3, 4, 4, 4, 2, 2, 2, 1, 1, 0, 0, 0 },
						{ 0, 0, 0, 0, 1, 2, 2, 2, 4, 2, 2, 3, 3, 2, 2, 4, 2, 2, 2, 1, 0, 0, 0, 0 },
				  /*10*/{ 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 1, 2, 2, 4, 2, 3, 3, 2, 4, 2, 2, 1, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 2, 3, 3, 2, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 3, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				  /*15*/{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 3, 3, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },



						};
						for (int i = 0; i < 18; i++)
						{
							for (int j = 0; j < 24; j++)
							{
								if (sailPixels[i][j])
								{
									drawPixel(j + 5, i + 12, reds[sailPixels[i][j]], greens[sailPixels[i][j]], blues[sailPixels[i][j]]);
								}
							}
						}
					}
				}
				
			}
		}
	}
	
};