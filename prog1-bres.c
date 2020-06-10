//1. Implement Brenham’s line drawing algorithm for all types of slope.

/*
Bresenham’s Line-Drawing Algorithm for |m| < 1.0
1. Input the two line endpoints and store the left endpoint in (x0, y0).

2. Set the color for frame-buffer position (x0, y0); i.e., plot the first point.

3. Calculate the constants _x, _y, 2_y, and 2_y − 2_x, and obtain the starting
    value or the decision parameter as  p0 = 2_y − _x

4. At each xk along the line, starting at k = 0, perform the following test:
    If pk < 0, the next point to plot is (xk + 1, yk ) and pk+1 = pk + 2_y
    Otherwise, the next point to plot is (xk + 1, yk + 1) and pk+1 = pk + 2_y − 2_x

5. Repeat step 4 _x − 1 more times.
*/

#include <GL/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;

void myInit()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y)
{
  glPointSize(3.0);
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void draw_line(int x1, int x2, int y1, int y2)
{
  int dx, dy, i, e;
  int incx, incy, inc1, inc2;
  int x,y;
  dx = x2-x1;
  dy = y2-y1;
  if (dx < 0) dx = -dx;
  if (dy < 0) dy = -dy;
  incx = 1;
  if (x2 < x1) incx = -1;
  incy = 1;
  if (y2 < y1) incy = -1;
  x = x1; y = y1;
  if (dx > dy)
  {
    draw_pixel(x, y);
    e = 2 * dy-dx;
    inc1 = 2*(dy-dx);
    inc2 = 2*dy;
    for (i=0; i<dx; i++)
    {
      if (e >= 0)
      {
        y += incy;
        e += inc1;
      }
      else
        e += inc2;

      x += incx;
      draw_pixel(x, y);
    }
  }
  else
  {
    draw_pixel(x, y);
    e = 2*dx-dy;
    inc1 = 2*(dx-dy);
    inc2 = 2*dx;
    for (i=0; i<dy; i++)
    {
      if (e >= 0)
      {
        x += incx;
        e += inc1;
      }
      else
        e += inc2;

      y += incy;
      draw_pixel(x, y);
    }
  }
}

void myDisplay()
{
  draw_line(x1, x2, y1, y2);
  glFlush();
}

int main(int argc, char **argv)
{
  printf( "Enter (x1, y1, x2, y2)\n");
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Bresenham's Line Drawing");
  myInit();
  glutDisplayFunc(myDisplay);
  glutMainLoop();
  return 0;
}
