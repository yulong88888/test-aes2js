
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AES_iOS.h"
#include "track_fun_AES.h"






//��Կ1
unsigned char BT_AES128key1[16]  = {0xC7,0x1D,0x49,0x70,0x08,0x87,0x21,0xA3,0xCA,0x69,0xEB,0xF9,0x01,0x14,0x68,0x38};
//��Կ2
unsigned char BT_AES128key2[16]  = {0xD2,0xAE,0x73,0x10,0x98,0xE1,0x8F,0x29,0xB6,0x39,0x41,0xA8,0x72,0x58,0x82,0x44};
//��Կ4
unsigned char BT_AES128key4[16]  = {0xFD,0x21,0xAA,0x04,0x73,0xC5,0x0E,0x6D,0x51,0x13,0x78,0x17,0xDA,0x48,0x18,0xEF};
//��Կ5
unsigned char BT_AES128key5[16]  = {0x20,0x85,0x52,0x29,0xF8,0xA1,0x65,0x74,0x4B,0xE1,0x8A,0xCF,0x94,0xC2,0x9E,0x8D};
//������
unsigned char BT_AES_IV[16]      = {0x78,0x28,0x65,0x6D,0xFC,0x2F,0xBB,0x0F,0x18,0xFB,0x62,0x22,0x45,0x3C,0x0C,0x9F};
/********************************************
* Function Name: AES_Chang_Key
* Description  : ����AES��Կ2
* Input        : NONE
* Output       : NONE
* Return Value : NONE
********************************************/
void  AES_Chang_Key2(unsigned char *Key)
{
	BT_AES128key2[2]  =(unsigned char)Key[1];
	BT_AES128key2[4]  =(unsigned char)Key[4];
	BT_AES128key2[5]  =(unsigned char)Key[6];
	BT_AES128key2[9]  =(unsigned char)Key[7];
	BT_AES128key2[10] =(unsigned char)Key[11];
	BT_AES128key2[12] =(unsigned char)Key[14];
}

/********************************************
* Function Name: AES_Chang_Key
* Description  : ����AES��Կ5
* Input        : NONE
* Output       : NONE
* Return Value : NONE
********************************************/
void  AES_Chang_Key5(unsigned char *Key)
{
	BT_AES128key5[1]  =(unsigned char)Key[7];
	BT_AES128key5[4]  =(unsigned char)Key[1];
	BT_AES128key5[7]  =(unsigned char)Key[13];
	BT_AES128key5[12] =(unsigned char)Key[8];
	BT_AES128key5[9]  =(unsigned char)Key[6];
	BT_AES128key5[11] =(unsigned char)Key[11];
	BT_AES128key5[15] =(unsigned char)Key[14];
}


