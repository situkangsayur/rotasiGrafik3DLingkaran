#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

static int year = 0, day = 0;
static int up = 0, down =0, left =0, right=0;

void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	//gluLookAt((GLfloat)right,(GLfloat) up,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
	glPushMatrix();
	glColor3f(0.9,1.0,0.6);
	glutWireSphere(1.0,20,16);
	glRotatef((GLfloat) year, 0.0,1.0,0.0);
	glTranslated(2.0,0.0,0.0);
	glRotatef((GLfloat) day, 0.0,1.0,0.0);
	glColor3f(0.2,1.0,0.6);
	glutWireSphere(0.2,10,8);
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h){
	glViewport(0,0,(GLsizei) w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,(GLfloat) w/(GLfloat) h, 1.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt((GLfloat)right+1,(GLfloat) up+1,5.0,0.0,0.0,0.0,0.0,1.0,0.0);

	//	glLoadIdentity();

}

void keyboard(unsigned char key, int x, int y){
	switch(key){
	case 'd' : day = (day+10) % 360;
				glutPostRedisplay();
				break;
	case 'D' : day = (day-10) %360;
				glutPostRedisplay();
				break;
	case 'y' : year = (year + 5) %360;
				glutPostRedisplay();
				break;
	case 'Y' : year = (year-5) %360;
				glutPostRedisplay();
				break;

	default : break;
	}
}

static void keyboard2(int key, int x, int y){
	switch(key){

	case GLUT_KEY_UP : up++; printf("tara");
						glutPostRedisplay();
						break;
	case GLUT_KEY_DOWN : up--;
							glutPostRedisplay();
							break;

	default : break;
	}
}

int main(int argc, char** argv){
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(500,500);
		glutInitWindowPosition(100,100);
		glutCreateWindow("universe");
		init();
		glutDisplayFunc(display);
		glutReshapeFunc(reshape);
		glutSpecialFunc(keyboard2);
		glutKeyboardFunc(keyboard);
		glutMainLoop();
		return 0;
}
