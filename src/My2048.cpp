#include "include/My2048.h"

My2048::My2048(int x,int y):_x(x),_y(y)
{
    //ctor
    _map.resize(y);
    for(auto& m:_map)
        m.resize(x);

}

My2048::~My2048()
{
    //dtor
}

void My2048::Print(){
    for(auto i:_map){
        for(auto j:i)
            printf(" %d ",j);
        printf("\n");
    }


}

bool My2048::Init(){


}

void My2048::Make(){
    while(1){
        srand(int(time(0)));
        int x = rand() % _x;
        int y = rand() % _y;
        if(_map[y][x] == 0){
            _map[y][x] = 2;
            break;
        }

    }
    Print();
}


char My2048::Check(){
    char tmp;
    cin>>tmp;
    return tmp;
}

void My2048::Move(){
    switch(Check()){
        case'w':    MoveSingRow(0,1);
                    break;
        case's':    MoveSingRow(_y-1,-1);
                    break;
        case'a':    MoveSingCol(0,1);
                    break;
        case'd':    MoveSingCol(_x-1,-1);
                    break;
        default:    cout<<"Please enter w,s,a,d"<<endl;
    }
}

void My2048::Play(){
    while(1){
        Make();
        Move();
 //       Print();
    }
}

bool visitRow[4]={0},visitCol[4] = {0};

void My2048::MoveSingCol(int col,int dir){
    if(col<0 || col >= _x){
        for(int i=0; i<_x; i++)
            visitRow[i] = false;
        return;
    }

    for(int i=0; i<_x ; i++){
        if(visitRow[i]) continue;

        if(_map[i][col] == 0 && !visitRow[i]){
                int pi = col+dir;
                for(; pi<_x && pi >= 0  && _map[i][pi] ==0; pi += dir);
                if(pi<0 || pi >=_x){
                    visitRow[i] = true;
                    continue;
                }
                else{
                    for(int pj=col;pj>=0 && pj<_x;pj += dir)
                        if(pi>=0 && pi<_x){
                            _map[i][pj] = _map[i][pi];
                            pi += dir;
                        }
                        else      _map[i][pj] = 0;

                }

        }

            int pi = col+dir;
            for(; pi<_x && pi >= 0 && _map[i][pi] ==0 ; pi += dir);
            if(pi<0 || pi >=_x){
                    visitRow[i] = true;
                    continue;
            }
            if(_map[i][col] == _map[i][pi]){
                _map[i][col] *= 2;
                _map[i][pi] = 0;
            }




    }
    MoveSingCol(col+dir,dir);
}

void My2048::MoveSingRow(int row,int dir){
    if(row<0 || row >= _y){
        for(int i=0; i<_y; i++)
            visitCol[i] = false;
        return;
    }

    for(int i=0; i<_y ; i++){
        if(visitCol[i]) continue;

        if(_map[row][i] == 0){
                int pi = row+dir;
                for(; pi<_y && pi >= 0 && _map[pi][i] ==0 ; pi += dir);
                if(pi<0 || pi >=_y){
                    visitCol[i] = true;
                    continue;
                }
                else{
                    for(int pj=row;pj>=0 && pj<_y;pj += dir)
                        if(pi>=0 && pi<_y){
                            _map[pj][i] = _map[pi][i];
                            pi += dir;
                        }
                        else      _map[pj][i] = 0;

                }

        }

            int pi = row+dir;
            for(; pi<_y && pi >= 0 && _map[pi][i] ==0 ; pi += dir);
            if(pi<0 || pi >=_y){
                    visitCol[i] = true;
                    continue;
            }
            if(_map[row][i] == _map[pi][i]){
                _map[row][i] *= 2;
                _map[pi][i] = 0;
            }






    }
    MoveSingRow(row+dir,dir);
}
