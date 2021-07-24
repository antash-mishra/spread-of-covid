#define STB_IMAGE_IMPLEMENTATION
#include "texture.h"
#include<unistd.h>
#include <stdlib.h>
#include <GL/glut.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include <SOIL/SOIL.h>

#define PI 3.1416
using namespace std;
int submenu;
int line = 0;
float tx = 0.0;
float ty = 0.0;
//float var_boat = 0.0;
float var_man = 0.0;
float var_man2 = 0.0;
//float var_boat2 = 0.0;
float var_small_car = 0.0;
float var_car2 = 0.0;
int window = 0;
bool bool_car=true;
//bool bool_boat=false;
bool bool_man=false;
bool bool_man2 = false;
bool bus_stop=false;
bool bus_stop_end=false;
bool man_in = false;
bool man_out = false;
int infected = 0;
GLfloat man_face[][3]={{1.0,0.8,0.6},{1.0,0.0,0.0}};
//void boat_moving();
void texti();
void var_man_moving();
void small_car_moving();
void var_man2_moving();
void drawWheel();
void busstop();
void busstop_top();
void busstop_left();
void lamp();
void bus();
void Man2();
void bus_scal();
void bus_final();
//void river();
void textarea();
void render();
void drawDisk(double radius);
void crismas();
void display();
void building_scal();
void building2_abd_bottom();
void building3_scal();
void building2_translate();
void building_abd_traslate();
void building_abd();
void building2_abd();
void building_abd_scal();
void building_abd_traslate_again_bottom();
void first_window();
void second_window();
void third_window();
void fourth_window();
void grass();
void building();
GLvoid Tire(GLdouble y);
GLvoid tree(GLdouble x);
GLvoid window1(GLdouble x);
GLvoid window2(GLdouble y);
GLvoid window3(GLdouble w);
GLvoid window4(GLdouble v);
GLvoid window_bus(GLdouble x);
GLuint intro;


Tombstone tombstone(600, 497, "tombstone3.png");
Ground logo(665, 375, "bit_logo.png");
//Tombstone tombstone2(598, 354, "tomb.png");

//Ground ground(1024,1024, "grass.png");

void menufunc(int n) {
	switch(n) {
		case 1:
		window = 1;
			break;
		case 2: window = 4;
			break;

		case 3: exit(0);
	}
}

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {


	    //for day night

		case 'd':
		    glClearColor(0.8941,0.8549,0.7608,1.0);
			break;

		case 'n':
			 glClearColor(.04,.09,.02,0);
			break;

		case 'N':
		     glClearColor(.04,.09,.02,0);
			 break;
         case 'D':
              glClearColor(0.8941,0.8549,0.7608,1.0);
         break;




         // moving the  vodka man


         case 'R':
             bool_man=true;
              glutIdleFunc(var_man_moving);
              glutPostRedisplay();

         break;

          case 'r':
              bool_man=true;
              glutIdleFunc(var_man_moving);
              glutPostRedisplay();
         break;



         //stop the vodka man
         case 'S':
              bool_man=false;
              if(bool_car){
                 glutIdleFunc(small_car_moving);
                 glutPostRedisplay();
              }
              //else if(bool_boat){
                //    glutIdleFunc(boat_moving);
                  //  glutPostRedisplay();
              //  }
                else{
                    glutIdleFunc(NULL);
                    glutPostRedisplay();
                }
         break;

         case 's':
              bool_man=false;
              if(bool_car){
                 glutIdleFunc(small_car_moving);
                 glutPostRedisplay();
              }
              //else if(bool_boat){
                //    glutIdleFunc(boat_moving);
                  //  glutPostRedisplay();
                //}
             else{
                glutIdleFunc(NULL);
                glutPostRedisplay();
                }
         break;

         // moving the second  vodka man


         case 'M':
             bool_man2=true;
              glutIdleFunc(var_man2_moving);
              glutPostRedisplay();

         break;

          case 'm':
              bool_man2=true;
              glutIdleFunc(var_man2_moving);
              glutPostRedisplay();
         break;

         //stop the second vodka man
         case 'L':
              bool_man2=false;
              if(bool_car){
                 glutIdleFunc(small_car_moving);
                 glutPostRedisplay();
              }
              //else if(bool_boat){
              //      glutIdleFunc(boat_moving);
              //      glutPostRedisplay();
              //  }
                else{
                    glutIdleFunc(NULL);
                    glutPostRedisplay();
                }
         break;

         case 'l':
              bool_man2=false;
              if(bool_car){
                 glutIdleFunc(small_car_moving);
                 glutPostRedisplay();
              }
              //else if(bool_boat){
              //      glutIdleFunc(boat_moving);
              //      glutPostRedisplay();
              //  }
             else{
                glutIdleFunc(NULL);
                glutPostRedisplay();
                }
         break;




         //get in the car from bus stop
         case 'y':
             if(tx>=480 && tx<=650){
                man_in =true;
                glutPostRedisplay();
             }
             else if(tx<480 || tx>650){
                 man_in = false;
                glutPostRedisplay();
             }

         break;

          case 'Y':
             if(tx>=480 && tx<=650){
                man_in =true;
                glutPostRedisplay();
             }
             else if(tx<480 || tx>650){
                 man_in = false;
                glutPostRedisplay();
             }

         break;




         //out the girl in font of varsity

         case 'A':
             if(tx>=1330 && tx<=1650){
                man_out =true;
                glutPostRedisplay();
             }
             else if(tx<1330 || tx>1650){
                 man_out = false;
                glutPostRedisplay();
             }

         break;

          case 'a':
             if(tx>=1330 && tx<=1600){
                man_out =true;
                glutPostRedisplay();
             }
             else if(tx<1330 || tx>1600){
                 man_out = false;
                glutPostRedisplay();
             }

         break;
				 case 'x': if(var_man>=2.75 && var_man<=5.0){
											infected = 1;
											glutPostRedisplay();
				 					}
				 					else if(var_man<2.75 || var_man>5){
						 				infected = 0;
										glutPostRedisplay();
				 					}

		 							break;
				case 'X': if(tx>=0 && tx<=100){
										 infected = 1;
										 glutPostRedisplay();
								 }
								 else if(tx<400 || tx>500){
									 infected = 0;
									 glutPostRedisplay();
								 }

								 break;




	  default:
			break;
	}
}

void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:

				tx -=10;
				glutPostRedisplay();
				break;


		case GLUT_KEY_RIGHT:
				tx +=10;
				glutPostRedisplay();

				break;
	  default:
			break;
	}
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		line++;
		glutPostRedisplay();
	}
	else if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN){
		bool_car=false;
		if(bool_man)
				glutIdleFunc(var_man_moving);
		else
				glutIdleFunc(NULL);
		glutPostRedisplay();
	}
}

