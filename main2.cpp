#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;



class life
{
public:
    life();
    void gen();
    void gen2();
    bool menu();
    void live();
    void show();
    void print();
    void cursor();
    void heelschoon();
    void clear_view();
    void parameters();
private:

    static const int MAX=1000;
    int view_breedte, view_hoogte;
    int viewx,viewy;
    int varfalse,vartrue;
    bool mat[MAX][MAX]={{false}};
    bool mat2[MAX][MAX]={{false}};

};

life::life(){
    view_breedte=80;
    view_hoogte=25;
    viewx=0;
    viewy=0;


}






void life::gen(){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            int aanliggend=0;
            
            if (mat[i-1][j-1] && i!=0 && j!=0 ){
                aanliggend+=1;
            }
            if (mat[i-1][j] && i!=0){
                aanliggend+=1;
            }
            if (mat[i-1][j+1] && i!=0 && j+1!=MAX){
                aanliggend+=1;
            }
            if (mat[i][j-1] && j!=0){
                aanliggend+=1;
            }
            if (mat[i][j+1] && j+1!=MAX){
                aanliggend+=1;
            }
            if (mat[i+1][j-1] && i!=MAX && j!=0){
                aanliggend+=1;
            }
            if (mat[i+1][j] && i!=MAX){
                aanliggend+=1;
            }
            if (mat[i+1][j+1] && i!=MAX && j+1!=MAX){
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

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            mat[i][j]=mat2[i][j];
        }
    }
}

void life::gen2(){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            int aanliggend=0;
            for (int m = -1; m <= 1; m++){
                for (int n = -1; n <= 1; n++)                {
                    int check_x=i+m;
                    int check_y=j+n;
                    if (m!=0 && n!=0 && mat[check_x][check_y]
                        && (!(check_x>MAX) || !(check_x<0)) 
                        && (!(check_y>MAX) || !(check_y<0))){
                        aanliggend+=1;
                    }
                }
            }
            if(aanliggend==2){
                mat2[i][j]=mat[i][j];
            }
            else if(aanliggend==3){
                mat2[i][j]={true};
            }
            else{
                mat2[i][j]={false};
            }
        }
    }
    
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            mat[i][j]=mat2[i][j];
        }
    }
    



}

void life::heelschoon(){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            mat[i][j]={false};
        }   
    }    
}

void life::parameters(){
    


    




}


void life::clear_view(){
    for (int i = viewy; i < view_hoogte; i++){
        for (int j = viewx; j < view_breedte; j++){
            mat[i][j]={false};
        }
    }
}

void life::cursor(){




}



void life::print(){     
    for (int i = viewy; i < view_hoogte; i++){
        for (int j = viewx; j < view_breedte; j++){
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

bool menu(){
    char keus;
    life my_life;
    
    cout << "Geef letter: " << endl;
    
    // cin.get(keus,100);
    cin >> keus;
    switch (keus){
    case 's': case 'S':
        return true;    
        break;
    case 'h': case 'H':
        my_life.heelschoon();
        break;
    case 'c': case 'C':
        break;
    case 'p': case 'P':
        break;
    case 'r': case 'R':
        break;
    case 't': case 'T':
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







int main(){

    while (true){
        if (menu()){return 0;}
    }
    return 0;
    
}