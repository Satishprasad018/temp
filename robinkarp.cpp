#include <iostream>
#include <string.h>

using namespace std;

const int d = 256; // Number of characters in the input alphabet

void rabinKarpSearch(const char* pattern, const char* text, int q)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int p = 0; // Hash value for the pattern
    int t = 0; // Hash value for the current window of text
    int h = 1;

    // Calculate the hash value of pattern and the first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Calculate h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Slide the pattern over the text one by one
    for (int i = 0; i <= n - m; i++) {
        // Check the hash values of current window of text and pattern.
        // If the hash values match, then only check for characters one by one.
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate the hash value for the next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // If t is negative, make it positive
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    const char* text = "ABCCDDAEFG";
    const char* pattern = "CDD";
    int q = 13; // A prime number

    rabinKarpSearch(pattern, text, q);

    return 0;
}
