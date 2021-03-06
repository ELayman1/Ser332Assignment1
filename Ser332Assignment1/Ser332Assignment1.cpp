// Ser332Assignment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "glut.h"

GLint viewWidth = 500;
GLint viewHeight = 500; 

GLfloat angle = 0.0f;  // Current rotational angle of the shapes

float posX = 0.0f;
float posY = 0.0f;
float posZ = 0.0f;

int posX2 = 0;
int posY2 = 0;



// myInit
void myInit() {
	glClearColor(0.0f, 0.0f, 0.2f, 1.0); // grey-blue clear color
	glClearDepth(1.0);
								  
	glMatrixMode(GL_PROJECTION); // projection transformations
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // units inside


}

void idle() {
	glutPostRedisplay();   // Post a re-paint request to activate display()
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
											   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset the projection matrix
	if (width >= height) {
		// aspect >= 1, set the height from -1 to 1, with larger width
		gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
	}
	else {
		// aspect < 1, set the width to -1 to 1, with larger height
		gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
	}
	width = viewWidth; 
	height = viewHeight;
}

void specialInput(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_LEFT: 
			posX = posX - 0.05f;
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT: 
			posX = posX + 0.05f;
			glutPostRedisplay();
			break;
		case GLUT_KEY_UP: 
			posY = posY + 0.05f;
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN: 
			posY = posY - 0.05f;
			glutPostRedisplay();
			break;
	}
}

void myMouseMove(int x, int y)
{
	posX2 = x;
	posY2 = viewHeight - y;

	glutPostRedisplay();
}

// 2DScene
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // clear the window
	glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
	glLoadIdentity();
	
//--Roof-----------------------------------------------
	//Right Roof Triangle
	glBegin(GL_TRIANGLES);  // fill connected polygon
	glColor3f(1.0f, 0.0f, 0.0f);  // red
	glVertex2f(0.41, 0.55);  // vertices of the triangle 2
	glVertex2f(0.41, 0.2);
	glVertex2f(0.125, 0.55);
	glEnd();
	//Right Roof Square
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(1.0f, 0.0f, 0.0f);  // red
	glVertex3f(0.41, 0.55, 0.0);  // vertices of the square 1
	glVertex3f(0.41, 0.2, 0.0);
	glVertex3f(0.7, 0.2, 0.0);
	glVertex3f(0.7, 0.55, 0.0);
	glEnd();
	//Left Roof Triangle
	glBegin(GL_TRIANGLES);  // fill connected polygon
	glColor3f(1.0f, 0.0f, 0.0f);  // red
	glVertex2f(-0.41, 0.55);  // vertices of the triangle 3
	glVertex2f(-0.41, 0.2);
	glVertex2f(-0.125, 0.55);
	glEnd();
	//Right Roof Square
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(1.0f, 0.0f, 0.0f);  // red
	glVertex3f(-0.41, 0.55, 0.0);  // vertices of the square 2
	glVertex3f(-0.41, 0.2, 0.0);
	glVertex3f(-0.7, 0.2, 0.0);
	glVertex3f(-0.7, 0.55, 0.0);
	glEnd();
	//Roof Lines
	glLineWidth(1.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.7, 0.25, 0.0);
	glVertex3f(0.7, 0.25, 0.0);
	glEnd();
	//Roof Lines
	glLineWidth(1.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.7, 0.3, 0.0);
	glVertex3f(0.7, 0.3, 0.0);
	glEnd();
	//Roof Lines
	glLineWidth(1.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.7, 0.35, 0.0);
	glVertex3f(0.7, 0.35, 0.0);
	glEnd();
	//Roof Lines
	glLineWidth(1.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.7, 0.4, 0.0);
	glVertex3f(0.7, 0.4, 0.0);
	glEnd();
	//Roof Lines
	glLineWidth(1.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.7, 0.45, 0.0);
	glVertex3f(0.7, 0.45, 0.0);
	glEnd();
	//Roof Lines
	glLineWidth(1.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.7, 0.5, 0.0);
	glVertex3f(0.7, 0.5, 0.0);
	glEnd();
	//Middle Roof Triangle
	glBegin(GL_TRIANGLES);  // fill connected polygon
	glColor3f(1.0f, 1.0f, 0.95f);  // off white
	glVertex2f(-0.4, 0.2);  // vertices of the triangle 1
	glVertex2f(0.4, 0.2);
	glVertex2f(0.0, 0.7);
	glEnd();

