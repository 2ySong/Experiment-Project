//
// Created by szy on 2021/10/31.
//第二版预处理

#include<stdio.h>
#include<String.h>
int main(){
    FILE *p;
    int  falg = 0,len,i=0,j=0;//
    char str[1000],str1[1000],c;
    if((p=fopen("E:\\Love me\\Compilation principle\\test.txt","rt"))==NULL){
        printf("无法打开");
        return  0;
    }
    else{
        //fgets(str,1000,p);
        while((c=getc(p))!=EOF){
            str[i++] = c;
        }
        fclose(p);
        str[i] = '\0';
        for(i=0;i<strlen(str);i++){
            if(str[i]=='/'&&str[i+1]=='/'){
                while(str[i++]!='\n'){}
            }//单行注释
            else if(str[i]=='/'&&str[i+1]=='*'){
                while(!(str[i]=='*'&&str[i+1]=='/')){i++;}
                i+=2;
            }//多行注释
            else if(str[i]==' '&&str[i+1]==' '){
                while(str[i]==' '){i++;}
                i--;
                if(str1[j-1]!=' ')
                    str1[j++]=' ';
            }//多个空格，去除空格
            else if(str[i]=='\n') {
                if(str1[j-1]!=' ')
                    str1[j++]=' ';
            }//换行处理，
            else if(str[i]==9){
                while(str[i]==9){
                    i++;
                }
                if(str1[j-1]!=' ')
                    str1[j++]=' ';
                i--;
            }//tab键处理
            else str1[j++] = str[i];//其他字符处理
        }
        str1[j] = '\0';

        if((p = fopen("E:\\Love me\\Compilation principle\\test1.txt","w"))==NULL){
            printf("can not find it!");
            return 0;
        }
        else{
            if(fputs(str1,p)!=0){
                printf("存储失败！");
            }
            else printf("存储成功！");
        }
        fclose(p);
    }
    return 0;
}