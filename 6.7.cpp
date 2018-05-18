#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

class complexNumber
{
    private:
        double real;
        double imaginary;

    public:
        complexNumber(double _realPart = 0,double _imaginaryPart = 0):real(_realPart),imaginary(_imaginaryPart)
        {}
        
        double getReal()
        {
            return real;
        }

        double getImaginary()
        {
            return imaginary;
        }

        string toString()
        {
            //To-Do 1
        }

        complexNumber add(complexNumber cn)
        {
            double tmpReal = real + cn.real;
            double tmpImaginary = imaginary + cn.imaginary;
            complexNumber tmpCN(tmpReal,tmpImaginary);
            return tmpCN;
        }

        complexNumber sub(complexNumber cn)
        {
            double tmpReal = real - cn.real;
            double tmpImaginary = imaginary - cn.imaginary;
            complexNumber tmpCN(tmpReal,tmpImaginary);
            return tmpCN;
        }

        complexNumber mul(complexNumber cn)
        {
            double tmpReal = real * cn.real - imaginary * cn.imaginary;
            double tmpImaginary = cn.real * imaginary + real * cn.imaginary;
            complexNumber tmpCN(tmpReal,tmpImaginary);
            return tmpCN;
        }

        complexNumber div(complexNumber cn)
        {
            double down =  cn.real * cn.real + cn.imaginary * cn.imaginary ;
            double tmpReal = ( real * cn.real + imaginary * cn.imaginary ) / down;
            double tmpImaginary = ( imaginary * cn.real - real * cn.imaginary ) / down;
            complexNumber tmpCN(tmpReal,tmpImaginary);
            return tmpCN;
        }
};

int main()
{
    complexNumber cn1(3,6);
    complexNumber cn2(5,4);

    cout << cn1.getReal() << endl;
    cout << cn2.getImaginary() << endl;

    //To-Do 2

    return 0;
}