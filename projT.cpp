#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <string>
#include <cstring>
#include <time.h>
#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>
#include<fstream>
#include <unistd.h>
#include "rblock.h"


using namespace std;
 
 
Block BlockA::blarr[10][18];
 
Block::Block(){
   c = 1;
}
void Block::printBlock(){
   attron(COLOR_PAIR(c));
   if(c==1)
      mvprintw(y+3,x*2+3,"□");
   else
      mvprintw(y+3,x*2+3,"■");
   refresh();
   attroff(COLOR_PAIR(c));
}
 
void BlockA::firstSet(){
  
   for(int i = 0 ; i < 10;i++){
      for(int j = 0 ; j < 18 ; j++){
         blarr[i][j].x=i;
         blarr[i][j].y=j;
      }
   }
   
   for(int i = 0 ; i < 10;i++){
      for(int j = 0 ; j < 18 ; j++){
         blarr[i][j].printBlock();
      }
   }
}
int BlockA::maxY(){
   int max= y+yarr[0];   
   for(int i = 1 ; i < 4 ; i++){
      max = (y+yarr[i])>max?(y+yarr[i]):max;
   }
   return max;
}
 
int BlockA::minY(){
   int min= y+yarr[0];   
   for(int i = 1 ; i < 4 ; i++){
      min = (y+yarr[i])<min?(y+yarr[i]):min;
   }
   return min;
}
 
void BlockA::color(int c){
   if(check()){
      for(int i = 0 ; i < 4 ; i++){
         blarr[x+xarr[i]][y+yarr[i]].c=c;
      }
   }
 
}
 
void BlockA::rotationB(int blocknum1,int blocknum2){
   color(1);
   setBlock(blocknum2);
   if(check()){
      if(check0()==4){
         color(c);
      }else{
         setBlock(blocknum1);
         color(c);
      }
   }else{
      setBlock(blocknum1);
      color(c);
   }
}
 