void render(){
	string story = "";
	glColor3ub(0,0,0);
	glRasterPos2f(20,150);
	if(line == 0 && window == 1)
	story = "Pushpa is eagerly waiting for the bus to arrive. She wants to tell her friends about the concert she visited.";
	else if(line == 1 && window == 1)
	story = "Aman, a classmate, walks to her on the bus stop. He exchanges greetings with her.";
	else if(line == 2 && window == 1)
	story = "She tells him about the concert she attended.";
	else if(line == 3 && window == 1)
	story ="Pushpa is not aware that she caught virus during the concert which was the cause of the cold she had. She thought of it as common cold.";
	else if(line == 4 && window == 1)
	story = "Unknowingly, Pushpa has now became a carrier or this virus. While her converstaion with Aman she gave him more than greetings,VIRUS!!";
	else if(line == 5 && window == 1)
	story = "The bus arrives and Pushpa hops on it enthusiastically and continues her journey towards her college";
	else if(line == 6 && window == 2)
	story = "She arrives at the college and meets her friends there.";
	else if(line == 7 && window == 2)
	story = "During this meet she passes the virus onto them too.";
	else if(line == 8 && window == 2)
	story = "After few days passed and Pushpa ignores the symptoms. Her health deteriorated exponentially.";
	else if(line == 9 && window == 3)
	story = "She dies after few days.";
	else if(line == 10 && window == 3)
	story = "Later, the news of a new lethal virus surfaced. The virus had spread worldwide and no cure was known for it.";
	else if(line >= 11 && window == 3)
	story = "Only way to prevention is to wear mask, sanitise your hands regularly and maintain social distancing.";
	for(int i = 0; i < story.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, story[i]);
	}
	if(line == 2){
		glColor3ub(255,0,0);
		glRasterPos2f(20, 70);
		string warning = "Note : They don't maintain social distancing";
		for(int i = 0; i<warning.length(); i++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, warning[i]);
		}
	}
}




//for second window boat
/*void boat_moving2(){
    if(var_car2<=2000){
         var_car2+=.08;
       glutPostRedisplay();
    }

    if(var_boat2<=1800){
       var_boat2+=.5;
       glutPostRedisplay();
    }


    glutPostRedisplay();
}*/

void car2_moving(/* arguments */) {
	/* code */
	if(var_car2<=2000){
			 var_car2+=.08;
	}
	glutPostRedisplay();
}


//car moving
void small_car_moving(){
    //check vodka man is running or not
     if(bool_man){
        var_man+=.005;
        glutPostRedisplay();
    }

    //check boat is running or not
    /*if(bool_boat){
        var_boat-=.35;
        glutPostRedisplay();
    }*/

    //check small car is running or not

    if(bool_car) {
    	var_small_car -= 0.7;
    	glutPostRedisplay();
    }
    else {
    glutPostRedisplay();
    }

}



//for vodka man moving
void var_man_moving(){
    //check boat is running or not
    // if(bool_boat){
      //  var_boat-=.35;
        //glutPostRedisplay();
    //}

    //check car is running or not
    if(bool_car){
        var_small_car-=.7;
        glutPostRedisplay();
    }

    //check vodka man is running or not
    if(bool_man){
        if(var_man<=23){
            var_man+=.005;
            glutPostRedisplay();
        }
         else{
            bool_man=false;
            glutPostRedisplay();
         }
    }
    else{
        glutPostRedisplay();
    }
}

//for second vodka man moving
void var_man2_moving(){
    //check boat is running or not
    // if(bool_boat){
      //  var_boat-=.35;
        //glutPostRedisplay();
    //}

    //check car is running or not
    if(bool_car){
        var_small_car-=.7;
        glutPostRedisplay();
    }

    //check vodka man is running or not
    if(bool_man2){
        if(var_man2<=23){
            var_man2 +=.005;
            glutPostRedisplay();
        }
         else{
            bool_man2=false;
            glutPostRedisplay();
         }
    }
    else{
        glutPostRedisplay();
    }
}




void init()
{

// glad: load all OpenGL function pointers

    glClearColor(.01,.9,.5,0);
    glOrtho(0,1800,0,1000,0,1);
    tombstone.configure();
    //tombstone2.configure();
    logo.configure();
    texti();

            submenu=glutCreateMenu(menufunc);
    glutCreateMenu(menufunc);
    glutAddMenuEntry("Start",1);
    glutAddMenuEntry("Future",2);
    glutAddMenuEntry("Exit",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);


//glOrtho(0, 1000, 10.0, 650,-2000,1500);
}


//road

void road(){
    glBegin(GL_POLYGON);
    glVertex2f(0,400);
    glVertex2f(1800,400);
    glVertex2f(1800,600);
    glVertex2f(0,600);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(150,600);
    glVertex2f(300,1000);
    glVertex2f(450,1000);
    glVertex2f(300,600);
    glEnd();

}


 //read er dag
void road_strip()
{

     glColor3ub(255,229,0);
    int j =185;
    for(int i=535;i<=1000;i+=80){
        glBegin(GL_POLYGON);
        glColor3ub(255,229,0);
        glVertex2f(j,i);
        glVertex2f(j+5,i);
        glVertex2f(j+15,i+50);
        glVertex2f(j+20,i+50);
        glEnd();
    j+=35;
    }

    for(int i=10;i<=1800;i+=100){
        glBegin(GL_POLYGON);
        glColor3ub(255,229,0);
        glVertex2f(i,505);
        glVertex2f(i,510);
        glVertex2f(i+50,510);
        glVertex2f(i+50,505);
        glEnd();
    }

}


//river

/*void river()
{
     glColor3ub(93,70,69);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,240);
    glVertex2f(200,260);
    glVertex2f(400,240);
    glVertex2f(700,250);
    glVertex2f(900,260);
    glVertex2f(1000,250);
    glVertex2f(1200,270);
    glVertex2f(1500,240);
    glVertex2f(1600,250);
    glVertex2f(1800,240);
    glVertex2f(1800,0);
    glEnd();

     glColor3ub(88,132,169);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,210);
    glVertex2f(200,230);
    glVertex2f(400,210);
    glVertex2f(700,220);
    glVertex2f(900,230);
    glVertex2f(1000,210);
    glVertex2f(1200,240);
    glVertex2f(1500,210);
    glVertex2f(1600,210);
    glVertex2f(1800,230);
    glVertex2f(1800,0);
    glEnd();

    glLineWidth(5);
    glColor3ub(99,145,174);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0,100);
    glVertex2f(200,110);
    glVertex2f(400,100);
    glVertex2f(700,140);
    glVertex2f(900,150);
    glVertex2f(1000,130);
    glVertex2f(1200,160);
    glVertex2f(1500,120);
    glVertex2f(1600,130);
    glVertex2f(1800,130);
    glEnd();

     glLineWidth(5);
    glColor3ub(99,145,174);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0,130);
    glVertex2f(200,190);
    glVertex2f(400,160);
    glVertex2f(700,160);
    glVertex2f(900,170);
    glVertex2f(1000,180);
    glVertex2f(1200,150);
    glVertex2f(1500,160);
    glVertex2f(1600,170);
    glVertex2f(1800,180);
    glEnd();

     glLineWidth(5);
    glColor3ub(99,145,174);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0,100);
    glVertex2f(200,50);
    glVertex2f(400,40);
    glVertex2f(700,40);
    glVertex2f(900,50);
    glVertex2f(1000,30);
    glVertex2f(1200,60);
    glVertex2f(1500,20);
    glVertex2f(1600,30);
    glVertex2f(1800,30);
    glEnd();

}*/
void textarea(){
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,270);
	glVertex2f(1800,270);
	glVertex2f(1800,0);
	glEnd();
}

//building 2nd scaling
void building_abd_scal()
{
     glPushMatrix();
    glScalef(.9,.8,0);
    building_abd_traslate_again_bottom();
    glPopMatrix();
}


//building 1st scalling
void building_scal()
{
     glPushMatrix();
    glScalef(6,6,0);
    building();
    glPopMatrix();

}


//building 2nd scaling
void building3_scal()
{
     glPushMatrix();
    glScalef(.9,.9,0);
    building2_translate();
    glPopMatrix();

}


//building 2nd transalte
void building_abd_traslate(){
     glPushMatrix();
    glTranslatef(1000,390,0);
     building_abd();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(1050,390,0);
     building_abd();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(1100,390,0);
     building_abd();
	glPopMatrix();


}


