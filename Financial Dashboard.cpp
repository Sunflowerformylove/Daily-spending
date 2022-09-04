#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <algorithm>
using namespace std;

struct financial{
    string name;
    string tag;
    string priority;
    string id;
    int price;
    int quantity;
    long long totalValue;
    int position;
};
void input_items(financial matter[], int &size, bool &input_check);
void output_items(financial matter[], int size, bool input_check);
void export_files(financial matter[], int size, bool input_check);
void raw_data(financial matter[], int size, bool input_check);
void load_file(financial matter[], int &size, bool &input_check);
void search_by_name(financial matter[], int size);
void search_by_tag(financial matter[], int size);
void search_by_priority(financial matter[], int size);
void search_by_id(financial matter[], int size);
void sort_by_cost(financial matter[], int size);
void result(financial matter[], int size, int budget_daily);
void add_items(financial matter[], int &size);
void update_by_id(financial matter[], int size);
void delete_by_id(financial matter[], int &size, bool &input_check);
void countdown(){
    cout << "Thank your using my software UwU" << endl;
    cout << "Exiting..." << endl;
    for(int i = 5; i >= 0; i--){
        cout << i << endl;
        Sleep(1000);
    }
}

int main(){
    int mode;
    int size;
    financial matter[size];
    int budget_daily;
    bool input_check = false;
    cout << "Welcome to the Financial Dashboard " << endl;
    cout << "Press any key to continue..." << endl;
    getch();
    system("cls");
    cout << "Enter daily budget: " << endl;
    cin >> budget_daily;
    repeat_choosing:
    cout << "Press any key to continue..." << endl;
    getch();
    system("cls");
    cout << "Choose your service!" << endl
         << "1. Input purchased items/services." << endl
         << "2. Output purchased items/services." << endl
         << "3. Load data." << endl
         << "4. Save data(.txt)." << endl
         << "5. Export financial report(.txt/.docx)." << endl
         << "6. Search by name." << endl
         << "7. Search by tag." << endl
         << "8. Search by priority." << endl
         << "9. Search by ID." << endl
         << "10. Sort by value/log order." << endl 
         << "11. Calculate daily spending" << endl //Average, median,total, percent base on budget 
         << "12. Update list of items/services by ID." << endl
         << "13. Remove items/services from list." << endl
         << "14. Exit" << endl;
    cin >> mode;
    switch(mode){
        case 1:
        if(!input_check){
            input_items(matter,size,input_check);
            goto repeat_choosing;
            break;
        }
        else{
            add_items(matter,size);
            goto repeat_choosing;
            break;
        }
        case 2:
            if(!input_check){
                cout << "No data in database!" << endl;
                goto repeat_choosing;
                break;
            }
            else{
                output_items(matter,size,input_check);
                goto repeat_choosing;
                break;
            }
        case 3:
            if(input_check){
                cout << "Database exists! Please add/remove data or active a new session." << endl;
                goto repeat_choosing;
                break;
            }
            else{
                load_file(matter,size,input_check);
                goto repeat_choosing;
                break;
            }
        case 4:
            if(input_check){
                raw_data(matter,size,input_check);
                goto repeat_choosing;
                break;
            }
            else{
                cout << "No data in database!" << endl;
                goto repeat_choosing;
                break;
            }
        case 5:
            if(input_check){
                export_files(matter,size,input_check);
                goto repeat_choosing;
                break;
            }
            else{
                cout << "No data in database!" << endl;
                goto repeat_choosing;
                break;
            }
        case 6:
            if(input_check){
                search_by_name(matter,size);
                goto repeat_choosing;
                break;
            }
            else{
                cout << "No data in database!" << endl;
                goto repeat_choosing;
                break;
            }
        case 7:
            if(input_check){
                search_by_tag(matter,size);
                goto repeat_choosing;
                break;
            }
            else{
                cout << "No data in database!" << endl;
                goto repeat_choosing;
                break;
            }
        case 8:
            if(input_check){
                search_by_priority(matter,size);
                goto repeat_choosing;
                break;
            }
            else{
                cout << "No data in database!" << endl;
                goto repeat_choosing;
                break;
            }
        case 9: 
            if(input_check){
                search_by_id(matter,size);
                goto repeat_choosing;
                break;
            }
            else{
                cout << "No data in database!" << endl;
                goto repeat_choosing;
                break;
            }
        case 10:
            if(input_check){
                sort_by_cost(matter,size);
                goto repeat_choosing;
                break;
            }
            else{
                cout << "No data in database!" << endl;
                goto repeat_choosing;
                break;
            }
        case 11:
            if(input_check){
                result(matter,size,budget_daily);
                goto repeat_choosing;
                break;
            }
            else{
                cout << "No data in database!" << endl;
                goto repeat_choosing;
                break;
            }
        case 12:
            if(input_check){
                update_by_id(matter,size);
                goto repeat_choosing;
                break;
            }
            else{
                cout << "No data in database!" << endl;
                goto repeat_choosing;
                break;
            }
        case 13:
            if(input_check){
                delete_by_id(matter,size,input_check);
                goto repeat_choosing;
                break;
            }
            else{
                cout << "No data in database!" << endl;
                goto repeat_choosing;
                break;
            }
        case 14:
            countdown();
            break;
        default:
            cout << "Invalid input!" << endl;
            goto repeat_choosing;
            break;
        }
return 0;
}

