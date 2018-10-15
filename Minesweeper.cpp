#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<ctime>
#include<string.h>
#include<fstream>
#include<sstream>
using namespace std;
HANDLE outcon=GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int x,int y)
{COORD coord;
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);}
void design()
{SetConsoleTextAttribute(outcon,0x80);
 system("cls");
 HWND hwnd=GetConsoleWindow();
 SetWindowPos(hwnd,HWND_TOPMOST,0,0,265,380,0);
 //Start of draw up task------------------------------------------------------------------
 SetConsoleTextAttribute(outcon,0x70|0x8);
 for(int i=0;i<30;i++)
    {gotoxy(i,0);cout<<" ";}
 //End of draw up task--------------------------------------------------------------------
 //Start of draw table--------------------------------------------------------------------
 gotoxy(1,6);cout<<"????????????????????????????";
 for(int i=7;i<=21;i+=2)
    {gotoxy(1,i);cout<<"³  ³  ³  ³  ³  ³  ³  ³  ³  ³";
     gotoxy(1,i+1);cout<<"???????????????????????????´";}
 gotoxy(1,23);cout<<"³  ³  ³  ³  ³  ³  ³  ³  ³  ³";
 gotoxy(1,24);cout<<"????????????????????????????";
 //End of draw table----------------------------------------------------------------------
 //Start of draw cells--------------------------------------------------------------------
 SetConsoleTextAttribute(outcon,0x80);
 for(int m=2;m<=26;m+=3)
     for(int n=7;n<=23;n+=2)
	    {gotoxy(m,n);cout<<"  ";}
 //End of draw cells----------------------------------------------------------------------
 SetConsoleTextAttribute(outcon,0x70|0x0);
 gotoxy(1,0);cout<<"New   Record!   About   Quit";
 SetConsoleTextAttribute(outcon,0x70|0x4);
 gotoxy(1,0);cout<<"N";gotoxy(7,0);cout<<"R";gotoxy(17,0);cout<<"A";gotoxy(25,0);cout<<"Q";
 //Start of draw down task----------------------------------------------------------------
 SetConsoleTextAttribute(outcon,0x70|0x8);
 gotoxy(1,2);cout<<"????????????????????????????";
 gotoxy(1,3);cout<<"³                          ³";
 gotoxy(1,4);cout<<"????????????????????????????";
 //End of draw down task------------------------------------------------------------------
 SetConsoleTextAttribute(outcon,0x00|0xC);
 gotoxy(5,3);cout<<"010";gotoxy(22,3);cout<<"000";
 gotoxy(12,3);cout<<"Start!";
}
void mouse_pos(int x,int y,int bombplace[10],int position[9][9],int *mark)
{void insert_number(int place[2],int bombplace[10],int position[9][9]);
int x1=22,x2=38,y1=116,y2=127,i=0,j=0;int place[2]={};
while(j<9)
	 {while(i<9)
           {if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
              {place[0]=i;place[1]=j;
               if(position[i][j]==2)
			      *mark+=1;
			   position[i][j]=1;
               gotoxy(2+3*i,7+2*j);insert_number(place,bombplace,position);break;}
	        else
	          {x1+=24;x2+=24;i++;}
           }
       j++;i=0;x1=22;x2=38;y1+=24;y2+=24;
      }
}
void insert_number(int place[2],int bombplace[10],int position[9][9])
{void lose_game(int bombplace[10]);
 int pl=1,num,sum=0;
 for(int j=1;j<=place[1];j++)
	 pl+=9;
 num=pl+place[0];
 for(int i=0;i<10;i++)
	 if(num==bombplace[i])
	 {SetConsoleTextAttribute(outcon,0x70|0x4);cout<<"! ";lose_game(bombplace);position[place[0]][place[1]]=0;}
 for(int i=0;i<10;i++)
	{if(num-1==bombplace[i] && num!=1 && num!=10 && num!=19 && num!=28 && num!=37 && num!=46 && num!=55 && num!=64 && num!=73)
		 sum+=1;
     if(num+1==bombplace[i] && num!=9 && num!=18 && num!=27 && num!=36 && num!=45 && num!=54 && num!=63 && num!=72)
		 sum+=1;
	 if(num-8==bombplace[i] && num!=9 && num!=18 && num!=27 && num!=36 && num!=45 && num!=54 && num!=63 && num!=72 && num!=81)
		 sum+=1;
	 if(num-9==bombplace[i])
		 sum+=1;
	 if(num-10==bombplace[i] && num!=10 && num!=19 && num!=28 && num!=37 && num!=46 && num!=55 && num!=64 && num!=73)
		 sum+=1;
	 if(num+8==bombplace[i] && num!=1 && num!=10 && num!=19 && num!=28 && num!=37 && num!=46 && num!=55 && num!=64 && num!=73)
		 sum+=1;
	 if(num+9==bombplace[i])
		 sum+=1;
	 if(num+10==bombplace[i] && num!=9 && num!=18 && num!=27 && num!=36 && num!=45 && num!=54 && num!=63 && num!=72)
		 sum+=1;}
 if(sum==0 && num!=bombplace[0] && num!=bombplace[1] && num!=bombplace[2] && num!=bombplace[3] && num!=bombplace[4] && num!=bombplace[5] && num!=bombplace[6] && num!=bombplace[7] && num!=bombplace[8] && num!=bombplace[9])
   {SetConsoleTextAttribute(outcon,0x70);
    cout<<"  ";}
 else if(sum==1 && num!=bombplace[0] && num!=bombplace[1] && num!=bombplace[2] && num!=bombplace[3] && num!=bombplace[4] && num!=bombplace[5] && num!=bombplace[6] && num!=bombplace[7] && num!=bombplace[8] && num!=bombplace[9])
	    {SetConsoleTextAttribute(outcon,0x70|0x9);
         cout<<"1 ";}
  else if(sum==2 && num!=bombplace[0] && num!=bombplace[1] && num!=bombplace[2] && num!=bombplace[3] && num!=bombplace[4] && num!=bombplace[5] && num!=bombplace[6] && num!=bombplace[7] && num!=bombplace[8] && num!=bombplace[9])
	    {SetConsoleTextAttribute(outcon,0x70|0x2);
         cout<<"2 ";}
  else if(sum==3 && num!=bombplace[0] && num!=bombplace[1] && num!=bombplace[2] && num!=bombplace[3] && num!=bombplace[4] && num!=bombplace[5] && num!=bombplace[6] && num!=bombplace[7] && num!=bombplace[8] && num!=bombplace[9])
	    {SetConsoleTextAttribute(outcon,0x70|0xC);
         cout<<"3 ";}
   else if(sum==4 && num!=bombplace[0] && num!=bombplace[1] && num!=bombplace[2] && num!=bombplace[3] && num!=bombplace[4] && num!=bombplace[5] && num!=bombplace[6] && num!=bombplace[7] && num!=bombplace[8] && num!=bombplace[9])
	    {SetConsoleTextAttribute(outcon,0x70|0x1);
         cout<<"4 ";}
     else if(sum==5 && num!=bombplace[0] && num!=bombplace[1] && num!=bombplace[2] && num!=bombplace[3] && num!=bombplace[4] && num!=bombplace[5] && num!=bombplace[6] && num!=bombplace[7] && num!=bombplace[8] && num!=bombplace[9])
	    {SetConsoleTextAttribute(outcon,0x70|0xD);
         cout<<"5 ";}
   else if(sum==6 && num!=bombplace[0] && num!=bombplace[1] && num!=bombplace[2] && num!=bombplace[3] && num!=bombplace[4] && num!=bombplace[5] && num!=bombplace[6] && num!=bombplace[7] && num!=bombplace[8] && num!=bombplace[9])
	    {SetConsoleTextAttribute(outcon,0x70|0xE);
         cout<<"6 ";}
   else if(sum==7 && num!=bombplace[0] && num!=bombplace[1] && num!=bombplace[2] && num!=bombplace[3] && num!=bombplace[4] && num!=bombplace[5] && num!=bombplace[6] && num!=bombplace[7] && num!=bombplace[8] && num!=bombplace[9])
	    {SetConsoleTextAttribute(outcon,0x70|0xB);
         cout<<"7 ";}
   else if(sum==8 && num!=bombplace[0] && num!=bombplace[1] && num!=bombplace[2] && num!=bombplace[3] && num!=bombplace[4] && num!=bombplace[5] && num!=bombplace[6] && num!=bombplace[7] && num!=bombplace[8] && num!=bombplace[9])
	    {SetConsoleTextAttribute(outcon,0x70|0xA);
         cout<<"8 ";}}
