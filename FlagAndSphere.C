
//C program to simulate a sphere colliding with a flag.  The program can detect when the sphere collides with the flag.


#include <GL/gl.h>




#include <GL/glut.h>
#include <math.h>
#include <stdio.h>






#define BALL_POSITION_X 5
#define BALL_POSITION_Y -2
#define BALL_POSITION_Z 0.0f
#define BALL_RADIUS 0.75
#define TRUE 1
#define FALSE 0


#define TIME_DELTA 0.003/* The speed of time. 0.003 */




// *************************************************************************************
// * GLOBAL variables. Not ideal but necessary to get around limitatins of GLUT API... *
// *************************************************************************************
float xsphere=0.2;     //0.2
float ysphere=0.0;      //0.0
float windForce_x=1;   //1 2 1
float windForce_y=2;
float windForce_z=1;
int pause = TRUE;
float seconds=1.000;
static float time=0.000;
float particleAcceleration[60];
int particle;
float restDistance;
float currentDistance;
float firstParticleVelocity_x=0.0;
float firstParticleVelocity_y=0.0;
float firstParticleVelocity_z=0.0;
float firstParticlePosition=3.0f;
float firstParticleAcceleration_x=0.0;
float firstParticleAcceleration_y=0.0;
float firstParticleAcceleration_z=0.0;

float particle5Velocity_x=0.0;
float particle5Velocity_y=0.0;
float particle5Velocity_z=0.0;


float particle6Velocity_x=0.0;
float particle6Velocity_y=0.0;
float particle6Velocity_z=0.0;


float particle7Velocity_x=0.0;
float particle7Velocity_y=0.0;
float particle7Velocity_z=0.0;


float particle8Velocity_x=0.0;
float particle8Velocity_y=0.0;
float particle8Velocity_z=0.0;


float particle9Velocity_x=0.0;
float particle9Velocity_y=0.0;
float particle9Velocity_z=0.0;


float particle17Velocity_x=0.0;
float particle17Velocity_y=0.0;
float particle17Velocity_z=0.0;

float particle18Velocity_x=0.0;
float particle18Velocity_y=0.0;
float particle18Velocity_z=0.0;



float particle19Velocity_x=0.0;
float particle19Velocity_y=0.0;
float particle19Velocity_z=0.0;


float particle20Velocity_x=0.0;
float particle20Velocity_y=0.0;
float particle20Velocity_z=0.0;

float particle21Velocity_x=0.0;
float particle21Velocity_y=0.0;
float particle21Velocity_z=0.0;


float particle22Velocity_x=0.0;
float particle22Velocity_y=0.0;
float particle22Velocity_z=0.0;

float particle23Velocity_x=0.0;
float particle23Velocity_y=0.0;
float particle23Velocity_z=0.0;

float particle24Velocity_x=0.0;
float particle24Velocity_y=0.0;
float particle24Velocity_z=0.0;

float particle25Velocity_x=0.0;
float particle25Velocity_y=0.0;
float particle25Velocity_z=0.0;

float particle26Velocity_x=0.0;
float particle26Velocity_y=0.0;
float particle26Velocity_z=0.0;


float particle27Velocity_x=0.0;
float particle27Velocity_y=0.0;
float particle27Velocity_z=0.0;

float particle13Velocity_x=0.0;
float particle13Velocity_y=0.0;
float particle13Velocity_z=0.0;

float particle14Velocity_x=0.0;
float particle14Velocity_y=0.0;
float particle14Velocity_z=0.0;


float particle15Velocity_x=0.0;
float particle15Velocity_y=0.0;
float particle15Velocity_z=0.0;



float particle16Velocity_x=0.0;
float particle16Velocity_y=0.0;
float particle16Velocity_z=0.0;




float particle29Velocity_x=0.0;
float particle29Velocity_y=0.0;
float particle29Velocity_z=0.0;



float particle41Velocity_x=0.0;
float particle41Velocity_y=0.0;
float particle41Velocity_z=0.0;



float particle42Velocity_x=0.0;
float particle42Velocity_y=0.0;
float particle42Velocity_z=0.0;


float particle28Velocity_x=0.0;
float particle28Velocity_y=0.0;
float particle28Velocity_z=0.0;


float front=1.0;
float spherex=0.5;
float spherey=0.0;
float secondParticlePosition=2.0f;

float secondParticleVelocity=0.0;
float secondParticleAcceleration=0.0;
float particle32DistanceSphere;
float thirdParticlePosition;
float fourthParticlePosition;
float fifthParticlePosition;
float temp32x;
float temp32y;
float temp32z;
int currentIterations=0;
int numberIterations=187;
float DAMPING=2.0f;

float aan=3.0f;
float bbn=3.0f;
float ccn=3.0f;
float ddn=3.0f;
float een=3.0f;
float ffn=3.0f;
float ggn=3.0f;
float hhn=3.0f;
float iin=3.0f;
float jjn=3.0f;
float kkn=3.0f;
float lln=3.0f;
float mmn=3.0f;



int end=0;



float Nnn=2.0f;
float oon=2.0f;
float ppn=2.0f;
float qqn=2.0f;
float rrn=2.0f;
float ssn=2.0f;
float ttn=2.0f;

float uun=2.0f;
float vvn=2.0f;
float wwn=2.0f;
float xxn=2.0f;
float yyn=2.0f;
float zzn=2.0f;



float nnnn=1.0f;
float ooon=1.0f;
float pppn=1.0f;
float qqqn=1.0f;
float rrrn=1.0f;
float sssn=1.0f;
float tttn=1.0f;
float uuun=1.0f;
float vvvn=1.0f;
float wwwn=1.0f;
float xxxn=1.0f;
float yyyn=1.0f;
float zzzn=1.0f;




float nnnnn=0.0f;
float oooon=0.0f;
float ppppn=0.0f;
float qqqqn=0.0f;
float rrrrn=0.0f;
float ssssn=0.0f;
float ttttn=0.0f;
float uuuun=0.0f;
float vvvvn=0.0f;
float wwwwn=0.0f;
float xxxxn=0.0f;
float yyyyn=0.0f;
float zzzzn=0.0f;





float nnnnnn=-1.0f;
float ooooon=-1.0f;
float pppppn=-1.0f;
float qqqqqn=-1.0f;
float rrrrrn=-1.0f;
float sssssn=-1.0f;
float tttttn=-1.0f;
float uuuuun=-1.0f;
float vvvvvn=-1.0f;
float wwwwwn=-1.0f;
float xxxxxn=-1.0f;
float yyyyyn=-1.0f;
float zzzzzn=-1.0f;










float za;
float mmm=0.7;
float nnn=1.7;
float ooo=1.25;
float ppp=2.15;
float qqq=2.25;
float rrr=3.15;
float sss=2.7;
float ttt=3.25;
float uuu=4.15;
float vvv=3.7;
float www=4.25;
float xxx=5.15;
float yyy=4.7;
float zzz=-5.77;
float aaaa=-4.77;
float bbbb=-3.77;
float dddd=-2.77;
float eeee=-1.77;
float ffff=-0.77;
float gggg=0.23;
float hhhh=1.23;
float iiii=2.23;
float jjjj=3.23;
float kkkk=4.23;
float llll=5.23;



float aa=-5.75;
float bb=-4.85;
float cc=-5.3;
float dd=-4.75;
float ee=-3.85;
float ff=-4.3;
float gg=-3.75;
float hh=-2.85;
float ii=-3.3;
float jj=-2.75;
float kk=-1.85;
float ll=-2.3;
float mm=-1.75;
float nn=-0.85;
float oo=-1.3;
float pp=-0.75;
float tt=0.15;
float uu=1.15;

float rr=-0.3;
float ss=0.25;
float qq=0.25;

float ef=-7.0f;
float cd=-6.5f;
float ab=-6.0f;

float a=-5.8f;
float b=-4.8;
float c=-3.8;
float d=-2.8;
float e=-1.8;
float f=-0.8f;
float g= 0.2f;
float h=1.2;
float i=2.2;
float j=3.2;
float k=4.2;

float l=5.2;
float m=6.2;
float n=1.0f;
float o=1.5f;
float p=2.0f;
float q=2.5f;
float r=3.0f;
float s=3.5f;
float t=4.0f;

float u=3.0f;
float v=3.0f;
float w=3.0f;
float x=3.0f;
float y=3.0f;
float A=3.0f;
float B=3.0f;

float D=3.0f;
float E=3.0f;
float F=3.0f;
float G=3.0f;
float H=3.0f;
float I=3.0f;

float mass=10.0f;
float gravity=-0.0000001f;
float gravityForce;
float distance;
float l0ijkl=1;
float lijkl;
float uFluid=3.0f;
float unitNormal=1.0f;

float value=-5.8f;
float z;
float zPoint=0.0f;

float K=15.0f;  //Hooke's Law constant
float C=3.0f;

float spring1[6]={-3.8, 3.0, 0.0, -2.8, 3.0, 0.0};
float spring2[6]={-2.8, 3.0, 0.0, -1.8, 3.0, 0.0};
float spring3[6]={-1.8, 3.0, 0.0, -0.8, 3.0, 0.0};
float spring4[6]={-0.8, 3.0, 0.0,  0.2, 3.0, 0.0};
float spring5[6]={0.2, 3.0, 0.0, 1.2, 3.0, 0.0};
float spring6[6]={1.2, 3.0, 0.0, 2.2, 3.0, 0.0};
float spring7[6]={2.2, 3.0, 0.0, 3.2, 3.0, 0.0};


float spring8[6]={-5.8, 2.0, 0.0, -4.8, 2.0, 0.0};
float spring9[6]={-4.8, 2.0, 0.0, -3.8, 2.0, 0.0};
float spring10[6]={-3.8, 2.0, 0.0, -2.8, 2.0, 0.0};
float spring11[6]={-2.8, 2.0, 0.0, -1.8, 2.0, 0.0};
float spring12[6]={-1.8, 2.0, 0.0, -0.8, 2.0, 0.0};




float spring13[6]={-0.8, 2.0, 0.0, 0.2, 2.0, 0.0};
float spring14[6]={0.2, 2.0, 0.0, 1.2, 2.0, 0.0};
float spring15[6]={1.2, 2.0, 0.0, 2.2, 2.0, 0.0};
float spring16[6]={2.2, 2.0, 0.0, 3.2, 2.0, 0.0};
float spring17[6]={3.2, 2.0, 0.0, 4.2, 2.0, 0.0};
float spring18[6]={4.2, 2.0, 0.0, 5.2, 2.0, 0.0};



float spring19[6]={-5.8, 1.0, 0.0, -4.8, 1.0, 0.0};
float spring20[6]={-4.8, 1.0, 0.0, -3.8, 1.0, 0.0};
float spring21[6]={-3.8, 1.0, 0.0, -2.8, 1.0, 0.0};
float spring22[6]={-2.8, 1.0, 0.0, -1.8, 1.0, 0.0};
float spring23[6]={-1.8, 1.0, 0.0 -0.8, 1.0, 0.0};
float spring24[6]={-0.8, 1.0, 0.0, 0.2, 1.0, 0.0};
float spring25[6]={0.2, 1.0, 0.0, 1.2, 1.0, 0.0};
float spring26[6]={1.2, 1.0, 0.0, 2.2, 1.0, 0.0};
float spring27[6]={2.2, 1.0, 0.0, 3.2, 1.0, 0.0};
float spring28[6]={3.2, 1.0, 0.0, 4.2, 1.0, 0.0};
float spring29[6]={4.2, 1.0, 0.0, 5.2, 1.0, 0.0};





float spring30[6]={-5.8, 0.0, 0.0 -4.8, 0.0, 0.0};
float spring31[6]={-4.8, 0.0, 0.0, -3.8, 0.0, 0.0};
float spring32[6]={-3.8, 0.0, 0.0, -2.8, 0.0, 0.0};
float spring33[6]={-2.8, 0.0, 0.0, -1.8, 0.0, 0.0};
float spring34[6]={-1.8, 0.0, 0.0, -0.8, 0.0, 0.0};
float spring35[6]={-0.8, 0.0, 0.0, 0.2, 0.0, 0.0};
float spring36[6]={0.2, 0.0, 0.0, 1.2, 0.0, 0.0};
float spring37[6]={1.2, 0.0, 0.0, 2.2, 0.0, 0.0};
float spring38[6]={2.2, 0.0, 0.0, 3.2, 0.0, 0.0};
float spring39[6]={3.2, 0.0, 0.0, 4.2, 0.0, 0.0};
float spring40[6]={4.2, 0.0, 0.0, 5.2, 0.0, 0.0};



float spring41[6]={-5.8, -1.0, 0.0, -4.8, -1.0, 0.0};
float spring42[6]={-4.8, -1.0, 0.0, -3.8, -1.0, 0.0};
float spring43[6]={-3.8, -1.0, 0.0, -2.8, -1.0, 0.0};
float spring44[6]={-2.8, -1.0, 0.0, -1.8, -1.0, 0.0};
float spring45[6]={-1.8, -1.0, 0.0, -0.8, -1.0, 0.0};
float spring46[6]={-0.8, -1.0, 0.0,  0.2, -1.0, 0.0};
float spring47[6]={0.2, -1.0, 0.0, 1.2, -1.0, 0.0};
float spring48[6]={1.2, -1.0, 0.0, 2.2, -1.0, 0.0};
float spring49[6]={2.2, -1.0, 0.0, 3.2, -1.0, 0.0};
float spring50[6]={3.2, -1.0, 0.0, 4.2, -1.0, 0.0};
float spring51[6]={4.2, -1.0, 0.0, 5.2, -1.0, 0.0};


//Horizontal Springs Over









float spring52[6]={-5.8, 3.0, 0.0 -4.8, 2.0, 0.0};
float spring53[6]={-4.8, 3.0, 0.0, -3.8, 2.0, 0.0};
float spring54[6]={-3.8, 3.0, 0.0, -3.8, 2.0, 0.0};
float spring55[6]={-2.8, 3.0, 0.0, -2.8, 2.0, 0.0};
float spring56[6]={-1.8, 3.0, 0.0, -1.8, 2.0, 0.0};
float spring57[6]={-0.8, 3.0, 0.0, -0.8, 2.0, 0.0};
float spring58[6]={0.2,  3.0, 0.0,  0.2,  2.0, 0.0};
float spring59[6]={1.2, 3.0, 0.0, 1.2, 2.0, 0.0};
float spring60[6]={2.2, 3.0, 0.0, 2.2, 2.0, 0.0};
float spring61[6]={3.2, 3.0, 0.0, 3.2, 2.0, 0.0};
float spring62[6]={4.2, 3.0, 0.0, 4.2, 2.0, 0.0};
float spring63[6]={5.2, 3.0, 0.0, 5.2, 2.0, 0.0};




float spring64[6]={-5.8, 2.0, 0.0, -5.8, 1.0, 0.0};
float spring65[6]={-4.8, 2.0, 0.0, -4.8, 1.0, 0.0};
float spring66[6]={-3.8, 2.0, 0.0, -3.8, 1.0, 0.0};
float spring67[6]={-2.8, 2.0, 0.0, -2.8, 1.0, 0.0};
float spring68[6]={-1.8, 2.0, 0.0, -1.8, 1.0, 0.0};
float spring69[6]={-0.8, 2.0, 0.0, -0.8, 1.0, 0.0};
float spring70[6]={0.2,  2.0, 0.0,  0.2, 1.0, 0.0};
float spring71[6]={1.2,  2.0, 0.0,  1.2, 1.0, 0.0};
float spring72[6]={2.2,  2.0, 0.0,  2.2, 1.0, 0.0};
float spring73[6]={3.2,  2.0, 0.0, 3.2, 1.0, 0.0};
float spring74[6]={4.2,  2.0, 0.0, 4.2, 1.0, 0.0};
float spring75[6]={5.2,  2.0, 0.0, 5.2, 1.0, 0.0};







float spring76[6]={-5.8, 1.0, 0.0, -5.8, 0.0, 0.0};
float spring77[6]={-4.8, 1.0, 0.0, -4.8, 0.0, 0.0};
float spring78[6]={-3.8, 1.0, 0.0, -3.8, 0.0, 0.0};
float spring79[6]={-2.8, 1.0, 0.0, -2.8, 0.0, 0.0};
float spring80[6]={-1.8, 1.0, 0.0, -1.8, 0.0, 0.0};
float spring81[6]={-0.8, 1.0, 0.0, -0.8, 0.0, 0.0};
float spring82[6]={0.2,  1.0, 0.0,  0.2, 0.0, 0.0};
float spring83[6]={1.2,  1.0, 0.0, 1.2, 0.0, 0.0};
float spring84[6]={2.2,  1.0, 0.0, 2.2, 0.0, 0.0};
float spring85[6]={3.2,  1.0, 0.0, 3.2, 0.0, 0.0};
float spring86[6]={4.2,  1.0, 0.0, 4.2, 0.0, 0.0};
float spring87[6]={5.2,  1.0, 0.0, 5.2, 0.0, 0.0};



float spring88[6]={-5.8, 0.0, 0.0,  -5.8, -1.0, 0.0};
float spring89[6]={-4.8, 0.0, 0.0, -4.8, -1.0, 0.0};
float spring90[6]={-3.8, 0.0, 0.0, -3.8, -1.0, 0.0};
float spring91[6]={-2.8, 0.0, 0.0, -2.8, -1.0, 0.0};
float spring92[6]={-1.8, 0.0, 0.0,  -1.8, -1.0, 0.0};
float spring93[6]={-0.8, 0.0, 0.0,  -0.8, -1.0, 0.0};
float spring94[6]={0.2,  0.0, 0.0,  0.2, -1.0, 0.0};
float spring95[6]={1.2,  0.0, 0.0,  1.2,  -1.0, 0.0};
float spring96[6]={2.2,  0.0, 0.0,  2.2,  -1.0, 0.0};
float spring97[6]={3.2,  0.0, 0.0, 3.2, -1.0, 0.0};
float spring98[6]={4.2,  0.0, 0.0, 4.2, -1.0, 0.0};
float spring99[6]={5.2,  0.0, 0.0, 5.2, -1.0, 0.0};

//Vertical Spring Over


float spring100[6]={-5.8, 3.0, 0.0,  -4.8, 2.0, 0.0};
float spring101[6]={-4.8, 3.0, 0.0, -3.8, 2.0, 0.0};
float spring102[6]={-3.8, 3.0, 0.0, -2.8, 2.0, 0.0};
float spring103[6]={-2.8, 3.0, 0.0, -1.8, 2.0, 0.0};
float spring104[6]={-1.8, 3.0, 0.0, -0.8, 2.0, 0.0};
float spring105[6]={-0.8, 3.0, 0.0,  0.2, 2.0, 0.0};
float spring106[6]={0.2,  3.0, 0.0,  1.2, 2.0, 0.0};
float spring107[6]={1.2,  3.0, 0.0,  2.2, 2.0, 0.0};
float spring108[6]={2.2,  3.0, 0.0,  3.2, 2.0, 0.0};
float spring109[6]={3.2,  3.0, 0.0,  4.2, 2.0, 0.0};
float spring110[6]={4.2,  3.0, 0.0,  5.2, 2.0, 0.0};

float spring111[6]={-5.8, 2.0, 0.0, -4.8, 1.0, 0.0};
float spring112[6]={-4.8, 2.0, 0.0, -3.8, 1.0, 0.0};
float spring113[6]={-3.8, 2.0, 0.0, -2.8, 2.0, 0.0};
float spring114[6]={-2.8, 2.0, 0.0, -1.8, 1.0, 0.0};
float spring115[6]={-1.8, 2.0, 0.0, -0.8, 1.0, 0.0};
float spring116[6]={-0.8, 2.0, 0.0,  0.2, 1.0, 0.0};
float spring117[6]={0.2,  2.0, 0.0,  1.2, 1.0, 0.0};
float spring118[6]={1.2,  2.0, 0.0,  2.2, 1.0, 0.0};
float spring119[6]={2.2,  2.0, 0.0,  3.2, 1.0, 0.0};
float spring120[6]={3.2,  2.0, 0.0,  4.2, 1.0, 0.0};
float spring121[6]={4.2,  2.0, 0.0,  5.2, 1.0, 0.0};




