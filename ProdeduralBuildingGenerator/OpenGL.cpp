#include "mainHeader.h"
#include <GL/freeglut.h>








void display() {

	vector<double> sVec;
	sVec.push_back(1);
	sVec.push_back(1);
	sVec.push_back(1);

	Symbol *a = new Symbol(sVec,sVec,"test");


	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);


	glColor3f(0.0, 1.0, 0.0);

	double x = a->position[0];
	double y = a->position[1];
	glRectd(x,y, x+2, y+2);

	glFlush();
}


void init(int argc, char **argv){
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)
	glutInitWindowSize(500, 500); // Set the width and height of the window
	glutInitWindowPosition(100, 100); // Set the position of the window
	glutCreateWindow("symbol"); // Set the title for the window

	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering

	glutIdleFunc(display); // Tell GLUT to use the method "display" as our idle method as well
	


	glutMainLoop(); // Enter GLUT's main loop

}
