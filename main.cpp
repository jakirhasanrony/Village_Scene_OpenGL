#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>


float boatX = 54.0;
float boatY = 17.0;
float boatSpeed = 0.1;


float carX = -100.0;
float carY = -76.0;
float carSpeed = 0.4;

void init(void)
{
 glClearColor(0.0,0.0,0.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-120.0, 120.0, -120.0, 120.0, -120.0, 120.0);
}


// Function to draw text on the screen
void drawText(float x, float y, const char *string)
{
    int length = strlen(string);
    glRasterPos2f(x, y);
    for (int i = 0; i < length; ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
    }
}


// circle function
void  circle(GLfloat  rx,  GLfloat  ry,  GLfloat cx,  GLfloat cy)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for  (int i=0; i<= 100;i++ )
    {
        float angle= 2.0f*3.1416*i/100;

        float x= rx * cosf(angle);
        float y= ry * sinf(angle);

        glVertex2f(x+cx,y+cy);
    }
     glEnd();
}

void  circle2(GLfloat  rx,  GLfloat  ry,  GLfloat cx,  GLfloat cy, int start, int range)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for  (int i=start; i<= range;i++ )
    {
        float angle= 2.0f*3.1416*i/100;

        float x= rx * cosf(angle);
        float y= ry * sinf(angle);

        glVertex2f(x+cx,y+cy);
    }
     glEnd();
}



// Function to draw a Quad
void drawRectQuad(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3) {
    glBegin(GL_QUADS);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}
// Function to draw a Triangle
void drawTriangle(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}