void BlockA::setBlock(int blocknum){
   this->blocknum = blocknum;
   switch(blocknum){
      /////////////////////ㅡ
   case 0:
      xarr[0] = -1;
      xarr[1] = 0;
      xarr[2] = 1;
      xarr[3] = 2;
 
      yarr[0] = 0;
      yarr[1] = 0;
      yarr[2] = 0;
      yarr[3] = 0;
      c = 2;
      break;
   case 1:
      xarr[0] = 0;
      xarr[1] = 0;
      xarr[2] = 0;
      xarr[3] = 0;
 
      yarr[0] = -1;
      yarr[1] = 0;
      yarr[2] = 1;
      yarr[3] = 2;
      c = 2;
      break;
      ////////////////////////////ㄴ
   case 2:
      xarr[0] = 0;
      xarr[1] = 0;
      xarr[2] = 1;
      xarr[3] = 2;
 
      yarr[0] = 0;
      yarr[1] = 1;
      yarr[2] = 1;
      yarr[3] = 1;
      c = 3;
      break;
 
   case 3:
      xarr[0] = 0;
      xarr[1] = 1;
      xarr[2] = 0;
      xarr[3] = 0;
 
      yarr[0] = 0;
      yarr[1] = 0;
      yarr[2] = 1;
      yarr[3] = 2;
      c = 3;
      break;
 
   case 4:
      xarr[0] = 0;
      xarr[1] = 1;
      xarr[2] = 2;
      xarr[3] = 2;
 
      yarr[0] = 0;
      yarr[1] = 0;
      yarr[2] = 0;
      yarr[3] = 1;
      c = 3;
      break;
 
   case 5:
      xarr[0] = 1;
      xarr[1] = 1;
      xarr[2] = 1;
      xarr[3] = 0;
 
      yarr[0] = 0;
      yarr[1] = 1;
      yarr[2] = 2;
      yarr[3] = 2;
      c = 3;
      break;
 
      ///////////////////////////ㄴ 반대
   case 6:
      xarr[0] = -1;
      xarr[1] = 0;
      xarr[2] = 1;
      xarr[3] = 1;
 
      yarr[0] = 1;
      yarr[1] = 1;
      yarr[2] = 1;
      yarr[3] = 0;
      c = 4;
      break;
 
   case 7:
      xarr[0] = 0;
      xarr[1] = 0;
      xarr[2] = 0;
      xarr[3] = 1;
 
      yarr[0] = 0;
      yarr[1] = 1;
      yarr[2] = 2;
      yarr[3] = 2;
      c = 4;
      break;
 
   case 8:
      xarr[0] = 0;
      xarr[1] = 0;
      xarr[2] = 1;
      xarr[3] = 2;
 
      yarr[0] = 1;
      yarr[1] = 0;
      yarr[2] = 0;
      yarr[3] = 0;
      c = 4;
      break;
 
   case 9:
      xarr[0] = 0;
      xarr[1] = 1;
      xarr[2] = 1;
      xarr[3] = 1;
 
      yarr[0] = 0;
      yarr[1] = 0;
      yarr[2] = 1;
      yarr[3] = 2;
      c = 4;
      break;
      ///////////////////////ㅁ
   case 10:
      xarr[0] = 0;
      xarr[1] = 1;
      xarr[2] = 0;
      xarr[3] = 1;
 
      yarr[0] = 0;
      yarr[1] = 0;
      yarr[2] = 1;
      yarr[3] = 1;
      c = 5;
      break;
 
      /////////////////z반대
 
   case 11:
      xarr[0] = -1;
      xarr[1] = 0;
      xarr[2] = 0;
      xarr[3] = 1;
 
      yarr[0] = 1;
      yarr[1] = 1;
      yarr[2] = 0;
      yarr[3] = 0;
      c = 6;
      break;
 
   case 12:
      xarr[0] = 0;
      xarr[1] = 0;
      xarr[2] = 1;
      xarr[3] = 1;
 
      yarr[0] = 0;
      yarr[1] = 1;
      yarr[2] = 1;
      yarr[3] = 2;
      c = 6;
      break;
      //////////////////z
 
   case 13:
      xarr[0] = 0;
      xarr[1] = 1;
      xarr[2] = 1;
      xarr[3] = 2;
 
      yarr[0] = 0;
      yarr[1] = 0;
      yarr[2] = 1;
      yarr[3] = 1;
      c = 7;
      break;
 
   case 14:
      xarr[0] = 1;
      xarr[1] = 1;
      xarr[2] = 0;
      xarr[3] = 0;
 
      yarr[0] = 0;
      yarr[1] = 1;
      yarr[2] = 1;
      yarr[3] = 2;
      c = 7;
      break;
 
      ///////////////ㅗ
   case 15:
      xarr[0] = 0;
      xarr[1] = -1;
      xarr[2] = 0;
      xarr[3] = 1;
 
      yarr[0] = 0;
      yarr[1] = 1;
      yarr[2] = 1;
      yarr[3] = 1;
      c = 8;
      break;
 
   case 16:
      xarr[0] = 0;
      xarr[1] = 0;
      xarr[2] = 0;
      xarr[3] = 1;
 
      yarr[0] = 0;
      yarr[1] = 1;
      yarr[2] = 2;
      yarr[3] = 1;
      c = 8;
      break;
 
   case 17:
      xarr[0] = 0;
      xarr[1] = -1;
      xarr[2] = 0;
      xarr[3] = 1;
 
      yarr[0] = 1;
      yarr[1] = 0;
      yarr[2] = 0;
      yarr[3] = 0;
      c = 8;
      break;
 
   case 18:
      xarr[0] = 1;
      xarr[1] = 1;
      xarr[2] = 1;
      xarr[3] = 0;
 
      yarr[0] = 0;
      yarr[1] = 1;
      yarr[2] = 2;
      yarr[3] = 1;
      c = 8;
      break;
   }
 
}
 
BlockA::BlockA(int blocknum){
   x = 4;
   y = 0;
   setBlock(blocknum);//랜덤으로(0,2,6,10,11,13,15) 중에서
   color(c);//블럭 넘버에 맞는 칼라
 
}
 
void BlockA::clear(int blocknum){
   x = 4;
   y = 0;
   setBlock(blocknum);//랜덤으로
   color(c);
 
}
 
