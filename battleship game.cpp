#include <iostream>
#include <string>
using namespace std;
const int fieldSize=7;
int num[fieldSize][fieldSize],numcl[fieldSize][fieldSize];
//pos1-строка, pos2-стобец
bool chekPos(int pos1, int pos2){
    if(pos1<0 || pos1> fieldSize-1 || pos2<0 || pos2> fieldSize-1) return true ;
    return num[pos1][pos2]==0 ;
   
}

bool noNrs(int pos1, int pos2)//function that shcekcs if there is no neaghibors
{
    return     chekPos(pos1-1, pos2-1) && 
               chekPos(pos1-1, pos2) && 
               chekPos(pos1-1, pos2+1) && 
               chekPos(pos1, pos2-1) && 
               chekPos(pos1, pos2+1) &&
               chekPos(pos1+1, pos2-1) && 
               chekPos(pos1+1, pos2) && 
               chekPos(pos1+1, pos2+1);
}

bool zvAv(int pos1, int pos2)
{
    if(pos1!=0)
        if(noNrs(pos1-1,pos2))
        return true;
    if(pos1!=6)
        if(noNrs(pos1+1,pos2))
        return true;
    if(pos2!=0)
        if(noNrs(pos1,pos2-1))
        return true;
    if(pos2!=6)
        if(noNrs(pos1,pos2+1))
        return true;
    return false;    
}
bool checkUp(int pos1,int pos2){
        if(pos2!=0)
            return noNrs(pos1,pos2-1);
        return false;
}
bool checkDw(int pos1,int pos2){
        if(pos2!=6)
            return noNrs(pos1,pos2+1);
        return false;
}
bool checkRight(int pos1,int pos2){
        if(pos1!=6)
            return noNrs(pos1+1,pos2);
        return false;
}
bool checkLeft(int pos1,int pos2){
        if(pos1!=0)
            return noNrs(pos1-1,pos2);
        return false;
}

void showFieldcl()
{
     for(int i=0; i<fieldSize; i++)
    {
       for(int z=0; z<fieldSize; z++)
            if(numcl[i][z]==1)
                cout<<"m  ";
            else if(numcl[i][z]==2)
                cout<<"h  ";
            else if(numcl[i][z]==3)
                cout<<"#  ";    
            else
                cout<<"0  ";
        cout<<endl;
    }
}

void showField()
{
     for(int i=0; i<fieldSize; i++)
    {
       for(int z=0; z<fieldSize; z++)
            if(num[i][z]==1)
                cout<<"*  ";
            else
                cout<<"0  ";
        cout<<endl;
    }
}

bool allSunk()//cheks if all ships are sunk
{
     for(int i=0; i<fieldSize; i++)
    {
       for(int z=0; z<fieldSize; z++)
            if(num[i][z]==1)
            return false;
    }
    return true;
}

void bigShip()
{
    int saba;
    int pos1=rand() % 7;
    int pos2=rand() % 7;
        num[pos1][pos2]=1;
        while(true)
        {
            saba=rand() % 3;
            if(saba==0 && pos2>=2)
            {
                num[pos1][pos2-1]=1;
                num[pos1][pos2-2]=1;
                break;
            }
            
            if(saba==1 && pos2<=4)
            {
                num[pos1][pos2+1]=1;
                num[pos1][pos2+2]=1;
                break;
            }
            
            if(saba==2 && pos1>=2)
            {
                num[pos1-1][pos2]=1;
                num[pos1-2][pos2]=1;
                break;
            }
            
            if(saba==3 && pos1<=4)
            {
                num[pos1+1][pos2]=1;
                num[pos1+2][pos2]=1;
                break;
            }
        }    
}

