#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include"controlcoord.h"
const int MAX = 26;
string s;  //stored combination of letters into string type
string words[10000000];    //array that holds all combinations of the string s
string final_words[10000];    //array that holds all valid words of string s
int Count=0,final_count=0,flag=5,checking=0;
Controlcoord config_console;
struct Node  // to create node
{
    string data;
    struct Node* Leftchild;
    struct Node* Rightchild;
};
struct Node *root,*par;

void rootNode(string firstWord)   //to insert root node
{
    struct Node* rootNode = new Node;
    rootNode->data=firstWord;
    rootNode->Leftchild = NULL;
    rootNode->Rightchild = NULL;
    root = rootNode;
}
void insertNode(string word)   //to insert node in bst
{
    par = NULL;
    Node *ptr = root;
    while(ptr!=NULL)
    {
        par = ptr;
        if(word.compare(ptr->data)<0)
        {
           ptr=ptr->Leftchild;
        }
        else if(word.compare(ptr->data)>0)
        {
            ptr = ptr->Rightchild;
        }
        else if(word.compare(ptr->data) ==0)
        {
            return;
        }
    }

    struct Node *childNode = new Node;
    childNode->data = word;
    childNode->Leftchild = NULL;
    childNode->Rightchild = NULL;

    if(word.compare(par->data)<0)
    {
        par->Leftchild = childNode;
    }
    else
    {
        par->Rightchild = childNode;
    }

}
 string search(string entered_word)   //to search string in bst
{
    par = root;
    struct Node *ptr = root;
    par = ptr;
    while(ptr!=NULL)
    {
        if(entered_word.compare(ptr->data)==0)
        {
            return ptr->data;
        }
        else if(entered_word.compare(ptr->data)>0)
        {
            ptr = ptr->Rightchild;
        }
        else if(entered_word.compare(ptr->data)<0)
        {
            ptr = ptr->Leftchild;
        }
    }
    if(ptr==NULL)
    {
        //cout<<"wrong guess"<<endl;
        return "a";
    }
}

void set_up_app()
{
    config_console.setxy(35,12);cout<<"Please wait gathering information....."<<endl;
    fstream newfile;
    int tree_flag = 0;
    newfile.open("word_data.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open())
    {
            //checking whether the file is open
      string tp;
      while(getline(newfile, tp)){
          if (tree_flag == 0)
          {
              rootNode(tp);
          }
          else
          {
              insertNode(tp);
          }
          tree_flag++;
      }
      newfile.close(); //close the file object.
    }
}

void permute(string a,int l,int r)   //to generate combination and store it on an array
{
    if (l == r)
    {
       words[Count]=a;
       Count++;
    }    //cout<<a<<endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]); //swap
            permute(a, l+1, r);  //recursion
            swap(a[l], a[i]);  //backtrack
        }
    }
}

void permutation()      //working
{
    int n = s.size();
    permute(s, 0, n-1);
}


void check()     // to store all valid words from combination array to final words array
{
    final_count=0;
    for(int i=0;i<Count;i++)
    {
        string samp=words[i];
        string z=search(samp);
        //cout<<z<<"  ";
        if(z.compare("a")==0)
        {
            // do nothing
        }
        else
        {
            final_words[final_count]=z;
            final_count++;
        }
    }

}
void search_array(string a)         // function to search user input in final valid words array
{
    int i,flag1=0;
    for(i=0;i<=final_count;i++)
    {
        if(a.compare(final_words[i])==0)
        {
            cout<<"CORRECT GUESS"<<endl;
            flag1=1;
            checking++;
            break;
        }
    }
        if(i>final_count && flag1==0)
        {
            cout<<"WRONG GUESS"<<endl;
            flag--;
        }
        cout<<"You have "<<::flag<<" chances remaining.\n"<<endl;

}
char printRandomchar(int k)    //function to generate random charcters
{
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };
        //char alphabet[6]={'h','o','e','l','l'};

    char res,ar[20];
    int arr[5]={0,4,8,14,20};            //1 5 9 15 21
    int new_n;
    int i,check=0;
    srand(time(0));
    for(int i=0;i<k;i++)
    {
        if(check=0)
        {
            new_n =rand()%5;
            int ki=arr[new_n];
            res = alphabet[ki];
            ar[i]=res;
            check++;
            cout<<res<<"  ";
        }
        else
            {
        new_n =rand()%26;
        res = alphabet[new_n];
        ar[i]=res;
        cout<<res<<"  "; }
    }
    s=ar;
    //cout<<s;

}

