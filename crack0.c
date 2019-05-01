//Souley Meaki
// programme that crack a user given hash

#define _XOPEN_SOURCE
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<cs50.h>
int main (int argc,string argv[])
{
 if(argc == 2)
 {
  const int numberOfCharacters = 53;
  string alpha="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string hash = argv[1];

  char salt[3];

  memcpy(salt,hash,2);
  salt[2]='\0';
  char userPassword[5]="\0\0\0\0\0";

  for(int lastC=0; lastC<numberOfCharacters; lastC++)
  {
   for( int thirdC=0;  thirdC < numberOfCharacters;  thirdC++)
   {
    for( int secondC=0; secondC < numberOfCharacters;secondC++)
    {
     for( int firstC=0; firstC < numberOfCharacters; firstC++)
     {

      userPassword[0]=alpha[firstC];
      userPassword[1]=alpha[secondC];
      userPassword[2]=alpha[thirdC];
      userPassword[3]=alpha[lastC];

      if(strcmp(crypt(userPassword,salt),hash)  == 0 )
      {
        printf("%s\n",userPassword);
      }

     }
   }
  }
 }


}
  else
  {
        printf("Usage: ./crack0 hash");
  }
}