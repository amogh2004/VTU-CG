/* 6. To draw a simple shaded scene consisting of a tea pot on a table.
        Define suitably the position and properties of the light source along with the properties
        of the surfaces of the solid object used in the scene.
*/

/*
ALGORITHM:
1. Initialize ambient, diffuse, specular & shininess material properties. Also initialize light intensity & position.
2. Define main()
    - Enable display mode as single, RGB and depth buffer.
    - Register shading with GL_SMOOTH.
    - Use viewport for (0,0,xmax,ymax)
    - Enable LIGHTING, LIGHT0, depth test & normalize.
3. Define reshape by gluLookAt() & clear() with color & depth buffer bit.
4. With the help of glutSolidCube () form a table (legs &top) and 3D wall.
    Use transformation functions translate, rotate and scale prefixed and suffixed by
    glPushMatrix() and PopMatrix() respectively.
5. Define display()
    - Set ambient, diffuse, specular & shininess for glMaterials ().
    - Set light intensity & position for glLightfv()
    - Call draw_wall() & draw_table().
    - Use glutSolidTeapot() to place it on the table.
*/

#include<GL/glut.h>

void obj(double tx,double ty,double tz,double sx,double sy,double sz)
{
  glRotated(50,0,1,0);
  glRotated(10,-1,0,0);
  glRotated(11.7,0,0,-1);
  glTranslated(tx,ty,tz);
  glScaled(sx,sy,sz);
  glutSolidCube(1.0);
  glLoadIdentity();
}

void display()
{
  glViewport(0,0,500,500);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  obj(0,0,0.5,1,1,0.04);
  obj(-0.5,0,0,0.04,1,1);
  obj(0,-0.3,0,0.02,0.2,0.02);
  obj(0,-0.3,-0.4,0.02,0.2,0.02);
  obj(0.4,-0.3,0,0.02,0.2,0.02);
  obj(0.4,-0.3,-0.4,0.02,0.2,0.02);
  obj(0.2,-0.18,-0.2,0.8,0.02,0.8);
  obj(0,0.-0.5,0.02,1,0.02,1);
  glTranslated(0.03,-0.2,-0.5);
  glutSolidTeapot(0.09);
  glLoadIdentity();
  glFlush();
}

int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
  GLfloat ambient[]={1,1,1,1};
  GLfloat Light_pos[]={27,80,2,3};
  glutInitWindowSize(500,500);
  glutInitWindowPosition(10,10);
  glutCreateWindow("Teapot");
  glutDisplayFunc(display);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glMaterialfv(GL_FRONT,GL_AMBIENT,ambient);
  glLightfv(GL_LIGHT0,GL_POSITION,Light_pos);
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
  return 0;
}