//--MainHouse------------------------------------------
	//Main House Square
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(1.0f, 1.0f, 0.95f);  // off white
	glVertex3f(-0.7, -0.6, 0.0);  // vertices of the square 2
	glVertex3f(-0.7, 0.2, 0.0);
	glVertex3f(0.7, 0.2, 0.0);
	glVertex3f(0.7, -0.6, 0.0);
	glEnd();
//--Windows--------------------------------------------
	//High Window
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(0.6f, 0.77f, 0.8f);  // grey-blue
	glVertex3f(-0.1, 0.4, 0.0);  // vertices of the square 2
	glVertex3f(-0.1, 0.15, 0.0);
	glVertex3f(0.1, 0.15, 0.0);
	glVertex3f(0.1, 0.4, 0.0);
	glEnd();
	//Left Window
	glBegin(GL_QUADS);  // fill connected polygon 
	glColor3f(0.6f, 0.77f, 0.8f);  // grey-blue
	glVertex3f(-0.6, -0.5, 0.0);  // vertices of the square 2
	glVertex3f(-0.6, -0.1, 0.0);
	glVertex3f(-0.2, -0.1, 0.0);
	glVertex3f(-0.2, -0.5, 0.0);
	glEnd();
	//Window Reflection
	glLineWidth(5.0);
	glColor3f(1.0f, 1.0f, 1.0f); // white
	glBegin(GL_LINES);
	glVertex3f(-0.5, -0.4, 0.0);
	glVertex3f(-0.3, -0.2, 0.0);
	glEnd();
	//Window Reflection
	glLineWidth(5.0);
	glColor3f(1.0f, 1.0f, 1.0f); // white
	glBegin(GL_LINES);
	glVertex3f(-0.425, -0.425, 0.0);
	glVertex3f(-0.275, -0.275, 0.0);
	glEnd();
	//Window Reflection
	glLineWidth(5.0);
	glColor3f(1.0f, 1.0f, 1.0f); // white
	glBegin(GL_LINES);
	glVertex3f(-0.35, -0.425, 0.0);
	glVertex3f(-0.250, -0.35, 0.0);
	glEnd();
	//Right Window
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(0.6f, 0.77f, 0.8f);  // grey-blue
	glVertex3f(0.6, -0.5, 0.0);  // vertices of the square 2
	glVertex3f(0.6, -0.1, 0.0);
	glVertex3f(0.2, -0.1, 0.0);
	glVertex3f(0.2, -0.5, 0.0);
	glEnd();
	//Window Reflection
	glLineWidth(5.0);
	glColor3f(1.0f, 1.0f, 1.0f); // white
	glBegin(GL_LINES);
	glVertex3f(0.5, -0.4, 0.0);
	glVertex3f(0.3, -0.2, 0.0);
	glEnd();
	//Window Reflection
	glLineWidth(5.0);
	glColor3f(1.0f, 1.0f, 1.0f); // white
	glBegin(GL_LINES);
	glVertex3f(0.425, -0.425, 0.0);
	glVertex3f(0.275, -0.275, 0.0);
	glEnd();
	//Window Reflection
	glLineWidth(5.0);
	glColor3f(1.0f, 1.0f, 1.0f); // white
	glBegin(GL_LINES);
	glVertex3f(0.35, -0.425, 0.0);
	glVertex3f(0.25, -0.35, 0.0);
	glEnd();

