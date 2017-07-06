#include "SDL/SDL.h"
#include <stdbool.h>
#include<stdio.h>
#include <sdl/sdl_mixer.h>
#include <sdl/sdl_ttf.h>
 /*to show the menu that appears at first*/
int showmenu(SDL_Surface* screen, TTF_Font* font)
{
        Uint32 time;
        int x, i, y;
        /*menu items*/
        const char* labels[6] = {"START","Exit", "CREDITS", "SATISH PANT" , "PRANJAL DHAKAL", "PRATEEK RAJ JOSHI"};
        SDL_Surface* menus[6];
        bool selected[3] = {0,0, 0};
        /*colour of texts*/
        SDL_Color color[5] = {{255,255,255},{255,0,0}, {238,202,179}, {235,245,68}, {0,0,0}};
/*assigning colour to menu items and font type*/
        menus[0] = TTF_RenderText_Solid(font,labels[0],color[0]);
        menus[1] = TTF_RenderText_Solid(font,labels[1],color[0]);
        menus[2] = TTF_RenderText_Solid(font,labels[2],color[2]);
        menus[3] = TTF_RenderText_Solid(font,labels[3],color[3]);
        menus[4] = TTF_RenderText_Solid(font,labels[4],color[3]);
        menus[5] = TTF_RenderText_Solid(font,labels[5],color[3]);
/*assigning position to menu items*/
        SDL_Rect pos[7];
        pos[0].x = 370;
        pos[0].y = 200;
        pos[1].x = 383;
        pos[1].y = 250;
        pos[2].x =350;
        pos[2].y =319;
        pos[3].x =320;
        pos[3].y =420;
        pos[4].x =288;
        pos[4].y =455;
        pos[5].x =270;
        pos[5].y =490;
        pos[6].x =88;
        pos[6].y =99;
/*displaying black background during menu*/
        SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0x00,0x00,0x00));

        SDL_Event event;
        while(1)
        {
                time = SDL_GetTicks();
                while(SDL_PollEvent(&event))
                {
                        switch(event.type)
                        {
                                case SDL_QUIT:
                                        SDL_FreeSurface(menus[0]);
                                        SDL_FreeSurface(menus[1]);
                                        SDL_FreeSurface(menus[2]);
                                        return 1;
                                        /*mouse movements*/
                                case SDL_MOUSEMOTION:
                                        x = event.motion.x;
                                        y = event.motion.y;
                                        for(i = 0; i < 3; i += 1) {
                                                if(x>=pos[i].x && x<=pos[i].x+pos[i].w && y>=pos[i].y && y<=pos[i].y+pos[i].h)
                                                {
                                                        if(!selected[i])
                                                        {
                                                              /*when mouse cursor is above the menu item, the text turns red i.e, colour 1*/

                                                                selected[i] = 1;
                                                                SDL_FreeSurface(menus[i]);
                                                                menus[i] = TTF_RenderText_Solid(font,labels[i],color[1]);
                                                                if (selected[2])
                                                                    {SDL_BlitSurface(menus[3],NULL,screen,&pos[3]);
                                                                    SDL_BlitSurface(menus[4],NULL,screen,&pos[4]);
                                                                    SDL_BlitSurface(menus[5],NULL,screen,&pos[5]);

                                                                    menus[3] = TTF_RenderText_Solid(font,labels[3],color[3]);
                                                                  menus[4] = TTF_RenderText_Solid(font,labels[4],color[3]);
                                                                  menus[5] = TTF_RenderText_Solid(font,labels[5],color[3]);

                                                                    }


                                                                    }
                                                }
                                                else
                                                {
                                                        if(selected[i])
                                                        {
                                                            if(!selected[2])    /*when mouse is away from the text white colour reaapers*/
                                                             {selected[2] = 0;
                                                                 menus[3] = TTF_RenderText_Solid(font,labels[3],color[5]);
                                                               menus[4] = TTF_RenderText_Solid(font,labels[4],color[5]);
                                                              menus[5] = TTF_RenderText_Solid(font,labels[5],color[5]);}

                                                                selected[i] = 0;
                                                                SDL_FreeSurface(menus[i]);
                                                                menus[i] = TTF_RenderText_Solid(font,labels[i],color[0]);


                                               }
                                                }
                                        }
                                        break;
                                case SDL_MOUSEBUTTONDOWN:
                                        x = event.button.x;
                                        y = event.button.y;
                                        for(i = 0; i < 3; i += 1) {
                                                if(x>=pos[i].x && x<=pos[i].x+pos[i].w && y>=pos[i].y && y<=pos[i].y+pos[i].h)
                                                {
                                                        SDL_FreeSurface(menus[0]);
                                                        SDL_FreeSurface(menus[1]);

                                                        return i;
                                                }
                                        }
                                        break;
                                case SDL_KEYDOWN:
                                    /*espace key during gameplay pauses and shows menu*/
                                        if(event.key.keysym.sym == SDLK_ESCAPE)
                                        {
                                                SDL_FreeSurface(menus[0]);
                                                SDL_FreeSurface(menus[1]);
                                                SDL_FreeSurface(menus[2]);
                                                 SDL_FreeSurface(menus[3]);
                                                return 0;
                                        }
                        }
                }
                for( i = 0; i < 3; i += 1) {
                        /*surface must be freed after using it*/
                        SDL_BlitSurface(menus[i],NULL,screen,&pos[i]);
                }
                SDL_Flip(screen);
                if(1000/30 > (SDL_GetTicks()-time))
                        SDL_Delay(1000/30 - (SDL_GetTicks()-time));
        }
}




