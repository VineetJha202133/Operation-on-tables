#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int** L(int x, int y, char* name){  
    cout<<name<<" :Enter all the "<<  x*y  <<" elements of matrix in correct order."<<endl; 
    int **A = new int*[x]; 
    for(int i=0; i<x; i++){
        A[i] = new int[y];
        for(int j=0; j<y; j++)
        cin>>A[i][j];
    }
   return A; 
}
void show(int **A,int x,int y,  char* name){  
    cout<<name<<":"; 
    for(int i=0; i< x ; i++){
        for(int j=0; j<y; j++)
        cout<<A[i][j]<<""; 
        cout<<"\n";
    }
}

void U (int **A, int x){  
for(int i=0; i<x; i++)
delete A[i]; 
delete[]A;
}

int** add(int **A,int **B,int x,int y){ 
int **C= new int*[x]; 
for(int i=0; i<x; i++){
    C[i]= new int[y];
    for(int j=0; j<y; j++)
    C[i][j] = A[i][j] + B[i][j];
}
return C;
}

int** subtract(int **A,int **B,int x,int y){ 
int **C= new int*[x]; 
for(int i=0; i<x; i++){
    C[i]= new int[y]; 
    for(int j=0; j<y; j++)
    C[i][j] = A[i][j] - B[i][j];
}
return C;
}
int** multiply(int **A,int **B,int x1,int y1,int y2){  
int **C= new int*[x1]; 
for(int i=0; i<x1; i++){
    C[i] = new int[y2];
    for(int j=0; j<y2; j++){
        C[i][j] =0; 
        for(int k=0; k<y1; k++)
        C[i][j] += A[i][k] * B[k][j];
    }
}
return C;
}

int** transpose(int **A,int x, int y){ 
    int **B = new int* [y];
    for(int i=0; i<y;i++){
        B[i]= new int[x];
        for(int j=0;j<x; j++){
        B[i][j] = A[j][i]; 
     }
    }
    return B;
}

int main(){   
 int ch=0;
 do{
     system("cls"); 
     cout<<"\n   Operations:-";
      cout<<"\n   1.Addition of matrices";
       cout<<"\n   2.Subtraction of matrices";
        cout<<"\n   3.Multiplication ofmatrices";
         cout<<"\n   4.Transpose of matrix";
         cout<<"\n   Enter the serial number of the operation you want to perform: ";
    cin>>ch;
  int x1, y1, x2, y2;
  int **I1, **I2, **O;
  switch (ch)
  {
case 1:
  cout<<"Enter the rows of matrix:";
  cin>>x1;
  cout<<"Enter the columns of matrix:";
  cin>>y1;
  I1=L(x1,y1,"1st matrix");
  I2=L(x1, y1,"2nd matrix");
  O = add(I1,I2,x1,y1);
  show(I1, x1, y1, "1st matrix");
   show(I2, x1, y1, "2nd matrix");
    show(O, x1, y1, "Output matrix");
    U(I1, x1);
    U(I2, x1);
    U(O, x1);
      break;
case 2:
  cout<<"Enter the rows of matrix:";
  cin>>x1;
  cout<<"Enter the columns of matrix:";
  cin>>y1;
  I1=L(x1,y1,"1st matrix");
  I2=L(x1, y1,"2nd matrix");
  O = subtract(I1,I2,x1,y1);
  show(I1, x1, y1, "1st matrix");
   show(I2, x1, y1, "2nd matrix");
    show(O, x1, y1, "Output matrix");
    U(I1, x1);
    U(I2, x1);
    U(O, x1);
      break;
 case 3: 
      cout<<"Enter the rows of 1st matrix:";
      cin>>x1;
      cout<<"Enter the columns of 1st matrix:";
      cin>>y1;
      I1=L(x1,y1,"1st matrix");
      cout<<"Enter the rows of 2nd matrix:";
      cin>>x2;
      cout<<"Enter the columns of 2nd matrix:";
      cin>>y2;
      I2=L(x2, y2, "2nd matrix");
      if(y1==x2){ //  c of x = r of y
      O = multiply (I1,I2,x1,y1,y2);
     show(I1,x1,y1,"1st matrix");
      show(I2,x2,y2,"2nd matrix");
      show(O,x1,y2,"Output matrix");
      U(I1, x1);
       U(I2, x2);
        U(O, x1);
      }
      else{
          cout<<"\nMultiplication can't be done of given dimension of matrix";
          U(I1,x1);
          U(I2,x2);
      }
         break;
case 4:
    cout<<"Enter rows of matrix:";
    cin>>x1;
    cout<<"ENter the columns of matrix:";
    cin>>y1;
    I1=L(x1, y1, "Matrix");
    I2= transpose(I1,x1,y1);
    show(I1,x1,y1,"Input matrix");
     show(I2,y1,x1,"Output matrix");
     U(I1, x1);
    U(I2,y1);
     break;

  default:
  cout<<"\n Choose the right serial number:";
    
  }
  getch();
 }while(1);
}