//--Floor----------------------------------------------
	//Street
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(0.0f, 0.0f, 0.0f);  // black
	glVertex3f(-1.0, -1.0, 0.0);  // vertices of the square 2
	glVertex3f(-1.0, -0.8, 0.0);
	glVertex3f(1.0, -0.8, 0.0);
	glVertex3f(1.0, -1.0, 0.0);
	glEnd();
	//Concrete Square
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(0.6f, 0.6f, 0.6f);  // grey
	glVertex3f(-1.0, -0.6, 0.0);  // vertices of the square 2
	glVertex3f(-1.0, -0.8, 0.0);
	glVertex3f(1.0, -0.8, 0.0);
	glVertex3f(1.0, -0.6, 0.0);
	glEnd();
	//Back House Square
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(1.0f, 1.0f, 0.95f);  // off white
	glVertex3f(0.85, -0.6, 0.0);  // vertices of the square 2
	glVertex3f(0.85, -0.73, 0.0);
	glVertex3f(-0.85, -0.73, 0.0);
	glVertex3f(-0.85, -0.6, 0.0);
	glEnd();
	//Dirt Left Square
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(0.4f, 0.15f, 0.03f);  // brown
	glVertex3f(-0.85, -0.6, 0.0);  // vertices of the square 2
	glVertex3f(-0.85, -0.73, 0.0);
	glVertex3f(-0.2, -0.73, 0.0);
	glVertex3f(-0.2, -0.6, 0.0);
	glEnd();
	//Dirt Right Square
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(0.4f, 0.15f, 0.03f);  // brown
	glVertex3f(0.85, -0.6, 0.0);  // vertices of the square 2
	glVertex3f(0.85, -0.73, 0.0);
	glVertex3f(0.2, -0.73, 0.0);
	glVertex3f(0.2, -0.6, 0.0);
	glEnd();
	//Main Lower House Square
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(1.0f, 1.0f, 0.95f);  // off white
	glVertex3f(-0.75, -0.55, 0.0);  // vertices of the square 2
	glVertex3f(-0.75, -0.65, 0.0);
	glVertex3f(0.75, -0.65, 0.0);
	glVertex3f(0.75, -0.55, 0.0);
	glEnd();
	
//--Door-----------------------------------------------
	//Door
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(0.4f, 0.0f, 0.1f);  // brown
	glVertex3f(-0.1, -0.65, 0.0);  // vertices of the square 2
	glVertex3f(-0.1, -0.25, 0.0);
	glVertex3f(0.1, -0.25, 0.0);
	glVertex3f(0.1, -0.65, 0.0);
	glEnd();
	//Door Window
	glBegin(GL_QUADS);  // fill connected polygon
	glColor3f(0.6f, 0.77f, 0.8f);  // grey-blue
	glVertex3f(-0.05, -0.4, 0.0);  // vertices of the square 2
	glVertex3f(-0.05, -0.3, 0.0);
	glVertex3f(0.05, -0.3, 0.0);
	glVertex3f(0.05, -0.4, 0.0);
	glEnd();
//-----------------------------------------------------
	
