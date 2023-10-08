#include<iostream>
#include<string>
#include <string.h>
#include<vector>
#include <iomanip>
#include <algorithm>

template <typename T> class Item{
    public:
        T name;
        T expiration;
        T category;
        int quantity;

        Item(T n, T e, T c, int q){
            name = n;
            expiration = e;
            category = c;
            quantity = q;
        }
};
template<typename T> class Inventory{
    public:
        // Write Your code 
        
        std::vector<Item<std::string>> items{};
        void addNewItem(Item<std::string> new_item)
        {
            if(items.size()==0)
            {
               items.push_back(new_item);

            }
            else{
            for(int i=0; i<items.size();i++)
            {
            if (items[i].name == new_item.name) 
            {
                std::cout << "Item is already present in inventory"<< ": " << new_item.name << std::endl;
                break;
            }
            else if (i == items.size()-1)
            {
                items.push_back(new_item);
                break;
            }
            else
            {
                continue;

            }
            }
            }
        }
        void increaseQuantity(T item_name, int quantity_)
        {
            for(int i=0; i<items.size();i++)
            {
                if(item_name == items[i].name)
                {
                    items[i].quantity = quantity_;
                }

                else
                {
                    continue;
                }
            }
        }

        void updateItem(T item_name, T expiration_, T category_, int quantity_)
        {
            for(int i=0; i<items.size();i++)
            {
                bool does_exist = false;
                if(item_name == items[i].name)
                {
                    does_exist = true;
                    items[i].quantity = quantity_;
                    items[i].expiration = expiration_;
                    items[i].category = category_;
                    break;
                }
                else if(does_exist == false && i == (items.size()-1))
                {
                    throw std::invalid_argument("Item not found");
                    continue;
                }
                else
                {
                    continue;
                }
            }
        }
              
        void removeItem(T item_name)
        {
            for(int i=0; i<items.size();i++)
            {
                bool does_exist = false;
                if(item_name == items[i].name)
                {
                    does_exist = true;
                    items.erase(items.begin()+i);
                    break;
                }
                else if(does_exist == false && i == (items.size()-1))
                {
                    throw std::invalid_argument("Item not found");
                    continue;
                }
                else
                {
                    continue;
                }
            }
        }
        void Total()
        {
            int total_items = 0;
            for(int i=0; i<items.size();i++)
            {
                
                total_items = total_items + items[i].quantity;
            }
            std::cout<< "\nThere are a total of: " << total_items << " items" << std::endl;
        }

        void searchItem(T item_name)
        {
            for(int i=0; i<items.size();i++)
            {
                bool does_exist = false;
                if(item_name == items[i].name)
                {
                    does_exist = true;
                    std::cout << "\nFound " << items[i].quantity << " "<< items[i].name << "!" << std::endl;
                    break;
                }
                else if(does_exist == false && i == (items.size()-1))
                {
                    throw std::invalid_argument("Item not found");
                    continue;
                }
                else
                {
                    continue;
                }
            }
        }

        void displayItems(){
            std::cout<<"-------Inventory-------"<< std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Expiration"<<std::setw(15)<<"Quantity"<<std::setw(10)<<"Category"<<std::endl;
            for(int i=0; i<items.size();i++){
                std::cout<<std::left << std::setw(20)<<items[i].name<<std::setw(15)<<items[i].expiration<<std::setw(15)<<items[i].quantity<<std::setw(15)<<items[i].category<<std::endl;
            }
        }
        
};
template<typename T>class Appointment{
    public: 
        T c_name;
        T ap_date;
        T ap_time;
        T CWID;
        Appointment(T n, T d, T t, T cw){
            c_name = n;
            ap_date = d;
            ap_time = t;
            CWID = cw; 
        }
};
template<typename T>class AppointmentSystem{
        public:
        // Write Your code 
        std::vector<Appointment<std::string>> ap{};

           void schedule(Appointment<std::string> new_ap)
        {
            if(ap.size()==0)
            {
               ap.push_back(new_ap);

            }
            else{
            for(int i=0; i<ap.size();i++)
            {
            if (ap[i].CWID == new_ap.CWID) 
            {
                std::cout << "You already have an appointment!!!"<< std::endl;
                break;
            }
            else if (i == ap.size()-1)
            {
                ap.push_back(new_ap);
                break;
            }
            else
            {
                continue;

            }
            }
            }
        }
        void Total_appointments(T date, T time)
        {
            int total_ap = 0;
            for(int i=0; i<ap.size();i++)
            {
                if (ap[i].ap_date == date && ap[i].ap_time == time)
                {
                total_ap = total_ap + 1;
                }
                else 
                {
                    continue;
                }
            }
            std::cout<< "\nThere are a total of: " << total_ap << " appointments at " << date << " and " << time << std::endl;
        }
        void removeRecent()
        {
                if(ap.size() == 0)
                {
                    std::cout << "There are no appointments to remove." << std::endl;
                    
                }
                else
                {
                    ap.pop_back();
                }
        }
        void display(){
            std::cout<<"-------Appointments-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Date"<<std::setw(15)<<"Time"<<std::setw(15)<<"CWID"<<std::endl;
            for(int i=0; i<ap.size();i++){
                std::cout<<std::left << std::setw(20)<<ap[i].c_name<<std::setw(15)<<ap[i].ap_date<<std::setw(15)<<ap[i].ap_time<<std::setw(15)<<ap[i].CWID<<std::endl;
            }
        }
};
int main(){
    Inventory<std::string> i1;
    Item<std::string> I1("Protien Bar","05/09/2023","Snacks",4);
    i1.addNewItem(I1);
    Item<std::string> I2("Milk","05/12/2023","Regular",2);
    i1.addNewItem(I2);
    Item<std::string> I3("Cerels","09/12/2023","Snacks",5);
    i1.addNewItem(I3);
    i1.displayItems();
    i1.updateItem("Milk","09/24/2023","Regular",3);
    i1.displayItems();
    i1.increaseQuantity("Cerels",10);
    i1.displayItems();
    try{
        i1.updateItem("Milk","09/12/2023","Snacks",3);
    }
    catch(const char* msg){
        std::cout <<msg << std::endl;
    }
    i1.Total();
    try{
        i1.removeItem("Milk");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    i1.displayItems();
   try{
        i1.searchItem("Cerels");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    Appointment<std::string> a1("John Bob","09/12/2023","9:30AM","889456723");
    Appointment<std::string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
    Appointment<std::string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
    Appointment<std::string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");
    AppointmentSystem<std::string> s1;
    s1.schedule(a1);
    s1.schedule(a2);
    s1.schedule(a3);
    s1.schedule(a4);
    s1.Total_appointments("09/12/2023","12:00PM");
    Appointment<std::string> a5("Chris Lynn","09/12/2023","12:00PM","879455714");
    s1.schedule(a4);
    s1.removeRecent();
    s1.display();
    
   

    }

