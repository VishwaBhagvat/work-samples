#include <stdlib.h>
#include <string.h>
#include <math.h>

  #include <GL/gl.h>
  #include <GL/glu.h>
  #include <GL/glut.h>


  //This is a computer graphics coding project where a rotating cube initially shows up when the user runs the code.  When the user clicks on the space
  //button on the keyboard, the cube explodes into many particles which look like they go farther and eventually disappear from the user's sight.
  //Eventually the user will end up seeing complete black darkness when all the particles disappear.

 int cube_exploded=0;
static GLfloat angle = 150;   /* in degrees */
float Angle=0.0;
GLfloat  light0Amb[4] =  { 1.0, 0.0, 0.0, 0.0 };
GLfloat  light0Dif[4] =  { 1.0, 0.0, 0.0, 0.0 };
GLfloat  light0Spec[4] = { 0.0, 0.0, 1.0, 0.0 };
GLfloat  light0Pos[4] =  { 0.0, 0.0, 0.0, 1.0 };
GLfloat  light1Amb[4] =  { 0.0, 0.0, 1.0, 0.0 };
GLfloat  light1Dif[4] =  { 0.0, 0.0, 1.0, 0.0 };
GLfloat  light1Spec[4] = { 0.0, 0.0, 1.0, 0.0 };
GLfloat  light1Pos[4] =  { 0.0, 1.0, 3.0, 0.0 };
static int spin = 0;
static int moving, begin;
static int newModel = 1;
static float time;
static int repeat = 1;
int useMipmaps = 1;
int linearFiltering = 1;

static GLfloat constant[3] = { 1/5.0, 0.0, 0.0 };
static GLfloat linear[3] = { 0.0, 1/5.0, 0.0 };
static GLfloat quad[3] = { 0.25, 0.0, 1/60.0 };





#define MAX_POINTS 11000

static int numPoints = 10000;

static GLfloat pointList[MAX_POINTS][3];
static GLfloat pointTime[MAX_POINTS];
static GLfloat pointVelocity[MAX_POINTS][3];
static GLfloat pointDirection[MAX_POINTS][3];
static int colorList[MAX_POINTS];
static int animate = 1, motion = 0;

static GLfloat colorSet[][4] = {
  /* Shades of red. */
  { 1.0, 0.0, 0.0, 0.0 },     //0.7 0.2 0.4 0.5
  { 1.0, 0.0, 0.0, 0.0 },     //0.8 0.0 0.7 0.5
  { 1.0, 0.0, 0.0, 0.0 },      //last is 0.5
  { 0.0, 1.0, 0.0, 0.0 },      //0.9 0.3 0.6 0.5
  { 1.0, 0.4, 0.0, 0.5 },
  { 1.0, 0.0, 0.5, 0.5 },
};

#define NUM_COLORS (sizeof(colorSet)/sizeof(colorSet[0]))

#define DEAD (NUM_COLORS+1)


#if 0

#else
static float float_rand(void) { return rand() / (float) RAND_MAX; }
#define RANDOM_RANGE(lo, hi) ((lo) + (hi - lo) * float_rand())
#endif

#define MEAN_VELOCITY 3.0  //3

#define TIME_DELTA 0.025  /* The speed of time. */


