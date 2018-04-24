//  
//  main.c  
//  Fourer1D  
//  
//  Created by Tony on 14/11/16.  
//  Copyright (c) 2017濡ょ姷鍎戦幏绌�hao Wang. All rights reserved.
//  
#include "fft.h"
#include "log.h"
  
////////////////////////////////////////////////////////////////////  
//闁诲氦顬冮惌顔剧不閻斿摜鈻旈柨鐔剁矙閸ゅ顭跨捄铏剐ｉ柡鍡欏枔缁辨帡骞樼�闈╂嫹婵炶揪缍囬幏锟�///////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////  
//闁诲氦顬冮惌顔剧不閻斿摜鈻旈柨鐔剁矙閸ゅ顭跨捄铏剐ｉ柡鍡欏枔閹峰鏁嶉崟顓熸瘓闂佹寧绋戦懟顖滐拷濮楋拷绠い鎴ｆ硶椤旀帗绻涙径瀣┛缂佽鲸绻堝畷婵嬫偐瀹曞洢锟介梺鎸庣☉閼活垶宕抽崫鍕ㄦ灃闁跨噦鎷�///////////////////////////////////////////////////////////////////
void Add_Complex(Complex * src1,Complex *src2,Complex *dst){  
    dst->imagin=src1->imagin+src2->imagin;  
    dst->real=src1->real+src2->real;  
}  
void Sub_Complex(Complex * src1,Complex *src2,Complex *dst){  
    dst->imagin=src1->imagin-src2->imagin;  
    dst->real=src1->real-src2->real;  
}  
void Multy_Complex(Complex * src1,Complex *src2,Complex *dst){  
    float r1=0.0,r2=0.0;
    float i1=0.0,i2=0.0;
    r1=src1->real;  
    r2=src2->real;  
    i1=src1->imagin;  
    i2=src2->imagin;  
    dst->imagin=r1*i2+r2*i1;  
    dst->real=r1*r2-i1*i2;  
}  
////////////////////////////////////////////////////////////////////  
//闂侀潻鑵归敓绱絋婵炴垶鎼╅崢钘夛耿娴ｅ湱鈻旈柨鐔剁矙閸ゅ獊N闂佹眹鍔岄崺鏍ㄧ箾閸″繐澧查柡宀�枑閵囧嫰鎯傞崫銉ь樅闂侀潻璐熼崝蹇涘礄椤栨稓顪栭柨婵嗗閸橆剙霉閸忚偐鐓紒妤�檨瀵剟顢橀悩铏闂佸憡甯掓惔婊呮濠靛绀傞柧姘�缁夊ジ鎮峰▎搴ゅ厡闁伙綀顕ч埢鏃堝即閳藉棗娈梺鍝勫閹凤拷
///////////////////////////////////////////////////////////////////
void getWN(float n,float size_n,Complex * dst){
    float x=2.0*M_PI*n/size_n;
    dst->imagin=-sin(x);  
    dst->real=cos(x);  
}  

////////////////////////////////////////////////////////////////////  
//闁诲氦顬冮惌顔剧不閻戭枠T闂佹眹鍔岀�顒勫垂閸偅鍙忛悗锝庝簻椤曆囨煛娴ｅ搫顣肩�鎾茬窔閺佸秶浠﹂懞銉ь樄婵炴垶鎸鹃惁婵琓闂佹眹鍔岀�顓㈠汲閻旂厧绠叉い鏂垮⒔閻ュ懘寮堕埡浣瑰枠闁革絾鎮傚顒勬偋閸啘渚�倶韫囨挸顏电紒杈ㄧ箞閺屽懘骞掗幋鐘敌ㄧ紓鍌欑劍閹稿鎮楅敓锟�//////////////////////////////////////////////////////////////////
int FFT_remap(float * src,int size_n)
{
	int i;
    float temp[32] = {0};
    if(size_n == 1)
    {
        return 0;
    }
    for(i = 0; i < size_n; i++)
    {
        if(i % 2 == 0)
        {
            temp[i / 2] = src[i];
        }
        else  
        {
            temp[(size_n + i) / 2] = src[i];
        }
    }
    for(i = 0; i < size_n; i++)
    {
        src[i] = temp[i];
    }
    FFT_remap(src, size_n/2);  
    FFT_remap(src+size_n/2, size_n/2);  
    return 1;  
}  

////////////////////////////////////////////////////////////////////  
//闁诲氦顬冮惌顔剧不閻戭枠T闂佹寧绋戦懟顖炲矗閹稿孩濯撮柟鎹愵嚃閻庮偆绱掗悩鎰佹缁绢厼澧庨幏鐘碉拷濡椿鐎介梺鎸庣☉閺堫剟寮悙鐑樼厒濠电姴鍟粩鎾煟閵娿儱顏俊顖氼樈缁牆煤椤忓嫬濮ら梺鍛婂笒濡梻鎷归悢鐓庢瀬闁绘鐗嗙粊锕傛煛閸曨偄鈷旈柕鍥ㄥ哺閺佸秶浠﹂挊澶庮唹婵炲濮伴崕鎾�娴ｇ尨鎷烽柣鏃囨濞夈垽鏌＄�鑸靛
///////////////////////////////////////////////////////////////////  
void FFT(float * src, Complex * dst, int size_n)
{
	int i,j;
	int k=size_n;
	int z=0;
    FFT_remap(src, size_n); 

    while (k/=2)
    {
        z++;  
    }  
    k=z;  
    if(size_n!=(1<<k))
    {
        exit(0);  
    }
    Complex src_com[32];
    if(src_com==NULL)  
    {
        exit(0);
    }
    for(i=0;i<size_n;i++)
    {
        src_com[i].real=src[i];  
        src_com[i].imagin=0;  
    }
    for(i=0;i<k;i++)
    {
        z=0;  
        for(j=0;j<size_n;j++)
        {
            if((j/(1<<i))%2==1)
            {
                Complex wn;  
                getWN(z, size_n, &wn);  
                Multy_Complex(&src_com[j], &wn,&src_com[j]);  
                z+=1<<(k-i-1);  
                Complex temp;  
                int neighbour=j-(1<<(i));  
                temp.real=src_com[neighbour].real;  
                temp.imagin=src_com[neighbour].imagin;  
                Add_Complex(&temp, &src_com[j], &src_com[neighbour]);  
                Sub_Complex(&temp, &src_com[j], &src_com[j]);  
            }  
            else  
            {
                z=0;
            }
        }  
      
    }
      
//   for(i=0;i<size_n;i++)
//   {
//        if(src_com[i].imagin>=0.0){
//            printf("%d+%dj\n",(int)(src_com[i].real * 1000000),(int)(src_com[i].imagin * 1000000));
//        }
//        else
//            printf("%d%dj\n",(int)(src_com[i].real * 1000000),(int)(src_com[i].imagin * 1000000));
//   }
//    LOG_DEBUG("fft result:");
    for(i=0 ; i < size_n; i++)
    {
        dst[i].imagin = src_com[i].imagin;
        dst[i].real = src_com[i].real;
//        printf("%d + %d i\r\n", dst[i].real, dst[i].imagin);
    }
}
