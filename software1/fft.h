#ifndef FFT_H
#define FFT_H FFT_HH

#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
#include <math.h>  
//mac娑撳┍_PI閸︹暕ath.h娑擃厽婀佺�蹇撶暰娑斿绱濋幍锟戒簰鏉╂瑩鍣烽幋鎴滄粦闁瀚ㄧ悰宀�畱鐎瑰繐鐣炬稊锟�
#ifndef M_PI  
#define M_PI 3.14159265358979323846  
#endif  

struct Complex_{  
    float real;
    float imagin;
};  

typedef struct Complex_ Complex;  
void FFT(float * src,Complex * dst,int size_n);
#endif
