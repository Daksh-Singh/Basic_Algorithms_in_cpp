#include <iostream> 
#include <string>
using namespace std; 

//Encryption Function
string encrypt(string text, int k) 
{ 
	string cipher = ""; 

	for (int i=0;i<text.length();i++) 
	{ 

		if (isupper(text[i])) 
			cipher += char(int((text[i]-65)*k)%26 +65);
		//Keeping White spaces as same 
		else if(isspace(text[i]))
			cipher += text[i];

		else if(islower(text[i]))
			cipher += char(int((text[i]-97)*k)%26 +97); 
	} 
	return cipher; 
} 

//Decryption Function
string decrypt(string text, int k) 
{ 
	string plain = ""; 
	for (int i=0;i<text.length();i++) 
	{ 

		if (isupper(text[i])) 
			plain += char(int((text[i]-65)*k)%26 +65); 

		//Keeping White spaces as same
		else if(isspace(text[i]))
			plain += text[i];
			
		else if(islower(text[i]))
			plain += char(int((text[i]-97)*k)%26 +97); 
	} 
	return plain; 
} 

//to check if multiplicative inverse is possible or not
int gcd(int x , int y)
{
	if(y==0)
		return x;
	else
		return gcd(y,x%y);	
} 
	
//Multiplicative inverse of the key
int mul_inv(int a, int b)
{
	int r,r1,r2,t,t1,t2,q=0;
	r1=b, r2=a, t1=0, t2=1;
	while(r2>0)
	{
		q=r1/r2;
		r=r1-(q*r2);
		r1=r2;
		r2=r;
		t=t1-(q*t2);
		t1=t2;
		t2=t;	
	}
	if(r1==1)
	{
		if(t1<0)
			return 26+t1;
		else
			return t1;
	}		
}

int main() 
{ 
	string Plain_text; 
	int key,key_inv; 
	cout << "Enter the plain Text: ";
	getline(cin,Plain_text); 
	cout << "Enter the Key value: ";
	cin>>key;
	if(gcd(key,26)==1){
		string En = encrypt(Plain_text, key); 
		key_inv=mul_inv(key,26);
		string De = decrypt(En, key_inv);
		cout<<"\nPlain Text: "<< Plain_text;
		cout << "\nEncrypted Text(Cipher text): " << En;
		cout << "\nDecrypted Text(Decrypted Plain text): " << De; 
	}
	else
		cout<<"Sorry the Multiplicative inverse of the key cannot be calculated thus cannot perform operations";
	return 0;
} 