//building 3rd translate
void building_abd_traslate_again_bottom(){

    glColor3ub(100,100,100);
    glBegin(GL_TRIANGLES);
    glVertex2f(1050,490);
    glVertex2f(1200,490);
    glVertex2f(1125,600);
    glEnd();


     glPushMatrix();
    glTranslatef(1050,440,0);
     building_abd();
	glPopMatrix();


    building_abd_traslate();
      glPushMatrix();
    glTranslatef(0,-50,0);
     building_abd_traslate();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0,-100,0);
     building_abd_traslate();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0,-150,0);
     building_abd_traslate();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0,-200,0);
     building_abd_traslate();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(0,-250,0);
     building_abd_traslate();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(150,-200,0);
     building_abd_traslate();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(150,-250,0);
     building_abd_traslate();
	glPopMatrix();
}



//building 2nd reanslate
void building2_translate(){

    int j=0;
    for(int i=50;i<=200;i+=50){
        glPushMatrix();
        glTranslatef(i,j,0);
        building2_abd();
        glPopMatrix();
        if(i==200){
            i=0;
            j+=50;
        }
        if(j>200)
            break;
    }
    building2_abd_bottom();
}

void building2_abd_bottom()
{
    glBegin(GL_POLYGON);
    glColor3ub(15, 0, 105);
        glVertex2f(100,50);
        glVertex2f(100,-20);
        glVertex2f(170,-20);
        glVertex2f(170,50);

  glEnd();



  glPushMatrix();
   glTranslatef(130,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(15, 0, 105);
        glVertex2f(100,50);
        glVertex2f(100,-20);
        glVertex2f(170,-20);
        glVertex2f(170,50);

  glEnd();
	glPopMatrix();

	  glBegin(GL_POLYGON);
    glColor3ub(150, 210, 105);
        glVertex2f(170,50);
        glVertex2f(170,-20);
        glVertex2f(230,-20);
        glVertex2f(230,50);

  glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(15, 0, 105);
        glVertex2f(100,300);
        glVertex2f(300,300);
        glVertex2f(200,370);
  glEnd();


}

void building2_abd(){
    glBegin(GL_POLYGON);
    glColor3ub(15, 0, 105);
        glVertex2f(50,50);
        glVertex2f(50,100);
        glVertex2f(100,100);
        glVertex2f(100,50);

  glEnd();

  glBegin(GL_POLYGON);
    glColor3ub(102, 1, 255);
        glVertex2f(60,60);
        glVertex2f(60,90);
        glVertex2f(90,90);
        glVertex2f(90,60);

  glEnd();
}


//abd first building
void building_abd(){
    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 255);
        glVertex2f(50,50);
        glVertex2f(50,100);
        glVertex2f(100,100);
        glVertex2f(100,50);

  glEnd();

  glBegin(GL_POLYGON);
    glColor3ub(102, 1, 255);
        glVertex2f(60,60);
        glVertex2f(60,90);
        glVertex2f(90,90);
        glVertex2f(90,60);

  glEnd();
}

//building bijori/// campus

void building()
{
    //building

  glBegin(GL_QUADS);
    glColor3ub(102, 255, 255);
        glVertex2f(70,85);
        glVertex2f(100,85);
        glVertex2f(100,30);
        glVertex2f(70,30);

  glEnd();



//gate1
   glBegin(GL_QUADS);
    glColor3ub(255, 128, 0);
        glVertex2f(50,30);
        glVertex2f(50,40);
        glVertex2f(58,44);
        glVertex2f(58,30);

  glEnd();


//gate2
  glBegin(GL_QUADS);
    glColor3ub(255, 128, 0);
        glVertex2f(68,30);
        glVertex2f(75,30);
        glVertex2f(75,40);
        glVertex2f(68,44);

  glEnd();





window1(1);
window1(8);
window1(16);
window1(24);

window2(1);
window2(8);
window2(16);
window2(24);

window3(1);
window3(8);
window3(16);
window3(24);

window4(1);
window4(8);
window4(16);
window4(24);




//wall-right

glBegin(GL_QUADS);
    glColor3ub(204, 0, 0);
        glVertex2f(75,40);
        glVertex2f(120,40);
        glVertex2f(120,30);
        glVertex2f(75,30);

  glEnd();


  //wall-left

  glBegin(GL_QUADS);
    glColor3ub(204, 0, 0);
        glVertex2f(20,30);
        glVertex2f(20,40);
        glVertex2f(50,40);
        glVertex2f(50,30);

  glEnd();


}

GLvoid window1(GLdouble y)
{
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
        glVertex2f(y+70,50);
        glVertex2f(y+75,50);
        glVertex2f(y+75,45);
        glVertex2f(y+70,45);

        glEnd();
        glFlush();
}
GLvoid window2(GLdouble z)
{
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
        glVertex2f(z+70,60);
        glVertex2f(z+75,60);
        glVertex2f(z+75,55);
        glVertex2f(z+70,55);

        glEnd();
        glFlush();
}

GLvoid window3(GLdouble w)
{
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
        glVertex2f(w+70,70);
        glVertex2f(w+75,70);
        glVertex2f(w+75,65);
        glVertex2f(w+70,65);

        glEnd();
        glFlush();

}

GLvoid window4 (GLdouble v)
{
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
        glVertex2f(v+70,80);
        glVertex2f(v+75,80);
        glVertex2f(v+75,75);
        glVertex2f(v+70,75);

        glEnd();
        glFlush();
}




//grass flowers

void grass()
{
    glColor3ub(0,225,0);
    glBegin(GL_QUADS);
    glVertex2f(150,150);
    glVertex2f(150,170);
    glVertex2f(230,170);
    glVertex2f(230,150);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(190,150);
    glVertex2f(210,150);
    glVertex2f(200,300);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(195,150);
    glVertex2f(215,150);
    glVertex2f(210,295);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(200,150);
    glVertex2f(215,150);
    glVertex2f(220,280);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(210,150);
    glVertex2f(225,150);
    glVertex2f(230,270);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(230,260);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(245,250);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(255,240);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(265,230);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(270,220);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(275,210);
    glEnd();
     glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(280,205);
    glEnd();
     glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(285,200);
    glEnd();
     glBegin(GL_POLYGON);
    glVertex2f(215,150);
    glVertex2f(225,150);
    glVertex2f(290,190);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(180,150);
    glVertex2f(200,150);
    glVertex2f(190,295);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(175,150);
    glVertex2f(195,150);
    glVertex2f(185,285);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(170,150);
    glVertex2f(185,150);
    glVertex2f(180,275);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(160,150);
    glVertex2f(180,150);
    glVertex2f(170,265);
    glEnd();



    glBegin(GL_POLYGON);
    glVertex2f(160,150);
    glVertex2f(180,150);
    glVertex2f(160,255);
    glEnd();
     glBegin(GL_POLYGON);
    glVertex2f(160,150);
    glVertex2f(180,150);
    glVertex2f(150,245);
    glEnd();

      glBegin(GL_POLYGON);
    glVertex2f(170,150);
    glVertex2f(160,150);
    glVertex2f(145,235);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(165,150);
    glVertex2f(155,150);
    glVertex2f(140,225);
    glEnd();


       glBegin(GL_POLYGON);
    glVertex2f(170,150);
    glVertex2f(160,150);
    glVertex2f(135,220);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(165,150);
    glVertex2f(155,150);
    glVertex2f(124,210);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(170,150);
    glVertex2f(160,150);
    glVertex2f(125,210);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(165,150);
    glVertex2f(155,150);
    glVertex2f(120,200);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(170,150);
    glVertex2f(160,150);
    glVertex2f(110,195);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(165,150);
    glVertex2f(155,150);
    glVertex2f(100,185);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(160,150);
    glVertex2f(150,150);
    glVertex2f(90,180);
    glEnd();

}


