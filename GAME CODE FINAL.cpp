#include <simplecpp>

class Pinball
{
public:
    Circle c;
    int x;
    int y;
    int r;
    int m,s;
    Pinball(int x1, int y1, int r1)
    {
        Circle c(x,y,r);
        x=x1;
        y=y1;
        r=r1;
        c.setColor(COLOR("red"));
        c.setFill();
    };

    void getcoordinates()  //to get the co-ordinates of the ball
    {
        cout<< x <<" "<<y<<endl;
    }

    void turn(bool initdir, int b) //to turn the ball in the right direction after
    {
        //hitting the bumper
        switch(b)
        {
        case 1:
            if(initdir) c.right(270);
            else c.right(90);
            break;
        case 2:
            if(initdir) c.right(90);
            else c.right(270);
            break;
        }
    }

    void forward(bool initdir, int b)  //to move the ball forward if their is no bumper
    {
        if(b==1)   //for the ball when moving down
        {
            if(initdir)
            {
                c.forward(80);
                y=y+80;
            }
            else
            {
                c.forward(80);
                x=x+80;
            }
        }
        if(b==2)   //for the ball when moving right
        {
            if(initdir)
            {
                c.forward(80);
                x=x+80;
            }
            else
            {
                c.forward(80);
                y=y+80;
            }
        }
        if(b==3)   //for the ball when moving up
        {
            if(initdir)
            {
                c.forward(80);
                y=y-80;
            }
            else
            {
                c.forward(80);
                x=x-80;
            }
        }
        if(b==4)   //for the ball when moving left
        {
            if(initdir)
            {
                c.forward(80);
                x=x-80;
            }
            else
            {
                c.forward(80);
                y=y-80;
            }
        }


    }
};
////////////////1=up; 2=down,3=left,4=right///////////////

////////////////////////////////////////////////
////////////////////////////////////