//MaroonHouseLines-------------------------------------
    //Roof Diagonal Right
	glLineWidth(10.0);
	glColor3f(0.5f, 0.0f, 0.2f); // maroon
	glBegin(GL_LINES);
	glVertex3f(0.4, 0.2, 0.0);
	glVertex3f(0.0, 0.7, 0.0);
	glEnd();
	//Roof Diagonal Left
	glLineWidth(10.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.4, 0.2, 0.0);
	glVertex3f(0.0, 0.7, 0.0);
	glEnd();
    //Roof Horizontal Left
	glLineWidth(10.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.39, 0.2, 0.0);
	glVertex3f(-0.7, 0.2, 0.0);
	glEnd();
	//Roof Horizontal Right
	glLineWidth(10.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(0.39, 0.2, 0.0);
	glVertex3f(0.7, 0.2, 0.0);
	glEnd();
	//Roof Vertical Left
	glLineWidth(10.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.7, 0.57, 0.0);
	glVertex3f(-0.7, 0.187, 0.0);
	glEnd();
	//Roof Vertical Right
	glLineWidth(10.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(0.7, 0.57, 0.0);
	glVertex3f(0.7, 0.187, 0.0);
	glEnd();
	//Roof Horizontal LowerLedge
	glLineWidth(10.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.72, 0.05, 0.0);
	glVertex3f(0.72, 0.05, 0.0);
	glEnd();
	//Roof Horizontal UpperLedge
	glLineWidth(10.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.74, 0.07, 0.0);
	glVertex3f(0.74, 0.07, 0.0);
	glEnd();
	//Left Window Horizontal UpperLedge 1
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.62, -0.1, 0.0);
	glVertex3f(-0.18, -0.1, 0.0);
	glEnd();
	//Left Window Horizontal UpperLedge 2
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.64, -0.08, 0.0);
	glVertex3f(-0.16, -0.08, 0.0);
	glEnd();
	//Left Window Vertical 1 
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.6, -0.5, 0.0);
	glVertex3f(-0.6, -0.1, 0.0);
	glEnd();
	//Left Window Vertical 2
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.2, -0.5, 0.0);
	glVertex3f(-0.2, -0.1, 0.0);
	glEnd();
	//Left Window Vertical 3
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.4, -0.5, 0.0);
	glVertex3f(-0.4, -0.1, 0.0);
	glEnd();
	//Right Window Horizontal 
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.61, -0.2, 0.0);
	glVertex3f(-0.19, -0.2, 0.0);
	glEnd();
	//Left Window Horizontal LowerLedge
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.61, -0.5, 0.0);
	glVertex3f(-0.19, -0.5, 0.0);
	glEnd();
	//Right Window Horizontal UpperLedge 1
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(0.62, -0.1, 0.0);
	glVertex3f(0.18, -0.1, 0.0);
	glEnd();
	//Right Window Horizontal UpperLedge 2
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(0.64, -0.08, 0.0);
	glVertex3f(0.16, -0.08, 0.0);
	glEnd();
	//Right Window Vertical 1 
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(0.6, -0.5, 0.0);
	glVertex3f(0.6, -0.1, 0.0);
	glEnd();
	//Right Window Vertical 2
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(0.2, -0.5, 0.0);
	glVertex3f(0.2, -0.1, 0.0);
	glEnd();
	//Right Window Vertical 3
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(0.4, -0.5, 0.0);
	glVertex3f(0.4, -0.1, 0.0);
	glEnd();
	//Right Window Horizontal 
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(0.61, -0.2, 0.0);
	glVertex3f(0.19, -0.2, 0.0);
	glEnd();
	//Right Window Horizontal LowerLedge
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(0.61, -0.5, 0.0);
	glVertex3f(0.19, -0.5, 0.0);
	glEnd();
	//High Window Left Trim
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.1, 0.41, 0.0);  // vertices of the square 2
	glVertex3f(-0.1, 0.14, 0.0);
	//High Window Middle Trim
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.0, 0.4, 0.0);  // vertices of the square 2
	glVertex3f(-0.0, 0.15, 0.0);
	//High Window Right Trim
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(0.1, 0.14, 0.0);
	glVertex3f(0.1, 0.41, 0.0);
	//High Window Top Trim
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.1, 0.4, 0.0);
	glVertex3f(0.1, 0.4, 0.0);
	//High Window Middle Trim
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.1, 0.3, 0.0);
	glVertex3f(0.1, 0.3, 0.0);
	//High Window Bottom Trim
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.1, 0.15, 0.0);
	glVertex3f(0.1, 0.15, 0.0);
	glEnd();
	//Door Window Horizontal Trim
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.05, -0.35, 0.0);  
	glVertex3f(0.05, -0.35, 0.0);
	glEnd();
	//Door Window Vertical Trim
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(0.0, -0.3, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glEnd();
	//Middle Roof Vertical
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.7, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	//Middle Roof Horizontal
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.17, 0.5, 0.0);
	glVertex3f(0.17, 0.5, 0.0);
	glEnd();
	//Middle Roof Horizontal
	glLineWidth(5.0);
	glColor3f(0.5f, 0.0f, 0.2f); //maroon
	glBegin(GL_LINES);
	glVertex3f(-0.17, 0.5, 0.0);
	glVertex3f(0.17, 0.5, 0.0);
	glEnd();

