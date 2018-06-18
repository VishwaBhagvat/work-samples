
  //Vishwa Bhagvat

#include <math.h>
#include <time.h>

  #include <GL/gl.h>
  #include <GL/glu.h>
  #include <GL/glut.h>


#define X_RESOLUTION  1280
#define Y_RESOLUTION 1000
#define UNDEFINED -1
#define NORTH 0
#define NORTHEAST 1
#define EAST 2
#define SOUTHEAST 3
#define SOUTH 4
#define SOUTHWEST 5
#define WEST 6
#define NORTHWEST 7
#define TRUE 1
#define FALSE 0
#define TIME_DELTA 0.002



// This is a computer graphics code that implements the marching squares algorithm.  I used Glut to code and display the visual representation of marching squares.  Eight balls are created and they all start off in the center.
//From there, all the eight balls move randomly following the marching squares pattern at the same time.
//You can read the link, http://jamie-wong.com/2014/08/19/metaballs-and-marching-squares/, to understand how the marching squares algorithm works.




typedef struct ball_color
{
  int r;
  int g;
  int b;
} ball_color;


typedef struct vec3
{
  int x;
  int y;
  int z;
  int direction;
} vec3;


typedef struct ball_type
{
  vec3 position;
  int radius;
  ball_color color;
} ball_type;

int cellNum=50;
GLfloat cells[50][50]={};
int MAX_X=50;
int MIN_X=0;
int MAX_Y=50;
int MIN_Y=0;
int N_X=50;
int N_Y=50;
int y3=0;
int x4=0;
int y4=0;
int x3=0;

float square1[1][4]={ {0.0, 10.0}, {0.0, 60.0}, {50.0, 10.0}, {50.0,60.0}};

ball_type ball1;
ball_type ball2;
ball_type ball3;
ball_type ball4;
ball_type ball5;
ball_type ball6;
ball_type ball7;
ball_type ball8;




int ball_hit_wall (ball_type);
int select_ball_direction (ball_type);
ball_type move_ball (ball_type);
void display (void);
void reshape (int, int);
void keyboard (unsigned char, int, int);
int x;
int y;
int x1;
int x2;
int Y1;
int y2;





int ball_hit_wall (ball_type ball)
{
  int ball_hit_wall;

  ball_hit_wall = FALSE;
  switch (ball.position.direction)
  {
    case NORTH:
      if ((ball.position.y - ball.radius) <= 0)
      {
        ball_hit_wall = TRUE;
      }
    break;
    case NORTHEAST:
      if (((ball.position.y - ball.radius) <= 0) || ((ball.position.x + ball.radius) >= X_RESOLUTION))
      {
        ball_hit_wall = TRUE;
      }
    break;
    case EAST:
      if ((ball.position.x + ball.radius) >= X_RESOLUTION)
      {
        ball_hit_wall = TRUE;
      }
    break;
    case SOUTHEAST:
      if (((ball.position.y + ball.radius) >= Y_RESOLUTION) || ((ball.position.x + ball.radius) >= X_RESOLUTION))
      {
        ball_hit_wall = TRUE;
      }
    break;
    case SOUTH:
      if ((ball.position.y + ball.radius) >= Y_RESOLUTION)
      {
        ball_hit_wall = TRUE;
      }
    break;
    case SOUTHWEST:
      if (((ball.position.y + ball.radius) >= Y_RESOLUTION) || ((ball.position.x - ball.radius) <= 0))
      {
        ball_hit_wall = TRUE;
      }
    break;
    case WEST:
      if ((ball.position.x - ball.radius) <= 0)
      {
        ball_hit_wall = TRUE;
      }
    break;
    case NORTHWEST:
      if (((ball.position.y - ball.radius) <= 0) || ((ball.position.x - ball.radius) <= 0))
      {
        ball_hit_wall = TRUE;
      }
    break;
    default:
    break;
  }
  return ball_hit_wall;
}