void lose_game(int bombplace[10])
{int w,h;
for(int i=0;i<10;i++)
   {h=bombplace[i]/9;w=bombplace[i]%9;
    if(w==0)
	  {w=9;h-=1;}
    gotoxy(2+3*w-3,7+2*h);cout<<"! ";bombplace[0]=-1;}
SetConsoleTextAttribute(outcon,0x00|0xC);gotoxy(12,3);cout<<" Lose ";}
void mark_pos(int x,int y,int bombplace[10],int position[9][9],int *mark)
{void insert_mark(int place[2],int bombplace[10],int position[9][9]);
 int x1=22,x2=38,y1=116,y2=127,i=0,j=0;int place[2]={};
 while(j<9)
	  {while(i<9)
           {if(x>=x1 && x<=x2 && y>=y1 && y<=y2 && position[i][j]==0 && *mark!=0)
              {place[0]=i;place[1]=j;
               gotoxy(2+3*i,7+2*j);insert_mark(place,bombplace,position);*mark-=1;break;}
	        else
	          {x1+=24;x2+=24;i++;}
           }
       j++;i=0;x1=22;x2=38;y1+=24;y2+=24;
      }
}
void insert_mark(int place[2],int bombplace[10],int position[9][9])
{int i,j;
 i=place[0];j=place[1];
 position[i][j]=2;
 SetConsoleTextAttribute(outcon,0x80|0x0);cout<<"/";SetConsoleTextAttribute(outcon,0x80|0xC);cout<<"~";
}
void win_game(int position[9][9],int bombplace[10],int *timing,char *name)
{void save_record(int *timing,char *name);
 int sum=0;
 for(int j=0;j<9;j++)
     for(int i=0;i<9;i++)
	     sum+=position[i][j];
 if(sum==91)
   {SetConsoleTextAttribute(outcon,0x00|0xC);gotoxy(12,3);cout<<" Win! ";bombplace[0]=-1;
    save_record(timing,name);}}
