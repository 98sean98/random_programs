#include <iostream>
using namespace std;

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void getCardCount(int input[], int inputSize, int cardCount[]) {
  int cards[5] = {-1};
  int nextCardIndex = 0;

  for (int i = 0; i < inputSize; i++) {
    int card = input[i];
    for (int j = 0; j < nextCardIndex + 1; j++) {
      if (cards[j] == card) {
        cardCount[j]++;
        break;
      } else if (j == nextCardIndex) {
        cards[nextCardIndex] = card;
        cardCount[nextCardIndex] = 1;
        nextCardIndex++;
        break;
      }
    }
  }
}

bool is3K(int cardCount[]) {
  int firstSet = cardCount[0];
  int secondSet = cardCount[1];
  bool combo1 = firstSet == 2 && secondSet == 3;
  bool combo2 = firstSet == 3 && secondSet == 2;
  return (combo1 || combo2);
}

int main () {
  int input[] = {2,3,3,2,4};

  int cardCount[5] = {-1};
  getCardCount(input, 5, cardCount);
  printArray(cardCount, 5);

  cout << is3K(cardCount) << endl;
}
