#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class Sor{
   
float a[3],b[3],c[3],d[3],x[11],y[11],z[11];
float a_demo[3],b_demo[3],c_demo[3];
int n=0;
float w;
int precision;
public:

int  get_coefficient()
{
cout<<"Enter the coefficient(ex. ax+by+cz=d,like this enter a,b,c and d ):"<<endl;
for(int i=0;i<3;i++)
{cout<<"FOR "<<i+1<<" EQUATION :"<<endl;
 cin >>a[i];
 cin >>b[i];
 cin >>c[i];
 cin >>d[i];
}
cout<<"w=1 Gauss SidelMethod"<<endl;
cout<<"W>1 SOR   Method"<<endl;
cout<<"W<1 SUR   Method"<<endl;
cout<<"Enter the value of w :"<<endl;
cin >>w;
for(int i=0;i<3;i++)
{
    a_demo[i]=a[i];
    b_demo[i]=b[i];
    c_demo[i]=c[i];
    if(a_demo[i]<0){a_demo[i]=a_demo[i]*(-1);}
    if(b_demo[i]<0){b_demo[i]=b_demo[i]*(-1);}
    if(c_demo[i]<0){c_demo[i]=c_demo[i]*(-1);}


}
cout<<"Enter the precision :"<<endl;
cin >>precision;

return w;
}



void sor_sidel_condition()
{
if(a_demo[0]>b_demo[0]+c_demo[0]){n++;}
if(b_demo[1]>a_demo[1]+c_demo[1]){n++;}
if(c_demo[2]>a_demo[2]+b_demo[2]){n++;}
}

int  condition_result()
{
    if(n==3 && w>1)
        {
        cout<<"Condition of Sor-Method is Satisfied"<<endl;
        return 1;
        }
    else  if(n==3 && w==1)
       {
        cout<<"Condition of Gauss-Sidel-Method is Satisfied"<<endl;
        return 1;
        }
    else if(n==3 && w<1)
      {
        cout<<"Condition of SUR-Method is Satisfied"<<endl;
        return 1;
        }

    else
        {
        cout<<"Condition of Sor-Method is not Satisfied"<<endl;
        system("pause>0");
        return 0;
        }
}

void rewriting_in_terms_of_variables()
{    
    cout<<"Enter the value of Xo :"<<endl;
    cin >>x[0];
    cout<<"Enter the value of Yo :"<<endl;
    cin >>y[0];
    cout<<"Enter the value of Zo :"<<endl;
    cin >>z[0];

    for(int j=1;j<=10;j++)
    {   
        x[j]=(1-w)*x[j-1]  + w*((d[0]-b[0]*y[j-1]-c[0]*z[j-1])/a[0]);
        y[j]=(1-w)*y[j-1]  + w*((d[1]-a[1]*x[j]-c[1]*z[j-1])/b[1]);
        z[j]=(1-w)*z[j-1]  + w*((d[2]-a[2]*x[j]-b[2]*y[j])/c[2]);
    }
}
void show_result()
{
    for(int i=1;i<=10;i++)
    {   cout<<endl<<"TERM :"<<i<<endl;
        cout<<setw(15)<<setprecision(precision+1)<<x[i]<<setw(15)<<setprecision(precision+1)<< y[i]<<setw(15)<<setprecision(precision+1)<<z[i];
        cout<<endl;
    }

}

};