void save_record(int *timing,char *name)
{void play_again(int *timing);
 //Start of draw save_record window-------------------------------------------------------
 SetConsoleTextAttribute(outcon,0x00|0xF);gotoxy(3,9);cout<<" You Win!               ";
 for(int k=10;k<=22;k++)
	{gotoxy(3,k);cout<<" ";gotoxy(26,k);cout<<" ";}
 for(int l=10;l<22;l++)
	{SetConsoleTextAttribute(outcon,0x80|0x0);gotoxy(4,l);cout<<"                      ";}
 gotoxy(4,22);cout<<"______________________";
 SetConsoleTextAttribute(outcon,0x80|0xF);
 gotoxy(4,10);cout<<"Congratulation!";
 gotoxy(4,11);cout<<"You Win this game!";
 gotoxy(4,13);cout<<"For save your record,";
 gotoxy(4,14);cout<<"please enter your name";
 gotoxy(5,16);cout<<"????????????????????";
 gotoxy(5,17);cout<<"³                  ³";
 gotoxy(5,18);cout<<"????????????????????";
 SetConsoleTextAttribute(outcon,0x00|0xF);
 gotoxy(6,19);cout<<" Enter for save ";gotoxy(6,21);cout<<" Escape for cancel ";
 //End of draw save_record window---------------------------------------------------------
 int i=0;gotoxy(6,17);SetConsoleTextAttribute(outcon,0x80|0x4);
 while(i<19)
      {char x=_getch();
       if(int(x)==32) //Means that: if you press space key--------------------------------
	     {cout<<" ";name[i]=' ';i++;}
	   if(int(x)==8 && i>0) //Means that: if you press backspace key----------------------
	     {name[i-1]='\0';gotoxy(i-1+6,17);cout<<" ";gotoxy(i-1+6,17);i--;}
	   if(int(x)!=32 && int(x)!=8 && int(x)!=13 && int(x)!=27)
	     {name[i]=x;cout<<x;i++;}
	   if(int(x)==13)
	     {ofstream file("Record.msw");file<<name<<"\n"<<*timing/100<<"\nEnd----------------";file.close();i=19;}
	   if(int(x)==27)
		  i=19;
       if(i==18)
	     {gotoxy(6,17);i=0;}}
 play_again(timing);}
