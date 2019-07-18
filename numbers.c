#include <stdio.h>
//#include <conio.h>
#include<stdlib.h>
#define SIZE 9
int top=-1;
int stack[SIZE];
int flag=1;
void push (int num)
{
 if (top>=SIZE-1)
 {
  printf ("The number is too huge. \n Stack Overflow \n");
  printf ("Press any key to exit \n");
  //getch ();
  exit (0);
 }
 else
 stack[++top]=num;
}
void print (int num)
{
 switch (num)
 {
  case 1: printf ("One ");
  break;
  case 2: printf ("Two ");
  break;
  case 3: printf ("Three ");
  break;
  case 4: printf ("Four ");
  break;
  case 5: printf ("Five ");
  break;
  case 6: printf ("Six ");
  break;
  case 7: printf ("Seven ");
  break;
  case 8: printf ("Eight ");
  break;
  case 9: printf ("Nine ");
  break;
 }
}
void print_pair (int num)
{
 switch (num)
 {
  case 1: switch (stack[top])
  {
   case 1: printf ("Eleven ");
   break;
   case 2: printf ("Twelve ");
   break;
   case 3: printf ("Thirteen ");
   break;
   case 4: printf ("Fourteen ");
   break;
   case 5: printf ("Fifteen ");
   break;
   case 6: printf ("Sixteen ");
   break;
   case 7: printf ("Seventeen ");
   break;
   case 8: printf ("Eighteen ");
   break;
   case 9: printf ("Nineteen ");
   break;
   case 0: printf ("Ten ");
   flag=0;
  }
  break;
  case 2: printf ("Twenty ");
  break;
  case 3: printf ("Thirty ");
  break;
  case 4: printf ("Forty ");
  break;
  case 5: printf ("Fifty ");
  break;
  case 6: printf ("Sixty ");
  break;
  case 7: printf ("Seventy ");
  break;
  case 8: printf ("Eighty ");
  break;
  case 9: printf ("Ninety ");
  break;
 }
}
void trans (int len)
{
 if (len==9)
 {
  print_pair (stack[top--]);
  if (stack[top+1]!=1 && flag)
  print (stack[top--]);
  else
  top--;
  printf ("Crores ");
 }
 if (len>=7)
 {
  if (len==8)
  {
   print (stack[top--]);
   printf ("Crores ");
  }
  print_pair (stack[top--]);
  if (stack[top+1]!=1 && flag)
  print (stack[top--]);
  else
  top--;
  if (stack[6]!=0 || stack[5]!=0)
  printf ("Lakhs ");
  if (flag==0)
  flag=1;
 }
 if (len>=5)
 {
  if (len==6)
  {
   print (stack[top--]);
   printf ("Lakhs ");
  }
  print_pair (stack[top--]);
  if (stack[top+1]!=1 && flag)
  print (stack[top--]);
  else
  top--;
  if (stack[4]!=0 || stack[3]!=0)
  printf ("Thousand ");
  if (flag==0)
  flag=1;
 }
 if (len>=3)
 {
  if (len==4)
  {
   print (stack[top--]);
   printf ("Thousand ");
  }
  print (stack[top--]);
  if (stack[2]!=0)
  printf ("Hundered ");
  if (stack[1]==0 && stack[0]!=0)
  {
   printf ("And ");
   print (stack[0]);
  }
  else if (stack[1]!=0)
  {
   printf ("And ");
   print_pair(stack[top--]);
   if (stack[top+1]!=1 && flag)
   print (stack[top--]);
  }
 }
 if (len==2)
 {
  print_pair (stack[top--]);
  if (stack[top+1]!=1 && flag)
  print (stack[top--]);
  if (flag==0)
  flag=1;
 }
 if (len==1)
 print (stack[top--]);
}
void main ()
{
 long n;
 //clrscr ();
 printf ("Enter the number to be translated : \n");
 scanf ("%ld",&n);
 while (n>0)
 {
  push (n%10);
  n=n/10;
 }
 printf ("The number in words is : \n");
 trans (top+1);
 //getch ();
}