//bus stop
void busstop()
{
      //bus stop
    glColor3ub(100,100,100);
    glBegin(GL_POLYGON);
    glVertex2f(380,650);
    glVertex2f(420,750);
    glVertex2f(720,750);
    glVertex2f(680,650);
    glEnd();

    glColor3ub(200,200,100);
    glBegin(GL_POLYGON);
    glVertex2f(380,650);
    glVertex2f(380,630);
    glVertex2f(690,630);
    glVertex2f(680,650);
    glEnd();

    glColor3ub(200,200,100);
    glBegin(GL_POLYGON);
    glVertex2f(690,630);
    glVertex2f(680,650);
    glVertex2f(720,750);
    glVertex2f(730,730);
    glEnd();


    glPushMatrix();
    glColor3ub(50,50,80);
    glTranslatef(0,200,0);
    busstop_top();
	glPopMatrix();

	busstop_left();

	//busstop right
	glPushMatrix();
    glTranslatef(300,0,0);
    busstop_left();
	glPopMatrix();
}

void busstop_top()
{
      //bus stop
    glColor3ub(50,50,80);
    glBegin(GL_POLYGON);
    glVertex2f(380,650);
    glVertex2f(420,710);
    glVertex2f(730,710);
    glVertex2f(700,650);
    glEnd();

    glColor3ub(200,200,200);
    glBegin(GL_POLYGON);
    glVertex2f(380,650);
    glVertex2f(380,630);
    glVertex2f(690,630);
    glVertex2f(680,650);
    glEnd();

    glColor3ub(200,200,200);
    glBegin(GL_POLYGON);
    glVertex2f(690,630);
    glVertex2f(680,650);
    glVertex2f(730,710);
    glVertex2f(735,685);
    glEnd();
}

void busstop_left()
{
    glColor3ub(50,50,80);
    glBegin(GL_POLYGON);
    glVertex2f(390,675);
    glVertex2f(390,865);
    glVertex2f(415,895);
    glVertex2f(415,735);
    glEnd();
}



//lamp
void lamp()
{
    glColor3ub(200,200,150);
    glBegin(GL_POLYGON);
    glVertex2f(120,600);
    glVertex2f(140,600);
    glVertex2f(140,800);
    glVertex2f(120,800);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(70,800);
    glVertex2f(70,810);
    glVertex2f(190,810);
    glVertex2f(190,800);
    glEnd();

    glPushMatrix();
    glTranslatef(88,695,0);
    glScalef(4,4,0);
    Tire(10);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-32,695,0);
    glScalef(4,4,0);
    Tire(10);
    glPopMatrix();

    glColor3ub(200,200,150);
    glBegin(GL_POLYGON);
    glVertex2f(70,800);
    glVertex2f(50,760);
    glVertex2f(90,760);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(190,800);
    glVertex2f(170,760);
    glVertex2f(210,760);
    glEnd();


}


//crismas tree
void crismas(){
    glColor3ub(200,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(50,0);
    glVertex2f(70,0);
    glVertex2f(70,110);
    glVertex2f(50,110);
    glEnd();

     glColor3ub(0,51,0);
    glBegin(GL_POLYGON);
    glVertex2f(60,230);
    glVertex2f(120,110);
    glVertex2f(0,110);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(60,270);
    glVertex2f(110,150);
    glVertex2f(10,150);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(60,280);
    glVertex2f(100,190);
    glVertex2f(20,190);
    glEnd();
}

//bus by bijori
GLvoid drawCircle(GLdouble xc, GLdouble yc, GLdouble rad)
{
    GLfloat i;
    glPointSize(3);
	glBegin(GL_POLYGON);

    for(i=0;i<=7;i+=.01)
        glVertex2f(xc+rad*cos(i),yc+rad*sin(i));
	glEnd();

}

 GLvoid  window_bus(GLdouble x)
{       glBegin(GL_QUADS);
    glColor3ub(0, 255, 255);
        glVertex2f(x+12,20);
        glVertex2f(x+17,20);

        glVertex2f(x+17,25);
        glVertex2f(x+12,25);
    glEnd();
    glFlush();



}

GLvoid Tire(GLdouble y)
{
    glColor3ub(255,255, 0);

    drawCircle(y+15,15,3);


}

void bus(){
     glPushMatrix();
    glTranslatef(30,15,0);
    glScalef(3,3,0);
    drawWheel();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(16,15,0);
    glScalef(3,3,0);
    drawWheel();
	glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 51);
    glVertex2f(10,15);
    glVertex2f(10,28);
    glVertex2f(34.5,28);
    glVertex2f(36,23);
    glVertex2f(36,15);
    glEnd();


    window_bus(0);
    window_bus(8);

    glBegin(GL_POLYGON);
   glColor3ub(0, 255, 255);
    glVertex2f(28,20);
    glVertex2f(28,25);
    glVertex2f(33.2,25);
    glVertex2f(34,22);
    glVertex2f(34,20);

    glEnd();


    glEnd();

}

//bus scaling

void bus_scal(){

    glPushMatrix();
    glScalef(9,9,0);
    bus();
    glPopMatrix();


}

//bus translating
void bus_final(){
    glPushMatrix();
    glTranslatef(-200,410,0);
    bus_scal();
	glPopMatrix();
}







//----------- car 2 + vodka moving -------->

//disk  for car and others
void drawDisk(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}




//mouth for vodka man and all the started from here
//.....................................

void Mouth(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 16; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}



void Hair(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 18; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}

