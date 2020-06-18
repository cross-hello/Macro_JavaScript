#include<stdio.h>
#include<stdlib.h>
#define flags 1 
#define false 0
//#define test
char cmp(const char *a, const char *b)
{
	if(*a!=*b)
		return false;
	static const char *re;
	re=b;
	while(*++a&&*++b)
		if(*a!=*b)
			return false;
	if(!*a)
		b++;
	if(*a|| *a=='\0'&&*b=='\0' )
	return b-re;
	else return false;
}
char len(const char *s)
{
	char i=0;
	while(*s++)
		i++;
	return i;
}

char * strsub(char *a,const char *sear,const char *sub)
{
	static char *va;
	va=a;

	char re,ti=0;
	while(*a)
	{
		if(*a==*sear)
		{
			re=cmp(a,sear);
			if(re)
			{
				*a=flags;
				ti++;
			}				
		}
		a++;
	}
#ifdef test
		printf("Original data:%s-%d \n",va,a-va);
		printf("search data:%s -%d \n",sear,len(sear));
		printf("Substitle data:%s -%d\n",sub,len(sub));
#endif
	int length=(a-va+1)+ti*(len(sub)-len(sear));
#ifdef test
	printf("ti:%d\nStack: %d\n",ti,length);
#endif
	char *r;
	r=(char *)malloc(length);
	a=r;
        const char * res;	
	re=len(sear);
	while(*va)
		if(*va!=flags)
			*a++=*va++;
		else
		{
			res=sub;
			while(*res)
				*a++=*res++;
			va+=re;
		}
	*a='\0';
	return r;
}
void get_line(char *s)
{
	char c;
	while((c=getchar())!='\n')
		*s++=c;
#ifndef test
	*s++='\n';
#endif
	*s='\0';
}
int main(int argc, char *argv[])
{
	char i;
#ifdef test
	char space[80];
	char search[80];
	char subt[80];
#endif
	int file_length;
	FILE *in,*out;
	char *pace,*cc,*sear,*sub,*file_pace,*ss,*cle;
	//puts(argv[1]);
	
	for(i=1;i<argc;i++)
	{
		in=fopen(argv[i],"r");
		if(in==NULL)
		{
			printf("Can't open %s\n.",argv[1]);
			continue;
		}

		cc=strsub(argv[i],".jc",".js");
		out=fopen(cc,"a");
		puts(cc);
		free(cc);

		fseek(in,0,SEEK_END);
		file_length=ftell(in);
		pace=(char *)malloc(file_length);
		if(pace==NULL)
		{
			puts("Sorry for spare memory.");
			return 0;
		}

		fseek(in,0,SEEK_SET);
		fread(pace,file_length,1,in);
//		puts("pace normal");
		fclose(in);

		
		pace[file_length-1]='\0';
		//puts(pace);  -m32 mode file read more than itself
		cc=pace;

		file_pace=(char*)malloc(file_length);
		ss=file_pace;
//		puts("file_pace normal");

		cle=pace;

		char record=0;
		while(*cc)
		{
			if(record)
			{
				*ss++='#';
				record=0;
			}
		while(*cc!='\0'&&*cc!='#')
			*ss++=*cc++;
		if(!*cc)
			break;
		if(*cc='#')
		{
			record=1;
			cc++;
		}
		if(cmp(cc,"define")==0)
			continue;
		else
			record=0;
		//puts("I am here");
		while(*cc!=' ')// clear define
			cc++;

		while(*cc==' ')
			cc++;
		sear=cc;
		while(*cc!=' ')
			cc++;
		*cc='\0';

		while(*++cc==' ')
			continue;
		sub=cc;
		while(*++cc!=' '&&*cc!='\n')
			continue;
		*cc='\0';

		cc++;
		//puts("I come again");
		cc=strsub(cc,sear,sub);
		//puts("May I here?");
		free(cle);
		cle=cc;
		}
	//	puts(cle);
		free(cle);
	//	*ss='\0';
	//	puts(file_pace);
		*ss=' ';
		fwrite(file_pace,ss-file_pace+1,1,out);
	//	while(*--ss!='\n')
	//		putchar(*ss);
		free(file_pace);
		fclose(out);
	}
	return 0;
}

#ifdef test
printf("Cmp:%d\n",cmp(".jc",".jc"));
	char *s;
	while(1)
	{
		get_line(space);
		get_line(search);
		get_line(subt);
		s=strsub(space,search,subt);
		puts(s);
		free(s);
	}
}
#endif