class Jacobi
{
float a[3],b[3],c[3],d[3],x[10],y[10],z[10];
float a_demo[3],b_demo[3],c_demo[3];

int n=0;
int precision;
public:

void get_coefficient()
{
cout<<"Enter the coefficient(ex. ax+by+cz=d,like this enter a,b,c and d ):"<<endl;
for(int i=0;i<3;i++)
{cout<<"FOR "<<i+1<<" EQUATION :"<<endl;
 cin >>a[i];
 cin >>b[i];
 cin >>c[i];
 cin >>d[i];
}
for(int i=0;i<3;i++)
{
    a_demo[i]=a[i];
    b_demo[i]=b[i];
    c_demo[i]=c[i];
    if(a_demo[i]<0){a_demo[i]=a_demo[i]*(-1);}
    if(b_demo[i]<0){b_demo[i]=b_demo[i]*(-1);}
    if(c_demo[i]<0){c_demo[i]=c_demo[i]*(-1);}


}
cout<<"Enter the precision :"<<endl;
cin >>precision;
}



void jacobi_condition()
{
if(a_demo[0]>b_demo[0]+c_demo[0]){n++;}
if(b_demo[1]>a_demo[1]+c_demo[1]){n++;}
if(c_demo[2]>a_demo[2]+b_demo[2]){n++;}
}
 int condition_result()
{
    if(n==3){
            cout<<"Condition of Gauss-Sidel-Method is Satisfied"<<endl;
            return 1;
             }
    else{
        cout<<"Condition of Gauss-Sidel-Method is not Satisfied"<<endl;
        system("pause>0");
        return 0;
        }
}

void rewriting_in_terms_of_variables()
{    
    cout<<"Enter the value of Xo :"<<endl;
    cin >>x[0];
    cout<<"Enter the value of Yo :"<<endl;
    cin >>y[0];
    cout<<"Enter the value of Zo :"<<endl;
    cin >>z[0];

    for(int j=1;j<=10;j++)
    {   
        x[j]=(d[0]-b[0]*y[j-1]-c[0]*z[j-1])/a[0];
        y[j]=(d[1]-a[1]*x[j-1]-c[1]*z[j-1])/b[1];
        z[j]=(d[2]-a[2]*x[j-1]-b[2]*y[j-1])/c[2];
    }
}
void show_result()
{
    for(int i=1;i<=10;i++)
    {  
       
        cout<<endl<<"TERM :"<<i<<endl;
        cout<<setw(15)<<setprecision(precision+1)<<x[i]<<setw(15)<<setprecision(precision+1)<< y[i]<<setw(15)<<setprecision(precision+1)<<z[i];
        cout<<endl;
    }

    

}



};

class Crout
{
    float A[4][4];
    float B[4];
    float L[4][4];
    float U[4][4];
    float Y[4];
    float X[4];
public:
Crout()
{
cout<<"Basic's of the Crout's Method"<<endl;
cout<<"          AX=B"<<endl;
cout<<"          A=LU"<<endl;
cout<<"Threfore, LUX=B"<<endl;
cout<<"Let us take UX=Y"<<endl;
cout<<"Y is some unknown matrix which is to be evaluated"<<endl;
cout<<"          LY=B"<<endl;


}
void input_in_A_and_B()
{
cout<<"Enter the value in A matrix :"<<endl;
for(int i=1;i<4;i++)
{
    for(int j=1;j<4;j++)
    {   
        cout<<"A["<<i<<"]"<<"["<<j<<"] :"<<endl;
        cin >>A[i][j];
    }
}

cout<<"Enter the value in B matrix :"<<endl;
for(int i=1;i<4;i++)
    {
    cout<<"B["<<i<<"]  :"<<endl;
    cin>>B[i];
    }
}
void  L_and_U()
{
    L[1][1]= A[1][1];
    L[2][1]= A[2][1];
    L[3][1]= A[3][1];
    L[1][2]=0; 
    L[1][3]=0;
    L[2][3]=0;

    U[1][1]=U[2][2]=U[3][3]=1;
    U[2][1]=U[3][1]=U[3][2]=0;
    U[1][2]=A[1][2]/L[1][1];
    U[1][3]=A[1][3]/L[1][1];
    
    L[2][2]=A[2][2]-L[2][1]*U[1][2];
    L[3][2]=A[3][2]-L[3][1]*U[1][2];

    U[2][3]=(A[2][3]-L[2][1]*U[1][3])/L[2][2];

    L[3][3]=A[3][3]-L[3][1]*U[1][3]-L[3][2]*U[2][3];

cout<<"L[3][[3] MATRIX :"<<endl;
for(int i=1;i<4;i++)
{
    for(int j=1;j<4;j++)
    {
        cout<<setw(7)<<L[i][j];
    }
    cout<<endl;
}
cout<<"U[3][[3] MATRIX :"<<endl;
for(int i=1;i<4;i++)
{
    for(int j=1;j<4;j++)
    {
        cout<<setw(12)<<U[i][j];
    }
    cout<<endl;
}
}

void finding_Y()
{
Y[1]=B[1]/L[1][1];
Y[2]=(B[2]-Y[1]*L[2][1])/L[2][2];
Y[3]=(B[3]-Y[1]*L[3][1]-Y[2]*L[3][2])/L[3][3];
cout<<"Y MATRIX :"<<endl;
for(int i=1;i<4;i++)
{
    cout<<Y[i];
    cout<<endl;
}
}


void finding_X()
{
    X[3]=Y[3]/U[3][3];
    X[2]=(Y[2]-U[2][3]*X[3])/U[2][2];
    X[1]=(Y[1]-U[1][2]*X[2]-U[1][3]*X[3])/U[1][1];
    cout<<"X MATIX :"<<endl;
    for(int i=1;i<4;i++)
    {
       cout<<"X["<<i<<"] ="<<X[i]<<endl;
    }
}

};