void setrects(SDL_Rect* clip)
{
/*clips for level bar*/
int i,j,w=0,k=0;
for(i=0;i<84;i++)

     {clip[i].x=0;
     clip[i].y=0;
     clip[i].w=i*5;
     clip[i].h=20;
     }   }

     void setrects2(SDL_Rect* clip)
{

/*clips for opening and closing the crocodile's mouth*/

     clip[0].x=7;
     clip[0].y=0;
     clip[0].w=200;
     clip[0].h=90;
      clip[1].x=0;
     clip[1].y=102;
     clip[1].w=170;
     clip[1].h=110;



        }

         void setrects3(SDL_Rect* clip)
{

/*clips for eac of eight fruits*/


int i;
for(i=0;i<8;i++)

     {

     clip[0].x=125;
     clip[0].y=0;
     clip[0].w=42;
     clip[0].h=42;

     clip[1].x=2;
     clip[1].y=7;
     clip[1].w=41;
     clip[1].h=60;


     clip[2].x=67;
     clip[2].y=5;
     clip[2].w=36;
     clip[2].h=39;


     clip[3].x=189;
     clip[3].y=5;
     clip[3].w=50;
     clip[3].h=38;

     clip[4].x=253;
     clip[4].y=5;
     clip[4].w=53;
     clip[4].h=37;

     clip[5].x=322;
     clip[5].y=2;
     clip[5].w=43;
     clip[5].h=40;


     clip[6].x=386;
     clip[6].y=8;
     clip[6].w=41;
     clip[6].h=38;

     clip[7].x=452;
     clip[7].y=0;
     clip[7].w=43;
     clip[7].h=46;
     }

}


bool collision (SDL_Rect* rect1,SDL_Rect* rect2)
{
    /*collision detection between ball and crocodile*/
    if(rect1 ->y >= rect2->y +rect2->h)
        return 0;
        if(rect1 ->x >=  rect2 ->x +rect2->w-24)
        return 0;
        if(rect1 ->y + rect1 ->h <=rect2->y)
        return 0;
        if(rect1 ->x + rect1 ->w <=rect2->x)
        return 0;
        return 1;

}

bool collision1 (SDL_Rect* rect1,SDL_Rect* rect2)
{/*collision detection between ball and pipe*/
    if(rect1 ->y +26>= rect2->y +rect2->h)
        return 0;
        if(rect1 ->x +38>=  rect2 ->x +rect2->w)
        return 0;
        if(rect1 ->y + rect1 ->h <=rect2->y+22)
        return 0;
        if(rect1 ->x + rect1 ->w <=rect2->x+24)
        return 0;
        return 1;

}

