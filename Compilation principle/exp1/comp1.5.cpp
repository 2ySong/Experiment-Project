//
// Created by szy on 2021/10/31.
//�ڶ���Ԥ����

#include<stdio.h>
#include<String.h>
int main(){
    FILE *p;
    int  falg = 0,len,i=0,j=0;//
    char str[1000],str1[1000],c;
    if((p=fopen("E:\\Love me\\Compilation principle\\test.txt","rt"))==NULL){
        printf("�޷���");
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
            }//����ע��
            else if(str[i]=='/'&&str[i+1]=='*'){
                while(!(str[i]=='*'&&str[i+1]=='/')){i++;}
                i+=2;
            }//����ע��
            else if(str[i]==' '&&str[i+1]==' '){
                while(str[i]==' '){i++;}
                i--;
                if(str1[j-1]!=' ')
                    str1[j++]=' ';
            }//����ո�ȥ���ո�
            else if(str[i]=='\n') {
                if(str1[j-1]!=' ')
                    str1[j++]=' ';
            }//���д���
            else if(str[i]==9){
                while(str[i]==9){
                    i++;
                }
                if(str1[j-1]!=' ')
                    str1[j++]=' ';
                i--;
            }//tab������
            else str1[j++] = str[i];//�����ַ�����
        }
        str1[j] = '\0';

        if((p = fopen("E:\\Love me\\Compilation principle\\test1.txt","w"))==NULL){
            printf("can not find it!");
            return 0;
        }
        else{
            if(fputs(str1,p)!=0){
                printf("�洢ʧ�ܣ�");
            }
            else printf("�洢�ɹ���");
        }
        fclose(p);
    }
    return 0;
}