bool BlockA::check(){
 
   for(int i = 0 ; i < 4 ; i++){
      if(((x+xarr[i]>9)||(y+yarr[i]>17))||((x+xarr[i]<0)||(y+yarr[i]<0))){
         return false;
      }
   }
   return true;
 
}
int BlockA::check0(){
   int re=0;
   for(int i = 0 ; i < 4 ; i++){
      if(blarr[x+xarr[i]][y+yarr[i]].c==1)
         re++;
   }
 
   return re;
 
}
 
void BlockA::moveR(){
   color(1);
   x++;
   if(check()){
      if(check0()==4){
         color(c);
      }else{
         x--;
         color(c);
      }      
   }else{
      x--;
      color(c);
   }
}
 
void BlockA::moveL(){
   color(1);
   x--;
   if(check()){
      if(check0()==4){
         color(c);
      }else{
         x++;
         color(c);
      }      
   }else{
      x++;
      color(c);
   }
}
 
void BlockA::moveD(){
   color(1);
   y++;
   if(check()){
      if(check0()==4){
         color(c);
      }else{
         y--;
         color(c);
      }
   }else{
      y--;
      color(c);
   }
}
 
void BlockA::moveB(){
   color(1);
   while(!(maxY() ==18||(check0()!=4))){
      y++;
   }
   y--;
   color(c);
 
}
 
void BlockA::moveU(){
 
   switch(blocknum){
   case 0:
      rotationB(0,1);
      break;
   case 1:
      rotationB(1,0);
      break;
      /////////////////////////////
   case 2:
      rotationB(2,3);
      break;
 
   case 3:
      rotationB(3,4);
      break;
 
   case 4:
      rotationB(4,5);
      break;
 
   case 5:
      rotationB(5,2);
      break;
      //////////////////////////////
   case 6:
      rotationB(6,7);
      break;
 
   case 7:
      rotationB(7,8);
      break;
 
   case 8:
      rotationB(8,9);
      break;
 
   case 9:
      rotationB(9,6);
      break;
      //////////////////////////////
   case 10:
      break;
      ///////////////////////////////
   case 11:
      rotationB(11,12);
      break;
   case 12:
      rotationB(12,11);
      break;
      ///////////////////////////////
   case 13:
      rotationB(13,14);
      break;
   case 14:
      rotationB(14,13);
      break;
 
      //////////////////////////////
   case 15:
      rotationB(15,16);
      break;
 
   case 16:
      rotationB(16,17);
      break;
 
   case 17:
      rotationB(17,18);
      break;
 
   case 18:
      rotationB(18,15);
      break;
 
   }
 
}
 
void BlockA::addScore(int & score){
   int re = 0;
   for(int i = 0 ; i < 18 ; i++){
      for(int j = 0 ; j < 10;j++){
         if(blarr[j][i].c!=1){
            re++;
         }else{
 
         }
      }
      if(re==10){//i열 지우고 땡기기
         score++;
         for(int f = 0 ; f < i;f++){
            for(int k = 0 ; k < 10 ; k++){
               blarr[k][i-f].c=blarr[k][i-1-f].c;
            }
         }
 
      }
      re = 0;
   }
   char scoreChar[10];
   sprintf(scoreChar,"%d",score);
   attron(COLOR_PAIR(2));
   mvprintw(6,32,scoreChar);
   attroff(COLOR_PAIR(2));
 
 
}
 char * str = new char[20];