float spring122[6]={-5.8, 1.0, 0.0, -4.8, 0.0, 0.0};
float spring123[6]={-4.8, 1.0, 0.0, -3.8, 0.0, 0.0};
float spring124[6]={-3.8, 1.0, 0.0, -2.8, 0.0, 0.0};
float spring125[6]={-2.8, 1.0, 0.0, -1.8, 0.0, 0.0};
float spring126[6]={-1.8, 1.0, 0.0, -0.8, 0.0, 0.0};
float spring127[6]={-0.8, 1.0, 0.0,  0.2, 0.0, 0.0};
float spring128[6]={0.2,  1.0, 0.0, 1.2, 0.0, 0.0};
float spring129[6]={1.2,  1.0, 0.0, 2.2, 0.0, 0.0};
float spring130[6]={2.2,  1.0, 0.0,  3.2, 0.0, 0.0};
float spring131[6]={3.2,  1.0, 0.0,  4.2, 0.0, 0.0};
float spring132[6]={4.2,  1.0, 0.0,  5.2, 0.0, 0.0};





float spring133[6]={-5.8, 0.0, 0.0, -4.8, -1.0, 0.0};
float spring134[6]={-4.8, 0.0, 0.0, -3.8, -1.0, 0.0};
float spring135[6]={-3.8, 0.0, 0.0, -2.8, -1.0, 0.0};
float spring136[6]={-2.8, 0.0, 0.0, -1.8, -1.0, 0.0};
float spring137[6]={-1.8, 0.0, 0.0, -0.8, -1.0, 0.0};
float spring138[6]={-0.8, 0.0, 0.0,  0.2, -1.0, 0.0};
float spring139[6]={0.2,  0.0, 0.0,  1.2, -1.0, 0.0};
float spring140[6]={1.2,  0.0, 0.0,  2.2, -1.0, 0.0};
float spring141[6]={2.2,  0.0, 0.0,  3.2, -1.0, 0.0};
float spring142[6]={3.2,  0.0, 0.0,  4.2, -1.0, 0.0};
float spring143[6]={4.2,  0.0, 0.0,  5.2, -1.0, 0.0};
//Top left to bottom right diagnol spring over



float spring144[6]={-5.8, 2.0, 0.0, -4.8, 3.0, 0.0};
float spring145[6]={-4.8, 2.0, 0.0, -3.8, 3.0, 0.0};
float spring146[6]={-3.8, 2.0, 0.0, -2.8, 3.0, 0.0};
float spring147[6]={-2.8, 2.0, 0.0, -1.8, 3.0, 0.0};
float spring148[6]={-1.8, 2.0, 0.0, -0.8, 3.0, 0.0};
float spring149[6]={-0.8, 2.0, 0.0,  0.2, 3.0, 0.0};
float spring150[6]={ 0.2, 2.0, 0.0,  1.2, 3.0, 0.0};
float spring151[6]={ 1.2, 2.0, 0.0,  2.2, 3.0, 0.0};
float spring152[6]={ 2.2, 2.0, 0.0,  3.2, 3.0, 0.0};
float spring153[6]={ 3.2, 2.0, 0.0,  4.2, 3.0, 0.0};
float spring154[6]={ 4.2, 2.0, 0.0,  5.2, 3.0, 0.0};




float spring155[6]={-5.8, 1.0, 0.0, -4.8, 2.0, 0.0};
float spring156[6]={-4.8, 1.0, 0.0, -3.8, 2.0, 0.0};
float spring157[6]={-3.8, 1.0, 0.0, -2.8, 2.0, 0.0};
float spring158[6]={-2.8, 1.0, 0.0, -1.8, 2.0, 0.0};
float spring159[6]={-1.8, 1.0, 0.0, -0.8, 2.0, 0.0};
float spring160[6]={-0.8, 1.0, 0.0,  0.2, 2.0, 0.0};
float spring161[6]={ 0.2, 1.0, 0.0,  1.2, 2.0, 0.0};
float spring162[6]={ 1.2, 1.0, 0.0,  2.2, 2.0, 0.0};
float spring163[6]={ 2.2, 1.0, 0.0,  3.2, 2.0, 0.0};
float spring164[6]={ 3.2, 1.0, 0.0,  4.2, 2.0, 0.0};
float spring165[6]={ 4.2, 1.0, 0.0,  5.2, 2.0, 0.0};



float spring166[6]={-5.8, 0.0, 0.0, -4.8, 1.0, 0.0};
float spring167[6]={-4.8, 0.0, 0.0, -3.8, 1.0, 0.0};
float spring168[6]={-3.8, 0.0, 0.0, -2.8, 1.0, 0.0};
float spring169[6]={-2.8, 0.0, 0.0, -1.8, 1.0, 0.0};
float spring170[6]={-1.8, 0.0, 0.0, -0.8, 1.0, 0.0};
float spring171[6]={-0.8, 0.0, 0.0,  0.2, 1.0, 0.0};
float spring172[6]={ 0.2, 0.0, 0.0,  1.2, 1.0, 0.0};
float spring173[6]={ 1.2, 0.0, 0.0,  2.2, 1.0, 0.0};
float spring174[6]={ 2.2, 0.0, 0.0,  3.2, 1.0, 0.0};
float spring175[6]={ 3.2, 0.0, 0.0,  4.2, 1.0, 0.0};
float spring176[6]={ 4.2, 0.0, 0.0,  5.2, 1.0, 0.0};




float spring177[6]={-5.8, -1.0, 0.0, -4.8, 0.0, 0.0};
float spring178[6]={-4.8, -1.0, 0.0 -3.8, 0.0, 0.0};
float spring179[6]={-3.8, -1.0, 0.0, -2.8, 0.0, 0.0};
float spring180[6]={-2.8, -1.0, 0.0, -1.8, 0.0, 0.0};
float spring181[6]={-1.8, -1.0, 0.0, -0.8, 0.0, 0.0};
float spring182[6]={-0.8, -1.0, 0.0,  0.2,  0.0, 0.0};
float spring183[6]={ 0.2, -1.0, 0.0,  1.2, 0.0, 0.0};
float spring184[6]={ 1.2, -1.0, 0.0,  2.2, 0.0, 0.0};
float spring185[6]={ 2.2, -1.0, 0.0, 3.2, 0.0, 0.0};
float spring186[6]={ 3.2, -1.0, 0.0,  4.2, 0.0, 0.0};
float spring187[6]={ 4.2, -1.0, 0.0,  5.2, 0.0, 0.0};



float particle1Acceleration_x=0.0;
float particle1Acceleration_y=0.0;
float particle1Acceleration_z=0.0;

float particle2Acceleration_x=0.0;
float particle2Acceleration_y=0.0;
float particle2Acceleration_z=0.0;


float particle3Acceleration_x=0.0;
float particle3Acceleration_y=0.0;
float particle3Acceleration_z=0.0;


float particle4Acceleration_x=0.0;
float particle4Acceleration_y=0.0;
float particle4Acceleration_z=0.0;

float particle5Acceleration_x=0.0;
float particle5Acceleration_y=0.0;
float particle5Acceleration_z=0.0;


float particle6Acceleration_x=0.0;
float particle6Acceleration_y=0.0;
float particle6Acceleration_z=0.0;

float particle7Acceleration_x=0.0;
float particle7Acceleration_y=0.0;
float particle7Acceleration_z=0.0;


float particle8Acceleration_x=0.0;
float particle8Acceleration_y=0.0;
float particle8Acceleration_z=0.0;

float particle9Acceleration_x=0.0;
float particle9Acceleration_y=0.0;
float particle9Acceleration_z=0.0;

float particle10Acceleration_x=0.0;
float particle10Acceleration_y=0.0;
float particle10Acceleration_z=0.0;


float particle11Acceleration_x=0.0;
float particle11Acceleration_y=0.0;
float particle11Acceleration_z=0.0;

float particle12Acceleration_x=0.0;
float particle12Acceleration_y=0.0;
float particle12Acceleration_z=0.0;

float particle13Acceleration_x=0.0;
float particle13Acceleration_y=0.0;
float particle13Acceleration_z=0.0;

float particle14Acceleration_x=0.0;
float particle14Acceleration_y=0.0;
float particle14Acceleration_z=0.0;

float particle15Acceleration_x=0.0;
float particle15Acceleration_y=0.0;
float particle15Acceleration_z=0.0;

float particle16Acceleration_x=0.0;
float particle16Acceleration_y=0.0;
float particle16Acceleration_z=0.0;

float particle17Acceleration_x=0.0;
float particle17Acceleration_y=0.0;
float particle17Acceleration_z=0.0;

float particle18Acceleration_x=0.0;
float particle18Acceleration_y=0.0;
float particle18Acceleration_z=0.0;

float particle19Acceleration_x=0.0f;
float particle19Acceleration_y=0.0f;
float particle19Acceleration_z=0.0f;


float particle20Acceleration_x=0.0;
float particle20Acceleration_y=0.0;
float particle20Acceleration_z=0.0;

float particle21Acceleration_x=0.0;
float particle21Acceleration_y=0.0;
float particle21Acceleration_z=0.0;

float particle22Acceleration_x=0.0;
float particle22Acceleration_y=0.0;
float particle22Acceleration_z=0.0;

float particle23Acceleration_x=0.0f;
float particle23Acceleration_y=0.0f;
float particle23Acceleration_z=0.0f;

float particle24Acceleration_x=0.0;
float particle24Acceleration_y=0.0;
float particle24Acceleration_z=0.0;

float particle25Acceleration_x=0.0;
float particle25Acceleration_y=0.0;
float particle25Acceleration_z=0.0;

float particle26Acceleration_x=0.0;
float particle26Acceleration_y=0.0;
float particle26Acceleration_z=0.0;

float particle27Acceleration_x=0.0f;
float particle27Acceleration_y=0.0f;
float particle27Acceleration_z=0.0f;

float particle28Acceleration_x=0.0;
float particle28Acceleration_y=0.0;
float particle28Acceleration_z=0.0;

float particle29Acceleration_x=0.0;
float particle29Acceleration_y=0.0;
float particle29Acceleration_z=0.0;

float particle30Acceleration_x=0.0;
float particle30Acceleration_y=0.0;
float particle30Acceleration_z=0.0;

float particle31Acceleration_x=0.0f;
float particle31Acceleration_y=0.0f;
float particle31Acceleration_z=0.0f;


float particle32Acceleration_x=0.0;
float particle32Acceleration_y=0.0;
float particle32Acceleration_z=0.0;

float particle33Acceleration_x=0.0;
float particle33Acceleration_y=0.0;
float particle33Acceleration_z=0.0;

float particle34Acceleration_x=0.0;
float particle34Acceleration_y=0.0;
float particle34Acceleration_z=0.0;

float particle35Acceleration_x=0.0f;
float particle35Acceleration_y=0.0f;
float particle35Acceleration_z=0.0f;


float particle36Acceleration_x=0.0;
float particle36Acceleration_y=0.0;
float particle36Acceleration_z=0.0;

float particle37Acceleration_x=0.0;
float particle37Acceleration_y=0.0;
float particle37Acceleration_z=0.0;

float particle38Acceleration_x=0.0;
float particle38Acceleration_y=0.0;
float particle38Acceleration_z=0.0;

float particle39Acceleration_x=0.0f;
float particle39Acceleration_y=0.0f;
float particle39Acceleration_z=0.0f;

float particle40Acceleration_x=0.0;
float particle40Acceleration_y=0.0;
float particle40Acceleration_z=0.0;

float particle41Acceleration_x=0.0;
float particle41Acceleration_y=0.0;
float particle41Acceleration_z=0.0;

float particle42Acceleration_x=0.0;
float particle42Acceleration_y=0.0;
float particle42Acceleration_z=0.0;

float particle43Acceleration_x=0.0f;
float particle43Acceleration_y=0.0f;
float particle43Acceleration_z=0.0f;



float particle44Acceleration_x=0.0;
float particle44Acceleration_y=0.0;
float particle44Acceleration_z=0.0;

float particle45Acceleration_x=0.0;
float particle45Acceleration_y=0.0;
float particle45Acceleration_z=0.0;

float particle46Acceleration_x=0.0;
float particle46Acceleration_y=0.0;
float particle46Acceleration_z=0.0;

float particle47Acceleration_x=0.0f;
float particle47Acceleration_y=0.0f;
float particle47Acceleration_z=0.0f;





float particle48Acceleration_x=0.0;
float particle48Acceleration_y=0.0;
float particle48Acceleration_z=0.0;

float particle49Acceleration_x=0.0;
float particle49Acceleration_y=0.0;
float particle49Acceleration_z=0.0;

float particle50Acceleration_x=0.0;
float particle50Acceleration_y=0.0;
float particle50Acceleration_z=0.0;

float particle51Acceleration_x=0.0f;
float particle51Acceleration_y=0.0f;
float particle51Acceleration_z=0.0f;

float particle52Acceleration_x=0.0;
float particle52Acceleration_y=0.0;
float particle52Acceleration_z=0.0;

float particle53Acceleration_x=0.0;
float particle53Acceleration_y=0.0;
float particle53Acceleration_z=0.0;

float particle54Acceleration_x=0.0;
float particle54Acceleration_y=0.0;
float particle54Acceleration_z=0.0;

float particle55Acceleration_x=0.0f;
float particle55Acceleration_y=0.0f;
float particle55Acceleration_z=0.0f;



float particle56Acceleration_x=0.0;
float particle56Acceleration_y=0.0;
float particle56Acceleration_z=0.0;

float particle57Acceleration_x=0.0;
float particle57Acceleration_y=0.0;
float particle57Acceleration_z=0.0;

float particle58Acceleration_x=0.0;
float particle58Acceleration_y=0.0;
float particle58Acceleration_z=0.0;

float particle59Acceleration_x=0.0;
float particle59Acceleration_y=0.0;
float particle59Acceleration_z=0.0;

float particle60Acceleration_x=0.0;
float particle60Acceleration_y=0.0;
float particle60Acceleration_z=0.0;


float particle1Position_x=-5.8;
float particle1Position_y=3.0;
float particle1Position_z=0.0;

float particle2Position_x=-4.8;
float particle2Position_y=3.0;
float particle2Position_z=0.0;

float particle3Position_x=-3.8;
float particle3Position_y=3.0;
float particle3Position_z=0.0;

float particle4Position_x=-2.8;
float particle4Position_y=3.0;
float particle4Position_z=0.0;

float particle5Position_x=-1.8;
float particle5Position_y=3.0;
float particle5Position_z=0.0;


float particle6Position_x=-0.8;
float particle6Position_y=3.0;
float particle6Position_z=0.0;

float particle7Position_x=0.2;
float particle7Position_y=3.0;
float particle7Position_z=0.0;

float particle8Position_x=1.2;
float particle8Position_y=3.0;
float particle8Position_z=0.0;

float particle9Position_x=2.2;
float particle9Position_y=3.0;
float particle9Position_z=0.0;

float particle10Position_x=3.2;
float particle10Position_y=3.0;
float particle10Position_z=0.0;

float particle11Position_x=4.2;
float particle11Position_y=3.0;
float particle11Position_z=0.0;

float particle12Position_x=5.2;
float particle12Position_y=3.0;
float particle12Position_z=0.0;


float particle13Position_x=-5.8;
float particle13Position_y=2.0;
float particle13Position_z=0.0;

float particle14Position_x=-4.8;
float particle14Position_y=2.0;
float particle14Position_z=0.0;

float particle15Position_x=-3.8;
float particle15Position_y=2.0;
float particle15Position_z=0.0;

float particle16Position_x=-2.8;
float particle16Position_y=2.0;
float particle16Position_z=0.0;

float particle17Position_x=-1.8;
float particle17Position_y=2.0;
float particle17Position_z=0.0;

float particle18Position_x=-0.8;
float particle18Position_y=2.0;
float particle18Position_z=0.0;

float particle19Position_x=0.2;
float particle19Position_y=2.0;
float particle19Position_z=0.0;


float particle20Position_x=1.2;
float particle20Position_y=2.0;
float particle20Position_z=0.0;

float particle21Position_x=2.2;
float particle21Position_y=2.0;
float particle21Position_z=0.0;


float particle22Position_x=3.2;
float particle22Position_y=2.0;
float particle22Position_z=0.0;


float particle23Position_x=4.2;
float particle23Position_y=2.0;
float particle23Position_z=0.0;

float particle24Position_x=5.2;
float particle24Position_y=2.0;
float particle24Position_z=0.0;



float particle25Position_x=-5.8;
float particle25Position_y=1.0;
float particle25Position_z=0.0;


float particle26Position_x=-4.8;
float particle26Position_y=1.0;
float particle26Position_z=0.0;

float particle27Position_x=-3.8;
float particle27Position_y=1.0;
float particle27Position_z=0.0;




float particle28Position_x=-2.8;
float particle28Position_y=1.0;
float particle28Position_z=0.0;


float particle29Position_x=-1.8;
float particle29Position_y=1.0;
float particle29Position_z=0.0;

float particle30Position_x=-0.8;
float particle30Position_y=1.0;
float particle30Position_z=0.0;



float particle31Position_x=0.2;
float particle31Position_y=1.0;
float particle31Position_z=0.0;


float particle32Position_x=1.2;
float particle32Position_y=1.0;
float particle32Position_z=0.0;

float particle33Position_x=2.2;
float particle33Position_y=1.0;
float particle33Position_z=0.0;





float particle34Position_x=3.2;
float particle34Position_y=1.0;
float particle34Position_z=0.0;

float particle35Position_x=4.2;
float particle35Position_y=1.0;
float particle35Position_z=0.0;

float particle36Position_x=5.2;
float particle36Position_y=1.0;
float particle36Position_z=0.0;

float particle37Position_x=-5.8;
float particle37Position_y=0.0;
float particle37Position_z=0.0;

float particle38Position_x=-4.8;
float particle38Position_y=0.0;
float particle38Position_z=0.0;

float particle39Position_x=-3.8;
float particle39Position_y=0.0;
float particle39Position_z=0.0;

float particle40Position_x=-2.8;
float particle40Position_y=0.0;
float particle40Position_z=0.0;

float particle41Position_x=-1.8;
float particle41Position_y=0.0;
float particle41Position_z=0.0;

float particle42Position_x=-0.8;
float particle42Position_y=0.0;
float particle42Position_z=0.0;

float particle43Position_x=0.2;
float particle43Position_y=0.0;
float particle43Position_z=0.0;

float particle44Position_x=1.2;
float particle44Position_y=0.0;
float particle44Position_z=0.0;

float particle45Position_x=2.2;
float particle45Position_y=0.0;
float particle45Position_z=0.0;

float particle46Position_x=3.2;
float particle46Position_y=0.0;
float particle46Position_z=0.0;

float particle47Position_x=4.2;
float particle47Position_y=0.0;
float particle47Position_z=0.0;

float particle48Position_x=5.2;
float particle48Position_y=0.0;
float particle48Position_z=0.0;

float particle49Position_x=-5.8;
float particle49Position_y=-1.0;
float particle49Position_z=0.0;

float particle50Position_x=-4.8;
float particle50Position_y=-1.0;
float particle50Position_z=0.0;

float particle51Position_x=-3.8;
float particle51Position_y=-1.0;
float particle51Position_z=0.0;

float particle52Position_x=-2.8;
float particle52Position_y=-1.0;
float particle52Position_z=0.0;

float particle53Position_x=-1.8;
float particle53Position_y=-1.0;
float particle53Position_z=0.0;

float particle54Position_x=-0.8;
float particle54Position_y=-1.0;
float particle54Position_z=0.0;

