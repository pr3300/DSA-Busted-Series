#include<iostream>
#include<math.h>
using namespace std;


int main() {

    int n;
    cin >> n;


    int ans  = 0;
    int i = 0;
    while(n != 0 ) {

        int bit  = n & 1;

        ans = (bit * pow(10, i) ) + ans;

        n = n >> 1;
        i++;

    }

    cout<<" Answer is " << ans << endl;
    return 0;
}
// in this code we also use the parity digit to get the answer
// for example
int num;
cin>>num;
int ans = 0;
int power = 1;
while(a>0){
    int paritydigit = a%2;
    ans+=paritydigit*power;
    power*=10;
    a/=2;

}

cout<<ans<<endl;
}
// in this code using parity digit we can convert our code desimal to binary with less code
