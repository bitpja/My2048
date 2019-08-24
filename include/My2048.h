#ifndef MY2048_H
#define MY2048_H

#include<vector>
#include<iostream>
#include<random>
#include<stdlib.h>
#include<time.h>
using namespace std;

class My2048
{
    public:
        My2048(int x=4,int y=4);
        virtual ~My2048();
        bool Init();
        char Check();
        void Move();
        void Print();
        void MoveSingRow(int row,int dir);
        void MoveSingCol(int col,int dir);
        void Play();
        void Make();
    protected:

    private:
//        vector<vector<int> > _map(4,vector<int>(4,0));
        vector<vector<int> > _map;
        int _x,_y;
        unsigned int _sum = 0;
};

#endif // MY2048_H