float particle55Position_x=0.2;
float particle55Position_y=-1.0;
float particle55Position_z=0.0;

float particle56Position_x=1.2;
float particle56Position_y=-1.0;
float particle56Position_z=0.0;

float particle57Position_x=2.2;
float particle57Position_y=-1.0;
float particle57Position_z=0.0;

float particle58Position_x=3.2;
float particle58Position_y=-1.0;
float particle58Position_z=0.0;

float particle59Position_x=4.2;
float particle59Position_y=-1.0;
float particle59Position_z=0.0;

float particle60Position_x=5.2;
float particle60Position_y=-1.0;
float particle60Position_z=0.0;










void init (void)
{
  glShadeModel (GL_SMOOTH);
  glClearColor (0.2f, 0.2f, 0.4f, 0.5f);
  glClearDepth (1.0f);
  glEnable (GL_DEPTH_TEST);
  glDepthFunc (GL_LEQUAL);
  glEnable (GL_COLOR_MATERIAL);
  glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glEnable (GL_LIGHTING);
  glEnable (GL_LIGHT0);
  GLfloat lightPos[4] = {-1.0, 1.0, 0.5, 0.0};
  glLightfv (GL_LIGHT0, GL_POSITION, (GLfloat *) &lightPos);
  glEnable (GL_LIGHT1);
  GLfloat lightAmbient1[4] = {0.0, 0.0,  0.0, 0.0};
  GLfloat lightPos1[4]     = {1.0, 0.0, -0.2, 0.0};
  GLfloat lightDiffuse1[4] = {0.5, 0.5,  0.3, 0.0};
  glLightfv (GL_LIGHT1,GL_POSITION, (GLfloat *) &lightPos1);
  glLightfv (GL_LIGHT1,GL_AMBIENT, (GLfloat *) &lightAmbient1);
  glLightfv (GL_LIGHT1,GL_DIFFUSE, (GLfloat *) &lightDiffuse1);
  glLightModeli (GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);



}





void initial(void)
{
    glPointSize(10.0f);
glColor3f(0.0, 1.0, 0.0);
glBegin(GL_POINTS);

glVertex3f(-5.8,3.0f, 0.0f);
glVertex3f(-4.8, 3.0f, 0.0f);
glVertex3f(-3.8, 3.0f, 0.0f);
glVertex3f(particle4Position_x, particle4Position_y, particle4Position_z);
glVertex3f(particle5Position_x, particle5Position_y, particle5Position_z);
glVertex3f(particle6Position_x, particle6Position_y, particle6Position_z);
glVertex3f(particle7Position_x, particle7Position_y, particle7Position_z);
glVertex3f(particle8Position_x, particle8Position_y, particle8Position_z);
glVertex3f(particle9Position_x, particle9Position_y, particle9Position_z);
glVertex3f(3.2, 3.0f, 0.0f);
glVertex3f(4.2, 3.0f, 0.0f);
glVertex3f(5.2, 3.0f, 0.0f);


glEnd();

glPointSize(10.0f);//set point size to 10 pixels
    glColor3f(0.0f, 1.0f, 0.0f);
glBegin(GL_POINTS);

glVertex3f(particle13Position_x, particle13Position_y, particle13Position_z);
glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);
glVertex3f(particle15Position_x, particle15Position_y , particle15Position_z);
glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);
glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);
glVertex3f(particle18Position_x,  particle18Position_y, particle18Position_z);
glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);
glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);
glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);
glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);
glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);
glVertex3f(particle24Position_x, particle24Position_y, particle24Position_z);

glEnd();


glPointSize(10.0f);//set point size to 10 pixels
    glColor3f(0.0f, 1.0f, 0.0f);
glBegin(GL_POINTS);

glVertex3f(particle25Position_x, particle25Position_y, particle25Position_z);
glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);
glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);
glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);
glVertex3f(particle29Position_x, particle30Position_y, particle29Position_z);
glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);
glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);
glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);
glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);
glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);
glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);
glVertex3f(particle36Position_x, particle36Position_y, particle36Position_z);


glEnd();

glPointSize(10.0f);//set point size to 10 pixels
glColor3f(0.0f, 1.0f, 0.0f);
glBegin(GL_POINTS);

glVertex3f(particle37Position_x, particle37Position_y, particle37Position_z);
glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);
glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);
glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);
glVertex3f(particle41Position_x,  particle41Position_y, particle41Position_z);
glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);
glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);
glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);
glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);
glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);
glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);
glVertex3f(particle48Position_x, particle48Position_y, particle48Position_z);


glEnd();

glPointSize(10.0f);//set point size to 10 pixels
glColor3f(0.0f, 1.0f, 0.0f);

glBegin(GL_POINTS);

glVertex3f(particle49Position_x, particle49Position_y, particle49Position_z);
glVertex3f(particle50Position_x, particle50Position_y, particle50Position_z);
glVertex3f(particle51Position_x, particle51Position_y, particle51Position_z);
glVertex3f(particle52Position_x, particle52Position_y, particle52Position_z);
glVertex3f(particle53Position_x, particle53Position_y, particle53Position_z);
glVertex3f(particle54Position_x, particle54Position_y, particle54Position_z);
glVertex3f(particle55Position_x, particle55Position_y, particle55Position_z);
glVertex3f(particle56Position_x, particle56Position_y, particle56Position_z);
glVertex3f(particle57Position_x, particle57Position_y, particle57Position_z);
glVertex3f(particle58Position_x, particle58Position_y, particle58Position_z);
glVertex3f(particle59Position_x, particle59Position_y, particle59Position_z);
glVertex3f(particle60Position_x, particle60Position_y, particle60Position_z);


glEnd();






glBegin(GL_LINES);

glVertex3f(-5.8, 3.0f, 0.0f);
glVertex3f(-4.8, 3.0f, 0.0f);

glEnd();

glBegin(GL_LINES);

glVertex3f(-4.8, 3.0f, 0.0f);
glVertex3f(-3.8, 3.0f, 0.0f);

glEnd();


glBegin(GL_LINES);

glVertex3f(-3.8, 3.0f, 0.0f);
glVertex3f(particle4Position_x, particle4Position_y, particle4Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle4Position_x, particle4Position_y, particle4Position_z);
glVertex3f(particle5Position_x, particle5Position_y, particle5Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle5Position_x, particle5Position_y, particle5Position_z);
glVertex3f(particle6Position_x, particle6Position_y, particle6Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle6Position_x, particle6Position_y, particle6Position_z);
glVertex3f(particle7Position_x, particle7Position_y, particle7Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle7Position_x, particle7Position_y, particle7Position_z);
glVertex3f(particle8Position_x, particle8Position_y, particle8Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle8Position_x, particle8Position_y, particle8Position_z);
glVertex3f(particle9Position_x, particle9Position_y, particle9Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle9Position_x, particle9Position_y, particle9Position_z);
glVertex3f(3.2, 3.0, 0.0f);

glEnd();


glBegin(GL_LINES);

glVertex3f(3.2, 3.0, 0.0f);
glVertex3f(4.2, 3.0, 0.0f);

glEnd();

glBegin(GL_LINES);

glVertex3f(4.2, 3.0f, 0.0f);
glVertex3f(5.2, 3.0f, 0.0f);

glEnd();






glBegin(GL_LINES);

glVertex3f(particle13Position_x, particle13Position_y, particle13Position_z);
glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);
glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);
glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);
glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);
glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);
glVertex3f(particle19Position_x, particle19Position_z, particle19Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);
glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);
glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);
glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);
glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);

glEnd();








glBegin(GL_LINES);

glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);
glVertex3f(particle24Position_x, particle24Position_y, particle24Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle24Position_x, particle24Position_y, particle24Position_z);
glVertex3f(particle25Position_x, particle25Position_y, particle25Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle25Position_x, particle25Position_y, particle25Position_z);
glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);
glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);
glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);
glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);
glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);
glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);

glEnd();




glBegin(GL_LINES);

glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);
glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);
glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);

glEnd();







glBegin(GL_LINES);

glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);
glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);
glVertex3f(particle35Position_x, particle35Position_y, particle34Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);
glVertex3f(particle36Position_x, particle36Position_y, particle36Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle36Position_x, particle36Position_y, particle36Position_z);
glVertex3f(particle37Position_x, particle37Position_y, particle37Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle37Position_x, particle37Position_y, particle37Position_z);
glVertex3f(particle37Position_x, particle37Position_y, particle37Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle37Position_x, particle37Position_y, particle37Position_z);
glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);
glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);
glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);
glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);
glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);
glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);

glEnd();






glBegin(GL_LINES);

glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);
glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);
glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);
glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);
glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);
glVertex3f(particle48Position_x, particle48Position_y, particle48Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle48Position_x, particle48Position_y, particle48Position_z);
glVertex3f(particle49Position_x, particle49Position_y, particle49Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle49Position_x, particle49Position_y, particle49Position_z);
glVertex3f(particle50Position_x, particle50Position_y, particle50Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle50Position_x, particle50Position_y, particle50Position_z);
glVertex3f(particle51Position_x, particle51Position_y, particle51Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle51Position_x, particle51Position_y, particle51Position_z);
glVertex3f(particle52Position_x, particle52Position_y, particle52Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle52Position_x, particle52Position_y, particle52Position_z);
glVertex3f(particle53Position_x, particle53Position_y, particle53Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle53Position_x, particle53Position_y, particle53Position_z);
glVertex3f(particle54Position_x, particle54Position_y, particle54Position_z);

glEnd();


int u;
glBegin(GL_LINES);

   glVertex3f(particle54Position_x, particle54Position_y, particle54Position_z);
 glVertex3f(particle55Position_x, particle55Position_y, particle55Position_z);

glEnd();
glBegin(GL_LINES);

glVertex3f(particle55Position_x, particle55Position_y, particle55Position_z);
glVertex3f(particle56Position_x, particle56Position_y, particle56Position_z);

glEnd();
glBegin(GL_LINES);

glVertex3f(particle56Position_x, particle56Position_y, particle56Position_z);
glVertex3f(particle57Position_x, particle57Position_y, particle57Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle57Position_x, particle57Position_y, particle57Position_z);
glVertex3f(particle58Position_x, particle58Position_y, particle58Position_z);

glEnd();
glBegin(GL_LINES);

glVertex3f(particle58Position_x, particle58Position_y, particle58Position_z);
glVertex3f(particle59Position_x, particle59Position_y, particle59Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle59Position_x, particle59Position_y, particle59Position_z);
glVertex3f(particle60Position_x, particle60Position_y, particle60Position_z);

glEnd();
glBegin(GL_LINES);

glVertex3f(-5.8, 3.0f, 0.0f);
glVertex3f(particle13Position_x, particle13Position_y, particle13Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(-4.8, 3.0f, 0.0f);
glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);

glEnd();

glBegin(GL_LINES);
 glVertex3f(-3.8, 3.0f, 0.0f);
 glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle4Position_x, particle4Position_y, particle4Position_z);
 glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle5Position_x, particle5Position_y, particle5Position_z);
 glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle6Position_x, particle6Position_y, particle6Position_z);
 glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);
 glEnd();

glBegin(GL_LINES);

glVertex3f(particle7Position_x, particle7Position_y, particle7Position_z);
glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);

glEnd();




glBegin(GL_LINES);

glVertex3f(particle8Position_x, particle8Position_y, particle8Position_z);
glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle9Position_x, particle9Position_y, particle9Position_z);
glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);

glEnd();




glBegin(GL_LINES);

glVertex3f(3.2, 3.0f, 0.0f);
glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(4.2, 3.0f, 0.0f);
glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(5.2, 3.0f, 0.0f);
glVertex3f(particle24Position_x, particle24Position_y, particle24Position_z);

glEnd();





glBegin(GL_LINES);
 glVertex3f(particle13Position_x, particle13Position_y, particle13Position_z);
 glVertex3f(particle25Position_x, particle25Position_y, particle25Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);
 glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);
 glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);
 glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);
 glEnd();







glBegin(GL_LINES);
 glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);
 glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);
 glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);
 glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);
 glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);
 glEnd();






glBegin(GL_LINES);
 glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);
 glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);
 glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);
 glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle24Position_x, particle24Position_y, particle24Position_z);
 glVertex3f(particle36Position_x, particle36Position_y, particle36Position_z);
 glEnd();




glBegin(GL_LINES);

glVertex3f(particle25Position_x, particle25Position_y, particle25Position_z);
glVertex3f(particle37Position_x, particle37Position_y, particle37Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);
glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);
glEnd();

glBegin(GL_LINES);

glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);
glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);
glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);
glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);
glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);
glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);
glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);
glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);

glEnd();






 glBegin(GL_LINES);
 glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);
 glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);
 glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle36Position_x, particle36Position_y, particle36Position_z);
 glVertex3f(particle48Position_x, particle48Position_y, particle48Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle37Position_x, particle37Position_y, particle37Position_z);
 glVertex3f(particle49Position_x, particle49Position_y, particle49Position_z);
 glEnd();






glBegin(GL_LINES);
 glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);
 glVertex3f(particle50Position_x, particle50Position_y, particle50Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);
 glVertex3f(particle51Position_x, particle51Position_y, particle51Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);
 glVertex3f(particle52Position_x, particle52Position_y, particle52Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);
 glVertex3f(particle53Position_x, particle53Position_y, particle53Position_z);
 glEnd();





 glBegin(GL_LINES);
 glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);
 glVertex3f(particle54Position_x, particle54Position_y, particle54Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);
 glVertex3f(particle55Position_x, particle55Position_y, particle55Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);
 glVertex3f(particle56Position_x, particle56Position_y, particle56Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);
 glVertex3f(particle57Position_x, particle57Position_y, particle57Position_z);
 glEnd();



glBegin(GL_LINES);
 glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);
 glVertex3f(particle58Position_x, particle58Position_y, particle58Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);
 glVertex3f(particle59Position_x, particle59Position_y, particle59Position_y);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle48Position_x, particle48Position_y, particle48Position_z);
 glVertex3f(particle60Position_x, particle60Position_y, particle60Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(-5.8, 3.0f, 0.0f);
 glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);
 glEnd();


 glBegin(GL_LINES);
 glVertex3f(-4.8, 3.0f, 0.0f);
 glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);
 glEnd();





 glBegin(GL_LINES);
 glVertex3f(-3.8, 3.0f, 0.0f);
 glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);
 glEnd();


 glBegin(GL_LINES);
 glVertex3f(particle4Position_x, particle4Position_y, particle4Position_z);
 glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);
 glEnd();



 glBegin(GL_LINES);
 glVertex3f(particle5Position_x, particle5Position_y, particle5Position_z);
 glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);
 glEnd();






glBegin(GL_LINES);
 glVertex3f(particle6Position_x, particle6Position_y, particle6Position_z);
 glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);
 glEnd();





 glBegin(GL_LINES);
 glVertex3f(particle7Position_x, particle7Position_y, particle7Position_z);
 glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle8Position_x, particle8Position_y, particle8Position_z);
 glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle9Position_x, particle9Position_y, particle9Position_z);
 glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);
 glEnd();

glBegin(GL_LINES);
 glVertex3f(3.2, 3.0f, 0.0f);
 glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);
 glEnd();



glBegin(GL_LINES);
 glVertex3f(4.2, 3.0f, 0.0f);
 glVertex3f(particle24Position_x, particle24Position_y, particle24Position_z);
 glEnd();




glBegin(GL_LINES);
 glVertex3f(particle13Position_x, particle13Position_y, particle13Position_z);
 glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);
 glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);
 glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);
 glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);
 glEnd();







 glBegin(GL_LINES);
 glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);
 glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);
 glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);
 glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);
 glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);
 glEnd();






glBegin(GL_LINES);
 glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);
 glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);
 glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);
 glVertex3f(particle36Position_x, particle36Position_y, particle36Position_z);
 glEnd();

 glBegin(GL_LINES);
 glVertex3f(particle25Position_x, particle25Position_y, particle25Position_z);
 glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);
 glEnd();



glBegin(GL_LINES);

glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);
glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);
glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);
glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);
glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);
glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);
glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);
glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);
glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);
glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);
glVertex3f(particle48Position_x, particle48Position_y, particle48Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle37Position_x, particle37Position_y, particle37Position_z);
glVertex3f(particle50Position_x, particle50Position_y, particle50Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);
glVertex3f(particle51Position_x, particle51Position_y, particle51Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);
glVertex3f(particle52Position_x, particle52Position_y, particle52Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);
glVertex3f(particle53Position_x, particle53Position_y, particle53Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);
glVertex3f(particle54Position_x, particle54Position_y, particle54Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);
glVertex3f(particle55Position_x, particle55Position_y, particle55Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);
glVertex3f(particle56Position_x, particle56Position_y, particle56Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);
glVertex3f(particle57Position_x, particle57Position_y, particle57Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);
glVertex3f(particle58Position_x, particle58Position_y, particle58Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);
glVertex3f(particle59Position_x, particle59Position_y, particle59Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);
glVertex3f(particle60Position_x, particle60Position_y, particle60Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(-4.8, 3.0f, 0.0f);
glVertex3f(particle13Position_x, particle13Position_y, particle13Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(-3.8, 3.0f, 0.0f);
glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle4Position_x, particle4Position_y, particle4Position_z);
glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle5Position_x, particle5Position_y, particle5Position_z);
glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle6Position_x, particle6Position_y, particle6Position_z);
glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle7Position_x, particle7Position_y, particle7Position_z);
glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle8Position_x, particle8Position_y, particle8Position_z);
glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle9Position_x, particle9Position_y, particle9Position_z);
glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle10Position_x, particle10Position_y, particle10Position_z);
glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle11Position_x, particle11Position_y, particle11Position_z);
glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle12Position_x, particle12Position_y, particle12Position_z);
glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);
glVertex3f(particle25Position_x, particle25Position_y, particle25Position_z);

glEnd();




glBegin(GL_LINES);

glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);
glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);
glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);
glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);
glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);
glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);

glEnd();




glBegin(GL_LINES);

glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);
glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);
glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);
glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);
glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle24Position_x, particle24Position_y, particle24Position_z);
glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);

glEnd();




glBegin(GL_LINES);

glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);
glVertex3f(particle37Position_x, particle37Position_y, particle37Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);
glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);
glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);
glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);
glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);
glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);
glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);
glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);
glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);
glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);

glEnd();




glBegin(GL_LINES);

glVertex3f(particle36Position_x, particle36Position_y, particle36Position_z);
glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);
glVertex3f(particle49Position_x, particle49Position_y, particle49Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);
glVertex3f(particle50Position_x, particle50Position_y, particle50Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);
glVertex3f(particle51Position_x, particle51Position_y, particle51Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);
glVertex3f(particle52Position_x, particle52Position_y, particle52Position_z);

glEnd();




glBegin(GL_LINES);

glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);
glVertex3f(particle53Position_x, particle53Position_y, particle53Position_z);

glEnd();


glBegin(GL_LINES);

glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);
glVertex3f(particle54Position_x, particle54Position_y, particle54Position_z);

glEnd();



glBegin(GL_LINES);

glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);
glVertex3f(particle55Position_x, particle55Position_y, particle55Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);
glVertex3f(particle56Position_x, particle56Position_y, particle56Position_z);

glEnd();


glBegin(GL_LINES);
glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);
glVertex3f(particle57Position_x, particle57Position_y, particle57Position_z);

glEnd();




glBegin(GL_LINES);

glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);
glVertex3f(particle58Position_x, particle58Position_y, particle58Position_z);

glEnd();

glBegin(GL_LINES);

