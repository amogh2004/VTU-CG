#include<GL/glut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2i(150,200);
	glVertex2i(200,100);
	glVertex2i(300,100);
	glVertex2i(350,200);
	glVertex2i(300,300);
	glVertex2i(200,300);
	glEnd();
	glutSwapBuffers();
}

void init()
{
	glClearColor(10,1.0,1.0,1.0);
	//glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
}

int main(int argc, char **argv)
{
	glutInit(& argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Display window");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

