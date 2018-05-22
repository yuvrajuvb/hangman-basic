
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int i=0,flag=0,randum=0,x=0;
int no_gues=5;

char word[15],blank[15],gues;
char* word_inventory(int ran)
{
    static char cities[10][15]={"ambala","yamunanagar","delhi","gurgaon","jaipur","chandigarh","pune","mumbai","dehradun","rajpura"};
    return cities[ran];

}
char letter[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void replace_letter(char replace)
{
  for(i=0;i<=26;i++)
  {
      if(replace==letter[i])
      {
          flag=1;
          letter[i]='_';
      }

  }

  if(flag==1)
  {flag=0;

  }
  else
  {
  cout<<"wrong input"<<endl;
  }
  for(i=0;i<=26;i++)
    cout<<letter[i]<<"\t";
    cout<<endl<<endl;

}
void blank_creator()
{
    for(i=0;i<x;i++)
    blank[i]='_';
}
void check_guess(char gues)
{
    for(i=0;i<=x;i++)
    {
        if(gues==word[i])
        { flag=1;
        blank[i]=gues;
        }

    }


    if(flag==1)
    {
        flag=0;
    }
    else
   {

   cout<<"\nWrong guess.tries left : "<<--no_gues<<endl<<endl<<endl;
  // no_gues--;
   }

   for(i=0;i<=x;i++)
    cout<<blank[i]<<"\t";
    cout<<endl<<endl;

}
int check_win()
{
    if(strcmp(word,blank)==0)
    {

       return 1;
    }
    else
    {  return 0;
    }
}
int main()
{    int win=0;
     cout<<"---------------Welcome to hangman------------"<<endl;
     cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have 5 tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<"\n\n**************Guess the city****************"<<endl;
    srand(time(NULL));
    randum = rand() % 10 + 0;
    strcpy(word,word_inventory(randum));
    char tes[15];
    strcpy(tes,word);
    x=strlen(word);

    blank_creator();

    for(i=0;i<=x;i++)
          cout<<blank[i]<<"\t";
          cout<<endl<<endl;

    for(i=0;i<=26;i++)
           cout<<letter[i]<<"\t";

    for(;no_gues>=0 && win==0;)
       {

        cout<<endl<<"Enter your guess"<<endl;
        cin>>gues;
        check_guess(gues);
        replace_letter(gues);

        win=check_win();
       }
      if(win==1)
    {
       cout<<"\nYou guessed the whole word right"<<endl;
    }

      else
    {cout<<"\n You failed to save the kangroo"<<endl;
    cout<<"\n correct word :"<<tes<<endl;
         cout<<"\nHanging now"<<endl;
    }


       //}
getch();
}