void midShip()
{
    int saba,pos1,pos2;
        while(true){ 
            int pos1=rand() % 7;
            int pos2=rand() % 7;
            if(num[pos1][pos2]==0 && noNrs(pos1, pos2))
            {   
                saba=rand() % 1;
                if(saba==1)
                {
                    if(checkUp(pos1,pos2)){
                        num[pos1][pos2]=1;
                        num[pos1][pos2-1]=1;
                        break;
                    }
                    if(checkDw(pos1,pos2)){
                        num[pos1][pos2]=1;
                        num[pos1][pos2+1]=1;
                        break;
                    }
                    if(checkRight(pos1,pos2)){
                        num[pos1][pos2]=1;
                        num[pos1+1][pos2]=1;
                        break;
                    }
                    if(checkLeft(pos1,pos2)){
                        num[pos1][pos2]=1;
                        num[pos1-1][pos2]=1;
                        break;
                    }
                }
                else{
                    if(checkRight(pos1,pos2)){
                        num[pos1][pos2]=1;
                        num[pos1+1][pos2]=1;
                        break;
                    }
                    if(checkLeft(pos1,pos2)){
                        num[pos1][pos2]=1;
                        num[pos1-1][pos2]=1;
                        break;
                    }    
                    if(checkUp(pos1,pos2)){
                        num[pos1][pos2]=1;
                        num[pos1][pos2-1]=1;
                        break;
                    }
                    if(checkDw(pos1,pos2)){
                        num[pos1][pos2]=1;
                        num[pos1][pos2+1]=1;
                        break;
                    }    
                }
            }
        }
}
void smallShip(){
    int saba,pos1,pos2;
        while(true){ 
            int pos1=rand() % 7;
            int pos2=rand() % 7;
            if(num[pos1][pos2]==0 && noNrs(pos1, pos2)){
                num[pos1][pos2]=1;
                break;
            }
        }
}

void fillNbrs(int pos1, int pos2){
    if(pos1-1>=0 && pos1-1<=fieldSize-1 && pos2-1>=0 && pos2-1<=fieldSize-1)
    numcl[pos1-1][pos2-1]=3; 
    if(pos1-1>=0 && pos1-1<=fieldSize-1 && pos2>=0 && pos2<=fieldSize-1)
    numcl[pos1-1][pos2]=3;
    if(pos1>=0 && pos1<=fieldSize-1 && pos2-1>=0 && pos2-1<=fieldSize-1)
    numcl[pos1][pos2-1]=3;
    if(pos1-1>=0 && pos1-1<=fieldSize-1 && pos2+1>=0 && pos2+1<=fieldSize-1)
    numcl[pos1-1][pos2+1]=3; 
    if(pos1>=0 && pos1<=fieldSize-1 && pos2+1>=0 && pos2+1<=fieldSize-1)
    numcl[pos1][pos2+1]=3; 
    if(pos1+1>=0 && pos1+1<=fieldSize-1 && pos2-1>=0 && pos2-1<=fieldSize-1)
    numcl[pos1+1][pos2-1]=3; 
    if(pos1+1>=0 && pos1+1<=fieldSize-1 && pos2>=0 && pos2<=fieldSize-1)
    numcl[pos1+1][pos2]=3; 
    if(pos1+1>=0 && pos1+1<=fieldSize-1 && pos2+1>=0 && pos2+1<=fieldSize-1)
    numcl[pos1+1][pos2+1]=3;    
}
void makeGuess(){
    int pos1,pos2;
    cin>>pos1>>pos2;
    pos1-=1;
    pos2-=1;
    if(0<=pos1 && pos1<=6 && 0<=pos2 && pos2<=6){
        if(numcl[pos1][pos2]!=1)
        {
            if(num[pos1][pos2]==1)
            {
                if(noNrs(pos1,pos2)){
                cout<<"Sunk!!!";
                fillNbrs(pos1,pos2);
                }
                else
                cout<<"Hit!!!";
                num[pos1][pos2]=0;
                numcl[pos1][pos2]=2;
            }
            else{
            cout<<"Miss!!";
            numcl[pos1][pos2]=1;
            }
        }
        else
        cout<<"You already shot there!!!";
    }
    else
    cout<<"Shooting out of bounds is not allowed";
}

int main()
{   
    cout<<"Welcome to the Battleship game!!!"<<endl<< "h-hit, m-miss, 0- you didnt shoot there yet"<<endl<<endl<<"Type your name:";
    srand((unsigned) time(NULL));
    int n=fieldSize,k=0,val=0,g,h, saba, pos1, pos2;
    string name;
    cin>>name;
     for(int i=0; i<n; i++)
    {
       for(int z=0; z<n; z++)
        {
            num[i][z]=0;
            numcl[i][z]=0;
        }
    }
    //ships spawn
    bigShip();
    midShip();
    midShip();
    smallShip();
    smallShip();
    smallShip();
    smallShip();
    //spawn is done with ships
    showField();
    while(true){
    cout<<endl<<"Now guess where is the ship!!!"<<endl;
    makeGuess();
    val++;
    if(allSunk())
        break;
    cout<<endl;
    showFieldcl();
    }
    cout<<"Congratulations You sunk all ships, your shot count is:"<<val;
    return 0;
} 
