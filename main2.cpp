#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

const int MAX=400;


class life
{
private:
    bool mat[MAX][MAX]={{false}};
    bool mat2[MAX][MAX]={{false}};

public:
    int size=0;
    int width, height;
    int pos_x[MAX],pos_y[MAX];
    int parx1,parx2,pary1,pary2;
    int varfalse,vartrue;


    void gen(){
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                int aanliggend=0;
                
                if (mat[i-1][j-1] && i!=0 && j!=0 ){
                    aanliggend+=1;
                }
                if (mat[i-1][j] && i!=0){
                    aanliggend+=1;
                }
                if (mat[i-1][j+1] && i!=0 && j+1!=width){
                    aanliggend+=1;
                }
                if (mat[i][j-1] && j!=0){
                    aanliggend+=1;
                }
                if (mat[i][j+1] && j+1!=width){
                    aanliggend+=1;
                }
                if (mat[i+1][j-1] && i!=height && j!=0){
                    aanliggend+=1;
                }
                if (mat[i+1][j] && i!=height){
                    aanliggend+=1;
                }
                if (mat[i+1][j+1] && i!=height && j+1!=width){
                    aanliggend+=1;
                }
                
                            
                if (mat[i][j]){
                    switch (aanliggend)
                    {
                    case 2: case 3:
                        mat2[i][j]={true};
                        break;
                    case 0: case 1: case 4: case 5: case 6: case 7: case 8:
                        mat2[i][j]={false};
                        break;
                    default:
                        break;
                    }
                }
                else if (!mat[i][j] && aanliggend==3){
                    mat2[i][j]={true};
                }
            }
        }
    
    for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                mat[i][j]=mat2[i][j];
            }
        }
    
    }

    void run(){
        gen();
        print();
    }
    
    
    void print(){
        
        for (int i = pary1; i < pary2; i++){
            for (int j = parx1; j < parx2; j++){
                if (mat[i][j]){
                    cout << "X" << " ";
                }
                else{
                    cout << " "; //<< " ";
                }
            }
            cout << endl;
        } 
    }






















};







int main(){

    while (true){
        if (menu()){return 0;}
    }
    return 0;


}