int main(int argc,char* argv[])
{
    /*everything is initialized i.e, sdl- text, pictures, sound , videos*/
SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();
TTF_Font *font = TTF_OpenFont("arial.ttf", 30);  /*arialtext is used */
SDL_Surface* screen, *background, *text2;   /*declaration of surfaces(images)*/
SDL_Surface* image, *image1, *image2, *image3, *image4, *image5,*image6, *text, *text1;
SDL_Surface* tex;
Mix_Chunk* effect, *effect2, *effect3, *effect4;/*declaration of sound effects*/
Mix_Music* music;
Mix_OpenAudio(22050 , MIX_DEFAULT_FORMAT, 2, 4096);
music = Mix_LoadMUS("mario3.wav");           /*different sound clips are loaded in .wav format*/
effect = Mix_LoadWAV("apple.wav");
effect2 = Mix_LoadWAV("collision.wav");
effect3 = Mix_LoadWAV("gameover.wav");
effect4 = Mix_LoadWAV("youwin.wav");
Mix_PlayMusic(music, -1);                 /*main background music that runs throughout the game */

screen=SDL_SetVideoMode(920,600,32,SDL_SWSURFACE);  /*main console screen 32 coloour depth*/
float  timer= 5;

srand(time(NULL));        /*to generate truly random number*/
bool running=true;
int frame = 0;
int collicount = 0;   /*variale to count number of collisions between crocodile and pipe*/
int  x=0, frames=0;    /*x== collisions with fruits OR the crocodile eating fruits*/
int t=rand()%8;
const int FPS=30;         /*frames per sec of the screen*/
Uint32 start;
bool b[5]={0,0,0,0,0};
SDL_Rect rect;

 rect.x=649;
 rect.y=208;
 SDL_Rect rect1;
 rect1.x=0;
 rect1.y=205;
 rect1.w=20;                 /*rect gives the position and dimension for surfaces and texts displayed on the screen*/
 rect1.h=26;
 SDL_Rect rect2[84];
setrects(rect2);
SDL_Rect rect3;
rect3.x=81;
 rect3.y=5;

 SDL_Rect rect4;
 rect4.x=0;
 rect4.y=2;

 SDL_Rect rect5;
  rect5.x=613;
 rect5.y=1;
 SDL_Rect rect6;
  rect6.x=845;
 rect6.y=33;
 SDL_Rect rect7;
  rect7.x=870;
 rect7.y=33;
 SDL_Rect rect8;
  rect8.x=756;
  rect8.y=0;

SDL_Rect rect9[2];
setrects2(rect9);

SDL_Rect rect10[8];
setrects3(rect10);

SDL_Rect rect11;
  rect11.x=-120;
  rect11.y=600;


     SDL_Rect rect12;
  rect12.x=-120;
  rect12.y=600;


 SDL_Rect rect13 ={895,33};
 SDL_Rect rect14 ={328,230};
  SDL_Rect rect15 ={240,170,0,0};

Uint32 color=SDL_MapRGB(screen->format,0x00,0x00,0x00);

 Uint32 color2=SDL_MapRGB(screen->format,0xef,0xaf,0xf6);
 background = SDL_LoadBMP("background.bmp");             /*image loaded to surfaces*/
 image=SDL_DisplayFormat(SDL_LoadBMP("download.bmp"));
 image1=SDL_DisplayFormat(SDL_LoadBMP("tennisball.bmp"));
 image2=SDL_DisplayFormat(SDL_LoadBMP("baar.bmp"));
 image3=SDL_DisplayFormat(SDL_LoadBMP("bar1.bmp"));
 image4=SDL_DisplayFormat(SDL_LoadBMP("ball1.bmp"));
image5=SDL_DisplayFormat(SDL_LoadBMP("pipe.bmp"));
image6=SDL_DisplayFormat(SDL_LoadBMP("pipe1.bmp"));
SDL_Rect camera;
camera.x = 1430;
camera.y = 0;              /*position for scrollable background*/
camera.w= 920;
camera.h = 600;


 SDL_SetColorKey(image,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0xff,0xff,0xff));

SDL_SetColorKey(image1,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0xff,0xff,0xff));
SDL_SetColorKey(image4,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0xff,0xff,0xff));   /*makes the background of the surfaces/ images invisible*/

SDL_SetColorKey(image5,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0xff,0xff,0xff));

SDL_SetColorKey(image6,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0xff,0xff,0xff));
SDL_Color colourt ={238,232,170};
SDL_Color colourt1 ={238,232,170};


int i =showmenu(screen, font);  /*menu function calling*/

if(i==1)
{
    running =false;  /*if exit is pressed it exits the program*/
}


