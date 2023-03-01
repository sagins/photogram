
#include "TestView.h"

void TestView::showMenu(int& choice)
{
  int numOptions = 5;

  cout << endl;
  cout << "Which test would you like to run?"<< endl;
  cout << "  (1) Test Photo" << endl;
  cout << "  (2) Test Album" << endl;
  cout << "  (3) Test AlbumArray" << endl;
  cout << "  (4) Test PhotoGram" << endl;
  cout << "  (5) Test Client" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}