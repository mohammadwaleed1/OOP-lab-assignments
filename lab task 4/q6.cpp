#include <iostream>
using namespace std;
class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double priceperitem;

public:
	Invoice(){
	partNumber="123";
	partDescription="ABCD";
	quantity=5;
	priceperitem=2.00;
	}
	
    Invoice(string partNum,string partDesc,int qty,double price){
	partNumber=partNum;
	partDescription=partDesc;
	if(qty<0) quantity=0;
	else quantity=qty;
	if(price<0)priceperitem=0.00;
	else priceperitem=price;
    }

    double getInvoiceAmount() const {
        return quantity * priceperitem;
    }

    string getPartNumber(){ return partNumber; }
    string getPartDescription(){ return partDescription; }
    int getQuantity(){ return quantity; }
    double getpriceperitem(){ return priceperitem; }

};
int main() {

    Invoice invoice("1234", "Hammer", 5, 10.00);
    
    cout << "Part Number: " << invoice.getPartNumber() << std::endl;
    cout << "Part Description: " << invoice.getPartDescription() << std::endl;
    cout << "Quantity: " << invoice.getQuantity() << std::endl;
    cout << "Price Per Item: " << invoice.getpriceperitem() << std::endl;
    cout << "Total Invoice Amount: " << invoice.getInvoiceAmount() << std::endl;

    return 0;
}
