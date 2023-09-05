#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
using namespace std;

/* Reference
                    00|01|02
                    10|11|12
                    20|21|22

*/

string A =" ";
string B =" ";
char Grid[3][3] =  {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}}; // create 2d array
                    

bool tie = true;
int row;
int column;
char token ='x'; 
void choice();
int a;  // a is any digit



void Getdata() 


  {

    cout << Grid[0][0] << " " << Grid[0][1] << " " << Grid[0][2] << endl;
    cout << Grid[1][0] << " " << Grid[1][1] << " " << Grid[1][2] << endl;
    cout << Grid[2][0] << " " << Grid[2][1] << " " << Grid[2][2] << endl;


  
}

void choice()
{      
 cout<<"Make your choice, choose gridroom: "<<endl;


          if(token=='x')
      {
        cout<<A<<" please enter your digit: ";
        cin>>a;
      }
          if(token=='o')
      {
        cout<<B<<" please enter your digit: ";
        cin>>a;
      }
       
         if(a==1)
          {
             row=0;
             column=0;
             
          }
             
         if(a==2)
            
          {
             row=0;
             column=1;

          }   
         if(a==3)
         
          {
             row=0;
             column=2;
        
          }  
         if(a==4)
       
          {
             row=1;
             column=0;
        
          }  
         if(a==5)
         
          {
             row=1;
             column=1;
         
          } 
         if(a==6)
         
          {
             row=1;
             column=2;
         
          } 
         if(a==7)
          
          {
             row=2;
             column=0;
           
          }   
         if(a==8)
          
          {
             row=2;
             column=1;
        
          } 
         if(a==9)
         
          {
             row=2;
             column=2;
             

          }
         else if(a<1 || a>9)
       
          {
            cout<<"invalid choice"<<endl;
          }

          if (token=='x' && Grid[row][column] !='x' && Grid[row][column]!='o')
          {
            Grid[row][column]='x';
            token='o';
          }
           else if (token=='o' && Grid[row][column] !='x' && Grid[row][column]!='o')
          {
            Grid[row][column]='o';
            token='x';
          }
        else {
            cout<<"There is no empty space"<<endl;
            choice();
        }
       
 
}




bool check()
{

    for (int i= 0; i< 3; i++)
    {
        if (Grid[0][i]== Grid[i][1] && Grid[0][i] == Grid[i][2] || Grid[0][i] == Grid[1][0] && Grid[0][i] == Grid[2][i]) //horizontally and vertically

        {
            return true;
        }
        if (Grid[0][0] == Grid[1][1] && Grid[0][0] == Grid[2][2] || Grid[0][2] == Grid[1][1] && Grid[0][2] == Grid [2][0]) //diagonally
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; i < 3; j++)
        {
            if (Grid[i][j] != 'x' && Grid[i][j] != 'o')
            {
                return false;
            }
        }
    }
tie=true;
return false;

}

int main()
{


    cout << "_____Welcome to the Tic Tac Toe Game_____" << endl;

    cout << "enter the name of the first player:" << endl;
    getline(cin, A); // press enter then write the player 1 name
    cout << "enter the name of the second player:" << endl;
    getline(cin, B); // press enter then write the player 2 name

   
        cout<<A << " will play first" << endl;

        cout<<B << " will play second" << endl;
  
    
    while(!check())
    {
        Getdata();
        cout<<endl;
        choice();
        cout<<endl;
        check();
        cout<<endl;

    }
if (token=='x' && tie == false)
{
    cout<<A<<"wins!!"<<endl;
}
else if(token=='o' && tie == false)
{
    cout<<B<<"wins!!"<<endl;
}
else{
    cout<<"Its a draw!!"<<endl;
}

    return 0;
}