void brew(double radius) {
	int d;
	glBegin(GL_LINE_LOOP);
	for (d = 0; d < 16; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}



void Hand()
{
       glPushMatrix();
  glTranslatef(-0.5,-0.5,0);
   glScalef(0.09,0.2,0);
     glColor3f (0.0, 0.9, .9);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(-0.5,-0.7,0);
   glScalef(0.09,0.4,0);
    glColor3f (1.0, 0.8, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
    glEnd();
  glPopMatrix();

  glPushMatrix();
     glTranslatef(-0.5,-0.95,0);
   glScalef(0.1,0.08,0);
     glColor3f (1.0, 0.8, 0.6);
     drawDisk(0.7);
     glPopMatrix();
}

void Leg()
{
    glPushMatrix();
  glTranslatef(-.5,-0.5,0);
   glScalef(.12,.9,0);
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
    glEnd();
  glPopMatrix();
   glPushMatrix();
    glTranslatef(-0.45,-0.9,0);
   glScalef(0.14,0.08,0);
     drawDisk(0.7);
     glPopMatrix();

}




void Hand1()
{
       glPushMatrix();
  glTranslatef(-0.5,-0.5,0);
   glScalef(0.09,0.2,0);
     glColor3f (0.0, 0.9, .9);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
     glEnd();
     glPopMatrix();



     glPushMatrix();
     glTranslatef(-0.5,-0.7,0);
   glScalef(0.09,0.4,0);
    glColor3f (1.0, 0.8, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
    glEnd();
  glPopMatrix();

  glPushMatrix();
     glTranslatef(-0.5,-0.95,0);
   glScalef(0.1,0.08,0);
     glColor3f (1.0, 0.8, 0.6);
     drawDisk(0.7);
     glPopMatrix();
}

void Leg1()
{
    glPushMatrix();
  glTranslatef(-.5,-0.5,0);
   glScalef(.09,.9,0);
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
    glEnd();
  glPopMatrix();
   glPushMatrix();
    glTranslatef(-0.5,-0.9,0);
   glScalef(0.14,0.08,0);
     drawDisk(0.6);
     glPopMatrix();

}

void Man1()
{
     glPushMatrix();
  glTranslatef(0.5,0,0);
  Leg();
glPopMatrix();
       glPushMatrix();
   glTranslatef(0,0.8,0);
   glScalef(0.4,0.456,0);
    glColor3fv(man_face[infected]);
  drawDisk(.5);
  glPopMatrix();
   glPushMatrix();
  glTranslatef(0,0.5,0);
   glScalef(0.1,0.2,0);
    glColor3f (1.0, 0.8, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
    glEnd();
  glPopMatrix();

    glPushMatrix();
     glTranslatef(0,0.1,0);
   glScalef(0.6,0.9,0);
    glColor3f (0.0, 0.9, .9);
  drawDisk(.5);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.5,0.9,0);
  Hand();
glPopMatrix();
   glFlush();
     glPushMatrix();
  glTranslatef(0.5,0.9,0);
  Hand();
glPopMatrix();



 glPushMatrix();
   glTranslatef(0.13,0.85,0);
   glScalef(0.1,0.05,0);
    glColor3f (1.0, 1.0, 1.0);
  drawDisk(.5);
  glPopMatrix();
   glPushMatrix();
   glTranslatef(0.13,0.85,0);
   glScalef(0.03,0.03,0);
    glColor3f (0.0, 0.0, 0.0);
  drawDisk(.5);
  glPopMatrix();
     glPushMatrix();
   glTranslatef(0.1,0.68,0);
   glScalef(0.06,0.03,0);
    glColor3f (.8, .5, 0.0);
    Mouth(1);
  glPopMatrix();
   glPushMatrix();
   glTranslatef(0,.98,0);
   glScalef(0.15,0.05,0);
  glColor3f(0,0,0);
  Hair(1);
glPopMatrix();

 glPushMatrix();
   glTranslatef(0.12,.88,0);
   glScalef(0.05,0.01,0);
  glColor3f(0,0,0);

  brew(1);
glPopMatrix();
   glPushMatrix();
   glTranslatef(.2,.76,0);
   glScalef(0.05,0.02,0);
   glColor3f (1.0, 0.8, 0.6);;
  drawDisk(1);
glPopMatrix();
}

void Man2()
{
     glPushMatrix();
  glTranslatef(0.5,0,0);
  Leg();
glPopMatrix();
       glPushMatrix();
   glTranslatef(0,0.8,0);
   glScalef(0.4,0.456,0);
    glColor3f (1.0, 0.8, 0.6);
  drawDisk(.5);
  glPopMatrix();
   glPushMatrix();
  glTranslatef(0,0.5,0);
   glScalef(0.1,0.2,0);
    glColor3ub(255,153,153);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.5);
    glEnd();
  glPopMatrix();

    glPushMatrix();
     glTranslatef(0,0.1,0);
   glScalef(0.6,0.9,0);
    glColor3ub(255,153,153);
  drawDisk(.5);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.5,0.9,0);
  Hand();
glPopMatrix();
   glFlush();



 glPushMatrix();
   glTranslatef(0.13,0.85,0);
   glScalef(0.1,0.05,0);
    glColor3f (1.0, 1.0, 1.0);
  drawDisk(.5);
  glPopMatrix();
   glPushMatrix();
   glTranslatef(0.13,0.85,0);
   glScalef(0.03,0.03,0);
    glColor3f (0.0, 0.0, 0.0);
  drawDisk(.5);
  glPopMatrix();
     glPushMatrix();
   glTranslatef(0.1,0.68,0);
   glScalef(0.06,0.03,0);
    glColor3f (.8, .5, 0.0);
    Mouth(1);
  glPopMatrix();
   glPushMatrix();
   glTranslatef(0,.98,0);
   glScalef(0.15,0.05,0);
	 glColor3ub(222,93,131);
  Hair(1);
glPopMatrix();

 glPushMatrix();
   glTranslatef(0.12,.88,0);
   glScalef(0.05,0.01,0);
  glColor3f(0,0,0);

  brew(1);
glPopMatrix();
   glPushMatrix();
   glTranslatef(.2,.76,0);
   glScalef(0.05,0.02,0);
   glColor3f (1.0, 0.8, 0.6);;
  drawDisk(1);
glPopMatrix();
}




//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//for car wheel

void drawWheel() {

	glColor3f(0,0,0);
	drawDisk(1);
	glColor3f(0.75f, 0.75f, 0.75f);
	drawDisk(0.8);
	glColor3f(0,0,0);
	drawDisk(0.2);

}



//circle for car and others  using disk
void drawCircle() {
	glColor3f(0.5,0,0);
	drawDisk(0.2);
}


//drawing small car ...............

void drawCart() {
	glPushMatrix();
	glTranslatef(-1.2f, -1.6f, 0);
	glScalef(0.4,0.4f,1);
	drawWheel();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.2f, -1.6f, 0);
	glScalef(0.4f,0.4f,1);
	drawWheel();
	glPopMatrix();
	glColor3f(1,0,0);

	glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.30f,0.30f,0.30f);            // Set The Color To Red
  glVertex2f(-1.0f, .90f);
  glVertex2f(1.0f, .90f);
  glVertex2f(1.5 , -.10f);
  glVertex2f(-1.5f, -.10f);       // Top left
  glEnd();


    glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Red
  glVertex2f(1.5f, -.10f);
  glVertex2f(2.5f, -.6f);
  glVertex2f(-2.0f , -.6f);
  glVertex2f(-1.5f, -.10f);        // Top left
  glEnd();

  glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Red
  glVertex2f(2.5f, -.6f);
  glVertex2f(2.5f, -1.6f);
  glVertex2f(-2.0f , -1.6f);
  glVertex2f(-2.0f , -.6f);;        // Top left
  glEnd();

glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Red
  glVertex2f(-1.0f, .90f);
  glVertex2f(1.0f, .90f);
  glVertex2f(1.0 , .75f);
  glVertex2f(-1.0f, .75f);       // Top left
  glEnd();

  glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Red
  glVertex2f(-1.0f, .90f);
  glVertex2f(-.90f, .90f);
  glVertex2f(-.90 , -.10f);
  glVertex2f(-1.0f, -.10f);       // Top left
  glEnd();

   glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Red
  glVertex2f(-.15f, .90f);
  glVertex2f(.15f, .90f);
  glVertex2f(.15f , -.10f);
  glVertex2f(-.15f, -.10f);       // Top left
  glEnd();

glBegin(GL_POLYGON);                // start drawing a polygon
  glColor3f(0.0f,0.0f,1.0f);            // Set The Color To Red
  glVertex2f(1.0f, .90f);
  glVertex2f(.90f, .90f);
  glVertex2f(.90 , -.10f);
  glVertex2f(1.0f, -.10f);
  glEnd();
}


//rotate the car for first window

void small_car_rotate(){
    glPushMatrix();
    glTranslatef(1900,480, 0);
	glScalef(35,35,0);
    glRotatef(180, 0, 360,0);
    drawCart();
    glPopMatrix();
}



//<------------Drawing girl for passenger------------------>>


//circle for girl face and other thing
GLvoid circle_for_girl(GLdouble rad)
{
	GLint points = 500;
	GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
	GLdouble theta = 0;

GLint i=0;
	glBegin(GL_POLYGON);
	{
		for(i = 0; i <=500; i++, theta += delTheta )
		{

			glVertex2f(rad * cos(theta),rad * sin(theta));
		}
	}
	glEnd();
}



//not proper circle for girl hair;
GLvoid semi_circle_for_girl(GLdouble rad)
{
	GLint points = 110;
	GLdouble delTheta = (PI) / (GLdouble)points;
	GLdouble theta = 30;

    GLint i=0;
	glBegin(GL_POLYGON);
	{

		for(i = 0; i <=100; i++, theta += delTheta )
		{

            glVertex2d(rad *cos(theta),rad * sin(theta));

		}
	}
	glEnd();
}