glVertex3f(particle48Position_x, particle48Position_y, particle48Position_z);
glVertex3f(particle59Position_x, particle59Position_y, particle59Position_z);

glEnd();










glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(-5.8, 3.0f, 0.0f);
glVertex3f(-4.8, 3.0f, 0.0f);
glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(-5.8, 3.0f, 0.0f);
glVertex3f(particle13Position_x, particle13Position_y, particle13Position_z);
glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);

glEnd();



glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(-4.8, 3.0f, 0.0f);
glVertex3f(-3.8, 3.0f, 0.0f);
glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(-4.8, 3.0f, 0.0f);
glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);
glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);

glEnd();



glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(-3.8, 3.0f, 0.0f);
glVertex3f(particle4Position_x, particle4Position_y, particle4Position_z);
glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(-3.8, 3.0f, 0.0f);
glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);
glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);  //here
glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);
glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);

glEnd();

glColor3f(0,1,0);
glBegin(GL_TRIANGLES);

glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);  //here
glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);
glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);

glEnd();
glColor3f(0,1,0);
glBegin(GL_TRIANGLES);

glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);  //here
glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);
glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);

glEnd();
glColor3f(0,1,0);
glBegin(GL_TRIANGLES);

glVertex3f(particle4Position_x, particle4Position_y, particle4Position_z);
glVertex3f(particle5Position_x, particle5Position_y, particle5Position_z);
glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);

glEnd();
glColor3f(0,1,0);
glBegin(GL_TRIANGLES);

glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);
glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);
glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle4Position_x, particle4Position_y, particle4Position_z);
glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);
glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle5Position_x, particle5Position_y, particle5Position_z);
glVertex3f(particle6Position_x, particle6Position_y, particle6Position_z);
glVertex3f(particle18Position_x,particle18Position_y, particle18Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle5Position_x, particle5Position_y, particle5Position_z);
glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);
glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle6Position_x, particle6Position_y, particle6Position_z);
glVertex3f(particle7Position_x, particle7Position_y, particle7Position_z);
glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle6Position_x, particle6Position_y, particle6Position_z);
glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);
glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle7Position_x, particle7Position_y, particle7Position_z);
glVertex3f(particle8Position_x, particle8Position_y, particle8Position_z);
glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle7Position_x, particle7Position_y, particle7Position_z);
glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);
glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle8Position_x, particle8Position_y, particle8Position_z);
glVertex3f(particle9Position_x, particle9Position_y, particle9Position_z);
glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle8Position_x, particle8Position_y, particle8Position_z);
glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);
glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);

glEnd();




glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle9Position_x, particle9Position_y, particle9Position_z);
glVertex3f(3.2, 3.0f, 0.0f);
glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle9Position_x, particle9Position_y, particle9Position_z);
glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);
glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);

glEnd();



glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(3.2, 3.0f, 0.0f);
glVertex3f(4.2, 3.0f, 0.0f);
glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(3.2, 3.0f, 0.0f);
glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);
glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(4.2, 3.0f, 0.0f);
glVertex3f(5.2, 3.0f, 0.0f);
glVertex3f(particle24Position_x, particle24Position_y, particle24Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(4.2, 3.0f, 0.0f);
glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);
glVertex3f(particle24Position_x, particle24Position_y, particle24Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle13Position_x, particle13Position_y, particle13Position_z);
glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);
glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle13Position_x, particle13Position_y, particle13Position_z);
glVertex3f(particle25Position_x, particle25Position_y, particle25Position_z);
glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);

glEnd();



glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);
glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);
glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle14Position_x, particle14Position_y, particle14Position_z);
glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);
glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);

glEnd();



glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);
glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);
glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle15Position_x, particle15Position_y, particle15Position_z);
glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);
glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);
glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);
glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle16Position_x, particle16Position_y, particle16Position_z);
glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);
glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);
glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);
glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle17Position_x, particle17Position_y, particle17Position_z);
glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);
glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);

glEnd();




glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);
glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);
glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle18Position_x, particle18Position_y, particle18Position_z);
glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);
glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);

glEnd();



glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);
glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);
glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle19Position_x, particle19Position_y, particle19Position_z);
glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);
glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);
glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);
glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle20Position_x, particle20Position_y, particle20Position_z);
glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);
glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);
glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);
glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle21Position_x, particle21Position_y, particle21Position_z);
glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);
glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);

glEnd();






glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);
glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);
glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle22Position_x, particle22Position_y, particle22Position_z);
glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);
glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);

glEnd();



glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);
glVertex3f(particle24Position_x, particle24Position_y, particle24Position_z);
glVertex3f(particle36Position_x, particle36Position_y, particle36Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle23Position_x, particle23Position_y, particle23Position_z);
glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);
glVertex3f(particle36Position_x, particle36Position_y, particle36Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle25Position_x, particle25Position_y, particle25Position_z);
glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);
glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle25Position_x, particle25Position_y, particle25Position_z);
glVertex3f(particle37Position_x, particle37Position_y, particle37Position_z);
glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);
glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);
glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle26Position_x, particle26Position_y, particle26Position_z);
glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);
glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);

glEnd();




glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);
glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);
glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle27Position_x, particle27Position_y, particle27Position_z);
glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);
glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);

glEnd();



glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);
glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);
glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle28Position_x, particle28Position_y, particle28Position_z);
glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);
glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);
glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);
glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle29Position_x, particle29Position_y, particle29Position_z);
glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);
glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);
glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);
glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle30Position_x, particle30Position_y, particle30Position_z);
glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);
glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);
glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);
glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle31Position_x, particle31Position_y, particle31Position_z);
glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);
glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);
glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);
glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle32Position_x, particle32Position_y, particle32Position_z);
glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);
glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);

glEnd();



glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);
glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);
glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle33Position_x, particle33Position_y, particle33Position_z);
glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);
glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);
glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);
glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);


glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle34Position_x, particle34Position_y, particle34Position_z);
glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);
glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);
glVertex3f(particle36Position_x, particle36Position_y, particle36Position_z);
glVertex3f(particle48Position_x, particle48Position_y, particle48Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle35Position_x, particle35Position_y, particle35Position_z);
glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);
glVertex3f(particle48Position_x, particle48Position_y, particle48Position_z);

glEnd();





glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle37Position_x, particle37Position_y, particle37Position_z);
glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);
glVertex3f(particle50Position_x, particle50Position_y, particle50Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle37Position_x, particle37Position_y, particle37Position_z);
glVertex3f(particle49Position_x, particle49Position_y, particle49Position_z);
glVertex3f(particle50Position_x, particle50Position_y, particle50Position_z);

glEnd();



glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);
glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);
glVertex3f(particle51Position_x, particle51Position_y, particle51Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle38Position_x, particle38Position_y, particle38Position_z);
glVertex3f(particle50Position_x, particle50Position_y, particle50Position_z);
glVertex3f(particle51Position_x, particle51Position_y, particle51Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);
glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);
glVertex3f(particle52Position_x, particle52Position_y, particle52Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle39Position_x, particle39Position_y, particle39Position_z);
glVertex3f(particle51Position_x, particle51Position_y, particle51Position_z);
glVertex3f(particle52Position_x, particle52Position_y, particle52Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);
glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);
glVertex3f(particle53Position_x, particle53Position_y, particle53Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle40Position_x, particle40Position_y, particle40Position_z);
glVertex3f(particle52Position_x, particle52Position_y, particle52Position_z);
glVertex3f(particle53Position_x, particle53Position_y, particle53Position_z);

glEnd();





glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);
glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);
glVertex3f(particle54Position_x, particle54Position_y, particle54Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle41Position_x, particle41Position_y, particle41Position_z);
glVertex3f(particle53Position_x, particle53Position_y, particle53Position_z);
glVertex3f(particle54Position_x, particle54Position_y, particle54Position_z);

glEnd();



glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle42Position_x, particle42Position_y, particle42Position_z);
glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);
glVertex3f(particle55Position_x, particle55Position_y, particle55Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle42Position_x,particle42Position_y, particle42Position_z);
glVertex3f(particle54Position_x, particle54Position_y, particle54Position_z);
glVertex3f(particle55Position_x, particle55Position_y, particle55Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);
glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);
glVertex3f(particle56Position_x, particle56Position_y, particle56Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle43Position_x, particle43Position_y, particle43Position_z);
glVertex3f(particle55Position_x, particle55Position_y, particle55Position_z);
glVertex3f(particle56Position_x, particle56Position_y, particle56Position_z);

glEnd();

glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);
glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);
glVertex3f(particle57Position_x, particle57Position_y, particle57Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle44Position_x, particle44Position_y, particle44Position_z);
glVertex3f(particle56Position_x, particle56Position_y, particle56Position_z);
glVertex3f(particle57Position_x, particle57Position_y, particle57Position_z);

glEnd();









glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);
glVertex3f(particle46Position_x, particle46Position_y, 0.0f);
glVertex3f(particle58Position_x, particle58Position_y, 0.0f);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle45Position_x, particle45Position_y, particle45Position_z);
glVertex3f(particle57Position_x, particle57Position_y, particle57Position_z);
glVertex3f(particle58Position_x, particle58Position_y, particle58Position_z);

glEnd();



glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);
glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);
glVertex3f(particle59Position_x, particle59Position_y, particle59Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle46Position_x, particle46Position_y, particle46Position_z);
glVertex3f(particle58Position_x, particle58Position_y, particle58Position_z);
glVertex3f(particle59Position_x, particle59Position_y, particle59Position_z);

glEnd();


glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);
glVertex3f(particle48Position_x, particle48Position_y, particle48Position_z);
glVertex3f(particle60Position_x, particle60Position_y, particle60Position_z);

glEnd();
glColor3f(0, 1, 0);
glBegin(GL_TRIANGLES);

glVertex3f(particle47Position_x, particle47Position_y, particle47Position_z);
glVertex3f(particle59Position_x, particle59Position_y, particle59Position_z);
glVertex3f(particle60Position_x, particle60Position_y, particle60Position_z);

glEnd();






}








void satisfyParticleConstraints(float x1, float y1, float z1, float x2, float y2, float z2)
{
    if((x1==x2 && y2==y1+1.0)||(x1==x2 && y1==y2+1.0))
    {
        restDistance=1.0;
    }
    if((y1==y2 && x2==x1+1.0)||(y1==y2 && x1==x2+1.0))
    {
        restDistance=1.0;
    }
     if(x2==x1+1.0 && y1==y2+1.0)
    {
        restDistance=sqrt(2.0);
    }
     if(x2==x1+1.0 && y1==y2-1.0)
    {
        restDistance=sqrt(2.0);
    }
    float particle_1_to_particle_2_distance_x=x2-x1;
     float particle_1_to_particle_2_distance_y=y2-y1;
      float particle_1_to_particle_2_distance_z=z2-z1;
      float currentDistance=sqrt(  ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)) +((z1-z2)*(z1-z2))   );
      float correction_vector_x=particle_1_to_particle_2_distance_x*(1.0-restDistance / currentDistance);
      float correction_vector_y=particle_1_to_particle_2_distance_y*(1.0-restDistance / currentDistance);
      float correction_vector_z=particle_1_to_particle_2_distance_z*(1.0-restDistance / currentDistance);
      float particle1_x=particle1_x+0.5*correction_vector_x;
      float particle1_y=particle1_y+0.5*correction_vector_y;
      float particle1_z=particle1_z+0.5*correction_vector_z;
      float particle2_x=particle2_x-0.5*correction_vector_x;
      float particle2_y=particle2_y-0.5*correction_vector_y;
      float particle2_z=particle2_z-0.5*correction_vector_z;

}







