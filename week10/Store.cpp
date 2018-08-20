#include<iostream>
#include "Store.hpp"
#include <string>

#include <vector>

/**********************************
name: string lowerCase(string s)

**********************************/
std::string lowerCase(std::string s)
{
    int length = s.length();
    for (int size=0; size < length; size++)
    {
        s[size] = tolower(s[size]);
    }
    return s;
}

/**********************************
name: Store::addProduct
Description: Add product into inventory
**********************************/
void Store::addProduct(Product* p)
{
     inventory.push_back(p);
}


/**********************************
name: Store::addMember
Description: Add customer to Members
**********************************/
void Store::addMember(Customer* c)
{
     members.push_back(c);
}


/**********************************
name: Store::getProductFromID
Description: Get product from the inventory list
**********************************/
Product* Store::getProductFromID(std::string ID)
{
    for(int size=0; size < inventory.size(); size++)
    {
        if(inventory[size]->getIdCode() == ID)
        {
            return inventory[size];
        }
    }
     return NULL;
}


/**********************************
name: Store::getMemberFormID
Description: Get the customer from Members using the ID
**********************************/
Customer* Store::getMemberFromID(std::string ID)
{
    for(int size=0; size < members.size(); size++)
    {
        if(members[size]->getAccountID()== ID)
        {
            return members[size];
        }
    }
    return NULL;
}


/**********************************
name: Store::productSearch
Description: search for the product by the characters
**********************************/
void Store::productSearch(std::string str)
{
    str = lowerCase(str);
    for(int size=0; size < inventory.size();size++)
    {
        std::string lowerCaseTitle = lowerCase(inventory[size] -> getTitle());
        std::string lowerCaseDescription = lowerCase(inventory[size] -> getDescription());
        if((lowerCaseTitle.find(str) != std::string::npos)||(lowerCaseDescription.find(str)!=std::string::npos))
        {
            std::cout<<inventory[size]->getTitle()<<std::endl;
            std::cout<<"ID code:"<<inventory[size]-> getIdCode()<<std::endl;
            std::cout<<"Price: $"<<inventory[size]-> getPrice()<<std::endl;
            std::cout<<inventory[size]-> getDescription()<<std::endl << std::endl;
        }
    }
}



/**********************************
name: Store::addProductToMemberCart
Description: Add the product to the customer's cart
**********************************/
void Store::addProductToMemberCart(std::string pID, std::string mID)
{
   Customer *customerPtr = getMemberFromID(mID);
   Product *productPtr = getProductFromID(pID);
   bool customerFound = false;
   bool productFound = false;

   if(!productPtr)
   {
       std::cout << "Product #" << pID <<" not found." << std::endl;
   }
   else
   {
    customerFound = true;
   }
   
   if(!customerPtr)
   {
    std::cout << "Member #" << mID <<" not found." << std::endl;
   }
   else
   { 
    productFound = true;
   }

   if (customerFound && productFound)
   {
        if(productPtr->getQuantityAvailable() > 0)
        {
           customerPtr->addProductToCart(pID);
        }
        else
        {
           std::cout << "Sorry, product #" << pID << " is currently out of stock." << std::endl;
        }
    }
};




/**********************************
name: Store::checkOutMember
Description: Total out the the customer's cart depending on if shipping is included or not
**********************************/
void Store::checkOutMember(std::string mID)
{
   Customer *customerCart = getMemberFromID(mID);
   if(customerCart==NULL)
   {
       std::cout << "Member "<<mID <<" not found."<<std::endl;
   }
   else
   {
       std::vector<std::string> cart = customerCart->getCart();
       double subTotal = 0;
       int totalItems = 0;

       for(int size=0;size<cart.size();size++)
       {
           Product *prod = getProductFromID(cart[size]);

           if(prod->getQuantityAvailable()>0)
           {
               std::cout <<prod->getTitle()<<" - $"<<prod->getPrice()<<std::endl;
               subTotal += prod->getPrice();
               totalItems++;
               prod->decreaseQuantity();
           }
           else
           {
               std::cout << "Sorry, product "<< cart[size] <<", "<< prod->getTitle()<<" is no longer available."<<std::endl;
           }
       }

       if(totalItems==0)
       {
           std::cout << "There are no items in the cart."<<std::endl <<std::endl;
           return;
       }

       double shippingCost = 0.0;
        if(customerCart->isPremiumMember()) 
        {
            shippingCost = 0;
        }
        else
        {
            shippingCost = 0.07*subTotal;
        }

       double final = subTotal + shippingCost;

       std::cout << "Subtotal: $"<< subTotal << std::endl <<"Shipping Cost: $"<<shippingCost<< std::endl <<"Total: $"<< final <<std::endl << std::endl;
   }

   customerCart-> emptyCart();
}

#include "Store.hpp"
#include <iostream>
#include "string"

using namespace std;

int main()
{
     Customer custom1("Stephen Curry","1",false);     //customer 1
     Customer custom2("Lebron James","2", true);      //customer 2

     Product item1("123","red blender","Sturdy blender perfect for making smoothies and sauces",350,1);    //product 1
     Product item2("456","hot air ballon","Fly into the sky in your own ballon - comes in red, blue or chartreuse",750,3);   //product 2

     Store supreme;                                 //Store object called Supreme

     supreme.addProduct(&item1);                    //Adding product P1 to the store
     supreme.addProduct(&item2);                    //Adding product P2 to the store
     supreme.addMember(&custom1);                   //Adding customer1 to the store
     supreme.addMember(&custom2);                   //Adding customer2 to the store

     //Add product to member cart
     supreme.addProductToMemberCart("123","1");     //Add item1 to the Customer's shopping cart
     supreme.addProductToMemberCart("123","2");     //Add item2 to the Customer's shopping cart
     
     supreme.productSearch("red");                  //Display the description of product being searched
     supreme.productSearch("hot");

     supreme.checkOutMember("1");                   //Checking out the customer
     supreme.checkOutMember("2");
    
     return 0;

}