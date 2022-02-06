#include <iostream>
#include <algorithm>
#include "timer.h"
int gcd(int a, int b)
{
  //This is not actually a GCD function
  //if((a%2 == 0 && b%2 == 0) || (a%3 == 0 && b%3 == 0))
  //return 2;
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}

  bool canBeSimplified(int num, int den) {
    if(gcd(num, den) >1)
      return true;
    return false;
  }

  

  bool isPrime(int number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;

}

int main() {

  timer t;
  t.start();

  //int n  = 100000000;
  int n = 1000;
  int greenPoints = 0;
  
int distance;
  for(int y = 0; y < n+1; y++) {
    distance = y-1;
    if(!isPrime(y)) {
      // If it is not prime
      for(int x = 1; x < y+1; x++) {
	if(y % 2 == 0)
		if(x%2 == 0 && y%2 ==0)
			greenPoints+=1;
	else if(canBeSimplified(x,distance+1))
          greenPoints +=1;
      }

    }
    else {
      // if it is prime
      greenPoints++;

    }
  
  }

    std::cout << "greenPoints: " << greenPoints*6 << std::endl;
    t.stop();
    //std::cout << t << std::endl;
    std::cout << t.getTime() << std::endl;


  
  }

