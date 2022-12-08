#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
int  mode=0,i=0,draw=0,de=0,sett=0,st=0;
 char a[100],b1[100];
int l;
int r=10,g=50,b=250;
int x1 = 100;

void colour_change(){
    r+=20;
    g+=10;
    b-=10;
    if(r>=250) r=40;
    if(g>=200) g=30;
    if(b<=20)  b=250;
 }

int *drawline(char a)
{

    if(a=='0') {
       static int c[6]={1,2,3,4,5,6};
         l=6;
         return c;
    }
    else if(a=='1'){
       static int  c[2]={4,5};
       l=2;
        return c;
    }
    else if(a=='2'){
        static int c[5]={2,3,5,6,7};
        l=5;
        return c;
    }
    else if(a=='3'){
        static int  c[5]={3,4,5,6,7};
        l=5;
        return c;
    }
    else if(a=='4'){
       static int  c[4]={1,4,5,7};
       l=4;
        return c;
    }
    else if(a=='5'){
        static int c[5]={1,3,4,6,7};
        l=5;
        return c;
    }
    else if(a=='6'){
        static int  c[]={1,2,3,4,6,7};
        l=6;
        return c;
    }
     else if(a=='7'){
       static int  c[3]={6,4,5};
       l=3;
        return c;
    }
    else if(a=='8'){
        static int c[7]={1,2,3,4,5,6,7};
        l=7;
        return c;
    }
    else if(a=='9'){
        static int  c[6]={1,3,4,5,6,7};
        l=6;
        return c;
    }
     else if(a=='A'){
        static int  c[]={1,2,5,4,6,7};
        l=6;
        return c;
    }
     else if(a=='b'){
       static int  c[5]={1,2,3,4,7};
       l=5;
        return c;
    }
    else if(a=='C'){
        static int c[5]={1,2,3,5,6};
        l=5;
        return c;
    }
    else if(a=='D'){
        static int  c[6]={1,2,3,4,5,6};
        l=6;
        return c;
    }
    else if(a=='E'){
        static int c[]={1,2,3,6,7};
        l=5;
        return c;
    }
    else if(a=='F'){
        static int c[]={1,2,6,7};
        l=4;
        return c;
    }
    else {
        static int c[]={0};
        return c;
    }


}
void decrease()
{

    x1-=5;

    if((x1+55*i-5)==0) x1=500;
}
void iDraw() {
	//place your drawing codes here
	iClear();

   int *p;
   int j,k,s;


    int x=x1,y=150;
    iSetColor(150,150,150);
	iRectangle(150,300,200,50);
	if(sett){
        iSetColor(255,255,255);
        iText(160,320,b1);
	}
	if(sett) {
        iSetColor(100,200,50);
        iText(10,10,"Click to activate the box and enter to finish");
	}

	else{
            iText(10,10,"Click to activate the box and enter to finish");
	}
    if(draw){
          iSetColor(r,g,b);
    for(j=0;j<i;j++,x=x+60){
    // if(x==55*(i+1)-5) x=x1;

        p=drawline(a[j]);
        for(k=0;k<l;k++){
                //if(*(k+p)==0) x-=55;
         if(*(k+p)==1)  iFilledRectangle(x,200,3,50);

        if(*(k+p)==2)  iFilledRectangle(x,y,3,50);
        if(*(k+p)==3)  iFilledRectangle(x,y,50,3);
        if(*(k+p)==4)  iFilledRectangle(x+50,y,3,50);
        if(*(k+p)==5)  iFilledRectangle(x+50,y+50,3,50);
        if(*(k+p)==6)  iFilledRectangle(x,y+100,53,3);
        if(*(k+p)==7)  iFilledRectangle(x,y+50,53,3);


     }


    }




    }



}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	//	printf("x = %d, y= %d\n",mx,my);
	//place your codes here


}

void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {


	if((mx>=150 &&mx<=350)&&(my>=300&&my<=350)) mode=1,sett=1;






	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {

	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {

   int j;
    if(mode)
    {
        if(key=='\r'){
                for(j=0;j<st;j++){
                    a[j]=b1[j];
                    b1[j]=0;

                }
                i=st;


          st=0;
         draw=1;
      sett=0;
         de=1;
         if(de==1){
            //printf("%s\n",a);
            //exit(0);}

        }
        }
        else {
            b1[st]=key;

            st++;

        }
    }

}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}


int main() {
	//place your own initialization codes here.

    iSetTimer(50,decrease);
    iSetTimer(100,colour_change);
	iInitialize(500, 500, "Text");

	return 0;
}
