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
   		n1 = atoi(arg1);//���ַ���ת����������
   		n2 = atoi(arg2);
   	}
   	
   	//������Ӧ������ṹ
   	sprintf(content, "Welcome to 120.27.44.3");
   	sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
   	sprintf(content, "The answer is: %d + %d = %d\r\n<p>",
   												content, n1, n2, n1 + n2);
   	sprintf(content, "%sThanks for visiting!\r\n", content);
   	
   	//����HTTP��Ӧ
   	
   	/*
   	*���ñ�׼I/O��ԭ���ӽ��������е�CGI������Ҫ��ʾ�Ĺر����������������
   	*���ӽ�����ֹʱ���ں˻��Զ��ر�������������
   	*/
   	
   	printf("Content-length: %d\r\n", (int)strlen(content));
   	printf("Content-type: text/html\r\n\r\n");
   	printf("%s", content);
   	fflush(stdout);
   	exit(0);
   	
} 