class LU
{
    float A[4][4];
    float B[4];
    float L[4][4];
    float U[4][4];
    float Y[4];
    float X[4];
public:
LU()
{
cout<<"Basic's of the LU Decomposition Method"<<endl;
cout<<"          AX=B"<<endl;
cout<<"          A=LU"<<endl;
cout<<"Threfore, LUX=B"<<endl;
cout<<"Let us take UX=Y"<<endl;
cout<<"Y is some unknown matrix which is to be evaluated"<<endl;
cout<<"          LY=B"<<endl;


}
void input_in_A_and_B()
{
cout<<"Enter the value in A matrix :"<<endl;
for(int i=1;i<4;i++)
{
    for(int j=1;j<4;j++)
    {   
        cout<<"A["<<i<<"]"<<"["<<j<<"] :"<<endl;
        cin >>A[i][j];
    }
}

cout<<"Enter the value in B matrix :"<<endl;
for(int i=1;i<4;i++)
    {
    cout<<"B["<<i<<"]  :"<<endl;
    cin>>B[i];
    }
}
void  L_and_U()
{
   L[1][1]=L[2][2]=L[3][3]=1;
   L[1][2]=L[1][3]=L[2][3]=0;
   U[2][1]=U[3][1]=U[3][2]=0;
   
   U[1][1]=A[1][1];
   U[1][2]=A[1][2];
   U[1][3]=A[1][3];

   L[2][1]=A[2][1]/U[1][1];
   L[3][1]=A[3][1]/U[1][1];

   U[2][2]=A[2][2]-L[2][1]*U[1][2];
   U[2][3]=A[2][3]-L[2][1]*U[1][3];

   L[3][2]=(A[3][2]-L[3][1]*U[1][2])/U[2][2];
   U[3][3]=A[3][3]-L[3][1]*U[1][3]-L[3][2]*U[2][3];





cout<<"L[3][[3] MATRIX :"<<endl;
for(int i=1;i<4;i++)
{
    for(int j=1;j<4;j++)
    {
        cout<<setw(7)<<L[i][j];
    }
    cout<<endl;
}
cout<<"U[3][[3] MATRIX :"<<endl;
for(int i=1;i<4;i++)
{
    for(int j=1;j<4;j++)
    {
        cout<<setw(12)<<U[i][j];
    }
    cout<<endl;
}
}

void finding_Y()
{
Y[1]=B[1]/L[1][1];
Y[2]=(B[2]-Y[1]*L[2][1])/L[2][2];
Y[3]=(B[3]-Y[1]*L[3][1]-Y[2]*L[3][2])/L[3][3];
cout<<"Y MATRIX :"<<endl;
for(int i=1;i<4;i++)
{
    cout<<Y[i];
    cout<<endl;
}
}


void finding_X()
{
    X[3]=Y[3]/U[3][3];
    X[2]=(Y[2]-U[2][3]*X[3])/U[2][2];
    X[1]=(Y[1]-U[1][2]*X[2]-U[1][3]*X[3])/U[1][1];
    cout<<"X MATIX :"<<endl;
    for(int i=1;i<4;i++)
    {
       cout<<"X["<<i<<"] ="<<X[i]<<endl;
    }
}

};

