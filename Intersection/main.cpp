#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

char char_temp1[2]={'\0','\0'};
int int_temp1=0;
char char_temp2[2]={'\0','\0'};
int int_temp2=0;


const char *input_file_name = "C:\\Users\\hbq\\Desktop\\big data\\RintersectionS.tsv";



int main()
{

     FILE *fp1;
     FILE *fp2;

     fp1=fopen("C:\\Users\\hbq\\Desktop\\big data\\R.tsv","r");
     fp2=fopen("C:\\Users\\hbq\\Desktop\\big data\\S.tsv","r");
     fstream outFile;

  //input
	 outFile.open(input_file_name, ios::out);

     int i=0;
     int j=0;

     fscanf(fp1,"%s \t%d",&char_temp1,&int_temp1);
     fscanf(fp2,"%s \t%d",&char_temp2,&int_temp2);
     while(i<300&&j<300)
	 {

	     if(strcmp(char_temp1,char_temp2)<0)
         {
             i++;
             fscanf(fp1,"%s \t%d",&char_temp1,&int_temp1);
             //Every time a line of R.tsv is read, i is incremented by 1
         }
         if(strcmp(char_temp1,char_temp2)>0)
        {
            j++;
            fscanf(fp2,"%s \t%d",&char_temp2,&int_temp2);
            //Every time a line of S.tsv is read, i is incremented by 1
        }
        if(strcmp(char_temp1,char_temp2)==0&&int_temp1!=int_temp2)
        {
            j++;
            fscanf(fp2,"%s \t%d",&char_temp2,&int_temp2);
        }
        if(strcmp(char_temp1,char_temp2)==0&&int_temp1==int_temp2)
        {
            j++;
            fscanf(fp2,"%s \t%d",&char_temp2,&int_temp2);
            outFile <<char_temp1<<'\t'<<int_temp1<< endl;
            //If two lines read are equal, write this line to RintersectionS.tsv
            //cout<<char_temp1<<" "<<int_temp1<<endl;
        }
	 }
	 //cout<<int_temp1<<" "<<endl2;
	 fscanf(fp1,"%s \t%d",&char_temp1,&int_temp1);i++;

	 cout<<i<<" "<<j<<endl;
	 outFile.close();
}
