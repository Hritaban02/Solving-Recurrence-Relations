#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    int a;
    int b;
    int c;
    int d;
}splnum;
splnum addspl(splnum, splnum);                  /* Returns u+v */
splnum subspl(splnum, splnum);                  /* Returns u-v */
splnum mulspl(splnum, splnum);                  /* Returns u*v */
splnum invspl(splnum);                          /* Returns 1/u provided that u is not zero */
splnum divspl(splnum, splnum);                  /* Returns u/v provided that v is not zero */
void prnspl(splnum);                            /* Print u as in the sample outputs */
void findroots(int,int,splnum*);                /*To compute the two roots of the characteristic equation and store them in the array roots*/
void solvehomogeneous(int,int,int,int);         /*To print the closed-form solution of the homogeneous recurrence*/
void solvenonhomogeneous(int,int,int,int,int);  /*To print the closed-form solution of the non-homogeneous recurrence*/
int GCD(int,int);                               /*To compute the greatest common divisor of two non-negative integers*/
int PerfectSquare(int);                         /*Returns whether a number is a Perfect Square or not*/

splnum addspl(splnum u, splnum v)
{
    if(u.d!=0 && v.d!=0 && u.d != v.d)          //Special numbers can be added only when the have the same irrational part
    {
        printf("\nCannot add these values!!!\n");
        exit(1);
    }
    else
    {
        int a,b,c,d,gcd;
        splnum result;
        if(u.d==0 && v.d==0)                    //Addition of two rational fractions
        {
            a=(u.a)*(v.c)+(u.c)*(v.a);
            b=0;
            c=(u.c)*(v.c);
            d=0;
            gcd=GCD(abs(a),abs(c));             //To enforce gcd(a,b,c)=1
            a=a/gcd;
            c=c/gcd;
        }
        else if(u.d==0 || v.d==0)               //Addition of one rational fraction and one quadratic irrational
        {
            if(u.d==0)                          //When u is the rational fraction
            {
                a=(u.a)*(v.c)+(u.c)*(v.a);
                b=(u.c)*(v.b);
                c=(u.c)*(v.c);
                d=v.d;
                gcd=GCD(abs(a),abs(b));         //To enforce gcd(a,b,c)=1
                gcd=GCD(gcd,abs(c));
                a=a/gcd;
                b=b/gcd;
                c=c/gcd;
            }
            else if(v.d==0)                     //When v is the rational fraction
            {
                a=(u.a)*(v.c)+(u.c)*(v.a);
                b=(v.c)*(u.b);
                c=(u.c)*(v.c);
                d=u.d;
                gcd=GCD(abs(a),abs(b));         //To enforce gcd(a,b,c)=1
                gcd=GCD(gcd,abs(c));
                a=a/gcd;
                b=b/gcd;
                c=c/gcd;
            }
        }
        else if(u.d!=0 && v.d!=0 && u.d==v.d)   //Addition of two quadratic irrationals
        {
            a=(u.a)*(v.c)+(u.c)*(v.a);
            b=(u.b)*(v.c)+(u.c)*(v.b);
            c=(u.c)*(v.c);
            d=u.d;
            gcd=GCD(abs(a),abs(b));             //To enforce gcd(a,b,c)=1
            gcd=GCD(gcd,abs(c));
            a=a/gcd;
            b=b/gcd;
            c=c/gcd;
        }
        if(c<0)                                 //Making the denominator positive
        {
            a=-a;
            b=-b;
            c=-c;
        }
        result.a=a;
        result.b=b;
        result.c=c;
        result.d=d;
        return(result);
    }
}
splnum subspl(splnum u, splnum v)
{
    if(u.d!=0 && v.d!=0 && u.d != v.d)          //Special numbers can be subtracted only when the have the same irrational part
    {
        printf("\nCannot subtract these values!!!\n");
        exit(2);
    }
    else
    {
        int a,b,c,d,gcd;
        splnum result;
        if(u.d==0 && v.d==0)                    //Subtraction of two rational fractions
        {
            a=(u.a)*(v.c)-(u.c)*(v.a);
            b=0;
            c=(u.c)*(v.c);
            d=0;
            gcd=GCD(abs(a),abs(c));             //To enforce gcd(a,b,c)=1
            a=a/gcd;
            c=c/gcd;
        }
        else if(u.d==0 || v.d==0)               //Subtraction of one rational fraction and one quadratic irrational
        {
            if(u.d==0)                          //When u is the rational fraction
            {
                a=(u.a)*(v.c)-(u.c)*(v.a);
                b=-(u.c)*(v.b);
                c=(u.c)*(v.c);
                d=v.d;
                gcd=GCD(abs(a),abs(b));         //To enforce gcd(a,b,c)=1
                gcd=GCD(gcd,abs(c));
                a=a/gcd;
                b=b/gcd;
                c=c/gcd;
            }
            else if(v.d==0)                     //When v is the rational fraction
            {
                a=(u.a)*(v.c)-(u.c)*(v.a);
                b=(v.c)*(u.b);
                c=(u.c)*(v.c);
                d=u.d;
                gcd=GCD(abs(a),abs(b));         //To enforce gcd(a,b,c)=1
                gcd=GCD(gcd,abs(c));
                a=a/gcd;
                b=b/gcd;
                c=c/gcd;
            }
        }
        else if(u.d!=0 && v.d!=0 && u.d==v.d)   //Addition of two quadratic irrationals
        {
            a=(u.a)*(v.c)-(u.c)*(v.a);
            b=(u.b)*(v.c)-(u.c)*(v.b);
            c=(u.c)*(v.c);
            d=u.d;
            gcd=GCD(abs(a),abs(b));             //To enforce gcd(a,b,c)=1
            gcd=GCD(gcd,abs(c));
            a=a/gcd;
            b=b/gcd;
            c=c/gcd;
        }
        if(c<0)                                 //Making the denominator positive
        {
            a=-a;
            b=-b;
            c=-c;
        }
        result.a=a;
        result.b=b;
        result.c=c;
        result.d=d;
        return(result);
    }
}
splnum mulspl(splnum u, splnum v)
{
    if(u.d!=0 && v.d!=0 && u.d != v.d)          //Special numbers can be multiplied only when the have the same irrational part
    {
        printf("\nCannot multiply these values!!!\n");
        exit(3);
    }
    else
    {
        int a,b,c,d,gcd;
        splnum result;
        if(u.d==0 && v.d==0)                    //Multiplication of two rational fractions
        {
            a=(u.a)*(v.a);
            b=0;
            c=(u.c)*(v.c);
            d=0;
            gcd=GCD(abs(a),abs(c));             //To enforce gcd(a,b,c)=1
            a=a/gcd;
            c=c/gcd;
        }
        else if(u.d==0 || v.d==0)               //Multiplication of one rational fraction and one quadratic irrational
        {
            if(u.d==0)                          //When u is the rational fraction
            {
                a=(u.a)*(v.a);
                b=(u.a)*(v.b);
                c=(u.c)*(v.c);
                d=v.d;
                gcd=GCD(abs(a),abs(b));         //To enforce gcd(a,b,c)=1
                gcd=GCD(gcd,abs(c));
                a=a/gcd;
                b=b/gcd;
                c=c/gcd;
            }
            else if(v.d==0)                     //When v is the rational fraction
            {
                a=(v.a)*(u.a);
                b=(v.a)*(u.b);
                c=(v.c)*(u.c);
                d=u.d;
                gcd=GCD(abs(a),abs(b));         //To enforce gcd(a,b,c)=1
                gcd=GCD(gcd,abs(c));
                a=a/gcd;
                b=b/gcd;
                c=c/gcd;
            }
        }
        else if(u.d!=0 && v.d!=0 && u.d==v.d)   //Multiplication of two quadratic irrationals
        {
            a=(u.a)*(v.a) + (u.b)*(v.b)*(u.d);
            b=(u.a)*(v.b)+(u.b)*(v.a);
            c=(u.c)*(v.c);
            d=u.d;
            gcd=GCD(abs(a),abs(b));             //To enforce gcd(a,b,c)=1
            gcd=GCD(gcd,abs(c));
            a=a/gcd;
            b=b/gcd;
            c=c/gcd;
        }
        if(c<0)                                 //Making the denominator positive
        {
            a=-a;
            b=-b;
            c=-c;
        }
        result.a=a;
        result.b=b;
        result.c=c;
        result.d=d;
        return(result);
    }
}
splnum invspl(splnum u)
{
    int c=(int)pow(u.a,2)-((int)pow(u.b,2))*(u.d);  //Denominator of the inverted special number
    if(c==0)
    {
        printf("\nCannot invert this values!!!\n"); //Inversion cannot be done as the denominator of the inverted special number is zero
        exit(4);
    }
    else if(c!=0)                                   //Denominator of the inverted special number is non-zero
    {
        int a,b,d,gcd;
        splnum result;
        if(u.d==0)                                  //Inversion of a rational fraction
        {
            a=u.c;
            b=0;
            c=u.a;
            d=0;
        }
        else if(u.d!=0)                             //Inversion of a quadratic irrational
        {
            a=(u.a)*(u.c);
            b=-1*(u.b)*(u.c);
            d=u.d;
            gcd=GCD(abs(a),abs(b));                 //To enforce gcd(a,b,c)=1
            gcd=GCD(gcd,abs(c));
        }
        if(c<0)                                     //Making the denominator positive
        {
            a=-a;
            b=-b;
            c=-c;
        }
        result.a=a;
        result.b=b;
        result.c=c;
        result.d=d;
        return(result);
    }

}
splnum divspl(splnum u, splnum v)
{
    return(mulspl(u,invspl(v)));                //u/v is u*(1/v)
}
void prnspl(splnum u)
{
    if(u.d==0 || u.b==0)                        //To check whether the number is rational or not
    {
        if(u.c==1)                              //To check whether the number is integer or not
        {
            printf("%d",u.a);                   //Printing an integer
        }
        else
        {
            if(u.a<0)
            {
                printf("(%d) / %d",u.a,u.c);    //Printing a negative rational fraction
            }
            else
            {
                printf("%d / %d",u.a,u.c);      //Printing a positive rational fraction
            }
        }
    }
    else if(u.d!=0)                             //To check whether the number is irrational or not
    {
        if(u.a!=0)                              //To check whether the number has a rational part or not
        {
            if(abs(u.b)==1)                     //Check for b=1 or not to avoid unnecessary multiplication by 1 on the display
            {
                printf("(%d %c sqrt(%d)) / %d",u.a,((u.b)>0)?'+':'-',u.d,u.c);
            }
            else
            {
                printf("(%d %c %d sqrt(%d)) / %d",u.a,((u.b)>0)?'+':'-',abs(u.b),u.d,u.c);
            }
        }
        else
        {
            if(abs(u.b)==1)                     //Check for b=1 or not to avoid unnecessary multiplication by 1 on the display
            {
                printf("(%csqrt(%d)) / %d",((u.b)>0)?' ':'-',u.d,u.c);
            }
            else
            {
                printf("(%c%d sqrt(%d)) / %d",((u.b)>0)?' ':'-',abs(u.b),u.d,u.c);
            }
        }
    }
}
void findroots(int r,int s,splnum roots[2])
{
    int a,b,c,d,gcd;
    a=r;
    b=1;
    c=2;
    d=pow(r,2)+4*s;
    if(d>0 && !(PerfectSquare(d)))              //Discriminant is greater than zero but not a perfect square i.e Two distinct roots which are quadratic irrationals
    {
        if(abs(a)%2==0 && d%4==0)               //Removing a factor of 2 from the numerator and denominator
        {
            a=a/2;
            d=d/4;
            c=c/2;
        }
        roots[0].a=a;
        roots[0].b=1*b;
        roots[0].c=c;
        roots[0].d=d;
        roots[1].a=a;
        roots[1].b=-1*b;
        roots[1].c=c;
        roots[1].d=d;
    }
    else if(d>=0 && PerfectSquare(d))           //Discriminant is greater than or equal to zero and is a perfect square i.e. Roots which are rational fractions
    {
        roots[0].a=a+b*(int)(sqrt((double)d));  //Absorbing the contribution of b*sqrt(d) in a
        roots[1].a=a-b*(int)(sqrt((double)d));
        if(abs(roots[0].a)%2==0)                //To enforce gcd(a,b,c)=1
        {
            roots[0].a=(roots[0].a)/2;
            roots[0].c=c/2;
        }
        else
        {
            roots[0].c=c;
        }
        if(abs(roots[1].a)%2==0)                //To enforce gcd(a,b,c)=1
        {
            roots[1].a=(roots[1].a)/2;
            roots[1].c=c/2;
        }
        else
        {
            roots[1].c=c;
        }
        b=0;                                    //Eliminating the irrational part
        d=0;
        roots[0].b=1*b;
        roots[0].d=d;
        roots[1].b=-1*b;
        roots[1].d=d;
    }
    else if(d<0)                                //Discriminant is less than zero i.e. Roots which are complex conjugates of each other
    {
        roots[0].a=a;
        roots[0].b=1*b;
        roots[0].c=c;
        roots[0].d=d;
        roots[1].a=a;
        roots[1].b=-1*b;
        roots[1].c=c;
        roots[1].d=d;
    }
}
void solvehomogeneous(int r,int s,int a0,int a1)
{
    splnum* roots=(splnum*)malloc(sizeof(splnum)*2);
    findroots(r,s,roots);
    int D=(int)pow(r,2)+4*s;                    //Discriminant of the Characteristic Equation
    printf("\n\n+++Solving the homogeneous recurrence");
    printf("\n   Characteristic equation: x^2 + (%d)x + (%d) = 0",-1*r,-1*s);
    printf("\n   Root 1 = ");
    prnspl(roots[0]);
    printf("\n   Root 2 = ");
    prnspl(roots[1]);
    printf("\n   Homogeneous Solution :");
    splnum U,V;                                 //U and V are constants in the solution of the homogeneous recurrence
    splnum a00,a11;                             //a00 and a11 are special numbers which hold a0/1 and a1/1 respectively to handle operations on integers and special numbers
    a00.a=a0;
    a00.b=0;
    a00.c=1;
    a00.d=0;
    a11.a=a1;
    a11.b=0;
    a11.c=1;
    a11.d=0;
    if(D==0)                                    //Repeated Roots
    {
        U=subspl(mulspl(a11,invspl(roots[0])),a00); //Constants determination
        V=a00;
        printf("\n   [(");
        prnspl(U);
        printf(")n + (");
        prnspl(V);
        printf(")] [");
        prnspl(roots[0]);
        printf("]^n\n");
    }
    else                                        //Distinct Roots
    {
        U=divspl(subspl(a11,mulspl(a00,roots[1])),subspl(roots[0],roots[1]));   //Constants determination
        V=divspl(subspl(a11,mulspl(a00,roots[0])),subspl(roots[1],roots[0]));
        printf("\n   [");
        prnspl(U);
        printf("][");
        prnspl(roots[0]);
        printf("]^n + [");
        prnspl(V);
        printf("][");
        prnspl(roots[1]);
        printf("]^n\n");
    }
}
void solvenonhomogeneous(int r,int s,int t,int a0,int a1)
{
    splnum* roots=(splnum*)malloc(sizeof(splnum)*2);
    findroots(r,s,roots);
    int D=(int)pow(r,2)+4*s;                    //Discriminant of the Characteristic Equation
    printf("\n\n+++Solving the non homogeneous recurrence");
    printf("\n   Characteristic equation: x^2 + (%d)x + (%d) = 0",-1*r,-1*s);
    printf("\n   Root 1 = ");
    prnspl(roots[0]);
    printf("\n   Root 2 = ");
    prnspl(roots[1]);
    splnum k;                                   //To store the constant of the Particular Solution
    int a,b,c,d,gcd;
    splnum U,V;                                 //To store the constants of the homogeneous part of the solution
    splnum a00,a11;                             //a00 and a11 are special numbers which hold a0/1 and a1/1 respectively to handle operations on integers and special numbers
    a00.a=a0;
    a00.b=0;
    a00.c=1;
    a00.d=0;
    a11.a=a1;
    a11.b=0;
    a11.c=1;
    a11.d=0;
    splnum one={1,0,1,0};                       //To store 1 as a special number to handle operations on one and special numbers
    if(D==0 && roots[0].a!=1 && roots[1].a!=1)  //Roots are equal but different from 1
    {
        a=t;                                    //k=t/(1-r-s)
        b=0;
        c=1-r-s;
        d=0;
        gcd=GCD(abs(a),abs(c));                 //To enforce gcd(a,b,c)=1
        a=a/gcd;
        c=c/gcd;
        if(c<0)                                 //Making the denominator positive
        {
            a=-a;
            b=-b;
            c=-c;
        }
        k.a=a;
        k.b=b;
        k.c=c;
        k.d=d;
        U=subspl(mulspl(subspl(a11,k),invspl(roots[0])),subspl(a00,k)); //To determine the constants of the homogeneous part of the solution
        V=subspl(a00,k);
        printf("\n   Particular Solution : ");
        prnspl(k);
        printf("\n   Homogeneous Solution :");
        printf("\n   [(");
        prnspl(U);
        printf(")n + (");
        prnspl(V);
        printf(")] [");
        prnspl(roots[0]);
        printf("]^n\n");
    }
    else if(D==0 && (roots[0].a==1 && roots[0].c==1) && (roots[1].a==1 && roots[1].c==1))   //Roots are equal and are equal to 1 i.e 1 is a Root of Multiplicity Two
    {
        a=-t;                                   //k=(-t)/(r+4*s)
        b=0;
        c=r+4*s;
        d=0;
        gcd=GCD(abs(a),abs(c));                 //To enforce gcd(a,b,c)=1
        a=a/gcd;
        c=c/gcd;
        if(c<0)                                 //Making the denominator positive
        {
            a=-a;
            b=-b;
            c=-c;
        }
        k.a=a;
        k.b=b;
        k.c=c;
        k.d=d;
        U=subspl(mulspl(subspl(a11,k),invspl(roots[0])),a00);   //To determine the constants of the homogeneous part of the solution
        V=a00;
        printf("\n   Particular Solution : ");
        printf("[");
        prnspl(k);
        printf("]n^2");
        printf("\n   Homogeneous Solution :");
        printf("\n   [(");
        prnspl(U);
        printf(")n + (");
        prnspl(V);
        printf(")] [");
        prnspl(roots[0]);
        printf("]^n\n");
    }
    else if(D!=0 && !((roots[0].a==1 && roots[0].c==1 && roots[0].d==0)||(roots[1].a==1 && roots[1].c==1 && roots[1].d==0)))    //Roots are distinct and both are not equal to 1
    {
        a=t;                                //k=t/(1-r-s)
        b=0;
        c=1-r-s;
        d=0;
        gcd=GCD(abs(a),abs(c));             //To enforce gcd(a,b,c)=1
        a=a/gcd;
        c=c/gcd;
        if(c<0)                             //Making the denominator positive
        {
            a=-a;
            b=-b;
            c=-c;
        }
        k.a=a;
        k.b=b;
        k.c=c;
        k.d=d;
        U=divspl(addspl(subspl(a11,mulspl(a00,roots[1])),mulspl(k,subspl(roots[1],one))),subspl(roots[0],roots[1]));    //To determine the constants of the homogeneous part of the solution
        V=divspl(addspl(subspl(a11,mulspl(a00,roots[0])),mulspl(k,subspl(roots[0],one))),subspl(roots[1],roots[0]));
        printf("\n   Particular Solution : ");
        prnspl(k);
        printf("\n   Homogeneous Solution :");
        printf("\n   [");
        prnspl(U);
        printf("][");
        prnspl(roots[0]);
        printf("]^n + [");
        prnspl(V);
        printf("][");
        prnspl(roots[1]);
        printf("]^n\n");
    }
    else if(D!=0 && (roots[0].a==1 && roots[0].c==1 && roots[0].d==0)||(roots[1].a==1 && roots[1].c==1 && roots[1].d==0))   //Roots are distinct but one of them is equal to 1 i.e 1 is a Root of Multiplicity One
    {
        a=t;                                //k=t/(r+2*s)
        b=0;
        c=r+2*s;
        d=0;
        gcd=GCD(abs(a),abs(c));             //To enforce gcd(a,b,c)=1
        a=a/gcd;
        c=c/gcd;
        if(c<0)                             //Making the denominator positive
        {
            a=-a;
            b=-b;
            c=-c;
        }
        k.a=a;
        k.b=b;
        k.c=c;
        k.d=d;
        U=divspl(subspl(subspl(a11,mulspl(a00,roots[1])),k),subspl(roots[0],roots[1])); //To determine the constants of the homogeneous part of the solution
        V=divspl(subspl(subspl(a11,mulspl(a00,roots[0])),k),subspl(roots[1],roots[0]));
        printf("\n   Particular Solution : ");
        printf("[");
        prnspl(k);
        printf("]n");
        printf("\n   Homogeneous Solution :");
        printf("\n   [");
        prnspl(U);
        printf("][");
        prnspl(roots[0]);
        printf("]^n + [");
        prnspl(V);
        printf("][");
        prnspl(roots[1]);
        printf("]^n\n");
    }
}
//GCD routine
int GCD(int a, int b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;
    if (a == b)
        return a;
    if (a > b)
        return GCD(a-b, b);
    return GCD(a, b-a);
}
int PerfectSquare(int num)
{
    int i;
    float f;
    f=sqrt((double)num);
    i=f;
    if(i==f)
        return 1;
    else
        return 0;
}
// main routine
int main ()
{
    int r,s,t,a0,a1;                    //Taking user input
    printf("r=");
    scanf("%d",&r);
    printf("\ns=");
    scanf("%d",&s);
    printf("\nt=");
    scanf("%d",&t);
    printf("\na0=");
    scanf("%d",&a0);
    printf("\na1=");
    scanf("%d",&a1);
    solvehomogeneous(r,s,a0,a1);
    solvenonhomogeneous(r,s,t,a0,a1);
}
