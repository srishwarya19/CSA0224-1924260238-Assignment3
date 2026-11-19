#include <stdio.h>
#include <ctype.h>

int word_count(const char s[])
{
    int i, count = 0, inside = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (isspace((unsigned char)s[i]))
            inside = 0;
        else if (inside == 0) {
            count++;
            inside = 1;
        }
    }

    return count;
}

int is_palindrome(const char s[])
{
    int left = 0, right = 0;

    while (s[right] != '\0')
        right++;

    right--;

    while (left < right) {
        while (left < right &&
               !isalpha((unsigned char)s[left]))
            left++;

        while (left < right &&
               !isalpha((unsigned char)s[right]))
            right--;

        if (tolower((unsigned char)s[left]) !=
            tolower((unsigned char)s[right]))
            return 0;

        left++;
        right--;
    }

    return 1;
}

void uppercase(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        s[i] = toupper((unsigned char)s[i]);
}

void reverse(char s[])
{
    int i = 0, j = 0;
    char temp;

    while (s[j] != '\0')
        j++;

    j--;

    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }
}

int main()
{
    char s1[] = "Meet at the library";
    char s2[] = "HELLO";

    printf("Words: %d\n",
           word_count(" Meet at the library at 5 PM "));

    printf("%d %d\n",
           is_palindrome("Madam, I'm Adam"),
           is_palindrome("Hello"));

    uppercase(s1);
    printf("Uppercase: %s\n", s1);

    reverse(s2);
    printf("Reverse: %s\n", s2);

    return 0;
}