//--Stars---------------------------------------------------------
	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(-0.8f, 0.5f, 0.0f);     // Translate
	glScalef(0.125f, 0.125f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix
	
	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(0.5f, 0.75f, 0.0f);     // Translate
	glScalef(0.125f, 0.125f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix

	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(0.8f, 0.4f, 0.0f);     // Translate
	glScalef(0.1f, 0.1f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix

	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(-0.6f, 0.65f, 0.0f);     // Translate
	glScalef(0.15f, 0.15f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix

	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(-0.5f, 0.85f, 0.0f);     // Translate
	glScalef(0.15f, 0.15f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix

	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(-0.2f, 0.9f, 0.0f);     // Translate
	glScalef(0.1f, 0.1f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix

	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(-0.25f, 0.65f, 0.0f);     // Translate
	glScalef(0.15f, 0.15f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix

	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(-0.8f, 0.8f, 0.0f);     // Translate
	glScalef(0.125f, 0.125f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix

	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(0.85f, 0.65f, 0.0f);     // Translate
	glScalef(0.15f, 0.15f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix

	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(0.6f, 0.85f, 0.0f);     // Translate
	glScalef(0.15f, 0.15f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix

	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(0.2f, 0.85f, 0.0f);     // Translate
	glScalef(0.125f, 0.125f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix

//--Bat------------------------------------------------
	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(posX, posY, posZ);     // Translate
	glBegin(GL_TRIANGLES);  // fill connected polygon
	glColor3f(0.5f, 0.5f, 0.5f);  // grey
	glVertex2f(0.01, 0.0);  // vertices of the triangle 3
	glVertex2f(-0.05, 0.07);
	glVertex2f(-0.2, 0.05);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix
	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(posX, posY, posZ);     // Translate
	glBegin(GL_TRIANGLES);  // fill connected polygon
	glColor3f(0.5f, 0.5f, 0.5f);  // grey
	glVertex2f(-0.01, 0.0);  // vertices of the triangle 3
	glVertex2f(0.05, 0.07);
	glVertex2f(0.2, 0.05);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix

//--Bat2-----------------------------------------------
	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(posX2, posY2, 0.0);     // Translate
	glBegin(GL_TRIANGLES);  // fill connected polygon
	glColor3f(0.3f, 0.3f, 0.3f);  // grey
	glVertex2f(0.01, 0.1);  // vertices of the triangle 3
	glVertex2f(-0.05, 0.17);
	glVertex2f(-0.2, 0.15);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix
	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(posX2, posY2, 0.0);     // Translate
	glBegin(GL_TRIANGLES);  // fill connected polygon
	glColor3f(0.3f, 0.3f, 0.3f);  // grey
	glVertex2f(-0.01, 0.1);  // vertices of the triangle 3
	glVertex2f(0.05, 0.17);
	glVertex2f(0.2, 0.15);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix


//--End------------------------------------------------
	glutSwapBuffers();

	// Change the rotational angle after each display()
	angle += 0.2f;

}

// Main
void main(int argc, char** argv) {
	glutInit(&argc, argv); // glut init
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(viewWidth, viewHeight); // actual window size	
	glutInitWindowPosition(50, 50); // window location
	glutCreateWindow("Elayman1 - Ser332 Assignment1");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	myInit();
	glutSpecialFunc(specialInput);
	glutPassiveMotionFunc(myMouseMove);
	glutMainLoop(); //event loop 
}

