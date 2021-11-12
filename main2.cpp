#include <iostream>
using namespace std;



class life
{
public:
    void print();
    void gen();
    void gen2();
    bool menu();
    void cursor(int keus,int count);
    void toggle();
    void heelschoon();
    void clear_view();
    void parameters();
    life();
private:

    static const int MAX=1000;
    int view_breedte, view_hoogte;
    int viewx,viewy;
    int varfalse,vartrue;
    bool mat[MAX][MAX]={{false}};
    bool mat2[MAX][MAX]={{false}};
    int cursorposx,cursorposy,blax;
    char chartrue,charfalse;
    char charcursor,charcursortrue;
};

life::life(){
    cursorposx=40;
    cursorposy=13;
    blax=1;
    view_breedte=80;
    view_hoogte=25;
    viewx=0;
    viewy=0;
    chartrue='X';
    charfalse='.';
    charcursortrue='$';
    charcursor='%';
}

void life::print(){     
    for (int i=viewx; i < view_hoogte; i++){
        for(int j=viewy; j<view_breedte; j++){
            if(i==cursorposy && j==cursorposx){
                if (mat[i][j]){
                    cout << charcursortrue << " ";
                }
                else if(mat[i][j]==false){
                    cout << charcursor << " ";
                }
            }
            else if(mat[i][j]){
                cout << chartrue << " "; 
            }
            else{
                cout << charfalse << " ";
            }
        }
        cout << endl;
    }
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
    bool cur,next;
    
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            int aanliggend=0;
            cur=mat[i][j];
            next=false;
            for (int m = -1; m <= 1; m++){
                for (int n = -1; n <= 1; n++){
                    int check_x=i+m;
                    int check_y=j+n;
                    if ((m!=0 || n!=0) && (mat[check_x][check_y])
                        && (check_x<MAX && check_x>=0) 
                        && (check_y<MAX && check_y>=0)){
                        aanliggend+=1;
                    }
                }
                
            }

            if(aanliggend==2){
                next=cur;
                cout << aanliggend << endl;
                // mat2[i][j]=mat[i][j];
            }
            else if(aanliggend==3){
                next=true;
                // mat2[i][j]={true};
            }
            // else{
                // mat2[i][j]={false};
            // }
            mat2[i][j]=next;
        }
    }
    
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            mat[i][j]=mat2[i][j];
        }
    }
    
}

void life::toggle(){
    int aantal=0;
    if(mat[cursorposy][cursorposx]==true){
        mat[cursorposy][cursorposx]={false};
    }
    else{
        mat[cursorposy][cursorposx]={true};
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            mat[j][j]=mat2[i][j];
            
            if (mat[i][j]==true)
            {
                aantal+=1;
            }
            
        }
        
    }
    // cout << aantal << endl;
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

void life::cursor(int keus,int count){
    switch (keus)
    {
    case 'w':
        for (int i = 0; i < count; i++){
            cursorposy-=1;
        }
        break;
    case 'a':
        for (int i = 0; i < count; i++){
            cursorposx-=1;
        }    
        break;
    case 'd':
        for (int i = 0; i < count; i++){
            cursorposx+=1;
        }
        break;
    case 'z':
        for (int i = 0; i < count; i++){
            cursorposy+=1;
        }
        break;
    default:
        break;
    }
   


}





bool menu(life & my_life){
    char keus;
    int count=1;
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
        // my_life.print();
        my_life.toggle();
        break;
    case 'e': case 'E':
        break;
    case 'g': case 'G':
        my_life.gen2();
        break;
    case 'v': case 'V':
        // view();
        break;
    case 'w':case 'a':case 'z':case 'd':
        my_life.cursor(keus,count);
        // my_life.print();
    default:
        break;
    } 
    return false;

}



int main(){
    life kanker;;

    while (true){
        kanker.print();
        if (menu(kanker)){return 0;}
    }
    return 0;
    
}