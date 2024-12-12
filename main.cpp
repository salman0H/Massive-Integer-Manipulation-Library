#include <iostream>
#include <string.h>
#include <string>
using namespace std;
class hugeint
{
    friend ostream &operator <<(ostream &out,hugeint &obj);
public:
        hugeint(string _number = "")
        {
            for(int i = 49; i>=0; i--)
            {
                number[i] = 0;
            }
            for(int j=49, i = _number.size(); i>=0; j--,i--)
            {
                number[j] = _number[i] - 48;
            }

        }
        /*~hugeint()
        {
            cout << "\nnumber is destructed\n";
        }*/
        int digit()
        {

            for(int i=0; i<50; i++)
            {
                if(number[i] != 0)
                {
                    return 49 - i;
                }
            }

        }
        hugeint operator ++(int)
        {
            hugeint temp = *this;
            number[49]++;
            for(int i = 49; i>=temp.digit(); i--)
            {
                if(number[i] > 9)
                {
                    number[i-1]++;
                    number[i] = 0;
                }
            }
            return temp;
        }
        hugeint operator +(hugeint &obj)
        {
            hugeint temp;
            temp.number[49] = 0;
            for(int i = 49; i>=obj.digit(); i--)
            {
                temp.number[i] = number[i] + obj.number[i] + temp.number[i];
                if(temp.number[i] > 9)
                {
                    temp.number[i] -= 10;
                    temp.number[i-1]++;
                }
            }
            return temp;
        }
        static int getmaxdigits()
        {
            return maxdigit;
        }
private:
        int number[50];
        static const int maxdigit = 50;
    };
    ostream &operator <<(ostream &out,hugeint &obj)
        {
            for(int i=49 - obj.digit(); i < 49; i++)
            {
                out <<obj.number[i];
            }
            return out;
        }
    int main()
    {
        /*hugeint num1("456360000"), num2("999999999"), num3;
        hugeint num4;
        num4 = num2++;
        num3 = num1 + num2;
        cout << num1 << '-' << num4 << '-' << num3;*/


        for(;;)
        {
            cout << "\nyou can enter number for do some test.\n";
            cout << "enter two number : \n";
            string number1;
            string number2;
            cin >> number1;
            cin >> number2;
            hugeint num1(number1);
            hugeint num2(number2);

            cout <<"\noperator ++ for num1 : ";
            hugeint num3 = num1++;
            cout<<num3<<endl;
            cout<<num1<<" after ++ number 1.\n";

            cout <<"\noperator ++ for num2 : ";
            num3 = num2++;
            cout << num3<<endl;
            cout<<num2<<" after ++ number 2.\n";

            num3 = num1 + num2;
            cout << "\nnum1 + num2 = "<<num3;

            cout << "\nsize of number 1 is : "<<num1.digit();

            cout << "\nsize of number 2 is : "<<num2.digit();

            int out;
            cout << "\n\"enter 0 for exit\"\n";
            cin >> out;
            if(out == 0) break;
        }
        return 0;
  }
