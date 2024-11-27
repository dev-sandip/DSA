#include <iostream>
#include <string>
#define MAX 100
using namespace std;

struct User
{
  int id;
  string name;
  string email;
  string password;
};

class Stack
{
private:
  int tos;
  User data[MAX];

public:
  Stack() : tos(-1) {}

  bool isEmpty()
  {
    return tos == -1;
  }

  bool isFull()
  {
    return tos == MAX - 1;
  }

  void push(const User &user)
  {
    if (isFull())
    {
      cout << "Stack overflow\n";
      return;
    }
    data[++tos] = user;
    cout << "User added to the stack.\n";
  }

  void pop()
  {
    if (isEmpty())
    {
      cout << "Stack underflow\n";
      return;
    }
    cout << "Popped user: " << data[tos].name << endl;
    tos--;
  }

  User peek()
  {
    if (isEmpty())
    {
      cout << "Stack is empty\n";
      return User();
    }
    return data[tos];
  }

  void display()
  {
    if (isEmpty())
    {
      cout << "Stack is empty\n";
      return;
    }
    cout << "Stack contents:\n";
    for (int i = tos; i >= 0; i--)
    {
      cout << "ID: " << data[i].id << endl
           << ", Name: " << data[i].name << endl
           << ", Email: " << data[i].email << endl;
    }
  }
};

int main()
{
  Stack stack;
  int choice;
  User user;

  do
  {
    cout << "\nMenu:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter user details:\n";
      cout << "ID: ";
      cin >> user.id;
      cin.ignore();
      cout << "Name: ";
      getline(cin, user.name);
      cout << "Email: ";
      getline(cin, user.email);
      cout << "Password: ";
      getline(cin, user.password);
      stack.push(user);
      break;

    case 2:
      stack.pop();
      break;

    case 3:
      user = stack.peek();
      if (!stack.isEmpty())
      {
        cout << "Top User -> ID: " << user.id << ", Name: " << user.name << ", Email: " << user.email << endl;
      }
      break;

    case 4:
      stack.display();
      break;

    case 5:
      cout << "Exiting...\n";
      break;

    default:
      cout << "Invalid choice! Try again.\n";
    }
  } while (choice != 5);

  return 0;
}
