#include "LinkedSortedList.hpp"
#include "ArraySortedList.hpp"
#include <iostream>

using std::cout;
using std::cerr;
using std::string;

// GetLength and GetEntry test
void print(SortedListInterface<int>* list) {
  for (int i = 1; i <= list->GetLength(); ++i)
      cout << list->GetEntry(i) << ',';
  cout << '\n';
}

int main() {
  // Create names
  string names[6] = { "Joe", "Bob", "Tom", "Ally", "Camille", "Karen" };
  int numbers[6] = {1, 2, 3, 4, 5, 6 };
  // Default constructor
  SortedListInterface<int>* list = new LinkedSortedList<int>();
  //SortedListInterface<string>* list = new ArraySortedList<string>();

  // Insert into list
  for (int i = 0; i < 6; ++i)
    list->InsertSorted(numbers[i]);

  cout << "GetLength = " << list->GetLength() << '\n';

  try {
    cout << "GetEntry Precondition Test: " << list->GetEntry(0) << '\n';
  }
  catch (PrecondViolatedExcept e) {
    cerr << e.what() << '\n';
  }

  // IsEmpty test
  if (!list->IsEmpty())
    print(list);
  // GetPosition test
//  cout << "Tom @ " << list->GetPosition("Tom") << '\n';
  // Remove test
//  cout << "Removing Tom...\n";
//  list->RemoveSorted("Tom");
//  cout << "Removing Camille...\n";
//  list->RemoveSorted("Camille");
//  print(list);
  // Copy constructor test
  cout << "Copying list and printing...\n";
  SortedListInterface<int>* copy = list;
  print(copy);
  // Clear test
  cout << "Clearing both lists...\n";
  list->Clear();
  cout << "Printing list: ";
  print(list);
  copy->Clear();
  cout << "Printing copy: ";
  print(copy);

  return 0;
}