class Cholesky
{
    float A[4][4];
    float B[4];
    float L[4][4];
    float LT[4][4];
    float Y[4];
    float X[4];
public:
Cholesky()
{
cout<<"Basic's of the Cholesky Method"<<endl;
cout<<"          AX=B"<<endl;
cout<<"          A=L L^T"<<endl;
cout<<"Threfore, L L^T X=B"<<endl;
cout<<"Let us take LX=Y"<<endl;
cout<<"Y is some unknown matrix which is to be evaluated"<<endl;
cout<<"          L^TX=Y"<<endl;


}
void input_in_A_and_B()
{
cout<<"Enter the value in A matrix :"<<endl;
for(int i=1;i<4;i++)
{
    for(int j=1;j<4;j++)
    {   
        cout<<"A["<<i<<"]"<<"["<<j<<"] :"<<endl;
        cin >>A[i][j];
    }
}

cout<<"Enter the value in B matrix :"<<endl;
for(int i=1;i<4;i++)
    {
    cout<<"B["<<i<<"]  :"<<endl;
    cin>>B[i];
    }
}
void  L_and_LT()
{
   L[1][1]=sqrt(A[1][1]);
   L[2][1]=A[2][1]/L[1][1];
   L[3][1]=A[3][1]/L[1][1];
   L[2][2]=sqrt(A[2][2]-pow(L[2][1],2));
   L[3][2]=(A[3][2]-L[3][1]*L[2][1])/L[2][2];
   L[3][3]=sqrt(A[3][3]-pow(L[3][2],2)-pow(L[3][1],2));
   L[1][2]=L[1][3]=L[2][3]=0;

   for(int i=1;i<4;i++)
   {
    for(int j=1;j<4;j++)
    {
        LT[i][j]=L[j][i];
    }
   }

cout<<"L[3][[3] MATRIX :"<<endl;
for(int i=1;i<4;i++)
{
    for(int j=1;j<4;j++)
    {
        cout<<setw(7)<<L[i][j];
    }
    cout<<endl;
}
cout<<"L^T[3][[3] MATRIX :"<<endl;
for(int i=1;i<4;i++)
{
    for(int j=1;j<4;j++)
    {
        cout<<setw(12)<<LT[i][j];
    }
    cout<<endl;
}
}

void finding_Y()
{
Y[1]=B[1]/L[1][1];
Y[2]=(B[2]-Y[1]*L[2][1])/L[2][2];
Y[3]=(B[3]-Y[1]*L[3][1]-Y[2]*L[3][2])/L[3][3];
cout<<"Y MATRIX :"<<endl;
for(int i=1;i<4;i++)
{
    cout<<Y[i];
    cout<<endl;
}
}


void finding_X()
{
    X[3]=Y[3]/LT[3][3];
    X[2]=(Y[2]-LT[2][3]*X[3])/LT[2][2];
    X[1]=(Y[1]-LT[1][2]*X[2]-LT[1][3]*X[3])/LT[1][1];
    cout<<"X MATIX :"<<endl;
    for(int i=1;i<4;i++)
    {
       cout<<"X["<<i<<"] ="<<X[i]<<endl;
    }
}

};


int main()
{   
    int choice;
    int condition_result;
cout<<"@@@@@@@@@  Menu  @@@@@@@@@"<<endl;
cout<<" Enter 1]Gauss-Jacobi-Method"<<endl;
cout<<" Enter 2]Gauss-Sidel_and_SOR-Method"<<endl;
cout<<" Enter 3]Crout's     -Method"<<endl;
cout<<" Enter 4]LU Decompositin Method"<<endl;
cout<<" Enter 5]Cholesky    -Method"<<endl;
cin >>choice;
cout<<"!!!  Attention Enter Value According to Sequence Rule !!!"<<endl;
if(choice==1)
{
Jacobi obj1;
obj1.get_coefficient();
obj1.jacobi_condition();
condition_result = obj1.condition_result();
if(condition_result==1)
   {
   obj1.rewriting_in_terms_of_variables();
   obj1.show_result();
   }
}

else if(choice==2)
{
int w;
cout<<"Enter the value according to the max diagoanl rule,unless you will face error !"<<endl;
Sor obj1;
w=obj1.get_coefficient();

if(w>0 && w<=2)
{
obj1.sor_sidel_condition();
int condition_result=obj1.condition_result();

  if(condition_result==1)
   {
    obj1.rewriting_in_terms_of_variables();
    obj1.show_result();
   }
}
else{
    cout<<"Wrong value of w is entered!!!!!!!!!"<<endl;
    cout<<"w must be between 0 to 2"<<endl;
    }
}

else if (choice==3)
{
Crout c;
c.input_in_A_and_B();
c.L_and_U();
c.finding_Y();
c.finding_X();
}

else if(choice==4)
{
 LU c;
c.input_in_A_and_B();
c.L_and_U();
c.finding_Y();
c.finding_X();
   
}
else if(choice==5)
{

Cholesky c;
c.input_in_A_and_B();
c.L_and_LT();
c.finding_Y();
c.finding_X();

}
else
{
    cout<<"Wrong Choice!!!!"<<endl;
}
string bye;
cout<<"Bye Bye!"<<endl;
cin >>bye;
}
