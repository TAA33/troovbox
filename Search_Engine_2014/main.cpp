#include "main.h"

using namespace std;

int main()
{
    string url ("www.google.com");
    Code_Sources *Code1 = new Code_Sources(url);

    delete Code1;
    return 0;
}
