/**
 * @Author: Song-zy
 * @Date: 2021/11/15 19:05
 * @Description: 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

char grammar[200][200];//存储产生式
char stack[200]={'\0'};//堆栈初值
int sp=0;//栈顶指针
int p1=0;//输入句型指针
int vtNum,vnNum,proNum;

/*变量定义*/
char terSymbol[200];//终结符号
char non_ter[200];//非终结符号
char firstSet[200][200];//各产生式右部的FIRST集
char followSet[200][200];//各产生式左部的FOLLOW集
int M[200][200];//分析表

//查找终结符位置
int ter(char ch)
{
    int i;
    for(i=0; i < vtNum; i++)
        if(terSymbol[i]==ch)
            break;
    return i;
}

//查找非终结符的位置
int non_t(char ch)
{
    int i;
    for(i=0; i < vnNum; i++)
        if(non_ter[i]==ch)
            break;
    return i;
}

//加入first集
int addFirstSet(char X, char c)
{
    int i,j,k,m;
    i=ter(c);
    if(i < vtNum)
    {
        j=non_t(X);
        firstSet[j][i]=1;
    }
    else{
        j=non_t(X);
        m=non_t(c);
        //产生式首部为非终结符时，将其follow集加入
        for(k=0; k <= vtNum; k++)
        {
            if(firstSet[m][k]==1)
                firstSet[j][k]=1;
        }
    }
    return 1;
}

bool haveEmpty(char c)//判断first集中是否包含空字符
{
    int i,j;
    i=ter(c);
    if(i < vtNum)
        return false;
    else{
        j=non_t(c);
        if(firstSet[j][vtNum] == 1)//first集中含空
            return true;
        else
            return false;
    }
}

int addFollowSet(char X, char c, int kind)//加入follow集，kind=0表示将follow加入，表示将first加入
{
    int i,j,k,m;
    i=ter(c);
    if(i < vtNum)//c是终结符
    {
        j=non_t(X);
        followSet[j][i]=1;
    }
    else{//c是非终结符
        if(kind==0){
            j=non_t(X);
            m=non_t(c);
            for(k=0; k <= vtNum; k++)
            {
                if(followSet[m][k]==1)
                    followSet[j][k]=1;
            }
        }
        else{

            j=non_t(X);
            m=non_t(c);
            for(k=0; k < vtNum; k++)
            {
                if(firstSet[m][k]==1)
                    followSet[j][k]=1;
            }
        }
    }
    return 1;
}


