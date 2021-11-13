#include <iostream>
using namespace std;


// als karakter a-z is sla op en return

void read_char(int arr[]){
    char kar='\0';
    char firstkar,firstkar2;
    bool continu=true;
    int count=0;

    

    while(kar!='\n'){
        kar=cin.get();        
        if(count==0){
            firstkar=kar;
            if (kar>='A' && kar <='Z'){
                firstkar2=kar+32;
            }
            else{
                firstkar2=kar-32;
            }
        }
        if((kar==firstkar || kar==firstkar2) && continu==true){
            count+=1;
        }
        else{
            continu=false;
        }

    }
    arr[0]=firstkar;
    arr[1]=count;
}



int read_num(int aantal){
    int getal=0;
    char kar='\0';
    int numkar;
    cout << "Geef getal: ";
    while (kar!='\n')
    {
        kar=cin.get();
        if (kar>='0' && kar<='9' && getal<100 && aantal>=1){
            numkar=kar-48;
            getal=getal*10+numkar;
            aantal-=1;
        }
    }

    return getal;
}









class life
{
public:
    void go();
    void gen();
    bool menu();
    void print();
    void alive();
    void cursor(int keus,int count);
    void toggle();
    void random();
    void legenda();
    void move_view();
    void heelschoon();
    void clear_view();
    void parameters();
    void cursorchecker();
    life();
private:

    static const int MAX=1000;
    int view_breedte, view_hoogte;
    int viewx,viewy;
    int generaties;
    int move_lengte;
    int rand_alive;
    double pro_alive;
    int varfalse,vartrue;
    bool mat[MAX][MAX]={{false}};
    bool mat2[MAX][MAX]={{false}};
    int cursorposx,cursorposy,blax;
    char chartrue,charfalse,charborder;
    char charcursor,charcursortrue;
};

life::life(){
    cursorposx=40;
    cursorposy=12;
    viewx=0;
    viewy=0;
    view_breedte=80;
    view_hoogte=25;
    chartrue='X';
    charfalse='.';
    charcursortrue='$';
    charcursor='%';
    move_lengte=5;
    charborder='@';
}

void life::move_view(){
    int arr[2],afstand;
    cout << "Hoeveel stappen wil je de view verplaatsen?(getal van 1 tm 9)" << endl;
    afstand=read_num(1);
    cout << "In welke richting wil je de view verplaatsen?(Gebruik w/a/z/d)" << endl;
    read_char(arr);
    
    switch (arr[0]){
    case 'w':
        viewy-=(move_lengte*afstand); 
        view_hoogte=viewy+25;
        break;
    case 'a':
        viewx-=(move_lengte*afstand); 
        view_breedte=viewx+80;
        break;
    case 'z':
        viewy=viewy+(move_lengte*afstand); 
        view_hoogte=viewy+25;
        break;
    case 'd':
        viewx+=(move_lengte*afstand); 
        view_breedte=viewx+80;
        break;
    default:
        break;
    }
    cursorposx=viewx+40;
    cursorposy=viewy+12;
}

void life::print(){     
    for (int i=viewy; i < view_hoogte; i++){
        for(int j=viewx; j<view_breedte; j++){
            if (i>=0 && i <=MAX && j>=0 && j<=MAX){
            
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
            else{
                cout << charborder << " ";
            }
        }
        cout << endl;
    }
    
}



void life::gen(){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            int aanliggend=0;
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
                mat2[i][j]=mat[i][j];
            }
            else if(aanliggend==3){
                mat2[i][j]={true};
            }
            else{
                mat2[i][j]=false;
            }
        }
    }
    
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            mat[i][j]=mat2[i][j];
        }
    }
    
}

void life::go(){
    int rounds;
    generaties=0;

    rounds=read_num(3);

    for (int i = 0; i < rounds; i++){
        gen();
        print();
        generaties+=1;

        cout << "Generatie: " << generaties << endl;
    }
}

void life::random(){





}

void life::toggle(){
    if(mat[cursorposy][cursorposx]==true){
        mat[cursorposy][cursorposx]={false};
    }
    else{
        mat[cursorposy][cursorposx]={true};
    }
}

void life::alive(){
    int alive=0;
    for (int i = viewy; i < viewy+25; i++){
        for (int j = viewx; j < viewx+80; j++){
            if (mat[i][j]){
                alive+=1;
            }
        }
        
    }
    
    pro_alive=(alive*100)/(80*25);
}

void life::heelschoon(){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            mat[i][j]={false};
        }   
    }      
}

