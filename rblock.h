#ifndef __RBLOCK_H__
#define __RBLOCK_H__

class Block
{
 
   int x;
   int y;
   int c;
public:
   
   Block();
   void printBlock();
   friend class BlockA;
};
 
class BlockSet{
public:
   int blocknum;
   int x;
   int y;
   int c;
   int xarr[4];
   int yarr[4];
};
 
class BlockA : public BlockSet{ 
   static Block blarr[10][18];
public:
   int maxY();
   int minY();
   
   BlockA(int blocknum);
 
   void display();
   void firstSet();
   void setBlock(int blocknum);
   void clear(int blocknum);
   void color(int c);
   void rotationB(int blocknum1,int blocknum2);
 
   bool check();
   int check0();
 
   void moveL();
   void moveR();
   void moveD();//밑으로
   void moveB();//바닥
   void moveU();//돌리기
 
   void addScore(int& score);
};
 #endif
