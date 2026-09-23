#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int roomNumber[6]      = {101, 102, 103, 104, 105, 106};
string roomType[6]     = {"Single", "Double", "Single", "Suite", "Double", "Suite"};
int pricePerNight[6]   = {500, 800, 500, 1200, 800, 1200};
bool isAvailable[6]    = {true, false, true, false, true, false};
string guestName[6]    = {"", "Ahmed", "", "Sara", "", "Omar"};
int numberOfNights[6]  = {0, 2, 0, 4, 0, 3};
string nationality[6] ={"","Egyptian","","Other","","Egyptian"};
double DollarRate = 50;


void ShowAllRooms(){
    cout << "========== ALL ROOMS ==========" << endl;
    for(int i = 0; i < 6; i++){
        cout << "Room Number: " << roomNumber[i] << endl;
        cout << "Room Type: " << roomType[i] << endl;
        cout<<"Price Per Night: "<<pricePerNight[i]<<" EGP"<<endl;

        if(isAvailable[i])
            cout << "Room Status: Available" << endl;
        else
            cout << "Room Status: Booked" << endl;

        cout << "--------------------------------" << endl;
    }
}

void ShowAvailableRooms(){
    bool found = false;
    cout << "========== AVAILABLE ROOMS ==========" << endl;
    for(int i = 0; i < 6; i++){
        if(isAvailable[i]){
            found = true;
            cout << "Room Number: " << roomNumber[i] << endl;
            cout << "Room Type: " << roomType[i] << endl;

            cout<<"Price Per Night: "<<pricePerNight[i]<<" EGP"<<endl;

            cout << "--------------------------------" << endl;
        }
    }
    if(!found)
        cout << "No rooms available." << endl;
}
void BookRoom(){
    cout << " " << endl;
    cout << "Do not miss this amazing offer!" << endl;
    cout << "Book 7 nights or more and get 10% OFF your stay!" << endl;
    cout << " " << endl;

    int number;
    cout << "Enter Room Number: ";
    if(!(cin>>number))
    {
        cout<<"Invalid input! Please enter a number."<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    bool found = false;
    int idx = -1;

     for(int i = 0; i < 6; i++){
        if(number == roomNumber[i]){
            found = true;
            idx = i;
        }
    }
    if(!found)
    {
        cout<<"Sorry, The room Not exists"<<endl;
        return;
    }
    if(!isAvailable[idx])
    {
        cout<<"Sorry, The room "<<number<<" is already booked"<<endl;
        return;
    }
    string name;
    cout << "Enter Guest Name: ";
    cin >> name;
    int nn;
    cout << "Enter Number of Nights: ";
    cin >> nn;
    if(nn <=0)
    {
        cout<<"Invalid number of nights!"<<endl;
        return;
    }
    int natchoice;
    string nat;
    cout << "Choose Nationality: 1.Egyptian  2.Other"<<endl;
    cin >> natchoice;
    if(natchoice==1)
        nat ="Egyptian";
        else if(natchoice ==2)
        nat ="Other";
        else
        {
        cout<<"Invalid nationality choice!"<<endl;
        return;
        }


            double total = pricePerNight[idx] * nn;

            // discount
            if(nn >= 7){
                total = total - (total * 0.10);
                cout << "Discount applied! 10% off for booking 7+ nights." << endl;
            }

            cout << "Room booked successfully!" << endl;
            if(nat=="Egyptian")
            cout << "Total Cost: " << total << " EGP" << endl;
            else
             cout << "Total Cost: " << total/DollarRate << " USD" << endl;

            isAvailable[idx] = false;
            guestName[idx] = name;
            numberOfNights[idx] = nn;
            nationality[idx] = nat;


}
void CancelBooking(){
    int n;
    int idx = -1;
    bool found = false;

    cout << "Enter room number: ";
    if(!(cin >> n))
    {
        cout<<"Invalid input! Please enter a number."<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    for(int i = 0; i < 6; i++){
        if(n == roomNumber[i]){
            found = true;
            idx = i;
        }
    }

    if(found){
        if(!isAvailable[idx]){
            cout << "Booking cancelled successfully!" << endl;
            cout << "Room " << n << " is now available" << endl;
            isAvailable[idx] = true;
            guestName[idx] = "";
            numberOfNights[idx] = 0;
            nationality[idx] = "";
        }
        else{
            cout << "Sorry, The room " << n << " is already unbooked" << endl;
        }
    }
    else{
        cout << "Sorry, The room NOT exists" << endl;
    }
}
string tolowerCase(string s)
{
    for(int i=0;i<s.length();i++)
    {
        s[i]=tolower(s[i]);
    }
    return s;
}

void SearchForGuest(){
    string searchName;
    cout << "Enter guest name to search: ";
    cin >> searchName;
    bool found = false;

    for(int i = 0; i < 6; i++){
        if(!isAvailable[i] &&tolowerCase(guestName[i]) == tolowerCase(searchName) ){
            cout << "\n--- Booking Info ---" << endl;
            cout << "Guest Name: " << guestName[i] << endl;
            cout << "Nationality: " << nationality[i] << endl;
            cout << "Room Number: " << roomNumber[i] << endl;
            cout << "Room Type: " << roomType[i] << endl;
            cout << "Price Per Night: " << pricePerNight[i] << "EGP"<< endl;
            cout << "Number of Nights: " << numberOfNights[i] << endl;
            double total =pricePerNight[i]*numberOfNights[i];
            if(numberOfNights[i]>=7)
                total =total -(total*0.1);
            if(nationality[i] =="Egyptian")
            cout<<"Total Cost: "<<total<<" EGP"<<endl;
            else
                cout<<"Total Cost: "<<total/DollarRate<<" USD"<<endl;
            cout << "--------------------------------" << endl;
            found = true;
        }
    }

    if(!found){
        cout << "Guest not found" << endl;
    }
}
void ShowAllBookings(){
    bool hasBookings = false;
    cout << "\n--- All Current Bookings ---\n";
    for(int i = 0; i < 6; i++){
        if(!isAvailable[i]){
            cout << "Guest Name: " << guestName[i]
                 << " | Nationality: " << nationality[i]
                 << " | Room Number: " << roomNumber[i]
                 << " | Room Type: " << roomType[i]
                 << " | Price Per Night: " << pricePerNight[i]
                 << " | Number of Nights: " << numberOfNights[i] << endl;
            hasBookings = true;
        }
    }
    if(!hasBookings){
        cout << "No rooms are currently booked.\n";
    }
}
void CalculateBookingCost(){
    int number;
    int idx = -1;
    bool found = false;

    cout << "Enter Room Number: ";
    if(!(cin>>number))
    {
        cout<<"Invalid input! Please enter a number."<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    for(int i = 0; i < 6; i++){
        if(number == roomNumber[i]){
            found = true;
            idx = i;
        }
    }

    if(!found){
        cout << "Sorry, The room NOT exists" << endl;
        return;
    }

    if(isAvailable[idx]){
        cout << "This room is not currently booked." << endl;
        return;
    }

    double total = pricePerNight[idx] * numberOfNights[idx];
    if(numberOfNights[idx]>=7)
        total=total-(total*0.10);

    if(nationality[idx]=="Egyptian")
      cout<<"Price Per Night: "<<pricePerNight[idx]<<" EGP"<<endl;
    else
        cout<<"Price Per Night: "<<pricePerNight[idx]/DollarRate <<" USD"<<endl;
    cout << "Number of Nights: " << numberOfNights[idx] << endl;

    // based on the guest nationality
    if(nationality[idx] == "Egyptian"){
        cout << "Total Cost: " << total << " EGP" << endl;
    }
    else{
        cout << "Total Cost: " << total / DollarRate << " USD" << endl;
    }
}
void ShowTotalRevenue(){
    double totalRevenue = 0;

    for(int i = 0; i < 6; i++){
        if(!isAvailable[i]){
            double roomRevenue =pricePerNight[i]*numberOfNights[i];
            if(numberOfNights[i]>=7)
            {
                roomRevenue =roomRevenue -(roomRevenue*0.1);
            }
            totalRevenue +=roomRevenue;
        }
    }

    cout << "========== TOTAL REVENUE ==========" << endl;
    cout << "Total Revenue from all current bookings: " << totalRevenue << " EGP" << endl;
}
void ShowOccupancyRate(){
    int bookedCount = 0;

    for(int i = 0; i < 6; i++){
        if(!isAvailable[i]){
            bookedCount++;
        }
    }

    double occupancyRate = (double(bookedCount) / 6) * 100;

    cout << "========== OCCUPANCY RATE ==========" << endl;
    cout << "Booked Rooms: " << bookedCount << " out of 6" << endl;
    cout << "Occupancy Rate: " << occupancyRate << "%" << endl;
}
void LongestStayGuest(){
    int maxNights = -1;
    int longestIndex = -1;
    bool hasBookings = false;

    for(int i = 0; i < 6; i++){
        if(!isAvailable[i]){
            hasBookings = true;
            if(numberOfNights[i] > maxNights){
                maxNights = numberOfNights[i];
                longestIndex = i;
            }
        }
    }

    if(!hasBookings){
        cout << "No bookings found.\n";
    }
    else{
        cout << "\n--- Longest Stay Guest ---\n";
        cout << "Guest Name: " << guestName[longestIndex] << endl;
        cout << "Nationality: " << nationality[longestIndex] << endl;
        cout << "Room Number: " << roomNumber[longestIndex] << endl;
        cout << "Room Type: " << roomType[longestIndex] << endl;
        cout << "Number of Nights: " << numberOfNights[longestIndex] << endl;
        double total =pricePerNight[longestIndex]*numberOfNights[longestIndex];
        if(numberOfNights[longestIndex]>=7)
            total=total-(total*0.10);
        if(nationality[longestIndex]=="Egyptian")
            cout << "Total Cost: " << total <<" EGP"<< endl;
        else
            cout << "Total Cost: " << total/DollarRate <<" USD"<< endl;
        cout << "--------------------------------\n";
    }
}
void SortRoomByPrice()
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6-i-1;j++)
        {
            if(pricePerNight[j]>pricePerNight[j+1])
            {
                int tempPrice=pricePerNight[j];
                pricePerNight[j]=pricePerNight[j+1];
                pricePerNight[j+1]=tempPrice;

                int tempRoomNum=roomNumber[j];
                roomNumber[j]=roomNumber[j+1];
                roomNumber[j+1]=tempRoomNum;

                string tempType=roomType[j];
                roomType[j]=roomType[j+1];
                roomType[j+1]=tempType;

                bool tempAvail=isAvailable[j];
                isAvailable[j]=isAvailable[j+1];
                isAvailable[j+1]=tempAvail;

                string tempGuest =guestName[j];
                guestName[j]=guestName[j+1];
                guestName[j+1]=tempGuest;

                int tempNights=numberOfNights[j];
                numberOfNights[j]=numberOfNights[j+1];
                numberOfNights[j+1]=tempNights;

                string tempNat=nationality[j];
                nationality[j]=nationality[j+1];
                nationality[j+1]=tempNat;

            }
        }
    }
    cout<<"Room Sorted by price successfully!"<<endl;
}
void RoomTypeFilter()
{
    int typeChoice;
    string type;

    cout<<"Choose Room Type:"<<endl;
    cout<<"1. Single"<<endl;
    cout<<"2. Double"<<endl;
    cout<<"3. Suite"<<endl;
    cout<<"Enter Your Choice: ";
    cin>>typeChoice;


    if(typeChoice == 1)
        type="Single";
    else if(typeChoice==2)
        type="Double";
    else if(typeChoice==3)
        type="Suite";
    else{cout<<"Invalid choice!"<<endl;
        return ;}
        bool found =0;
        for(int i=0;i<6;i++)
        {
            if(isAvailable[i]&& roomType[i]==type)
            {
                cout<<roomNumber[i]<<endl;
                cout<<roomType[i]<<endl;
                cout<<pricePerNight[i]<<" EGP"<<endl;
                found=1;
            }
        }
        if(!found)
        {
            cout<<"No Available rooms of this type."<<endl;
        }
}
int main()
{
    int choice=0;
    while(choice!=13)
    {
        cout<<"===== Hotel Management System ====="<<endl;
        cout<<"1. Show All Rooms"<<endl;
        cout<<"2. Show Available Rooms"<<endl;
        cout<<"3. Book a Room"<<endl;
        cout<<"4. Cancel Booking"<<endl;
        cout<<"5. Search for Guest"<<endl;
        cout<<"6. Show All Bookings"<<endl;
        cout<<"7. Calculate Booking Cost"<<endl;
        cout<<"8. Show Total Revenue"<<endl;
        cout<<"9. Show Occupancy Rate"<<endl;
        cout<<"10. Show Longest Stay Guest"<<endl;
        cout<<"11. Sort Rooms by Price"<<endl;
        cout<<"12. Room Type Filter"<<endl;
        cout<<"13. Exit"<<endl;
        cout<<"Enter Your Choice: "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            ShowAllRooms();
            break;
        case 2:
            ShowAvailableRooms();
            break;
        case 3:
           BookRoom();
           break;
        case 4:
            CancelBooking();
            break;
        case 5:
            SearchForGuest();
            break;
        case 6:
            ShowAllBookings();
            break;
        case 7:
            CalculateBookingCost();
            break;
        case 8:
            ShowTotalRevenue();
            break;
        case 9:
            ShowOccupancyRate();
            break;
        case 10:
            LongestStayGuest();
            break;
        case 11:
            SortRoomByPrice();
            break;
        case 12:
            RoomTypeFilter();
            break;
        case 13:
            cout<<"Goodbye!"<<endl;
            break;
        default:
            cout<<"Invalid Choice!"<<endl;
        }
    }
    return 0;
}