void input_items(financial matter[], int &size, bool &input_check){
    cout << "Enter the number of items/services: ";
    cin >> size;
    for(int i = 0; i < size; i++){
    matter[i].position = i + 1;
    cout << "Enter item/service #" << i + 1 << "'s name: " << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    getline(cin, matter[i].name);
    repeat_price:
    cout << "Enter item/service #" << i + 1 << "'s price: " << endl;
    cin >> matter[i].price;
    if(matter[i].price < 0){
        cout << "Invalid input!" << endl;
        goto repeat_price;
    }
    repeat_quant:
    cout << "Enter item/service #" << i + 1 << "'s quantity: " << endl;
    cin >> matter[i].quantity;
    if(matter[i].quantity <= 0){
        cout << "Invalid input!" << endl;
        goto repeat_quant;
    }
    cout << "Enter item/service #" << i + 1 << "'s priority(Urgent/Necessities/Favorites/Burst of the moment/Redundancies): " << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    cin >> matter[i].priority;
    cout << "Enter item/service #" << i + 1 << "'s id: " << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    cin >> matter[i].id;
    cout << "Enter item/service #" << i + 1 << "'s tag: " << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    cin >> matter[i].tag;
    matter[i].totalValue = matter[i].price * matter[i].quantity;        
    }
    input_check = true;
}

void output_items(financial matter[], int size, bool input_check){
    for(int i = 0; i < size; i++){
        cout << matter[i].position << "." << endl;
        cout << "Name: " << matter[i].name << endl;
        cout << "Price: " << matter[i].price << endl;
        cout << "Quantity: " << matter[i].quantity << endl;
        cout << "Priority: " << matter[i].priority << endl;
        cout << "Tag: " << matter[i].tag << endl;
        cout << "Total cost: " << matter[i].totalValue << endl;
    }
}

void export_files(financial matter[], int size, bool input_check){
    string fileName;
    cout << "Enter file name(Default format: .txt): " << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    getline(cin, fileName);
    string tail = ".txt";
    string tail2 = ".docx";
    size_t found = fileName.find(tail);
    if(found == string::npos){
        fileName += tail;
    }
    ofstream file(fileName);
    for(int i = 0; i < size; i++){
        file << matter[i].position << "." << endl;
        file << "ID: " << matter[i].id << endl;
        file << "Name: " << matter[i].name << endl;
        file << "Price: " << matter[i].price << endl;
        file << "Quantity: " << matter[i].quantity << endl;
        file << "Priority: " << matter[i].priority << endl;
        file << "Tag: " << matter[i].tag << endl;
        file << "Total cost: " << matter[i].totalValue << endl;
    }
    if(!file.is_open()){
        cout << "Cannot create file" << endl;
    }
    else{
        cout << "Successfully created file" << endl;
    }
}

void raw_data(financial matter[], int size, bool input_check){
    string filename;
    cout << "Enter raw data file name(Default format: .txt): " << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    getline(cin, filename);
    string tail = ".txt";
    string tail2 = ".docx";
    size_t found2 = filename.find(tail2);
    size_t found = filename.find(tail);
    if(found == string::npos && found2 == string::npos){
        filename += tail;
    }
    ofstream file(filename);
    file << size << endl;
    for(int i = 0; i < size; i++){
        file << matter[i].position << endl;
        file << matter[i].id << endl;
        file << matter[i].name << endl;
        file << matter[i].price << endl;
        file << matter[i].quantity << endl;
        file << matter[i].priority << endl;
        file << matter[i].tag << endl;
        file << matter[i].totalValue << endl;
    }
        if(!file.is_open()){
        cout << "Cannot save file" << endl;
    }
    else{
        cout << "Successfully saved file" << endl;
    }
}