int first(char X)//求非终结符的first集
{
    int i,j,k,m,p,flag;
    for(i=0; i < proNum; i++)
    {
        if(grammar[i][0] == X)//找X所对应的产生式
        {
            p=3;
            if(grammar[i][p] == '$')//产生式右部为空
            {
                j=non_t(X);
                firstSet[j][vtNum]=1;
            }
            else{//产生式右部非空
                while(grammar[i][p] != '\0')
                {
                    int q=ter(grammar[i][p]);
                    //grammar[i][p]是终结符
                    if(q < vtNum){
                        addFirstSet(X, grammar[i][p]);
                        break;
                    }
                        //grammar[i][p]不是终结符
                    else if(q >= vtNum){
                        //找到其在非终结符中的位置
                        k=non_t(grammar[i][p]);
                        flag=0;
                        for(m=0; m<=vtNum; m++)
                        {
                            if(firstSet[k][m]==1)
                            {
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0)//	First集未被求过
                            first(grammar[i][p]);
                        addFirstSet(X, grammar[i][p]);
                        if(haveEmpty(grammar[i][p]))//首字符First集是否为空，是则继续，否则跳出while循环
                            p++;
                        else
                            break;
                    }
                }
            }
        }
    }
    return 1;
}

int follow(char X)//求非终结符的follow集
{
    int i,j,k,p,flag;
    char ch;
    followSet[0][vtNum]=1;//将#加入开始符的follow集
    for(i=0; i < proNum; i++)
    {
        p=3;
        while(grammar[i][p] != '\0' && grammar[i][p] != X)
            p++;
        if(grammar[i][p] == X)
        {
            ch=grammar[i][p++];
            if(grammar[i][p] == '\0')//X是右部的最后一个字符
            {
                j=non_t(grammar[i][0]);
                flag=0;
                for(k=0; k <= vtNum; k++)
                {
                    if(followSet[j][k]==1)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0 && grammar[i][0] != X)//follow集未被求过或者是左部字符不为X
                    follow(grammar[i][0]);
                addFollowSet(X, grammar[i][0], 0);
            }
            else{//X不是右部最后一个字符
                while(haveEmpty(grammar[i][p]) && grammar[i][p] != '\0')
                {
                    addFollowSet(X, grammar[i][p], 1);

                    /*if(grammar[i][p]=='\0')
                    {*/
                    j=non_t(grammar[i][0]);
                    flag=0;
                    for(k=0; k <= vtNum; k++)
                    {
                        if(followSet[j][k]==1)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0 && grammar[i][0] != X)//未求follow集或者不为X
                        follow(grammar[i][0]);
                    addFollowSet(X, grammar[i][0], 0);
                    p++;
                }
                if(!haveEmpty(grammar[i][p]))
                    addFollowSet(X, grammar[i][p], 1);
            }
        }
    }
    return 1;
}

//初始化分析表
int initAnalysis()
{
    int i,j;
    for(i=0; i < vnNum; i++)
        for(j=0; j <= vtNum; j++)
        {
            M[i][j]=-1;
        }
    return 1;
}

//构造预测分析表
int analysis()
{
    int i,j,k,m,n,x;
    for(x=0; x < proNum; x++)
    {
        i=non_t(grammar[x][0]);
        m=ter(grammar[x][3]);
        if(grammar[x][3] != '$')
        {
            for(j=0; j < vtNum; j++)//对每个终结符a属于firstSet(grammar[x][0]),把文法grammar[x]加入到M[x][a]
            {
                if(firstSet[i][j]==1)
                {
                    if(m < vtNum)
                    {
                        if(M[i][j]==-1 && grammar[x][3] == terSymbol[j])
                            M[i][j]=x;
                    }
                    else{
                        n=non_t(grammar[x][3]);
                        if(M[i][j]==-1&&firstSet[n][j]==1)
                            M[i][j]=x;
                    }
                }
            }
        }
        if(haveEmpty(grammar[x][0]))//若$属于firstSet(grammar[x][0]),对任何b属于followSet(grammar[x][0])把grammer[x]加入到M[X][b]
        {
            for(k=0; k <= vtNum; k++)
            {
                if(followSet[i][k]==1)
                    M[i][k]=x;
            }
        }
    }
    return 1;
}

int control()//总控程序
{
    int i,j,k,m,n,x,y,flag=0;
    char c1[20]={'\0'};
    char c2;//c1存放待分析字符串的当前字符,c2存放已弹出的栈顶元素
    stack[sp++]='#';
    stack[sp++]=non_ter[0];
    printf("\n请输入要分析的句型(以#结尾):");
    i=0;
    char c=getchar();

    while(c!='#')
    {
        c1[i++]=c;
        c=getchar();
    }
    c1[i]='#';
    printf("\n分析过程:\n\n分析栈              输入串              所用规则                ");

    while(c1[p1]!='\0')
    {
        printf("\n");
        for(i=0;stack[i]!='\0';i++)
            printf("%c",stack[i]);
        for(k=0;k<20-i;k++)
            printf(" ");//输出栈内情况

        m=0;
        for(i=p1;c1[i]!='\0';i++)
        {
            printf("%c",c1[i]);
            m++;
        }
        for(i=0;i<20-m;i++)
            printf(" ");//输出当前字符串

        c2=stack[sp-1];
        stack[sp-1]='\0';
        sp--;//弹出栈顶元素,并把栈顶后一位赋值为'\0',sp指向栈顶后一位

        i=ter(c2);
        if(i < vtNum)//c2是终结符
        {
            if(c2==c1[p1])
            {
                p1++;
                printf(" ");
            }
            else
                break;
        }
        else
        {
            if(c2=='#')//栈顶元素为#
            {
                if(c1[p1]==c2)
                {
                    flag=1;//运行成功,跳出
                    break;
                }
                else
                    break;
            }
            else
            {
                m=non_t(c2);//c2是非终结符
                n=ter(c1[p1]);
                //if(M[m][n]=='0') break;
                if(M[m][n]!=-1)
                {
                    //输出对应的文法
                    j=M[m][n];
                    printf("%s", grammar[j]);
                    k=3;
                    while(grammar[j][k] != '\0')
                        k++;

                    /*printf("%c->",grammar[m][0]);
                    for(k=1;grammar[j][k]!='\0';k++)
                        printf("%c",grammar[j][k]);*/
                    //for(x=0;x<20-k;x++)
                    //  printf(" ");
                    if(grammar[j][3] != '$')//逆序压入,忽略空字符$
                    {
                        for(y=k-1;y>=3;y--)
                        {
                            stack[sp++]=grammar[j][y];
                            stack[sp]='\0';
                        }
                    }
                }
                else break;
            }
        }
    }
    if(flag==1)
        printf("\n\n符合句型！\n");
    else
        printf("\n\n不符!\n");
    return 1;
}

int printf_table()//输出预测分析表
{
    int i,j,p;
    printf("\n预测分析表为:\n");;
    printf("          ");
    for(i=0; i < vtNum; i++)
    {
        printf("%c         ",terSymbol[i]);
    }
    printf("#         \n");
    for(i=0; i < vnNum; i++)
    {
        printf("%c         ",non_ter[i]);
        for(j=0; j <= vtNum; j++)
        {
            if(M[i][j]!=-1)
            {
                int k=M[i][j];
                int m=strlen(grammar[k]);
                printf("%s", grammar[k]);
                for(p=0;p<10-m;p++)
                    printf(" ");
            }
            else{
                for(p=0;p<10;p++)
                    printf(" ");
            }
        }
        printf("\n");
    }
    return 1;
}

int main()
{
    int i,j;
    for(i=0;i<200;i++)
        for(j=0;j<200;j++)
            grammar[i][j]='\0';
    printf("请输入文法的非终结符号串(不带空格)：\n");
    scanf("%s",non_ter);
    getchar();
    vnNum=strlen(non_ter);
    printf("请输入文法的终结符号串(不带空格)：\n");
    scanf("%s",terSymbol);
    getchar();
    vtNum=strlen(terSymbol);
    printf("请输入产生式个数:\n");
    scanf("%d",&proNum);
    printf("请输入文法：\n");
    for(i=0; i < proNum; i++)
    {
        scanf("%s", grammar[i]);
        getchar();
    }
    for(i=0; i < vnNum; i++)
        for(j=0; j <= vtNum; j++)
            firstSet[i][j]=0;//初始化FIRST集
    for(i=0; i < vnNum; i++)
        first(non_ter[i]);//对每个non_ter求FIRST集
    for(i=0; i < vnNum; i++)
        for(j=0; j <= vtNum; j++)
            followSet[i][j]=0;//初始化FOLLOW集
    for(i=0; i < vnNum; i++)
        follow(non_ter[i]);//对每个non_ter求FOLLOW集
    printf("\n");
    for (int k = 0; k < vnNum; ++k) {
        printf(" %c 的FIRST集为：{",non_ter[k]);
        for (int l = 0; l < vtNum; ++l) {
            if(firstSet[k][l] == 1){
                printf(" %c ",terSymbol[l]);
            }
        }
        printf("}\n");
    }
    printf("\n");
    for (int k = 0; k < vnNum; ++k) {
        printf("%c 的FOLLOW集为：{",non_ter[k]);
        for (int l = 0; l < vtNum; ++l) {
            if(followSet[k][l] == 1){
                printf(" %c ",terSymbol[l]);
            }
        }
        printf("}\n");
    }
    initAnalysis();
    analysis();
    printf_table();
    control();
    system("pause");
}