void init(int argc){
   initscr(); //cuses모드 시작
   echo();
   if(argc<=1)
   {
   	mvprintw(1,1,"start tetris");
   	mvprintw(3,3,"name: ");
   	getstr(str);
   	refresh();
   	clear();
   }
   resize_term(25,50);//터미널 사이즈 50,25 로 지정
   start_color(); //color사용 선언
 
   init_pair(1,COLOR_GREEN,COLOR_BLACK);//색 attribute 지정
   init_pair(2,COLOR_YELLOW,COLOR_BLACK);//색 attribute 지정
   init_pair(3,COLOR_WHITE,COLOR_BLACK);
   init_pair(4,COLOR_RED,COLOR_BLACK);
   init_pair(5,COLOR_BLUE,COLOR_BLACK);
   init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
   init_pair(7,COLOR_CYAN,COLOR_BLACK);
   init_pair(8,COLOR_GREEN,COLOR_BLACK);
 
   border('|','|','-','-','+','+','+','+');
   refresh();//화면에 나타내기
}
WINDOW** printBackground(WINDOW ** re){
 
   re[0] = newwin(20,22,2,2); 
   wborder(re[0],'|','|','-','-','+','+','+','+');
   wrefresh(re[0]);
 
   re[1] = newwin(4,10,4,30);
   wborder(re[1],'|','|','-','-','+','+','+','+');
   wrefresh(re[1]);
 
   re[2] = newwin(4,10,10,30);
   wborder(re[2],'|','|','-','-','+','+','+','+');
   wrefresh(re[2]);
 
   mvprintw(2,9,"Tetris");
 
   attron(COLOR_PAIR(2));
   mvprintw(5,32,"SCORE:");
   mvprintw(11,32,"NAME:");
   mvprintw(12,33,str);
   delete(str);
   attroff(COLOR_PAIR(2));
 
   refresh();
 
   return re;
 
}
void BlockA::display(){ // 키보드 처리 후의 화면을 출력한다.
   for(int i = 0 ; i < 10;i++){
      for(int j = 0 ; j < 18 ; j++){
         blarr[i][j].printBlock();
      }
   }
 
}
///////////////////////////
int main(int argc, char* argv[])
{
   ifstream inStream;
 
   int q=0;
   char ch=0;
 try{
  	 if (argc>1)
   	{
      inStream.open(argv[1]);
   	}
   	inStream>>str;
   	inStream>>q;
   }catch(ifstream::failure ex)
   {
   	cout<<ex.what()<<endl;
   }
   WINDOW * winmain=0x00l;
   WINDOW * winscore=0x00l;
   WINDOW *winname=0x00l;
   WINDOW*re[3] = {winmain,winscore,winname};
   WINDOW ** del;
   int num = 0;
   int * itoatotalScore = &num;
   bool isGameOver = false;
   // i) arg를 보고, 입력파일이 있으면 파일을 연다. (없으면 그냥 통과)
   init(argc);//테트리스 게임의 초기 화면을 구성한다
   del = printBackground(re);
   //printBackBlock();
   keypad(stdscr, TRUE); //특수키 활성화
   curs_set(0);//커서 없애기
   noecho();//에코 없애기
 
   //int blockC=0;
   int in ;
   char key;
   int score=0;
   int R[]={0,2,6,10,11,13,15};
   srand((unsigned)time(NULL));
   if(argc>1)srand(q);
   BlockA A(R[rand()%7]);
   A.firstSet();
   A.addScore(score);
   A.setBlock(A.blocknum);
   
  while(!isGameOver){
      A.display();

      A.color(1);
      A.y++;
      if(A.maxY() ==18||(A.check0()!=4)){
         A.y--;
         A.color(A.c);
         A.display();
         in = getch();
         if(((in=='d')||(in==' '))||((in=='g')||in==KEY_DOWN)){
            if(A.minY()==0)
               isGameOver = true;
            A.addScore(score);
            A.clear(R[rand()%7]);
 
            continue;
         }
      }else{
         A.y--;
         A.color(A.c);
         if(argc<=1)in = getch();
	   else {
	   inStream>>key;
	   sleep(1);
	   }
      }
 
      if((in=='l'|| key=='l')||(in==KEY_LEFT)){
         A.moveL();
      }else if((in=='r'|| key=='r')||(in==KEY_RIGHT)){
         A.moveR();
      }else if((in=='d'|| key=='d')||(in==' ')){
         A.moveB();
         A.addScore(score);
         A.clear(R[rand()%7]);
 
      }else if((in=='g'|| key=='g')||in==KEY_DOWN){
         A.moveD();
      }else if((in=='u'|| key=='t')||in==KEY_UP){
         A.moveU();
      }else if(in=='q'|| key=='q')
         break;
   }
   return 0;
}            
