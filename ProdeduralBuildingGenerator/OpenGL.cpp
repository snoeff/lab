#include "mainHeader.h"
#include <GL/freeglut.h>




static GLfloat spin = 0.0;



void display() {

	vector<double> sVec;
	sVec.push_back(0.25);
	sVec.push_back(0.25);
	sVec.push_back(0.25);

	Symbol *a = new Symbol(sVec,sVec,"test");

	glLoadIdentity();

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);


	glColor3f(1.0, 1.0, 0.0);

	double x = a->position[0];
	double y = a->position[1];
	double z = a->position[2];


	glTranslated(x,y,z);
	glRotated(45,1,1,1);
	glutSolidCube(0.25);
	glPopMatrix();

	glLoadIdentity();

	glColor3f(0.0, 1.0, 0.5);
	glTranslated(-x,-y,-z);
	glRotated(35,0.5,1,0.25);
	glutSolidCube(0.25);
	glPopMatrix();

	
	glFlush();
}

void spinDisplay(void)
{
   spin = spin + 2.0;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) 
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
         break;
      case GLUT_MIDDLE_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}


void init(int argc, char **argv){
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)
	glutInitWindowSize(500, 500); // Set the width and height of the window
	glutInitWindowPosition(100, 100); // Set the position of the window
	glutCreateWindow("symbol"); // Set the title for the window

	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering

	glutMouseFunc(mouse); // Tell GLUT to use the method "display" as our idle method as well
	


	glutMainLoop(); // Enter GLUT's main loop

}
