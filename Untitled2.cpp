#include "iGraphics.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int bctrl=0,ball_x,mainmenu=1,k, ball_y,ball_direction,stick_x=200,stick_y,random,counter,play,pre,bulbul=0,ba[22][17],bi,bj,bk,bl,bm,bn,
bdx,bdy;
int dx, dy,l2_ch[26],c,z,i,j,n,d,level,singular,ins,over,quit,resume,high_score=0,check,dec[15][26];
char result[3],life[1],High_score[3],bins[2000],bch,blevel[2],blife[2];
bool bin1,bin2;

FILE *save;

void direction_change()
{
    if(ball_direction==5)
        ball_direction=4;
    else if(ball_direction==4)
        ball_direction=5;
    else if(ball_direction==1)
        ball_direction=2;
    else if(ball_direction==2)
        ball_direction=1;
    else if(ball_direction==6)
        ball_direction=3;
    else if(ball_direction==3)
        ball_direction=6;
}

void iDraw()
{
    if(mainmenu==1)
    {
        iClear();
        iSetColor(10,100,100);
        iFilledRectangle(0,0,1500,750);
        iSetColor(255,255,255);
        iText(720,600,"DX BALL",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(720,540,"Created by",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(620,500,"MD. MAHBUBUL HAQUE(1605051)",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(790,470,"&",GLUT_BITMAP_HELVETICA_18);
        iText(620,440,"HASAN NAJIB MAHMUD(1605049)",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iRectangle(300,200,70,30);
        iRectangle(1000,200,60,30);
        iRectangle(495,200,190,30);
        iRectangle(750,200,160,30);
        iSetColor(255,255,255);
        iText(305,205,"PLAY",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(500,205,"INSTRUCTIONS",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(755,205,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1000,205,"QUIT",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(ins==1)
    {
        iSetColor(10,100,100);
        iFilledRectangle(0,0,1500,750);
        iSetColor(255,255,255);
        iText(600,600,"INSTRUCTIONS",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(200,500,"You have to clear the window by touching bricks with the ball.You can control the ball with the bar at the bottom of the screen.",GLUT_BITMAP_HELVETICA_18);
        iText(200,450,"You can move the bar either pressing direction keys of the keyboard or by moving the mouse.While using mouse,you must keep",GLUT_BITMAP_HELVETICA_18);
        iText(200,400,"the left button pressed.There is some bricks that can't be broken.There is also some that needs three touch to be broken.",GLUT_BITMAP_HELVETICA_18);
        iText(200,350,"If the ball misses the bar,then you will have one life down.You will have two chances like that.",GLUT_BITMAP_HELVETICA_18);

        iRectangle(1000,100,80,30);
        iText(1005,105,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    if(play==1)
    {
        iClear();
        iSetColor(10,100,100);
        iFilledRectangle(0,0,1500,750);
        iSetColor(255,255,255);
        iText(580,510,"SELECT LEVEL",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(600,400,100,30);
        iText(600,405,"LEVEL 1",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(600,300,100,30);
        iText(600,305,"LEVEL 2",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(600,200,100,30);
        iText(600,205,"LEVEL 3",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(600,100,100,30);
        iText(600,105,"RESUME",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(1000,100,80,30);
        iText(1005,105,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    if(level!=0||resume!=0)
    {
        if(c>0)
        {
            if(c!=pre)
            {
                 pre--;
                 iPauseTimer(0);
            }
            iClear();
            iSetColor(0,255,0);
            iFilledRectangle(0,0,1500,750);
            iSetColor(0,0,0);
            iFilledRectangle(0,720,1500,30);
            iSetColor(255,10,10);
            iFilledCircle(ball_x,ball_y,8);
            iSetColor(255,0,0);
            iFilledRectangle(stick_x,stick_y,200,20);
            int k,m,l=650,r,g,b;
            r=255;g=0;b=255;

            for(m=0;m<=14;m++)
           {
                iSetColor(r,g,b);
                i=180;
                j=0;
               for(k=1;k<=26;k++)
                    {
                        if(level==1&&m==14&dec[m][j]==1)
                        {
                            iSetColor(255,250,250);
                            iFilledRectangle(i,l,40,15);
                        }
                        if(level==2&&m==14)
                        {
                            if(dec[m][j]==1&&l2_ch[j]==0)
                            {
                                iSetColor(255,255,255);
                                iFilledRectangle(i,l,40,15);
                            }
                            else if(dec[m][j]==1&&l2_ch[j]==1)
                            {
                                iSetColor(10,100,255);
                                iFilledRectangle(i,l,40,15);
                            }
                            else if(dec[m][j]==1&&l2_ch[j]==2)
                            {
                                iSetColor(0,0,255);
                                iFilledRectangle(i,l,40,15);
                            }
                        }
                        if(level==2&&m!=14&&dec[m][j]==1)
                        {
                            if((m+j)%4==0)
                                iSetColor(0,0,255);
                            else if((m+j)%4==1)
                                iSetColor(255,0,0);
                            else if((m+j)%4==2)
                                iSetColor(255,0,130);
                            else if((m+j)%4==3)
                                iSetColor(0,0,0);
                            iFilledRectangle(i,l,40,15);
                        }
                        if(dec[m][j]==1&&m!=14&&level==1)
                        {
                            iFilledRectangle(i,l,40,15);
                        }

                        if(level==3&&dec[m][j]==1)
                        {
                            if((m+j)%4==0)
                                iSetColor(0,0,255);
                            else if((m+j)%4==1)
                                iSetColor(255,0,0);
                            else if((m+j)%4==2)
                                iSetColor(255,0,130);
                            else if((m+j)%4==3)
                                iSetColor(0,0,0);
                            iFilledRectangle(i,l,40,15);
                        }

                        i+=41;
                        j++;
                    }
                    l-=16;
                    r-=25;
                    g+=1;
                    b-=25;
                }
                iSetColor(255,255,255);
                result[0]=(counter/100)+'0';
                result[1]=((counter%100)/10)+'0';
                result[2]=((counter%100)%10)+'0';
                blevel[0]=level+'0';
                blevel[1]='\0';
                blife[0]=c+'0';
                blife[1]='\0';

               iFilledRectangle(1330,720,170,30);
               iText(10,730,"SCORE : ",GLUT_BITMAP_TIMES_ROMAN_24);
               iText(130,730,result,GLUT_BITMAP_TIMES_ROMAN_24);
               iText(400,730,"LEVEL : " ,GLUT_BITMAP_TIMES_ROMAN_24);
               iText(510,730,blevel,GLUT_BITMAP_TIMES_ROMAN_24);
               iText(800,730,"LIFE : " ,GLUT_BITMAP_TIMES_ROMAN_24);
              iText(910,730,blife,GLUT_BITMAP_TIMES_ROMAN_24);
               iSetColor(0,0,0);
               iText(1390,730,"BACK" ,GLUT_BITMAP_TIMES_ROMAN_24);

        }
        else
       {
            iClear();
            iSetColor(10,100,100);
            iFilledRectangle(0,0,1500,750);
            iSetColor(255,0,0);
            iText(600,350,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(600,300,"YOUR SCORE IS",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(790,300,result,GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(200,200,160,40);
            iText(205,210,"PLAY AGAIN",GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(900,200,300,40);
            iText(905,210,"RETURN TO MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
            iPauseTimer(0);
        }
    }
    if(over==1)
    {
        iClear();
        iSetColor(10,100,100);
        iFilledRectangle(0,0,1500,750);
        iSetColor(255,0,0);
        iText(400,400,"YOU HAVE COMPLETED THE LEVEL.CONGRATS!!!!",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(400,350,"IF YOU WANT TO PLAY ANOTHER TIME,PRESS PLAY AGAIN.",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iRectangle(500,300,200,60);
        iText(505,305,"PLAY AGAIN",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(quit==1)
    {
      iSetColor(55,155,255);
      iFilledRectangle(500,300,450,200);
      iSetColor(0,0,0);
      iText(520,450,"DO YOU WANT TO SAVE YOUR PROGRESS?",GLUT_BITMAP_HELVETICA_18);
      iText(520,400,"OTHERWISE YOUR PROGRESS WILL BE LOST",GLUT_BITMAP_HELVETICA_18);
      iSetColor(255,255,255);
      iFilledRectangle(530,320,60,20);
      iFilledRectangle(850,320,85,20);
      iSetColor(0,0,0);
      iText(535,325,"SAVE",GLUT_BITMAP_HELVETICA_12);
      iText(855,325,"DON'T SAVE",GLUT_BITMAP_HELVETICA_12);
    }

    if(high_score==1)
    {
        iSetColor(10,100,100);
        iFilledRectangle(0,0,1500,750);
        iSetColor(255,255,255);

        FILE *high;
        high=fopen("High_score_1.txt","r");
        fscanf(high,"%d",&check);
        fclose(high);

        High_score[0]=(check/100)+'0';
        High_score[1]=((check%100)/10)+'0';
        High_score[2]=((check%100)%10)+'0';
        iText(20,350,"The high score for level 1:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(300,350,High_score,GLUT_BITMAP_TIMES_ROMAN_24);


        high=fopen("High_score_2.txt","r");
        fscanf(high,"%d",&check);
        fclose(high);

        High_score[0]=(check/100)+'0';
        High_score[1]=((check%100)/10)+'0';
        High_score[2]=((check%100)%10)+'0';
        iText(20,300,"The high score for level 2:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(300,300,High_score,GLUT_BITMAP_TIMES_ROMAN_24);


        high=fopen("High_score_3.txt","r");
        fscanf(high,"%d",&check);
        fclose(high);

        High_score[0]=(check/100)+'0';
        High_score[1]=((check%100)/10)+'0';
        High_score[2]=((check%100)%10)+'0';
        iText(20,250,"The high score for level 3:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(300,250,High_score,GLUT_BITMAP_TIMES_ROMAN_24);

        iRectangle(900,100,300,40);
        iText(905,110,"RETURN TO MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
    }
}

void iMouseMove(int mx,int my)
{
    if(mx>=1300)
        stick_x=1300;
    else if(mx<0)
        stick_x=0;
    else
        stick_x=mx;
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
	    if(mainmenu==1)
        {
            if(mx>=300&&mx<=370&&my>=200&&my<=230)
            {
                play=1;
                mainmenu=0;
            }
            else if(mx>=1000&&mx<=1060&&my>=200&&my<=230)
                exit(0);
            else if(mx>=495&&mx<=685&&my>=200&&my<=230)
            {
                ins=1;
                mainmenu=0;
            }
            else if(mx>=750&&mx<=910&&my>=200&&my<=230)
            {
                high_score=1;
                mainmenu=0;
            }
        }
        if(ins==1)
        {
            if(mx>=1000&&mx<=1080&&my>=100&&my<=130)
            {
                ins=0;
                mainmenu=1;
            }
        }
        if(play==1)
        {
            if(mx>=600&&mx<=700&&my>=400&&my<=460)
            {
                level=1;
                bin1=true;
                bin2=false;
                c=2;
                pre=2;
                counter=0;
                resume=0;
                mainmenu=0;
                play=0;
                iResumeTimer(0);
            }
             if(mx>=600&&mx<=700&&my>=300&&my<=360)
            {
                 level=2;
                 bin1=true;
                bin2=false;
                c=2;
                pre=2;
                counter=0;
                resume=0;
                ball_direction=1;
                mainmenu=0;
                play=0;
                iResumeTimer(0);
            }
            if(mx>=600&&mx<=700&&my>=100&&my<=130)
            {
                mainmenu=0;
                resume=1;
                bin2=true;
                bin1=false;
                ball_direction=1;
                level=0;
                play=0;
                bctrl=1;
                ins=0;
                c=2;
                counter=0;
                pre=2;
                for(j=0;j<26;j++)
                    l2_ch[j]=0;
                play=0;
                iResumeTimer(0);
            }
            if(mx>=600&&mx<=700&&my>=200&&my<=230)
            {
                 mainmenu=0;
                level=3;
                bin1=true;
                bin2=false;
                c=2;
                pre=2;
                counter=0;
                resume=0;
                ball_direction=1;
                play=0;
                iResumeTimer(0);
            }
            else if(mx>=1000&&mx<=1080&&my>=100&&my<=130)
            {
                play=0;
                mainmenu=1;
            }
	    }
	    if(level==1||level==2||level==3)
        {
            if(mx>=1330&&mx<=1500&&my>=720&&my<=750)
            {
                level=0;
                play=0;
                ins=0;
                mainmenu=1;
                c=2;
                counter=0;
                bctrl=0;
                pre=2;
                for(j=0;j<26;j++)
                    l2_ch[j]=0;
                ball_direction=1;
                iPauseTimer(0);
            }
            if(c<=0)
            {
                if(mx>=200&&mx<=360&&my>=200&&my<=240)
                {
                    if(level==1){
                    mainmenu=0;
                level=1;
                bin1=true;
                bin2=false;
                c=2;
                pre=2;
                counter=0;
                resume=0;
                bctrl=0;
                ball_direction=1;
                play=0;
                iResumeTimer(0);
                    }
                    else if(level==3){
                    mainmenu=0;
                level=3;
                bin1=true;
                bin2=false;
                c=2;
                pre=2;
                counter=0;
                resume=0;
                bctrl=0;
                ball_direction=1;
                play=0;
                iResumeTimer(0);
                    }
                    else if(level==2){
                    mainmenu=0;
                level=2;
                bin1=true;
                bin2=false;
                c=2;
                pre=2;
                bctrl=0;
                counter=0;
                resume=0;
                for(j=0;j<26;j++)
                    l2_ch[j]=0;
                ball_direction=1;
                play=0;
                iResumeTimer(0);
                    }
                }
                if(mx>=900&&mx<=1200&&my>=200&&my<=240)
                {
                     level=0;
                    play=0;
                    ins=0;
                    mainmenu=1;
                    c=2;
                    counter=0;
                    bctrl=0;
                    pre=2;
                    for(j=0;j<26;j++)
                        l2_ch[j]=0;
                    ball_direction=1;
                }
            }
        }
        if(over==1)
       {
            if(mx>=500&mx<=700&&my>=300&&my<=360)
            {
                over=0;
                bin1=true;
                bin2=false;
                c=2;
                counter=0;
                bctrl=0;
                pre=2;
                for(j=0;j<26;j++)
                    l2_ch[j]=0;
                ball_direction=1;
            }
        }
        if(high_score==1)
        {
            if(mx>=900&&mx<=1200&&my>=100&&my<=140)
           {
                high_score=0;
                mainmenu=1;
            }
        }
        if(quit==1)
        {
          if(mx>=530&&mx<=590&&my>=320&&my<=340)
          {
                int a,b;
              save=fopen("saved_game.txt","w");
              for(a=0;a<=14;a++)
              {
                  for(b=0;b<26;b++)
                  {
                      fprintf(save,"%d ",dec[a][b]);
                  }
            ///  fprintf(save,"\n");
              }
              fclose(save);

              save=fopen("saved_Life.txt","w");
              fprintf(save,"%d",c);
              fclose(save);

              save=fopen("saved_score.txt","w");
              fprintf(save,"%d",counter);
              fclose(save);

              save=fopen("saved_level.txt","w");
              fprintf(save,"%d",level);
              fclose(save);
              save=fopen("saved_ball_pos.txt","w");
              fprintf(save,"%d %d",ball_x,ball_y);
              fclose(save);

              resume=0;
              level=0;
              play=0;
             quit=0;
              ins=0;
              exit(0);
          }
             if(mx>=850&&mx<=935&&my>=320&&my<=340)
            {
              level=0;
              resume=0;
              ins=0;
              play=0;
              quit=0;
              exit(0);
            }
        }
    }
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{}
}


void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
    if(key=='q')
    {
        if(level==1||level==2||level==3||resume==1)
        quit=1;
        iPauseTimer(0);
    }
}

void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key==GLUT_KEY_LEFT)
    {
          if(stick_x<=0)
          {
               stick_x=stick_x;
           }
           else
              stick_x-=100;
    }
    if(key==GLUT_KEY_RIGHT)
    {
         if(stick_x>=1300)
       {
        stick_x=stick_x;
       }
       else
        stick_x+=100;
    }
}

void ballmove()
{
    if (counter >= 50)
    {

        dy = 10;
    }
    if (counter >= 100)
    {
        dy = 12;
    }

    if (counter >= 140)
    {
        dy = 14;
        dx = 10;
    }

    if (counter >= 180)
    {
        dy = 16;
        dx = 11;
    }

    int k,s,y;
         if(level==1||level==2||level==3||resume==1){
         if(resume==1&&bin2==true)
        {
            int a,b;
            save=fopen("saved_game.txt","r");

            for(a=0;a<=14;a++)
            {
                for(b=0;b<26;b++){
                    if(fscanf(save,"%d",&dec[a][b])==EOF)
                        break;

                }
            }

            fclose(save);

            save=fopen("saved_Life.txt","r");
             fscanf(save,"%d",&c);
             fclose(save);

             save=fopen("saved_score.txt","r");
            fscanf(save,"%d",&counter);
            fclose(save);

            save=fopen("saved_level.txt","r");
            fscanf(save,"%d",&level);
            fclose(save);
            save=fopen("saved_pre.txt","r");
            fscanf(save,"%d",&pre);
            fclose(save);
           save=fopen("saved_ball_pos.txt","r");
            fscanf(save,"%d%d",&ball_x,&ball_y);
            fclose(save);
            bin2=false;
            bctrl=1;
            resume=0;
        }

        if(level==1||level==2||level==3)
        {
            if(bctrl==0)
            {
                FILE *fp;
                if(level==1)
                    fp=fopen("bstyle1.txt","r");
                else if(level==2)
                    fp=fopen("bstyle2.txt","r");
                else if(level==3)
                    fp=fopen("bstyle3.txt","r");

                for(bi=0;bi<=14;bi++)
                {
                    for(bj=0;bj<26;bj++)
                    {
                        if(fscanf(fp,"%d",&bk)!=EOF)
                            dec[bi][bj]=bk;
                   }
                }
                fclose(fp);
                bctrl=1;
            }
        }

        y=1;
        for(k=0;k<=14;k++)
        {
            for(s=0;s<26;s++)
            {
                if(dec[k][s]==0)
                    y=1;
                else {
                    y=0;
                    break;
               }
            }
            if(y==0)
                break;
        }

        if(y==1)
       {
            over=1;
        }

        int a=0,b,l;
        if(ball_y<=0)
        {
            ball_x=645;
	        ball_y=222;
	        ball_direction=1;
	        stick_x=615;
	       c--;
        }

        l=650;
        while(a<=14)
        {
            if(ball_y>=l&&ball_y<=(l+15))
           {
             n=0;
                i=180;
                j=0;
        while(n<26)
        {
            if(ball_x>=i&&ball_x<=(i+40)&&dec[a][j]==1)
            {
                if(ball_x>=i&&ball_x<=(i+40)&&dec[a][j]==1&&a==14&&level==1)
                {
                    direction_change();
                        dec[a][j]=0;
                        counter++;
                        printf("\a");
                }
                    else if(ball_x>=i&&ball_x<=(i+40)&&dec[a][j]==1&&a==14&&level==2)
                    {
                        if(l2_ch[j]==2)
                        {
                            dec[a][j]=0;
                            direction_change();
                            counter++;
                            printf("\a");
                        }
                        else
                        {l2_ch[j]++;
                         direction_change();}
                    }
                   else if(ball_x>=i&&ball_x<=(i+40)&&dec[a][j]==1&&a==14&&level==3)
                   {
                        direction_change();
                        dec[a][j]=0;
                        counter++;
                        printf("\a");
                    }
                else if(ball_x>=i&&ball_x<=(i+40)&&dec[a][j]==1&&a!=14)
                {
                dec[a][j]=0;
                direction_change();
                counter++;
                printf("\a");
                }
            }

                j++;
                i+=41;
                n++;
        }
    }
    a++;
    l-=16;
    }
    int bchk;
    FILE *fp;
        if(level==1)
            fp=fopen("High_score_1.txt","r");
       else if(level==2)
            fp=fopen("High_score_2.txt","r");
        else if(level==3)
            fp=fopen("High_score_3.txt","r");
        fscanf(fp,"%d",&bchk);
        fclose(fp);
        if(counter>check)
        {
            if(level==1)
            fp=fopen("High_score_1.txt","w");
       else if(level==2)
            fp=fopen("High_score_2.txt","w");
        else if(level==3)
            fp=fopen("High_score_3.txt","w");
        fprintf(fp,"%d",counter);
        fclose(fp);
        }

    if (ball_x<=0)
    {
        if(ball_direction==3)
            ball_direction=5;

        if(ball_direction==6)
            ball_direction=4;
    }
    if(ball_x>=1500)
    {
        if(ball_direction==5)
            ball_direction=3;
        else if(ball_direction==4)
            ball_direction=6;
    }
    if(ball_y>=710)
    {
       random=rand()%3+1;
       if(random==1)
        ball_direction=2;
       else if(random==2)
        ball_direction=6;
       else if(random==3)
        ball_direction=4;
    }

    if(ball_direction==1)
    {
        ball_y+=dy;
    }

    else if(ball_direction==2)
    {
        ball_y-=dy;
    }

    else if(ball_direction==3)
    {
        ball_x-=dx;
        ball_y+=dy;
    }
    else if(ball_direction==4)
    {
        ball_x+=dx;
        ball_y-=dy;
    }
    else if(ball_direction==5)
    {
        ball_x+=dx;
        ball_y+=dy;
    }
    else if(ball_direction==6)
    {
        ball_x-=dx;
        ball_y-=dy;
    }
     if(ball_y<=20)
    {
        if(ball_x>(stick_x+60)&&ball_x<(stick_x+140))
        {
            ball_direction=1;
        }
        else if(ball_x>=stick_x&&ball_x<=(stick_x+60))
        {
            ball_direction=3;
        }
        else if(ball_x>=(stick_x+140)&&ball_x<=(stick_x+200))
        {
            ball_direction=5;
        }
    }
    }
}

int main()
{
    quit=0;
    resume=0;
    over=0;
    d=0;
    counter=0;
    c=2;
	ball_x=20;
	ball_y=25;
	ball_direction=1;
    dx = 8;
	dy = 8;

    iSetTimer(1,ballmove);
    iInitialize(1500,750, "DX BALL");
    return 0;
}