void play_again(int *timing)
{int chk=1;POINT p;
 //Start of draw play_again window--------------------------------------------------------
 SetConsoleTextAttribute(outcon,0x00|0xF);gotoxy(1,11);cout<<"                            ";
 for(int k=12;k<=20;k++)
	{gotoxy(1,k);cout<<" ";gotoxy(28,k);cout<<" ";}
 for(int l=12;l<20;l++)
	{SetConsoleTextAttribute(outcon,0x80|0x0);gotoxy(2,l);cout<<"                          ";}
 gotoxy(2,20);cout<<"__________________________";
 SetConsoleTextAttribute(outcon,0x80|0xF);
 gotoxy(2,12);cout<<"Do you want to play again?";
 gotoxy(2,14);cout<<"If you want to play again,";
 gotoxy(2,15);cout<<"click on Yes.";
 gotoxy(2,16);cout<<"Else click on No.";
 SetConsoleTextAttribute(outcon,0x00|0xF);
 gotoxy(4,19);cout<<" Yes ";gotoxy(22,19);cout<<" No ";
 //End of draw play_again window----------------------------------------------------------
 while(chk==1)
      {if(GetAsyncKeyState(VK_LBUTTON)!=0)
         {GetCursorPos(&p);
          if(p.x>=38 && p.x<=78 && p.y>=258 && p.y<=269)
		    {*timing=-1;chk=0;} //Means that: start new game-------------------------------------
		  if(p.x>=182 && p.x<=214 && p.y>=258 && p.y<=269)
		    {*timing=-2;chk=0;}} //Means that: Quit game------------------------------------------
       Sleep(10);}}
void display_num_of_marks(int *mark)
{SetConsoleTextAttribute(outcon,0x00|0xC);
 gotoxy(5,3);
 if(*mark==10)
    cout<<"0"<<*mark;
 else
	cout<<"00"<<*mark;}
void display_time(int *timing)
{SetConsoleTextAttribute(outcon,0x00|0xC);
 gotoxy(22,3);
 if(*timing<1000)
	cout<<"00";
 if(*timing>=1000 && *timing<10000)
	cout<<"0";
 *timing+=1;
 if(*timing<100000)
    cout<<*timing/100;
 if(*timing>100000)
	cout<<"999";
 SetConsoleTextAttribute(outcon,0x70);
 gotoxy(25,3);cout<<"   ";
}
void record_game(int *condition)
{int chk=1;POINT p;
 //Start of draw record_game window-------------------------------------------------------
 SetConsoleTextAttribute(outcon,0x00|0xF);gotoxy(3,9);cout<<" Record!                ";
 for(int k=10;k<=22;k++)
	{gotoxy(3,k);cout<<" ";gotoxy(26,k);cout<<" ";}
 for(int l=10;l<22;l++)
	{SetConsoleTextAttribute(outcon,0x80|0x0);gotoxy(4,l);cout<<"                      ";}
 gotoxy(4,22);cout<<"______________________";
 SetConsoleTextAttribute(outcon,0x80|0xF);
 gotoxy(4,10);cout<<"Last Record";
 gotoxy(4,12);cout<<" Name:";
 gotoxy(4,16);cout<<" Time:";
 ifstream file("Record.msw");
 string hold1;string hold2;
 getline(file,hold1);
 getline(file,hold2);
 SetConsoleTextAttribute(outcon,0x80|0x4);
 gotoxy(5,14);cout<<hold1;
 gotoxy(5,18);cout<<hold2;
 SetConsoleTextAttribute(outcon,0x00|0xF);
 gotoxy(11,21);cout<<" Start ";
 //End of draw record_game window---------------------------------------------------------
 while(chk==1)
      {if(GetAsyncKeyState(VK_LBUTTON)!=0)
         {GetCursorPos(&p);
          if(p.x>=94 && p.x<=150 && p.y>=282 && p.y<=293)
		    {*condition=1;chk=0;}}Sleep(10);}}
void about_game(int *condition)
{int chk=1;POINT p;
 //Start of draw about_game window--------------------------------------------------------
 SetConsoleTextAttribute(outcon,0x00|0xF);gotoxy(1,9);cout<<" About                      ";
 for(int k=10;k<=22;k++)
	{gotoxy(1,k);cout<<" ";gotoxy(28,k);cout<<" ";}
 for(int l=10;l<22;l++)
	{SetConsoleTextAttribute(outcon,0x80|0x0);gotoxy(2,l);cout<<"                          ";}
 gotoxy(2,22);cout<<"__________________________";
 SetConsoleTextAttribute(outcon,0x80|0xF);
 gotoxy(2,10);cout<<"Minesweeper";
 gotoxy(2,11);cout<<"Version 1.0";
 gotoxy(2,13);cout<<"Created by:Ehsan Mohammadi";
 gotoxy(2,14);cout<<"(Jan 21 2013 01:14:23)";
 gotoxy(2,16);cout<<"Copyright(C) 2013-2014";
 gotoxy(2,17);cout<<"Developed by:";
 gotoxy(2,18);cout<<"Ehsan Mohammadi";
 SetConsoleTextAttribute(outcon,0x00|0xF);
 gotoxy(11,21);cout<<" Start ";
 //End of draw about_game window----------------------------------------------------------
  while(chk==1)
      {if(GetAsyncKeyState(VK_LBUTTON)!=0)
         {GetCursorPos(&p);
          if(p.x>=94 && p.x<=150 && p.y>=282 && p.y<=293)
		    {*condition=1;chk=0;}}Sleep(10);}}
