#include <glut.h>

class Drawable
{ 
protected:
    const int pixelSize = 5;
	float xMin;
	float xMax;
	float yMin;
    float yMax;
    int frame0;
	void drawPixel(float xStart, float yStart, float red, float green, float blue)
	{
		xStart = xStart * pixelSize;
        yStart = yStart * pixelSize;
		glBegin(GL_POLYGON);
		{
			glColor3f(red, green, blue);
			glVertex3f(xStart, yStart, 0.0);
			glVertex3f(xStart, pixelSize + yStart, 0.0);
			glVertex3f(pixelSize + xStart, pixelSize + yStart, 0.0);
			glVertex3f(pixelSize + xStart, yStart, 0.0);
		}
        glEnd();
	}
};