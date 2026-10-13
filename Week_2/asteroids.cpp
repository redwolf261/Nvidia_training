#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main() {
  vector<int> asteroids;
  int n, value;
  cout << "enter number of elements in array: " << endl;
  cin >> n;
  if (n <= 0) {
    cout << "invalid";
    return 0;
  }
  cout << "enter the elements: " << endl;
  for (int i = 0; i < n; ++i) {
    cin >> value;
    asteroids.push_back(value);
  }
  vector<int> collisions;
  int current;
  for (int i = 0; i < n; ++i) {
    current = asteroids[i];
    bool alive = true;
    while (!collisions.empty() && alive && collisions.back() > 0 &&
           current < 0) {
      if (collisions.back() > abs(current)) {
        alive = false;
      } else if (collisions.back() < abs(current)) {
        collisions.pop_back();
      } else {
        collisions.pop_back();
        alive = false;
      }
    }
    if (alive) {
      collisions.push_back(current);
    }
  }
  cout << "answer" << endl;
  for (int i = 0; i < collisions.size(); ++i) {
    cout << collisions[i] << endl;
  }
  return 0;
}