main_program
{
    initCanvas("PINBALL RECALL",1300,650);


    Rectangle r1(650,325,1300,650);
    r1.setColor(COLOR (45,120,100));
    r1.setFill();

home:
    Rectangle r2(650,325,200,50);  //for creating the home page of the game
    r2.setColor(COLOR("white"));
    r2.setFill();
    settextstyle(10,0,2);               //to create the options in the home page
    Text t1(650,325,"NEW GAME");        //of the game
    Rectangle r3(650,375,200,50);
    r3.setColor(COLOR("white"));
    r3.setFill();
    Text t2(650,375,"HOW TO PLAY");
    Rectangle e(650,425,200,50);
    e.setColor(COLOR("white"));
    e.setFill();
    Text ex(650,425,"EXIT");

/////////////////////////////////////////////////////

    while(true)
    {
        int pos=getClick();
        int cx=pos/65536;
        int cy=pos%65536;
        if(cx>550&&cx<750&&cy>350&&cy<400)  //instructions for the game(how to play)
        {
            r2.hide();
            r3.hide();
            t1.hide();
            t2.hide();
            e.hide();
            ex.hide();
            Text t4(650,50,"HOW TO PLAY");
            Rectangle r4(650,325,750,50);
            Rectangle b_back(50,500,50,50);
            b_back.setColor(COLOR("WHITE"));
            b_back.setFill();
            Text back(50,500,"back");
            Rectangle g_home(1250,500,50,50);
            g_home.setColor(COLOR("WHITE"));
            g_home.setFill();
            Text home(1250,500,"home");
            r4.setColor(COLOR("white"));
            r4.setFill();

prev1:
            Text t3(650,325,"click to continue");
            int
            getpos1=getClick(),getposx1=getpos1/65536,getposy1=getpos1%65536;
            if(getposx1>=25&&getposx1<=75&&getposy1>=475&&getposy1<=525)
            {
                goto home;
            }
            //for the help menu page
            if(getposx1>=1225&&getposx1<=1275&&getposy1>=475&&getposy1<=525)
            {
                goto home;
            }
            t3.hide();

prev2:
            Text t5(650,325,"You will have a 6*6 matrix");
            getpos1=getClick(),getposx1=getpos1/65536,getposy1=getpos1%65536;
            if(getposx1>=25&&getposx1<=75&&getposy1>=475&&getposy1<=525)
            {
                goto prev1;
            }
            if(getposx1>=1225&&getposx1<=1275&&getposy1>=475&&getposy1<=525)
            {
                goto home;
            }
            t5.hide();

prev3:
            Text t6(650,325,"Bumpers will appear on this layout for 3s");
            getpos1=getClick(),getposx1=getpos1/65536,getposy1=getpos1%65536;
            if(getposx1>=25&&getposx1<=75&&getposy1>=475&&getposy1<=525)
            {
                goto prev2;
            }
            if(getposx1>=1225&&getposx1<=1275&&getposy1>=475&&getposy1<=525)
            {
                goto home;
            }
            t6.hide();

prev4:
            Text t7(650,325,"Remember their position and orientation");
            getpos1=getClick(),getposx1=getpos1/65536,getposy1=getpos1%65536;
            if(getposx1>=25&&getposx1<=75&&getposy1>=475&&getposy1<=525)
            {
                goto prev3;
            }
            if(getposx1>=1225&&getposx1<=1275&&getposy1>=475&&getposy1<=525)
            {
                goto home;
            }
            t7.hide();

prev5:
            Text t8(650,325,"Then hole from which pinball starts is shown");
            getpos1=getClick(),getposx1=getpos1/65536,getposy1=getpos1%65536;
            if(getposx1>=25&&getposx1<=75&&getposy1>=475&&getposy1<=525)
            {
                goto prev4;
            }
            if(getposx1>=1225&&getposx1<=1275&&getposy1>=475&&getposy1<=525)
            {
                goto home;
            }
            t8.hide();
            Text t9(650,325,"Use your memory to predict hole into which pinball goes");
            getpos1=getClick(),getposx1=getpos1/65536,getposy1=getpos1%65536;
            if(getposx1>=25&&getposx1<=75&&getposy1>=475&&getposy1<=525)
            {
                goto prev5;
            }
            if(getposx1>=1225&&getposx1<=1275&&getposy1>=475&&getposy1<=525)
            {
                goto home;
            }
            t9.hide();
            Text t10(650,325,"Have fun!!!");
            getpos1=getClick(),getposx1=getpos1/65536,getposy1=getpos1%65536;
            if(getposx1>=25&&getposx1<=75&&getposy1>=475&&getposy1<=525)
            {
                goto home;
            }
            t10.hide();
            r4.hide();
            t4.hide();
            r2.show();
            r3.show();
            t1.show();
            t2.show();
            ex.show();
            e.show();

        }

b:
        bool again=true;
        int score=0;

        {


            if(cx>550&&cx<750&&cy>300&&cy<350)   //to start the game
            {

                r2.hide();
                r3.hide();
                t1.hide();
                t2.hide();
                ex.hide();
                e.hide();
                Rectangle r5(650,325,620,620);
                r5.setColor(COLOR(205,200,0));
                r5.setFill();
                Rectangle r6(650,325,480,480); //to make the rectangular boxes
                r6.setColor(COLOR("red"));
                r6.setFill();
                Rectangle r7(1150,25,300,50);
                r7.setColor(COLOR("white"));
                r7.setFill();
                Text t11(1050,25,"score:");
                Line l1(490,85,490,565);
                Line l2(570,85,570,565);
                Line l3(650,85,650,565);
                Line l4(730,85,730,565);
                Line l5(810,85,810,565);
                Line l6(410,165,890,165);
                Line l7(410,245,890,245);
                Line l8(410,325,890,325);
                Line l9(410,405,890,405);
                Line l10(410,485,890,485);  //to make the 6*6 grid
                Circle c[24];
                while(again==true)
                {
                    int bumper[36];     // creating the bumpers
                    for(int i=0; i<36; i++)
                    {
                        bumper[i]=0;
                    }                  //intialising the value of bumpers to zero
                    for( int i=0; i<24; i++)
                    {
                        if(i<6)             c[i]=Circle(450+(80*i),45,20);
                        if(i<12 && i>5)     c[i]=Circle(450+80*(i-6),605,20);
                        if(i<18 && i>11)    c[i]=Circle(370,125+80*(i-12),20);
                        if(i<24 && i>17)    c[i]=Circle(930,125+80*(i-18),20);
                    }                  //to create the holes around the grid

                    Text t12(650,325,"click when you are ready");
                    int secret=getClick();
                    t12.hide();
                    Text sc(1250,25,score);  //creating the box for score
                    int i;

                    int x=secret/65536;   //to decide the position of the bumpers

                    if(score>=0&&score<=500)
                    {
                        int ax[3],ay[3],bx[3],by[3];
                        //deciding the no.of bumpers to be arranged on basis of the score
                        for(i=0; i<3; i++)
                        {
                            int y=(x)%36+1;
                            cout<<y<<endl;
                            if(y>=1&&y<=6)     //to arrange the bumpers in 1st row
                            {
                                ax[i]=410+(80*(y-1));
                                ay[i]=85;
                                bx[i]=490+(80*(y-1));
                                by[i]=165;
                                bumper[y-1]=1;  //to mark the existence of bumper
                            }
                            if(y>6&&y<=12)   //to arrange the bumpers in the 2nd row
                            {
                                ax[i]=410+(80*(y-7));
                                ay[i]=165;
                                bx[i]=490+(80*(y-7));
                                by[i]=245;
                                bumper[y-1]=1;   //to mark the existence of bumper
                            }

                            if(y>12&&y<=18)   //to arrange the bumpers in the 3rd row
                            {
                                ax[i]=410+(80*(y-13));
                                ay[i]=245;
                                bx[i]=490+(80*(y-13));
                                by[i]=325;
                                bumper[y-1]=1;  //to mark the existence of bumper

                            }
                            if(y>18&&y<=24)   //to arrange the bumpers in the 4th row
                            {
                                ax[i]=410+(80*(y-19));
                                ay[i]=325;
                                bx[i]=490+(80*(y-19));
                                by[i]=405;
                                bumper[y-1]=1;  //to mark the existence of bumper
                            }

                            if(y>24&&y<=30)   //to arrange the bumpers in the 5th row
                            {
                                ax[i]=410+(80*(y-25));
                                ay[i]=405;
                                bx[i]=490+(80*(y-25));
                                by[i]=485;
                                bumper[y-1]=1;   //to mark the existence of bumper
                            }

                            if(y>30&&y<=36)   //to arrange the bumpers in the 6th row
                            {
                                ax[i]=410+(80*(y-31));
                                ay[i]=485;
                                bx[i]=490+(80*(y-31));
                                by[i]=565;
                                bumper[y-1]=1;   //to mark the existence of bumper
                            }

                            x=x+rand();

                        }
                        Line b1(ax[0],ay[0],bx[0],by[0]);
                        Line b2(ax[1],ay[1],bx[1],by[1]);
                        Line b3(ax[2],ay[2],bx[2],by[2]);
                        //to displayy the lines in the grid
                        wait(5);
                        b1.hide();
                        b2.hide();
                        b3.hide();
                    }

                    if(score>=1000&&score<1500)
                    {
                        int ax[4],ay[4],bx[4],by[4];
                        //increasing the no.of bumpers in accordance
                        //with the score
                        for(i=0; i<4; i++)
                        {
                            int y=(x)%36+1;
                            cout<<y<<endl;
                            if(y>=1&&y<=6)
                            {
                                ax[i]=410+(80*(y-1));
                                ay[i]=85;
                                bx[i]=490+(80*(y-1));
                                by[i]=165;
                                bumper[y-1]=1;
                            }
                            if(y>6&&y<=12)
                            {
                                ax[i]=410+(80*(y-7));
                                ay[i]=165;
                                bx[i]=490+(80*(y-7));
                                by[i]=245;
                                bumper[y-1]=1;
                            }
                            if(y>12&&y<=18)
                            {
                                ax[i]=410+(80*(y-13));
                                ay[i]=245;
                                bx[i]=490+(80*(y-13));
                                by[i]=325;
                                bumper[y-1]=1;
                            }
                            if(y>18&&y<=24)
                            {
                                ax[i]=410+(80*(y-19));
                                ay[i]=325;
                                bx[i]=490+(80*(y-19));
                                by[i]=405;
                                bumper[y-1]=1;
                            }
                            if(y>24&&y<=30)
                            {
                                ax[i]=410+(80*(y-25));
                                ay[i]=405;
                                bx[i]=490+(80*(y-25));
                                by[i]=485;
                                bumper[y-1]=1;
                            }
                            if(y>30&&y<=36)
                            {
                                ax[i]=410+(80*(y-31));
                                ay[i]=485;
                                bx[i]=490+(80*(y-31));
                                by[i]=565;
                                bumper[y-1]=1;
                            }
                            x=x+rand();

                        }
                        Line b1(ax[0],ay[0],bx[0],by[0]);
                        Line b2(ax[1],ay[1],bx[1],by[1]);
                        Line b3(ax[2],ay[2],bx[2],by[2]);
                        Line b4(ax[3],ay[3],bx[3],by[3]);

                        wait(5);
                        b1.hide();
                        b2.hide();
                        b3.hide();
                        b4.hide();
                    }

                    if(score>=1500&&score<2000)
                    {
                        int ax[5],ay[5],bx[5],by[5];
                        for(i=0; i<5; i++)
                        {
                            int y=(x)%36+1;
                            cout<<y<<endl;
                            if(y>=1&&y<=6)
                            {
                                ax[i]=410+(80*(y-1));
                                ay[i]=85;
                                bx[i]=490+(80*(y-1));
                                by[i]=165;
                                bumper[y-1]=1;
                            }
                            if(y>6&&y<=12)
                            {
                                ax[i]=410+(80*(y-7));
                                ay[i]=165;
                                bx[i]=490+(80*(y-7));
                                by[i]=245;
                                bumper[y-1]=1;
                            }
                            if(y>12&&y<=18)
                            {
                                ax[i]=410+(80*(y-13));
                                ay[i]=245;
                                bx[i]=490+(80*(y-13));
                                by[i]=325;
                                bumper[y-1]=1;
                            }
                            if(y>18&&y<=24)
                            {
                                ax[i]=410+(80*(y-19));
                                ay[i]=325;
                                bx[i]=490+(80*(y-19));
                                by[i]=405;
                                bumper[y-1]=1;
                            }
                            if(y>24&&y<=30)
                            {
                                ax[i]=410+(80*(y-25));
                                ay[i]=405;
                                bx[i]=490+(80*(y-25));
                                by[i]=485;
                                bumper[y-1]=1;
                            }
                            if(y>30&&y<=36)
                            {
                                ax[i]=410+(80*(y-31));
                                ay[i]=485;
                                bx[i]=490+(80*(y-31));
                                by[i]=565;
                                bumper[y-1]=1;
                            }
                            x=x+rand();

                        }
                        Line b1(ax[0],ay[0],bx[0],by[0]);
                        Line b2(ax[1],ay[1],bx[1],by[1]);
                        Line b3(ax[2],ay[2],bx[2],by[2]);
                        Line b4(ax[3],ay[3],bx[3],by[3]);
                        Line b5(ax[4],ay[4],bx[4],by[4]);

                        wait(5);
                        b1.hide();
                        b2.hide();
                        b3.hide();
                        b4.hide();
                        b5.hide();
                    }
                    if(score>=2000&&score<=2500)
                    {
                        int ax[6],ay[6],bx[6],by[6];
                        for(i=0; i<6; i++)
                        {
                            int y=(x)%36+1;
                            cout<<y<<endl;
                            if(y>=1&&y<=6)
                            {
                                ax[i]=410+(80*(y-1));
                                ay[i]=85;
                                bx[i]=490+(80*(y-1));
                                by[i]=165;
                                bumper[y-1]=1;
                            }
                            if(y>6&&y<=12)
                            {
                                ax[i]=410+(80*(y-7));
                                ay[i]=165;
                                bx[i]=490+(80*(y-7));
                                by[i]=245;
                                bumper[y-1]=1;
                            }
                            if(y>12&&y<=18)
                            {
                                ax[i]=410+(80*(y-13));
                                ay[i]=245;
                                bx[i]=490+(80*(y-13));
                                by[i]=325;
                                bumper[y-1]=1;
                            }
                            if(y>18&&y<=24)
                            {
                                ax[i]=410+(80*(y-19));
                                ay[i]=325;
                                bx[i]=490+(80*(y-19));
                                by[i]=405;
                                bumper[y-1]=1;
                            }
                            if(y>24&&y<=30)
                            {
                                ax[i]=410+(80*(y-25));
                                ay[i]=405;
                                bx[i]=490+(80*(y-25));
                                by[i]=485;
                                bumper[y-1]=1;
                            }
                            if(y>30&&y<=36)
                            {
                                ax[i]=410+(80*(y-31));
                                ay[i]=485;
                                bx[i]=490+(80*(y-31));
                                by[i]=565;
                                bumper[y-1]=1;
                            }
                            x=x+rand();

                        }
                        Line b1(ax[0],ay[0],bx[0],by[0]);
                        Line b2(ax[1],ay[1],bx[1],by[1]);
                        Line b3(ax[2],ay[2],bx[2],by[2]);
                        Line b4(ax[3],ay[3],bx[3],by[3]);
                        Line b5(ax[4],ay[4],bx[4],by[4]);
                        Line b6(ax[5],ay[5],bx[5],by[5]);
                        wait(5);
                        b1.hide();
                        b2.hide();
                        b3.hide();
                        b4.hide();
                        b5.hide();
                        b6.hide();
                    }

                    if(score>=3000&&score<=4000)
                    {
                        int ax[7],ay[7],bx[7],by[7];
                        for(i=0; i<7; i++)
                        {
                            int y=((x)%36)+1;
                            cout<<y<<endl;
                            if(y>=1&&y<=6)
                            {
                                ax[i]=410+(80*(y-1));
                                ay[i]=85;
                                bx[i]=490+(80*(y-1));
                                by[i]=165;
                                bumper[y-1]=1;
                            }
                            if(y>6&&y<=12)
                            {
                                ax[i]=410+(80*(y-7));
                                ay[i]=165;
                                bx[i]=490+(80*(y-7));
                                by[i]=245;
                                bumper[y-1]=1;
                            }
                            if(y>12&&y<=18)
                            {
                                ax[i]=410+(80*(y-13));
                                ay[i]=245;
                                bx[i]=490+(80*(y-13));
                                by[i]=325;
                                bumper[y-1]=1;
                            }
                            if(y>18&&y<=24)
                            {
                                ax[i]=410+(80*(y-19));
                                ay[i]=325;
                                bx[i]=490+(80*(y-19));
                                by[i]=405;
                                bumper[y-1]=1;
                            }
                            if(y>24&&y<=30)
                            {
                                ax[i]=410+(80*(y-25));
                                ay[i]=405;
                                bx[i]=490+(80*(y-25));
                                by[i]=485;
                                bumper[y-1]=1;
                            }
                            if(y>30&&y<=36)
                            {
                                ax[i]=410+(80*(y-31));
                                ay[i]=485;
                                bx[i]=490+(80*(y-31));
                                by[i]=565;
                                bumper[y-1]=1;
                            }
                            x=x+rand();
                        }
                        Line b1(ax[0],ay[0],bx[0],by[0]);
                        Line b2(ax[1],ay[1],bx[1],by[1]);
                        Line b3(ax[2],ay[2],bx[2],by[2]);
                        Line b4(ax[3],ay[3],bx[3],by[3]);
                        Line b5(ax[4],ay[4],bx[4],by[4]);
                        Line b6(ax[5],ay[5],bx[5],by[5]);
                        Line b7(ax[6],ay[6],bx[6],by[6]);
                        wait(5);
                        b1.hide();
                        b2.hide();
                        b3.hide();
                        b4.hide();
                        b5.hide();
                        b6.hide();
                        b7.hide();
                    }
                    if(score>=4500&&score<=5000)
                    {
                        int ax[8],ay[8],bx[8],by[8];
                        for(i=0; i<8; i++)
                        {
                            int y=((x)%36)+1;
                            cout<<y<<endl;
                            if(y>=1&&y<=6)
                            {
                                ax[i]=410+(80*(y-1));
                                ay[i]=85;
                                bx[i]=490+(80*(y-1));
                                by[i]=165;
                                bumper[y-1]=1;
                            }
                            if(y>6&&y<=12)
                            {
                                ax[i]=410+(80*(y-7));
                                ay[i]=165;
                                bx[i]=490+(80*(y-7));
                                by[i]=245;
                                bumper[y-1]=1;
                            }
                            if(y>12&&y<=18)
                            {
                                ax[i]=410+(80*(y-13));
                                ay[i]=245;
                                bx[i]=490+(80*(y-13));
                                by[i]=325;
                                bumper[y-1]=1;
                            }
                            if(y>18&&y<=24)
                            {
                                ax[i]=410+(80*(y-19));
                                ay[i]=325;
                                bx[i]=490+(80*(y-19));
                                by[i]=405;
                                bumper[y-1]=1;
                            }
                            if(y>24&&y<=30)
                            {
                                ax[i]=410+(80*(y-25));
                                ay[i]=405;
                                bx[i]=490+(80*(y-25));
                                by[i]=485;
                                bumper[y-1]=1;
                            }
                            if(y>30&&y<=36)
                            {
                                ax[i]=410+(80*(y-31));
                                ay[i]=485;
                                bx[i]=490+(80*(y-31));
                                by[i]=565;
                                bumper[y-1]=1;
                            }
                            x=x+rand();
                        }
                        Line b1(ax[0],ay[0],bx[0],by[0]);
                        Line b2(ax[1],ay[1],bx[1],by[1]);
                        Line b3(ax[2],ay[2],bx[2],by[2]);
                        Line b4(ax[3],ay[3],bx[3],by[3]);
                        Line b5(ax[4],ay[4],bx[4],by[4]);
                        Line b6(ax[5],ay[5],bx[5],by[5]);
                        Line b7(ax[6],ay[6],bx[6],by[6]);
                        Line b8(ax[7],ay[7],bx[7],by[7]);
                        wait(5);
                        b1.hide();
                        b2.hide();
                        b3.hide();
                        b4.hide();
                        b5.hide();
                        b6.hide();
                        b7.hide();
                        b8.hide();
                    }
                    if(score>5000)
                    {
                        int ax[9],ay[9],bx[9],by[9];
                        for(i=0; i<9; i++)
                        {
                            int y=((x)%36)+1;
                            cout<<y<<endl;
                            if(y>=1&&y<=6)
                            {
                                ax[i]=410+(80*(y-1));
                                ay[i]=85;
                                bx[i]=490+(80*(y-1));
                                by[i]=165;
                                bumper[y-1]=1;
                            }
                            if(y>6&&y<=12)
                            {
                                ax[i]=410+(80*(y-7));
                                ay[i]=165;
                                bx[i]=490+(80*(y-7));
                                by[i]=245;
                                bumper[y-1]=1;
                            }
                            if(y>12&&y<=18)
                            {
                                ax[i]=410+(80*(y-13));
                                ay[i]=245;
                                bx[i]=490+(80*(y-13));
                                by[i]=325;
                                bumper[y-1]=1;
                            }
                            if(y>18&&y<=24)
                            {
                                ax[i]=410+(80*(y-19));
                                ay[i]=325;
                                bx[i]=490+(80*(y-19));
                                by[i]=405;
                                bumper[y-1]=1;
                            }
                            if(y>24&&y<=30)
                            {
                                ax[i]=410+(80*(y-25));
                                ay[i]=405;
                                bx[i]=490+(80*(y-25));
                                by[i]=485;
                                bumper[y-1]=1;
                            }
                            if(y>30&&y<=36)
                            {
                                ax[i]=410+(80*(y-31));
                                ay[i]=485;
                                bx[i]=490+(80*(y-31));
                                by[i]=565;
                                bumper[y-1]=1;
                            }
                            x=x+rand();
                        }
                        Line b1(ax[0],ay[0],bx[0],by[0]);
                        Line b2(ax[1],ay[1],bx[1],by[1]);
                        Line b3(ax[2],ay[2],bx[2],by[2]);
                        Line b4(ax[3],ay[3],bx[3],by[3]);
                        Line b5(ax[4],ay[4],bx[4],by[4]);
                        Line b6(ax[5],ay[5],bx[5],by[5]);
                        Line b7(ax[6],ay[6],bx[6],by[6]);
                        Line b8(ax[7],ay[7],bx[7],by[7]);
                        Line b9(ax[8],ay[8],bx[8],by[8]);
                        wait(5);
                        b1.hide();
                        b2.hide();
                        b3.hide();
                        b4.hide();
                        b5.hide();
                        b6.hide();
                        b7.hide();
                        b8.hide();
                        b9.hide();
                    }


                    int z=rand();  //to take the random input
                    int k=z%24+1;
                    c[k-1].setFill();  //to decide the hole where the ball starts
                    int ans=getClick();
                    int ansx=ans/65536;
                    int ansy=ans%65536;   //to get the co-ordinates of the answer hole
                    Circle playerans(ansx,ansy,5);
                    playerans.setColor(COLOR("BLUE"));
                    playerans.setFill();  //to indicate the click position
                    //the below program is to direct and determine the path of the ball
                    if(k>=1&&k<=6)
                    {
                        Pinball p(450+(k-1)*80,45,20);  //to create the pinball in accordance
                        int j=k;    //to indicate the box
                        bool initdir=false;
                        p.turn(initdir,1);
                        initdir=!initdir;
                        while(j<=36)
                        {
                            if((initdir==false&&j%6==1))
                            {

                                break;
                            }
                            if(bumper[j-1]==0)  //checks whether there is a bumper
                            {

                                p.forward(initdir,1);

                                if(initdir)j=j+6;
                                else
                                {
                                    j=j+1;
                                }

                            }
                            else   //and moves in accordance if there is a bumper
                            {

                                p.forward(initdir,1);
                                p.turn(initdir,1);
                                initdir=!initdir;

                                if(initdir)j=j+6;
                                else
                                {
                                    j=j+1;
                                }


                            }

                            Circle path(p.x,p.y,20);
                            path.setFill();
                            wait(0.1);
                        }
                        p.forward(initdir,1);
                        Circle final(p.x,p.y,20);
                        final.setFill();
                        wait(0.1);
                        if(ansx>=p.x-20&&ansx<=p.x+20&&ansy>=p.y-20&&ansy<=p.y+20)
                        {
                            Text result(650,325,"great job!!click to continue");
                            score=score+500;
                            getClick();
                        }      //if the answer is correct
                        else  //if the answer is wrong
                        {
                            Text sorry(650,325,"sorry!! wanna try again??");
                            Rectangle ryes(600,250,50,50);
                            Text yes(600,250,"yes");
                            ryes.setColor(COLOR("BLUE"));
                            ryes.setFill();
                            Rectangle rno(700,250,50,50);
                            rno.setColor(COLOR("BLUE"));
                            rno.setFill();
                            Text no(700,250,"no");
l3:
                            int temp =getClick();
                            int tempx=temp/65536;
                            int tempy=temp%65536;
                            if(tempx>=575&&tempx<=625&&tempy>=225&&tempy<=275)
                            {
                                goto b;
                            }
                            else if(tempx>=675&&tempx<=725&&tempy>=225&&tempy<=275)
                            {
                                goto a;
                            }
                            else
                            {
                                goto l3;
                            }
                        }
                    }
                    if(k>12&&k<19)
                    {
                        Pinball p(370,125+80*(k-13),20);
                        int j=(k-13)*6+1;
                        bool initdir=true;
                        do
                        {

                            if(bumper[j-1]==0)
                            {

                                p.forward(initdir,2);
                                wait(0.3);
                                if(initdir)j=j+1;
                                else
                                {
                                    j=j+6;
                                }

                            }
                            else
                            {

                                p.forward(initdir,2);
                                p.turn(initdir,2);
                                initdir=!initdir;

                                if(initdir)j=j+1;
                                else
                                {
                                    j=j+6;
                                }


                            }

                            Circle path2(p.x,p.y,20);
                            path2.setFill();
                            wait(0.1);
                        }
                        while(p.x>=410&&p.x<=880&&p.y>=85&&p.y<=565);



                        if(ansx>=p.x-20&&ansx<=p.x+20&&ansy>=p.y-20&&ansy<p.y+20)
                        {
                            Text result(650,325,"great job!!click to continue");
                            score=score+500;
                            getClick();
                            again=true;
                        }
                        else
                        {
                            Text sorry(650,325,"sorry!! wanna try again??");
                            Rectangle ryes(600,250,50,50);
                            ryes.setColor(COLOR("BLUE"));
                            ryes.setFill();
                            Text yes(600,250,"yes");
                            Rectangle rno(700,250,50,50);
                            rno.setColor(COLOR("BLUE"));
                            rno.setFill();
                            Text no(700,250,"no");
l2:
                            int temp =getClick();
                            int tempx=temp/65536;
                            int tempy=temp%65536;
                            if(tempx>=575&&tempx<=625&&tempy>=225&&tempy<=275)
                            {
                                goto b;
                            }
                            else if(tempx>=675&&tempx<=725&&tempy>=225&&tempy<=275)
                            {
                                goto a;
                            }
                            else
                            {
                                goto l2;
                            }
                        }
                    }
                    if(k>=7&&k<13)
                    {
                        Pinball p(450+(k-7)*80,605,20);
                        int j=k+24;
                        bool initdir=true;

                        do
                        {

                            if(bumper[j-1]==0)
                            {

                                p.forward(initdir,3);

                                if(initdir)j=j-6;
                                else
                                {
                                    j=j-1;
                                }


                            }

                            else
                            {

                                p.forward(initdir,3);
                                p.turn(initdir,1);
                                initdir=!initdir;

                                if(initdir)j=j-6;
                                else
                                {
                                    j=j-1;
                                }

                            }

                            Circle path3(p.x,p.y,20);
                            path3.setFill();
                            wait(0.1);
                        }
                        while(p.x>=410&&p.x<=880&&p.y>=85&&p.y<=565);



                        if(ansx>=p.x-20&&ansx<=p.x+20&&ansy>=p.y-20&&ansy<p.y+20)
                        {
                            Text result(650,325,"great job!!click to continue");
                            score=score+500;
                            getClick();
                            again=true;
                        }
                        else
                        {
                            Text sorry(650,325,"sorry!! wanna try again??");
                            Rectangle ryes(600,250,50,50);
                            ryes.setColor(COLOR("BLUE"));
                            ryes.setFill();
                            Text yes(600,250,"yes");
                            Rectangle rno(700,250,50,50);
                            rno.setColor(COLOR("BLUE"));
                            rno.setFill();
                            Text no(700,250,"no");
l1:
                            int temp=getClick();
                            int tempx=temp/65536;
                            int tempy=temp%65536;
                            if(tempx>=575&&tempx<=625&&tempy>=225&&tempy<=275)
                            {
                                goto b;
                            }
                            else if(tempx>=675&&tempx<=725&&tempy>=225&&tempy<=275)
                            {
                                goto a;
                            }
                            else
                            {
                                goto l1;
                            }

                        }
                    }
                    if(k>=19&&k<=24)
                    {
                        Pinball p(930,125+80*(k-19),20);
                        int j=(k-18)*6;
                        bool initdir=true;
                        wait(0.1);
                        do
                        {

                            if(bumper[j-1]==0)
                            {
                                p.forward(initdir,4);
                                if(initdir)j=j-1;
                                else
                                {
                                    j=j-6;
                                }


                            }
                            else
                            {
                                p.forward(initdir,4);
                                p.turn(initdir,2);
                                initdir=!initdir;
                                if(initdir)j=j-1;
                                else
                                {
                                    j=j-6;
                                }

                            }

                            Circle path4(p.x,p.y,20);
                            path4.setFill();
                            wait(0.1);
                        }
                        while(p.x>=410&&p.x<=880&&p.y>=85&&p.y<=565);



                        if(ansx>=p.x-20&&ansx<=p.x+20&&ansy>=p.y-20&&ansy<p.y+20)
                        {
                            Text result(650,325,"great job!!click to continue");
                            score=score+500;
                            getClick();
                            again=true;
                        }
                        else
                        {
                            Text sorry(650,325,"sorry!! wanna try again??");
                            Rectangle ryes(600,250,50,50);
                            ryes.setColor(COLOR("BLUE"));
                            ryes.setFill();
                            Text yes(600,250,"yes");
                            Rectangle rno(700,250,50,50);
                            rno.setColor(COLOR("BLUE"));
                            rno.setFill();
                            Text no(700,250,"no");
l:
                            int temp =getClick();
                            int tempx=temp/65536;
                            int tempy=temp%65536;
                            if(tempx>=575&&tempx<=625&&tempy>=225&&tempy<=275)
                            {
                                goto b;
                            }
                            else if(tempx>=675&&tempx<=725&&tempy>=225&&tempy<=275)
                            {
                                goto a;
                            }
                            else
                            {
                                goto l;
                            }

                        }
                    }
                }
            }
        }
        if(cx>550&&cx<750&&cy>400&&cy<450)
        {
            goto a;
        }


    }


a:
    ;
}