GLvoid ghand(void)
{
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glColor3d(1,.8,.5);
    glVertex2f(.2,.05);
    glVertex2f(.3,-.2);
    glVertex2f(.2,-.4);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glColor3d(1,.8,.5);
    glVertex2f(-.2,.05);
    glVertex2f(-.3,-.2);
    glVertex2f(-.2,-.4);
    glEnd();
}


GLvoid gleg(void)
{
    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glColor3d(1,.8,.5);
    glVertex2f(-.2,-0.8);
    glVertex2f(-.4,-1.4);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glColor3d(1,.8,.5);
    glVertex2f(.2,-0.8);
    glVertex2f(.4,-1.4);
    glEnd();
}


GLvoid girldress(void)
{
    gleg();
    glBegin(GL_POLYGON);
    glColor3d(.2,0,.2);
    glVertex2f(-.2,.05);
    glVertex2f(.2,.05);
    glVertex2f(.3,-1);
    glVertex2f(-.3,-1);
    glEnd();
    glPushMatrix();
    glColor3d(.8,0,.4);
    glRotated(90,0,0,1);
    semi_circle_for_girl(.33);
    glPopMatrix();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0,0);
    glVertex2f(0,-.8);
    glVertex2f(0,0);
    glVertex2f(-.1,-.7);
    glVertex2f(0,0);
    glVertex2f(.1,-.7);
    glEnd();

    glPushMatrix();
    glColor3d(0,.2,0);
    glTranslated(-.4,-1.35,0);
    circle_for_girl(.09);
    glTranslated(.8,0,0);
    circle_for_girl(.09);
    glPopMatrix();

    ghand();

    glEnd();

}

GLvoid girl2dress(void)
{
    gleg();
		glColor3ub(255,142,142);
    glBegin(GL_POLYGON);
    glVertex2f(-.2,.05);
    glVertex2f(.2,.05);
    glVertex2f(.3,-1);
    glVertex2f(-.3,-1);
    glEnd();
    glPushMatrix();
    glColor3d(.8,0,.4);
    glRotated(90,0,0,1);
    semi_circle_for_girl(.33);
    glPopMatrix();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0,0);
    glVertex2f(0,-.8);
    glVertex2f(0,0);
    glVertex2f(-.1,-.7);
    glVertex2f(0,0);
    glVertex2f(.1,-.7);
    glEnd();

    glPushMatrix();
    glColor3d(0,.2,0);
    glTranslated(-.4,-1.35,0);
    circle_for_girl(.09);
    glTranslated(.8,0,0);
    circle_for_girl(.09);
    glPopMatrix();

    ghand();

    glEnd();

}

GLvoid girl3dress(void)
{
    gleg();
		glColor3ub(242,0,60);
    glBegin(GL_POLYGON);
    glVertex2f(-.2,.05);
    glVertex2f(.2,.05);
    glVertex2f(.3,-1);
    glVertex2f(-.3,-1);
    glEnd();
    glPushMatrix();
    glColor3d(.8,0,.4);
    glRotated(90,0,0,1);
    semi_circle_for_girl(.33);
    glPopMatrix();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0,0);
    glVertex2f(0,-.8);
    glVertex2f(0,0);
    glVertex2f(-.1,-.7);
    glVertex2f(0,0);
    glVertex2f(.1,-.7);
    glEnd();

    glPushMatrix();
    glColor3d(0,.2,0);
    glTranslated(-.4,-1.35,0);
    circle_for_girl(.09);
    glTranslated(.8,0,0);
    circle_for_girl(.09);
    glPopMatrix();

    ghand();

    glEnd();

}

//girl final
GLvoid girl(void)
{

    glPushMatrix();
    glTranslated(-4,3.4,0);
    girldress();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4,4,0);
    glColor3d(1,.8,.5);
    circle_for_girl(.25);
    glColor3d(0,0,0);
    glRotated(65,0,0,1);
    glTranslated(.1,.08,0);
    semi_circle_for_girl(.25);
    glRotated(65,0,0,1);
    semi_circle_for_girl(.25);
    glTranslated(-.15,0,0);
    circle_for_girl(.03);
    glTranslated(.11,.1,0);
    circle_for_girl(.03);
    glTranslated(-.13,.01,0);
    circle_for_girl(.0185);
    glColor3d(1,0,0);
    glTranslated(-.09,.07,0);
    glColor3d(1,0,0.2);
    circle_for_girl(.033);
    glColor3d(1,.8,.5);
    glTranslated(-.05,.07,0);
    circle_for_girl(.05);
    glPopMatrix();

}

GLvoid girl2(void)
{

    glPushMatrix();
    glTranslated(-4,3.4,0);
    girl2dress();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4,4,0);
    glColor3fv(man_face[infected]);
    circle_for_girl(.25);
    glColor3d(0,0,0);
    glRotated(65,0,0,1);
    glTranslated(.1,.08,0);
    semi_circle_for_girl(.25);
    glRotated(65,0,0,1);
    semi_circle_for_girl(.25);
    glTranslated(-.15,0,0);
    circle_for_girl(.03);
    glTranslated(.11,.1,0);
    circle_for_girl(.03);
    glTranslated(-.13,.01,0);
    circle_for_girl(.0185);
    glColor3d(1,0,0);
    glTranslated(-.09,.07,0);
    glColor3d(1,0,0.2);
    circle_for_girl(.033);
    glColor3d(1,.8,.5);
    glTranslated(-.05,.07,0);
    circle_for_girl(.05);
    glPopMatrix();

}

GLvoid girl3(void)
{

    glPushMatrix();
    glTranslated(-4,3.4,0);
    girl3dress();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4,4,0);
    glColor3fv(man_face[infected]);
    circle_for_girl(.25);
    glColor3d(0,0,0);
    glRotated(65,0,0,1);
    glTranslated(.1,.08,0);
    semi_circle_for_girl(.25);
    glRotated(65,0,0,1);
    semi_circle_for_girl(.25);
    glTranslated(-.15,0,0);
    circle_for_girl(.03);
    glTranslated(.11,.1,0);
    circle_for_girl(.03);
    glTranslated(-.13,.01,0);
    circle_for_girl(.0185);
    glColor3d(1,0,0);
    glTranslated(-.09,.07,0);
    glColor3d(1,0,0.2);
    circle_for_girl(.033);
    glColor3d(1,.8,.5);
    glTranslated(-.05,.07,0);
    circle_for_girl(.05);
    glPopMatrix();

}

