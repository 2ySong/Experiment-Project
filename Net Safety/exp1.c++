#include <stdio.h>
#include<math.h>

#define MAXLENGTH(1024)     //最大位数1024*8
#define P0                  //为正数
#define N1                  //为负数
#define UPPERBOUND100000000 //进制
class BigInt
{
private:
    bool m_bSign;                     //符号位
    unsigned int m_nLength;           //数组长度
    unsigned int m_nValue[MAXLENGTH]; //存储UPPERBOUND进制的每一位的值
public:
    BigInt();
    BigInt(char *str);
    BigInt(unsigned long Num);

    void Zero();                 //将大数置零
    void Set(unsigned long Num); //把大数设置成Num
    void Set(BigInt);
    //字符串与大数的转换
    bool GetBigInt(char *str); //将字符串str转换为大数
    void PutBigInt(char *str); //将大数转换为字符串
    //加减乘除幂
    int Mod(_int64); //求模运算，参数为64位无符号整型
    BigIntAdd(BigInt);
    BigIntSub(BigInt);
    BigIntMul(BigInt);
    BigIntDiv(unsigned int, unsigned int *M = NULL); //除法运算，M为余数
    bool Comp(BigInt);                                //比较两个大数，大于等于为正，小于为负
    BigIntPower(BigInt);                             //求幂运算，但由于位数的限制，指数实际上不可以很大

    //会改变数据成员的值
    voidAdd(unsigned int);
    BigIntMul(_int64);
    BigIntSub(unsigned int);
    boolEqulZero(); //判断是否等于零
};
//-------------------------构造函数-----------------------------------
BigInt::BigInt()
{
    this->Zero();
}
BigInt::BigInt(char *str)
{
    this->GetBigInt(str);
}
BigInt::BigInt(unsigned long Num)
{
    this->Set(Num);
}

//-------------------------设置成员变量的函数----------------------------
void BigInt::Zero()
{
    this->m_bSign = P;
    this->m_nLength = 1;
    for (int i = 0; i < MAXLENGTH; i++)
        this->m_nValue[i] = 0;
}
void BigInt::Set(unsigned long Num)
{
    this->m_bSign = P;
    this->m_nLength = 1;
    this->m_nValue[0] = Num;
}
void BigInt::Set(BigInt A)
{
    this->m_bSign = A.m_bSign;
    this->m_nLength = A.m_nLength;
    for (int i = 0; i < A.m_nLength; i++)
        this->m_nValue[i] = A.m_nValue[i];
}
bool BigInt::EqulZero()
{
    if ((this->m_nLength == 1) && (this->m_nValue[0] == 0))
        return true;
    return false;
}

//将字符串str转换为大数
bool BigInt::GetBigInt(char *str)
{
    int i = 0;
    int length = 0; //记录字符串的长度
    for (i = 0; str[i] != '/0'; i++)
        length++;
    this->Zero();
    //字符串为空
    if (length == 0)
        return true;

    if (str[0] == '-') //开头为负号
    {
        this->m_bSign = N;
        i = 1;
    }
    else
    {

        i = 0;
        this->m_bSign = P;
    }
    //去掉开头多余的零
    while ((str[i] == '0') && (i < length))
        i++;
    if (i == length) //如果都是零
    {
        this->Set(0);
        return true;
    }
    //确定大数的长度，数组的每个元素可以表示8位的整数
    if (length % 8 == 0)
        this->m_nLength = length / 8;
    else
        this->m_nLength = length / 8 + 1;

    for (; i < length; i++) //从第一个非零值开始转换
    {
        Set(Mul(10));
        if ((str[i] >= '0') && (str[i] <= '9'))
            Add(str[i] - '0');
        else
        {
            cerr << "不识别符号！" << endl;
            this->m_nLength = 1;
            this->m_nValue[0] = 0;
            return false;
        }
    }
    return true;
}
//将大数转换为字符串
void BigInt::PutBigInt(char *str)
{
    if (this->EqulZero())
    {
        str[0] = '0';
        str[1] = '/0';
        return;
    }
    int k = 0;
    _int64 km = 0;
    char *temp = new char[this->m_nLength * 8];
    for (int i = 0; i < this->m_nLength; i++)
    {
        km = this->m_nValue[i];
        for (int j = 0; j < 8; j++) //除十求余转换，直到被除数为零（可以除十转换是因为设置成了100000000进制）
        {
            if (this->m_nValue[i] != 0)
            {
                temp[k] = km % 10 + '0';
                k++;
                if ((km = km / 10) == 0)
                    break;
            }
            else
            {
                temp[k] = '0';
                k++;
            }
        }
    }

    //将temp中倒序储存的字符逆序放入str中
    if (this->m_bSign == N)
    {
        str[0] = '-';
        for (i = 1; k - i >= 0; i++)
            str[i] = temp[k - i];
    }
    else
    {
        for (i = 0; k - i >= 0; i++)
            str[i] = temp[k - 1 - i];
    }
    str[i] = '/0';
}