#define EDGE 3   //12
void reshape (int w, int h)
{
  glViewport (0.0, 0.0, (GLfloat) w, (GLfloat) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective (45.0, (GLfloat) w / (GLfloat) h, 0.1, 100.0);
  glMatrixMode (GL_MODELVIEW);

}


void
makePointList(void)
{
  float angle, velocity, direction;
  int i;

  motion = 1;
  for (i=0; i<numPoints; i++) {
    pointList[i][0] = 0.0;           //y=0
    pointList[i][1] = 0.0;           //y=1
    pointList[i][2] = 0.0;           //y=2
    pointTime[i] = 0.0;
    angle = (RANDOM_RANGE(60.0, 70.0)) * M_PI/180.0;
    direction = RANDOM_RANGE(0.0, 360.0) * M_PI/180.0;
    pointDirection[i][0] = cos(direction);
    pointDirection[i][1] = sin(direction);
    velocity = MEAN_VELOCITY;
    pointVelocity[i][0] = velocity* cos(angle);
    pointVelocity[i][1] = velocity* sin(angle);
    //colorList[i] = rand() % NUM_COLORS;
  }
  time = 0.0;
}

void
updatePointList(void)
{
  float displacement;
  int i;

  motion = 0;
  for (i=0; i<numPoints; i++) {
    displacement = pointVelocity[i][0] * time;

    int y=rand()%3;
    if(y==0)
    {
        pointList[i][0] = pointDirection[i][0] * displacement;

    }
    else if (y==1)
    {
        pointList[i][1] = (pointVelocity[i][1]-0.5) * displacement;
    }
    else if(y==2)
    {
        pointList[i][2]=pointDirection[i][1] * displacement;
    }

    if (pointList[i][1] <= 0.0) {
      if (displacement > EDGE) {

       colorList[i] = NUM_COLORS;
       continue;
      }

      pointVelocity[i][1] *= 0.8;
      pointTime[i] = 0.0;
    }
    motion = 1;
    pointTime[i] += TIME_DELTA;
  }
  time += TIME_DELTA;
  int j;




  if (!motion && !spin) {
    if (repeat) {
      makePointList();
    } else {
      glutIdleFunc(NULL);
    }
  }

}
void Idle (void)
{
    if(!cube_exploded)
    {
  Angle += 0.3;

  glutPostRedisplay ();
}
}
void idle(void)
{
 if(!cube_exploded)
 {
     Angle+=0.3;
 }
else
{

  updatePointList();
  if (spin) {
    angle += 0.3;

    newModel = 1;

  }
  int j;





}
  glutPostRedisplay();

}

void
visible(int vis)
{
  if (vis == GLUT_VISIBLE) {
    if (animate && (motion || spin)) {
      glutIdleFunc(idle);
    }
  } else {
    glutIdleFunc(NULL);
  }
}

void
recalcModelView(void)
{
  glPopMatrix();
  glPushMatrix();
  glRotatef(angle, 0.0, 1.0, 0.0);
  newModel = 0;
}


void display (void)
{
  int i;

  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity ();
//
// Place the camera
  glTranslatef (0.0, 0.0, -10.0);
  glRotatef (Angle, 0.0, 1.0, 0.0);
//
// If no explosion, draw cube
  if (!cube_exploded)
  {

    glEnable (GL_LIGHTING);
    glDisable (GL_LIGHT0);
    glEnable (GL_DEPTH_TEST);
    glEnable (GL_LIGHT0);
    glEnable (GL_LIGHT1);
  glLightfv (GL_LIGHT0, GL_AMBIENT, light0Amb);
  glLightfv (GL_LIGHT0, GL_DIFFUSE, light0Dif);
  glLightfv (GL_LIGHT0, GL_SPECULAR, light0Spec);
  glLightfv (GL_LIGHT0, GL_POSITION, light0Pos);
  glLightfv (GL_LIGHT1, GL_AMBIENT, light1Amb);
  glLightfv (GL_LIGHT1, GL_DIFFUSE, light1Dif);
  glLightfv (GL_LIGHT1, GL_SPECULAR, light1Spec);
  glLightfv (GL_LIGHT1, GL_POSITION, light1Pos);
  glLightModelf (GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  glEnable (GL_NORMALIZE);
    glutSolidCube (1.0);
  }
  else
  {
        int i;


  if (newModel)
    recalcModelView();

  glDepthMask(GL_FALSE);




  glEnable(GL_TEXTURE_2D);
  glColor3f(0.5, 1.0, 0.5);




  glDepthMask(GL_TRUE);



  glDisable(GL_TEXTURE_2D);
  glEnable (GL_LIGHTING);
    glDisable (GL_LIGHT0);
    glEnable (GL_DEPTH_TEST);
    glEnable (GL_LIGHT0);
    glEnable (GL_LIGHT1);
  glLightfv (GL_LIGHT0, GL_AMBIENT, light0Amb);
  glLightfv (GL_LIGHT0, GL_DIFFUSE, light0Dif);
  glLightfv (GL_LIGHT0, GL_SPECULAR, light0Spec);
  glLightfv (GL_LIGHT0, GL_POSITION, light0Pos);
  glLightfv (GL_LIGHT1, GL_AMBIENT, light1Amb);
  glLightfv (GL_LIGHT1, GL_DIFFUSE, light1Dif);
  glLightfv (GL_LIGHT1, GL_SPECULAR, light1Spec);
  glLightfv (GL_LIGHT1, GL_POSITION, light1Pos);
  glLightModelf (GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  glEnable (GL_NORMALIZE);

  glBegin(GL_POINTS);

    for (i=0; i<numPoints; i++) {

      if (colorList[i] != DEAD) {


        glVertex3fv(pointList[i]);

        glColor4fv(colorSet[colorList[i]]);



      }

    }


  glEnd();
  }
  glutSwapBuffers ();
}







void explode_cube(void)
{
  cube_exploded = 1;
  printf ("BOOM!\n");
}

void key(unsigned char c, int x, int y)
{
  switch (c) {
  case 13:
    animate = 1 - animate;
    if (animate && (motion || spin)) {
      glutIdleFunc(idle);
    } else {
      glutIdleFunc(NULL);
    }
    break;
  case ' ':
   explode_cube();
    animate = 1;
    makePointList();
    glutIdleFunc(idle);



    break;
  case 27:
    exit(0);
  }
}







int
main(int argc, char **argv)
{
  int i;

  glutInit(&argc, argv);
   glutInitWindowPosition (0, 0);
  glutInitWindowSize (1280, 1024);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
   glutCreateWindow("point burst");
   glutKeyboardFunc(key);



glutIdleFunc (Idle);

glutDisplayFunc (display);
glutReshapeFunc (reshape);







  glutVisibilityFunc(visible);



  glEnable(GL_DEPTH_TEST);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glPointSize(15.0);



  makePointList();

  glutMainLoop();



  return 0;





}
