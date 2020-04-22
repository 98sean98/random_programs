#include <iostream>
#include <cstdlib>
#define SPADE "\xE2\x99\xA0"
#define CLUB  "\xE2\x99\xA3"
#define HEART "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
using namespace std;

void
DealHand (int &c1, int &c2, int &c3, int &c4, int &c5)
{
  int x;
  cin >> x;
  std::srand (x);
  c1 = (rand () % 52);
  c2 = (rand () % 52);
  c3 = (rand () % 52);
  c4 = (rand () % 52);
  c5 = (rand () % 52);
}

void
PrintHand (int c1, int c2, int c3, int c4, int c5)
{
  int x;
  for (int n = 1; n <= 5; n++)
    {
      if (n == 1)
	x = c1;
      else if (n == 2)
	x = c2;
      else if (n == 3)
	x = c3;
      else if (n == 4)
	x = c4;
      else if (n == 5)
	x = c5;

      if (x % 13 == 0)
	cout << "A";
      else if (x % 13 <= 9)
	cout << (x % 13 + 1);
      else if (x % 13 <= 10)
	cout << "J";
      else if (x % 13 <= 11)
	cout << "Q";
      else if (x % 13 <= 12)
	cout << "K";

      if (x <= 12)
	cout << SPADE;
      else if (x <= 25)
	cout << HEART;
      else if (x <= 38)
	cout << CLUB;
      else if (x <= 51)
	cout << DIAMOND;
      if (n != 5)
	cout << " ";
    }
  cout << endl;
}

bool
IsFourOfAKind (int c1, int c2, int c3, int c4, int c5)
{

  c1 = c1 % 13;
  c2 = c2 % 13;
  c3 = c3 % 13;
  c4 = c4 % 13;
  c5 = c5 % 13;

  if (c1 == c2 && c2 == c3 && c3 == c4)
    return true;
  else if (c2 == c3 && c3 == c4 && c4 == c5)
    return true;
  else if (c3 == c4 && c4 == c5 && c5 == c1)
    return true;
  else if (c4 == c5 && c5 == c1 && c1 == c2)
    return true;
  else if (c5 == c1 && c1 == c2 && c2 == c3)
    return true;
  return false;
}

bool
IsFullHouse (int c1, int c2, int c3, int c4, int c5)
{

  c1 = c1 % 13;
  c2 = c2 % 13;
  c3 = c3 % 13;
  c4 = c4 % 13;
  c5 = c5 % 13;

  if (c1 == c2 && c2 == c3 && c4 == c5)
    return true;
  else if (c1 == c2 && c2 == c4 && c3 == c5)
    return true;
  else if (c1 == c2 && c2 == c5 && c3 == c4)
    return true;
  else if (c1 == c3 && c3 == c4 && c2 == c5)
    return true;
  else if (c1 == c3 && c3 == c5 && c2 == c4)
    return true;
  else if (c2 == c3 && c3 == c4 && c1 == c5)
    return true;
  else if (c2 == c3 && c3 == c5 && c1 == c4)
    return true;
  else if (c3 == c4 && c4 == c5 && c1 == c2)
    return true;
  return false;
}

bool
IsFlush (int c1, int c2, int c3, int c4, int c5)
{
  if ((c1 >= 0 && c1 <= 12) && (c2 >= 0 && c2 <= 12) && (c3 >= 0 && c3 <= 12)
      && (c4 >= 0 && c4 <= 12) && (c5 >= 0 && c5 <= 12))
      return true;
    
  else if ((c1 >= 13 && c1 <= 25) && (c2 >= 13 && c2 <= 25)
	   && (c3 >= 13 && c3 <= 25) && (c4 >= 13 && c4 <= 25) && (c5 >= 13
								   && c5 <=
								   25))
      return true;
  else if ((c1 >= 26 && c1 <= 38) && (c2 >= 26 && c2 <= 38)
	   && (c3 >= 26 && c3 <= 38) && (c4 >= 26 && c4 <= 38) && (c5 >= 26
								   && c5 <=
								   38))
      return true;

  else if ((c1 >= 39 && c1 <= 51) && (c2 >= 39 && c2 <= 51)
	   && (c3 >= 39 && c3 <= 51) && (c4 >= 39 && c4 <= 51) && (c5 >= 39
								   && c5 <=
								   51))
      return true;
  return false;
}