//Intro
void texti()
{
    //glEnable(GL_TEXTURE_2D);
    //glColor3f(1, 1, 1);
    //glBindTexture(GL_TEXTURE_2D, intro);
    //glBegin(GL_QUADS);
    	//glVertex3f(200, 200, 0);
    //glTexCoord2f(0, 0);
    //glVertex3f(200, 400, 0);
    //glTexCoord2f(0, 1);
    //glVertex3f(400, 400, 0);
    //glTexCoord2f(1, 1);
    //glVertex3f(400, 200, 0);
    //glTexCoord2f(1, 0);
    //glEnd();
    //glFlush();
    //glDisable(GL_TEXTURE_2D);
    
	glClearColor(0.8941,0.8549,0.7608,1.0);
	char string[]="BANGALORE INSTITUTE OF TECHNOLOGY";
	void *font= GLUT_BITMAP_TIMES_ROMAN_24;
	int k;
	glColor3f(0.0,0.0,0);
	glRasterPos3f(630,900,0);
	for(k=0;k<strlen(string);k++) {
	        glutBitmapCharacter(font,string[k]);
	}

	char string0[]="K.R.ROAD,V.V.PURAM,BANGALORE-560004";
	void *font0=GLUT_BITMAP_TIMES_ROMAN_24;
	glColor3f(0, 0, 0);
	glRasterPos3f(635,850,0);
	for(k=0;k<strlen(string0);k++)
	        glutBitmapCharacter(font0,string0[k]);	        
	 
	char string10[]="DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING";
	void *font10=GLUT_BITMAP_TIMES_ROMAN_24;
	glColor3f(0, 0, 0);
	glRasterPos3f(550,780,0);
	for(k=0;k<strlen(string10);k++)
	        glutBitmapCharacter(font10,string10[k]);
	
	char string11[]="Computer Graphics Laboratory (18CSL67)";
	void *font11=GLUT_BITMAP_TIMES_ROMAN_24;
	glColor3f(0, 0, 0);
	glRasterPos3f(650,700,0);
	for(k=0;k<strlen(string11);k++)
	        glutBitmapCharacter(font11,string11[k]);	        
	
	char string1[]="SPREAD OF COVID-19";
	void *font1=GLUT_BITMAP_TIMES_ROMAN_24;
	glColor3f(0, 0, 0);
	glRasterPos3f(700,630,0);
	for(k=0;k<strlen(string1);k++)
	        glutBitmapCharacter(font1,string1[k]);

		char string2[]="BY";
	void *font2=GLUT_BITMAP_TIMES_ROMAN_24;
	glColor3f(0.0,0.0,0.0);


	glRasterPos3f(1200,430+100,0);

	for(k=0;k<strlen(string2);k++)
	        glutBitmapCharacter(font2,string2[k]);
	char string3[]="1. ANTASH MISHRA (1BI18CS023)";
	void *font3=GLUT_BITMAP_HELVETICA_18;
	glColor3f(0.0,0.0,0.0);
	glRasterPos3f(1220,400+100,0);
	for(k=0;k<strlen(string3);k++)
	        glutBitmapCharacter(font3,string3[k]);

	char string4[]="2. ARPIT ANAND (1BI18CS026)";
	void *font4=GLUT_BITMAP_HELVETICA_18;
	glColor3f(0.0,0.0,0.0);
	glRasterPos3f(1220,400+70,0);
	for(k=0;k<strlen(string4);k++)
	        glutBitmapCharacter(font4,string4[k]);



	char string5[]="UNDER THE GUIDANCE OF ";
	void *font5=GLUT_BITMAP_HELVETICA_18;

	glColor3f(0.0,0.0,0.0);


	glRasterPos3f(200,460+70,0);

	for(k=0;k<strlen(string5);k++)
	        glutBitmapCharacter(font5,string5[k]);

	char string6[]="Dr. Girija J (Associate Professor)";
	void *font6=GLUT_BITMAP_HELVETICA_18;

	glColor3f(0.0,0.0,0.0);

	glRasterPos3f(200,430+70,0);
	for(k=0;k<strlen(string6);k++)
	        glutBitmapCharacter(font6,string6[k]);

	char string9[]="Dr. B N Shankar Gowda (Associate Professor)";
	void *font9=GLUT_BITMAP_HELVETICA_18;

	glColor3f(0.0,0.0,0.0);

	glRasterPos3f(200,430+40,0);
	for(k=0;k<strlen(string9);k++)
	        glutBitmapCharacter(font9,string9[k]);
	char string8[]="Click on the Right button to start the show of COVID-19 Spread Animation";
	void *font8=GLUT_BITMAP_HELVETICA_18;
	glColor3f(.5,0,0);
	glRasterPos3f(370,160,0);
	for(k=0;k<strlen(string8);k++)
	        glutBitmapCharacter(font8,string8[k]);
	        
	        
	glPushMatrix();
	glTranslatef(650,1050,0);
	glScalef(1.0,0.7, 1.0);
	glRotatef(180, 0,0,1);
	logo.draw();
        glPopMatrix();
}


//first window
void first_window()
{




    road();
    road_strip();
    busstop();

	//crismas tree
	glPushMatrix();
    glTranslatef(130,760,0);
    crismas();
	glPopMatrix();


	//printing 9/10 grass
	for(int i=-100;i<=1800;i+=200){
        glPushMatrix();
        glTranslatef(i,150,0);
        grass();
        glPopMatrix();
	}

	glPushMatrix();
    glTranslatef(750,650,0);
    crismas();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(900,650,0);
    crismas();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(1050,650,0);
    crismas();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(1700,650,0);
    crismas();
	glPopMatrix();


	//car small one which will moving
	glPushMatrix();
	glTranslatef(var_small_car,0, 0);
    small_car_rotate();
	glPopMatrix();


	//printing 3/4 grass other side of road
	for(int i=600;i<=1050;i+=180){
        glPushMatrix();
        glTranslatef(i,465,0);
        grass();
        glPopMatrix();
	}



	glPushMatrix();
    glTranslatef(1600,465,0);
    grass();
    glPopMatrix();




	glPushMatrix();
    glTranslatef(20,40,0);
    lamp();
	glPopMatrix();



	glPushMatrix();
    glTranslatef(210,30,0);
    lamp();
	glPopMatrix();


	glPushMatrix();
  glTranslatef(660,0,0);
  lamp();
	glPopMatrix();



  glPushMatrix();
  glTranslatef(280,480,0);
  building_abd_scal();
	glPopMatrix();


  glPushMatrix();
  glTranslatef(1400,630,0);
  building2_translate();
	glPopMatrix();

  glPushMatrix();
  glTranslatef(-50,-320,0);
  lamp();
	glPopMatrix();

	//river();

	// if the car is in font of bus stop then man_in will be true press y/Y
	 if(!man_in){
         glPushMatrix();
        glTranslatef(740,520, 0);
        glScalef(43,45,0);
        girl();
        glPopMatrix();
	 }

  glPushMatrix();
	glTranslatef(320,655, 0);
	glScalef(60,60,0);
	glTranslatef(var_man,0, 0);
  Man1();
	glPopMatrix();

	glPushMatrix();
  glTranslatef(400,665, 0);
  glScalef(60,60,0);
  glTranslatef(var_man2,-0.4, 0);
  Man2();
  glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,0);
	glScalef(1,1,0);
	textarea();
	glPopMatrix();
small_car_moving();
}


//second window
void second_window()
{

		 if(tx>=1330 && tx<=1650){
			 infected = 1;
		 }
		else if(tx<1330 && tx >= 1650){
			infected= 0;
		}
    //road
    glBegin(GL_POLYGON);
    glVertex2f(0,400);
    glVertex2f(1800,400);
    glVertex2f(1800,600);
    glVertex2f(0,600);
    glEnd();

    glColor3ub(255,229,0);


    //second window road strip
    for(int i=10;i<=1800;i+=100){
        glBegin(GL_POLYGON);
        glColor3ub(255,229,0);
        glVertex2f(i,505);
        glVertex2f(i,510);
        glVertex2f(i+50,510);
        glVertex2f(i+50,505);
        glEnd();
    }


    // printing grass on my side
    for(int i=-50;i<=1450;i+=250){
        glPushMatrix();
        glTranslatef(i,150,0);
        grass();
        glPopMatrix();
    }


    //crismas tree
	glPushMatrix();
    glTranslatef(130,720,0);
    crismas();
	glPopMatrix();


	glPushMatrix();
    glTranslatef(870,720,0);
    crismas();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(950,470,0);
    grass();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(-50,470,0);
    grass();
	glPopMatrix();


	glPushMatrix();
    glTranslatef(450,470,0);
    grass();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(700,470,0);
    grass();
	glPopMatrix();


	//printing crismas tree

	for(int i=200;i<=1400;i+=400){

        glPushMatrix();
        glTranslatef(i,220,0);
        crismas();
        glPopMatrix();
	}


    glPushMatrix();
    glTranslatef(310,480,0);
     building_abd_scal();
	glPopMatrix();

    glPushMatrix();
    glTranslatef(1100,430,0);
    building_scal();
	glPopMatrix();


	glPushMatrix();
    glTranslatef(200,650,0);
     building3_scal();
	glPopMatrix();


	//if the car is in font of varsity that time man out will be true press A/a
	if(man_out){
        glPushMatrix();
        glTranslatef(1640,520, 0);
        glScalef(43,45,0);
        girl();
        glPopMatrix();
	 }

	 glPushMatrix();
	 glTranslatef(1600,520, 0);
	 glScalef(43,45,0);
	 girl2();
	 glPopMatrix();

	 glPushMatrix();
	 glTranslatef(1700,520, 0);
	 glScalef(43,45,0);
	 girl3();
	 glPopMatrix();


	 glPushMatrix();
    glTranslatef(100,640, 0);
	glScalef(30,30,0);
	glTranslatef(var_car2,0,0);
    drawCart();
    glPopMatrix();

	//river();



    //glPushMatrix();
	//glTranslatef(500,110, 0);
	//glScalef(.7,.7,0);
	//glTranslatef(var_boat2,0, 0);
    //boat();
	//glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0,0);
	glScalef(1,1,0);
	textarea();
	glPopMatrix();

	car2_moving();

}