void life::legenda(){
    cout << "Cursor positie is: (" << cursorposx << "," <<
        cursorposy << ") View is:(" << viewx << "," << viewy 
        << ") Aantal generaties: " << generaties << endl; 

}



void life::parameters(){
    int optie;
    int arr[0];
    alive();
    
    cout << "wat wil je veranderen: " << endl <<
    "1: Leven karakter is: " << chartrue << endl <<
    "2: Dood karakter is: " << charfalse << endl <<
    "3: Border Karakter is: " << charborder << endl <<
    "4: Cursor dood karakter is: " << charcursor << endl <<
    "5: Cursor levend karakter is: " << charcursortrue << endl <<
    "6: Aantal levende cellen in view in procent: " << pro_alive << endl <<
    "7: Stapgrootte van de view is: " << move_lengte << endl; 
    optie=read_num(2);
    if(optie>=1 && optie<=7){
    switch (optie){
    case 1:
        cout << "In welk karakter moet het levend karakter veranderen: ";
        read_char(arr);chartrue=arr[0];
        break;
    case 2:
        cout << "In welk karakter moet het dode karakter veranderen: ";
        read_char(arr);charfalse=arr[0];
        break;
    case 3:
        cout << "In welk karakter moet de border veranderen: ";
        read_char(arr);charborder=arr[0];
        break;
    case 4:
        cout << "In welk karakter moet de dode cursor veranderen: ";
        read_char(arr);charcursor=arr[0];
        break;
    case 5:
        cout << "In welk karakter moet de levende cursor veranderen: ";
        read_char(arr);charcursortrue=arr[0];
        break;
    case 6:
        cout << "Welk percentage van de view moet levend worden: ";
        rand_alive=read_num(2);
        break;
    case 7:
        cout << "Wat moet de stapgrootte van de view verplaatsing worden: ";
        move_lengte=read_num(2);
        break;
    default:
        break;
    }
    }
}


void life::clear_view(){
    for (int i = viewy; i < view_hoogte; i++){
        for (int j = viewx; j < view_breedte; j++){
            mat[i][j]={false};
        }
    }
}

void life::cursor(int keus,int count){
    switch (keus){
    case 'w':
        for (int i = 0; i < count; i++){
            if(cursorposy>0){cursorposy-=1;}
            if (cursorposy<viewy){viewy-=1; view_hoogte-=1;}
        }
        break;
    case 'a':
        for (int i = 0; i < count; i++){
            if(cursorposx>0){cursorposx-=1;}
            if(cursorposx<viewx){viewx-=1; view_breedte-=1;}
        }
        break;
    case 'd':
        for (int i = 0; i < count; i++){
            if(cursorposx<MAX){cursorposx+=1;}
            if(cursorposx>=viewx+80){viewx+=1; view_breedte+=1;}
        }
        break;
    case 'z':
        for (int i = 0; i < count; i++){
            if(cursorposy<MAX){cursorposy+=1;}
            if(cursorposy>=viewy+25){viewy+=1; view_hoogte+=1;}
        }
        break;
    default:
        break;
    }
}



bool menu(life & my_life){
    int arr[2];
    cout << "Geef aan wat je wil doen" << endl <<
    "Type de letter die tussen de haakjes staat om het uit te voeren" << endl <<
    "(S)toppen, (H)eelschoon, s(C)hoon, (M)ove view, (P)arameters, "
    "(R)andom, (T)oggle, g(L)idergun, (E)en generatie, (G)a meerdere, (W/A/Z/D) bewegen cursor: ";
    
    read_char(arr);
    
    
    switch (arr[0]){
    case 's': case 'S':
        return true;    
        break;
    case 'h': case 'H':
        my_life.heelschoon();
        break;
    case 'c': case 'C':
        my_life.clear_view();
        break;
    case 'p': case 'P':
        my_life.parameters();
        break;
    case 'r': case 'R':
        //random
        break;
    case 't': case 'T':
        my_life.toggle();
        break;
    case 'e': case 'E':
        my_life.gen();
        break;
    case 'g': case 'G':
        my_life.go();
        break;
    case 'v': case 'V':
        // view();
        break;
    case 'm': case 'M':
        my_life.move_view();
        break;
    case 'w':case 'a':case 'z':case 'd':
        my_life.cursor(arr[0],arr[1]);
    default:
        break;
    } 
    return false;

}



int main(){
    life main_life;

    while (true){
        main_life.print();
        main_life.legenda();
        if (menu(main_life)){return 0;}
        
    }
    return 0;
    
}