bool
IsThreeOfAKind (int c1, int c2, int c3, int c4, int c5)
{

  c1 = c1 % 13;
  c2 = c2 % 13;
  c3 = c3 % 13;
  c4 = c4 % 13;
  c5 = c5 % 13;

  if (c1 == c2 && c2 == c3)
    return true;
  else if (c1 == c2 && c2 == c4)
    return true;
  else if (c1 == c2 && c2 == c5)
    return true;
  else if (c1 == c3 && c3 == c4)
    return true;
  else if (c1 == c3 && c3 == c5)
    return true;
  else if (c1 == c4 && c4 == c5)
    return true;
  else if (c2 == c3 && c3 == c4)
    return true;
  else if (c2 == c3 && c3 == c5)
    return true;
  else if (c2 == c4 && c4 == c5)
    return true;
  else if (c3 == c4 && c4 == c5)
    return true;
  return false;
}

bool
IsTwoPair (int c1, int c2, int c3, int c4, int c5)
{

  c1 = c1 % 13;
  c2 = c2 % 13;
  c3 = c3 % 13;
  c4 = c4 % 13;
  c5 = c5 % 13;

  if (c1 == c2 && (c3 == c4 || c4 == c5 || c3 == c5))
    return true;
  else if (c1 == c3 && (c2 == c4 || c4 == c5 || c2 == c5))
    return true;
  else if (c1 == c4 && (c2 == c3 || c3 == c5 || c2 == c5))
    return true;
  else if (c1 == c5 && (c2 == c3 || c3 == c4 || c2 == c4))
    return true;
  else if (c2 == c3 && (c1 == c4 || c1 == c5 || c4 == c5))
    return true;
  else if (c2 == c4 && (c1 == c3 || c3 == c5 || c1 == c5))
    return true;
  else if (c2 == c5 && (c1 == c3 || c3 == c4 || c1 == c4))
    return true;
  else if (c3 == c4 && (c1 == c2 || c2 == c5 || c1 == c5))
    return true;
  else if (c3 == c5 && (c1 == c2 || c2 == c4 || c1 == c4))
    return true;
  else if (c4 == c5 && (c1 == c2 || c2 == c3 || c1 == c3))
    return true;
  return false;
}

bool
IsOnePair (int c1, int c2, int c3, int c4, int c5)
{

  c1 = c1 % 13;
  c2 = c2 % 13;
  c3 = c3 % 13;
  c4 = c4 % 13;
  c5 = c5 % 13;

  if (c1 == c2 || c1 == c3 || c1 == c4 || c1 == c5 || c2 == c3 || c2 == c4
      || c2 == c5 || c3 == c4 || c3 == c5 || c4 == c5)
    return true;
  return false;
}

int
main ()
{
  int c1, c2, c3, c4, c5;
  DealHand (c1, c2, c3, c4, c5);
  PrintHand (c1, c2, c3, c4, c5);
  if (IsFourOfAKind (c1, c2, c3, c4, c5))
    cout << "four of a kind";
  else if (IsFullHouse (c1, c2, c3, c4, c5))
    cout << "full house";
  else if (IsFlush (c1, c2, c3, c4, c5))
    cout << "flush";
  else if (IsThreeOfAKind (c1, c2, c3, c4, c5))
    cout << "three of a kind";
  else if (IsTwoPair (c1, c2, c3, c4, c5))
    cout << "two pair";
  else if (IsOnePair (c1, c2, c3, c4, c5))
    cout << "one pair";
  else
    cout << "others";
  cout << endl;
  return 0;
}