while(running)
{        /*main logic loop of the game*/

    start=SDL_GetTicks();
    SDL_Event event;
    while(SDL_PollEvent(&event)){
     switch(event.type)
     {
         case SDL_QUIT:
          running=false;
          break;
          case SDL_KEYDOWN:
           switch(event.key.keysym.sym)
           {

               case SDLK_UP:
               b[0]=1;
               break;

               case SDLK_DOWN:
               b[1]=1;                    /*when different keys are pressed*/
               break;

               case SDLK_SPACE:
               b[2]=1;
               break;
               case SDLK_RETURN:

               b[3]=1;
               break;
             case SDLK_ESCAPE:
            i = showmenu(screen, font);
            if(i==1)
           running = false;
           break;


               }
           break;
            case SDL_KEYUP:
             switch(event.key.keysym.sym)
               {

               case SDLK_UP:
               b[0]=0;
               break;

               case SDLK_DOWN:
               b[1]=0;
               break;                    /*values returned to 0 after ressing the keys*/

                  case SDLK_SPACE:
               b[2]=1;
               break;
                case SDLK_RETURN:
               b[3]=0;
               break;
}
           break;
     }

    }
if(t>=8)
             /*clips of fruits cant exceed 8 itens so*/
{
    t=0;
}
char f[100];
sprintf(f, "%d", x);                                     /*to display count*/
text= TTF_RenderText_Solid(font, f, colourt );

char g[100];
if(x<8)
{
  sprintf(g, "%d", x*2);
}

if(x<15 && x>7)
{
  sprintf(g, "%d", x*4);
}
if(x<21 && x>14)                                       /*score factor changes as score increases*/
{
  sprintf(g, "%d", x*8);
}
if(x<26 && x>20)
{
  sprintf(g, "%d", x*12);
}
if(x>30 && x>25)
{
  sprintf(g, "%d", x*16);
}
text1= TTF_RenderText_Solid(font, g, colourt1 );               /*to display score*/



SDL_FillRect(screen,&screen->clip_rect,color2);

  SDL_BlitSurface(background,&camera,screen,NULL);
  SDL_BlitSurface(image,&rect9[frames],screen,&rect);       /*differnt part of images used*/
   SDL_BlitSurface(image1,&rect10[t],screen,&rect1);
    SDL_BlitSurface(image3,NULL,screen, &rect4);
    SDL_BlitSurface(image4,NULL,screen, &rect6);
     SDL_BlitSurface(image4,NULL,screen, &rect7);
     SDL_BlitSurface(image4,NULL,screen, &rect13);                     /*image must be blited in order to see in the screen*/
    SDL_BlitSurface(image2,&rect2[frame],screen, &rect3);
     SDL_BlitSurface(text,NULL,screen,&rect5);
     SDL_BlitSurface(text1,NULL,screen,&rect8);
      SDL_BlitSurface(image5,NULL,screen, &rect12);
      SDL_BlitSurface(image6,NULL,screen, &rect11);
      SDL_BlitSurface(text2,NULL,screen,&rect14);
      SDL_BlitSurface(tex , NULL ,screen,&rect15);



   if (rect1.x>=885)
   {                                     /*after the fruit reaches the rightmost end then it again appers from leftmost end*/
       rect1.x=0;                           /*height of the fruit is random*/
       t=rand()%8;
        rect1.y= rand()%440+55;
   }

    if(rect.x-rect1.x<=60)
{
    frames=1;                                /*crocodile opens the mouth when it comes near the fruit*/
}
else
{
    frames=0;                                   /*and again shuts the mouth*/
}

 if(b[2])
{

     rect12.x+=6+timer;
     rect11.x+=6+timer;                   /*speed of pipe increases with score*/
     camera.x -=6;                             /*speed of the scrollable screen*/
     rect1.x +=7;                              /*speed of ball*/
     rect.y+=(int) (8+ timer/11);              /*crocodile always moves down and moving speed increases with score*/
     if(camera.x <= 0)
     {
         camera.x = 1430;                       /*background loop*/
     }
        if(collision(&rect, &rect1) )           /*collision between fruit and crocodile*/
 {      x++;                                     /*score increses*/

        t=rand()%8;                                 /*another random fruit appers*/

        Mix_PlayChannel(-1, effect, 0);              /*sound effect is played*/
        frame ++;                                     /*level baa increses*/

        rect1.x = 0;                                    /*ball appears from left most*/
       rect1.y= rand()%440+55;                           /*ball comes from rando height*/
         timer += 0.47; }                                 /*every collision increses timer*/

    if(b[0])
   {rect.y-= (int) (21+ timer/2.5);

 }
                                                        /*when up key is pressed*/
     else if(b[1])
   {

       rect.y+=22;

   }



   if(x%6==0)
    {  if(rect12.x>=999 || collision1(&rect, &rect12))
    {   if(collision1(&rect, &rect12))                             /*appearance of pipes and their effect after collsion*/
    {
       Mix_PlayChannel(-1, effect2, 0);
       collicount++;
       if (collicount==4){


Mix_PlayChannel(-1, effect3, 0);                                     /*plays sound after collsion*/
}



    }
        rect12.x=-(rand()%1250884643+65);
         rect12.y=rand()%100+320;              /*emerges having random height */

    }}

else
    {  if(rect12.x>=999 || collision1(&rect, &rect12))
    {

        if(collision1(&rect, &rect12))
    {
       Mix_PlayChannel(-1, effect2, 0);
       collicount++;

       if (collicount==4){


Mix_PlayChannel(-1, effect3, 0);
}


    }

        rect12.x=-(rand()%1250884464643+65);
         rect12.y=rand()%200+rand()%125+223;

    }}


      if(rect11.x>=999 || collision1(&rect, &rect11))
       {

             if(collision1(&rect, &rect11))
    {
       Mix_PlayChannel(-1, effect2, 0);
       collicount++;

    }


        if(x%6==0 || collision1(&rect, &rect11))
    {
        rect11.x=75+rand()%28-rect12.x;
         rect11.y=-0;

    }}


    if(rect.y>=540)
{
    rect.y=540;
}


    if (collicount==1)
    {
         rect6.x=920;

    }

else if (collicount==2)
{
rect7.x=920;

}

else if (collicount==3)
                                                     /*4 lives i.e collicount is 4*/
{
rect13.x=920;

}

else if (collicount==4){
rect12.x=920;
rect11.x=920;
rect1.x=920;
rect.x=380;
rect.y = 265;
rect5.x=920;                                     /*after game over*/
 rect3.x=920;
 rect4.x=920;
  rect8.x=480;
  rect8.y=230;


text2= TTF_RenderText_Solid(font, "SCORE", colourt );                             /*displays score and message */

tex= TTF_RenderText_Solid(font, "You lose, Press Enter to go to Menu!", colourt1 );

 if(b[3])

{
     i = showmenu(screen, font);                                    /*when enter pressed goes to main menu*/
            if(i==1)
           running = false;


}}
}

if(x >84)
         {
rect12.x=920;
rect11.x=920;
rect1.x=920;                                                    /*if whole game is completed, then its final screen*/
rect.x=380;
rect.y = 265;
rect5.x=920;
 rect3.x=920;
 rect4.x=920;
  rect8.x=480;
  rect8.y=230;
  rect6.x=920;
  rect7.x=920;
  rect13.x=920;
   if(camera.x%112==0)
   {Mix_PlayChannel(-1, effect4, 1);}                            /*plays sound effects*/


text2= TTF_RenderText_Solid(font, "SCORE", colourt );
              tex = TTF_RenderText_Solid(font, "Congrats! You WIN, Press Enter to go to MENU!" , colourt );          /*diplays congrats message*/
              if(b[3])
       {

            i = showmenu(screen, font);                      /*shows menu when enter is pressed*/
            if(i==1)
           running = false;
}



}

SDL_WM_SetCaption( "SHOOTFRUIT", NULL );                                 /*windowa caption*/
SDL_Flip(screen);
    if(1000/FPS>SDL_GetTicks()-start)
       SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
}
Mix_FreeMusic(music);
Mix_FreeChunk(effect);
Mix_FreeChunk(effect2);
Mix_FreeChunk(effect3);
Mix_CloseAudio();
SDL_FreeSurface(image);
SDL_FreeSurface(image1);
SDL_FreeSurface(image2);
SDL_FreeSurface(image3);
SDL_FreeSurface(image4);              /*every surface, music clips should be freed in order to avoid possible errors*/
SDL_FreeSurface(image5);
SDL_FreeSurface(image6);
SDL_FreeSurface(background);
SDL_FreeSurface(text);
SDL_FreeSurface(text1);

SDL_Quit();
return 0;
}
