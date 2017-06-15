#include <iostream>
using namespace std;
class MyString
{
private:
char *str;
public:
MyString(char *s);
MyString(const MyString&);			// �������캯��
int strlenth(void)const;			// �ַ�������
int strcmpp(const MyString&) const;  // �Ƚ��ַ���
void strcpy(const MyString&);  // �����ַ���
void strcat(const MyString&);  // �����ַ���
void display();
~MyString();
};
MyString::MyString(char *s)
{	int i=0;
	str = new char[100];
	while(*(s+i)!=' ')
	{
	*(str+i)=*(s+i);
	i++;
	} 
}
MyString::~MyString(){delete [] str;}
int MyString::strlenth()const
{	//str = new char[100];
    int i=0;
	while(*(str+i)!=' ')
		i++;
	return i;
}
int MyString::strcmpp(const MyString& a)const
{	int ret;
	char* s1=this->str;
	char* s2=a.str;
	while( !(ret = *(unsigned char*)s1 - *(unsigned char*)s2) && *s1)
    {
        s1 ++;
        s2 ++;
    }
 
     if(ret < 0) return -1;
     else if( ret >0) return 1;
     return 0;
}
void MyString::strcpy(const MyString& a)
{	str = new char[100];
	char* s0=this->str;
	char* s=a.str;
    int i=0;
	while(*(s+i)!=' ')
	{
	*(s0+i)=*(s+i);
	i++;
	}
}
void MyString::strcat(const MyString& a)
{	
	str = new char[100];
	char* s0=this->str;
	char* s=a.str;
    int i=0;
    int j=0;
    while(*(s0+i)!= '\0')
        i++;
    while(*(s+j)!=' ')
    {
	 *(s0+i)= *(s+j);
	 j++;
	 i++;
	}
}
void MyString::display()
{
	puts(str);
}
MyString::MyString(const MyString& a)
{
	str = new char[100];
	char* s0=this->str;
	char* s=a.str;
    int i=0;
	while(*(s+i)!=' ')
	{
	*(s0+i)=*(s+i);
	i++;
	}
}
int main() 
{	char aa[100],bb[100];
	cin >> aa>>bb;
	MyString ss1(aa);
	ss1.display();
	MyString ss2(bb);
	ss2.display();
	MyString ss3(ss1);
	ss3.display();
	int n=ss1.strlenth();
	cout << n << endl;
    n=ss1.strcmpp(ss2);
	cout << n << endl;
	ss1.strcpy(ss2);
	ss1.display();
	ss1.strcat(ss2);
	ss1.display();
	return 0;
}
