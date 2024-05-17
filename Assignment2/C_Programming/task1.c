#include<stdio.h>

struct Item{
    int quantity;
    int price;
    
};
struct Number{
    int num;

};


int main(){
    struct Item i1,i2,i3;  // struct(like objects[i1,i2,i3] accessing instance variable from a class)
    struct Number n;
    int total;
    float average;


    printf("Quantity of Paratha: ");
    scanf("%d",&i1.quantity);
    printf("unit price: ");
    scanf("%d",&i1.price);

    printf("Quantity of vegetable: ");
    scanf("%d",&i2.quantity);
    printf("unit price: ");
    scanf("%d",&i2.price);

    printf("Quantity of mineral water: ");
    scanf("%d",&i3.quantity);
    printf("unit price: ");
    scanf("%d",&i3.price);
    printf("Number of people: ");
    scanf("%d",&n.num);
    total=(i1.price*i1.quantity)+(i2.price*i2.quantity)+(i3.price*i3.quantity);
    average=total/n.num;
    printf("Individual people will pay: %f tk", average );
    return 0;
}




