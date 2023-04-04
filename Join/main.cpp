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


const char *input_file_name = "C:\\Users\\hbq\\Desktop\\big data\\RjoinT.tsv";


int main()
{

     FILE *fp1;
     FILE *fp2;

     fp1=fopen("C:\\Users\\hbq\\Desktop\\big data\\R.tsv","r");
     fp2=fopen("C:\\Users\\hbq\\Desktop\\big data\\T.tsv","r");
     ofstream outFile;

  //input
	 outFile.open(input_file_name, ios::out);

     int i=0;
     int t=0;
     int s=0;
     int flag=0;

     for(i=0;i<300;i++)
	 {
	     fscanf(fp1,"%s \t%d",&char_temp1,&int_temp1);
	     //cout<<"src1:"<<char_temp1<<endl;
	     s++;
	     //Every time a line of R.tsv is read, s is incremented by 1
         if(strcmp(char_temp1,char_temp2)==0)
            {
                outFile << char_temp1<<'\t'<<int_temp1<<'\t'<<int_temp2<< endl;
                flag=1;
                //If the chars of the line in the two files is the same, write this line to RjoinT
            }
	     while(t<1000)
         {

             fscanf(fp2,"%s \t%d",&char_temp2,&int_temp2);
             //cout<<char_temp2<<endl;
             t++;
             //Every time a line of T.tsv is read, t is incremented by 1
            if(strcmp(char_temp1,char_temp2)==0)
            {
                outFile << char_temp1<<'\t'<<int_temp1<<'\t'<<int_temp2<< endl;
                flag=1;

            }
             if(strcmp(char_temp1,char_temp2)<0)
             {
                 flag=0;
                 break;
             }

         }

     }
    cout<<t<<" "<<s<<endl;
    outFile.close();
 }
