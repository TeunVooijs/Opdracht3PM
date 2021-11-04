#include <iostream>
#include <fstream>
using namespace std;


void clearview(){

cout << "dikke hoer\n";
}

void heelschoon(){

cout << "Tyfus trut\n";

}

void parameters(){

cout << "P\n";

}

void random(){

cout << "R\n";


}

void toggle(){

cout << "T\n";


}

void glidergun(){

cout << "F\n";


}

void run(){
    cout << "G" ;


}





void view(){
    const int x=10,y=10;
    bool m[x][y]={{false}};
    int herhalingen;

    cout << "Geef aantal herh.: "<< endl;
    cin >> herhalingen;

    // for (int i = 0; i < x; i++){
    //     for (int j = 0; j < y; j++){
    //     m[i][j]; 
    //     }
    // }

    while(herhalingen!=0){
        
        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                if(m[i][j]){
                    cout << m[i][j]; 
                }
                else{
                    cout << '.';
                }
            }
            cout << endl;
        }

        if(herhalingen!=1){
            cout << endl << endl << endl;
        }
        herhalingen-=1;
    }


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
        heelschoon();
        break;
    case 'c': case 'C':
        clearview();
        break;
    case 'p': case 'P':
        parameters();
        break;
    case 'r': case 'R':
        random();
        break;
    case 't': case 'T':
        toggle();
        break;
    case 'f': case 'F':
        glidergun();
        break;
    case 'e': case 'E':
        run();
        break;
    case 'g': case 'G':
        run();
        break;
    case 'v': case 'V':
        view();
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