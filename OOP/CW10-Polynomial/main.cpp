#include <iostream>
#include <string>

using namespace std;
  
class Demo {
    public:
        Demo(){
            for (int k = 0;k < 1000;k++)
                i[k] = 0;
        }
        friend istream& operator>>(istream& s, Demo& a){
            s >> a.num;
            for (int k = 0;k < a.num;k++){
                s >> a.pos >> a.val;
                a.i[a.pos] = a.val;
            }
            return s;
        };
        
        friend ostream& operator<<(ostream &s, Demo &a){
            for (int k = 999;k >= 0;k--){
                if (a.i[k] != 0){
                    cout << a.i[k] << "x^" << k;
                    cout << "+";
                }
            }
            return s;
        };

        Demo& operator+=(Demo &p){
            for (int k = 0;k < 1000;k++){
                i[k] += p.i[k];
            }
            return *this;
        };

    private:
        int i[1000];
        int num,pos,val;
    };

int main() {
    Demo demo1,demo2;
    cin >> demo1 >> demo2;
    demo1 += demo2;
    cout << demo1;
    return 0;
}