int main()
{

    config_console.setxy(35,10);cout<<"Please wait setting up the application...donot click anything..";
    set_up_app();
    menu:system("cls");
    config_console.setxy(35,10);cout<<"WELCOME TO THE GAME.....";
    config_console.setxy(35,11);cout<<"SELECT THE DIFIICULTY OF GAME : "<<endl;
    config_console.setxy(37,12);cout<<"1) EASY";
    config_console.setxy(37,13);cout<<"2) INTERMEDIATE";
    config_console.setxy(37,14);cout<<"3) PRO MODE";
    config_console.setxy(37,15);cout<<"4) EXIT THE APPLICATION";
    string mode_select;
    config_console.setxy(40,17);cout<<"ENTER THE MODE HERE: ";
    config_console.setxy(63,17);cin>>mode_select;
    system("cls");
    if(mode_select == "EASY" || mode_select == "easy" || mode_select == "1")
    {
        int z=4,console_x=84,console_y=2;
        final_count=0;
        flag=5;
        config_console.setxy(35,2);cout<<"ENTER AN WORD FROM THE GIVEN LIST OF ALPHABETS : "<<endl;
        string user_entered_word;
        config_console.setxy(console_x,console_y);
        //s="elap";   //otsp  akew  elap
        //cout<<"e  l  a  p";
        printRandomchar(z);
        permutation();
        check();
        config_console.setxy(35,4);cout<<"TOTALLY YOU HAVE "<<flag<<" CHANCES TO GUESS THE WORD : \n"<<endl;

        //this loop runs untill the chances are over
        while(flag)
        {
            l2:cout<<"\nENTER YOUR GUESS: ";
            cin>>user_entered_word;
            if(user_entered_word.size()==s.size())
            {
                search_array(user_entered_word);
                if(checking==final_count && final_count!=0)
                {
                    cout<<"CONGRATS!!! YOU FOUND ALL THE WORDS"<<endl;
                    break;
                }
            }
            else if(user_entered_word.size()>s.size())
            {
                cout<<"Word limit exceeded\n"<<endl;
                goto l2;
            }
            else
            {
                string sample=search(user_entered_word);
                if(sample.compare("a")==0)
                {
                    cout<<"oops!!wrong guess\n"<<endl;
                }
                else
                {
                    cout<<"GREAT!!You have found a extra word\n"<<endl;
                }
            }
        }
        int choice;
        cout<<"Do you wish to continue the game ?(1-yes 0-no)  ";
        cin>>choice;
        if(choice==1)
        {
            goto menu;
        }


    }
    else if(mode_select == "INTERMEDIATE" || mode_select == "intermediate" || mode_select == "2")
    {
        int z=5,console_x=84,console_y=2;
        final_count=0;
        flag=4;
        config_console.setxy(35,2);cout<<"ENTER AN WORD FROM THE GIVEN LIST OF ALPHABETS : "<<endl;
        string user_entered_word;
        config_console.setxy(console_x,console_y);
        s="abt";    //abt
        cout<<"a  b  t";
        //printRandomchar(z);
        permutation();
        check();
        config_console.setxy(35,4);cout<<"TOTALLY YOU HAVE "<<flag<<" CHANCES TO GUESS THE WORD : \n"<<endl;

        //this loop runs untill the chances are over
        while(flag)
        {
            l3:cout<<"\nENTER YOUR GUESS: ";
            cin>>user_entered_word;
            if(user_entered_word.size()==s.size())
            {
                search_array(user_entered_word);
                if(checking==final_count && final_count!=0)
                {
                    cout<<"CONGRATS!!! YOU FOUND ALL THE WORDS"<<endl;
                    break;
                }
            }
            else if(user_entered_word.size()>s.size())
            {
                cout<<"Word limit exceeded\n"<<endl;
                goto l3;
            }
            else
            {
                string sample=search(user_entered_word);
                if(sample.compare("a")==0)
                {
                    cout<<"oops!!wrong guess\n"<<endl;
                }
                else
                {
                    cout<<"GREAT!!You have found a extra word\n"<<endl;
                }
            }
        }
        int choice;
        cout<<"Do you wish to continue the game ?(1-yes 0-no)  ";
        cin>>choice;
        if(choice==1)
        {
            goto menu;
        }


    }
    else if(mode_select == "PRO MODE" || mode_select == "pro mode" || mode_select == "3")
    {
        int z=6,console_x=84,console_y=2;
        //config_console.setxy(console_x,console_y);
        final_count=0;
        flag=3;
        config_console.setxy(35,2);cout<<"ENTER AN WORD FROM THE GIVEN LIST OF ALPHABETS : "<<endl;
        string user_entered_word;
        config_console.setxy(console_x,console_y);
        s="irsach";     //irsach
        cout<<"i  r  s  a  c  h";
        //printRandomchar(z);
        //console_x = console_x+2;
        permutation();
        check();
        config_console.setxy(35,4);cout<<"TOTALLY YOU HAVE "<<flag<<" CHANCES TO GUESS THE WORD : \n"<<endl;

        //this loop runs untill the chances are over
        while(flag)
        {
            l4:cout<<"\nENTER YOUR GUESS: ";
            cin>>user_entered_word;
            if(user_entered_word.size()==s.size())
            {
                search_array(user_entered_word);
                if(checking==final_count && final_count!=0)
                {
                    cout<<"CONGRATS!!! YOU FOUND ALL THE WORDS"<<endl;
                    break;
                }
            }
            else if(user_entered_word.size()>s.size())
            {
                cout<<"Word limit exceeded\n"<<endl;
                goto l4;
            }
            else
            {
                string sample=search(user_entered_word);
                if(sample.compare("a")==0)
                {
                    cout<<"oops!!wrong guess\n"<<endl;
                }
                else
                {
                    cout<<"GREAT!!You have found a extra word\n"<<endl;
                }
            }
        }
        int choice;
        cout<<"Do you wish to continue the game ?(1-yes 0-no)  ";
        cin>>choice;
        if(choice==1)
        {
            goto menu;
        }

    }
    //to check for exit condition
    else if(mode_select=="exit" || mode_select=="EXIT" || mode_select=="4")
    {
        return 0;
    }
    else
    {
        cout<<"PLEASE ENTER A VALID OPTION \n"<<endl;
        goto menu;
    }


}

