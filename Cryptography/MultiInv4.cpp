#include <iostream>
#include <utility>
using namespace std;

/* Return the gcd of a and b, along with the pair x and y such that 
   ax + by = gcd(a, b) */
pair<int, pair<int, int>> extendedEuclid(int a, int b) 
{
    int x = 1, y = 0;
    int xLast = 0, yLast = 1;
    int q, r, m, n;
    
    while (a != 0) 
    {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x; 
        yLast = y;
        x = m; 
        y = n;
        b = a; 
        a = r;
    }
    
    return make_pair(b, make_pair(xLast, yLast));
}

/* Find the modular multiplicative inverse of a under modulo m */
int modInverse(int a, int m) 
{
    pair<int, pair<int, int>> result = extendedEuclid(a, m);
    int gcd = result.first;
    int x = result.second.first;
    
    // Check if gcd is 1
    if (gcd != 1) 
    {
        cout << "Modular inverse does not exist." << endl;
        return -1;  // Inverse does not exist
    }
    
    // Ensure positive result
    return (x % m + m) % m;
}

// Main function
int main()
{
    int a, m;
    
    cout << "Enter number to find modular multiplicative inverse: ";
    cin >> a;
    
    cout << "Enter Modular Value: ";
    cin >> m;
    
    int inverse = modInverse(a, m);
    
    if (inverse != -1)
    {
        cout << "Multiplicative inverse is: " << inverse << endl;
    }

    return 0;
}