void load_file(financial matter[], int &size, bool &input_check){
    string filename;
    cout << "Enter file name: " << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    getline(cin, filename);
    string tail = ".txt";
    size_t found = filename.find(tail);
    if(found == string::npos){
        filename += tail;
    }
    ifstream file(filename);
    file >> size;
    for(int i = 0; i < size; i++){
        file >> matter[i].position;
        file >> matter[i].id;
        file >> matter[i].name;
        file >> matter[i].price;
        file >> matter[i].quantity;
        file >> matter[i].priority;
        file >> matter[i].tag;
        file >> matter[i].totalValue;
    }
    if(!file.is_open()){
        cout << "Cannot load file" << endl;
    }
    else{
        cout << "Successfully loaded file" << endl;
        input_check = true;
    }
}

void search_by_name(financial matter[], int size){
    string search;
    cout << "Enter item/service' s name: " << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    getline(cin, search);
    int count = 0;
    for(int i = 0; i < size; i++){
        size_t found = matter[i].name.find(search);
        if(matter[i].name == search || found != string::npos){
            cout << matter[i].position << "." << endl;
            cout << "Name: " << matter[i].name << endl;
            cout << "Price: " << matter[i].price << endl;
            cout << "Quantity: " << matter[i].quantity << endl;
            cout << "Priority: " << matter[i].priority << endl;
            cout << "Tag: " << matter[i].tag << endl;
            cout << "Total cost: " << matter[i].totalValue << endl;
        }
        else{
            count ++;
        }
    }
    if(count == size){
        cout << "No item/service found." << endl;
    }
}

void search_by_tag(financial matter[], int size){
    string search;
    cout << "Enter tagname: " << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    getline(cin, search);
    int count = 0;
    for(int i = 0; i < size; i++){
        if(matter[i].tag == search){
            cout << matter[i].position << "." << endl;
            cout << "Name: " << matter[i].name << endl;
            cout << "Price: " << matter[i].price << endl;
            cout << "Quantity: " << matter[i].quantity << endl;
            cout << "Priority: " << matter[i].priority << endl;
            cout << "Tag: " << matter[i].tag << endl;
            cout << "Total cost: " << matter[i].totalValue << endl;
        }
        else{
            count ++;
        }
    }
    if(count == size){
        cout << "No item/service found." << endl;
    }
}

void search_by_priority(financial matter[], int size){
    string search;
    cout << "Enter priority type: " << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    getline(cin, search);
    int count = 0;
    for(int i = 0; i < size; i++){
        if(matter[i].priority == search){
            cout << matter[i].position << "." << endl;
            cout << "Name: " << matter[i].name << endl;
            cout << "Price: " << matter[i].price << endl;
            cout << "Quantity: " << matter[i].quantity << endl;
            cout << "Priority: " << matter[i].priority << endl;
            cout << "Tag: " << matter[i].tag << endl;
            cout << "Total cost: " << matter[i].totalValue << endl;
            }
        else{
            count ++;
        }
    }
    if(count == size){
        cout << "No item/service found." << endl;
    }
}

void search_by_id(financial matter[], int size){
    string search;
    cout << "Enter ID: " << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    getline(cin, search);
    int count = 0;
    for(int i = 0; i < size; i++){
        if(matter[i].id == search){
            cout << matter[i].position << "." << endl;
            cout << "Name: " << matter[i].name << endl;
            cout << "Price: " << matter[i].price << endl;
            cout << "Quantity: " << matter[i].quantity << endl;
            cout << "Priority: " << matter[i].priority << endl;
            cout << "Tag: " << matter[i].tag << endl;
            cout << "Total cost: " << matter[i].totalValue << endl;
            break;
        }
        else{
            count ++;
        }
    }
    if(count == size){
        cout << "No item/service found." << endl;
    }
}