void cell( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{

    int n=0;
    if (((ball1.radius*ball1.radius)>= ((((x1-ball1.position.x) * (x1-ball1.position.x)) + ((y1-ball1.position.y) * (y1-ball1.position.y))))) || ((ball2.radius*ball2.radius)>= (((x1-ball2.position.x) * (x1-ball2.position.x)) + ((y1-ball2.position.y) * (y1-ball2.position.y)))) || ((ball3.radius*ball3.radius)>= (((x1-ball3.position.x) * (x1-ball3.position.x)) + ((y1-ball3.position.y) * (y1-ball3.position.y)))) || ((ball4.radius*ball4.radius)>= (((x1-ball4.position.x) * (x1-ball4.position.x)) + ((y1-ball4.position.y) * (y1-ball4.position.y)))) || ((ball5.radius*ball5.radius)>= (((x1-ball5.position.x) * (x1-ball5.position.x)) + ((y1-ball5.position.y) * (y1-ball5.position.y)))) || ((ball6.radius*ball6.radius)>= (((x1-ball6.position.x) * (x1-ball6.position.x)) + ((y1-ball6.position.y) * (y1-ball6.position.y)))) || ((ball7.radius*ball7.radius)>= (((x1-ball7.position.x) * (x1-ball7.position.x)) + ((y1-ball7.position.y) * (y1-ball7.position.y)))) || ((ball8.radius*ball8.radius)>= (((x1-ball8.position.x) * (x1-ball8.position.x)) + ((y1-ball8.position.y) * (y1-ball8.position.y)))))
    {
        n=n+1;
    }
    if(((ball1.radius*ball1.radius)>=((((x2-ball1.position.x) * (x2-ball1.position.x)) +((y2-ball1.position.y) *(y2-ball1.position.y))))) || ((ball2.radius*ball2.radius)>= (((x2-ball2.position.x) *(x2-ball2.position.x)) +((y2-ball2.position.y) *(y2-ball2.position.y)))) ||((ball3.radius*ball3.radius)>= (((x2-ball3.position.x) *(x2-ball3.position.x)) + ((y2-ball3.position.y) *(y2-ball3.position.y)))) ||((ball4.radius*ball4.radius)>= (((x2-ball4.position.x) *(x2-ball4.position.x)) + ((y2-ball4.position.y) *(y2-ball4.position.y)))) || ((ball5.radius*ball5.radius)>= (((x2-ball5.position.x) *(x2-ball5.position.x)) +((y2-ball5.position.y) *(y2-ball5.position.y)))) || ((ball6.radius*ball6.radius)>=(((x2-ball6.position.x)*(x2-ball6.position.x)) +((y2-ball6.position.y) *(y2-ball6.position.y)))) || ((ball7.radius*ball7.radius)>=(((x2-ball7.position.x) *(x2-ball7.position.x))+((y2-ball7.position.y) *(y2-ball7.position.y)))) || ((ball8.radius*ball8.radius)>=(((x2-ball8.position.x) *(x2-ball8.position.x)) +((y2-ball8.position.y) *(y2-ball8.position.y)))))
    {
        n=n+2;
    }
    if(((ball1.radius*ball1.radius)>=((((x3-ball1.position.x) * (x3-ball1.position.x)) +((y3-ball1.position.y) * (y3-ball1.position.y))))) || ((ball2.radius*ball2.radius)>=(((x3-ball2.position.x)*(x3-ball2.position.x)) + ((y3-ball2.position.y)*(y3-ball2.position.y)))) || ((ball3.radius * ball3.radius)>= (((x3-ball3.position.x) *(x3-ball3.position.x)) +((y3-ball3.position.y) *(y3-ball3.position.y)))) || ((ball4.radius*ball4.radius)>= (((x3-ball4.position.x)*(x3-ball4.position.x)) +((y3-ball4.position.y) *(y3-ball4.position.y)))) ||((ball5.radius*ball5.radius)>= (((x3-ball5.position.x) *(x3-ball5.position.x)) +((y3-ball5.position.y) *(y3-ball5.position.y)))) ||((ball6.radius *ball6.radius)>= (((x3-ball6.position.x) *(x3-ball6.position.x)) +((y3-ball6.position.y) *(y3-ball6.position.y)))) ||((ball7.radius * ball7.radius)>= (((x3-ball7.position.x) *(x3-ball7.position.x)) +((y3-ball7.position.y) *(y3-ball7.position.y)))) ||((ball8.radius * ball8.radius)>=(((x3-ball8.position.x)*(x3-ball8.position.x))+((y3-ball8.position.y)*(y3-ball8.position.y)))))
    {
        n=n+4;
    }
    if(((ball1.radius*ball1.radius)>=((((x4-ball1.position.x) * (x4-ball1.position.x)) + ((y4-ball1.position.y) * (y4-ball1.position.y))))) || ((ball2.radius*ball2.radius)>=(((x4-ball2.position.x)*(x4-ball2.position.x)) +((y4-ball2.position.y)* (y4-ball2.position.y)))) || ((ball3.radius*ball3.radius)>=(((x4-ball3.position.x) *(x4-ball3.position.x)) + ((y4-ball3.position.y) *(y4-ball3.position.y)))) || ((ball4.radius*ball4.radius)>= (((x4-ball4.position.x)*(x4-ball4.position.x)) +((y4-ball4.position.y) *(y4-ball4.position.y)))) || ((ball5.radius*ball5.radius)>=(((x4-ball5.position.x)*(x4-ball5.position.x))+((y4-ball5.position.y)*(y4-ball5.position.y)))) || ((ball6.radius*ball6.radius)>=(((x4-ball6.position.x)*(x4-ball6.position.x)) +((y4-ball6.position.y)*(y4-ball6.position.y)))) ||((ball7.radius*ball7.radius)>= (((x4-ball7.position.x)*(x4-ball7.position.x))+((y4-ball7.position.y)*(y4-ball7.position.y)))) ||((ball8.radius*ball8.radius)>=(((x4-ball8.position.x)*(x4-ball8.position.x))+((y4-ball8.position.y)*(y4-ball8.position.y)))))
    {
        n=n+8;
    }




    if( n==1 || n==14)
    {
        int Ax;
        int Ay;
        int Qx;
        int Qy;
        int px;
        int py;
        int Dx;
        int Dy;
        int Cx;
        int Cy;

        Ax=x4;
        Ay=y4;
        Cx=x1;
        Cy=y1;
        Dx=x2;
        Dy=y2;

        py=Cy;
    //px=ball.position.x+sqrt(((py-Dy)/(Cy-Dy))*((((Cx-ball.position.x)*(Cx-ball.position.x))+((Cy-ball.position.y) * (Cy-ball.position.y))-((Dx-ball.position.x)*(Dx-ball.position.x))+((Dy-ball.position.y)*(Dy-ball.position.y))+((Dx-ball.position.x)*(Dx-ball.position.x))+((Dy-ball.position.y)*(Dy-ball.position.y)) - ((py-ball.position.y)))));
    px=(Cx+Dx)/2;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           // (py-ball.position.y)))));
        Qx=Cx;
        Qy=(Ay+Cy)/2;
        //Qy=Ay+((Cy-Ay)* (1-  ((Ax-ball.position.x)*(Ax-ball.position.x) + (Ay-ball.position.y) * (Ay-ball.position.y))) /  (((Cx-ball.position.x)*(Cx-ball.position.x) + (Cy-ball.position.y)*(Cy-ball.position.y)) -  ((Ax-ball.position.x)*(Ax-ball.position.x) + (Ay-ball.position.y)*(Ay-ball.position.y))));
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glVertex2i(Qx, Qy);
        glVertex2i(px, py);
        glEnd();
    }

     if(n==2 || n==13)
    {
        int Qx;
        int Qy;
        int px;
        int py;
        int Dx;
        int Dy;
        int Cx;
        int Cy;
        int Bx;
        int By;

        Cx=x1;
        Cy=y1;
        Dx=x2;
        Dy=y2;
        Bx=x3;
        By=y3;

        py=y1;
       // px=ball.position.x+sqrt(((py-Dy)/(Cy-Dy)) * (((Cx-ball.position.x)*(Cx-ball.position.x)) + ((Cy-ball.position.y)*(Cy-ball.position.y)) - ((Dx-ball.position.x)*(Dx-ball.position.x)) +((Dy-ball.position.y)*(Dy-ball.position.y)) +(((Dx-ball.position.x)*(Dx-ball.position.x)))
         px=(Cx+Dx)/2;                                                                                                                                                                                              // +((Dy-ball.position.y)*(Dy-ball.position.y)) - ((py-ball.position.y)*(py-ball.position.y))));
        Qx=x2;
        Qy=(By+Dy)/2;
        //Qy=By+((Dy-By)* ((1-(((Bx-ball.position.x) *(Bx-ball.position.x)) + ((By-ball.position.y) *(By-ball.position.y)))) /((((Dx-ball.position.x) *(Dx-ball.position.x)) + ((Dy-ball.position.y) *(Dy-ball.position.y))) -  (((Bx-ball.position.x) *(Bx-ball.position.x)) + ((By-ball.position.y)*(By-ball.position.y))))));
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glVertex2i(Qx, Qy);
        glVertex2i(px, py);
        glEnd();
    }

     if(n==3|| n==12)
    {


        int Cx=x1;
        int Cy=y1;
        int Dx=x2;
        int Dy=y2;
        int Bx=x3;
        int By=y3;
        int px=x1;
        int Qx=x2;
        int Ax=x4;
        int Ay=y4;
        int Qy=(By+Dy)/2;
        int py=(Ay+Cy)/2;

       // int Qy=By+((Dy-By) * ((1-  (((Bx-ball.position.x)*(Bx-ball.position.x)) + ((By-ball.position.y)*(By-ball.position.y)))) / ((((Dx-ball.position.x)*(Dx-ball.position.x)) + ((Dy-ball.position.y)*(Dy-ball.position.y))) - (((Bx-ball.position.x)*(Bx-ball.position.x)) +((By-ball.position.y)*(By-ball.position.y))))));

       // int py=Ay+((Cy-Ay) * ((1-  (((Ax-ball.position.x)*(Ax-ball.position.x)) + ((Ay-ball.position.y)*(Ay-ball.position.y)))) / ((((Cx-ball.position.x)*(Cx-ball.position.x)) + ((Cy-ball.position.y)*(Cy-ball.position.y))) - (((Ax-ball.position.x)*(Ax-ball.position.x)) + ((Ay-ball.position.y)*(Ay-ball.position.y))))));
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glVertex2i(Qx, Qy);
        glVertex2i(px, py);
        glEnd();
    }

     if(n==4|| n==11)
    {
        int Cx=x1;
        int Cy=y1;
        int Dx=x2;
        int Dy=y2;
        int Bx=x3;
        int By=y3;
        int py=By;
        int Qx=Bx;
        int Ax=x4;
        int Ay=y4;
        int px=(Ax+Bx)/2;
        int Qy=(By+Dy)/2;
        //int Qy=By+((Dy-By) * ((1- (((Bx-ball.position.x) *(Bx-ball.position.x)) + ((By-ball.position.y)*(By-ball.position.y)))) / ((((Dx-ball.position.x)*(Dx-ball.position.x)) + ((Dy-ball.position.y)*(Dy-ball.position.y))) - (((Bx-ball.position.x)*(Bx-ball.position.x)) +((By-ball.position.y)*(By-ball.position.y))))));
        //int px=ball.position.x+sqrt(((py-By)/(Ay-By)) * (((  ((Ax-ball.position.x)*(Ax-ball.position.x))   + ((Ay-ball.position.y)*(Ay-ball.position.y)) - ((Bx-ball.position.x)*(Bx-ball.position.x)) + ((By-ball.position.y)*(By-ball.position.y)) +( ((Bx-ball.position.x)*(Bx-ball.position.x)) + ((By-ball.position.y)*(By-ball.position.y))
                                                                                                                                                                                                                                //                        - ((py-ball.position.y)*(py-ball.position.y)))))));
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glVertex2i(Qx, Qy);
        glVertex2i(px, py);
        glEnd();
    }

     if(n==5)
    {
        int Cx=x1;
        int Cy=y1;
        int Dx=x2;
        int Ax=x4;
        int Ay=y4;
        int Bx=x3;
        int By=y3;
        int Dy=y2;
        int py1=Ay;
        int Qx1=Ax;
        int py2=Cy;
        int Qx2=Bx;
        int px1=(Ax+Bx)/2;
        int Qy1=(Ay+Cy)/2;
        int px2=(Cx+Dx)/2;
        int Qy2=(By+Dy)/2;


        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glVertex2i(px1, py1);
        glVertex2i(Qx1, Qy1);
        glEnd();
         glBegin(GL_LINES);
        glVertex2i(px2, py2);
        glVertex2i(Qx2, Qy2);
        glEnd();


    }

     if(n==6 || n==9)
    {
        int Cx=x1;
        int Cy=y1;
        int Dx=x2;
        int Ay=y4;
        int Dy=y2;
        int py=Cy;
        int Qy=Ay;

           int px=(Cx+Dx)/2;
        int Qx=px;

        glBegin(GL_LINES);
        glVertex2i(px, py);
        glVertex2i(Qx, Qy);
        glEnd();
    }

     if(n==7|| n==8)
    {
        int Cx=x1;
        int Cy=y1;
        int Dx=x2;
        int Ax=x4;
        int Ay=y4;
        int Bx=x3;
        int By=y3;

        int Dy=y2;
        int py=y4;
        int px=(x4+x3)/2;
        //int px=ball.position.x+sqrt(((py-By)/(Ay-By)) * (((((Ax-ball.position.x)*(Ax-ball.position.x)) + ((Ay-ball.position.y)*(Ay-ball.position.y))) - (((Bx-ball.position.x)*(Bx-ball.position.x)) +((By-ball.position.y)*(By-ball.position.y))) +(((Bx-ball.position.x)*(Bx-ball.position.x))+(By-ball.position.y)*(By-ball.position.x)) -
                                                     //     (py-ball.position.y)*(py-ball.position.y))));
        int Qx=Ax;
        int Qy=(y4+y1)/2;
        //int Qy=Ay+ ((Cy-Ay) * ((1-  (((Ax-ball.position.x)*(Ax-ball.position.x)) + ((Ay-ball.position.y)*(Ay-ball.position.y)))) / ((((Cx-ball.position.x)*(Cx-ball.position.x)) + ((Cy-ball.position.y)*(Cy-ball.position.y))) - (((Ax-ball.position.x)*(Ax-ball.position.x)) +((Ay-ball.position.y)*(Ay-ball.position.y))))));
        glBegin(GL_LINES);
        glVertex2i(px, py);
        glVertex2i(Qx, Qy);
        glEnd();

    }

     if(n==10)
    {
        int Cx=x1;
        int Cy=y1;
        int Dx=x2;
        int Ax=x4;
        int Ay=y4;
        int Bx=x3;
        int By=y3;
        int Dy=y2;
        int py1=Cy;
        int Qx1=Ax;
        int py2=Ay;
        int Qx2=Bx;
        int px1=(Cx+Dx)/2;
        int Qy1=(Ay+Cy)/2;
        int px2=(Ax+Bx)/2;
        int Qy2=(Ay+By)/2;


        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glVertex2i(px1, py1);
        glVertex2i(Qx1, Qy1);
        glEnd();
         glBegin(GL_LINES);
        glVertex2i(px2, py2);
        glVertex2i(Qx2, Qy2);
        glEnd();


    }




}


int select_ball_direction (ball_type ball)
{
  int new_ball_direction, random_direction;
  float new_move_north, new_move_northeast, new_move_east, new_move_southeast, new_move_south, new_move_southwest, new_move_west, new_move_northwest;
  float random_number, lower_bound, upper_bound;

  switch (ball.position.direction)
  {
    case NORTH:
      if (((ball.position.x - ball.radius) <= 0) && ((ball.position.y - ball.radius) <= 0))
      {
        new_ball_direction = SOUTHEAST;
      }
      else
      {
        if (((ball.position.x + ball.radius) >= X_RESOLUTION) && ((ball.position.y - ball.radius) <= 0))
        {
          new_ball_direction = SOUTHWEST;
        }
        else
        {
          random_number = (float) rand() / (float) RAND_MAX * 2.0f;
          random_direction = (int) random_number;
          switch (random_direction)
          {
            case 0:
              new_ball_direction = SOUTHEAST;
            break;
            case 1:
              new_ball_direction = SOUTHWEST;
            break;
            default:
              new_ball_direction = SOUTHEAST;
            break;
          }
        }
      }
    break;
    case NORTHEAST:
      if ((ball.position.x + ball.radius) >= X_RESOLUTION)
      {
        if ((ball.position.y - ball.radius) <= 0)
        {
          new_ball_direction = SOUTHWEST;
        }
        else
        {
          random_number = (float) rand() / (float) RAND_MAX * 2.0f;
          random_direction = (int) random_number;
          switch (random_direction)
          {
            case 0:
              new_ball_direction = NORTHWEST;
            break;
            case 1:
              new_ball_direction = WEST;
            break;
            default:
              new_ball_direction = NORTHWEST;
            break;
          }
        }
      }
      else
      {
        random_number = (float) rand() / (float) RAND_MAX * 2.0f;
        random_direction = (int) random_number;
        switch (random_direction)
        {
          case 0:
            new_ball_direction = SOUTHEAST;
          break;
          case 1:
            new_ball_direction = EAST;
          break;
          default:
            new_ball_direction = SOUTHEAST;
          break;
        }
      }
    break;
    case EAST:
      if ((ball.position.y - ball.radius) <= 0)
      {
        new_ball_direction = SOUTHWEST;
      }
      else
      {
        if ((ball.position.y + ball.radius) >= Y_RESOLUTION)
        {
          new_ball_direction = NORTHWEST;
        }
        else
        {
          random_number = (float) rand() / (float) RAND_MAX * 2.0f;
          random_direction = (int) random_number;
          switch (random_direction)
          {
            case 0:
              new_ball_direction = NORTHWEST;
            break;
            case 1:
              new_ball_direction = SOUTHWEST;
            break;
            default:
              new_ball_direction = NORTHWEST;
            break;
          }
        }
      }
    break;
    case SOUTHEAST:
      if ((ball.position.y + ball.radius) >= Y_RESOLUTION)
      {
        if ((ball.position.x + ball.radius) >= X_RESOLUTION)
        {
          new_ball_direction = NORTHWEST;
        }
        else
        {
          random_number = (float) rand() / (float) RAND_MAX * 2.0f;
          random_direction = (int) random_number;
          switch (random_direction)
          {
            case 0:
              new_ball_direction = NORTH;
            break;
            case 1:
              new_ball_direction = NORTHEAST;
            break;
            case 2:
              new_ball_direction = EAST;
            break;
            default:
              new_ball_direction = NORTH;
            break;
          }
        }
      }
      else
      {
        random_number = (float) rand() / (float) RAND_MAX * 2.0f;
        random_direction = (int) random_number;
        switch (random_direction)
        {
          case 0:
            new_ball_direction = SOUTH;
          break;
          case 1:
            new_ball_direction = SOUTHWEST;
          break;
          case 2:
            new_ball_direction = WEST;
          break;
          default:
            new_ball_direction = SOUTH;
          break;
        }
      }
    break;
    case SOUTH:
      if ((ball.position.x + ball.radius) >= X_RESOLUTION)
      {
        new_ball_direction = NORTHWEST;
      }
      else
      {
        new_ball_direction = NORTHEAST;
      }
    break;
    case SOUTHWEST:
      if ((ball.position.x - ball.radius) <= 0)
      {
        if ((ball.position.y + ball.radius) >= Y_RESOLUTION)
        {
          new_ball_direction = NORTHEAST;
        }
        else
        {
          new_ball_direction = SOUTHEAST;
        }
      }
      else
      {
        random_number = (float) rand() / (float) RAND_MAX * 2.0f;
        random_direction = (int) random_number;
        switch (random_direction)
        {
          case 0:
            new_ball_direction = NORTH;
          break;
          case 1:
            new_ball_direction = NORTHWEST;
          break;
          case 2:
            new_ball_direction = WEST;
          break;
          default:
            new_ball_direction = NORTH;
          break;
        }
      }
    break;
    case WEST:
      if ((ball.position.y - ball.radius) <= 0)
      {
        new_ball_direction = SOUTHEAST;
      }
      else
      {
        if ((ball.position.y + ball.radius) >= Y_RESOLUTION)
        {
          new_ball_direction = NORTHEAST;
        }
        else
        {
          random_number = (float) rand() / (float) RAND_MAX * 2.0f;
          random_direction = (int) random_number;
          switch (random_direction)
          {
            case 0:
              new_ball_direction = NORTHEAST;
            break;
            case 1:
              new_ball_direction = SOUTHEAST;
            break;
            default:
              new_ball_direction = NORTHEAST;
            break;
          }
        }
      }
    break;
    case NORTHWEST:
      if ((ball.position.x - ball.radius) <= 0)
      {
        if ((ball.position.y - ball.radius) <= 0)
        {
          new_ball_direction = SOUTHEAST;
        }
        else
        {
          random_number = (float) rand() / (float) RAND_MAX * 2.0f;
          random_direction = (int) random_number;
          switch (random_direction)
          {
            case 0:
              new_ball_direction = NORTHEAST;
            break;
            case 1:
              new_ball_direction = EAST;
            break;
            default:
              new_ball_direction = NORTHEAST;
            break;
          }
        }
      }
      else
      {
        if ((ball.position.y - ball.radius) <= 0)
        {
          random_number = (float) rand() / (float) RAND_MAX * 2.0f;
          random_direction = (int) random_number;
          switch (random_direction)
          {
            case 0:
              new_ball_direction = SOUTHWEST;
            break;
            case 1:
              new_ball_direction = SOUTH;
            break;
            case 2:
              new_ball_direction = WEST;
            break;
            default:
              new_ball_direction = SOUTHWEST;
            break;
          }
        }
      }
    break;
    default:
    break;
  }
  ball.position.direction = new_ball_direction;
  return ball.position.direction;
}


double myFunction(double x, double y)
{
    double a=0.49;
    double b=0.5;

    return (x*x + y*y + a*a) * (x*x + y*y + a*a)-4*a*a*x*x - b*b*b*b;
}

void drawLine(int state, int i, int j, double a, double b, double c, double d)
{
    x=MIN_X + (double)i * (MAX_X-MIN_X)/N_X;
    y=MIN_Y + (double)j * (MAX_Y-MIN_Y)/N_Y;
    int halfx;
    int halfy;

    halfx=(MAX_X-MIN_X)/(2*N_X);
    halfy=(MAX_Y-MIN_Y)/(2*N_Y);
    x1=x;
    x2=x;
    Y1=y;
    y2=y;

    glBegin(GL_LINES);
    glVertex2d(x1, Y1);
    glVertex2d(x2, y2);
    glEnd();
    switch(state)
    {
      case 0:  case 15:
               break;

      case 1:

                x1=x;
                x2=x+halfx;
                Y1=y+halfy;
                y2=y;

                glBegin(GL_LINES);
                glVertex2f(x1, Y1);
                glVertex2f(x2, y2);
                glEnd();
                break;

                case 14:

                x1=x;
                x2=x+halfx;
                Y1=y+halfy;
                y2=y;

                glBegin(GL_LINES);
                glVertex2f(x1, Y1);
                glVertex2f(x2, y2);
                glEnd();
                break;

           case 2:
                 x1=x+halfx;
                 x2=x+halfx*2;
                 Y1=y;
                 y2=y+halfy;


                 glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();
                 break;


                 case 13:
                 x1=x+halfx;
                 x2=x+halfx*2;
                 Y1=y;
                 y2=y+halfy;

                 glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();
                 break;
      case 3:
                 x1=x;
                 Y1=y+halfy;
                 x2=x+halfx*2;
                 y2=y+halfy;

                 glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();
                 break;

                 case 12:
                 x1=x;
                 Y1=y+halfy;
                 x2=x+halfx*2;
                 y2=y+halfy;
                 glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();
                 break;

      case 4:
                 x1=x+halfx;
                 Y1=y+halfy*2;
                 x2=x+halfx*2;
                 y2=y+halfy;
                 glPointSize(5.0f);


                 glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();
                 break;
  case 11:
                 x1=x+halfx;
                 Y1=y+halfy*2;
                 x2=x+halfx*2;
                 y2=y+halfy;


                 glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();
                 break;

      case 5:
              x1=x;
              Y1=y+halfy;
              x2=x+halfx;
              y2=y+halfy*2;
              x3=x+halfx;
              y3=y;
              x4=x+halfx*2;
              y4=y+halfy;


              glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();
                 glBegin(GL_LINES);
                 glVertex2f(x3, y3);
                 glVertex2f(x4, y4);
                 glEnd();
              break;

      case 6:

                x1=x+halfx;
                Y1=y;
                x2=x+halfx;
                y2=y+halfy*2;
                 glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();



                break;

                case 9:

                x1=x+halfx;
                Y1=y;
                x2=x+halfx;
                y2=y+halfy*2;
                 glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();



                break;


      case 7:
                x1=x;
                Y1=y+halfy;
                x2=x+halfx;
                y2=y+halfy*2;

                glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();
                break;

                case 8:
                x1=x;
                Y1=y+halfy;
                x2=x+halfx;
                y2=y+halfy*2;

                glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();
                break;

      case 10:
               x1=x+halfx;
               Y1=y;
               x2=x;
               y2=y+halfy;
               x3=x+halfx;
               y3=y+halfy*2;
               x4=x+halfx*2;
               y4=y+halfy;
               glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();
                 glBegin(GL_LINES);
                 glVertex2f(x1, Y1);
                 glVertex2f(x2, y2);
                 glEnd();
               break;






    }

}
ball_type move_ball (ball_type ball)
{
  ball_type new_ball;

  new_ball = ball;
  switch (ball.position.direction)
  {
    case NORTH:
      new_ball.position.y--;
    break;
    case NORTHEAST:
      new_ball.position.x++;
      new_ball.position.y--;
    break;
    case EAST:
      new_ball.position.x++;
    break;
    case SOUTHEAST:
      new_ball.position.x++;
      new_ball.position.y++;
    break;
    case SOUTH:
      new_ball.position.y++;
    break;
    case SOUTHWEST:
      new_ball.position.x--;
      new_ball.position.y++;
    break;
    case WEST:
      new_ball.position.x--;
    break;
    case NORTHWEST:
      new_ball.position.x--;
      new_ball.position.y--;
    break;
    default:
    break;
  }
  return new_ball;
}




void draw_ball (ball_type ball)
{


    glPointSize(5.0f);
   glColor3f(0.0f, 1.0f, 0.0f);
   int k;
   int m;
   int n;
   int o;
   int p;
   int q;
   int r;
   int s;
   int t;
   int u;
   int v;
   int w;
   int x;
   int y;
   int z;
   int aa;
   int bb;
   int cc;
   int dd;
   int ee;
   int ff;
   int gg;
   int hh;
   int ii;
   int jj;
   int kk;
   int ll;
   int mm;
   int nn;

int oo;
int pp;
int qq;
int rr;

   glColor3f(0.329, 0.329, 0.329);
   glBegin(GL_POINTS);
   for(k=10.0; k<1100; k=k+50)
   {

   glVertex2f(0.0f, k);

  }
   glEnd();

   glBegin(GL_POINTS);
   for(m=10.0; m<1100; m=m+50)
   {

   glVertex2f(50.0f, m);

  }
   glEnd();

   glBegin(GL_POINTS);
   for(n=10.0; n<1100; n=n+50)
   {

   glVertex2f(100.0f, n);

  }
   glEnd();

   glBegin(GL_POINTS);
   for(o=10.0; o<1100; o=o+50)
   {

   glVertex2f(150.0f, o);

  }
   glEnd();

   glBegin(GL_POINTS);
   for(p=10.0; p<1100; p=p+50)
   {

   glVertex2f(200.0f, p);

  }
   glEnd();

   glBegin(GL_POINTS);
   for(q=10.0; q<1100; q=q+50)
   {

   glVertex2f(250.0f, q);

  }
   glEnd();

   glBegin(GL_POINTS);
   for(r=10.0; r<1100; r=r+50)
   {

   glVertex2f(300.0f, r);

  }
   glEnd();

   glBegin(GL_POINTS);
   for(s=10.0; s<1100; s=s+50)
   {

   glVertex2f(350.0f, s);

  }
   glEnd();
   glBegin(GL_POINTS);
   for(t=10.0; t<1100; t=t+50)
   {

   glVertex2f(400.0f, t);

  }
   glEnd();
   glBegin(GL_POINTS);
   for(u=10.0; u<1100; u=u+50)
   {

   glVertex2f(450.0f, u);

  }
   glEnd();
     glBegin(GL_POINTS);
   for(v=10.0; v<1100; v=v+50)
   {

   glVertex2f(450.0f, v);

  }
   glEnd();
     glBegin(GL_POINTS);
   for(w=10.0; w<1100; w=w+50)
   {

   glVertex2f(450.0f, w);

  }

   glEnd();

    glBegin(GL_POINTS);
   for(x=10.0; x<1100; x=x+50)
   {

   glVertex2f(500.0f, x);

  }

   glEnd();
    glBegin(GL_POINTS);
   for(y=10.0; y<1100; y=y+50)
   {

   glVertex2f(500.0f, y);

  }

   glEnd();

    glBegin(GL_POINTS);
   for(z=10.0; z<1100; z=z+50)
   {

   glVertex2f(550.0f, z);

  }
  glEnd();

   glBegin(GL_POINTS);
   for(aa=10.0; aa<1100; aa=aa+50)
   {

   glVertex2f(600.0f, aa);

  }

   glEnd();

    glBegin(GL_POINTS);
   for(bb=10.0; bb<1100; bb=bb+50)
   {

   glVertex2f(650.0f, bb);

  }
  glEnd();

  glBegin(GL_POINTS);
   for(cc=10.0; cc<1100; cc=cc+50)
   {

   glVertex2f(650.0f, cc);

  }
  glEnd();
  glBegin(GL_POINTS);
   for(dd=10.0; dd<1100; dd=dd+50)
   {

   glVertex2f(700.0f, dd);

  }
  glEnd();

   glBegin(GL_POINTS);
   for(ee=10.0; ee<1100; ee=ee+50)
   {

   glVertex2f(750.0f, ee);

  }
  glEnd();
   glBegin(GL_POINTS);
   for(ff=10.0; ff<1100; ff=ff+50)
   {

   glVertex2f(800.0f, ff);

  }
  glEnd();
   glBegin(GL_POINTS);
   for(gg=10.0; gg<1100; gg=gg+50)
   {

   glVertex2f(850.0f, gg);

  }
  glEnd();

   glBegin(GL_POINTS);
   for(hh=10.0; hh<1100; hh=hh+50)
   {

   glVertex2f(900.0f, hh);

  }
  glEnd();

  glBegin(GL_POINTS);
   for(ii=10.0; ii<1100; ii=ii+50)
   {

   glVertex2f(950.0f, ii);

  }
  glEnd();
  glBegin(GL_POINTS);
  for(jj=10.0; jj<1100; jj=jj+50)
   {

   glVertex2f(1000.0f, jj);

  }
  glEnd();

  glBegin(GL_POINTS);
  for(kk=10.0; kk<1100; kk=kk+50)
   {

   glVertex2f(1050.0f, kk);

  }
  glEnd();
  glBegin(GL_POINTS);
  for(ll=10.0; ll<1100; ll=ll+50)
   {

   glVertex2f(1100.0f, ll);

  }
  glEnd();
  glBegin(GL_POINTS);
  for(mm=10.0; mm<1100; mm=mm+50)
   {

   glVertex2f(1150.0f, mm);

  }
  glEnd();

  glBegin(GL_POINTS);
  for(nn=10.0; nn<1100; nn=nn+50)
   {

   glVertex2f(1200.0f, nn);

  }
  glEnd();
  glBegin(GL_POINTS);
  for(oo=10.0; oo<1100; oo=oo+50)
   {

   glVertex2f(1250.0f, oo);

  }
  glEnd();
  glBegin(GL_POINTS);
  for(pp=10.0; pp<1100; pp=pp+50)
   {

   glVertex2f(1300.0f, pp);

  }
  glEnd();
  glPointSize(10.0);
  glColor3f(0.0, 0.0, 1.0);

  float theta, circle_iterations = 24.0;

  glColor3ub (ball.color.r, ball.color.g, ball.color.b);
  glPolygonMode (GL_FRONT, GL_FILL);


  glBegin (GL_POLYGON);
  glVertex3f (ball.position.x + ball.radius, ball.position.y, 0.0f);
  for (theta = 0; theta < 2* M_PI; theta += M_PI /circle_iterations)  //2*M_PI
  {
    glVertex3f (ball.position.x+cos(theta) * ball.radius, ball.position.y+sin(theta)*ball.radius, 0.0f);
  }           //ball.position.x + cos(theta) * ball.radius-30,  ball.position.y + sin(theta) * ball.radius, 0.0f
  glEnd();
}





void display (void)
{
// **********
// * Ball 1 *
// **********
 /* glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();//load identity matrix

    glTranslatef(0.0f,0.0f,-4.0f);//move forward 4 units
    glColor3f(0.0f, 0.0f, 1.0f);
*/




  if (ball_hit_wall(ball1))
  {
    ball1.position.direction = select_ball_direction (ball1);
  }
  ball1 = move_ball (ball1);
// **********
// * Ball 2 *
// **********

  if (ball_hit_wall(ball2))
  {
    ball2.position.direction = select_ball_direction (ball2);
  }
  ball2 = move_ball (ball2);
// **********
// * Ball 3 *
// **********
  if (ball_hit_wall(ball3))
  {
    ball3.position.direction = select_ball_direction (ball3);
  }
  ball3 = move_ball (ball3);
// **********
// * Ball 4 *
// **********
  if (ball_hit_wall(ball4))
  {
    ball4.position.direction = select_ball_direction (ball4);
  }
  ball4 = move_ball (ball4);
// **********
// * Ball 5 *
// **********
  if (ball_hit_wall(ball5))
  {
    ball5.position.direction = select_ball_direction (ball5);
  }
  ball5 = move_ball (ball5);
// **********
// * Ball 6 *
// **********
  if (ball_hit_wall(ball6))
  {
    ball6.position.direction = select_ball_direction (ball6);
  }
  ball6 = move_ball (ball6);
// **********
// * Ball 7 *
// **********
  if (ball_hit_wall(ball7))
  {
    ball7.position.direction = select_ball_direction (ball7);
  }
  ball7 = move_ball (ball7);
// **********
// * Ball 8 *
// **********
  if (ball_hit_wall(ball8))
  {
    ball8.position.direction = select_ball_direction (ball8);
  }
  ball8 = move_ball (ball8);



/*
int i;
int j;
int k;
int m;

   double data [50][50]={};
   double sx, sy;
   glColor3f(1, 0, 0);
   glPointSize(10);
   glBegin(GL_POINTS);
   for(i=0; i<N_X; i++)
    for(j=0; j<N_Y; j++)
   {
       sx=MIN_X+(i*(MAX_X-MIN_X)/N_X);
       sy=MIN_Y+(j*(MAX_Y-MIN_Y)/N_Y);
       data[i][j]=myFunction(sx,sy);
       glVertex2d(sx,sy);
   }
     glEnd();

     for(k=0; k<N_X; k++)
     {
         for(m=0; m<N_Y; m++)
         {
             int c;
             c=cell(data[k][m], data[k+1][m], data[k+1][m+1], data[k][m+1]);

             drawLine(c, k, m, data[k][m], data[k+1][m],data[k+1][m+1],data[k][m+1]);
         }
     }




*/




//
// clear the screen to black
  glColor3ub (0, 0, 0);
  glPolygonMode (GL_FRONT, GL_FILL);
  glRecti (0, 0, X_RESOLUTION, Y_RESOLUTION);
//
//
  draw_ball (ball1);
  draw_ball (ball2);
  draw_ball (ball3);
  draw_ball (ball4);
  draw_ball (ball5);
  draw_ball (ball6);
  draw_ball (ball7);
  draw_ball (ball8);

  int u;
  int v;
   int w;
  int x;
  int y;
   int z;
  int aaa;
  int bbb;
  int ccc;
  int ddd;
  int eee;
  int fff;
  int ggg;
  int hhh;

  float iii;
  float jjj;
  float kkk;
  float lll;
  float mmm;
  for(u=0; u<3050; u=u+50)
  {
      //cell(ball1, u, 10.0, u, 60.0, u+50.0, 10.0, u+50.0, 60.0);
          cell( u, 60, u+50, 60, u+50, 10, u, 10);

  }

  for(v=0; v<3050; v=v+50)
  {
      cell( v, 110, v+50, 110, v+50, 60, v, 60);

  }

  for(w=0; w<3050; w=w+50)
  {
       cell(w, 160, w+50, 160, w+50, 110, w, 110);

  }

  for(x=0; x<850; x=x+50)
  {
      cell(x, 210, x+50, 210, x+50, 160, x, 160);

  }

  for(y=0; y<3050; y=y+50)
  {
      cell(y, 260, y+50, 260, y+50, 210, y, 210);


  }

  for(z=0; z<3050; z=z+50)
  {
      cell(z, 310, z+50, 310, z+50, 260, z, 260);

  }

  for(aaa=0; aaa<3050; aaa=aaa+50)
  {
      cell( aaa, 360, aaa+50, 360, aaa+50, 310, aaa, 310);

  }

  for(bbb=0; bbb<3050; bbb=bbb+50)
  {
      cell(bbb, 410, bbb+50, 410, bbb+50, 360, bbb, 360);

  }
  for(ccc=0; ccc<3050; ccc=ccc+50)
  {
      cell( ccc, 460, ccc+50, 460, ccc+50, 410, ccc, 410);

  }

  for(ddd=0.0; ddd<3050.0; ddd=ddd+50.0)
  {
      cell(ddd, 510.0, ddd+50.0, 510.0, ddd+50.0, 460.0, ddd, 460.0);

  }
  for(eee=0.0; eee<3050.0; eee=eee+50.0)
  {
      cell(eee, 560.0, eee+50.0, 560.0, eee+50.0, 510.0, eee, 510.0);

  }
  for(fff=0.0;fff<3050.0; fff=fff+50.0)
  {
      cell( fff, 610.0, fff+50.0, 610.0, fff+50.0, 560.0, fff, 560.0);

  }
  for(ggg=0.0; ggg<3050.0; ggg=ggg+50.0)
  {
      cell(ggg, 660.0, ggg+50.0, 660.0, ggg+50.0, 610.0, ggg, 610.0);

  }
  for(hhh=0.0; hhh<3050.0; hhh=hhh+50.0)
  {
      cell( hhh, 710.0, hhh+50.0, 710.0, hhh+50.0, 660.0, hhh, 660.0);

  }
   for(iii=0.0; iii<3050.0; iii=iii+50.0)
  {
      cell(iii, 760.0, iii+50.0, 760.0, iii+50.0, 710.0, iii, 710.0);

  }
   for(jjj=0.0; jjj<3050.0; jjj=jjj+50.0)
  {
      cell(jjj, 810.0, jjj+50.0, 810.0, jjj+50.0, 760.0, jjj, 760.0);

  }
   for(kkk=0.0; kkk<3050.0; kkk=kkk+50.0)
  {
          cell(kkk, 860.0, kkk+50.0, 860.0, kkk+50.0, 810.0, kkk, 810.0);

  }
   for(lll=0.0; lll<3050.0; lll=lll+50.0)
  {
      cell(lll, 910.0, lll+50.0, 910.0, lll+50.0, 860.0, lll, 860.0);

  }
   for(mmm=0.0; mmm<3050.0; mmm=mmm+50.0)
  {
      cell(mmm, 960.0, mmm+50.0, 960.0, mmm+50.0, 910.0, mmm, 910.0);

  }






 //cell(ball1, 150.0, 110.0, 150.0, 160.0, 200.0, 110.0, 200.0, 160.0);
 // cell(ball1, 250.0, 160.0, 250.0, 210.0, 300.0, 160.0, 200.0, 210.0);
  glutSwapBuffers();
  glutPostRedisplay();
}
//glVertex3f(0, 0)     glVertex3f(1280, 0)  glVertex3f(1280, 1000)      glVertex3f(0,1000)




void reshape (int w, int h)
{
  glViewport (0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (h == 0)
  {
    glOrtho (0.0, X_RESOLUTION, 1, 0, -1.0, 1.0);
  }
  else
  {
    glOrtho (0.0, X_RESOLUTION, Y_RESOLUTION, 0, -1.0, 1.0);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}





void keyboard (unsigned char key, int x, int y)
{
  switch (key)
  {
    case 27:
      exit (0);
    break;
    default:
    break;
  }
}






int main (int argc, char *argv[])
{
// **************************
// * ball 1 characteristics *
// **************************
  ball1.position.x = X_RESOLUTION / 2;
  ball1.position.y = Y_RESOLUTION / 2,
  ball1.position.z = 0;
  ball1.position.direction = EAST;
  ball1.radius = 220;
  ball1.color.r = 0;
  ball1.color.g = 0;
  ball1.color.b = 0;
// **************************
// * ball 2 characteristics *
// **************************
  ball2.position.x = X_RESOLUTION / 2;
  ball2.position.y = Y_RESOLUTION / 2;
  ball2.position.z = 0;
  ball2.position.direction =EAST;
  ball2.radius = 220;
  ball2.color.r = 0;
  ball2.color.g = 0;
  ball2.color.b = 0;
// **************************
// * ball 3 characteristics *
// **************************
  ball3.position.x = X_RESOLUTION / 2;
  ball3.position.y = Y_RESOLUTION / 2;
  ball3.position.z = 0;
  ball3.position.direction = SOUTH;
  ball3.radius = 220;
  ball3.color.r = 0;
  ball3.color.g = 0;
  ball3.color.b = 0;
// **************************
// * ball 4 characteristics *
// **************************
  ball4.position.x = X_RESOLUTION / 2;
  ball4.position.y = Y_RESOLUTION / 2;
  ball4.position.z = 0;
  ball4.position.direction = WEST;
  ball4.radius = 120;
  ball4.color.r = 0;
  ball4.color.g = 0;
  ball4.color.b = 0;
// **************************
// * ball 5 characteristics *
// **************************
  ball5.position.x = X_RESOLUTION / 2;
  ball5.position.y = Y_RESOLUTION / 2;
  ball5.position.z = 0;
  ball5.position.direction = NORTH;
  ball5.radius = 120;
  ball5.color.r = 0;
  ball5.color.g = 0;
  ball5.color.b = 0;
// **************************
// * ball 6 characteristics *
// **************************
  ball6.position.x = X_RESOLUTION / 2;
  ball6.position.y = Y_RESOLUTION / 2;
  ball6.position.z = 0;
  ball6.position.direction = NORTHWEST;
  ball6.radius = 120;
  ball6.color.r = 0;
  ball6.color.g = 0;
  ball6.color.b = 0;
// **************************
// * ball 7 characteristics *
// **************************
  ball7.position.x = X_RESOLUTION / 2;
  ball7.position.y = Y_RESOLUTION / 2;
  ball7.position.z = 0;
  ball7.position.direction = SOUTHEAST;
  ball7.radius = 120;
  ball7.color.r = 0;
  ball7.color.g = 0;
  ball7.color.b = 0;
// **************************
// * ball 8 characteristics *
// **************************
  ball8.position.x = X_RESOLUTION / 2;
  ball8.position.y = Y_RESOLUTION / 2;
  ball8.position.z = 0;
  ball8.position.direction = SOUTHEAST;

  ball8.radius = 120;
  ball8.color.r = 0;
  ball8.color.g = 0;
  ball8.color.b = 0;
//
// seed the random number generator
  srand (time(0));
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize (X_RESOLUTION, Y_RESOLUTION);
  glutCreateWindow ("Marching Squares");

  glutDisplayFunc (display);
  glutReshapeFunc (reshape);
  glutKeyboardFunc (keyboard);
  glutMainLoop();
}


