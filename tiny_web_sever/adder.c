#include "csapp.h"

int main(void)
{
   char *buf, *p;
   char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE]; 
   int n1=0, n2=0;
   
   if((buf = getenv("QUERY_STRING")) != NULL)
   	{
   		p = strchr(arg1, '&');
   		*p = '\0';
   		strcpy(arg1, buf);
   		strcpy(arg2, p+1);
   		n1 = atoi(arg1);//将字符串转换成整型数
   		n2 = atoi(arg2);
   	}
   	
   	//建立响应的主体结构
   	sprintf(content, "Welcome to 120.27.44.3");
   	sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
   	sprintf(content, "The answer is: %d + %d = %d\r\n<p>",
   												content, n1, n2, n1 + n2);
   	sprintf(content, "%sThanks for visiting!\r\n", content);
   	
   	//生成HTTP响应
   	
   	/*
   	*采用标准I/O的原因：子进程中运行的CGI程序不需要显示的关闭它的输入输出流。
   	*当子进程终止时，内核会自动关闭所有描述符。
   	*/
   	
   	printf("Content-length: %d\r\n", (int)strlen(content));
   	printf("Content-type: text/html\r\n\r\n");
   	printf("%s", content);
   	fflush(stdout);
   	exit(0);
   	
} 