void display (void)
{

//clear color and depth buffer




float particle1DistanceSphere=sqrt(( (-5.8-xsphere) * (-5.8-xsphere) )+( (3.0-spherey) * (3.0-spherey) )+( (0.0-front) * (0.0-front)));



float particle2DistanceSphere=sqrt(( (-4.8-xsphere) * (-4.8-xsphere) )+( (3.0-ysphere) * (3.0-ysphere) )+( (0.0-front) * (0.0-front)));



float particle3DistanceSphere=sqrt( ((-3.8-xsphere) * (-3.8-xsphere) )+( (3.0-ysphere) * (3.0-ysphere) )+( (0.0-front) * (0.0-front)));




float particle4DistanceSphere=sqrt( ((particle4Position_x-xsphere) * (particle4Position_x-xsphere) )+( (particle4Position_y-ysphere) * (particle4Position_y-ysphere) )+( (particle4Position_z-front) * (particle4Position_z-front)));





float particle5DistanceSphere=sqrt(((particle5Position_x-xsphere) * (particle5Position_x-xsphere) )+( (particle5Position_y-ysphere) * (particle5Position_y-ysphere) )+( (particle5Position_z-front) * (particle5Position_z-front)));




float particle6DistanceSphere=sqrt( ((particle6Position_x-xsphere) * (particle6Position_x-xsphere) )+( (particle6Position_y-ysphere) * (particle6Position_y-ysphere) )+( (particle6Position_z-front) * (particle6Position_z-front)));



float particle7DistanceSphere=sqrt( ((particle7Position_x-xsphere) * (particle7Position_x-xsphere) )+( (particle7Position_y-ysphere) * (particle7Position_y-ysphere) )+( (particle7Position_z-front) * (particle7Position_z-front)));




float particle8DistanceSphere=sqrt(( (particle8Position_x-xsphere) * (particle8Position_x-xsphere) )+( (particle8Position_y-ysphere) * (particle8Position_y-ysphere) )+( (particle8Position_z-front) * (particle8Position_z-front)));






float particle9DistanceSphere=sqrt(((particle9Position_x-xsphere) * (particle9Position_x-xsphere) )+( (particle9Position_y-ysphere) * (particle9Position_y-ysphere) )+( (particle9Position_z-front) * (particle9Position_z-front)));




float particle10DistanceSphere=sqrt(( (3.2-xsphere) * (3.2-xsphere) )+( (3.0-ysphere) * (3.0-ysphere) )+( (0.0-front) * (0.0-front)));



float particle11DistanceSphere=sqrt(( (4.2-xsphere) * (4.2-xsphere) )+( (3.0-ysphere) * (3.0-ysphere) )+( (0.0-front) * (0.0-front)));




float particle12DistanceSphere=sqrt((( 5.2-xsphere) * (5.2-xsphere) )+( (3.0-ysphere) * (3.0-ysphere) )+( (0.0-front) * (0.0-front)));






float particle13DistanceSphere=sqrt(( (particle13Position_x-xsphere) * (particle13Position_x-xsphere) )+( (particle13Position_y-ysphere) * (particle13Position_y-ysphere) )+( (particle13Position_z-front) * (particle13Position_z-front)));




float particle14DistanceSphere=sqrt(( (particle14Position_x-xsphere) * (particle14Position_x-xsphere) )+( (particle14Position_y-ysphere) * (particle14Position_y-ysphere) )+( (particle14Position_z-front) * (particle14Position_z-front)));



float particle15DistanceSphere=sqrt(( (particle15Position_x-xsphere) * (particle15Position_x-xsphere) )+( (particle15Position_y-ysphere) * (particle15Position_y-ysphere) )+( (particle15Position_z-front) * (particle15Position_z-front)));




float particle16DistanceSphere=sqrt(( (particle16Position_x-xsphere) * (particle16Position_x-xsphere) )+( (particle16Position_y-ysphere) * (particle16Position_y-ysphere) )+( (particle16Position_z-front) * (particle16Position_z-front)));






float particle17DistanceSphere=sqrt(( (particle17Position_x-xsphere) * (particle17Position_x-xsphere) )+( (particle17Position_y-ysphere) * (particle17Position_y-ysphere) )+( (particle17Position_z-front) * (particle17Position_z-front)));





float particle18DistanceSphere=sqrt(( (particle18Position_x-xsphere) * (particle18Position_x-xsphere) )+( (particle18Position_y-ysphere) * (particle18Position_y-ysphere) )+( (particle18Position_z-front) * (particle18Position_z-front)));




float particle19DistanceSphere=sqrt(( (particle19Position_x-xsphere) * (particle19Position_x-xsphere) )+( (particle19Position_y-ysphere) * (particle19Position_y-ysphere) )+( (particle19Position_z-front) * (particle19Position_z-front)));



float particle20DistanceSphere=sqrt(( (particle20Position_x-xsphere) * (particle20Position_x-xsphere) )+( (particle20Position_y-ysphere) * (particle20Position_y-ysphere) )+( (particle20Position_z-front) * (particle20Position_z-front)));




float particle21DistanceSphere=sqrt(( (particle21Position_x-xsphere) * (particle21Position_x-xsphere) )+( (particle21Position_y-ysphere) * (particle21Position_y-ysphere) )+( (particle21Position_z-front) * (particle21Position_z-front)));



float particle22DistanceSphere=sqrt(( (particle22Position_x-xsphere) * (particle22Position_x-xsphere) )+( (particle22Position_y-ysphere) * (particle22Position_y-ysphere) )+( (particle22Position_z-front) * (particle22Position_z-front)));





float particle23DistanceSphere=sqrt(( (particle23Position_x-xsphere) * (particle23Position_x-xsphere) )+( (particle23Position_y-ysphere) * (particle23Position_y-ysphere) )+( (particle23Position_z-front) * (particle23Position_z-front)));




float particle24DistanceSphere=sqrt(( (particle24Position_x-xsphere) * (particle24Position_x-xsphere) )+( (particle24Position_y-ysphere) * (particle24Position_y-ysphere) )+( (particle24Position_z-front) * (particle24Position_z-front)));



float particle25DistanceSphere=sqrt(( (particle25Position_x-xsphere) * (particle25Position_x-xsphere) )+( (particle25Position_y-ysphere) * (particle25Position_y-ysphere) )+( (particle25Position_z-front) * (particle25Position_z-front)));




float particle26DistanceSphere=sqrt(( (particle26Position_x-xsphere) * (particle26Position_x-xsphere) )+( (particle26Position_y-ysphere) * (particle26Position_y-ysphere) )+( (particle26Position_z-front) * (particle26Position_z-front)));



float particle27DistanceSphere=sqrt(( (particle27Position_x-xsphere) * (particle27Position_x-xsphere) )+( (particle27Position_y-ysphere) * (particle27Position_y-ysphere) )+( (particle27Position_z-front) * (particle27Position_z-front)));



float particle28DistanceSphere=sqrt(( (particle28Position_x-xsphere) * (particle28Position_x-xsphere) )+( (particle28Position_y-ysphere) * (particle28Position_y-ysphere) )+( (particle28Position_z-front) * (particle28Position_z-front)));




float particle29DistanceSphere=sqrt(( (particle29Position_x-xsphere) * (particle29Position_x-xsphere) )+( (particle29Position_y-ysphere) * (particle29Position_y-ysphere) )+( (particle29Position_z-front) * (particle29Position_z-front)));



float particle30DistanceSphere=sqrt(( (particle30Position_x-xsphere) * (particle30Position_x-xsphere) )+( (particle30Position_y-ysphere) * (particle30Position_y-ysphere) )+( (particle30Position_z-front) * (particle30Position_z-front)));




float particle31DistanceSphere=sqrt(( (particle31Position_x-xsphere) * (particle31Position_x-xsphere) )+( (particle31Position_y-ysphere) * (particle31Position_y-ysphere) )+( (particle31Position_z-front) * (particle31Position_z-front)));







float particle32DistanceSphere=sqrt(( (particle32Position_x-xsphere) * (particle32Position_x-xsphere) )+( (particle32Position_y-ysphere) * (particle33Position_y-ysphere) )+( (particle33Position_z-front) * (particle33Position_z-front)));






float particle33DistanceSphere=sqrt(( (particle33Position_x-xsphere) * (particle33Position_x-xsphere) )+( (particle33Position_y-ysphere) * (particle33Position_y-ysphere) )+( (particle33Position_z-front) * (particle33Position_z-front)));





float particle34DistanceSphere=sqrt(( (particle34Position_x-xsphere) * (particle34Position_x-xsphere) )+( (particle34Position_y-ysphere) * (particle34Position_y-ysphere) )+( (particle34Position_z-front) * (particle34Position_z-front)));




float particle35DistanceSphere=sqrt(( (particle35Position_x-xsphere) * (particle35Position_x-xsphere) )+( (particle35Position_y-ysphere) * (particle35Position_y-ysphere) )+( (particle35Position_z-front) * (particle35Position_z-front)));




float particle36DistanceSphere=sqrt(( (particle36Position_x-xsphere) * (particle36Position_x-xsphere) )+( (particle36Position_y-ysphere) * (particle36Position_y-ysphere) )+( (particle36Position_z-front) * (particle36Position_z-front)));





float particle37DistanceSphere=sqrt(( (particle37Position_x-xsphere) * (particle37Position_x-xsphere) )+( (particle37Position_y-ysphere) * (particle37Position_y-ysphere) )+( (particle37Position_z-front) * (particle37Position_z-front)));




float particle38DistanceSphere=sqrt(( (particle38Position_x-xsphere) * (particle38Position_x-xsphere) )+( (particle38Position_y-ysphere) * (particle38Position_y-ysphere) )+( (particle38Position_z-front) * (particle38Position_z-front)));



float particle39DistanceSphere=sqrt(( (particle39Position_x-xsphere) * (particle39Position_x-xsphere) )+( (particle39Position_y-ysphere) * (particle39Position_y-ysphere) )+( (particle39Position_z-front) * (particle39Position_z-front)));



float particle40DistanceSphere=sqrt(( (particle40Position_x-xsphere) * (particle40Position_x-xsphere) )+( (particle40Position_y-ysphere) * (particle40Position_y-ysphere) )+( (particle40Position_z-front) * (particle40Position_z-front)));



float particle41DistanceSphere=sqrt(( (particle41Position_x-xsphere) * (particle41Position_x-xsphere) )+( (particle41Position_y-ysphere) * (particle41Position_y-ysphere) )+( (particle41Position_z-front) * (particle41Position_z-front)));




float particle42DistanceSphere=sqrt(( (particle42Position_x-xsphere) * (particle42Position_x-xsphere) )+( (particle42Position_y-ysphere) * (particle42Position_y-ysphere) )+( (particle42Position_z-front) * (particle42Position_z-front)));



float particle43DistanceSphere=sqrt(( (particle43Position_x-xsphere) * (particle43Position_x-xsphere) )+( (particle43Position_y-ysphere) * (particle43Position_y-ysphere) )+( (particle43Position_z-front) * (particle43Position_z-front)));



float particle44DistanceSphere=sqrt(( (particle44Position_x-xsphere) * (particle44Position_x-xsphere) )+( (particle44Position_y-ysphere) * (particle44Position_y-ysphere) )+( (particle44Position_z-front) * (particle44Position_z-front)));


float particle45DistanceSphere=+sqrt(( (particle45Position_x-xsphere) * (particle45Position_x-xsphere) )+( (particle45Position_y-ysphere) * (particle45Position_y-ysphere) )+( (particle45Position_z-front) * (particle45Position_z-front)));



float particle46DistanceSphere=sqrt(( (particle46Position_x-xsphere) * (particle46Position_x-xsphere) )+( (particle46Position_y-ysphere) * (particle46Position_y-ysphere) )+( (particle46Position_z-front) * (particle46Position_z-front)));






float particle47DistanceSphere=sqrt(( (particle47Position_x-xsphere) * (particle47Position_x-xsphere) )+( (particle47Position_y-ysphere) * (particle47Position_y-ysphere) )+( (particle47Position_z-front) * (particle47Position_z-front)));



float particle48DistanceSphere=sqrt(( (particle48Position_x-xsphere) * (particle48Position_x-xsphere) )+( (particle48Position_y-ysphere) * (particle48Position_y-ysphere) )+( (particle48Position_z-front) * (particle48Position_z-front)));



float particle49DistanceSphere=sqrt(( (particle49Position_x-xsphere) * (particle49Position_x-xsphere) )+( (particle49Position_y-ysphere) * (particle49Position_y-ysphere) )+( (front-particle49Position_z) * (front-particle49Position_z)));



float particle50DistanceSphere=sqrt(( (particle50Position_x-xsphere) * (particle50Position_x-xsphere) )+( (particle50Position_y-ysphere) * (particle50Position_y-ysphere) )+( (particle50Position_z-front) * (particle50Position_z-front)));




float particle51DistanceSphere=sqrt(( (particle51Position_x-xsphere) * (particle51Position_x-xsphere) )+( (particle51Position_y-ysphere) * (particle51Position_y-ysphere) )+( (particle51Position_z-front) * (particle51Position_z-front)));



float particle52DistanceSphere=sqrt(( (particle52Position_x-xsphere) * (particle52Position_x-xsphere) )+( (particle52Position_y-ysphere) * (particle52Position_y-ysphere) )+( (particle52Position_z-front) * (particle52Position_z-front)));



float particle53DistanceSphere=sqrt(( (particle53Position_x-xsphere) * (particle53Position_x-xsphere) )+( (particle53Position_y-ysphere) * (particle53Position_y-ysphere) )+( (front-particle53Position_z) * (front-particle53Position_z)));



float particle54DistanceSphere=sqrt(( (particle54Position_x-xsphere) * (particle54Position_x-xsphere) )+( (particle54Position_y-ysphere) * (particle54Position_y-ysphere) )+( (particle54Position_z-front) * (particle54Position_z-front)));




float particle55DistanceSphere=sqrt(( (particle55Position_x-xsphere) * (particle55Position_x-xsphere) )+( (particle55Position_y-ysphere) * (particle55Position_y-ysphere) )+( (particle55Position_z-front) * (particle55Position_z-front)));



float particle56DistanceSphere=sqrt(( (particle56Position_x-xsphere) * (particle56Position_x-xsphere) )+( (particle56Position_y-ysphere) * (particle56Position_y-ysphere) )+( (particle56Position_z-front) * (particle56Position_z-front)));



float particle57DistanceSphere=sqrt(( (particle57Position_x-xsphere) * (particle57Position_x-xsphere) )+( (particle57Position_y-ysphere) * (particle57Position_y-ysphere) )+( (particle57Position_z-front) * (particle57Position_z-front)));



float particle58DistanceSphere=sqrt(( (particle58Position_x-xsphere) * (particle58Position_x-xsphere) )+( (particle58Position_y-ysphere) * (particle58Position_y-ysphere) )+( (particle58Position_z-front) * (particle58Position_z-front)));



float particle59DistanceSphere=sqrt(( (particle59Position_x-xsphere) * (particle59Position_x-xsphere) )+( (particle59Position_y-ysphere) * (particle59Position_y-ysphere) )+( (particle59Position_z-front) * (particle59Position_z-front)));



float particle60DistanceSphere=sqrt(( (particle60Position_x-xsphere) * (particle60Position_x-xsphere) )+( (particle60Position_y-ysphere) * (particle60Position_y-ysphere) )+( (particle60Position_z-front) * (particle60Position_z-front)));



if((particle25DistanceSphere<spherex)||(front-particle25Position_z<spherex&&particle25Position_z-front<spherex&&particle25Position_y<=ysphere))
{

 particle25Position_x=((particle25Position_x-xsphere)/particle25DistanceSphere)*(spherex-particle25DistanceSphere);
 particle25Position_y=((particle25Position_y-ysphere)/particle25DistanceSphere)*(spherex-particle25DistanceSphere);
 particle25Position_z=((particle25Position_z-front)/particle25DistanceSphere)*(spherex-particle25DistanceSphere);
}




if((particle26DistanceSphere<spherex) ||(front-particle26Position_z<spherex&&particle26Position_z-front<spherex&&particle26Position_y<=ysphere))
{

 particle26Position_x=((particle26Position_x-xsphere)/particle26DistanceSphere)*(spherex-particle26DistanceSphere);
 particle26Position_y=((particle26Position_y-ysphere)/particle26DistanceSphere)*(spherex-particle26DistanceSphere);
 particle26Position_z=((particle26Position_z-front)/particle26DistanceSphere)*(spherex-particle26DistanceSphere);
}



if((particle27DistanceSphere<spherex)||(front-particle27Position_z<spherex&&particle27Position_z-front<spherex&&particle27Position_y<=ysphere))
{

 particle27Position_x=((particle27Position_x-xsphere)/particle27DistanceSphere)*(spherex-particle27DistanceSphere);
 particle27Position_y=((particle27Position_y-ysphere)/particle27DistanceSphere)*(spherex-particle27DistanceSphere);
 particle27Position_z=((particle27Position_z-front)/particle27DistanceSphere)*(spherex-particle27DistanceSphere);
}



if((particle28DistanceSphere<spherex)||(front-particle28Position_z<spherex&&particle28Position_z-front<spherex&&particle28Position_y<=ysphere))
{

 particle28Position_x=((particle28Position_x-xsphere)/particle28DistanceSphere)*(spherex-particle28DistanceSphere);
 particle28Position_y=((particle28Position_y-ysphere)/particle28DistanceSphere)*(spherex-particle28DistanceSphere);
 particle28Position_z=((particle28Position_z-front)/particle28DistanceSphere)*(spherex-particle28DistanceSphere);
}













if((particle23DistanceSphere<spherex) ||(front-particle23Position_z<spherex&&particle23Position_z-front<spherex&&particle23Position_y<=ysphere))
{

 particle23Position_x=((particle23Position_x-xsphere)/particle23DistanceSphere)*(spherex-particle23DistanceSphere);
 particle23Position_y=((particle23Position_y-ysphere)/particle23DistanceSphere)*(spherex-particle23DistanceSphere);
 particle23Position_z=((particle23Position_z-front)/particle23DistanceSphere)*(spherex-particle23DistanceSphere);
}


if((particle24DistanceSphere<spherex) ||(front-particle24Position_z<spherex&&particle24Position_z-front<spherex&&particle24Position_y<=ysphere))
{

 particle24Position_x=((particle24Position_x-xsphere)/particle24DistanceSphere)*(spherex-particle24DistanceSphere);
 particle24Position_y=((particle24Position_y-ysphere)/particle24DistanceSphere)*(spherex-particle24DistanceSphere);
 particle24Position_z=((particle24Position_z-front)/particle24DistanceSphere)*(spherex-particle24DistanceSphere);
}


if((particle25DistanceSphere<spherex) ||(front-particle25Position_z<spherex&&particle25Position_z-front<spherex&&particle25Position_y<=ysphere))
{

 particle25Position_x=((particle25Position_x-xsphere)/particle25DistanceSphere)*(spherex-particle25DistanceSphere);
 particle25Position_y=((particle25Position_y-ysphere)/particle25DistanceSphere)*(spherex-particle25DistanceSphere);
 particle25Position_z=((particle25Position_z-front)/particle25DistanceSphere)*(spherex-particle25DistanceSphere);
}




if((particle26DistanceSphere<spherex) ||(front-particle26Position_z<spherex&&particle26Position_z-front<spherex&&particle26Position_y<=ysphere))
{

 particle26Position_x=((particle26Position_x-xsphere)/particle26DistanceSphere)*(spherex-particle26DistanceSphere);
 particle26Position_y=((particle26Position_y-ysphere)/particle26DistanceSphere)*(spherex-particle26DistanceSphere);
 particle26Position_z=((particle26Position_z-front)/particle26DistanceSphere)*(spherex-particle26DistanceSphere);
}



if((particle27DistanceSphere<spherex) ||(front-particle27Position_z<spherex&&particle27Position_z-front<spherex&&particle27Position_y<=ysphere))
{

 particle27Position_x=((particle27Position_x-xsphere)/particle27DistanceSphere)*(spherex-particle27DistanceSphere);
 particle27Position_y=((particle27Position_y-ysphere)/particle27DistanceSphere)*(spherex-particle27DistanceSphere);
 particle27Position_z=((particle27Position_z-front)/particle27DistanceSphere)*(spherex-particle27DistanceSphere);
}



if((particle28DistanceSphere<spherex) ||(front-particle28Position_z<spherex&&particle28Position_z-front<spherex&&particle28Position_y<=ysphere))
{

 particle28Position_x=((particle28Position_x-xsphere)/particle28DistanceSphere)*(spherex-particle28DistanceSphere);
 particle28Position_y=((particle28Position_y-ysphere)/particle28DistanceSphere)*(spherex-particle28DistanceSphere);
 particle28Position_z=((particle28Position_z-front)/particle28DistanceSphere)*(spherex-particle28DistanceSphere);
}

if((particle29DistanceSphere<spherex) ||(front-particle29Position_z<spherex&&particle29Position_z-front<spherex&&particle29Position_y<=ysphere))
{

 particle29Position_x=((particle29Position_x-xsphere)/particle29DistanceSphere)*(spherex-particle29DistanceSphere);
 particle29Position_y=((particle29Position_y-ysphere)/particle29DistanceSphere)*(spherex-particle29DistanceSphere);
 particle29Position_z=((particle29Position_z-front)/particle29DistanceSphere)*(spherex-particle29DistanceSphere);
}


if((particle30DistanceSphere<spherex) ||(front-particle30Position_z<spherex&&particle30Position_z-front<spherex&&particle30Position_y<=ysphere))
{

 particle30Position_x=((particle30Position_x-xsphere)/particle30DistanceSphere)*(spherex-particle30DistanceSphere);
 particle30Position_y=((particle30Position_y-ysphere)/particle30DistanceSphere)*(spherex-particle30DistanceSphere);
 particle30Position_z=((particle30Position_z-front)/particle30DistanceSphere)*(spherex-particle30DistanceSphere);
}
if((particle31DistanceSphere<spherex) ||(front-particle31Position_z<spherex&&particle31Position_z-front<spherex&&particle31Position_y<=ysphere))
{

 particle31Position_x=((particle31Position_x-xsphere)/particle31DistanceSphere)*(spherex-particle31DistanceSphere);
 particle31Position_y=((particle31Position_y-ysphere)/particle31DistanceSphere)*(spherex-particle31DistanceSphere);
 particle31Position_z=((particle31Position_z-front)/particle31DistanceSphere)*(spherex-particle31DistanceSphere);
}
if((particle32DistanceSphere<spherex) ||(front-particle32Position_z<spherex&&particle32Position_z-front<spherex&&particle32Position_y<=ysphere))
{

 particle32Position_x=((particle32Position_x-xsphere)/particle32DistanceSphere)*(spherex-particle32DistanceSphere);
 particle32Position_y=((particle32Position_y-ysphere)/particle32DistanceSphere)*(spherex-particle32DistanceSphere);
 particle32Position_z=((particle32Position_z-front)/particle32DistanceSphere)*(spherex-particle32DistanceSphere);
}

if((particle33DistanceSphere<spherex) ||(front-particle33Position_z<spherex&&particle33Position_z-front<spherex&&particle33Position_y<=ysphere))
{

 particle33Position_x=((particle33Position_x-xsphere)/particle33DistanceSphere)*(spherex-particle33DistanceSphere);
 particle33Position_y=((particle33Position_y-ysphere)/particle33DistanceSphere)*(spherex-particle33DistanceSphere);
 particle33Position_z=((particle33Position_z-front)/particle33DistanceSphere)*(spherex-particle33DistanceSphere);
}


if((particle34DistanceSphere<spherex) ||(front-particle34Position_z<spherex&&particle34Position_z-front<spherex&&particle34Position_y<=ysphere))
{

 particle34Position_x=((particle34Position_x-xsphere)/particle34DistanceSphere)*(spherex-particle34DistanceSphere);
 particle34Position_y=((particle34Position_y-ysphere)/particle34DistanceSphere)*(spherex-particle34DistanceSphere);
 particle34Position_z=((particle34Position_z-front)/particle34DistanceSphere)*(spherex-particle34DistanceSphere);
}

if((particle35DistanceSphere<spherex) ||(front-particle35Position_z<spherex&&particle35Position_z-front<spherex&&particle35Position_y<=ysphere))
{

 particle35Position_x=((particle35Position_x-xsphere)/particle35DistanceSphere)*(spherex-particle35DistanceSphere);
 particle35Position_y=((particle35Position_y-ysphere)/particle35DistanceSphere)*(spherex-particle35DistanceSphere);
 particle35Position_z=((particle35Position_z-front)/particle35DistanceSphere)*(spherex-particle35DistanceSphere);
}
if((particle36DistanceSphere<spherex) ||(front-particle36Position_z<spherex&&particle36Position_z-front<spherex&&particle36Position_y<=ysphere))
{

 particle36Position_x=((particle36Position_x-xsphere)/particle36DistanceSphere)*(spherex-particle36DistanceSphere);
 particle36Position_y=((particle36Position_y-ysphere)/particle36DistanceSphere)*(spherex-particle36DistanceSphere);
 particle36Position_z=((particle36Position_z-front)/particle36DistanceSphere)*(spherex-particle36DistanceSphere);
}

if((particle37DistanceSphere<spherex)||(particle37DistanceSphere<spherex&&particle37Position_z-front<spherex&&particle37Position_y<=ysphere))
{

 particle37Position_x=((particle37Position_x-xsphere)/particle37DistanceSphere)*(spherex-particle37DistanceSphere);
 particle37Position_y=((particle37Position_y-ysphere)/particle37DistanceSphere)*(spherex-particle37DistanceSphere);
 particle37Position_z=((particle37Position_z-front)/particle37DistanceSphere)*(spherex-particle37DistanceSphere);
}
if((particle38DistanceSphere<spherex) ||(front-particle38Position_z<spherex&&particle38Position_z-front<spherex&&particle38Position_y<=ysphere))
{

 particle38Position_x=((particle38Position_x-xsphere)/particle38DistanceSphere)*(spherex-particle38DistanceSphere);
 particle38Position_y=((particle38Position_y-ysphere)/particle38DistanceSphere)*(spherex-particle38DistanceSphere);
 particle38Position_z=((particle38Position_z-front)/particle38DistanceSphere)*(spherex-particle38DistanceSphere);
}
if((particle39DistanceSphere<spherex) ||(front-particle39Position_z<spherex&&particle39Position_z-front<spherex&&particle39Position_y<=ysphere))
{

 particle39Position_x=((particle39Position_x-xsphere)/particle39DistanceSphere)*(spherex-particle39DistanceSphere);
 particle39Position_y=((particle39Position_y-ysphere)/particle39DistanceSphere)*(spherex-particle39DistanceSphere);
 particle39Position_z=((particle39Position_z-front)/particle39DistanceSphere)*(spherex-particle39DistanceSphere);
}
if((particle40DistanceSphere<spherex) ||(front-particle40Position_z<spherex&&particle40Position_z-front<spherex&&particle40Position_y<=ysphere))
{

 particle40Position_x=((particle40Position_x-xsphere)/particle40DistanceSphere)*(spherex-particle40DistanceSphere);
 particle40Position_y=((particle40Position_y-ysphere)/particle40DistanceSphere)*(spherex-particle40DistanceSphere);
 particle40Position_z=((particle40Position_z-front)/particle40DistanceSphere)*(spherex-particle40DistanceSphere);
}
if((particle41DistanceSphere<spherex) ||(front-particle41Position_z<spherex&&particle41Position_z-front<spherex&&particle41Position_y<=ysphere))
{

 particle41Position_x=((particle41Position_x-xsphere)/particle41DistanceSphere)*(spherex-particle41DistanceSphere);
 particle41Position_y=((particle41Position_y-ysphere)/particle41DistanceSphere)*(spherex-particle41DistanceSphere);
 particle41Position_z=((particle41Position_z-front)/particle41DistanceSphere)*(spherex-particle41DistanceSphere);
}

if((particle42DistanceSphere<spherex) ||(front-particle42Position_z<spherex&&particle42Position_z-front<spherex&&particle42Position_y<=ysphere))
{

 particle42Position_x=((particle42Position_x-xsphere)/particle42DistanceSphere)*(spherex-particle42DistanceSphere);
 particle42Position_y=((particle42Position_y-ysphere)/particle42DistanceSphere)*(spherex-particle42DistanceSphere);
 particle42Position_z=((particle42Position_z-front)/particle42DistanceSphere)*(spherex-particle42DistanceSphere);
}

if((particle43DistanceSphere<spherex) ||(front-particle43Position_z<spherex&&particle43Position_z-front<spherex&&particle43Position_y<=ysphere))
{

 particle43Position_x=((particle43Position_x-xsphere)/particle43DistanceSphere)*(spherex-particle43DistanceSphere);
 particle43Position_y=((particle43Position_y-ysphere)/particle43DistanceSphere)*(spherex-particle43DistanceSphere);
 particle43Position_z=((particle43Position_z-front)/particle43DistanceSphere)*(spherex-particle43DistanceSphere);
}

if((particle44DistanceSphere<spherex)||(front-particle44Position_z<spherex&&particle44Position_z-front<particle44Position_y<=ysphere))
{

 particle44Position_x=((particle44Position_x-xsphere)/particle44DistanceSphere)*(spherex-particle44DistanceSphere);
 particle44Position_y=((particle44Position_y-ysphere)/particle44DistanceSphere)*(spherex-particle44DistanceSphere);
 particle44Position_z=((particle44Position_z-front)/particle44DistanceSphere)*(spherex-particle44DistanceSphere);
}

if((particle45DistanceSphere<spherex)||(front-particle45Position_z<spherex&&particle45Position_z-front<spherex&&particle45Position_y<=ysphere))
{

 particle45Position_x=((particle45Position_x-xsphere)/particle45DistanceSphere)*(spherex-particle45DistanceSphere);
 particle45Position_y=((particle45Position_y-ysphere)/particle45DistanceSphere)*(spherex-particle45DistanceSphere);
 particle45Position_z=((particle45Position_z-front)/particle45DistanceSphere)*(spherex-particle45DistanceSphere);
}
if((particle46DistanceSphere<spherex)||(front-particle46Position_z<spherex&&particle46Position_z-front<=spherex&&particle46Position_y<=ysphere))
{

 particle46Position_x=((particle46Position_x-xsphere)/particle46DistanceSphere)*(spherex-particle46DistanceSphere);
 particle46Position_y=((particle46Position_y-ysphere)/particle46DistanceSphere)*(spherex-particle46DistanceSphere);
 particle46Position_z=((particle46Position_z-front)/particle46DistanceSphere)*(spherex-particle46DistanceSphere);
}

if((particle47DistanceSphere<spherex)||(front-particle47Position_z<spherex&&particle47Position_z-front<=spherex&&particle47Position_y<=ysphere))
{

 particle47Position_x=((particle47Position_x-xsphere)/particle47DistanceSphere)*(spherex-particle47DistanceSphere);
 particle47Position_y=((particle47Position_y-ysphere)/particle47DistanceSphere)*(spherex-particle47DistanceSphere);
 particle47Position_z=((particle47Position_z-front)/particle47DistanceSphere)*(spherex-particle47DistanceSphere);
}
if((particle48DistanceSphere<spherex)||(front-particle48Position_z<spherex&&particle48Position_z-front<=spherex&&particle48Position_y<=ysphere))
{

 particle48Position_x=((particle48Position_x-xsphere)/particle48DistanceSphere)*(spherex-particle48DistanceSphere);
 particle48Position_y=((particle48Position_y-ysphere)/particle48DistanceSphere)*(spherex-particle48DistanceSphere);
 particle48Position_z=((particle48Position_z-front)/particle48DistanceSphere)*(spherex-particle48DistanceSphere);
}
if((particle49DistanceSphere<spherex)||(front-particle49Position_z<spherex&&particle49Position_z-front<spherex&&particle49Position_y<=ysphere))
{

 particle49Position_x=((particle49Position_x-xsphere)/particle49DistanceSphere)*(spherex-particle49DistanceSphere);
 particle49Position_y=((particle49Position_y-ysphere)/particle49DistanceSphere)*(spherex-particle49DistanceSphere);
 particle49Position_z=((particle49Position_z-front)/particle49DistanceSphere)*(spherex-particle49DistanceSphere);
}
if((particle50DistanceSphere<spherex)||(front-particle50Position_z<spherex&&particle50Position_z-front<spherex&&particle50Position_y<=ysphere))
{

 particle50Position_x=((particle50Position_x-xsphere)/particle50DistanceSphere)*(spherex-particle50DistanceSphere);
 particle50Position_y=((particle50Position_y-ysphere)/particle50DistanceSphere)*(spherex-particle50DistanceSphere);
 particle50Position_z=((particle50Position_z-front)/particle50DistanceSphere)*(spherex-particle50DistanceSphere);
}
if((particle51DistanceSphere<spherex)||(front-particle51Position_z<spherex&&particle51Position_z-front<spherex&&particle51Position_y<=ysphere))
{

 particle51Position_x=((particle51Position_x-xsphere)/particle51DistanceSphere)*(spherex-particle51DistanceSphere);
 particle51Position_y=((particle51Position_y-ysphere)/particle51DistanceSphere)*(spherex-particle51DistanceSphere);
 particle51Position_z=((particle51Position_z-front)/particle51DistanceSphere)*(spherex-particle51DistanceSphere);
}
if((particle52DistanceSphere<spherex)||(front-particle52Position_z<spherex&&particle52Position_z-front<spherex&&particle52Position_y<=ysphere))
{

 particle52Position_x=((particle52Position_x-xsphere)/particle52DistanceSphere)*(spherex-particle52DistanceSphere);
 particle52Position_y=((particle52Position_y-ysphere)/particle52DistanceSphere)*(spherex-particle52DistanceSphere);
 particle52Position_z=((particle52Position_z-front)/particle52DistanceSphere)*(spherex-particle52DistanceSphere);
}
if((particle53DistanceSphere<spherex)||(front-particle53Position_z<spherex&&particle53Position_z-front<spherex&&particle53Position_y<=ysphere))
{

 particle53Position_x=((particle53Position_x-xsphere)/particle53DistanceSphere)*(spherex-particle53DistanceSphere);
 particle53Position_y=((particle53Position_y-ysphere)/particle53DistanceSphere)*(spherex-particle53DistanceSphere);
 particle53Position_z=((particle53Position_z-front)/particle53DistanceSphere)*(spherex-particle53DistanceSphere);
}
if((particle54DistanceSphere<spherex)||(front-particle54Position_z<spherex&&particle54Position_z-front<spherex&&particle54Position_y<=ysphere))
{

 particle54Position_x=((particle54Position_x-xsphere)/particle54DistanceSphere)*(spherex-particle54DistanceSphere);
 particle54Position_y=((particle54Position_y-ysphere)/particle54DistanceSphere)*(spherex-particle54DistanceSphere);
 particle54Position_z=((particle54Position_z-front)/particle54DistanceSphere)*(spherex-particle54DistanceSphere);
}

if((particle55DistanceSphere<spherex)||(front-particle55Position_z<spherex&&particle55Position_z-front<spherex&&particle55Position_y<=ysphere))
{

 particle55Position_x=((particle55Position_x-xsphere)/particle55DistanceSphere)*(spherex-particle55DistanceSphere);
 particle55Position_y=((particle55Position_y-ysphere)/particle55DistanceSphere)*(spherex-particle55DistanceSphere);
 particle55Position_z=((particle55Position_z-front)/particle55DistanceSphere)*(spherex-particle55DistanceSphere);
}
if((particle56DistanceSphere<spherex)||(front-particle56Position_z<spherex&&particle56Position_z-front<spherex&&particle56Position_y<=ysphere))
{

 particle56Position_x=((particle56Position_x-xsphere)/particle56DistanceSphere)*(spherex-particle56DistanceSphere);
 particle56Position_y=((particle56Position_y-ysphere)/particle56DistanceSphere)*(spherex-particle56DistanceSphere);
 particle56Position_z=((particle56Position_z-front)/particle56DistanceSphere)*(spherex-particle56DistanceSphere);
}
if((particle57DistanceSphere<spherex)||(front-particle57Position_z<spherex&&particle57Position_z-front<spherex&&particle57Position_y<=ysphere))
{

 particle57Position_x=((particle57Position_x-xsphere)/particle57DistanceSphere)*(spherex-particle57DistanceSphere);
 particle57Position_y=((particle57Position_y-ysphere)/particle57DistanceSphere)*(spherex-particle57DistanceSphere);
 particle57Position_z=((particle57Position_z-front)/particle57DistanceSphere)*(spherex-particle57DistanceSphere);
}
if((particle58DistanceSphere<spherex)||(front-particle58Position_z<spherex&&particle58Position_z-front<spherex&&particle58Position_y<=ysphere))
{

 particle58Position_x=((particle58Position_x-xsphere)/particle58DistanceSphere)*(spherex-particle58DistanceSphere);
 particle58Position_y=((particle58Position_y-ysphere)/particle58DistanceSphere)*(spherex-particle58DistanceSphere);
 particle58Position_z=((particle58Position_z-front)/particle58DistanceSphere)*(spherex-particle58DistanceSphere);
}
if((particle59DistanceSphere<spherex)||(front-particle59Position_z<spherex&&particle59Position_z-front<spherex&&particle59Position_y<=ysphere))
{

 particle59Position_x=((particle59Position_x-xsphere)/particle59DistanceSphere)*(spherex-particle59DistanceSphere);
 particle59Position_y=((particle59Position_y-ysphere)/particle59DistanceSphere)*(spherex-particle59DistanceSphere);
 particle59Position_z=((particle59Position_z-front)/particle59DistanceSphere)*(spherex-particle59DistanceSphere);
}
if((particle60DistanceSphere<spherex)||(front-particle60Position_z<spherex&&particle60Position_z-front<spherex&&particle60Position_y<=ysphere))
{

 particle60Position_x=((particle60Position_x-xsphere)/particle60DistanceSphere)*(spherex-particle60DistanceSphere);
 particle60Position_y=((particle60Position_y-ysphere)/particle60DistanceSphere)*(spherex-particle60DistanceSphere);
 particle60Position_z=((particle60Position_z-front)/particle60DistanceSphere)*(spherex-particle60DistanceSphere);
}





float windCrossProductXY=(((particle4Position_y*particle5Position_z) - (particle4Position_z*particle5Position_y))- ((particle4Position_x*particle5Position_z)-(particle4Position_z*particle5Position_x))+((particle4Position_x*particle5Position_y)-(particle4Position_y*particle5Position_x)));

float product1_x=(particle4Position_y*particle5Position_z)-(particle4Position_z*particle5Position_y);
float product1_y=(particle4Position_x*particle5Position_z)-(particle4Position_z*particle5Position_x);
float product1_z= (particle4Position_x*particle5Position_y)- (particle4Position_y*particle5Position_x);


float windCrossProductYZ=(((product1_x*particle17Position_z)-(product1_z*particle17Position_y))- ((product1_x*particle17Position_z)-(product1_z*particle17Position_z)) + ((product1_x*particle17Position_y)-(product1_y*particle17Position_x)));

float windX1=((product1_x*particle17Position_z)-(product1_z*particle17Position_y));
float windY1=((product1_x*particle17Position_z)-(product1_z*particle17Position_z));
float windZ1=((product1_x*particle17Position_y)-(product1_y*particle17Position_x));
float magnitude1=sqrt( (windX1*windX1)+(windY1*windY1)+(windZ1*windZ1));

float dotProduct=((windForce_x*(windX1/magnitude1))+(windForce_y*(windY1/magnitude1))+(windForce_z*(windZ1/magnitude1)));




float windCrossProductXY3=(((particle5Position_y*particle6Position_z) - (particle5Position_z*particle6Position_y))- ((particle5Position_x*particle6Position_z)-(particle5Position_z*particle6Position_x))+((particle5Position_x*particle6Position_y)-(particle5Position_y*particle6Position_x)));

float product3_x=(particle5Position_y*particle6Position_z)-(particle5Position_z*particle6Position_y);
float product3_y=(particle5Position_x*particle6Position_z)-(particle5Position_z*particle6Position_x);
float product3_z= (particle5Position_x*particle6Position_y)- (particle5Position_y*particle6Position_x);


float windCrossProductYZ3=(((product3_x*particle18Position_z)-(product3_z*particle18Position_y))- ((product3_x*particle18Position_z)-(product3_z*particle18Position_z)) + ((product3_x*particle18Position_y)-(product3_y*particle18Position_x)));

float windX3=((product3_x*particle18Position_z)-(product3_z*particle18Position_y));
float windY3=((product3_x*particle18Position_z)-(product3_z*particle18Position_z));
float windZ3=((product3_x*particle18Position_y)-(product3_y*particle18Position_x));
float magnitude3=sqrt( (windX3*windX3)+(windY3*windY3)+(windZ3*windZ3));

float windProduct2=((windForce_x*(windX3/magnitude3))+(windForce_y*(windY3/magnitude3))+(windForce_z*(windZ3/magnitude3)));






float windCrossProductXY1=(((3.0*particle4Position_z) - (0.0*particle4Position_y))- ((-3.8*particle4Position_z)-(0.0*particle4Position_x))+((-3.8*particle4Position_y)-(3.0*particle4Position_x)));

float product2_x=(3.0*particle4Position_z)-(0.0*particle4Position_y);
float product2_y=(-3.8*particle4Position_z)-(0.0*particle4Position_x);
float product2_z= (-3.8*particle4Position_y)- (3.0*particle4Position_x);


float windCrossProductYZ1=(((product2_x*particle16Position_z)-(product2_z*particle16Position_y))- ((product2_x*particle16Position_z)-(product2_z*particle16Position_z)) + ((product2_x*particle16Position_y)-(product2_y*particle16Position_x)));

float windX2=((product2_x*particle16Position_z)-(product2_z*particle16Position_y));
float windY2=((product2_x*particle16Position_z)-(product2_z*particle16Position_z));
float windZ2=((product2_x*particle16Position_y)-(product2_y*particle16Position_x));
float magnitude2=sqrt( (windX2*windX2)+(windY2*windY2)+(windZ2*windZ2));

float windProduct=((windForce_x*(windX2/magnitude2))+(windForce_y*(windY2/magnitude2))+(windForce_z*(windZ2/magnitude2)));




float windCrossProductXY4=(((particle6Position_y*particle7Position_z) - (particle6Position_z*particle7Position_y))- ((particle6Position_x*particle7Position_z)-(particle6Position_z*particle7Position_x))+((particle6Position_x*particle7Position_y)-(particle6Position_y*particle7Position_x)));

float product4_x=(particle6Position_y*particle7Position_z)-(particle6Position_z*particle7Position_y);
float product4_y=(particle6Position_x*particle7Position_z)-(particle6Position_z*particle7Position_x);
float product4_z= (particle6Position_x*particle7Position_y)- (particle6Position_y*particle7Position_x);


float windCrossProductYZ4=(((product4_x*particle19Position_z)-(product4_z*particle19Position_y))- ((product4_x*particle19Position_z)-(product4_z*particle19Position_z)) + ((product4_x*particle19Position_y)-(product4_y*particle19Position_x)));

float windX4=((product4_x*particle19Position_z)-(product4_z*particle19Position_y));
float windY4=((product4_x*particle19Position_z)-(product4_z*particle19Position_z));
float windZ4=((product4_x*particle19Position_y)-(product4_y*particle19Position_x));
float magnitude4=sqrt( (windX4*windX4)+(windY4*windY4)+(windZ4*windZ4));

float windProduct3=((windForce_x*(windX4/magnitude4))+(windForce_y*(windY4/magnitude4))+(windForce_z*(windZ4/magnitude4)));



float windCrossProductXY5=(((particle7Position_y*particle8Position_z) - (particle7Position_z*particle8Position_y))- ((particle7Position_x*particle8Position_z)-(particle7Position_z*particle8Position_x))+((particle7Position_x*particle8Position_y)-(particle7Position_y*particle8Position_x)));

float product5_x=(particle7Position_y*particle8Position_z)-(particle7Position_z*particle8Position_y);
float product5_y=(particle7Position_x*particle8Position_z)-(particle7Position_z*particle8Position_x);
float product5_z= (particle7Position_x*particle8Position_y)- (particle7Position_y*particle8Position_x);


float windCrossProductYZ5=(((product5_x*particle20Position_z)-(product5_z*particle20Position_y))- ((product5_x*particle20Position_z)-(product5_z*particle20Position_z)) + ((product5_x*particle20Position_y)-(product5_y*particle20Position_x)));

float windX5=((product5_x*particle20Position_z)-(product5_z*particle20Position_y));
float windY5=((product5_x*particle20Position_z)-(product5_z*particle20Position_z));
float windZ5=((product5_x*particle20Position_y)-(product5_y*particle20Position_x));
float magnitude5=sqrt( (windX5*windX5)+(windY5*windY5)+(windZ5*windZ5));

float windProduct4=((windForce_x*(windX5/magnitude5))+(windForce_y*(windY5/magnitude5))+(windForce_z*(windZ5/magnitude5)));



float windCrossProductXY31=(((particle15Position_y*particle27Position_z) - (particle15Position_z*particle27Position_y))- ((particle15Position_x*particle27Position_z)-(particle15Position_z*particle27Position_x))+((particle15Position_x*particle27Position_y)-(particle15Position_y*particle27Position_x)));

float product31_x=(particle15Position_y*particle27Position_z)-(particle15Position_z*particle27Position_y);
float product31_y=(particle15Position_x*particle27Position_z)-(particle15Position_z*particle27Position_x);
float product31_z= (particle15Position_x*particle27Position_y)- (particle15Position_y*particle27Position_x);

float windCrossProductYZ31=(((product31_x*particle28Position_z)-(product31_z*particle28Position_y))- ((product31_x*particle28Position_z)-(product31_z*particle28Position_z)) + ((product31_x*particle28Position_y)-(product31_y*particle28Position_x)));

float windX31=((product31_x*particle28Position_z)-(product31_z*particle28Position_y));
float windY31=((product31_x*particle28Position_z)-(product31_z*particle28Position_z));
float windZ31=((product31_x*particle28Position_y)-(product31_y*particle28Position_x));
float magnitude31=sqrt( (windX31*windX31)+(windY31*windY31)+(windZ31*windZ31));

float windProduct31=((windForce_x*(windX31/magnitude31))+(windForce_y*(windY31/magnitude31))+(windForce_z*(windZ31/magnitude31)));

float windCrossProductXY30=(((particle9Position_y*particle21Position_z) - (particle9Position_z*particle21Position_y))- ((particle9Position_x*particle21Position_z)-(particle9Position_z*particle21Position_x))+((particle9Position_x*particle21Position_y)-(particle9Position_y*particle21Position_x)));

float product30_x=(particle9Position_y*particle21Position_z)-(particle9Position_z*particle21Position_y);
float product30_y=(particle9Position_x*particle21Position_z)-(particle9Position_z*particle21Position_x);
float product30_z= (particle9Position_x*particle21Position_y)- (particle9Position_y*particle21Position_x);

float windCrossProductYZ30=(((product30_x*particle22Position_z)-(product30_z*particle22Position_y))- ((product30_x*particle22Position_z)-(product30_z*particle22Position_z)) + ((product30_x*particle22Position_y)-(product30_y*particle22Position_x)));

float windX30=((product30_x*particle22Position_z)-(product30_z*particle22Position_y));
float windY30=((product30_x*particle22Position_z)-(product30_z*particle22Position_z));
float windZ30=((product30_x*particle22Position_y)-(product30_y*particle22Position_x));
float magnitude30=sqrt( (windX30*windX30)+(windY30*windY30)+(windZ30*windZ30));

float windProduct30=((windForce_x*(windX5/magnitude5))+(windForce_y*(windY5/magnitude5))+(windForce_z*(windZ5/magnitude5)));



float windCrossProductXY9=(((3.0*particle13Position_z) - (0.0*particle13Position_y))- ((-5.8*particle13Position_z)-(0.0*particle13Position_x))+((-5.8*particle13Position_y)-(3.0*particle13Position_x)));

float product7_x=(3.0*particle13Position_z)-(0.0*particle13Position_y);
float product7_y=(-5.8*particle13Position_z)-(0.0*particle13Position_x);
float product7_z= (-5.8*particle13Position_y)- (3.0*particle13Position_x);


float windCrossProductYZ9=(((product7_x*particle14Position_z)-(product7_z*particle14Position_y))- ((product7_x*particle14Position_z)-(product7_z*particle14Position_z)) + ((product7_x*particle14Position_y)-(product7_y*particle14Position_x)));

float windX9=((product7_x*particle14Position_z)-(product7_z*particle14Position_y));
float windY9=((product7_x*particle14Position_z)-(product7_z*particle14Position_z));
float windZ9=((product7_x*particle14Position_y)-(product7_y*particle14Position_x));
float magnitude9=sqrt( (windX9*windX9)+(windY9*windY9)+(windZ9*windZ9));

float windProduct6=((windForce_x*(windX9/magnitude9))+(windForce_y*(windY9/magnitude9))+(windForce_z*(windZ9/magnitude9)));

float windCrossProductXY10=(((3.0*particle14Position_z) - (0.0*particle14Position_y))- ((-4.8*particle14Position_z)-(0.0*particle14Position_x))+((-4.8*particle14Position_y)-(3.0*particle14Position_x)));

float product10_x=(3.0*particle14Position_z)-(0.0*particle14Position_y);
float product10_y=(-4.8*particle14Position_z)-(0.0*particle14Position_x);
float product10_z= (-4.8*particle14Position_y)- (3.0*particle14Position_x);


float windCrossProductYZ10=(((product10_x*particle15Position_z)-(product10_z*particle15Position_y))- ((product10_x*particle15Position_z)-(product10_z*particle15Position_z)) + ((product10_x*particle15Position_y)-(product10_y*particle15Position_x)));

float windX10=((product10_x*particle15Position_z)-(product10_z*particle15Position_y));
float windY10=((product10_x*particle15Position_z)-(product10_z*particle15Position_z));
float windZ10=((product10_x*particle15Position_y)-(product10_y*particle15Position_x));
float magnitude10=sqrt( (windX10*windX10)+(windY10*windY10)+(windZ10*windZ10));

float windProduct7=((windForce_x*(windX10/magnitude10))+(windForce_y*(windY10/magnitude10))+(windForce_z*(windZ10/magnitude10)));


float windCrossProductXY11=(((3.0*particle22Position_z) - (0.0*particle22Position_y))- ((3.2*particle22Position_z)-(0.0*particle22Position_x))+((3.2*particle22Position_y)-(3.0*particle22Position_x)));

float product11_x=(3.0*particle22Position_z)-(0.0*particle22Position_y);
float product11_y=(3.2*particle22Position_z)-(0.0*particle22Position_x);
float product11_z= (3.2*particle22Position_y)- (3.0*particle22Position_x);


float windCrossProductYZ11=(((product11_x*particle23Position_z)-(product11_z*particle23Position_y))- ((product11_x*particle23Position_z)-(product11_z*particle23Position_z)) + ((product11_x*particle23Position_y)-(product11_y*particle23Position_x)));

float windX11=((product11_x*particle23Position_z)-(product11_z*particle23Position_y));
float windY11=((product11_x*particle23Position_z)-(product11_z*particle23Position_z));
float windZ11=((product11_x*particle23Position_y)-(product11_y*particle23Position_x));
float magnitude11=sqrt( (windX11*windX11)+(windY11*windY11)+(windZ11*windZ11));

float windProduct9=((windForce_x*(windX11/magnitude11))+(windForce_y*(windY11/magnitude11))+(windForce_z*(windZ11/magnitude11)));



float windCrossProductXY12=(((particle13Position_y*particle25Position_z) - (particle13Position_z*particle25Position_y))- ((particle13Position_x*particle25Position_z)-(particle13Position_z*particle25Position_x))+((particle13Position_x*particle25Position_y)-(particle13Position_y*particle25Position_x)));

float product12_x=(particle13Position_y*particle25Position_z)-(particle13Position_z*particle25Position_y);
float product12_y=(particle13Position_x*particle25Position_z)-(particle13Position_z*particle25Position_x);
float product12_z= (particle13Position_x*particle25Position_y)- (particle13Position_y*particle25Position_x);


float windCrossProductYZ12=(((product12_x*particle26Position_z)-(product12_z*particle26Position_y))- ((product12_x*particle26Position_z)-(product12_z*particle26Position_z)) + ((product12_x*particle26Position_y)-(product12_y*particle26Position_x)));

float windX12=((product12_x*particle26Position_z)-(product12_z*particle26Position_y));
float windY12=((product12_x*particle26Position_z)-(product12_z*particle26Position_z));
float windZ12=((product12_x*particle26Position_y)-(product12_y*particle26Position_x));
float magnitude12=sqrt( (windX12*windX12)+(windY12*windY12)+(windZ12*windZ12));

float windProduct12=((windForce_x*(windX12/magnitude12))+(windForce_y*(windY12/magnitude12))+(windForce_z*(windZ12/magnitude12)));



float windCrossProductXY13=(((particle14Position_y*particle26Position_z) - (particle14Position_z*particle26Position_y))- ((particle14Position_x*particle26Position_z)-(particle14Position_z*particle26Position_x))+((particle14Position_x*particle26Position_y)-(particle14Position_y*particle26Position_x)));

float product13_x=(particle14Position_y*particle26Position_z)-(particle14Position_z*particle26Position_y);
float product13_y=(particle14Position_x*particle26Position_z)-(particle14Position_z*particle26Position_x);
float product13_z= (particle14Position_x*particle26Position_y)- (particle14Position_y*particle26Position_x);


float windCrossProductYZ13=(((product13_x*particle27Position_z)-(product13_z*particle27Position_y))- ((product13_x*particle27Position_z)-(product13_z*particle27Position_z)) + ((product13_x*particle27Position_y)-(product13_y*particle27Position_x)));

float windX13=((product13_x*particle27Position_z)-(product13_z*particle27Position_y));
float windY13=((product13_x*particle27Position_z)-(product13_z*particle27Position_z));
float windZ13=((product13_x*particle27Position_y)-(product13_y*particle27Position_x));
float magnitude13=sqrt( (windX13*windX13)+(windY13*windY13)+(windZ13*windZ13));

float windProduct13=((windForce_x*(windX13/magnitude13))+(windForce_y*(windY13/magnitude13))+(windForce_z*(windZ13/magnitude13)));




float windCrossProductXY33=(((particle29Position_y*particle41Position_z) - (particle29Position_z*particle41Position_y))- ((particle29Position_x*particle41Position_z)-(particle29Position_z*particle41Position_x))+((particle29Position_x*particle41Position_y)-(particle29Position_y*particle41Position_x)));

float product33_x=(particle29Position_y*particle41Position_z)-(particle29Position_z*particle41Position_y);
float product33_y=(particle29Position_x*particle41Position_z)-(particle29Position_z*particle41Position_x);
float product33_z= (particle29Position_x*particle41Position_y)- (particle29Position_y*particle41Position_x);



float windCrossProductYZ33=(((product33_x*particle42Position_z)-(product33_z*particle42Position_y))- ((product33_x*particle42Position_z)-(product33_z*particle42Position_z)) + ((product33_x*particle42Position_y)-(product33_y*particle42Position_x)));

float windX33=((product33_x*particle42Position_z)-(product33_z*particle42Position_y));
float windY33=((product33_x*particle42Position_z)-(product33_z*particle42Position_z));
float windZ33=((product33_x*particle42Position_y)-(product33_y*particle42Position_x));
float magnitude33=sqrt( (windX33*windX33)+(windY33*windY33)+(windZ13*windZ33));

float windProduct33=((windForce_x*(windX33/magnitude33))+(windForce_y*(windY33/magnitude33))+(windForce_z*(windZ33/magnitude33)));


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();//load identity matrix

    glTranslatef(0.0f,0.0f,-4.0f);//move forward 4 units
  glColor3f(0.0f,0.0f,1.0f); //blue color

glPushMatrix();
glTranslatef(xsphere, ysphere, front);
glColor3f(1.0, 1.0,0.0);
glutSolidSphere(spherex, 50 ,50);
glPopMatrix();
if(front<=3.0f&&end==0)
{
 front=front+0.01;
 if(front>=3.0f)
 {
     end=1;
 }

}
 else if(front>=-3.0f&&end==1)
{
front=front-0.01;
if(front<=-3.0)
{
    end=0;
}

}

  initial();











  float topFourthFirstParticleMagnitude=sqrt((-2.8+1.8)*(-2.8+1.8) +(particle1Position_y-een)*(particle1Position_y-een)+0);
float   topFourthSecondParticleMagnitude=sqrt((-2.8+3.8)*(-2.8+3.8) + (ccn-ddn)*(ccn-ddn)+0);
float   topFourthThirdParticleMagnitude=sqrt((-2.8+2.8)*(-2.8+2.8) +(ddn-qqn)*(ddn-qqn)+0);
float  topFourthFourthParticleMagnitude=sqrt((-2.8+3.8)*(-2.8+3.8) + (ddn-ppn)*(ddn-ppn)+0);
float  topFourthFifthParticleMagnitude=sqrt((-2.8+3.8)*(-2.8+3.8) + (ddn-rrn)*(ddn-rrn)+0);

float secondTopFirstSecondParticleMagnitude=sqrt((-3.8+3.8)*(-3.8+3.8) +(particle4Position_y-particle13Position_y)*(particle4Position_y-particle13Position_y)+0);
float   secondTopSecondParticleMagnitude=sqrt((-3.8+3.8)*(-3.8+3.8) + (particle13Position_y-particle25Position_y)*(particle13Position_y-particle25Position_y)+0);
float    secondTopFourthFourthParticleMagnitude=sqrt((-3.8+2.8)*(-3.8+2.8) + (particle13Position_y-particle13Position_y)*(particle13Position_y-particle13Position_y)+0);
float    secondTopFifthFifthParticleMagnitude=sqrt((-3.8+4.8)*(-3.8+4.8) + (particle13Position_y-particle13Position_y)*(particle13Position_y-particle13Position_y)+0);

float  secondTopSixthParticleMagnitude=sqrt((-3.8+4.8)*(-3.8+4.8) +(particle13Position_y-particle1Position_y)*(particle13Position_y-particle25Position_y)+0);
float   secondTopFourthSecondParticleMagnitude=sqrt((-3.8+2.8)*(-3.8+2.8) + (particle13Position_y-particle1Position_y)*(particle13Position_y-particle25Position_y)+0);
float   secondTopFourthThirdParticleMagnitude=sqrt((-3.8+4.8)*(-3.8+4.8) +(particle13Position_y-particle25Position_y)*(particle13Position_y-particle25Position_y)+0);
float  secondTopFourthSixthParticleMagnitude=sqrt((-3.8+2.8)*(-3.8+2.8) + (particle13Position_y-particle25Position_y)*(particle13Position_y-particle25Position_y)+0);




int verticalLineInitialForth=1.0;
int horizontalLineInitialForth=1.0;
int diagnolLineInitialForth=1.414;

gravityForce=mass*gravity;


float forceIntfourthFirstParticle=K*(topFourthFirstParticleMagnitude-horizontalLineInitialForth* (((-3.8+3.8)/topFourthFirstParticleMagnitude)+(particle4Position_y-een)/topFourthFirstParticleMagnitude+0));
float forceIntfourthSecondParticle=K*(topFourthSecondParticleMagnitude-horizontalLineInitialForth* (((-2.8+3.8)/topFourthSecondParticleMagnitude)+(ccn-ddn)/topFourthSecondParticleMagnitude+0));
float forceIntfourthThirdParticle=K*(topFourthThirdParticleMagnitude-verticalLineInitialForth* (((-2.8+2.8)/topFourthThirdParticleMagnitude)+(ddn-qqn)/topFourthThirdParticleMagnitude+0));
float forceIntfourthFourthParticle=K*(topFourthFourthParticleMagnitude-diagnolLineInitialForth* (((-2.8+3.8)/topFourthFourthParticleMagnitude)+(ddn-ppn)/topFourthFourthParticleMagnitude+0));
float forceIntfourthFifthParticle=K*(topFourthFifthParticleMagnitude-diagnolLineInitialForth* (((-2.8+3.8)/topFourthFifthParticleMagnitude)+(ddn-rrn)/topFourthFifthParticleMagnitude+0));


float viscousDamping=-C*firstParticleVelocity_y-(K-2);
float viscousForce=-C*(unitNormal*(uFluid-firstParticleVelocity_y))*unitNormal;



float firstParticleTotalInternalForce=forceIntfourthFirstParticle+forceIntfourthSecondParticle+forceIntfourthThirdParticle+forceIntfourthFourthParticle+forceIntfourthFifthParticle;




float totalForceOnFourthParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+dotProduct;
float totalForceOnFourthParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+dotProduct;
float totalForceOnFourthParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+dotProduct;


float totalForceOnsixteenthParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct;
float totalForceOnsixteenthParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct;
float totalForceOnsixteenthParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct;


 float totalForceOnsixthParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct2;
 float totalForceOnsixthParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct2;
 float totalForceOnsixthParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct2;

 float totalForceOneighteenthParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct2;
 float totalForceOneighteenthParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct2;
 float totalForceOneighteenthParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct2;

float totalForceOnfifthParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+dotProduct;
float totalForceOnfifthParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+dotProduct;
float totalForceOnfifthParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+dotProduct;



float totalForceOnSeventhParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct3;
float totalForceOnSeventhParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct3;
float totalForceOnSeventhParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct3;

float totalForceOnseventeenthParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+dotProduct;
float totalForceOnseventeenthParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+dotProduct;
float totalForceOnseventeenthParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+dotProduct;

float totalForceOnNineteenthParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct3;
float totalForceOnNineteenthParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct3;
float totalForceOnNineteenthParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct3;


float totalForceOnEighthParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct4;
float totalForceOnEighthParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct4;
float totalForceOnEighthParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct4;



float totalForceOnNinthParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct30;
float totalForceOnNinthParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct30;
float totalForceOnNinthParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct30;


float totalForceOntwentyParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct4;
float totalForceOntwentyParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct4;
float totalForceOntwentyParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct4;




float totalForceOnthirteenParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct6;
float totalForceOnthirteenParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct6;
float totalForceOnthirteenParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct6;

float totalForceOnfourteenParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct6;
float totalForceOnfourteenParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct6;
float totalForceOnfourteenParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct6;


float totalForceOnfifteenParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct7;
float totalForceOnfifteenParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct7;
float totalForceOnfifteenParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct7;

float totalForceOntwentyOneParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct30;
float totalForceOntwentyOneParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct30;
float totalForceOntwentyOneParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct30;

float totalForceOnTwentyTwoParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct30;
float totalForceOnTwentyTwoParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct30;
float totalForceOnTwentyTwoParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct30;


float totalForceOnTwentyThreeParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct30;
float totalForceOnTwentyThreeParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct30;
float totalForceOnTwentyThreeParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct30;


float totalForceOnTwentyFourParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct30;
float totalForceOnTwentyFourParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct30;
float totalForceOnTwentyFourParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct30;

float totalForceOntwentyfifthParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct12;
float totalForceOntwentyfifthParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct12;
float totalForceOntwentyfifthParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct12;


float totalForceOntwentysixthParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct12;
float totalForceOntwentysixthParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct12;
float totalForceOntwentysixthParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct12;



float totalForceOntwentyseventhParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct13;
float totalForceOntwentyseventhParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct13;
float totalForceOntwentyseventhParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct13;




float totalForceOntwentyEightParticle_y=firstParticleTotalInternalForce+gravityForce+viscousDamping+viscousForce+windProduct31;
float totalForceOntwentyEightParticle_x=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct31;
float totalForceOntwentyEightParticle_z=firstParticleTotalInternalForce+viscousDamping+viscousForce+windProduct31;
float particlePosition_y=(particle4Position_y)+(TIME_DELTA*firstParticleVelocity_y);
float particlePosition_z=(particle4Position_z)+(TIME_DELTA*firstParticleVelocity_z);
float particlePosition_x=(particle4Position_x)+(TIME_DELTA*firstParticleVelocity_x);


 particle5Position_y=(particle5Position_y)+(TIME_DELTA*particle5Velocity_y);
 particle5Position_z=(particle5Position_z)+(TIME_DELTA*particle5Velocity_z);
 particle5Position_x=(particle5Position_x)+(TIME_DELTA*particle5Velocity_x);


 particle6Position_y=(particle6Position_y)+(TIME_DELTA*particle6Velocity_y);
 particle6Position_z=(particle6Position_z)+(TIME_DELTA*particle6Velocity_z);
 particle6Position_x=(particle6Position_x)+(TIME_DELTA*particle6Velocity_x);



 particle7Position_y=(particle7Position_y)+(TIME_DELTA*particle7Velocity_y);
 particle7Position_z=(particle7Position_z)+(TIME_DELTA*particle7Velocity_z);
 particle7Position_x=(particle7Position_x)+(TIME_DELTA*particle7Velocity_x);


 particle8Position_y=(particle8Position_y)+(TIME_DELTA*particle8Velocity_y);
 particle8Position_z=(particle8Position_z)+(TIME_DELTA*particle8Velocity_z);
 particle8Position_x=(particle8Position_x)+(TIME_DELTA*particle8Velocity_x);


 particle9Position_y=(particle9Position_y)+(TIME_DELTA*particle9Velocity_y);
 particle9Position_z=(particle9Position_z)+(TIME_DELTA*particle9Velocity_z);
 particle9Position_x=(particle9Position_x)+(TIME_DELTA*particle9Velocity_x);


 particle13Position_y=(particle13Position_y)+(TIME_DELTA*particle13Velocity_y);
 particle13Position_z=(particle13Position_z)+(TIME_DELTA*particle13Velocity_z);
 particle13Position_x=(particle13Position_x)+(TIME_DELTA*particle13Velocity_x);


 particle14Position_y=(particle14Position_y)+(TIME_DELTA*particle14Velocity_y);
 particle14Position_z=(particle14Position_z)+(TIME_DELTA*particle14Velocity_z);
 particle14Position_x=(particle14Position_x)+(TIME_DELTA*particle14Velocity_x);


 particle15Position_y=(particle15Position_y)+(TIME_DELTA*particle15Velocity_y);
 particle15Position_z=(particle15Position_z)+(TIME_DELTA*particle15Velocity_z);
 particle15Position_x=(particle15Position_x)+(TIME_DELTA*particle15Velocity_x);

 particle19Position_y=(particle19Position_y)+(TIME_DELTA*particle19Velocity_y);
 particle19Position_z=(particle19Position_z)+(TIME_DELTA*particle19Velocity_z);
 particle19Position_x=(particle19Position_x)+(TIME_DELTA*particle19Velocity_x);


 particle20Position_y=(particle20Position_y)+(TIME_DELTA*particle20Velocity_y);
 particle20Position_z=(particle20Position_z)+(TIME_DELTA*particle20Velocity_z);
 particle20Position_x=(particle20Position_x)+(TIME_DELTA*particle20Velocity_x);


 particle21Position_y=(particle21Position_y)+(TIME_DELTA*particle21Velocity_y);
 particle21Position_z=(particle21Position_z)+(TIME_DELTA*particle21Velocity_z);
 particle21Position_x=(particle21Position_x)+(TIME_DELTA*particle21Velocity_x);


 particle22Position_y=(particle22Position_y)+(TIME_DELTA*particle22Velocity_y);
 particle22Position_z=(particle22Position_z)+(TIME_DELTA*particle22Velocity_z);
 particle22Position_x=(particle22Position_x)+(TIME_DELTA*particle22Velocity_x);


 particle23Position_y=(particle23Position_y)+(TIME_DELTA*particle23Velocity_y);
 particle23Position_z=(particle23Position_z)+(TIME_DELTA*particle23Velocity_z);
 particle23Position_x=(particle23Position_x)+(TIME_DELTA*particle23Velocity_x);

 particle18Position_y=(particle18Position_y)+(TIME_DELTA*particle18Velocity_y);
 particle18Position_z=(particle18Position_z)+(TIME_DELTA*particle18Velocity_z);
 particle18Position_x=(particle18Position_x)+(TIME_DELTA*particle18Velocity_x);

 particle17Position_y=(particle17Position_y)+(TIME_DELTA*particle17Velocity_y);
 particle17Position_z=(particle17Position_z)+(TIME_DELTA*particle17Velocity_z);
 particle17Position_x=(particle17Position_x)+(TIME_DELTA*particle17Velocity_x);

  particle16Position_y=(particle16Position_y)+(TIME_DELTA*particle16Velocity_y);
 particle16Position_z=(particle16Position_z)+(TIME_DELTA*particle16Velocity_z);
 particle16Position_x=(particle16Position_x)+(TIME_DELTA*particle16Velocity_x);


 particle24Position_y=(particle24Position_y)+(TIME_DELTA*particle24Velocity_y);
 particle24Position_z=(particle24Position_z)+(TIME_DELTA*particle24Velocity_z);
 particle24Position_x=(particle24Position_x)+(TIME_DELTA*particle24Velocity_x);


 particle25Position_y=(particle25Position_y)+(TIME_DELTA*particle25Velocity_y);
 particle25Position_z=(particle25Position_z)+(TIME_DELTA*particle25Velocity_z);
 particle25Position_x=(particle25Position_x)+(TIME_DELTA*particle25Velocity_x);


 particle27Position_y=(particle27Position_y)+(TIME_DELTA*particle27Velocity_y);
 particle27Position_z=(particle27Position_z)+(TIME_DELTA*particle27Velocity_z);
 particle27Position_x=(particle27Position_x)+(TIME_DELTA*particle27Velocity_x);


 particle28Position_y=(particle28Position_y)+(TIME_DELTA*particle28Velocity_y);
 particle28Position_z=(particle28Position_z)+(TIME_DELTA*particle28Velocity_z);
 particle28Position_x=(particle28Position_x)+(TIME_DELTA*particle28Velocity_x);

 particle26Position_y=(particle26Position_y)+(TIME_DELTA*particle26Velocity_y);
 particle26Position_z=(particle26Position_z)+(TIME_DELTA*particle26Velocity_z);
 particle26Position_x=(particle26Position_x)+(TIME_DELTA*particle26Velocity_x);






particle4Position_x=particlePosition_x;
particle4Position_y=particlePosition_y;
particle4Position_z=particlePosition_z;

particle29Position_y=particle28Position_y;
particle30Position_y=particle29Position_y;
particle31Position_y=particle30Position_y;
particle32Position_y=particle31Position_y;
particle33Position_y=particle32Position_y;
particle34Position_y=particle33Position_y;
particle35Position_y=particle34Position_y;
particle36Position_y=particle35Position_y;
particle37Position_y=particle36Position_y-1;
particle38Position_y=particle37Position_y;
particle39Position_y=particle38Position_y;
particle40Position_y=particle39Position_y;
particle41Position_y=particle40Position_y;
particle42Position_y=particle41Position_y;
particle43Position_y=particle42Position_y;
particle44Position_y=particle43Position_y;
particle45Position_y=particle44Position_y;
particle46Position_y=particle45Position_y;
particle47Position_y=particle46Position_y;
particle48Position_y=particle47Position_y;
particle49Position_y=particle48Position_y-1;
particle50Position_y=particle49Position_y;
particle51Position_y=particle50Position_y;
particle52Position_y=particle51Position_y;
particle53Position_y=particle52Position_y;



particle54Position_y=particle53Position_y;
particle55Position_y=particle54Position_y;
particle56Position_y=particle55Position_y;
particle57Position_y=particle56Position_y;
particle58Position_y=particle57Position_y;

particle59Position_y=particle58Position_y;
particle60Position_y=particle59Position_y;


float particleAcceleration_x=(1/mass)*totalForceOnFourthParticle_x*time;
 firstParticleAcceleration_x=particleAcceleration_x;
float particleVelocity_x=firstParticleVelocity_x+ TIME_DELTA*firstParticleAcceleration_x;
firstParticleVelocity_x=particleVelocity_x;



float particleAcceleration_y=(1/mass)*totalForceOnFourthParticle_y*time;
 firstParticleAcceleration_y=particleAcceleration_y;
float particleVelocity_y=firstParticleVelocity_y+ TIME_DELTA*firstParticleAcceleration_y;
firstParticleVelocity_y=particleVelocity_y;


float particleAcceleration_z=(1/mass)*totalForceOnFourthParticle_z*time;
 firstParticleAcceleration_z=particleAcceleration_z;
float particleVelocity_z=firstParticleVelocity_z+ TIME_DELTA*firstParticleAcceleration_z;
firstParticleVelocity_z=particleVelocity_z;



particle5Acceleration_x=(1/mass)*totalForceOnfifthParticle_x*time;

particle5Velocity_x=particle5Velocity_x+ TIME_DELTA*particle5Acceleration_x;




 particle5Acceleration_y=(1/mass)*totalForceOnfifthParticle_y*time;
 particle5Velocity_y=particle5Velocity_y+ TIME_DELTA*particle5Acceleration_y;


 particle5Acceleration_z=(1/mass)*totalForceOnfifthParticle_z*time;
 particle5Velocity_z=particle5Velocity_z+ TIME_DELTA*particle5Acceleration_z;



particle17Acceleration_x=(1/mass)*totalForceOnseventeenthParticle_x*time;

particle17Velocity_x=particle17Velocity_x+ TIME_DELTA*particle17Acceleration_x;




 particle17Acceleration_y=(1/mass)*totalForceOnseventeenthParticle_y*time;
 particle17Velocity_y=particle17Velocity_y+ TIME_DELTA*particle17Acceleration_y;


 particle17Acceleration_z=(1/mass)*totalForceOnseventeenthParticle_z*time;
 particle17Velocity_z=particle17Velocity_z+ TIME_DELTA*particle17Acceleration_z;



particle17Acceleration_x=(1/mass)*totalForceOnseventeenthParticle_x*time;

particle17Velocity_x=particle17Velocity_x+ TIME_DELTA*particle17Acceleration_x;



 particle16Acceleration_x=(1/mass)*totalForceOnsixteenthParticle_x*time;
 particle16Velocity_x=particle16Velocity_x+ TIME_DELTA*particle16Acceleration_x;


 particle16Acceleration_y=(1/mass)*totalForceOnsixteenthParticle_y*time;
 particle16Velocity_y=particle16Velocity_y+ TIME_DELTA*particle16Acceleration_y;


 particle16Acceleration_z=(1/mass)*totalForceOnsixteenthParticle_z*time;
 particle16Velocity_z=particle16Velocity_z+ TIME_DELTA*particle16Acceleration_z;


 particle14Acceleration_x=(1/mass)*totalForceOnfourteenParticle_x*time;
 particle14Velocity_x=particle14Velocity_x+ TIME_DELTA*particle14Acceleration_x;


 particle14Acceleration_y=(1/mass)*totalForceOnfourteenParticle_y*time;
 particle14Velocity_y=particle14Velocity_y+ TIME_DELTA*particle14Acceleration_y;


 particle14Acceleration_z=(1/mass)*totalForceOnfourteenParticle_z*time;
 particle14Velocity_z=particle14Velocity_z+ TIME_DELTA*particle14Acceleration_z;


 particle13Acceleration_x=(1/mass)*totalForceOnthirteenParticle_x*time;
 particle13Velocity_x=particle13Velocity_x+ TIME_DELTA*particle13Acceleration_x;


 particle13Acceleration_y=(1/mass)*totalForceOnthirteenParticle_y*time;
 particle13Velocity_y=particle13Velocity_y+ TIME_DELTA*particle13Acceleration_y;


 particle13Acceleration_z=(1/mass)*totalForceOnthirteenParticle_z*time;
 particle13Velocity_z=particle13Velocity_z+ TIME_DELTA*particle13Acceleration_z;





 particle6Acceleration_x=(1/mass)*totalForceOnsixthParticle_x*time;
 particle6Velocity_x=particle6Velocity_x+ TIME_DELTA*particle6Acceleration_x;


 particle6Acceleration_y=(1/mass)*totalForceOnsixthParticle_y*time;
 particle6Velocity_y=particle6Velocity_y+ TIME_DELTA*particle6Acceleration_y;


 particle6Acceleration_z=(1/mass)*totalForceOnsixthParticle_z*time;
 particle6Velocity_z=particle6Velocity_z+ TIME_DELTA*particle6Acceleration_z;


 particle18Acceleration_x=(1/mass)*totalForceOneighteenthParticle_x*time;
 particle18Velocity_x=particle18Velocity_x+ TIME_DELTA*particle18Acceleration_x;


 particle18Acceleration_y=(1/mass)*totalForceOneighteenthParticle_y*time;
 particle18Velocity_y=particle18Velocity_y+ TIME_DELTA*particle18Acceleration_y;


 particle18Acceleration_z=(1/mass)*totalForceOneighteenthParticle_z*time;
 particle18Velocity_z=particle18Velocity_z+ TIME_DELTA*particle18Acceleration_z;



 particle8Acceleration_x=(1/mass)*totalForceOnEighthParticle_x*time;
 particle8Velocity_x=particle8Velocity_x+ TIME_DELTA*particle8Acceleration_x;


 particle8Acceleration_y=(1/mass)*totalForceOnEighthParticle_y*time;
 particle8Velocity_y=particle8Velocity_y+ TIME_DELTA*particle8Acceleration_y;


 particle8Acceleration_z=(1/mass)*totalForceOnEighthParticle_z*time;
 particle8Velocity_z=particle8Velocity_z+ TIME_DELTA*particle8Acceleration_z;


 particle19Acceleration_x=(1/mass)*totalForceOnNineteenthParticle_x*time;
 particle19Velocity_x=particle19Velocity_x+ TIME_DELTA*particle19Acceleration_x;


 particle19Acceleration_y=(1/mass)*totalForceOnNineteenthParticle_y*time;
 particle19Velocity_y=particle19Velocity_y+ TIME_DELTA*particle19Acceleration_y;


 particle19Acceleration_z=(1/mass)*totalForceOnNineteenthParticle_z*time;
 particle19Velocity_z=particle19Velocity_z+ TIME_DELTA*particle19Acceleration_z;



 particle20Acceleration_x=(1/mass)*totalForceOntwentyParticle_x*time;
 particle20Velocity_x=particle20Velocity_x+ TIME_DELTA*particle20Acceleration_x;


 particle20Acceleration_y=(1/mass)*totalForceOntwentyParticle_y*time;
 particle20Velocity_y=particle20Velocity_y+ TIME_DELTA*particle20Acceleration_y;


 particle20Acceleration_z=(1/mass)*totalForceOntwentyParticle_z*time;
 particle20Velocity_z=particle20Velocity_z+ TIME_DELTA*particle20Acceleration_z;



 particle7Acceleration_x=(1/mass)*totalForceOnSeventhParticle_x*time;
 particle7Velocity_x=particle7Velocity_x+ TIME_DELTA*particle7Acceleration_x;


 particle7Acceleration_y=(1/mass)*totalForceOnSeventhParticle_y*time;
 particle7Velocity_y=particle7Velocity_y+ TIME_DELTA*particle7Acceleration_y;


 particle7Acceleration_z=(1/mass)*totalForceOnSeventhParticle_z*time;
 particle7Velocity_z=particle7Velocity_z+ TIME_DELTA*particle7Acceleration_z;



 particle9Acceleration_x=(1/mass)*totalForceOnNinthParticle_x*time;
 particle9Velocity_x=particle9Velocity_x+ TIME_DELTA*particle9Acceleration_x;


 particle9Acceleration_y=(1/mass)*totalForceOnNinthParticle_y*time;
 particle9Velocity_y=particle9Velocity_y+ TIME_DELTA*particle9Acceleration_y;


 particle9Acceleration_z=(1/mass)*totalForceOnNinthParticle_z*time;
 particle9Velocity_z=particle9Velocity_z+ TIME_DELTA*particle9Acceleration_z;

 particle21Acceleration_x=(1/mass)*totalForceOntwentyOneParticle_x*time;
 particle21Velocity_x=particle21Velocity_x+ TIME_DELTA*particle21Acceleration_x;


 particle21Acceleration_y=(1/mass)*totalForceOntwentyOneParticle_y*time;
 particle21Velocity_y=particle21Velocity_y+ TIME_DELTA*particle21Acceleration_y;


 particle21Acceleration_z=(1/mass)*totalForceOntwentyOneParticle_z*time;
 particle21Velocity_z=particle21Velocity_z+ TIME_DELTA*particle21Acceleration_z;
 particle22Acceleration_x=(1/mass)*totalForceOnTwentyTwoParticle_x*time;
 particle22Velocity_x=particle22Velocity_x+ TIME_DELTA*particle22Acceleration_x;

particle22Acceleration_y=(1/mass)*totalForceOnTwentyTwoParticle_y*time;
 particle22Velocity_y=particle22Velocity_y+ TIME_DELTA*particle22Acceleration_y;

 particle22Acceleration_z=(1/mass)*totalForceOnTwentyTwoParticle_z*time;
 particle22Velocity_z=particle22Velocity_z+ TIME_DELTA*particle22Acceleration_z;

particle24Acceleration_x=(1/mass)*totalForceOnTwentyFourParticle_x*time;
 particle24Velocity_x=particle24Velocity_x+ TIME_DELTA*particle24Acceleration_x;

particle24Acceleration_y=(1/mass)*totalForceOnTwentyFourParticle_y*time;
 particle24Velocity_y=particle24Velocity_y+ TIME_DELTA*particle24Acceleration_y;

 particle24Acceleration_z=(1/mass)*totalForceOnTwentyFourParticle_z*time;
 particle24Velocity_z=particle24Velocity_z+ TIME_DELTA*particle24Acceleration_z;
 particle25Acceleration_x=(1/mass)*totalForceOntwentyfifthParticle_x*time;
 particle25Velocity_x=particle25Velocity_x+ TIME_DELTA*particle25Acceleration_x;
 particle25Acceleration_y=(1/mass)*totalForceOntwentyfifthParticle_y*time;
 particle25Velocity_y=particle25Velocity_y+ TIME_DELTA*particle25Acceleration_y;
 particle25Acceleration_z=(1/mass)*totalForceOntwentyfifthParticle_z*time;
 particle25Velocity_z=particle25Velocity_z+ TIME_DELTA*particle25Acceleration_z;


 particle26Acceleration_x=(1/mass)*totalForceOntwentysixthParticle_x*time;
 particle26Velocity_x=particle26Velocity_x+ TIME_DELTA*particle26Acceleration_x;


 particle26Acceleration_y=(1/mass)*totalForceOntwentysixthParticle_y*time;
 particle26Velocity_y=particle26Velocity_y+ TIME_DELTA*particle26Acceleration_y;


 particle26Acceleration_z=(1/mass)*totalForceOntwentysixthParticle_z*time;
 particle26Velocity_z=particle26Velocity_z+ TIME_DELTA*particle26Acceleration_z;


 particle27Acceleration_x=(1/mass)*totalForceOntwentyseventhParticle_x*time;
 particle27Velocity_x=particle27Velocity_x+ TIME_DELTA*particle27Acceleration_x;


 particle27Acceleration_y=(1/mass)*totalForceOntwentyseventhParticle_y*time;
 particle27Velocity_y=particle27Velocity_y+ TIME_DELTA*particle27Acceleration_y;


 particle27Acceleration_z=(1/mass)*totalForceOntwentyseventhParticle_z*time;
 particle27Velocity_z=particle27Velocity_z+ TIME_DELTA*particle27Acceleration_z;



 particle28Acceleration_x=(1/mass)*totalForceOntwentyEightParticle_x*time;
 particle28Velocity_x=particle28Velocity_x+ TIME_DELTA*particle28Acceleration_x;


 particle28Acceleration_y=(1/mass)*totalForceOntwentyEightParticle_y*time;
 particle28Velocity_y=particle28Velocity_y+ TIME_DELTA*particle28Acceleration_y;


 particle28Acceleration_z=(1/mass)*totalForceOntwentyEightParticle_z*time;
 particle28Velocity_z=particle28Velocity_z+ TIME_DELTA*particle28Acceleration_z;





particle15Acceleration_x=(1/mass)*totalForceOnfifteenParticle_x*time;
 particle15Velocity_x=particle15Velocity_x+ TIME_DELTA*particle15Acceleration_x;


 particle15Acceleration_y=(1/mass)*totalForceOnfifteenParticle_y*time;
 particle15Velocity_y=particle15Velocity_y+ TIME_DELTA*particle15Acceleration_y;


 particle15Acceleration_z=(1/mass)*totalForceOnfifteenParticle_z*time;
 particle15Velocity_z=particle15Velocity_z+ TIME_DELTA*particle15Acceleration_z;


particle23Acceleration_x=(1/mass)*totalForceOnTwentyThreeParticle_x*time;
 particle23Velocity_x=particle23Velocity_x+ TIME_DELTA*particle23Acceleration_x;


 particle23Acceleration_y=(1/mass)*totalForceOnTwentyThreeParticle_y*time;
 particle23Velocity_y=particle23Velocity_y+ TIME_DELTA*particle23Acceleration_y;


 particle23Acceleration_z=(1/mass)*totalForceOnTwentyThreeParticle_z*time;
 particle23Velocity_z=particle23Velocity_z+ TIME_DELTA*particle23Acceleration_z;

  glEnable (GL_LIGHTING);






if(time<10.000)
{
time=time+0.002;


  glutSwapBuffers();
  glutPostRedisplay();
}
}






void reshape (int w, int h)
{
  glViewport (0, 0, w, h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  if (h == 0)
  {
    gluPerspective (80, (float) w, 1.0, 5000.0);
  }
  else
  {
    gluPerspective (80, (float) w / (float) h, 1.0, 5000.0);
  }
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
}





void keyboard (unsigned char key, int x, int y)
{
  switch (key)
  {
    case 27:
      exit (0);
    break;
    case 32:
      pause = 1 - pause;
      break;
    default:
    break;
  }
}





void arrow_keys (int a_keys, int x, int y)
{
  switch(a_keys)
  {
    case GLUT_KEY_UP:
      glutFullScreen();
    break;
    case GLUT_KEY_DOWN:
      glutReshapeWindow (1280, 720 );
    break;
    default:
    break;
  }
}




















int main (int argc, char *argv[])
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize (2280, 720 );  //1280 720
  glutCreateWindow ("Cloth simulator");
  init ();
  glutDisplayFunc (display);
  glutReshapeFunc (reshape);
  glutKeyboardFunc (keyboard);
  glutSpecialFunc (arrow_keys);

  glutMainLoop ();
}



