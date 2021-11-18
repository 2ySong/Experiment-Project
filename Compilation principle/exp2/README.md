输入文法及待分析的输入串，输出其预测分析过程及结果。

### 1. 参考数据结构 

##### (1) 定义产生式的语法集结构

```c++
typedef struct{

  char formula[200];//产生式

}grammarElement;

grammarElement  gramOldSet[200];//原始文法的产生式集
```

##### (2) 变量定义

```c++
char terSymbol[200];//终结符号

char non_ter[200];//非终结符号

char allSymbol[400];//所有符号

char firstSET[100][100];//各产生式右部的FIRST集

char followSET[100][100];//各产生式左部的FOLLOW集

int M[200][200];//分析表
```

### 2. 判断文法的左递归性：

将左递归文法转换成非左递归文法。（该步骤可以省略，直接输入非左递归文法）。

### 3. 根据文法求FIRST集和FOLLOW集。

#### （1）求 First 集的算法

begin

if  X为终结符(X∈V~N~)

​    在所有产生式中查找X所在的产生式

​    if  产生式右部第一个字符为终结符或空(即X→a（X∈V~T~）或X→ε)

​     then 把a或e加进FIRST(X)

​    if 产生式右部第一个字符为非终结符 then

​       if产生式右部的第一个符号等于当前字符 then

​        跳到下一条产生式进行查找

​       if 当前非终结符还没有求其FIRST集 then

​         查找它的FIRST集并标识此符号已求其FIRST集

​     求得结果并入到X的FIRST集

​     if  当前产生式右部符号可推出空字且当前字符不是右部的最后一个字符

​     then  获取右部符号下一个字符在所有字符集中的位置

​     if  此字符的FIRST集还未查找 then

​     找其FIRST集，并标其查找状态为1

​     把求得的FIRST集并入到X的FIRST集

​     if  当前右部符号串可推出空且是右部符号串的最后一个字符(即产生式为$X→Y_1Y_2...Y_n$，若对一切1≤i≤k,均有e ÎFIRST(![img](file:///C:\Users\szy\AppData\Local\Temp\ksohtml35724\wps16.png)),则将eÎ符号加进FIRST(X))  then 把空字加入到当前字符X的FIRST集

​     else

​        不能推出空字则结束循环

​    标识当前字符X已查找其FIRST集。

end

（2）求 FOLLOW 集的算法

begin

  if  X为开始符号 then # ÞFOLLOW(X) 

  对全部的产生式找一个右部含有当前字符X的产生式

  if X在产生式右部的最后(形如产生式A®aX) then

​    查找非终结符A是否已经求过其FOLLOW集.避免循环递归

​    if 非终结符A已经求过其FOLLOW集 then

​      把FOLLOW(A)中的元素加入FOLLOW(X)

​      继续查下一条产生式是否含有X

​    else

​      求A的FOLLOW集，并标记为A已求其FOLLOW集

  else if X不在产生式右部的最后(A®aBb) then

​      if  右部X后面的符号串b能推出空字e then

​           查找b是否已求过其FOLLOW集.避免循环递归

​           if 已求过b的FOLLOW集 then

把FOLLOW(A)中的元素加入FOLLOW(B)

​          结束本次循环

​       else if b不能推出空字 then

​           求 FIRST(b)

​           把FIRST(b)中所有非空元素加入到FOLLOW(B)中

　　　　　标识当前要求的非终结符X的FOLLOW集已求过

​    end

4.构造预测分析表。

构造分析表

在AÎ![img](file:///C:\Users\szy\AppData\Local\Temp\ksohtml35724\wps17.png)所在行,aÎ![img](file:///C:\Users\szy\AppData\Local\Temp\ksohtml35724\wps18.png)所在列, M[A,a]的填写方法如下:

```c++
if (A®dÎP and aÎFIRST(δ) ) do

    M[A,a]=‘A→d’

if (dÞ*e(eÎFIRST(d)) and aÎFOLLOW(A)) do

 M[A,a]=‘A→d’;

else   do  M[A,a]=‘ERR’.
```

5.构造总控程序。

程序流程图如下图1所示：

<img src="https://gitee.com/song-zhangyao/mapdepot1/raw/master/typora/202111072110408.png" alt="img" style="zoom:28%;" />

6.对给定的输入串，给出分析过程及结果。