/********************************************
* Function Name: iOS_AES_Encryption
* Description  : AES����ʹ����Կ1
* Input        : src Ҫ��������ָ�� �� ���ܺ������ָ��
                 len ���ݳ���
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key1_Encryption(unsigned char *src,  unsigned char len)
{

    unsigned char i;
    unsigned char in[48]   = {0};
    unsigned char out[128]   = {0};
	//1. AES��ʼ��
    AES_Init(BT_AES128key1);

	//2.��ȡҪ���ܵ�����
    for (i=0; i < len; i++)
    {
        in[i] = src[i];
    }

	//3.����
    AES_Encrypt(in, out, len, BT_AES_IV);//����


	//4.��ֵ
	for (i=0; i < len; i++)
    {
        src[i] = out[i];
    }
}

/********************************************
* Function Name: iOS_AES_Key1_Decryption
* Description  : AES����ʹ����Կ1
* Input        : src Ҫ��������ָ�� �� ���ܺ������ָ��
                 len ���ݳ���
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key1_Decryption(unsigned char *src,  unsigned char len)
{

    unsigned char Data[48]   = {0};
    unsigned char i;
	//1. AES��ʼ��
    AES_Init(BT_AES128key1);

	//2.��ȡҪ���ܵ�����
    for (i=0; i < len; i++)
    {
        Data[i] = src[i];
    }

	//3.����
	AES_Decrypt(Data, Data, len, BT_AES_IV);//����

    AES_Chang_Key2(Data);

	//4.��ֵ
	for (i=0; i < len; i++)
    {
        src[i] = Data[i];
    }
}



/********************************************
* Function Name: iOS_AES_Key2_Encryption
* Description  : AES����ʹ����Կ2
* Input        : src Ҫ��������ָ�� �� ���ܺ������ָ��
                 len ���ݳ���
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key2_Encryption(unsigned char *src,  unsigned char len)
{

    unsigned char Out[256] = {0};
    unsigned char In[48]   = {0};
    unsigned char i;

	//1. AES��ʼ��
    AES_Init(BT_AES128key2);

	//2.��ȡҪ���ܵ�����
    for (i=0; i < len; i++)
    {
        In[i] = (unsigned char)src[i];
    }

	//3.����
    AES_Encrypt(In, Out, len, BT_AES_IV);//����


	//4.��ֵ
	for (i=0; i < len; i++)
    {
        src[i] = (char)Out[i];
    }
}




/********************************************
* Function Name: iOS_AES_Key2_Decryption
* Description  : AES����ʹ����Կ2
* Input        : src Ҫ��������ָ�� �� ���ܺ������ָ��
                 len ���ݳ���
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key2_Decryption(unsigned char *src,  unsigned char len)
{

    unsigned char Data[48]   = {0};
    unsigned char i;


	//1. AES��ʼ��,ʹ����Կ2
    AES_Init(BT_AES128key2);

	//2.��ȡҪ���ܵ�����
    for (i=0; i < len; i++)
    {
        Data[i] = src[i];
    }

	//3.����
	AES_Decrypt(Data, Data, len, BT_AES_IV);//����

	//4.��ֵ
	for (i=0; i < len; i++)
    {
        src[i] = Data[i];
    }
}


/********************************************
* Function Name: iOS_AES_Key4_Decryption
* Description  : AES����ʹ����Կ4,��������Կ5�ɱ���
* Input        : src Ҫ��������ָ�� �� ���ܺ������ָ��
                 len ���ݳ���
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key4_Decryption(unsigned char *src,  unsigned char len)
{

    unsigned char Data[48]   = {0};
    unsigned char i;


	//1. AES��ʼ��
    AES_Init(BT_AES128key4);

	//2.��ȡҪ���ܵ�����
    for (i=0; i < len; i++)
    {
        Data[i] = src[i];
    }

	//3.����
	AES_Decrypt(Data, Data, len, BT_AES_IV);//����

	//4.������Կ5
	AES_Chang_Key5(Data);

	//5.��ֵ
	for (i=0; i < len; i++)
    {
        src[i] = Data[i];
    }
}


/********************************************
* Function Name: iOS_AES_Key4_Encryption
* Description  : AES����ʹ����Կ4
* Input        : src Ҫ��������ָ�� �� ���ܺ������ָ��
                 len ���ݳ���
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key4_Encryption(unsigned char *src,  unsigned char len)
{

    unsigned char Out[256] = {0};
    unsigned char In[48]   = {0};
    unsigned char i;

	//1. AES��ʼ��
    AES_Init(BT_AES128key4);

	//2.��ȡҪ���ܵ�����
    for (i=0; i < len; i++)
    {
        In[i] = (unsigned char)src[i];
    }

	//3.����
    AES_Encrypt(In, Out, len, BT_AES_IV);//����


	//4.��ֵ
	for (i=0; i < len; i++)
    {
        src[i] = (char)Out[i];
    }
}




/********************************************
* Function Name: iOS_AES_Key5_Decryption
* Description  : AES����ʹ����Կ5
* Input        : src Ҫ��������ָ�� �� ���ܺ������ָ��
                 len ���ݳ���
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key5_Decryption(unsigned char *src,  unsigned char len)
{

    unsigned char Data[48]   = {0};
    unsigned char i;


	//1. AES��ʼ��
    AES_Init(BT_AES128key5);

	//2.��ȡҪ���ܵ�����
    for (i=0; i < len; i++)
    {
        Data[i] = src[i];
    }

	//3.����
	AES_Decrypt(Data, Data, len, BT_AES_IV);//����


	//4.��ֵ
	for (i=0; i < len; i++)
    {
        src[i] = Data[i];
    }
}



/********************************************
* Function Name: iOS_AES_Key5_Encryption
* Description  : AES����ʹ����Կ5
* Input        : src Ҫ��������ָ�� �� ���ܺ������ָ��
                 len ���ݳ���
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key5_Encryption(unsigned char *src,  unsigned char len)
{

    unsigned char Out[256] = {0};
    unsigned char In[48]   = {0};
    unsigned char i;

	//1. AES��ʼ��
    AES_Init(BT_AES128key5);

	//2.��ȡҪ���ܵ�����
    for (i=0; i < len; i++)
    {
        In[i] = (unsigned char)src[i];
    }

	//3.����
    AES_Encrypt(In, Out, len, BT_AES_IV);//����


	//4.��ֵ
	for (i=0; i < len; i++)
    {
        src[i] = (char)Out[i];
    }
}



