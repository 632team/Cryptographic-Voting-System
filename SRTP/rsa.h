#ifndef RSA_H
#define RSA_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#define __int64 long long

typedef struct  RSA_PARAM_Tag
{
    unsigned __int64 p, q;   //两个素数，不参与加密解密运算
    unsigned __int64 f;      //f=(p-1)*(q-1)，不参与加密解密运算
    unsigned __int64 n, e;   //公匙，n=p*q，gcd(e,f)=1
    unsigned __int64 d;      //私匙，e*d=1 (mod f)，gcd(n,d)=1
    unsigned __int64 s;      //块长，满足2^s<=n的最大的s，即log2(n)
} RSA_PARAM;//小素数表




class RSA
{
public:
    RSA();
public:
    constexpr static long g_PrimeTable[24]{
        3,
        5,
        7,
        11,
        13,
        17,
        19,
        23,
        29,
        31,
        37,
        41,
        43,
        47,
        53,
        59,
        61,
        67,
        71,
        73,
        79,
        83,
        89,
        97
    };
    const static long g_PrimeCount=sizeof(g_PrimeTable) /sizeof(long);
    const static unsigned __int64 multiplier=12747293821;
    const static unsigned __int64  adder=1343545677842234541;//随机数类
    class  RandNumber
    {
        /* */
    private:
        unsigned __int64    randSeed;/* */
    public:
        RandNumber(unsigned __int64 s=0);
        unsigned __int64   Random(unsigned __int64 n);
    };
    static RandNumber   g_Rnd;

    static unsigned __int64 MulMod(unsigned __int64 a, unsigned __int64 b, unsigned __int64 n);
    static unsigned __int64 PowMod(const unsigned __int64 &base, const unsigned __int64 &pow, const unsigned __int64 &n);
    static long RabinMillerKnl(unsigned __int64 &n);
    static long RabinMiller(unsigned __int64 &n,long loop);
    static unsigned __int64 RandomPrime(char bits);
    static unsigned long long EuclidGcd(unsigned long long &p, unsigned long long &q);
    static unsigned __int64 SteinGcd(unsigned __int64&p, unsigned __int64 &q);
    static unsigned __int64 Euclid(unsigned __int64 &a, unsigned __int64 &b);
    static RSA_PARAM RsaGetParam(void);
};

#endif // RSA_H