int main()
{int position[9][9]={};POINT p;int chance,bombplace[10]={},i=0,mark=10,timing=0,condition=0;char name[19]="\0";
 design();
 srand(time(0));
 //Start of programming bomb places-------------------------------------------------------
 while(i<10)
     {chance=rand()%81+1;
      if(chance!=bombplace[0] && chance!=bombplace[1] && chance!=bombplace[2] && chance!=bombplace[3] && chance!=bombplace[4] && chance!=bombplace[5] && chance!=bombplace[6] && chance!=bombplace[7] && chance!=bombplace[8] && chance!=bombplace[9])
	    {bombplace[i]=chance;i++;}}
 //End of programming bomb places---------------------------------------------------------
 while(bombplace[0]!=-1) //Means that: while game is not finished-------------------------
	  {if(GetAsyncKeyState(VK_LBUTTON)!=0)
         {GetCursorPos(&p);mouse_pos(p.x,p.y,bombplace,position,&mark);}
       if(GetAsyncKeyState(VK_RBUTTON)!=0)
	     {GetCursorPos(&p);mark_pos(p.x,p.y,bombplace,position,&mark);}
       display_num_of_marks(&mark);
	   display_time(&timing);
	   win_game(position,bombplace,&timing,name);
 //Start of programming record game while playing-----------------------------------------
       if(p.x>=62 && p.x<=116 && p.y>=31 && p.y<=39)
	     {bombplace[0]=-1;record_game(&condition);p.x=0;p.y=0;}
 //End of programming record game while playing-------------------------------------------
 //Start of programming about game while playing------------------------------------------
       if(p.x>=142 && p.x<=180 && p.y>=31 && p.y<=39)
	     {bombplace[0]=-1;about_game(&condition);p.x=0;p.y=0;}
 //End of programming about game while playing--------------------------------------------
 //Start of programming new game while playing--------------------------------------------
	   if(timing==-1 || (p.x>=14 && p.x<=37 && p.y>=31 && p.y<=39) || condition==1)
	     {i=0;mark=10;timing=0;condition=0;char name[19]="\0";bombplace[0]=0;
	      for(int a=0;a<10;a++)
			  for(int b=0;b<10;b++)
				  position[a][b]=0;
	      design();
	      while(i<10)
               {chance=rand()%81+1;
                if(chance!=bombplace[0] && chance!=bombplace[1] && chance!=bombplace[2] && chance!=bombplace[3] && chance!=bombplace[4] && chance!=bombplace[5] && chance!=bombplace[6] && chance!=bombplace[7] && chance!=bombplace[8] && chance!=bombplace[9])
	              {bombplace[i]=chance;i++;}}
	      p.x=0;p.y=0;}
 //End of programming new game while playing----------------------------------------------
 //Start of programming end game while playing--------------------------------------------
	   if(timing==-2 || (p.x>=206 && p.x<=236 && p.y>=31 && p.y<=39))
		  return 0;
 //End of programming end game while playing----------------------------------------------
	   while(bombplace[0]==-1)
	        {if(GetAsyncKeyState(VK_LBUTTON)!=0)
               {GetCursorPos(&p);
 //Start of programming record game after playing-----------------------------------------
                if(p.x>=62 && p.x<=116 && p.y>=31 && p.y<=39)
	              {bombplace[0]=-1;record_game(&condition);p.x=0;p.y=0;}
 //End of programming record game after playing-------------------------------------------
 //Start of programming about game after playing------------------------------------------
                if(p.x>=142 && p.x<=180 && p.y>=31 && p.y<=39)
	              {bombplace[0]=-1;about_game(&condition);p.x=0;p.y=0;}
 //End of programming about game after playing--------------------------------------------
 //Start of programming new game after playing--------------------------------------------
	            if((p.x>=14 && p.x<=37 && p.y>=31 && p.y<=39) || condition==1)
	              {timing==-1;bombplace[0]=0;}}
 //End of programming new game after playing----------------------------------------------
 //Start of programming end game after playing--------------------------------------------
	            if(p.x>=206 && p.x<=236 && p.y>=31 && p.y<=39)
				  {return 0;}
 //End of programming end game after playing----------------------------------------------
	           Sleep(10);}
	   Sleep(10);}
}