void sort_by_cost(financial matter[], int size){
    cout << "Choose your sorting type!" << endl;
    cout << "1. Highest to lowest." << endl;
    cout << "2. Lowest to highest." << endl; 
    cout << "3. Log order." << endl;
    int mode_sort;
    cin >> mode_sort;
    if(mode_sort == 1){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(matter[i].totalValue < matter[j].totalValue){
                swap(matter[i], matter[j]);
                }
            }
        }
    }
    else if (mode_sort == 2){
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                if(matter[i].totalValue > matter[j].totalValue){
                    swap(matter[i], matter[j]);
                }
            }
        }
    }
    else if (mode_sort == 3){
        for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++){
            if(matter[i].position == matter[j].position){
                swap(matter[i], matter[j]);
                }
            }
        }
    }
    cout << "Sorted!" << endl;
}

void result(financial matter[], int size, int budget_daily){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += matter[i].totalValue;
    }
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(matter[i].price > matter[j].price){
                swap(matter[i],matter[j]);
            }
        }
    }
    long long int total_quant = 0;
    for(int i = 0; i < size; i++){
        total_quant += matter[i].quantity;
    }
    int median = size / 2;
    double avg = double(sum) / total_quant;
    double percent_over = (double(sum) - double(budget_daily)) / double(budget_daily) * 100;
    double percent_under = (double(sum) / double(budget_daily)) * 100;
    cout << "Total spending: " << sum << endl;
    cout << "Median price per item/service: " << matter[median].totalValue << endl;
    cout << "Average price per item/service: " << setprecision(3) << fixed << avg << endl;
    if(sum > budget_daily){
        cout << "You have exceeded the daily budget by " << setprecision(3) << fixed << percent_over << "%" << endl;
    }
    else{
        cout << "Great job! You have only spent " << setprecision(3) << fixed << percent_under << "% " << "of daily budget." << endl;
    }
}

void add_items(financial matter[], int &size){
    int add;
    cout << "Enter number of additional items/services: " << endl;
    cin >> add;
    int old_size = size;
    size += add;
    for(int i = old_size; i < size; i++){
        matter[i].position = i + 1;
        cout << "Enter item/service #" << i + 1 << "'s name: " << endl;
        cin.ignore(1000, '\n');
        cin.clear();
        getline(cin, matter[i].name);
        repeat_price:
        cout << "Enter item/service #" << i + 1 << "'s price: " << endl;
        cin >> matter[i].price;
        if(matter[i].price < 0){
            cout << "Invalid input!" << endl;
            goto repeat_price;
        }
        repeat_quant:
        cout << "Enter item/service #" << i + 1 << "'s quantity: " << endl;
        cin >> matter[i].quantity;
        if(matter[i].quantity <= 0){
            cout << "Invalid input!" << endl;
            goto repeat_quant;
        }
        cout << "Enter item/service #" << i + 1 << "'s priority(Urgent/Necessities/Favorites/Burst of the moment/Redundancies): " << endl;
        cin.ignore(1000, '\n');
        cin.clear();
        cin >> matter[i].priority;
        cout << "Enter item/service #" << i + 1 << "'s id: " << endl;
        cin.ignore(1000, '\n');
        cin.clear();
        cin >> matter[i].id;
        cout << "Enter item/service #" << i + 1 << "'s tag: " << endl;
        cin.ignore(1000, '\n');
        cin.clear();
        cin >> matter[i].tag;
        matter[i].totalValue = matter[i].price * matter[i].quantity;        
    }
}

void update_by_id(financial matter[], int size){
    string id_search;
    cout << "Enter ID of items/services you would like to update: " << endl;
    cin.ignore(1000,'\n');
    cin.clear();
    getline(cin, id_search);
    for(int i = 0; i < size; i++){
        if(matter[i].id == id_search){
        cout << matter[i].position << "." << endl;
        cout << "Name: " << matter[i].name << endl;
        cout << "Price: " << matter[i].price << endl;
        cout << "Quantity: " << matter[i].quantity << endl;
        cout << "Priority: " << matter[i].priority << endl;
        cout << "Tag: " << matter[i].tag << endl;
        cout << "Total cost: " << matter[i].totalValue << endl;
        }
    }
}

void delete_by_id(financial matter[], int &size, bool &input_check){
    string id_search;
    cout << "Enter ID of items/services you would like to erase: " << endl;
    cin.ignore(1000,'\n');
    cin.clear();
    getline(cin, id_search);
    int target;
    for(int i = 0; i < size; i++){
        if(matter[i].id == id_search){
            target = i;
        }
        break;
    }
    for(int j = target; j < size; j++) {
        matter[j] = matter[j+1];
    }
    size--;
    if(size == 0){
        input_check = false;
    }
}