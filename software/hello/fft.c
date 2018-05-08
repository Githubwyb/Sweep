//  
//  main.c  
//  Fourer1D  
//  
//  Created by Tony on 14/11/16.  
//  Copyright (c) 2017婵°倗濮烽崕鎴﹀箯缁岋拷hao Wang. All rights reserved.
//  
#include "fft.h"
#include "log.h"
  
////////////////////////////////////////////////////////////////////  
//闂佽姘﹂‖鍐儗椤斿墽涓嶉柣鏂挎憸閳绘棃鏌ㄩ悢鍓佺煓闁搞倕顑呴…璺ㄦ崉閾忓墣锝夋煛閸℃瑥鏋旂紒杈ㄥ浮楠炴锟介棃鈺傚濠电偠鎻紞鍥箯閿燂拷///////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////  
//闂佽姘﹂‖鍐儗椤斿墽涓嶉柣鏂挎憸閳绘棃鏌ㄩ悢鍓佺煓闁搞倕顑呴…璺ㄦ崉閾忓墣锝夋煛閸℃瑥鏋旈柟宄邦儔閺佸秹宕熼鐔哥槗闂備焦瀵х粙鎴︽嚐椤栨粣鎷锋慨妤嬫嫹缁狀垱銇勯幋锝嗙《妞ゆ梹甯楃换娑欏緞鐎ｎ偆鈹涚紓浣介哺缁诲牆鐣峰┑瀣亹鐎规洖娲㈤敓浠嬫⒑閹稿海鈽夐柤娲诲灦瀹曟娊宕崟銊︾亙闂佽法鍣﹂幏锟�///////////////////////////////////////////////////////////////////
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
//闂備線娼婚懙褰掓晸缁辩祴濠电偞鍨堕幖鈺呭储閽樺鑰垮ù锝呮贡閳绘棃鏌ㄩ悢鍓佺煓闁搞倕鐛奛闂備焦鐪归崝宀勫春閺嶃劎绠鹃柛鈥崇箰婢ф煡鏌″畝锟芥瀾闁靛洤瀚伴幆鍌炲传閵壯屾▍闂備線娼荤拹鐔煎礉韫囨稑绀勬い鏍ㄧ〒椤牠鏌ㄥ┑鍡楊伂闁告﹩鍓欓湁闁稿繗鍋愰悡顖滅磼濡わ拷妾ㄧ�殿噮鍓熼、姗�鎮╅搹顐ｎ吂闂備礁鎲＄敮鎺撴償濠婂懏顬忔繝闈涱儏缁�鍌炴煣濮橆剙锟界紒澶娿偢閹嘲鈻庢惔銈呭帯闂佷紮缍�椤曆囧煝閺冨牆鍗抽柍钘夋濞堫垶姊洪崫鍕伒闁瑰嚖鎷�
///////////////////////////////////////////////////////////////////
void getWN(float n,float size_n,Complex * dst){
    float x=2.0*M_PI*n/size_n;
    dst->imagin=-sin(x);  
    dst->real=cos(x);  
}  

////////////////////////////////////////////////////////////////////  
//闂佽姘﹂‖鍐儗椤斿墽涓嶉柣鎴灎T闂備焦鐪归崝宀�锟介鍕瀭闁割煈鍋呴崣蹇涙倵閿濆簼绨绘い鏇嗗洦鐓涘ù锝呮惈椤ｈ偐锟介幘鑼獢闁轰礁绉舵禒锕傛嚍閵壯屾▌濠电偞鍨堕幐楣冩儊濠电悡闂備焦鐪归崝宀�锟介銏犳辈闁绘梻鍘х粻鍙夈亜閺傚灝鈷旈柣銉ユ嚇瀵爼鍩℃担鐟版灎闂侀潻绲鹃幃鍌氼嚕椤掑嫭鍋嬮柛顐ゅ晿娓氾拷鍊堕煫鍥ㄦ尭椤忕數绱掓潏銊х疄闁哄苯鎳橀獮鎺楀箣閻樻晫銊х磽閸屾瑧鍔嶉柟绋款煼閹鏁撻敓锟�//////////////////////////////////////////////////////////////////
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
    LOG_DEBUG("OK");
    for(i = 0; i < size_n; i++)
    {
        src[i] = temp[i];
    }
    FFT_remap(src, size_n/2);
    FFT_remap(src+size_n/2, size_n/2);
    return 1;  
}  

////////////////////////////////////////////////////////////////////  
//闂佽姘﹂‖鍐儗椤斿墽涓嶉柣鎴灎T闂備焦瀵х粙鎴︽嚐椤栫偛鐭楅柟绋垮婵挳鏌熼幑鎰靛殐闁诲寒鍋嗙槐鎺楁偐閹颁焦顔堢紒缁㈠幖婢у酣骞忛悩纰夋嫹婵☆垱妞块悗浠嬫⒑閹稿海鈽夐柡鍫墴瀵偊鎮欓悜妯煎帓婵犵數濮撮崯顐ょ博閹绢喗鐓熼柕濞垮劚椤忣亝淇婇姘兼▓缂侇喖鐗嗙叅妞ゅ繐瀚慨銈夋⒑閸涘﹤绗掓俊顐ｆ⒒閹峰綊鎮㈤悡搴㈢�梺缁橆殰閻楀棛绮婇敃鍌涚厸闁告洦鍋勯埛鏃堟煏閸ャ劌鍝洪柡浣哥Ф娴狅箓鎸婃径搴敼濠电偛顕慨浼村磿閹绢喒锟藉ù锝囧皑閹风兘鏌ｉ弮鍥仩婵炲鍨介弻锛勶拷閼搁潧顏�
///////////////////////////////////////////////////////////////////  
void FFT(float * src, Complex * dst, int size_n)
{
	int i,j;
	int k=size_n;
	int z=0;
	LOG_DEBUG("OK");
    FFT_remap(src, size_n); 
    LOG_DEBUG("OK");
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
    LOG_DEBUG("OK");
    for(i=0;i<size_n;i++)
    {
        src_com[i].real=src[i];  
        src_com[i].imagin=0;  
    }
    LOG_DEBUG("OK");
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
    LOG_DEBUG("OK");
      
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
    LOG_DEBUG("OK");
}