void Draw()
{
 glClear(GL_COLOR_BUFFER_BIT);

 //green field
 glColor3f(0.4, 0.8, 0.4);
 drawRectQuad(-120,20,120,20,120,-120,-120,-120);


 //sky
 glBegin(GL_POLYGON);
 glColor3f(1, 1, 1);
 glVertex2f(-120, 20);
 glVertex2f(120, 20);
 glColor3f(0.027, 0.953, 0.969);
 glVertex2f(120, 120);
 glVertex2f(-120, 120);
 glEnd();





 // road
 glColor3f(0.8, 0.8, 0.5);
 drawRectQuad(-60, -40, -60, -80, -120 , -62, -120, -16); // road below houses
 circle2( 30, 20, -60, -60, 0, 25);
 circle2( 30, 20, -60, -80, 40, 75);
 glColor3f(0.8, 0.8, 0.5);
 glRectf(-60, -60, 120, -100); // road below river
 drawRectQuad(-60, -80, -120, -100, -120 , 0, -50, -50);


 //tree body-01
 glColor3f(0.6, 0.3, 0.0);
 drawRectQuad(-107,8,-107,53,-103,53,-103,8);

 //tree shape leaf -01
 glColor3f(0.0, 0.8, 0.0);
 //circle(10, 10, -105, 50);
 circle(9, 9, -115, 50);
 circle(9, 9, -95, 50);
 circle(8, 8, -110, 57);
 circle(8, 8, -100, 57);
 circle(8, 8, -105, 43);
 glEnd();


 //tree body-02
 glColor3f(0.6, 0.3, 0.0);
 drawRectQuad(-58,18,-62,18,-62,47,-58,47);


 //tree shape leaf -02
 glColor3f(0.0, 0.8, 0.0);
 circle(7, 7, -60, 50);
 circle(5, 5, -67, 50);
 circle(5, 5, -53, 50);
 circle(4, 4, -63, 55);
 circle(4, 4, -57, 55);
 circle(4, 4, -60, 45);
 glEnd();




 // house-01
 glColor3f(1,1,1);
 drawRectQuad(-60,10,-60,6,-84,6,-84,10);
 glColor3f(0.95,0.95,0.95);
 drawRectQuad(-84,10,-84,6,-100,8,-96,10);
 glColor3f(0.95, 0.95, 0.9);
 drawRectQuad(-84,10,-84,30,-60,30,-60,10);
 glColor3f(0.929, 0.839, 0.647);
 drawRectQuad(-84,30,-92,46,-68,46,-60,30);
 glColor3f(0.800, 0.720, 0.650);
 drawRectQuad(-100,30,-92,46,-88,40,-96,30);
 glColor3f(0.85,0.85,0.8);
 drawRectQuad(-96,30,-84,30,-84,10,-96,10);
 glColor3f(0.85,0.85,0.8);
 drawTriangle(-96,30,-88,40,-84,30);


 //door-01
 glColor3f(0.686,0.525,0.345);
 drawRectQuad(-78,28,-64,28,-64,10,-78,10);
 glColor3f(0.55,0.45,0.22);
 drawRectQuad(-70,16,-66,16,-66,10,-70,10);
 glColor3f(0.55,0.45,0.22);
 drawRectQuad(-76,16,-72,16,-72,10,-76,10);
 glColor3f(0.55,0.45,0.22);
 drawRectQuad(-66,18,-70,18,-70,24,-66,24);
 glColor3f(0.55,0.45,0.22);
 drawRectQuad(-76,18,-76,24,-72,24,-72,18);



 //window-01
 glColor3f(0.686,0.525,0.345);
 drawRectQuad(-86,18,-95,18,-95,28,-86,28);
 glColor3f(0.85,0.85,0.8);
 drawRectQuad(-87,19,-88,19,-88,27,-87,27);
 glColor3f(0.85,0.85,0.8);
 drawRectQuad(-90,19,-91,19,-91,27,-90,27);
 glColor3f(0.85,0.85,0.8);
 drawRectQuad(-93,19,-94,19,-94,27,-93,27);


 //house-02
 glColor3f(0.800, 0.720, 0.650);
 drawTriangle(-50,46,-40,30,-60,30);
 glColor3f(0.95, 0.95, 0.9);
 drawRectQuad(-40,30,-14,30,-14,10,-40,10);
 glColor3f(0.85,0.85,0.8);
 drawRectQuad(-60,30,-40,30,-40,10,-60,12);
 glColor3f(0.929, 0.839, 0.647);
 drawRectQuad(-50,46,-22,46,-14,30,-40,30);
 glColor3f(1,1,1);
 drawRectQuad(-40,10,-14,10,-14,6,-40,6);
 glColor3f(0.95,0.95,0.95);
 drawRectQuad(-60,12,-40,10,-40,6,-60,8);




 // window-2.1
 glColor3f(0.686,0.525,0.345);
 drawRectQuad(-42,16,-49,16,-49,24,-42,24);
 glColor3f(0.85,0.85,0.8);
 drawRectQuad(-43,17,-44,17,-44,23,-43,23);
 glColor3f(0.85,0.85,0.8);
 drawRectQuad(-45,17,-46,17,-46,23,-45,23);
 glColor3f(0.85,0.85,0.8);
 drawRectQuad(-47,17,-48,17,-48,23,-47,23);


  // window-2.2
 glColor3f(0.686,0.525,0.345);
 drawRectQuad(-51,16,-56,16,-56,24,-51,24);
 glColor3f(0.85,0.85,0.8);
 drawRectQuad(-52,17,-53,17,-53,23,-52,23);
 glColor3f(0.85,0.85,0.8);
 drawRectQuad(-54,17,-55,17,-55,23,-54,23);


 //door-2
 glColor3f(0.686,0.525,0.345);
 drawRectQuad(-20,10,-34,10,-34,26,-20,26);
 glColor3f(0.55,0.45,0.22);
 drawRectQuad(-22,10,-26,10,-26,16,-22,16);
 glColor3f(0.55,0.45,0.22);
 drawRectQuad(-22,18,-26,18,-26,24,-22,24);
 glColor3f(0.55,0.45,0.22);
 drawRectQuad(-28,10,-32,10,-32,16,-28,16);
 glColor3f(0.55,0.45,0.22);
 drawRectQuad(-28,18,-32,18,-32,24,-28,24);

 //stair-2
 glColor3f(0.55,0.45,0.22);
 drawRectQuad(-16,0,-30,0,-34,6,-20,6);
 glColor3f(0.8, 0.8, 0.5);
 drawRectQuad(-12,-60,-17,-60,-26,0,-22,0);


 // house 2 to house 1 road:
 glColor3f(0.8, 0.8, 0.5);
 drawRectQuad(-18,-14,-66,-10,-64,-4,-22,-8);
 glColor3f(0.8, 0.8, 0.5);
 drawRectQuad(-66,-10,-76,6,-70,6,-64,-4);

//house 1 to road left
 glColor3f(0.8, 0.8, 0.5);
 drawRectQuad(-120,-16,-120,-13,-69,-4,-67,-7);


 //white circle
 glColor3f(1 , 1, 1);
 circle(10, 10, 108, 104);

 // river border
 glColor3f(0.8, 0.4, 0.1);
 circle(11.5, 10, 34, 10);
 circle(52, 20, 77, -30);

 // river
 glColor3f(0.0, 0.75, 1.0);
 glRectf(34, -30, 120, 20);
 circle(10, 10, 34, 10);
 circle(50, 18, 77, -30);

  // grass field
 glColor3f(0.4, 0.8, 0.4);
 circle(12, 10, 32, -10);



 // hill shape
 glColor3f(0.0, 0.5, 0.0);
 drawTriangle(92, 20, 95, 30, 100, 20);
 drawTriangle(98, 20, 105, 30, 110, 20);
 drawTriangle(109, 20, 115, 30, 122, 20);


 // Boat shape
 glColor3f(1.0, 0.5, 0.5);
 drawTriangle(boatX, boatY, boatX + 6, boatY + 12, boatX + 6, boatY);
 glColor3f(0.8, 0.72, 0.49);
 drawRectQuad(boatX + 5, boatY - 8, boatX + 5, boatY, boatX + 6, boatY, boatX + 6, boatY - 8);
 glColor3f(0.65, 0.16, 0.16);
 drawRectQuad(boatX - 1, boatY - 16, boatX - 7, boatY - 8, boatX + 19, boatY - 8, boatX + 13, boatY - 16);

 // Update boat position
 boatX += boatSpeed;

 // Reset boat position if it goes off-screen
 if (boatX > 120.0) {
     boatX = 54.0;
     }


 //cloud
 glColor3f(0.8, 1, 1);
 circle(10, 10, -52, 100);
 circle(8, 8, -37, 100);
 circle(8, 8, -67, 100);

 glColor3f(0.8, 1, 1);
 circle(10, 10, -100, 110);
 circle(8, 8, -85, 110);
 circle(8, 8, -115, 110);
 circle(6, 6, -95, 115);

 glColor3f(0.8, 1, 1);
 circle(12, 12, 60, 100);
 circle(10, 10, 75, 100);
 circle(10, 10, 45, 100);
 circle(8, 8, 65, 105);



 //bird shape
 //bird-1
 glBegin(GL_LINES);
 glColor3f(0.0, 0.0, 0.0);
 glVertex2f(-18,70);
 glVertex2f(-16, 72);
 glEnd();


 glBegin(GL_LINES);
 glColor3f(0.0, 0.0, 0.0);
 glVertex2f(-18,70);
 glVertex2f(-20, 72);
 glEnd();

 //bird-2
 glBegin(GL_LINES);
 glColor3f(0.0, 0.0, 0.0);
 glVertex2f(-16,74);
 glVertex2f(-14, 76);
 glEnd();


 glBegin(GL_LINES);
 glColor3f(0.0, 0.0, 0.0);
 glVertex2f(-16,74);
 glVertex2f(-18, 76);
 glEnd();


 //bird-3
 glBegin(GL_LINES);
 glColor3f(0.0, 0.0, 0.0);
 glVertex2f(-22,74);
 glVertex2f(-20, 76);
 glEnd();


 glBegin(GL_LINES);
 glColor3f(0.0, 0.0, 0.0);
 glVertex2f(-22,74);
 glVertex2f(-24, 76);
 glEnd();


 // Car on the road
    glColor3f(0.8, 0.1, 0.1);
    drawRectQuad(carX, carY, carX, carY + 26, carX + 29, carY + 26, carX + 29, carY);
     glColor3f(1.0, 1.0, 1.0);
    drawText(carX + 10, carY + 10, "Jakir Auto");
    glColor3f(0.2, 0.2, 0.2);
    circle(3, 3, carX + 9, carY);

    glColor3f(0.8, 0.1, 0.1);
    drawRectQuad(carX + 29, carY, carX + 29, carY + 15, carX + 37, carY + 15, carX + 37, carY);

    glColor3f(0.2, 0.2, 0.2);
    circle(3, 3, carX + 36, carY);

    glColor3f(0.6, 0.6, 0.8);
    drawRectQuad(carX + 29, carY + 15, carX + 29, carY + 26, carX + 37, carY + 15, carX + 37, carY + 15);



 glutSwapBuffers();


}

void update(int value)
{
    //car
    carX += carSpeed;
    if (carX > 120.0)
    {
        carX = -130.0;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
 glutInitWindowPosition(0,0);
 glutInitWindowSize(800,800);
 glutCreateWindow("Immersive Rural Scene: Moving Boat in OpenGL By: Jakir Hasan Rony");
 init();
 glutDisplayFunc(Draw);

 // Start the update loop
 glutTimerFunc(16, update, 0);
 glutMainLoop();
 return 0;
}