void third_window() {

//intro();

    glColor3ub(255,229,0);
    int i,j;
 //printing grass on my side
 for(int j=-50; j <= 1450; j+=150) {
    for(int i=-50;i<=1450;i+=250){
        glPushMatrix();
        glTranslatef(i,j,0);
        glScalef(0.7, 0.7, 0);
        grass();
        glPopMatrix();
    }
    }
//    glPushMatrix();
//glTranslatef(650,400	,0);
//        	glBegin(GL_QUADS);
//	glColor3f(1, 0, 0);
//	glVertex2f(200, 400);
//	glVertex2f(400, 400);
//	glVertex2f(400, 200);
//	glVertex2f(200, 200);
//	glEnd();
//  glPopMatrix();


     //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     //glMatrixMode(GL_MODELVIEW);
       //   glLoadIdentity();
//          ground.draw();

//for(int j=-50; j <= 1450; j+=150) {
//    for(int i=-50;i<=1450;i+=250){
//        glPushMatrix();
//	//glTranslatef(650,400	,0);
//	glTranslatef(i,j,0);
//	glScalef(0.5,0.5, 0);
//	glRotatef(180, 0,0,1);
//	tombstone.draw();
//        glPopMatrix();
//    }
//    }

    glPushMatrix();
	glTranslatef(1700,1100,0);
	glScalef(1.2,1.2, 0);
	glRotatef(180, 0,0,1);
	tombstone.draw();
        glPopMatrix();
        
        	

        glPushMatrix();
	glTranslatef(700,1100,0);
	glScalef(1.2,1.2, 0);
	glRotatef(180, 0,0,1);
	tombstone.draw();
        glPopMatrix();

        glPushMatrix();
	glTranslatef(1200,1100,0);
	glScalef(1.2,1.2, 0);
	glRotatef(180, 0,0,1);
	tombstone.draw();
        glPopMatrix();
              //glutSwapBuffers();


		glPushMatrix();
	glTranslatef(0,0,0);
		glScalef(1,1,0);
		textarea();
		glPopMatrix();


}


// Last window(Future window)
void fourth_window() {

road();
    road_strip();
    busstop();

	//crismas tree
	glPushMatrix();
    glTranslatef(130,760,0);
    crismas();
	glPopMatrix();


	//printing 9/10 grass
	for(int i=-100;i<=1800;i+=200){
        glPushMatrix();
        glTranslatef(i,150,0);
        grass();
        glPopMatrix();
	}

	glPushMatrix();
    glTranslatef(750,650,0);
    crismas();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(900,650,0);
    crismas();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(1050,650,0);
    crismas();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(1700,650,0);
    crismas();
	glPopMatrix();


	//car small one which will moving
	glPushMatrix();
	glTranslatef(var_small_car,0, 0);
    small_car_rotate();
	glPopMatrix();


	//printing 3/4 grass other side of road
	for(int i=600;i<=1050;i+=180){
        glPushMatrix();
        glTranslatef(i,465,0);
        grass();
        glPopMatrix();
	}



	glPushMatrix();
    glTranslatef(1600,465,0);
    grass();
    glPopMatrix();




	glPushMatrix();
    glTranslatef(20,40,0);
    lamp();
	glPopMatrix();



	glPushMatrix();
    glTranslatef(210,30,0);
    lamp();
	glPopMatrix();


	glPushMatrix();
  glTranslatef(660,0,0);
  lamp();
	glPopMatrix();



  glPushMatrix();
  glTranslatef(280,480,0);
  building_abd_scal();
	glPopMatrix();


  glPushMatrix();
  glTranslatef(1400,630,0);
  building2_translate();
	glPopMatrix();

  glPushMatrix();
  glTranslatef(-50,-320,0);
  lamp();
	glPopMatrix();

	//river();

	// if the car is in font of bus stop then man_in will be true press y/Y
	 if(!man_in){
         glPushMatrix();
        glTranslatef(740,520, 0);
        glScalef(43,45,0);
        girl();
        glPopMatrix();
	 }

  glPushMatrix();
	glTranslatef(320,655, 0);
	glScalef(60,60,0);
	glTranslatef(var_man,0, 0);
  Man1();
	glPopMatrix();

	glPushMatrix();
  glTranslatef(400,665, 0);
  glScalef(60,60,0);
  glTranslatef(var_man2,-0.4, 0);
  Man2();
  glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,0);
	glScalef(1,1,0);
	textarea();
	glPopMatrix();
small_car_moving();
}



//display
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(30,40,60);

    if(window==2){
        glClear(GL_COLOR_BUFFER_BIT);
        glutIdleFunc(NULL);
        second_window();
        glPushMatrix();
    	glTranslatef(tx,ty,0);
    bus_final();
    	glPopMatrix();
	glPushMatrix();
	render();
	glPopMatrix();
        glutPostRedisplay();
        if(tx<=0){
            window=0;
            tx=1750;
        }
        else if(tx>1800){
            window=3;
            tx=0;
            ty=0;
        }
    }

    else if(window == 1) {
    	glClear(GL_COLOR_BUFFER_BIT);
        //texti();
        first_window();
        glPushMatrix();
    	glTranslatef(tx,ty,0);
    bus_final();
    	glPopMatrix();
	glPushMatrix();
	render();
	glPopMatrix();

        glutPostRedisplay();
        if(tx>=1790){
             glutIdleFunc(NULL);
            window=2;
            glutPostRedisplay();
            tx=10;
        }

    }
    else if(window==3) {

    	glClear(GL_COLOR_BUFFER_BIT);
        glutIdleFunc(NULL);
        //intro();
        third_window();
				glPushMatrix();
				render();
				glPopMatrix();
        glutPostRedisplay();
    }
    else if(window==4) {
    glClear(GL_COLOR_BUFFER_BIT);
        glutIdleFunc(NULL);
        //intro();
        fourth_window();
        glPushMatrix();
    	glTranslatef(tx,ty,0);
    bus_final();
    	glPopMatrix();
        
				glPushMatrix();
				render();
				glPopMatrix();
        glutPostRedisplay();
    }
    else{

        glClear(GL_COLOR_BUFFER_BIT);
        texti();
        glutPostRedisplay();
        if(tx>=1790){
             glutIdleFunc(NULL);
            window=1;
            glutPostRedisplay();
            tx=0;
        }
    }

    glFlush();
    glutSwapBuffers();

}





//main
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(1800,1000);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Covid Spread Animation");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutMouseFunc(mouse);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();
    return 0;
}
