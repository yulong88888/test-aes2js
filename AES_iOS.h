
#ifndef __AES_iOS_H_
#define __AES_iOS_H_





/********************************************
* Function Name: iOS_AES_Key1_Encryption
* Description  : AES加密使用密钥1
* Input        : src 要加密数据指针 和 加密后的数据指针
                 len 数据长度
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key1_Encryption(unsigned char *src,  unsigned char len);


/********************************************
* Function Name: iOS_AES_Key1_Decryption
* Description  : AES解密使用密钥1
* Input        : src 要解闷数据指针 和 解密后的数据指针
                 len 数据长度
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key1_Decryption(unsigned char *src,  unsigned char len);

/********************************************
* Function Name: iOS_AES_Key2_Encryption
* Description  : AES加密使用密钥2
* Input        : src 要加密数据指针 和 加密后的数据指针
                 len 数据长度
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key2_Encryption(unsigned char *src,  unsigned char len);



/********************************************
* Function Name: iOS_AES_Key4_Decryption
* Description  : AES解密使用密钥4,并更新密钥5可变组
* Input        : src 要解闷数据指针 和 解密后的数据指针
                 len 数据长度
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key4_Decryption(unsigned char *src,  unsigned char len);

/********************************************
* Function Name: iOS_AES_Key4_Encryption
* Description  : AES加密使用密钥4
* Input        : src 要加密数据指针 和 加密后的数据指针
                 len 数据长度
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key4_Encryption(unsigned char *src,  unsigned char len);

/********************************************
* Function Name: iOS_AES_Key5_Decryption
* Description  : AES解密使用密钥5
* Input        : src 要解闷数据指针 和 解密后的数据指针
                 len 数据长度
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key5_Decryption(unsigned char *src,  unsigned char len);

/********************************************
* Function Name: iOS_AES_Key5_Encryption
* Description  : AES加密使用密钥5
* Input        : src 要加密数据指针 和 加密后的数据指针
                 len 数据长度
* Output       : NONE
* Return Value : NONE
********************************************/
void iOS_AES_Key5_Encryption(unsigned char *src,  unsigned char len);




#endif
