#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;
ifstream f("data.in");

class Item
{
    public:
    char productName[30];
    float price;
    int stock;

};
class Money{
public:
char currency[30];
int currencyVal;

};


void prinNameandPrice(Item N, string currencyType, int count ){
cout <<count<<":"<<" "<< N.productName<<" "<<currencyType<<N.price<< "\n";

cout <<"\n";

}

int main()

{
    cout<<fixed<<showpoint<<setprecision(2);



    string currencyType;
    Item item[6];
    int count=1, stock, decision;
    char currency[100],itemSelection,name[100];
    bool validItem;
    float num, pay,price,cost;
    int currencyVal;
    f>>currencyType;


      for (int i=0; i<6; ++i){
      f>>name;
      strcpy(item[i].productName, name);
    }
      for (int i=0; i<6; ++i){
      f>>price;
      item[i].price=price;

    }
     for (int i=0; i<6; ++i){
      f>>stock;
      item[i].stock=stock;
    }
    Money money[6];
     for (int i=0; i<6; ++i){
      f>>currency;
      strcpy(money[i].currency, currency);
    }
     for (int i=0; i<6; ++i){
      f>>currencyVal;
      money[i].currencyVal=currencyVal;
    }


    do{
      for (int i=0; i<6; ++i){
      prinNameandPrice(item[i],currencyType, count);
      count=count+1;

    }
    count=1;
    cout<<"\n";
    cout<<"Enter 1-6 "<<endl;
    cout<<"\n";
    cout<<"Enter 7 to stop the machine"<<endl<<endl;
    cin>>itemSelection;
int product= itemSelection-'0';
  switch(itemSelection)
    {
        case'1':
        case'2':
        case'3':
        case'4':
        case'5':
        case'6': validItem= true;
        break;
        default: validItem= false;
    }
    if(validItem==true){
        cout<<"How many items do you want?"<<endl;
        cin>>num;
    }
if (validItem)
{

    cost=num*item[product-1].price;
    cout<<"Total cost is: "<<currencyType<<cost<<endl;

}
if(validItem==true){
        cout<<"\n";
        cout<<"\n";
        cout<<"Enter the total payment"<<endl;
        cin>>pay;
        float x= pay-cost;
        int diff= item[product-1].stock-num;
        if(validItem==true){
        cout<<"If you want to proceed then press 1 and to cancel press any other number"<<endl;
        cin>>decision;


        if(decision==1){


        if(x<0){

            cout<<"Invalid money entry, try again"<<endl;
        }
        else if(x>0 && diff>=0)

        {   cout<<"\n";
            cout<<"Collect your food item from below"<<endl;
            cout<<"\n";
            cout<<"Return Change: "<<currencyType<<x<<endl;
            cout<<"\n";

            float ch=x*100;
            int change=ch;

            for(int i=0; i<6; ++i ){
                int typeNumber= change/money[5-i].currencyVal;
                cout<<"Returning "<<typeNumber<<" "<<money[5-i].currency<<endl;
                change=change-(typeNumber*money[5-i].currencyVal);
                cout<<"\n";

            }

            }
            else {cout<<"Oops! we ran out of the product you are looking for, please try a different product"<<endl;
            num=0;}

        }
        else

        {   cout<<"\n";
            cout<<"Thank you"<<endl;
            cout<<"\n";
            cout<<"Return Change: "<<currencyType<<pay<<endl;
            cout<<"\n";

            float ch=pay*100;
            int change=ch;
             for(int i=0; i<6; ++i ){
                int typeNumber= change/money[5-i].currencyVal;
                cout<<"Returning "<<typeNumber<<" "<<money[5-i].currency<<endl;
                change=change-(typeNumber*money[5-i].currencyVal);
                cout<<"\n";
             num=0;
            }

            }
    }

    }

item[product-1].stock=item[product-1].stock-num;

} while (itemSelection!='7');


    return 0;
}
