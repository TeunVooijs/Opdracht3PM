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
    int pos_x[MAX],pos_y[MAX];
    int width,height;
    int parx1,parx2,pary1,pary2;



    void pos_adder(int x,int y){        

        if(size==0){
            pos_x[size]={x};
            pos_y[size]={y};
            // mat[pos_x[size]][pos_y[size]]={true};
        }
        else if (size!=0){
            pos_x[size]=x;
            pos_y[size]=y;

            // mat[pos_x[size]][pos_y[size]]={true};
        }
        // cout << pos_y[size] << endl;
        // cout << pos_x[size] << endl;
    }

    // void run(){
    //     // for (int i = 0; i < size; i++){
    //     //     cout << pos_x[i] << " " << pos_y[i] << endl;
    //     // }
    //     for (int i = 0; i < size; i++){
    //         cout << pos_x[i] << " " << pos_y[i] << endl;
    //     }
    // }
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
    void runner(int x){
        for (int i = 0; i < x; i++)
        {
            show();
            gen();
            cout << endl << i << endl;
            Sleep(300);
        }
        

    }


    void live(){
        for (int i=0; i< size; i++){
            mat[pos_x[i]][pos_y[i]]={true};
        }   
    }


    // void change(){
    //     for(int i=0; i<size )
    //         if (mat[pos_x[i]][pos_y[j]]==true){
    //             if (mat[pos_x[i+1]][pos_y[j]]==true){
                
    //             }
    //             if (mat[pos_x[i]][pos_y[j]]==true){
                
    //             }
    //             if (mat[pos_x[i]][pos_y[j]]==true){
                
    //             }
    //             if (mat[pos_x[i]][pos_y[j]]==true){
                
    //             }
    //         }
    // }
    



    void show(){
        
        for (int i = pary1; i < pary2; i++){
            for (int j = parx1; j < parx2; j++){
                if (mat[i][j]){
                    cout << "X" << " ";
                }
                else{
                    cout << /*mat[i][j]*/ " "; //<< " ";
                }
            }
            cout << endl;
        } 
        // cout << width << " " << height << endl;
    }
};
// glider gun
//  {1,2,2,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,6,7,7,7,8,8,9,9}
//  {25,23,25,13,14,21,22,35,36,12,16,21,22,35,36,1,2,11,17,21,22,1,2,11,15,17,18,23,25,11,17,25,12,16,13,14}
void glidergun(){
    // int x[]={2,2,6,3,5,5,5,23,17,14,19},y[]={4,6,8,2,18,19,20,6,18,12,21};
    int x[]={6,7,7,8,8,8,8,8,8,9,9,9,9,9,9,10,10,10,10,10,10,11,11,11,11,11,11,11,11,12,12,12,13,13,14,14};
    int y[]={30,28,30,18,19,26,27,40,41,17,21,26,27,40,41,6,7,16,22,26,27,6,7,16,20,22,23,28,30,16,22,30,17,21,18,19};
    int size=sizeof(x)/sizeof(x[0]);;
    life mat;


    mat.parx1=0;
    mat.parx2=120;
    mat.pary1=5;
    mat.pary2=30;


    mat.height=100;
    mat.width=200;
    size=sizeof(x)/sizeof(x[0]);
    cout << size << endl;
    for (int i = 0; i < size; i++){
        int j=i;
        mat.pos_adder(x[j],y[i]);
        mat.size+=1;
    }
    int bla;
    cout << "Hoe vaak: " << endl;
    cin >> bla;


    // int parx1,parx2,pary1,pary2;




    // mat.run();
    mat.live();
    mat.show();
    // mat.gen();
    mat.runner(bla);


}

bool menu(){
    char keus;
    cout << "Kies een letter: " << endl;
    cin >> keus;
    switch (keus)
    {
    case 's': case 'S':
        return true;    
        break;
    case 'h': case 'H':
        break;
    case 'c': case 'C':
        break;
    case 'p': case 'P':
        break;
    case 'r': case 'R':
        break;
    case 't': case 'T':
        break;
    case 'f': case 'F':
        glidergun();
        break;
    case 'e': case 'E':
        break;
    case 'g': case 'G':
        // run();
        // matrix();
        break;
    case 'v': case 'V':
        // view();
        break;    
    default:
        break;
    } 
    return false;
}
//life::drukaf




// void print(){
//     life matrix;

    
//     // matrix.width=5;
//     // matrix.height=7;
//     // matrix.mat[matrix.height][matrix.height];

//     matrix.width=10;
//     matrix.height=10;
//     matrix.show();
//     // matrix.show(matrix.width,matrix.height);


    


// }




// int f[], int g[], int size
// bool matrix(){
//     const int x=40,y=40;
//     int cordx,cordy, size=6;
//     int f[]={0},g[]={0};
//     bool m[x][y]{};


//     for (int i = 0; i < size; i++){
//         cordx=f[i]; cordy=g[i];
//         m[cordx][cordy]=true;    
//     }


//     for (int i = -1; i < x; i++){
//         for (int j = -1; j < y; j++){   
//             // if (m[x][y]==true)
//             // {
//             //     cout << "A" << " ";
//             // }
//             // else{
//             //     cout << m[i][j] << " ";
//             // }
//             if (i==-1 && j!=-1){
//                 cout << j << " ";
//             }
//             else if(j==-1 && i==-1){
//                 cout << "  ";
//             }
//             else if(j==-1 && i!=-1){
//                 cout << i << " ";
//             }
//             else{
//                 cout << m[i][j] << " ";
//             }
//         }
//         cout << endl;
//     }
    
//     return 0;
// }





int main(){

    while (true){
        if (menu()){return 0;}
    }
    return 0;


}